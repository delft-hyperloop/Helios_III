<script lang="ts">
    import {Battery, Table, FSM, TileGrid, Tile, Command, GrandDataDistributor, Localiser} from "$lib";
    import {AppBar, getToastStore} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {invoke} from "@tauri-apps/api/tauri";

    let width: number;

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lvBattery = storeManager.getStore("BatteryEstimatedChargeLow");
    const hvBattery = storeManager.getStore("BatteryEstimatedChargeHigh");

    const minVHigh = storeManager.getStore("BatteryMinVoltageHigh");
    const maxVHigh = storeManager.getStore("BatteryMaxVoltageHigh");
    const avgVHigh = storeManager.getStore("BatteryVoltageHigh");

    const minTempHigh = storeManager.getStore("BatteryMinTemperatureHigh");
    const maxTempHigh = storeManager.getStore("BatteryMaxTemperatureHigh");
    const avgTempHigh = storeManager.getStore("BatteryTemperatureHigh");

    const maxVLow = storeManager.getStore("BatteryMaxVoltageLow")
    const minVLow = storeManager.getStore("BatteryMinVoltageLow")
    const avgVLow = storeManager.getStore("BatteryVoltageLow")

    const maxTempLow = storeManager.getStore("BatteryMaxTemperatureLow")
    const minTempLow = storeManager.getStore("BatteryMinTemperatureLow")
    const avgTempLow = storeManager.getStore("BatteryTemperatureLow")

    const currentLow = storeManager.getStore("BatteryCurrentLow")
    const currentHigh = storeManager.getStore("BatteryCurrentHigh")

    const speed = storeManager.getStore("Velocity");
    const position = storeManager.getStore("Localisation");

    const propTemp = storeManager.getStore("PropulsionCurrent");
    const leviTemp = storeManager.getStore("LevitationTemperature");
    const brakeTemp = storeManager.getStore("BrakeTemperature");

    const ins = storeManager.getStore("InsulationOriginal")
    const insp = storeManager.getStore("InsulationPositive")
    const insn = storeManager.getStore("InsulationNegative")
    const imdv = storeManager.getStore("IMDVoltageDetails")

    const totalLVV = storeManager.getStore("TotalBatteryVoltageLow");
    const totalHVV = storeManager.getStore("TotalBatteryVoltageHigh");

    const upDrawerVB = storeManager.getStore("Average_Temp_VB_top");
    const downDrawerVB = storeManager.getStore("Average_Temp_VB_Bottom");
    const outsideVB = storeManager.getStore("Ambient_temp");

    const hems1 = storeManager.getStore("Temp_HEMS_1");
    const hems2 = storeManager.getStore("Temp_HEMS_2");
    const hems3 = storeManager.getStore("Temp_HEMS_3");
    const hems4 = storeManager.getStore("Temp_HEMS_4");
    const ems1 = storeManager.getStore("Temp_EMS_2");
    const ems2 = storeManager.getStore("Temp_EMS_2");

    let tableTempsArr: any[][];
    let tableArr2: any[][];

    let tableBatteryTitles = ["", "HV Voltages", "HV Temp", "LV Voltages", "LV Temp"]

    $: tableBatteryVitals = [
        ["Min", $minVHigh + " V", $minTempHigh + " °C", $minVLow + " V", $minTempLow + " °C"],
        ["Max", $maxVHigh + " V", $maxTempHigh + " °C", $maxVLow + " V", $maxTempLow + " °C"],
        ["Avg", $avgVHigh + " V", $avgTempHigh + " °C", $avgVLow + " V", $avgTempLow + " °C"]
    ]

    $: tableTempsArr = [
        ["Upper drawer VB", $upDrawerVB, "HEMS 1", $hems1 + " °C"],
        ["Bottom drawer VB", $downDrawerVB, "HEMS 2", $hems2 + " °C"],
        ["Outside of VB", $outsideVB, "HEMS 3", $hems3 + " °C"],
        ["Propulsion", $propTemp, "HEMS 4", $hems4 + " °C"],
        ["Levitation", $leviTemp, "EMS 1", $ems1 + " °C"],
        ["Brake", $brakeTemp, "EMS 2", $ems2 + " °C"],
    ]

    $: tableArr2 = [
        ["Insulation", $ins, "Insulation-", $insn],
        ["Insulation+", $insp, "IMD Voltage", $imdv],
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
                                Velocity: <span class="font-mono font-medium">{$speed}</span>
                                <br>
                                Position: <span class="font-mono font-medium">{$position}</span>
                            </p>
                            <p>
                                HV Current: <span class="font-mono font-medium">{$currentHigh}</span>
                                <br>
                                LV Current: <span class="font-mono font-medium">{$currentLow}</span>
                            </p>
                        </div>
                        <div style="grid-template-columns: 1fr 2fr 2fr;" class="grid gap-y-2">
                            <span>LV: </span>
                            <Battery fill="#3b669c" orientation="horizontal" perc={Number($lvBattery)}/>
                            <span>Total: <span class="font-mono font-medium">{$totalLVV} V</span></span>
                            <span>HV: </span>
                            <Battery fill="#723f9c" orientation="horizontal" perc={Number($hvBattery)}/>
                            <span>Total: <span class="font-mono font-medium">{$totalHVV} V</span></span>
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
