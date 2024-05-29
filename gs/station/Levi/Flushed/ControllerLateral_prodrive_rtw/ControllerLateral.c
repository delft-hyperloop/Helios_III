/*
 * ControllerLateral.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControllerLateral".
 *
 * Model version              : 6.194
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon May 20 14:18:02 2024
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
  (dsp_simulink_MovingAverage_ControllerLateral_e_T *obj);

/* Forward declaration for local functions */
static real_T ControllerLateral_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj, real_T u);
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

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_Init(DW_MovingAverage_ControllerLateral_T
  *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S14>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S14>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_Start(DW_MovingAverage_ControllerLateral_T *
  localDW)
{
  /* Start for MATLABSystem: '<S14>/Moving Average' */
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
void ControllerLateral_MovingAverage(real_T rtu_0,
  B_MovingAverage_ControllerLateral_T *localB,
  DW_MovingAverage_ControllerLateral_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;
  real_T csumrev[7];
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S14>/Moving Average' */
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

  /* MATLABSystem: '<S14>/Moving Average' */
  localB->MovingAverage = z / 8.0;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ControllerLateral_MovingAverage_Term(DW_MovingAverage_ControllerLateral_T
  *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *obj;

  /* Terminate for MATLABSystem: '<S14>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S14>/Moving Average' */
}

static void ControllerLateral_SystemCore_setup
  (dsp_simulink_MovingAverage_ControllerLateral_e_T *obj)
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
void ControllerLateral_MovingAverage_p_Init
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* InitializeConditions for MATLABSystem: '<S72>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S72>/Moving Average' */
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
void ControllerLateral_MovingAverage_n_Start
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  /* Start for MATLABSystem: '<S72>/Moving Average' */
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
void ControllerLateral_MovingAverage_p(real_T rtu_0, real_T rtu_1,
  B_MovingAverage_ControllerLateral_c_T *localB,
  DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T varargin_1;
  boolean_T p;

  /* MATLABSystem: '<S72>/Moving Average' */
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

  /* MATLABSystem: '<S72>/Moving Average' */
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
void ControllerLateral_MovingAverage_d_Term
  (DW_MovingAverage_ControllerLateral_f_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj;

  /* Terminate for MATLABSystem: '<S72>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S72>/Moving Average' */
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 */
void ControllerLateral_MATLABFunction(real_T rtu_mode,
  B_MATLABFunction_ControllerLateral_T *localB)
{
  /* MATLAB Function 'MATLAB Function': '<S5>:1' */
  if (!(rtu_mode == 0.0)) {
    if (rtu_mode == 2.0) {
      /* '<S5>:1:4' */
      if (localB->current > 0.0) {
        /* '<S5>:1:5' */
        /* '<S5>:1:6' */
        localB->current = 0.0;
      }
    } else if ((rtu_mode == 1.0) && (localB->current < 0.0)) {
      /* '<S5>:1:8' */
      /* '<S5>:1:9' */
      /* '<S5>:1:10' */
      localB->current = 0.0;
    }
  } else {
    /* '<S5>:1:2' */
  }
}

/*
 * Termination for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 */
void ControllerLateral_MATLABFunction_Term(void)
{
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
  real_T rtb_Switch3;
  real_T rtb_Switch1_c;
  real_T rtb_error_j;
  real_T rtb_error_l;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  real_T rtb_uDLookupTable2[9];
  real_T rtb_uDLookupTable2_p[9];
  real_T rtb_Gain_a[5];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_Add;
  real_T rtb_Add1;
  real_T rtb_Add1_f;
  real_T rtb_Add_i;
  real_T rtb_Beta;
  real_T rtb_DigitalClock_h;
  real_T rtb_Divide1;
  real_T rtb_Divide1_o;
  real_T rtb_Gain1;
  real_T rtb_Gain2;
  real_T rtb_Gain2_i;
  real_T rtb_Gain3;
  real_T rtb_Gain_f_idx_0;
  real_T rtb_Gain_f_idx_1;
  real_T rtb_IProdOut;
  real_T rtb_IProdOut_p;
  real_T rtb_Sign;
  real_T rtb_Sign_l;
  real_T rtb_Sum;
  real_T rtb_Sum_k;
  real_T rtb_Sum_l;
  real_T rtb_Sum_p;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  real_T rtb_Switch1_e_idx_1;
  real_T rtb_Switch2_i;
  real_T rtb_Switch2_idx_0;
  real_T rtb_Switch2_idx_1;
  real_T rtb_Switch2_no;
  real_T rtb_Switch7;
  real_T rtb_Switch_g;
  real_T rtb_Switch_gp;
  real_T rtb_Switch_i;
  real_T rtb_Switch_i2;
  real_T rtb_Switch_m5;
  real_T rtb_Switch_n;
  real_T rtb_Switch_p;
  real_T rtb_mode_fore;
  real_T rtb_offset;
  real_T rtb_offset_i;
  real_T rtb_uDLookupTable1;
  real_T rtb_uDLookupTable1_n;
  int32_T i;
  int32_T rtb_PulseGenerator;
  int32_T rtb_Switch4;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T tmp;

  /* Switch: '<S8>/Switch4' incorporates:
   *  Constant: '<S8>/Constant6'
   *  Constant: '<S8>/Constant7'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
   */
  if (ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE >
      ControllerLateral_InstP->LandingTime) {
    rtb_Switch4 = 2;
  } else {
    rtb_Switch4 = 3;
  }

  /* End of Switch: '<S8>/Switch4' */

  /* Logic: '<S8>/OR' incorporates:
   *  Constant: '<S244>/Constant'
   *  Memory: '<S8>/Memory'
   *  RelationalOperator: '<S244>/Compare'
   */
  ControllerLateral_B->OR = (boolean_T)((rtb_Switch4 == 2) || ((int32_T)
    ControllerLateral_DW->Memory_PreviousInput));

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (ControllerLateral_InstP->LateralOperatingMode != 0.0) {
    rtb_Switch1 = ControllerLateral_InstP->LateralOperatingMode;
  } else {
    /* DigitalClock: '<S8>/Digital Clock1' incorporates:
     *  DigitalClock: '<S8>/Digital Clock'
     */
    rtb_Gain_f_idx_0 = (((ControllerLateral_M->Timing.clockTick0+
                          ControllerLateral_M->Timing.clockTickH0* 4294967296.0))
                        * 0.00025);

    /* Switch: '<S8>/Switch6' incorporates:
     *  Constant: '<S8>/Constant12'
     *  Constant: '<S8>/Constant13'
     *  DigitalClock: '<S8>/Digital Clock1'
     *  Sum: '<S8>/Subtract3'
     */
    if (((ControllerLateral_InstP->RunTime +
          ControllerLateral_InstP->StartupTime) + 2.0) - rtb_Gain_f_idx_0 > 0.0)
    {
      /* Switch: '<S8>/Switch' incorporates:
       *  Constant: '<S8>/Constant2'
       *  Constant: '<S8>/Constant3'
       *  Sum: '<S8>/Subtract'
       */
      if ((ControllerLateral_InstP->StartupTime + 2.0) - rtb_Gain_f_idx_0 > 0.0)
      {
        rtb_Switch1 = ControllerLateral_InstP->LateralOperatingMode;
      } else {
        rtb_Switch1 = 1.0;
      }

      /* End of Switch: '<S8>/Switch' */
    } else {
      rtb_Switch1 = 3.0;
    }

    /* End of Switch: '<S8>/Switch6' */
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Switch: '<S8>/Switch7' incorporates:
   *  Constant: '<S8>/Constant11'
   *  Constant: '<S8>/Constant4'
   *  Sum: '<S8>/Subtract1'
   *  Switch: '<S8>/Switch2'
   */
  if (ControllerLateral_B->OR) {
    rtb_Switch7 = 2.0;
  } else if (rtb_Switch1 - 3.0 != 0.0) {
    /* Switch: '<S8>/Switch2' */
    rtb_Switch7 = rtb_Switch1;
  } else {
    rtb_Switch7 = (real_T)rtb_Switch4;
  }

  /* End of Switch: '<S8>/Switch7' */

  /* Outport: '<Root>/Mode' */
  ControllerLateral_Y->Mode = rtb_Switch7;

  /* Gain: '<S7>/Gain' incorporates:
   *  Inport: '<Root>/G_A2'
   *  Inport: '<Root>/G_B2'
   *  Inport: '<Root>/G_C2'
   *  Inport: '<Root>/G_D2'
   */
  rtb_Gain[0] = 1000.0 * ControllerLateral_U->G_A2;
  rtb_Gain[1] = 1000.0 * ControllerLateral_U->G_B2;
  rtb_Gain[2] = 1000.0 * ControllerLateral_U->G_C2;
  rtb_Gain[3] = 1000.0 * ControllerLateral_U->G_D2;

  /* Constant: '<S233>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Gain[0],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnae,
    &ControllerLateral_DW->MovingAverage1_pnae);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pnae.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevv,
     &ControllerLateral_DW->MovingAverage_pnaevv);

  /* Switch: '<S233>/Switch' incorporates:
   *  Constant: '<S233>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch = ControllerLateral_B->MovingAverage_pnaevv.MovingAverage;
  } else {
    rtb_Switch = ControllerLateral_B->MovingAverage1_pnae.MovingAverage;
  }

  /* End of Switch: '<S233>/Switch' */

  /* Constant: '<S234>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Gain[1],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaev,
    &ControllerLateral_DW->MovingAverage1_pnaev);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pnaev.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvf,
     &ControllerLateral_DW->MovingAverage_pnaevvf);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_m5 = ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage;
  } else {
    rtb_Switch_m5 = ControllerLateral_B->MovingAverage1_pnaev.MovingAverage;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Constant: '<S235>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Gain[2],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevv,
    &ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfp,
     &ControllerLateral_DW->MovingAverage_pnaevvfp);

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_g = ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage;
  } else {
    rtb_Switch_g = ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Constant: '<S236>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Gain[3],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvf,
    &ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpg,
     &ControllerLateral_DW->MovingAverage_pnaevvfpg);

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_i = ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage;
  } else {
    rtb_Switch_i = ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage;
  }

  /* End of Switch: '<S236>/Switch' */

  /* Outport: '<Root>/Linpos Lateral' */
  ControllerLateral_Y->LinposLateral[0] = rtb_Switch;
  ControllerLateral_Y->LinposLateral[1] = rtb_Switch_m5;
  ControllerLateral_Y->LinposLateral[2] = rtb_Switch_g;
  ControllerLateral_Y->LinposLateral[3] = rtb_Switch_i;

  /* Product: '<S16>/Divide' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S16>/Constant1'
   */
  rtb_Switch1_e_idx_1 = ControllerLateral_InstP->Mass /
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
    /* Gain: '<S17>/Gain' */
    rtb_Gain_f_idx_0 = -rtb_Gain2;
    rtb_Gain_f_idx_1 = -rtb_Gain3;
  } else {
    /* Gain: '<S17>/Gain' incorporates:
     *  Delay: '<Root>/Delay1'
     */
    rtb_Gain_f_idx_0 = -ControllerLateral_DW->Delay1_DSTATE[0];
    rtb_Gain_f_idx_1 = -ControllerLateral_DW->Delay1_DSTATE[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/Constant1'
   *  Constant: '<S128>/Constant4'
   *  Sum: '<S128>/Subtract5'
   */
  if (rtb_Switch7 - -1.0 != 0.0) {
    rtb_Switch_n = 0.0;
  } else {
    rtb_Switch_n = rtb_Gain_f_idx_0;
  }

  /* End of Switch: '<S128>/Switch' */

  /* RelationalOperator: '<S8>/Equal' incorporates:
   *  Constant: '<S8>/Constant11'
   */
  ControllerLateral_B->Equal = (boolean_T)(2.0 == rtb_Switch7);

  /* DiscreteIntegrator: '<S164>/Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState <= 0)) || ((!(int32_T)
        ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState == 1))) {
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
  }

  /* SampleTimeMath: '<S159>/Tsamp' incorporates:
   *  Gain: '<S156>/Derivative Gain'
   *
   * About '<S159>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  ControllerLateral_B->Tsamp = 0.0 * rtb_Switch_n * 4000.0;

  /* Delay: '<S157>/UD' */
  if ((((int32_T)ControllerLateral_PrevZCX->UD_Reset_ZCE == 1) != (int32_T)
       ControllerLateral_B->Equal) && ((int32_T)
       ControllerLateral_PrevZCX->UD_Reset_ZCE != 3)) {
    ControllerLateral_DW->UD_DSTATE = 0.0;
  }

  ControllerLateral_PrevZCX->UD_Reset_ZCE = (ZCSigState)
    ControllerLateral_B->Equal;

  /* Sum: '<S173>/Sum' incorporates:
   *  Delay: '<S157>/UD'
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  Gain: '<S169>/Proportional Gain'
   *  Sum: '<S157>/Diff'
   */
  rtb_Sum = (0.0 * rtb_Switch_n + ControllerLateral_DW->Integrator_DSTATE) +
    (ControllerLateral_B->Tsamp - ControllerLateral_DW->UD_DSTATE);

  /* Sum: '<S17>/Add' incorporates:
   *  Constant: '<S17>/Setpoint'
   */
  rtb_Add = rtb_Sum + ControllerLateral_InstP->ReferenceLateralOffsets[0];

  /* DiscretePulseGenerator: '<S15>/Pulse Generator' */
  rtb_PulseGenerator = ((real_T)ControllerLateral_DW->clockTickCounter <
                        ControllerLateral_InstP->BeamErrorTime / 0.00025) &&
    (ControllerLateral_DW->clockTickCounter >= 0) ? 2 : 0;
  if ((real_T)ControllerLateral_DW->clockTickCounter >=
      ControllerLateral_InstP->BeamErrorTime * 2.0 / 0.00025 - 1.0) {
    ControllerLateral_DW->clockTickCounter = 0;
  } else {
    ControllerLateral_DW->clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S15>/Pulse Generator' */

  /* Product: '<S15>/Product1' incorporates:
   *  Constant: '<S15>/Constant6'
   *  Constant: '<S15>/Constant9'
   *  Sum: '<S15>/Subtract7'
   */
  ControllerLateral_B->Product1 = ((real_T)rtb_PulseGenerator - 1.0) *
    ControllerLateral_InstP->LateralBeamOffsets;

  /* Constant: '<S72>/Constant' */
  ControllerLateral_MovingAverage_p(ControllerLateral_B->Product1,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1, &ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_p,
     &ControllerLateral_DW->MovingAverage_p);

  /* Switch: '<S15>/Switch7' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  if (ControllerLateral_InstP->LateralBeamOffsetsBackDelay > 0.0) {
    /* Switch: '<S15>/Switch7' incorporates:
     *  Delay: '<S15>/Delay1'
     */
    rtb_Switch7_e = ControllerLateral_DW->Delay1_DSTATE_b[0];
  } else {
    /* Switch: '<S15>/Switch7' */
    rtb_Switch7_e = ControllerLateral_B->Product1;
  }

  /* End of Switch: '<S15>/Switch7' */

  /* Constant: '<S73>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Switch7_e,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_p,
    &ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_p.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pn,
     &ControllerLateral_DW->MovingAverage_pn);

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/Constant'
   */
  if (ControllerLateral_InstP->LateralSineSwitches[0] != 0.0) {
    /* Switch: '<S15>/Switch3' incorporates:
     *  Sin: '<S15>/Sine Wave1'
     */
    rtb_Switch3 = sin((real_T)ControllerLateral_DW->counter * 2.0 *
                      3.1415926535897931 / floor
                      (ControllerLateral_InstP->SineTime / 0.00025)) *
      ControllerLateral_InstP->LateralBeamOffsets;
  } else {
    /* Switch: '<S15>/Switch3' incorporates:
     *  Constant: '<S15>/Constant1'
     */
    rtb_Switch3 = 0.0;
  }

  /* End of Switch: '<S15>/Switch3' */

  /* Constant: '<S74>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Switch3,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pn,
    &ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pn.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pna,
     &ControllerLateral_DW->MovingAverage_pna);

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  if (ControllerLateral_InstP->LateralSineSwitches[1] != 0.0) {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Sin: '<S15>/Sine Wave2'
     */
    rtb_Switch1_c = sin((real_T)ControllerLateral_DW->counter_k * 2.0 *
                        3.1415926535897931 / floor
                        (ControllerLateral_InstP->SineTime / 0.00025)) *
      (ControllerLateral_InstP->LateralBeamOffsets *
       ControllerLateral_InstP->LateralBeamOffsetsFactor);
  } else {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/Constant3'
     */
    rtb_Switch1_c = 0.0;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Constant: '<S75>/Constant' */
  ControllerLateral_MovingAverage_p(rtb_Switch1_c,
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pna,
    &ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_p
    (ControllerLateral_B->MovingAverage1_pna.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnae,
     &ControllerLateral_DW->MovingAverage_pnae);

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S74>/Constant1'
   *  Sum: '<S15>/Subtract2'
   *  Switch: '<S74>/Switch'
   *  Switch: '<S75>/Switch'
   */
  if (rtb_Switch7 - 7.0 != 0.0) {
    /* Switch: '<S15>/Switch4' incorporates:
     *  Constant: '<S15>/Constant7'
     *  Constant: '<S72>/Constant1'
     *  Sum: '<S15>/Subtract6'
     *  Switch: '<S72>/Switch'
     *  Switch: '<S73>/Switch'
     */
    if (rtb_Switch7 - 5.0 != 0.0) {
      rtb_Switch2_idx_0 = 0.0;
      rtb_Switch2_idx_1 = 0.0;
    } else if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
      /* Switch: '<S72>/Switch' */
      rtb_Switch2_idx_0 = ControllerLateral_B->MovingAverage_p.MovingAverage;

      /* Switch: '<S73>/Switch' */
      rtb_Switch2_idx_1 = ControllerLateral_B->MovingAverage_pn.MovingAverage;
    } else {
      rtb_Switch2_idx_0 = ControllerLateral_B->MovingAverage1.MovingAverage;
      rtb_Switch2_idx_1 = ControllerLateral_B->MovingAverage1_p.MovingAverage;
    }

    /* End of Switch: '<S15>/Switch4' */
  } else if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    /* Switch: '<S74>/Switch' */
    rtb_Switch2_idx_0 = ControllerLateral_B->MovingAverage_pna.MovingAverage;

    /* Switch: '<S75>/Switch' */
    rtb_Switch2_idx_1 = ControllerLateral_B->MovingAverage_pnae.MovingAverage;
  } else {
    rtb_Switch2_idx_0 = ControllerLateral_B->MovingAverage1_pn.MovingAverage;
    rtb_Switch2_idx_1 = ControllerLateral_B->MovingAverage1_pna.MovingAverage;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* DigitalClock: '<Root>/Digital Clock' */
  rtb_DigitalClock_h = (((ControllerLateral_M->Timing.clockTick0+
    ControllerLateral_M->Timing.clockTickH0* 4294967296.0)) * 0.00025);

  /* MATLAB Function: '<Root>/Lane Switch Transition1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Lane Switch Mode'
   */
  /* MATLAB Function 'Lane Switch Transition1': '<S4>:1' */
  if (!(int32_T)ControllerLateral_DW->mode_old_not_empty) {
    /* '<S4>:1:5' */
    /* '<S4>:1:6' */
    ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;
    ControllerLateral_DW->mode_old_not_empty = true;
  }

  /* '<S4>:1:17' */
  rtb_mode_fore = ControllerLateral_InstP->LS_mode;

  /* '<S4>:1:18' */
  if (ControllerLateral_DW->mode_old != ControllerLateral_InstP->LS_mode) {
    /* '<S4>:1:22' */
    /* '<S4>:1:23' */
    ControllerLateral_DW->t_old = rtb_DigitalClock_h;

    /* '<S4>:1:24' */
    ControllerLateral_DW->mode_memory_old = ControllerLateral_DW->mode_old;
  }

  rtb_Gain_f_idx_0 = rtb_DigitalClock_h - ControllerLateral_DW->t_old;
  if ((0.0 <= rtb_Gain_f_idx_0) && (rtb_Gain_f_idx_0 <
       ControllerLateral_InstP->t_trans)) {
    /* '<S4>:1:29' */
    /* '<S4>:1:34' */
    /* '<S4>:1:35' */
    rtb_mode_fore = ControllerLateral_DW->mode_memory_old;

    /* '<S4>:1:36' */
  }

  /* '<S4>:1:41' */
  ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;

  /* Switch: '<S238>/Switch1' incorporates:
   *  Constant: '<S237>/Mode 1 AG5'
   *  Constant: '<S240>/Constant'
   *  Constant: '<S241>/Constant'
   *  RelationalOperator: '<S240>/Compare'
   *  RelationalOperator: '<S241>/Compare'
   *  Sum: '<S237>/Subtract2'
   *  Switch: '<S238>/Switch'
   */
  if (rtb_mode_fore == 2.0) {
    rtb_offset = rtb_Switch - ControllerLateral_InstP->LS_curved_AG;
  } else if (rtb_mode_fore == 1.0) {
    /* Switch: '<S238>/Switch' incorporates:
     *  Constant: '<S237>/Mode 1 AG'
     *  Sum: '<S237>/Subtract4'
     */
    rtb_offset = ControllerLateral_InstP->LS_straight_AG - rtb_Switch_m5;
  } else {
    /* Switch: '<S238>/Switch' incorporates:
     *  Gain: '<S237>/Gain'
     *  Sum: '<S237>/Subtract'
     */
    rtb_offset = (rtb_Switch - rtb_Switch_m5) * 0.5;
  }

  /* End of Switch: '<S238>/Switch1' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Sum: '<S16>/Sum1'
   */
  rtb_error_j = (rtb_Add + rtb_Switch2_idx_0) - rtb_offset;
  ControllerLateral_MovingAverage(rtb_error_j,
    &ControllerLateral_B->MovingAverage_pnaev,
    &ControllerLateral_DW->MovingAverage_pnaev);

  /* RelationalOperator: '<S16>/Equal' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  ControllerLateral_B->Equal_p = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S111>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S106>/Filter'
   */
  tmp = (boolean_T)!(int32_T)ControllerLateral_B->Equal_p;
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_o <= 0)) || (((int32_T)
        tmp) && ((int32_T)ControllerLateral_DW->Integrator_PrevResetState_o == 1)))
  {
    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S106>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState <= 0)) || (((int32_T)tmp) &&
       ((int32_T)ControllerLateral_DW->Filter_PrevResetState == 1))) {
    ControllerLateral_DW->Filter_DSTATE = 0.0;
  }

  /* Product: '<S114>/NProd Out' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/Constant3'
   *  Constant: '<S77>/N'
   *  DiscreteIntegrator: '<S106>/Filter'
   *  Product: '<S105>/DProd Out'
   *  Product: '<S77>/Divide'
   *  Sum: '<S106>/SumD'
   */
  ControllerLateral_B->NProdOut =
    (ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
     ControllerLateral_InstP->L_K_d - ControllerLateral_DW->Filter_DSTATE) *
    (6.2831853071795862 / ControllerLateral_InstP->L_T_c);

  /* Sum: '<S120>/Sum' incorporates:
   *  Constant: '<S77>/Constant1'
   *  DiscreteIntegrator: '<S111>/Integrator'
   *  Product: '<S116>/PProd Out'
   */
  rtb_Sum_k = (ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
               ControllerLateral_InstP->L_K_p +
               ControllerLateral_DW->Integrator_DSTATE_n) +
    ControllerLateral_B->NProdOut;

  /* Product: '<S16>/Divide1' incorporates:
   *  Product: '<S16>/Divide'
   */
  rtb_Divide1 = rtb_Switch1_e_idx_1 * rtb_Sum_k;

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/Constant1'
   *  Constant: '<S129>/Constant4'
   *  Sum: '<S129>/Subtract5'
   */
  if (rtb_Switch7 - -1.0 != 0.0) {
    rtb_Switch_i2 = 0.0;
  } else {
    rtb_Switch_i2 = rtb_Gain_f_idx_1;
  }

  /* End of Switch: '<S129>/Switch' */

  /* DiscreteIntegrator: '<S215>/Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_m <= 0)) || ((!(int32_T)
        ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_m == 1))) {
    ControllerLateral_DW->Integrator_DSTATE_o = 0.0;
  }

  /* SampleTimeMath: '<S210>/Tsamp' incorporates:
   *  Gain: '<S207>/Derivative Gain'
   *
   * About '<S210>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  ControllerLateral_B->Tsamp_c = 0.0 * rtb_Switch_i2 * 4000.0;

  /* Delay: '<S208>/UD' */
  if ((((int32_T)ControllerLateral_PrevZCX->UD_Reset_ZCE_d == 1) != (int32_T)
       ControllerLateral_B->Equal) && ((int32_T)
       ControllerLateral_PrevZCX->UD_Reset_ZCE_d != 3)) {
    ControllerLateral_DW->UD_DSTATE_o = 0.0;
  }

  ControllerLateral_PrevZCX->UD_Reset_ZCE_d = (ZCSigState)
    ControllerLateral_B->Equal;

  /* Sum: '<S224>/Sum' incorporates:
   *  Delay: '<S208>/UD'
   *  DiscreteIntegrator: '<S215>/Integrator'
   *  Gain: '<S220>/Proportional Gain'
   *  Sum: '<S208>/Diff'
   */
  rtb_Sum_p = (0.0 * rtb_Switch_i2 + ControllerLateral_DW->Integrator_DSTATE_o)
    + (ControllerLateral_B->Tsamp_c - ControllerLateral_DW->UD_DSTATE_o);

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S17>/Setpoint'
   */
  rtb_Add1 = rtb_Sum_p + ControllerLateral_InstP->ReferenceLateralOffsets[1];

  /* Switch: '<S239>/Switch1' incorporates:
   *  Constant: '<Root>/Lane Switch Mode'
   *  Constant: '<S237>/Mode 1 AG4'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S243>/Constant'
   *  MATLAB Function: '<Root>/Lane Switch Transition1'
   *  RelationalOperator: '<S242>/Compare'
   *  RelationalOperator: '<S243>/Compare'
   *  Sum: '<S237>/Subtract3'
   *  Switch: '<S239>/Switch'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_offset_i = rtb_Switch_g - ControllerLateral_InstP->LS_curved_AG;
  } else if (ControllerLateral_InstP->LS_mode == 1.0) {
    /* Switch: '<S239>/Switch' incorporates:
     *  Constant: '<S237>/Mode 1 AG6'
     *  Sum: '<S237>/Subtract5'
     */
    rtb_offset_i = ControllerLateral_InstP->LS_straight_AG - rtb_Switch_i;
  } else {
    /* Switch: '<S239>/Switch' incorporates:
     *  Gain: '<S237>/Gain1'
     *  Sum: '<S237>/Subtract1'
     */
    rtb_offset_i = (rtb_Switch_g - rtb_Switch_i) * 0.5;
  }

  /* End of Switch: '<S239>/Switch1' */

  /* Sum: '<S14>/Sum' incorporates:
   *  Sum: '<S14>/Sum1'
   */
  rtb_error_l = (rtb_Add1 + rtb_Switch2_idx_1) - rtb_offset_i;
  ControllerLateral_MovingAverage(rtb_error_l,
    &ControllerLateral_B->MovingAverage, &ControllerLateral_DW->MovingAverage);

  /* RelationalOperator: '<S14>/Equal' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  ControllerLateral_B->Equal_m = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S53>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S48>/Filter'
   */
  tmp = (boolean_T)!(int32_T)ControllerLateral_B->Equal_m;
  if ((((int32_T)ControllerLateral_B->Equal_m) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_k <= 0)) || (((int32_T)
        tmp) && ((int32_T)ControllerLateral_DW->Integrator_PrevResetState_k == 1)))
  {
    ControllerLateral_DW->Integrator_DSTATE_k = 0.0;
  }

  /* DiscreteIntegrator: '<S48>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_m) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState_g <= 0)) || (((int32_T)tmp) &&
       ((int32_T)ControllerLateral_DW->Filter_PrevResetState_g == 1))) {
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;
  }

  /* Product: '<S56>/NProd Out' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/N'
   *  DiscreteIntegrator: '<S48>/Filter'
   *  Product: '<S19>/Divide'
   *  Product: '<S47>/DProd Out'
   *  Sum: '<S48>/SumD'
   */
  ControllerLateral_B->NProdOut_k =
    (ControllerLateral_B->MovingAverage.MovingAverage *
     ControllerLateral_InstP->L_K_d - ControllerLateral_DW->Filter_DSTATE_d) *
    (6.2831853071795862 / ControllerLateral_InstP->L_T_c);

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S19>/Constant1'
   *  DiscreteIntegrator: '<S53>/Integrator'
   *  Product: '<S58>/PProd Out'
   */
  rtb_Sum_l = (ControllerLateral_B->MovingAverage.MovingAverage *
               ControllerLateral_InstP->L_K_p +
               ControllerLateral_DW->Integrator_DSTATE_k) +
    ControllerLateral_B->NProdOut_k;

  /* Product: '<S14>/Divide1' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  Product: '<S14>/Divide'
   */
  rtb_Divide1_o = ControllerLateral_InstP->Mass /
    ControllerLateral_InstP->ReferenceMass * rtb_Sum_l;

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S10>/Beta'
   *  Constant: '<S3>/1'
   *  Constant: '<S3>/2'
   *  Gain: '<S3>/Gain'
   *  Math: '<S3>/Square'
   *  Math: '<S3>/Square1'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Beta = 0.140625 * ControllerLateral_InstP->Mass /
    ((ControllerLateral_InstP->PodWidth * ControllerLateral_InstP->PodWidth +
      ControllerLateral_InstP->PodLength * ControllerLateral_InstP->PodLength) *
     (ControllerLateral_InstP->Mass / 12.0));

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S246>:1' */
  /* '<S246>:1:2' */
  /* '<S246>:1:3' */
  if (ControllerLateral_InstP->SemiCentralized > 0.0) {
    /* MATLAB Function: '<S10>/MATLAB Function' */
    rtb_Gain_f_idx_0 = rtb_Beta * rtb_Beta;
    rtb_Gain_f_idx_0 = ((rtb_Gain_f_idx_0 + 1.0) * rtb_Divide1 / rtb_Beta +
                        (rtb_Gain_f_idx_0 + -1.0) * rtb_Divide1_o / rtb_Beta) *
      0.25 + 0.5 * rtb_Divide1;
    rtb_Switch1_e_idx_1 = ((rtb_Beta * rtb_Beta + 1.0) * rtb_Divide1_o /
      rtb_Beta + (rtb_Beta * rtb_Beta + -1.0) * rtb_Divide1 / rtb_Beta) * 0.25 +
      0.5 * rtb_Divide1_o;
  } else {
    rtb_Gain_f_idx_0 = rtb_Divide1;
    rtb_Switch1_e_idx_1 = rtb_Divide1_o;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outport: '<Root>/Control SIgnals Lateral' */
  ControllerLateral_Y->ControlSIgnalsLateral[0] = rtb_Gain_f_idx_0;
  ControllerLateral_Y->ControlSIgnalsLateral[1] = rtb_Switch1_e_idx_1;

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain_a[i] = -ControllerLateral_InstP->LateralOffsetsHEMSMotor[i];
  }

  /* End of Gain: '<S9>/Gain' */

  /* Gain: '<S9>/Gain1' incorporates:
   *  Sum: '<S9>/Add8'
   */
  rtb_Gain1 = (rtb_offset + rtb_Gain_a[0]) * ControllerLateral_InstP->FrontGain;

  /* Gain: '<S9>/Gain2' incorporates:
   *  Sum: '<S9>/Add9'
   */
  rtb_Gain2_i = (rtb_offset_i + rtb_Gain_a[1]) *
    -ControllerLateral_InstP->BackGain;

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/hems1'
   *  Inport: '<Root>/hems2'
   *  Inport: '<Root>/motor1'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  Sum: '<S9>/Add2'
   *  Sum: '<S9>/Add3'
   *  Sum: '<S9>/Add6'
   */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S245>:1' */
  /* '<S245>:1:4' */
  /* '<S245>:1:5' */
  rtb_Add_i = rtb_Gain_f_idx_0 -
    (-ControllerLateral_InstP->lateral_over_vertical_force_motor *
     ControllerLateral_U->motor1 * (rtb_Gain1 + rtb_Gain_a[4]) - ((rtb_Gain1 +
       rtb_Gain_a[2]) * ControllerLateral_U->hems1 + (rtb_Gain1 + rtb_Gain_a[3])
      * ControllerLateral_U->hems2) *
     ControllerLateral_InstP->lateral_over_vertical_force_hems);

  /* Sum: '<S9>/Add1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/hems3'
   *  Inport: '<Root>/hems4'
   *  Inport: '<Root>/motor2'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  Sum: '<S9>/Add4'
   *  Sum: '<S9>/Add5'
   *  Sum: '<S9>/Add7'
   */
  rtb_Add1_f = rtb_Switch1_e_idx_1 -
    (-ControllerLateral_InstP->lateral_over_vertical_force_motor *
     ControllerLateral_U->motor2 * (rtb_Gain2_i + rtb_Gain_a[4]) - ((rtb_Gain2_i
       + rtb_Gain_a[2]) * ControllerLateral_U->hems3 + (rtb_Gain2_i +
       rtb_Gain_a[3]) * ControllerLateral_U->hems4) *
     ControllerLateral_InstP->lateral_over_vertical_force_hems);

  /* Outport: '<Root>/Control Signals Lateral Final' */
  ControllerLateral_Y->ControlSignalsLateralFinal[0] = rtb_Add_i;
  ControllerLateral_Y->ControlSignalsLateralFinal[1] = rtb_Add1_f;

  /* Outport: '<Root>/OffsetFront' */
  ControllerLateral_Y->OffsetFront = rtb_offset;

  /* Outport: '<Root>/OffsetBack' */
  ControllerLateral_Y->OffsetBack = rtb_offset_i;

  /* Signum: '<S13>/Sign' */
  if (rtb_Add_i < 0.0) {
    rtb_Sign = -1.0;
  } else if (rtb_Add_i > 0.0) {
    rtb_Sign = 1.0;
  } else if (rtb_Add_i == 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = (rtNaN);
  }

  /* End of Signum: '<S13>/Sign' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Saturate: '<S1>/Saturation1'
   */
  if (rtb_Sign > 0.0) {
    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Switch_m5 > 25.0) {
      rtb_Switch_p = 25.0;
    } else if (rtb_Switch_m5 < 2.0) {
      rtb_Switch_p = 2.0;
    } else {
      rtb_Switch_p = rtb_Switch_m5;
    }
  } else if (rtb_Switch > 25.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_p = 25.0;
  } else if (rtb_Switch < 2.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_p = 2.0;
  } else {
    rtb_Switch_p = rtb_Switch;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Constant: '<S13>/Constant7'
   *  Sum: '<S13>/Subtract4'
   */
  if (rtb_Switch7 - 2.0 != 0.0) {
    /* Lookup_n-D: '<S13>/2-D Lookup Table2' incorporates:
     *  Constant: '<S13>/Constant'
     *  Switch: '<S13>/Switch'
     */
    bpIndices[1U] = plook_binxp(rtb_Switch_p, ControllerLateral_ConstP.pooled6,
      100U, &rtb_Gain_f_idx_0, &ControllerLateral_DW->m_Cache02);
    fractions[1U] = rtb_Gain_f_idx_0;
    for (i = 0; i < 9; i++) {
      bpIndices[0U] = plook_binxp(ControllerLateral_ConstP.pooled4[i],
        ControllerLateral_ConstP.pooled4, 8U, &rtb_Gain_f_idx_0,
        &ControllerLateral_DW->m_Cache01[i]);
      fractions[0U] = rtb_Gain_f_idx_0;
      rtb_uDLookupTable2[i] = intrp2d_l_pw(bpIndices, fractions,
        ControllerLateral_ConstP.pooled5, 9U);
    }

    /* End of Lookup_n-D: '<S13>/2-D Lookup Table2' */

    /* Lookup_n-D: '<S13>/2-D Lookup Table1' incorporates:
     *  Abs: '<S13>/Abs'
     *  Gain: '<S13>/Gain'
     */
    rtb_uDLookupTable1 = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
      (rtb_Add_i), rtb_uDLookupTable2, ControllerLateral_ConstP.pooled4,
      &ControllerLateral_DW->m_bpIndex_e, 8U);

    /* Saturate: '<S13>/Saturation2' */
    if (rtb_uDLookupTable1 > 5.6) {
      rtb_Switch2_i = 5.6;
    } else if (rtb_uDLookupTable1 < -5.6) {
      rtb_Switch2_i = -5.6;
    } else {
      rtb_Switch2_i = rtb_uDLookupTable1;
    }

    /* End of Saturate: '<S13>/Saturation2' */
  } else {
    rtb_Switch2_i = 0.0;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Product: '<S13>/Product'
   */
  ControllerLateral_B->sf_MATLABFunction.current = rtb_Sign * rtb_Switch2_i;
  ControllerLateral_MATLABFunction(rtb_mode_fore,
    &ControllerLateral_B->sf_MATLABFunction);

  /* Outport: '<Root>/I_Demand_Front' incorporates:
   *  Gain: '<Root>/Gain'
   */
  ControllerLateral_Y->I_Demand_Front = ControllerLateral_InstP->PolarityFront *
    ControllerLateral_B->sf_MATLABFunction.current;

  /* Signum: '<S12>/Sign' */
  if (rtb_Add1_f < 0.0) {
    rtb_Sign_l = -1.0;
  } else if (rtb_Add1_f > 0.0) {
    rtb_Sign_l = 1.0;
  } else if (rtb_Add1_f == 0.0) {
    rtb_Sign_l = 0.0;
  } else {
    rtb_Sign_l = (rtNaN);
  }

  /* End of Signum: '<S12>/Sign' */

  /* Switch: '<S12>/Switch' incorporates:
   *  Saturate: '<S1>/Saturation1'
   */
  if (rtb_Sign_l > 0.0) {
    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Switch_i > 25.0) {
      rtb_Switch_gp = 25.0;
    } else if (rtb_Switch_i < 2.0) {
      rtb_Switch_gp = 2.0;
    } else {
      rtb_Switch_gp = rtb_Switch_i;
    }
  } else if (rtb_Switch_g > 25.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_gp = 25.0;
  } else if (rtb_Switch_g < 2.0) {
    /* Saturate: '<S1>/Saturation1' */
    rtb_Switch_gp = 2.0;
  } else {
    rtb_Switch_gp = rtb_Switch_g;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S12>/Constant6'
   *  Constant: '<S12>/Constant7'
   *  Sum: '<S12>/Subtract4'
   */
  if (rtb_Switch7 - 2.0 != 0.0) {
    /* Lookup_n-D: '<S12>/2-D Lookup Table2' incorporates:
     *  Constant: '<S12>/Constant'
     *  Switch: '<S12>/Switch'
     */
    bpIndices_0[1U] = plook_binxp(rtb_Switch_gp,
      ControllerLateral_ConstP.pooled6, 100U, &rtb_Gain_f_idx_0,
      &ControllerLateral_DW->m_Cache02_g);
    fractions_0[1U] = rtb_Gain_f_idx_0;
    for (i = 0; i < 9; i++) {
      bpIndices_0[0U] = plook_binxp(ControllerLateral_ConstP.pooled4[i],
        ControllerLateral_ConstP.pooled4, 8U, &rtb_Gain_f_idx_0,
        &ControllerLateral_DW->m_Cache01_d[i]);
      fractions_0[0U] = rtb_Gain_f_idx_0;
      rtb_uDLookupTable2_p[i] = intrp2d_l_pw(bpIndices_0, fractions_0,
        ControllerLateral_ConstP.pooled5, 9U);
    }

    /* End of Lookup_n-D: '<S12>/2-D Lookup Table2' */

    /* Lookup_n-D: '<S12>/2-D Lookup Table1' incorporates:
     *  Abs: '<S12>/Abs'
     *  Gain: '<S12>/Gain'
     */
    rtb_uDLookupTable1_n = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
      (rtb_Add1_f), rtb_uDLookupTable2_p, ControllerLateral_ConstP.pooled4,
      &ControllerLateral_DW->m_bpIndex_p, 8U);

    /* Saturate: '<S12>/Saturation2' */
    if (rtb_uDLookupTable1_n > 5.6) {
      rtb_Switch2_no = 5.6;
    } else if (rtb_uDLookupTable1_n < -5.6) {
      rtb_Switch2_no = -5.6;
    } else {
      rtb_Switch2_no = rtb_uDLookupTable1_n;
    }

    /* End of Saturate: '<S12>/Saturation2' */
  } else {
    rtb_Switch2_no = 0.0;
  }

  /* End of Switch: '<S12>/Switch2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Lane Switch Mode'
   *  MATLAB Function: '<Root>/Lane Switch Transition1'
   *  Product: '<S12>/Product'
   */
  ControllerLateral_B->sf_MATLABFunction1.current = rtb_Sign_l * rtb_Switch2_no;
  ControllerLateral_MATLABFunction(ControllerLateral_InstP->LS_mode,
    &ControllerLateral_B->sf_MATLABFunction1);

  /* Outport: '<Root>/I_Demand_Back' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  ControllerLateral_Y->I_Demand_Back = ControllerLateral_InstP->PolarityBack *
    ControllerLateral_B->sf_MATLABFunction1.current;

  /* Outport: '<Root>/Power_Lat' incorporates:
   *  Abs: '<S11>/Abs'
   *  Abs: '<S11>/Abs1'
   *  Inport: '<Root>/VrB'
   *  Inport: '<Root>/VrF'
   *  Inport: '<Root>/VtB'
   *  Inport: '<Root>/VtF'
   *  Product: '<S11>/Product'
   *  Sum: '<Root>/Subtract2'
   *  Sum: '<S11>/Sum'
   */
  ControllerLateral_Y->Power_Lat = fabs(ControllerLateral_U->VtF -
    ControllerLateral_U->VrF) * fabs(rtb_Gain2) + fabs(ControllerLateral_U->VtB
    - ControllerLateral_U->VrB) * fabs(rtb_Gain3);

  /* MATLABSystem: '<S11>/Moving Average' */
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
   *  MATLABSystem: '<S11>/Moving Average'
   *  Outport: '<Root>/Power_Lat'
   */
  ControllerLateral_Y->Power_Lat_avg =
    ControllerLateral_SlidingWindowAverageCG_stepImpl(obj,
    ControllerLateral_Y->Power_Lat);

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if ((((int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState <= 0)) || ((
        !(int32_T)ControllerLateral_B->Equal) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
  }

  /* Outport: '<Root>/Energy_Lat' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   */
  ControllerLateral_Y->Energy_Lat =
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f;

  /* Outport: '<Root>/EMS_F_Front' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Lookup_n-D: '<S13>/2-D Lookup Table3'
   *  Switch: '<S13>/Switch'
   */
  ControllerLateral_Y->EMS_F_Front = look2_pbinlxpw(rtb_Gain2, rtb_Switch_p,
    ControllerLateral_ConstP.pooled4, ControllerLateral_ConstP.pooled6,
    ControllerLateral_ConstP.pooled5, ControllerLateral_DW->m_bpIndex,
    ControllerLateral_ConstP.pooled19, 9U);

  /* Outport: '<Root>/EMS_F_Back' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Lookup_n-D: '<S12>/2-D Lookup Table3'
   *  Switch: '<S12>/Switch'
   */
  ControllerLateral_Y->EMS_F_Back = look2_pbinlxpw(rtb_Gain3, rtb_Switch_gp,
    ControllerLateral_ConstP.pooled4, ControllerLateral_ConstP.pooled6,
    ControllerLateral_ConstP.pooled5, ControllerLateral_DW->m_bpIndex_b,
    ControllerLateral_ConstP.pooled19, 9U);

  /* Product: '<S50>/IProd Out' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  rtb_IProdOut = ControllerLateral_B->MovingAverage.MovingAverage *
    ControllerLateral_InstP->L_K_i;

  /* Signum: '<S44>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0) {
    rtb_Gain_f_idx_0 = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    rtb_Gain_f_idx_0 = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S44>/SignPreIntegrator' */

  /* DataTypeConversion: '<S44>/DataTypeConv2' */
  rtb_Switch1_e_idx_1 = fabs(rtb_Gain_f_idx_0);
  if (rtb_Switch1_e_idx_1 < 4.503599627370496E+15) {
    if (rtb_Switch1_e_idx_1 >= 0.5) {
      rtb_Gain_f_idx_0 = floor(rtb_Gain_f_idx_0 + 0.5);
    } else {
      rtb_Gain_f_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Gain_f_idx_0)) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = fmod(rtb_Gain_f_idx_0, 256.0);
  }

  /* DeadZone: '<S46>/DeadZone' */
  if (rtb_Sum_l >= (rtMinusInf)) {
    rtb_Switch1_e_idx_1 = 0.0;
  } else {
    rtb_Switch1_e_idx_1 = (rtNaN);
  }

  /* End of DeadZone: '<S46>/DeadZone' */

  /* Switch: '<S44>/Switch' incorporates:
   *  DataTypeConversion: '<S44>/DataTypeConv1'
   *  DataTypeConversion: '<S44>/DataTypeConv2'
   *  Gain: '<S44>/ZeroGain'
   *  Logic: '<S44>/AND3'
   *  RelationalOperator: '<S44>/Equal1'
   *  RelationalOperator: '<S44>/NotEqual'
   */
  if ((0.0 * rtb_Sum_l != rtb_Switch1_e_idx_1) && ((rtb_Gain_f_idx_0 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)-rtb_Gain_f_idx_0 : (int32_T)
        (int8_T)(uint8_T)rtb_Gain_f_idx_0) == 0)) {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Constant1'
     */
    ControllerLateral_B->Switch = 0.0;
  } else {
    /* Switch: '<S44>/Switch' */
    ControllerLateral_B->Switch = rtb_IProdOut;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Product: '<S108>/IProd Out' incorporates:
   *  Constant: '<S77>/Constant2'
   */
  rtb_IProdOut_p = ControllerLateral_B->MovingAverage_pnaev.MovingAverage *
    ControllerLateral_InstP->L_K_i;

  /* Signum: '<S102>/SignPreIntegrator' */
  if (rtb_IProdOut_p < 0.0) {
    rtb_Gain_f_idx_0 = -1.0;
  } else if (rtb_IProdOut_p > 0.0) {
    rtb_Gain_f_idx_0 = 1.0;
  } else if (rtb_IProdOut_p == 0.0) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S102>/SignPreIntegrator' */

  /* DataTypeConversion: '<S102>/DataTypeConv2' */
  rtb_Switch1_e_idx_1 = fabs(rtb_Gain_f_idx_0);
  if (rtb_Switch1_e_idx_1 < 4.503599627370496E+15) {
    if (rtb_Switch1_e_idx_1 >= 0.5) {
      rtb_Gain_f_idx_0 = floor(rtb_Gain_f_idx_0 + 0.5);
    } else {
      rtb_Gain_f_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Gain_f_idx_0)) {
    rtb_Gain_f_idx_0 = 0.0;
  } else {
    rtb_Gain_f_idx_0 = fmod(rtb_Gain_f_idx_0, 256.0);
  }

  /* DeadZone: '<S104>/DeadZone' */
  if (rtb_Sum_k >= (rtMinusInf)) {
    rtb_Switch1_e_idx_1 = 0.0;
  } else {
    rtb_Switch1_e_idx_1 = (rtNaN);
  }

  /* End of DeadZone: '<S104>/DeadZone' */

  /* Switch: '<S102>/Switch' incorporates:
   *  DataTypeConversion: '<S102>/DataTypeConv1'
   *  DataTypeConversion: '<S102>/DataTypeConv2'
   *  Gain: '<S102>/ZeroGain'
   *  Logic: '<S102>/AND3'
   *  RelationalOperator: '<S102>/Equal1'
   *  RelationalOperator: '<S102>/NotEqual'
   */
  if ((0.0 * rtb_Sum_k != rtb_Switch1_e_idx_1) && ((rtb_Gain_f_idx_0 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)-rtb_Gain_f_idx_0 : (int32_T)
        (int8_T)(uint8_T)rtb_Gain_f_idx_0) == 0)) {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S102>/Constant1'
     */
    ControllerLateral_B->Switch_l = 0.0;
  } else {
    /* Switch: '<S102>/Switch' */
    ControllerLateral_B->Switch_l = rtb_IProdOut_p;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Sum: '<S155>/SumI4' incorporates:
   *  Gain: '<S155>/Kb'
   *  Gain: '<S161>/Integral Gain'
   *  Sum: '<S155>/SumI2'
   */
  ControllerLateral_B->SumI4 = (rtb_Sum - rtb_Sum) * 0.01 +
    ControllerLateral_InstP->CurrentIntegralLat * rtb_Switch_n;

  /* Sum: '<S206>/SumI4' incorporates:
   *  Gain: '<S206>/Kb'
   *  Gain: '<S212>/Integral Gain'
   *  Sum: '<S206>/SumI2'
   */
  ControllerLateral_B->SumI4_e = (rtb_Sum_p - rtb_Sum_p) * 0.01 +
    ControllerLateral_InstP->CurrentIntegralLat * rtb_Switch_i2;

  /* SignalConversion generated from: '<Root>/Delay1' */
  ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0] =
    ControllerLateral_B->sf_MATLABFunction.current;
  ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1] =
    ControllerLateral_B->sf_MATLABFunction1.current;

  /* Outport: '<Root>/Filtered_Gaps Lateral' */
  ControllerLateral_Y->Filtered_GapsLateral[0] = rtb_Switch;
  ControllerLateral_Y->Filtered_GapsLateral[1] = rtb_Switch_m5;
  ControllerLateral_Y->Filtered_GapsLateral[2] = rtb_Switch_g;
  ControllerLateral_Y->Filtered_GapsLateral[3] = rtb_Switch_i;

  /* Outport: '<Root>/RefOutFront' */
  ControllerLateral_Y->RefOutFront = rtb_Add;

  /* Outport: '<Root>/RefOutBack' */
  ControllerLateral_Y->RefOutBack = rtb_Add1;

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/Constant4'
   *  Sum: '<S8>/Subtract1'
   */
  ControllerLateral_B->Switch3 = (real_T)!(rtb_Switch1 - 3.0 != 0.0);
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

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE += 0.00025 *
    ControllerLateral_B->Switch3;

  /* Update for Memory: '<S8>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput = ControllerLateral_B->OR;

  /* Update for Delay: '<Root>/Delay1' */
  ControllerLateral_DW->Delay1_DSTATE[0] =
    ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0];
  ControllerLateral_DW->Delay1_DSTATE[1] =
    ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1];

  /* Update for DiscreteIntegrator: '<S164>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE += 0.00025 *
    ControllerLateral_B->SumI4;
  ControllerLateral_DW->Integrator_PrevResetState = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for Delay: '<S157>/UD' */
  ControllerLateral_DW->UD_DSTATE = ControllerLateral_B->Tsamp;

  /* Update for Delay: '<S15>/Delay1' */
  for (idxDelay = 0; idxDelay < 399; idxDelay++) {
    ControllerLateral_DW->Delay1_DSTATE_b[idxDelay] =
      ControllerLateral_DW->Delay1_DSTATE_b[idxDelay + 1];
  }

  ControllerLateral_DW->Delay1_DSTATE_b[399] = ControllerLateral_B->Product1;

  /* End of Update for Delay: '<S15>/Delay1' */

  /* Update for Sin: '<S15>/Sine Wave1' incorporates:
   *  Sin: '<S15>/Sine Wave2'
   */
  ControllerLateral_DW->counter++;
  tmp = floor(ControllerLateral_InstP->SineTime / 0.00025);
  if ((real_T)ControllerLateral_DW->counter == tmp) {
    ControllerLateral_DW->counter = 0;
  }

  /* End of Update for Sin: '<S15>/Sine Wave1' */

  /* Update for Sin: '<S15>/Sine Wave2' */
  ControllerLateral_DW->counter_k++;
  if ((real_T)ControllerLateral_DW->counter_k == tmp) {
    ControllerLateral_DW->counter_k = 0;
  }

  /* Update for DiscreteIntegrator: '<S111>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_n += 0.00025 *
    ControllerLateral_B->Switch_l;
  ControllerLateral_DW->Integrator_PrevResetState_o = (int8_T)
    ControllerLateral_B->Equal_p;

  /* Update for DiscreteIntegrator: '<S106>/Filter' incorporates:
   *  DiscreteIntegrator: '<S111>/Integrator'
   */
  ControllerLateral_DW->Filter_DSTATE += 0.00025 * ControllerLateral_B->NProdOut;
  ControllerLateral_DW->Filter_PrevResetState = (int8_T)
    ControllerLateral_B->Equal_p;

  /* Update for DiscreteIntegrator: '<S215>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S164>/Integrator'
   */
  ControllerLateral_DW->Integrator_DSTATE_o += 0.00025 *
    ControllerLateral_B->SumI4_e;
  ControllerLateral_DW->Integrator_PrevResetState_m = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for Delay: '<S208>/UD' */
  ControllerLateral_DW->UD_DSTATE_o = ControllerLateral_B->Tsamp_c;

  /* Update for DiscreteIntegrator: '<S53>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_k += 0.00025 *
    ControllerLateral_B->Switch;
  ControllerLateral_DW->Integrator_PrevResetState_k = (int8_T)
    ControllerLateral_B->Equal_m;

  /* Update for DiscreteIntegrator: '<S48>/Filter' incorporates:
   *  DiscreteIntegrator: '<S53>/Integrator'
   */
  ControllerLateral_DW->Filter_DSTATE_d += 0.00025 *
    ControllerLateral_B->NProdOut_k;
  ControllerLateral_DW->Filter_PrevResetState_g = (int8_T)
    ControllerLateral_B->Equal_m;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  Outport: '<Root>/Power_Lat'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f += 0.00025 *
    ControllerLateral_Y->Power_Lat;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    ControllerLateral_B->Equal;

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

  /* Constant: '<S233>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pnae);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnaevv);

  /* Constant: '<S234>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pnaev);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvf);

  /* Constant: '<S235>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfp);

  /* Constant: '<S236>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnaevvfpg);

  /* Constant: '<S72>/Constant' */
  ControllerLateral_MovingAverage_n_Start(&ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_n_Start(&ControllerLateral_DW->MovingAverage_p);

  /* Constant: '<S73>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pn);

  /* Constant: '<S74>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pna);

  /* Constant: '<S75>/Constant' */
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_n_Start
    (&ControllerLateral_DW->MovingAverage_pnae);
  ControllerLateral_MovingAverage_Start
    (&ControllerLateral_DW->MovingAverage_pnaev);
  ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage);

  /* Start for MATLABSystem: '<S11>/Moving Average' */
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

  {
    c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE = 0.0;

    /* InitializeConditions for Memory: '<S8>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput = false;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    ControllerLateral_DW->Delay1_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[1] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S164>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState = (int8_T)2;

    /* InitializeConditions for Delay: '<S157>/UD' */
    ControllerLateral_DW->UD_DSTATE = 0.0;

    /* InitializeConditions for DiscretePulseGenerator: '<S15>/Pulse Generator' */
    ControllerLateral_DW->clockTickCounter = 0;

    /* InitializeConditions for Delay: '<S15>/Delay1' */
    for (i = 0; i < 400; i++) {
      ControllerLateral_DW->Delay1_DSTATE_b[i] = 0.0;
    }

    /* End of InitializeConditions for Delay: '<S15>/Delay1' */

    /* InitializeConditions for Sin: '<S15>/Sine Wave1' */
    ControllerLateral_DW->counter = 0;

    /* InitializeConditions for Sin: '<S15>/Sine Wave2' */
    ControllerLateral_DW->counter_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S111>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_o = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Filter' */
    ControllerLateral_DW->Filter_DSTATE = 0.0;
    ControllerLateral_DW->Filter_PrevResetState = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S215>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_o = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_m = (int8_T)2;

    /* InitializeConditions for Delay: '<S208>/UD' */
    ControllerLateral_DW->UD_DSTATE_o = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_k = 0.0;
    ControllerLateral_DW->Integrator_PrevResetState_k = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S48>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;
    ControllerLateral_DW->Filter_PrevResetState_g = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)2;

    /* SystemInitialize for MATLAB Function: '<Root>/Lane Switch Transition1' */
    ControllerLateral_DW->mode_old_not_empty = false;
    ControllerLateral_DW->t_old = -1000.0;
    ControllerLateral_DW->mode_memory_old = -1.0;
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pnae);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnaevv);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pnaev);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvf);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevv);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfp);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvf);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
    ControllerLateral_MovingAverage_p_Init(&ControllerLateral_DW->MovingAverage1);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_p);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_p);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pn);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pn);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pna);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage1_pna);
    ControllerLateral_MovingAverage_p_Init
      (&ControllerLateral_DW->MovingAverage_pnae);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaev);
    ControllerLateral_MovingAverage_Init(&ControllerLateral_DW->MovingAverage);

    /* InitializeConditions for MATLABSystem: '<S11>/Moving Average' */
    obj = ControllerLateral_DW->obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0;
      for (i = 0; i < 1999; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S11>/Moving Average' */
  }
}

