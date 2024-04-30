<script lang="ts">
    import { appWindow } from '@tauri-apps/api/window'
    import Icon from '@iconify/svelte'
</script>

<div data-tauri-drag-region class="bg-surface-900 flex justify-between items-center px-1">
    <div class="flex items-center gap-1">
        <enhanced:img src="/static/images/logo-green.png?w=16" alt="Delft logo" />
        <span class="text-primary-500 font-medium text-xs">DELFT HYPERLOOP</span>
    </div>
    <div class="text-white">
        <button on:click={appWindow.minimize} class="text-success-500">
            <Icon icon="mdi:window-minimize" />
        </button>
        <button on:click={appWindow.maximize} class="text-warning-500">
            <Icon icon="mdi:window-maximize" />
        </button>
        <button on:click={appWindow.close} class="text-error-500">
            <Icon icon="mdi:window-close" />
        </button>
    </div>
</div>