<script lang="ts">
    import {AppBar} from "@skeletonlabs/skeleton";
    import Icon from "@iconify/svelte";
    import Command from "$lib/components/abstract/Command.svelte";
</script>

<AppBar padding="p-3" background="bg-surface-700 text-surface-50">
    <svelte:fragment slot="lead"><Icon icon="codicon:terminal-bash" /></svelte:fragment>
    Logs
    <svelte:fragment slot="trail"></svelte:fragment>
</AppBar>