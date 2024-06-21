import { Type } from "./Type";

export interface ObjectEntryInformation {
  name: string,
  description?: string,
  friend?: string,
  id: number,
  unit?: string,
  ty: Type,
  plottable: boolean,
}


