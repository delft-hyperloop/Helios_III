use embassy_stm32::Peripherals;

pub struct FSMPeripherals {
    pub peripherals: Peripherals,
}

impl FSMPeripherals{
    pub fn new(p : Peripherals) -> Self {
        Self {
            peripherals: p,
        }
    }
}