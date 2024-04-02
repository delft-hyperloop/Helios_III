//TODO
// This file is just an idea butttt, we could make the can tasks here or go like fuck it they stay on the fsm peripherals which i also am considering renaming as i really dont like the name //




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
    let negative_isolation_resistance= ((data[0] as u16) << 8) | (data[1] as u16);
    let positive_isolation_resistance = ((data[2] as u16)<< 8)  | (data[3] as u16);
    let original_isolation_resistance = ((data[4] as u16)<< 8)  | (data[5] as u16);
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

pub async fn battery_voltage_overall_bms(data: &[u8]){
    let min_cell_voltage = (data[0] +  200) as u16; //VOLTAGE scaled by 100
    //Should be a decimal number so multiplying it by 100 is not such a bad idea
    let max_cell_voltage = (data[1] +  200) as u16; //VOLTAGE
    let avg_cell_voltage = (data[0] +  200) as u16; //VOLTAGE
    let total_pack_voltage = (((data[5] << 24) | (data[6] << 16) | (data[3] << 8) | data[4])+ 200) as u32; //VOLTAGE
    }

pub async fn state_of_charge_bms(data: &[u8]){
    let current = (data[1]<<8 | data[0]) as u16; //AMPERES scaled by 10
    let estimated_charge =  (data[2]<<8 | data[3]) as u16;//AMPERES
    let state_of_charge = data[6]; //PERCENTAGE
}

pub async fn overall_temperature_bms(data: &[u8]){
    let min_temp = data[0] - 100; //CELSIUS
    let max_temp = data[1] - 100; //CELSIUS
    let avg_temp = data[2] - 100; //CELSIUS
}

pub async fn individual_temperature_bms(data: &[u8]){
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

pub async fn individual_voltages_bms(data: &[u8]){
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

pub async fn overall_balancing_status_bms(data: &[u8]){
    let min_cell_balancing = data[0]/255*100; //PERCENTAGE
    let max_cell_balancing = data[1]/255*100; //PERCENTAGE
    let avg_cell_balancing = data[2]/255*100; //PERCENTAGE
}






