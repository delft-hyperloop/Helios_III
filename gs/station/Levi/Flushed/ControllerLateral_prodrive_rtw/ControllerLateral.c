/*
 * ControllerLateral.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControllerLateral".
 *
 * Model version              : 6.259
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jun 28 18:33:21 2024
 *
 * Target selection: pmp.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControllerLateral.h"
#include "ControllerLateral_private.h"

/* Forward declaration for local functions */
static void ControllerLateral_SystemCore_setup
  (dsp_simulink_MovingAverage_ControllerLateral_T *obj);

/* Forward declaration for local functions */
static real_T ControllerLateral_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj, real_T u);
real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look2_pbinlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], uint32_T prevIndex[], const
                      uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex[0U];
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  prevIndex[0U] = bpIdx;
  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[1U];
    iLeft = 0U;
    iRght = maxIndex[1U];
    found = 0U;
    while (found == 0U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u1 < bp1[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1U] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  prevIndex[1U] = bpIdx;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  iLeft = bpIdx * stride + bpIndices[0U];
  yL_0d0 = table[iLeft];
  yL_0d0 += (table[iLeft + 1U] - yL_0d0) * fractions[0U];
  iLeft += stride;
  yL_0d1 = table[iLeft];
  return (((table[iLeft + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

uint32_T plook_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction, uint32_T *prevIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d_prevIdx(u, bp, *prevIndex, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

real_T intrp2d_l_pw(const uint32_T bpIndex[], const real_T frac[], const real_T
                    table[], const uint32_T stride)
{
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((table[offset_1d + 1U] - yL_0d1) * frac[0U] + yL_0d1) - yL_0d0) *
    frac[1U] + yL_0d0;
}

uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Binary Search using Previous Index */
  bpIndex = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIndex]) {
      iRght = bpIndex - 1U;
      bpIndex = ((bpIndex + iLeft) - 1U) >> 1U;
    } else if (u < bp[bpIndex + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIndex + 1U;
      bpIndex = ((bpIndex + iRght) + 1U) >> 1U;
    }
  }

  return bpIndex;
}

static void ControllerLateral_SystemCore_setup
  (dsp_simulink_MovingAverage_ControllerLateral_T *obj)
{
  real_T varargin_2;
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  flag = (boolean_T)(obj->isInitialized == 1);
  if (flag) {
    obj->TunablePropsChanged = true;
  }

  obj->ForgettingFactor = 0.0;
  obj->TunablePropsChanged = false;
  obj->NumChannels = 1;
  varargin_2 = obj->ForgettingFactor;
  obj->_pobj0.isInitialized = 0;
  flag = (boolean_T)(obj->_pobj0.isInitialized == 1);
  if (flag) {
    obj->_pobj0.TunablePropsChanged = true;
  }

  obj->_pobj0.ForgettingFactor = varargin_2;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    ...
 */
void ControllerLateral_MovingAverage_Init(DW_MovingAverage_ControllerLateral_T
  *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* InitializeConditions for MATLABSystem: '<S22>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S22>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    ...
 */
void ControllerLateral_MovingAverage_Start(DW_MovingAverage_ControllerLateral_T *
  localDW)
{
  /* Start for MATLABSystem: '<S22>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  ControllerLateral_SystemCore_setup(&localDW->obj);
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    ...
 */
void ControllerLateral_MovingAverage(real_T rtu_0, real_T rtu_1,
  B_MovingAverage_ControllerLateral_T *localB,
  DW_MovingAverage_ControllerLateral_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T varargin_1;
  boolean_T p;

  /* MATLABSystem: '<S22>/Moving Average' */
  varargin_1 = localDW->obj.ForgettingFactor;
  p = false;
  if ((varargin_1 == rtu_1) || (((int32_T)rtIsNaN(varargin_1)) && ((int32_T)
        rtIsNaN(rtu_1)))) {
    p = true;
  }

  if (!(int32_T)p) {
    p = (boolean_T)(localDW->obj.isInitialized == 1);
    if (p) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = rtu_1;
  }

  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
    obj = localDW->obj.pStatistic;
    p = (boolean_T)(obj->isInitialized == 1);
    if (p) {
      obj->TunablePropsChanged = true;
    }

    localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  varargin_1 = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  pmLocal = (1.0 - 1.0 / varargin_1) * pmLocal + 1.0 / varargin_1 * rtu_0;
  obj->pwN = lambda * varargin_1 + 1.0;
  obj->pmN = pmLocal;

  /* MATLABSystem: '<S22>/Moving Average' */
  localB->MovingAverage = pmLocal;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    ...
 */
void ControllerLateral_MovingAverage_Term(DW_MovingAverage_ControllerLateral_T
  *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* Terminate for MATLABSystem: '<S22>/Moving Average' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/Moving Average' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_p_Init
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S27>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_n_Start
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  real_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<S27>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  flag = (boolean_T)(localDW->obj.isInitialized == 1);
  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.ForgettingFactor = 0.98;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  varargin_2 = localDW->obj.ForgettingFactor;
  localDW->obj._pobj0.isInitialized = 0;
  flag = (boolean_T)(localDW->obj._pobj0.isInitialized == 1);
  if (flag) {
    localDW->obj._pobj0.TunablePropsChanged = true;
  }

  localDW->obj._pobj0.ForgettingFactor = varargin_2;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S27>/Moving Average' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_ControllerLateral_c_T *localB,
  DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;
  boolean_T flag;

  /* MATLABSystem: '<S27>/Moving Average' */
  if (localDW->obj.ForgettingFactor != 0.98) {
    flag = (boolean_T)(localDW->obj.isInitialized == 1);
    if (flag) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = 0.98;
  }

  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
    obj = localDW->obj.pStatistic;
    flag = (boolean_T)(obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
    }

    localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  pmLocal = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * rtu_0;
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = pmLocal;

  /* MATLABSystem: '<S27>/Moving Average' */
  localB->MovingAverage = pmLocal;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_d_Term
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* Terminate for MATLABSystem: '<S27>/Moving Average' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/Moving Average' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage1_Init(DW_MovingAverage1_ControllerLateral_T
  *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S27>/Moving Average1' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S27>/Moving Average1' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage1_Start
  (DW_MovingAverage1_ControllerLateral_T *localDW)
{
  /* Start for MATLABSystem: '<S27>/Moving Average1' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage1(real_T rtu_0,
  B_MovingAverage1_ControllerLateral_T *localB,
  DW_MovingAverage1_ControllerLateral_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;
  real_T csumrev[499];
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S27>/Moving Average1' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 499; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  csum += rtu_0;
  z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 499.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 497; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  obj->pCumSum = csum;
  for (i = 0; i < 499; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<S27>/Moving Average1' */
  localB->MovingAverage1 = z / 500.0;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage1_Term(DW_MovingAverage1_ControllerLateral_T
  *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;

  /* Terminate for MATLABSystem: '<S27>/Moving Average1' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/Moving Average1' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_h_Init
  (DW_MovingAverage_ControllerLateral_fw_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_n_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S17>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S17>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_p_Start
  (DW_MovingAverage_ControllerLateral_fw_T *localDW)
{
  /* Start for MATLABSystem: '<S17>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_pn(real_T rtu_0,
  B_MovingAverage_ControllerLateral_ca_T *localB,
  DW_MovingAverage_ControllerLateral_fw_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_n_T *obj;
  real_T csumrev[7];
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S17>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 7; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  csum += rtu_0;
  z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 7.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 5; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  obj->pCumSum = csum;
  for (i = 0; i < 7; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<S17>/Moving Average' */
  localB->MovingAverage = z / 8.0;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_p_Term
  (DW_MovingAverage_ControllerLateral_fw_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_n_T *obj;

  /* Terminate for MATLABSystem: '<S17>/Moving Average' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/Moving Average' */
}

static real_T ControllerLateral_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj, real_T u)
{
  real_T csum;
  real_T cumRevIndex;
  real_T y;
  real_T z;
  int32_T k;
  csum = obj->pCumSum + u;
  z = obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] + csum;
  obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] = u;
  if (obj->pCumRevIndex != 1999.0) {
    cumRevIndex = obj->pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (k = 1997; k >= 0; k--) {
      obj->pCumSumRev[k] += obj->pCumSumRev[k + 1];
    }
  }

  y = z / 2000.0;
  obj->pCumSum = csum;
  obj->pCumRevIndex = cumRevIndex;
  return y;
}

/* Model output function */
void ControllerLateral_output(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M)
{
  B_ControllerLateral_T *ControllerLateral_B = ControllerLateral_M->blockIO;
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
  InstP_ControllerLateral_T *ControllerLateral_InstP =
    ControllerLateral_M->ControllerLateral_InstP_ref;
  PrevZCX_ControllerLateral_T *ControllerLateral_PrevZCX =
    ControllerLateral_M->prevZCSigState;
  ExtU_ControllerLateral_T *ControllerLateral_U = (ExtU_ControllerLateral_T *)
    ControllerLateral_M->inputs;
  ExtY_ControllerLateral_T *ControllerLateral_Y = (ExtY_ControllerLateral_T *)
    ControllerLateral_M->outputs;

  /* local block i/o variables */
  real_T rtb_Gain[4];
  real_T rtb_Switch7_e;
  real_T rtb_Switch3_d;
  real_T rtb_Switch1_c;
  real_T rtb_error_j;
  real_T rtb_error_d;
  real_T rtb_Delay2_n[2];
  real_T rtb_Switch2_h;
  real_T rtb_Switch2_o;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  real_T rtb_uDLookupTable2[14];
  real_T rtb_uDLookupTable2_b[14];
  real_T rtb_Gain_p[5];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T Gain;
  real_T Gain3;
  real_T rtb_Add1;
  real_T rtb_Add1_f;
  real_T rtb_Add_i;
  real_T rtb_Add_m;
  real_T rtb_B2mm;
  real_T rtb_Beta;
  real_T rtb_D2mm;
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_DiscreteTimeIntegrator1_o;
  real_T rtb_DiscreteTimeIntegrator_f;
  real_T rtb_DiscreteTimeIntegrator_p;
  real_T rtb_Divide1;
  real_T rtb_Divide1_n;
  real_T rtb_Gain1;
  real_T rtb_Gain1_d;
  real_T rtb_Gain2;
  real_T rtb_Gain2_i;
  real_T rtb_Gain3;
  real_T rtb_Gain_f_idx_0;
  real_T rtb_Gain_f_idx_1;
  real_T rtb_Gain_k;
  real_T rtb_IProdOut;
  real_T rtb_IProdOut_l;
  real_T rtb_Inertia;
  real_T rtb_Sign;
  real_T rtb_Sign_k;
  real_T rtb_Sum;
  real_T rtb_Sum_k;
  real_T rtb_Sum_o;
  real_T rtb_Sum_ok;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  real_T rtb_Switch1_a2;
  real_T rtb_Switch1_e_idx_0;
  real_T rtb_Switch2;
  real_T rtb_Switch2_e;
  real_T rtb_Switch2_k_idx_1;
  real_T rtb_Switch2_m0;
  real_T rtb_Switch3;
  real_T rtb_Switch4_oh;
  real_T rtb_Switch7;
  real_T rtb_Switch_c;
  real_T rtb_Switch_ci;
  real_T rtb_Switch_do;
  real_T rtb_Switch_e;
  real_T rtb_Switch_gx;
  real_T rtb_Switch_hy;
  real_T rtb_Switch_m;
  real_T rtb_Switch_pn;
  real_T rtb_a2;
  real_T rtb_a2_dot;
  real_T rtb_a_n;
  real_T rtb_b;
  real_T rtb_b2;
  real_T rtb_b2_dot;
  real_T rtb_c2;
  real_T rtb_c2_dot;
  real_T rtb_c_a;
  real_T rtb_current;
  real_T rtb_current_a;
  real_T rtb_d;
  real_T rtb_d2;
  real_T rtb_d2_dot;
  real_T rtb_offset;
  real_T rtb_offset_h;
  real_T rtb_uDLookupTable1;
  real_T rtb_uDLookupTable1_b;
  real_T rtb_uDLookupTable3;
  real_T rtb_uDLookupTable3_d;
  int32_T i;
  int32_T rtb_PulseGenerator;
  int32_T rtb_Switch4;
  int32_T rtb_Switch_dw_idx_0;
  int32_T rtb_Switch_dw_idx_1;
  int32_T rtb_Switch_dw_idx_2;
  int32_T rtb_Switch_dw_idx_3;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T rtb_AND_b;
  boolean_T rtb_AND_c;
  boolean_T rtb_Equal_e;
  boolean_T rtb_Equal_f;
  boolean_T rtb_Equal_g;
  boolean_T rtb_GreaterThan1;
  boolean_T rtb_GreaterThan1_e;
  boolean_T rtb_GreaterThan2;
  boolean_T rtb_GreaterThan2_c;
  boolean_T rtb_GreaterThan_d;
  boolean_T rtb_GreaterThan_nv;
  boolean_T rtb_OR3;
  boolean_T rtb_OR3_b;
  boolean_T tmp;

  /* Switch: '<S9>/Switch4' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Constant: '<S9>/Constant7'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   */
  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE >
      ControllerLateral_InstP->LandingTime) {
    rtb_Switch4 = 2;
  } else {
    rtb_Switch4 = 3;
  }

  /* End of Switch: '<S9>/Switch4' */

  /* Logic: '<S9>/OR' incorporates:
   *  Constant: '<S650>/Constant'
   *  Memory: '<S9>/Memory'
   *  RelationalOperator: '<S650>/Compare'
   */
  ControllerLateral_B->OR = (boolean_T)((rtb_Switch4 == 2) || ((int32_T)
    ControllerLateral_DW->Memory_PreviousInput_dc));

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (ControllerLateral_InstP->LateralOperatingMode != 0.0) {
    rtb_Switch1 = ControllerLateral_InstP->LateralOperatingMode;
  } else {
    /* DigitalClock: '<S9>/Digital Clock1' incorporates:
     *  DigitalClock: '<S9>/Digital Clock'
     */
    rtb_Switch1_e_idx_0 = (((ControllerLateral_M->Timing.clockTick0+
      ControllerLateral_M->Timing.clockTickH0* 4294967296.0)) * 0.00025);

    /* Switch: '<S9>/Switch6' incorporates:
     *  Constant: '<S9>/Constant12'
     *  Constant: '<S9>/Constant13'
     *  DigitalClock: '<S9>/Digital Clock1'
     *  Sum: '<S9>/Subtract3'
     */
    if (((ControllerLateral_InstP->RunTime +
          ControllerLateral_InstP->StartupTime) + 2.0) - rtb_Switch1_e_idx_0 >
        0.0) {
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant2'
       *  Constant: '<S9>/Constant3'
       *  Sum: '<S9>/Subtract'
       */
      if ((ControllerLateral_InstP->StartupTime + 2.0) - rtb_Switch1_e_idx_0 >
          0.0) {
        rtb_Switch1 = ControllerLateral_InstP->LateralOperatingMode;
      } else {
        rtb_Switch1 = 1.0;
      }

      /* End of Switch: '<S9>/Switch' */
    } else {
      rtb_Switch1 = 3.0;
    }

    /* End of Switch: '<S9>/Switch6' */
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch7' incorporates:
   *  Constant: '<S9>/Constant11'
   *  Constant: '<S9>/Constant4'
   *  Sum: '<S9>/Subtract1'
   *  Switch: '<S9>/Switch2'
   */
  if (ControllerLateral_B->OR) {
    rtb_Switch7 = 2.0;
  } else if (rtb_Switch1 - 3.0 != 0.0) {
    /* Switch: '<S9>/Switch2' */
    rtb_Switch7 = rtb_Switch1;
  } else {
    rtb_Switch7 = (real_T)rtb_Switch4;
  }

  /* End of Switch: '<S9>/Switch7' */

  /* Outport: '<Root>/Mode' */
  ControllerLateral_Y->Mode = rtb_Switch7;

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Constant'
   *  Constant: '<S236>/Constant1'
   *  Constant: '<S236>/Constant2'
   *  Constant: '<S236>/Constant3'
   *  RelationalOperator: '<S236>/Equal'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_Switch = 0.18;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S236>/Switch' */

  /* RelationalOperator: '<S9>/Equal' incorporates:
   *  Constant: '<S9>/Constant11'
   */
  ControllerLateral_B->Equal = (boolean_T)(2.0 == rtb_Switch7);

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/G_A2'
   *  Inport: '<Root>/G_B2'
   *  Inport: '<Root>/G_C2'
   *  Inport: '<Root>/G_D2'
   */
  rtb_Gain[0] = 1000.0 * ControllerLateral_U->G_A2;
  rtb_Gain[1] = 1000.0 * ControllerLateral_U->G_B2;
  rtb_Gain[2] = 1000.0 * ControllerLateral_U->G_C2;
  rtb_Gain[3] = 1000.0 * ControllerLateral_U->G_D2;

  /* Constant: '<S241>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[2],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvfp,
    &ControllerLateral_DW->MovingAverage1_pnaevvfp);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpgh,
     &ControllerLateral_DW->MovingAverage_pnaevvfpgh);

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_do = ControllerLateral_B->MovingAverage_pnaevvfpgh.MovingAverage;
  } else {
    rtb_Switch_do = ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage;
  }

  /* End of Switch: '<S241>/Switch' */

  /* Gain: '<S238>/Gain' */
  Gain = 0.001 * rtb_Switch_do;

  /* DiscreteIntegrator: '<S238>/Discrete-Time Integrator1' */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = Gain;
  }

  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState <= 0)) ||
      ((!(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = Gain;
  }

  rtb_c2 = ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE;

  /* Switch: '<S236>/Switch4' incorporates:
   *  Constant: '<S236>/Constant5'
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator1'
   *  Gain: '<S238>/Gain7'
   */
  if (ControllerLateral_InstP->UseComplementaryBD > 0.0) {
    rtb_Switch4_oh = 1000.0 *
      ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE;
  } else {
    rtb_Switch4_oh = rtb_Switch_do;
  }

  /* End of Switch: '<S236>/Switch4' */

  /* Constant: '<S239>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[0],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevv,
    &ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfp,
     &ControllerLateral_DW->MovingAverage_pnaevvfp);

  /* Switch: '<S239>/Switch' incorporates:
   *  Constant: '<S239>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_hy = ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage;
  } else {
    rtb_Switch_hy = ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Gain: '<S238>/Gain3' */
  Gain3 = 0.001 * rtb_Switch_hy;

  /* DiscreteIntegrator: '<S238>/Discrete-Time Integrator' */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l = Gain3;
  }

  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState <= 0)) || ((
        !(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l = Gain3;
  }

  rtb_a2 = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l;

  /* Switch: '<S236>/Switch3' incorporates:
   *  Constant: '<S236>/Constant5'
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator'
   *  Gain: '<S238>/Gain6'
   */
  if (ControllerLateral_InstP->UseComplementaryBD > 0.0) {
    rtb_Switch3 = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l;
  } else {
    rtb_Switch3 = rtb_Switch_hy;
  }

  /* End of Switch: '<S236>/Switch3' */

  /* Gain: '<S236>/Gain' incorporates:
   *  Sum: '<S236>/Add'
   */
  rtb_Gain_k = (rtb_Switch4_oh - rtb_Switch3) * 0.124;

  /* Sum: '<S236>/Add6' incorporates:
   *  Sum: '<S236>/Add1'
   */
  rtb_a_n = (rtb_Gain_k + rtb_Switch3) - rtb_Switch;

  /* DiscreteIntegrator: '<S237>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S236>/Constant6'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING_o != 0)
  {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g = 0.0;
  }

  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g = 0.0;
  }

  rtb_d2 = ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g;

  /* Gain: '<S237>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S237>/Discrete-Time Integrator1'
   */
  rtb_D2mm = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g;

  /* Constant: '<S242>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[3],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvfpg,
    &ControllerLateral_DW->MovingAverage1_pnaevvfpg);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpgh5,
     &ControllerLateral_DW->MovingAverage_pnaevvfpgh5);

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_pn = ControllerLateral_B->MovingAverage_pnaevvfpgh5.MovingAverage;
  } else {
    rtb_Switch_pn = ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage;
  }

  /* End of Switch: '<S242>/Switch' */

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S236>/Constant5'
   */
  if (ControllerLateral_InstP->UseComplementaryBD > 0.0) {
    rtb_Switch2 = rtb_D2mm;
  } else {
    rtb_Switch2 = rtb_Switch_pn;
  }

  /* End of Switch: '<S236>/Switch2' */

  /* DiscreteIntegrator: '<S237>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S236>/Constant6'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_n != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = 0.0;
  }

  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = 0.0;
  }

  rtb_b2 = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d;

  /* Gain: '<S237>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S237>/Discrete-Time Integrator'
   */
  rtb_B2mm = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d;

  /* Constant: '<S240>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[1],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvf,
    &ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpg,
     &ControllerLateral_DW->MovingAverage_pnaevvfpg);

  /* Switch: '<S240>/Switch' incorporates:
   *  Constant: '<S240>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_m = ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage;
  } else {
    rtb_Switch_m = ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage;
  }

  /* End of Switch: '<S240>/Switch' */

  /* Switch: '<S236>/Switch1' incorporates:
   *  Constant: '<S236>/Constant5'
   */
  if (ControllerLateral_InstP->UseComplementaryBD > 0.0) {
    rtb_Switch1_a2 = rtb_B2mm;
  } else {
    rtb_Switch1_a2 = rtb_Switch_m;
  }

  /* End of Switch: '<S236>/Switch1' */

  /* Gain: '<S236>/Gain1' incorporates:
   *  Sum: '<S236>/Add3'
   */
  rtb_Gain1 = (rtb_Switch2 - rtb_Switch1_a2) * 0.124;

  /* Sum: '<S236>/Add4' */
  rtb_b = rtb_Gain1 + rtb_Switch1_a2;

  /* Sum: '<S236>/Add7' incorporates:
   *  Sum: '<S236>/Add2'
   */
  rtb_c_a = (rtb_Switch4_oh - rtb_Gain_k) - rtb_Switch;

  /* Sum: '<S236>/Add5' */
  rtb_d = rtb_Switch2 - rtb_Gain1;

  /* Outport: '<Root>/Linpos Lateral' */
  ControllerLateral_Y->LinposLateral[0] = rtb_a_n;
  ControllerLateral_Y->LinposLateral[1] = rtb_b;
  ControllerLateral_Y->LinposLateral[2] = rtb_c_a;
  ControllerLateral_Y->LinposLateral[3] = rtb_d;

  /* Product: '<S17>/Divide' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant1'
   */
  rtb_Switch1_e_idx_0 = ControllerLateral_InstP->Mass /
    ControllerLateral_InstP->ReferenceMass;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Inport: '<Root>/I_Front_m'
   */
  rtb_Gain2 = ControllerLateral_InstP->PolarityFront *
    ControllerLateral_U->I_Front_m;

  /* Gain: '<Root>/Gain3' incorporates:
   *  Inport: '<Root>/I_Back_m'
   */
  rtb_Gain3 = ControllerLateral_InstP->PolarityBack *
    ControllerLateral_U->I_Back_m;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (ControllerLateral_InstP->MeasureCurrent != 0.0) {
    /* Gain: '<S19>/Gain' */
    rtb_Gain_f_idx_0 = -rtb_Gain2;
    rtb_Gain_f_idx_1 = -rtb_Gain3;
  } else {
    /* Gain: '<S19>/Gain' incorporates:
     *  Delay: '<Root>/Delay1'
     */
    rtb_Gain_f_idx_0 = -ControllerLateral_DW->Delay1_DSTATE[0];
    rtb_Gain_f_idx_1 = -ControllerLateral_DW->Delay1_DSTATE[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S130>/Constant4'
   *  Sum: '<S130>/Subtract5'
   */
  if (rtb_Switch7 - -1.0 != 0.0) {
    rtb_Switch_ci = 0.0;
  } else {
    rtb_Switch_ci = rtb_Gain_f_idx_0;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Logic: '<S130>/OR' incorporates:
   *  Constant: '<S130>/Constant3'
   *  RelationalOperator: '<S133>/FixPt Relational Operator'
   *  RelationalOperator: '<S134>/FixPt Relational Operator'
   *  UnitDelay: '<S133>/Delay Input1'
   *  UnitDelay: '<S134>/Delay Input1'
   */
  ControllerLateral_B->OR_h = (boolean_T)
    ((ControllerLateral_InstP->lat_zero_reset !=
      ControllerLateral_DW->DelayInput1_DSTATE) || ((int32_T)
      ControllerLateral_B->Equal != (int32_T)
      ControllerLateral_DW->DelayInput1_DSTATE_a));

  /* DiscreteIntegrator: '<S168>/Integrator' */
  if ((((int32_T)ControllerLateral_B->OR_h) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState <= 0)) || ((!(int32_T)
        ControllerLateral_B->OR_h) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState == 1))) {
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
  }

  /* SampleTimeMath: '<S163>/Tsamp' incorporates:
   *  Gain: '<S160>/Derivative Gain'
   *
   * About '<S163>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  ControllerLateral_B->Tsamp = 0.0 * rtb_Switch_ci * 4000.0;

  /* Delay: '<S161>/UD' */
  if ((((int32_T)ControllerLateral_PrevZCX->UD_Reset_ZCE == 1) != (int32_T)
       ControllerLateral_B->OR_h) && ((int32_T)
       ControllerLateral_PrevZCX->UD_Reset_ZCE != 3)) {
    ControllerLateral_DW->UD_DSTATE = 0.0;
  }

  ControllerLateral_PrevZCX->UD_Reset_ZCE = (ZCSigState)
    ControllerLateral_B->OR_h;

  /* Sum: '<S177>/Sum' incorporates:
   *  Delay: '<S161>/UD'
   *  DiscreteIntegrator: '<S168>/Integrator'
   *  Gain: '<S173>/Proportional Gain'
   *  Sum: '<S161>/Diff'
   */
  rtb_Sum = (0.0 * rtb_Switch_ci + ControllerLateral_DW->Integrator_DSTATE) +
    (ControllerLateral_B->Tsamp - ControllerLateral_DW->UD_DSTATE);

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Setpoint'
   */
  rtb_Add_i = rtb_Sum + ControllerLateral_InstP->ReferenceLateralOffsets[0];

  /* DiscretePulseGenerator: '<S16>/Pulse Generator' */
  rtb_PulseGenerator = ((real_T)ControllerLateral_DW->clockTickCounter <
                        ControllerLateral_InstP->BeamErrorTime / 0.00025) &&
    (ControllerLateral_DW->clockTickCounter >= 0) ? 2 : 0;
  if ((real_T)ControllerLateral_DW->clockTickCounter >=
      ControllerLateral_InstP->BeamErrorTime * 2.0 / 0.00025 - 1.0) {
    ControllerLateral_DW->clockTickCounter = 0;
  } else {
    ControllerLateral_DW->clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S16>/Pulse Generator' */

  /* Product: '<S16>/Product1' incorporates:
   *  Constant: '<S16>/Constant6'
   *  Constant: '<S16>/Constant9'
   *  Sum: '<S16>/Subtract7'
   */
  ControllerLateral_B->Product1 = ((real_T)rtb_PulseGenerator - 1.0) *
    ControllerLateral_InstP->LateralBeamOffsets;

  /* Constant: '<S22>/Constant' */
  ControllerLateral_MovingAverage(ControllerLateral_B->Product1,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1, &ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage, &ControllerLateral_DW->MovingAverage);

  /* Switch: '<S16>/Switch7' incorporates:
   *  Constant: '<S16>/Constant4'
   */
  if (ControllerLateral_InstP->LateralBeamOffsetsBackDelay > 0.0) {
    /* Switch: '<S16>/Switch7' incorporates:
     *  Delay: '<S16>/Delay1'
     */
    rtb_Switch7_e = ControllerLateral_DW->Delay1_DSTATE_b[0];
  } else {
    /* Switch: '<S16>/Switch7' */
    rtb_Switch7_e = ControllerLateral_B->Product1;
  }

  /* End of Switch: '<S16>/Switch7' */

  /* Constant: '<S23>/Constant' */
  ControllerLateral_MovingAverage(rtb_Switch7_e,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_p,
    &ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_p.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_p,
     &ControllerLateral_DW->MovingAverage_p);

  /* Switch: '<S16>/Switch3' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (ControllerLateral_InstP->LateralSineSwitches[0] != 0.0) {
    /* Switch: '<S16>/Switch3' incorporates:
     *  Sin: '<S16>/Sine Wave1'
     */
    rtb_Switch3_d = sin((real_T)ControllerLateral_DW->counter * 2.0 *
                        3.1415926535897931 / floor
                        (ControllerLateral_InstP->SineTime / 0.00025)) *
      ControllerLateral_InstP->LateralBeamOffsets;
  } else {
    /* Switch: '<S16>/Switch3' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    rtb_Switch3_d = 0.0;
  }

  /* End of Switch: '<S16>/Switch3' */

  /* Constant: '<S24>/Constant' */
  ControllerLateral_MovingAverage(rtb_Switch3_d,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pn,
    &ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pn.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pn,
     &ControllerLateral_DW->MovingAverage_pn);

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (ControllerLateral_InstP->LateralSineSwitches[1] != 0.0) {
    /* Switch: '<S16>/Switch1' incorporates:
     *  Sin: '<S16>/Sine Wave2'
     */
    rtb_Switch1_c = sin((real_T)ControllerLateral_DW->counter_k * 2.0 *
                        3.1415926535897931 / floor
                        (ControllerLateral_InstP->SineTime / 0.00025)) *
      (ControllerLateral_InstP->LateralBeamOffsets *
       ControllerLateral_InstP->LateralBeamOffsetsFactor);
  } else {
    /* Switch: '<S16>/Switch1' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    rtb_Switch1_c = 0.0;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Constant: '<S25>/Constant' */
  ControllerLateral_MovingAverage(rtb_Switch1_c,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pna,
    &ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pna.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pna,
     &ControllerLateral_DW->MovingAverage_pna);

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/Constant2'
   *  Constant: '<S24>/Constant1'
   *  Sum: '<S16>/Subtract2'
   *  Switch: '<S24>/Switch'
   *  Switch: '<S25>/Switch'
   */
  if (rtb_Switch7 - 7.0 != 0.0) {
    /* Switch: '<S16>/Switch4' incorporates:
     *  Constant: '<S16>/Constant7'
     *  Constant: '<S22>/Constant1'
     *  Sum: '<S16>/Subtract6'
     *  Switch: '<S22>/Switch'
     *  Switch: '<S23>/Switch'
     */
    if (rtb_Switch7 - 5.0 != 0.0) {
      rtb_Gain_f_idx_0 = 0.0;
      rtb_Switch2_k_idx_1 = 0.0;
    } else if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
      /* Switch: '<S22>/Switch' */
      rtb_Gain_f_idx_0 = ControllerLateral_B->MovingAverage.MovingAverage;

      /* Switch: '<S23>/Switch' */
      rtb_Switch2_k_idx_1 = ControllerLateral_B->MovingAverage_p.MovingAverage;
    } else {
      rtb_Gain_f_idx_0 = ControllerLateral_B->MovingAverage1.MovingAverage;
      rtb_Switch2_k_idx_1 = ControllerLateral_B->MovingAverage1_p.MovingAverage;
    }

    /* End of Switch: '<S16>/Switch4' */
  } else if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    /* Switch: '<S24>/Switch' */
    rtb_Gain_f_idx_0 = ControllerLateral_B->MovingAverage_pn.MovingAverage;

    /* Switch: '<S25>/Switch' */
    rtb_Switch2_k_idx_1 = ControllerLateral_B->MovingAverage_pna.MovingAverage;
  } else {
    rtb_Gain_f_idx_0 = ControllerLateral_B->MovingAverage1_pn.MovingAverage;
    rtb_Switch2_k_idx_1 = ControllerLateral_B->MovingAverage1_pna.MovingAverage;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S644>/Switch1' incorporates:
   *  Constant: '<S236>/Constant4'
   *  Constant: '<S243>/Mode 1 AG5'
   *  Constant: '<S646>/Constant'
   *  Constant: '<S647>/Constant'
   *  RelationalOperator: '<S646>/Compare'
   *  RelationalOperator: '<S647>/Compare'
   *  Sum: '<S243>/Subtract2'
   *  Switch: '<S644>/Switch'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_offset = rtb_a_n - ControllerLateral_InstP->LS_curved_AG;
  } else if (ControllerLateral_InstP->LS_mode == 1.0) {
    /* Switch: '<S644>/Switch' incorporates:
     *  Constant: '<S243>/Mode 1 AG'
     *  Sum: '<S243>/Subtract4'
     */
    rtb_offset = ControllerLateral_InstP->LS_straight_AG - rtb_b;
  } else {
    /* Switch: '<S644>/Switch' incorporates:
     *  Gain: '<S243>/Gain'
     *  Sum: '<S243>/Subtract'
     */
    rtb_offset = (rtb_a_n - rtb_b) * 0.5;
  }

  /* End of Switch: '<S644>/Switch1' */

  /* Sum: '<S17>/Sum' incorporates:
   *  Sum: '<S17>/Sum1'
   */
  rtb_error_j = (rtb_Add_i + rtb_Gain_f_idx_0) - rtb_offset;
  ControllerLateral_MovingAverage_pn(rtb_error_j,
    &ControllerLateral_B->MovingAverage_pnaev,
    &ControllerLateral_DW->MovingAverage_pnaev);

  /* RelationalOperator: '<S17>/Equal' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  ControllerLateral_B->Equal_p = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S61>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S56>/Filter'
   */
  tmp = (boolean_T)!(int32_T)ControllerLateral_B->Equal_p;
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_o <= 0)) || (((int32_T)
        tmp) && ((int32_T)ControllerLateral_DW->Integrator_PrevResetState_o == 1)))
  {
    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S56>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState <= 0)) || (((int32_T)tmp) &&
       ((int32_T)ControllerLateral_DW->Filter_PrevResetState == 1))) {
    ControllerLateral_DW->Filter_DSTATE = 0.0;
  }

  /* Product: '<S64>/NProd Out' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant3'
   *  Constant: '<S27>/N'
   *  DiscreteIntegrator: '<S56>/Filter'
   *  Product: '<S27>/Divide'
   *  Product: '<S55>/DProd Out'
   *  Sum: '<S56>/SumD'
   */
  ControllerLateral_B->NProdOut =
    (ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
     ControllerLateral_InstP->L_K_d - ControllerLateral_DW->Filter_DSTATE) *
    (6.2831853071795862 / ControllerLateral_InstP->L_T_c);

  /* Sum: '<S70>/Sum' incorporates:
   *  Constant: '<S27>/Constant1'
   *  DiscreteIntegrator: '<S61>/Integrator'
   *  Product: '<S66>/PProd Out'
   */
  rtb_Sum_k = (ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
               ControllerLateral_InstP->L_K_p +
               ControllerLateral_DW->Integrator_DSTATE_n) +
    ControllerLateral_B->NProdOut;

  /* Product: '<S17>/Divide1' incorporates:
   *  Product: '<S17>/Divide'
   */
  rtb_Divide1 = rtb_Switch1_e_idx_0 * rtb_Sum_k;

  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S131>/Constant1'
   *  Constant: '<S131>/Constant4'
   *  Sum: '<S131>/Subtract5'
   */
  if (rtb_Switch7 - -1.0 != 0.0) {
    rtb_Switch_gx = 0.0;
  } else {
    rtb_Switch_gx = rtb_Gain_f_idx_1;
  }

  /* End of Switch: '<S131>/Switch' */

  /* DiscreteIntegrator: '<S219>/Integrator' */
  if ((((int32_T)ControllerLateral_B->OR_h) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_m <= 0)) || ((!(int32_T)
        ControllerLateral_B->OR_h) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_m == 1))) {
    ControllerLateral_DW->Integrator_DSTATE_o = 0.0;
  }

  /* SampleTimeMath: '<S214>/Tsamp' incorporates:
   *  Gain: '<S211>/Derivative Gain'
   *
   * About '<S214>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  ControllerLateral_B->Tsamp_c = 0.0 * rtb_Switch_gx * 4000.0;

  /* Delay: '<S212>/UD' */
  if ((((int32_T)ControllerLateral_PrevZCX->UD_Reset_ZCE_d == 1) != (int32_T)
       ControllerLateral_B->OR_h) && ((int32_T)
       ControllerLateral_PrevZCX->UD_Reset_ZCE_d != 3)) {
    ControllerLateral_DW->UD_DSTATE_o = 0.0;
  }

  ControllerLateral_PrevZCX->UD_Reset_ZCE_d = (ZCSigState)
    ControllerLateral_B->OR_h;

  /* Sum: '<S228>/Sum' incorporates:
   *  Delay: '<S212>/UD'
   *  DiscreteIntegrator: '<S219>/Integrator'
   *  Gain: '<S224>/Proportional Gain'
   *  Sum: '<S212>/Diff'
   */
  rtb_Sum_ok = (0.0 * rtb_Switch_gx + ControllerLateral_DW->Integrator_DSTATE_o)
    + (ControllerLateral_B->Tsamp_c - ControllerLateral_DW->UD_DSTATE_o);

  /* Sum: '<S19>/Add1' incorporates:
   *  Constant: '<S19>/Setpoint'
   */
  rtb_Add1 = rtb_Sum_ok + ControllerLateral_InstP->ReferenceLateralOffsets[1];

  /* Switch: '<S645>/Switch1' incorporates:
   *  Constant: '<S236>/Constant4'
   *  Constant: '<S243>/Mode 1 AG4'
   *  Constant: '<S648>/Constant'
   *  Constant: '<S649>/Constant'
   *  RelationalOperator: '<S648>/Compare'
   *  RelationalOperator: '<S649>/Compare'
   *  Sum: '<S243>/Subtract3'
   *  Switch: '<S645>/Switch'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_offset_h = rtb_c_a - ControllerLateral_InstP->LS_curved_AG;
  } else if (ControllerLateral_InstP->LS_mode == 1.0) {
    /* Switch: '<S645>/Switch' incorporates:
     *  Constant: '<S243>/Mode 1 AG6'
     *  Sum: '<S243>/Subtract5'
     */
    rtb_offset_h = ControllerLateral_InstP->LS_straight_AG - rtb_d;
  } else {
    /* Switch: '<S645>/Switch' incorporates:
     *  Gain: '<S243>/Gain1'
     *  Sum: '<S243>/Subtract1'
     */
    rtb_offset_h = (rtb_c_a - rtb_d) * 0.5;
  }

  /* End of Switch: '<S645>/Switch1' */

  /* Sum: '<S18>/Sum' incorporates:
   *  Sum: '<S18>/Sum1'
   */
  rtb_error_d = (rtb_Add1 + rtb_Switch2_k_idx_1) - rtb_offset_h;
  ControllerLateral_MovingAverage_pn(rtb_error_d,
    &ControllerLateral_B->MovingAverage_pnaevvf,
    &ControllerLateral_DW->MovingAverage_pnaevvf);

  /* RelationalOperator: '<S18>/Equal' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  ControllerLateral_B->Equal_b = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S108>/Filter'
   */
  tmp = (boolean_T)!(int32_T)ControllerLateral_B->Equal_b;
  if ((((int32_T)ControllerLateral_B->Equal_b) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_j <= 0)) || (((int32_T)
        tmp) && ((int32_T)ControllerLateral_DW->Integrator_PrevResetState_j == 1)))
  {
    ControllerLateral_DW->Integrator_DSTATE_m = 0.0;
  }

  /* DiscreteIntegrator: '<S108>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_b) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState_j <= 0)) || (((int32_T)tmp) &&
       ((int32_T)ControllerLateral_DW->Filter_PrevResetState_j == 1))) {
    ControllerLateral_DW->Filter_DSTATE_a = 0.0;
  }

  /* Product: '<S116>/NProd Out' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S79>/Constant3'
   *  Constant: '<S79>/N'
   *  DiscreteIntegrator: '<S108>/Filter'
   *  Product: '<S107>/DProd Out'
   *  Product: '<S79>/Divide'
   *  Sum: '<S108>/SumD'
   */
  ControllerLateral_B->NProdOut_k =
    (ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage *
     ControllerLateral_InstP->L_K_d - ControllerLateral_DW->Filter_DSTATE_a) *
    (6.2831853071795862 / ControllerLateral_InstP->L_T_c);

  /* Sum: '<S122>/Sum' incorporates:
   *  Constant: '<S79>/Constant1'
   *  DiscreteIntegrator: '<S113>/Integrator'
   *  Product: '<S118>/PProd Out'
   */
  rtb_Sum_o = (ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage *
               ControllerLateral_InstP->L_K_p +
               ControllerLateral_DW->Integrator_DSTATE_m) +
    ControllerLateral_B->NProdOut_k;

  /* Product: '<S18>/Divide1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Product: '<S18>/Divide'
   */
  rtb_Divide1_n = ControllerLateral_InstP->Mass /
    ControllerLateral_InstP->ReferenceMass * rtb_Sum_o;

  /* Gain: '<S3>/Gain' incorporates:
   *  Constant: '<S3>/1'
   *  Constant: '<S3>/2'
   *  Math: '<S3>/Square'
   *  Math: '<S3>/Square1'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Inertia = (ControllerLateral_InstP->PodWidth *
                 ControllerLateral_InstP->PodWidth +
                 ControllerLateral_InstP->PodLength *
                 ControllerLateral_InstP->PodLength) *
    (ControllerLateral_InstP->Mass / 12.0);

  /* Product: '<S11>/Divide' incorporates:
   *  Constant: '<S11>/Beta'
   */
  rtb_Beta = 0.140625 * ControllerLateral_InstP->Mass / rtb_Inertia;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<S11>/MATLAB Function'
   */
  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S652>:1' */
  /* '<S652>:1:2' */
  /* '<S652>:1:3' */
  if (ControllerLateral_InstP->SemiCentralized > 0.0) {
    /* MATLAB Function: '<S11>/MATLAB Function' */
    rtb_Switch1_e_idx_0 = rtb_Beta * rtb_Beta;
    rtb_Switch1_e_idx_0 = ((rtb_Switch1_e_idx_0 + 1.0) * rtb_Divide1 / rtb_Beta
      + (rtb_Switch1_e_idx_0 + -1.0) * rtb_Divide1_n / rtb_Beta) * 0.25 + 0.5 *
      rtb_Divide1;
    rtb_Gain_f_idx_1 = ((rtb_Beta * rtb_Beta + 1.0) * rtb_Divide1_n / rtb_Beta +
                        (rtb_Beta * rtb_Beta + -1.0) * rtb_Divide1 / rtb_Beta) *
      0.25 + 0.5 * rtb_Divide1_n;
  } else {
    rtb_Switch1_e_idx_0 = rtb_Divide1;
    rtb_Gain_f_idx_1 = rtb_Divide1_n;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outport: '<Root>/Control SIgnals Lateral' */
  ControllerLateral_Y->ControlSIgnalsLateral[0] = rtb_Switch1_e_idx_0;
  ControllerLateral_Y->ControlSIgnalsLateral[1] = rtb_Gain_f_idx_1;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain_p[i] = -ControllerLateral_InstP->LateralOffsetsHEMSMotor[i];
  }

  /* End of Gain: '<S10>/Gain' */

  /* Gain: '<S10>/Gain1' incorporates:
   *  Sum: '<S10>/Add8'
   */
  rtb_Gain1_d = (rtb_offset + rtb_Gain_p[0]) *
    ControllerLateral_InstP->FrontGain;

  /* Gain: '<S10>/Gain2' incorporates:
   *  Sum: '<S10>/Add9'
   */
  rtb_Gain2_i = (rtb_offset_h + rtb_Gain_p[1]) *
    -ControllerLateral_InstP->BackGain;

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Inport: '<Root>/hems1'
   *  Inport: '<Root>/hems2'
   *  Inport: '<Root>/motor1'
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  Sum: '<S10>/Add2'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S10>/Add6'
   */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S651>:1' */
  /* '<S651>:1:4' */
  /* '<S651>:1:5' */
  rtb_Add_m = rtb_Switch1_e_idx_0 -
    (-ControllerLateral_InstP->lateral_over_vertical_force_motor *
     ControllerLateral_U->motor1 * (rtb_Gain1_d + rtb_Gain_p[4]) - ((rtb_Gain1_d
       + rtb_Gain_p[2]) * ControllerLateral_U->hems1 + (rtb_Gain1_d +
       rtb_Gain_p[3]) * ControllerLateral_U->hems2) *
     ControllerLateral_InstP->lateral_over_vertical_force_hems);

  /* Sum: '<S10>/Add1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Inport: '<Root>/hems3'
   *  Inport: '<Root>/hems4'
   *  Inport: '<Root>/motor2'
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  Sum: '<S10>/Add4'
   *  Sum: '<S10>/Add5'
   *  Sum: '<S10>/Add7'
   */
  rtb_Add1_f = rtb_Gain_f_idx_1 -
    (-ControllerLateral_InstP->lateral_over_vertical_force_motor *
     ControllerLateral_U->motor2 * (rtb_Gain2_i + rtb_Gain_p[4]) - ((rtb_Gain2_i
       + rtb_Gain_p[2]) * ControllerLateral_U->hems3 + (rtb_Gain2_i +
       rtb_Gain_p[3]) * ControllerLateral_U->hems4) *
     ControllerLateral_InstP->lateral_over_vertical_force_hems);

  /* Outport: '<Root>/Control Signals Lateral Final' */
  ControllerLateral_Y->ControlSignalsLateralFinal[0] = rtb_Add_m;
  ControllerLateral_Y->ControlSignalsLateralFinal[1] = rtb_Add1_f;

  /* Outport: '<Root>/OffsetFront' */
  ControllerLateral_Y->OffsetFront = rtb_offset;

  /* Outport: '<Root>/OffsetBack' */
  ControllerLateral_Y->OffsetBack = rtb_offset_h;

  /* RelationalOperator: '<Root>/Equal' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   */
  rtb_Equal_e = (boolean_T)(ControllerLateral_InstP->LateralOperatingMode == 2.0);

  /* Signum: '<S15>/Sign' */
  if (rtb_Add_m < 0.0) {
    rtb_Sign = -1.0;
  } else if (rtb_Add_m > 0.0) {
    rtb_Sign = 1.0;
  } else if (rtb_Add_m == 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = (rtNaN);
  }

  /* End of Signum: '<S15>/Sign' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Saturate: '<S1>/Saturation1'
   */
  if (rtb_Sign > 0.0) {
    /* Saturate: '<S1>/Saturation1' */
    if (rtb_b > 25.0) {
      rtb_Switch_c = 25.0;
    } else if (rtb_b < 2.0) {
      rtb_Switch_c = 2.0;
    } else {
      rtb_Switch_c = rtb_b;
    }
  } else if (rtb_a_n > 25.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_c = 25.0;
  } else if (rtb_a_n < 2.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_c = 2.0;
  } else {
    rtb_Switch_c = rtb_a_n;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Lookup_n-D: '<S15>/2-D Lookup Table2' incorporates:
   *  Constant: '<S15>/Constant'
   *  Switch: '<S15>/Switch'
   */
  bpIndices[1U] = plook_binxp(rtb_Switch_c, ControllerLateral_ConstP.pooled26,
    100U, &rtb_Switch1_e_idx_0, &ControllerLateral_DW->m_Cache02);
  fractions[1U] = rtb_Switch1_e_idx_0;
  for (i = 0; i < 14; i++) {
    bpIndices[0U] = plook_binxp(ControllerLateral_ConstP.pooled24[i],
      ControllerLateral_ConstP.pooled24, 13U, &rtb_Switch1_e_idx_0,
      &ControllerLateral_DW->m_Cache01[i]);
    fractions[0U] = rtb_Switch1_e_idx_0;
    rtb_uDLookupTable2[i] = intrp2d_l_pw(bpIndices, fractions,
      ControllerLateral_ConstP.pooled25, 14U);
  }

  /* End of Lookup_n-D: '<S15>/2-D Lookup Table2' */

  /* Lookup_n-D: '<S15>/2-D Lookup Table1' incorporates:
   *  Abs: '<S15>/Abs'
   *  Gain: '<S15>/Gain'
   */
  rtb_uDLookupTable1 = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
    (rtb_Add_m), rtb_uDLookupTable2, ControllerLateral_ConstP.pooled24,
    &ControllerLateral_DW->m_bpIndex_m, 13U);

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S15>/Constant6'
   *  Constant: '<S15>/Constant7'
   *  Sum: '<S15>/Subtract4'
   */
  if (rtb_Switch7 - 2.0 != 0.0) {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/Constant2'
     *  DataTypeConversion: '<S15>/Cast To Boolean'
     *  DataTypeConversion: '<S15>/Cast To Boolean1'
     *  Delay: '<S15>/Delay2'
     *  Gain: '<S15>/Gain1'
     *  Logic: '<S15>/AND'
     *  RelationalOperator: '<S15>/GreaterThan'
     *  Saturate: '<S15>/Saturation1'
     */
    if (((rtb_Switch_c > 10.0 ? -128 : 0) != 0) &&
        (ControllerLateral_DW->Delay2_DSTATE != 0.0)) {
      /* Saturate: '<S15>/Saturation1' */
      if (rtb_uDLookupTable1 > 8.0) {
        rtb_Switch1_e_idx_0 = 8.0;
      } else if (rtb_uDLookupTable1 < -8.0) {
        rtb_Switch1_e_idx_0 = -8.0;
      } else {
        rtb_Switch1_e_idx_0 = rtb_uDLookupTable1;
      }

      /* Saturate: '<S15>/Saturation2' */
      if (rtb_Switch1_e_idx_0 > 5.6) {
        rtb_Switch2_m0 = 5.6;
      } else if (rtb_Switch1_e_idx_0 < -5.6) {
        rtb_Switch2_m0 = -5.6;
      } else {
        rtb_Switch2_m0 = rtb_Switch1_e_idx_0;
      }

      /* End of Saturate: '<S15>/Saturation2' */
    } else if (rtb_uDLookupTable1 > 8.0) {
      /* Saturate: '<S15>/Saturation1' */
      rtb_Switch2_m0 = 8.0;
    } else if (rtb_uDLookupTable1 < -8.0) {
      /* Saturate: '<S15>/Saturation1' */
      rtb_Switch2_m0 = -8.0;
    } else {
      /* Saturate: '<S15>/Saturation1' */
      rtb_Switch2_m0 = rtb_uDLookupTable1;
    }

    /* End of Switch: '<S15>/Switch1' */
  } else {
    rtb_Switch2_m0 = 0.0;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Product: '<S15>/Product' */
  rtb_current_a = rtb_Sign * rtb_Switch2_m0;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S653>/Constant11'
   *  Constant: '<S653>/Constant12'
   *  Constant: '<S654>/Constant11'
   *  Constant: '<S654>/Constant12'
   *  Constant: '<S655>/Constant11'
   *  Constant: '<S655>/Constant12'
   *  Constant: '<S656>/Constant11'
   *  Constant: '<S656>/Constant12'
   *  Logic: '<S653>/AND'
   *  Logic: '<S654>/AND'
   *  Logic: '<S655>/AND'
   *  Logic: '<S656>/AND'
   *  RelationalOperator: '<S653>/GreaterThan'
   *  RelationalOperator: '<S653>/SmallerThan'
   *  RelationalOperator: '<S654>/GreaterThan'
   *  RelationalOperator: '<S654>/SmallerThan'
   *  RelationalOperator: '<S655>/GreaterThan'
   *  RelationalOperator: '<S655>/SmallerThan'
   *  RelationalOperator: '<S656>/GreaterThan'
   *  RelationalOperator: '<S656>/SmallerThan'
   */
  if (ControllerLateral_InstP->UseBothEMS > 0.0) {
    rtb_Switch_dw_idx_0 = ((rtb_a_n > 6.5) && (rtb_a_n < 23.0));
    rtb_Switch_dw_idx_1 = ((rtb_b > 6.5) && (rtb_b < 23.0));
    rtb_Switch_dw_idx_2 = ((rtb_c_a > 6.5) && (rtb_c_a < 23.0));
    rtb_Switch_dw_idx_3 = ((rtb_d > 6.5) && (rtb_d < 23.0));
  } else {
    rtb_Switch_dw_idx_0 = 0;
    rtb_Switch_dw_idx_1 = 0;
    rtb_Switch_dw_idx_2 = 0;
    rtb_Switch_dw_idx_3 = 0;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Add1_f < 0.0) {
    rtb_Sign_k = -1.0;
  } else if (rtb_Add1_f > 0.0) {
    rtb_Sign_k = 1.0;
  } else if (rtb_Add1_f == 0.0) {
    rtb_Sign_k = 0.0;
  } else {
    rtb_Sign_k = (rtNaN);
  }

  /* End of Signum: '<S14>/Sign' */

  /* Switch: '<S14>/Switch' incorporates:
   *  Saturate: '<S1>/Saturation1'
   */
  if (rtb_Sign_k > 0.0) {
    /* Saturate: '<S1>/Saturation1' */
    if (rtb_d > 25.0) {
      rtb_Switch_e = 25.0;
    } else if (rtb_d < 2.0) {
      rtb_Switch_e = 2.0;
    } else {
      rtb_Switch_e = rtb_d;
    }
  } else if (rtb_c_a > 25.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_e = 25.0;
  } else if (rtb_c_a < 2.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_e = 2.0;
  } else {
    rtb_Switch_e = rtb_c_a;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Lookup_n-D: '<S14>/2-D Lookup Table2' incorporates:
   *  Constant: '<S14>/Constant'
   *  Switch: '<S14>/Switch'
   */
  bpIndices_0[1U] = plook_binxp(rtb_Switch_e, ControllerLateral_ConstP.pooled26,
    100U, &rtb_Switch1_e_idx_0, &ControllerLateral_DW->m_Cache02_m);
  fractions_0[1U] = rtb_Switch1_e_idx_0;
  for (i = 0; i < 14; i++) {
    bpIndices_0[0U] = plook_binxp(ControllerLateral_ConstP.pooled24[i],
      ControllerLateral_ConstP.pooled24, 13U, &rtb_Switch1_e_idx_0,
      &ControllerLateral_DW->m_Cache01_k[i]);
    fractions_0[0U] = rtb_Switch1_e_idx_0;
    rtb_uDLookupTable2_b[i] = intrp2d_l_pw(bpIndices_0, fractions_0,
      ControllerLateral_ConstP.pooled25, 14U);
  }

  /* End of Lookup_n-D: '<S14>/2-D Lookup Table2' */

  /* Lookup_n-D: '<S14>/2-D Lookup Table1' incorporates:
   *  Abs: '<S14>/Abs'
   *  Gain: '<S14>/Gain'
   */
  rtb_uDLookupTable1_b = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
    (rtb_Add1_f), rtb_uDLookupTable2_b, ControllerLateral_ConstP.pooled24,
    &ControllerLateral_DW->m_bpIndex_i, 13U);

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/Constant6'
   *  Constant: '<S14>/Constant7'
   *  Sum: '<S14>/Subtract4'
   */
  if (rtb_Switch7 - 2.0 != 0.0) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Constant2'
     *  DataTypeConversion: '<S14>/Cast To Boolean'
     *  DataTypeConversion: '<S14>/Cast To Boolean1'
     *  Delay: '<S14>/Delay2'
     *  Gain: '<S14>/Gain1'
     *  Logic: '<S14>/AND'
     *  RelationalOperator: '<S14>/GreaterThan'
     *  Saturate: '<S14>/Saturation1'
     */
    if (((rtb_Switch_e > 10.0 ? -128 : 0) != 0) &&
        (ControllerLateral_DW->Delay2_DSTATE_i != 0.0)) {
      /* Saturate: '<S14>/Saturation1' */
      if (rtb_uDLookupTable1_b > 8.0) {
        rtb_Switch1_e_idx_0 = 8.0;
      } else if (rtb_uDLookupTable1_b < -8.0) {
        rtb_Switch1_e_idx_0 = -8.0;
      } else {
        rtb_Switch1_e_idx_0 = rtb_uDLookupTable1_b;
      }

      /* Saturate: '<S14>/Saturation2' */
      if (rtb_Switch1_e_idx_0 > 5.6) {
        rtb_Switch2_e = 5.6;
      } else if (rtb_Switch1_e_idx_0 < -5.6) {
        rtb_Switch2_e = -5.6;
      } else {
        rtb_Switch2_e = rtb_Switch1_e_idx_0;
      }

      /* End of Saturate: '<S14>/Saturation2' */
    } else if (rtb_uDLookupTable1_b > 8.0) {
      /* Saturate: '<S14>/Saturation1' */
      rtb_Switch2_e = 8.0;
    } else if (rtb_uDLookupTable1_b < -8.0) {
      /* Saturate: '<S14>/Saturation1' */
      rtb_Switch2_e = -8.0;
    } else {
      /* Saturate: '<S14>/Saturation1' */
      rtb_Switch2_e = rtb_uDLookupTable1_b;
    }

    /* End of Switch: '<S14>/Switch1' */
  } else {
    rtb_Switch2_e = 0.0;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Product: '<S14>/Product' */
  rtb_current = rtb_Sign_k * rtb_Switch2_e;

  /* Abs: '<S12>/Abs1' incorporates:
   *  Abs: '<S14>/Abs3'
   *  Abs: '<S15>/Abs3'
   */
  rtb_Switch1_e_idx_0 = fabs(rtb_Gain3);
  rtb_Gain_f_idx_1 = fabs(rtb_Gain2);

  /* Outport: '<Root>/Power_Lat' incorporates:
   *  Abs: '<S12>/Abs'
   *  Abs: '<S12>/Abs1'
   *  Inport: '<Root>/VrB'
   *  Inport: '<Root>/VrF'
   *  Inport: '<Root>/VtB'
   *  Inport: '<Root>/VtF'
   *  Product: '<S12>/Product'
   *  Sum: '<Root>/Subtract2'
   *  Sum: '<S12>/Sum'
   */
  ControllerLateral_Y->Power_Lat = fabs(ControllerLateral_U->VtF -
    ControllerLateral_U->VrF) * rtb_Gain_f_idx_1 + fabs(ControllerLateral_U->VtB
    - ControllerLateral_U->VrB) * rtb_Switch1_e_idx_0;

  /* MATLABSystem: '<S12>/Moving Average' */
  if (ControllerLateral_DW->obj.TunablePropsChanged) {
    ControllerLateral_DW->obj.TunablePropsChanged = false;
  }

  obj = ControllerLateral_DW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 1999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 1999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* Outport: '<Root>/Power_Lat_avg' incorporates:
   *  MATLABSystem: '<S12>/Moving Average'
   *  Outport: '<Root>/Power_Lat'
   */
  ControllerLateral_Y->Power_Lat_avg =
    ControllerLateral_SlidingWindowAverageCG_stepImpl(obj,
    ControllerLateral_Y->Power_Lat);

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_g <= 0)) ||
      ((!(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_g == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
  }

  /* Outport: '<Root>/Energy_Lat' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  ControllerLateral_Y->Energy_Lat =
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f;

  /* Lookup_n-D: '<S15>/2-D Lookup Table3' incorporates:
   *  Abs: '<S15>/Abs1'
   *  Switch: '<S15>/Switch'
   */
  rtb_uDLookupTable3 = look2_pbinlxpw(fabs(rtb_Gain2), rtb_Switch_c,
    ControllerLateral_ConstP.pooled24, ControllerLateral_ConstP.pooled26,
    ControllerLateral_ConstP.pooled25, ControllerLateral_DW->m_bpIndex_g,
    ControllerLateral_ConstP.pooled32, 14U);

  /* Signum: '<S15>/Sign1' */
  if (rtb_Gain2 < 0.0) {
    rtb_Gain_f_idx_0 = -1.0;
  } else if (rtb_Gain2 > 0.0) {
    rtb_Gain_f_idx_0 = 1.0;
  } else if (rtb_Gain2 == 0.0) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S15>/Sign1' */

  /* Outport: '<Root>/EMS_F_Front' incorporates:
   *  Product: '<S15>/Product1'
   */
  ControllerLateral_Y->EMS_F_Front = rtb_uDLookupTable3 * rtb_Gain_f_idx_0;

  /* Lookup_n-D: '<S14>/2-D Lookup Table3' incorporates:
   *  Abs: '<S14>/Abs1'
   *  Switch: '<S14>/Switch'
   */
  rtb_uDLookupTable3_d = look2_pbinlxpw(fabs(rtb_Gain3), rtb_Switch_e,
    ControllerLateral_ConstP.pooled24, ControllerLateral_ConstP.pooled26,
    ControllerLateral_ConstP.pooled25, ControllerLateral_DW->m_bpIndex_ge,
    ControllerLateral_ConstP.pooled32, 14U);

  /* Signum: '<S14>/Sign1' */
  if (rtb_Gain3 < 0.0) {
    rtb_Gain_f_idx_0 = -1.0;
  } else if (rtb_Gain3 > 0.0) {
    rtb_Gain_f_idx_0 = 1.0;
  } else if (rtb_Gain3 == 0.0) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S14>/Sign1' */

  /* Outport: '<Root>/EMS_F_Back' incorporates:
   *  Product: '<S14>/Product1'
   */
  ControllerLateral_Y->EMS_F_Back = rtb_uDLookupTable3_d * rtb_Gain_f_idx_0;

  /* Outport: '<Root>/uncapped_current' */
  ControllerLateral_Y->uncapped_current = rtb_current_a;

  /* Delay: '<S14>/Delay1' */
  ControllerLateral_B->Delay1 = ControllerLateral_DW->Delay1_DSTATE_f;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (((ControllerLateral_B->Delay1 > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p <= 0)) ||
      ((ControllerLateral_B->Delay1 <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
  }

  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b >= 1.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 1.0;
  } else if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b <= 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
  }

  rtb_DiscreteTimeIntegrator_f =
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b;

  /* End of DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  /* Delay: '<S14>/Delay' */
  ControllerLateral_B->Delay = ControllerLateral_DW->Delay_DSTATE[0];

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  if (((ControllerLateral_B->Delay > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a <= 0)) ||
      ((ControllerLateral_B->Delay <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_b = 0.0;
  }

  rtb_DiscreteTimeIntegrator1 =
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_b;

  /* End of DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  /* Switch: '<S14>/Switch4' incorporates:
   *  Constant: '<S14>/Constant11'
   *  Sum: '<S14>/Subtract6'
   */
  ControllerLateral_B->Switch4 = (real_T)(rtb_DiscreteTimeIntegrator_f - 1.0 >=
    0.0);

  /* Switch: '<S14>/Switch3' incorporates:
   *  Constant: '<S14>/Constant9'
   *  Sum: '<S14>/Subtract5'
   *  Switch: '<S14>/Switch6'
   */
  if (rtb_Switch1_e_idx_0 - 5.6 > 0.0) {
    /* Switch: '<S14>/Switch3' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    ControllerLateral_B->Switch3 = 1.0;
  } else if (ControllerLateral_B->Switch4 != 0.0) {
    /* Switch: '<S14>/Switch6' incorporates:
     *  Constant: '<S14>/Constant8'
     *  Switch: '<S14>/Switch3'
     */
    ControllerLateral_B->Switch3 = 0.0;
  } else {
    /* Switch: '<S14>/Switch3' incorporates:
     *  Constant: '<S14>/Constant17'
     *  Switch: '<S14>/Switch6'
     */
    ControllerLateral_B->Switch3 = -1.0;
  }

  /* End of Switch: '<S14>/Switch3' */

  /* Switch: '<S14>/Switch5' incorporates:
   *  Constant: '<S14>/Constant12'
   *  Sum: '<S14>/Subtract7'
   */
  ControllerLateral_B->Switch5 = (real_T)(rtb_DiscreteTimeIntegrator1 - 1.0 >=
    0.0);

  /* Delay: '<S15>/Delay1' */
  ControllerLateral_B->Delay1_f = ControllerLateral_DW->Delay1_DSTATE_j;

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  if (((ControllerLateral_B->Delay1_f > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j <= 0)) ||
      ((ControllerLateral_B->Delay1_f <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 0.0;
  }

  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e >= 1.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 1.0;
  } else if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e <= 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 0.0;
  }

  rtb_DiscreteTimeIntegrator_p =
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e;

  /* End of DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  /* Delay: '<S15>/Delay' */
  ControllerLateral_B->Delay_d = ControllerLateral_DW->Delay_DSTATE_g[0];

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  if (((ControllerLateral_B->Delay_d > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o <= 0)) ||
      ((ControllerLateral_B->Delay_d <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_n = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_o =
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_n;

  /* End of DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  /* Switch: '<S15>/Switch4' incorporates:
   *  Constant: '<S15>/Constant11'
   *  Sum: '<S15>/Subtract6'
   */
  ControllerLateral_B->Switch4_b = (real_T)(rtb_DiscreteTimeIntegrator_p - 1.0 >=
    0.0);

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/Constant9'
   *  Sum: '<S15>/Subtract5'
   *  Switch: '<S15>/Switch6'
   */
  if (rtb_Gain_f_idx_1 - 5.6 > 0.0) {
    /* Switch: '<S15>/Switch3' incorporates:
     *  Constant: '<S15>/Constant1'
     */
    ControllerLateral_B->Switch3_m = 1.0;
  } else if (ControllerLateral_B->Switch4_b != 0.0) {
    /* Switch: '<S15>/Switch6' incorporates:
     *  Constant: '<S15>/Constant8'
     *  Switch: '<S15>/Switch3'
     */
    ControllerLateral_B->Switch3_m = 0.0;
  } else {
    /* Switch: '<S15>/Switch3' incorporates:
     *  Constant: '<S15>/Constant17'
     *  Switch: '<S15>/Switch6'
     */
    ControllerLateral_B->Switch3_m = -1.0;
  }

  /* End of Switch: '<S15>/Switch3' */

  /* Switch: '<S15>/Switch5' incorporates:
   *  Constant: '<S15>/Constant12'
   *  Sum: '<S15>/Subtract7'
   */
  ControllerLateral_B->Switch5_e = (real_T)(rtb_DiscreteTimeIntegrator1_o - 1.0 >=
    0.0);

  /* Logic: '<S27>/OR3' incorporates:
   *  Constant: '<S27>/Constant12'
   *  Constant: '<S27>/Constant13'
   *  Constant: '<S27>/Constant14'
   *  Constant: '<S27>/Constant15'
   *  Constant: '<S27>/Constant16'
   *  Constant: '<S27>/Constant6'
   *  Logic: '<S27>/AND5'
   *  Logic: '<S27>/AND6'
   *  Logic: '<S27>/AND7'
   *  Logic: '<S27>/OR2'
   *  RelationalOperator: '<S27>/Equal2'
   *  RelationalOperator: '<S27>/Equal3'
   *  RelationalOperator: '<S27>/Equal4'
   */
  rtb_OR3 = (boolean_T)(((ControllerLateral_InstP->UseBothEMS == 1.0) &&
    (((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_1 != 0)) ||
     ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_0 != 0))))
                        || (ControllerLateral_InstP->StopDeIntegral != 0.0));

  /* Delay: '<Root>/Delay2' */
  rtb_Delay2_n[0] = ControllerLateral_DW->Delay2_DSTATE_f[0];
  rtb_Delay2_n[1] = ControllerLateral_DW->Delay2_DSTATE_f[1];
  ControllerLateral_MovingAverage_p(rtb_Delay2_n[0],
    &ControllerLateral_B->MovingAverage_pnae,
    &ControllerLateral_DW->MovingAverage_pnae);

  /* Switch: '<S27>/Switch2' */
  if (rtb_OR3) {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    rtb_Switch2_h = ControllerLateral_InstP->L_K_i;
  } else {
    /* Logic: '<S27>/AND' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S27>/Constant10'
     *  Constant: '<S27>/Constant8'
     *  RelationalOperator: '<S27>/Equal1'
     *  RelationalOperator: '<S27>/GreaterThan3'
     */
    rtb_AND_c = (boolean_T)
      ((ControllerLateral_B->MovingAverage_pnae.MovingAverage > 0.0) && (2.0 ==
        ControllerLateral_InstP->LS_mode));

    /* RelationalOperator: '<S27>/GreaterThan1' incorporates:
     *  Constant: '<S27>/Constant5'
     *  Gain: '<S17>/Gain1'
     */
    rtb_GreaterThan1_e = (boolean_T)(-rtb_error_j > 0.0);

    /* RelationalOperator: '<S27>/Equal' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S27>/Constant7'
     */
    rtb_Equal_f = (boolean_T)(1.0 == ControllerLateral_InstP->LS_mode);

    /* RelationalOperator: '<S27>/GreaterThan' incorporates:
     *  Constant: '<S27>/Constant4'
     *  Gain: '<S17>/Gain1'
     */
    rtb_GreaterThan_nv = (boolean_T)(0.0 > -rtb_error_j);

    /* RelationalOperator: '<S27>/GreaterThan2' incorporates:
     *  Constant: '<S27>/Constant10'
     */
    rtb_GreaterThan2_c = (boolean_T)(0.0 >
      ControllerLateral_B->MovingAverage_pnae.MovingAverage);

    /* Switch: '<S27>/Switch1' incorporates:
     *  Logic: '<S27>/AND1'
     *  Logic: '<S27>/AND2'
     *  Logic: '<S27>/AND3'
     *  Logic: '<S27>/AND4'
     *  Logic: '<S27>/OR'
     *  Logic: '<S27>/OR1'
     *  Switch: '<S27>/Switch'
     */
    if ((((int32_T)rtb_AND_c) && ((int32_T)rtb_GreaterThan1_e)) || (((int32_T)
          rtb_Equal_f) && ((int32_T)rtb_GreaterThan_nv) && ((int32_T)
          rtb_GreaterThan2_c))) {
      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S27>/Constant11'
       */
      rtb_Switch2_h = ControllerLateral_InstP->L_K_i * 2.0;
    } else if ((((int32_T)rtb_GreaterThan_nv) && ((int32_T)rtb_AND_c)) ||
               (((int32_T)rtb_GreaterThan1_e) && ((int32_T)rtb_Equal_f) &&
                ((int32_T)rtb_GreaterThan2_c))) {
      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S27>/Constant9'
       *  Switch: '<S27>/Switch2'
       */
      rtb_Switch2_h = -ControllerLateral_InstP->L_K_i / 2.0;
    } else {
      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S27>/Constant2'
       *  Switch: '<S27>/Switch'
       */
      rtb_Switch2_h = ControllerLateral_InstP->L_K_i;
    }

    /* End of Switch: '<S27>/Switch1' */
  }

  /* End of Switch: '<S27>/Switch2' */
  ControllerLateral_MovingAverage1(rtb_Switch2_h,
    &ControllerLateral_B->MovingAverage1_pnae,
    &ControllerLateral_DW->MovingAverage1_pnae);

  /* Product: '<S58>/IProd Out' */
  rtb_IProdOut = ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
    ControllerLateral_B->MovingAverage1_pnae.MovingAverage1;

  /* Signum: '<S52>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0) {
    rtb_Switch1_e_idx_0 = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    rtb_Switch1_e_idx_0 = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    rtb_Switch1_e_idx_0 = 0.0;
  } else {
    rtb_Switch1_e_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S52>/SignPreIntegrator' */

  /* DataTypeConversion: '<S52>/DataTypeConv2' */
  rtb_Gain_f_idx_1 = fabs(rtb_Switch1_e_idx_0);
  if (rtb_Gain_f_idx_1 < 4.503599627370496E+15) {
    if (rtb_Gain_f_idx_1 >= 0.5) {
      rtb_Switch1_e_idx_0 = floor(rtb_Switch1_e_idx_0 + 0.5);
    } else {
      rtb_Switch1_e_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch1_e_idx_0)) {
    rtb_Switch1_e_idx_0 = 0.0;
  } else {
    rtb_Switch1_e_idx_0 = fmod(rtb_Switch1_e_idx_0, 256.0);
  }

  /* DeadZone: '<S54>/DeadZone' */
  if (rtb_Sum_k >= (rtMinusInf)) {
    rtb_Gain_f_idx_1 = 0.0;
  } else {
    rtb_Gain_f_idx_1 = (rtNaN);
  }

  /* End of DeadZone: '<S54>/DeadZone' */

  /* Switch: '<S52>/Switch' incorporates:
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Gain: '<S52>/ZeroGain'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((0.0 * rtb_Sum_k != rtb_Gain_f_idx_1) && ((rtb_Switch1_e_idx_0 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)-rtb_Switch1_e_idx_0 :
        (int32_T)(int8_T)(uint8_T)rtb_Switch1_e_idx_0) == 0)) {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    ControllerLateral_B->Switch = 0.0;
  } else {
    /* Switch: '<S52>/Switch' */
    ControllerLateral_B->Switch = rtb_IProdOut;
  }

  /* End of Switch: '<S52>/Switch' */

  /* Logic: '<S79>/OR3' incorporates:
   *  Constant: '<S79>/Constant12'
   *  Constant: '<S79>/Constant13'
   *  Constant: '<S79>/Constant14'
   *  Constant: '<S79>/Constant15'
   *  Constant: '<S79>/Constant16'
   *  Constant: '<S79>/Constant6'
   *  Logic: '<S79>/AND5'
   *  Logic: '<S79>/AND6'
   *  Logic: '<S79>/AND7'
   *  Logic: '<S79>/OR2'
   *  RelationalOperator: '<S79>/Equal2'
   *  RelationalOperator: '<S79>/Equal3'
   *  RelationalOperator: '<S79>/Equal4'
   */
  rtb_OR3_b = (boolean_T)(((ControllerLateral_InstP->UseBothEMS == 1.0) &&
    (((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_3 != 0)) ||
     ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_2 != 0))))
    || (ControllerLateral_InstP->StopDeIntegral != 0.0));
  ControllerLateral_MovingAverage_p(rtb_Delay2_n[1],
    &ControllerLateral_B->MovingAverage_pnaevv,
    &ControllerLateral_DW->MovingAverage_pnaevv);

  /* Switch: '<S79>/Switch2' */
  if (rtb_OR3_b) {
    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Switch2_o = ControllerLateral_InstP->L_K_i;
  } else {
    /* Logic: '<S79>/AND' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S79>/Constant10'
     *  Constant: '<S79>/Constant8'
     *  RelationalOperator: '<S79>/Equal1'
     *  RelationalOperator: '<S79>/GreaterThan3'
     */
    rtb_AND_b = (boolean_T)
      ((ControllerLateral_B->MovingAverage_pnaevv.MovingAverage > 0.0) && (2.0 ==
        ControllerLateral_InstP->LS_mode));

    /* RelationalOperator: '<S79>/GreaterThan1' incorporates:
     *  Constant: '<S79>/Constant5'
     *  Gain: '<S18>/Gain1'
     */
    rtb_GreaterThan1 = (boolean_T)(-rtb_error_d > 0.0);

    /* RelationalOperator: '<S79>/Equal' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S79>/Constant7'
     */
    rtb_Equal_g = (boolean_T)(1.0 == ControllerLateral_InstP->LS_mode);

    /* RelationalOperator: '<S79>/GreaterThan' incorporates:
     *  Constant: '<S79>/Constant4'
     *  Gain: '<S18>/Gain1'
     */
    rtb_GreaterThan_d = (boolean_T)(0.0 > -rtb_error_d);

    /* RelationalOperator: '<S79>/GreaterThan2' incorporates:
     *  Constant: '<S79>/Constant10'
     */
    rtb_GreaterThan2 = (boolean_T)(0.0 >
      ControllerLateral_B->MovingAverage_pnaevv.MovingAverage);

    /* Switch: '<S79>/Switch1' incorporates:
     *  Logic: '<S79>/AND1'
     *  Logic: '<S79>/AND2'
     *  Logic: '<S79>/AND3'
     *  Logic: '<S79>/AND4'
     *  Logic: '<S79>/OR'
     *  Logic: '<S79>/OR1'
     *  Switch: '<S79>/Switch'
     */
    if ((((int32_T)rtb_AND_b) && ((int32_T)rtb_GreaterThan1)) || (((int32_T)
          rtb_Equal_g) && ((int32_T)rtb_GreaterThan_d) && ((int32_T)
          rtb_GreaterThan2))) {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Constant: '<S79>/Constant11'
       */
      rtb_Switch2_o = ControllerLateral_InstP->L_K_i * 2.0;
    } else if ((((int32_T)rtb_GreaterThan_d) && ((int32_T)rtb_AND_b)) ||
               (((int32_T)rtb_GreaterThan1) && ((int32_T)rtb_Equal_g) &&
                ((int32_T)rtb_GreaterThan2))) {
      /* Switch: '<S79>/Switch' incorporates:
       *  Constant: '<S79>/Constant9'
       *  Switch: '<S79>/Switch2'
       */
      rtb_Switch2_o = -ControllerLateral_InstP->L_K_i / 2.0;
    } else {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Constant: '<S79>/Constant2'
       *  Switch: '<S79>/Switch'
       */
      rtb_Switch2_o = ControllerLateral_InstP->L_K_i;
    }

    /* End of Switch: '<S79>/Switch1' */
  }

  /* End of Switch: '<S79>/Switch2' */
  ControllerLateral_MovingAverage1(rtb_Switch2_o,
    &ControllerLateral_B->MovingAverage1_pnaev,
    &ControllerLateral_DW->MovingAverage1_pnaev);

  /* Product: '<S110>/IProd Out' */
  rtb_IProdOut_l = ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage *
    ControllerLateral_B->MovingAverage1_pnaev.MovingAverage1;

  /* Signum: '<S104>/SignPreIntegrator' */
  if (rtb_IProdOut_l < 0.0) {
    rtb_Switch1_e_idx_0 = -1.0;
  } else if (rtb_IProdOut_l > 0.0) {
    rtb_Switch1_e_idx_0 = 1.0;
  } else if (rtb_IProdOut_l == 0.0) {
    rtb_Switch1_e_idx_0 = 0.0;
  } else {
    rtb_Switch1_e_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S104>/SignPreIntegrator' */

  /* DataTypeConversion: '<S104>/DataTypeConv2' */
  rtb_Gain_f_idx_1 = fabs(rtb_Switch1_e_idx_0);
  if (rtb_Gain_f_idx_1 < 4.503599627370496E+15) {
    if (rtb_Gain_f_idx_1 >= 0.5) {
      rtb_Switch1_e_idx_0 = floor(rtb_Switch1_e_idx_0 + 0.5);
    } else {
      rtb_Switch1_e_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch1_e_idx_0)) {
    rtb_Switch1_e_idx_0 = 0.0;
  } else {
    rtb_Switch1_e_idx_0 = fmod(rtb_Switch1_e_idx_0, 256.0);
  }

  /* DeadZone: '<S106>/DeadZone' */
  if (rtb_Sum_o >= (rtMinusInf)) {
    rtb_Gain_f_idx_1 = 0.0;
  } else {
    rtb_Gain_f_idx_1 = (rtNaN);
  }

  /* End of DeadZone: '<S106>/DeadZone' */

  /* Switch: '<S104>/Switch' incorporates:
   *  DataTypeConversion: '<S104>/DataTypeConv1'
   *  DataTypeConversion: '<S104>/DataTypeConv2'
   *  Gain: '<S104>/ZeroGain'
   *  Logic: '<S104>/AND3'
   *  RelationalOperator: '<S104>/Equal1'
   *  RelationalOperator: '<S104>/NotEqual'
   */
  if ((0.0 * rtb_Sum_o != rtb_Gain_f_idx_1) && ((rtb_Switch1_e_idx_0 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)-rtb_Switch1_e_idx_0 :
        (int32_T)(int8_T)(uint8_T)rtb_Switch1_e_idx_0) == 0)) {
    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S104>/Constant1'
     */
    ControllerLateral_B->Switch_a = 0.0;
  } else {
    /* Switch: '<S104>/Switch' */
    ControllerLateral_B->Switch_a = rtb_IProdOut_l;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Sum: '<S159>/SumI4' incorporates:
   *  Gain: '<S159>/Kb'
   *  Gain: '<S165>/Integral Gain'
   *  Sum: '<S159>/SumI2'
   */
  ControllerLateral_B->SumI4 = (rtb_Sum - rtb_Sum) * 0.01 +
    ControllerLateral_InstP->CurrentIntegralLat * rtb_Switch_ci;

  /* Sum: '<S210>/SumI4' incorporates:
   *  Gain: '<S210>/Kb'
   *  Gain: '<S216>/Integral Gain'
   *  Sum: '<S210>/SumI2'
   */
  ControllerLateral_B->SumI4_e = (rtb_Sum_ok - rtb_Sum_ok) * 0.01 +
    ControllerLateral_InstP->CurrentIntegralLat * rtb_Switch_gx;

  /* DiscreteIntegrator: '<S251>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S236>/Constant6'
   */
  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  /* Gain: '<S236>/Gain3' incorporates:
   *  Inport: '<Root>/IMU_yaw'
   */
  ControllerLateral_B->Gain3_i = ControllerLateral_InstP->kalman_yawdot_gain *
    ControllerLateral_U->IMU_yaw;

  /* Gain: '<S244>/Gain10' incorporates:
   *  Memory: '<S244>/Memory'
   *  Memory: '<S244>/Memory1'
   *  Sum: '<S244>/Subtract'
   */
  ControllerLateral_B->Gain10 = ((ControllerLateral_B->Gain3_i -
    ControllerLateral_DW->Memory_PreviousInput) +
    ControllerLateral_DW->Memory1_PreviousInput) *
    ControllerLateral_InstP->ForgetFactor_Highpass_Lat;

  /* Product: '<S251>/Product' incorporates:
   *  Constant: '<S251>/sensor half arm'
   *  Product: '<S250>/Product'
   */
  rtb_Switch1_e_idx_0 = ControllerLateral_B->Gain10 * 0.465;

  /* Sum: '<S251>/Add1' incorporates:
   *  DiscreteIntegrator: '<S251>/Discrete-Time Integrator'
   *  Product: '<S251>/Product'
   */
  rtb_d2_dot = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n -
    rtb_Switch1_e_idx_0;

  /* DiscreteIntegrator: '<S250>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S236>/Constant6'
   */
  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g = 0.0;
  }

  /* Sum: '<S250>/Add' incorporates:
   *  DiscreteIntegrator: '<S250>/Discrete-Time Integrator'
   */
  rtb_b2_dot = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g +
    rtb_Switch1_e_idx_0;

  /* Sum: '<S237>/Subtract4' incorporates:
   *  Gain: '<S237>/Gain'
   */
  ControllerLateral_B->diff2 = 0.001 * rtb_Switch_pn - rtb_d2;

  /* Gain: '<S382>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S374>/Filter'
   *  Gain: '<S373>/Derivative Gain'
   *  Sum: '<S374>/SumD'
   */
  ControllerLateral_B->FilterCoefficient = (0.7 * ControllerLateral_B->diff2 -
    ControllerLateral_DW->Filter_DSTATE_d) * 100.0;

  /* Sum: '<S237>/Add' incorporates:
   *  DiscreteIntegrator: '<S250>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S379>/Integrator'
   *  Gain: '<S384>/Proportional Gain'
   *  Sum: '<S250>/Add1'
   *  Sum: '<S388>/Sum'
   */
  ControllerLateral_B->Add = ((2.0 * ControllerLateral_B->diff2 +
    ControllerLateral_DW->Integrator_DSTATE_m1) +
    ControllerLateral_B->FilterCoefficient) +
    (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g - rtb_Switch1_e_idx_0);

  /* Sum: '<S237>/Subtract3' incorporates:
   *  Gain: '<S237>/Gain3'
   */
  ControllerLateral_B->diff1 = 0.001 * rtb_Switch_m - rtb_b2;

  /* Gain: '<S286>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S278>/Filter'
   *  Gain: '<S277>/Derivative Gain'
   *  Sum: '<S278>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_o = (0.7 * ControllerLateral_B->diff1 -
    ControllerLateral_DW->Filter_DSTATE_b) * 100.0;

  /* Sum: '<S237>/Add1' incorporates:
   *  DiscreteIntegrator: '<S251>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S283>/Integrator'
   *  Gain: '<S288>/Proportional Gain'
   *  Product: '<S251>/Product'
   *  Sum: '<S251>/Add'
   *  Sum: '<S292>/Sum'
   */
  ControllerLateral_B->Add1 = ((2.0 * ControllerLateral_B->diff1 +
    ControllerLateral_DW->Integrator_DSTATE_ok) +
    ControllerLateral_B->FilterCoefficient_o) +
    (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n + rtb_Switch1_e_idx_0);

  /* Gain: '<S334>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S326>/Filter'
   *  Gain: '<S325>/Derivative Gain'
   *  Sum: '<S326>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_n = (0.7 * ControllerLateral_B->diff2 -
    ControllerLateral_DW->Filter_DSTATE_dy) * 100.0;

  /* Gain: '<S236>/Gain2' incorporates:
   *  Inport: '<Root>/IMU_y'
   */
  ControllerLateral_B->Gain2 = ControllerLateral_InstP->kalman_ydotdot_gain *
    ControllerLateral_U->IMU_y;

  /* Gain: '<S237>/Gain9' */
  ControllerLateral_B->Gain9 = -ControllerLateral_B->Gain2;

  /* Gain: '<S245>/Gain10' incorporates:
   *  Memory: '<S245>/Memory'
   *  Memory: '<S245>/Memory1'
   *  Sum: '<S245>/Subtract'
   */
  ControllerLateral_B->Gain10_e = ((ControllerLateral_B->Gain9 -
    ControllerLateral_DW->Memory_PreviousInput_k) +
    ControllerLateral_DW->Memory1_PreviousInput_n) *
    ControllerLateral_InstP->ForgetFactor_Highpass_Lat;

  /* Sum: '<S237>/Add2' incorporates:
   *  DiscreteIntegrator: '<S331>/Integrator'
   *  Gain: '<S336>/Proportional Gain'
   *  Sum: '<S340>/Sum'
   */
  ControllerLateral_B->Add2 = ((2.0 * ControllerLateral_B->diff2 +
    ControllerLateral_DW->Integrator_DSTATE_f) +
    ControllerLateral_B->FilterCoefficient_n) + ControllerLateral_B->Gain10_e;

  /* Gain: '<S430>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S422>/Filter'
   *  Gain: '<S421>/Derivative Gain'
   *  Sum: '<S422>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_p = (0.7 * ControllerLateral_B->diff1 -
    ControllerLateral_DW->Filter_DSTATE_g) * 100.0;

  /* Sum: '<S237>/Add6' incorporates:
   *  DiscreteIntegrator: '<S427>/Integrator'
   *  Gain: '<S432>/Proportional Gain'
   *  Sum: '<S436>/Sum'
   */
  ControllerLateral_B->Add6 = ((2.0 * ControllerLateral_B->diff1 +
    ControllerLateral_DW->Integrator_DSTATE_or) +
    ControllerLateral_B->FilterCoefficient_p) + ControllerLateral_B->Gain10_e;

  /* DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_c <= 0)) ||
      ((!(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_c == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq = 0.0;
  }

  /* Gain: '<S445>/Gain10' incorporates:
   *  Memory: '<S445>/Memory'
   *  Memory: '<S445>/Memory1'
   *  Sum: '<S445>/Subtract'
   */
  ControllerLateral_B->Gain10_o = ((ControllerLateral_B->Gain3_i -
    ControllerLateral_DW->Memory_PreviousInput_d) +
    ControllerLateral_DW->Memory1_PreviousInput_g) *
    ControllerLateral_InstP->ForgetFactor_Highpass_Lat;

  /* Product: '<S451>/Product' incorporates:
   *  Constant: '<S451>/sensor half arm'
   *  Product: '<S450>/Product'
   */
  rtb_Switch1_e_idx_0 = ControllerLateral_B->Gain10_o * 0.465;

  /* Sum: '<S451>/Add1' incorporates:
   *  DiscreteIntegrator: '<S451>/Discrete-Time Integrator'
   *  Product: '<S451>/Product'
   */
  rtb_c2_dot = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq +
    rtb_Switch1_e_idx_0;

  /* DiscreteIntegrator: '<S450>/Discrete-Time Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_h <= 0)) ||
      ((!(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_h == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o = 0.0;
  }

  /* Sum: '<S450>/Add' incorporates:
   *  DiscreteIntegrator: '<S450>/Discrete-Time Integrator'
   */
  rtb_a2_dot = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o -
    rtb_Switch1_e_idx_0;

  /* Sum: '<S238>/Subtract4' */
  ControllerLateral_B->diff2_k = Gain - rtb_c2;

  /* Gain: '<S582>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S574>/Filter'
   *  Gain: '<S573>/Derivative Gain'
   *  Sum: '<S574>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_e = (0.7 * ControllerLateral_B->diff2_k
    - ControllerLateral_DW->Filter_DSTATE_a1) * 100.0;

  /* Sum: '<S238>/Add' incorporates:
   *  DiscreteIntegrator: '<S450>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S579>/Integrator'
   *  Gain: '<S584>/Proportional Gain'
   *  Sum: '<S450>/Add1'
   *  Sum: '<S588>/Sum'
   */
  ControllerLateral_B->Add_c = ((2.0 * ControllerLateral_B->diff2_k +
    ControllerLateral_DW->Integrator_DSTATE_b) +
    ControllerLateral_B->FilterCoefficient_e) +
    (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o + rtb_Switch1_e_idx_0);

  /* Sum: '<S238>/Subtract3' */
  ControllerLateral_B->diff1_k = Gain3 - rtb_a2;

  /* Gain: '<S486>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S478>/Filter'
   *  Gain: '<S477>/Derivative Gain'
   *  Sum: '<S478>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_ow = (0.7 *
    ControllerLateral_B->diff1_k - ControllerLateral_DW->Filter_DSTATE_n) *
    100.0;

  /* Sum: '<S238>/Add1' incorporates:
   *  DiscreteIntegrator: '<S451>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S483>/Integrator'
   *  Gain: '<S488>/Proportional Gain'
   *  Product: '<S451>/Product'
   *  Sum: '<S451>/Add'
   *  Sum: '<S492>/Sum'
   */
  ControllerLateral_B->Add1_b = ((2.0 * ControllerLateral_B->diff1_k +
    ControllerLateral_DW->Integrator_DSTATE_a) +
    ControllerLateral_B->FilterCoefficient_ow) +
    (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq -
     rtb_Switch1_e_idx_0);

  /* Gain: '<S534>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S526>/Filter'
   *  Gain: '<S525>/Derivative Gain'
   *  Sum: '<S526>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_f = (0.7 * ControllerLateral_B->diff2_k
    - ControllerLateral_DW->Filter_DSTATE_dv) * 100.0;

  /* Gain: '<S444>/Gain10' incorporates:
   *  Memory: '<S444>/Memory'
   *  Memory: '<S444>/Memory1'
   *  Sum: '<S444>/Subtract'
   */
  ControllerLateral_B->Gain10_ol = ((ControllerLateral_B->Gain2 -
    ControllerLateral_DW->Memory_PreviousInput_l) +
    ControllerLateral_DW->Memory1_PreviousInput_d) *
    ControllerLateral_InstP->ForgetFactor_Highpass_Lat;

  /* Sum: '<S238>/Add2' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   *  Gain: '<S536>/Proportional Gain'
   *  Sum: '<S540>/Sum'
   */
  ControllerLateral_B->Add2_a = ((2.0 * ControllerLateral_B->diff2_k +
    ControllerLateral_DW->Integrator_DSTATE_p) +
    ControllerLateral_B->FilterCoefficient_f) + ControllerLateral_B->Gain10_ol;

  /* Gain: '<S630>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S622>/Filter'
   *  Gain: '<S621>/Derivative Gain'
   *  Sum: '<S622>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_k = (0.7 * ControllerLateral_B->diff1_k
    - ControllerLateral_DW->Filter_DSTATE_b5) * 100.0;

  /* Sum: '<S238>/Add6' incorporates:
   *  DiscreteIntegrator: '<S627>/Integrator'
   *  Gain: '<S632>/Proportional Gain'
   *  Sum: '<S636>/Sum'
   */
  ControllerLateral_B->Add6_g = ((2.0 * ControllerLateral_B->diff1_k +
    ControllerLateral_DW->Integrator_DSTATE_i) +
    ControllerLateral_B->FilterCoefficient_k) + ControllerLateral_B->Gain10_ol;

  /* SignalConversion generated from: '<Root>/Delay2' */
  ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[0] = rtb_current_a;
  ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[1] = rtb_current;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant5'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  /* MATLAB Function 'MATLAB Function': '<S5>:1' */
  if (!(ControllerLateral_InstP->LS_mode == 0.0)) {
    if ((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_1 == 0))
    {
      /* '<S5>:1:4' */
      if (rtb_current_a > 0.0) {
        /* '<S5>:1:5' */
        /* '<S5>:1:6' */
        rtb_current_a = 0.0;
      }
    } else if ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_0
                == 0) && (rtb_current_a < 0.0)) {
      /* '<S5>:1:8' */
      /* '<S5>:1:9' */
      /* '<S5>:1:10' */
      rtb_current_a = 0.0;
    }

    if ((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_3 == 0))
    {
      /* '<S6>:1:4' */
      if (rtb_current > 0.0) {
        /* '<S6>:1:5' */
        /* '<S6>:1:6' */
        rtb_current = 0.0;
      }
    } else if ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_2
                == 0) && (rtb_current < 0.0)) {
      /* '<S6>:1:8' */
      /* '<S6>:1:9' */
      /* '<S6>:1:10' */
      rtb_current = 0.0;
    }
  } else {
    /* '<S5>:1:2' */
    /* '<S6>:1:2' */
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Switch: '<Root>/Switch3' */
  /* MATLAB Function 'MATLAB Function1': '<S6>:1' */
  if (rtb_Equal_e) {
    /* Outport: '<Root>/I_Demand_Front' */
    ControllerLateral_Y->I_Demand_Front = 0.0;

    /* Outport: '<Root>/I_Demand_Back' */
    ControllerLateral_Y->I_Demand_Back = 0.0;
  } else {
    /* Outport: '<Root>/I_Demand_Front' incorporates:
     *  Gain: '<Root>/Gain'
     */
    ControllerLateral_Y->I_Demand_Front = ControllerLateral_InstP->PolarityFront
      * rtb_current_a;

    /* Outport: '<Root>/I_Demand_Back' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    ControllerLateral_Y->I_Demand_Back = ControllerLateral_InstP->PolarityBack *
      rtb_current;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* SignalConversion generated from: '<Root>/Delay1' */
  ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0] = rtb_current_a;
  ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1] = rtb_current;

  /* Outport: '<Root>/Filtered_Gaps Lateral' */
  ControllerLateral_Y->Filtered_GapsLateral[0] = rtb_a_n;
  ControllerLateral_Y->Filtered_GapsLateral[1] = rtb_b;
  ControllerLateral_Y->Filtered_GapsLateral[2] = rtb_c_a;
  ControllerLateral_Y->Filtered_GapsLateral[3] = rtb_d;

  /* Outport: '<Root>/RefOutFront' */
  ControllerLateral_Y->RefOutFront = rtb_Add_i;

  /* Outport: '<Root>/RefOutBack' */
  ControllerLateral_Y->RefOutBack = rtb_Add1;

  /* Outport: '<Root>/L_K_i_out' */
  ControllerLateral_Y->L_K_i_out[0] =
    ControllerLateral_B->MovingAverage1_pnae.MovingAverage1;
  ControllerLateral_Y->L_K_i_out[1] =
    ControllerLateral_B->MovingAverage1_pnaev.MovingAverage1;

  /* Outport: '<Root>/LS_mode_vert' incorporates:
   *  Constant: '<Root>/Lane Switch Mode'
   */
  ControllerLateral_Y->LS_mode_vert = ControllerLateral_InstP->LS_mode;

  /* MATLAB Function: '<Root>/Lane Switch Transition1' incorporates:
   *  Constant: '<Root>/Lane Switch Mode'
   *  DigitalClock: '<Root>/Digital Clock'
   */
  /* MATLAB Function 'Lane Switch Transition1': '<S4>:1' */
  if (!(int32_T)ControllerLateral_DW->mode_old_not_empty) {
    /* '<S4>:1:5' */
    /* '<S4>:1:6' */
    ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;
    ControllerLateral_DW->mode_old_not_empty = true;
  }

  /* '<S4>:1:17' */
  /* '<S4>:1:18' */
  if (ControllerLateral_DW->mode_old != ControllerLateral_InstP->LS_mode) {
    /* '<S4>:1:22' */
    /* '<S4>:1:23' */
    ControllerLateral_DW->t_old = (((ControllerLateral_M->Timing.clockTick0+
      ControllerLateral_M->Timing.clockTickH0* 4294967296.0)) * 0.00025);

    /* '<S4>:1:24' */
    ControllerLateral_DW->mode_memory_old = ControllerLateral_DW->mode_old;
  }

  /* '<S4>:1:41' */
  ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;

  /* End of MATLAB Function: '<Root>/Lane Switch Transition1' */

  /* Outport: '<Root>/Complementary_B' */
  ControllerLateral_Y->Complementary_B = rtb_B2mm;

  /* Outport: '<Root>/Complementary_D' */
  ControllerLateral_Y->Complementary_D = rtb_D2mm;

  /* Logic: '<S7>/OR' incorporates:
   *  Inport: '<Root>/PropulsionOn'
   */
  ControllerLateral_B->OR_hn = (boolean_T)(((int32_T)
    ControllerLateral_U->PropulsionOn) || ((int32_T)ControllerLateral_B->Equal));

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
   */
  tmp = (boolean_T)!(int32_T)ControllerLateral_B->OR_hn;
  if ((((int32_T)ControllerLateral_B->OR_hn) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_lt <= 0)) ||
      (((int32_T)tmp) && ((int32_T)
                          ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_lt
        == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_ls = 0.0;
  }

  /* Outport: '<Root>/x_speed' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   */
  ControllerLateral_Y->x_speed =
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_ls;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
  if ((((int32_T)ControllerLateral_B->OR_hn) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m4 <= 0)) ||
      (((int32_T)tmp) && ((int32_T)
                          ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m4
        == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_m = 0.0;
  }

  /* Outport: '<Root>/x_location' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
   */
  ControllerLateral_Y->x_location =
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_m;

  /* Gain: '<S7>/Gain' incorporates:
   *  Inport: '<Root>/IMU_x'
   */
  ControllerLateral_B->Gain_k = ControllerLateral_InstP->kalman_xdotdot_gain *
    ControllerLateral_U->IMU_x;

  /* Outport: '<Root>/Complementary_A' */
  ControllerLateral_Y->Complementary_A = rtb_Switch3;

  /* Outport: '<Root>/Complementary_C' */
  ControllerLateral_Y->Complementary_C = rtb_Switch4_oh;

  /* Outport: '<Root>/Inertia' */
  ControllerLateral_Y->Inertia = rtb_Inertia;

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Sum: '<S9>/Subtract1'
   */
  ControllerLateral_B->Switch3_h = (real_T)!(rtb_Switch1 - 3.0 != 0.0);
}

/* Model update function */
void ControllerLateral_update(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M)
{
  B_ControllerLateral_T *ControllerLateral_B = ControllerLateral_M->blockIO;
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
  InstP_ControllerLateral_T *ControllerLateral_InstP =
    ControllerLateral_M->ControllerLateral_InstP_ref;
  ExtY_ControllerLateral_T *ControllerLateral_Y = (ExtY_ControllerLateral_T *)
    ControllerLateral_M->outputs;
  real_T tmp;
  int_T idxDelay;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE += 0.00025 *
    ControllerLateral_B->Switch3_h;

  /* Update for Memory: '<S9>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_dc = ControllerLateral_B->OR;

  /* Update for DiscreteIntegrator: '<S238>/Discrete-Time Integrator1' */
  ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE += 0.00025 *
    ControllerLateral_B->Add_c;
  ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for DiscreteIntegrator: '<S238>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator1'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l += 0.00025 *
    ControllerLateral_B->Add1_b;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for DiscreteIntegrator: '<S237>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S236>/Constant6'
   *  DiscreteIntegrator: '<S237>/Discrete-Time Integrator'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING_o = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g += 0.00025 *
    ControllerLateral_B->Add;
  if (ControllerLateral_InstP->ResetComplementary > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m = (int8_T)1;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)1;
  } else {
    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m = (int8_T)
        -1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m = (int8_T)2;
    }

    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)-1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)2;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S237>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_n = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d += 0.00025 *
    ControllerLateral_B->Add1;

  /* Update for Delay: '<Root>/Delay1' */
  ControllerLateral_DW->Delay1_DSTATE[0] =
    ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0];
  ControllerLateral_DW->Delay1_DSTATE[1] =
    ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1];

  /* Update for UnitDelay: '<S134>/Delay Input1' incorporates:
   *  Constant: '<S130>/Constant3'
   */
  ControllerLateral_DW->DelayInput1_DSTATE =
    ControllerLateral_InstP->lat_zero_reset;

  /* Update for UnitDelay: '<S133>/Delay Input1' */
  ControllerLateral_DW->DelayInput1_DSTATE_a = ControllerLateral_B->Equal;

  /* Update for DiscreteIntegrator: '<S168>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE += 0.00025 *
    ControllerLateral_B->SumI4;
  ControllerLateral_DW->Integrator_PrevResetState = (int8_T)
    ControllerLateral_B->OR_h;

  /* Update for Delay: '<S161>/UD' */
  ControllerLateral_DW->UD_DSTATE = ControllerLateral_B->Tsamp;

  /* Update for Delay: '<S16>/Delay1' */
  for (idxDelay = 0; idxDelay < 399; idxDelay++) {
    ControllerLateral_DW->Delay1_DSTATE_b[idxDelay] =
      ControllerLateral_DW->Delay1_DSTATE_b[idxDelay + 1];
  }

  ControllerLateral_DW->Delay1_DSTATE_b[399] = ControllerLateral_B->Product1;

  /* End of Update for Delay: '<S16>/Delay1' */

  /* Update for Sin: '<S16>/Sine Wave1' incorporates:
   *  Sin: '<S16>/Sine Wave2'
   */
  ControllerLateral_DW->counter++;
  tmp = floor(ControllerLateral_InstP->SineTime / 0.00025);
  if ((real_T)ControllerLateral_DW->counter == tmp) {
    ControllerLateral_DW->counter = 0;
  }

  /* End of Update for Sin: '<S16>/Sine Wave1' */

  /* Update for Sin: '<S16>/Sine Wave2' */
  ControllerLateral_DW->counter_k++;
  if ((real_T)ControllerLateral_DW->counter_k == tmp) {
    ControllerLateral_DW->counter_k = 0;
  }

  /* Update for DiscreteIntegrator: '<S61>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_n += 0.00025 *
    ControllerLateral_B->Switch;
  ControllerLateral_DW->Integrator_PrevResetState_o = (int8_T)
    ControllerLateral_B->Equal_p;

  /* Update for DiscreteIntegrator: '<S56>/Filter' incorporates:
   *  DiscreteIntegrator: '<S61>/Integrator'
   */
  ControllerLateral_DW->Filter_DSTATE += 0.00025 * ControllerLateral_B->NProdOut;
  ControllerLateral_DW->Filter_PrevResetState = (int8_T)
    ControllerLateral_B->Equal_p;

  /* Update for DiscreteIntegrator: '<S219>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S168>/Integrator'
   */
  ControllerLateral_DW->Integrator_DSTATE_o += 0.00025 *
    ControllerLateral_B->SumI4_e;
  ControllerLateral_DW->Integrator_PrevResetState_m = (int8_T)
    ControllerLateral_B->OR_h;

  /* Update for Delay: '<S212>/UD' */
  ControllerLateral_DW->UD_DSTATE_o = ControllerLateral_B->Tsamp_c;

  /* Update for DiscreteIntegrator: '<S113>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_m += 0.00025 *
    ControllerLateral_B->Switch_a;
  ControllerLateral_DW->Integrator_PrevResetState_j = (int8_T)
    ControllerLateral_B->Equal_b;

  /* Update for DiscreteIntegrator: '<S108>/Filter' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator'
   */
  ControllerLateral_DW->Filter_DSTATE_a += 0.00025 *
    ControllerLateral_B->NProdOut_k;
  ControllerLateral_DW->Filter_PrevResetState_j = (int8_T)
    ControllerLateral_B->Equal_b;

  /* Update for Delay: '<S15>/Delay2' */
  ControllerLateral_DW->Delay2_DSTATE = ControllerLateral_B->Switch4_b;

  /* Update for Delay: '<S14>/Delay2' */
  ControllerLateral_DW->Delay2_DSTATE_i = ControllerLateral_B->Switch4;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator1'
   *  Outport: '<Root>/Power_Lat'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f += 0.00025 *
    ControllerLateral_Y->Power_Lat;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_g = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for Delay: '<S14>/Delay1' */
  ControllerLateral_DW->Delay1_DSTATE_f = ControllerLateral_B->Switch5;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b += 0.00025 *
    ControllerLateral_B->Switch3;
  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b >= 1.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 1.0;
  } else if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b <= 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
  }

  if (ControllerLateral_B->Delay1 > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p = (int8_T)1;
  } else if (ControllerLateral_B->Delay1 < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p = (int8_T)-1;
  } else if (ControllerLateral_B->Delay1 == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for Delay: '<S14>/Delay' */
  ControllerLateral_DW->Delay_DSTATE[0] = ControllerLateral_DW->Delay_DSTATE[1];
  ControllerLateral_DW->Delay_DSTATE[1] = ControllerLateral_B->Switch5;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_b += 0.00025 *
    ControllerLateral_B->Switch4;
  if (ControllerLateral_B->Delay > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a = (int8_T)1;
  } else if (ControllerLateral_B->Delay < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a = (int8_T)-1;
  } else if (ControllerLateral_B->Delay == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S15>/Delay1' */
  ControllerLateral_DW->Delay1_DSTATE_j = ControllerLateral_B->Switch5_e;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e += 0.00025 *
    ControllerLateral_B->Switch3_m;
  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e >= 1.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 1.0;
  } else if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e <= 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 0.0;
  }

  if (ControllerLateral_B->Delay1_f > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j = (int8_T)1;
  } else if (ControllerLateral_B->Delay1_f < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j = (int8_T)-1;
  } else if (ControllerLateral_B->Delay1_f == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Update for Delay: '<S15>/Delay' */
  ControllerLateral_DW->Delay_DSTATE_g[0] = ControllerLateral_DW->
    Delay_DSTATE_g[1];
  ControllerLateral_DW->Delay_DSTATE_g[1] = ControllerLateral_B->Switch5_e;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_n += 0.00025 *
    ControllerLateral_B->Switch4_b;
  if (ControllerLateral_B->Delay_d > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o = (int8_T)1;
  } else if (ControllerLateral_B->Delay_d < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o = (int8_T)-1;
  } else if (ControllerLateral_B->Delay_d == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */

  /* Update for Delay: '<Root>/Delay2' */
  ControllerLateral_DW->Delay2_DSTATE_f[0] =
    ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[0];
  ControllerLateral_DW->Delay2_DSTATE_f[1] =
    ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[1];

  /* Update for DiscreteIntegrator: '<S251>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S236>/Constant6'
   *  DiscreteIntegrator: '<S250>/Discrete-Time Integrator'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n += 0.00025 *
    ControllerLateral_B->Add6;
  if (ControllerLateral_InstP->ResetComplementary > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k = (int8_T)1;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m = (int8_T)1;
  } else {
    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k = (int8_T)-1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k = (int8_T)2;
    }

    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m = (int8_T)-1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m = (int8_T)2;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S251>/Discrete-Time Integrator' */

  /* Update for Memory: '<S244>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput = ControllerLateral_B->Gain3_i;

  /* Update for Memory: '<S244>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput = ControllerLateral_B->Gain10;

  /* Update for DiscreteIntegrator: '<S250>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g += 0.00025 *
    ControllerLateral_B->Add2;

  /* Update for DiscreteIntegrator: '<S379>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_m1 += 0.00025 *
    ControllerLateral_B->diff2;

  /* Update for DiscreteIntegrator: '<S374>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_d += 0.00025 *
    ControllerLateral_B->FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S283>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_ok += 0.00025 *
    ControllerLateral_B->diff1;

  /* Update for DiscreteIntegrator: '<S278>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_b += 0.00025 *
    ControllerLateral_B->FilterCoefficient_o;

  /* Update for DiscreteIntegrator: '<S331>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_f += 0.00025 *
    ControllerLateral_B->diff2;

  /* Update for DiscreteIntegrator: '<S326>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_dy += 0.00025 *
    ControllerLateral_B->FilterCoefficient_n;

  /* Update for Memory: '<S245>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_k = ControllerLateral_B->Gain9;

  /* Update for Memory: '<S245>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_n = ControllerLateral_B->Gain10_e;

  /* Update for DiscreteIntegrator: '<S427>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_or += 0.00025 *
    ControllerLateral_B->diff1;

  /* Update for DiscreteIntegrator: '<S422>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_g += 0.00025 *
    ControllerLateral_B->FilterCoefficient_p;

  /* Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator1'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq += 0.00025 *
    ControllerLateral_B->Add6_g;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_c = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for Memory: '<S445>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_d = ControllerLateral_B->Gain3_i;

  /* Update for Memory: '<S445>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_g = ControllerLateral_B->Gain10_o;

  /* Update for DiscreteIntegrator: '<S450>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S238>/Discrete-Time Integrator1'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o += 0.00025 *
    ControllerLateral_B->Add2_a;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_h = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for DiscreteIntegrator: '<S579>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_b += 0.00025 *
    ControllerLateral_B->diff2_k;

  /* Update for DiscreteIntegrator: '<S574>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_a1 += 0.00025 *
    ControllerLateral_B->FilterCoefficient_e;

  /* Update for DiscreteIntegrator: '<S483>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_a += 0.00025 *
    ControllerLateral_B->diff1_k;

  /* Update for DiscreteIntegrator: '<S478>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_n += 0.00025 *
    ControllerLateral_B->FilterCoefficient_ow;

  /* Update for DiscreteIntegrator: '<S531>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_p += 0.00025 *
    ControllerLateral_B->diff2_k;

  /* Update for DiscreteIntegrator: '<S526>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_dv += 0.00025 *
    ControllerLateral_B->FilterCoefficient_f;

  /* Update for Memory: '<S444>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_l = ControllerLateral_B->Gain2;

  /* Update for Memory: '<S444>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_d = ControllerLateral_B->Gain10_ol;

  /* Update for DiscreteIntegrator: '<S627>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_i += 0.00025 *
    ControllerLateral_B->diff1_k;

  /* Update for DiscreteIntegrator: '<S622>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_b5 += 0.00025 *
    ControllerLateral_B->FilterCoefficient_k;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_ls += 0.00025 *
    ControllerLateral_B->Gain_k;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_lt = (int8_T)
    ControllerLateral_B->OR_hn;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Outport: '<Root>/x_speed'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_m += 0.00025 *
    ControllerLateral_Y->x_speed;
  ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m4 = (int8_T)
    ControllerLateral_B->OR_hn;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.00025, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  ControllerLateral_M->Timing.clockTick0++;
  if (!ControllerLateral_M->Timing.clockTick0) {
    ControllerLateral_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void ControllerLateral_initialize(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M)
{
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;

  /* Constant: '<S241>/Constant' */
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);

  /* Constant: '<S239>/Constant' */
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfp);

  /* Constant: '<S242>/Constant' */
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfpgh5);

  /* Constant: '<S240>/Constant' */
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfpg);

  /* Constant: '<S22>/Constant' */
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage);

  /* Constant: '<S23>/Constant' */
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage_p);

  /* Constant: '<S24>/Constant' */
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage_pn);

  /* Constant: '<S25>/Constant' */
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage_pna);
  ControllerLateral_MovingAverage_p_Start
    (&ControllerLateral_DW->MovingAverage_pnaev);
  ControllerLateral_MovingAverage_p_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvf);

  /* Start for MATLABSystem: '<S12>/Moving Average' */
  ControllerLateral_DW->obj.matlabCodegenIsDeleted = true;
  ControllerLateral_DW->obj.isInitialized = 0;
  ControllerLateral_DW->obj.NumChannels = -1;
  ControllerLateral_DW->obj.matlabCodegenIsDeleted = false;
  ControllerLateral_DW->objisempty = true;
  ControllerLateral_DW->obj.isSetupComplete = false;
  ControllerLateral_DW->obj.isInitialized = 1;
  ControllerLateral_DW->obj.NumChannels = 1;
  ControllerLateral_DW->obj._pobj0.isInitialized = 0;
  ControllerLateral_DW->obj.pStatistic = &ControllerLateral_DW->obj._pobj0;
  ControllerLateral_DW->obj.isSetupComplete = true;
  ControllerLateral_DW->obj.TunablePropsChanged = false;
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnae);
  ControllerLateral_MovingAverage1_Start
    (&ControllerLateral_DW->MovingAverage1_pnae);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnaevv);
  ControllerLateral_MovingAverage1_Start
    (&ControllerLateral_DW->MovingAverage1_pnaev);

  {
    c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE = 0.0;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_dc = false;

    /* InitializeConditions for DiscreteIntegrator: '<S238>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S238>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S237>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING_o = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_n = (uint8_T)1U;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    ControllerLateral_DW->Delay1_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S134>/Delay Input1' */
    ControllerLateral_DW->DelayInput1_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S133>/Delay Input1' */
    ControllerLateral_DW->DelayInput1_DSTATE_a = false;

    /* InitializeConditions for DiscreteIntegrator: '<S168>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState = (int8_T)2;

    /* InitializeConditions for Delay: '<S161>/UD' */
    ControllerLateral_DW->UD_DSTATE = 0.0;

    /* InitializeConditions for DiscretePulseGenerator: '<S16>/Pulse Generator' */
    ControllerLateral_DW->clockTickCounter = 0;

    /* InitializeConditions for Delay: '<S16>/Delay1' */
    for (i = 0; i < 400; i++) {
      ControllerLateral_DW->Delay1_DSTATE_b[i] = 0.0;
    }

    /* End of InitializeConditions for Delay: '<S16>/Delay1' */

    /* InitializeConditions for Sin: '<S16>/Sine Wave1' */
    ControllerLateral_DW->counter = 0;

    /* InitializeConditions for Sin: '<S16>/Sine Wave2' */
    ControllerLateral_DW->counter_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S61>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_o = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S56>/Filter' */
    ControllerLateral_DW->Filter_DSTATE = 0.0;
    ControllerLateral_DW->Filter_PrevResetState = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S219>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_o = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_m = (int8_T)2;

    /* InitializeConditions for Delay: '<S212>/UD' */
    ControllerLateral_DW->UD_DSTATE_o = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_m = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_j = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_a = 0.0;
    ControllerLateral_DW->Filter_PrevResetState_j = (int8_T)2;

    /* InitializeConditions for Delay: '<S15>/Delay2' */
    ControllerLateral_DW->Delay2_DSTATE = 0.0;

    /* InitializeConditions for Delay: '<S14>/Delay2' */
    ControllerLateral_DW->Delay2_DSTATE_i = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_g = (int8_T)2;

    /* InitializeConditions for Delay: '<S14>/Delay1' */
    ControllerLateral_DW->Delay1_DSTATE_f = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_p = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_b = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_a = (int8_T)2;

    /* InitializeConditions for Delay: '<S15>/Delay1' */
    ControllerLateral_DW->Delay1_DSTATE_j = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_j = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_n = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_o = (int8_T)2;

    /* InitializeConditions for Delay: '<S14>/Delay' */
    ControllerLateral_DW->Delay_DSTATE[0] = 0.0;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    ControllerLateral_DW->Delay_DSTATE_g[0] = 0.0;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    ControllerLateral_DW->Delay2_DSTATE_f[0] = 0.0;

    /* InitializeConditions for Delay: '<S14>/Delay' */
    ControllerLateral_DW->Delay_DSTATE[1] = 0.0;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    ControllerLateral_DW->Delay_DSTATE_g[1] = 0.0;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    ControllerLateral_DW->Delay2_DSTATE_f[1] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S251>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_k = (int8_T)2;

    /* InitializeConditions for Memory: '<S244>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput = 0.0;

    /* InitializeConditions for Memory: '<S244>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S250>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_m = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_m1 = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S374>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S283>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_ok = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S278>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_b = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S331>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_f = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S326>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_dy = 0.0;

    /* InitializeConditions for Memory: '<S245>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_k = 0.0;

    /* InitializeConditions for Memory: '<S245>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_n = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S427>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_or = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S422>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_g = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_c = (int8_T)2;

    /* InitializeConditions for Memory: '<S445>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_d = 0.0;

    /* InitializeConditions for Memory: '<S445>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_g = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S450>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_h = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S579>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_b = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S574>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_a1 = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S483>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_a = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S478>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_n = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S531>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_p = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S526>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_dv = 0.0;

    /* InitializeConditions for Memory: '<S444>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_l = 0.0;

    /* InitializeConditions for Memory: '<S444>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_d = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_i = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S622>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_b5 = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_ls = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_lt = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_m = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState_m4 = (int8_T)2;

    /* SystemInitialize for MATLAB Function: '<Root>/Lane Switch Transition1' */
    ControllerLateral_DW->mode_old_not_empty = false;
    ControllerLateral_DW->t_old = -1000.0;
    ControllerLateral_DW->mode_memory_old = -1.0;
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevv);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfp);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpgh5);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvf);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage1);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage1_p);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage_p);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pn);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage_pn);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pna);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pna);
    ControllerLateral_MovingAverage_h_Init
      (&ControllerLateral_DW->MovingAverage_pnaev);
    ControllerLateral_MovingAverage_h_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvf);

    /* InitializeConditions for MATLABSystem: '<S12>/Moving Average' */
    obj = ControllerLateral_DW->obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0;
      for (i = 0; i < 1999; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S12>/Moving Average' */
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnae);
    ControllerLateral_MovingAverage1_Init
      (&ControllerLateral_DW->MovingAverage1_pnae);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnaevv);
    ControllerLateral_MovingAverage1_Init
      (&ControllerLateral_DW->MovingAverage1_pnaev);
  }
}

