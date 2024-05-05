import uPlot from 'uplot';
import util from './util';
import type {IntervalFunction} from "$lib/types";
/**
 * This class is a wrapper around uPlot to make it easier to use.
 * It provides a simple interface to draw a graph and update it with new data.
 * It also takes care of buffering the data and updating the graph.
 */
export class GraphPlot {
    private readonly _data: uPlot.AlignedData;
    private readonly _opts: uPlot.Options;
    private _plot: uPlot | undefined;
    private _intervalId: number | undefined;

    /**
     * Create a new GraphPlot object. The graph will have the specified number of data points.
     * @param count The number of data points to display in the graph.
     * @param yRange The range of the y-axis.
     * @param showLegend Whether to show the legend on the graph.
     */
    public constructor(count:number, yRange:[number, number], showLegend:boolean = false) {
        this._data = [util.range(count), util.range(count, 0, 0)];

        this._opts = {
            width: 500,
            height: 300,
            legend: {
                show: showLegend,
            },
            scales: {
                "%": {
                    auto: false,
                },
                y: {
                    range: yRange
                },
                x: {
                    time: false,
                }
            },
            series: [
                {
                    label: "timestamp"
                },
                {
                    fill: "rgba(159,227,205,0.1)",
                    label: "y",
                    spanGaps: false,
                    stroke: "#0ea774",
                },
            ],
            axes: [
                {
                    stroke: "#e4e6ee",
                    grid: {
                        stroke: "rgba(255, 255, 255, 0.05)",
                        width: 0.5,
                    },
                },
                {
                    stroke: "#e4e6ee",
                    scale: "y",
                    grid: {
                        show: true,
                        width: 0.5,
                        stroke: "rgba(255, 255, 255, 0.05)"
                    },
                }
            ],
        };
    }

    /**
     * Redraw the graph with the current data.
     */
    public redraw() {
        if (this._plot) {
            this._plot.batch(() => {
                this._plot!.setData(this._data, false);
                this._plot!.redraw(false, false);
            });
        }
    }

    public addSeries(series:uPlot.Series, data:uPlot.TypedArray) {
        this._plot?.addSeries(series)
        this._data.push(data);
    }

    public updateSeries(seriesIndex:number, data:uPlot.TypedArray) {
        this._data[seriesIndex] = data;
    }

    /**
     * Draw the graph in the specified container.
     * The graph will be updated every 100ms.
     * @param plotContainer The HTML element in which the graph should be drawn.
     * @param updateInterval The interval in milliseconds at which the graph should be updated.
     * If 0 is passed, the graph will not be updated automatically!
     * @param intervalCallback A callback function that will be called at the specified interval.
     * This function should not take any arguments and return void.
     * By default, the function will call the redraw method.
     * @see [uPlot library](https://leeoniya.github.io/uPlot/) for more information on uPlot.
     * Documentation is severely lacking, but the examples should be helpful.
     */
    public draw(plotContainer: HTMLDivElement,
                updateInterval:number = 100,
                intervalCallback: IntervalFunction = () => {this.redraw()}) {
        this._plot = new uPlot(this._opts, this._data, plotContainer);

        if (updateInterval === 0) {
            intervalCallback();
            return;
        }

        this._intervalId = window.setInterval(intervalCallback, updateInterval);
    }



    /**
     * Set the size of the graph.
     * @param width width in pixels
     * @param height height in pixels
     */
    public setSize(width:number, height:number) {
        if (this._plot) {
            this._plot.setSize({width: width, height: height});
        }
    }

    /**
     * Add a new data point to the end of the graph.
     * This data will be buffered and displayed in the graph once its update interval is reached.
     * @param info The new data point to add to the graph.
     */
    public addEntry(info:number) {
        if (this._plot) {
            let yData = this._data[1];

            for (let i = 0; i < yData.length-1; i++) {
                yData[i] = yData[i+1];
            }

            yData[yData.length-1] = info
        }
    }

    public setEntry(index:number, info:number) {
        if (this._plot) {
            let yData = this._data[1];
            yData[index] = info;
        }
    }

    /**
     * Destroy the graph and stop updating it.
     * This method should be called when the graph is no longer needed.
     * It will stop the update interval and destroy the uPlot object.
     */
    public destroy() {
        if (this._plot) {
            this._plot.destroy();
        }
        if (this._intervalId !== undefined) {
            window.clearInterval(this._intervalId);
        }
    }
}