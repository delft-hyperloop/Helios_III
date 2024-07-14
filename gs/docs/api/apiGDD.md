# GDD API

## GrandDataDistributor

The GrandDataDistributor class is responsible for fetching data from the backend and distributing it to the appropriate 
stores. This is a singleton to ensure that there are no erroneous multiple instances of the GDD running at the same time.

| Method                                 | Description                                    |
|----------------------------------------|------------------------------------------------|
| `getInstance(): GrandDataDistributor`  | Returns the singleton instance of the GDD.     |
| `start(interval: number): void`        | Starts the GDD with the given interval.        |
| `kill(): void`                         | Stops the GDD.                                 |
| `fetchData(): void`                    | Fetches the data from the back-end.            |
| `processData(data: Datapoint[]): void` | Processes the data received from the back-end. |
| `stores: StoreManager`                 | The store manager of the GDD.                  |


### `processData(data: Datapoint[]): void`) 

This method will be called with the data-points unbuffered from calling the `fetchData()` method. Thus, these data-points
will be of type `Datapoint`: 

```typescript
export type Datapoint = {
    datatype: NamedDatatype,
    value: bigint,
    timestamp: number,
}
```

Using this `.datatype` field the process data method will update the appropriate store with the value received. Therefore,
the stores can only have names of this type. This is ensured by the `NamedDatatype` type which is auto-generated using the
`generate:datatypes` script in the `package.json` file.

| Parameter | Type          | Description                          |
|-----------|---------------|--------------------------------------|
| `data`    | `Datapoint[]` | The data received from the back-end. |

## StoreManager

| Method                                                                                                | Description                                                                            |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------|
| `registerStore(name: NamedDatatype, initial: T, dataConvFun?: (data: bigint, current: T) => T): void` | Register a store with the given name, initial value, and an optional process function. |
| `updateStore(name: NamedDatatype, data: bigint)`                                                      | Update a store with the given name and data.                                           |
| `getWritable(name: NamedDatatype):Writable<any>`                                                         | Get a store with the given name. (Which is any of `NamedDatatype`                      |


## Store

| Method                       | Description                 |
|------------------------------|-----------------------------|
| `set(value: T): void`        | Set the value of the store. |
| `getWritable(): Writable<T>` | Get the writable store.     |