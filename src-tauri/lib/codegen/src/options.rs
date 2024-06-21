
pub enum Platform {
    Linux,
}

pub struct Options {
    source_file_path : String,
    header_file_path : String,
    platform : Platform,
    indent : usize,
    namespace : String,
}

impl Default for Options {
    fn default() -> Self {
        Self {
            source_file_path : "canzero.c".to_owned(),
            header_file_path : "canzero.h".to_owned(),
            platform : Platform::Linux,
            indent : 2,
            namespace : "canzero".to_owned(),
        }
    }
}

impl Options {
    pub fn source_file_path(&self) -> &str {
        &self.source_file_path
    }
    pub fn set_source_file_path(&mut self, path : &str) {
        self.source_file_path = path.to_owned();
    }
    pub fn header_file_path(&self) -> &str {
        &self.header_file_path
    }
    pub fn set_header_file_path(&mut self, path : &str) {
        self.header_file_path = path.to_owned();
    }
    pub fn platform(&self) -> &Platform {
        &self.platform
    }
    pub fn set_platform(&mut self, platform : Platform) {
        self.platform = platform;
    }
    pub fn indent(&self) -> usize {
        self.indent
    }
    pub fn set_indent(&mut self, indent : usize) {
        self.indent = indent;
    }
    pub fn namespace(&self) -> &str {
        &self.namespace
    }
    pub fn set_namespace(&mut self, namespace : &str) {
        self.namespace = namespace.to_owned();
    }
}
