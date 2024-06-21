import { useEffect, useRef, useState } from "react";
import Mode from "./mode";
import Side from "./side";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";

import { listen } from "@tauri-apps/api/event";
import { ObjectEntryListenHistoryResponse } from "../../object_entry/types/events/ObjectEntryListenHistoryResponse";
import { invoke } from "@tauri-apps/api";
import { ObjectEntryHistoryEvent } from "../../object_entry/types/events/ObjectEntryHistoryEvent";

import * as d3 from "d3";
import { Button, ButtonGroup, Slider, Stack } from "@mui/material";

function PIGraph() {
  const svgRef = useRef(null) as any;

  const [autoWidth, setAutoWidth] = useState(0);

  const [nodeName, setNodeName] = useState("levitation_board1");
  const [airgapOe, setAirgapOe] = useState("current_left");
  const [pTermOe, setPTermOe] = useState("left_current_controller_p_term");
  const [iTermOe, setITermOe] = useState("left_current_controller_i_term");
  const [dTermOe, setDTermOe] = useState("left_current_controller_d_term");
  const [outputOe, setOutputOe] = useState("left_current_controller_output");

  const [maxY, setMaxY] = useState(125);
  const [minY, setMinY] = useState(-125);
  const [timeDomain, setTimeDomain] = useState(10 * 1000);

  const [mode, setMode] = useState(Mode.Board1);
  const [side, setSide] = useState(Side.Left);


  const marginLeft = 50;
  const marginRight = 0;
  const marginTop = 0;
  const marginBottom = 50;

  const colorAirgap = "#fa0";
  const colorPTerm = "#ff0000";
  const colorITerm = "#00ff00";
  const colorOutput = "#0000ff";

  const refreshRate = 100;
  const interval = 100;

  const height = 450;

  useEffect(() => {
    switch (side) {
      case Side.Left: {
        setAirgapOe("current_left");
        setPTermOe("left_current_controller_p_term");
        setITermOe("left_current_controller_i_term");
        setDTermOe("left_current_controller_d_term");
        setOutputOe("left_current_controller_output");
        break;
      }
      case Side.Right: {
        setAirgapOe("current_right");
        setPTermOe("right_current_controller_p_term");
        setITermOe("right_current_controller_i_term");
        setDTermOe("right_current_controller_d_term");
        setOutputOe("right_current_controller_output");
        break;
      }
    }
    switch (mode) {
      case Mode.Board1: {
        setNodeName("levitation_board1");
        break;
      }
      case Mode.Board2: {
        setNodeName("levitation_board2");
        break;
      }
      case Mode.Board3: {
        setNodeName("levitation_board3");
        break;
      }
    }
  }, [mode, side]);

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

    let airgap_data: ObjectEntryEvent[] = [];
    let p_term_data: ObjectEntryEvent[] = [];
    let i_term_data: ObjectEntryEvent[] = [];
    let output_data: ObjectEntryEvent[] = [];

    let timestamp = 0; // initalized from listen history respnse!

    async function asyncRegister() {
      const respAirgap = await invoke<ObjectEntryListenHistoryResponse>("listen_to_history_of_object_entry", {
        nodeName,
        objectEntryName: airgapOe,
        frameSize: timeDomain,
        minInterval: interval // 24fps
      });
      airgap_data = respAirgap.history;
      timestamp = respAirgap.now;
      const unlistenAirgap = await listen<ObjectEntryHistoryEvent>(respAirgap.event_name, event => {
        airgap_data.splice(0, event.payload.deprecated_count);
        airgap_data.push(...event.payload.new_values);
      });


      const respKpTerm = await invoke<ObjectEntryListenHistoryResponse>("listen_to_history_of_object_entry", {
        nodeName,
        objectEntryName: pTermOe,
        frameSize: timeDomain,
        minInterval: interval // 24fps
      });
      p_term_data = respKpTerm.history;
      const unlistenKpTerm = await listen<ObjectEntryHistoryEvent>(respKpTerm.event_name, event => {
        p_term_data.splice(0, event.payload.deprecated_count);
        p_term_data.push(...event.payload.new_values);
      });


      const respKiTerm = await invoke<ObjectEntryListenHistoryResponse>("listen_to_history_of_object_entry", {
        nodeName,
        objectEntryName: iTermOe,
        frameSize: timeDomain,
        minInterval: interval // 24fps
      });
      i_term_data = respKiTerm.history;
      const unlistenKiTerm = await listen<ObjectEntryHistoryEvent>(respKiTerm.event_name, event => {
        i_term_data.splice(0, event.payload.deprecated_count);
        i_term_data.push(...event.payload.new_values);
      });

      const respOutput = await invoke<ObjectEntryListenHistoryResponse>("listen_to_history_of_object_entry", {
        nodeName,
        objectEntryName: outputOe,
        frameSize: timeDomain,
        minInterval: interval // 24fps
      });
      output_data = respOutput.history;
      const unlistenOutput = await listen<ObjectEntryHistoryEvent>(respOutput.event_name, event => {
        output_data.splice(0, event.payload.deprecated_count);
        output_data.push(...event.payload.new_values);
      });

      return () => {
        unlistenAirgap();
        unlistenKpTerm();
        unlistenKiTerm();
        unlistenOutput();
        invoke("unlisten_from_history_of_object_entry", {
          nodeName,
          objectEntryName: airgapOe,
          eventName: respAirgap.event_name,
        }).catch(console.error);
        invoke("unlisten_from_history_of_object_entry", {
          nodeName,
          objectEntryName: pTermOe,
          eventName: respKpTerm.event_name,
        }).catch(console.error);
        invoke("unlisten_from_history_of_object_entry", {
          nodeName,
          objectEntryName: iTermOe,
          eventName: respKiTerm.event_name,
        }).catch(console.error);
        invoke("unlisten_from_history_of_object_entry", {
          nodeName,
          objectEntryName: outputOe,
          eventName: respOutput.event_name,
        }).catch(console.error);
      };
    }

    const asyncCleanup = asyncRegister();

    const xScale = d3.scaleLinear().range([0, innerWidth]);
    const yScale = d3.scaleLinear().range([innerHeight, 0]);

    const airgapLine = d3.line();
    airgapLine.curve(d3.curveStepAfter);
    airgapLine.x((d: any) => xScale(d.timestamp));
    airgapLine.y((d: any) => yScale(d.value));

    const pTermLine = d3.line();
    pTermLine.curve(d3.curveStepAfter);
    pTermLine.x((d: any) => xScale(d.timestamp));
    pTermLine.y((d: any) => yScale(d.value));

    const iTermLine = d3.line();
    iTermLine.curve(d3.curveStepAfter);
    iTermLine.x((d: any) => xScale(d.timestamp));
    iTermLine.y((d: any) => yScale(d.value));

    const outputLine = d3.line();
    outputLine.curve(d3.curveStepAfter);
    outputLine.x((d: any) => xScale(d.timestamp));
    outputLine.y((d: any) => yScale(d.value));

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

    svg.append("text")
      .attr("x", innerWidth - 20)
      .attr("y", 25)
      .attr("text-anchor", "end")
      .attr("fill", colorAirgap)
      .text("Current");
    svg.append("text")
      .attr("x", innerWidth - 20)
      .attr("y", 50)
      .attr("text-anchor", "end")
      .attr("fill", colorPTerm)
      .text("KpTerm");
    svg.append("text")
      .attr("x", innerWidth - 20)
      .attr("y", 75)
      .attr("text-anchor", "end")
      .attr("fill", colorITerm)
      .text("KiTerm");
    svg.append("text")
      .attr("x", innerWidth - 20)
      .attr("y", 100)
      .attr("text-anchor", "end")
      .attr("fill", colorOutput)
      .text("Output");

    const group = graph.append("g");

    group.append("path")
      .datum(airgap_data)
      .attr("d", airgapLine(airgap_data as any))
      .attr("class", "airgap-line")
      .style("stroke", colorAirgap)
      .style("stroke-width", 1.5)
      .style("opacity", 0.5)
      .style("fill", "none")

    group.append("path")
      .datum(p_term_data)
      .attr("d", pTermLine(p_term_data as any))
      .attr("class", "p-term-line")
      .style("stroke", colorPTerm)
      .style("stroke-width", 1.5)
      .style("opacity", 0.5)
      .style("fill", "none")

    group.append("path")
      .datum(i_term_data)
      .attr("d", iTermLine(i_term_data as any))
      .attr("class", "i-term-line")
      .style("stroke", colorITerm)
      .style("stroke-width", 1.5)
      .style("opatimeDomainMscity", 0.5)
      .style("fill", "none")

    group.append("path")
      .datum(output_data)
      .attr("d", outputLine(output_data as any))
      .attr("class", "output-line")
      .style("stroke", colorOutput)
      .style("stroke-width", 1.5)
      .style("opacity", 0.5)
      .style("fill", "none")




    let running = true;
    const timeShiftMs = 0;


    function updateXScale() {
      xScale.domain([timestamp - timeDomain, timestamp - timeShiftMs])
    }

    function updateYScale() {
      yScale.domain([minY, maxY]);
    }

    function updateSvgLineGraph() {
      group.attr("transform", "");
      group.select(".airgap-line")
        .datum(airgap_data as any)
        .attr("d", airgapLine);

      group.select(".p-term-line")
        .datum(p_term_data as any)
        .attr("d", pTermLine);

      group.select(".i-term-line")
        .datum(i_term_data as any)
        .attr("d", iTermLine);

      group.select(".output-line")
        .datum(output_data as any)
        .attr("d", outputLine);

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

  }, [autoWidth, nodeName, airgapOe,
    pTermOe, iTermOe, dTermOe, dTermOe, outputOe, minY, maxY, timeDomain]);

  const [yRange, setYRange] = useState([minY, maxY]);

  const handleChange = (_event: Event, newValue: number | number[]) => {
    setYRange(newValue as number[]);
    setMinY((newValue as number[])[0]);
    setMaxY((newValue as number[])[1]);
  };

  const [xRange, setXRange] = useState(10);

  const handleXChange = (_event: Event, newValue: number | number[]) => {
    setXRange(newValue as number);
    setTimeDomain((newValue as number) * 1000);
  };

  return (
    <Stack direction="row" spacing={2} sx={{
      height: "100%",
    }}>
      <Stack direction="column" spacing={2} sx={{
        width: "100%"
      }}>
        <Stack direction="row" justifyContent="end" spacing={3}>

          <Slider
            getAriaValueText={() => 'Minimum distance'}
            valueLabelDisplay="auto"
            min={1} 
            max={60}
            value={xRange}
            onChange={handleXChange}
          />

          <ButtonGroup variant="contained" aria-label="Basic button group">
            <Button variant={mode == Mode.Board1 ? "contained" : "text"}
              onClick={() => setMode(Mode.Board1)}
              sx={{
                width: "25px",
              }}
            >
              1
            </Button>
            <Button variant={mode == Mode.Board2 ? "contained" : "text"}
              onClick={() => setMode(Mode.Board2)}
              sx={{
                width: "25px",
              }}
            >
              2
            </Button>
            <Button variant={mode == Mode.Board3 ? "contained" : "text"}
              onClick={() => setMode(Mode.Board3)}
              sx={{
                width: "25px",
              }}
            >
              3
            </Button>
          </ButtonGroup>

          <ButtonGroup variant="contained" aria-label="Basic button group">
            <Button variant={side == Side.Right ? "contained" : "text"}
              onClick={() => setSide(Side.Right)}
              sx={{
                width: "75px",
              }}
            >
              Right
            </Button>
            <Button variant={side == Side.Left ? "contained" : "text"}
              onClick={() => setSide(Side.Left)}
              sx={{
                width: "75px",
              }}
            >
              Left
            </Button>
          </ButtonGroup>

        </Stack>
        <svg ref={svgRef}></svg>
      </Stack>

      <Slider
        getAriaLabel={() => 'Minimum distance'}
        valueLabelDisplay="auto"
        orientation="vertical"
        min={-1000}
        max={1000}
        onChange={handleChange}
        value={yRange}
      />
    </Stack>
  );
}

export default PIGraph;
