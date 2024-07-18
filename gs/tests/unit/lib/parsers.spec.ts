import {describe, expect, it} from "vitest";
import {metersPerMinuteToByte} from "$lib/util/parsers";

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