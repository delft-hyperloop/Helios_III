import { SVGAttributes } from 'react';
interface BackgroundProps extends SVGAttributes<SVGPathElement> {
    angle?: number;
    color?: string;
    opacity?: number;
}
export default function Background({ angle, color, opacity, ...rest }: BackgroundProps): JSX.Element;
export {};
