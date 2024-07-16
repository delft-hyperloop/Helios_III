<script lang="ts">
  import {
    Battery,
    Chart,
    GrandDataDistributor,
    Status, Store,
    Table,
    Tile,
    TileGrid, ToggleCommand
  } from "$lib";
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
    ]

    let dcStatus:boolean = false;
    let connectorStatus:boolean = false;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <TileGrid columns="1fr 1fr 1fr 1fr" rows="auto 1fr auto">
        <Tile insideClass="flex h-full items-center gap-4">
            <div class="flex flex-col items-center">
                <Battery fill="#3b669c" orientation="horizontal" height={40} perc={Number($lvBattery)} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery fill="#723f9c" orientation="horizontal" height={40} perc={Number($hvBattery)} />
                <p>High voltage</p>
            </div>
        </Tile>
        <Tile containerClass="col-span-2" insideClass="flex flex-col h-full gap-2 items-center">
            <div class="w-full flex justify-between items-center">
                <Status label="HV Battery relay status" onColor="text-error-400" offColor="text-surface-50"
                        on="HV Relays ON" off="HV Relays Off" bind:status={connectorStatus} />
                <ToggleCommand onCmd="OpenContactor" offCmd="CloseContactor" bind:status={connectorStatus} />
            </div>
            <div class="w-full flex justify-between items-center">
                <Status label="DC Converter status" on="charging" off="off" offColor="text-surface-50" bind:status={dcStatus} />
                <ToggleCommand onCmd="DcOn" offCmd="DcOff" bind:status={dcStatus} />
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
    </TileGrid>
</div>
