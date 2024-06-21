import {NodeInformation} from "../../nodes/types/NodeInformation.ts";

export interface ValueTableCellInformation {
    node : NodeInformation,
    entry : string,
    min : number,
    max : number,
}