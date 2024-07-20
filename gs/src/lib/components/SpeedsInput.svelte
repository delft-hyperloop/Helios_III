<script lang="ts">
    import type { SvelteComponent } from "svelte"
    import DragDropList, { VerticalDropZone, reorder, type DropEvent } from "svelte-dnd-list"

    import { getModalStore } from "@skeletonlabs/skeleton"
    import { invoke } from "@tauri-apps/api/tauri"
    import util from "$lib/util/util"
    import { EventChannel, type RouteStep, TauriCommand } from "$lib"
    import Icon from "@iconify/svelte"
    import type { RouteConfig } from "$lib/types"
    import { routeConfig } from "$lib/stores/data"
    import { get } from "svelte/store"

    const CurrentRouteConfig: RouteConfig = get(routeConfig)

    const RouteStepNames: RouteStep[] = ["ForwardA", "ForwardB", "ForwardC", "BackwardsA", "BackwardsB", "BackwardsC",
        "LaneSwitchStraight", "LaneSwitchCurved", "StopAndWait", "BrakeHere"]

    let isValid: boolean = false
    $: focusedInput = ""
    let invalidInputs: SpeedFormKey[] = []
    export let parent: SvelteComponent
    const modalStore = getModalStore()

    type SpeedFormType = {
        ForwardA: number,
        ForwardB: number,
        ForwardC: number,
        BackwardsA: number,
        BackwardsB: number,
        BackwardsC: number,
        LaneSwitchCurved: number,
        LaneSwitchStraight: number,
    }

    const speedForm: SpeedFormType = CurrentRouteConfig.speeds
    type SpeedFormKey = keyof typeof speedForm;
    const inputs: SpeedFormKey[] = Object.keys(CurrentRouteConfig.speeds) as SpeedFormKey[]

    function onRouteStepClick(step: RouteStep): void {
        if (CurrentRouteConfig.positions.length < 16) {
            CurrentRouteConfig.positions = [...CurrentRouteConfig.positions, step]
        }
    }

    function removeRouteStep(index: number): void {
        CurrentRouteConfig.positions = CurrentRouteConfig.positions.filter((_, i) => i !== index)
    }

    function onDrop({ detail: { from, to } }: CustomEvent<DropEvent>) {
        if (!to || from === to) return
        CurrentRouteConfig.positions = reorder(CurrentRouteConfig.positions, from.index, to.index)
    }

    function speedToU8(speed: number): number {
        return speed === 0 ? 0 : Math.floor(128 + (128 * ((speed + 10) / 20)))
    }

    function u8ToSpeed(u8: number): number {
        return u8 === 0 ? 0 : Math.floor(20 * ((u8 - 128) / 128) - 10)
    }

    function u8toSpeeds(speeds: SpeedFormType): SpeedFormType {
        return {
            ForwardA: u8ToSpeed(speeds.ForwardA),
            ForwardB: u8ToSpeed(speeds.ForwardB),
            ForwardC: u8ToSpeed(speeds.ForwardC),
            BackwardsA: u8ToSpeed(speeds.BackwardsA),
            BackwardsB: u8ToSpeed(speeds.BackwardsB),
            BackwardsC: u8ToSpeed(speeds.BackwardsC),
            LaneSwitchCurved: u8ToSpeed(speeds.LaneSwitchCurved),
            LaneSwitchStraight: u8ToSpeed(speeds.LaneSwitchStraight),
        }
    }

    function speedsToU8(speeds: SpeedFormType): SpeedFormType {
        return {
            ForwardA: speedToU8(speeds.ForwardA),
            ForwardB: speedToU8(speeds.ForwardB),
            ForwardC: speedToU8(speeds.ForwardC),
            BackwardsA: speedToU8(speeds.BackwardsA),
            BackwardsB: speedToU8(speeds.BackwardsB),
            BackwardsC: speedToU8(speeds.BackwardsC),
            LaneSwitchCurved: speedToU8(speeds.LaneSwitchCurved),
            LaneSwitchStraight: speedToU8(speeds.LaneSwitchStraight),
        }
    }

    async function onFormSubmit() {
        let modifiedRouteConfig = { ...CurrentRouteConfig, positions: [...CurrentRouteConfig.positions] }

        modifiedRouteConfig.speeds = speedsToU8(CurrentRouteConfig.speeds)

        if (modifiedRouteConfig.positions.length < 16) {
            for (let i = modifiedRouteConfig.positions.length; i < 16; i++) {
                modifiedRouteConfig.positions.push("BrakeHere")
            }
        }

        await invoke("set_route", { route: modifiedRouteConfig }).then(r => {
            console.log(`Route config SET: ${r}`)
            isValid = r as boolean
            modalStore.close()

        }).catch(e => {
            console.error(`Error setting route config: ${e}`)
        })
    }

    async function importSpeeds() {
        console.log(`Sending command: speeds_from_u64`)
        await invoke("speeds_from_u64", { speeds: speedInputValue }).then(r => {
            console.log(`Command speeds_from_u64 sent with response: `)
            console.log(r)
            util.log(`Command speeds_from_u64 sent`, EventChannel.INFO)
            CurrentRouteConfig.speeds = u8toSpeeds(r as SpeedFormType)
        }).catch((e) => {
            console.error(`Error sending command speeds_from_u64: ${e}`)
            util.log(`Command speeds_from_u64 ERROR sending`, EventChannel.WARNING)
        })
    }

    async function importRoutes() {
        console.log(`Sending command: positions_from_u64`)
        await invoke("positions_from_u64", { positions: routesInputValue }).then(r => {
            console.log(`Command positions_from_u64 sent with response: `)
            console.log(r)
            CurrentRouteConfig.positions = r as RouteStep[]
        }).catch((e) => {
            console.error(`Error sending command positions_from_u64: ${e}`)
            util.log(`Command positions_from_u64 ERROR sending`, EventChannel.WARNING)
        })
    }

    async function processSpeeds() {
        console.log(`Sending command: speeds_to_u64`)
        await invoke("speeds_to_u64", { speeds: speedsToU8(CurrentRouteConfig.speeds) }).then(r => {
            console.log(`Command speeds_to_u64 sent with response: `)
            console.log(r)
            util.log(`Command speeds_to_u64 sent`, EventChannel.INFO)
            exportedSpeeds.value = r as string
        }).catch((e) => {
            console.error(`Error sending command speeds_to_u64: ${e}`)
            util.log(`Command speeds_to_u64 ERROR sending`, EventChannel.WARNING)
        })
    }

    async function processRoutes() {
        console.log(`Sending command: positions_to_u64`)
        let modifiedPos = [...CurrentRouteConfig.positions]

        if (modifiedPos.length < 16) {
            for (let i = modifiedPos.length; i < 16; i++) {
                modifiedPos.push("BrakeHere")
            }
        }

        await invoke("positions_to_u64", { positions: modifiedPos }).then(r => {
            console.log(`Command positions_to_u64 sent with response: `)
            console.log(r)
            util.log(`Command positions_to_u64 sent`, EventChannel.INFO)
            exportedRoutes.value = r as string
        }).catch((e) => {
            console.error(`Error sending command positions_to_u64: ${e}`)
            util.log(`Command positions_to_u64 ERROR sending`, EventChannel.WARNING)
        })
    }

    async function validateCurrentRouteConfig() {
        let modifiedRouteConfig = { ...CurrentRouteConfig, positions: [...CurrentRouteConfig.positions] }

        modifiedRouteConfig.speeds = speedsToU8(CurrentRouteConfig.speeds)

        if (modifiedRouteConfig.positions.length < 16) {
            for (let i = modifiedRouteConfig.positions.length; i < 16; i++) {
                modifiedRouteConfig.positions.push("BrakeHere")
            }
        }

        await invoke("validate_route", { route: modifiedRouteConfig }).then(r => {
            console.log(`Route config validated: ${r}`)
            isValid = r as boolean
        }).catch(e => {
            console.error(`Error validating route config: ${e}`)
        })
    }

    async function resetSpeeds() {
        CurrentRouteConfig.speeds = {
            ForwardA: 0,
            ForwardB: 0,
            ForwardC: 0,
            BackwardsA: 0,
            BackwardsB: 0,
            BackwardsC: 0,
            LaneSwitchCurved: 0,
            LaneSwitchStraight: 0,
        }
    }

    async function resetRouteConfig() {
        CurrentRouteConfig.positions = []
    }

    $: if (CurrentRouteConfig.positions) {
        validateCurrentRouteConfig()
        processRoutes()
    }

    $: if (CurrentRouteConfig.speeds) {
        validateCurrentRouteConfig()
        processSpeeds()
    }

    async function clickToCopy(elem: HTMLInputElement) {
        await navigator.clipboard.writeText(elem.value)
    }

    let speedInputValue = "14104086254467416064"
    let routesInputValue = "1822648539875311616"

    let exportedRoutes: HTMLInputElement
    let exportedSpeeds: HTMLInputElement
