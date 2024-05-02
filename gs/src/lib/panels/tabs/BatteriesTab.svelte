<script lang="ts">
    import {Battery, Chart, south_bridge_payload} from "$lib";
</script>


<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Batteries</h2>
    <div class="">
        <div class="flex flex-col items-center">
            <Battery height={100} perc={$south_bridge_payload.value+80} />
            <p>Low voltage</p>
        </div>
        <div class="flex flex-col items-center">
            <Battery height={100} perc={$south_bridge_payload.value+80} />
            <p>High voltage</p>
        </div>
        <div>
            <Chart title="aa" refreshRate={100} />
        </div>
    </div>
</div>