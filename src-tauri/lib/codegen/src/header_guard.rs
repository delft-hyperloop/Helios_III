
use crate::errors::Result;

pub fn generate_header_guard_top(header : &mut String) -> Result<()> {
    header.push_str("#ifndef CANZERO_H
#define CANZERO_H
");
    Ok(())
}

pub fn generate_header_guard_bottom(header : &mut String) -> Result<()> {
    header.push_str("#endif");
    Ok(())
}
