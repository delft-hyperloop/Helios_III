<script lang="ts">
    export let status: boolean;
    export let on: string = "Connected";
    export let off: string = "Disconnected";
</script>

{#if status}
    <p class="text-primary-400">{on}</p>
{:else}
    <p class="text-error-400">{off}</p>
{/if}