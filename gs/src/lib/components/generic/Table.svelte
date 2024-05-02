<script lang="ts">
    export let tableArr: any[][] = [];
    export let titles = ["Module", "Temp C°"];
    export let background = "bg-surface-800";
</script>


<div class="pt-2 rounded-lg1 {background}">
    <table class="text-sm w-full">
        <thead>
        <tr class="{background} text-center p-4 border-b border-b-surface-700">
            {#each titles as title}
                <th class="font-medium">{title}</th>
            {/each}
        </tr>
        </thead>
        <tbody>
        {#each tableArr as row}
            <tr class="{background} border-b border-b-surface-700">
                {#each row as cell, i}
                    <td class="{i === 0 ? 'px-2' : 'px-4'}
                           {i === row.length-1 ? '' : 'border-r border-r-primary-700'}">
                        {#if typeof cell === "number"}
                            <span class="font-mono">{cell.toFixed(2)}</span>
                        {:else}
                            {cell}
                        {/if}
                    </td>
                {/each}
            </tr>
        {/each}
        </tbody>
    </table>
</div>

