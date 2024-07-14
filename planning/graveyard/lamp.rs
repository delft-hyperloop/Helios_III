//! # LinearAttributeMAp (lamp)
//! Mapping a key to a constant attribute and a mutable value, with `O(n)` for all operations.

use heapless::Vec;

pub enum MapError {
    KeyNotFound,
    MapFull,
}

pub trait AttributedMap<A: Eq, B: Initialisable, C> {
    fn init(&mut self, key: A, attr: B) -> Result<(), MapError>;
    fn insert(&mut self, key: A, val: C) -> Result<Option<C>, MapError>;
    fn set(&mut self, key: A, attr: B, val: C) -> Result<(), MapError>;
    fn get(&self, key: &A) -> Result<(&B, Option<&C>), MapError>;
}

pub trait Initialisable {
    fn init() -> Self;
}

pub struct LinearAttributeMap<A: Eq, B: Initialisable, C, const N: usize> {
    buffer: Vec<(A, B, Option<C>), N>,
}

impl<A: Eq, B: Initialisable, C, const N: usize> LinearAttributeMap<A, B, C, N> {
    pub fn new() -> Self { Self { buffer: Vec::new() } }

    fn set_inner(&mut self, key: A, attr: B, val: Option<C>) -> Result<(), MapError> {
        match self.buffer.iter_mut().find(|(k, _, _)| k == &key) {
            None => match self.buffer.push((key, attr, val)) {
                Ok(_) => Ok(()),
                Err(_) => Err(MapError::MapFull),
            },
            Some(x) => {
                *x = (key, attr, val);
                Ok(())
            },
        }
    }
}

impl<A: Eq, B: Initialisable , C, const N: usize> AttributedMap<A, B, C> for LinearAttributeMap<A, B, C, N> {
    fn init(&mut self, key: A, attr: B) -> Result<(), MapError> { self.set_inner(key, attr, None) }

    fn insert(&mut self, key: A, value: C) -> Result<Option<C>, MapError> {
        match self.buffer.iter_mut().find(|(k, _, _)| k == &key) {
            None => match self.buffer.push((key, B::init(), Some(value))) {
                Ok(_) => Ok(None),
                Err(_) => Err(MapError::MapFull),
            },
            Some((_, _, c)) => {
                match c {
                    None => {
                        *c = Some(value);
                        Ok(None)
                    }
                    Some(x) => {
                        let r = core::mem::replace(x, value);
                        Ok(Some(r))
                    }
                }
            },
        }
    }

    fn set(&mut self, key: A, attr: B, val: C) -> Result<(), MapError> {
        self.set_inner(key, attr, Some(val))
    }

    fn get(&self, key: &A) -> Result<(&B, Option<&C>), MapError> {
        for (k, b, v) in self.buffer.iter() {
            if k == key {
                return Ok((b, v.as_ref()));
            }
        }
        Err(MapError::KeyNotFound)
    }
}

impl<'a, A: Eq, B: Initialisable, C, const N: usize> IntoIterator for &'a LinearAttributeMap<A, B, C, N> {
    type Item = (&'a A, &'a B, Option<&'a C>);
    type IntoIter = core::iter::Map<
        core::slice::Iter<'a, (A, B, Option<C>)>,
        fn(&(A, B, Option<C>)) -> (&A, &B, Option<&C>),
    >;

    fn into_iter(self) -> Self::IntoIter {
        self.buffer.iter().map(|(a, b, c)| (a, b, c.as_ref()))
    }
}

// Iterate through all the heartbeats and check that none are expired, send an EmergencyBraking event if something has expired,
// async fn check_heartbeats(hb: &HB, event_sender: EventSender, data_sender: DataSender) {
//     let now = Instant::now();
//     for (dt, out, last) in hb.into_iter() {
//         if let Some(l) = last {
//             if l.elapsed() > *out {
//                 event_sender.send(Event::EmergencyBraking).await;
//                 data_sender.send(Datapoint::new(Datatype::HeartbeatExpired, dt.to_id() as u64, now.as_ticks())).await;
//             }
//         }
//     }
// }