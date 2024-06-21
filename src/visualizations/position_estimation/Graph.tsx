import { useEffect, useRef, useState } from "react";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";

import { listen } from "@tauri-apps/api/event";
import { ObjectEntryListenHistoryResponse } from "../../object_entry/types/events/ObjectEntryListenHistoryResponse";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryHistoryEvent } from "../../object_entry/types/events/ObjectEntryHistoryEvent";

import * as d3 from "d3";
import { Box, Button, ButtonGroup, Stack } from "@mui/material";

const nodeName = "input_board";
const positionOe = "position";
const velocityOe = "velocity";
const accelerationOe = "acceleration";

const minYPosition = -1;
const maxYPosition = 21;

const minYVelocity = -3;
const maxYVelocity = 3;

const minYAcceleration = -30.1;
const maxYAcceleration = 30.1;

const timeDomain = 10 * 1000;

const marginLeft = 50;
const marginRight = 0;
const marginTop = 20;
const marginBottom = 50;

const refreshRate = 100;
const interval = 100;

const height = 250;


const lineColors = [
  "#fa0",
  "#f00",
  "#0f0",
  "#00f",
];


enum Mode {
  Position,
  Velocity,
  Acceleration
}

function Graph() {
  const svgRef = useRef(null) as any;

  const [autoWidth, setAutoWidth] = useState(0);

  const [oes, setOes] = useState<string[]>([]);

  const [maxY, setMaxY] = useState(125);
  const [minY, setMinY] = useState(-125);

  const [mode, setMode] = useState(Mode.Position);




  useEffect(() => {
    switch (mode) {
      case Mode.Position: {
        setOes([positionOe]);
        setMinY(minYPosition);
        setMaxY(maxYPosition);
        break;
      }
      case Mode.Velocity: {
        setOes([velocityOe]);
        setMinY(minYVelocity);
        setMaxY(maxYVelocity);
        break;
      }
      case Mode.Acceleration: {
        setOes([accelerationOe]);
        setMinY(minYAcceleration);
        setMaxY(maxYAcceleration);
        break;
      }
    }
  }, [mode]);

  useEffect(() => {

    // AUTO RESIZING!
    let trueWidth = autoWidth;
    const innerWidth = trueWidth - marginLeft - marginRight;
    const innerHeight = height - marginTop - marginBottom;

    let resizeObserver: ResizeObserver | undefined = undefined;
    let current = svgRef.current;
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

    // REGISTER LISTENERS

    let data: (ObjectEntryEvent[])[] = [];
    for (let _ in oes) {
      data.push([]);
    }

    let timestamp = 0; // initalized from listen history respnse!

    async function asyncRegister() {

      let unlisteners: (() => void)[] = [];

      for (let [i, oe] of oes.entries()) {
        const resp = await invoke<ObjectEntryListenHistoryResponse>("listen_to_history_of_object_entry", {
          nodeName,
          objectEntryName: oe,
          frameSize: timeDomain,
          minInterval: interval // 24fps
        });
        data[i] = resp.history;
        if (i == 0) {
          timestamp = resp.now;
        }
        const unlistenJs = await listen<ObjectEntryHistoryEvent>(resp.event_name, event => {
          data[i].splice(0, event.payload.deprecated_count);
          data[i].push(...event.payload.new_values);
        });
        unlisteners.push(() => {
          unlistenJs();
          invoke("unlisten_from_history_of_object_entry", {
            nodeName,
            objectEntryName: oe,
            eventName: resp.event_name,
          }).catch(console.error);
        });
      }

      return () => {
        unlisteners.map(f => f());
      };
    }

    const asyncCleanup = asyncRegister();

    const xScale = d3.scaleLinear().range([0, innerWidth]);
    const yScale = d3.scaleLinear().range([innerHeight, 0]);

    let lines: d3.Line<[number, number]>[] = [];
    for (let _ of oes) {
      const line = d3.line();
      line.curve(d3.curveStepAfter);
      line.x((d: any) => xScale(d.timestamp));
      line.y((d: any) => yScale(d.value));
      lines.push(line);
    }

    const timeAxis = d3.axisBottom(xScale)
      .tickFormat(x => `${x as number / 1000.0}s`)
      .ticks(5);

    const yAxis = d3.axisLeft(yScale).tickFormat(x => `${x}`);

    const yAxisGrid = d3.axisLeft(yScale)
      .tickSize(-innerWidth)
      .tickFormat("" as any)
      .ticks(5);

    const svg = d3.select(svgRef.current)
      .attr("width", "100%")
      .attr("height", height)
      .append("g")
      .attr("transform", `translate(${marginLeft},${marginTop})`)

    svg.append("defs").append("clipPath").attr("id", "clip").append("rect")
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


    for (let [i, oe] of oes.entries()) {
      svg.append("text")
        .attr("x", innerWidth - 20)
        .attr("y", i * 25)
        .attr("text-anchor", "end")
        .attr("fill", lineColors[i])
        .text(oe);
    }
    const group = graph.append("g");

    for (let [i, oe] of oes.entries()) {
      group.append("path")
        .datum(data[i])
        .attr("d", lines[i](data[i] as any))
        .attr("class", oe)
        .style("stroke", lineColors[i])
        .style("stroke-width", 1.5)
        .style("opacity", 0.5)
        .style("fill", "none")
    }

    let running = true;
    const timeShiftMs = 0;


    function updateXScale() {
      xScale.domain([timestamp - timeDomain, timestamp - timeShiftMs])
    }

    function updateYScale() {
      yScale.domain([minY, maxY]);
    }

    function updateSvgLineGraph() {

      for (let [i, oe] of oes.entries()) {
        group.attr("transform", "");
        group.select(`.${oe}`)
          .datum(data[i] as any)
          .attr("d", lines[i]);
      }

    }


    function updateSvg() {

      timestamp += refreshRate;
      updateXScale();
      updateYScale();
      updateSvgLineGraph();
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
          .attr("transform", `translate(${xScale(timestamp - timeDomain - refreshRate)},0)`);
      }
    }

    group.transition()
      .on("start", updateSvg)
      .ease(d3.easeLinear)
      .duration(refreshRate);

    return () => {

      asyncCleanup.then(f => f()).catch(console.error);

      resizeObserver?.unobserve(current);

      running = false;
      svg.remove();
    };

  }, [autoWidth, nodeName, oes, minY, maxY, timeDomain]);

  return (
    <Stack direction="row" spacing={2} sx={{
      height: "100%",
    }} alignItems="start">
      <svg ref={svgRef}></svg>

      <Box paddingTop={1} paddingRight={1}>
      <ButtonGroup variant="contained" aria-label="Basic button group" orientation="vertical">
        <Button variant={mode == Mode.Position ? "contained" : "text"}
          onClick={() => setMode(Mode.Position)}
          sx={{
            width: "10em",
          }}
        >
          Position
        </Button>
        <Button variant={mode == Mode.Velocity ? "contained" : "text"}
          onClick={() => setMode(Mode.Velocity)}
          sx={{
            width: "10em",
          }}
        >
          Velocity
        </Button>
        <Button variant={mode == Mode.Acceleration ? "contained" : "text"}
          onClick={() => setMode(Mode.Acceleration)}
          sx={{
            width: "10em",
          }}
        >
          Acceleration
        </Button>
      </ButtonGroup>
      </Box>
    </Stack>
  );
}

export default Graph;
