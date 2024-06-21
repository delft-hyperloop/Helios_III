import * as React from 'react';
import { AllSeriesType } from '../models/seriesType';
import { ChartSeriesType, DatasetType, FormatterResult } from '../models/seriesType/config';
import { ChartsColorPalette } from '../colorPalettes';
export type SeriesContextProviderProps = {
    dataset?: DatasetType;
    /**
     * The array of series to display.
     * Each type of series has its own specificity.
     * Please refer to the appropriate docs page to learn more about it.
     */
    series: AllSeriesType[];
    /**
     * Color palette used to colorize multiple series.
     * @default blueberryTwilightPalette
     */
    colors?: ChartsColorPalette;
    children: React.ReactNode;
};
export type FormattedSeries = {
    [type in ChartSeriesType]?: FormatterResult<type>;
};
export declare const SeriesContext: React.Context<FormattedSeries>;
declare function SeriesContextProvider(props: SeriesContextProviderProps): React.JSX.Element;
export { SeriesContextProvider };
