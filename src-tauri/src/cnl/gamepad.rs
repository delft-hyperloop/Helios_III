use std::sync::Arc;

use canzero_config::config::{message::MessageUsage, MessageRef, NetworkRef, SignalType};
use color_print::cprintln;
use gilrs::{Button, Event, Gilrs};

use super::tx::TxCom;

pub struct Gamepad {}

impl Gamepad {
    pub fn create(tx: &Arc<TxCom>, config: &NetworkRef) -> std::io::Result<Gamepad> {
        let gilrs = gilrs::Gilrs::new().map_err(|_| {
            std::io::Error::new(
                std::io::ErrorKind::InvalidInput,
                "Failed to initalize gilrs".to_owned(),
            )
        })?;

        let msg = config
            .messages()
            .iter()
            .find(|m| m.name() == "gamepad_stream_input");
        match msg {
            Some(msg) => {
                tokio::spawn(Self::gamepad_task(tx.clone(), gilrs, msg.clone()));
            }
            None => (),
        }

        Ok(Self {})
    }

    pub async fn gamepad_task(tx: Arc<TxCom>, mut gilrs: Gilrs, msg: MessageRef) {
        let MessageUsage::Stream(stream) = msg.usage() else {
            cprintln!(
                "<red>message {} is not a stream message. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        let lt2_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_lt2")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: lt2_offset,
            scale: lt2_scale,
        } = lt2_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let rt2_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_rt2")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: rt2_offset,
            scale: rt2_scale,
        } = rt2_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let lsb_x_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_lsb_x")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: lsb_x_offset,
            scale: lsb_x_scale,
        } = lsb_x_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let lsb_y_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_lsb_y")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: lsb_y_offset,
            scale: lsb_y_scale,
        } = lsb_y_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let rsb_x_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_rsb_x")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: rsb_x_offset,
            scale: rsb_x_scale,
        } = rsb_x_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let rsb_y_signal = msg
            .signals()
            .iter()
            .find(|s| s.name() == "value_name_rsb_y")
            .unwrap();
        let SignalType::Decimal {
            size,
            offset: rsb_y_offset,
            scale: rsb_y_scale,
        } = rsb_y_signal.ty()
        else {
            cprintln!(
                "<red>message {} ill formed. Disabling gamepad controller</red>",
                msg.name()
            );
            return;
        };
        assert_eq!(*size, 8);

        let mut interval = tokio::time::interval(*stream.min_interval());
        let mut connected_count = 0usize;
        let mut left_trigger = 0f32;
        let mut right_trigger = 0f32;
        let mut x_down = false;
        let mut y_down = false;
        let mut a_down = false;
        let mut b_down = false;
        let mut lt_down = false;
        let mut rt_down = false;
        let mut lsb_down = false;
        let mut rsb_down = false;
        let mut lsb_x = 0f32;
        let mut lsb_y = 0f32;
        let mut rsb_x = 0f32;
        let mut rsb_y = 0f32;
        loop {
            interval.tick().await;
            // Examine new events
            while let Some(Event {
                id: _,
                event,
                time: _,
            }) = gilrs.next_event()
            {
                match event {
                    gilrs::EventType::Connected => {
                        cprintln!("<green>Gamepad connected</green>");
                        connected_count += 1;
                        if connected_count > 1 {
                            cprintln!("<yellow>Gamepad input will be ignored if more than one gamepad is connected</yellow>");
                        }
                    }
                    gilrs::EventType::Disconnected => {
                        cprintln!("<yellow>Gamepad disconnected</yellow>");
                        left_trigger = 0.0;
                        right_trigger = 0.0;
                        x_down = false;
                        y_down = false;
                        a_down = false;
                        b_down = false;
                        lt_down = false;
                        rt_down = false;
                        lsb_down = false;
                        rsb_down = false;
                        lsb_x = 0f32;
                        lsb_y = 0f32;
                        rsb_x = 0f32;
                        rsb_y = 0f32;
                        connected_count -= 1;
                    }
                    gilrs::EventType::AxisChanged(axis, value, _) => match axis {
                        gilrs::Axis::LeftStickX => {
                            lsb_x = value;
                        }
                        gilrs::Axis::LeftStickY => {
                            lsb_y = value;
                        }
                        gilrs::Axis::RightStickX => {
                            rsb_x = value;
                        }
                        gilrs::Axis::RightStickY => {
                            rsb_y = value;
                        }
                        _ => (),
                    },
                    gilrs::EventType::ButtonChanged(button, value, _) => match button {
                        Button::LeftTrigger2 => {
                            left_trigger = value;
                        }
                        Button::RightTrigger2 => {
                            right_trigger = value;
                        }
                        _ => continue,
                    },
                    gilrs::EventType::ButtonPressed(button, _) => match button {
                        Button::South => {
                            a_down = true;
                        }
                        Button::East => {
                            b_down = true;
                        }
                        Button::North => {
                            y_down = true;
                        }
                        Button::West => {
                            x_down = true;
                        }
                        Button::LeftTrigger => {
                            lt_down = true;
                        }
                        Button::RightTrigger => {
                            rt_down = true;
                        }
                        Button::LeftThumb => {
                            lsb_down = true;
                        }
                        Button::RightThumb => {
                            rsb_down = true;
                        }
                        _ => (),
                    },
                    gilrs::EventType::ButtonReleased(button, _) => match button {
                        Button::South => {
                            a_down = false;
                        }
                        Button::East => {
                            b_down = false;
                        }
                        Button::North => {
                            y_down = false;
                        }
                        Button::West => {
                            x_down = false;
                        }
                        Button::LeftTrigger => {
                            lt_down = false;
                        }
                        Button::RightTrigger => {
                            rt_down = false;
                        }
                        Button::LeftThumb => {
                            lsb_down = false;
                        }
                        Button::RightThumb => {
                            rsb_down = false;
                        }
                        _ => (),
                    },
                    _ => continue,
                }
            }
            if connected_count == 1 {
                println!("{}", rsb_x_signal.byte_offset());
                let mut data = [0u8; 8];
                data[0] = ((left_trigger as f64 - *lt2_offset) / *lt2_scale).round() as u8;
                data[1] = ((right_trigger as f64 - *rt2_offset) / *rt2_scale).round() as u8;
                data[2] = ((lsb_x as f64 - *lsb_x_offset) / *lsb_x_scale).round() as u8;
                data[3] = ((lsb_y as f64 - *lsb_y_offset) / *lsb_y_scale).round() as u8;
                data[4] = ((rsb_x as f64 - *rsb_x_offset) / *rsb_x_scale).round() as u8;
                data[5] = ((rsb_y as f64 - *rsb_y_offset) / *rsb_y_scale).round() as u8;
                data[6] = 0;
                if lt_down {
                    data[6] |= 1;
                }
                if rt_down {
                    data[6] |= 2;
                }
                if x_down {
                    data[6] |= 4;
                }
                if y_down {
                    data[6] |= 8;
                }
                if b_down {
                    data[6] |= 16;
                }
                if a_down {
                    data[6] |= 32;
                }
                if lsb_down {
                    data[6] |= 64;
                }
                if rsb_down {
                    data[6] |= 128;
                }

                tx.send_native(&msg, unsafe { std::mem::transmute(data) })
                    .await;
            }
        }
    }
}
