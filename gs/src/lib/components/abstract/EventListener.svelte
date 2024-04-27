<script lang="ts">
    import { listen, type UnlistenFn } from '@tauri-apps/api/event';
    import {onDestroy, onMount} from "svelte";
    import type {EventChannel, Payload} from "$lib/types";

    export let channel:EventChannel;
    export let payload: Payload = {
        value: 0,
        values: [],
        timestamp: 0
    };

    let unlisten: UnlistenFn;

    onMount(async () => {
        unlisten = await listen(channel, (event) => {
            //@ts-ignore
            payload = event.payload;
        });
    });

    onDestroy(() => {
        unlisten();
    });
</script>