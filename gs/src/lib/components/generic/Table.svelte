<script lang="ts">
    import type {TempTableEntry} from "$lib/types";
    export let tableArr: TempTableEntry[] = [];

    export let titles = ["Module", "Temp C°"];
</script>


<table class="text-sm w-full">
    <thead>
    <tr class="bg-surface-800 text-center p-4">
        <th class="p-2 px-8">
            <span class="font-medium">{titles[0]}</span>
        </th>
        <th class="p-2 px-8 w-1/2">
            <span class="font-medium text-center">{titles[1]}</span>
        </th>
    </tr>
    </thead>
    <tbody>
    {#each tableArr as row, i}
        <tr class="bg-surface-800">
            <td class="px-4 border-r border-r-primary-600">{row.name}</td>
            <td class="px-4 py-1 font-mono">{row.value.toFixed(2)}</td>
        </tr>
    {/each}
    </tbody>
</table>

