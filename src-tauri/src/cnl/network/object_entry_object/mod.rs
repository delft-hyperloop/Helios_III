use std::{
    ops::Deref,
    sync::{atomic::AtomicU64, Arc, OnceLock},
    time::{Duration, Instant},
};

use canzero_config::config;
use chrono;
use tokio::sync::{Mutex, OnceCell};

use crate::{
    cnl::{
        self, frame::Value, network::object_entry_object::database::ObjectEntryDatabase, tx::TxCom,
    },
    notification::{notify_error, notify_info, notify_warning},
};

use self::{
    database::value::ObjectEntryValue,
    history::ObjectEntryHistroyObservable,
    info::{ty::ObjectEntryType, ObjectEntryInformation},
    latest::{event::OwnedObjectEntryEvent, ObjectEntryLatestObservable},
};

mod database;
pub mod history;
pub mod info;
pub mod latest;

pub struct ObjectEntryObject {
    object_entry_ref: config::ObjectEntryRef,
    store: Arc<Mutex<ObjectEntryDatabase>>,
    timebase: std::time::Instant,
    latest_observable: ObjectEntryLatestObservable,
    latest_event_name: String,
    history_observables: Mutex<Vec<ObjectEntryHistroyObservable>>,
    history_observables_id_acc: AtomicU64,
    history_event_name_prefix: String,
    app_handle: tauri::AppHandle,
    tx_com: Arc<TxCom>,
    open_set_request: Arc<Mutex<(u64, Option<Value>)>>,
    open_get_request: Arc<Mutex<u64>>,
    set_request_timeout: Duration,
    get_request_timeout: Duration,
    plottable: bool,
}

impl ObjectEntryObject {
    pub fn create(
        _network_config: &config::NetworkRef,
        node_config: &config::NodeRef,
        object_entry_config: &config::ObjectEntryRef,
        app_handle: &tauri::AppHandle,
        tx_com: Arc<TxCom>,
        timebase: Instant,
    ) -> Self {
        let latest_event_name = format!(
            "{}_{}_latest",
            object_entry_config.node().name(),
            object_entry_config.name()
        );
        let history_event_name = format!(
            "{}_{}_history",
            object_entry_config.node().name(),
            object_entry_config.name()
        );
        let get_req_num_frames = object_entry_config.ty().size().div_ceil(32) as u64;

        let plottable = node_config.tx_streams().iter().any(|stream| {
            stream
                .mapping()
                .iter()
                .flatten()
                .any(|o| o.id() == object_entry_config.id())
        });

        Self {
            object_entry_ref: object_entry_config.clone(),
            store: Arc::new(Mutex::new(ObjectEntryDatabase::new())),
            timebase,
            latest_observable: ObjectEntryLatestObservable::new(
                &latest_event_name,
                Duration::from_millis(100),
                &app_handle,
            ),
            latest_event_name,
            history_observables: Mutex::new(vec![]),
            history_observables_id_acc: AtomicU64::new(0),
            history_event_name_prefix: history_event_name,
            app_handle: app_handle.clone(),
            tx_com,
            open_set_request: Arc::new(Mutex::new((0, None))),
            open_get_request: Arc::new(Mutex::new(0)),
            set_request_timeout: Duration::from_millis(1000 + get_req_num_frames * 200),
            get_request_timeout: Duration::from_millis(1000 + get_req_num_frames * 200),
            plottable,
        }
    }
    pub async fn kill_yourself(&self) {
        let store = self.store.lock().await;
        tokio::time::sleep(Duration::from_secs(3600)).await;
        drop(store)
    }
    pub fn name(&self) -> &str {
        self.object_entry_ref.name()
    }
    pub fn id(&self) -> u32 {
        self.object_entry_ref.id()
    }
    pub fn latest_event_name(&self) -> &str {
        &self.latest_event_name
    }
    pub fn node_id(&self) -> u8 {
        self.object_entry_ref.node().id() as u8
    }

    pub async fn request_current_value(&self) {
        let mut get_req_num = match self.open_get_request.try_lock() {
            Ok(n) => {
                if *n % 2 == 0 {
                    n
                } else {
                    notify_warning(
                        &self.app_handle,
                        "Ignoring Get Request",
                        &format!(
                            "Older get request for {}::{} still in progress",
                            self.object_entry_ref.node().name(),
                            self.name()
                        ),
                        chrono::Local::now(),
                    );
                    return;
                }
            }
            Err(_) => {
                notify_warning(
                    &self.app_handle,
                    "Ignoring Get Request",
                    &format!(
                        "Older get request for {}::{} still in progress",
                        self.object_entry_ref.node().name(),
                        self.name()
                    ),
                    chrono::Local::now(),
                );
                return;
            }
        };
        *get_req_num += 1;
        let my_req_num = *get_req_num;
        drop(get_req_num);
        self.tx_com
            .send_get_req(self.node_id(), self.id() as u16)
            .await;
        tokio::spawn({
            let timeout = self.get_request_timeout.clone();
            let oe_name = self.name().to_owned();
            let node_name = self.object_entry_ref.node().name().to_owned();
            let get_requests = self.open_get_request.clone();
            let app_handle = self.app_handle.clone();

            async move {
                tokio::time::sleep(timeout).await;
                let mut new_req_num = get_requests.lock().await;
                if *new_req_num == my_req_num {
                    *new_req_num += 1;
                    drop(new_req_num);
                    notify_error(
                        &app_handle,
                        "Get Request Timeout",
                        &format!("Get request for {node_name}::{oe_name} timed out",),
                        chrono::Local::now(),
                    );
                }
            }
        });
    }

