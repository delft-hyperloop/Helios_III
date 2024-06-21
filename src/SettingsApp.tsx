import { ThemeProvider } from "@emotion/react";
import theme from "./theme";
import SettingsContent from "./SettingsContent";



function SettingsApp() {
  return (
    <ThemeProvider theme={theme}>
      <SettingsContent/>
    </ThemeProvider>
  );

}

export default SettingsApp;
