import {invoke} from "@tauri-apps/api/tauri";

export class GrandDataDistributor {
    private intervalId: NodeJS.Timeout | null = null;
    private StoreManager:StoreManager;

    constructor() {
        this.StoreManager = new StoreManager();
    }

    /* TODO: MAKE IT CALLABLE ONLY ONCE */
    public start(interval:number) {
        this.intervalId = setInterval(() => this.fetchData(), interval);
    }

    public kill() {
        if (this.intervalId) clearInterval(this.intervalId);
    }

    private async fetchData() {
        const data:any[] = await invoke('unload_buffer');
        this.processData(data);
    }

    protected processData(data: any[]) {

    }
}

class StoreManager {

}