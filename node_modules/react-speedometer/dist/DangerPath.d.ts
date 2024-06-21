import { SVGAttributes } from 'react';
interface DangerPathProps extends SVGAttributes<SVGPathElement> {
    color?: string;
    angle?: number;
    arcWidth?: number;
    lineCap?: SVGAttributes<SVGPathElement>['strokeLinecap'];
    offset?: number;
}
export default function DangerPath({ color, angle, arcWidth, lineCap, offset, ...rest }: DangerPathProps): JSX.Element;
export {};
