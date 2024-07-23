<script lang="ts">
    import {
        Battery,
        Chart,
        GrandDataDistributor,
        Status, Store,
        Table,
        Tile,
        TileGrid, ToggleCommand,
    } from "$lib"
  const storeManager = GrandDataDistributor.getInstance().stores;
  const lvBattery = storeManager.getWritable("ChargeStateLow");
  const hvBattery = storeManager.getWritable("ChargeStateHigh");

  const avg1Temp = "Module1AvgTemperature", max1Temp = "Module1MaxTemperature", min1Temp = "Module1MinTemperature",
    avg1Vol = "Module1AvgVoltage", max1Vol = "Module1MaxVoltage", min1Vol = "Module1MinVoltage",
    avg2Temp = "Module2AvgTemperature", max2Temp = "Module2MaxTemperature", min2Temp = "Module2MinTemperature",
    avg2Vol = "Module2AvgVoltage", max2Vol = "Module2MaxVoltage", min2Vol = "Module2MinVoltage",
    avg3Temp = "Module3AvgTemperature", max3Temp = "Module3MaxTemperature", min3Temp = "Module3MinTemperature",
    avg3Vol = "Module3AvgVoltage", max3Vol = "Module3MaxVoltage", min3Vol = "Module3MinVoltage",
    avg4Temp = "Module4AvgTemperature", max4Temp = "Module4MaxTemperature", min4Temp = "Module4MinTemperature",
    avg4Vol = "Module4AvgVoltage", max4Vol = "Module4MaxVoltage", min4Vol = "Module4MinVoltage",
    avg5Temp = "Module5AvgTemperature", max5Temp = "Module5MaxTemperature", min5Temp = "Module5MinTemperature",
    avg5Vol = "Module5AvgVoltage", max5Vol = "Module5MaxVoltage", min5Vol = "Module5MinVoltage",
    avg6Temp = "Module6AvgTemperature", max6Temp = "Module6MaxTemperature", min6Temp = "Module6MinTemperature",
    avg6Vol = "Module6AvgVoltage", max6Vol = "Module6MaxVoltage", min6Vol = "Module6MinVoltage",
    avg7Temp = "Module7AvgTemperature", max7Temp = "Module7MaxTemperature", min7Temp = "Module7MinTemperature",
    avg7Vol = "Module7AvgVoltage", max7Vol = "Module7MaxVoltage", min7Vol = "Module7MinVoltage",
    avg8Temp = "Module8AvgTemperature", max8Temp = "Module8MaxTemperature", min8Temp = "Module8MinTemperature",
    avg8Vol = "Module8AvgVoltage", max8Vol = "Module8MaxVoltage", min8Vol = "Module8MinVoltage",
    avgLvTemp = "BatteryTemperatureLow", minLvTemp = "BatteryMinTemperatureLow", maxLvTemp = "BatteryMaxTemperatureLow",
    avgLvVol = "BatteryVoltageLow", minLvVol = "BatteryMinVoltageLow", maxLvVol = "BatteryMaxVoltageHigh";


  let titles = ["Battery", "Avg cell V", "Max cell V", "Min cell V"
        , "Avg cell °C", "Max cell °C", "Min cell °C"];
    $: tableArr = [
        ["LV", avgLvVol, maxLvVol, minLvVol, avgLvTemp, maxLvTemp, minLvTemp],
        ["HV mod 1", avg1Vol, max1Vol, min1Vol, avg1Temp, max1Temp, min1Temp],
        ["HV mod 2", avg2Vol, max2Vol, min2Vol, avg2Temp, max2Temp, min2Temp],
        ["HV mod 3", avg3Vol, max3Vol, min3Vol, avg3Temp, max3Temp, min3Temp],
        ["HV mod 4", avg4Vol, max4Vol, min4Vol, avg4Temp, max4Temp, min4Temp],
        ["HV mod 5", avg5Vol, max5Vol, min5Vol, avg5Temp, max5Temp, min5Temp],
        ["HV mod 6", avg6Vol, max6Vol, min6Vol, avg6Temp, max6Temp, min6Temp],
        ["HV mod 7", avg7Vol, max7Vol, min7Vol, avg7Temp, max7Temp, min7Temp],
        ["HV mod 8", avg8Vol, max8Vol, min8Vol, avg8Temp, max8Temp, min8Temp],
    ];

    let lvTitles = ["cell 1" , "cell 2" , "cell 3" , "cell 4" , "cell 5" , "cell 6" , "cell 7"];
    let hvTitles = ["Module","cell 1" , "cell 2" , "cell 3" , "cell 4" , "cell 5" , "cell 6" , "cell 7", "cell 8" ,
     "cell 9" , "cell 10" , "cell 11" , "cell 12" , "cell 13" , "cell 14"];
    const lv0 = "SingleCellVoltageLV1", lv1 = "SingleCellVoltageLV2", lv2 = "SingleCellVoltageLV3", lv3 = "SingleCellVoltageLV4",lv4 = "SingleCellVoltageLV5",lv5 = "SingleCellVoltageLV6",lv6 = "SingleCellVoltageLV7",lv7 = "SingleCellVoltageLV8";

    const hv0 = "SingleCellVoltageHV1",
    hv1 = "SingleCellVoltageHV2",
    hv2 = "SingleCellVoltageHV3",
    hv3 = "SingleCellVoltageHV4",
    hv4 = "SingleCellVoltageHV5",
    hv5 = "SingleCellVoltageHV6",
    hv6 = "SingleCellVoltageHV7",
    hv7 = "SingleCellVoltageHV8",
    hv8 = "SingleCellVoltageHV9",
    hv9 = "SingleCellVoltageHV10",
    hv10 = "SingleCellVoltageHV11",
    hv11 = "SingleCellVoltageHV12",
    hv12 = "SingleCellVoltageHV13",
    hv13 = "SingleCellVoltageHV14",
    hv14 = "SingleCellVoltageHV15",
    hv15 = "SingleCellVoltageHV16",
    hv16 = "SingleCellVoltageHV17",
    hv17 = "SingleCellVoltageHV18",
    hv18 = "SingleCellVoltageHV19",
    hv19 = "SingleCellVoltageHV20",
    hv20 = "SingleCellVoltageHV21",
    hv21 = "SingleCellVoltageHV22",
    hv22 = "SingleCellVoltageHV23",
    hv23 = "SingleCellVoltageHV24",
    hv24 = "SingleCellVoltageHV25",
    hv25 = "SingleCellVoltageHV26",
    hv26 = "SingleCellVoltageHV27",
    hv27 = "SingleCellVoltageHV28",
    hv28 = "SingleCellVoltageHV29",
    hv29 = "SingleCellVoltageHV30",
    hv30 = "SingleCellVoltageHV31",
    hv31 = "SingleCellVoltageHV32",
    hv32 = "SingleCellVoltageHV33",
    hv33 = "SingleCellVoltageHV34",
    hv34 = "SingleCellVoltageHV35",
    hv35 = "SingleCellVoltageHV36",
    hv36 = "SingleCellVoltageHV37",
    hv37 = "SingleCellVoltageHV38",
    hv38 = "SingleCellVoltageHV39",
    hv39 = "SingleCellVoltageHV40",
    hv40 = "SingleCellVoltageHV41",
    hv41 = "SingleCellVoltageHV42",
    hv42 = "SingleCellVoltageHV43",
    hv43 = "SingleCellVoltageHV44",
    hv44 = "SingleCellVoltageHV45",
    hv45 = "SingleCellVoltageHV46",
    hv46 = "SingleCellVoltageHV47",
    hv47 = "SingleCellVoltageHV48",
    hv48 = "SingleCellVoltageHV49",
    hv49 = "SingleCellVoltageHV50",
    hv50 = "SingleCellVoltageHV51",
    hv51 = "SingleCellVoltageHV52",
    hv52 = "SingleCellVoltageHV53",
    hv53 = "SingleCellVoltageHV54",
    hv54 = "SingleCellVoltageHV55",
    hv55 = "SingleCellVoltageHV56",
    hv56 = "SingleCellVoltageHV57",
    hv57 = "SingleCellVoltageHV58",
    hv58 = "SingleCellVoltageHV59",
    hv59 = "SingleCellVoltageHV60",
    hv60 = "SingleCellVoltageHV61",
    hv61 = "SingleCellVoltageHV62",
    hv62 = "SingleCellVoltageHV63",
    hv63 = "SingleCellVoltageHV64",
    hv64 = "SingleCellVoltageHV65",
    hv65 = "SingleCellVoltageHV66",
    hv66 = "SingleCellVoltageHV67",
    hv67 = "SingleCellVoltageHV68",
    hv68 = "SingleCellVoltageHV69",
    hv69 = "SingleCellVoltageHV70",
    hv70 = "SingleCellVoltageHV71",
    hv71 = "SingleCellVoltageHV72",
    hv72 = "SingleCellVoltageHV73",
    hv73 = "SingleCellVoltageHV74",
    hv74 = "SingleCellVoltageHV75",
    hv75 = "SingleCellVoltageHV76",
    hv76 = "SingleCellVoltageHV77",
    hv77 = "SingleCellVoltageHV78",
    hv78 = "SingleCellVoltageHV79",
    hv79 = "SingleCellVoltageHV80",
    hv80 = "SingleCellVoltageHV81",
    hv81 = "SingleCellVoltageHV82",
    hv82 = "SingleCellVoltageHV83",
    hv83 = "SingleCellVoltageHV84",
    hv84 = "SingleCellVoltageHV85",
    hv85 = "SingleCellVoltageHV86",
    hv86 = "SingleCellVoltageHV87",
    hv87 = "SingleCellVoltageHV88",
    hv88 = "SingleCellVoltageHV89",
    hv89 = "SingleCellVoltageHV90",
    hv90 = "SingleCellVoltageHV91",
    hv91 = "SingleCellVoltageHV92",
    hv92 = "SingleCellVoltageHV93",
    hv93 = "SingleCellVoltageHV94",
    hv94 = "SingleCellVoltageHV95",
    hv95 = "SingleCellVoltageHV96",
    hv96 = "SingleCellVoltageHV97",
    hv97 = "SingleCellVoltageHV98",
    hv98 = "SingleCellVoltageHV99",
    hv99 = "SingleCellVoltageHV100",
    hv100 = "SingleCellVoltageHV101",
    hv101 = "SingleCellVoltageHV102",
    hv102 = "SingleCellVoltageHV103",
    hv103 = "SingleCellVoltageHV104",
    hv104 = "SingleCellVoltageHV105",
    hv105 = "SingleCellVoltageHV106",
    hv106 = "SingleCellVoltageHV107",
    hv107 = "SingleCellVoltageHV108",
    hv108 = "SingleCellVoltageHV109",
    hv109 = "SingleCellVoltageHV110",
    hv110 = "SingleCellVoltageHV111",
    hv111 = "SingleCellVoltageHV112";
    $: lvCellVoltArr = [[lv0,lv1,lv2,lv3,lv4,lv5,lv6,lv7]];
    $: hvCellVoltArr = [["Module 1", hv0, hv1, hv2, hv3, hv4, hv5, hv6, hv7, hv8, hv9, hv10, hv11, hv12,hv13],
        ["Module 2", hv14, hv15, hv16, hv17, hv18, hv19, hv20, hv21, hv22, hv23, hv24, hv25, hv26, hv27,],
        ["Module 3", hv28, hv29, hv30, hv31, hv32, hv33, hv34, hv35, hv36, hv37, hv38 ,hv39, hv108, hv105],
        ["Module 4",  hv40, hv41, hv42, hv43, hv44, hv45, hv46, hv47, hv48, hv49, hv50, hv51,hv107 ,hv104],
        ["Module 5", hv52, hv53, hv54, hv55, hv56, hv57, hv58, hv59, hv60, hv61, hv62, hv63, hv64, hv106],
        ["Module 6", hv65, hv66, hv67, hv68, hv69, hv70, hv71, hv72, hv73, hv74, hv75, hv76, hv77, hv110],
        ["Module 7", hv78, hv79, hv80, hv81, hv82, hv83, hv84, hv85, hv86, hv87, hv88, hv89, hv90, hv109],
        ["Module 8", hv91, hv92, hv93, hv94, hv95, hv96, hv97, hv98, hv99, hv100, hv101, hv102, hv103, hv111],]

    let dcStatus:boolean = false;
    let connectorStatus:boolean = false;

    const lvTotalStore = storeManager.getWritable("TotalBatteryVoltageLow");
    export const pop_up: boolean = true;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <div class="flex gap-x-2 items-start">
    </div>
    <TileGrid columns="1fr 1fr 1fr 1fr" rows="auto 1fr auto">
        <Tile insideClass="flex h-full items-center gap-4">
            <div class="flex flex-col items-center">
                <Battery fill="#3b669c" orientation="horizontal" height={40} perc={Number($lvBattery.value)} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery fill="#723f9c" orientation="horizontal" height={40} perc={Number($hvBattery.value)} />
                <p>High voltage</p>
            </div>
        </Tile>
        <Tile containerClass="col-span-2" insideClass="flex flex-col h-full gap-2 items-center">
            <div class="w-full flex justify-between items-center">
                <Status label="HV Battery relay status" onColor="text-error-400" offColor="text-surface-50"
                        on="HV Relays ON" off="HV Relays Off" bind:status={connectorStatus} />
                <ToggleCommand onCmd="StartHV" offCmd="StopHV" bind:status={connectorStatus} />
            </div>
            <div class="w-full flex justify-between items-center">
                <Status label="DC Converter status" on="charging" off="off" offColor="text-surface-50" bind:status={dcStatus} />
                <ToggleCommand onCmd="DcOn" offCmd="DcOff" bind:status={dcStatus} disabled={$lvTotalStore.value > 21} />
            </div>
        </Tile>
        <Tile insideClass="flex h-full items-center">
            <div class="flex flex-col ml-4">
                <p>LV Current: <Store datatype="BatteryCurrentLow" /></p>
                <p>HV Current: <Store datatype="BatteryCurrentHigh" /></p>
                <p>IMD Voltage: <Store datatype="IMDVoltageDetails" /></p>
            </div>
        </Tile>
        <Tile containerClass="col-span-4" heading="Battery stats">
            <Table background="bg-surface-900" {tableArr} {titles} />
        </Tile>
        <Tile containerClass="col-span-2" heading="LV Current">
            <Chart title="LV Current" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2" heading="HV Current">
            <Chart title="HV Current" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2" heading="LV Total">
            <Chart title="LV Total" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2" heading="HV Total">
            <Chart title="HV Total" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-4" heading="Lv Cell Voltages">
            <Table background="bg-surface-900" tableArr={lvCellVoltArr} titles =  {lvTitles} />
        </Tile>
        <Tile containerClass="col-span-4" heading="HV Cell Voltages">
            <Table background="bg-surface-900 text-xs" tableArr={hvCellVoltArr} titles ={hvTitles} />
        </Tile>
    </TileGrid>
</div>
