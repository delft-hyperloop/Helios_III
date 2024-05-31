<script lang="ts">
    import '../app.postcss';
    import {emit} from "@tauri-apps/api/event";
    import {BottomBar, GrandDataDistributor, PlotBuffer, StrokePresets, TitleBar,} from "$lib";
    import {initializeStores, Toast} from '@skeletonlabs/skeleton';
    import {chartStore} from "$lib/stores/state";
    import type {dataConvFun} from "$lib/types";

    // CHARTS
    let emsChart = new PlotBuffer(1000, [0, 100], false);
    let hemsChart = new PlotBuffer(1000, [0, 100], false);
    emsChart.addSeries(StrokePresets.theoretical())
    emsChart.addSeries(StrokePresets.yellow())
    emsChart.addSeries(StrokePresets.blue())
    hemsChart.addSeries(StrokePresets.theoretical())
    hemsChart.addSeries(StrokePresets.yellow())
    hemsChart.addSeries(StrokePresets.blue())
    $chartStore.set("EMS", emsChart);
    $chartStore.set("HEMS", hemsChart);

    let voffChart = new PlotBuffer(1000, [0, 100], false)
    let hoffChart = new PlotBuffer(1000, [0, 100], false)
    hoffChart.addSeries(StrokePresets.theoretical())
    let velChart = new PlotBuffer(1000, [0, 100], false)

    $chartStore.set('Offset Horizontal', hoffChart);
    $chartStore.set('Offset Vertical', voffChart);
    $chartStore.set('Velocity', velChart);

    let trr = new PlotBuffer(16000, [0, 50], false)
    trr.addSeries(StrokePresets.theoretical())
    $chartStore.set('Theoretical vs Real run', trr)



    ///////////////////////////////////////////////////////
    ///// GRAND DATA DISTRIBUTOR //////////////////////////
    ///////////////////////////////////////////////////////

    let gdd = GrandDataDistributor.getInstance();
    gdd.stores.registerStore<number>("BatteryBalanceHigh", 0.0);
    gdd.stores.registerStore<number>("BatteryBalanceLow", 0.0);
    
    const tempParse:dataConvFun<number> = (data:bigint) => {
        return Number(data) - 100;
    }
    
    const voltParse:dataConvFun<number> = (data:bigint) => {
        return Number(data) / 100 + 2;
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

    gdd.stores.registerStore<number>("Module3AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module3MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module4AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module4MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module5AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module5MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module6AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module6MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module7AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module7MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module8AvgTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MaxTemperature", 0.0, tempParse);
    gdd.stores.registerStore<number>("Module8MinTemperature", 0.0, tempParse);

    gdd.stores.registerStore<number>("Module2AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module2MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module2MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module3AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module3MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module3MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module4AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module4MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module4MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module5AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module5MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module5MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module6AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module6MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module6MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module7AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module7MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module7MinVoltage", 0.0, voltParse);

    gdd.stores.registerStore<number>("Module8AvgVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module8MaxVoltage", 0.0, voltParse);
    gdd.stores.registerStore<number>("Module8MinVoltage", 0.0, voltParse);

    const currParse:dataConvFun<number> = (data:bigint) => {
        return Number(data) / 10;
    }

    gdd.stores.registerStore<number>("BatteryCurrentHigh", 0.0, data => {
        emit('current_hv', {x: 50, y: currParse(data, 0)})

        // TODO: REMOVE THIS, IT'S ONLY FOR TESTING
        emit('speed', {data})

        $chartStore.get("EMS")?.addEntry(1, Math.random()*20);
        $chartStore.get("EMS")?.addEntry(2, 25+Math.random()*20);
        $chartStore.get("EMS")?.addEntry(3, 50+Math.random()*20);
        $chartStore.get("EMS")?.addEntry(4, 75+Math.random()*20);
        $chartStore.get("HEMS")?.addEntry(1, Math.random()*20);
        $chartStore.get("HEMS")?.addEntry(2, 25+Math.random()*20);
        $chartStore.get("HEMS")?.addEntry(3, 50+Math.random()*20);
        $chartStore.get("HEMS")?.addEntry(4, 75+Math.random()*20);

        return Number(data);
    });


    gdd.start(100);

    initializeStores();
    // main listener - update south bridge stores
</script>

<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast/>
    <TitleBar/>
    <slot/>
    <BottomBar/>
</div>
