<script lang="ts">
    import { Pane, Splitpanes } from "svelte-splitpanes";
    import VitalsPanel from "$lib/panels/VitalsPanel.svelte";
    import DetailsPanel from "$lib/panels/DetailsPanel.svelte";
    import LogsPanel from "$lib/panels/LogsPanel.svelte";

    import { getToastStore } from '@skeletonlabs/skeleton';
    import {listen, type UnlistenFn} from "@tauri-apps/api/event";
    import {onDestroy, onMount} from "svelte";
    import {details_pane, vitals_pane} from "$lib";
    import {EventChannel} from "$lib/types";
    import {bigErrorStatus, ErrorStatus} from "$lib/stores/state";

    let unlisten_status: UnlistenFn;
    const toastStore = getToastStore();

    onMount(async () => {
        unlisten_status = await listen(EventChannel.INFO, (event: {payload: string}) => {
        const message:string[] = event.payload.split(";");
        toastStore.trigger({
          message: message[0],
          background: message[1] || "bg-surface-600",
        });

        switch (message[0]) {
          case "Unsafe":
            bigErrorStatus.set(ErrorStatus.UNSAFE)
            break;
          case "Safe":
            bigErrorStatus.set(ErrorStatus.SAFE)
            break;
        }
      });
    });

    onDestroy(() => {
        unlisten_status();
    });
</script>

<main class="w-full flex-grow border-t border-black overflow-auto">
    <Splitpanes theme="modern-theme" dblClickSplitter={false} on:resize={(event) => vitals_pane.set(event.detail[0].size)}>
        <Pane maxSize={50} snapSize={10} minSize={2} size={40} class="rounded-md bg-surface-700" >
            <VitalsPanel />
        </Pane>
        <Pane minSize={50} class="rounded-md bg-surface-900">
            <Splitpanes horizontal={true} theme="modern-theme-logs" dblClickSplitter={false} on:resize={(event) => details_pane.set(event.detail[0].size)}>
                <Pane minSize={50} class="bg-surface-800">
                    <DetailsPanel />
                </Pane>
                <Pane size={30} snapSize={10} minSize={5} class="bg-surface-800">
                    <LogsPanel />
                </Pane>
            </Splitpanes>
        </Pane>
    </Splitpanes>
</main>