import { useEffect, useRef, useState } from "react";
import { GraphDatum } from "./GraphDatum";
import { GraphInterpolation } from "./GraphInterpolation";
import * as d3 from "d3";
import { Paper } from "@mui/material";



interface StringGraphProps<T> {
  datum: GraphDatum<T, string>,
  domain: string[],
  width?: number,
  now : number,
  height: number,
  margin?: { top: number, bottom: number, left: number, right: number },
  interpolation?: GraphInterpolation,
  unit?: string,
  timeDomainMs?: number
  refreshRate?: number
  timeShiftMs?: number
}

function StringGraph<T>({
  datum,
  domain,
  width,
  height,
  now,
  margin = { top: 0, bottom: 0, left: 0, right: 0 },
  interpolation = GraphInterpolation.Step,
  unit,
  timeDomainMs = 5000,
  refreshRate = 500,
  timeShiftMs = 0,
}: Readonly<StringGraphProps<T>>) {
  margin.left += 120;
  margin.bottom += 20;
  margin.top += 20;
  let yDomain = domain.slice();
  yDomain.push("UNDEFINED");
  yDomain.push("");
  yDomain.push(" ");
  yDomain.push("  ");


  const svgRef = useRef(null) as any;
  const [autoWidth, setWidth] = useState(200);

  useEffect(() => {

    const innerWidth = autoWidth - margin.left - margin.right;
    const innerHeight = height - margin.top - margin.bottom;

    let resizeObserver: ResizeObserver | undefined = undefined;
    let current = svgRef.current;
    if (!width) {
      resizeObserver = new ResizeObserver(
        entries => {
          if (!Array.isArray(entries)) return;
          if (!entries.length) return;
          const entry = entries[0];
          if (autoWidth != entry.contentRect.width) {
            setWidth(entry.contentRect.width);
          }
        }
      );
      resizeObserver.observe(current);
    }

    const xScale = d3.scaleLinear().range([0, innerWidth]);
    const yScaleAxis = d3.scalePoint([innerHeight, 0]).domain(yDomain);
    const yScale = d3.scalePoint().domain(yDomain).range([innerHeight, 0]);



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
    line.y((d: any) => yScale(datum.yValue(d)) as number);


    const timeAxis = d3.axisBottom(xScale)
      .tickFormat(x => `${x as number / 1000.0}s`)
      .ticks(5);


    const yAxis = d3.axisLeft(yScaleAxis)
      .tickFormat(x => `${x}${unit ?? ""}`)
      .ticks(yDomain.length);

    const yAxisGrid = d3.axisLeft(yScaleAxis)
      .tickSize(-innerWidth)
      .tickFormat("" as any)
      .ticks(yDomain.length);


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

    let graph = svg.append("g");
    graph.attr("clip-path", "url(#clip)")

    const a = svg.append("g")
      .attr("transform", `translate(0 ${innerHeight})`)
      .call(timeAxis);

    const b = svg.append("g")
      .attr("transform", "translate(0 0)")
      .call(yAxis);

    let c = graph.append("g")
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

    // UPDATE METHODS

    // initalize timestamp
    let timestamp = now;

    function updateXScale() {
      xScale.domain([timestamp - timeDomainMs, timestamp - timeShiftMs])
    }

    function updateSvgLineGraph() {
      group.attr("transform", "");
      group.select(".line")
        .datum(datum.values as any)
        .attr("d", line);
    }

    function updateTextValue() {
      value.text(datum.values.length === 0 ? "" : datum.yValue(datum.values[datum.values.length - 1]));
    }

    function updateSvg() {
      timestamp += refreshRate;
      updateXScale();
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

export default StringGraph;
