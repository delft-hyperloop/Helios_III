
import "./PrechargeVis.css"
import { useEffect, useState } from "react";
import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryListenLatestResponse } from "../../object_entry/types/events/ObjectEntryListenLatestResponse";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";
import { Paper } from "@mui/material";

interface PrechargeVisProps {
  nodeName: string,
  sdcEntryName?: string,
  prechargeEntryName?: string,
  feedthroughEntryName?: string,
  vdcVoltageEntryName? : string,
  width? : string,
}

function PrechargeVis({
  nodeName,
  sdcEntryName = "sdc_status",
  prechargeEntryName = "precharge_status",
  feedthroughEntryName = "feedthrough_status",
  vdcVoltageEntryName = "vdc_voltage",
  width = "10%",
}: PrechargeVisProps) {

  const [vdcVoltage, setVdcVoltage] = useState("0V");

  useEffect(() => {

    async function asyncSetup() {
      const svg = document.getElementById("precharge_vis")!;

      const sdcResp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
        nodeName,
        objectEntryName: sdcEntryName
      });
      if (sdcResp.latest !== undefined && sdcResp.latest !== null) {
        svg.style.setProperty("--sdc_switch", (sdcResp.latest.value as string == "CLOSED") ? "-30deg" : "0deg");
      }
      const unlistenSdc = await listen<ObjectEntryEvent>(sdcResp.event_name, event => {
        svg.style.setProperty("--sdc_switch", (event.payload.value as string == "CLOSED") ? "-30deg" : "0deg");
      });

      const prechargeResp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
        nodeName,
        objectEntryName: prechargeEntryName,
      });
      if (prechargeResp.latest !== undefined && prechargeResp.latest !== null) {
        svg.style.setProperty("--precharge_switch", (prechargeResp.latest.value as string == "CLOSED") ? "-30deg" : "0deg");
      }
      const unlistenPrecharge = await listen<ObjectEntryEvent>(prechargeResp.event_name, event => {
        svg.style.setProperty("--precharge_switch", (event.payload.value as string == "CLOSED") ? "-30deg" : "0deg");
      });

      const feedthroughResp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
        nodeName,
        objectEntryName: feedthroughEntryName,
      });
      if (feedthroughResp.latest !== undefined && feedthroughResp.latest !== null) {
        svg.style.setProperty("--feedthrough_switch", (feedthroughResp.latest.value as string == "CLOSED") ? "-30deg" : "0deg");
      }
      const unlistenFeedthrough = await listen<ObjectEntryEvent>(feedthroughResp.event_name, event => {
        svg.style.setProperty("--feedthrough_switch", (event.payload.value as string == "CLOSED") ? "-30deg" : "0deg");
      });

      const vdcResp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", {
        nodeName,
        objectEntryName: vdcVoltageEntryName,
      });
      if (vdcResp.latest !== undefined && vdcResp.latest !== null) {
        setVdcVoltage((vdcResp.latest.value as number).toFixed(1).toString() + "V");
      }
      const unlistenVdc = await listen<ObjectEntryEvent>(vdcResp.event_name, event => {
        setVdcVoltage((event.payload.value as number).toFixed(1).toString() + "V");
      });


      return () => {
        unlistenSdc();
        unlistenPrecharge();
        unlistenFeedthrough();
        unlistenVdc();
      }
    }
    let asyncCleanup = asyncSetup();
    return () => {
      asyncCleanup.then(f => f()).catch(console.error);
    };

  }, []);

  return (
    <Paper sx={{
      width,
    }}>
      <svg id="precharge_vis"
        data-name="Layer 1"
        xmlns="http://www.w3.org/2000/svg"
        version="1.1"
        viewBox="0 0 178 489">

        <g id="precharge_switch">
          <line className="cls-5" x1="39" y1="182.56" x2="23.5" y2="209.4" />
        </g>
        <g id="vdc_voltage">
          <text className="cls-10" transform="translate(104.5 390.12)"><tspan x="0" y="0">{vdcVoltage}</tspan></text>
        </g>
        <g id="feedthrough_switch">
          <line className="cls-5" x1="147" y1="183.56" x2="131.5" y2="210.4" />
        </g>
        <g id="sdc_switch">
          <line className="cls-5" x1="92" y1="82" x2="76.5" y2="108.85" />
        </g>
        <g id="background">
          <line className="cls-5" x1="68.5" y1="45.5" x2="115.5" y2="45.5" />
          <text className="cls-8" transform="translate(67.98 37.75)"><tspan x="0" y="0">45V-link</tspan></text>
          <line className="cls-5" x1="39" y1="141.5" x2="39" y2="182.5" />
          <line className="cls-5" x1="37.5" y1="142.5" x2="147" y2="142.5" />
          <line className="cls-5" x1="147" y1="182.5" x2="147" y2="141" />
          <circle className="cls-6" cx="92.5" cy="142.5" r="5.5" />
          <line className="cls-5" x1="39" y1="213.39" x2="38.5" y2="324.5" />
          <line className="cls-5" x1="146.5" y1="324.5" x2="146.95" y2="213.51" />
          <rect className="cls-3" x="32" y="251.5" width="14" height="40" />
          <circle className="cls-6" cx="39" cy="182" r="4" />
          <circle className="cls-6" cx="147" cy="183" r="4" />
          <line className="cls-5" x1="92" y1="44.5" x2="92" y2="82.72" />
          <circle className="cls-6" cx="92" cy="82.22" r="4" />
          <line className="cls-1" x1="92" y1="142" x2="92" y2="113" />
          <text className="cls-7" transform="translate(45.67 169.42)"><tspan x="0" y="0">Precharge</tspan></text>
          <text className="cls-7" transform="translate(81.92 234.19)"><tspan x="0" y="0">Feedthrough</tspan></text>
          <line className="cls-5" x1="39" y1="323" x2="147" y2="323" />
          <circle className="cls-6" cx="92.42" cy="322.73" r="5.5" />
          <line className="cls-1" x1="91.92" y1="323.23" x2="91.92" y2="352.23" />
          <circle className="cls-3" cx="92" cy="353" r="5.5" />
          <line className="cls-1" x1="91.68" y1="450.31" x2="91.68" y2="421.31" />
          <circle className="cls-3" cx="91.77" cy="420.54" r="5.5" />
          <line className="cls-5" x1="75.5" y1="449.5" x2="106.5" y2="449.5" />
          <line className="cls-2" x1="78.5" y1="454.5" x2="102.5" y2="454.5" />
          <line className="cls-4" x1="82" y1="458" x2="99" y2="458" />
          <text className="cls-9" transform="translate(103.21 103.36)"><tspan x="0" y="0">SDC</tspan></text>
          <g>
            <line className="cls-4" x1="92" y1="363" x2="92" y2="405.76" />
            <polygon className="cls-6" points="92 410 89.56 404.03 92 405.45 94.44 404.03 92 410" />
          </g>
        </g>
      </svg>
    </Paper>
  );
}


export default PrechargeVis;
