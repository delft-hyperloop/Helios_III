

import { Paper, Stack, Typography, useTheme } from "@mui/material";
import "./StateVis.css"
import { invoke } from "@tauri-apps/api";
import { listen } from "@tauri-apps/api/event";
import { ObjectEntryListenLatestResponse } from "../../object_entry/types/events/ObjectEntryListenLatestResponse";
import { ObjectEntryEvent } from "../../object_entry/types/events/ObjectEntryEvent";
import { useEffect } from "react";


const MLU_OE = { nodeName: "levitation_board1", objectEntryName: "state" };
const MGU_OE = { nodeName: "guidance_board_front", objectEntryName: "state" };
const DSLIM_OE = { nodeName: "motor_driver", objectEntryName: "state" };
const STATE_OE = { nodeName: "mother_board", objectEntryName: "state" };
const AIRGAP_OE = { nodeName: "levitation_board1", objectEntryName: "airgap_left" };


interface OeId {
  nodeName: string,
  objectEntryName: string,
}

async function registerOe(oe: OeId, property: string, element: HTMLElement, color: (_: string) => string) {
  const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", oe as any);
  if (resp.latest !== undefined && resp.latest !== null) {
    element.style.setProperty(property, color(resp.latest.value as string));
  }
  const unlistenJs = await listen<ObjectEntryEvent>(resp.event_name, event => {
    element.style.setProperty(property, color(event.payload.value as string));
  });

  return () => {
    unlistenJs();
    invoke("unlisten_from_latest_object_entry_value", oe as any);
  }
}

