import { SVGProps } from 'react';
interface IndicatorProps extends SVGProps<SVGTextElement> {
    fontSize?: number;
    color?: string;
    fontFamily?: string;
    textAnchor?: SVGProps<SVGTextElement>['textAnchor'];
    children?: (fixedValue: string, textProps: {
        transform: string;
    }) => JSX.Element;
}
export default function Indicator({ fontSize, color, fontFamily, children, ...rest }: IndicatorProps): JSX.Element;
export {};
