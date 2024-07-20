<script lang="ts">
  import {Battery, Table, FSM, TileGrid, Tile, Command, GrandDataDistributor, Localiser, Store} from "$lib";
    import {AppBar, getToastStore} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {invoke} from "@tauri-apps/api/tauri";
    import {DatatypeEnum as DE} from "$lib/namedDatatypeEnum";
  import {LOCALISATION_NAME, STATUS} from "$lib/types";

    let width: number;

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lvBattery = storeManager.getWritable("ChargeStateLow");
    const hvBattery = storeManager.getWritable("ChargeStateHigh");
    const statuses = storeManager.getWritable("ConnectionStatus");

    let tableTempsArr: any[][];
    let tableArr2: any[][];

    let tableBatteryTitles = ["", "HV Voltages", "HV Temp", "LV Voltages", "LV Temp"]

    $: tableBatteryVitals = [
        ["Min", DE.BATTERYMINVOLTAGEHIGH, DE.BATTERYMINTEMPERATUREHIGH, DE.BATTERYMINVOLTAGELOW, DE.BATTERYMINTEMPERATURELOW],
        ["Max", DE.BATTERYMAXVOLTAGEHIGH, DE.BATTERYMAXTEMPERATUREHIGH, DE.BATTERYMAXVOLTAGELOW, DE.BATTERYMAXTEMPERATURELOW],
        ["Avg", DE.BATTERYVOLTAGEHIGH, DE.BATTERYTEMPERATUREHIGH, DE.BATTERYVOLTAGELOW, DE.BATTERYTEMPERATURELOW],
        ["Safe Range", "[360, 420] V", "[15,50] °C", "[280,360] V", "[15,50] °C"]
    ]

    $: tableTempsArr = [
        ["Up VB", DE.AVERAGE_TEMP_VB_TOP, "[0,70] °C", "HEMS 1", DE.TEMP_HEMS_1, "[0,80] °C"],
        ["Low VB", DE.AVERAGE_TEMP_VB_BOTTOM, "[0,70] °C", "HEMS 2", DE.TEMP_HEMS_2, "[0,80] °C"],
        ["Ambient", DE.AMBIENT_TEMP, "[0,50] °C", "HEMS 3", DE.TEMP_HEMS_3, "[0,80] °C"],
        ["Motor Front", "Temp_Motor_1", "[0,80] °C", "HEMS 4", DE.TEMP_HEMS_4, "[0,80] °C"],
        ["Motor Back", "Temp_Motor_2", "[0,80] °C", "EMS 1", DE.TEMP_EMS_1, "[0,80] °C"],
        ["", "", "", "EMS 2", DE.TEMP_EMS_2, "[0,80] °C"],
    ]

    $: tableArr2 = [
        ["HEMS A1", DE.LEVI_HEMS_CURRENT_A1, "[-10,10] A", "HEMS A2", DE.LEVI_HEMS_CURRENT_A2, "[-10,10] A"],
        ["HEMS B1", DE.LEVI_HEMS_CURRENT_B1, "[-10,10] A", "HEMS B2", DE.LEVI_HEMS_CURRENT_B2, "[-10,10] A"],
        ["HEMS C1", DE.LEVI_HEMS_CURRENT_C1, "[-10,10] A", "HEMS C2", DE.LEVI_HEMS_CURRENT_C2, "[-10,10] A"],
        ["HEMS D1", DE.LEVI_HEMS_CURRENT_D1, "[-10,10] A", "HEMS D2", DE.LEVI_HEMS_CURRENT_D2, "[-10,10] A"],
        ["EMS AB", DE.LEVI_EMS_CURRENT_AB, "[-10,10] A", "EMS CD", DE.LEVI_EMS_CURRENT_CD, "[-10,10] A"],
    ]

    const location = storeManager.getWritable(LOCALISATION_NAME);

    const toastStore = getToastStore();

</script>

