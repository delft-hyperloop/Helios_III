<script lang="ts">

import {AppRail} from "@skeletonlabs/skeleton";
import Chart from "$lib/components/generic/Chart.svelte";
import Command from "$lib/components/abstract/Command.svelte";
</script>


<main class="bg-surface-800 flex-grow border-t border-black
             flex flex-nowrap flex-row">
    <!-- !IMPORTANT  -->
    <div class="w-2/3">
        <Command command="start_north_bridge" />
        <AppRail>

        </AppRail>
    </div>
    <div class="w-1/3 bg-surface-700 border-l border-r border-black p-4">
        <Chart refreshRate={5} />
        <Chart refreshRate={100} />
    </div>
</main>

<style lang="css">

</style>