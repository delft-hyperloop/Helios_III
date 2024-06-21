use canzero_codegen::{generate, options::Options};
use canzero_yaml::{self, parse_yaml_config_from_file};

pub fn main() {
    let network_ref = parse_yaml_config_from_file("./examples/simple.yaml").unwrap();
    generate("simple", network_ref, Options::default()).unwrap();

}
