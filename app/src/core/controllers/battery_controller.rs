use crate::core::communication::Datapoint;
use crate::core::controllers::ethernet_controller::EthernetPins;
use crate::{DataReceiver, DataSender, Datatype, EventSender};
use defmt::export::u64;
use embassy_executor::Spawner;
use embassy_stm32::adc::Temperature;
use embassy_stm32::can::Timestamp;
use embassy_time::Instant;
use embedded_hal::can::{Id, StandardId};

pub struct BatteryController {
    sender: EventSender,
    data_sender: DataSender,
    id: u16,
    temperature_threshold: u8,
    voltage_threshold: u16,
    current_threshold: u16,
    number_of_groups: u8,
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
        }
    }
}

pub struct BatteryPack {
    //TODO Add whatever we should add also once powertrain do their job
    //IMHO idk if it makes sense to keep all values here or if we should simply send all of them to the ground station as we have updates
    //Its something that can be debated but I dont see where changing keeping all of this makes sense, The only plausible reason would be to constantly add all new values to an
    //ETH packet to send them all at once which now that I think about it its quite smart to do
    id: u16,
}
pub struct GroundFaultDetection {
    //TODO Add the treshoulds once powertrain do their job
}
pub async fn ground_fault_detection_isolation_details(data: &[u8]) {
    let negative_insulation_resistance = ((data[0] as u16) << 8) | (data[1] as u16);
    let positive_insulation_resistance = ((data[2] as u16) << 8) | (data[3] as u16);
    let original_insulation_resistance = ((data[4] as u16) << 8) | (data[5] as u16);
    let measurement_counter = data[6];
    let isolation_quality = data[7];
    //TODO -> Do something here rn im just doing this for the sake of organization;
}

//===============BMS===============//
pub async fn default_bms_startup_info(data: &[u8]) {
    //Messy guy ill leave it for later
}
pub async fn diagnostic_bms(data: &[u8]) {
    //Messy guy ill leave it for later
}
impl BatteryController {
    pub async fn bms_can_handle(
        &mut self,
        id: u16,
        data: &[u8],
        sender: DataSender,
        timestamp: u64,
    ) {
        let own_id = self.id;
        match id {
            x if x == own_id => {
                //TODO -> Default BMS Startup Info
            }
            x if x == own_id + 1 => {
                self.battery_voltage_overall_bms(data, timestamp).await;
            }
            x if x == own_id + 7 => {
                //TODO -> Diagnostic BMS
            }
            x if x == own_id + 8 => {
                self.overall_temperature_bms(data, timestamp).await;
            }
            x if x == own_id + 3 => {
                self.overall_balancing_status_bms(data, timestamp).await;
            }
            x if x == own_id + 5 => {
                self.state_of_charge_bms(data, timestamp).await;
            }
            x if x <= own_id + 32 + self.number_of_groups as u16 => {
                self.individual_voltages_bms(data, (x - own_id - 32) as u8, timestamp)
                    .await;
            }
            x => {
                self.individual_temperature_bms(data, (x - own_id - 256) as u8, timestamp)
                    .await;
            }
        }
    }
    pub async fn battery_voltage_overall_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_cell_voltage = (data[0] + 200) as u16; //VOLTAGE scaled by 100
                                                       //Should be a decimal number so multiplying it by 100 is not such a bad idea
        let max_cell_voltage = (data[1] + 200) as u16; //VOLTAGE
        let avg_cell_voltage = (data[0] + 200) as u16; //VOLTAGE
        let total_pack_voltage =
            (((data[5] << 24) | (data[6] << 16) | (data[3] << 8) | data[4]) + 200) as u32; //VOLTAGE
        self.data_sender
            .send(Datapoint::new(
                Datatype::BatteryVoltage,
                (min_cell_voltage as u64) << 32
                    | (max_cell_voltage as u64) << 16
                    | avg_cell_voltage as u64,
                timestamp,
            ))
            .await;
        self.data_sender
            .send(Datapoint::new(
                Datatype::TotalBatteryVoltage,
                total_pack_voltage as u64,
                timestamp,
            ))
            .await;
    }

    pub async fn state_of_charge_bms(&mut self, data: &[u8], timestamp: u64) {
        let current = (data[1] << 8 | data[0]) as u16; //AMPERES scaled by 10
        let estimated_charge = (data[2] << 8 | data[3]) as u16; //AMPERES
        let state_of_charge = data[6]; //PERCENTAGE
        self.data_sender
            .send(Datapoint::new(
                Datatype::BatteryCurrent,
                current as u64,
                timestamp,
            ))
            .await;
        self.data_sender
            .send(Datapoint::new(
                Datatype::ChargeState,
                (estimated_charge << 8) as u64 | state_of_charge as u64,
                timestamp,
            ))
            .await;
    }

    pub async fn overall_temperature_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_temp = data[0] - 100; //CELSIUS
        let max_temp = data[1] - 100; //CELSIUS
        let avg_temp = data[2] - 100; //CELSIUS
        self.data_sender
            .send(Datapoint::new(
                Datatype::BatteryTemperature,
                (min_temp as u64) << 16 | (max_temp as u64) << 8 | avg_temp as u64,
                timestamp,
            ))
            .await;
    }

    pub async fn individual_temperature_bms(
        &mut self,
        data: &[u8],
        group_number: u8,
        timestamp: u64,
    ) {
        let d = data.iter().for_each(|&x| {
            x - 100;
        }); //CELSIUS base -100 C
        let mut n: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            self.data_sender
                .send(Datapoint::new(
                    Datatype::SingleCellTemperature,
                    (group_number as u64) << 16 | (n << 8) | x as u64,
                    timestamp,
                ))
                .await;
            n += 1;
        }
    }

    pub async fn individual_voltages_bms(&mut self, data: &[u8], group_number: u8, timestamp: u64) {
        let mut n: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            self.data_sender
                .send(Datapoint::new(
                    Datatype::SingleCellVoltage,
                    (group_number as u64) << 16 | (n << 8) | x as u64,
                    timestamp,
                ))
                .await;
            n += 1;
        }
    }

    pub async fn overall_balancing_status_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_cell_balancing = data[0] / 255 * 100; //PERCENTAGE
        let max_cell_balancing = data[1] / 255 * 100; //PERCENTAGE
        let avg_cell_balancing = data[2] / 255 * 100; //PERCENTAGE
        self.data_sender
            .send(Datapoint::new(
                Datatype::BatteryBalance,
                (min_cell_balancing as u64) << 16
                    | (max_cell_balancing as u64) << 8
                    | avg_cell_balancing as u64,
                timestamp,
            ))
            .await;
    }
}
