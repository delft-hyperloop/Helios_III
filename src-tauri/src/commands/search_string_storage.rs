use std::{collections::HashMap, sync::Mutex};
use tauri::State;

pub struct SearchStringStorage {
    pub store: Mutex<HashMap<String, String>>,
}


#[tauri::command]
pub fn get_stored_search_string(
    page: String,
    storage: State<SearchStringStorage>
) -> Option<String> {
    return storage.store.lock().unwrap().get(&page).cloned();
}

#[tauri::command]
pub fn store_search_string(
    page: String,
    string: String,
    storage: State<SearchStringStorage>
) {
    storage.store.lock().unwrap().insert(page, string);
}
