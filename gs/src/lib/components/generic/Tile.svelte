<script lang="ts">
    export let bgToken:number = 900;
    export let col_start:number = -1;
    export let col_span:number = -1;
    export let row_start:number = -1;
    export let row_span:number = -1;
    export let className:string = '';
</script>
<div class="bg-surface-{bgToken} {className}
            {col_start !== -1 ? `col-start-${col_start}` : ''}
            {col_span !== -1 ? `col-span-${col_span}` : ''}
            {row_start !== -1 ? `row-start-${row_start}` : ''}
            {row_span !== -1 ? `row-span-${row_span}` : ''}
            p-4 rounded-lg">
    <slot />
</div>