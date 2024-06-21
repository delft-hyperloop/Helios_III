import { invoke } from "@tauri-apps/api";
import { Value } from "../object_entry/types/Value";


const COMMAND_OE_NODE_NAME = "mother_board";
const COMMAND_OE_NAME = "command";

const EMERGENCY: Value = "EMERGENCY";
const ABORT : Value = "ABORT";
const SHUTDOWN : Value = "SHUTDOWN";
const RESTART : Value = "RESTART";
const CALIBRATE : Value = "CALIBRATE";

const START_45 : Value = "START_45";
const STOP_45: Value = "STOP_45";

const START_LEVITATION : Value = "START_LEVITATION";
const STOP_LEVITATION : Value = "STOP_LEVITATION";

const START_PROPULSION : Value = "START_PROPULSION";
const STOP_PROPULSION : Value = "STOP_PROPULSION";

const START_CONTROLLER : Value = "START_CONTROLLER";
const STOP_CONTROLLER : Value = "STOP_CONTROLLER";

export function sendEmergencyCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(EMERGENCY)
  });
}

export function sendStart45Command() {
  console.log("send precharge command");
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(START_45)
  });
}

export function sendStop45Command() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(STOP_45)
  });
}

export function sendStartLevitationCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(START_LEVITATION)
  });
}

export function sendStopLevitationCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(STOP_LEVITATION)
  });
}


export function sendStartPropulsionCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(START_PROPULSION)
  });
}

export function sendStopPropulsionCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(STOP_PROPULSION)
  });
}

export function sendAbortCommand() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(ABORT)
  });
}

export function sendStartController() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(START_CONTROLLER)
  });
}

export function sendStopController() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(STOP_CONTROLLER)
  });
}

export function sendShutdown() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(SHUTDOWN)
  });
}

export function sendRestart() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(RESTART)
  });
}

export function sendCalibrate() {
  invoke("set_object_entry_value", {
    nodeName: COMMAND_OE_NODE_NAME, objectEntryName: COMMAND_OE_NAME,
    newValueJson: JSON.stringify(CALIBRATE)
  });
}
