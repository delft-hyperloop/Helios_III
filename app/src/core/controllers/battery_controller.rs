use defmt::{debug, trace};
use defmt::info;

use crate::core::communication::Datapoint;
use crate::pconfig::{bytes_to_u64, queue_data, queue_dp};
use crate::DataSender;
use crate::Datatype;
use crate::EventSender;

#[allow(dead_code)]
pub struct BatteryController {
    sender: EventSender,
    data_sender: DataSender,
    id: u16,
    temperature_threshold: u8,
    voltage_threshold: u16,
    current_threshold: u16,
    number_of_groups: u8,
    high_voltage: bool,
    single_cell_id: u16,
    receive_single_cell_id: bool,
    current_number_of_cells: usize,
    module_buffer: [u64; 14],
    temp_buffer: [u64; 112],
    voltage_buffer: [u64; 112],
    number_of_temp: u8,
    number_of_volt: u8,
}

impl BatteryController {
    /// parameters needed:
    /// - x: Spawner, to create the tasks that actually do stuff
    /// - sender: EventSender, to send events to the FSM
    /// - ?
    pub fn new(
        sender: EventSender,
        temperature: u8,
        voltage: u16,
        current: u16,
        id: u16,
        number_of_groups: u8,
        data_sender: DataSender,
        high_voltage: bool,
    ) -> Self {
        // Initialise anything needed by the battery controller here
        Self {
            sender,
            id,
            temperature_threshold: temperature,
            voltage_threshold: voltage,
            current_threshold: current,
            number_of_groups,
            data_sender,
            high_voltage,
            single_cell_id: 0,
            receive_single_cell_id: true,
            current_number_of_cells: 0,
            module_buffer: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            temp_buffer: [0; 112],
            voltage_buffer: [0; 112],
            number_of_temp: 0,
            number_of_volt: 0,
        }
    }
}
pub struct GroundFaultDetection {}

pub async fn ground_fault_detection_isolation_details(
    data: &[u8],
    data_sender: DataSender,
    t: u64,
) {
    let negative_insulation_resistance = ((data[1] as u64) << 8) | (data[0] as u64);
    queue_dp(data_sender, Datatype::InsulationNegative, negative_insulation_resistance, t).await;
    let positive_insulation_resistance = ((data[3] as u64) << 8) | (data[2] as u64);
    queue_dp(data_sender, Datatype::InsulationPositive, positive_insulation_resistance, t).await;

    let original_measurement_counter = data[4] as u64 | ((data[5] as u64) << 8);
    queue_dp(data_sender, Datatype::InsulationOriginal, original_measurement_counter, t).await;
}

pub async fn ground_fault_detection_voltage_details(
    data: &[u8],
    data_sender: DataSender,
    timestamp: u64,
) {
    let hv_voltage = ((data[1] as u64) << 8) | (data[0] as u64);
    queue_dp(data_sender, Datatype::IMDVoltageDetails, hv_voltage, timestamp).await;
}

//===============BMS===============//

