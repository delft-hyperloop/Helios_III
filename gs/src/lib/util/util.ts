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

export default {range, snakeToCamel, normalize, colourCode};
