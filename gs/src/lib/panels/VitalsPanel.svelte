<script lang="ts">
  import {Battery, Table, FSM, TileGrid, Tile, Command, GrandDataDistributor, Localiser, Store} from "$lib";
    import {AppBar, getToastStore} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {invoke} from "@tauri-apps/api/tauri";
    import {DatatypeEnum as DE} from "$lib/namedDatatypeEnum";

    let width: number;

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lvBattery = storeManager.getStore("BatteryEstimatedChargeLow");
    const hvBattery = storeManager.getStore("BatteryEstimatedChargeHigh");

    let tableTempsArr: any[][];
    let tableArr2: any[][];

    let tableBatteryTitles = ["", "HV Voltages", "HV Temp", "LV Voltages", "LV Temp"]

    $: tableBatteryVitals = [
        ["Min", DE.BATTERYMINVOLTAGEHIGH, DE.BATTERYMINTEMPERATUREHIGH, DE.BATTERYMINVOLTAGELOW, DE.BATTERYMINTEMPERATURELOW],
        ["Max", DE.BATTERYMAXVOLTAGEHIGH, DE.BATTERYMINTEMPERATUREHIGH, DE.BATTERYMAXVOLTAGELOW, DE.BATTERYMAXTEMPERATURELOW],
        ["Avg", DE.BATTERYVOLTAGEHIGH, DE.BATTERYMINTEMPERATUREHIGH, DE.BATTERYVOLTAGELOW, DE.BATTERYTEMPERATURELOW]
    ]

    $: tableTempsArr = [
        ["Upper drawer VB", DE.AVERAGE_TEMP_VB_BOTTOM, "HEMS 1", DE.TEMP_HEMS_1],
        ["Bottom drawer VB", DE.AVERAGE_TEMP_VB_BOTTOM, "HEMS 2", DE.TEMP_HEMS_2],
        ["Outside of VB", DE.AMBIENT_TEMP, "HEMS 3", DE.TEMP_HEMS_3],
        ["Propulsion", DE.PROPULSIONCURRENT, "HEMS 4", DE.TEMP_HEMS_4],
        ["Levitation", DE.LEVITATIONTEMPERATURE, "EMS 1", DE.TEMP_EMS_1],
        ["Brake", DE.BRAKETEMPERATURE, "EMS 2", DE.TEMP_EMS_2],
    ]

    $: tableArr2 = [
        ["Insulation", DE.INSULATIONORIGINAL, "Insulation-", DE.INSULATIONNEGATIVE],
        ["IMD Voltage", DE.IMDVOLTAGEDETAILS, "Insulation+", DE.INSULATIONPOSITIVE],
    ]

    const location = storeManager.getStore("Localisation");

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
                <Battery fill="#3b669c" orientation="vertical" height={55} perc={Number($lvBattery)}/>
                <Battery fill="#723f9c" orientation="vertical" height={55} perc={Number($hvBattery)}/>
            </div>
        </div>
    {:else}
        <div class="snap-x scroll-px-0.5 snap-mandatory overflow-x-auto h-[90vh]">
            <TileGrid className="p-4 w-full" columns="1fr 1fr" rows="">
                <!--     FSM       -->
                <Tile bgToken={800} containerClass="col-span-2">
                    <Localiser turning={true} loc={$location} showLabels={false} />
                </Tile>
                <!--      Under FSM      -->
                <Tile bgToken={700} containerClass="col-span-2">
                    <div class="flex flex-wrap justify-between">
                        <div class="flex gap-4">
                            <p>
                                Velocity: <Store datatype="Velocity" />
                                <br>
                                Position: <Store datatype="Localisation" />
                            </p>
                            <p>
                                HV Current: <Store datatype="BatteryCurrentHigh" />
                                <br>
                                LV Current: <Store datatype="BatteryCurrentLow" />
                            </p>
                        </div>
                        <div style="grid-template-columns: 1fr 2fr 2fr;" class="grid gap-y-2">
                            <span>LV: </span>
                            <Battery fill="#3b669c" orientation="horizontal" perc={Number($lvBattery)}/>
                            <span>Total: <Store datatype="TotalBatteryVoltageLow" /></span>
                            <span>HV: </span>
                            <Battery fill="#723f9c" orientation="horizontal" perc={Number($hvBattery)}/>
                            <span>Total: <Store datatype="TotalBatteryVoltageHigh" /></span>
                        </div>
                    </div>
                    <div class="flex gap-4">
                        <Command cmd="StopHV" />
                        <Command cmd="ArmBrakes" />
                        <Command cmd="StartRun" />
                    </div>
                </Tile>
                <!--     TEMPERATURE TABLE      -->
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table titles={tableBatteryTitles} tableArr={tableBatteryVitals}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table tableArr={tableTempsArr} titles={["Module", "Temp °C", "Module", "Temp °C"]}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table titles={["Variable", "Status", "Variable", "Status"]} tableArr={tableArr2}/>
                </Tile>
                <Tile bgToken={800} containerClass="col-span-2 px-16">
                    {#if width > 550}
                        <FSM size="sm"/>
                    {:else}
                        <FSM size="lg"/>
                    {/if}
                </Tile>

            </TileGrid>
        </div>
    {/if}
</div>