/* Model terminate function */
void ControllerLateral_terminate(RT_MODEL_ControllerLateral_T
  * ControllerLateral_M)
{
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfp);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpgh5);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_p);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_pn);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_pna);
  ControllerLateral_MovingAverage_p_Term
    (&ControllerLateral_DW->MovingAverage_pnaev);
  ControllerLateral_MovingAverage_p_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvf);

  /* Terminate for MATLABSystem: '<S12>/Moving Average' */
  if (!(int32_T)ControllerLateral_DW->obj.matlabCodegenIsDeleted) {
    ControllerLateral_DW->obj.matlabCodegenIsDeleted = true;
    if ((ControllerLateral_DW->obj.isInitialized == 1) && ((int32_T)
         ControllerLateral_DW->obj.isSetupComplete)) {
      obj = ControllerLateral_DW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      ControllerLateral_DW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Moving Average' */
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnae);
  ControllerLateral_MovingAverage1_Term
    (&ControllerLateral_DW->MovingAverage1_pnae);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnaevv);
  ControllerLateral_MovingAverage1_Term
    (&ControllerLateral_DW->MovingAverage1_pnaev);

  /* model code */
  rt_FREE(ControllerLateral_M->blockIO);
  rt_FREE(ControllerLateral_M->inputs);
  rt_FREE(ControllerLateral_M->outputs);
  rt_FREE(ControllerLateral_M->dwork);
  rt_FREE(ControllerLateral_M->prevZCSigState);

  /* Free instance parameters */
  rt_FREE(ControllerLateral_M->ControllerLateral_InstP_ref);
  rt_FREE(ControllerLateral_M);
}

