<script lang="ts">
    import '../app.postcss';
    import {emit} from "@tauri-apps/api/event";
    import {
        BottomBar,
        TitleBar,
        GrandDataDistributor, PlotBuffer, StrokePresets,
    } from "$lib";
    import {initializeStores, Toast} from '@skeletonlabs/skeleton';
    import {chartStore} from "$lib/stores/state";

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
    gdd.stores.registerStore<bigint>("BatteryBalanceHigh", BigInt(0));
    gdd.stores.registerStore<bigint>("BatteryBalanceLow", BigInt(0));

    gdd.stores.registerStore<bigint>("Module1AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module1MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module1MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module1AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module1MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module1MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module2AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module2MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module2MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module3AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module3MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module3MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module4AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module4MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module4MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module5AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module5MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module5MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module6AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module6MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module6MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module7AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module7MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module7MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module8AvgTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module8MaxTemperature", BigInt(0), data => BigInt(data)-BigInt(100));
    gdd.stores.registerStore<bigint>("Module8MinTemperature", BigInt(0), data => BigInt(data)-BigInt(100));

    gdd.stores.registerStore<bigint>("Module2AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module2MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module2MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module3AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module3MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module3MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module4AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module4MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module4MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module5AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module5MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module5MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module6AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module6MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module6MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module7AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module7MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module7MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    gdd.stores.registerStore<bigint>("Module8AvgVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module8MaxVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));
    gdd.stores.registerStore<bigint>("Module8MinVoltage", BigInt(0), data => BigInt(data)/BigInt(100) + BigInt(2));

    // gdd.stores.registerStore<BmsModuleTemperature[]>("BatteryTemperatureHigh", initTemps, (data:bigint, old:BmsModuleTemperature[]) => {
    //     let {id, max, min, avg} = moduleTemperature(data);
    //
    //     let updatedArray = [...old]
    //     updatedArray[Number(id)] = {id, max, min, avg};
    //     return updatedArray;
    // });
    //
    // gdd.stores.registerStore<BmsModuleVoltage[]>("BatteryVoltageHigh", initTemps, (data:bigint, old:BmsModuleTemperature[]) => {
    //     let {id, max, min, avg} = moduleTemperature(data);
    //
    //     let updatedArray = [...old]
    //     updatedArray[Number(id)] = {id, max, min, avg};
    //     return updatedArray;
    // });

    gdd.stores.registerStore<bigint>("BatteryCurrentHigh", BigInt(0), data => {
        emit('current_hv', {x: 50, y: data})

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

        return data;
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
