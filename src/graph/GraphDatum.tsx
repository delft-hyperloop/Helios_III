
export interface GraphDatum<T, R> {
  values : T[],
  xValue : (value : T) => number,
  yValue : (value : T) => R,
}
