<script lang="ts">
    import {
        Table,
        TheoreticalRun,
        Status,
        inputSpeed,
        inputTurn,
        Command,
        Tile,
        TileGrid,
        TauriCommand,
        type IntervalFunction,
        RunMode,
        SpeedsInput, GrandDataDistributor
    } from "$lib";
    import {inputEmerg, inputPosit} from "$lib/stores/state";
    import {getModalStore, type ModalComponent} from "@skeletonlabs/skeleton";

    const storeManager = GrandDataDistributor.getInstance().stores;

    const accelX = storeManager.getStore("AccelerationX")
    const accelY = storeManager.getStore("AccelerationY")
    const accelZ = storeManager.getStore("AccelerationZ")
    const gyroX = storeManager.getStore("GyroscopeX")
    const gyroY = storeManager.getStore("GyroscopeY")
    const gyroZ = storeManager.getStore("GyroscopeZ")

    let calculateTheoretical:IntervalFunction;
    let clearRuns: () => void;

    let tableArr2:any[][];
    $: tableArr2 = [
        ["Acceleration X", $accelX],
        ["Acceleration Y", $accelY],
        ["Acceleration Z", $accelZ],
        ["Gyroscope X", $gyroX],
        ["Gyroscope Y", $gyroY],
        ["Gyroscope Z", $gyroZ],
    ]

    const modalStore = getModalStore();

    const input:ModalComponent = {ref: SpeedsInput};
    let inputModal = () => {
        modalStore.trigger({
            type: "component",
            component: input,
            title: "Run Configuration",
        })
    }
</script>

<div class="p-4 h-full">
    <h2 class="text-xl font-semibold mb-4">Initialization</h2>
    <TileGrid columns="1fr 1fr 1.5fr" rows="auto 1fr">
        <Tile containerClass="row-span-2" insideClass="flex flex-col gap-2" heading="Run Initialisation">
            <div class="flex justify-between col-span-2">
                <button class="btn flex-grow bg-surface-700 rounded-none rounded-l-lg p-2" type="button"
                        class:active={$inputTurn === RunMode.ShortRun}
                        on:click={() => inputTurn.set(RunMode.ShortRun)}>
                    Short run
                </button>
                <button class="btn flex-grow bg-surface-700 rounded-none p-2" type="button"
                        class:active={$inputTurn === RunMode.LeftSwitch}
                        on:click={() => inputTurn.set(RunMode.LeftSwitch)}>
                    Left switch
                </button>
                <button class="btn flex-grow bg-surface-700 rounded-none rounded-r-lg p-2" type="button"
                        class:active={$inputTurn === RunMode.RightSwitch}
                        on:click={() => inputTurn.set(RunMode.RightSwitch)}>
                    Right switch
                </button>
            </div>
            <div>
                <label for="speed_input">Speed: </label>
                <input name="speed_input" bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
                <label for="pos_input">Braking Point position: </label>
                <input name="pos_input" bind:value={$inputPosit} class="input rounded-md px-2 col-span-2" type="number" min="0" max="60000" step="1">
                <label for="accel_input">Acceleration: </label>
                <input name="accel_input" bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
                <label for="emerg_point">Emergency Braking Location: </label>
                <input name="emerg_point" bind:value={$inputEmerg} class="input rounded-md px-2 col-span-2" type="number" min="0" max="60000" step="1">
            </div>
            <div class="flex-grow" />
            <div class="grid grid-cols-2 gap-2">
                <TauriCommand cmd="start_server" className="btn rounded-md bg-surface-700  col-span-2" />
                <Command cmd="StartHV" className="btn flex-grow rounded-md bg-surface-700 " />
                <Command cmd="StopHV" className="btn flex-grow rounded-md bg-surface-700 " />
<!--                <Command cmd="Levitate" className="btn flex-grow rounded-md bg-surface-700 " />-->
<!--                <Command cmd="StopLevitating" className="btn flex-grow rounded-md bg-surface-700 " />-->
                <button class="btn rounded-md bg-primary-500 col-span-2" on:click={inputModal}>
                    Run Config
                </button>
                <button class="btn rounded-md col-span-2 bg-surface-700 " type="button" on:click={calculateTheoretical}>
                    Calculate theoretical run
                </button>
                <button class="btn rounded-md col-span-2 bg-surface-700 " type="button" on:click={clearRuns} >
                    Clear runs
                </button>
                <Command cmd="SystemReset" className="btn flex-grow rounded-md bg-surface-700" />
                <Command cmd="ArmBrakes" className="btn flex-grow rounded-md bg-surface-700" />
            </div>
        </Tile>
        <Tile insideClass="grid grid-cols-2 gap-y-2 auto-rows-min" heading="Statuses" >
            <p>Helios III</p>
            <Status status={0 % 2 === 0} />
            <p>Propulsion:</p>
            <Status status={0 % 2 === 1} />
            <p>Levitation:</p>
            <Status status={0 % 2 === 0} />
            <p>PTC:</p>
            <Status status={0 % 2 === 0} />
            <p>Localization:</p>
            <Status status={0 % 2 === 1} />
            <p>Breaking PCB:</p>
            <Status on="armed" off="unarmed" status={0 % 2 === 0} />
        </Tile>
        <Tile heading="Data">
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["important", "variable"]}/>
        </Tile>
        <Tile containerClass="col-span-2">
            <TheoreticalRun xDataCount={100} bind:clearRuns={clearRuns} bind:calculateTheoretical={calculateTheoretical}/>
        </Tile>
    </TileGrid>
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>