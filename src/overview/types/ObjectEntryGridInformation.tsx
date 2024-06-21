import {NodeInformation} from "../../nodes/types/NodeInformation.ts";

// If interpolate is true min and max must be specified and the numerical values are interpolated.
// if interpolate is false error, warning, ok and tooGood must be specified.
// They contain which values should be displayed in which color.
// error -> red (All values that are not in the other ranges)
// warning -> yellow
// ok -> green
// too good to be true -> blue
// If interpolate is not specified the text field has no special color.
export interface ObjectEntryGridInformation {
    node : NodeInformation,
    entry : string,
    interpolate?: boolean
    min? : number,
    max? : number,
    warning?: number[] | string[],
    ok?: number[] | string[],
    tooGood?: number[] | string[]
}
