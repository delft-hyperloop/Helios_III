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

function stepTo4Bit(step: RouteStep): number {
    const mapping: Record<RouteStep, number> = {
        ForwardA: 0b0001,
        BackwardsA: 0b0011,
        ForwardB: 0b0100,
        BackwardsB: 0b0101,
        ForwardC: 0b0111,
        BackwardsC: 0b1000,
        LaneSwitchStraight: 0b1001,
        LaneSwitchCurved: 0b1010,
    };
    return mapping[step];
}

export default {range, snakeToCamel, normalize, colourCode, log, stepTo4Bit};
