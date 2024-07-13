<script lang="ts">
  import {
    Table,
    Status,
    Command,
    Tile,
    TileGrid,
    SpeedsInput, GrandDataDistributor, Chart
  } from "$lib";
    import {getModalStore, type ModalComponent} from "@skeletonlabs/skeleton";

    const storeManager = GrandDataDistributor.getInstance().stores;

    const accelX = storeManager.getStore("AccelerationX")
    const accelY = storeManager.getStore("AccelerationY")
    const accelZ = storeManager.getStore("AccelerationZ")
    const gyroX = storeManager.getStore("GyroscopeX")
    const gyroY = storeManager.getStore("GyroscopeY")
    const gyroZ = storeManager.getStore("GyroscopeZ")

    const state = storeManager.getStore("FSMState");

    // const mainpcb_connected = storeManager.getStore("");
    // const propulsion_connected = storeManager.getStore("PropulsionVRefInt");
    // const levitation_connected = storeManager.getStore("");
    // const mainpcb_connected = storeManager.getStore("");
    // const mainpcb_connected = storeManager.getStore("");
    

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
            <div class="grid grid-cols-2 gap-2">
                <Command cmd="StartHV" className="btn flex-grow rounded-md bg-surface-700 " />
                <Command cmd="StopHV" className="btn flex-grow rounded-md bg-surface-700 " />
                <Command cmd="SystemReset" className="btn flex-grow rounded-md bg-surface-700" />
                <Command cmd="ArmBrakes" className="btn flex-grow rounded-md bg-surface-700" />
                <button class="btn rounded-md bg-primary-500 col-span-2" on:click={inputModal} disabled={$state !== 2}>
                    Configure Run
                </button>
            </div>
        </Tile>
        <Tile insideClass="grid grid-cols-2 gap-y-2 auto-rows-min" heading="Statuses" >
            <p>Main PCB</p>
            <Status status={0 % 2 === 1} />
            <p>Propulsion</p>
            <Status on="Active" off="Off" status={0 % 2 === 1} />
            <p>Levitation</p>
            <Status status={0 % 2 === 1} />
            <p>Sensor Hub</p>
            <Status status={0 % 2 === 1} />
            <p>Batteries</p>
            <Status status={0 % 2 === 1} />
            <p>Braking PCB</p>
            <Status on="Armed" off="Extended" status={0 % 2 === 1} />
        </Tile>
        <Tile heading="Data">
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["important", "variable"]}/>
        </Tile>
        <Tile containerClass="col-span-2">
            <Chart height={250} background="bg-surface-900" title="Velocity" />
        </Tile>
    </TileGrid>
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>
