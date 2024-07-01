import {describe, expect, it} from "vitest";
import {u64ToDouble, metersPerMinuteToByte} from "$lib/util/parsers";


describe("Parse u64 to double", () => {
    it("works correctly", () => {
        const u64 = BigInt(0x3ff0000000000000n);
        const expected = 1.0;
        expect(u64ToDouble(u64)).toBe(expected);
    });

    it("works correctly with negative", () => {
        const u64 = BigInt(0xbff0000000000000n);
        const expected = -1.0;
        expect(u64ToDouble(u64)).toBe(expected);
    })

    it("works correctly with 0", () => {
        const u64 = BigInt(0x0n);
        const expected = 0.0;
        expect(u64ToDouble(u64)).toBe(expected);
    })

    it("works correctly with big number", () => {
        const u64 = BigInt(0x7ff0000000000000n);
        expect(u64ToDouble(u64)).toBe(Infinity);
    })
});

describe("Parse speed input", () => {
    it("works correctly with good weather input", () => {
        const speed = 10;
        const expected = 130;
        expect(metersPerMinuteToByte(speed)).toBe(expected);
    })

    it('should correctly parse max and min values', () => {
        expect(metersPerMinuteToByte(500)).toBe(255);
        expect(metersPerMinuteToByte(-500)).toBe(0);
    });

    it('should correctly map 0', () => {
        expect(metersPerMinuteToByte(0)).toBe(0);
    });
})