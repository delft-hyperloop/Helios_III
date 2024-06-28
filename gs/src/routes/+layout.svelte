<script lang="ts">
    import '../app.postcss';
    import {
        BottomBar,
        GrandDataDistributor,
        PlotBuffer,
        StrokePresets,
        TitleBar,
        tempParse,
        voltParse,
        addEntryToChart, u64ToDouble
    } from "$lib";
    import {initializeStores, Modal, Toast} from '@skeletonlabs/skeleton';
    import {chartStore} from "$lib/stores/state";

    //////////////////////////////
    /////////// CHARTS ///////////
    //////////////////////////////
    let emsTempChart = new PlotBuffer(500, 60000, [0, 120], true, "EMS 1");
    emsTempChart.addSeries(StrokePresets.theoretical("EMS 2"))
    $chartStore.set("EMS Temperatures", emsTempChart);

    let hemsTempChart = new PlotBuffer(500, 60000, [0, 120], true, "HEMS 1");
    hemsTempChart.addSeries(StrokePresets.theoretical("HEMS 2"))
    hemsTempChart.addSeries(StrokePresets.yellow("HEMS 3"))
    hemsTempChart.addSeries(StrokePresets.blue("HEMS 4"))
    $chartStore.set("HEMS Temperatures", hemsTempChart);

    let hemsCurrentChart = new PlotBuffer(500, 60000, [-11.3, 11.3], true, "a1");
    hemsCurrentChart.addSeries(StrokePresets.hyperloopGreenDashed("a2"))
    hemsCurrentChart.addSeries(StrokePresets.theoretical("b1"))
    hemsCurrentChart.addSeries(StrokePresets.theoreticalDashed("b2"))
    hemsCurrentChart.addSeries(StrokePresets.yellow("c1"))
    hemsCurrentChart.addSeries(StrokePresets.yellowDashed("c2"))
    hemsCurrentChart.addSeries(StrokePresets.blue("d1"))
    hemsCurrentChart.addSeries(StrokePresets.blueDashed("d2"))
    $chartStore.set("HEMS Current", hemsCurrentChart);

    let emsCurrentChart = new PlotBuffer(500, 60000, [-11.3, 11.3], true);
    emsCurrentChart.addSeries(StrokePresets.theoretical("cd"))
    $chartStore.set("EMS Current", emsCurrentChart);

    let voffChart = new PlotBuffer(1000, 300000, [0, 100], false)
    let hoffChart = new PlotBuffer(1000, 300000, [0, 100], false)
    hoffChart.addSeries(StrokePresets.theoretical())
    let velChart = new PlotBuffer(1000, 5 * 60 * 1000, [0, 100], false)
    let leviChart = new PlotBuffer(1000, 300000, [0, 100], false);

    $chartStore.set('Offset Horizontal', hoffChart);
    $chartStore.set('Offset Vertical', voffChart);

    let rolPitchChart = new PlotBuffer(500, 60000, [-0.8, 0.8], true, "roll")
    rolPitchChart.addSeries(StrokePresets.theoretical("pitch"))
    $chartStore.set("Roll Pitch", rolPitchChart)

    let hoffChart = new PlotBuffer(500, 60000, [-8, 8], true, "ab")
    hoffChart.addSeries(StrokePresets.theoretical("cd"))
    $chartStore.set('Offset Horizontal', hoffChart);

    let velChart = new PlotBuffer(500, 5*60*1000, [0, 100], false)
    $chartStore.set('Velocity', velChart);

    let leviChart = new PlotBuffer(500, 60000, [0, 13000], false);
    $chartStore.set('Localisation', leviChart);

    let trr = new PlotBuffer(500, 60000, [0, 50], false)
    trr.addSeries(StrokePresets.theoretical())
    $chartStore.set('Theoretical vs Real run', trr)

    let lvCurrent = new PlotBuffer(500, 60000, [-15, 15], false)
    $chartStore.set('LV Current', lvCurrent)

    let hvCurrent = new PlotBuffer(500, 60000, [-15, 15], false)
    $chartStore.set('HV Current', hvCurrent)

    ///////////////////////////////////////////////////////
    //////////////// BMS REGISTER /////////////////////////
    ///////////////////////////////////////////////////////

    let gdd = GrandDataDistributor.getInstance();
    gdd.stores.registerStore<number>("BatteryEstimatedChargeHigh", 0.0, data => Number(data) / 100);
    gdd.stores.registerStore<number>("BatteryEstimatedChargeLow", 0.0, data => Number(data) / 100);

    gdd.stores.registerStore<number>("Module1AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module1MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module1MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module1AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module1MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module1MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module2AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module2MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module2MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module2AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module2MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module2MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module3AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module3AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module3MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module3MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module4AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module4AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module4MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module4MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module5AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module5AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module5MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module5MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module6AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module6AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module6MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module6MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module7AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MinTemperature", 0.0, tempParse)
    gdd.stores.registerStore<string>("Module7AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module7MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module7MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<number>("Module8AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MinTemperature", 0.0, tempParse);
    gdd.stores.registerStore<string>("Module8AvgVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module8MaxVoltage", "0.0", voltParse);
    gdd.stores.registerStore<string>("Module8MinVoltage", "0.0", voltParse);

    gdd.stores.registerStore<string>("BatteryMinVoltageHigh", "0.0", voltParse);
    gdd.stores.registerStore<string>("BatteryMaxVoltageHigh", "0.0", voltParse);
    gdd.stores.registerStore<string>("BatteryVoltageHigh", "0.0", voltParse);

    gdd.stores.registerStore<number>("BatteryMinTemperatureHigh", 0.0, tempParse);
    gdd.stores.registerStore<number>("BatteryMaxTemperatureHigh", 0.0, tempParse);
    gdd.stores.registerStore<number>("BatteryTemperatureHigh", 0.0, tempParse);

    gdd.stores.registerStore<number>("BatteryTemperatureLow", 0.0, tempParse)
    gdd.stores.registerStore<number>("BatteryMinTemperatureLow", 0.0, tempParse)
    gdd.stores.registerStore<number>("BatteryMaxTemperatureLow", 0.0, tempParse)

    gdd.stores.registerStore<string>("BatteryVoltageLow", "0.0", voltParse)
    gdd.stores.registerStore<string>("BatteryMinVoltageLow", "0.0", voltParse)
    gdd.stores.registerStore<string>("BatteryMaxVoltageLow", "0.0", voltParse)

    gdd.stores.registerStore<number>("TotalBatteryVoltageHigh", 0.0, data => {
        return Number(data) / 100 - 2;
    })
    gdd.stores.registerStore<number>("TotalBatteryVoltageLow", 0.0, data => {
        return Number(data) / 100 - 2;
    })

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

    gdd.stores.registerStore<number>("BatteryEnergyParamsHigh", 0);
    gdd.stores.registerStore<number>("BatteryEnergyParamsLow", 0);

    ////////////////////////////////////////////////////////////////
    ///////////////// PROPULSION REGISTER //////////////////////////
    ////////////////////////////////////////////////////////////////

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
    gdd.stores.registerStore<number>("Acceleration", 0);
    gdd.stores.registerStore<number>("Direction", 0);

    gdd.stores.registerStore<number>("PropulsionCurrent", 0);
    gdd.stores.registerStore<number>("PropulsionSpeed", 0);
    gdd.stores.registerStore<number>("PropulsionVoltage", 0);
    gdd.stores.registerStore<number>("PropulsionVRefInt", 0);

    gdd.stores.registerStore<number>("BrakeTemperature", 0);
    gdd.stores.registerStore<number>("BrakePressure", 0);

    ///////////////////////////////////////////////////////////////
    //////////////////// REGISTER GYROSCOPE ///////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("GyroscopeX", 0, data => {
        const curr: number = Number(data);
        $chartStore.get("Offset Horizontal")?.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("GyroscopeY", 0, data => {
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

    ///////////////////////////////////////////////////////////////
    /////////////////// REGISTER TEMPERATURES /////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("LevitationTemperature", 0);

    gdd.stores.registerStore<number>("Average_Temp_VB_Bottom", 0.0);
    gdd.stores.registerStore<number>("Average_Temp_VB_top", 0.0);
    gdd.stores.registerStore<number>("Ambient_temp", 0.0);

    gdd.stores.registerStore<number>("Temp_HEMS_1", 0.0, data => {
        const curr = Number(data);
        hemsTempChart.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("Temp_HEMS_2", 0.0, data => {
        const curr = Number(data);
        hemsTempChart.addEntry(2, curr);
        return curr;
    })

    gdd.stores.registerStore<number>("Temp_HEMS_3", 0.0, data => {
        const curr = Number(data);
        hemsTempChart.addEntry(3, curr);
        return curr;
    })

    gdd.stores.registerStore<number>("Temp_HEMS_4", 0.0, data => {
        const curr = Number(data);
        hemsTempChart.addEntry(4, curr);
        return curr;
    })


    gdd.stores.registerStore<number>("Temp_EMS_1", 0.0, data => {
        const curr = Number(data);
        emsTempChart.addEntry(1, curr);
        return curr;
    })

    gdd.stores.registerStore<number>("Temp_EMS_2", 0.0, data => {
        const curr = Number(data);
        emsTempChart.addEntry(2, curr);
        return curr;
    })

    ///////////////////////////////////////////////////////////////
    ///////////////////// REGISTER LEVI DATA //////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("levi_hems_gap_a", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_hems_gap_b", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_hems_gap_c", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_hems_gap_d", 0.0, u64ToDouble)

    gdd.stores.registerStore<number>("levi_ems_gap_a", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_ems_gap_b", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_ems_gap_c", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_ems_gap_d", 0.0, u64ToDouble)

    gdd.stores.registerStore<number>("levi_hems_current_a1", 0.0, data => addEntryToChart(hemsCurrentChart, data, 1))
    gdd.stores.registerStore<number>("levi_hems_current_a2", 0.0, data => addEntryToChart(hemsCurrentChart, data, 2))
    gdd.stores.registerStore<number>("levi_hems_current_b1", 0.0, data => addEntryToChart(hemsCurrentChart, data, 3))
    gdd.stores.registerStore<number>("levi_hems_current_b2", 0.0, data => addEntryToChart(hemsCurrentChart, data, 4))
    gdd.stores.registerStore<number>("levi_hems_current_c1", 0.0, data => addEntryToChart(hemsCurrentChart, data, 5))
    gdd.stores.registerStore<number>("levi_hems_current_c2", 0.0, data => addEntryToChart(hemsCurrentChart, data, 6))
    gdd.stores.registerStore<number>("levi_hems_current_d1", 0.0, data => addEntryToChart(hemsCurrentChart, data, 7))
    gdd.stores.registerStore<number>("levi_hems_current_d2", 0.0, data => addEntryToChart(hemsCurrentChart, data, 8))

    gdd.stores.registerStore<number>("levi_ems_current_ab", 0.0, data => addEntryToChart(emsCurrentChart, data, 1))
    gdd.stores.registerStore<number>("levi_ems_current_cd", 0.0, data => addEntryToChart(emsCurrentChart, data, 2))

    gdd.stores.registerStore<number>("levi_hems_airgap", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_hems_pitch", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_hems_roll", 0.0, u64ToDouble)

    gdd.stores.registerStore<number>("levi_ems_offset_ab", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_ems_offset_cd", 0.0, u64ToDouble)

    gdd.stores.registerStore<number>("levi_hems_power", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_ems_power", 0.0, u64ToDouble)

    gdd.stores.registerStore<number>("levi_voltage_a", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_voltage_b", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_voltage_c", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_voltage_d", 0.0, u64ToDouble)
    gdd.stores.registerStore<number>("levi_voltage_e", 0.0, u64ToDouble)

    ///////////////////////////////////////////////////////////////
    ///////////////////////// PNEUMATICS //////////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("LowPressureSensor", 0);
    gdd.stores.registerStore<number>("HighPressureSensor", 0);

    ///////////////////////////////////////////////////////////////
    /////////////////// GROUND FAULT DETECTION ////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("InsulationOriginal", 0);
    gdd.stores.registerStore<number>("InsulationPositive", 0);
    gdd.stores.registerStore<number>("InsulationNegative", 0);
    gdd.stores.registerStore<number>("IMDVoltageDetails", 0);
    gdd.stores.registerStore<number>("IMDIsolationDetails", 0);
    gdd.stores.registerStore<number>("IMDGeneralInfo", 0);

    ///////////////////////////////////////////////////////////////
    ///////////////// REGISTER META & ADDITIONAL //////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("FSMState", 0);

    gdd.start(100);

    initializeStores();
</script>


<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast/>
    <Modal/>
    <TitleBar/>
    <slot/>
    <BottomBar/>
</div>
