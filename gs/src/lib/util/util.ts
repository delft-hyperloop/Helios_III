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

export default {range, snakeToCamel, normalize};
