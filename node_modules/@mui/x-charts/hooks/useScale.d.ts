import { D3Scale } from '../models/axis';
/**
 * For a given scale return a function that map value to their position.
 * Usefull when dealing with specific scale such as band.
 * @param scale The scale to use
 * @returns (value: any) => number
 */
export declare function getValueToPositionMapper(scale: D3Scale): (value: any) => number;
export declare function useXScale(identifier?: number | string): import("d3-scale").ScaleBand<string | number | Date> | import("d3-scale").ScalePoint<string | number | Date> | import("d3-scale").ScaleLogarithmic<number, number, never> | import("d3-scale").ScalePower<number, number, never> | import("d3-scale").ScaleTime<number, number, never> | import("d3-scale").ScaleLinear<number, number, never>;
export declare function useYScale(identifier?: number | string): import("d3-scale").ScaleBand<string | number | Date> | import("d3-scale").ScalePoint<string | number | Date> | import("d3-scale").ScaleLogarithmic<number, number, never> | import("d3-scale").ScalePower<number, number, never> | import("d3-scale").ScaleTime<number, number, never> | import("d3-scale").ScaleLinear<number, number, never>;
