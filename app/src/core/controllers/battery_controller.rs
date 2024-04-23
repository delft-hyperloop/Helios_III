use embassy_executor::Spawner;
use embassy_stm32::adc::Temperature;
use embedded_hal::can::{Id, StandardId};
use crate::{DataReceiver, EventSender};
use crate::core::controllers::ethernet_controller::EthernetPins;

pub struct BatteryController {
    sender: EventSender,
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
    ) -> Self {
        // Initialise anything needed by the battery controller here
        Self {
            sender,
            id,
            temperature_threshold: temperature,
            voltage_threshold: voltage,
            current_threshold: current,
            number_of_groups
        }
    }
}

pub struct BatteryPack{
    //TODO Add whatever we should add also once powertrain do their job
    //IMHO idk if it makes sense to keep all values here or if we should simply send all of them to the ground station as we have updates
    //Its something that can be debated but I dont see where changing keeping all of this makes sense, The only plausible reason would be to constantly add all new values to an
    //ETH packet to send them all at once which now that I think about it its quite smart to do
    id : u16
}
pub struct GroundFaultDetection{
    //TODO Add the treshoulds once powertrain do their job
}
pub async fn ground_fault_detection_isolation_details(data: &[u8]) {
    let negative_insulation_resistance= ((data[0] as u16) << 8) | (data[1] as u16);
    let positive_insulation_resistance = ((data[2] as u16)<< 8)  | (data[3] as u16);
    let original_insulation_resistance = ((data[4] as u16)<< 8)  | (data[5] as u16);
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
impl BatteryController{
    pub async fn bms_can_handle(&mut self, id: u16, data: &[u8]) {
        let own_id = self.id;
        // match id {
        //     Id::Standard(StandardId(x)) if x == own_id => {
        //         //TODO -> Default BMS Startup Info
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 1 => {
        //         //TODO -> Battery Voltage Overall
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 7 => {
        //         //TODO -> Balancing Status
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 2 => {
        //         //TODO -> Temperature Module
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 8 => {
        //         //TODO -> Temperature Overall
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 3 => {
        //         //TODO -> Balancing Status
        //     }
        //     Id::Standard(StandardId(x)) if x == own_id + 5 => {
        //         //TODO -> State of Charge
        //     }
        //     Id::Standard(StandardId(x)) if x <= own_id+32+self.number_of_groups as u16 => {
        //         //TODO -> Voltage Individual + 32
        //     }
        //     _=>{
        //         //TODO -> Temperature Individual + 256
        //     }
        // }
    }
    pub async fn battery_voltage_overall_bms(&mut self,data: &[u8]){
        let min_cell_voltage = (data[0] +  200) as u16; //VOLTAGE scaled by 100
        //Should be a decimal number so multiplying it by 100 is not such a bad idea
        let max_cell_voltage = (data[1] +  200) as u16; //VOLTAGE
        let avg_cell_voltage = (data[0] +  200) as u16; //VOLTAGE
        let total_pack_voltage = (((data[5] << 24) | (data[6] << 16) | (data[3] << 8) | data[4])+ 200) as u32; //VOLTAGE
    }

    pub async fn state_of_charge_bms(&mut self,data: &[u8]){
        let current = (data[1]<<8 | data[0]) as u16; //AMPERES scaled by 10
        let estimated_charge =  (data[2]<<8 | data[3]) as u16;//AMPERES
        let state_of_charge = data[6]; //PERCENTAGE
    }

    pub async fn overall_temperature_bms(&mut self,data: &[u8]){

        let min_temp = data[0] - 100; //CELSIUS
        let max_temp = data[1] - 100; //CELSIUS
        let avg_temp = data[2] - 100; //CELSIUS
    }

    pub async fn individual_temperature_bms(&mut self,data: &[u8],group_number: u8){
        let temp_1 = data[0] - 100; //CELSIUS
        let temp_2 = data[1] - 100; //CELSIUS
        let temp_3 = data[2] - 100; //CELSIUS
        let temp_4 = data[3] - 100; //CELSIUS
        let temp_5 = data[4] - 100; //CELSIUS
        let temp_6 = data[5] - 100; //CELSIUS
        let temp_7 = data[6] - 100; //CELSIUS
        let temp_8 = data[7] - 100; //CELSIUS
        // ^^^^^^^ This is Terrible ^^^^^^ //
    }

    pub async fn individual_voltages_bms(&mut self,data: &[u8],group_number: u8){
        let cell_1 = (data[0] +  200) as u16; //VOLTAGE scaled by 100
        let cell_2 = (data[1] +  200) as u16; //VOLTAGE
        let cell_3 = (data[2] +  200) as u16; //VOLTAGE
        let cell_4 = (data[3] +  200) as u16; //VOLTAGE
        let cell_5 = (data[4] +  200) as u16; //VOLTAGE
        let cell_6 = (data[5] +  200) as u16; //VOLTAGE
        let cell_7 = (data[6] +  200) as u16; //VOLTAGE
        let cell_8 = (data[7] +  200) as u16; //VOLTAGE
        // ^^^^^^^ This is Terrible ^^^^^^ //
    }

    pub async fn overall_balancing_status_bms(&mut self,data: &[u8]){
        let min_cell_balancing = data[0]/255*100; //PERCENTAGE
        let max_cell_balancing = data[1]/255*100; //PERCENTAGE
        let avg_cell_balancing = data[2]/255*100; //PERCENTAGE
    }


}





