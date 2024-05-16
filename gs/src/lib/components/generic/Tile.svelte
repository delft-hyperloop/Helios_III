<script lang="ts">
    export let bgToken:number = 900;
    export let insideClass:string = '';
    export let heading:string = '';
    export let containerClass:string = '';
</script>
<div class="bg-surface-{bgToken} p-4 {containerClass} rounded-lg">
    {#if heading !== ''}
        <h3 class="text-lg mb-2 font-normal col-span-full">{heading}</h3>
        <hr class="col-span-full mb-2">
    {/if}
    <div class="{insideClass}">
        <slot />
    </div>
</div>