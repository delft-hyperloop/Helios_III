<script lang="ts">
    import {onMount} from "svelte";
    import util from "$lib/util/util";
    import {inputEmerg} from "$lib/stores/state";
    import {GrandDataDistributor} from "$lib";

    export let max:number = 60000;
    export let loc:number = 1000; /* should be < 16000 */
    export let turning:boolean;

    // todo let current_segment:Segment = 'L1';

    // SVG elements
    let progress_container:SVGGElement;
    let path_straight:SVGGElement;
    let path_turn:SVGGElement;
    let progress_straight:SVGPathElement;
    let progress_turn:SVGPathElement;

    // points
    let point_start:SVGCircleElement;
    let point_divergence:SVGCircleElement;
    let point_choice_straight:SVGCircleElement;
    let point_final:SVGCircleElement;
    let point_end_straight:SVGCircleElement;
    let point_choice_turn:SVGCircleElement;
    let point_end_turn:SVGCircleElement;

    let pathLength: number;

    const color_disabled = "#2C3030";
    const color_active = "#4D9C89";
    const color_off = "#525B5B"

    /**
     * Set the fill and stroke colour of the svg elements to a disabled color
     * @param elems the elements which to update
     */
    function disable(...elems:SVGElement[]) {
        elems.forEach(e => {
            e.style.stroke = color_disabled;
            if (e instanceof SVGCircleElement) {
                e.style.fill = color_disabled;
            }
        })
    }

    /**
     * Setup progress svg pathing for the given path.
     * This function will set the stroke offset and dash array to whatever the length
     * of the path is and it.
     * @param path the path for which to set up progressing pathing
     */
    function setupProgressPathing(path:SVGPathElement) {
        let totalLength = path.getTotalLength();
        path.style.strokeDasharray = totalLength.toString();
        path.style.strokeDashoffset = totalLength.toString();
        return totalLength;
    }

    onMount(() => {
        if (turning) {
            disable(progress_straight, point_choice_straight, point_final, point_end_straight)
            progress_container.insertBefore(path_straight, path_turn);
            pathLength = setupProgressPathing(progress_turn);
        } else {
            disable(point_choice_turn, point_end_turn, progress_turn);
            progress_container.insertBefore(path_turn, path_straight);
            pathLength = setupProgressPathing(progress_straight);
        }
    });

    $: emergPosition = (pathLength * (util.normalize($inputEmerg, max) / 100))
    $: emergYPosition = 26;

    $: if(progress_straight || progress_turn) {
        let normalized_loc = util.normalize(loc, max)
        let offset = pathLength - (pathLength * (normalized_loc / 100));

        point_start.style.fill = normalized_loc > 0 ? color_active : color_off;

        if (turning) {
            progress_turn.style.strokeDashoffset = offset.toString();
            point_divergence.style.fill = normalized_loc > 40 ? color_active : color_off;
            point_choice_turn.style.fill = normalized_loc > 73 ? color_active : color_off;
            point_end_turn.style.fill = normalized_loc >= 100 ? color_active : color_off;
            emergYPosition = progress_turn.getPointAtLength(emergPosition).y;
        } else {
            progress_straight.style.strokeDashoffset = offset.toString();
            point_divergence.style.fill = normalized_loc > 38 ? color_active : color_off;
            point_choice_straight.style.fill = normalized_loc > 62 ? color_active : color_off;
            point_final.style.fill = normalized_loc > 74 ? color_active : color_off;
            point_end_straight.style.fill = normalized_loc >= 100 ? color_active : color_off;
            emergYPosition = progress_straight.getPointAtLength(emergPosition).y;
        }
    }

    const storeManager = GrandDataDistributor.getInstance().stores;
    const velocity = storeManager.getStore("Velocity");
</script>

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



