
<!-- TODO 2: SOME KIND OF LOG FLUSHING? AT ONE POINT IT WILL RUN OUT OF SPACE!  -->

<script lang="ts">
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {afterUpdate, onDestroy, onMount} from "svelte";
    import {EventChannel, type Log, type LogType} from "$lib/types";

    let unlistens: UnlistenFn[] = [];
    let logContainer: HTMLElement;
    let userHasScrolled = false;
    let logs: Log[] = [];

    let colours = new Map([
      ['STATUS', 'text-surface-50'],
      ['WARNING', 'text-warning-400'],
      ['INFO', 'text-surface-300'],
      ['ERROR', 'text-error-500']
    ]);

    let filters: Record<string, boolean> = { 'STATUS': true, 'WARNING': true, 'INFO': true, 'ERROR': true }; // filter variable

    $: filteredLogs = logs.filter(log => filters[log.log_type]);

    function toggleFilter(type: string) {
        filters[type] = !filters[type];
    }

    function registerChannel(channel: string, log_type: LogType) {
      return listen(channel, (event: {payload: string}) => {
        logs = [...logs, {message: event.payload, log_type, timestamp: Date.now().valueOf()}]
      });
    }

    function clearLogs() {
      logs = [];
    }

    onMount(async () => {
        unlistens[0] = await registerChannel(EventChannel.STATUS, 'STATUS');

        unlistens[1] = await listen(EventChannel.INFO, (event: {payload: string}) => {
          logs = [...logs, {message: event.payload.split(';')[0], log_type: 'INFO', timestamp: Date.now().valueOf()}]
        });

        unlistens[2] = await registerChannel(EventChannel.WARNING, 'WARNING');
        unlistens[3] = await registerChannel(EventChannel.ERROR, 'ERROR');

        unlistens[4] = await listen("clear_logs", () => clearLogs());

        logContainer.addEventListener('scroll', () => {
            userHasScrolled = logContainer.scrollTop < logContainer.scrollHeight - logContainer.clientHeight;
        });
    });

    onDestroy(() =>
        unlistens.forEach(u => u())
    );

    afterUpdate(() => {
        if (!userHasScrolled) logContainer.scrollTop = logContainer.scrollHeight;
    });
</script>

<div class="h-full">
    <AppBar padding="p-3" background="bg-surface-700 text-surface-50">
        <svelte:fragment slot="lead"><Icon icon="codicon:terminal-bash" /></svelte:fragment>
        Logs
        <svelte:fragment slot="trail">
            <button class="btn rounded-lg text-sm" on:click={clearLogs}>
                Clear logs
            </button>
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
                <p class="{colours.get(log.log_type)}"><span class="font-mono font-light">[{log.timestamp}]</span>{log.log_type}: {log.message}</p>
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
