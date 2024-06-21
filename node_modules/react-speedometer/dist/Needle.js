import { jsx as _jsx, jsxs as _jsxs } from "react/jsx-runtime";
import { useContext } from 'react';
import Context from './context';
export default function Needle({ offset = 25, baseWidth = 6, baseOffset = 18, color = 'white', circleRadius = 15, circleColor, strokeLinejoin = 'round', children, }) {
    const { currentFillAngle, radius, accentColor } = useContext(Context);
    const bottom = radius + baseOffset;
    const points = `
    ${radius - baseWidth / 2}, ${bottom} ${radius + baseWidth / 2}, ${bottom} ${radius}, ${offset}
  `;
    const defaultNeedle = (_jsxs("g", { children: [_jsx("circle", { r: circleRadius, cx: radius, cy: radius, fill: circleColor || accentColor }), _jsx("polygon", { points: points, fill: color, strokeWidth: "2", stroke: color, style: { strokeLinejoin } })] }));
    return (_jsx("g", { transform: `rotate(${currentFillAngle}, ${radius}, ${radius})`, children: children ? children() : defaultNeedle }));
}
