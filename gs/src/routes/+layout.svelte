<script lang="ts">
    import '../app.postcss';
    import {BottomBar, GrandDataDistributor, PlotBuffer, StrokePresets, TitleBar,} from "$lib";
    import {initializeStores, Modal, Toast} from '@skeletonlabs/skeleton';
    import {chartStore} from "$lib/stores/state";
    import type {dataConvFun} from "$lib/types";

    // CHARTS
    let emsChart = new PlotBuffer(1000, 300000, [0, 100], false);
    let hemsChart = new PlotBuffer(1000, 300000, [0, 100], false);
    emsChart.addSeries(StrokePresets.theoretical())
    emsChart.addSeries(StrokePresets.yellow())
    emsChart.addSeries(StrokePresets.blue())
    hemsChart.addSeries(StrokePresets.theoretical())
    hemsChart.addSeries(StrokePresets.yellow())
    hemsChart.addSeries(StrokePresets.blue())
    $chartStore.set("EMS", emsChart);
    $chartStore.set("HEMS", hemsChart);

    let voffChart = new PlotBuffer(1000, 300000, [0, 100], false)
    let hoffChart = new PlotBuffer(1000, 300000, [0, 100], false)
    hoffChart.addSeries(StrokePresets.theoretical())
    let velChart = new PlotBuffer(1000, 5*60*1000, [0, 100], false)

    let leviChart = new PlotBuffer(1000, 300000, [0, 100], false);

    $chartStore.set('Offset Horizontal', hoffChart);
    $chartStore.set('Offset Vertical', voffChart);
    $chartStore.set('Velocity', velChart);
    $chartStore.set('Localisation', leviChart);

    let trr = new PlotBuffer(1000, 60000, [0, 50], false)
    trr.addSeries(StrokePresets.theoretical())
    $chartStore.set('Theoretical vs Real run', trr)

    let lvCurrent = new PlotBuffer(1000, 300000, [-4000, 4000], false)
    $chartStore.set('LV Current', lvCurrent)

    let hvCurrent = new PlotBuffer(1000, 300000, [-4000, 4000], false)
    $chartStore.set('HV Current', hvCurrent)

    ///////////////////////////////////////////////////////
    ///// GRAND DATA DISTRIBUTOR //////////////////////////
    ///////////////////////////////////////////////////////

    let gdd = GrandDataDistributor.getInstance();
    gdd.stores.registerStore<number>("BatteryEstimatedChargeHigh", 0.0, data => Number(data) / 100);
    gdd.stores.registerStore<number>("BatteryEstimatedChargeLow", 0.0, data => Number(data) / 100);
    
    const tempParse:dataConvFun<number> = (data:bigint) => {
        return Number(data) - 100;
    }

    const voltParse:dataConvFun<number> = (data:bigint) => {
        return Number(data) / 100;
    }

    gdd.stores.registerStore<number>("Module1AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module1MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module1MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module1AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module1MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module1MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module2AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module2MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module2MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module2AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module2MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module2MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module3AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module3MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module3MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module4AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module4MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module4MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module5AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module5MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module5MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module6AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module6MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module6MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module7AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MinTemperature", 0.0, tempParse)
    gdd.stores.registerStore<number>("Module7AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module7MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module7MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module8AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module8MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module8MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("BatteryMinVoltageHigh", 0.0, voltParse);
    gdd.stores.registerStore<number>("BatteryMaxVoltageHigh", 0.0, voltParse);
    gdd.stores.registerStore<number>("BatteryVoltageHigh", 0.0, voltParse);

    gdd.stores.registerStore<number>("BatteryMinTemperatureHigh", 0.0, tempParse);
    gdd.stores.registerStore<number>("BatteryMaxTemperatureHigh", 0.0, tempParse);
    gdd.stores.registerStore<number>("BatteryTemperatureHigh", 0.0, tempParse);

    gdd.stores.registerStore<number>("BatteryTemperatureLow", 0.0, tempParse)
    gdd.stores.registerStore<number>("BatteryMinTemperatureLow", 0.0, tempParse)
    gdd.stores.registerStore<number>("BatteryMaxTemperatureLow", 0.0, tempParse)

    gdd.stores.registerStore<number>("BatteryVoltageLow", 0.0, voltParse)
    gdd.stores.registerStore<number>("BatteryMinVoltageLow", 0.0, voltParse)
    gdd.stores.registerStore<number>("BatteryMaxVoltageLow", 0.0, voltParse)

    gdd.stores.registerStore<number>("TotalBatteryVoltageHigh", 0.0, voltParse)
    gdd.stores.registerStore<number>("TotalBatteryVoltageLow", 0.0, voltParse)

    gdd.stores.registerStore<number>("BatteryCurrentLow", 0.0, data => {
        const curr = Number(data) / 10;
        lvCurrent.addEntry(1, curr + 150);
        return curr;
    });

    gdd.stores.registerStore<number>("BatteryCurrentHigh", 0.0, data => {
        const curr = Number(data) / 10;
        hvCurrent.addEntry(1, curr + 10);
        return curr;
    });

    gdd.stores.registerStore<number>("Velocity", 0, data => {
        const curr = Number(data);
        $chartStore.get("Velocity")!.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("Localisation", 0, data => {
        const curr = Number(data);
        $chartStore.get("Localisation")!.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("Localisation", 0);
    gdd.stores.registerStore<number>("BrakePressure", 0);

    gdd.stores.registerStore<number>("Acceleration", 0)
    gdd.stores.registerStore<number>("FSMState", 0);
    gdd.stores.registerStore<number>("PropulsionCurrent", 0);
    gdd.stores.registerStore<number>("LevitationTemperature", 0);
    gdd.stores.registerStore<number>("BrakeTemperature", 0);

    gdd.stores.registerStore<number>("GyroscopeX", 0, data => {
        const curr:number = Number(data);
        $chartStore.get("Offset Horizontal")?.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("GyroscpoeY", 0, data => {
        const curr = Number(data);
        $chartStore.get("Offset Horizontal")?.addEntry(2, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("GyroscopeZ", 0, data => {
        const curr = Number(data);
        $chartStore.get("Offset Vertical")?.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("IMDVoltageDetails", 0);
    gdd.stores.registerStore<number>("IMDIsolationDetails", 0);

    gdd.stores.registerStore<number>("Average_Temp_VB_Bottom", 0.0);
    gdd.stores.registerStore<number>("Average_Temp_VB_top", 0.0);
    gdd.stores.registerStore<number>("Ambient_temp", 0.0);

    gdd.stores.registerStore<number>("Temp_HEMS_1", 0.0)
    gdd.stores.registerStore<number>("Temp_HEMS_2", 0.0)
    gdd.stores.registerStore<number>("Temp_HEMS_3", 0.0)
    gdd.stores.registerStore<number>("Temp_HEMS_4", 0.0)

    gdd.stores.registerStore<number>("levi_hems_gap_a", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_b", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_c", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_d", 0.0)

    gdd.stores.registerStore<number>("levi_ems_gap_a", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_b", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_c", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_d", 0.0)


    gdd.start(100);

    initializeStores();
</script>


<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast/>
    <Modal />
    <TitleBar/>
    <slot/>
    <BottomBar/>
</div>
