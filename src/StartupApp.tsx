import { ThemeProvider } from "@emotion/react";
import theme from "./theme";
import { SnackbarProvider } from "notistack";
import StartupContent from "./StartupContent";



function StartupApp() {
  return (
    <ThemeProvider theme={theme}>
      <SnackbarProvider preventDuplicate maxSnack={7}>
        <StartupContent/>
      </SnackbarProvider>
    </ThemeProvider>
  );

}

export default StartupApp;
