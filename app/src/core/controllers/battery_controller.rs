use crate::core::communication::Datapoint;
use crate::core::controllers::ethernet_controller::EthernetPins;
use crate::{DataReceiver, DataSender, Datatype, EventSender};
use defmt::export::u64;
use defmt::{debug, info};
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
    high_voltage: bool,
    single_cell_id: u16,
    receive_single_cell_id: bool,
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
        high_voltage : bool,
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
            single_cell_id : 0,
            receive_single_cell_id: true,
        }
    }
}
pub struct GroundFaultDetection{

}

pub async fn ground_fault_detection_isolation_details(data: &[u8]) -> u64 {
    let negative_insulation_resistance = ((data[0] as u16) << 8) | (data[1] as u16);
    let positive_insulation_resistance = ((data[2] as u16) << 8) | (data[3] as u16);
    let original_insulation_resistance = ((data[4] as u16) << 8) | (data[5] as u16);
    let measurement_counter = data[6];
    let isolation_quality = data[7];
    let mut msg:u64 = 0;
    for (i, &x) in data.iter().enumerate() {
        msg |= (x as u64) << (i*8);
    }
    msg

}

pub async fn ground_fault_detection_voltage_details(data: &[u8]) -> u64 {
    let hv_voltage = ((data[0] as u16) << 8) | (data[1] as u16);
    let hv_voltage_negative_to_earth = ((data[2] as u16) << 8) | (data[3] as u16);
    let hv_voltage_positive_to_earth = ((data[4] as u16) << 8) | (data[5] as u16);
    let measurement_counter = data[6];
    let nothing = data[7];
    let mut msg:u64 = 0;
    for (i, &x) in data.iter().enumerate() {
        msg |= (x as u64) << (i*8);
    }
    msg

}

//===============BMS===============//

impl BatteryController {
    pub async fn bms_can_handle(
        &mut self,
        id: u16,
        data: &[u8],
        sender: DataSender,
        timestamp: u64,
    ) {
        debug!("Here BMS");
        match Datatype::from_id(id) {
            Datatype::DefaultBMSLow | Datatype::DefaultBMSHigh  => {
                self.default_bms_startup_info(data, timestamp).await;
                info!("Default BMS");
            }
            Datatype::BatteryVoltageLow | Datatype::BatteryVoltageHigh => {
                self.battery_voltage_overall_bms(data, timestamp).await;
                info!("Battery Voltage")
            }
            Datatype::DiagonosticBMSLow | Datatype::DiagonosticBMSHigh => {
                self.diagnostic_bms(data, timestamp).await;
                info!("Diagnostic BMS")

            }
            Datatype::BatteryTemperatureLow | Datatype::BatteryTemperatureHigh => {
                self.overall_temperature_bms(data, timestamp).await;
                info!("Battery Temperature")
            }
            Datatype::BatteryBalanceLow | Datatype::BatteryBalanceHigh => {
                self.overall_balancing_status_bms(data, timestamp).await;
                info!("Battery Balancing")
            }
            Datatype::ChargeStateLow | Datatype::ChargeStateHigh => {
                self.state_of_charge_bms(data, timestamp).await;
                info!("Charge State")
            }
            x if  Datatype::SingleCellTemperatureLow.to_id() == id || Datatype::SingleCellTemperatureHigh.to_id() == id => {
                if (self.receive_single_cell_id) {
                    self.single_cell_id = if x.to_id() == Datatype::SingleCellTemperatureHigh.to_id() { id- Datatype::SingleCellTemperatureHigh.to_id()} else {id- Datatype::SingleCellTemperatureLow.to_id()};
                    self.receive_single_cell_id = false;
                }
                else {
                    self.individual_temperature_bms(data, timestamp)
                        .await;
                    self.receive_single_cell_id = true;
                }
                info!("Individual Temperature")
            }
            x if Datatype::SingleCellVoltageLow.to_id() == id || Datatype::SingleCellVoltageHigh.to_id() == id => {
                if (self.receive_single_cell_id) {
                    self.single_cell_id = if x .to_id() == Datatype::SingleCellVoltageHigh.to_id() { id- Datatype::SingleCellVoltageHigh.to_id()} else {id- Datatype::SingleCellVoltageLow.to_id()};
                    self.receive_single_cell_id = false;
                }
                else {
                    self.individual_temperature_bms(data, timestamp)
                        .await;
                    self.receive_single_cell_id = true;
                }
                info!("Individual Voltage")
            }
            x =>{
                info!("Ignored BMS id: {:?}", x.to_id());
            }
        }
    }
    pub async fn battery_voltage_overall_bms(&mut self,data: &[u8],timestamp: u64){
        let min_cell_voltage = (data[0] as u16 +  200) ; //VOLTAGE scaled by 100
        //Should be a decimal number so multiplying it by 100 is not such a bad idea
        let max_cell_voltage = (data[1] as u16  +  200); //VOLTAGE
        let avg_cell_voltage = (data[0] as u16  +  200); //VOLTAGE
        let total_pack_voltage = ((((data[5]as u32) << 24) | ((data[6] as u32) << 16) | ((data[3] as u32) << 8) | (data[4] as u32) )+ 200); //VOLTAGE
        let battery_voltage_dt = if (self.high_voltage) {Datatype::BatteryVoltageHigh} else {Datatype::BatteryVoltageLow};
        let total_battery_voltage_dt = if (self.high_voltage) {Datatype::TotalBatteryVoltageHigh} else {Datatype::TotalBatteryVoltageLow};
        self.data_sender.send(Datapoint::new(battery_voltage_dt,(min_cell_voltage as u64) <<32 | (max_cell_voltage as u64) <<16 | avg_cell_voltage as u64,timestamp)).await;
        self.data_sender.send(Datapoint::new(total_battery_voltage_dt,total_pack_voltage as u64,timestamp)).await;
    }
    pub async fn default_bms_startup_info(&mut self,data: &[u8],timestamp: u64) {
        let dt = if (self.high_voltage) {Datatype::DefaultBMSHigh} else {Datatype::DefaultBMSLow};
        let mut msg:u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            msg |= (x as u64) << (i*8);
        }
        self.data_sender.send(Datapoint::new(dt,msg,timestamp)).await;

