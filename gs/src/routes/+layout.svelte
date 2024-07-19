<script lang="ts">
    import '../app.postcss';
    import {
        BottomBar,
        GrandDataDistributor,
        PlotBuffer,
        StrokePresets,
        TitleBar,
        addEntryToChart,
    } from "$lib";
    import {initializeStores, Modal, Toast} from '@skeletonlabs/skeleton';
    import {chartStore, latestTimestamp} from "$lib/stores/state";
    import {initProcedures} from "$lib/stores/data";
    import {onDestroy} from "svelte";
    import {listen} from "@tauri-apps/api/event";
    import {parseShortCut, setBitsToBooleans} from "$lib/util/parsers";
    import { computePosition, autoUpdate, offset, shift, flip, arrow } from '@floating-ui/dom';
    import { storePopup } from '@skeletonlabs/skeleton';
    import {LOCALISATION_NAME} from "$lib/types";

    storePopup.set({ computePosition, autoUpdate, offset, shift, flip, arrow });

    initProcedures();

    const unlisten = listen("shortcut_channel", (event: {payload: string}) => parseShortCut(event.payload));

    //////////////////////////////
    /////////// CHARTS ///////////
    //////////////////////////////

    let breakingCommsChart = new PlotBuffer(500, 60000, [0, 120], true, "Breaking Comms");
    $chartStore.set("Breaking Comms", breakingCommsChart);

    let emsTempChart = new PlotBuffer(500, 60000, [0, 120], true, "EMS 1");
    emsTempChart.addSeries(StrokePresets.theoretical("EMS 2"))
    $chartStore.set("EMS Temperatures", emsTempChart);

    let hemsTempChart = new PlotBuffer(500, 60000, [0, 120], true, "HEMS 1");

    hemsTempChart.addSeries(StrokePresets.theoretical("HEMS 2"))
    hemsTempChart.addSeries(StrokePresets.yellow("HEMS 3"))
    hemsTempChart.addSeries(StrokePresets.blue("HEMS 4"))
    $chartStore.set("HEMS Temperatures", hemsTempChart);

    let hemsCurrentChart = new PlotBuffer(500, 3*60000, [-11.3, 11.3], true, "a1");
    hemsCurrentChart.addSeries(StrokePresets.hyperloopGreenDashed("a2"))
    hemsCurrentChart.addSeries(StrokePresets.theoretical("b1"))
    hemsCurrentChart.addSeries(StrokePresets.theoreticalDashed("b2"))
    hemsCurrentChart.addSeries(StrokePresets.yellow("c1"))
    hemsCurrentChart.addSeries(StrokePresets.yellowDashed("c2"))
    hemsCurrentChart.addSeries(StrokePresets.blue("d1"))
    hemsCurrentChart.addSeries(StrokePresets.blueDashed("d2"))
    $chartStore.set("HEMS Current", hemsCurrentChart);

    let emsCurrentChart = new PlotBuffer(500, 3*60000, [-11.3, 11.3], true);
    emsCurrentChart.addSeries(StrokePresets.theoretical("cd"))
    $chartStore.set("EMS Current", emsCurrentChart);

    let voffChart = new PlotBuffer(500, 60000, [8, 25], false)
    $chartStore.set('Offset Vertical', voffChart);

    let accelChart = new PlotBuffer(500, 60000, [0, 25], false)
    $chartStore.set('Acceleration', accelChart);

    let rolPitchChart = new PlotBuffer(500, 60000, [-0.8, 0.8], true, "roll")
    rolPitchChart.addSeries(StrokePresets.theoretical("pitch"))
    $chartStore.set("Roll Pitch", rolPitchChart)

    let hoffChart = new PlotBuffer(500, 60000, [-8, 8], true, "ab")
    hoffChart.addSeries(StrokePresets.theoretical("cd"))
    $chartStore.set('Offset Horizontal', hoffChart);

    let velChart = new PlotBuffer(500, 60000, [0, 100], false)
    $chartStore.set('Velocity', velChart);

    let localisationChart = new PlotBuffer(500, 60000, [0, 13000], false);
    $chartStore.set('Localisation', localisationChart);

    let trr = new PlotBuffer(500, 60000, [0, 50], false)
    trr.addSeries(StrokePresets.theoretical())
    $chartStore.set('Theoretical vs Real run', trr)

    let lvCurrent = new PlotBuffer(500, 60000, [-15, 15], false)
    $chartStore.set('LV Current', lvCurrent)

    let hvCurrent = new PlotBuffer(500, 60000, [-15, 15], false)
    $chartStore.set('HV Current', hvCurrent)

    let lvTotal = new PlotBuffer(500, 2*60000, [-1, 30], false)
    $chartStore.set('LV Total', lvTotal)

    let hvTotal = new PlotBuffer(500, 2*60000, [-10, 450], false)
    $chartStore.set('HV Total', hvTotal)

    ///////////////////////////////////////////////////////
    //////////////// BMS REGISTER /////////////////////////
    ///////////////////////////////////////////////////////

    let gdd = GrandDataDistributor.getInstance();
    gdd.stores.registerStore<number>("ChargeStateHigh", 0.0);
    gdd.stores.registerStore<number>("ChargeStateLow", 0.0);

    gdd.stores.registerStore<number>("Module1AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module1MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module1MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module1AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module1MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module1MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module2AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module2MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module2MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module2AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module2MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module2MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module3AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module3MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module3MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module3AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module3MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module3MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module4AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module4MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module4MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module4AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module4MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module4MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module5AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module5MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module5MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module5AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module5MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module5MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module6AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module6MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module6MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module6AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module6MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module6MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module7AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module7MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module7MinTemperature", 0.0)
    gdd.stores.registerStore<number>("Module7AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module7MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module7MinVoltage", 0.0);

    gdd.stores.registerStore<number>("Module8AvgTemperature", 0.0);
    gdd.stores.registerStore<number>("Module8MaxTemperature", 0.0);
    gdd.stores.registerStore<number>("Module8MinTemperature", 0.0);
    gdd.stores.registerStore<number>("Module8AvgVoltage", 0.0);
    gdd.stores.registerStore<number>("Module8MaxVoltage", 0.0);
    gdd.stores.registerStore<number>("Module8MinVoltage", 0.0);

    gdd.stores.registerStore<number>("BatteryMinVoltageHigh", 0.0);
    gdd.stores.registerStore<number>("BatteryMaxVoltageHigh", 0.0);
    gdd.stores.registerStore<number>("BatteryVoltageHigh", 0.0);

    gdd.stores.registerStore<number>("BatteryMinTemperatureHigh", 0.0);
    gdd.stores.registerStore<number>("BatteryMaxTemperatureHigh", 0.0);
    gdd.stores.registerStore<number>("BatteryTemperatureHigh", 0.0);

    gdd.stores.registerStore<number>("BatteryTemperatureLow", 0.0)
    gdd.stores.registerStore<number>("BatteryMinTemperatureLow", 0.0)
    gdd.stores.registerStore<number>("BatteryMaxTemperatureLow", 0.0)

    gdd.stores.registerStore<number>("BatteryVoltageLow", 0.0)
    gdd.stores.registerStore<number>("BatteryMinVoltageLow", 0.0)
    gdd.stores.registerStore<number>("BatteryMaxVoltageLow", 0.0)

    gdd.stores.registerStore<number>("TotalBatteryVoltageHigh", 0.0)
    gdd.stores.registerStore<number>("TotalBatteryVoltageLow", 0.0)

    gdd.stores.registerStore<number>("SingleCellVoltageLV1", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV2", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV3", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV4", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV5", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV6", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV7", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageLV8", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV1", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV2", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV3", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV4", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV5", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV6", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV7", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV8", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV9", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV10", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV11", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV12", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV13", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV14", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV15", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV16", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV17", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV18", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV19", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV20", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV21", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV22", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV23", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV24", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV25", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV26", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV27", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV28", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV29", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV30", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV31", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV32", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV33", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV34", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV35", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV36", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV37", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV38", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV39", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV40", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV41", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV42", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV43", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV44", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV45", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV46", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV47", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV48", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV49", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV50", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV51", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV52", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV53", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV54", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV55", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV56", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV57", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV58", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV59", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV60", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV61", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV62", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV63", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV64", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV65", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV66", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV67", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV68", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV69", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV70", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV71", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV72", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV73", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV74", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV75", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV76", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV77", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV78", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV79", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV80", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV81", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV82", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV83", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV84", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV85", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV86", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV87", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV88", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV89", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV90", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV91", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV92", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV93", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV94", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV95", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV96", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV97", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV98", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV99", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV100", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV101", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV102", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV103", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV104", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV105", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV106", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV107", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV108", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV109", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV110", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV111", 0.0);
    gdd.stores.registerStore<number>("SingleCellVoltageHV112", 0.0);


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

    gdd.stores.registerStore<number>("Temp_Motor_1", 0);
    gdd.stores.registerStore<number>("Temp_Motor_2", 0);
    ////////////////////////////////////////////////////////////////
    ///////////////// PROPULSION REGISTER //////////////////////////
    ////////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("Velocity", 0, data => {
        const curr = Number(data);
        $chartStore.get("Velocity")!.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>(LOCALISATION_NAME, 0, data => {
        const curr = Number(data);
        $chartStore.get("Localisation")!.addEntry(1, curr);
        return curr;
    });

    gdd.stores.registerStore<number>("Acceleration", 0);
    gdd.stores.registerStore<number>("Direction", 0);

    gdd.stores.registerStore<number>("PropulsionTemperature", 0);
    gdd.stores.registerStore<number>("PropulsionCurrent", 0);
    gdd.stores.registerStore<number>("PropulsionSpeed", 0);
    gdd.stores.registerStore<number>("PropulsionVoltage", 0);
    gdd.stores.registerStore<number>("PropulsionVRefInt", 0);

    gdd.stores.registerStore<number>("BrakeTemperature", 0);
    gdd.stores.registerStore<number>("BrakePressure", 0);

    ///////////////////////////////////////////////////////////////
    //////////////////// REGISTER GYROSCOPE ///////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("GyroscopeX", 0);
    gdd.stores.registerStore<number>("GyroscopeY", 0);
    gdd.stores.registerStore<number>("GyroscopeZ", 0);
    gdd.stores.registerStore<number>("AccelerationX", 0);
    gdd.stores.registerStore<number>("AccelerationY", 0);
    gdd.stores.registerStore<number>("AccelerationZ", 0);

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

    gdd.stores.registerStore<number>("levi_hems_gap_a", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_b", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_c", 0.0)
    gdd.stores.registerStore<number>("levi_hems_gap_d", 0.0)

    gdd.stores.registerStore<number>("levi_ems_gap_a", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_b", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_c", 0.0)
    gdd.stores.registerStore<number>("levi_ems_gap_d", 0.0)

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

    gdd.stores.registerStore<number>("levi_hems_airgap", 0.0, data => addEntryToChart(voffChart, data, 1))
    gdd.stores.registerStore<number>("levi_hems_roll", 0.0, data => addEntryToChart(rolPitchChart, data, 1))
    gdd.stores.registerStore<number>("levi_hems_pitch", 0.0, data => addEntryToChart(rolPitchChart, data, 2))

    gdd.stores.registerStore<number>("levi_ems_offset_ab", 0.0, data => {
        hoffChart.addEntry(1, data);
        return data;
    })
    gdd.stores.registerStore<number>("levi_ems_offset_cd", 0.0, data => {
        hoffChart.addEntry(2, data);
        return data;
    })

    gdd.stores.registerStore<number>("levi_hems_power", 0.0)
    gdd.stores.registerStore<number>("levi_ems_power", 0.0)

    gdd.stores.registerStore<number>("levi_volt_min", 0.0)
    gdd.stores.registerStore<number>("levi_volt_max", 0.0)
    gdd.stores.registerStore<number>("levi_volt_avg", 0.0)

    ///////////////////////////////////////////////////////////////
    ///////////////////////// PNEUMATICS //////////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("LowPressureSensor", 0);
    gdd.stores.registerStore<number>("HighPressureSensor", 0);
    gdd.stores.registerStore<number>("BrakingCommDebug", 0, data => {
        breakingCommsChart.addEntry(1, data);
        return data;
    });
    gdd.stores.registerStore<number>("BrakingSignalDebug", 0)
    gdd.stores.registerStore<number>("BrakingRearmDebug", 0)

    ///////////////////////////////////////////////////////////////
    /////////////////// GROUND FAULT DETECTION ////////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("InsulationOriginal", 0);
    gdd.stores.registerStore<number>("InsulationPositive", 0);
    gdd.stores.registerStore<number>("InsulationNegative", 0);
    gdd.stores.registerStore<number>("IMDVoltageDetails", 0);

    ///////////////////////////////////////////////////////////////
    ///////////////// REGISTER META & ADDITIONAL //////////////////
    ///////////////////////////////////////////////////////////////

    gdd.stores.registerStore<number>("FSMState", 0);

    gdd.stores.registerStore<boolean[]>("ConnectionStatus", [false, false, false, false, false, false, false, false, false], setBitsToBooleans)

    gdd.start(50);

    initializeStores();

    setInterval(() => {
       latestTimestamp.set(Date.now());
    }, 1000)

    onDestroy(async () => {
      GrandDataDistributor.getInstance().kill();
      (await unlisten)();
    })
</script>


<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast/>
    <Modal/>
    <TitleBar/>
    <slot/>
    <BottomBar/>
</div>

