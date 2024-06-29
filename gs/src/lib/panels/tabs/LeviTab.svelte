<script lang="ts">
    import {Chart, TileGrid, Tile, Table, GrandDataDistributor} from "$lib";

    const gdd = GrandDataDistributor.getInstance().stores;
    const emsGapA = gdd.getStore("levi_ems_gap_a");
    const emsGapB = gdd.getStore("levi_ems_gap_b");
    const emsGapC = gdd.getStore("levi_ems_gap_c");
    const emsGapD = gdd.getStore("levi_ems_gap_d");
    const hemsGapA = gdd.getStore("levi_hems_gap_a");
    const hemsGapB = gdd.getStore("levi_hems_gap_b");
    const hemsGapC = gdd.getStore("levi_hems_gap_c");
    const hemsGapD = gdd.getStore("levi_hems_gap_d");

    $: tableGaps = [
        ["A", $emsGapA, $hemsGapA],
        ["B", $emsGapB, $hemsGapB],
        ["C", $emsGapC, $hemsGapC],
        ["D", $emsGapD, $hemsGapD],
    ]

    const leviVA = gdd.getStore("levi_volt_min");
    const leviVB = gdd.getStore("levi_volt_max");
    const leviVC = gdd.getStore("levi_volt_avg");

    $: leviVolt = [
        ["Min", $leviVA],
        ["Max", $leviVB],
        ["Avg", $leviVC],
    ]

    const leviHemsAG = gdd.getStore("levi_hems_airgap");
    const leviHemsPT = gdd.getStore("levi_hems_pitch");
    const leviHemsRL = gdd.getStore("levi_hems_roll");

    $: leviHems = [
        ["Air Gap", $leviHemsAG],
        ["Pitch", $leviHemsPT],
        ["Roll", $leviHemsRL],
    ]
</script>

<div class="p-4">
    <h2 class="text-xl font-semibold mb-4">Levitation</h2>
    <TileGrid columns="1fr 1fr 1fr 1fr" rows="">
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
        <Tile heading="Gaps">
            <Table background="bg-surface-900" titles={["Gap", "EMS", "HEMS"]} tableArr={tableGaps} />
        </Tile>
        <Tile heading="Levi Voltages" insideClass="flex flex-col justify-center">
            <Table background="bg-surface-900" titles={["Value", "V"]} tableArr={leviVolt} />
        </Tile>
        <Tile heading="Levi Rotation" insideClass="flex flex-col justify-center">
            <Table background="bg-surface-900" titles={["Axis", "Value"]} tableArr={leviHems} />
        </Tile>
    </TileGrid>
    <br>
</div>