/* Model data allocation function */
RT_MODEL_ControllerLateral_T *ControllerLateral(void)
{
  RT_MODEL_ControllerLateral_T *ControllerLateral_M;
  ControllerLateral_M = (RT_MODEL_ControllerLateral_T *) malloc(sizeof
    (RT_MODEL_ControllerLateral_T));
  if (ControllerLateral_M == NULL) {
    return NULL;
  }

  (void) memset((char *)ControllerLateral_M, 0,
                sizeof(RT_MODEL_ControllerLateral_T));

  /* block I/O */
  {
    B_ControllerLateral_T *b = (B_ControllerLateral_T *) malloc(sizeof
      (B_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,b);
    ControllerLateral_M->blockIO = (b);
  }

  /* Initialize instance parameters */
  {
    InstP_ControllerLateral_T *group__InstP = (InstP_ControllerLateral_T *)
      malloc(sizeof(InstP_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,group__InstP);
    ControllerLateral_M->ControllerLateral_InstP_ref = (group__InstP);
    (void) memcpy(group__InstP, &ControllerLateral_InstP,
                  sizeof(InstP_ControllerLateral_T));
  }

  /* states (dwork) */
  {
    DW_ControllerLateral_T *dwork = (DW_ControllerLateral_T *) malloc(sizeof
      (DW_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,dwork);
    ControllerLateral_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_ControllerLateral_T *ControllerLateral_U = (ExtU_ControllerLateral_T *)
      malloc(sizeof(ExtU_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,ControllerLateral_U);
    ControllerLateral_M->inputs = (((ExtU_ControllerLateral_T *)
      ControllerLateral_U));
  }

  /* external outputs */
  {
    ExtY_ControllerLateral_T *ControllerLateral_Y = (ExtY_ControllerLateral_T *)
      malloc(sizeof(ExtY_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,ControllerLateral_Y);
    ControllerLateral_M->outputs = (ControllerLateral_Y);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_ControllerLateral_T *zc = (PrevZCX_ControllerLateral_T *) malloc
      (sizeof(PrevZCX_ControllerLateral_T));
    rt_VALIDATE_MEMORY(ControllerLateral_M,zc);
    ControllerLateral_M->prevZCSigState = (zc);
  }

  {
    B_ControllerLateral_T *ControllerLateral_B = ControllerLateral_M->blockIO;
    DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
    PrevZCX_ControllerLateral_T *ControllerLateral_PrevZCX =
      ControllerLateral_M->prevZCSigState;
    ExtU_ControllerLateral_T *ControllerLateral_U = (ExtU_ControllerLateral_T *)
      ControllerLateral_M->inputs;
    ExtY_ControllerLateral_T *ControllerLateral_Y = (ExtY_ControllerLateral_T *)
      ControllerLateral_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* block I/O */
    (void) memset(((void *) ControllerLateral_B), 0,
                  sizeof(B_ControllerLateral_T));

    {
      ControllerLateral_B->Tsamp = 0.0;
      ControllerLateral_B->Product1 = 0.0;
      ControllerLateral_B->NProdOut = 0.0;
      ControllerLateral_B->Tsamp_c = 0.0;
      ControllerLateral_B->NProdOut_k = 0.0;
      ControllerLateral_B->Delay1 = 0.0;
      ControllerLateral_B->Delay = 0.0;
      ControllerLateral_B->Switch4 = 0.0;
      ControllerLateral_B->Switch3 = 0.0;
      ControllerLateral_B->Switch5 = 0.0;
      ControllerLateral_B->Delay1_f = 0.0;
      ControllerLateral_B->Delay_d = 0.0;
      ControllerLateral_B->Switch4_b = 0.0;
      ControllerLateral_B->Switch3_m = 0.0;
      ControllerLateral_B->Switch5_e = 0.0;
      ControllerLateral_B->Switch = 0.0;
      ControllerLateral_B->Switch_a = 0.0;
      ControllerLateral_B->SumI4 = 0.0;
      ControllerLateral_B->SumI4_e = 0.0;
      ControllerLateral_B->Gain3_i = 0.0;
      ControllerLateral_B->Gain10 = 0.0;
      ControllerLateral_B->diff2 = 0.0;
      ControllerLateral_B->FilterCoefficient = 0.0;
      ControllerLateral_B->Add = 0.0;
      ControllerLateral_B->diff1 = 0.0;
      ControllerLateral_B->FilterCoefficient_o = 0.0;
      ControllerLateral_B->Add1 = 0.0;
      ControllerLateral_B->FilterCoefficient_n = 0.0;
      ControllerLateral_B->Gain2 = 0.0;
      ControllerLateral_B->Gain9 = 0.0;
      ControllerLateral_B->Gain10_e = 0.0;
      ControllerLateral_B->Add2 = 0.0;
      ControllerLateral_B->FilterCoefficient_p = 0.0;
      ControllerLateral_B->Add6 = 0.0;
      ControllerLateral_B->Gain10_o = 0.0;
      ControllerLateral_B->diff2_k = 0.0;
      ControllerLateral_B->FilterCoefficient_e = 0.0;
      ControllerLateral_B->Add_c = 0.0;
      ControllerLateral_B->diff1_k = 0.0;
      ControllerLateral_B->FilterCoefficient_ow = 0.0;
      ControllerLateral_B->Add1_b = 0.0;
      ControllerLateral_B->FilterCoefficient_f = 0.0;
      ControllerLateral_B->Gain10_ol = 0.0;
      ControllerLateral_B->Add2_a = 0.0;
      ControllerLateral_B->FilterCoefficient_k = 0.0;
      ControllerLateral_B->Add6_g = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[0] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[1] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1] = 0.0;
      ControllerLateral_B->Gain_k = 0.0;
      ControllerLateral_B->Switch3_h = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpgh5.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpgh.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaev.MovingAverage1 = 0.0;
      ControllerLateral_B->MovingAverage_pnaevv.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaev.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnae.MovingAverage1 = 0.0;
      ControllerLateral_B->MovingAverage_pnae.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pna.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pna.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pn.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pn.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_p.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_p.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage.MovingAverage = 0.0;
    }

    /* states (dwork) */
    (void) memset((void *)ControllerLateral_DW, 0,
                  sizeof(DW_ControllerLateral_T));
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_g = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[1] = 0.0;
    ControllerLateral_DW->DelayInput1_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
    ControllerLateral_DW->UD_DSTATE = 0.0;

    {
      int32_T i;
      for (i = 0; i < 400; i++) {
        ControllerLateral_DW->Delay1_DSTATE_b[i] = 0.0;
      }
    }

    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
    ControllerLateral_DW->Filter_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_o = 0.0;
    ControllerLateral_DW->UD_DSTATE_o = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_m = 0.0;
    ControllerLateral_DW->Filter_DSTATE_a = 0.0;
    ControllerLateral_DW->Delay2_DSTATE = 0.0;
    ControllerLateral_DW->Delay2_DSTATE_i = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
    ControllerLateral_DW->Delay1_DSTATE_f = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
    ControllerLateral_DW->Delay_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay_DSTATE[1] = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_b = 0.0;
    ControllerLateral_DW->Delay1_DSTATE_j = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_e = 0.0;
    ControllerLateral_DW->Delay_DSTATE_g[0] = 0.0;
    ControllerLateral_DW->Delay_DSTATE_g[1] = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_n = 0.0;
    ControllerLateral_DW->Delay2_DSTATE_f[0] = 0.0;
    ControllerLateral_DW->Delay2_DSTATE_f[1] = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_n = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_g = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_m1 = 0.0;
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_ok = 0.0;
    ControllerLateral_DW->Filter_DSTATE_b = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_f = 0.0;
    ControllerLateral_DW->Filter_DSTATE_dy = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_or = 0.0;
    ControllerLateral_DW->Filter_DSTATE_g = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_fq = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_o = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_b = 0.0;
    ControllerLateral_DW->Filter_DSTATE_a1 = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_a = 0.0;
    ControllerLateral_DW->Filter_DSTATE_n = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_p = 0.0;
    ControllerLateral_DW->Filter_DSTATE_dv = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_i = 0.0;
    ControllerLateral_DW->Filter_DSTATE_b5 = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_ls = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE_m = 0.0;
    ControllerLateral_DW->Memory_PreviousInput = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_k = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_n = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_d = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_g = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_l = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_d = 0.0;
    ControllerLateral_DW->mode_old = 0.0;
    ControllerLateral_DW->t_old = 0.0;
    ControllerLateral_DW->mode_memory_old = 0.0;

    /* external inputs */
    (void)memset(ControllerLateral_U, 0, sizeof(ExtU_ControllerLateral_T));
    ControllerLateral_U->G_A2 = 0.0;
    ControllerLateral_U->G_B2 = 0.0;
    ControllerLateral_U->G_C2 = 0.0;
    ControllerLateral_U->G_D2 = 0.0;
    ControllerLateral_U->motor1 = 0.0;
    ControllerLateral_U->motor2 = 0.0;
    ControllerLateral_U->hems1 = 0.0;
    ControllerLateral_U->hems2 = 0.0;
    ControllerLateral_U->hems3 = 0.0;
    ControllerLateral_U->hems4 = 0.0;
    ControllerLateral_U->I_Front_m = 0.0;
    ControllerLateral_U->I_Back_m = 0.0;
    ControllerLateral_U->LateralAxisState = 0.0;
    ControllerLateral_U->VrF = 0.0;
    ControllerLateral_U->VrB = 0.0;
    ControllerLateral_U->VtF = 0.0;
    ControllerLateral_U->VtB = 0.0;
    ControllerLateral_U->IMU_x = 0.0;
    ControllerLateral_U->IMU_yaw = 0.0;
    ControllerLateral_U->IMU_y = 0.0;

    /* external outputs */
    ControllerLateral_Y->Mode = 0.0;
    ControllerLateral_Y->LinposLateral[0] = 0.0;
    ControllerLateral_Y->LinposLateral[1] = 0.0;
    ControllerLateral_Y->LinposLateral[2] = 0.0;
    ControllerLateral_Y->LinposLateral[3] = 0.0;
    ControllerLateral_Y->Filtered_GapsLateral[0] = 0.0;
    ControllerLateral_Y->Filtered_GapsLateral[1] = 0.0;
    ControllerLateral_Y->Filtered_GapsLateral[2] = 0.0;
    ControllerLateral_Y->Filtered_GapsLateral[3] = 0.0;
    ControllerLateral_Y->ControlSIgnalsLateral[0] = 0.0;
    ControllerLateral_Y->ControlSIgnalsLateral[1] = 0.0;
    ControllerLateral_Y->ControlSignalsLateralFinal[0] = 0.0;
    ControllerLateral_Y->ControlSignalsLateralFinal[1] = 0.0;
    ControllerLateral_Y->OffsetFront = 0.0;
    ControllerLateral_Y->OffsetBack = 0.0;
    ControllerLateral_Y->RefOutFront = 0.0;
    ControllerLateral_Y->RefOutBack = 0.0;
    ControllerLateral_Y->I_Demand_Front = 0.0;
    ControllerLateral_Y->I_Demand_Back = 0.0;
    ControllerLateral_Y->Power_Lat = 0.0;
    ControllerLateral_Y->Power_Lat_avg = 0.0;
    ControllerLateral_Y->Energy_Lat = 0.0;
    ControllerLateral_Y->EMS_F_Front = 0.0;
    ControllerLateral_Y->EMS_F_Back = 0.0;
    ControllerLateral_Y->L_K_i_out[0] = 0.0;
    ControllerLateral_Y->L_K_i_out[1] = 0.0;
    ControllerLateral_Y->uncapped_current = 0.0;
    ControllerLateral_Y->LS_mode_vert = 0.0;
    ControllerLateral_Y->Complementary_B = 0.0;
    ControllerLateral_Y->Complementary_D = 0.0;
    ControllerLateral_Y->x_speed = 0.0;
    ControllerLateral_Y->x_location = 0.0;
    ControllerLateral_Y->Complementary_A = 0.0;
    ControllerLateral_Y->Complementary_C = 0.0;
    ControllerLateral_Y->Inertia = 0.0;

    /* previous zero-crossing states */
    {
      ControllerLateral_PrevZCX->UD_Reset_ZCE = UNINITIALIZED_ZCSIG;
      ControllerLateral_PrevZCX->UD_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    }
  }

  return ControllerLateral_M;
}
