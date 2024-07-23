<script lang="ts">
  import {Chart, TileGrid, Tile, Table, Command} from "$lib";
    import {DatatypeEnum as DE} from "$lib/namedDatatypeEnum";

    $: tableGaps = [
        ["A", DE.LEVI_EMS_GAP_A, DE.LEVI_HEMS_GAP_A],
        ["B", DE.LEVI_EMS_GAP_B, DE.LEVI_HEMS_GAP_B],
        ["C", DE.LEVI_EMS_GAP_C, DE.LEVI_HEMS_GAP_C],
        ["D", DE.LEVI_EMS_GAP_D, DE.LEVI_HEMS_GAP_D],
    ]

    $: leviVolt = [
        ["Min", DE.LEVI_VOLT_MIN],
        ["Max", DE.LEVI_VOLT_MAX],
        ["Avg", DE.LEVI_VOLT_AVG],
    ]

    $: leviHems = [
        ["Air Gap", DE.LEVI_HEMS_AIRGAP],
        ["Pitch", DE.LEVI_HEMS_PITCH],
        ["Roll", DE.LEVI_HEMS_ROLL],
    ]

    export const pop_up: boolean = true;
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Levitation</h2>

    <TileGrid columns="1fr 1fr 1fr 1fr" rows="">
        <Tile heading="Levi Control" insideClass="flex gap-x-4" containerClass="col-span-4">
            <Command cmd="launch" />
            <Command cmd="land" />
            <Command cmd="vert0" text="Vertical 0 current" />
            <Command cmd="vert_mode_dance" text="Vertical Dance" />
            <Command cmd="vert_mode_sine" text="Vertical Sine" />
            <Command cmd="vert0_reset" text="Reset Vertical 0 current" />
        </Tile>
        <Tile heading="Gaps" containerClass="col-span-2">
            <Table background="bg-surface-900" titles={["Gap", "EMS", "HEMS"]} tableArr={tableGaps} />
        </Tile>
        <Tile heading="Levi Voltages" insideClass="flex flex-col justify-center">
            <Table background="bg-surface-900" titles={["Value", "V"]} tableArr={leviVolt} />
        </Tile>
        <Tile heading="Levi Rotation" insideClass="flex flex-col justify-center">
            <Table background="bg-surface-900" titles={["Axis", "Value"]} tableArr={leviHems} />
        </Tile>
        <Tile containerClass="col-span-4">
            <Chart title="HEMS Current" background="bg-surface-900" height={300} />
        </Tile>
        <Tile containerClass="col-span-4">
            <Chart title="EMS Current" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2">
            <Chart title="HEMS Temperatures" background="bg-surface-900" />
        </Tile>
        <Tile containerClass="col-span-2">
            <Chart title="EMS Temperatures" background="bg-surface-900" />
        </Tile>
    </TileGrid>
    <br>
</div>

