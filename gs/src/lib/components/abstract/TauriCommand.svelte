<script lang="ts">
    import {invoke} from '@tauri-apps/api/tauri';
    import {type NamedCommand, util} from "$lib";

    export let className: string = '';
    export let cmd: 'start_server' | 'start_levi' | 'quit_levi' | 'quit_server';
    export let send = async () => {
        console.log(`Sending command: ${cmd}`);
        await invoke(cmd).then(() => {
            console.log(`Command ${cmd} sent`);
        }).catch((e) => {
            console.error(`Error sending command ${cmd}: ${e}`);
        });
    };
</script>

<button class="btn rounded-md font-number font-medium {className ? className : 'py-2 bg-primary-500 text-surface-900'}"
        on:click={send}>
    {util.snakeToCamel(cmd)}
</button>
