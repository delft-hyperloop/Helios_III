<script lang="ts">
    export let status: boolean;
    export let on: string = "Connected";
    export let off: string = "Disconnected";
    export let label: string = '';
    export let onColor: string = 'text-primary-400';
    export let offColor: string = 'text-error-400';
</script>

<div class="flex gap-2 text-sm">
    {#if label !== ''}
        <p>{label}:</p>
    {/if}
    {#if status}
        <p class={onColor}>{on}</p>
    {:else}
        <p class={offColor}>{off}</p>
    {/if}
</div>
