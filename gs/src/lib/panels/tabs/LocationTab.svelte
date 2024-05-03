<script lang="ts">
    import Localiser from "$lib/components/Localiser.svelte";
    import {south_bridge_payload} from "$lib/stores/data";
    import Pneumatics from "$lib/components/Pneumatics.svelte";
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Location & IMU</h2>
    <div class="flex flex-col gap-4">
        <Localiser loc={$south_bridge_payload.value} max={10} turning={true}/>
        <div class="w-7/12">
            <Pneumatics pressure_left={10 - $south_bridge_payload.value} pressure_right={$south_bridge_payload.value} max_pressure={10}/>
        </div>
    </div>
</div>