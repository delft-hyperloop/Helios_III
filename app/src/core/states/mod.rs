mod boot;
mod emergency_braking;
mod establish_connection;
mod exit;
mod hv_on;
mod idle;
mod levitating;
mod moving_end_ls;
mod moving_end_st;
mod moving_ls_cv;
mod moving_ls_st;
mod moving_st;
mod run_config;

/// Helper functions to the route planning moving states.
mod moving {
    use crate::core::finite_state_machine::{Fsm, State};
    use crate::core::fsm_status::{Location, RouteUse};
    use crate::{Info, transit};

    impl Fsm {
        /// Check the planned route and transition from a not-moving state to the correct moving state
        pub async fn enter_moving(&mut self) {
            match self.route.next_position() {
                Location::ForwardA | Location::BackwardsA => transit!(self, State::MovingST),
                Location::ForwardB | Location::BackwardsB => {
                    transit!(self, State::EndST)
                },
                Location::ForwardC | Location::BackwardsC => transit!(self, State::EndLS),
                Location::StopAndWait => self.peripherals.propulsion_controller.stop(),
                _ => {
                    self.log(Info::InvalidRouteConfiguration).await;
                    transit!(self, State::Exit);
                },
            }
        }
    }
}