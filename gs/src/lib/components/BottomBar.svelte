<script lang="ts">
    import { onMount } from 'svelte';
    import {GrandDataDistributor} from "$lib";

    let time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', second: '2-digit', hour12: true });

    onMount(() => {
        const interval = setInterval(() => {
            time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', second: '2-digit', hour12: true });
        }, 1000);

        return () => {
            clearInterval(interval);
        };
    });

    const storeManager = GrandDataDistributor.getInstance().stores;
    const fsmState = storeManager.getStore("FSMState");
</script>


<footer class="text-zinc-100 text-sm bg-primary-600 w-full flex flex-row flex-nowrap
               justify-between px-4 gap-4 border-t border-black">
    <p>Delft Hyperloop: Helios III</p>
    <div class="flex gap-4">
        <p>Current state: {$fsmState}</p>
        <p class="">{time}</p>
    </div>
</footer>
