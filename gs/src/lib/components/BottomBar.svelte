<script lang="ts">
    import { onMount } from 'svelte';

    let time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', hour12: true });

    onMount(() => {
        const interval = setInterval(() => {
            time = new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit', hour12: true });
        }, 1000);

        return () => {
            clearInterval(interval);
        };
    });
</script>


<footer class="text-zinc-100 text-sm bg-primary-600 w-full flex flex-row flex-nowrap justify-end px-4 gap-4
               border-t border-black">
    <p>Sponsored by goose?</p>
    <p class="">{time}</p>
</footer>