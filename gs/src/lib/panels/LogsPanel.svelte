
<!-- TODO: ADD IMPORTANCE TO LOGS, MAKE SUPER IMPORTANT LOG "UN-FILTERABLE"  -->

<!-- TODO 2: SOME KIND OF LOG FLUSHING? AT ONE POINT IT WILL RUN OUT OF SPACE!  -->

<script lang="ts">
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {afterUpdate, onDestroy, onMount} from "svelte";
    import type {Log} from "$lib/types";

    let unlisten: UnlistenFn;
    let logContainer: HTMLElement;
    let userHasScrolled = false;
    let logs: Log[] = [];
    let filters: Record<string, boolean> = { 'brake': true, 'fsm': true, 'levi': true, 'prop': true }; // filter variable

    $: filteredLogs = logs.filter(log => filters[log.log_type]);

    function toggleFilter(type: string) {
        filters[type] = !filters[type];
    }

    onMount(async () => {
        unlisten = await listen('logs_bridge', (event) => {
            //@ts-ignore
            logs = [...logs, {message: event.payload.message, log_type: event.payload.log_type, timestamp: event.payload.timestamp}];
        });

        logContainer.addEventListener('scroll', () => {
            userHasScrolled = logContainer.scrollTop < logContainer.scrollHeight - logContainer.clientHeight;
        });
    });

    onDestroy(() => {
        unlisten();
    });

    afterUpdate(() => {
        // Only scroll to the bottom if the user has not scrolled up
        if (!userHasScrolled) {
            logContainer.scrollTop = logContainer.scrollHeight;
        }
    });
</script>

<div class="h-full">
    <AppBar padding="p-3" background="bg-surface-700 text-surface-50">
        <svelte:fragment slot="lead"><Icon icon="codicon:terminal-bash" /></svelte:fragment>
        Logs
        <svelte:fragment slot="trail">
            <button class="line-through" class:active={filters['brake']} on:click={() => toggleFilter('brake')}>
                BRAKE
            </button>
            <button class="line-through"  class:active={filters['fsm']} on:click={() => toggleFilter('fsm')}>
                FSM
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