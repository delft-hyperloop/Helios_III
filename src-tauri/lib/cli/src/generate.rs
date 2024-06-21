use std::path::{Path, PathBuf};

use canzero_appdata::AppData;

use crate::errors::{Error, Result};

fn rec_create_dir(dir : &Path) -> Result<()>{
   if !dir.is_dir() {
       if let Some(parent) = dir.parent() {
           rec_create_dir(parent)?;
       }
       std::fs::create_dir(dir)?;
    }
    Ok(())
}

pub fn command_generate(node_name : &str, output_dir : &PathBuf) -> Result<()> {
    let appdata = AppData::read()?;
    let network_config = appdata.config()?;
    let output_dir = output_dir.clone();
    if !output_dir.exists() {
        return Err(Error::FileNotFound(output_dir.to_str().unwrap().to_owned()));
    }
    
    rec_create_dir(&output_dir)?;

    let mut options = canzero_codegen::options::Options::default();

    let mut source_file_path = output_dir.clone();
    source_file_path.push("canzero.cpp");
    options.set_source_file_path(source_file_path.to_str().unwrap());

    let mut header_file_path = output_dir.clone();
    header_file_path.push("canzero.h");
    options.set_header_file_path(header_file_path.to_str().unwrap());

    canzero_codegen::generate(node_name, network_config, options)?;

    Ok(())
}
