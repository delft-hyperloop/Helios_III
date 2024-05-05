<script lang="ts">
    import {inputSpeed, Command} from "$lib";

    let selectedButton = 1;

    function selectButton(value:number) {
        selectedButton = value;
    }
</script>

<div class="grid grid-cols-2 gap-2">
    <p>Mode: </p>
    <div class="flex col-span-2">
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 1} on:click={() => selectButton(1)}>
            short run
        </button>
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 2} on:click={() => selectButton(2)}>
            lane-switch left
        </button>
        <button class="btn bg-surface-700 rounded-none p-2" type="button" class:active={selectedButton === 3} on:click={() => selectButton(3)}>
            lane-switch right
        </button>
    </div>
    <p>Speed: </p>
    <input bind:value={$inputSpeed} class="input rounded-md px-2 col-span-2" type="number" min="0" max="100" step="1">
    <Command command="establish_connection" classes="btn rounded-md bg-surface-700 hover:bg-primary-500 col-span-2" />
    <Command command="start_hv" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    <Command command="stop_hv" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    <Command command="levitate" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    <Command command="stop_levitating" classes="btn flex-grow rounded-md bg-surface-700 hover:bg-primary-500" />
    <Command command="start_run" classes="btn w-full rounded-md bg-primary-500 col-span-2" />
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>