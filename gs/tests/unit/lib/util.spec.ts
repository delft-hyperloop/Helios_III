import {describe, it, expect} from "vitest";
import util from "$lib/util/util";


describe("snake to camel", () => {
   it("work correctly", () => {
       const snake = "hello_world";
       const camel = "Hello World";
       expect(util.snakeToCamel(snake)).toBe(camel);
   });
});