function StateVis() {

  const theme = useTheme();

  useEffect(() => {
    const svg = document.getElementById("state_vis")!;
    let cleanup: (Promise<() => void>)[] = [];

    cleanup.push(registerOe(MLU_OE, "--mlu_state", svg, state => {
      switch (state) {
        case "INIT": return theme.palette.stateInit.main;
        case "IDLE": return theme.palette.stateIdle.main;
        case "ARMING45": return theme.palette.subStateArm.main;
        case "PRECHARGE": return theme.palette.subStateArm.main;
        case "READY": return theme.palette.subStateReady.main;
        case "START": return theme.palette.subStateStart.main;
        case "CONTROL": return theme.palette.subStateControl.main;
        case "STOP": return theme.palette.subStateStop.main;
        case "DISARMING45": return theme.palette.subStateDisarm.main;
        default : return theme.palette.subStateOther.main;
      }
    }));
    cleanup.push(registerOe(MGU_OE, "--mgu_state", svg, state => {
      switch (state) {
        case "INIT": return theme.palette.stateInit.main;
        case "IDLE": return theme.palette.stateIdle.main;
        case "ARMING45": return theme.palette.subStateArm.main;
        case "PRECHARGE": return theme.palette.subStateArm.main;
        case "READY": return theme.palette.subStateReady.main;
        case "START": return theme.palette.subStateStart.main;
        case "CONTROL": return theme.palette.subStateControl.main;
        case "STOP": return theme.palette.subStateStop.main;
        case "DISARMING45": return theme.palette.subStateDisarm.main;
        default : return theme.palette.subStateOther.main;
      }
    }));
    cleanup.push(registerOe(DSLIM_OE, "--dslim_state", svg, state => {
      switch (state) {
        case "INIT": return theme.palette.stateInit.main;
        case "IDLE": return theme.palette.stateIdle.main;
        case "ARMING45": return theme.palette.subStateArm.main;
        case "PRECHARGE": return theme.palette.subStateArm.main;
        case "READY": return theme.palette.subStateReady.main;
        case "START": return theme.palette.subStateStart.main;
        case "CONTROL": return theme.palette.subStateControl.main;
        case "STOP": return theme.palette.subStateStop.main;
        case "DISARMING45": return theme.palette.subStateDisarm.main;
        default : return theme.palette.subStateOther.main;
      }
    }));
    cleanup.push(registerOe(STATE_OE, "--global_state", svg, state => {
      switch (state) {
        case "INIT": return theme.palette.stateInit.main;
        case "IDLE": return theme.palette.stateIdle.main;
        case "ARMING45": return theme.palette.stateArming45.main;
        case "PRECHARGE": return theme.palette.statePrecharge.main;
        case "DISARMING45": return theme.palette.stateDisarming45.main;
        case "READY": return theme.palette.stateReady.main;
        case "START_LEVITATION": return theme.palette.stateStartLevitation.main
        case "LEVITATION_STABLE" : return theme.palette.stateLevitation.main;
        case "START_GUIDANCE": return theme.palette.stateStartGuidance.main;
        case "GUIDANCE_STABLE": return theme.palette.stateGuidance.main;
        case "ACCELERATION": return theme.palette.stateAccelerate.main;
        case "CONTROLLER" : return theme.palette.stateController.main;
        case "CRUISING": return theme.palette.stateCruising.main;
        case "DECELERATE": return theme.palette.stateDeceleration.main;
        case "STOP_LEVITATION": return theme.palette.stateStopLevitation.main;
        case "STOP_GUIDANCE": return theme.palette.stateStopGuidance.main;
        case "SHUTDOWN": return theme.palette.stateShutdown.main;
        case "RESTARTING": return theme.palette.stateRestarting.main;
        case "CALIBRATING": return theme.palette.stateCalibrating.main;
        default: return theme.palette.disconnected.main;
      }
    }));


    async function setupAirgap() {
      const resp = await invoke<ObjectEntryListenLatestResponse>("listen_to_latest_object_entry_value", AIRGAP_OE);
      if (resp.latest !== undefined && resp.latest !== null) {
        const airgap = resp.latest.value as number; // [6 - 12];
        const offset = ((airgap - 12.0) / 6.0) * 10;
        svg.style.setProperty("--air_gap", `${offset}px`);
      }
      const unlistenJs = await listen<ObjectEntryEvent>(resp.event_name, event => {
        const airgap = event.payload.value as number; // [6 - 12];
        const offset = ((airgap - 12.0) / 6.0) * 24;
        svg.style.setProperty("--air_gap", `${offset}px`);
      });
      return () => {
        unlistenJs();
        invoke("unlisten_from_latest_object_entry_value", AIRGAP_OE);
      }
    }
    cleanup.push(setupAirgap());



    return () => {
      cleanup.forEach(p => p.then(f => f()).catch(console.error));
    };

  }, []);

  return (
    <Paper sx={{
      width: "50%",
      padding: 1,
    }}>
      <Stack>
        <Typography
          style={{
            textAlign: "center",
          }}
          variant="h5"
        >
          State
        </Typography>
        <svg
          version="1.1"
          id="state_vis"
          xmlns="http://www.w3.org/2000/svg"
          x="0px"
          y="0px"
          viewBox="250 100 850 518"
        >
          <g id="pod">
            <rect x="601.5" y="183.7" className="st0" width="168.2" height="87.9" />
            <path className="st1" d="M603.1,255.4h-16.3c-4.8,0-8.6-3.9-8.6-8.6v-10.5c0-4.8,3.9-8.6,8.6-8.6h16.3c4.8,0,8.6,3.9,8.6,8.6v10.5
		C611.7,251.5,607.8,255.4,603.1,255.4z"/>
            <path className="st1" d="M651.5,255.7h-18.8c-4,0-7.2-3.2-7.2-7.2v-13.4c0-4,3.2-7.2,7.2-7.2h18.8c4,0,7.2,3.2,7.2,7.2v13.4
		C658.7,252.4,655.5,255.7,651.5,255.7z"/>
            <path className="st1" d="M785.7,255.9h-20.1c-3.6,0-6.5-2.9-6.5-6.5v-15.2c0-3.6,2.9-6.5,6.5-6.5h20.1c3.6,0,6.5,2.9,6.5,6.5v15.2
		C792.3,253,789.3,255.9,785.7,255.9z"/>
            <rect x="797.8" y="321.1" className="st0" width="19.7" height="79.6" />
            <rect x="538.6" y="291.5" className="st0" width="38.7" height="110.4" />
            <rect x="650.2" y="197" className="st0" width="98.2" height="71.1" />
            <rect x="559.4" y="247.7" className="st0" width="250.5" height="156.2" />
            <rect x="604.1" y="270.1" className="st0" width="165.2" height="84" />
            <rect x="583.3" y="288.3" className="global_state" width="205.8" height="113.9" />
            <rect x="349.5" y="464.2" className="st2" width="55" height="96.1" />
            <line className="st3" x1="403.2" y1="477" x2="349" y2="477" />
            <line className="st3" x1="403.2" y1="489.2" x2="349" y2="489.2" />
            <line className="st3" x1="403.2" y1="501.3" x2="349" y2="501.3" />
            <line className="st3" x1="403.2" y1="513.5" x2="349" y2="513.5" />
            <line className="st3" x1="403.2" y1="525.6" x2="349" y2="525.6" />
            <line className="st3" x1="403.2" y1="549.9" x2="349" y2="549.9" />
            <line className="st3" x1="403.2" y1="537.8" x2="349" y2="537.8" />
            <rect x="394.1" y="381.9" className="st0" width="34.7" height="19" />
            <rect x="341.1" y="353.9" className="st0" width="142.2" height="21.7" />
            <rect x="360.3" y="326.7" className="mlu" width="36" height="75.2" />
            <rect x="428.1" y="326.5" className="mlu" width="36" height="74.3" />
            <rect x="337" y="339.7" className="st0" width="151.8" height="17.3" />
            <path className="st0" d="M439.9,362.8h15.4c1.5,0,2.8-1.2,2.8-2.8v-8.8c0-1.5-1.2-2.8-2.8-2.8h-15.4c-1.5,0-2.8,1.2-2.8,2.8v8.8
		C437.1,361.5,438.4,362.8,439.9,362.8z"/>
            <rect x="394.7" y="339.7" className="st0" width="35.1" height="5.1" />
            <rect x="345.6" y="377.1" className="st0" width="31.1" height="63.3" />
            <rect x="451.2" y="378.8" className="st0" width="29.8" height="58" />
            <path className="mgu" d="M337.7,544.4h9.4v-58.7h-9.1c-1.6,0-2.9,1.3-2.9,2.9v53.4C335.2,543.3,336.3,544.4,337.7,544.4z" />
            <path className="mgu" d="M334.8,523.4h11c1.5,0,2.7-1.2,2.7-2.7v-11.5c0-1.5-1.2-2.7-2.7-2.7h-11c-1.5,0-2.7,1.2-2.7,2.7v11.5
		C332.1,522.2,333.3,523.4,334.8,523.4z"/>
            <rect x="346.8" y="445.6" className="st0" width="58.7" height="20" />
            <polygon className="st0" points="407,571.9 420.1,572.1 448.3,471.1 406.4,464.5 	" />
            <polygon className="st0" points="448.1,476.2 553.3,477.1 553.3,404.9 504.8,404.9 406.6,444.6 406.4,466.7 	" />
            <rect x="346.4" y="561" className="st0" width="57.4" height="19.2" />
            <rect x="403.8" y="445.2" className="st0" width="3.4" height="135.2" />
            <rect x="373.6" y="454.9" className="st0" width="3.4" height="116.1" />
            <rect x="345.5" y="443.4" className="st0" width="3.4" height="136.8" />
            <path className="st0" d="M331.9,445.2H542c1.7,0,3.2-1.4,3.2-3.2v-0.9c0-1.7-1.4-3.2-3.2-3.2H331.9V445.2z" />
            <rect x="402.1" y="330" className="st0" width="20.3" height="25.2" />
            <rect x="337.7" y="369.7" className="st0" width="150.8" height="15.9" />
            <rect x="426.3" y="337.3" className="st0" width="5.9" height="61" />
            <rect x="392.2" y="337.4" className="st0" width="5.1" height="60.9" />
            <path className="st0" d="M343.4,408.6h140.8c2.1,0,3.8-1.7,3.8-3.8v-2.8c0-2.1-1.7-3.8-3.8-3.8H343.4c-2.1,0-3.8,1.7-3.8,3.8v2.8
		C339.6,406.9,341.2,408.6,343.4,408.6z"/>
            <circle className="st4" cx="447.6" cy="355.7" r="4.9" />
            <path className="st0" d="M367.8,362.7h15.4c1.5,0,2.8-1.2,2.8-2.8v-8.8c0-1.5-1.2-2.8-2.8-2.8h-15.4c-1.5,0-2.8,1.2-2.8,2.8v8.8
		C365,361.5,366.3,362.7,367.8,362.7z"/>
            <circle className="st4" cx="375.5" cy="355.6" r="4.9" />
            <path className="st0" d="M352.8,594.2h47.1c4,0,7.2-3.2,7.2-7.2v-7.2h-61.6v7.2C345.5,590.9,348.8,594.2,352.8,594.2z" />
            <rect x="966.3" y="463.3" className="st2" width="55" height="96.1" />
            <line className="st3" x1="967.5" y1="476.1" x2="1021.7" y2="476.1" />
            <line className="st3" x1="967.5" y1="488.3" x2="1021.7" y2="488.3" />
            <line className="st3" x1="967.5" y1="500.4" x2="1021.7" y2="500.4" />
            <line className="st3" x1="967.5" y1="512.6" x2="1021.7" y2="512.6" />
            <line className="st3" x1="967.5" y1="524.7" x2="1021.7" y2="524.7" />
            <line className="st3" x1="967.5" y1="549" x2="1021.7" y2="549" />
            <line className="st3" x1="967.5" y1="536.9" x2="1021.7" y2="536.9" />
            <rect x="941" y="381" className="st0" width="34.7" height="19" />
            <rect x="886.5" y="353" className="st0" width="142.2" height="21.7" />
            <rect x="974.5" y="325.8" className="mlu" width="36" height="75.2" />
            <rect x="905.6" y="325.6" className="mlu" width="36" height="74.3" />
            <rect x="880.9" y="338.8" className="st0" width="151.8" height="17.3" />
            <path className="st0" d="M930.9,362.9h-15.4c-1.5,0-2.8-1.2-2.8-2.8v-8.8c0-1.5,1.2-2.8,2.8-2.8h15.4c1.5,0,2.8,1.2,2.8,2.8v8.8
		C933.6,361.6,932.4,362.9,930.9,362.9z"/>
            <rect x="939.9" y="338.8" className="st0" width="35.2" height="5.1" />
            <rect x="993.1" y="376.2" className="st0" width="31.1" height="61.9" />
            <rect x="888.8" y="377.9" className="st0" width="29.8" height="58" />
            <path className="mgu" d="M1033.1,543.5h-9.4v-58.7h9.1c1.6,0,2.9,1.3,2.9,2.9V541C1035.6,542.4,1034.4,543.5,1033.1,543.5z" />
            <path className="mgu" d="M1036,522.5h-11c-1.5,0-2.7-1.2-2.7-2.7v-11.5c0-1.5,1.2-2.7,2.7-2.7h11c1.5,0,2.7,1.2,2.7,2.7v11.5
		C1038.7,521.3,1037.5,522.5,1036,522.5z"/>
            <rect x="965.3" y="441.4" className="st0" width="58.7" height="23.2" />
            <polygon className="st0" points="963.8,571 950.7,571.2 922.4,470.2 964.3,463.6 	" />
            <path className="st0" d="M902.3,532.2h-5.2v-64.4h23.8v38.5c0,1.4-0.4,2.8-1.1,4l-10.6,18C907.7,530.8,905.1,532.2,902.3,532.2z" />
            <path className="st0" d="M867.7,532.4h5.2V468h-23.8v38.5c0,1.4,0.4,2.8,1.1,4l10.6,18C862.3,530.9,864.9,532.4,867.7,532.4z" />
            <polygon className="st0" points="922.7,475.3 817.5,476.2 817.5,404 866,404 964.1,443.7 964.4,465.8 	" />
            <path className="st0" d="M651.3,575.2h16.6c2.9,0,5.3-2.4,5.3-5.3v-5h-35l9.5,8.8C648.7,574.6,649.9,575.2,651.3,575.2z" />
            <rect x="621.2" y="484.6" className="st0" width="17.3" height="9.2" />
            <path className="st0" d="M638.6,564.8h-4.8c-2.2,0-3.9-1.8-3.9-3.9v-76.5h8.8V564.8z" />
            <path className="st0" d="M675,484.6h-69.7v-18.2c0-2.9-1.4-5.5-3.8-7.1l-6.2-4.2H675V484.6z" />
            <rect x="781.6" y="453.8" className="st0" width="8" height="24.6" />
            <rect x="582.2" y="453.7" className="st0" width="8" height="24.6" />
            <rect x="570.8" y="446.7" className="st0" width="227.9" height="8.5" />
            <rect x="552.6" y="408.7" className="st0" width="6.1" height="93" />
            <rect x="811.4" y="408.6" className="st0" width="6.1" height="93" />
            <rect x="558.5" y="400.2" className="st0" width="253.9" height="49.3" />
            <path className="st0" d="M811,446.2H559.4c-2.1,0-3.8-1.7-3.8-3.9v-6l1.8-1.6c0.5-0.5,0.8-1.1,0.8-1.8l0.1-4.7c0-0.7-0.3-1.4-0.8-1.9
		l-1.9-1.9v-5.8c0-2.1,1.7-3.9,3.8-3.9H811c2.1,0,3.8,1.7,3.8,3.9v6l-2,1.5c-0.7,0.5-1.1,1.3-1.1,2.1v3.6c0,0.8,0.4,1.6,1,2.1l2,1.6
		v6.6C814.8,444.5,813.1,446.2,811,446.2z"/>
            <rect x="520.6" y="400" className="st0" width="326.9" height="8.6" />
            <rect x="639.2" y="460.2" className="st0" width="32.6" height="19.1" />
            <rect x="608.3" y="460.2" className="st4" width="4.5" height="19.2" />
            <rect x="615.3" y="460.1" className="st4" width="4.6" height="19.2" />
            <rect x="622.3" y="460.2" className="st4" width="5.1" height="19.2" />
            <rect x="630.4" y="460.2" className="st3" width="5.1" height="19.2" />
            <path d="M651.9,460.2c0.4,0.8,0.7,1.8,0.7,2.8c0,3-2.1,5.5-4.7,5.5s-4.7-2.4-4.7-5.5c0-1.1,0.3-2,0.7-2.9" />
            <path d="M666.6,460.6c0.4,0.8,0.7,1.7,0.7,2.7c0,2.9-2.1,5.2-4.7,5.2s-4.7-2.3-4.7-5.2c0-1,0.3-2,0.7-2.8" />
            <path d="M644,478.9c-0.4-0.8-0.7-1.7-0.7-2.6c0-2.8,2.1-5.1,4.7-5.1s4.7,2.3,4.7,5.1c0,1-0.3,1.9-0.7,2.7" />
            <path d="M658.7,479.1c-0.4-0.8-0.7-1.7-0.7-2.7c0-2.9,2.1-5.2,4.7-5.2s4.7,2.3,4.7,5.2c0,1-0.3,2-0.7,2.8" />
            <rect x="638.7" y="484.7" className="motor" width="34.5" height="80.1" />
            <path className="st0" d="M721,575.3h-17c-2.3,0-4.2-1.9-4.2-4.2V565h33.9l-8,8.3C724.5,574.6,722.8,575.3,721,575.3z" />
            <rect x="734.5" y="484.7" className="st0" width="17.3" height="9.2" />
            <path className="st0" d="M734.3,564.9h4.9c2.1,0,3.8-1.7,3.8-3.8v-76.6h-8.8L734.3,564.9L734.3,564.9z" />
            <path className="st0" d="M698,484.7h69.7v-18.2c0-2.9,1.4-5.5,3.8-7.1l6.2-4.2H698V484.7z" />
            <rect x="701.2" y="460.3" className="st0" width="32.6" height="19.1" />
            <rect x="760.1" y="460.3" className="st4" width="4.5" height="19.2" />
            <rect x="753" y="460.2" className="st4" width="4.6" height="19.2" />
            <rect x="745.6" y="460.3" className="st4" width="5.1" height="19.2" />
            <rect x="737.5" y="460.3" className="st3" width="5.1" height="19.2" />
            <path d="M721,460.4c-0.4,0.8-0.7,1.8-0.7,2.8c0,3,2.1,5.5,4.7,5.5s4.7-2.4,4.7-5.5c0-1.1-0.3-2-0.7-2.9" />
            <path d="M706.3,460.8c-0.4,0.8-0.7,1.7-0.7,2.7c0,2.9,2.1,5.2,4.7,5.2s4.7-2.3,4.7-5.2c0-1-0.3-2-0.7-2.8" />
            <path d="M729,479c0.4-0.8,0.7-1.7,0.7-2.6c0-2.8-2.1-5.1-4.7-5.1s-4.7,2.3-4.7,5.1c0,1,0.3,1.9,0.7,2.7" />
            <path d="M714.3,479.2c0.4-0.8,0.7-1.7,0.7-2.7c0-2.9-2.1-5.2-4.7-5.2s-4.7,2.3-4.7,5.2c0,1,0.3,2,0.7,2.8" />
            <rect x="699.8" y="484.8" className="motor" width="34.5" height="80.1" />
            <path className="st0" d="M862.4,529.2" />
            <rect x="967" y="560.2" className="st0" width="57.4" height="21.1" />
            <rect x="963.6" y="444.2" className="st0" width="3.4" height="136.5" />
            <rect x="993.8" y="454" className="st0" width="3.4" height="116.1" />
            <rect x="1021.8" y="442.5" className="st0" width="3.4" height="139.8" />
            <path className="st0" d="M1038.9,444.3H828.7c-1.7,0-3.2-1.4-3.2-3.2v-0.9c0-1.7,1.4-3.2,3.2-3.2h210.2L1038.9,444.3L1038.9,444.3z" />
            <rect x="947.4" y="329.1" className="st0" width="20.3" height="25.2" />
            <rect x="881.3" y="368.8" className="st0" width="150.8" height="15.9" />
            <rect x="937.5" y="336.4" className="st0" width="5.9" height="61" />
            <rect x="972.4" y="336.5" className="st0" width="5.1" height="60.9" />
            <path className="st0" d="M1026.4,407.7H885.6c-2.1,0-3.8-1.7-3.8-3.8V401c0-2.1,1.7-3.8,3.8-3.8h140.8c2.1,0,3.8,1.7,3.8,3.8v2.8
		C1030.2,406,1028.5,407.7,1026.4,407.7z"/>
            <circle className="st4" cx="923.2" cy="355.8" r="4.9" />
            <path className="st0" d="M1000.9,362.8h-15.4c-1.5,0-2.8-1.2-2.8-2.8v-8.8c0-1.5,1.2-2.8,2.8-2.8h15.4c1.5,0,2.8,1.2,2.8,2.8v8.8
		C1003.7,361.6,1002.5,362.8,1000.9,362.8z"/>
            <circle className="st4" cx="993.2" cy="355.8" r="4.9" />
            <path className="st0" d="M1018,594.3h-47.2c-4,0-7.2-3.2-7.2-7.2v-7.2h61.6v7.2C1025.2,591,1022,594.3,1018,594.3z" />
            <rect x="560.4" y="415" className="st5" width="255.4" height="30.2" />
            <text transform="matrix(1 0 0 1 622.2816 435.4493)" className="st6 st7">muzero-HYPERLOOP</text>
          </g>
          <g id="track">
            <rect x="336.6" y="593" className="st0" width="77.3" height="21.2" />
            <rect x="955.6" y="593" className="st0" width="77.3" height="21.2" />
            <rect x="679" y="463.2" className="st0" width="15.4" height="150.6" />
            <rect x="904.6" y="275.9" className="st0" width="106.3" height="21.2" />
            <rect x="358.8" y="275.5" className="st0" width="106.4" height="21.2" />

            <rect x="276.1" y="481.1" transform="matrix(-1.836970e-16 1 -1 -1.836970e-16 797.3289 186.129)" className="st0" width="59.1" height="21.2" />

            <rect x="1035.7" y="479.2" transform="matrix(-1.836970e-16 1 -1 -1.836970e-16 1555.4026 -575.8605)" className="st0" width="60" height="21.2" />
            <rect x="877.7" y="480.5" className="st0" width="14.6" height="51.2" />
          </g>
        </svg>
      </Stack>
    </Paper>
  );
}


export default StateVis;