</script>

{#if $modalStore[0]}
    <div class="modal-example-form w-modal-wide card p-4 shadow-xl space-y-4">
        <header class="text-2xl font-bold">{$modalStore[0].title}</header>

        <div class="grid modal-grid grid-rows-[1fr 2fr] h-full gap-4 col-span-1">
            <div class="w-full p-4 col-span-3">
                <svg viewBox="0 0 919 148" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <g id="localiser">
                        <g id="track">
                            <path d="M10 26H909" stroke="#525B5B" stroke-width="5" />
                            <path
                                d="M10 26H347.125M344.878 26.0002C459 26.0002 550 53.7775 639.3 77.6926L859.555 138.375"
                                stroke="#525B5B" stroke-width="5" />
                            <g id="point">
                                <circle cx="10" cy="26" r="7" fill="#525B5B" />
                                <circle cx="347" cy="26" r="7" fill="#525B5B" />
                                <circle cx="572" cy="26" r="7" fill="#525B5B" />
                                <circle cx="909" cy="26" r="7" fill="#525B5B" />
                                <circle cx="638" cy="78" r="7" fill="#525B5B" />
                                <circle cx="860" cy="138" r="7" fill="#525B5B" />
                            </g>
                        </g>
                        <g id="labels">
                            <text x="165" y="10" fill={focusedInput === 'ForwardA' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">Forward A
                            </text>
                            <text x="162" y="50" fill={focusedInput === 'BackwardA' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">Backward A
                            </text>
                            <text x="405" y="10" fill={focusedInput === 'LaneSwitchStraight' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">Lane-switch Straight
                            </text>
                            <text x="731" y="10" fill={focusedInput === 'ForwardB' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">Forward B
                            </text>
                            <text x="728" y="50" fill={focusedInput === 'BackwardB' ? '#4D9C89' : '#EFF0F0'}
                                  font-size="12">Backward B
                            </text>
                            <text x="453" y="55" fill={focusedInput === 'LaneSwitchCurved' ? '#4D9C89' : '#EFF0F0'}
                                  transform="rotate(12,450,70)"
                                  font-size="12">Lane-switch curve
                            </text>
                            <text x="705" y="116" fill={focusedInput === 'ForwardC' ? '#4D9C89' : '#EFF0F0'}
                                  transform="rotate(15,680,125)"
                                  font-size="12">Backward C
                            </text>
                            <text x="708" y="75" fill={focusedInput === 'BackwardC' ? '#4D9C89' : '#EFF0F0'}
                                  transform="rotate(15,680,125)"
                                  font-size="12">Forward C
                            </text>
                        </g>
                    </g>
                    <g filter="url(#filter0_d_64_411)">
                        <rect x="189" y="16" width="10" height="1" rx="0.5" fill="#4D9C89" />
                        <path
                            d="M194.902 19.2983C194.735 19.0783 194.778 18.7647 194.998 18.5978L198.185 16.1796C198.405 16.0126 198.718 16.0556 198.885 16.2756C199.052 16.4956 199.009 16.8092 198.789 16.9762L195.603 19.3943C195.383 19.5613 195.069 19.5183 194.902 19.2983Z"
                            fill="#4D9C89" />
                        <rect x="198.4" y="17.0792" width="5" height="1" rx="0.5"
                              transform="rotate(-138.181 198.4 17.0792)" fill="#4D9C89" />
                        <rect x="754" y="18" width="10" height="1" rx="0.5" fill="#4D9C89" />
                        <path
                            d="M759.902 21.2983C759.735 21.0783 759.778 20.7647 759.998 20.5978L763.185 18.1796C763.405 18.0126 763.718 18.0556 763.885 18.2756C764.052 18.4956 764.009 18.8092 763.789 18.9762L760.603 21.3943C760.383 21.5613 760.069 21.5183 759.902 21.2983Z"
                            fill="#4D9C89" />
                        <rect x="763.4" y="19.0792" width="5" height="1" rx="0.5"
                              transform="rotate(-138.181 763.4 19.0792)" fill="#4D9C89" />
                        <rect x="754" y="17.9999" width="10" height="1" rx="0.5" fill="#4D9C89" />
                        <path
                            d="M759.902 21.2982C759.735 21.0783 759.778 20.7646 759.998 20.5977L763.185 18.1795C763.405 18.0126 763.718 18.0556 763.885 18.2755C764.052 18.4955 764.009 18.8092 763.789 18.9761L760.603 21.3943C760.383 21.5612 760.069 21.5182 759.902 21.2982Z"
                            fill="#4D9C89" />
                        <rect x="763.4" y="19.0791" width="5" height="1" rx="0.5"
                              transform="rotate(-138.181 763.4 19.0791)" fill="#4D9C89" />
                        <rect x="764.188" y="36.6966" width="10" height="1" rx="0.5"
                              transform="rotate(179.998 764.188 36.6966)" fill="#4D9C89" />
                        <path
                            d="M758.285 33.3985C758.452 33.6185 758.409 33.9322 758.189 34.0991L755.003 36.5174C754.783 36.6843 754.469 36.6414 754.302 36.4214C754.135 36.2014 754.178 35.8878 754.398 35.7208L757.585 33.3026C757.805 33.1356 758.118 33.1786 758.285 33.3985Z"
                            fill="#4D9C89" />
                        <rect x="754.787" y="35.6178" width="5" height="1" rx="0.5"
                              transform="rotate(41.8165 754.787 35.6178)" fill="#4D9C89" />
                        <rect x="740.787" y="96.8915" width="10" height="1" rx="0.5"
                              transform="rotate(15.4693 740.787 96.8915)" fill="#4D9C89" />
                        <path
                            d="M745.596 101.645C745.494 101.388 745.619 101.097 745.875 100.995L749.591 99.5143C749.848 99.4121 750.138 99.5372 750.241 99.7937C750.343 100.05 750.218 100.341 749.961 100.443L746.245 101.924C745.989 102.026 745.698 101.901 745.596 101.645Z"
                            fill="#4D9C89" />
                        <rect x="749.559" y="100.439" width="5" height="1" rx="0.5"
                              transform="rotate(-122.712 749.559 100.439)" fill="#4D9C89" />
                        <rect x="745.619" y="117.628" width="10" height="1" rx="0.5"
                              transform="rotate(-164.533 745.619 117.628)" fill="#4D9C89" />
                        <path
                            d="M740.81 112.875C740.912 113.132 740.787 113.422 740.531 113.525L736.815 115.006C736.558 115.108 736.267 114.983 736.165 114.726C736.063 114.47 736.188 114.179 736.445 114.077L740.16 112.596C740.417 112.494 740.708 112.619 740.81 112.875Z"
                            fill="#4D9C89" />
                        <rect x="736.847" y="114.081" width="5" height="1" rx="0.5"
                              transform="rotate(57.2857 736.847 114.081)" fill="#4D9C89" />
                        <rect x="198.199" y="36.737" width="10" height="1" rx="0.5"
                              transform="rotate(-179.773 198.199 36.737)" fill="#4D9C89" />
                        <path
                            d="M192.31 33.4153C192.476 33.6359 192.432 33.9494 192.211 34.1154L189.015 36.5209C188.795 36.687 188.481 36.6428 188.315 36.4222C188.149 36.2015 188.193 35.888 188.414 35.722L191.61 33.3165C191.831 33.1504 192.144 33.1946 192.31 33.4153Z"
                            fill="#4D9C89" />
                        <rect x="188.804" y="35.6205" width="5" height="1" rx="0.5"
                              transform="rotate(42.0461 188.804 35.6205)" fill="#4D9C89" />
                    </g>
                    <defs>
                        <filter id="filter0_d_64_411" x="-4" y="0" width="927" height="156" filterUnits="userSpaceOnUse"
                                color-interpolation-filters="sRGB">
                            <feFlood flood-opacity="0" result="BackgroundImageFix" />
                            <feColorMatrix in="SourceAlpha" type="matrix"
                                           values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 127 0" result="hardAlpha" />
                            <feOffset dy="4" />
                            <feGaussianBlur stdDeviation="2" />
                            <feComposite in2="hardAlpha" operator="out" />
                            <feColorMatrix type="matrix" values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.25 0" />
                            <feBlend mode="normal" in2="BackgroundImageFix" result="effect1_dropShadow_64_411" />
                            <feBlend mode="normal" in="SourceGraphic" in2="effect1_dropShadow_64_411" result="shape" />
                        </filter>
                    </defs>
                </svg>
            </div>
            <div class="col-span-1 row-span-2 h-[500px] overflow-auto">
                <DragDropList
                    id="aaa"
                    type={VerticalDropZone}
                    itemSize={55}
                    itemCount={CurrentRouteConfig.positions.length}
                    on:drop={onDrop}
                    let:index
                    zoneClass="bg-surface-900 scrollable"
                >
                    <div class="flex items-center justify-between p-2 bg-surface-800 rounded-lg cursor-move m-2">
                        <div class="flex items-center">
                            <Icon icon="mdi:drag" />
                            <span>{index + 1}. {CurrentRouteConfig.positions[index]}</span>
                        </div>
                        <button type="button"
                                class="btn rounded-lg"
                                on:click={() => removeRouteStep(index)}>
                            <Icon icon="mdi:close" class="text-error-400" />
                        </button>
                    </div>
                </DragDropList>
            </div>
            <div class="col-span-2 w-full">
                {#each inputs as input}
                    <label class="text-lg grid labels-grid gap-2 mb-2">
                        <span class="text-lg">{util.snakeToCamel(input)}</span>
                        <input class={`input rounded-lg px-1 ${invalidInputs.includes(input) ? 'text-error-400' : ''}`}
                               type="number"
                               max="500"
                               min="-500"
                               bind:value={CurrentRouteConfig.speeds[input]}
                               pattern="^-?[0-9]*$"
                               on:focus={() => focusedInput = input} on:blur={() => focusedInput = ''}
                               on:input={() => {
                           if (CurrentRouteConfig.speeds[input] < -9 || CurrentRouteConfig.speeds[input] > 9) {
                               if (!invalidInputs.includes(input)) {
                                   invalidInputs = [...invalidInputs, input];
                               }
                           } else {
                               invalidInputs = invalidInputs.filter(i => i !== input);
                           }
                        }} />
                        <span class="text-lg">m/s</span>
                    </label>
                {/each}
            </div>
            <div
                class="col-span-1 flex flex-col items-center gap-2 rounded-lg p-2 bg-surface-900 max-h-80 overflow-auto">
                {#each RouteStepNames as step}
                    <div class="flex items-center justify-between w-full p-2 bg-surface-800 rounded-lg">
                        <span>{step}</span>
                        <button type="button"
                                class="btn rounded-none"
                                on:click={() => onRouteStepClick(step)}>
                            <Icon icon="mdi:plus"
                                  class={CurrentRouteConfig.positions.length < 16 ? "text-surface-400" : "text-error-400"} />
                        </button>
                    </div>
                {/each}
            </div>
            <div class="col-span-4 flex gap-4">
                <div class="grid grid-cols-4 grid-rows-2 gap-4">
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={importSpeeds}>
                        Import Speeds
                    </button>
                    <input bind:value={speedInputValue} type="text" class="input rounded-lg">
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={importRoutes}>
                        Import Route Setup
                    </button>
                    <input bind:value={routesInputValue} type="text" class="input rounded-lg">
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={() => clickToCopy(exportedSpeeds)}>
                        Copy Speeds Setup
                    </button>
                    <input contenteditable="false" bind:this={exportedSpeeds} readonly type="text"
                           class="input rounded-lg">
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={() => clickToCopy(exportedRoutes)}>
                        Copy Route Setup
                    </button>
                    <input contenteditable="false" bind:this={exportedRoutes} readonly type="text"
                           class="input rounded-lg">
                </div>
                <div class="">
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={resetSpeeds}>
                        Reset Speeds
                    </button>
                    <button class="btn border-2 border-primary-500 text-primary-500 font-medium rounded-lg"
                            on:click={resetRouteConfig}>
                        Reset Route
                    </button>

                    <TauriCommand cmd="demonstration_a" />
                    <TauriCommand cmd="demonstration_b" />

                    <span>Valid: {isValid}</span>
                </div>
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

<style lang="scss">
  .modal-grid {
    grid-template-columns: 1fr 1fr 1fr 1.3fr;
  }

  .labels-grid {
    grid-template-columns: 2fr 3fr 1fr;
  }
</style>
