
import {MutableRefObject, useEffect, useRef} from "react";
import {invoke} from "@tauri-apps/api";

function useInterval(callback: () => void, delay: number) {
    const savedCallback: MutableRefObject<any> = useRef();

    // Remember the latest callback.
    useEffect(() => {
        savedCallback.current = callback;
    }, [callback]);

    // Set up the interval.
    useEffect(() => {
        function tick() {
            savedCallback.current();
        }
        if (delay !== null) {
            let id = setInterval(tick, delay);
            return () => clearInterval(id);
        }
    }, [delay]);
}

export function Heartbeat() {

    useInterval(() => {
        invoke("heartbeat").catch(console.error)
    }, 100);

    return <></>
}