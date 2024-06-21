use std::{fmt::Display, hash::Hash};

use super::ConfigRef;



#[derive(Debug)]
pub enum SignalSign {
    Signed,
    Unsigned,
}

impl Hash for SignalSign {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        match &self {
            SignalSign::Signed => state.write_u8(0),
            SignalSign::Unsigned => state.write_u8(1),
        }
    }
}

impl Display for SignalSign {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self {
            SignalSign::Signed => write!(f, "signed"),
            SignalSign::Unsigned => write!(f, "unsigned"),
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
pub enum SignalType {
    UnsignedInt { size: u8 },
    SignedInt { size: u8 },
    Decimal { size: u8, offset: f64, scale: f64 },
}

impl Hash for SignalType {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        match &self {
            SignalType::UnsignedInt { size } => {
                state.write_u8(0);
                state.write_u128(*size as u128);
            },
            SignalType::SignedInt { size } => {
                state.write_u8(1);
                state.write_u128(*size as u128);
            },
            SignalType::Decimal { size, offset, scale } => {
                state.write_u8(2);
                state.write_u128(*size as u128);
                ((*offset * 1e4) as u128).hash(state);
                ((*scale * 1e4) as u128).hash(state);
            }
        }
    }
}

impl SignalType {
    pub fn offset(&self) -> f64 {
        match &self {
            SignalType::UnsignedInt { size: _ } => 0.0,
            SignalType::SignedInt { size: _ } => 0.0,
            SignalType::Decimal {
                size: _,
                offset,
                scale: _,
            } => *offset,
        }
    }
    pub fn size(&self) -> u8 {
        match &self {
            SignalType::UnsignedInt { size } => *size,
            SignalType::SignedInt { size } => *size,
            SignalType::Decimal {
                size,
                offset: _,
                scale: _,
            } => *size,
        }
    }
    pub fn scale(&self) -> f64 {
        match &self {
            SignalType::UnsignedInt { size: _ } => 1.0,
            SignalType::SignedInt { size: _ } => 1.0,
            SignalType::Decimal {
                size: _,
                offset: _,
                scale,
            } => *scale,
        }
    }
    pub fn sign(&self) -> SignalSign {
        match &self {
            SignalType::UnsignedInt { size: _ } => SignalSign::Unsigned,
            SignalType::SignedInt { size: _ } => SignalSign::Signed,
            SignalType::Decimal {
                size: _,
                offset: _,
                scale: _,
            } => SignalSign::Unsigned,
        }
    }
}

pub type SignalRef = ConfigRef<Signal>;

#[derive(Debug, Clone)]
pub struct Signal {
    pub name: String,
    pub description: Option<String>,
    pub ty: SignalType,
    pub value_table: Option<ValueTableRef>,
    // refers to the byte offset!
    pub offset: usize,
}

impl Hash for Signal {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for b in self.name.bytes() {
            state.write_u8(b);
        }
        match &self.description{
            Some(desc) => {
                state.write_u8(0);
                for b in desc.bytes() {
                    state.write_u8(b);
                }
            }
            None => state.write_u8(1),
        }
        self.ty.hash(state);
        match &self.value_table {
            Some(vt) => {
                state.write_u8(0);
                vt.hash(state);
            }
            None => state.write_u8(1),
        }
        state.write_u128(self.offset as u128);
    }
}

impl Signal {
    pub fn new(name : &str, description : Option<&str>, ty : SignalType, offset : usize) -> Signal {
        Signal {
            name : name.to_owned(),
            description : description.map(|s| s.to_owned()),
            ty,
            offset,
            value_table : None,
        }
    }
    pub fn create(name : &str, description : Option<&str>, ty : SignalType) -> Signal {
        Signal {
            name : name.to_owned(),
            description : description.map(|s| s.to_owned()),
            ty,
            offset : 0,
            value_table : None,
        }
    }
    pub fn name(&self) -> &str {
        &self.name
    }
    pub fn description(&self) -> Option<&str> {
        match &self.description {
            Some(some) => Some(&some),
            None => None,
        }
    }
    pub fn ty(&self) -> &SignalType {
        &self.ty
    }
    pub fn scale(&self) -> f64 {
        self.ty.scale()
    }
    pub fn byte_offset(&self) -> usize {
        self.offset
    }
    pub fn offset(&self) -> f64 {
        self.ty.offset()
    }
    pub fn sign(&self) -> SignalSign {
        self.ty.sign()
    }
    pub fn size(&self) -> u8 {
        self.ty.size()
    }
}

pub type ValueTableRef = ConfigRef<ValueTable>;
#[derive(Debug, Clone)]
pub struct ValueTable(pub Vec<(String, u64)>);

impl Hash for ValueTable {
    fn hash<H: std::hash::Hasher>(&self, state: &mut H) {
        for (n,v) in &self.0 {
            for b in n.bytes() {
                state.write_u8(b);
            }
            state.write_u64(*v);
        }
    }
}