<div bind:clientWidth={width} class="h-full bg-surface-700 text-surface-50">
    <AppBar padding="p-3" border="border-b border-b-surface-900" background="bg-surface-700">
        <svelte:fragment slot="lead">
            <Icon icon="codicon:graph-line"/>
        </svelte:fragment>
        <span>Vitals</span>
        <svelte:fragment slot="trail">
            <Command callback={() => {
                toastStore.trigger({
                    //@ts-ignore
                    message: "Emergency Brake triggered!",
                    background: 'variant-filled-error'
                });
            }} className="bg-error-500 text-surface-100 btn py-0 border border-error-500 rounded-sm" cmd="EmergencyBrake"/>
        </svelte:fragment>
    </AppBar>

    {#if width < 200}
        <div class="flex flex-col h-full pb-20 justify-between items-center">
            <button on:click={() => {
                invoke('send_command', {cmdName: "EmergencyBrake", val: 0}).then(() => {
                    console.log(`Triggered EmergencyBrake!!`);
                })
            }} class="btn border border-error-500 bg-error-500 rounded-sm">
                <span style="writing-mode: vertical-lr">EMERGENCY BRAKE</span>
            </button>
            <span style="writing-mode: vertical-lr" class="font-medium">Vitals Panel</span>
            <div class="flex flex-col gap-4">
                <Battery fill="#3b669c" orientation="vertical" height={55} perc={Number($lvBattery.value)}/>
                <Battery fill="#723f9c" orientation="vertical" height={55} perc={Number($hvBattery.value)}/>
            </div>
        </div>
    {:else}
        <div class="snap-x scroll-px-0.5 snap-mandatory overflow-x-auto h-[90vh]">
            <TileGrid className="p-4 w-full" columns="1fr 1fr" rows="">
                <Tile bgToken={800} containerClass="col-span-2">
                    <Localiser turning={$statuses.value[STATUS.TURNING]} loc={$location.value} showLabels={false} />
                </Tile>
                <Tile bgToken={700} containerClass="col-span-2">
                    <div class="flex flex-wrap justify-between">
                        <div class="flex gap-4 ">
                            <p>
                                Velocity: <Store datatype="Velocity" /> m/s
                                <br>
                                Position: <Store datatype={LOCALISATION_NAME} /> mm
                                <br>
                                Acceleration: <Store datatype="Acceleration" /> m/s²
                            </p>
                            <p>
                                HV Current: <Store datatype="BatteryCurrentHigh" /> - [0, 25] A
                                <br>
                                LV Current: <Store datatype="BatteryCurrentLow" /> - [0, 10] A
                            </p>
                            <p>
                                Low Pressure: <Store datatype="LowPressureSensor" /> - [40, 52] bar
                                <br>
                                High Pressure: <Store datatype="HighPressureSensor" /> - [80, 180] bar
                            </p>
                        </div>
                        <div style="grid-template-columns: 1fr 2fr 3fr;" class="grid gap-2">
                            <span>LV: </span>
                            <Battery fill="#3b669c" orientation="horizontal" perc={Number($lvBattery.value)}/>
                            <span>Total: <Store datatype="TotalBatteryVoltageLow" /></span>

                            <span>HV: </span>
                            <Battery fill="#723f9c" orientation="horizontal" perc={Number($hvBattery.value)}/>
                            <span>Total: <Store datatype="TotalBatteryVoltageHigh" /></span>
                        </div>
                    </div>
                    <div class="flex flex-wrap justify-between mt-4">
                        <div class="flex gap-4">
                            <Command cmd="StopHV" className="py-1 text-error-400 border-error-400 border-2" />
                            <Command cmd="ArmBrakes" className="py-1 bg-primary-500 text-surface-900 " />
                            <Command cmd="StartRun" className="py-1 bg-primary-500 text-surface-900" />
                            <Command cmd="ContinueRun" className="py-1 bg-primary-500 text-surface-900" />
                        </div>
                        <div class="flex flex-col">
                            <span>LV Total Safe: [21, 29.5] V</span>
                            <span>HV Total Safe: [347, 470] V</span>
                        </div>
                    </div>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table titles={tableBatteryTitles} tableArr={tableBatteryVitals}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table tableArr={tableTempsArr} titles={["Module", "Temp °C", "Safe range", "Module", "Temp °C", "Safe range"]}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table titles={["Datatype", "Value", "Safe range", "Datatype", "Value", "Safe range"]} tableArr={tableArr2}/>
                </Tile>
                <Tile bgToken={800} containerClass="col-span-2 px-16">
                    <FSM />
                </Tile>
            </TileGrid>
        </div>
    {/if}
</div>
