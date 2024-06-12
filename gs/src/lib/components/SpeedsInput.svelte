<script lang="ts">
    import type { SvelteComponent } from 'svelte';

    import { getModalStore } from '@skeletonlabs/skeleton';
    import {invoke} from "@tauri-apps/api/tauri";

    import util from '$lib/util/util';
    import {inputTurn, Localiser, RunMode} from "$lib";

    export let parent: SvelteComponent;

    const modalStore = getModalStore();

    const speedForm = {
        straightStart: 0,
        straightBackwards: 0,
        laneSwitchStraight: 0,
        laneSwitchCurved: 0,
        straightEndTrack: 0,
        laneSwitchEndTrack: 0,
    };

    type SpeedFormKey = keyof typeof speedForm;
    const inputs: SpeedFormKey[] = Object.keys(speedForm) as SpeedFormKey[];


    function onFormSubmit(): void {
        if (Object.values(speedForm).some(v => v < 0 || v > 255)) {
            console.log(`Invalid values in form`);
            return;
        } else {
            let val = 0;
            for (let i = 0; i < inputs.length; i++) {
                val |= speedForm[inputs[i]] << ((5 - i) * 8);
            }

            invoke('send_command', {cmdName: "RunConfiddg", val}).then(() => {
                console.log(`Command RunConfig sent`);
                modalStore.close();
            })
        }
    }

    const cBase = 'card p-4 w-modal shadow-xl space-y-4';
    const cHeader = 'text-2xl font-bold';
</script>

{#if $modalStore[0]}
    <div class="modal-example-form w-modal-wide {cBase}">
        <header class={cHeader}>{$modalStore[0].title}</header>

        <div class="flex flex-col gap-4">
            <div class="p-4">

                <div class="w-full">
                    <svg viewBox="0 0 919 148" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <g id="localiser">
                            <g id="track">
                                <g id="progress_container" bind:this={progress_container}>
                                    <g id="path-turning" bind:this={path_straight}>
                                        <path d="M10 26H909" stroke="#525B5B" stroke-width="6"/>
                                        <path bind:this={progress_straight} d="M10 25.7224H909" stroke="#4D9C89" stroke-width="6"/>
                                    </g>
                                    <g id="path-turning" bind:this={path_turn}>
                                        <path d="M10 26H347.125M344.878 26.0002C459 26.0002 550 53.7775 639.3 77.6926L859.555 138.375" stroke="#525B5B" stroke-width="6"/>
                                        <path bind:this={progress_turn} d="M10 25.7224H347.125L344.878 25.7226C459 25.7226 550 53.4999 639.3 77.4151L859.555 138.097" stroke="#4D9C89" stroke-width="6"/>
                                    </g>
                                </g>
                                <g id="point">
                                    <circle bind:this={point_start} cx="10" cy="26" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_divergence} cx="347" cy="26" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_choice_straight} cx="572" cy="26" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_final} cx="684" cy="26" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_end_straight} cx="909" cy="26" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_choice_turn} cx="638" cy="78" r="10" fill="#525B5B"/>
                                    <circle bind:this={point_end_turn} cx="860" cy="138" r="10" fill="#525B5B"/>
                                    <circle cx={emergPosition} cy={emergYPosition} r="5" fill="red"/>
                                </g>
                            </g>
                            <g id="labels">
                                <text x="140" y="10" fill="#EFF0F0" font-size="12">Straight Start</text>
                                <text x="405" y="10" fill="#EFF0F0" font-size="12">Lane-switch Straight</text>
                                <text x="575" y="10" fill="#EFF0F0" font-size="12">Straight Backwards</text>
                                <text x="750" y="10" fill="#EFF0F0" font-size="12">Straight End Track</text>
                                <text x="453" y="55" fill="#EFF0F0" transform="rotate(12,450,70)"
                                      font-size="12">Lane-switch curve
                                </text>
                                <text x="678" y="111" fill="#EFF0F0" transform="rotate(15,680,125)"
                                      font-size="12">Lane-switch End Track
                                </text>
                            </g>
                            <text x="10" y="140" fill="#EFF0F0" font-size="12">Location: {loc}</text>
                            <text x="100" y="140" fill="#EFF0F0" font-size="12">Speed: {$velocity}</text>
                        </g>
                    </svg>
                </div>
            </div>
            <div class="grid grid-cols-6 gap-2">
                {#each inputs as input}
                    <label>
                        <span>{util.snakeToCamel(input)}</span>
                        <input class="input rounded-lg px-1" type="number" max="255" min="0" bind:value={speedForm[input]}/>
                    </label>
                {/each}
            </div>
        </div>

        <footer class="modal-footer {parent.regionFooter}">
            <button class="btn {parent.buttonNeutral} rounded-lg" on:click={parent.onClose}>
                Cancel
            </button>
            <button class="btn bg-primary-500 rounded-lg" on:click={onFormSubmit}>
                Run Configuration
            </button>
        </footer>
    </div>
{/if}