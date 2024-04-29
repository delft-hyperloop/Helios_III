<script lang="ts">
    import { invoke } from '@tauri-apps/api/tauri';
    import util from "$lib/util/util";
    import type {NamedCommand} from "$lib/types";

    export let background: string = `bg-primary-500`;
    export let classes: string = '';
    export let command: NamedCommand;
    export const send = async () => {
        await invoke(command);
    };
</script>
<button class="{classes === '' ? 'btn rounded-md py-2' : classes } {command === 'abort' ? 'bg-error-500' : background}" on:click={send}>
    {util.snakeToCamel(command)}
</button>