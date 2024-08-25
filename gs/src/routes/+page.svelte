<script lang="ts">
    import VitalsPanel from "$lib/panels/VitalsPanel.svelte";
    import DetailsPanel from "$lib/panels/DetailsPanel.svelte";
    import LogsPanel from "$lib/panels/LogsPanel.svelte";
    import { PanelBase } from '@delft-hyperloop/serpenta';
</script>

<PanelBase>
    <VitalsPanel slot="VITALS_PANEL" />
    <DetailsPanel slot="DETAILS_PANEL" />
    <LogsPanel slot="LOGS_PANEL" />
</PanelBase>
