<script lang="ts">
    import {invoke} from '@tauri-apps/api/tauri';
    import {type NamedCommand} from "$lib";

    export let offCmd: NamedCommand;
    export let onCmd: NamedCommand;
    export let val: number = 0;
    export let callback: (val:number) => void = () => {};

    // for binding
    export let status: boolean = false;

    const toggleOff = () => {
        status = false;  // todo: remove and uncomment below
        invoke('send_command', {offCmd, val}).then(() => {
            // status = false;
            callback(val);
        });
    };

    const toggleOn = () => {
        status = true;  // todo: remove and uncomment below
        invoke('send_command', {onCmd, val}).then(() => {
            // status = true;
            callback(val);
        });
    };
</script>

<div class="flex">
    <button class="btn rounded-none rounded-l-lg font-number py-2 text-surface-50 bg-surface-700"
            class:active={!status}
            on:click={toggleOff}>
        Off
    </button>
    <button class="btn rounded-none rounded-r-lg font-number py-2 text-surface-50 bg-surface-700"
            class:active={status}
            on:click={toggleOn}>
        On
    </button>
</div>

<style lang="scss">
  .active {
    background-color: rgb(77, 156, 137);
  }
</style>