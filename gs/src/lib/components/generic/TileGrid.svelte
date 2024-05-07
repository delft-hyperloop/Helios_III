<script lang="ts">
    export let columns:string;
    export let rows:string;
</script>

<div class="grid gap-2" style="grid-template-columns: {columns}; grid-template-rows: {rows};">
    <slot />
</div>