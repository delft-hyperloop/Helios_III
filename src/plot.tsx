import React from "react";
import ReactDOM from "react-dom/client";
import "./styles.css";
import FloatingPlot from "./FloatingPlot";

ReactDOM.createRoot(document.getElementById("root") as HTMLElement).render(
  <React.StrictMode>
    <FloatingPlot />
  </React.StrictMode>,
);
