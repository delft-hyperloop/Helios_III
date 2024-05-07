<script lang="ts">
    import { Pane, Splitpanes } from "svelte-splitpanes";
    import VitalsPanel from "$lib/panels/VitalsPanel.svelte";
    import DetailsPanel from "$lib/panels/DetailsPanel.svelte";
    import LogsPanel from "$lib/panels/LogsPanel.svelte";

    import { getToastStore } from '@skeletonlabs/skeleton';
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {onDestroy, onMount} from "svelte";
    import {details_pane, vitals_pane} from "$lib";

    let unlisten_error: UnlistenFn;
    const toastStore = getToastStore();

    onMount(async () => {
        unlisten_error = await listen("error_bridge", (event) => {
            toastStore.trigger({
                //@ts-ignore
                message: event.payload.message,
                background: 'variant-filled-error',
            });
        });
    });

    onDestroy(() => {
        unlisten_error();
    });

    let style: string;
    $: style = `height: ${$details_pane-5}vh`;
</script>

<main class="w-full flex-grow border-t border-black overflow-auto">
    <Splitpanes theme="modern-theme" dblClickSplitter={false} on:resize={(event) => vitals_pane.set(event.detail[0].size)}>
        <Pane maxSize={50} snapSize={10} minSize={2} size={40} class="rounded-md bg-surface-700" >
            <VitalsPanel />
        </Pane>
        <Pane minSize={50} class="rounded-md bg-surface-900">
            <Splitpanes horizontal={true} theme="modern-theme-logs" dblClickSplitter={false} on:resize={(event) => details_pane.set(event.detail[0].size)}>
                <Pane minSize={50} class="bg-surface-800">
                    <div style={style} class="snap-x scroll-px-4 snap-mandatory scroll-smooth overflow-x-auto">
                        <DetailsPanel />
                    </div>
                </Pane>
                <Pane size={20} snapSize={10} minSize={5} class="bg-surface-800">
                    <LogsPanel />
                </Pane>
            </Splitpanes>
        </Pane>
    </Splitpanes>
</main>

<style global lang="scss">
</style>