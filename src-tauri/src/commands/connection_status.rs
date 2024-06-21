use std::sync::Arc;

use crate::{
    cnl::connection::{ConnectionObject, ConnectionStatus},
    state::cnl_state::CNLState,
};

#[tauri::command]
pub async fn get_connection_status(
    state: tauri::State<'_, CNLState>,
) -> Result<ConnectionStatus, ()> {
    let cnl = state.lock().await;
    let connection_object: &Arc<ConnectionObject> = cnl.connection_object();
    let connection_status = connection_object.get_status();
    Ok(connection_status)
}

#[tauri::command]
pub async fn heartbeat(state: tauri::State<'_, CNLState>) -> Result<(), ()> {
    state.lock().await.reset_watchdog().await;
    Ok(())
}

#[tauri::command]
pub async fn unregister_from_heartbeat(state: tauri::State<'_, CNLState>) -> Result<(), ()> {
    state.lock().await.unregister_from_heartbeat();
    Ok(())
}

#[tauri::command]
pub async fn reregister_to_heartbeat(state: tauri::State<'_, CNLState>) -> Result<(), ()> {
    state.lock().await.reregister_to_heartbeat();
    Ok(())
}

#[tauri::command]
pub fn restart(app_handle: tauri::AppHandle) {
    println!("Restarting...");
    app_handle.restart();
}

#[tauri::command]
pub fn close(app_handle: tauri::AppHandle) {
    println!("Closing...");
    app_handle.exit(0);
}

#[tauri::command]
pub async fn create_deadlock(state: tauri::State<'_, CNLState>) -> Result<(), ()> {
   let cnl = state.lock().await; 
   println!("aquired cnl lock, killing object entry object...");
   let oe = cnl.nodes()[0].object_entries()[0].clone();
   drop(cnl);
   oe.kill_yourself().await;
   println!("lock freed");
   Ok(())
}
