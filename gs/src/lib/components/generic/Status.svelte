<script lang="ts">
    export let status: boolean;
</script>

{#if status}
    <p class="text-primary-400">armed</p>
{:else}
    <p class="text-error-400">unarmed</p>
{/if}