<script lang="ts">
    import {serverStatus, TauriCommand} from "$lib";
    import {getToastStore} from "@skeletonlabs/skeleton";
    import {procedures} from "$lib/stores/data";
    import {parseProcedure} from "$lib/util/parsers";

    const toastStore = getToastStore();

    const handleSuccess = () => {
        toastStore.trigger({
            message: "Server started successfully",
            background: "bg-primary-400",
            timeout: 1500
        });
        serverStatus.set(true);
    };

    const handleFailure = (error:string) => {
        toastStore.trigger({
            message: `Server did not start successfully: ${error}`,
            background: "bg-error-400"
        });
    };

    const parseProcedures = (rawProcedures: string[][]) => {
        procedures.set(rawProcedures.map(parseProcedure));
    };
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
        <TauriCommand cmd="start_server" successCallback={handleSuccess} errorCallback={handleFailure} />
        <TauriCommand cmd="start_levi" />
        <TauriCommand cmd="quit_server" successCallback={() => serverStatus.set(false)} />
        <TauriCommand cmd="quit_levi" />
        <TauriCommand cmd="procedures" textOverride="Refresh Procedures" successCallback={parseProcedures} />
    </div>
    <p><kbd class="kbd">Esc</kbd> to trigger Emergency Braking.</p>
    <p><kbd class="kbd">0</kbd> - <kbd class="kbd">7</kbd> to browse between the tabs of this panel</p>
</div>
