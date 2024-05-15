<script lang="ts">
	import '../app.postcss';
    import {onDestroy, onMount} from "svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {north_bridge_payload, south_bridge_payload, BottomBar, TitleBar} from "$lib";
    import { initializeStores, Toast } from '@skeletonlabs/skeleton';
    initializeStores();


    // two main listeners - update north & south bridge stores
    let unlisten_north: UnlistenFn;
    let unlisten_south: UnlistenFn;
    onMount(async () => {
        unlisten_south = await listen("south_bridge", (event) => {
            //@ts-ignore
            south_bridge_payload.set(event.payload);
        });
        unlisten_north = await listen("north_bridge", (event) => {
            //@ts-ignore
            north_bridge_payload.set(event.payload);
        });
    });

    onDestroy(() => {
        unlisten_south();
        unlisten_north();
    });
</script>

<div class="flex flex-col w-screen h-screen max-h-screen overflow-hidden">
    <Toast />
    <TitleBar />
    <slot />
    <BottomBar />
</div>
