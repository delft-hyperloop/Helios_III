<script lang="ts">
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {afterUpdate, onDestroy, onMount} from "svelte";
    import type {Log} from "$lib/types";

    let unlisten: UnlistenFn;

    let logs: Log[] = [];
    let filters: Record<string, boolean> = { 'brake': true, 'fsm': true, 'levi': true, 'prop': true }; // filter variable

    $: filteredLogs = logs.filter(log => filters[log.log_type]);

    onMount(async () => {
        unlisten = await listen('logs_bridge', (event) => {
            //@ts-ignore
            logs = [...logs, {message: event.payload.message, log_type: event.payload.log_type, timestamp: event.payload.timestamp}];
        });
    });

    onDestroy(() => {
        unlisten();
    });

    let logContainer: HTMLElement;
    afterUpdate(() => {
        logContainer.scrollTop = logContainer.scrollHeight;
    });


    function toggleFilter(type: string) {
        filters[type] = !filters[type];
    }
</script>

<div class="h-full">
    <AppBar padding="p-3" background="bg-surface-700 text-surface-50">
        <svelte:fragment slot="lead"><Icon icon="codicon:terminal-bash" /></svelte:fragment>
        Logs
        <svelte:fragment slot="trail">
            <button class="line-through" class:active={filters['brake']} on:click={() => toggleFilter('brake')}>
                FSM
            </button>
            <button class="line-through"  class:active={filters['fsm']} on:click={() => toggleFilter('fsm')}>
                BRAKE
            </button>
            <button class="line-through"  class:active={filters['levi']} on:click={() => toggleFilter('levi')}>
                LEVI
            </button>
            <button class="line-through"  class:active={filters['prop']} on:click={() => toggleFilter('prop')}>
                PROP
            </button>
        </svelte:fragment>
    </AppBar>

    <div class="h-full p-1 pb-16 overflow-y-auto font-mono" bind:this={logContainer}>
        {#each filteredLogs as log}
            <div class="flex items-center">
                <p>[{log.timestamp}]  {log.log_type}: {log.message}</p>
            </div>
        {/each}
    </div>
</div>

<style>
    .active {
        text-decoration: none;
        color: white;
    }
</style>