import * as React from 'react';
import { ChartItemIdentifier, ChartSeriesType } from '../models/seriesType/config';
export interface HighlightProviderProps {
    children: React.ReactNode;
}
export type ItemHighlighData<T extends ChartSeriesType> = ChartItemIdentifier<T>;
export type HighlightOptions = 'none' | 'item' | 'series';
export type FadeOptions = 'none' | 'series' | 'global';
export type HighlightScope = {
    /**
     * The scope of highlighted elements.
     * - 'none': no highlight.
     * - 'item': only highlight the item.
     * - 'series': highlight all elements of the same series.
     * @default 'none'
     */
    highlighted: HighlightOptions;
    /**
     * The scope of faded elements.
     * - 'none': no fading.
     * - 'series': only fade element of the same series.
     * - 'global': fade all elements that are not highlighted.
     * @default 'none'
     */
    faded: FadeOptions;
};
type HighlighActions<T extends ChartSeriesType = ChartSeriesType> = {
    type: 'enterItem';
    item: ItemHighlighData<T>;
    scope?: Partial<HighlightScope>;
} | {
    type: 'leaveItem';
    item: ItemHighlighData<T>;
};
type HighlighState = {
    /**
     * The item that triggers the highlight state.
     */
    item: null | ItemHighlighData<ChartSeriesType>;
    scope: HighlightScope;
    dispatch: React.Dispatch<HighlighActions>;
};
export declare const HighlighContext: React.Context<HighlighState>;
declare function HighlightProvider(props: HighlightProviderProps): React.JSX.Element;
export { HighlightProvider };
