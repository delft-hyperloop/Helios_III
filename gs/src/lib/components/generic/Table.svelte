<script lang="ts">
    import type {TempTableEntry} from "$lib/types";
    export let tableArr: TempTableEntry[] = [];
    export let titles = ["Module", "Temp C°"];
    export let background = "bg-surface-800";
</script>


<table class="text-sm w-full">
    <thead>
    <tr class="{background} text-center p-4 border-b border-b-surface-700">
        <th class="p-2 px-8">
            <span class="font-medium">{titles[0]}</span>
        </th>
        <th class="p-2 px-8 w-1/2">
            <span class="font-medium">{titles[1]}</span>
        </th>
    </tr>
    </thead>
    <tbody>
    {#each tableArr as row}
        <tr class="{background} border-b border-b-surface-700">
            <td class="px-4 border-r border-r-primary-700">{row.name}</td>
            <td class="px-4 py-1 font-mono">{row.value.toFixed(2)}</td>
        </tr>
    {/each}
    </tbody>
</table>

