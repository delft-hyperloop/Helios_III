import {
  createTheme,
  responsiveFontSizes,
} from "@mui/material/styles";


declare module "@mui/material/styles" {
  interface BreakpointOverrides {
    xs: true;
    sm: true;
    md: true;
    lg: true;
    xl: true;
    mobile: true;
    tablet: true;
    laptop: true;
    desktop: true;
  }
  interface Palette {
    stateInit: Palette["primary"],
    stateIdle: Palette["primary"],
    stateArming45: Palette["primary"],
    statePrecharge: Palette["primary"],
    stateDisarming45: Palette["primary"],
    stateReady: Palette["primary"],
    stateStartLevitation: Palette["primary"],
    stateLevitation: Palette["primary"],
    stateStartGuidance: Palette["primary"],
    stateGuidance: Palette["primary"],
    stateAccelerate: Palette["primary"],
    stateController: Palette["primary"],
    stateCruising: Palette["primary"],
    stateDeceleration: Palette["primary"],

    stateStopLevitation: Palette["primary"],
    stateStopGuidance: Palette["primary"],

    stateShutdown: Palette["primary"],
    stateRestarting: Palette["primary"],
    stateCalibrating: Palette["primary"],

    subStateArm: Palette["primary"],
    subStatePrecharge: Palette["primary"],
    subStateDisarm: Palette["primary"],
    subStateReady: Palette["primary"],
    subStateStart: Palette["primary"],
    subStateStop: Palette["primary"],
    subStateControl: Palette["primary"],
    subStateOther: Palette["primary"],

    cmdStart : Palette["primary"],
    cmdStop : Palette["primary"],
    cmdAbort : Palette["primary"],
    cmdExtra : Palette["primary"],

    disconnected: Palette["primary"],

    temperatureHot: Palette["primary"],
    temperatureOk: Palette["primary"],
  }
  interface PaletteOptions {
    stateInit?: PaletteOptions["primary"],
    stateIdle?: PaletteOptions["primary"],
    stateArming45?: PaletteOptions["primary"],
    statePrecharge?: PaletteOptions["primary"],
    stateDisarming45?: PaletteOptions["primary"],
    stateReady?: PaletteOptions["primary"],
    stateStartLevitation?: PaletteOptions["primary"],
    stateLevitation?: PaletteOptions["primary"],
    stateStartGuidance?: PaletteOptions["primary"],
    stateGuidance?: PaletteOptions["primary"],
    stateAccelerate?: PaletteOptions["primary"],
    stateController?: PaletteOptions["primary"],
    stateCruising?: PaletteOptions["primary"],
    stateDeceleration?: PaletteOptions["primary"],

    stateStopLevitation?: PaletteOptions["primary"],
    stateStopGuidance?: PaletteOptions["primary"],

    stateShutdown?: PaletteOptions["primary"],
    stateRestarting?: PaletteOptions["primary"],
    stateCalibrating?: PaletteOptions["primary"],

    subStateArm?: PaletteOptions["primary"],
    subStatePrecharge?: PaletteOptions["primary"],
    subStateDisarm?: PaletteOptions["primary"],
    subStateReady?: PaletteOptions["primary"],
    subStateStart?: PaletteOptions["primary"],
    subStateStop?: PaletteOptions["primary"],
    subStateControl?: PaletteOptions["primary"],
    subStateOther?: PaletteOptions["primary"],


    cmdStart? : PaletteOptions["primary"],
    cmdStop? : PaletteOptions["primary"],
    cmdAbort? : PaletteOptions["primary"],
    cmdExtra? : PaletteOptions["primary"],

    disconnected?: PaletteOptions["primary"],

    temperatureHot?: PaletteOptions["primary"],
    temperatureOk?: PaletteOptions["primary"],
  }
  interface TypeBackground {
    drawer?: string,
    appBar?: string,
    trace?: string,
    main?: string,
    paper2?: string,
    warn?: string,
    error?: string,
    disabled?: string
  }
}

