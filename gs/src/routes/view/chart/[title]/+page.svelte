<script lang="ts">
    import { Chart } from "$lib"
    import type { PageData } from './$types';
    import { onMount, onDestroy } from 'svelte';
    import { writable } from "svelte/store"

    let height = writable<number>(window.innerHeight-100);

    function updateHeight() {
        height.set(window.innerHeight-100);
    }

    onMount(() => {
        updateHeight();
        window.addEventListener('resize', updateHeight);
    });

    onDestroy(() => {
        window.removeEventListener('resize', updateHeight);
    });

    export let data: PageData;
</script>

<div class="h-full">
    <Chart title={data.title} height={$height} background="bg-surface-900" pop_up={false} />
</div>