impl BatteryController {
    pub async fn bms_can_handle(
        &mut self,
        id: u16,
        data: &[u8],
        _sender: DataSender,
        timestamp: u64,
    ) {
        trace!("Here BMS");
        match Datatype::from_id(id) {
            Datatype::DefaultBMSLow | Datatype::DefaultBMSHigh => {
                self.default_bms_startup_info(data, timestamp).await;
                debug!("Default BMS");
            },
            Datatype::BatteryVoltageLow | Datatype::BatteryVoltageHigh => {
                self.battery_voltage_overall_bms(data, timestamp).await;
                debug!("Battery Voltage")
            },
            Datatype::DiagnosticBMSLow | Datatype::DiagnosticBMSHigh => {
                self.diagnostic_bms(data, timestamp).await;
                debug!("Diagnostic BMS")
            },
            Datatype::BatteryTemperatureLow | Datatype::BatteryTemperatureHigh => {
                self.overall_temperature_bms(data, timestamp).await;
                debug!("Battery Temperature")
            },
            Datatype::BatteryBalanceLow | Datatype::BatteryBalanceHigh => {
                self.overall_balancing_status_bms(data, timestamp).await;
                debug!("Battery Balancing")
            },
            Datatype::ChargeStateLow | Datatype::ChargeStateHigh => {
                self.state_of_charge_bms(data, timestamp).await;
                debug!("Charge State")
            },
            _x if Datatype::SingleCellTemperatureLow.to_id() == id
                || (Datatype::SingleCellTemperatureHigh_1.to_id() <= id
                    && Datatype::SingleCellTemperatureHigh_14.to_id() >= id) =>
            {
                debug!("Individual Temperature");
                if self.number_of_temp >= 13 {
                    self.number_of_temp = 0;
                    let mut i = 0;
                    while i < 8 {
                        self.single_cell_id = i;
                        let a = &self.temp_buffer[(i * 14) as usize..((i + 1) * 14) as usize];
                        // Initialize a new fixed-size array
                        let mut temp: [u64; 14] = [0; 14];

                        temp.copy_from_slice(a);
                        // Copy the elements from the slice to the fixed-size array
                        self.module_buffer = temp;
                        self.send_module_temp(timestamp).await;
                        i += 1;
                    }
                }
                if Datatype::SingleCellTemperatureLow.to_id() == id {
                    // self.overall_temperature_bms(&*Self::single_cell_low_process(data).await,timestamp);
                } else {
                    let module_id =
                        ((id - Datatype::SingleCellTemperatureHigh_1.to_id()) * 8) as usize;
                    for (i, &x) in data.iter().enumerate() {
                        self.temp_buffer[module_id + i] = x as u64;
                    }
                    self.number_of_temp += 1;
                }

                debug!("Individual Temperature")
            },
            _x if Datatype::SingleCellVoltageLow.to_id() == id
                || (Datatype::SingleCellVoltageHigh_1.to_id() <= id
                    && Datatype::SingleCellVoltageHigh_14.to_id() >= id) =>
            {
                if self.number_of_volt >= 13 {
                    self.number_of_volt = 0;
                    let mut i = 0;
                    while i < 8 {
                        self.single_cell_id = i;
                        let a = &self.voltage_buffer[(i * 14) as usize..((i + 1) * 14) as usize];
                        // Initialize a new fixed-size array
                        let mut temp: [u64; 14] = [0; 14];

                        temp.copy_from_slice(a);
                        // Copy the elements from the slice to the fixed-size array
                        self.module_buffer = temp;
                        self.send_module_voltage(timestamp).await;
                        i += 1;
                    }
                }
                if Datatype::SingleCellVoltageLow.to_id() == id {
                    // self.overall_temperature_bms(&*Self::single_cell_low_process(data).await,timestamp);
                } else {
                    let module_id = ((id - Datatype::SingleCellVoltageHigh_1.to_id()) * 8) as usize;
                    for (i, &x) in data.iter().enumerate() {
                        if x != 0 {
                            self.voltage_buffer[module_id + i] = x as u64;
                        }
                    }
                    self.number_of_volt += 1;
                }

                debug!("Individual Voltage")
            },
            Datatype::BatteryEventLow | Datatype::BatteryEventHigh => {
                self.event_bms(data, timestamp).await;
                debug!("Battery Event")
            },
            x => {
                debug!("Ignored BMS: {:?} (id={:?})", x, x.to_id());
            },
        }
    }

    pub async fn event_bms(&mut self, data: &[u8], timestamp: u64) {
        // let mut msg: u64 = 0;
        let dt =
            if self.high_voltage { Datatype::BatteryEventHigh } else { Datatype::BatteryEventLow };
        queue_dp(self.data_sender, dt, bytes_to_u64(data), timestamp).await;
    }

