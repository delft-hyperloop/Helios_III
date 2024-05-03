<script lang="ts">
    import Localiser from "$lib/components/Localiser.svelte";
    import {south_bridge_payload} from "$lib/stores/data";

</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Location & IMU</h2>
    <div class="">
        <Localiser loc={$south_bridge_payload.value} max={10} turning={true}/>
    </div>
</div>