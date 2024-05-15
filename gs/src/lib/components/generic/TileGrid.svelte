<script lang="ts">
    export let columns:string;
    export let rows:string;
    export let className:string = '';
</script>

<div class="grid gap-2 {className}" style="grid-template-columns: {columns}; grid-template-rows: {rows};">
    <slot />
</div>