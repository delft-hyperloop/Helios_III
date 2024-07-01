<script lang="ts">
    import type { SvelteComponent } from 'svelte';

    import { getModalStore } from '@skeletonlabs/skeleton';
    import {invoke} from "@tauri-apps/api/tauri";
    import util from '$lib/util/util';
    import {metersPerMinuteToByte} from "$lib/util/parsers";

    $: focusedInput = '';
    let invalidInputs: SpeedFormKey[] = [];

    export let parent: SvelteComponent;

    const modalStore = getModalStore();

    const speedForm = {
        straightStart: 0,
        laneSwitchStraight: 0,
        straightBackwards: 0,
        straightEndTrack: 0,
        laneSwitchCurved: 0,
        laneSwitchEndTrack: 0,
    };

    type SpeedFormKey = keyof typeof speedForm;
    const inputs: SpeedFormKey[] = Object.keys(speedForm) as SpeedFormKey[];

    function onFormSubmit(): void {
        if (Object.values(speedForm).some(v => v < -500 || v > 500)) {
            console.log(`Invalid values in form`);
            return;
        } else {
            let speeds_u64 = BigInt(0);



            for (let i = 0; i < inputs.length; i++) {
                const input = metersPerMinuteToByte(speedForm[inputs[i]]);
                speeds_u64 |= BigInt(input) << BigInt((5 - i) * 8);
            }

            invoke('send_command', {cmdName: "SetSpeeds", val: Number(speeds_u64)}).then(() => {
                console.log(`Command SetSpeeds sent`);
                modalStore.close();
            })

            let route_u64 = BigInt(0);

            invoke('send_command', {cmdName: "SetRoute", val: Number(route_u64)}).then(() => {
                console.log(`Command SetRoute sent`);
                modalStore.close();
            })

            invoke('send_command', {cmdName: "FinishRunConfig", val: 0}).then(() => {
                console.log(`Command FinishRunConfig sent`);
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
            <div class="w-full p-4">
                <svg viewBox="0 0 919 148" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <g id="localiser">
                        <g id="track">
                            <path d="M10 26H909" stroke="#525B5B" stroke-width="5"/>
                            <path d="M10 26H347.125M344.878 26.0002C459 26.0002 550 53.7775 639.3 77.6926L859.555 138.375" stroke="#525B5B" stroke-width="5"/>
                            <g id="point">
                                <circle cx="10" cy="26" r="7" fill="#525B5B"/>
                                <circle cx="347" cy="26" r="7" fill="#525B5B"/>
                                <circle cx="572" cy="26" r="7" fill="#525B5B"/>
                                <circle cx="684" cy="26" r="7" fill="#525B5B"/>
                                <circle cx="909" cy="26" r="7" fill="#525B5B"/>
                                <circle cx="638" cy="78" r="7" fill="#525B5B"/>
                                <circle cx="860" cy="138" r="7" fill="#525B5B"/>
                            </g>
                        </g>
                        <g id="labels">
                            <text x="140" y="10" fill={focusedInput === 'straightStart' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">
                                Straight Start
                            </text>

                            <text x="405" y="10" fill={focusedInput === 'laneSwitchStraight' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">
                                Lane-switch Straight
                            </text>

                            <text x="575" y="10" fill={focusedInput === 'straightBackwards' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">
                                Straight Backwards
                            </text>

                            <text x="750" y="10" fill={focusedInput === 'straightEndTrack' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">
                                Straight End Track
                            </text>

                            <text x="453" y="55" fill={focusedInput === 'laneSwitchCurved' ? '#4D9C89' : '#EFF0F0'}
                                  transform="rotate(12,450,70)" font-size="12">
                                Lane-switch curve
                            </text>

                            <text x="678" y="111" fill={focusedInput === 'laneSwitchEndTrack' ? '#4D9C89' : '#EFF0F0'}
                                  transform="rotate(15,680,125)" font-size="12">
                                Lane-switch End Track
                            </text>
                        </g>
                    </g>
                </svg>
            </div>
            <div class="grid grid-cols-6 gap-2">
                {#each inputs as input}
                    <label>
                        <span>{util.snakeToCamel(input)}</span>
                        <input class={`input rounded-lg px-1 ${invalidInputs.includes(input) ? 'text-error-400' : ''}`}
                               type="number" max="500" min="-500" bind:value={speedForm[input]}
                               on:focus={() => focusedInput = input} on:blur={() => focusedInput = ''}
                               on:input={() => {
                               if (speedForm[input] < -500 || speedForm[input] > 500) {
                                   if (!invalidInputs.includes(input)) {
                                       invalidInputs = [...invalidInputs, input];
                                   }
                               } else {
                                   invalidInputs = invalidInputs.filter(i => i !== input);
                               }
                        }}/>
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