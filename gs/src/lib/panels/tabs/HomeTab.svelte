<script>
    import {Command} from "$lib";
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
        <Command command="start_south_bridge" />
        <Command command="start_north_bridge" />
    </div>
    <p><kbd class="kbd">Ctrl</kbd> + <kbd class="kbd">Space</kbd> + <kbd class="kbd">Enter</kbd> to launch Abort operation.</p>
    <p><kbd class="kbd">0</kbd> - <kbd class="kbd">7</kbd> to browse between the tabs of this panel</p>
</div>
