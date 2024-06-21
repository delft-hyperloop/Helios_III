pub fn main() {
    let config = can_yaml_config_rs::parse_yaml_config_from_file("./stream_example.yaml").unwrap();
    println!("{config:}")
}
