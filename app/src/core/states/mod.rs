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
pub mod precharging;
mod run_config;

/// Helper functions to the route planning moving states.
mod moving {
    use core::sync::atomic::Ordering;

    use crate::core::finite_state_machine::Fsm;
    use crate::core::finite_state_machine::State;
    use crate::core::fsm_status::Location;
    use crate::core::fsm_status::RouteUse;
    use crate::core::fsm_status::IN_A_LANE_SWITCH;
    use crate::transit;
    use crate::Command;
    use crate::Datatype;
    use crate::Info;

    impl Fsm {
        /// Check the planned route and transition from a not-moving state to the correct moving state
        pub async fn enter_moving(&mut self) {
            self.log(Info::EnterMoving).await;
            match self.route.next_position() {
                Location::ForwardA | Location::BackwardsA => transit!(self, State::MovingST),
                Location::ForwardB | Location::BackwardsB => {
                    transit!(self, State::EndST)
                },
                Location::ForwardC | Location::BackwardsC => transit!(self, State::EndLS),
                Location::StopAndWait => self.peripherals.propulsion_controller.stop(),
                x => {
                    self.log(Info::InvalidRouteConfiguration).await;
                    self.send_dp(
                        Datatype::NextPositionDebug,
                        x as u64,
                        self.route.current_position as u64,
                    )
                    .await;
                    transit!(self, State::Exit);
                },
            }
        }

        /// Only used in ForwardA, BackwardB, BackwardC positions.
        /// Tells levi which LS mode to use.
        pub async fn set_ls_mode(&mut self) {
            self.log(Info::SettingLSMode).await;
            match self.route.peek_next_position() {
                Location::LaneSwitchStraight => {
                    self.send_levi_cmd(Command::ls1(0)).await;
                    IN_A_LANE_SWITCH.store(false, Ordering::Relaxed);
                },
                Location::LaneSwitchCurved => {
                    self.send_levi_cmd(Command::ls2(0)).await;
                    IN_A_LANE_SWITCH.store(true, Ordering::Relaxed);
                },
                _ => self.send_levi_cmd(Command::ls0(0)).await,
            }
        }
    }
}

