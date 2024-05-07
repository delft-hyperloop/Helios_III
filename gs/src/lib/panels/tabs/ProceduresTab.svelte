<script lang="ts">
    import {AppRail, AppRailTile} from "@skeletonlabs/skeleton";

    let currentTile: number = 0;

    let procedures = [
        {title: "Turning off pod", description: "This is the first procedure"},
        {title: "Installing linux", description: "This is asdwa firdwwt procedure"},
        {title: "Something", description: "This is the sa padarocedure"},
        {title: "Else", description: "This is tasdhe asocedure"},
        {title: "I linux", description: "This is the as procedure"},
        {title: "oof linux", description: "This is the first as"},
    ]
</script>

<div class="h-full flex items-stretch">
    <div>
        <AppRail background="bg-surface-900" aspectRatio="aspect-auto" width="w-40">
            {#each procedures as procedure, i}
                <AppRailTile bind:group={currentTile} name={procedure.title} value={i} title={procedure.title}>
                    <p class="py-2 text-base font-medium">{procedure.title}</p>
                </AppRailTile>
            {/each}
        </AppRail>
    </div>
    <div class="p-8 w-10/12 flex-grow flex flex-col gap-4">
        <h2 class="text-2xl font-bold">Important procedure: {procedures[currentTile].title}</h2>
        <p class="text-base font-medium">This is the first procedure</p>
        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Magni nesciunt dicta porro rerum blanditiis maxime, quidem at amet! Id eius adipisci autem excepturi labore omnis, itaque cum. Provident, deserunt nostrum.</p>
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Porro recusandae error quibusdam harum modi animi perspiciatis magni in, obcaecati quam quaerat quas expedita debitis, eligendi eaque. Blanditiis, tempore? Quaerat, minima? Lorem ipsum dolor sit amet consectetur adipisicing elit. Incidunt excepturi quis cupiditate nam praesentium deleniti. Accusantium quas neque ipsum, laudantium doloremque error. Alias animi, itaque minus et ipsum facilis excepturi?</p>
        <p>{procedures[currentTile].description}</p>
    </div>
</div>
