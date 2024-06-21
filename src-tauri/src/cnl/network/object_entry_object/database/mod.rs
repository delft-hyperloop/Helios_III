use self::value::ObjectEntryValue;

pub mod value;

pub struct ObjectEntryDatabase {
    history: Vec<ObjectEntryValue>,
}

impl ObjectEntryDatabase {
    pub fn new() -> Self {
        Self { history: vec![] }
    }

    pub fn history(&self) -> &Vec<ObjectEntryValue> {
        &self.history
    }

    pub fn latest_value(&self) -> Option<&ObjectEntryValue> {
        self.history.last()
    }
    pub fn push_value(&mut self, value: ObjectEntryValue) {
        self.history.push(value);
    }
}
