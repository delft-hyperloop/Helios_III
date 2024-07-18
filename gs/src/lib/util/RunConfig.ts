import {RouteStep} from "$lib";
import {metersPerMinuteToByte} from "$lib/util/parsers";


const speedForm = {
  ForwardA: 0,
  BackwardA: 0,
  ForwardB: 0,
  BackwardB: 0,
  ForwardC: 0,
  BackwardC: 0,
  LaneSwitchStraight: 0,
  LaneSwitchCurved: 0,
  StopAndWait: 0,
  BrakeHere: 0,
};

type SpeedFormKey = keyof typeof speedForm;

export class RunConfig {
    private readonly speeds:SpeedFormKey[];
    private routeSteps:RouteStep[];


    constructor(routeSteps: RouteStep[]) {
        this.speeds = Object.keys(speedForm) as SpeedFormKey[];
        this.routeSteps = routeSteps;
    }
}
