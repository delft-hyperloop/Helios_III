import "./App.css";
import { ThemeProvider} from "@mui/material";
import theme from "./theme.ts"
import FloatingPlotContent from "./FloatingPlotContent.tsx";

function FloatingPlot() {
  return (
    <ThemeProvider theme={theme}>
      <FloatingPlotContent/>
    </ThemeProvider>
  );
}

export default FloatingPlot;
