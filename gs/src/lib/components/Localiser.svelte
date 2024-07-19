<script lang="ts">
    import {onMount} from "svelte";
    import util from "$lib/util/util";
    import {inputEmerg} from "$lib/stores/state";

    export let max:number = 13000;
    export let loc:number = 1000; /* should be < 16000 */
    export let turning:boolean;
    export let showLabels:boolean = true;

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
            disable(progress_straight, point_choice_straight, point_end_straight)
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
            point_end_straight.style.fill = normalized_loc >= 100 ? color_active : color_off;
            emergYPosition = progress_straight.getPointAtLength(emergPosition).y;
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
                    <circle bind:this={point_divergence} cx="347" cy="26" r="5" fill="#525B5B"/>
                    <circle bind:this={point_choice_straight} cx="572" cy="26" r="5" fill="#525B5B"/>
                    <circle bind:this={point_end_straight} cx="909" cy="26" r="10" fill="#525B5B"/>
                    <circle bind:this={point_choice_turn} cx="638" cy="78" r="5" fill="#525B5B"/>
                    <circle bind:this={point_end_turn} cx="860" cy="138" r="10" fill="#525B5B"/>
                    <circle cx={emergPosition} cy={emergYPosition} r="5" fill="red"/>
                </g>
            </g>
            <g id="labels">
                {#if showLabels}
                    <text x="165" y="10" fill="#EFF0F0" font-size="12">Forward A</text>
                    <text x="162" y="50" fill="#EFF0F0" font-size="12">Backward A</text>
                    <text x="405" y="10" fill="#EFF0F0" font-size="12">Lane-switch Straight</text>
                    <text x="731" y="10" fill="#EFF0F0" font-size="12">Forward B</text>
                    <text x="728" y="50" fill="#EFF0F0" font-size="12">Backward B</text>
                    <text x="453" y="55" fill="#EFF0F0" transform="rotate(12,450,70)"
                          font-size="12">Lane-switch curve
                    </text>
                    <text x="705" y="116" fill="#EFF0F0" transform="rotate(15,680,125)"
                          font-size="12">Backward C
                    </text>
                    <text x="708" y="75" fill="#EFF0F0" transform="rotate(15,680,125)"
                          font-size="12">Forward C
                    </text>
                {/if}
            </g>
        </g>
        <g filter="url(#filter0_d_64_411)">
            <rect x="189" y="16" width="10" height="1" rx="0.5" fill="#4D9C89"/>
            <path d="M194.902 19.2983C194.735 19.0783 194.778 18.7647 194.998 18.5978L198.185 16.1796C198.405 16.0126 198.718 16.0556 198.885 16.2756C199.052 16.4956 199.009 16.8092 198.789 16.9762L195.603 19.3943C195.383 19.5613 195.069 19.5183 194.902 19.2983Z" fill="#4D9C89"/>
            <rect x="198.4" y="17.0792" width="5" height="1" rx="0.5" transform="rotate(-138.181 198.4 17.0792)" fill="#4D9C89"/>
            <rect x="754" y="18" width="10" height="1" rx="0.5" fill="#4D9C89"/>
            <path d="M759.902 21.2983C759.735 21.0783 759.778 20.7647 759.998 20.5978L763.185 18.1796C763.405 18.0126 763.718 18.0556 763.885 18.2756C764.052 18.4956 764.009 18.8092 763.789 18.9762L760.603 21.3943C760.383 21.5613 760.069 21.5183 759.902 21.2983Z" fill="#4D9C89"/>
            <rect x="763.4" y="19.0792" width="5" height="1" rx="0.5" transform="rotate(-138.181 763.4 19.0792)" fill="#4D9C89"/>
            <rect x="754" y="17.9999" width="10" height="1" rx="0.5" fill="#4D9C89"/>
            <path d="M759.902 21.2982C759.735 21.0783 759.778 20.7646 759.998 20.5977L763.185 18.1795C763.405 18.0126 763.718 18.0556 763.885 18.2755C764.052 18.4955 764.009 18.8092 763.789 18.9761L760.603 21.3943C760.383 21.5612 760.069 21.5182 759.902 21.2982Z" fill="#4D9C89"/>
            <rect x="763.4" y="19.0791" width="5" height="1" rx="0.5" transform="rotate(-138.181 763.4 19.0791)" fill="#4D9C89"/>
            <rect x="764.188" y="36.6966" width="10" height="1" rx="0.5" transform="rotate(179.998 764.188 36.6966)" fill="#4D9C89"/>
            <path d="M758.285 33.3985C758.452 33.6185 758.409 33.9322 758.189 34.0991L755.003 36.5174C754.783 36.6843 754.469 36.6414 754.302 36.4214C754.135 36.2014 754.178 35.8878 754.398 35.7208L757.585 33.3026C757.805 33.1356 758.118 33.1786 758.285 33.3985Z" fill="#4D9C89"/>
            <rect x="754.787" y="35.6178" width="5" height="1" rx="0.5" transform="rotate(41.8165 754.787 35.6178)" fill="#4D9C89"/>
            <rect x="740.787" y="96.8915" width="10" height="1" rx="0.5" transform="rotate(15.4693 740.787 96.8915)" fill="#4D9C89"/>
            <path d="M745.596 101.645C745.494 101.388 745.619 101.097 745.875 100.995L749.591 99.5143C749.848 99.4121 750.138 99.5372 750.241 99.7937C750.343 100.05 750.218 100.341 749.961 100.443L746.245 101.924C745.989 102.026 745.698 101.901 745.596 101.645Z" fill="#4D9C89"/>
            <rect x="749.559" y="100.439" width="5" height="1" rx="0.5" transform="rotate(-122.712 749.559 100.439)" fill="#4D9C89"/>
            <rect x="745.619" y="117.628" width="10" height="1" rx="0.5" transform="rotate(-164.533 745.619 117.628)" fill="#4D9C89"/>
            <path d="M740.81 112.875C740.912 113.132 740.787 113.422 740.531 113.525L736.815 115.006C736.558 115.108 736.267 114.983 736.165 114.726C736.063 114.47 736.188 114.179 736.445 114.077L740.16 112.596C740.417 112.494 740.708 112.619 740.81 112.875Z" fill="#4D9C89"/>
            <rect x="736.847" y="114.081" width="5" height="1" rx="0.5" transform="rotate(57.2857 736.847 114.081)" fill="#4D9C89"/>
            <rect x="198.199" y="36.737" width="10" height="1" rx="0.5" transform="rotate(-179.773 198.199 36.737)" fill="#4D9C89"/>
            <path d="M192.31 33.4153C192.476 33.6359 192.432 33.9494 192.211 34.1154L189.015 36.5209C188.795 36.687 188.481 36.6428 188.315 36.4222C188.149 36.2015 188.193 35.888 188.414 35.722L191.61 33.3165C191.831 33.1504 192.144 33.1946 192.31 33.4153Z" fill="#4D9C89"/>
            <rect x="188.804" y="35.6205" width="5" height="1" rx="0.5" transform="rotate(42.0461 188.804 35.6205)" fill="#4D9C89"/>
        </g>
        <defs>
            <filter id="filter0_d_64_411" x="-4" y="0" width="927" height="156" filterUnits="userSpaceOnUse" color-interpolation-filters="sRGB">
                <feFlood flood-opacity="0" result="BackgroundImageFix"/>
                <feColorMatrix in="SourceAlpha" type="matrix" values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 127 0" result="hardAlpha"/>
                <feOffset dy="4"/>
                <feGaussianBlur stdDeviation="2"/>
                <feComposite in2="hardAlpha" operator="out"/>
                <feColorMatrix type="matrix" values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.25 0"/>
                <feBlend mode="normal" in2="BackgroundImageFix" result="effect1_dropShadow_64_411"/>
                <feBlend mode="normal" in="SourceGraphic" in2="effect1_dropShadow_64_411" result="shape"/>
            </filter>
        </defs>
    </svg>
</div>



