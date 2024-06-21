"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.useReducedMotion = void 0;
var _web = require("@react-spring/web");
/**
 * Returns `boolean` or `null`, used to automatically
 * set skipAnimations to the value of the user's
 * `prefers-reduced-motion` query.
 *
 * The return value, post-effect, is the value of their prefered setting
 */
const useReducedMotion = () => {
  // Taken from: https://github.com/pmndrs/react-spring/blob/02ec877bbfab0df46da0e4a47d5f68d3e731206a/packages/shared/src/hooks/useReducedMotion.ts#L13

  (0, _web.useIsomorphicLayoutEffect)(() => {
    const mql = window.matchMedia('(prefers-reduced-motion)');
    const handleMediaChange = e => {
      _web.Globals.assign({
        // Modification such the react-spring implementation such that this hook can remove animation but never activate animation.
        skipAnimation: e.matches || undefined
      });
    };
    handleMediaChange(mql);
    mql.addEventListener('change', handleMediaChange);
    return () => {
      mql.removeEventListener('change', handleMediaChange);
    };
  }, []);
};
exports.useReducedMotion = useReducedMotion;