    pub async fn battery_voltage_overall_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_cell_voltage = data[0] as u64 + 200; //VOLTAGE scaled by 100
        //Should be a decimal number so multiplying it by 100 is not such a bad idea
        let max_cell_voltage = data[1] as u64 + 200; //VOLTAGE
        let avg_cell_voltage = data[0] as u64 + 200; //VOLTAGE
        let total_pack_voltage = (((data[5] as u64) << 24)
            | ((data[6] as u64) << 16)
            | ((data[3] as u64) << 8)
            | (data[4] as u64))
            + 200; //VOLTAGE
        let battery_voltage_dt = if self.high_voltage {
            Datatype::BatteryVoltageHigh
        } else {
            Datatype::BatteryVoltageLow
        };
        let battery_voltage_min = if self.high_voltage {
            Datatype::BatteryMinVoltageHigh
        } else {
            Datatype::BatteryMinVoltageLow
        };
        let battery_voltage_max = if self.high_voltage {
            Datatype::BatteryMaxVoltageHigh
        } else {
            Datatype::BatteryMaxVoltageLow
        };
        let total_battery_voltage_dt = if self.high_voltage {
            Datatype::TotalBatteryVoltageHigh
        } else {
            Datatype::TotalBatteryVoltageLow
        };
        queue_dp(self.data_sender, battery_voltage_dt, avg_cell_voltage, timestamp).await;
        queue_dp(self.data_sender, battery_voltage_min, min_cell_voltage, timestamp).await;
        queue_dp(self.data_sender, battery_voltage_max, max_cell_voltage, timestamp).await;
        queue_dp(self.data_sender, total_battery_voltage_dt, total_pack_voltage, timestamp).await;
    }

    pub async fn default_bms_startup_info(&mut self, data: &[u8], timestamp: u64) {
        let dt = if self.high_voltage { Datatype::DefaultBMSHigh } else { Datatype::DefaultBMSLow };
        let mut msg: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            msg |= (x as u64) << (i * 8);
        }
        self.data_sender.send(Datapoint::new(dt, msg, timestamp)).await;
    }

    pub async fn diagnostic_bms(&mut self, data: &[u8], timestamp: u64) {
        let dt = if self.high_voltage {
            Datatype::DiagnosticBMSHigh
        } else {
            Datatype::DiagnosticBMSLow
        };
        let mut msg: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            msg |= (x as u64) << (i * 8);
        }
        queue_dp(self.data_sender, dt, msg, timestamp).await;
    }

    pub async fn state_of_charge_bms(&mut self, data: &[u8], timestamp: u64) {
        let current = (data[0] as u64) << 8 | data[1] as u64; //AMPERES scaled by 0.1
        let estimated_charge = (data[2] as u64) << 8 | data[3] as u64; //AMPERES
        let state_of_charge = (data[5] as u64) << 8 | data[6] as u64; //PERCENTAGE
        let battery_current_dt = if self.high_voltage {
            Datatype::BatteryCurrentHigh
        } else {
            Datatype::BatteryCurrentLow
        };
        let charge_state_dt =
            if self.high_voltage { Datatype::ChargeStateHigh } else { Datatype::ChargeStateLow };
        let estimated_charge_dt = if self.high_voltage {
            Datatype::BatteryEstimatedChargeHigh
        } else {
            Datatype::BatteryEstimatedChargeLow
        };

        queue_dp(self.data_sender, battery_current_dt, current, timestamp).await;
        queue_dp(self.data_sender, charge_state_dt, state_of_charge, timestamp).await;
        queue_dp(self.data_sender, estimated_charge_dt, estimated_charge, timestamp).await;
    }

    pub async fn overall_temperature_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_temp = (data[0]) as u64; //CELSIUS
        let max_temp = (data[1]) as u64; //CELSIUS
        let avg_temp = (data[2]) as u64; //CELSIUS
                                         //Take 100 out as it is base -100 so basically 115 means 15 degrees
        let battery_temp_dt = if self.high_voltage {
            Datatype::BatteryTemperatureHigh
        } else {
            Datatype::BatteryTemperatureLow
        };
        let battery_temp_min = if self.high_voltage {
            Datatype::BatteryMinTemperatureHigh
        } else {
            Datatype::BatteryMinTemperatureLow
        };
        let battery_temp_max = if self.high_voltage {
            Datatype::BatteryMaxTemperatureHigh
        } else {
            Datatype::BatteryMaxTemperatureLow
        };

        queue_dp(self.data_sender, battery_temp_dt, avg_temp, timestamp).await;
        queue_dp(self.data_sender, battery_temp_min, min_temp, timestamp).await;
        queue_dp(self.data_sender, battery_temp_max, max_temp, timestamp).await;
    }

    /*pub async fn individual_temperature_bms(&mut self, data: &[u8], timestamp: u64) {
        for &x in data.iter() {
            if self.single_cell_id < 8 {
                self.module_buffer[self.current_number_of_cells] = x as u64;
                if self.current_number_of_cells == 13 {
                    self.current_number_of_cells = 0;
                    self.send_module_temp(timestamp).await;
                    info!("Module {:?} Temperature sent", self.single_cell_id + 1);
                    self.single_cell_id += 1;
                } else {
                    self.current_number_of_cells += 1;
                }
            } else {
                self.single_cell_id = 0;
                self.receive_single_cell_id = true;
                self.module_buffer = [0; 14];
                break;
            }
        }
    }*/

    async fn send_module_temp(&mut self, timestamp: u64) {
        let module_id = self.single_cell_id;
        let (min_temp, max_temp, avg_temp) =
            Self::module_data_calculation(self.module_buffer).await;
        let (avg_temp_dt, min_temp_dt, max_temp_dt) = Self::match_temp(module_id).await;
        queue_dp(self.data_sender, avg_temp_dt, avg_temp, timestamp).await;
        queue_dp(self.data_sender, min_temp_dt, min_temp, timestamp).await;
        queue_dp(self.data_sender, max_temp_dt, max_temp, timestamp).await;
    }

    async fn send_module_voltage(&mut self, timestamp: u64) {
        let module_id = self.single_cell_id;
        let (min_voltage, max_voltage, avg_voltage) =
            Self::module_data_calculation(self.module_buffer).await;
        let (avg_voltage_dt, min_voltage_dt, max_voltage_dt) = Self::match_voltage(module_id).await;
        queue_dp(self.data_sender, avg_voltage_dt, avg_voltage + 200, timestamp).await;
        queue_dp(self.data_sender, min_voltage_dt, min_voltage + 200, timestamp).await;
        queue_dp(self.data_sender, max_voltage_dt, max_voltage + 200, timestamp).await;
    }

    pub async fn match_temp(id: u16) -> (Datatype, Datatype, Datatype) {
        match id {
            0 => (
                Datatype::Module1AvgTemperature,
                Datatype::Module1MinTemperature,
                Datatype::Module1MaxTemperature,
            ),
            1 => (
                Datatype::Module2AvgTemperature,
                Datatype::Module2MinTemperature,
                Datatype::Module2MaxTemperature,
            ),
            2 => (
                Datatype::Module3AvgTemperature,
                Datatype::Module3MinTemperature,
                Datatype::Module3MaxTemperature,
            ),
            3 => (
                Datatype::Module4AvgTemperature,
                Datatype::Module4MinTemperature,
                Datatype::Module4MaxTemperature,
            ),
            4 => (
                Datatype::Module5AvgTemperature,
                Datatype::Module5MinTemperature,
                Datatype::Module5MaxTemperature,
            ),
            5 => (
                Datatype::Module6AvgTemperature,
                Datatype::Module6MinTemperature,
                Datatype::Module6MaxTemperature,
            ),
            6 => (
                Datatype::Module7AvgTemperature,
                Datatype::Module7MinTemperature,
                Datatype::Module7MaxTemperature,
            ),
            7 => (
                Datatype::Module8AvgTemperature,
                Datatype::Module8MinTemperature,
                Datatype::Module8MaxTemperature,
            ),
            _ => (Datatype::DefaultDatatype, Datatype::DefaultDatatype, Datatype::DefaultDatatype),
        }
    }

    pub async fn match_voltage(id: u16) -> (Datatype, Datatype, Datatype) {
        match id {
            0 => (
                Datatype::Module1AvgVoltage,
                Datatype::Module1MinVoltage,
                Datatype::Module1MaxVoltage,
            ),
            1 => (
                Datatype::Module2AvgVoltage,
                Datatype::Module2MinVoltage,
                Datatype::Module2MaxVoltage,
            ),
            2 => (
                Datatype::Module3AvgVoltage,
                Datatype::Module3MinVoltage,
                Datatype::Module3MaxVoltage,
            ),
            3 => (
                Datatype::Module4AvgVoltage,
                Datatype::Module4MinVoltage,
                Datatype::Module4MaxVoltage,
            ),
            4 => (
                Datatype::Module5AvgVoltage,
                Datatype::Module5MinVoltage,
                Datatype::Module5MaxVoltage,
            ),
            5 => (
                Datatype::Module6AvgVoltage,
                Datatype::Module6MinVoltage,
                Datatype::Module6MaxVoltage,
            ),
            6 => (
                Datatype::Module7AvgVoltage,
                Datatype::Module7MinVoltage,
                Datatype::Module7MaxVoltage,
            ),
            7 => (
                Datatype::Module8AvgVoltage,
                Datatype::Module8MinVoltage,
                Datatype::Module8MaxVoltage,
            ),
            _ => (Datatype::DefaultDatatype, Datatype::DefaultDatatype, Datatype::DefaultDatatype),
        }
    }

    pub async fn module_data_calculation(data: [u64; 14]) -> (u64, u64, u64) {
        let mut min: u64 = 1000;
        let mut max: u64 = 0;
        let mut avg: u64 = 0;
        let mut n = 14;
        for &x in data.iter() {
            if x == 0 {
                n -= 1;
                continue;
            }
            if (x) < min {
                min = x;
            }
            if (x) > max {
                max = x;
            }
            avg += x;
        }
        if n == 0 {
            n = 1
        }
        avg /= n;
        if min == 1000 {
            min = 0;
        }
        (min, max, avg)
    }

    pub async fn individual_voltages_bms(&mut self, data: &[u8], timestamp: u64) {
        for &x in data.iter() {
            if self.single_cell_id < 8 {
                self.module_buffer[self.current_number_of_cells] = x as u64;
                if self.current_number_of_cells == 13 {
                    self.current_number_of_cells = 0;
                    self.send_module_voltage(timestamp).await;
                    self.single_cell_id += 1;
                } else {
                    self.current_number_of_cells += 1;
                }
            } else {
                self.single_cell_id = 0;
                self.receive_single_cell_id = true;
                self.module_buffer = [0; 14];
                break;
            }
        }
    }

    pub async fn overall_balancing_status_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_cell_balancing = data[0] as u64 / 255 * 100; //PERCENTAGE
        let max_cell_balancing = data[1] as u64 / 255 * 100; //PERCENTAGE
        let avg_cell_balancing = data[2] as u64 / 255 * 100; //PERCENTAGE
        let balancing_dt = if self.high_voltage {
            Datatype::BatteryBalanceHigh
        } else {
            Datatype::BatteryBalanceLow
        };
        let balancing_min = if self.high_voltage {
            Datatype::BatteryMinBalancingHigh
        } else {
            Datatype::BatteryMinBalancingLow
        };
        let balancing_max = if self.high_voltage {
            Datatype::BatteryMaxBalancingHigh
        } else {
            Datatype::BatteryMaxBalancingLow
        };
        queue_dp(self.data_sender, balancing_dt, avg_cell_balancing, timestamp).await;
        queue_dp(self.data_sender, balancing_min, min_cell_balancing, timestamp).await;
        queue_dp(self.data_sender, balancing_max, max_cell_balancing, timestamp).await;
    }
}
