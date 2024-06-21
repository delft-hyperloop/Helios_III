import { jsx as _jsx } from "react/jsx-runtime";
import { useContext, useMemo } from 'react';
import Context from './context';
import { getCirclePath } from './utils';
export default function Progress({ color, arcWidth = 5, lineCap, ...rest }) {
    const { accentColor, radius, lineCap: globalLineCap, currentFillAngle, } = useContext(Context);
    const progressPath = useMemo(() => getCirclePath(radius, radius, radius - arcWidth / 2, 0, currentFillAngle), [radius, arcWidth, currentFillAngle]);
    return (_jsx("path", { d: progressPath, stroke: color || accentColor, strokeWidth: arcWidth, strokeLinecap: lineCap || globalLineCap, fill: "transparent", ...rest }));
}