        // TO be dealt with in the ground station
    }
    pub async fn diagnostic_bms(&mut self,data: &[u8],timestamp: u64) {
        let dt = if (self.high_voltage) {Datatype::DiagonosticBMSHigh} else {Datatype::DiagonosticBMSLow};
        let mut msg:u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            msg |= (x as u64) << (i*8);
        }
        self.data_sender.send(Datapoint::new(dt,msg,timestamp)).await;
    }
    pub async fn state_of_charge_bms(&mut self, data: &[u8], timestamp: u64) {
        let current = ((data[1] as u16) << 8 | data[0] as u16); //AMPERES scaled by 10
        let estimated_charge = ((data[2] as u16) << 8 | data[3] as u16);//AMPERES
        let state_of_charge = data[6]; //PERCENTAGE
        let battery_current_dt = if (self.high_voltage) {Datatype::BatteryCurrentHigh} else {Datatype::BatteryCurrentLow};
        let charge_state_dt = if (self.high_voltage) {Datatype::ChargeStateHigh} else {Datatype::ChargeStateLow};

        self.data_sender
            .send(Datapoint::new(
                battery_current_dt,
                current as u64,
                timestamp,
            ))
            .await;
        self.data_sender
            .send(Datapoint::new(
                charge_state_dt,
                ((estimated_charge  as u64) << 8) | state_of_charge as u64,
                timestamp,
            ))
            .await;
    }

    pub async fn overall_temperature_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_temp = data[0]; //CELSIUS
        let max_temp = data[1]; //CELSIUS
        let avg_temp = data[2]; //CELSIUS
    //Take 100 out as it is base -100 so basically 115 means 15 degrees
        let battery_temp_dt = if (self.high_voltage) {Datatype::BatteryTemperatureHigh} else {Datatype::BatteryTemperatureLow};
        info!("test");
        self.data_sender
            .send(Datapoint::new(
                battery_temp_dt,
                (min_temp as u64) << 16 | (max_temp as u64) << 8 | avg_temp as u64,
                timestamp,
            ))
            .await;
    }

    pub async fn individual_temperature_bms(
        &mut self,
        data: &[u8],
        timestamp: u64,
    ) {

        let d = data.iter().for_each(|&x| {
            (x as u64);
        }); //CELSIUS base -100 C
        let mut n: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            let individual_temp_dt = if (self.high_voltage) {Datatype::SingleCellTemperatureHigh} else {Datatype::SingleCellTemperatureLow};
            self.data_sender
                .send(Datapoint::new(individual_temp_dt
                    ,
                    (self.single_cell_id as u64) << 16 | (n << 8) | x as u64,
                    timestamp,
                ))
                .await;
            n += 1;
        }
    }

    pub async fn individual_voltages_bms(&mut self, data: &[u8], timestamp: u64) {
        let mut n: u64 = 0;
        for (i, &x) in data.iter().enumerate() {
            let individual_voltage_dt = if (self.high_voltage) {Datatype::SingleCellTemperatureHigh} else {Datatype::SingleCellTemperatureLow};
            self.data_sender
                .send(Datapoint::new(
                    individual_voltage_dt,
                    (self.single_cell_id as u64) << 16 | (n << 8) | x as u64,
                    timestamp,
                ))
                .await;
            n += 1;
        }
    }

    pub async fn overall_balancing_status_bms(&mut self, data: &[u8], timestamp: u64) {
        let min_cell_balancing = data[0] as u64 / 255 * 100; //PERCENTAGE
        let max_cell_balancing = data[1] as u64 / 255 * 100; //PERCENTAGE
        let avg_cell_balancing = data[2] as u64 / 255 * 100; //PERCENTAGE
        let balancing_dt = if (self.high_voltage) {Datatype::BatteryBalanceHigh} else {Datatype::BatteryBalanceLow};
        self.data_sender
            .send(Datapoint::new(
                balancing_dt,
                (min_cell_balancing) << 16
                    | (max_cell_balancing) << 8
                    | avg_cell_balancing ,
                timestamp,
            ))
            .await;
    }
}
