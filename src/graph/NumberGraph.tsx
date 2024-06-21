import * as d3 from "d3";
import { useEffect, useRef, useState } from "react";
import { GraphInterpolation } from "./GraphInterpolation";
import { GraphDatum } from "./GraphDatum";
import { Paper } from "@mui/material";


interface NumberGraphProps<T> {
  datum: GraphDatum<T, number>
  now : number,
  width?: number,
  height: number,
  margin?: { top: number, bottom: number, left: number, right: number },
  interpolation?: GraphInterpolation,
  unit?: string,
  timeDomainMs?: number
  refreshRate?: number
  bounds?: { max: number, min: number },
  timeShiftMs?: number
}


function NumberGraph<T>({
  datum,
  width,
  height,
  margin = { top: 0, bottom: 0, left: 0, right: 0 },
  interpolation = GraphInterpolation.Step,
  unit,
  now,
  timeDomainMs = 5000,
  refreshRate = 500,
  bounds,
  timeShiftMs = 0,
}: Readonly<NumberGraphProps<T>>) {

  console.log("render number graph");
  margin.left += 60;
  margin.bottom += 20;
  margin.top += 20;

  const svgRef = useRef(null) as any;

  const [autoWidth, setAutoWidth] = useState(200);


  useEffect(() => {
    let trueWidth = autoWidth;

    const innerWidth = trueWidth - margin.left - margin.right;
    const innerHeight = height - margin.top - margin.bottom;

    let resizeObserver: ResizeObserver | undefined = undefined;
    let current = svgRef.current;
    if (!width) {
      resizeObserver = new ResizeObserver(
        entries => {
          if (!Array.isArray(entries)) return;
          if (!entries.length) return;
          const entry = entries[0];
          if (trueWidth != entry.contentRect.width) {
            setAutoWidth(entry.contentRect.width);
          }
        }
      );
      resizeObserver.observe(current);
    }

    const xScale = d3.scaleLinear().range([0, innerWidth]);
    const yScale = d3.scaleLinear().range([innerHeight, 0]);
    const line = d3.line();
    // Select interpolation mode!
    switch (interpolation) {
      case GraphInterpolation.BasisSpline:
        line.curve(d3.curveBasis);
        break;
      case GraphInterpolation.BezierCurve:
        line.curve(d3.curveBumpX);
        break;
      case GraphInterpolation.CardinalSpline:
        line.curve(d3.curveCardinal);
        break;
      case GraphInterpolation.CatmullRomSpline:
        line.curve(d3.curveCatmullRom);
        break;
      case GraphInterpolation.Linear:
        line.curve(d3.curveLinear);
        break;
      case GraphInterpolation.MonotoneSpline:
        line.curve(d3.curveMonotoneX);
        break;
      case GraphInterpolation.NaturalSpline:
        line.curve(d3.curveNatural);
        break;
      case GraphInterpolation.Step:
        line.curve(d3.curveStepAfter);
        break;
    }
    // access the properties!
    line.x((d: any) => xScale(datum.xValue(d)));
    line.y((d: any) => yScale(datum.yValue(d)));


    const timeAxis = d3.axisBottom(xScale)
      .tickFormat(x => `${x as number / 1000.0}s`)
      .ticks(5);

    const yAxis = d3.axisLeft(yScale).tickFormat(x => `${x}${unit ?? ""}`);

    const yAxisGrid = d3.axisLeft(yScale)
      .tickSize(-innerWidth)
      .tickFormat("" as any)
      .ticks(5);


    const svg = d3.select(svgRef.current)
      .attr("width", "100%")
      .attr("height", height)
      .append("g")
      .attr("transform", `translate(${margin.left},${margin.top})`)

    svg.append("defs")
      .append("clipPath")
      .attr("id", "clip")
      .append("rect")
      .attr("width", innerWidth)
      .attr("height", innerHeight);

    const graph = svg.append("g");
    graph.attr("clip-path", "url(#clip)");

    const a = svg.append("g")
      .attr("transform", `translate(0 ${innerHeight})`)
      .call(timeAxis);

    const b = svg.append("g")
      .attr("transform", "translate(0 0)")
      .call(yAxis);

    const c = graph.append("g")
      .style("color", "#afcdfa")
      .style("stroke-width", 0.5)
      .call(yAxisGrid);

    const value = svg.append("text")
      .attr("x", innerWidth - 20)
      .attr("y", 25)
      .attr("text-anchor", "end");



    const group = graph.append("g");

    group.append("path")
      .datum(datum.values)
      .attr("d", line(datum.values as any))
      .attr("class", "line")
      .style("stroke", "#ff1e00")
      .style("stroke-width", 1.5)
      .style("fill", "none")

    let running = true;

    // initalize timestamp
    let timestamp = now;

    let maxY = bounds?.max ?? datum.values.length == 0 ? 100 : Math.max(...datum.values.map(datum.yValue));
    let minY = bounds?.min ?? datum.values.length == 0 ? 0 : Math.min(...datum.values.map(datum.yValue));

    function updateXScale() {
      xScale.domain([timestamp - timeDomainMs, timestamp - timeShiftMs])
    }

    function updateYScale() {
      yScale.domain([minY, maxY * 1.25]);
    }


    function updateSvgLineGraph() {
      group.attr("transform", "");
      group.select(".line")
        .datum(datum.values as any)
        .attr("d", line);
    }


    function updateTextValue() {
      value.text(datum.values.length === 0 ? "" : `${Math.round(
        datum.yValue(datum.values[datum.values.length - 1]) * 100.0)
        / 100.0}${unit ?? ""}`);
    }



    function updateSvg() {

      timestamp += refreshRate;
      updateXScale();
      updateYScale();
      updateSvgLineGraph();
      updateTextValue();
      a.transition()
        .duration(refreshRate)
        .ease(d3.easeLinear)
        .call(timeAxis);
      b.call(yAxis);
      c.call(yAxisGrid);


      if (running) {
        //restart animation
        d3.active(group.node())
          ?.transition()
          .on("start", updateSvg)
          .attr("transform", `translate(${xScale(timestamp - timeDomainMs - refreshRate)},0)`);
      }
    }

    group.transition()
      .on("start", updateSvg)
      .ease(d3.easeLinear)
      .duration(refreshRate);



    return () => {
      // Cleanup!
      resizeObserver?.unobserve(current);
      running = false;
      svg.remove();
    }
  }, [
    refreshRate,
    interpolation,
    autoWidth,
    height,
    timeDomainMs]);


  return <Paper sx={{ width: "100%", backgroundColor: "#f2f2f2" }}>
    <svg ref={svgRef}></svg>
  </Paper>;
}

export default NumberGraph;
