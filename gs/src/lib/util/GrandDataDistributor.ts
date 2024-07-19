import {invoke} from "@tauri-apps/api/tauri";
import {get, type Writable, writable} from "svelte/store";
import {type dataConvFun, type Datapoint, type NamedDatatype} from "$lib/types";
import {latestTimestamp} from "$lib/stores/state";

/**
 * The GrandDataDistributor class is responsible for fetching data from the backend
 * and distributing it to the appropriate stores. This is a singleton to ensure
 * that there are no erroneous multiple instances of the GDD running at the same time.
 *
 * @example
 * ```typescript
 *  // +layout.svelte
 *  let gdd = GrandDataDistributor.getInstance();
 *  gdd.registerStore('BatteryBalanceHigh');
 *  gdd.start(1000);
 * ```
 *
 * ```svelte
 * .
 * <!-- +page.svelte -->
 * <script>
 *     let gdd = GrandDataDistributor.getInstance();
 *     let store = gdd.stores.get('BatteryBalanceHigh');
 * </script>
 * <h1>{$store}</h1>
 * ```
 *
 * @see StateManager
 * @version 2.0
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

    public async fetchTestOnce() {
        const data:Datapoint[] = await invoke('generate_test_data');
        this.processData(data);
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
            this.StoreManager.updateStore(datapoint.datatype, new Date().getTime(), datapoint.style, datapoint.units, datapoint.value);
        });
    }

    /**
     * Get the store manager
     */
    get stores() {
        return this.StoreManager;
    }
}

/**
 * The StoreManager class is responsible for managing the data stores
 */
class StoreManager {
    private stores: Map<string, Writable<Store<any>>>;

    constructor() {
        this.stores = new Map();
    }

    /**
     * Register a store
     * @param name - the name of the store
     * @param initial
     * @param initialUnits
     * @param processFunction - the function to process the data
     */
    public registerStore<T>(name: NamedDatatype, initial: T, processFunction?: dataConvFun<T>, initialUnits?:string) {
        this.stores.set(name, writable<Store<T>>(new Store(initial, '', initialUnits || '', 0, processFunction)));
    }

    /**
     * Update a store
     * @param name - the name of the store
     * @param timestamp
     * @param style
     * @param units
     * @param data - the data to update the store with
     */
    public updateStore(name: NamedDatatype, timestamp:number, style:string, units:string, data: number) {
        const store = this.stores.get(name);
        if (store) {
            const storeVal = get(store);
            store.set(new Store(storeVal.processFunction(data, storeVal.value), style, units, timestamp, storeVal.processFunction))
        }
    }

    public getValue(name: NamedDatatype):any {
        if (!this.stores.has(name)) throw new Error(`Store with name ${name} does not exist`);
        return get(this.stores.get(name)!).value;
    }

    public getWritable(name: NamedDatatype):Writable<Store<any>> {
        if (!this.stores.has(name)) throw new Error(`Store with name ${name} does not exist`);
        return this.stores.get(name)!;
    }
}

/**
 * The Store class is responsible for managing the data store
 * and processing the data before setting it to the store.
 * This allows for processing the data before setting it to the store.
 */
class Store<T> {
    public readonly processFunction: dataConvFun<T>;
    private _value: T;
    private _style: string;
    private _units: string;
    private _timestamp: number;

    constructor(initial:T, style:string, units:string, timestamp: number, processFunction: dataConvFun<T> = (data) => data.valueOf() as unknown as T) {
        this._value = initial;
        this.processFunction = processFunction;
        this._style = style;
        this._units = units;
        this._timestamp = timestamp;
    }

    // public set(data: number, style: string, units:string) {
    //     this._value = this.processFunction(data, this._value);
    //     this._style = style;
    //     this._units = units;
    // }

    public get value():T {
        return this._value;
    }

    public get style():string {
        return this._style;
    }

    get units(): string {
        return this._units;
    }


    get timestamp(): number {
        return this._timestamp;
    }
}
