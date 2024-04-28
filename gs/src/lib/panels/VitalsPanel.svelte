<script>
import Chart from "$lib/components/generic/Chart.svelte";
</script>

<div class="flex flex-col w-full p-4 gap-4">
    <p>vitals</p>

    <Chart refreshRate={5} />
    <Chart refreshRate={100} />
</div>