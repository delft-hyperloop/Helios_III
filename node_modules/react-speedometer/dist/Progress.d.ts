import { SVGAttributes } from 'react';
interface ProgressProps extends SVGAttributes<SVGPathElement> {
    color?: string;
    arcWidth?: number;
    lineCap?: SVGAttributes<SVGPathElement>['strokeLinecap'];
}
export default function Progress({ color, arcWidth, lineCap, ...rest }: ProgressProps): JSX.Element;
export {};
