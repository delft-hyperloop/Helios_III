/// <reference types="react" />
interface NeedleProps {
    offset?: number;
    baseWidth?: number;
    baseOffset?: number;
    color?: string;
    circleRadius?: number;
    circleColor?: string;
    strokeLinejoin?: 'bevel' | 'miter' | 'round';
    children?: () => JSX.Element;
}
export default function Needle({ offset, baseWidth, baseOffset, color, circleRadius, circleColor, strokeLinejoin, children, }: NeedleProps): JSX.Element;
export {};
