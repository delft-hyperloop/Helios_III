
import { useEffect } from "react";
import "./TemperatureVis.css"
import { invoke } from "@tauri-apps/api";
import { ObjectEntryListenLatestResponse } from "../../object_entry/types/events/ObjectEntryListenLatestResponse";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryInformation } from "../../object_entry/types/ObjectEntryInformation";
import { IntTypeInfo, RealTypeInfo, UIntTypeInfo } from "../../object_entry/types/Type";
import { Paper, Stack, Typography } from "@mui/material";


interface Color {
  r: number,
  g: number,
  b: number,
}

function learpColor(alpha: number, colorA: Color, colorB: Color): Color {
  return {
    r: alpha * colorA.r + (1.0 - alpha) * colorB.r,
    g: alpha * colorA.g + (1.0 - alpha) * colorB.g,
    b: alpha * colorA.b + (1.0 - alpha) * colorB.b
  }
}

function colorToCss(color: Color): string {
  return `rgb(${color.r},${color.g},${color.b}`;
}

const hot: Color = {
  r: 242,
  g: 5,
  b: 5,
};

const cold: Color = {
  r: 195,
  g: 197,
  b: 203
}

const MLU1_OE = { nodeName: "mlu1", objectEntryName: "magnet_temperature" };
const MLU2_OE = { nodeName: "mlu2", objectEntryName: "magnet_temperature" };
const MLU3_OE = { nodeName: "mlu3", objectEntryName: "magnet_temperature" };
const MLU4_OE = { nodeName: "mlu4", objectEntryName: "magnet_temperature" };
const MLU5_OE = { nodeName: "mlu5", objectEntryName: "magnet_temperature" };
const MLU6_OE = { nodeName: "mlu6", objectEntryName: "magnet_temperature" };
const MGU1_STARBOARD_OE = { nodeName: "mgu1", objectEntryName: "magnet_temperature_starboard" };
const MGU1_PORT_OE = { nodeName: "mgu1", objectEntryName: "magnet_temperature_port" };
const MGU2_STARBOARD_OE = { nodeName: "mgu2", objectEntryName: "magnet_temperature_starboard" };
const MGU2_PORT_OE = { nodeName: "mgu2", objectEntryName: "magnet_temperature_port" };
const DSLIM_STARBOARD_OE = { nodeName: "motor_driver", objectEntryName: "motor_temperature_starboard" };
const DSLIM_PORT_OE = { nodeName: "motor_driver", objectEntryName: "motor_temperature_port" };
const EBOX1_OE = { nodeName: "input_board", objectEntryName: "ebox_temperature" };
const EBOX2_OE = { nodeName: "input_board", objectEntryName: "ebox_temperature" };
const MOTOR_DRIVER_OR = { nodeName: "motor_driver", objectEntryName: "motor_temperature_starboard" }; // TODO
const COOLING_RESERVOIR_OE = { nodeName: "input_board", objectEntryName: "cooling_cycle_temperature" };


interface OeId {
  nodeName: string,
  objectEntryName: string,
}

async function registerOe(oe: OeId, property: string, element: HTMLElement) {
  const info = await invoke<ObjectEntryInformation>("object_entry_information", oe as any);
  let min: number, max: number;
  switch (info.ty.id) {
    case "int": {
      const typeInfo = info.ty.info as IntTypeInfo;
      const bitSize = typeInfo.bit_size;
      max = Math.pow(2, bitSize / 2) - 1;
      min = -Math.pow(2, bitSize / 2);
      break;
    }
    case "uint": {
      const typeInfo = info.ty.info as UIntTypeInfo;
      const bitSize = typeInfo.bit_size;
      max = Math.pow(2, bitSize / 2) - 1;
      min = -Math.pow(2, bitSize / 2);
      break;
    }
    case "real": {
      const typeInfo = info.ty.info as RealTypeInfo;
      max = typeInfo.max;
      min = typeInfo.min;
      break;
    }
    case "enum":
    case "struct":
      return () => { };
  }
  const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", oe as any);
  if (resp.latest !== undefined && resp.latest !== null) {
    const alpha = ((resp.latest.value as number) + min) / (max - min);
    const cssColor = colorToCss(learpColor(alpha, hot, cold));
    element.style.setProperty(property, cssColor);
  }
  const unlistenJs = await listen<ObjectEntryEvent>(resp.event_name, event => {
    const alpha = ((event.payload.value as number) + min) / (max - min);
    const cssColor = colorToCss(learpColor(alpha, hot, cold));
    element.style.setProperty(property, cssColor);
  });

  return () => {
    unlistenJs();
    invoke("unlisten_from_latest_object_entry_value", oe as any);
  }
}


