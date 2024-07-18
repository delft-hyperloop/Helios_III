/*
 * TemplateLaserSensorsFull_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TemplateLaserSensorsFull".
 *
 * Model version              : 1.54
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Jul 17 17:40:54 2024
 *
 * Target selection: pmp.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TemplateLaserSensorsFull.h"
#include "TemplateLaserSensorsFull_private.h"

/* Invariant block signals (default storage) */
const ConstB_TemplateLaserSensorsFull_T TemplateLaserSensorsFull_ConstB = {
  { -0.0, -0.0, -0.0 }                 /* '<S2>/Gain2' */
};

/* instance parameters */
InstP_TemplateLaserSensorsFull_T TemplateLaserSensorsFull_InstP = {
  /* Variable: CalibrateIMU
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Variable: IMU_Filter
   * Referenced by:
   *   '<S21>/Moving Average6'
   *   '<S23>/Moving Average6'
   *   '<S25>/Moving Average6'
   *   '<S27>/Moving Average6'
   *   '<S29>/Moving Average6'
   *   '<S31>/Moving Average6'
   *   '<S33>/Moving Average6'
   *   '<S35>/Moving Average6'
   */
  0.97,

  /* Variable: IMU_SecondFilter
   * Referenced by:
   *   '<S21>/Moving Average7'
   *   '<S23>/Moving Average7'
   *   '<S25>/Moving Average7'
   *   '<S27>/Moving Average7'
   *   '<S29>/Moving Average7'
   *   '<S31>/Moving Average7'
   *   '<S33>/Moving Average7'
   *   '<S35>/Moving Average7'
   */
  0.97,

  /* Variable: a_A
   * Referenced by: '<Root>/Gain'
   */
  7.395E-7,

  /* Variable: a_A2
   * Referenced by: '<Root>/Gain4'
   */
  7.395E-7,

  /* Variable: a_B
   * Referenced by: '<Root>/Gain1'
   */
  7.395E-7,

  /* Variable: a_B2
   * Referenced by: '<Root>/Gain5'
   */
  7.395E-7,

  /* Variable: a_C
   * Referenced by: '<Root>/Gain2'
   */
  7.395E-7,

  /* Variable: a_C2
   * Referenced by: '<Root>/Gain6'
   */
  7.395E-7,

  /* Variable: a_D
   * Referenced by: '<Root>/Gain3'
   */
  7.395E-7,

  /* Variable: a_D2
   * Referenced by: '<Root>/Gain7'
   */
  7.395E-7,

  /* Variable: b_A
   * Referenced by: '<Root>/Constant1'
   */
  0.00218,

  /* Variable: b_A2
   * Referenced by: '<Root>/Constant5'
   */
  0.00368,

  /* Variable: b_B
   * Referenced by: '<Root>/Constant2'
   */
  0.00361,

  /* Variable: b_B2
   * Referenced by: '<Root>/Constant6'
   */
  0.00503,

  /* Variable: b_C
   * Referenced by: '<Root>/Constant3'
   */
  0.00269,

  /* Variable: b_C2
   * Referenced by: '<Root>/Constant7'
   */
  0.00442,

  /* Variable: b_D
   * Referenced by: '<Root>/Constant4'
   */
  0.00347,

  /* Variable: b_D2
   * Referenced by: '<Root>/Constant8'
   */
  0.0055,

  /* Variable: kalman_pitchdot_gain
   * Referenced by: '<Root>/Gain17'
   */
  -1.0,

  /* Variable: kalman_rolldot_gain
   * Referenced by: '<Root>/Gain15'
   */
  1.0,

  /* Variable: kalman_xdotdot_gain
   * Referenced by:
   *   '<Root>/Gain13'
   *   '<Root>/Gain19'
   *   '<Root>/Gain20'
   *   '<S6>/Gain3'
   *   '<S6>/Gain8'
   */
  1.0,

  /* Variable: kalman_yawdot_gain
   * Referenced by: '<Root>/Gain16'
   */
  1.0,

  /* Variable: kalman_ydotdot_gain
   * Referenced by:
   *   '<Root>/Gain14'
   *   '<Root>/Gain21'
   *   '<Root>/Gain22'
   *   '<S6>/Gain6'
   *   '<S6>/Gain9'
   */
  1.0,

  /* Variable: kalman_zdotdot_gain
   * Referenced by:
   *   '<Root>/Gain18'
   *   '<Root>/Gain23'
   *   '<Root>/Gain24'
   *   '<S6>/Gain5'
   *   '<S6>/Gain7'
   */
  1.0,

  /* Variable: remove_IMU_bias_g
   * Referenced by:
   *   '<S3>/Constant9'
   *   '<S4>/Constant9'
   *   '<S5>/Constant9'
   *   '<S6>/Constant'
   */
  0.0
};
