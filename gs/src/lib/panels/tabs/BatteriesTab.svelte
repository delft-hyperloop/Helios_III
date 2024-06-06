<script lang="ts">
    import {
        Battery,
        Chart,
        GrandDataDistributor,
        Status,
        Table,
        Tile,
        TileGrid, ToggleCommand
    } from "$lib";

    const storeManager = GrandDataDistributor.getInstance().stores;
    const lvBattery = storeManager.getStore("BatteryBalanceLow");
    const hvBattery = storeManager.getStore("BatteryBalanceHigh");

    const avg1Temp = storeManager.getStore("Module1AvgTemperature");
    const max1Temp = storeManager.getStore("Module1MaxTemperature");
    const min1Temp = storeManager.getStore("Module1MinTemperature");
    const avg1Vol = storeManager.getStore("Module1AvgVoltage");
    const max1Vol = storeManager.getStore("Module1MaxVoltage");
    const min1Vol = storeManager.getStore("Module1MinVoltage");

    const avg2Temp = storeManager.getStore("Module2AvgTemperature");
    const max2Temp = storeManager.getStore("Module2MaxTemperature");
    const min2Temp = storeManager.getStore("Module2MinTemperature");
    const avg2Vol = storeManager.getStore("Module2AvgVoltage");
    const max2Vol = storeManager.getStore("Module2MaxVoltage");
    const min2Vol = storeManager.getStore("Module2MinVoltage");

    const avg3Temp = storeManager.getStore("Module3AvgTemperature");
    const max3Temp = storeManager.getStore("Module3MaxTemperature");
    const min3Temp = storeManager.getStore("Module3MinTemperature");
    const avg3Vol = storeManager.getStore("Module3AvgVoltage");
    const max3Vol = storeManager.getStore("Module3MaxVoltage");
    const min3Vol = storeManager.getStore("Module3MinVoltage");

    const avg4Temp = storeManager.getStore("Module4AvgTemperature");
    const max4Temp = storeManager.getStore("Module4MaxTemperature");
    const min4Temp = storeManager.getStore("Module4MinTemperature");
    const avg4Vol = storeManager.getStore("Module4AvgVoltage");
    const max4Vol = storeManager.getStore("Module4MaxVoltage");
    const min4Vol = storeManager.getStore("Module4MinVoltage");

    const avg5Temp = storeManager.getStore("Module5AvgTemperature");
    const max5Temp = storeManager.getStore("Module5MaxTemperature");
    const min5Temp = storeManager.getStore("Module5MinTemperature");
    const avg5Vol = storeManager.getStore("Module5AvgVoltage");
    const max5Vol = storeManager.getStore("Module5MaxVoltage");
    const min5Vol = storeManager.getStore("Module5MinVoltage");

    const avg6Temp = storeManager.getStore("Module6AvgTemperature");
    const max6Temp = storeManager.getStore("Module6MaxTemperature");
    const min6Temp = storeManager.getStore("Module6MinTemperature");
    const avg6Vol = storeManager.getStore("Module6AvgVoltage");
    const max6Vol = storeManager.getStore("Module6MaxVoltage");
    const min6Vol = storeManager.getStore("Module6MinVoltage");

    const avg7Temp = storeManager.getStore("Module7AvgTemperature");
    const max7Temp = storeManager.getStore("Module7MaxTemperature");
    const min7Temp = storeManager.getStore("Module7MinTemperature");
    const avg7Vol = storeManager.getStore("Module7AvgVoltage");
    const max7Vol = storeManager.getStore("Module7MaxVoltage");
    const min7Vol = storeManager.getStore("Module7MinVoltage");

    const avg8Temp = storeManager.getStore("Module8AvgTemperature");
    const max8Temp = storeManager.getStore("Module8MaxTemperature");
    const min8Temp = storeManager.getStore("Module8MinTemperature");
    const avg8Vol = storeManager.getStore("Module8AvgVoltage");
    const max8Vol = storeManager.getStore("Module8MaxVoltage");
    const min8Vol = storeManager.getStore("Module8MinVoltage");

    const avgLvTemp = storeManager.getStore("BatteryMinTemperatureLow");
    const minLvTemp = storeManager.getStore("BatteryMinTemperatureLow");
    const maxLvTemp = storeManager.getStore("BatteryMaxTemperatureLow");
    const avgLvVol = storeManager.getStore("BatteryMinVoltageLow");
    const minLvVol = storeManager.getStore("BatteryMinVoltageLow");
    const maxLvVol = storeManager.getStore("BatteryMaxVoltageLow");

    const lvCurrent = storeManager.getStore("BatteryCurrentLow");
    const hvCurrent = storeManager.getStore("BatteryCurrentHigh");

    let titles = ["Battery", "Avg cell V", "Max cell V", "Min cell V"
        , "Avg cell °C", "Max cell °C", "Min cell °C"];
    $: tableArr = [
        ["LV", $avgLvVol, $maxLvVol, $minLvVol, $avgLvTemp, $maxLvTemp, $minLvTemp],
        ["HV mod 1", $avg1Vol, $max1Vol, $min1Vol, $avg1Temp, $max1Temp, $min1Temp],
        ["HV mod 2", $avg2Vol, $max2Vol, $min2Vol, $avg2Temp, $max2Temp, $min2Temp],
        ["HV mod 3", $avg3Vol, $max3Vol, $min3Vol, $avg3Temp, $max3Temp, $min3Temp],
        ["HV mod 4", $avg4Vol, $max4Vol, $min4Vol, $avg4Temp, $max4Temp, $min4Temp],
        ["HV mod 5", $avg5Vol, $max5Vol, $min5Vol, $avg5Temp, $max5Temp, $min5Temp],
        ["HV mod 6", $avg6Vol, $max6Vol, $min6Vol, $avg6Temp, $max6Temp, $min6Temp],
        ["HV mod 7", $avg7Vol, $max7Vol, $min7Vol, $avg7Temp, $max7Temp, $min7Temp],
        ["HV mod 8", $avg8Vol, $max8Vol, $min8Vol, $avg8Temp, $max8Temp, $min8Temp],
    ]

    let dcStatus:boolean = false;
    let connectorStatus:boolean = false;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <TileGrid columns="1fr 1fr 1fr 1fr" rows="auto 1fr auto">
        <Tile insideClass="flex h-full items-center gap-4">
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={Number($lvBattery)} />
                <p>Low voltage</p>
            </div>
            <div class="flex flex-col items-center">
                <Battery orientation="horizontal" height={40} perc={Number($hvBattery)} />
                <p>High voltage</p>
            </div>
        </Tile>
        <Tile containerClass="col-span-2" insideClass="flex flex-col h-full gap-2 items-center">
            <div class="w-full flex justify-between items-center">
                <Status label="HV Battery relay status" on="closed" off="open" bind:status={connectorStatus} />
                <ToggleCommand onCmd="OpenContactor" offCmd="CloseContactor" bind:status={connectorStatus} />
            </div>
            <div class="w-full flex justify-between items-center">
                <Status label="DC Converter status" on="closed" off="open" bind:status={dcStatus} />
                <ToggleCommand onCmd="DcOn" offCmd="DcOff" bind:status={dcStatus} />
            </div>
        </Tile>
        <Tile insideClass="flex h-full items-center">
            <div class="flex flex-col ml-4">
                <p>LV Current: {$lvCurrent}</p>
                <p>HV Current: {$hvCurrent}</p>
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
