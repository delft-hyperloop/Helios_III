<script lang="ts">
    import {invoke} from '@tauri-apps/api/tauri';
    import {EventChannel, util} from "$lib";
    import { popup } from '@skeletonlabs/skeleton';
    import type {PopupSettings} from "@skeletonlabs/skeleton";

    export let className: string = '';
    export let cmd: 'connect_to_pod' | 'start_levi' | 'quit_levi' | 'disconnect' | 'procedures' | 'save_logs' |
                    'test_route' | 'speeds_to_u64' | 'speeds_from_u64' | 'positions_to_u64' | 'positions_from_u64' |
                    'demonstration_a' | 'demonstration_b';
    export let successCallback: (r:any) => void = () => {};
    export let errorCallback: (error:string) => void = () => {};
    export let textOverride: string = '';
    export let hoverContent: string = '';


    export let send = async () => {
        console.log(`Sending command: ${cmd}`);
        await invoke(cmd).then(r => {
            console.log(`Command ${cmd} sent with response: ` + r);
            util.log(`Command ${cmd} sent`, EventChannel.INFO);
            r ? successCallback(r) : errorCallback(r as string);
        }).catch((e) => {
            console.error(`Error sending command ${cmd}: ${e}`);
            util.log(`Command ${cmd} ERROR sending`, EventChannel.WARNING);
            errorCallback(`Error Sending Command: ${e}`);
        });
    };

    const popupHover: PopupSettings = {
      event: 'hover',
      target: 'popupHover',
      placement: 'top'
    };
</script>

{#if hoverContent !== ''}
    <div class="card p-4 variant-filled-secondary" data-popup="popupHover">
        <p>{hoverContent}</p>
        <div class="arrow variant-filled-secondary" />
    </div>
{/if}

<button class="btn [&>*]:pointer-events-none rounded-md font-number font-medium
               {className ? className : 'py-2 bg-primary-500 text-surface-900'}"
        on:click={send}
        use:popup={popupHover}>
    {textOverride === '' ? util.snakeToCamel(cmd) : textOverride}
</button>
