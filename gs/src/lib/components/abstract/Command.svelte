<script lang="ts">
    import { invoke } from '@tauri-apps/api/tauri';
    import util from "$lib/util/util";
    import type {NamedCommand} from "$lib/types";

    export let command: NamedCommand;
    export const send = async () => {
        await invoke(command);
    };
</script>

<button class="btn" on:click={send}>{util.snakeToCamel(command)}</button>