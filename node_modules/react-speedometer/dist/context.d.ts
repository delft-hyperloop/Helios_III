import { SVGAttributes } from 'react';
interface ContextProps {
    currentFillAngle: number;
    radius: number;
    rotation: number;
    min: number;
    max: number;
    angle: number;
    lineCap: SVGAttributes<SVGPathElement>['strokeLinecap'];
    accentColor: string;
    fontFamily: string;
    value: number;
}
declare const _default: import("react").Context<ContextProps>;
export default _default;