    pub async fn set_request(&self, value: Value) {
        let mut set_req_data = match self.open_set_request.try_lock() {
            Ok(set_req_data) => {
                if set_req_data.0 % 2 == 0 {
                    set_req_data
                } else {
                    drop(set_req_data);
                    notify_warning(
                        &self.app_handle,
                        "Ignoring Set Request",
                        &format!(
                            "Older set request for {}::{} still in progress",
                            self.object_entry_ref.node().name(),
                            self.name()
                        ),
                        chrono::Local::now(),
                    );
                    return;
                }
            }
            Err(_) => {
                notify_warning(
                    &self.app_handle,
                    "Ignoring Set Request",
                    &format!(
                        "Older set request for {}::{} still in progress",
                        self.object_entry_ref.node().name(),
                        self.name()
                    ),
                    chrono::Local::now(),
                );
                return;
            }
        };
        set_req_data.0 += 1;
        let my_req_num = set_req_data.0;
        let (bit_value, last_fill) = value.get_as_bin(self.ty());
        set_req_data.1 = Some(value);
        drop(set_req_data);

        let server_id = self.node_id();
        let oe_id = self.id();

        let tx = self.tx().clone();
        tokio::spawn(async move {
            tx.send_set_request(server_id, oe_id, bit_value, last_fill)
                .await;
        });

        tokio::task::spawn({
            let timeout = self.set_request_timeout.clone();
            let oe_name = self.name().to_owned();
            let node_name = self.object_entry_ref.node().name().to_owned();
            let app_handle = self.app_handle.clone();
            let set_req_data = self.open_set_request.clone();

            async move {
                tokio::time::sleep(timeout).await;
                let mut curr_req = set_req_data.lock().await;
                if curr_req.0 == my_req_num {
                    *curr_req = (curr_req.0 + 1, None);
                    drop(curr_req);
                    notify_error(
                        &app_handle,
                        "Set Request Timeout",
                        &format!("Set request for {node_name}::{oe_name} timed out",),
                        chrono::Local::now(),
                    );
                }
            }
        });
    }

    pub async fn push_value(&self, value: Value, timestamp: &Duration) {
        let mut store = self.store.lock().await;
        let delta_time = match store.latest_value() {
            Some(latest) => timestamp.saturating_sub(latest.timestamp), //Not sure if saturating
            //sub is correct here
            None => timestamp.clone(),
        };

        // The value has to be stored before notify because the observables
        // use the values in the store directly to reduce clones
        store.push_value(ObjectEntryValue::new(value, timestamp.clone(), delta_time));
        drop(store); // <- Gentlemen we got him.
        self.latest_observable.notify().await;
        for history_observable in self.history_observables.lock().await.iter() {
            history_observable.notify().await;
        }
    }

    pub async fn push_get_response(&self, value: Value, timestamp: &Duration) {
        let mut get_req_num = self.open_get_request.lock().await;
        if *get_req_num % 2 == 0 {
            drop(get_req_num);
            notify_warning(
                &self.app_handle,
                "Ignoring Get Response",
                &format!(
                    "Get response for {}::{} came in after timeout",
                    self.object_entry_ref.node().name(),
                    self.name()
                ),
                chrono::Local::now(),
            );
            return;
        }
        *get_req_num += 1;
        drop(get_req_num);
        self.push_value(value, timestamp).await;
        notify_info(
            &self.app_handle,
            "Get Request Successfull",
            &format!(
                "Get request for {}::{} successfull",
                self.object_entry_ref.node().name(),
                self.name(),
            ),
            chrono::Local::now(),
        );
    }

    pub async fn push_get_response_unsolicited(&self, value: Value, timestamp: &Duration) {
        self.push_value(value, timestamp).await;
        notify_info(
            &self.app_handle,
            "Unsolicited Get Response",
            &format!(
                "Received unsolicited get response for {}::{}",
                self.object_entry_ref.node().name(),
                self.name(),
            ),
            chrono::Local::now(),
        );
    }

