import {invoke} from "@tauri-apps/api/tauri";
import {type Writable} from "svelte/store";
import type {dataConvFun, Datapoint, NamedDatatype} from "$lib/types";

/**
 * The GrandDataDistributor class is responsible for fetching data from the backend
 * and distributing it to the appropriate stores. This is a singleton to ensure
 * that there are no erroneous multiple instances of the GDD running at the same time.
 *
 * @example
 * ```typescript
 *  let gdd = GrandDataDistributor.getInstance();
 *  gdd.registerStore('temperature', temperatureStore, (data) => data + 273.15);
 *  gdd.start(1000);
 * ```
 *
 * @see StateManager
 * @version 1.0
 */
export class GrandDataDistributor {
    private intervalId: NodeJS.Timeout | null = null;
    private readonly StoreManager:StoreManager;
    private static instance: GrandDataDistributor;

    static getInstance() {
        if (!GrandDataDistributor.instance) {
            GrandDataDistributor.instance = new GrandDataDistributor();
        }
        return GrandDataDistributor.instance;
    }

    /**
     * Private constructor to make it a singleton
     * @private
     *
     * @note this is a singleton class, possibly this is a good choice since
     * we want to have only one instance of the GDD running at a time.
     */
    private constructor() {
        this.StoreManager = new StoreManager();
    }

    /**
     * Start the data fetching process
     * @param interval - the interval in milliseconds
     * @note this method will start the interval and fetch data from the backend
     * at the specified interval
     */
    public start(interval:number) {
        if (!this.intervalId) this.intervalId = setInterval(() => this.fetchData(), interval);
    }

    /**
     * Stop the data fetching process. This will clear the interval.
     */
    public kill() {
        if (this.intervalId) clearInterval(this.intervalId);
    }

    /**
     * Fetch data from the backend
     * @private
     */
    private async fetchData() {
        const data:Datapoint[] = await invoke('unload_buffer');
        this.processData(data);
    }

    /**
     * Process the data fetched from the backend
     * @param data - the data fetched from the backend
     */
    protected processData(data: Datapoint[]) {
        data.forEach((datapoint) => {
            this.StoreManager.updateStore(datapoint.datatype, datapoint.value);
        });
    }

    get stores() {
        return this.StoreManager;
    }
}

/**
 * The StoreManager class is responsible for managing the data stores
 */
class StoreManager {
    private stores: Map<string, Store<any>>;

    constructor() {
        this.stores = new Map();
    }

    /**
     * Register a store
     * @param name - the name of the store
     * @param store - the store
     * @param processFunction - the function to process the data
     */
    public registerStore<T>(name: NamedDatatype, store: Writable<T>, processFunction?: dataConvFun<T>) {
        this.stores.set(name, new Store(store, processFunction));
    }

    /**
     * Update a store
     * @param name - the name of the store
     * @param data - the data to update the store with
     */
    public updateStore(name: NamedDatatype, data: bigint) {
        const store = this.stores.get(name);
        if (store) store.set(data);
    }
}

/**
 * The Store class is responsible for managing the data store
 * and processing the data before setting it to the store.
 * This allows for processing the data before setting it to the store.
 * @version 1.0
 */
class Store<T> {
    private readonly writable: Writable<T>;
    private readonly processFunction: dataConvFun<T>;

    constructor(writable:Writable<T>, processFunction: dataConvFun<T> = (data) => data.valueOf() as unknown as T) {
        this.writable = writable;
        this.processFunction = processFunction;
    }

    public set(data: bigint) {
        this.writable.set(this.processFunction(data));
    }
}