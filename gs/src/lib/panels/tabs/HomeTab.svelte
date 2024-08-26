<script lang="ts">
    import { serverStatus } from '$lib';
    import { getSerpentaContext, TauriCommandButton } from '@delft-hyperloop/serpenta';
    import { getToastStore } from '@skeletonlabs/skeleton';
    import { procedures } from '$lib/stores/data';
    import { parseProcedure } from '$lib/util/parsers';

    const toastStore = getToastStore();
    const handleSuccess = () => {
        toastStore.trigger({
            message: 'Server started successfully',
            background: 'bg-primary-400',
            timeout: 1500,
        });
        serverStatus.set(true);
    };

    const handleFailure = (error: string) => {
        toastStore.trigger({
            message: `Server did not start successfully: ${error}`,
            background: 'bg-error-400',
        });
    };

    const parseProcedures = (rawProcedures: string[][]) => {
        procedures.set(rawProcedures.map(parseProcedure));
    };

    const context = getSerpentaContext();
</script>

<div class="h-full w-full p-4 flex flex-col gap-8 text-surface-50">
    <div class="flex flex-row items-center gap-5">
        <enhanced:img src="/static/images/logo-white.png?w=160" alt="Delft logo" />
        <div class="flex flex-col gap-2">
            <h1 class="text-4xl text-primary-500">Delft Hyperloop Ground Station</h1>
            <div class="text-surface-100">
                <p>Ground station UI.</p>
                <p>Connect to the ground station to control the pod.</p>
            </div>
        </div>
    </div>
    <div>
        <TauriCommandButton options={{}} cmd="connect_to_pod" successCallback={handleSuccess} errorCallback={handleFailure} />
        <TauriCommandButton options={{}} cmd="disconnect" successCallback={() => serverStatus.set(false)} />
        <TauriCommandButton options={{}} cmd="start_levi" />
        <TauriCommandButton options={{}} cmd="quit_levi" />
        <button class="btn py-2 text-black bg-primary-500" on:click={() => context.window_engine.spawnWindow("Chart", "/view")}>
            Window
        </button>
        <TauriCommandButton options={{}} cmd="procedures" textOverride="Refresh Procedures" successCallback={parseProcedures} />
        <TauriCommandButton options={{}} cmd="save_logs" />
    </div>
    <p><kbd class="kbd">Esc</kbd> to trigger Emergency Braking.</p>

</div>
