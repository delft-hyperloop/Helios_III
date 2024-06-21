

pub fn main() {
    let config = can_yaml_config_rs::parse_yaml_config_from_file("./test.yaml").unwrap();
    println!("{config:}")

}
