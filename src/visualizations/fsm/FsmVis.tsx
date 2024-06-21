import { Paper } from "@mui/material";
import "./FsmVis.css"
import { useEffect, useRef, useState } from "react";
import useObjectEntryValue from "../../hooks/object_entry_value";


function FsmVis() {
  const ref = useRef() as any;

  const [aspect, setAspect] = useState(3.72);
  const [height, setHeight] = useState(0);
  const [width, setWidth] = useState(0);
  const [x,setX] = useState(450 + 210 * 0);
  const [y,setY] = useState(335 + 100 * 0);

  const globalState = useObjectEntryValue("mother_board", "state");

  useEffect(()=>{
    switch (globalState as string) {
      case "INIT":
        setX(340);
        setY(335);
      break;
      case "IDLE":
        setX(450);
        setY(335);
      break;
      case "ARMING45":
        setX(450 + 210);
        setY(335);
      break;
      case "PRECHARGE":
        setX(450 + 210 * 2);
        setY(335);
      break;
      case "DISARMING45":
        setX(450 + 210);
        setY(335 + 100);
      break;
      case "READY":
        setX(450 + 210 * 3);
        setY(335);
      break;
      case "START_LEVITATION":
        setX(450 + 210 * 4);
        setY(335);
      break;
      case "LEVITATION_STABLE":
        setX(450 + 210 * 5);
        setY(335);
      break;
      case "GUIDANCE_STABLE":
        setX(450 + 210 * 6);
        setY(335);
      break;
      case "ACCELERATION":
        setX(450 + 210 * 7);
        setY(335);
      break;
      case "CONTROLLER":
        setX(450 + 210 * 7);
        setY(335);
      break;
      case "CRUISING":
        setX(450 + 210 * 8);
        setY(335);
      break;
      case "DECELERATION":
        setX(450 + 210 * 7);
        setY(335 + 100);
      break;
      case "STOP_LEVITATION":
        setX(450 + 210 * 5);
        setY(335 + 100);
      break;
      case "STOP_GUIDANCE":
        setX(450 + 210 * 3);
        setY(335 + 100);
      break;
      case "SHUTDOWN":
        setX(450);
        setY(335 - 100);
      break;
      case "RESTARTING":
        setX(340);
        setY(335 - 100);
      break;
      case "CALIBRATING":
        setX(450);
        setY(335 + 100);
      break;
    };
  },[globalState]);

  useEffect(() => {
    let current = ref.current;

    let resizeObserver: ResizeObserver | undefined = undefined;
    resizeObserver = new ResizeObserver(
      entries => {
        if (!Array.isArray(entries)) return;
        if (!entries.length) return;
        const entry = entries[0];
        console.log("aspect", entry.contentRect.width / entry.contentRect.height);
        setAspect(entry.contentRect.width / entry.contentRect.height);
        setHeight(entry.contentRect.height);
        setWidth(entry.contentRect.width);
      }
    );
    resizeObserver.observe(current);
    return () => {
      resizeObserver?.unobserve(current);
    };
  }, []);

  useEffect(()=>{
    const leftX = x - width / 2.0;
    const topY = y - height / 2.0;

    const svg = document.getElementById("fsm-vis")!;

    svg.style.setProperty("--x", `-${leftX}px`);
    svg.style.setProperty("--y", `-${topY}px`);
  },[height,width, x,y]);

  return (
    <Paper sx={{
      width: "50%",
      height: "27vh",
    }} ref={ref}>
      <svg
        xmlns="http://www.w3.org/2000/svg"
        version="1.1"
        ref={ref}
        viewBox={`0 0 ${300 * aspect} 300`}
        id="fsm-vis">
        <g id="view">
          <g id="Background">
            <path className="cls-3" d="M689,0h2092.18v435H777.89c-49.06,0-88.89-39.83-88.89-88.89V0h0Z" />
            <text className="cls-28" transform="translate(704.57 316.99)"><tspan x="0" y="0">SDC</tspan><tspan x="-5.73" y="14.4">closed</tspan></text>
            <text className="cls-28" transform="translate(656.54 317.25)"><tspan x="0" y="0">SDC</tspan><tspan x="-2.61" y="14.4">open</tspan></text>
            <rect className="cls-5" x="908.74" width="1918.26" height="435" />
            <text className="cls-28" transform="translate(911.5 314.78)"><tspan x="0" y="0">Precharge</tspan><tspan x="9.23" y="14.4">closed</tspan></text>
            <rect className="cls-6" x="1132.64" width="1694.36" height="435" />
            <text className="cls-28" transform="translate(1130.42 314.28)"><tspan x="0" y="0">Feedthrough</tspan><tspan x="16.72" y="14.4">closed</tspan></text>
          </g>
          <g id="States">
            <line className="cls-10" x1="871" y1="473" x2="2389" y2="473" />
            <rect className="cls-22" x="321" y="341" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(372.28 367.99)"><tspan x="0" y="0">Init</tspan></text>
            <rect className="cls-19" x="529.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(579.69 367.49)"><tspan x="0" y="0">Idle</tspan></text>
            <g>
              <line className="cls-10" x1="442" y1="364" x2="518.28" y2="364" />
              <g>
                <polygon className="cls-7" points="512.38 370.6 517.5 364 512.38 357.4 528 364 512.38 370.6" />
                <polygon className="cls-4" points="514.28 369.17 526.44 364 518.28 364 514.28 369.17" />
                <polygon className="cls-1" points="514.25 358.85 526.44 364 518.25 364 514.25 358.85" />
              </g>
            </g>
            <rect className="cls-24" x="530.5" y="235.5" width="121" height="47" rx="10.72" ry="10.72" />
            <g>
              <line className="cls-10" x1="591" y1="342" x2="591" y2="293.72" />
              <g>
                <polygon className="cls-7" points="597.6 299.62 591 294.5 584.4 299.62 591 284 597.6 299.62" />
                <polygon className="cls-4" points="596.17 297.72 591 285.56 591 293.72 596.17 297.72" />
                <polygon className="cls-1" points="585.85 297.75 591 285.56 591 293.75 585.85 297.75" />
              </g>
            </g>
            <rect className="cls-20" x="528.5" y="447.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(560.46 474.49)"><tspan x="0" y="0">Calibration</tspan></text>
            <g>
              <line className="cls-10" x1="592" y1="436.28" x2="592" y2="388" />
              <g>
                <polygon className="cls-7" points="598.6 430.38 592 435.5 585.4 430.38 592 446 598.6 430.38" />
                <polygon className="cls-4" points="597.17 432.28 592 444.44 592 436.28 597.17 432.28" />
                <polygon className="cls-1" points="586.85 432.25 592 444.44 592 436.25 586.85 432.25" />
              </g>
            </g>
            <rect className="cls-25" x="320.5" y="235.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(354.41 262.49)"><tspan x="0" y="0">Restarting</tspan></text>
            <g>
              <line className="cls-10" x1="449" y1="285.54" x2="532" y2="343" />
              <g>
                <polygon className="cls-7" points="450.08 294.32 449.64 285.98 457.6 283.46 441 280 450.08 294.32" />
                <polygon className="cls-4" points="449.34 292.06 442.29 280.89 449 285.54 449.34 292.06" />
                <polygon className="cls-1" points="455.24 283.59 442.29 280.89 449.01 285.55 455.24 283.59" />
              </g>
            </g>
            <rect className="cls-16" x="739.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(774.05 367.49)"><tspan x="0" y="0">Arming45</tspan></text>
            <text className="cls-28" transform="translate(563.93 262.49)"><tspan x="0" y="0">Shutdown</tspan></text>
            <g>
              <line className="cls-10" x1="652" y1="364" x2="728.28" y2="364" />
              <g>
                <polygon className="cls-7" points="722.38 370.6 727.5 364 722.38 357.4 738 364 722.38 370.6" />
                <polygon className="cls-4" points="724.28 369.17 736.44 364 728.28 364 724.28 369.17" />
                <polygon className="cls-1" points="724.25 358.85 736.44 364 728.25 364 724.25 358.85" />
              </g>
            </g>
            <rect className="cls-26" x="949.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(983.54 367.49)"><tspan x="0" y="0">Precharge</tspan></text>
            <g>
              <line className="cls-10" x1="862" y1="364" x2="938.28" y2="364" />
              <g>
                <polygon className="cls-7" points="932.38 370.6 937.5 364 932.38 357.4 948 364 932.38 370.6" />
                <polygon className="cls-4" points="934.28 369.17 946.44 364 938.28 364 934.28 369.17" />
                <polygon className="cls-1" points="934.25 358.85 946.44 364 938.25 364 934.25 358.85" />
              </g>
            </g>
            <rect className="cls-27" x="1159.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1203.59 367.49)"><tspan x="0" y="0">Ready</tspan></text>
            <g>
              <line className="cls-10" x1="1072" y1="364" x2="1148.28" y2="364" />
              <g>
                <polygon className="cls-7" points="1142.38 370.6 1147.5 364 1142.38 357.4 1158 364 1142.38 370.6" />
                <polygon className="cls-4" points="1144.28 369.17 1156.44 364 1148.28 364 1144.28 369.17" />
                <polygon className="cls-1" points="1144.25 358.85 1156.44 364 1148.25 364 1144.25 358.85" />
              </g>
            </g>
            <rect className="cls-21" x="740.5" y="447.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(768.05 474.49)"><tspan x="0" y="0">Disarming45</tspan></text>
            <g>
              <line className="cls-10" x1="656.1" y1="392.64" x2="741" y2="472" />
              <g>
                <polygon className="cls-7" points="655.9 401.49 656.67 393.17 664.92 391.84 649 386 655.9 401.49" />
                <polygon className="cls-4" points="655.5 399.14 650.14 387.07 656.1 392.64 655.5 399.14" />
                <polygon className="cls-1" points="662.57 391.63 650.14 387.07 656.12 392.66 662.57 391.63" />
              </g>
            </g>
            <g>
              <line className="cls-10" x1="799" y1="447" x2="799" y2="398.72" />
              <g>
                <polygon className="cls-7" points="805.6 404.62 799 399.5 792.4 404.62 799 389 805.6 404.62" />
                <polygon className="cls-4" points="804.17 402.72 799 390.56 799 398.72 804.17 402.72" />
                <polygon className="cls-1" points="793.85 402.75 799 390.56 799 398.75 793.85 402.75" />
              </g>
            </g>
            <g>
              <path className="cls-10" d="M872.72,472.87c150.57-3.38,137.21-85.37,137.21-85.37" />
              <g>
                <polygon className="cls-7" points="878.73 479.32 873.5 472.8 878.5 466.11 863 472.98 878.73 479.32" />
                <g>
                  <polygon className="cls-1" points="876.83 477.91 864.57 472.95 872.75 472.81 876.83 477.91" />
                  <polygon className="cls-4" points="876.66 467.59 864.57 472.95 872.75 472.81 876.66 467.59" />
                </g>
              </g>
            </g>
            <path className="cls-10" d="M1218.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-23" x="1369.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1390.85 367.49)"><tspan x="0" y="0">Start Levitation</tspan></text>
            <g>
              <line className="cls-10" x1="1282" y1="364" x2="1358.28" y2="364" />
              <g>
                <polygon className="cls-7" points="1352.38 370.6 1357.5 364 1352.38 357.4 1368 364 1352.38 370.6" />
                <polygon className="cls-4" points="1354.28 369.17 1366.44 364 1358.28 364 1354.28 369.17" />
                <polygon className="cls-1" points="1354.25 358.85 1366.44 364 1358.25 364 1354.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M1428.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-8" x="1579.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1596.97 367.49)"><tspan x="0" y="0">Levitation Stable</tspan></text>
            <g>
              <line className="cls-10" x1="1492" y1="364" x2="1568.28" y2="364" />
              <g>
                <polygon className="cls-7" points="1562.38 370.6 1567.5 364 1562.38 357.4 1578 364 1562.38 370.6" />
                <polygon className="cls-4" points="1564.28 369.17 1576.44 364 1568.28 364 1564.28 369.17" />
                <polygon className="cls-1" points="1564.25 358.85 1576.44 364 1568.25 364 1564.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M1638.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-15" x="1788.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1810.99 367.49)"><tspan x="0" y="0">Start Guidance</tspan></text>
            <g>
              <line className="cls-10" x1="1701" y1="364" x2="1777.28" y2="364" />
              <g>
                <polygon className="cls-7" points="1771.38 370.6 1776.5 364 1771.38 357.4 1787 364 1771.38 370.6" />
                <polygon className="cls-4" points="1773.28 369.17 1785.44 364 1777.28 364 1773.28 369.17" />
                <polygon className="cls-1" points="1773.25 358.85 1785.44 364 1777.25 364 1773.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M1847.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-13" x="1998.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(2017.1 367.49)"><tspan x="0" y="0">Guidance Stable</tspan></text>
            <g>
              <line className="cls-10" x1="1911" y1="364" x2="1987.28" y2="364" />
              <g>
                <polygon className="cls-7" points="1981.38 370.6 1986.5 364 1981.38 357.4 1997 364 1981.38 370.6" />
                <polygon className="cls-4" points="1983.28 369.17 1995.44 364 1987.28 364 1983.28 369.17" />
                <polygon className="cls-1" points="1983.25 358.85 1995.44 364 1987.25 364 1983.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M2057.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-17" x="2207.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(2235.59 367.49)"><tspan x="0" y="0">Acceleration</tspan></text>
            <g>
              <line className="cls-10" x1="2120" y1="364" x2="2196.28" y2="364" />
              <g>
                <polygon className="cls-7" points="2190.38 370.6 2195.5 364 2190.38 357.4 2206 364 2190.38 370.6" />
                <polygon className="cls-4" points="2192.28 369.17 2204.44 364 2196.28 364 2192.28 369.17" />
                <polygon className="cls-1" points="2192.25 358.85 2204.44 364 2196.25 364 2192.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M2266.93,387.5s10.79,85.5-85.93,85.5" />
            <rect className="cls-18" x="2415.5" y="340.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(2454.31 367.49)"><tspan x="0" y="0">Cruising</tspan></text>
            <g>
              <line className="cls-10" x1="2328" y1="364" x2="2404.28" y2="364" />
              <g>
                <polygon className="cls-7" points="2398.38 370.6 2403.5 364 2398.38 357.4 2414 364 2398.38 370.6" />
                <polygon className="cls-4" points="2400.28 369.17 2412.44 364 2404.28 364 2400.28 369.17" />
                <polygon className="cls-1" points="2400.25 358.85 2412.44 364 2404.25 364 2400.25 358.85" />
              </g>
            </g>
            <path className="cls-10" d="M2442.99,388s2.4,85-53.99,85" />
            <rect className="cls-12" x="2208.5" y="232.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(2235.94 260.49)"><tspan x="0" y="0">Deceleration</tspan></text>
            <path className="cls-2" d="M2058,340" />
            <path className="cls-2" d="M2207,259" />
            <g>
              <line className="cls-10" x1="2269" y1="339" x2="2269" y2="290.72" />
              <g>
                <polygon className="cls-7" points="2275.6 296.62 2269 291.5 2262.4 296.62 2269 281 2275.6 296.62" />
                <polygon className="cls-4" points="2274.17 294.72 2269 282.56 2269 290.72 2274.17 294.72" />
                <polygon className="cls-1" points="2263.85 294.75 2269 282.56 2269 290.75 2263.85 294.75" />
              </g>
            </g>
            <g>
              <path className="cls-14" d="M2442.93,340.37s6.46-79.75-103.71-84.18" />
              <g>
                <polygon className="cls-7" points="2345.3 249.86 2340 256.31 2344.92 263.06 2329.5 256 2345.3 249.86" />
                <g>
                  <polygon className="cls-1" points="2343.39 251.24 2331.07 256.05 2339.24 256.29 2343.39 251.24" />
                  <polygon className="cls-4" points="2343.09 261.56 2331.07 256.05 2339.24 256.29 2343.09 261.56" />
                </g>
              </g>
            </g>
            <g>
              <path className="cls-14" d="M2208.5,255s-115.64-8.36-124.02,74.29" />
              <g>
                <polygon className="cls-7" points="2078.45 322.98 2084.7 328.52 2091.63 323.86 2084 339 2078.45 322.98" />
                <g>
                  <polygon className="cls-1" points="2079.77 324.94 2084.11 337.43 2084.65 329.27 2079.77 324.94" />
                  <polygon className="cls-4" points="2090.06 325.63 2084.11 337.43 2084.65 329.27 2090.06 325.63" />
                </g>
              </g>
            </g>
            <rect className="cls-9" x="1788.5" y="232.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1811.12 261.49)"><tspan x="0" y="0">Stop Guidance</tspan></text>
            <g>
              <line className="cls-10" x1="1849" y1="339" x2="1849" y2="290.72" />
              <g>
                <polygon className="cls-7" points="1855.6 296.62 1849 291.5 1842.4 296.62 1849 281 1855.6 296.62" />
                <polygon className="cls-4" points="1854.17 294.72 1849 282.56 1849 290.72 1854.17 294.72" />
                <polygon className="cls-1" points="1843.85 294.75 1849 282.56 1849 290.75 1843.85 294.75" />
              </g>
            </g>
            <g>
              <path className="cls-14" d="M2030.92,339.25s6.84-80-110.03-84.2" />
              <g>
                <polygon className="cls-7" points="1926.95 248.68 1921.67 255.15 1926.61 261.88 1911.17 254.88 1926.95 248.68" />
                <g>
                  <polygon className="cls-1" points="1925.04 250.07 1912.74 254.92 1920.91 255.13 1925.04 250.07" />
                  <polygon className="cls-4" points="1924.78 260.39 1912.74 254.92 1920.91 255.13 1924.78 260.39" />
                </g>
              </g>
            </g>
            <rect className="cls-11" x="1369.5" y="232.5" width="121" height="47" rx="10.72" ry="10.72" />
            <text className="cls-28" transform="translate(1392.12 260.49)"><tspan x="0" y="0">Stop Guidance</tspan></text>
            <g>
              <line className="cls-10" x1="1430" y1="339" x2="1430" y2="290.72" />
              <g>
                <polygon className="cls-7" points="1436.6 296.62 1430 291.5 1423.4 296.62 1430 281 1436.6 296.62" />
                <polygon className="cls-4" points="1435.17 294.72 1430 282.56 1430 290.72 1435.17 294.72" />
                <polygon className="cls-1" points="1424.85 294.75 1430 282.56 1430 290.75 1424.85 294.75" />
              </g>
            </g>
            <g>
              <line className="cls-10" x1="1501.72" y1="256" x2="1787" y2="256" />
              <g>
                <polygon className="cls-7" points="1507.62 262.6 1502.5 256 1507.62 249.4 1492 256 1507.62 262.6" />
                <polygon className="cls-4" points="1505.72 261.17 1493.56 256 1501.72 256 1505.72 261.17" />
                <polygon className="cls-1" points="1505.75 250.85 1493.56 256 1501.75 256 1505.75 250.85" />
              </g>
            </g>
            <path className="cls-14" d="M1639.79,339.35s11.18-83.35-115.79-83.35" />
            <g>
              <path className="cls-14" d="M1368,256.23s-137.31-8.23-147.41,73.05" />
              <g>
                <polygon className="cls-7" points="1214.7 322.89 1220.86 328.53 1227.86 323.98 1220 339 1214.7 322.89" />
                <g>
                  <polygon className="cls-1" points="1215.98 324.88 1220.13 337.43 1220.8 329.29 1215.98 324.88" />
                  <polygon className="cls-4" points="1226.27 325.72 1220.13 337.43 1220.8 329.29 1226.27 325.72" />
                </g>
              </g>
            </g>
          </g>
        </g>
      </svg>
    </Paper>
  );
}

export default FsmVis;

/*
      */
