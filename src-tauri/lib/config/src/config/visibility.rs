use std::hash::Hash;


#[derive(Debug, Clone, PartialEq)]
pub enum Visibility {
    Global,
    Static,
}

impl Hash for Visibility {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        match &self {
            Visibility::Global => state.write_u8(1),
            Visibility::Static => state.write_u8(0),
        }
    }
}