function TemperatureVis() {

  useEffect(() => {

    const svg = document.getElementById("temperature_vis")!;

    let cleanup: (Promise<() => void>)[] = [];
    cleanup.push(registerOe(MLU1_OE, "--mlu1_temperature", svg));
    cleanup.push(registerOe(MLU2_OE, "--mlu2_temperature", svg));
    cleanup.push(registerOe(MLU3_OE, "--mlu3_temperature", svg));
    cleanup.push(registerOe(MLU4_OE, "--mlu4_temperature", svg));
    cleanup.push(registerOe(MLU5_OE, "--mlu5_temperature", svg));
    cleanup.push(registerOe(MLU6_OE, "--mlu6_temperature", svg));

    cleanup.push(registerOe(MGU1_STARBOARD_OE, "--mgu1_starboard_temperature", svg));
    cleanup.push(registerOe(MGU1_PORT_OE, "--mgu1_port_temperature", svg));
    cleanup.push(registerOe(MGU2_STARBOARD_OE, "--mgu2_starboard_temperature", svg));
    cleanup.push(registerOe(MGU2_PORT_OE, "--mgu2_port_temperature", svg));

    cleanup.push(registerOe(DSLIM_STARBOARD_OE, "--dslim_starboard_temperature", svg));
    cleanup.push(registerOe(DSLIM_PORT_OE, "--dslim_port_temperature", svg));

    cleanup.push(registerOe(EBOX1_OE, "--ebox1_temperature", svg));
    cleanup.push(registerOe(EBOX2_OE, "--ebox2_temperature", svg));

    cleanup.push(registerOe(MOTOR_DRIVER_OR, "--motor_driver_temperature", svg)); // TODO

    cleanup.push(registerOe(COOLING_RESERVOIR_OE, "--cooling_reservoir_temperature", svg));

    return () => {
      cleanup.forEach(p => p.then(f => f()).catch(console.error));
    };
  }, []);

  return (
    <Paper sx={{
      width: "62%",
      padding: 1
    }}>
      <Stack>
        <Typography
          style={{ textAlign: "center" }}
          variant="h5"
        >
          Temperatures
        </Typography>
        <svg
          version="1.1"
          xmlns="http://www.w3.org/2000/svg"
          x="0px"
          y="0px"
          viewBox="0 0 1366 768"
          id="temperature_vis"
        >
          <g id="frame">
            <g id="mgu2">
              <path className="mgu1_starboard" d="M433.16,126.83h-70.66c-2.88,0-5.24-2.36-5.24-5.24v-7.07c0-2.88,2.36-5.24,5.24-5.24h70.66
			c2.88,0,5.24,2.36,5.24,5.24v7.07C438.4,124.47,436.05,126.83,433.16,126.83z"/>
              <path className="mgu1_port" d="M433.56,595.03h-70.66c-2.88,0-5.24,2.36-5.24,5.24v7.07c0,2.88,2.36,5.24,5.24,5.24h70.66
			c2.88,0,5.24-2.36,5.24-5.24v-7.07C438.8,597.38,436.44,595.03,433.56,595.03z"/>
              <path className="mgu2_starboard" d="M1019.94,126.55h-70.66c-2.88,0-5.24-2.36-5.24-5.24v-7.07c0-2.88,2.36-5.24,5.24-5.24h70.66
			c2.88,0,5.24,2.36,5.24,5.24v7.07C1025.18,124.19,1022.82,126.55,1019.94,126.55z"/>
              <path className="mgu2_port" d="M1020.34,594.74h-70.66c-2.88,0-5.24,2.36-5.24,5.24v7.07c0,2.88,2.36,5.24,5.24,5.24h70.66
			c2.88,0,5.24-2.36,5.24-5.24v-7.07C1025.58,597.1,1023.22,594.74,1020.34,594.74z"/>
            </g>
            <path className="st0" d="M1192.42,176.87H172.34c-7.44,0-13.47-6.03-13.47-13.47v-21.77c0-7.44,6.03-13.47,13.47-13.47h1020.08
		c7.44,0,13.47,6.03,13.47,13.47v21.77C1205.89,170.84,1199.86,176.87,1192.42,176.87z"/>
            <path className="st0" d="M1192.42,593.5H172.34c-7.44,0-13.47-6.03-13.47-13.47v-18.9c0-7.44,6.03-13.47,13.47-13.47h1020.08
		c7.44,0,13.47,6.03,13.47,13.47v18.9C1205.89,587.47,1199.86,593.5,1192.42,593.5z"/>
            <path className="st1" d="M1163.53,601.84H207.47c-9.37,0-16.97-7.6-16.97-16.97V137.17c0-9.37,7.6-16.97,16.97-16.97h956.07
		c9.37,0,16.97,7.6,16.97,16.97v447.71C1180.5,594.25,1172.9,601.84,1163.53,601.84z"/>
            <g>
              <line className="st2" x1="539.76" y1="173.31" x2="539.76" y2="545.62" />
              <line className="st2" x1="639.24" y1="173.93" x2="639.24" y2="546.25" />
              <line className="st2" x1="937.68" y1="177.04" x2="937.68" y2="549.35" />
              <line className="st2" x1="440.27" y1="174.55" x2="440.27" y2="546.87" />
              <line className="st2" x1="738.72" y1="175.18" x2="738.72" y2="547.49" />
              <line className="st2" x1="340.79" y1="177.66" x2="340.79" y2="549.97" />
              <line className="st2" x1="838.2" y1="172.69" x2="838.2" y2="545" />
              <line className="st2" x1="1136.64" y1="172.07" x2="1136.64" y2="544.38" />
              <line className="st2" x1="241.31" y1="175.8" x2="241.31" y2="548.11" />
              <line className="st2" x1="1037.16" y1="176.42" x2="1037.16" y2="548.73" />
            </g>
            <path className="st3" d="M1151.83,465.29H221.39c-6.6,0-12-5.4-12-12V268.12c0-6.6,5.4-12,12-12h930.44c6.6,0,12,5.4,12,12v185.18
		C1163.83,459.89,1158.43,465.29,1151.83,465.29z"/>
            <path className="st4" d="M725.83,442.82h-64.55c-9.6,0-17.37-7.78-17.37-17.37V289.65c0-9.6,7.78-17.37,17.37-17.37h64.55
		c9.6,0,17.37,7.78,17.37,17.37v135.79C743.21,435.04,735.43,442.82,725.83,442.82z"/>
            <path className="st4" d="M1111.41,442.32h-79.25c-6.6,0-12-5.4-12-12V395.2c0-6.6,5.4-12,12-12h79.25c6.6,0,12,5.4,12,12v35.12
		C1123.41,436.92,1118.01,442.32,1111.41,442.32z"/>
            <g>
              <path className="st5" d="M568.09,423.24c-4.62,0-8.38-3.76-8.38-8.38V300.24c0-4.62,3.76-8.38,8.38-8.38h261.65
			c4.62,0,8.38,3.76,8.38,8.38v114.62c0,4.62-3.76,8.38-8.38,8.38H568.09z"/>
              <path d="M829.73,292.36c4.35,0,7.88,3.54,7.88,7.88v114.62c0,4.35-3.54,7.88-7.88,7.88H568.09c-4.35,0-7.88-3.54-7.88-7.88V300.24
			c0-4.35,3.54-7.88,7.88-7.88H829.73 M829.73,291.36H568.09c-4.91,0-8.88,3.98-8.88,8.88v114.62c0,4.91,3.98,8.88,8.88,8.88h261.65
			c4.91,0,8.88-3.98,8.88-8.88V300.24C838.62,295.33,834.64,291.36,829.73,291.36L829.73,291.36z"/>
            </g>
          </g>
          <g id="ebox1">
            <path className="ebox2" d="M524.83,437.52h-66.97c-6.6,0-12-5.4-12-12V294.66c0-6.6,5.4-12,12-12h66.97c6.6,0,12,5.4,12,12v130.86
		C536.83,432.12,531.43,437.52,524.83,437.52z"/>
            <rect x="452.42" y="291.86" className="st3" width="36.57" height="69.35" />
            <rect x="494.2" y="291.86" className="st3" width="36.57" height="69.35" />
            <rect x="452.52" y="365" className="st3" width="78.54" height="28.8" />
            <rect x="452.75" y="398.16" className="st3" width="78.54" height="28.8" />
          </g>
          <g id="ebox2">
            <path className="ebox1" d="M424.9,436.28h-66.97c-6.6,0-12-5.4-12-12V293.41c0-6.6,5.4-12,12-12h66.97c6.6,0,12,5.4,12,12v130.86
		C436.9,430.88,431.5,436.28,424.9,436.28z"/>
            <rect x="351.86" y="396.83" className="st3" width="79.77" height="30.32" />
            <rect x="351.86" y="362.16" className="st3" width="79.77" height="30.32" />
            <rect x="351.86" y="326.98" className="st3" width="79.77" height="30.32" />
            <rect x="351.86" y="292.05" className="st3" width="79.77" height="30.32" />
          </g>
          <g id="motor_x5F_driver">
            <path className="motor_driver_board" d="M899.15,441.07h-26.14c-6.6,0-12-5.4-12-12V288.02c0-6.6,5.4-12,12-12h26.14
		c6.6,0,12,5.4,12,12v141.05C911.15,435.67,905.75,441.07,899.15,441.07z"/>
          </g>
          <g id="reservoir">
            <circle className="cooling_reservoir" cx="1069.66" cy="323.45" r="50.92" />
          </g>
          <g id="supercaps">
            <path className="st4" d="M995.01,421.46h-58.74c-7.68,0-13.96-6.28-13.96-13.96v-98.4c0-7.68,6.28-13.96,13.96-13.96h58.74
		c7.68,0,13.96,6.28,13.96,13.96v98.4C1008.97,415.18,1002.69,421.46,995.01,421.46z"/>
            <path className="st3" d="M950.99,336.01h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C962.99,330.61,957.59,336.01,950.99,336.01z"/>
            <path className="st3" d="M991.73,336.29h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C1003.73,330.89,998.33,336.29,991.73,336.29z"/>
            <path className="st3" d="M950.99,375.93h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C962.99,370.53,957.59,375.93,950.99,375.93z"/>
            <path className="st3" d="M991.73,376.21h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C1003.73,370.81,998.33,376.21,991.73,376.21z"/>
            <path className="st3" d="M950.99,416.47h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C962.99,411.07,957.59,416.47,950.99,416.47z"/>
            <path className="st3" d="M991.73,416.76h-12.38c-6.6,0-12-5.4-12-12v-12.38c0-6.6,5.4-12,12-12h12.38c6.6,0,12,5.4,12,12v12.38
		C1003.73,411.36,998.33,416.76,991.73,416.76z"/>
            <circle className="st0" cx="935.8" cy="317.82" r="3.41" />
            <circle className="st0" cx="953.04" cy="318.11" r="3.51" />
            <circle className="st0" cx="977.53" cy="317.96" r="3.41" />
            <circle className="st0" cx="994.77" cy="318.25" r="3.51" />
            <circle className="st0" cx="935.85" cy="358.04" r="3.41" />
            <circle className="st0" cx="953.09" cy="358.32" r="3.51" />
            <circle className="st0" cx="976.96" cy="358.98" r="3.41" />
            <circle className="st0" cx="994.21" cy="359.27" r="3.51" />
            <circle className="st0" cx="936.04" cy="398.21" r="3.41" />
            <circle className="st0" cx="953.28" cy="398.49" r="3.51" />
            <circle className="st0" cx="977.15" cy="398.87" r="3.41" />
            <circle className="st0" cx="994.39" cy="399.15" r="3.51" />
          </g>
          <g id="DSLIM">
            <path className="st3" d="M838.54,406.12h-41.55c-2.38,0-4.64,1.03-6.2,2.83l-2.75,3.17h-17.43l-2.56-3.06
		c-1.56-1.86-3.87-2.94-6.3-2.94h-43.99c-2.79,0-5.38,1.41-6.89,3.75l-1.46,2.25h-19.64l-1.43-2.22c-1.51-2.35-4.12-3.78-6.91-3.78
		h-47.56c-2.32,0-4.54,0.98-6.09,2.71l-2.98,3.29h-16.41l-2.33-2.92c-1.56-1.95-3.92-3.08-6.41-3.08h-40.48V366.8h279.39V406.12z"/>
            <rect x="566.02" y="366.32" className="dslim_port" width="49.65" height="12.71" />
            <rect x="559.27" y="353" className="st3" width="279.3" height="10.45" />
            <rect x="586.04" y="378.01" className="dslim_port" width="49.65" height="12.71" />
            <rect x="606.35" y="389.72" className="dslim_port" width="49.65" height="12.71" />
            <rect x="623.64" y="366.32" className="dslim_port" width="49.65" height="12.71" />
            <rect x="643.66" y="378.01" className="dslim_port" width="49.65" height="12.71" />
            <rect x="663.97" y="389.72" className="dslim_port" width="49.65" height="12.71" />
            <rect x="681.64" y="366.32" className="dslim_port" width="49.65" height="12.71" />
            <rect x="701.66" y="378.01" className="dslim_port" width="49.65" height="12.71" />
            <rect x="721.97" y="389.72" className="dslim_port" width="49.65" height="12.71" />
            <rect x="740.05" y="366.32" className="dslim_port" width="49.65" height="12.71" />
            <rect x="760.06" y="378.01" className="dslim_port" width="49.65" height="12.71" />
            <rect x="780.37" y="389.72" className="dslim_port" width="49.65" height="12.71" />
            <circle cx="610.77" cy="408.36" r="1.17" />
            <circle cx="622.65" cy="408.17" r="1.17" />
            <circle cx="693.75" cy="408.53" r="1.17" />
            <circle cx="705.62" cy="408.34" r="1.17" />
            <circle cx="773.52" cy="408.63" r="1.17" />
            <circle cx="785.39" cy="408.44" r="1.17" />
            <path className="st3" d="M838.62,309.91h-41.55c-2.38,0-4.64-1.03-6.2-2.83l-2.75-3.17h-17.43l-2.56,3.06
		c-1.56,1.86-3.87,2.94-6.3,2.94h-43.99c-2.79,0-5.38-1.41-6.89-3.75l-1.46-2.25h-19.64l-1.43,2.22c-1.51,2.35-4.12,3.78-6.91,3.78
		h-47.56c-2.32,0-4.54-0.98-6.09-2.71l-2.98-3.29h-16.41l-2.33,2.92c-1.56,1.95-3.92,3.08-6.41,3.08h-40.48v39.32h279.39V309.91z"/>
            <rect x="566.1" y="337.01" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="586.12" y="325.31" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="606.43" y="313.6" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="623.73" y="337.01" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="643.75" y="325.31" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="664.06" y="313.6" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="681.73" y="337.01" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="701.74" y="325.31" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="722.05" y="313.6" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="740.13" y="337.01" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="760.15" y="325.31" className="dslim_starboard" width="49.65" height="12.71" />
            <rect x="780.46" y="313.6" className="dslim_starboard" width="49.65" height="12.71" />
            <circle cx="610.86" cy="307.67" r="1.17" />
            <circle cx="622.73" cy="307.86" r="1.17" />
            <circle cx="693.83" cy="307.49" r="1.17" />
            <circle cx="705.71" cy="307.68" r="1.17" />
            <circle cx="773.6" cy="307.4" r="1.17" />
            <circle cx="785.48" cy="307.59" r="1.17" />
          </g>
          <g id="Layer_11">
          </g>
          <g id="Layer_3">
          </g>
          <g id="mlus">
            <path className="st6" d="M352.32,241.2" />
            <path className="st6" d="M344.87,240.56" />
            <path className="st3" d="M463.39,239.64l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18v-69.63c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C482.67,235.93,472.68,242.92,463.39,239.64z"/>
            <path className="st4" d="M441.56,223.49h-98.39c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.06,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C443.3,223.2,442.46,223.49,441.56,223.49z"/>
            <rect x="309.37" y="174.77" className="st3" width="32.59" height="28.79" />
            <rect x="442.37" y="174.77" className="st3" width="34" height="28.79" />
            <rect x="462.37" y="178.09" className="st7" width="10.58" height="21.71" />
            <rect x="313.03" y="178.09" className="st7" width="10.33" height="21.71" />
            <path id="XMLID_00000025420474694617434220000010280258879107864983_" className="mlu1" d="M428.88,183.51h-72.78
		c-5.4,0-9.78-5.17-9.78-11.55V160.8c0-6.38,4.38-11.55,9.78-11.55h72.78c5.4,0,9.78,5.17,9.78,11.55v11.15
		C438.65,178.33,434.28,183.51,428.88,183.51z"/>
            <path className="mlu1" d="M428.69,227.09H355.9c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C438.46,221.91,434.09,227.09,428.69,227.09z"/>
            <path className="st3" d="M426.78,176.85h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C431.2,174.86,429.21,176.85,426.78,176.85z"/>
            <path className="st3" d="M426.59,220.43h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C431.01,218.44,429.02,220.43,426.59,220.43z"/>
            <ellipse className="st7" cx="423.49" cy="166.47" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="361.02" cy="166.47" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="423.31" cy="210.05" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="360.83" cy="210.05" rx="2.25" ry="2.49" />
            <circle className="st4" cx="469.37" cy="150.87" r="8.86" />
            <circle className="st7" cx="469.37" cy="150.87" r="2.39" />
            <circle className="st4" cx="469.18" cy="227.53" r="8.86" />
            <circle className="st7" cx="469.18" cy="227.53" r="2.39" />
            <circle className="st4" cx="318.2" cy="228.1" r="8.86" />
            <circle className="st7" cx="318.2" cy="228.1" r="2.39" />
            <circle className="st4" cx="318.2" cy="151.37" r="8.86" />
            <circle className="st7" cx="318.2" cy="151.37" r="2.39" />
            <path className="st3" d="M758.75,240.09l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18V154.8c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C778.03,236.38,768.04,243.37,758.75,240.09z"/>
            <path className="st4" d="M736.92,223.94h-98.39c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.05,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C738.66,223.65,737.82,223.94,736.92,223.94z"/>
            <rect x="604.72" y="175.22" className="st3" width="32.59" height="28.79" />
            <rect x="737.72" y="175.22" className="st3" width="34" height="28.79" />
            <rect x="757.72" y="178.54" className="st7" width="10.58" height="21.71" />
            <rect x="608.39" y="178.54" className="st7" width="10.33" height="21.71" />
            <path className="mlu2" d="M724.23,183.95h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C734.01,178.78,729.63,183.95,724.23,183.95z"/>
            <path className="mlu2" d="M724.04,227.53h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C733.82,222.36,729.44,227.53,724.04,227.53z"/>
            <path className="st3" d="M722.13,177.3h-68.96c-2.43,0-4.42-1.99-4.42-4.42V161.1c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C726.56,175.31,724.57,177.3,722.13,177.3z"/>
            <path className="st3" d="M721.94,220.88h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C726.37,218.89,724.38,220.88,721.94,220.88z"/>
            <ellipse className="st7" cx="718.85" cy="166.92" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="656.38" cy="166.92" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="718.66" cy="210.5" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="656.19" cy="210.5" rx="2.25" ry="2.49" />
            <circle className="st4" cx="764.73" cy="151.32" r="8.86" />
            <circle className="st7" cx="764.73" cy="151.32" r="2.39" />
            <circle className="st4" cx="764.54" cy="227.98" r="8.86" />
            <circle className="st7" cx="764.54" cy="227.98" r="2.39" />
            <circle className="st4" cx="613.56" cy="228.55" r="8.86" />
            <circle className="st7" cx="613.56" cy="228.55" r="2.39" />
            <circle className="st4" cx="613.56" cy="151.82" r="8.86" />
            <circle className="st7" cx="613.56" cy="151.82" r="2.39" />
            <path className="st3" d="M1057.07,240.09l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18v-69.63c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C1076.35,236.38,1066.36,243.37,1057.07,240.09z"/>
            <path className="st4" d="M1035.24,223.93h-98.39c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.06,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C1036.98,223.65,1036.14,223.93,1035.24,223.93z"/>
            <rect x="903.05" y="175.22" className="st8" width="32.59" height="28.79" />
            <rect x="1036.05" y="175.22" className="st8" width="34" height="28.79" />
            <rect x="1056.05" y="178.54" className="st7" width="10.58" height="21.71" />
            <rect x="906.71" y="178.54" className="st7" width="10.33" height="21.71" />
            <path className="mlu3" d="M1022.56,183.95h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C1032.33,178.78,1027.96,183.95,1022.56,183.95z"/>
            <path className="mlu3" d="M1022.37,227.53h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C1032.14,222.36,1027.77,227.53,1022.37,227.53z"/>
            <path className="st3" d="M1020.46,177.29h-68.96c-2.43,0-4.42-1.99-4.42-4.42V161.1c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C1024.88,175.3,1022.89,177.29,1020.46,177.29z"/>
            <path className="st3" d="M1020.27,220.88h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C1024.69,218.88,1022.7,220.88,1020.27,220.88z"/>
            <ellipse className="st7" cx="1017.18" cy="166.92" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="954.71" cy="166.92" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="1016.99" cy="210.5" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="954.52" cy="210.5" rx="2.25" ry="2.49" />
            <circle className="st4" cx="1063.05" cy="151.32" r="8.86" />
            <circle className="st7" cx="1063.05" cy="151.32" r="2.39" />
            <circle className="st4" cx="1062.86" cy="227.98" r="8.86" />
            <circle className="st7" cx="1062.86" cy="227.98" r="2.39" />
            <circle className="st4" cx="911.88" cy="228.55" r="8.86" />
            <circle className="st7" cx="911.88" cy="228.55" r="2.39" />
            <circle className="st4" cx="911.88" cy="151.81" r="8.86" />
            <circle className="st7" cx="911.88" cy="151.81" r="2.39" />
            <path className="st3" d="M463.82,583.83l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18v-69.63c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C483.1,580.12,473.11,587.11,463.82,583.83z"/>
            <path className="st4" d="M441.98,567.68H343.6c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.06,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C443.72,567.39,442.88,567.68,441.98,567.68z"/>
            <rect x="309.79" y="518.96" className="st3" width="32.59" height="28.79" />
            <rect x="442.79" y="518.96" className="st3" width="34" height="28.79" />
            <rect x="462.79" y="522.28" className="st7" width="10.58" height="21.71" />
            <rect x="313.46" y="522.28" className="st7" width="10.33" height="21.71" />
            <path className="mlu4" d="M429.3,527.69h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C439.08,522.52,434.7,527.69,429.3,527.69z"/>
            <path className="mlu4" d="M429.11,571.28h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C438.89,566.1,434.51,571.28,429.11,571.28z"/>
            <path className="st3" d="M427.2,521.04h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C431.62,519.05,429.63,521.04,427.2,521.04z"/>
            <path className="st3" d="M427.01,564.62h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C431.44,562.63,429.44,564.62,427.01,564.62z"/>
            <ellipse className="st7" cx="423.92" cy="510.66" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="361.45" cy="510.66" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="423.73" cy="554.24" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="361.26" cy="554.24" rx="2.25" ry="2.49" />
            <circle className="st4" cx="469.8" cy="495.06" r="8.86" />
            <circle className="st7" cx="469.8" cy="495.06" r="2.39" />
            <circle className="st8" cx="469.61" cy="571.72" r="8.86" />
            <circle className="st7" cx="469.61" cy="571.72" r="2.39" />
            <circle className="st4" cx="318.62" cy="572.29" r="8.86" />
            <circle className="st7" cx="318.62" cy="572.29" r="2.39" />
            <circle className="st4" cx="318.62" cy="495.56" r="8.86" />
            <circle className="st7" cx="318.62" cy="495.56" r="2.39" />
            <path className="st3" d="M759.17,584.28l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18v-69.63c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C778.45,580.57,768.46,587.56,759.17,584.28z"/>
            <path className="st4" d="M737.34,568.13h-98.39c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.05,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C739.08,567.84,738.24,568.13,737.34,568.13z"/>
            <rect x="605.15" y="519.41" className="st3" width="32.59" height="28.79" />
            <rect x="738.15" y="519.41" className="st3" width="34" height="28.79" />
            <rect x="758.15" y="522.73" className="st7" width="10.58" height="21.71" />
            <rect x="608.81" y="522.73" className="st7" width="10.33" height="21.71" />
            <path className="mlu5" d="M724.66,528.14h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C734.44,522.97,730.06,528.14,724.66,528.14z"/>
            <path className="mlu5" d="M724.47,571.72h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C734.25,566.55,729.87,571.72,724.47,571.72z"/>
            <path className="st3" d="M722.56,521.49H653.6c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C726.98,519.5,724.99,521.49,722.56,521.49z"/>
            <path className="st3" d="M722.37,565.07h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C726.79,563.08,724.8,565.07,722.37,565.07z"/>
            <ellipse className="st7" cx="719.28" cy="511.11" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="656.81" cy="511.11" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="719.09" cy="554.69" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="656.62" cy="554.69" rx="2.25" ry="2.49" />
            <circle className="st4" cx="765.16" cy="495.51" r="8.86" />
            <circle className="st7" cx="765.16" cy="495.51" r="2.39" />
            <circle className="st4" cx="764.97" cy="572.17" r="8.86" />
            <circle className="st7" cx="764.97" cy="572.17" r="2.39" />
            <circle className="st4" cx="613.98" cy="572.74" r="8.86" />
            <circle className="st7" cx="613.98" cy="572.74" r="2.39" />
            <circle className="st4" cx="613.98" cy="496.01" r="8.86" />
            <circle className="st7" cx="613.98" cy="496.01" r="2.39" />
            <path className="st3" d="M1057.5,584.28l-9.99-3.53c-5-1.76-10.21-2.66-15.45-2.66h-92.9c-4.09,0-8.15,0.8-11.99,2.37l-8.31,3.4
		c-9.31,3.81-19.68-3.1-20.35-14.06c-0.02-0.39-0.04-0.78-0.04-1.18v-69.63c0-0.4,0.01-0.79,0.04-1.18
		c0.64-10.55,10.19-17.6,19.43-14.9l10.16,2.97c3.24,0.95,6.57,1.43,9.92,1.43h97.08c3.24,0,6.47-0.4,9.63-1.2l13.81-3.48
		c6.86-1.73,14.13,1.69,17.29,8.65c1.05,2.32,1.64,4.94,1.64,7.71v69.63c0,0.4-0.01,0.79-0.04,1.18
		C1076.78,580.57,1066.79,587.56,1057.5,584.28z"/>
            <path className="st4" d="M1035.67,568.12h-98.39c-0.72,0-1.4-0.18-2.01-0.51c-6.95-3.76-14.04-7.19-21.61-8.96l-15.11-3.52v-43.07
		l14.75-3.74c7.54-1.91,15.01-4.59,21.53-9.17c0.71-0.5,1.55-0.78,2.45-0.78h98.39c0.9,0,1.74,0.29,2.45,0.78
		c4.68,3.28,9.63,6.08,15.05,7.4l24.24,5.9v40.6l-16.99,4.59c-7.8,2.1-15.53,4.95-22.31,9.7
		C1037.41,567.84,1036.57,568.12,1035.67,568.12z"/>
            <rect x="903.47" y="519.41" className="st3" width="32.59" height="28.79" />
            <rect x="1036.47" y="519.41" className="st3" width="34" height="28.79" />
            <rect x="1056.47" y="522.73" className="st7" width="10.58" height="21.71" />
            <rect x="907.14" y="522.73" className="st7" width="10.33" height="21.71" />
            <path className="mlu6" d="M1022.98,528.14H950.2c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C1032.76,522.97,1028.38,528.14,1022.98,528.14z"/>
            <path className="mlu6" d="M1022.79,571.72h-72.78c-5.4,0-9.78-5.17-9.78-11.55v-11.15c0-6.38,4.38-11.55,9.78-11.55h72.78
		c5.4,0,9.78,5.17,9.78,11.55v11.15C1032.57,566.55,1028.19,571.72,1022.79,571.72z"/>
            <path className="st3" d="M1020.88,521.48h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C1025.31,519.49,1023.32,521.48,1020.88,521.48z"/>
            <path className="st3" d="M1020.69,565.07h-68.96c-2.43,0-4.42-1.99-4.42-4.42v-11.77c0-2.43,1.99-4.42,4.42-4.42h68.96
		c2.43,0,4.42,1.99,4.42,4.42v11.77C1025.12,563.07,1023.13,565.07,1020.69,565.07z"/>
            <ellipse className="st7" cx="1017.6" cy="511.1" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="955.13" cy="511.1" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="1017.41" cy="554.69" rx="2.25" ry="2.49" />
            <ellipse className="st7" cx="954.94" cy="554.69" rx="2.25" ry="2.49" />
            <circle className="st4" cx="1063.48" cy="495.51" r="8.86" />
            <circle className="st7" cx="1063.48" cy="495.51" r="2.39" />
            <circle className="st4" cx="1063.29" cy="572.17" r="8.86" />
            <circle className="st7" cx="1063.29" cy="572.17" r="2.39" />
            <circle className="st4" cx="912.31" cy="572.74" r="8.86" />
            <circle className="st7" cx="912.31" cy="572.74" r="2.39" />
            <circle className="st4" cx="912.31" cy="496" r="8.86" />
            <circle className="st7" cx="912.31" cy="496" r="2.39" />
          </g>
        </svg>
      </Stack>
    </Paper>
  );
}

export default TemperatureVis;
