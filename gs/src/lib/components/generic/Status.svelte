<script lang="ts">
    export let status: boolean;
</script>

{#if status}
    <p class="text-primary-400">Connected</p>
{:else}
    <p class="text-error-400">Disconnected</p>
{/if}