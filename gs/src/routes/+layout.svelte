<script lang="ts">
    import '../app.postcss';
    import {onDestroy, onMount} from "svelte";
    import {emit, listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {
        south_bridge_payload,
        BottomBar,
        TitleBar,
        GrandDataDistributor,
    } from "$lib";
    import {initializeStores, Toast} from '@skeletonlabs/skeleton';
    import type {BmsModuleTemperature, BmsModuleVoltage} from "$lib/types";
    import {moduleTemperature} from "$lib/util/DecodeBMS";
    import {initTemps} from "$lib/stores/data";


    let gdd = GrandDataDistributor.getInstance();
    gdd.stores.registerStore<bigint>("BatteryBalanceHigh", BigInt(-1));
    gdd.stores.registerStore<bigint>("BatteryBalanceLow", BigInt(-1));
    gdd.stores.registerStore<bigint>("BatteryCurrentHigh", BigInt(-1), data => {
        emit('current_hv', {x: 50, y: data})

        // TODO: REMOVE THIS, IT'S ONLY FOR TESTING
        emit('speed', {data})
        emit('ems', {values: [Math.random()*20, 25+Math.random()*20, 50+Math.random()*20, 75+Math.random()*20]})
        emit('hems', {values: [Math.random()*20, 25+Math.random()*20, 50+Math.random()*20, 75+Math.random()*20]})

        return data;
    });

    gdd.stores.registerStore<BmsModuleTemperature[]>("BatteryTemperatureHigh", initTemps, (data:bigint, old:BmsModuleTemperature[]) => {
        let {id, max, min, avg} = moduleTemperature(data);

        let updatedArray = [...old]
        updatedArray[Number(id)] = {id, max, min, avg};
        return updatedArray;
    });

    gdd.stores.registerStore<BmsModuleVoltage[]>("BatteryVoltageHigh", initTemps, (data:bigint, old:BmsModuleTemperature[]) => {
        let {id, max, min, avg} = moduleTemperature(data);

        let updatedArray = [...old]
        updatedArray[Number(id)] = {id, max, min, avg};
        return updatedArray;
    });
    gdd.start(100);


    initializeStores();

    // main listener - update south bridge stores
    let unlisten_south: UnlistenFn;

    onMount(async () => {
        // DEPRECATED! USE STORES INSTEAD AND NOT THE SOUTH BRIDGE
        unlisten_south = await listen("south_bridge", (event) => {
            //@ts-ignore
            south_bridge_payload.set(event.payload);
        });

    });

    onDestroy(() => {
        unlisten_south();
    });
</script>

<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast/>
    <TitleBar/>
    <slot/>
    <BottomBar/>
</div>
