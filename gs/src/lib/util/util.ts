import {emit} from "@tauri-apps/api/event";
import {RouteStep} from "$lib";

function range(count:number, start?:number, num?:number):number[] {
    return Array.from({length: count}, (_, i) => (num || i) + (start || 0));
}

function snakeToCamel(s:string):string {
    return s.replace(/([-_]\w)/g, g => g[1].toUpperCase())
        .replace(/([A-Z])/g, ' $1')
        .replace(/^./, g => g.toUpperCase())
        .trim();
}

function normalize(value: number, max: number): number {
    return (value / max) * 100;
}

function colourCode(value: number, max: number, saturation:number = 50): string {
    const normalized = normalize(value, max);
    const hue = 120 - (normalized * 1.2);
    return `hsl(${hue}, ${saturation}%, 50%)`;
}

function log(message: string, channel: string) {
    emit(channel, message).then(r => console.log(r));
}

function stepTo3Bit(step: RouteStep): number {
    const mapping: Record<RouteStep, number> = {
        stop: 0,
        andreas: 1,
        straight: 2,
        left: 3,
        right: 4
    };
    return mapping[step];
}

export default {range, snakeToCamel, normalize, colourCode, log, stepTo3Bit};
