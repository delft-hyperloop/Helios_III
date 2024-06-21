import { jsx as _jsx } from "react/jsx-runtime";
import { useMemo } from 'react';
import SpeedometerContext from './context';
export default function Speedometer({ width = 250, height = width, angle = 250, rotation = -angle / 2, value = 0, min = 0, max = 180, lineCap = 'butt', accentColor = '#00e0ff', fontFamily = 'helvetica', children, }) {
    const radius = width / 2;
    const currentFillAngle = useMemo(() => {
        const clampValue = Math.min(max, Math.max(min, Number(value)));
        return (angle * (clampValue - min)) / (max - min);
    }, [min, max, value, angle]);
    const contextValue = {
        currentFillAngle,
        radius,
        rotation,
        min,
        max,
        angle,
        lineCap,
        accentColor,
        fontFamily,
        value,
    };
    return (_jsx(SpeedometerContext.Provider, { value: contextValue, children: _jsx("svg", { width: width, height: height, children: _jsx("g", { transform: `rotate(${rotation} ${radius} ${radius})`, children: children }) }) }));
}
