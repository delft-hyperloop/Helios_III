<script lang="ts">
    import { onMount } from 'svelte';
    import {GrandDataDistributor} from "$lib";
    import {bigErrorStatus} from "$lib/stores/state";

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
    const fsmState = storeManager.getWritable("FSMState");
</script>

<!---->
<!-- <button class="btn" on:click={() => bigErrorStatus.set(0)}> -->
<!--     change to 0 -->
<!-- </button> -->
<!-- <button class="btn" on:click={() => bigErrorStatus.set(1)}> -->
<!--     change to 1 -->
<!-- </button> -->
<!-- <button class="btn" on:click={() => bigErrorStatus.set(2)}> -->
<!--     change to 2 -->
<!-- </button> -->

<footer class="text-zinc-100 text-sm {$bigErrorStatus === 0 ? 'bg-primary-600' :
               $bigErrorStatus === 1 ? 'bg-warning-500' : 'bg-error-500'} w-full flex
               flex-row flex-nowrap justify-between px-4 gap-4 border-t border-black">
    <p>Delft Hyperloop: Helios III</p>
    <div class="flex gap-4">
        <p>Current state: {$fsmState.value}</p>
        <p class="">{time}</p>
    </div>
</footer>
