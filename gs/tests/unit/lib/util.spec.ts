import {describe, it, expect} from "vitest";
import util from "$lib/util/util";


describe("snake to camel", () => {
    it("work correctly with 2 words", () => {
       const snake = "hello_world";
       const camel = "Hello World";
       expect(util.snakeToCamel(snake)).toBe(camel);
    });
    it("work correctly with 1 word", () => {
        const snake = "hello";
        const camel = "Hello";
        expect(util.snakeToCamel(snake)).toBe(camel);
    });
    it("work correctly with many words", () => {
        const snake = "hello_world_this_is_a_test";
        const camel = "Hello World This Is A Test";
        expect(util.snakeToCamel(snake)).toBe(camel);
    });
});