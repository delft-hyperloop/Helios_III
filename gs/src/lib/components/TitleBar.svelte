<script lang="ts">
    import { appWindow } from '@tauri-apps/api/window'
    import Icon from '@iconify/svelte'
</script>

<div data-tauri-drag-region class="bg-surface-900 flex justify-between items-center p-1 px-2">
    <div class="flex items-center gap-1">
        <enhanced:img src="/static/images/logo-green.png?w=16" alt="Delft logo" />
        <span class="text-primary-500 font-medium text-xs">DELFT HYPERLOOP</span>
    </div>
    <div class="text-surface-300">
        <button on:click={appWindow.minimize} class="rounded-full bg-surface-800 hover:bg-surface-700 p-1">
            <Icon icon="mdi:window-minimize" />
        </button>
        <button on:click={appWindow.maximize} class="rounded-full bg-surface-800 hover:bg-surface-700 p-1" >
            <Icon icon="mdi:window-maximize" />
        </button>
        <button on:click={appWindow.close} class="rounded-full bg-surface-800 hover:bg-surface-700 p-1">
            <Icon icon="mdi:window-close" />
        </button>
    </div>
</div>