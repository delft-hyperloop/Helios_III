
export interface TraceFrameAttribute {
  name : string,
  value : string,
}

export interface TraceFrame {
  id : string,
  name : string,
  dlc : number,
  ty : "undefined" | "error" | "normal",
  detail : number | string | TraceFrameAttribute[],
}


export interface TraceEvent {
  deltaTime : string,
  absoluteTime : string,
  timeSinceLast : number,
  key : number,
  bus : string,
  frame : TraceFrame,
}
