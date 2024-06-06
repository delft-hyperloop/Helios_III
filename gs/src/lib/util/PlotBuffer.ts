import uPlot from 'uplot';
import util from './util';

/**
 * This class is a wrapper around uPlot to make it easier to use.
 * It provides a simple interface to draw a graph and update it with new data.
 * It also takes care of buffering the data and updating the graph.
 */
export class PlotBuffer {
    private _plot: uPlot | undefined;
    private _intervalId: number | undefined;
    private readonly _data: uPlot.AlignedData;
    private readonly _opts: uPlot.Options;

    constructor(xDataLength: number, yRange: [number, number], showLegend: boolean = false) {
        this._data = [util.range(xDataLength)];

        this._opts = {
            width: 500,
            height: 300,
            legend: {show: showLegend},
            scales: { "%": { auto: false }, y: { range: yRange }, x: { time: false } },
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
            series: [{
                label: "timestamp",
            }],
        };

        this.addSeries(StrokePresets.hyperLoopGreen());
    }

    public addSeries(series:uPlot.Series) {
        const index: number = this._data.length;

        this._data.push(new Int32Array(this._data[0].length));
        this._opts.series.push(series);
        this._plot?.addSeries(series);

        setInterval(() => {
            this.addEntry(index, this.lastEntryOf(index))
        }, 100)
    }

    public lastEntryOf(seriesIndex:number):number {
        if (seriesIndex >= this._data.length) throw new Error("Series index out of bounds");
        return this._data[seriesIndex]![this._data[0].length-1]!;
    }

    public updateSeries(seriesIndex:number, data:uPlot.TypedArray) {
        if (seriesIndex >= this._data.length) throw new Error("Series index out of bounds");
        this._data[seriesIndex] = data;
    }

    public getSeriesData(seriesIndex: number) {
        return this._data[seriesIndex];
    }

    public setEntry(seriesIndex:number, dataIndex:number, value:number) {
        this._data[seriesIndex][dataIndex] = value;
    }

    /**
     * Add a new data point to the end of the graph.
     * This data will be buffered and displayed in the graph once its update interval is reached.
     * @param seriesIndex
     * @param value
     */
    public addEntry(seriesIndex:number, value:number) {
        let datum = this._data[seriesIndex];

        for (let i = 0; i < datum.length-1; i++) {
            datum[i] = datum[i+1];
        }

        datum[datum.length-1] = value;
    }

    /**
     * Draw the graph in the specified container.
     * @param plotContainer The HTML element in which the graph should be drawn.
     * @param updateInterval The interval in milliseconds at which the graph should be updated.
     * If 0 is passed, the graph will not be updated automatically!
     * This function should not take any arguments and return void.
     * @see [uPlot library](https://leeoniya.github.io/uPlot/) for more information on uPlot.
     * Documentation is severely lacking, but the examples should be helpful.
     */
    public draw(plotContainer: HTMLDivElement,
                updateInterval:number) {
        this._plot = new uPlot(this._opts, this._data, plotContainer);

        if (updateInterval === 0) {
            this.redraw();
            return;
        }

        this._intervalId = window.setInterval(() => this.redraw(), updateInterval);
    }

    /**
     * Redraw the graph with the current data.
     * This method should be called when the data in the graph has to be drawn.
     */
    public redraw() {
        if (this._plot) {
            this._plot.batch(() => {
                this._plot!.setData(this._data, false);
                this._plot!.redraw(false, false);
            });
        }
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
     * Destroy the graph and stop updating it.
     * This method should be called when the graph is no longer needed.
     * It will stop the update interval and destroy the uPlot object.
     */
    public destroy() {
        this._plot?.destroy();
        if (this._intervalId !== undefined) {
            window.clearInterval(this._intervalId);
        }
    }
}

export class StrokePresets {
    public static hyperLoopGreen(): uPlot.Series {
        return {
            fill: "rgba(159,227,205,0.1)",
            label: "y",
            spanGaps: false,
            stroke: "#0ea774"
        }
    }

    public static theoretical(): uPlot.Series {
        return {
            label: "y",
            spanGaps: false,
            stroke: "#ff0a43"
        }
    }

    public static yellow(): uPlot.Series {
        return {
            label: "y",
            spanGaps: false,
            stroke: "#ffde0a"
        }
    }

    public static blue(): uPlot.Series {
        return {
            label: "y",
            spanGaps: false,
            stroke: "#0a85ff"
        }
    }
}





