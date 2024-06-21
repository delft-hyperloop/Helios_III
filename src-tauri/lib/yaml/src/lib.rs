use std::{path::{Path, PathBuf}, str::FromStr};

use canzero_config::{builder::NetworkBuilder, config::NetworkRef};
use errors::Result;

use crate::parser::parse_included_files;

pub mod errors;
mod parser;


pub fn parse_yaml_config_from_file(path : &str) -> Result<NetworkRef> {
    let path = PathBuf::from_str(path).unwrap();
    let src = std::fs::read_to_string(&path)?;
    let network = parse_yaml_config(&src, path.as_path())?;
    Ok(network)
}

pub fn parse_yaml_config(src : &str, path : &Path) -> Result<NetworkRef> {
    let mut network_builder = NetworkBuilder::new();

    let docs = yaml_rust::yaml::YamlLoader::load_from_str(src)?;
    let doc = &docs[0];
    //println!("{doc:?}");
    parser::parse_top_level(doc, &mut network_builder, path)?;

    let network = network_builder.build()?;
    Ok(network)
}

pub fn parse_yaml_config_files_from_file(path: &str) -> Result<Vec<PathBuf>> {
    let path = PathBuf::from_str(path).unwrap();
    let src = std::fs::read_to_string(&path)?;
    parse_yaml_config_files(&src, path.as_path())
}

pub fn parse_yaml_config_files(src :&str, path: &Path) -> Result<Vec<PathBuf>> {

    let docs = yaml_rust::yaml::YamlLoader::load_from_str(src)?;
    let doc = &docs[0];
    parse_included_files(doc, path)
}
