<script lang="ts">
    export let status: boolean;
    export let on: string = "Connected";
    export let off: string = "Disconnected";
    export let label: string = '';
</script>

<div class="flex gap-2">
    {#if label !== ''}
        <p>{label}:</p>
    {/if}
    {#if status}
        <p class="text-primary-400">{on}</p>
    {:else}
        <p class="text-error-400">{off}</p>
    {/if}
</div>
