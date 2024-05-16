<script lang="ts">
    import '../app.postcss';
    import {onDestroy, onMount} from "svelte";
    import {emit, listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {
        south_bridge_payload,
        BottomBar,
        TitleBar,
        GrandDataDistributor,
        hvBattery,
        lvBattery,
        hvBatCurrent
    } from "$lib";
    import {initializeStores, Toast} from '@skeletonlabs/skeleton';
    import type {BmsModuleTemperature, BmsModuleVoltage} from "$lib/types";
    import {hvModulesTemp, hvModulesVol} from "$lib/stores/data";
    import {moduleTemperature} from "$lib/util/DecodeBMS";
    import {get} from "svelte/store";

    initializeStores();

    // main listener - update south bridge stores
    let unlisten_south: UnlistenFn;

    onMount(async () => {
        // DEPRECATED! USE STORES INSTEAD AND NOT THE SOUTH BRIDGE
        unlisten_south = await listen("south_bridge", (event) => {
            //@ts-ignore
            south_bridge_payload.set(event.payload);
        });

        let gdd = GrandDataDistributor.getInstance();
        gdd.stores.registerStore<bigint>("BatteryBalanceHigh", hvBattery);
        gdd.stores.registerStore<bigint>("BatteryBalanceLow", lvBattery);
        gdd.stores.registerStore<bigint>("BatteryCurrentHigh", hvBatCurrent, data => {
            emit('current_hv', {x: 50, y: data})
            return data;
        });

        gdd.stores.registerStore<BmsModuleTemperature[]>("BatteryTemperatureHigh", hvModulesTemp, data => {
            let {id, max, min, avg} = moduleTemperature(data);

            let updatedArray = [...get(hvModulesTemp)]
            updatedArray[Number(id)] = {id, max, min, avg};
            return updatedArray;
        });

        gdd.stores.registerStore<BmsModuleVoltage[]>("BatteryVoltageHigh", hvModulesVol, data => {
            let {id, max, min, avg} = moduleTemperature(data);

            let updatedArray = [...get(hvModulesVol)];
            updatedArray[Number(id)] = {id, max, min, avg};
            return updatedArray;
        });

        await gdd.start(100);
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
