<script lang="ts">
    import {onMount} from "svelte";
    import util from "$lib/util/util";
    import {south_bridge_payload} from "$lib";
    import {inputEmerg} from "$lib/stores/state";

    export let max:number = 16000;
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

    $: if(progress_straight || progress_turn) {
        let normalized_loc = util.normalize(loc, max)
        let offset = pathLength - (pathLength * (normalized_loc / 100));

        point_start.style.fill = normalized_loc > 0 ? color_active : color_off;

        if (turning) {
            progress_turn.style.strokeDashoffset = offset.toString();
            point_divergence.style.fill = normalized_loc > 40 ? color_active : color_off;
            point_choice_turn.style.fill = normalized_loc > 73 ? color_active : color_off;
            point_end_turn.style.fill = normalized_loc >= 100 ? color_active : color_off;
        } else {
            progress_straight.style.strokeDashoffset = offset.toString();
            point_divergence.style.fill = normalized_loc > 38 ? color_active : color_off;
            point_choice_straight.style.fill = normalized_loc > 62 ? color_active : color_off;
            point_final.style.fill = normalized_loc > 74 ? color_active : color_off;
            point_end_straight.style.fill = normalized_loc >= 100 ? color_active : color_off;
        }
    }
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
                    <circle cx={emergPosition} cy="26" r="5" fill="red"/>
                </g>
            </g>
            <g id="labels">
                <path id="L1" d="M173.044 12V3.54H174.028V11.136H178.336V12H173.044ZM180.004 12V11.16H181.936V4.728L180.412 5.688L179.992 4.956L182.212 3.54H182.92V11.16H184.732V12H180.004Z" fill="#EFF0F0"/>
                <path id="L2" d="M453.044 12V3.54H454.028V11.136H458.336V12H453.044ZM459.596 12V11.256L462.488 8.136C462.896 7.688 463.188 7.28 463.364 6.912C463.548 6.544 463.64 6.168 463.64 5.784C463.64 4.8 463.068 4.308 461.924 4.308C461.068 4.308 460.312 4.628 459.656 5.268L459.284 4.5C459.596 4.18 459.992 3.924 460.472 3.732C460.96 3.532 461.472 3.432 462.008 3.432C462.856 3.432 463.504 3.632 463.952 4.032C464.408 4.424 464.636 4.984 464.636 5.712C464.636 6.216 464.512 6.712 464.264 7.2C464.016 7.68 463.636 8.192 463.124 8.736L460.856 11.16H464.984V12H459.596Z" fill="#EFF0F0"/>
                <path id="L3" d="M622.044 12V3.54H623.028V11.136H627.336V12H622.044ZM631.02 12.108C630.46 12.108 629.928 12.024 629.424 11.856C628.92 11.68 628.496 11.428 628.152 11.1L628.512 10.32C628.904 10.64 629.3 10.872 629.7 11.016C630.1 11.16 630.532 11.232 630.996 11.232C631.604 11.232 632.068 11.1 632.388 10.836C632.716 10.564 632.88 10.168 632.88 9.648C632.88 9.152 632.716 8.776 632.388 8.52C632.06 8.264 631.584 8.136 630.96 8.136H629.712V7.284H630.876C631.42 7.284 631.848 7.144 632.16 6.864C632.48 6.576 632.64 6.184 632.64 5.688C632.64 5.248 632.492 4.908 632.196 4.668C631.908 4.428 631.496 4.308 630.96 4.308C630.08 4.308 629.312 4.628 628.656 5.268L628.296 4.5C628.608 4.164 629.004 3.904 629.484 3.72C629.972 3.528 630.484 3.432 631.02 3.432C631.836 3.432 632.472 3.624 632.928 4.008C633.392 4.392 633.624 4.924 633.624 5.604C633.624 6.076 633.504 6.492 633.264 6.852C633.024 7.204 632.692 7.46 632.268 7.62C632.772 7.756 633.164 8.008 633.444 8.376C633.724 8.736 633.864 9.184 633.864 9.72C633.864 10.448 633.608 11.028 633.096 11.46C632.592 11.892 631.9 12.108 631.02 12.108Z" fill="#EFF0F0"/>
                <path id="L4" d="M791.044 12V3.54H792.028V11.136H796.336V12H791.044ZM801.04 12V10.188H797.14V9.444L801.208 3.54H802.036V9.348H803.296V10.188H802.036V12H801.04ZM801.04 9.348V5.16L798.16 9.348H801.04Z" fill="#EFF0F0"/>
                <path id="L6" d="M740.044 124V115.54H741.028V123.136H745.336V124H740.044ZM749.404 124.108C748.404 124.108 747.632 123.748 747.088 123.028C746.552 122.3 746.284 121.284 746.284 119.98C746.284 118.516 746.584 117.392 747.184 116.608C747.784 115.824 748.624 115.432 749.704 115.432C750.136 115.432 750.568 115.524 751 115.708C751.44 115.892 751.8 116.14 752.08 116.452L751.72 117.22C751.424 116.916 751.1 116.688 750.748 116.536C750.404 116.384 750.048 116.308 749.68 116.308C748.896 116.308 748.292 116.6 747.868 117.184C747.452 117.768 747.244 118.636 747.244 119.788V120.376C747.396 119.848 747.676 119.436 748.084 119.14C748.5 118.844 748.988 118.696 749.548 118.696C750.044 118.696 750.484 118.812 750.868 119.044C751.252 119.268 751.552 119.58 751.768 119.98C751.984 120.38 752.092 120.84 752.092 121.36C752.092 121.896 751.976 122.372 751.744 122.788C751.52 123.196 751.204 123.52 750.796 123.76C750.396 123.992 749.932 124.108 749.404 124.108ZM749.344 123.268C749.88 123.268 750.312 123.096 750.64 122.752C750.976 122.408 751.144 121.956 751.144 121.396C751.144 120.844 750.976 120.396 750.64 120.052C750.312 119.7 749.88 119.524 749.344 119.524C748.808 119.524 748.372 119.7 748.036 120.052C747.708 120.396 747.544 120.844 747.544 121.396C747.544 121.956 747.708 122.408 748.036 122.752C748.372 123.096 748.808 123.268 749.344 123.268Z" fill="#EFF0F0"/>
                <path id="L5" d="M487.044 58V49.54H488.028V57.136H492.336V58H487.044ZM496.296 58.108C495.752 58.108 495.232 58.02 494.736 57.844C494.24 57.668 493.82 57.42 493.476 57.1L493.848 56.32C494.592 56.928 495.404 57.232 496.284 57.232C496.868 57.232 497.328 57.068 497.664 56.74C498 56.412 498.168 55.98 498.168 55.444C498.168 54.892 498.008 54.44 497.688 54.088C497.368 53.736 496.928 53.56 496.368 53.56C495.56 53.56 494.924 53.896 494.46 54.568H493.74V49.54H498.648V50.38H494.712V53.404C495.176 52.94 495.788 52.708 496.548 52.708C497.076 52.708 497.536 52.82 497.928 53.044C498.32 53.268 498.62 53.584 498.828 53.992C499.044 54.392 499.152 54.86 499.152 55.396C499.152 55.924 499.036 56.392 498.804 56.8C498.572 57.208 498.24 57.528 497.808 57.76C497.384 57.992 496.88 58.108 496.296 58.108Z" fill="#EFF0F0"/>
            </g>
            <text x="10" y="140" fill="#EFF0F0" font-size="12">Location: {$south_bridge_payload.value}</text>
            <text x="100" y="140" fill="#EFF0F0" font-size="12">Speed: {$south_bridge_payload.value}</text>
        </g>
    </svg>
</div>



