<script lang="ts">

    import {Pneumatics, south_bridge_payload, Tile, TileGrid} from "$lib";
</script>


<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Currents</h2>
    <TileGrid columns="3fr 1fr" rows="">
        <Tile>
            <Pneumatics pressure_left={$south_bridge_payload.value} pressure_right={9-$south_bridge_payload.value} max_pressure={9} />
        </Tile>
    </TileGrid>
</div>