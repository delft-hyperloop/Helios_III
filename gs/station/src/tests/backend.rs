use std::path::PathBuf;
use std::str::FromStr;

use crate::backend::Backend;

#[test]
fn import_procedures() {
    let procedures =
        Backend::load_procedures(PathBuf::from_str("../../config/procedures/").unwrap()).unwrap();
    assert!(procedures.len() > 0);
    // panic!("{:?}", procedures);
    let example = procedures.iter().find(|x| x[0] == "example").unwrap();
    assert_eq!(example[1], "This is an example procedure");
    assert_eq!(example[2], "DH08.PROC.SC.x");
    assert_eq!(example[3], "Kiko\nKiril\n");
    assert_eq!(example[4], "Andreas\n");
    assert_eq!(example[5], "1. I refuse to elaborate.\n2. :)\n3. if in trouble just call me\njust text is also fine in a procedure.\n");
}
