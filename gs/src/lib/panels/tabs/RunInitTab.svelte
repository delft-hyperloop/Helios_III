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
    import {DatatypeEnum} from "$lib/namedDatatypeEnum";
    import {invoke} from "@tauri-apps/api/tauri";
    import {STATUS} from "$lib/types";
    import {routeConfig} from "$lib/stores/data";

    const storeManager = GrandDataDistributor.getInstance().stores;
    const statuses = storeManager.getWritable("ConnectionStatus")

    export let pop_up: boolean = true;

    let tableArr2:any[][];
    $: tableArr2 = [
        ["Acceleration X", DatatypeEnum.ACCELERATIONX],
        ["Acceleration Y", DatatypeEnum.ACCELERATIONY],
        ["Acceleration Z", DatatypeEnum.ACCELERATIONZ],
        ["Gyroscope X", DatatypeEnum.GYROSCOPEX],
        ["Gyroscope Y", DatatypeEnum.GYROSCOPEY],
        ["Gyroscope Z", DatatypeEnum.GYROSCOPEZ],
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
    let finishRunConfig = () => {
        invoke('send_command', {cmdName: "FinishRunConfig", val: 0}).then(() => {
            console.log(`Command FinishRunConfig sent`);
            modalStore.close();
        });
    }

</script>

<div class="p-4 h-full">
    <h2 class="text-xl font-semibold mb-4">Initialization</h2>

    <TileGrid columns="1fr 1fr 1.5fr" rows="auto 1fr">
        <Tile containerClass="row-span-2" insideClass="flex flex-col gap-2" heading="Run Initialisation">
            <div class="grid grid-cols-2 gap-2">
                <Command cmd="EnablePropulsion" className="btn flex-grow rounded-md bg-surface-700 " />
                <Command cmd="DisablePropulsion" className="btn flex-grow rounded-md bg-surface-700 " />
                <Command cmd="SystemReset" className="btn flex-grow rounded-md bg-surface-700" />
                <Command cmd="ArmBrakes" className="btn flex-grow rounded-md bg-surface-700" />
                <button class="btn rounded-md bg-primary-500 col-span-2" on:click={inputModal} disabled={false}>
                    Configure Run
                </button>
                <button class="btn rounded-md bg-primary-500 col-span-2" on:click={finishRunConfig} disabled={false}>
                    Submit Configuration
                </button>
                <h3 class="col-span-2">Desired speeds</h3>
                <p>Forward A</p>
                <p>{$routeConfig.speeds.ForwardA} m/s</p>
                <p>Forward B</p>
                <p>{$routeConfig.speeds.ForwardB} m/s</p>
                <p>Forward C</p>
                <p>{$routeConfig.speeds.ForwardC} m/s</p>
                <p>Backwards A</p>
                <p>{$routeConfig.speeds.BackwardsA} m/s</p>
                <p>Backwards B</p>
                <p>{$routeConfig.speeds.BackwardsB} m/s</p>
                <p>Backwards C</p>
                <p>{$routeConfig.speeds.BackwardsC} m/s</p>
                <p>Lane Switch Curved</p>
                <p>{$routeConfig.speeds.LaneSwitchCurved} m/s</p>
                <p>Lane Switch Straight</p>
                <p>{$routeConfig.speeds.LaneSwitchStraight} m/s</p>
            </div>
        </Tile>
        <Tile insideClass="grid grid-cols-2 gap-y-2 auto-rows-min" heading="Statuses" >
            <p>Main PCB</p>
            <Status status={$statuses.value[STATUS.MAIN_PCB]} />
            <p>Propulsion</p>
            <Status on="Active" off="Off" status={$statuses.value[STATUS.PROPULSION]} />
            <p>Levitation</p>
            <Status status={$statuses.value[STATUS.LEVITATION]} />
            <p>Sensor Hub</p>
            <Status status={$statuses.value[STATUS.SENSOR_HUB]} />
            <p>LV Batteries</p>
            <Status status={$statuses.value[STATUS.LV_BATTERIES]} />
            <p>HV Batteries</p>
            <Status status={$statuses.value[STATUS.HV_BATTERIES]} />
            <p>Braking PCB</p>
            <Status on="Armed" off="Extended" status={$statuses.value[STATUS.BRAKING_PCB]} />
            <p>Voltage Over 50</p>
            <Status offColor="text-primary-400" off="Safe"
                    onColor="text-error-400" on="UNSAFE"
                    status={$statuses.value[STATUS.VOLTAGE_OVER]} />
        </Tile>
        <Tile heading="Data">
            <Table tableArr={tableArr2} background="bg-surface-900" titles={["important", "variable"]}/>
        </Tile>
        <Tile containerClass="col-span-2">
            <Chart height={250} background="bg-surface-900" title="Velocity" />
        </Tile>
    </TileGrid>
</div>
