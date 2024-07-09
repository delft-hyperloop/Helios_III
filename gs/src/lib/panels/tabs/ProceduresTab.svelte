<script lang="ts">
    import {AppRail, AppRailTile} from "@skeletonlabs/skeleton";
    import {procedures} from "$lib/stores/data";

    let currentTile: number = 0;
</script>

<div class="h-full flex items-stretch">
    <div>
        <AppRail background="bg-surface-900" aspectRatio="aspect-auto" width="w-50">
            {#each $procedures as procedure, i}
                <AppRailTile regionLabel="text-left px-4" bind:group={currentTile} name={procedure?.name || 'NONE LOADED'} value={i} title={procedure?.title || 'NONE LOADED'}>
                    <p class="py-2 text-base font-medium">{procedure?.name || 'NONE LOADED'}</p>
                </AppRailTile>
            {/each}
        </AppRail>
    </div>
    <div class="p-8 w-10/12 flex-grow flex flex-col gap-4">
        <h2 class="text-2xl font-bold">{$procedures[currentTile]?.title || 'NONE LOADED'}</h2>
        <span>Needed personnel:</span>
        <ul class="list-disc">
            {#each $procedures[currentTile]?.people as person}
                <li class="text-sm">{person}</li>
            {/each}
        </ul>
        <span>Needed equipment:</span>
        <ul class="list-disc">
            {#each $procedures[currentTile]?.equipment as equipment}
                <li class="text-sm">{equipment}</li>
            {/each}
        </ul>
        <p>{$procedures[currentTile]?.content || 'NONE LOADED'}</p>
    </div>
</div>
