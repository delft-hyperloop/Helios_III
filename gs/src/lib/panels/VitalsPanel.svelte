<script lang="ts">
    import {
        Chart,
        Battery,
        Table,
        FSM,
        TileGrid,
        Tile,
        Command, GrandDataDistributor
    } from "$lib";
    import {AppBar, getToastStore} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {invoke} from "@tauri-apps/api/tauri";
    import Keydown from "svelte-keydown";

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

    const totalLVV = storeManager.getStore("TotalBatteryVoltageLow");
    const totalHVV = storeManager.getStore("TotalBatteryVoltageHigh");

    const upDrawerVB = storeManager.getStore("Average_Temp_VB_top");
    const downDrawerVB = storeManager.getStore("Average_Temp_VB_Bottom");
    const outsideVB = storeManager.getStore("Ambient_temp");

    let tableArr: any[][];
    let tableArr2: any[][];

    let tableBatteryTitles = ["", "HV Voltages", "HV Temp", "LV Voltages", "LV Temp"]
    $: tableBatteryVitals = [
        ["Min", $minVHigh + " V", $minTempHigh + " °C", $minVLow + " V", $minTempLow + " °C"],
        ["Max", $maxVHigh + " V", $maxTempHigh + " °C", $maxVLow + " V", $maxTempLow + " °C"],
        ["Avg", $avgVHigh + " V", $avgTempHigh + " °C", $avgVLow + " V", $avgTempLow + " °C"]
    ]

    $: tableArr = [
        ["Upper drawer VB", $upDrawerVB],
        ["Bottom drawer VB", $downDrawerVB],
        ["Outside of VB", $outsideVB],
        ["HEMS", 0],
        ["EMS", 0],
        ["Motor Front", 0],
        ["Motor Back", 0],
    ]

    $: tableArr2 = [
        ["Current State", 0],
        ["Bottom drawer VB", 0],
        ["outside of VB", 0],
        ["HEMS", 0],
        ["Motor core", 0]
    ]

    const toastStore = getToastStore();

</script>

<Keydown on:combo={({detail}) => {
    if (detail === "Control- -Enter") {
        invoke('abort')
    }
    }}/>

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
                    message: "Abort operation triggered",
                    background: 'variant-filled-error',
                });
            }} className="bg-error-500 text-surface-100 btn py-0 border border-error-500 rounded-sm" cmd="EmergencyBrake"/>
        </svelte:fragment>
    </AppBar>

    {#if width < 200}
        <div class="flex flex-col h-full pb-20 justify-between items-center">
            <button on:click={() => {invoke('abort')}} class="btn border border-error-500 bg-error-500 rounded-sm">
                <span style="writing-mode: vertical-lr">ABORT</span>
            </button>
            <span style="writing-mode: vertical-lr" class="font-medium">Vitals Panel</span>
            <div class="flex flex-col gap-4">
                <Battery orientation="vertical" height={55} perc={Number($lvBattery)}/>
                <Battery orientation="vertical" height={55} perc={Number($hvBattery)}/>
            </div>
        </div>
    {:else}
        <div class="snap-x scroll-px-0.5 snap-mandatory overflow-x-auto h-[90vh]">
            <TileGrid className="p-4 w-full" columns="1fr 1fr" rows="">
                <!--     FSM       -->
                <Tile bgToken={800} containerClass="col-span-2">
                    {#if width > 550}
                        <FSM size="sm"/>
                    {:else}
                        <FSM size="lg"/>
                    {/if}
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
                        <div class="flex gap-4">
                            <div class="flex gap-2">
                                <span>LV: </span>
                                <Battery orientation="horizontal" perc={Number($lvBattery)}/>
                                <span>Total LV V: {$totalLVV}</span>
                            </div>
                            <div class="flex gap-2">
                                <span>HV: </span>
                                <Battery orientation="horizontal" perc={Number($hvBattery)}/>
                                <span>Total HV V: {$totalHVV}</span>
                            </div>
                        </div>
                    </div>
                </Tile>
                <!--     TEMPERATURE TABLE      -->
                <Tile containerClass="pt-2 pb-1 col-span-2" bgToken={800}>
                    <Table titles={tableBatteryTitles} tableArr={tableBatteryVitals}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-{width < 550 ? 2 : 1}" bgToken={800}>
                    <Table {tableArr}/>
                </Tile>
                <Tile containerClass="pt-2 pb-1 col-span-{width < 550 ? 2 : 1}" bgToken={800}>
                    <Table titles={["Variable", "Status"]} tableArr={tableArr2}/>
                </Tile>
                <!--     OFFSET GRAPHS       -->
                <Tile containerClass="py-1 col-span-{width < 550 ? 2 : 1}" bgToken={800}>
                    <Chart title="Offset Horizontal"
                           refreshRate={100}/>
                </Tile>
                <Tile containerClass="py-1 h-full w-full col-span-{width < 550 ? 2 : 1}" bgToken={800}>
                    <Chart title="Offset Vertical" refreshRate={100}/>
                </Tile>
                <Tile containerClass="py-2 col-span-2" bgToken={800}>
                    <Chart title="Velocity" refreshRate={100}/>
                </Tile>
            </TileGrid>
        </div>
    {/if}
</div>