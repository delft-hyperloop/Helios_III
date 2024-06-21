"use strict";

var _interopRequireDefault = require("@babel/runtime/helpers/interopRequireDefault");
Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = void 0;
var _defaultizeValueFormatter = _interopRequireDefault(require("../internals/defaultizeValueFormatter"));
const formatter = ({
  series,
  seriesOrder
}) => {
  return {
    series: (0, _defaultizeValueFormatter.default)(series, v => `(${v.x}, ${v.y})`),
    seriesOrder
  };
};
var _default = exports.default = formatter;