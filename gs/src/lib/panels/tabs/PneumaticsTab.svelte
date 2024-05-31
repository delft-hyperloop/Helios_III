<script lang="ts">

    import {Pneumatics, Tile, TileGrid} from "$lib";
</script>


<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Pneumatics</h2>
    <TileGrid columns="3fr 1fr" rows="">
        <Tile>
            <Pneumatics pressure_left={Math.random()*9} pressure_right={9-Math.random()*9} max_pressure={9} />
        </Tile>
    </TileGrid>
</div>