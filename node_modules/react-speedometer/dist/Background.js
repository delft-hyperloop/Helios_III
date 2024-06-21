import { jsx as _jsx } from "react/jsx-runtime";
import { useContext, useMemo } from 'react';
import Context from './context';
import { getCirclePath } from './utils';
export default function Background({ angle = 360, color = 'black', opacity = 0.5, ...rest }) {
    const { rotation, radius } = useContext(Context);
    const backgroundStart = rotation + angle / 2;
    const backgroundPath = useMemo(() => getCirclePath(radius, radius, radius, -backgroundStart, -backgroundStart + angle), [radius, backgroundStart, angle]);
    return (_jsx("path", { d: backgroundPath, fill: color, fillOpacity: opacity, ...rest }));
}
