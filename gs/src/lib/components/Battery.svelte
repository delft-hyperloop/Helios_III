<script lang="ts">
    export let orientation:'horizontal'|'vertical' = 'vertical';
    export let perc:number;
    export let height:number = 27;
    export let fill:string = '#4D9C89';
</script>

<div>
    {#if orientation === 'vertical'}
        <svg {height} viewBox="0 0 51 114" fill="none" xmlns="http://www.w3.org/2000/svg">
            <g id="battery">
                <rect id="battery-fill" y={107 - perc} width="51" height={7 + perc} rx="8" {fill}/>
                <rect id="battery-body" x="1" y="6" width="49" height="107" rx="7" stroke="#EFF0F0" stroke-width="2"/>
                <path id="battery-edge" d="M20 1H32C33.6569 1 35 2.34315 35 4V6H17V4C17 2.34315 18.3431 1 20 1Z"
                      fill="#EFF0F0" stroke="#EFF0F0" stroke-width="2"/>
                <text id="battery-percentage" x="25" y="60" fill="white"
                      class="font-number {height > 50 ? `text-lg` : `text-sm`}" text-anchor="middle">{perc}%</text>
            </g>
        </svg>
    {:else if orientation === 'horizontal'}
        <svg {height} viewBox="0 0 115 52" fill="none" xmlns="http://www.w3.org/2000/svg">
            <g id="battery">
                <rect id="battery-fill" x="107.5" y={100-perc} width="51" height={7.5 + perc} rx="8" transform="rotate(90 107.5 0.5)"
                      {fill}/>
                <rect id="battery-body" x="108.5" y="1.5" width="49" height="107" rx="7" transform="rotate(90 108.5 1.5)"
                      stroke="#EFF0F0" stroke-width="2"/>
                <path id="battery-edge"
                      d="M113.5 20.5L113.5 32.5C113.5 34.1569 112.157 35.5 110.5 35.5L108.5 35.5L108.5 17.5L110.5 17.5C112.157 17.5 113.5 18.8431 113.5 20.5Z"
                      fill="#EFF0F0" stroke="#EFF0F0" stroke-width="2"/>
                <text id="battery-percentage" x="55" y="32" fill="white"
                      class="font-number {height > 30 ? 'text-lg' : 'text-2xl'}" text-anchor="middle">{perc}%</text>
            </g>
        </svg>
    {/if}
</div>