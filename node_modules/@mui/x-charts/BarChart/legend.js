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
  const data = seriesOrder.map(seriesId => ({
    color: series[seriesId].color,
    label: series[seriesId].label,
    id: seriesId
  }));
  return data.filter(item => item.label !== undefined);
};
var _default = exports.default = legendGetter;