/* Model terminate function */
void ControllerLateral_terminate(RT_MODEL_ControllerLateral_T
  * ControllerLateral_M)
{
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pnae);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnaevv);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pnaev);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvf);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfp);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
  ControllerLateral_MovingAverage_d_Term(&ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_d_Term(&ControllerLateral_DW->MovingAverage_p);
  ControllerLateral_MovingAverage_d_Term(&ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_d_Term(&ControllerLateral_DW->MovingAverage_pn);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pna);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_d_Term
    (&ControllerLateral_DW->MovingAverage_pnae);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaev);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage);

  /* Terminate for MATLABSystem: '<S11>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S11>/Moving Average' */

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
      ControllerLateral_B->Switch = 0.0;
      ControllerLateral_B->Switch_l = 0.0;
      ControllerLateral_B->SumI4 = 0.0;
      ControllerLateral_B->SumI4_e = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1] = 0.0;
      ControllerLateral_B->Switch3 = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaev.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnae.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevv.MovingAverage = 0.0;
      ControllerLateral_B->sf_MATLABFunction1.current = 0.0;
      ControllerLateral_B->sf_MATLABFunction.current = 0.0;
      ControllerLateral_B->MovingAverage_pnaev.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pna.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnae.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pn.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pna.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_p.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pn.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_p.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage.MovingAverage = 0.0;
    }

    /* states (dwork) */
    (void) memset((void *)ControllerLateral_DW, 0,
                  sizeof(DW_ControllerLateral_T));
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[1] = 0.0;
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
    ControllerLateral_DW->Integrator_DSTATE_k = 0.0;
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_f = 0.0;
    ControllerLateral_DW->mode_old = 0.0;
    ControllerLateral_DW->t_old = 0.0;
    ControllerLateral_DW->mode_memory_old = 0.0;

    /* external inputs */
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

    /* previous zero-crossing states */
    {
      ControllerLateral_PrevZCX->UD_Reset_ZCE = UNINITIALIZED_ZCSIG;
      ControllerLateral_PrevZCX->UD_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    }
  }

  return ControllerLateral_M;
}
