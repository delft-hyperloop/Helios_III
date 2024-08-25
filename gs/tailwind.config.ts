import { join } from 'path';
import type { Config } from 'tailwindcss';
import { skeleton } from '@skeletonlabs/tw-plugin';
import { delft_hyperloop_dark } from './src/delft_hyperloop_dark';

export default {
    darkMode: 'class',
    content: [
        './src/**/*.{html,js,svelte,ts}',
        join(require.resolve('@delft-hyperloop/serpenta'), '../**/*.{html,js,svelte,ts}'),
        join(require.resolve('@skeletonlabs/skeleton'), '../**/*.{html,js,svelte,ts}'),
    ],
    theme: {
        extend: {},
    },
    plugins: [
        skeleton({
            themes: {
                custom: [
                    delft_hyperloop_dark,
                ],
            },
        }),
    ],
} satisfies Config;
