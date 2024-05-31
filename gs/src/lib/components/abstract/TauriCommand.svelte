<script lang="ts">
    import {invoke} from '@tauri-apps/api/tauri';
    import {util} from "$lib";

    export let className: string = '';
    export let cmd: 'start_server' | 'start_levi' | 'quit_levi' | 'quit_server';
    export let successCallback: () => void = () => {};
    export let errorCallback: (error:string) => void = () => {};

    export let send = async () => {
        console.log(`Sending command: ${cmd}`);
        await invoke(cmd).then(r => {
            console.log(`Command ${cmd} sent with response: ${r}`);
            r ? successCallback() : errorCallback(r as string);
        }).catch((e) => {
            console.error(`Error sending command ${cmd}: ${e}`);
            errorCallback(`Error Sending Command: ${e}`);
        });
    };
</script>

<button class="btn rounded-md font-number font-medium {className ? className : 'py-2 bg-primary-500 text-surface-900'}"
        on:click={send}>
    {util.snakeToCamel(cmd)}
</button>
