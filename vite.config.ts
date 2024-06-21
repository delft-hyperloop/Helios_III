import { defineConfig } from "vite";
import react from "@vitejs/plugin-react";
import { resolve } from 'path';


// https://vitejs.dev/config/
export default defineConfig(async () => ({
  build :{
    rollupOptions: {
      input: {
        main: resolve(__dirname, "index.html"),
        startup: resolve(__dirname, "startup.html"),
        settings: resolve(__dirname, "settings.html"),
        plot: resolve(__dirname, "plot.html")
      }
    },
    chunkSizeWarningLimit: 1600,
  },
  plugins: [
    react()
  ],

  // Vite options tailored for Tauri development and only applied in `tauri dev` or `tauri build`
  //
  // 1. prevent vite from obscuring rust errors
  clearScreen: false,
  // 2. tauri expects a fixed port, fail if that port is not available
  server: {
    port: 1420,
    strictPort: true,
  },
  // 3. to make use of `TAURI_DEBUG` and other env variables
  // https://tauri.app/v1/api/config#buildconfig.beforedevcommand
  envPrefix: ["VITE_", "TAURI_"],
}));