declare module '@mui/material/Button' {
  interface ButtonPropsColorOverrides {
    stateInit: true,
    stateIdle: true,
    stateArming45: true,
    statePrecharge: true,
    stateDisarming45: true,
    stateReady: true,
    stateStartLevitation: true,
    stateLevitation: true,
    stateStartGuidance: true,
    stateGuidance: true,
    stateAccelerate: true,
    stateController: true,
    stateCruising: true,
    stateDeceleration: true,

    stateStopLevitation: true,
    stateStopGuidance: true,

    stateShutdown: true,
    stateRestarting: true,
    stateCalibrating: true,

    subStateArm: true,
    subStatePrecharge: true,
    subStateDisarm: true,
    subStateReady: true,
    subStateStart: true,
    subStateStop: true,
    subStateControl: true,
    subStateOther: true,

    cmdStart : true,
    cmdStop : true,
    cmdAbort : true,
    cmdExtra : true,

    disconnected: true,
  }
}

declare module "@mui/material/AppBar" {
  interface AppBarPropsColorOverrides {
    background: true,
    front: true,
  }
}

const theme = responsiveFontSizes(createTheme({
  palette: {
    background: {
      appBar: "#232323",
      trace: "#e7e7e7",
      drawer: "#ffffff",
      default: "#f7f7f7",
      main: "#f3f3f3",
      paper: "#ededed",
      paper2: "#f3f3f3",
      warn: "#f2e9ce",
      error: "#f2d5d5",
      disabled: "#a2a2a2"
    },


    stateInit: {
      main: "#B3EBFF",
    },
    stateIdle: {
      main: "#568BE8",
    },
    stateArming45: {
      main: "#AF5BC4",
    },
    statePrecharge: {
      main: "#D871D3",
    },
    stateDisarming45: {
      main: "#F9A35D",
    },
    stateReady: {
      main: "#8BE26F",
    },
    stateStartLevitation: {
      main: "#BBEDFF",
    },
    stateLevitation: {
      main: "#89E0F4",
    },
    stateStartGuidance: {
      main: "#98ACEA",
    },
    stateGuidance: {
      main: "#6699FF",
    },
    stateAccelerate: {
      main: "#7FD3B9"
    },
    stateController: {
      main: "#3AEFBB",
    },
    stateCruising: {
      main: "#3AEFBB",
    },
    stateDeceleration: {
      main: "#E5E567"
    },
    stateStopLevitation: {
      main: "#FFE54A",
    },
    stateStopGuidance: {
      main: "#FFFF99",
    },
    stateShutdown: {
      main: "#F44A3D",
    },
    stateRestarting: {
      main: "#F7C663",
    },
    stateCalibrating: {
      main: "#67C1E5",
    },
    subStateArm: {
      main: "#ffff00",
    },
    subStatePrecharge: {
      main: "#b3ff00",
    },
    subStateDisarm: {
      main: "#ff9100",
    },
    subStateReady: {
      main: "#8BE26F",
    },
    subStateStart: {
      main: "#89E0F4",
    },
    subStateStop: {
      main: "#ffff00",
    },
    subStateControl: {
      main: "#3AEFBB",
    },
    subStateOther: {
      main: "#D871D3",
    },
    cmdStart : {
      main: "#57A355",
    },
    cmdStop : {
      main: "#E0BC00",
    },
    cmdAbort : {
      main: "#ff0a0a",
    },
    cmdExtra : {
      main: "#D871D3",
    },

    disconnected: {
      main: "#F44A3D",
    },

    temperatureHot: {
      main: "#ff0a0a",
    },
    temperatureOk: {
      main: "#89E0F4",
    },
  },
  breakpoints: {
    values: {
      xs: 0,
      sm: 600,
      md: 900,
      lg: 1200,
      xl: 1536,
      mobile: 0,
      tablet: 640,
      laptop: 1200,
      desktop: 1600,
    },
  },
}));

export default theme;
