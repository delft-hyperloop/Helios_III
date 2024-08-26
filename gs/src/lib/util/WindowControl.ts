import { WebviewWindow, type WindowOptions } from "@tauri-apps/api/window"

import type { WindowEngine } from "@delft-hyperloop/serpenta";

export class ViewWindow {
    private readonly _webview: WebviewWindow

    constructor(label: string, url: string) {
        const options: WindowOptions = { url, decorations: false, resizable: true, alwaysOnTop: true, center: true }
        this._webview = new WebviewWindow(label.replace(" ", "-"), options)
        this._webview.once("tauri://created", function() {
            console.log("Successful creation")
        })

        this._webview.once("tauri://error", function(e) {
            console.error("Error creating window", e)
        })
    }
}

export class WindowCreator implements WindowEngine<WindowOptions> {
    spawnWindow(url: string, label: string): void {
        new ViewWindow(label, url);
    }
}