<script lang="ts">
    import { Pane, Splitpanes } from "svelte-splitpanes";
    import VitalsPanel from "$lib/panels/VitalsPanel.svelte";
    import DetailsPanel from "$lib/panels/DetailsPanel.svelte";
    import LogsPanel from "$lib/panels/LogsPanel.svelte";
</script>


<main class="w-full flex-grow border-t border-black overflow-auto">
    <Splitpanes theme="modern-theme" dblClickSplitter={false}>
        <Pane minSize={50} class="rounded-md bg-surface-900">
            <Splitpanes horizontal={true} theme="modern-theme-logs" dblClickSplitter={false}>
                <Pane minSize={50} class="bg-surface-800">
                    <DetailsPanel />
                </Pane>
                <Pane size={20} snapSize={10} minSize={5} class="bg-surface-800">
                    <LogsPanel />
                </Pane>
            </Splitpanes>
        </Pane>
        <Pane maxSize={50} snapSize={10} minSize={2} size={40} class="rounded-md bg-surface-700" >
            <VitalsPanel />
        </Pane>
    </Splitpanes>
</main>

<style global lang="scss">
</style>