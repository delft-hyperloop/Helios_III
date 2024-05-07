<script lang="ts">
    import {south_bridge_payload, Table, TheoreticalRun, Status, inputSpeed, Command, Tile, TileGrid} from "$lib";
    import type {IntervalFunction} from "$lib/types";

    enum Mode {
        ShortRun = 1,
        LeftSwitch = 2,
        RightSwitch = 3
    }

    let selectedMode:Mode = Mode.ShortRun;
    let calculateTheoretical:IntervalFunction;
    let clearRuns: () => void;

    let tableArr2:any[][];
    $: tableArr2 = [
        ["Some", $south_bridge_payload.value],
        ["Important", $south_bridge_payload.value],
        ["Value", $south_bridge_payload.value],
        ["That", $south_bridge_payload.value],
        ["Could", $south_bridge_payload.value],
        ["stay", $south_bridge_payload.value],
        ["as a", $south_bridge_payload.value],
        ["table entry", $south_bridge_payload.value],
        ["here", $south_bridge_payload.value]
    ]
</script>

<div class="p-4 h-full">
    <h2 class="text-xl font-semibold mb-4">Initialization</h2>
    <TileGrid columns="1fr 1fr 1.5fr" rows="auto 2fr">
        <Tile row_span={2} className="flex flex-col gap-2">
            <h3 class="col-span-2 font-medium text-lg">Run initialisation</h3>
            <hr class="col-span-2">
            <p>Mode: </p>
            <div class="flex justify-between col-span-2">
                <button class="btn flex-grow bg-surface-700 rounded-none rounded-l-lg p-2" type="button" class:active={selectedMode === 1} on:click={() => selectedMode = Mode.ShortRun}>
                    Short run
                </button>
                <button class="btn flex-grow bg-surface-700 rounded-none p-2" type="button" class:active={selectedMode === 2} on:click={() => selectedMode = Mode.LeftSwitch}>
                    Left switch
                </button>
                <button class="btn flex-grow bg-surface-700 rounded-none rounded-r-lg p-2" type="button" class:active={selectedMode === 3} on:click={() => selectedMode = Mode.RightSwitch}>
                    Right switch
                </button>
            </div>
            <div>
                <label for="speed_input">Speed: </label>
                <input name="speed_input" bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
                <label for="pos_input">Position: </label>
                <input name="pos_input" bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
                <label for="accel_input">Acceleration: </label>
                <input name="accel_input" bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
            </div>
            <div class="flex-grow"></div>
            <div class="grid grid-cols-2 gap-2">
                <Command command="establish_connection" classes="btn rounded-md bg-surface-700  col-span-2" />
                <Command command="start_hv" classes="btn flex-grow rounded-md bg-surface-700 " />
                <Command command="stop_hv" classes="btn flex-grow rounded-md bg-surface-700 " />
                <Command command="levitate" classes="btn flex-grow rounded-md bg-surface-700 " />
                <Command command="stop_levitating" classes="btn flex-grow rounded-md bg-surface-700 " />
                <Command command="start_run" classes="btn rounded-md bg-primary-500 col-span-2" />
                <button class="btn rounded-md col-span-2 bg-surface-700 " type="button" on:click={calculateTheoretical}>
                    Calculate theoretical run
                </button>
                <button class="btn rounded-md col-span-2 bg-surface-700 " type="button" on:click={clearRuns} >
                    Clear runs
                </button>
            </div>
        </Tile>
        <Tile row_span={1} className="grid grid-cols-2 gap-y-2 auto-rows-min">
            <h3 class="text-lg font-normal col-span-2">Statuses</h3>
            <hr class="col-span-2">
            <p>Helios III</p>
            <Status status={$south_bridge_payload.value % 2 === 0} />
            <p>Propulsion:</p>
            <Status status={$south_bridge_payload.value % 2 === 1} />
            <p>Levitation:</p>
            <Status status={$south_bridge_payload.value % 2 === 0} />
            <p>PTC:</p>
            <Status status={$south_bridge_payload.value % 2 === 0} />
            <p>Localization:</p>
            <Status status={$south_bridge_payload.value % 2 === 1} />
            <p>Prop Thermal:</p>
            <Status status={$south_bridge_payload.value % 2 === 0} />
            <p>Levi Thermal:</p>
            <Status status={$south_bridge_payload.value % 2 === 1} />
        </Tile>
        <Tile>
            <h3 class="text-lg mb-2 font-normal">Data:</h3>
            <hr>
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["important", "variable"]}/>
        </Tile>
        <Tile col_span={2}>
            <TheoreticalRun bind:clearRuns={clearRuns} bind:calculateTheoretical={calculateTheoretical}/>
        </Tile>
    </TileGrid>
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>