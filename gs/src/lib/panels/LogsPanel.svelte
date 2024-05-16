
<!-- TODO 2: SOME KIND OF LOG FLUSHING? AT ONE POINT IT WILL RUN OUT OF SPACE!  -->

<script lang="ts">
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {afterUpdate, onDestroy, onMount} from "svelte";
    import {EventChannels, type Log} from "$lib/types";

    let unlistens: UnlistenFn[];
    let logContainer: HTMLElement;
    let userHasScrolled = false;
    let logs: Log[] = [];

    let groups = ['STATUS', 'INFO', 'WARNING', 'ERROR'];

    let filters: Record<string, boolean> = { 'STATUS': true, 'WARNING': true, 'INFO': true, 'ERROR': true }; // filter variable

    $: filteredLogs = logs.filter(log => filters[log.log_type]);

    function toggleFilter(type: string) {
        filters[type] = !filters[type];
    }

    function registerChannel(channel: string, log_type: string) {
        return listen(channel, (event) => {
            //@ts-ignore
            logs.push({message: event.payload, log_type, timestamp: Date.now().valueOf()})
        });
    }

    onMount(async () => {
        unlistens[0] = await registerChannel(EventChannels.STATUS, "STATUS");
        unlistens[1] = await registerChannel(EventChannels.INFO, "INFO");
        unlistens[2] = await registerChannel(EventChannels.WARNING, "WARNING");
        unlistens[3] = await registerChannel(EventChannels.ERROR, "ERROR");

        logContainer.addEventListener('scroll', () => {
            userHasScrolled = logContainer.scrollTop < logContainer.scrollHeight - logContainer.clientHeight;
        });
    });

    onDestroy(() =>
        unlistens.forEach(u => u())
);

    afterUpdate(() => {
        // Only scroll to the bottom if the user has not scrolled up
        if (!userHasScrolled) logContainer.scrollTop = logContainer.scrollHeight;
    });
</script>

<div class="h-full">
    <AppBar padding="p-3" background="bg-surface-700 text-surface-50">
        <svelte:fragment slot="lead"><Icon icon="codicon:terminal-bash" /></svelte:fragment>
        Logs
        <svelte:fragment slot="trail">
            <button class="line-through" class:active={filters['STATUS']} on:click={() => toggleFilter('STATUS')}>
                STATUS
            </button>
            <button class="line-through"  class:active={filters['INFO']} on:click={() => toggleFilter('INFO')}>
                INFO
            </button>
            <button class="line-through"  class:active={filters['WARNING']} on:click={() => toggleFilter('WARNING')}>
                WARNING
            </button>
            <button class="line-through"  class:active={filters['ERROR']} on:click={() => toggleFilter('ERROR')}>
                ERROR
            </button>
        </svelte:fragment>
    </AppBar>

    <div class="h-full p-1 pb-16 overflow-y-auto" bind:this={logContainer}>
        {#each filteredLogs as log}
            <div class="flex items-center">
                <p><span class="font-mono font-light">[{log.timestamp}]</span>{log.log_type}: {log.message}</p>
            </div>
        {/each}
        <hr>
    </div>
</div>

<style>
    .active {
        text-decoration: none;
        color: white;
    }
</style>