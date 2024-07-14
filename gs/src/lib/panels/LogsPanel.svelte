
<!-- TODO 2: SOME KIND OF LOG FLUSHING? AT ONE POINT IT WILL RUN OUT OF SPACE!  -->

<script lang="ts">
    import {AppBar, getToastStore} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {afterUpdate, onDestroy, onMount} from "svelte";
    import {EventChannel, type LogType} from "$lib/types";
    import {bigErrorStatus, ErrorStatus} from "$lib/stores/state";

    const toastStore = getToastStore();

    let unlistens: UnlistenFn[] = [];
    let logContainer: HTMLElement;
    let userHasScrolled = false;
    $: logString = "";

    let filters: Record<string, boolean> = { 'STATUS': true, 'WARNING': true, 'INFO': true, 'ERROR': true }; // filter variable

    function toggleFilter(type: string) {
        filters[type] = !filters[type];
    }

    function registerChannel(channel: string, log_type: LogType) {
        return listen(channel, (event: {payload: string}) => {
            logString += `[${Date.now().valueOf()}] ${log_type}: ${event.payload}` + "\r\n"
        });
    }

    onMount(async () => {
        unlistens[0] = await registerChannel(EventChannel.STATUS, 'STATUS');
        unlistens[1] = await listen(EventChannel.INFO, (event: {payload: string}) => {
            logString += `[${Date.now().valueOf()}] INFO: ${event.payload}` + "\r\n"

            const message:string[] = event.payload.split(";");
            toastStore.trigger({
                message: message[0],
                background: message[1],
                timeout: 3000
            });

            switch (message[0]) {
                case "UNSAFE":
                    bigErrorStatus.set(ErrorStatus.UNSAFE)
                    break;
                case "SAFE":
                    bigErrorStatus.set(ErrorStatus.SAFE)
                    break;
            }
        });
        unlistens[2] = await registerChannel(EventChannel.WARNING, 'WARNING')
        unlistens[3] = await registerChannel(EventChannel.ERROR, 'ERROR');

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
        <p class="whitespace-pre-line">{logString}</p>
        <hr>
    </div>
</div>

<style>
    .active {
        text-decoration: none;
        color: white;
    }
</style>