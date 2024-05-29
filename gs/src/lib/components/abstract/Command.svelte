<script lang="ts">
    import {invoke} from '@tauri-apps/api/tauri';
    import {type NamedCommand, util} from "$lib";

    export let className: string = '';
    export let cmd: NamedCommand;
    export let val: number = 0;
    export let callback: (val:number) => void = () => {};

    const send = async () => {
        await invoke('send_command', {cmd, val});
        callback(val);
    };
</script>

<button class="btn rounded-md font-number font-medium {className ? className : 'py-2 bg-primary-500 text-surface-900'}"
        on:click={send}>
    {util.snakeToCamel(cmd)}
</button>