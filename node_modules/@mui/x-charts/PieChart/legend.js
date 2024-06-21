"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = void 0;
const legendGetter = params => {
  const {
    seriesOrder,
    series
  } = params;
  return seriesOrder.flatMap(seriesId => series[seriesId].data.map(item => ({
    color: item.color,
    label: item.label,
    id: item.id
  })).filter(item => item.label !== undefined));
};
var _default = exports.default = legendGetter;