    pub async fn push_set_response(&self, result: cnl::errors::Result<()>) {
        let mut set_req_data = self.open_set_request.lock().await;
        if set_req_data.0 % 2 == 0 {
            drop(set_req_data);
            notify_info(
                &self.app_handle,
                "Ignoring Set Response",
                &format!(
                    "Set response for {}::{} came in after timeout",
                    self.object_entry_ref.node().name(),
                    self.name(),
                ),
                chrono::Local::now(),
            );
            return;
        };
        set_req_data.0 += 1;
        match result {
            Ok(_) => {
                if let Some(value) = set_req_data.1.as_ref() {
                    self.push_value(value.clone(), &self.now()).await;
                    *set_req_data = (set_req_data.0, None);
                };
                drop(set_req_data);
                notify_info(
                    &self.app_handle,
                    "Set Request Successfull",
                    &format!(
                        "{}::{} was set successfully",
                        self.object_entry_ref.node().name(),
                        self.name(),
                    ),
                    chrono::Local::now(),
                );
            }
            Err(err) => {
                *set_req_data = (set_req_data.0, None);
                drop(set_req_data);
                notify_error(
                    &self.app_handle,
                    err.reason(),
                    err.description(),
                    chrono::Local::now(),
                );
            }
        }
    }

    pub fn ty(&self) -> &config::TypeRef {
        &self.object_entry_ref.ty()
    }

    fn tx(&self) -> Arc<TxCom> {
        self.tx_com.clone()
    }

    pub fn listen_to_latest(&self) {
        self.latest_observable.listen(&self.store);
    }
    pub async fn unlisten_from_latest(&self) {
        self.latest_observable.unlisten().await;
    }
    pub async fn latest_event(&self) -> Option<OwnedObjectEntryEvent> {
        self.store
            .lock()
            .await
            .latest_value()
            .map(ObjectEntryValue::clone)
            .map(OwnedObjectEntryEvent::new)
    }

    pub async fn listen_to_history(
        &self,
        frame_size: Duration,
        min_interval: Duration,
    ) -> (String, Vec<OwnedObjectEntryEvent>) {
        let store_lock = self.store.lock().await;
        let history = store_lock.history();
        let now = std::time::Instant::now().duration_since(self.timebase);
        let breakpoint = now.saturating_sub(frame_size);
        let mut breakpoint_index = None;
        for (i, event) in history.iter().enumerate().rev() {
            if event.timestamp <= breakpoint {
                breakpoint_index = Some(i);
                break;
            }
        }
        let start_index = breakpoint_index.unwrap_or(0);
        let history_of = history[start_index..]
            .iter()
            .map(ObjectEntryValue::clone)
            .map(OwnedObjectEntryEvent::new)
            .collect();
        drop(store_lock);

        // create a custom event_name for the
        let event_name = format!(
            "{}_{}",
            self.history_event_name_prefix,
            self.history_observables_id_acc
                .fetch_add(1, std::sync::atomic::Ordering::SeqCst)
        );
        let new_history_observable = ObjectEntryHistroyObservable::new(
            &event_name,
            min_interval,
            frame_size,
            &self.app_handle,
            start_index,
            self.timebase,
        );
        new_history_observable.start_notify_task(&self.store).await;
        self.history_observables
            .lock()
            .await
            .push(new_history_observable);

        (event_name, history_of)
    }

    pub async fn complete_history(&self) -> Vec<OwnedObjectEntryEvent> {
        let store_lock = self.store.lock().await;
        let history = store_lock.history();
        history
            .iter()
            .map(ObjectEntryValue::clone)
            .map(OwnedObjectEntryEvent::new)
            .collect()
    }

    pub async fn unlisten_from_history(&self, event_name: &str) {
        let mut history_observables = self.history_observables.lock().await;
        let mut remove = None;
        for (i, observable) in history_observables.iter_mut().enumerate() {
            if observable.event_name() == event_name {
                observable.stop_notify_task().await;
                remove = Some(i);
                break;
            }
        }
        let Some(remove_index) = remove else {
            panic!("Failed to unlisten from object entry history {event_name}");
        };
        history_observables.remove(remove_index);
    }

    pub fn information(&self) -> ObjectEntryInformation {
        ObjectEntryInformation::new(
            self.object_entry_ref.name().to_owned(),
            self.object_entry_ref.description().map(str::to_owned),
            self.object_entry_ref.friend().map(str::to_owned),
            self.object_entry_ref.id() as u16,
            self.object_entry_ref.unit().map(str::to_owned),
            ObjectEntryType::new(self.object_entry_ref.ty()),
            self.plottable,
        )
    }

    pub fn now(&self) -> Duration {
        std::time::Instant::now().duration_since(self.timebase)
    }

    pub async fn deadlock_watchdog(&self) {
        drop(self.store.lock().await);
        drop(self.history_observables.lock().await);
        drop(self.open_set_request.lock().await);
        drop(self.open_get_request.lock().await);
    }
}
