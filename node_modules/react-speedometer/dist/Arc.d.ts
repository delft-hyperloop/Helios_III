import { SVGAttributes } from 'react';
interface ArcProps extends SVGAttributes<SVGPathElement> {
    color?: string;
    opacity?: number;
    arcWidth?: number;
    lineCap?: SVGAttributes<SVGPathElement>['strokeLinecap'];
}
export default function Arc({ color, opacity, arcWidth, lineCap, ...rest }: ArcProps): JSX.Element;
export {};
