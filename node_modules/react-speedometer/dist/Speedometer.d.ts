import { SVGAttributes } from 'react';
export interface SpeedometerProps {
    width?: number;
    height?: number;
    angle?: number;
    rotation?: number;
    value?: number;
    min?: number;
    max?: number;
    lineCap?: SVGAttributes<SVGPathElement>['strokeLinecap'];
    accentColor?: string;
    fontFamily?: string;
    children: JSX.Element | Array<JSX.Element | false>;
}
export default function Speedometer({ width, height, angle, rotation, value, min, max, lineCap, accentColor, fontFamily, children, }: SpeedometerProps): JSX.Element;
