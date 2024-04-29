<script lang="ts">
    import { onMount } from 'svelte';
    import {south_bridge_payload} from "$lib/stores/data";

    let time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', hour12: true });

    onMount(() => {
        const interval = setInterval(() => {
            time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', hour12: true });
            console.log($south_bridge_payload.timestamp)
        }, 1000);

        return () => {
            clearInterval(interval);
        };
    });
</script>


<footer class="text-zinc-100 text-sm bg-primary-600 w-full flex flex-row flex-nowrap
               justify-end px-4 gap-4 border-t border-black">
    <p>Current state: {$south_bridge_payload.value}</p>
    <p>Sponsored by goose?</p>
    <p class="">{time}</p>
</footer>