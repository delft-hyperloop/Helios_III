struct HeartBeat_Controller {
    pub braking_heartbeat: Output<'static>,
    pub braking_rearm: Output<'static>,
    pub braking_communication: Input<'static>,
    pub brake_retraction:bool,
}

impl HeartBeat_Controller{
    pub fn new(p: Peripherals) -> Self {
        let braking_heartbeat = Output::new(p.PB8, Level::High, Speed::Low);
        let braking_rearm = Output::new(p.PG1, Level::High, Speed::Low);
        let braking_communication = Input::new(p.PF12, Pull::None);

        let brake_retraction = false;
        Self {
            braking_heartbeat,
            braking_rearm,
            braking_communication,
            brake_retraction,
        }
    }
    pub fn rearm_breaks(&mut self) -> bool {
        self.braking_rearm.set_high();
        if self.braking_communication.is_high() {
            true
        } else {
            false
        }
    }
}