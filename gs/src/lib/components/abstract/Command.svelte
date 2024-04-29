<script lang="ts">
    import { invoke } from '@tauri-apps/api/tauri';
    import util from "$lib/util/util";
    import type {NamedCommand} from "$lib/types";

    export let command: NamedCommand;
    export const send = async () => {
        await invoke(command);
    };
</script>

<button class="btn rounded-md py-2 {command === 'abort' ? 'bg-error-500' : `bg-primary-500`}" on:click={send}>
    {util.snakeToCamel(command)}
</button>