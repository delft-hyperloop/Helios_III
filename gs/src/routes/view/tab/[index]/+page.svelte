<script lang="ts">
    import {
        ProceduresTab,
    } from "$lib"
    import type { PageData } from './$types';


    export let data: PageData;
</script>

<div class="h-full snap-x scroll-px-4 snap-mandatory scroll-smooth overflow-x-auto">
    <!--{#if data.index === 0}-->
    <!--    <HomeTab />-->
    <!--{:else if data.index === 1}-->
    <!--    <RunInitTab pop_up={false} />-->
    <!--{:else if data.index === 2}-->
    <!--    <LocationTab pop_up={false}  />-->
    <!--{:else if data.index === 3}-->
    <!--    <BatteriesTab pop_up={false}  />-->
    <!--{:else if data.index === 4}-->
    <!--    <LeviTab pop_up={false}  />-->
    <!--{:else if data.index === 5}-->
    <!--    <PneumaticsTab pop_up={false}  />-->
    <!--{:else if data.index === 6}-->
    <!--    <ProceduresTab pop_up={false}  />-->
    <!--{:else if data.index === 7}-->
    <!--    <DebugTab pop_up={false}  />-->
    <!--{/if}-->
    <ProceduresTab pop_up={false} />
</div>