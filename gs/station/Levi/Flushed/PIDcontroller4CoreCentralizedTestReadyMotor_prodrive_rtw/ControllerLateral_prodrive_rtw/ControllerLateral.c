/*
 * ControllerLateral.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControllerLateral".
 *
 * Model version              : 6.282
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Jul 17 17:29:12 2024
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
static real_T ControllerLateral_xnrm2(int32_T n, const real_T x[10], int32_T ix0);
static void ControllerLateral_xgemv(int32_T m, int32_T n, const real_T A[10],
  int32_T ia0, const real_T x[10], int32_T ix0, real_T y[2]);
static void ControllerLateral_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T
  ix0, const real_T y[2], real_T A[10], int32_T ia0);
static void ControllerLateral_qrFactor(const real_T A[6], const real_T S[9],
  const real_T Ns[4], real_T b_S[4]);
static void ControllerLateral_trisolve(const real_T A[4], real_T B[6]);
static void ControllerLateral_linsolve(const real_T A[4], const real_T B[6],
  real_T C[6]);
static void ControllerLateral_trisolve_o(const real_T A[4], real_T B[6]);
static void ControllerLateral_linsolve_o(const real_T A[4], const real_T B[6],
  real_T C[6]);
static void ControllerLateral_mtimes(const real_T A[9], const real_T B[9],
  real_T C[9]);
static real_T ControllerLateral_xnrm2_k(int32_T n, const real_T x[15], int32_T
  ix0);
static void ControllerLateral_xgemv_g(int32_T m, int32_T n, const real_T A[15],
  int32_T ia0, const real_T x[15], int32_T ix0, real_T y[3]);
static void ControllerLateral_xgerc_p(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[15], int32_T ia0);
static void ControllerLateral_qrFactor_k(const real_T A[9], real_T S[9], const
  real_T Ns[6]);
static real_T ControllerLateral_xnrm2_ks(int32_T n, const real_T x[18], int32_T
  ix0);
static void ControllerLateral_xgemv_gq(int32_T m, int32_T n, const real_T A[18],
  int32_T ia0, const real_T x[18], int32_T ix0, real_T y[3]);
static void ControllerLateral_xgerc_ph(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[18], int32_T ia0);
static void ControllerLateral_qrFactor_k0(const real_T A[9], real_T S[9], const
  real_T Ns[9]);
static real_T ControllerLateral_xnrm2_ksh(int32_T n, const real_T x[9], int32_T
  ix0);
static void ControllerLateral_xscal(int32_T n, real_T a, real_T x[9], int32_T
  ix0);
static real_T ControllerLateral_xnrm2_ksh2(const real_T x[3], int32_T ix0);
static real_T ControllerLateral_xdotc(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0);
static void ControllerLateral_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0);
static void ControllerLateral_xscal_e(real_T a, real_T x[3], int32_T ix0);
static void ControllerLateral_xaxpy_m(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ControllerLateral_xaxpy_m0(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0);
static void ControllerLateral_xscal_e5(real_T a, real_T x[9], int32_T ix0);
static void ControllerLateral_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ControllerLateral_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T
  c, real_T s);
static void ControllerLateral_xswap(real_T x[9], int32_T ix0, int32_T iy0);
static void ControllerLateral_svd(const real_T A[9], real_T U[9], real_T s[3],
  real_T V[9]);
static void ControllerLateral_xgemv_gq4(int32_T m, int32_T n, const real_T A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3]);
static void ControllerLateral_xgerc_pho(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[9], int32_T ia0);
static void ControllerLateral_qr(const real_T A[9], real_T Q[9], real_T R[9]);
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

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xnrm2(int32_T n, const real_T x[10], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!(int32_T)rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgemv(int32_T m, int32_T n, const real_T A[10],
  int32_T ia0, const real_T x[10], int32_T ix0, real_T y[2])
{
  real_T c;
  int32_T b;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  int32_T iy;
  if (n != 0) {
    y[0] = 0.0;
    iy = 0;
    for (iac = ia0; iac <= ia0; iac += 5) {
      ix = ix0;
      c = 0.0;
      b = (iac + m) - 1;
      for (ia = iac; ia <= b; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T
  ix0, const real_T y[2], real_T A[10], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 5;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_qrFactor(const real_T A[6], const real_T S[9],
  const real_T Ns[4], real_T b_S[4])
{
  real_T b_A[10];
  real_T y[6];
  real_T R[4];
  real_T work[2];
  real_T beta1;
  real_T s;
  real_T tau_idx_0;
  int32_T aoffset;
  int32_T coffset;
  int32_T exitg1;
  int32_T j;
  int32_T knt;
  for (j = 0; j < 2; j++) {
    coffset = j * 3;
    for (knt = 0; knt < 3; knt++) {
      aoffset = knt * 3;
      y[coffset + knt] = (S[aoffset + 1] * A[j + 2] + S[aoffset] * A[j]) +
        S[aoffset + 2] * A[j + 4];
    }
  }

  for (knt = 0; knt < 2; knt++) {
    b_A[5 * knt] = y[3 * knt];
    b_A[5 * knt + 1] = y[3 * knt + 1];
    b_A[5 * knt + 2] = y[3 * knt + 2];
    b_A[5 * knt + 3] = Ns[knt];
    b_A[5 * knt + 4] = Ns[knt + 2];
    work[knt] = 0.0;
  }

  s = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = ControllerLateral_xnrm2(4, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        aoffset = 0;
        for (j = 1; j < 5; j++) {
          b_A[j] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(s, ControllerLateral_xnrm2(4, b_A, 2));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (j = 1; j < 5; j++) {
        b_A[j] *= s;
      }

      while (aoffset <= knt - 1) {
        beta1 *= 1.0020841800044864E-292;
        aoffset++;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      s = 1.0 / (b_A[0] - beta1);
      for (aoffset = 1; aoffset < 5; aoffset++) {
        b_A[aoffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 5;
    aoffset = 4;
    while ((knt > 0) && (b_A[aoffset] == 0.0)) {
      knt--;
      aoffset--;
    }

    aoffset = 1;
    j = 5;
    do {
      exitg1 = 0;
      if (j + 1 <= knt + 5) {
        if (b_A[j] != 0.0) {
          exitg1 = 1;
        } else {
          j++;
        }
      } else {
        aoffset = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    aoffset = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv(knt, aoffset, b_A, 6, b_A, 1, work);
    ControllerLateral_xgerc(knt, aoffset, -tau_idx_0, 1, work, b_A, 6);
  }

  b_A[0] = s;
  s = b_A[6];
  beta1 = ControllerLateral_xnrm2(3, b_A, 8);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[6], beta1);
    if (b_A[6] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (j = 7; j < 10; j++) {
          b_A[j] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(s, ControllerLateral_xnrm2(3, b_A, 8));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      s = 1.0 / (s - beta1);
      for (j = 7; j < 10; j++) {
        b_A[j] *= s;
      }

      for (aoffset = 0; aoffset < knt; aoffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      s = 1.0 / (b_A[6] - beta1);
      for (aoffset = 7; aoffset < 10; aoffset++) {
        b_A[aoffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[6] = s;
  R[0] = b_A[0];
  for (coffset = 0; coffset < 2; coffset++) {
    R[coffset + 2] = b_A[coffset + 5];
  }

  b_S[0] = R[0];
  b_S[1] = R[2];
  b_S[2] = 0.0;
  b_S[3] = R[3];
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_trisolve(const real_T A[4], real_T B[6])
{
  int32_T j;
  int32_T jBcol;
  for (j = 0; j < 3; j++) {
    jBcol = j << 1;
    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
      B[jBcol + 1] -= B[jBcol] * A[1];
    }

    if (B[jBcol + 1] != 0.0) {
      B[jBcol + 1] /= A[3];
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_linsolve(const real_T A[4], const real_T B[6],
  real_T C[6])
{
  int32_T C_tmp;
  int32_T j;
  for (j = 0; j < 3; j++) {
    C_tmp = j << 1;
    C[C_tmp] = B[C_tmp];
    C[C_tmp + 1] = B[C_tmp + 1];
  }

  ControllerLateral_trisolve(A, C);
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_trisolve_o(const real_T A[4], real_T B[6])
{
  real_T tmp;
  int32_T j;
  int32_T jBcol;
  for (j = 0; j < 3; j++) {
    jBcol = j << 1;
    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[3];
      B[jBcol] -= B[jBcol + 1] * A[2];
    }

    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_linsolve_o(const real_T A[4], const real_T B[6],
  real_T C[6])
{
  int32_T C_tmp;
  int32_T j;
  for (j = 0; j < 3; j++) {
    C_tmp = j << 1;
    C[C_tmp] = B[C_tmp];
    C[C_tmp + 1] = B[C_tmp + 1];
  }

  ControllerLateral_trisolve_o(A, C);
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_mtimes(const real_T A[9], const real_T B[9],
  real_T C[9])
{
  int32_T aoffset;
  int32_T coffset;
  int32_T i;
  int32_T j;
  for (j = 0; j < 3; j++) {
    coffset = j * 3;
    for (i = 0; i < 3; i++) {
      aoffset = i * 3;
      C[coffset + i] = (A[aoffset + 1] * B[j + 3] + A[aoffset] * B[j]) +
        A[aoffset + 2] * B[j + 6];
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xnrm2_k(int32_T n, const real_T x[15], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgemv_g(int32_T m, int32_T n, const real_T A[15],
  int32_T ia0, const real_T x[15], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if (n != 0) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 5 + ia0;
    for (iac = ia0; iac <= b; iac += 5) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgerc_p(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[15], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 5;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_qrFactor_k(const real_T A[9], real_T S[9], const
  real_T Ns[6])
{
  real_T b_A[15];
  real_T R[9];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  real_T tau_idx_0;
  int32_T coltop;
  int32_T exitg1;
  int32_T ia;
  int32_T knt;
  int32_T lastc;
  boolean_T exitg2;
  ControllerLateral_mtimes(S, A, R);
  for (lastc = 0; lastc < 3; lastc++) {
    b_A[5 * lastc] = R[3 * lastc];
    b_A[5 * lastc + 1] = R[3 * lastc + 1];
    b_A[5 * lastc + 2] = R[3 * lastc + 2];
    b_A[5 * lastc + 3] = Ns[lastc];
    b_A[5 * lastc + 4] = Ns[lastc + 3];
    work[lastc] = 0.0;
  }

  b_atmp = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = ControllerLateral_xnrm2_k(4, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        lastc = 0;
        for (coltop = 1; coltop < 5; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_k(4, b_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 1; coltop < 5; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      while (lastc <= knt - 1) {
        beta1 *= 1.0020841800044864E-292;
        lastc++;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      b_atmp = 1.0 / (b_A[0] - beta1);
      for (lastc = 1; lastc < 5; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 5;
    lastc = 0;
    while ((knt > 0) && (b_A[lastc + 4] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 5 + 5;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia + 1 <= coltop + knt) {
          if (b_A[ia] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_g(knt, lastc, b_A, 6, b_A, 1, work);
    ControllerLateral_xgerc_p(knt, lastc, -tau_idx_0, 1, work, b_A, 6);
  }

  b_A[0] = b_atmp;
  b_atmp = b_A[6];
  tau_idx_0 = 0.0;
  beta1 = ControllerLateral_xnrm2_k(3, b_A, 8);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[6], beta1);
    if (b_A[6] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 7; coltop < 10; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_k(3, b_A, 8));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 7; coltop < 10; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      for (lastc = 0; lastc < knt; lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[6]) / beta1;
      b_atmp = 1.0 / (b_A[6] - beta1);
      for (lastc = 7; lastc < 10; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[6] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 4;
    lastc = 5;
    while ((knt > 0) && (b_A[lastc + 4] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 1;
    ia = 11;
    do {
      exitg1 = 0;
      if (ia + 1 <= 11 + knt) {
        if (b_A[ia] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_g(knt, lastc, b_A, 12, b_A, 7, work);
    ControllerLateral_xgerc_p(knt, lastc, -tau_idx_0, 7, work, b_A, 12);
  }

  b_A[6] = b_atmp;
  b_atmp = b_A[12];
  beta1 = ControllerLateral_xnrm2_k(2, b_A, 14);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[12], beta1);
    if (b_A[12] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 13; coltop < 15; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_k(2, b_A, 14));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 13; coltop < 15; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      for (lastc = 0; lastc < knt; lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      b_atmp = 1.0 / (b_A[12] - beta1);
      for (lastc = 13; lastc < 15; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[12] = b_atmp;
  R[0] = b_A[0];
  for (lastc = 1; lastc + 1 < 4; lastc++) {
    R[lastc] = 0.0;
  }

  for (lastc = 0; lastc < 2; lastc++) {
    R[lastc + 3] = b_A[lastc + 5];
  }

  while (lastc + 1 < 4) {
    R[lastc + 3] = 0.0;
    lastc++;
  }

  for (lastc = 0; lastc < 3; lastc++) {
    R[lastc + 6] = b_A[lastc + 10];
  }

  for (lastc = 0; lastc < 3; lastc++) {
    S[3 * lastc] = R[lastc];
    S[3 * lastc + 1] = R[lastc + 3];
    S[3 * lastc + 2] = R[lastc + 6];
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xnrm2_ks(int32_T n, const real_T x[18], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgemv_gq(int32_T m, int32_T n, const real_T A[18],
  int32_T ia0, const real_T x[18], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if (n != 0) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 6 + ia0;
    for (iac = ia0; iac <= b; iac += 6) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgerc_ph(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[18], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 6;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_qrFactor_k0(const real_T A[9], real_T S[9], const
  real_T Ns[9])
{
  real_T b_A[18];
  real_T R[9];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  real_T tau_idx_0;
  int32_T coltop;
  int32_T exitg1;
  int32_T ia;
  int32_T knt;
  int32_T lastc;
  boolean_T exitg2;
  ControllerLateral_mtimes(S, A, R);
  for (lastc = 0; lastc < 3; lastc++) {
    b_A[6 * lastc] = R[3 * lastc];
    b_A[6 * lastc + 3] = Ns[lastc];
    b_A[6 * lastc + 1] = R[3 * lastc + 1];
    b_A[6 * lastc + 4] = Ns[lastc + 3];
    b_A[6 * lastc + 2] = R[3 * lastc + 2];
    b_A[6 * lastc + 5] = Ns[lastc + 6];
    work[lastc] = 0.0;
  }

  b_atmp = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = ControllerLateral_xnrm2_ks(5, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        lastc = 0;
        for (coltop = 1; coltop < 6; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_ks(5, b_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 1; coltop < 6; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      while (lastc <= knt - 1) {
        beta1 *= 1.0020841800044864E-292;
        lastc++;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      b_atmp = 1.0 / (b_A[0] - beta1);
      for (lastc = 1; lastc < 6; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 6;
    lastc = 0;
    while ((knt > 0) && (b_A[lastc + 5] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 6 + 6;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia + 1 <= coltop + knt) {
          if (b_A[ia] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_gq(knt, lastc, b_A, 7, b_A, 1, work);
    ControllerLateral_xgerc_ph(knt, lastc, -tau_idx_0, 1, work, b_A, 7);
  }

  b_A[0] = b_atmp;
  b_atmp = b_A[7];
  tau_idx_0 = 0.0;
  beta1 = ControllerLateral_xnrm2_ks(4, b_A, 9);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[7], beta1);
    if (b_A[7] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 8; coltop < 12; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_ks(4, b_A, 9));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 8; coltop < 12; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      for (lastc = 0; lastc < knt; lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[7]) / beta1;
      b_atmp = 1.0 / (b_A[7] - beta1);
      for (lastc = 8; lastc < 12; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[7] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 5;
    lastc = 6;
    while ((knt > 0) && (b_A[lastc + 5] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 1;
    ia = 13;
    do {
      exitg1 = 0;
      if (ia + 1 <= 13 + knt) {
        if (b_A[ia] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_gq(knt, lastc, b_A, 14, b_A, 8, work);
    ControllerLateral_xgerc_ph(knt, lastc, -tau_idx_0, 8, work, b_A, 14);
  }

  b_A[7] = b_atmp;
  b_atmp = b_A[14];
  beta1 = ControllerLateral_xnrm2_ks(3, b_A, 16);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[14], beta1);
    if (b_A[14] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 15; coltop < 18; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_ks(3, b_A, 16));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 15; coltop < 18; coltop++) {
        b_A[coltop] *= b_atmp;
      }

      for (lastc = 0; lastc < knt; lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      b_atmp = 1.0 / (b_A[14] - beta1);
      for (lastc = 15; lastc < 18; lastc++) {
        b_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[14] = b_atmp;
  R[0] = b_A[0];
  for (lastc = 1; lastc + 1 < 4; lastc++) {
    R[lastc] = 0.0;
  }

  for (lastc = 0; lastc < 2; lastc++) {
    R[lastc + 3] = b_A[lastc + 6];
  }

  while (lastc + 1 < 4) {
    R[lastc + 3] = 0.0;
    lastc++;
  }

  for (lastc = 0; lastc < 3; lastc++) {
    R[lastc + 6] = b_A[lastc + 12];
  }

  for (lastc = 0; lastc < 3; lastc++) {
    S[3 * lastc] = R[lastc];
    S[3 * lastc + 1] = R[lastc + 3];
    S[3 * lastc + 2] = R[lastc + 6];
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xnrm2_ksh(int32_T n, const real_T x[9], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xscal(int32_T n, real_T a, real_T x[9], int32_T
  ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xnrm2_ksh2(const real_T x[3], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = ix0; k <= ix0 + 1; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static real_T ControllerLateral_xdotc(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xscal_e(real_T a, real_T x[3], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 1; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xaxpy_m(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xaxpy_m0(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xscal_e5(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T ads;
  real_T bds;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }
  }

  *a = scale;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T
  c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + temp * s;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xswap(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_svd(const real_T A[9], real_T U[9], real_T s[3],
  real_T V[9])
{
  real_T b_A[9];
  real_T b_s[3];
  real_T e[3];
  real_T work[3];
  real_T emm1;
  real_T nrm;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T d;
  int32_T exitg1;
  int32_T k_ii;
  int32_T kase;
  int32_T m;
  int32_T qjj;
  int32_T qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  e[0] = 0.0;
  work[0] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (qq = 0; qq < 9; qq++) {
    b_A[qq] = A[qq];
    U[qq] = 0.0;
    V[qq] = 0.0;
  }

  qq = 0;
  apply_transform = false;
  nrm = ControllerLateral_xnrm2_ksh(3, b_A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (fabs(b_s[0]) >= 1.0020841800044864E-292) {
      ControllerLateral_xscal(3, 1.0 / b_s[0], b_A, 1);
    } else {
      for (qjj = 0; qjj < 3; qjj++) {
        b_A[qjj] /= b_s[0];
      }
    }

    b_A[0]++;
    b_s[0] = -b_s[0];
  } else {
    b_s[0] = 0.0;
  }

  for (d = 1; d + 1 < 4; d++) {
    qjj = 3 * d;
    if (apply_transform) {
      ControllerLateral_xaxpy(3, -(ControllerLateral_xdotc(3, b_A, 1, b_A, qjj +
        1) / b_A[0]), 1, b_A, qjj + 1);
    }

    e[d] = b_A[qjj];
  }

  while (qq + 1 < 4) {
    U[qq] = b_A[qq];
    qq++;
  }

  nrm = ControllerLateral_xnrm2_ksh2(e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      nrm = -nrm;
    }

    e[0] = nrm;
    if (fabs(nrm) >= 1.0020841800044864E-292) {
      ControllerLateral_xscal_e(1.0 / nrm, e, 2);
    } else {
      for (qq = 1; qq < 3; qq++) {
        e[qq] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (qq = 2; qq < 4; qq++) {
      work[qq - 1] = 0.0;
    }

    for (qq = 1; qq + 1 < 4; qq++) {
      ControllerLateral_xaxpy_m(2, e[qq], b_A, 3 * qq + 2, work, 2);
    }

    for (qq = 1; qq + 1 < 4; qq++) {
      ControllerLateral_xaxpy_m0(2, -e[qq] / e[1], work, 2, b_A, 3 * qq + 2);
    }
  }

  for (qq = 1; qq + 1 < 4; qq++) {
    V[qq] = e[qq];
  }

  apply_transform = false;
  nrm = ControllerLateral_xnrm2_ksh(2, b_A, 5);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      b_s[1] = -nrm;
    } else {
      b_s[1] = nrm;
    }

    if (fabs(b_s[1]) >= 1.0020841800044864E-292) {
      ControllerLateral_xscal(2, 1.0 / b_s[1], b_A, 5);
    } else {
      for (qjj = 4; qjj < 6; qjj++) {
        b_A[qjj] /= b_s[1];
      }
    }

    b_A[4]++;
    b_s[1] = -b_s[1];
  } else {
    b_s[1] = 0.0;
  }

  for (d = 2; d + 1 < 4; d++) {
    qjj = 3 * d + 1;
    if (apply_transform) {
      ControllerLateral_xaxpy(2, -(ControllerLateral_xdotc(2, b_A, 5, b_A, qjj +
        1) / b_A[4]), 5, b_A, qjj + 1);
    }

    e[d] = b_A[qjj];
  }

  for (qq = 1; qq + 1 < 4; qq++) {
    U[qq + 3] = b_A[qq + 3];
  }

  m = 1;
  b_s[2] = b_A[8];
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (d = 1; d >= 0; d--) {
    qq = 3 * d + d;
    if (b_s[d] != 0.0) {
      for (kase = d + 1; kase + 1 < 4; kase++) {
        qjj = (3 * kase + d) + 1;
        ControllerLateral_xaxpy(3 - d, -(ControllerLateral_xdotc(3 - d, U, qq +
          1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (qjj = d; qjj + 1 < 4; qjj++) {
        kase = 3 * d + qjj;
        U[kase] = -U[kase];
      }

      U[qq]++;
      if (0 <= d - 1) {
        U[3 * d] = 0.0;
      }
    } else {
      U[3 * d] = 0.0;
      U[3 * d + 1] = 0.0;
      U[3 * d + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (qq = 2; qq >= 0; qq--) {
    if ((qq + 1 <= 1) && (e[0] != 0.0)) {
      ControllerLateral_xaxpy(2, -(ControllerLateral_xdotc(2, V, 2, V, 5) / V[1]),
        2, V, 5);
      ControllerLateral_xaxpy(2, -(ControllerLateral_xdotc(2, V, 2, V, 8) / V[1]),
        2, V, 8);
    }

    V[3 * qq] = 0.0;
    V[3 * qq + 1] = 0.0;
    V[3 * qq + 2] = 0.0;
    V[qq + 3 * qq] = 1.0;
  }

  ztest = e[0];
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    ztest = e[0] / nrm;
    ControllerLateral_xscal_e5(nrm, U, 1);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] *= nrm;
    ControllerLateral_xscal_e5(nrm, V, 4);
  }

  e[0] = ztest;
  ztest = b_A[7];
  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    ztest = b_A[7] / nrm;
    ControllerLateral_xscal_e5(nrm, U, 4);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[2] = b_A[8] * nrm;
    ControllerLateral_xscal_e5(nrm, V, 7);
  }

  e[1] = ztest;
  if (b_s[2] != 0.0) {
    rt = fabs(b_s[2]);
    nrm = b_s[2] / rt;
    b_s[2] = rt;
    ControllerLateral_xscal_e5(nrm, U, 7);
  }

  e[2] = 0.0;
  qq = 0;
  if ((b_s[0] > e[0]) || ((int32_T)rtIsNaN(e[0]))) {
    nrm = b_s[0];
  } else {
    nrm = e[0];
  }

  if ((b_s[1] > ztest) || ((int32_T)rtIsNaN(ztest))) {
    ztest = b_s[1];
  }

  if ((!(nrm > ztest)) && (!(int32_T)rtIsNaN(ztest))) {
    nrm = ztest;
  }

  if (b_s[2] > 0.0) {
    rt = b_s[2];
  } else {
    rt = 0.0;
  }

  if ((!(nrm > rt)) && (!(int32_T)rtIsNaN(rt))) {
    nrm = rt;
  }

  while ((m + 2 > 0) && (qq < 75)) {
    kase = m + 1;
    do {
      exitg1 = 0;
      d = kase;
      if (kase == 0) {
        exitg1 = 1;
      } else {
        rt = fabs(e[kase - 1]);
        if ((rt <= (fabs(b_s[kase - 1]) + fabs(b_s[kase])) *
             2.2204460492503131E-16) || ((rt <= 1.0020841800044864E-292) || ((qq
               > 20) && (rt <= 2.2204460492503131E-16 * nrm)))) {
          e[kase - 1] = 0.0;
          exitg1 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg1 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      qjj = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= kase)) {
        qjj = k_ii;
        if (k_ii == kase) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (k_ii < m + 2) {
            rt = fabs(e[k_ii - 1]);
          }

          if (k_ii > kase + 1) {
            rt += fabs(e[k_ii - 2]);
          }

          ztest = fabs(b_s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qjj == kase) {
        kase = 3;
      } else if (m + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        d = qjj;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qjj = m; qjj + 1 >= d + 1; qjj--) {
        ControllerLateral_xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        if (qjj + 1 > d + 1) {
          rt = -sqds * e[0];
          e[0] *= ztest;
        }

        ControllerLateral_xrot(V, 3 * qjj + 1, 3 * (m + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[d - 1];
      e[d - 1] = 0.0;
      for (qjj = d; qjj < m + 2; qjj++) {
        ControllerLateral_xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        ControllerLateral_xrot(U, 3 * qjj + 1, 3 * (d - 1) + 1, ztest, sqds);
      }
      break;

     case 3:
      rt = b_s[m + 1];
      ztest = fabs(rt);
      sqds = fabs(b_s[m]);
      if ((ztest > sqds) || ((int32_T)rtIsNaN(sqds))) {
        sqds = ztest;
      }

      ztest = fabs(e[m]);
      if ((sqds > ztest) || ((int32_T)rtIsNaN(ztest))) {
        ztest = sqds;
      }

      sqds = fabs(b_s[d]);
      if ((ztest > sqds) || ((int32_T)rtIsNaN(sqds))) {
        sqds = ztest;
      }

      ztest = fabs(e[d]);
      if ((sqds > ztest) || ((int32_T)rtIsNaN(ztest))) {
        ztest = sqds;
      }

      rt /= ztest;
      smm1 = b_s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = b_s[d] / ztest;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      ztest = e[d] / ztest * sqds;
      for (qjj = d + 1; qjj <= m + 1; qjj++) {
        ControllerLateral_xrotg(&rt, &ztest, &sqds, &smm1);
        if (qjj > d + 1) {
          e[0] = rt;
        }

        ztest = e[qjj - 1];
        emm1 = b_s[qjj - 1];
        rt = emm1 * sqds + ztest * smm1;
        e[qjj - 1] = ztest * sqds - emm1 * smm1;
        ztest = smm1 * b_s[qjj];
        b_s[qjj] *= sqds;
        ControllerLateral_xrot(V, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds, smm1);
        ControllerLateral_xrotg(&rt, &ztest, &sqds, &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        ControllerLateral_xrot(U, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds, smm1);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[d] < 0.0) {
        b_s[d] = -b_s[d];
        ControllerLateral_xscal_e5(-1.0, V, 3 * d + 1);
      }

      qq = d + 1;
      while ((d + 1 < 3) && (b_s[d] < b_s[qq])) {
        rt = b_s[d];
        b_s[d] = b_s[qq];
        b_s[qq] = rt;
        ControllerLateral_xswap(V, 3 * d + 1, 3 * (d + 1) + 1);
        ControllerLateral_xswap(U, 3 * d + 1, 3 * (d + 1) + 1);
        d = qq;
        qq++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
  s[2] = b_s[2];
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgemv_gq4(int32_T m, int32_T n, const real_T A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if (n != 0) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 3 + ia0;
    for (iac = ia0; iac <= b; iac += 3) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_xgerc_pho(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[3], real_T A[9], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 3;
    }
  }
}

/* Function for MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
static void ControllerLateral_qr(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  int32_T b_coltop;
  int32_T c_lastc;
  int32_T coltop;
  int32_T exitg1;
  int32_T knt;
  boolean_T exitg2;
  tau_idx_0 = 0.0;
  tau_idx_1 = 0.0;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  b_atmp = b_A[0];
  beta1 = ControllerLateral_xnrm2_ksh(2, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        c_lastc = 0;
        for (b_coltop = 1; b_coltop < 3; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_ksh(2, b_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 1; b_coltop < 3; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      while (c_lastc <= knt - 1) {
        beta1 *= 1.0020841800044864E-292;
        c_lastc++;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      b_atmp = 1.0 / (b_A[0] - beta1);
      for (c_lastc = 1; c_lastc < 3; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 0;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 3 + 3;
      coltop = b_coltop;
      do {
        exitg1 = 0;
        if (coltop + 1 <= b_coltop + knt) {
          if (b_A[coltop] != 0.0) {
            exitg1 = 1;
          } else {
            coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_gq4(knt, c_lastc, b_A, 4, b_A, 1, work);
    ControllerLateral_xgerc_pho(knt, c_lastc, -tau_idx_0, 1, work, b_A, 4);
  }

  b_A[0] = b_atmp;
  b_atmp = b_A[4];
  beta1 = ControllerLateral_xnrm2_ksh(1, b_A, 6);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[4], beta1);
    if (b_A[4] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (b_coltop = 5; b_coltop < 6; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(b_atmp, ControllerLateral_xnrm2_ksh(1, b_A, 6));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 5; b_coltop < 6; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      for (c_lastc = 0; c_lastc < knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[4]) / beta1;
      b_atmp = 1.0 / (b_A[4] - beta1);
      for (c_lastc = 5; c_lastc < 6; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 3;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 7;
    do {
      exitg1 = 0;
      if (coltop + 1 <= 7 + knt) {
        if (b_A[coltop] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ControllerLateral_xgemv_gq4(knt, c_lastc, b_A, 8, b_A, 5, work);
    ControllerLateral_xgerc_pho(knt, c_lastc, -tau_idx_1, 5, work, b_A, 8);
  }

  b_A[4] = b_atmp;
  R[0] = b_A[0];
  for (c_lastc = 1; c_lastc + 1 < 4; c_lastc++) {
    R[c_lastc] = 0.0;
  }

  work[0] = 0.0;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    R[c_lastc + 3] = b_A[c_lastc + 3];
  }

  while (c_lastc + 1 < 4) {
    R[c_lastc + 3] = 0.0;
    c_lastc++;
  }

  work[1] = 0.0;
  for (c_lastc = 0; c_lastc < 3; c_lastc++) {
    R[c_lastc + 6] = b_A[c_lastc + 6];
  }

  work[2] = 0.0;
  b_A[8] = 1.0;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    b_A[7 - c_lastc] = 0.0;
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    b_coltop = 7;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 1;
    knt = 8;
    do {
      exitg1 = 0;
      if (knt <= c_lastc + 7) {
        if (b_A[knt - 1] != 0.0) {
          exitg1 = 1;
        } else {
          knt++;
        }
      } else {
        b_coltop = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    c_lastc = 0;
    b_coltop = 0;
  }

  if (c_lastc > 0) {
    ControllerLateral_xgemv_gq4(c_lastc, b_coltop, b_A, 8, b_A, 5, work);
    ControllerLateral_xgerc_pho(c_lastc, b_coltop, -tau_idx_1, 5, work, b_A, 8);
  }

  for (b_coltop = 5; b_coltop < 6; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_1;
  }

  b_A[4] = 1.0 - tau_idx_1;
  b_A[3] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    c_lastc = 3;
    b_coltop = 4;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 2;
    exitg2 = false;
    while ((!exitg2) && (b_coltop > 0)) {
      coltop = (b_coltop - 1) * 3 + 4;
      knt = coltop;
      do {
        exitg1 = 0;
        if (knt <= (coltop + c_lastc) - 1) {
          if (b_A[knt - 1] != 0.0) {
            exitg1 = 1;
          } else {
            knt++;
          }
        } else {
          b_coltop--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    c_lastc = 0;
    b_coltop = 0;
  }

  if (c_lastc > 0) {
    ControllerLateral_xgemv_gq4(c_lastc, b_coltop, b_A, 4, b_A, 1, work);
    ControllerLateral_xgerc_pho(c_lastc, b_coltop, -tau_idx_0, 1, work, b_A, 4);
  }

  for (b_coltop = 1; b_coltop < 3; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (c_lastc = 0; c_lastc < 3; c_lastc++) {
    Q[3 * c_lastc] = b_A[3 * c_lastc];
    b_coltop = 3 * c_lastc + 1;
    Q[b_coltop] = b_A[b_coltop];
    b_coltop = 3 * c_lastc + 2;
    Q[b_coltop] = b_A[b_coltop];
  }
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
  real_T rtb_Delay2_n[2];
  real_T rtb_Switch2_h;
  real_T rtb_Switch2_o;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj_0;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  real_T rtb_uDLookupTable2[14];
  real_T rtb_uDLookupTable2_b[14];
  real_T Ss[9];
  real_T Ss_0[9];
  real_T V[9];
  real_T rtb_Zs[9];
  real_T Hnew[6];
  real_T e[6];
  real_T f[6];
  real_T rtb_L[6];
  real_T rtb_M[6];
  real_T rtb_Gain_p[5];
  real_T RsInv[4];
  real_T yCovSqrt[4];
  real_T yCovSqrt_0[4];
  real_T Add_a[3];
  real_T c[3];
  real_T s[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_Reshapey[2];
  real_T Gain;
  real_T Gain3;
  real_T Gain3_n;
  real_T rtb_A2mm;
  real_T rtb_Add1;
  real_T rtb_Add1_f;
  real_T rtb_Add3_k;
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
  real_T rtb_Gain1_jl;
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
  real_T rtb_Sum_d;
  real_T rtb_Sum_ez;
  real_T rtb_Sum_f;
  real_T rtb_Sum_k;
  real_T rtb_Sum_m;
  real_T rtb_Sum_p;
  real_T rtb_Switch;
  real_T rtb_Switch1;
  real_T rtb_Switch1_e_idx_0;
  real_T rtb_Switch2_e;
  real_T rtb_Switch2_k_idx_1;
  real_T rtb_Switch2_m0;
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
  real_T rtb_c2_dot;
  real_T rtb_c_a;
  real_T rtb_current;
  real_T rtb_current_a;
  real_T rtb_d;
  real_T rtb_d2;
  real_T rtb_d2_dot;
  real_T rtb_d2_dot_g;
  real_T rtb_diff1;
  real_T rtb_diff1_n;
  real_T rtb_diff2;
  real_T rtb_error_a;
  real_T rtb_error_i;
  real_T rtb_offset;
  real_T rtb_offset_h;
  real_T rtb_uDLookupTable1;
  real_T rtb_uDLookupTable1_b;
  real_T rtb_uDLookupTable3;
  real_T rtb_uDLookupTable3_d;
  int32_T exitg1;
  int32_T i;
  int32_T iU;
  int32_T rtb_PulseGenerator;
  int32_T rtb_Switch4;
  int32_T rtb_Switch_dw_idx_0;
  int32_T rtb_Switch_dw_idx_1;
  int32_T rtb_Switch_dw_idx_2;
  int32_T rtb_Switch_dw_idx_3;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  int8_T p;
  boolean_T errorCondition;
  boolean_T exitg2;
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
   *  Constant: '<S563>/Constant'
   *  Memory: '<S9>/Memory'
   *  RelationalOperator: '<S563>/Compare'
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

  /* Switch: '<S337>/Switch' incorporates:
   *  Constant: '<S337>/Constant'
   *  Constant: '<S337>/Constant1'
   *  Constant: '<S337>/Constant2'
   *  Constant: '<S337>/Constant3'
   *  RelationalOperator: '<S337>/Equal'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_Switch = 0.18;
  } else {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S337>/Switch' */

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

  /* Constant: '<S342>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[2],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvfp,
    &ControllerLateral_DW->MovingAverage1_pnaevvfp);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpg,
     &ControllerLateral_DW->MovingAverage_pnaevvfpg);

  /* Switch: '<S342>/Switch' incorporates:
   *  Constant: '<S342>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_do = ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage;
  } else {
    rtb_Switch_do = ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage;
  }

  /* End of Switch: '<S342>/Switch' */

  /* RelationalOperator: '<S9>/Equal' incorporates:
   *  Constant: '<S9>/Constant11'
   */
  ControllerLateral_B->Equal = (boolean_T)(2.0 == rtb_Switch7);

  /* Constant: '<S340>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[0],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevv,
    &ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvf,
     &ControllerLateral_DW->MovingAverage_pnaevvf);

  /* Switch: '<S340>/Switch' incorporates:
   *  Constant: '<S340>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_hy = ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage;
  } else {
    rtb_Switch_hy = ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage;
  }

  /* End of Switch: '<S340>/Switch' */

  /* Gain: '<S339>/Gain3' */
  Gain3 = 0.001 * rtb_Switch_hy;

  /* DiscreteIntegrator: '<S339>/Discrete-Time Integrator' */
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

  /* Gain: '<S339>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S339>/Discrete-Time Integrator'
   */
  rtb_A2mm = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l;

  /* Gain: '<S337>/Gain' incorporates:
   *  Sum: '<S337>/Add'
   *  Switch: '<S337>/Switch3'
   *  Switch: '<S337>/Switch4'
   */
  rtb_Gain_k = (rtb_Switch_do - rtb_Switch_hy) * 0.124;

  /* Sum: '<S337>/Add6' incorporates:
   *  Sum: '<S337>/Add1'
   *  Switch: '<S337>/Switch3'
   */
  rtb_a_n = (rtb_Gain_k + rtb_Switch_hy) - rtb_Switch;

  /* Constant: '<S343>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[3],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvfpg,
    &ControllerLateral_DW->MovingAverage1_pnaevvfpg);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfpgh,
     &ControllerLateral_DW->MovingAverage_pnaevvfpgh);

  /* Switch: '<S343>/Switch' incorporates:
   *  Constant: '<S343>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_pn = ControllerLateral_B->MovingAverage_pnaevvfpgh.MovingAverage;
  } else {
    rtb_Switch_pn = ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage;
  }

  /* End of Switch: '<S343>/Switch' */

  /* Gain: '<S338>/Gain' */
  Gain = 0.001 * rtb_Switch_pn;

  /* DiscreteIntegrator: '<S338>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S337>/Constant6'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = Gain;
  }

  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = Gain;
  }

  rtb_d2 = ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE;

  /* Gain: '<S338>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S338>/Discrete-Time Integrator1'
   */
  rtb_D2mm = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE;

  /* Constant: '<S341>/Constant' */
  ControllerLateral_MovingAverage(rtb_Gain[1],
    ControllerLateral_InstP->LateralForgettingFactor,
    &ControllerLateral_B->MovingAverage1_pnaevvf,
    &ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage
    (ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage,
     ControllerLateral_InstP->LateralForgettingFactor,
     &ControllerLateral_B->MovingAverage_pnaevvfp,
     &ControllerLateral_DW->MovingAverage_pnaevvfp);

  /* Switch: '<S341>/Switch' incorporates:
   *  Constant: '<S341>/Constant1'
   */
  if (ControllerLateral_InstP->LateralDoubleFilter != 0.0) {
    rtb_Switch_m = ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage;
  } else {
    rtb_Switch_m = ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage;
  }

  /* End of Switch: '<S341>/Switch' */

  /* Gain: '<S338>/Gain3' */
  Gain3_n = 0.001 * rtb_Switch_m;

  /* DiscreteIntegrator: '<S338>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S337>/Constant6'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_n != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = Gain3_n;
  }

  if (((ControllerLateral_InstP->ResetComplementary > 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l <= 0)) ||
      ((ControllerLateral_InstP->ResetComplementary <= 0.0) && ((int32_T)
        ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l == 1))) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = Gain3_n;
  }

  rtb_b2 = ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d;

  /* Gain: '<S338>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S338>/Discrete-Time Integrator'
   */
  rtb_B2mm = 1000.0 * ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d;

  /* Gain: '<S337>/Gain1' incorporates:
   *  Sum: '<S337>/Add3'
   *  Switch: '<S337>/Switch1'
   *  Switch: '<S337>/Switch2'
   */
  rtb_Gain1 = (rtb_Switch_pn - rtb_Switch_m) * 0.124;

  /* Sum: '<S337>/Add4' incorporates:
   *  Switch: '<S337>/Switch1'
   */
  rtb_b = rtb_Gain1 + rtb_Switch_m;

  /* Sum: '<S337>/Add7' incorporates:
   *  Sum: '<S337>/Add2'
   *  Switch: '<S337>/Switch4'
   */
  rtb_c_a = (rtb_Switch_do - rtb_Gain_k) - rtb_Switch;

  /* Sum: '<S337>/Add5' incorporates:
   *  Switch: '<S337>/Switch2'
   */
  rtb_d = rtb_Switch_pn - rtb_Gain1;

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

  /* Switch: '<S557>/Switch1' incorporates:
   *  Constant: '<S337>/Constant4'
   *  Constant: '<S344>/Mode 1 AG5'
   *  Constant: '<S559>/Constant'
   *  Constant: '<S560>/Constant'
   *  RelationalOperator: '<S559>/Compare'
   *  RelationalOperator: '<S560>/Compare'
   *  Sum: '<S344>/Subtract2'
   *  Switch: '<S557>/Switch'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_offset = rtb_a_n - ControllerLateral_InstP->LS_curved_AG;
  } else if (ControllerLateral_InstP->LS_mode == 1.0) {
    /* Switch: '<S557>/Switch' incorporates:
     *  Constant: '<S344>/Mode 1 AG'
     *  Sum: '<S344>/Subtract4'
     */
    rtb_offset = ControllerLateral_InstP->LS_straight_AG - rtb_b;
  } else {
    /* Switch: '<S557>/Switch' incorporates:
     *  Gain: '<S344>/Gain'
     *  Sum: '<S344>/Subtract'
     */
    rtb_offset = (rtb_a_n - rtb_b) * 0.5;
  }

  /* End of Switch: '<S557>/Switch1' */

  /* Sum: '<S17>/Sum' incorporates:
   *  Sum: '<S17>/Sum1'
   */
  rtb_error_a = (rtb_Add_i + rtb_Gain_f_idx_0) - rtb_offset;

  /* RelationalOperator: '<S17>/Equal' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  ControllerLateral_B->Equal_p = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S61>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S56>/Filter'
   */
  errorCondition = (boolean_T)!(int32_T)ControllerLateral_B->Equal_p;
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_o <= 0)) || (((int32_T)
        errorCondition) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_o == 1))) {
    ControllerLateral_DW->Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S56>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_p) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState <= 0)) || (((int32_T)
        errorCondition) && ((int32_T)ControllerLateral_DW->Filter_PrevResetState
        == 1))) {
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
  ControllerLateral_B->NProdOut = (rtb_error_a * ControllerLateral_InstP->L_K_d
    - ControllerLateral_DW->Filter_DSTATE) * (6.2831853071795862 /
    ControllerLateral_InstP->L_T_c);

  /* Sum: '<S70>/Sum' incorporates:
   *  Constant: '<S27>/Constant1'
   *  DiscreteIntegrator: '<S61>/Integrator'
   *  Product: '<S66>/PProd Out'
   */
  rtb_Sum_k = (rtb_error_a * ControllerLateral_InstP->L_K_p +
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
  rtb_Sum_p = (0.0 * rtb_Switch_gx + ControllerLateral_DW->Integrator_DSTATE_o)
    + (ControllerLateral_B->Tsamp_c - ControllerLateral_DW->UD_DSTATE_o);

  /* Sum: '<S19>/Add1' incorporates:
   *  Constant: '<S19>/Setpoint'
   */
  rtb_Add1 = rtb_Sum_p + ControllerLateral_InstP->ReferenceLateralOffsets[1];

  /* Switch: '<S558>/Switch1' incorporates:
   *  Constant: '<S337>/Constant4'
   *  Constant: '<S344>/Mode 1 AG4'
   *  Constant: '<S561>/Constant'
   *  Constant: '<S562>/Constant'
   *  RelationalOperator: '<S561>/Compare'
   *  RelationalOperator: '<S562>/Compare'
   *  Sum: '<S344>/Subtract3'
   *  Switch: '<S558>/Switch'
   */
  if (ControllerLateral_InstP->LS_mode == 2.0) {
    rtb_offset_h = rtb_c_a - ControllerLateral_InstP->LS_curved_AG;
  } else if (ControllerLateral_InstP->LS_mode == 1.0) {
    /* Switch: '<S558>/Switch' incorporates:
     *  Constant: '<S344>/Mode 1 AG6'
     *  Sum: '<S344>/Subtract5'
     */
    rtb_offset_h = ControllerLateral_InstP->LS_straight_AG - rtb_d;
  } else {
    /* Switch: '<S558>/Switch' incorporates:
     *  Gain: '<S344>/Gain1'
     *  Sum: '<S344>/Subtract1'
     */
    rtb_offset_h = (rtb_c_a - rtb_d) * 0.5;
  }

  /* End of Switch: '<S558>/Switch1' */

  /* Sum: '<S18>/Sum' incorporates:
   *  Sum: '<S18>/Sum1'
   */
  rtb_error_i = (rtb_Add1 + rtb_Switch2_k_idx_1) - rtb_offset_h;

  /* RelationalOperator: '<S18>/Equal' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  ControllerLateral_B->Equal_b = (boolean_T)(rtb_Switch7 == 2.0);

  /* DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S108>/Filter'
   */
  errorCondition = (boolean_T)!(int32_T)ControllerLateral_B->Equal_b;
  if ((((int32_T)ControllerLateral_B->Equal_b) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_j <= 0)) || (((int32_T)
        errorCondition) && ((int32_T)
        ControllerLateral_DW->Integrator_PrevResetState_j == 1))) {
    ControllerLateral_DW->Integrator_DSTATE_m = 0.0;
  }

  /* DiscreteIntegrator: '<S108>/Filter' */
  if ((((int32_T)ControllerLateral_B->Equal_b) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState_j <= 0)) || (((int32_T)
        errorCondition) && ((int32_T)
        ControllerLateral_DW->Filter_PrevResetState_j == 1))) {
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
  ControllerLateral_B->NProdOut_k = (rtb_error_i *
    ControllerLateral_InstP->L_K_d - ControllerLateral_DW->Filter_DSTATE_a) *
    (6.2831853071795862 / ControllerLateral_InstP->L_T_c);

  /* Sum: '<S122>/Sum' incorporates:
   *  Constant: '<S79>/Constant1'
   *  DiscreteIntegrator: '<S113>/Integrator'
   *  Product: '<S118>/PProd Out'
   */
  rtb_Sum_f = (rtb_error_i * ControllerLateral_InstP->L_K_p +
               ControllerLateral_DW->Integrator_DSTATE_m) +
    ControllerLateral_B->NProdOut_k;

  /* Product: '<S18>/Divide1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Product: '<S18>/Divide'
   */
  rtb_Divide1_n = ControllerLateral_InstP->Mass /
    ControllerLateral_InstP->ReferenceMass * rtb_Sum_f;

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
  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S565>:1' */
  /* '<S565>:1:2' */
  /* '<S565>:1:3' */
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
  rtb_Gain1_jl = (rtb_offset + rtb_Gain_p[0]) *
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
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S564>:1' */
  /* '<S564>:1:4' */
  /* '<S564>:1:5' */
  rtb_Add_m = rtb_Switch1_e_idx_0 -
    (-ControllerLateral_InstP->lateral_over_vertical_force_motor *
     ControllerLateral_U->motor1 * (rtb_Gain1_jl + rtb_Gain_p[4]) -
     ((rtb_Gain1_jl + rtb_Gain_p[2]) * ControllerLateral_U->hems1 +
      (rtb_Gain1_jl + rtb_Gain_p[3]) * ControllerLateral_U->hems2) *
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
  bpIndices[1U] = plook_binxp(rtb_Switch_c, ControllerLateral_ConstP.pooled29,
    100U, &rtb_Switch1_e_idx_0, &ControllerLateral_DW->m_Cache02);
  fractions[1U] = rtb_Switch1_e_idx_0;
  for (iU = 0; iU < 14; iU++) {
    bpIndices[0U] = plook_binxp(ControllerLateral_ConstP.pooled27[iU],
      ControllerLateral_ConstP.pooled27, 13U, &rtb_Switch1_e_idx_0,
      &ControllerLateral_DW->m_Cache01[iU]);
    fractions[0U] = rtb_Switch1_e_idx_0;
    rtb_uDLookupTable2[iU] = intrp2d_l_pw(bpIndices, fractions,
      ControllerLateral_ConstP.pooled28, 14U);
  }

  /* End of Lookup_n-D: '<S15>/2-D Lookup Table2' */

  /* Lookup_n-D: '<S15>/2-D Lookup Table1' incorporates:
   *  Abs: '<S15>/Abs'
   *  Gain: '<S15>/Gain'
   */
  rtb_uDLookupTable1 = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
    (rtb_Add_m), rtb_uDLookupTable2, ControllerLateral_ConstP.pooled27,
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
   *  Constant: '<S566>/Constant11'
   *  Constant: '<S566>/Constant12'
   *  Constant: '<S567>/Constant11'
   *  Constant: '<S567>/Constant12'
   *  Constant: '<S568>/Constant11'
   *  Constant: '<S568>/Constant12'
   *  Constant: '<S569>/Constant11'
   *  Constant: '<S569>/Constant12'
   *  Logic: '<S566>/AND'
   *  Logic: '<S567>/AND'
   *  Logic: '<S568>/AND'
   *  Logic: '<S569>/AND'
   *  RelationalOperator: '<S566>/GreaterThan'
   *  RelationalOperator: '<S566>/SmallerThan'
   *  RelationalOperator: '<S567>/GreaterThan'
   *  RelationalOperator: '<S567>/SmallerThan'
   *  RelationalOperator: '<S568>/GreaterThan'
   *  RelationalOperator: '<S568>/SmallerThan'
   *  RelationalOperator: '<S569>/GreaterThan'
   *  RelationalOperator: '<S569>/SmallerThan'
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
  bpIndices_0[1U] = plook_binxp(rtb_Switch_e, ControllerLateral_ConstP.pooled29,
    100U, &rtb_Switch1_e_idx_0, &ControllerLateral_DW->m_Cache02_m);
  fractions_0[1U] = rtb_Switch1_e_idx_0;
  for (iU = 0; iU < 14; iU++) {
    bpIndices_0[0U] = plook_binxp(ControllerLateral_ConstP.pooled27[iU],
      ControllerLateral_ConstP.pooled27, 13U, &rtb_Switch1_e_idx_0,
      &ControllerLateral_DW->m_Cache01_k[iU]);
    fractions_0[0U] = rtb_Switch1_e_idx_0;
    rtb_uDLookupTable2_b[iU] = intrp2d_l_pw(bpIndices_0, fractions_0,
      ControllerLateral_ConstP.pooled28, 14U);
  }

  /* End of Lookup_n-D: '<S14>/2-D Lookup Table2' */

  /* Lookup_n-D: '<S14>/2-D Lookup Table1' incorporates:
   *  Abs: '<S14>/Abs'
   *  Gain: '<S14>/Gain'
   */
  rtb_uDLookupTable1_b = look1_pbinlxpw(ControllerLateral_InstP->M_f * fabs
    (rtb_Add1_f), rtb_uDLookupTable2_b, ControllerLateral_ConstP.pooled27,
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
    ControllerLateral_ConstP.pooled27, ControllerLateral_ConstP.pooled29,
    ControllerLateral_ConstP.pooled28, ControllerLateral_DW->m_bpIndex_g,
    ControllerLateral_ConstP.pooled36, 14U);

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
    ControllerLateral_ConstP.pooled27, ControllerLateral_ConstP.pooled29,
    ControllerLateral_ConstP.pooled28, ControllerLateral_DW->m_bpIndex_ge,
    ControllerLateral_ConstP.pooled36, 14U);

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
    rtb_GreaterThan1_e = (boolean_T)(-rtb_error_a > 0.0);

    /* RelationalOperator: '<S27>/Equal' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S27>/Constant7'
     */
    rtb_Equal_f = (boolean_T)(1.0 == ControllerLateral_InstP->LS_mode);

    /* RelationalOperator: '<S27>/GreaterThan' incorporates:
     *  Constant: '<S27>/Constant4'
     *  Gain: '<S17>/Gain1'
     */
    rtb_GreaterThan_nv = (boolean_T)(0.0 > -rtb_error_a);

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
  rtb_IProdOut = rtb_error_a *
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
    &ControllerLateral_B->MovingAverage_pnaev,
    &ControllerLateral_DW->MovingAverage_pnaev);

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
      ((ControllerLateral_B->MovingAverage_pnaev.MovingAverage > 0.0) && (2.0 ==
        ControllerLateral_InstP->LS_mode));

    /* RelationalOperator: '<S79>/GreaterThan1' incorporates:
     *  Constant: '<S79>/Constant5'
     *  Gain: '<S18>/Gain1'
     */
    rtb_GreaterThan1 = (boolean_T)(-rtb_error_i > 0.0);

    /* RelationalOperator: '<S79>/Equal' incorporates:
     *  Constant: '<Root>/Lane Switch Mode'
     *  Constant: '<S79>/Constant7'
     */
    rtb_Equal_g = (boolean_T)(1.0 == ControllerLateral_InstP->LS_mode);

    /* RelationalOperator: '<S79>/GreaterThan' incorporates:
     *  Constant: '<S79>/Constant4'
     *  Gain: '<S18>/Gain1'
     */
    rtb_GreaterThan_d = (boolean_T)(0.0 > -rtb_error_i);

    /* RelationalOperator: '<S79>/GreaterThan2' incorporates:
     *  Constant: '<S79>/Constant10'
     */
    rtb_GreaterThan2 = (boolean_T)(0.0 >
      ControllerLateral_B->MovingAverage_pnaev.MovingAverage);

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
  rtb_IProdOut_l = rtb_error_i *
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
  if (rtb_Sum_f >= (rtMinusInf)) {
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
  if ((0.0 * rtb_Sum_f != rtb_Gain_f_idx_1) && ((rtb_Switch1_e_idx_0 < 0.0 ?
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
  ControllerLateral_B->SumI4_e = (rtb_Sum_p - rtb_Sum_p) * 0.01 +
    ControllerLateral_InstP->CurrentIntegralLat * rtb_Switch_gx;

  /* Gain: '<S337>/Gain2' incorporates:
   *  Inport: '<Root>/CoM_y_dot'
   */
  ControllerLateral_B->Gain2 = ControllerLateral_InstP->kalman_ydotdot_gain *
    ControllerLateral_U->CoM_y_dot;

  /* Gain: '<S338>/Gain9' */
  ControllerLateral_B->Gain9 = -ControllerLateral_B->Gain2;

  /* Gain: '<S346>/Gain10' incorporates:
   *  Memory: '<S346>/Memory'
   *  Memory: '<S346>/Memory1'
   *  Sum: '<S346>/Subtract'
   */
  ControllerLateral_B->Gain10 = ((ControllerLateral_B->Gain9 -
    ControllerLateral_DW->Memory_PreviousInput) +
    ControllerLateral_DW->Memory1_PreviousInput) * 0.99995;

  /* Gain: '<S337>/Gain3' incorporates:
   *  Inport: '<Root>/IMU_yaw'
   */
  ControllerLateral_B->Gain3_i = ControllerLateral_InstP->kalman_yawdot_gain *
    ControllerLateral_U->IMU_yaw;

  /* Gain: '<S345>/Gain10' incorporates:
   *  Memory: '<S345>/Memory'
   *  Memory: '<S345>/Memory1'
   *  Sum: '<S345>/Subtract'
   */
  ControllerLateral_B->Gain10_c = ((ControllerLateral_B->Gain3_i -
    ControllerLateral_DW->Memory_PreviousInput_k) +
    ControllerLateral_DW->Memory1_PreviousInput_n) * 0.99995;

  /* Product: '<S350>/Product' incorporates:
   *  Constant: '<S350>/sensor half arm'
   *  Product: '<S349>/Product'
   */
  rtb_Switch1_e_idx_0 = ControllerLateral_B->Gain10_c * 0.465;

  /* Sum: '<S350>/Add1' incorporates:
   *  Product: '<S350>/Product'
   *  Sum: '<S349>/Add1'
   */
  rtb_Gain_f_idx_0 = ControllerLateral_B->Gain10 - rtb_Switch1_e_idx_0;
  rtb_d2_dot = rtb_Gain_f_idx_0;

  /* Sum: '<S349>/Add' incorporates:
   *  Sum: '<S350>/Add'
   */
  rtb_Gain_f_idx_1 = ControllerLateral_B->Gain10 + rtb_Switch1_e_idx_0;
  rtb_b2_dot = rtb_Gain_f_idx_1;

  /* Sum: '<S349>/Add1' */
  rtb_d2_dot_g = rtb_Gain_f_idx_0;

  /* Sum: '<S338>/Subtract4' */
  rtb_diff2 = Gain - rtb_d2;

  /* Gain: '<S437>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S429>/Filter'
   *  Gain: '<S428>/Derivative Gain'
   *  Sum: '<S429>/SumD'
   */
  ControllerLateral_B->FilterCoefficient = (0.0 * rtb_diff2 -
    ControllerLateral_DW->Filter_DSTATE_l) * 100.0;

  /* Sum: '<S443>/Sum' incorporates:
   *  DiscreteIntegrator: '<S434>/Integrator'
   *  Gain: '<S439>/Proportional Gain'
   */
  rtb_Sum_ez = (20.0 * rtb_diff2 + ControllerLateral_DW->Integrator_DSTATE_nb) +
    ControllerLateral_B->FilterCoefficient;

  /* Sum: '<S338>/Add' */
  ControllerLateral_B->Add = rtb_d2_dot_g + rtb_Sum_ez;

  /* Sum: '<S338>/Subtract3' */
  rtb_diff1 = Gain3_n - rtb_b2;

  /* Gain: '<S387>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S379>/Filter'
   *  Gain: '<S378>/Derivative Gain'
   *  Sum: '<S379>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_d = (0.0 * rtb_diff1 -
    ControllerLateral_DW->Filter_DSTATE_d) * 100.0;

  /* Sum: '<S393>/Sum' incorporates:
   *  DiscreteIntegrator: '<S384>/Integrator'
   *  Gain: '<S389>/Proportional Gain'
   */
  rtb_Sum_m = (20.0 * rtb_diff1 + ControllerLateral_DW->Integrator_DSTATE_p) +
    ControllerLateral_B->FilterCoefficient_d;

  /* Sum: '<S338>/Add1' */
  ControllerLateral_B->Add1 = rtb_Gain_f_idx_1 + rtb_Sum_m;

  /* DeadZone: '<S377>/DeadZone' */
  if (rtb_Sum_m >= (rtMinusInf)) {
    Gain = 0.0;
  } else {
    Gain = (rtNaN);
  }

  /* End of DeadZone: '<S377>/DeadZone' */

  /* Switch: '<S375>/Switch' incorporates:
   *  Gain: '<S375>/ZeroGain'
   *  RelationalOperator: '<S375>/NotEqual'
   */
  if (0.0 * rtb_Sum_m != Gain) {
    /* Switch: '<S375>/Switch' incorporates:
     *  Constant: '<S375>/Constant1'
     */
    ControllerLateral_B->Switch_b = 0.0;
  } else {
    /* Switch: '<S375>/Switch' incorporates:
     *  Gain: '<S381>/Integral Gain'
     */
    ControllerLateral_B->Switch_b = 0.0 * rtb_diff1;
  }

  /* End of Switch: '<S375>/Switch' */

  /* DeadZone: '<S427>/DeadZone' */
  if (rtb_Sum_ez >= (rtMinusInf)) {
    Gain = 0.0;
  } else {
    Gain = (rtNaN);
  }

  /* End of DeadZone: '<S427>/DeadZone' */

  /* Switch: '<S425>/Switch' incorporates:
   *  Gain: '<S425>/ZeroGain'
   *  RelationalOperator: '<S425>/NotEqual'
   */
  if (0.0 * rtb_Sum_ez != Gain) {
    /* Switch: '<S425>/Switch' incorporates:
     *  Constant: '<S425>/Constant1'
     */
    ControllerLateral_B->Switch_bb = 0.0;
  } else {
    /* Switch: '<S425>/Switch' incorporates:
     *  Gain: '<S431>/Integral Gain'
     */
    ControllerLateral_B->Switch_bb = 0.0 * rtb_diff2;
  }

  /* End of Switch: '<S425>/Switch' */

  /* Gain: '<S451>/Gain10' incorporates:
   *  Memory: '<S451>/Memory'
   *  Memory: '<S451>/Memory1'
   *  Sum: '<S451>/Subtract'
   */
  ControllerLateral_B->Gain10_o = ((ControllerLateral_B->Gain2 -
    ControllerLateral_DW->Memory_PreviousInput_l) +
    ControllerLateral_DW->Memory1_PreviousInput_d) * 0.99995;

  /* Gain: '<S452>/Gain10' incorporates:
   *  Memory: '<S452>/Memory'
   *  Memory: '<S452>/Memory1'
   *  Sum: '<S452>/Subtract'
   */
  ControllerLateral_B->Gain10_o4 = ((ControllerLateral_B->Gain3_i -
    ControllerLateral_DW->Memory_PreviousInput_d) +
    ControllerLateral_DW->Memory1_PreviousInput_g) * 0.99995;

  /* Sum: '<S456>/Add1' incorporates:
   *  Constant: '<S456>/sensor half arm'
   *  Product: '<S456>/Product'
   */
  rtb_c2_dot = ControllerLateral_B->Gain10_o + ControllerLateral_B->Gain10_o4 *
    0.465;

  /* Sum: '<S455>/Add' incorporates:
   *  Constant: '<S455>/sensor half arm'
   *  Product: '<S455>/Product'
   *  Sum: '<S456>/Add'
   */
  Gain = ControllerLateral_B->Gain10_o - ControllerLateral_B->Gain10_o4 * 0.465;
  rtb_a2_dot = Gain;

  /* Sum: '<S339>/Subtract3' */
  rtb_diff1_n = Gain3 - rtb_a2;

  /* Gain: '<S493>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S485>/Filter'
   *  Gain: '<S484>/Derivative Gain'
   *  Sum: '<S485>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_l = (0.0 * rtb_diff1_n -
    ControllerLateral_DW->Filter_DSTATE_i) * 100.0;

  /* Sum: '<S499>/Sum' incorporates:
   *  DiscreteIntegrator: '<S490>/Integrator'
   *  Gain: '<S495>/Proportional Gain'
   */
  rtb_Sum_d = (20.0 * rtb_diff1_n + ControllerLateral_DW->Integrator_DSTATE_h) +
    ControllerLateral_B->FilterCoefficient_l;

  /* Sum: '<S339>/Add1' */
  ControllerLateral_B->Add1_b = Gain + rtb_Sum_d;

  /* DeadZone: '<S483>/DeadZone' */
  if (rtb_Sum_d >= (rtMinusInf)) {
    Gain3 = 0.0;
  } else {
    Gain3 = (rtNaN);
  }

  /* End of DeadZone: '<S483>/DeadZone' */

  /* Switch: '<S481>/Switch' incorporates:
   *  Gain: '<S481>/ZeroGain'
   *  RelationalOperator: '<S481>/NotEqual'
   */
  if (0.0 * rtb_Sum_d != Gain3) {
    /* Switch: '<S481>/Switch' incorporates:
     *  Constant: '<S481>/Constant1'
     */
    ControllerLateral_B->Switch_g = 0.0;
  } else {
    /* Switch: '<S481>/Switch' incorporates:
     *  Gain: '<S487>/Integral Gain'
     */
    ControllerLateral_B->Switch_g = 0.0 * rtb_diff1_n;
  }

  /* End of Switch: '<S481>/Switch' */

  /* SignalConversion generated from: '<Root>/Delay2' */
  ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[0] = rtb_current_a;
  ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[1] = rtb_current;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant5'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  /* MATLAB Function 'MATLAB Function': '<S6>:1' */
  if (!(ControllerLateral_InstP->LS_mode == 0.0)) {
    if ((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_1 == 0))
    {
      /* '<S6>:1:4' */
      if (rtb_current_a > 0.0) {
        /* '<S6>:1:5' */
        /* '<S6>:1:6' */
        rtb_current_a = 0.0;
      }
    } else if ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_0
                == 0) && (rtb_current_a < 0.0)) {
      /* '<S6>:1:8' */
      /* '<S6>:1:9' */
      /* '<S6>:1:10' */
      rtb_current_a = 0.0;
    }

    if ((ControllerLateral_InstP->LS_mode == 2.0) && (rtb_Switch_dw_idx_3 == 0))
    {
      /* '<S7>:1:4' */
      if (rtb_current > 0.0) {
        /* '<S7>:1:5' */
        /* '<S7>:1:6' */
        rtb_current = 0.0;
      }
    } else if ((ControllerLateral_InstP->LS_mode == 1.0) && (rtb_Switch_dw_idx_2
                == 0) && (rtb_current < 0.0)) {
      /* '<S7>:1:8' */
      /* '<S7>:1:9' */
      /* '<S7>:1:10' */
      rtb_current = 0.0;
    }
  } else {
    /* '<S6>:1:2' */
    /* '<S7>:1:2' */
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Switch: '<Root>/Switch3' */
  /* MATLAB Function 'MATLAB Function1': '<S7>:1' */
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
  /* MATLAB Function 'Lane Switch Transition1': '<S5>:1' */
  if (!(int32_T)ControllerLateral_DW->mode_old_not_empty) {
    /* '<S5>:1:5' */
    /* '<S5>:1:6' */
    ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;
    ControllerLateral_DW->mode_old_not_empty = true;
  }

  /* '<S5>:1:17' */
  /* '<S5>:1:18' */
  if (ControllerLateral_DW->mode_old != ControllerLateral_InstP->LS_mode) {
    /* '<S5>:1:22' */
    /* '<S5>:1:23' */
    ControllerLateral_DW->t_old = (((ControllerLateral_M->Timing.clockTick0+
      ControllerLateral_M->Timing.clockTickH0* 4294967296.0)) * 0.00025);

    /* '<S5>:1:24' */
    ControllerLateral_DW->mode_memory_old = ControllerLateral_DW->mode_old;
  }

  /* '<S5>:1:41' */
  ControllerLateral_DW->mode_old = ControllerLateral_InstP->LS_mode;

  /* End of MATLAB Function: '<Root>/Lane Switch Transition1' */

  /* Outport: '<Root>/Complementary_B' */
  ControllerLateral_Y->Complementary_B = rtb_B2mm;

  /* Outport: '<Root>/Complementary_D' */
  ControllerLateral_Y->Complementary_D = rtb_D2mm;

  /* Outport: '<Root>/Complementary_A' incorporates:
   *  Switch: '<S337>/Switch3'
   */
  ControllerLateral_Y->Complementary_A = rtb_Switch_hy;

  /* Outport: '<Root>/Complementary_C' incorporates:
   *  Switch: '<S337>/Switch4'
   */
  ControllerLateral_Y->Complementary_C = rtb_Switch_do;

  /* Outport: '<Root>/Inertia' */
  ControllerLateral_Y->Inertia = rtb_Inertia;

  /* Delay: '<S236>/MemoryP' incorporates:
   *  Constant: '<S236>/P0'
   */
  if (ControllerLateral_DW->icLoad) {
    memcpy(&ControllerLateral_DW->MemoryP_DSTATE[0],
           &ControllerLateral_ConstP.P0_Value[0], 9U * sizeof(real_T));
  }

  /* Outputs for Atomic SubSystem: '<S236>/CalculatePL' */
  /* MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' incorporates:
   *  Constant: '<S258>/Bbar_'
   *  Constant: '<S258>/Qbar_'
   *  Constant: '<S258>/Rbar_'
   *  Constant: '<S4>/A'
   *  Constant: '<S4>/C'
   *  Delay: '<S236>/MemoryP'
   */
  /* MATLAB Function 'KalmanFilterUtilities/DTCalculatePLSqrt/Discrete-Time SqrtKF - Calculate SLMZ': '<S280>:1' */
  /* '<S280>:1:7' */
  ControllerLateral_qrFactor(ControllerLateral_ConstP.C_Value,
    ControllerLateral_DW->MemoryP_DSTATE, ControllerLateral_ConstP.Rbar_Value,
    yCovSqrt);
  for (i = 0; i < 3; i++) {
    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3; rtb_Switch_dw_idx_0++)
    {
      rtb_Switch_dw_idx_1 = i + 3 * rtb_Switch_dw_idx_0;
      V[rtb_Switch_dw_idx_1] = 0.0;
      V[rtb_Switch_dw_idx_1] += ControllerLateral_DW->MemoryP_DSTATE[i] *
        ControllerLateral_DW->MemoryP_DSTATE[rtb_Switch_dw_idx_0];
      V[rtb_Switch_dw_idx_1] += ControllerLateral_DW->MemoryP_DSTATE[i + 3] *
        ControllerLateral_DW->MemoryP_DSTATE[rtb_Switch_dw_idx_0 + 3];
      V[rtb_Switch_dw_idx_1] += ControllerLateral_DW->MemoryP_DSTATE[i + 6] *
        ControllerLateral_DW->MemoryP_DSTATE[rtb_Switch_dw_idx_0 + 6];
    }

    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 2; rtb_Switch_dw_idx_0++)
    {
      iU = i + 3 * rtb_Switch_dw_idx_0;
      Hnew[iU] = 0.0;
      Hnew[iU] += V[i] * ControllerLateral_ConstP.C_Value[rtb_Switch_dw_idx_0];
      Hnew[iU] += V[i + 3] *
        ControllerLateral_ConstP.C_Value[rtb_Switch_dw_idx_0 + 2];
      Hnew[iU] += V[i + 6] *
        ControllerLateral_ConstP.C_Value[rtb_Switch_dw_idx_0 + 4];
    }
  }

  for (i = 0; i < 2; i++) {
    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3; rtb_Switch_dw_idx_0++)
    {
      f[i + (rtb_Switch_dw_idx_0 << 1)] = (Hnew[3 * i + 1] *
        ControllerLateral_ConstP.A_Value[rtb_Switch_dw_idx_0 + 3] + Hnew[3 * i] *
        ControllerLateral_ConstP.A_Value[rtb_Switch_dw_idx_0]) + Hnew[3 * i + 2]
        * ControllerLateral_ConstP.A_Value[rtb_Switch_dw_idx_0 + 6];
    }
  }

  ControllerLateral_linsolve(yCovSqrt, f, e);
  yCovSqrt_0[0] = yCovSqrt[0];
  yCovSqrt_0[1] = yCovSqrt[2];
  yCovSqrt_0[2] = yCovSqrt[1];
  yCovSqrt_0[3] = yCovSqrt[3];
  ControllerLateral_linsolve_o(yCovSqrt_0, e, f);
  for (i = 0; i < 2; i++) {
    rtb_L[3 * i] = f[i];
    rtb_L[3 * i + 1] = f[i + 2];
    rtb_L[3 * i + 2] = f[i + 4];
  }

  for (i = 0; i < 3; i++) {
    iU = i << 1;
    f[iU] = Hnew[i];
    f[iU + 1] = Hnew[i + 3];
  }

  ControllerLateral_linsolve(yCovSqrt, f, e);
  yCovSqrt_0[0] = yCovSqrt[0];
  yCovSqrt_0[1] = yCovSqrt[2];
  yCovSqrt_0[2] = yCovSqrt[1];
  yCovSqrt_0[3] = yCovSqrt[3];
  ControllerLateral_linsolve_o(yCovSqrt_0, e, f);
  for (i = 0; i < 2; i++) {
    rtb_M[3 * i] = f[i];
    rtb_M[3 * i + 1] = f[i + 2];
    rtb_M[3 * i + 2] = f[i + 4];
  }

  for (i = 0; i < 9; i++) {
    Ss[i] = 0.0;
    rtb_Zs[i] = ControllerLateral_DW->MemoryP_DSTATE[i];
  }

  Ss[0] = 1.0;
  Ss[4] = 1.0;
  Ss[8] = 1.0;
  for (i = 0; i < 3; i++) {
    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3; rtb_Switch_dw_idx_0++)
    {
      iU = rtb_Switch_dw_idx_0 << 1;
      rtb_Switch_dw_idx_1 = 3 * rtb_Switch_dw_idx_0 + i;
      Ss_0[rtb_Switch_dw_idx_1] = Ss[rtb_Switch_dw_idx_1] -
        (ControllerLateral_ConstP.C_Value[iU + 1] * rtb_M[i + 3] +
         ControllerLateral_ConstP.C_Value[iU] * rtb_M[i]);
    }

    Hnew[i] = 0.0;
    Hnew[i] += rtb_M[i] * 223.60679774997897;
    Gain3 = rtb_M[i + 3];
    Hnew[i] += Gain3 * 0.0;
    Hnew[i + 3] = 0.0;
    Hnew[i + 3] += rtb_M[i] * 0.0;
    Hnew[i + 3] += Gain3 * 0.22360679774997896;
  }

  ControllerLateral_qrFactor_k(Ss_0, rtb_Zs, Hnew);
  RsInv[0] = 0.00447213595499958;
  RsInv[1] = -0.0;
  RsInv[2] = -0.0;
  RsInv[3] = 4.47213595499958;
  for (i = 0; i < 3; i++) {
    Hnew[i] = 0.0;
    Hnew[i] = 0.0;
    Hnew[i] = 0.0;
    Hnew[i + 3] = 0.0;
  }

  memcpy(&Ss[0], &rtb_Zs[0], 9U * sizeof(real_T));
  for (i = 0; i < 2; i++) {
    yCovSqrt[i] = 0.0;
    iU = i << 1;
    Gain3 = RsInv[iU];
    yCovSqrt[i] += Gain3 * 0.00447213595499958;
    Gain = RsInv[iU + 1];
    yCovSqrt[i] += Gain * -0.0;
    yCovSqrt[i + 2] = 0.0;
    yCovSqrt[i + 2] += Gain3 * -0.0;
    yCovSqrt[i + 2] += Gain * 4.47213595499958;
  }

  for (i = 0; i < 3; i++) {
    f[i] = 0.0;
    f[i] += 0.0 * yCovSqrt[0];
    f[i] += 0.0 * yCovSqrt[1];
    f[i + 3] = 0.0;
    f[i + 3] += 0.0 * yCovSqrt[2];
    f[i + 3] += 0.0 * yCovSqrt[3];
    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3; rtb_Switch_dw_idx_0++)
    {
      rtb_Switch_dw_idx_1 = rtb_Switch_dw_idx_0 << 1;
      iU = 3 * rtb_Switch_dw_idx_0 + i;
      V[iU] = ControllerLateral_ConstP.A_Value[iU] -
        (ControllerLateral_ConstP.C_Value[rtb_Switch_dw_idx_1 + 1] * f[i + 3] +
         ControllerLateral_ConstP.C_Value[rtb_Switch_dw_idx_1] * f[i]);
    }
  }

  ControllerLateral_qrFactor_k0(V, Ss, ControllerLateral_ConstP.Qbar_Value);
  for (i = 0; i < 3; i++) {
    ControllerLateral_B->SNew[3 * i] = Ss[i];
    ControllerLateral_B->SNew[3 * i + 1] = Ss[i + 3];
    ControllerLateral_B->SNew[3 * i + 2] = Ss[i + 6];
  }

  for (iU = 0; iU < 2; iU++) {
    for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 2; rtb_Switch_dw_idx_0++)
    {
      ControllerLateral_B->SNew[rtb_Switch_dw_idx_0 + 1] = 0.0;
    }

    ControllerLateral_B->SNew[5] = 0.0;
    rtb_Switch_dw_idx_0 = 0;
    p = (int8_T)0;
    if ((ControllerLateral_B->SNew[0] == 0.0) || (ControllerLateral_B->SNew[4] ==
         0.0) || (ControllerLateral_B->SNew[8] == 0.0)) {
      p = (int8_T)2;
    } else {
      Add_a[0] = Hnew[3 * iU];
      Add_a[1] = Hnew[3 * iU + 1];
      Add_a[2] = Hnew[3 * iU + 2];
      Add_a[0] /= ControllerLateral_B->SNew[0];
      Add_a[1] = (Add_a[1] - Add_a[0] * ControllerLateral_B->SNew[3]) /
        ControllerLateral_B->SNew[4];
      Gain3 = Add_a[2];
      for (i = 0; i < 2; i++) {
        Gain3 -= ControllerLateral_B->SNew[i + 6] * Add_a[i];
      }

      Add_a[2] = Gain3 / ControllerLateral_B->SNew[8];
      Gain = 3.3121686421112381E-170;
      Gain3_n = fabs(Add_a[0]);
      if (Gain3_n > 3.3121686421112381E-170) {
        Gain3 = 1.0;
        Gain = Gain3_n;
      } else {
        rtb_Switch1_e_idx_0 = Gain3_n / 3.3121686421112381E-170;
        Gain3 = rtb_Switch1_e_idx_0 * rtb_Switch1_e_idx_0;
      }

      Gain3_n = fabs(Add_a[1]);
      if (Gain3_n > Gain) {
        rtb_Switch1_e_idx_0 = Gain / Gain3_n;
        Gain3 = Gain3 * rtb_Switch1_e_idx_0 * rtb_Switch1_e_idx_0 + 1.0;
        Gain = Gain3_n;
      } else {
        rtb_Switch1_e_idx_0 = Gain3_n / Gain;
        Gain3 += rtb_Switch1_e_idx_0 * rtb_Switch1_e_idx_0;
      }

      Gain3_n = fabs(Add_a[2]);
      if (Gain3_n > Gain) {
        rtb_Switch1_e_idx_0 = Gain / Gain3_n;
        Gain3 = Gain3 * rtb_Switch1_e_idx_0 * rtb_Switch1_e_idx_0 + 1.0;
        Gain = Gain3_n;
      } else {
        rtb_Switch1_e_idx_0 = Gain3_n / Gain;
        Gain3 += rtb_Switch1_e_idx_0 * rtb_Switch1_e_idx_0;
      }

      Gain3 = Gain * sqrt(Gain3);
      if (Gain3 >= 1.0) {
        p = (int8_T)1;
      } else {
        Gain = sqrt(1.0 - Gain3 * Gain3);
        if (Gain3_n == 0.0) {
          c[2] = 1.0;
          s[2] = 0.0;
        } else {
          Gain3 = Gain + Gain3_n;
          Gain /= Gain3;
          Gain3_n = Add_a[2] / Gain3;
          rtb_Gain_f_idx_1 = rt_hypotd_snf(Gain, fabs(Gain3_n));
          c[2] = Gain / rtb_Gain_f_idx_1;
          Gain /= Gain;
          s[2] = Gain * Gain3_n / rtb_Gain_f_idx_1;
          Gain *= rtb_Gain_f_idx_1 * Gain3;
        }

        Add_a[2] = 0.0;
        Gain3_n = fabs(Add_a[1]);
        if (Gain3_n == 0.0) {
          c[1] = 1.0;
          s[1] = 0.0;
        } else if (Gain == 0.0) {
          c[1] = 0.0;
          s[1] = 1.0;
          Gain = Add_a[1];
        } else {
          Gain3 = Gain + Gain3_n;
          Gain /= Gain3;
          Gain3_n = Add_a[1] / Gain3;
          rtb_Gain_f_idx_1 = rt_hypotd_snf(Gain, fabs(Gain3_n));
          c[1] = Gain / rtb_Gain_f_idx_1;
          Gain /= Gain;
          s[1] = Gain * Gain3_n / rtb_Gain_f_idx_1;
          Gain *= rtb_Gain_f_idx_1 * Gain3;
        }

        Add_a[1] = 0.0;
        Gain3 = fabs(Gain);
        Gain3_n = fabs(Add_a[0]);
        if (Gain3_n == 0.0) {
          c[0] = 1.0;
          s[0] = 0.0;
        } else if (Gain3 == 0.0) {
          c[0] = 0.0;
          s[0] = 1.0;
        } else {
          Gain3 += Gain3_n;
          Gain /= Gain3;
          Gain3_n = Add_a[0] / Gain3;
          rtb_Switch1_e_idx_0 = fabs(Gain);
          rtb_Gain_f_idx_1 = rt_hypotd_snf(rtb_Switch1_e_idx_0, fabs(Gain3_n));
          c[0] = rtb_Switch1_e_idx_0 / rtb_Gain_f_idx_1;
          s[0] = Gain / rtb_Switch1_e_idx_0 * Gain3_n / rtb_Gain_f_idx_1;
        }

        Add_a[0] = 0.0;
        while (rtb_Switch_dw_idx_0 + 1 > 0) {
          Gain3 = s[rtb_Switch_dw_idx_0] * ControllerLateral_B->
            SNew[rtb_Switch_dw_idx_0];
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_0] = c[rtb_Switch_dw_idx_0]
            * ControllerLateral_B->SNew[rtb_Switch_dw_idx_0] -
            s[rtb_Switch_dw_idx_0] * Add_a[0];
          Add_a[0] = c[rtb_Switch_dw_idx_0] * Add_a[0] + Gain3;
          rtb_Switch_dw_idx_0--;
        }

        for (rtb_Switch_dw_idx_0 = 1; rtb_Switch_dw_idx_0 + 1 > 0;
             rtb_Switch_dw_idx_0--) {
          Gain3 = ControllerLateral_B->SNew[rtb_Switch_dw_idx_0 + 3];
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_0 + 3] = Gain3 *
            c[rtb_Switch_dw_idx_0] - s[rtb_Switch_dw_idx_0] * Add_a[1];
          Add_a[1] = c[rtb_Switch_dw_idx_0] * Add_a[1] + Gain3 *
            s[rtb_Switch_dw_idx_0];
        }

        for (rtb_Switch_dw_idx_0 = 2; rtb_Switch_dw_idx_0 + 1 > 0;
             rtb_Switch_dw_idx_0--) {
          Gain3 = ControllerLateral_B->SNew[rtb_Switch_dw_idx_0 + 6];
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_0 + 6] = Gain3 *
            c[rtb_Switch_dw_idx_0] - s[rtb_Switch_dw_idx_0] * Add_a[2];
          Add_a[2] = c[rtb_Switch_dw_idx_0] * Add_a[2] + Gain3 *
            s[rtb_Switch_dw_idx_0];
        }
      }
    }

    if ((int32_T)p != 0) {
      for (i = 0; i < 3; i++) {
        for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3;
             rtb_Switch_dw_idx_0++) {
          rtb_Switch_dw_idx_1 = i + 3 * rtb_Switch_dw_idx_0;
          V[rtb_Switch_dw_idx_1] = 0.0;
          V[rtb_Switch_dw_idx_1] += ControllerLateral_B->SNew[3 * i] *
            ControllerLateral_B->SNew[3 * rtb_Switch_dw_idx_0];
          V[rtb_Switch_dw_idx_1] += ControllerLateral_B->SNew[3 * i + 1] *
            ControllerLateral_B->SNew[3 * rtb_Switch_dw_idx_0 + 1];
          V[rtb_Switch_dw_idx_1] += ControllerLateral_B->SNew[3 * i + 2] *
            ControllerLateral_B->SNew[3 * rtb_Switch_dw_idx_0 + 2];
          Ss[rtb_Switch_dw_idx_0 + 3 * i] = Hnew[3 * iU + rtb_Switch_dw_idx_0] *
            Hnew[3 * iU + i];
        }
      }

      for (i = 0; i < 9; i++) {
        Ss_0[i] = V[i] - Ss[i];
      }

      errorCondition = true;
      for (i = 0; i < 9; i++) {
        Gain3 = Ss_0[i];
        if (((int32_T)errorCondition) && ((!(int32_T)rtIsInf(Gain3)) &&
             (!(int32_T)rtIsNaN(Gain3)))) {
        } else {
          errorCondition = false;
        }
      }

      if (errorCondition) {
        ControllerLateral_svd(Ss_0, Ss, s, V);
      } else {
        s[0] = (rtNaN);
        s[1] = (rtNaN);
        s[2] = (rtNaN);
        for (i = 0; i < 9; i++) {
          V[i] = (rtNaN);
        }
      }

      for (i = 0; i < 9; i++) {
        Ss[i] = 0.0;
      }

      Ss[0] = s[0];
      Ss[4] = s[1];
      Ss[8] = s[2];
      for (i = 0; i < 9; i++) {
        Ss[i] = sqrt(Ss[i]);
      }

      for (i = 0; i < 3; i++) {
        for (rtb_Switch_dw_idx_0 = 0; rtb_Switch_dw_idx_0 < 3;
             rtb_Switch_dw_idx_0++) {
          rtb_Switch_dw_idx_1 = i + 3 * rtb_Switch_dw_idx_0;
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_1] = 0.0;
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_1] += Ss[3 * i] *
            V[rtb_Switch_dw_idx_0];
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_1] += Ss[3 * i + 1] *
            V[rtb_Switch_dw_idx_0 + 3];
          ControllerLateral_B->SNew[rtb_Switch_dw_idx_1] += Ss[3 * i + 2] *
            V[rtb_Switch_dw_idx_0 + 6];
        }
      }

      errorCondition = true;
      i = 0;
      exitg2 = false;
      while ((!exitg2) && (i < 3)) {
        rtb_Switch_dw_idx_0 = i + 1;
        do {
          exitg1 = 0;
          if (rtb_Switch_dw_idx_0 + 1 < 4) {
            if (!(ControllerLateral_B->SNew[3 * i + rtb_Switch_dw_idx_0] == 0.0))
            {
              errorCondition = false;
              exitg1 = 1;
            } else {
              rtb_Switch_dw_idx_0++;
            }
          } else {
            i++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (!(int32_T)errorCondition) {
        ControllerLateral_qr(ControllerLateral_B->SNew, Ss, Ss_0);
        memcpy(&ControllerLateral_B->SNew[0], &Ss_0[0], 9U * sizeof(real_T));
      }
    }
  }

  for (i = 0; i < 3; i++) {
    V[3 * i] = ControllerLateral_B->SNew[i];
    V[3 * i + 1] = ControllerLateral_B->SNew[i + 3];
    V[3 * i + 2] = ControllerLateral_B->SNew[i + 6];
  }

  memcpy(&ControllerLateral_B->SNew[0], &V[0], 9U * sizeof(real_T));

  /* End of MATLAB Function: '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
  /* End of Outputs for SubSystem: '<S236>/CalculatePL' */

  /* MATLABSystem: '<S4>/Moving Average' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  /* '<S280>:1:7' */
  if (ControllerLateral_DW->obj_a.ForgettingFactor != 0.9) {
    errorCondition = (boolean_T)(ControllerLateral_DW->obj_a.isInitialized == 1);
    if (errorCondition) {
      ControllerLateral_DW->obj_a.TunablePropsChanged = true;
    }

    ControllerLateral_DW->obj_a.ForgettingFactor = 0.9;
  }

  if (ControllerLateral_DW->obj_a.TunablePropsChanged) {
    ControllerLateral_DW->obj_a.TunablePropsChanged = false;
    obj_0 = ControllerLateral_DW->obj_a.pStatistic;
    errorCondition = (boolean_T)(obj_0->isInitialized == 1);
    if (errorCondition) {
      obj_0->TunablePropsChanged = true;
    }

    ControllerLateral_DW->obj_a.pStatistic->ForgettingFactor =
      ControllerLateral_DW->obj_a.ForgettingFactor;
  }

  obj_0 = ControllerLateral_DW->obj_a.pStatistic;
  if (obj_0->isInitialized != 1) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1;
    obj_0->pwN = 1.0;
    obj_0->pmN = 0.0;
    obj_0->plambda = obj_0->ForgettingFactor;
    obj_0->isSetupComplete = true;
    obj_0->TunablePropsChanged = false;
    obj_0->pwN = 1.0;
    obj_0->pmN = 0.0;
  }

  if (obj_0->TunablePropsChanged) {
    obj_0->TunablePropsChanged = false;
    obj_0->plambda = obj_0->ForgettingFactor;
  }

  Gain3 = obj_0->pwN;
  Gain3_n = obj_0->pmN;
  Gain = obj_0->plambda;
  Gain3_n = (1.0 - 1.0 / Gain3) * Gain3_n + 1.0 / Gain3 *
    ControllerLateral_InstP->x_location_raw;
  obj_0->pwN = Gain * Gain3 + 1.0;
  obj_0->pmN = Gain3_n;

  /* Gain: '<S4>/Gain' incorporates:
   *  Inport: '<Root>/com_acc_x'
   */
  ControllerLateral_B->Gain_f = ControllerLateral_InstP->kalman_xdotdot_gain *
    ControllerLateral_U->com_acc_x;

  /* Reshape: '<S236>/Reshapey' incorporates:
   *  MATLABSystem: '<S4>/Moving Average'
   */
  rtb_Reshapey[0] = Gain3_n;
  rtb_Reshapey[1] = ControllerLateral_B->Gain_f;

  /* Delay: '<S236>/MemoryX' */
  if (ControllerLateral_DW->icLoad_m) {
    ControllerLateral_DW->MemoryX_DSTATE[0] = 0.0;
    ControllerLateral_DW->MemoryX_DSTATE[1] = 0.0;
    ControllerLateral_DW->MemoryX_DSTATE[2] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S264>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S288>/Enable'
   */
  ControllerLateral_DW->EnabledSubsystem_MODE = true;
  for (i = 0; i < 2; i++) {
    /* Sum: '<S288>/Add1' incorporates:
     *  Constant: '<S4>/C'
     *  Delay: '<S236>/MemoryX'
     *  Product: '<S288>/Product'
     */
    fractions[i] = rtb_Reshapey[i] - ((ControllerLateral_ConstP.C_Value[i + 2] *
      ControllerLateral_DW->MemoryX_DSTATE[1] +
      ControllerLateral_ConstP.C_Value[i] * ControllerLateral_DW->
      MemoryX_DSTATE[0]) + ControllerLateral_ConstP.C_Value[i + 4] *
      ControllerLateral_DW->MemoryX_DSTATE[2]);
  }

  for (i = 0; i < 3; i++) {
    /* Sum: '<S264>/Add' incorporates:
     *  Delay: '<S236>/MemoryX'
     *  Product: '<S288>/Product2'
     */
    Add_a[i] = (rtb_M[i + 3] * fractions[1] + rtb_M[i] * fractions[0]) +
      ControllerLateral_DW->MemoryX_DSTATE[i];
  }

  /* End of Outputs for SubSystem: '<S264>/Enabled Subsystem' */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant11'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_k != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l4 = Add_a[1];
  }

  if ((ControllerLateral_InstP->LS_signal > 0.0) && ((int32_T)
       ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e <= 0)) {
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l4 = Add_a[1];
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant11'
   */
  if (ControllerLateral_InstP->LS_signal > 0.0) {
    /* Outport: '<Root>/x_speed' incorporates:
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
     */
    ControllerLateral_Y->x_speed =
      ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l4;
  } else {
    /* Outport: '<Root>/x_speed' */
    ControllerLateral_Y->x_speed = Add_a[1];
  }

  /* End of Switch: '<S4>/Switch' */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' incorporates:
   *  Inport: '<Root>/PropulsionOn'
   *  MATLABSystem: '<S4>/Moving Average'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator2_IC_LOADING != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE = Gain3_n;
  }

  if ((ControllerLateral_U->PropulsionOn > 0.0) && ((int32_T)
       ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState <= 0)) {
    ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE = Gain3_n;
  }

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S4>/Constant11'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
   */
  if ((int32_T)ControllerLateral_DW->DiscreteTimeIntegrator3_IC_LOADING != 0) {
    ControllerLateral_DW->DiscreteTimeIntegrator3_DSTATE =
      ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE;
  }

  if ((ControllerLateral_InstP->LS_signal > 0.0) && ((int32_T)
       ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState <= 0)) {
    ControllerLateral_DW->DiscreteTimeIntegrator3_DSTATE =
      ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE;
  }

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant11'
   */
  if (ControllerLateral_InstP->LS_signal > 0.0) {
    /* Outport: '<Root>/x_location' incorporates:
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator3'
     */
    ControllerLateral_Y->x_location =
      ControllerLateral_DW->DiscreteTimeIntegrator3_DSTATE;
  } else {
    /* Outport: '<Root>/x_location' incorporates:
     *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
     */
    ControllerLateral_Y->x_location =
      ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Sum: '<S4>/Add3' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator2'
   */
  rtb_Add3_k = Add_a[0] - ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE;

  /* Gain: '<S323>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S315>/Filter'
   *  Sum: '<S315>/SumD'
   */
  ControllerLateral_B->FilterCoefficient_b = (rtb_Add3_k -
    ControllerLateral_DW->Filter_DSTATE_i4) * 100.0;

  /* Sum: '<S4>/Add' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator'
   *  Gain: '<S325>/Proportional Gain'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/com_spd_x'
   *  Sum: '<S329>/Sum'
   */
  ControllerLateral_B->Add_j = ((5.0 * rtb_Add3_k +
    ControllerLateral_DW->Integrator_DSTATE_nh) +
    ControllerLateral_B->FilterCoefficient_b) +
    ControllerLateral_InstP->kalman_xdotdot_gain *
    ControllerLateral_U->com_spd_x;

  /* Outputs for Enabled SubSystem: '<S257>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S284>/Enable'
   */
  /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S283>:1' */
  ControllerLateral_DW->MeasurementUpdate_MODE = true;
  for (i = 0; i < 2; i++) {
    /* Sum: '<S284>/Sum' incorporates:
     *  Constant: '<S4>/C'
     *  Delay: '<S236>/MemoryX'
     *  Product: '<S284>/C[k]*xhat[k|k-1]'
     */
    fractions[i] = rtb_Reshapey[i] - (ControllerLateral_ConstP.C_Value[i + 4] *
      ControllerLateral_DW->MemoryX_DSTATE[2] +
      (ControllerLateral_ConstP.C_Value[i + 2] *
       ControllerLateral_DW->MemoryX_DSTATE[1] +
       ControllerLateral_ConstP.C_Value[i] *
       ControllerLateral_DW->MemoryX_DSTATE[0]));
  }

  for (i = 0; i < 3; i++) {
    /* Sum: '<S257>/Add' incorporates:
     *  Constant: '<S4>/A'
     *  Delay: '<S236>/MemoryX'
     *  Product: '<S257>/A[k]*xhat[k|k-1]'
     *  Product: '<S284>/Product3'
     */
    ControllerLateral_B->Add_h[i] = (ControllerLateral_ConstP.A_Value[i + 6] *
      ControllerLateral_DW->MemoryX_DSTATE[2] +
      (ControllerLateral_ConstP.A_Value[i + 3] *
       ControllerLateral_DW->MemoryX_DSTATE[1] +
       ControllerLateral_ConstP.A_Value[i] *
       ControllerLateral_DW->MemoryX_DSTATE[0])) + (rtb_L[i + 3] * fractions[1]
      + rtb_L[i] * fractions[0]);
  }

  /* End of Outputs for SubSystem: '<S257>/MeasurementUpdate' */

  /* Gain: '<S317>/Integral Gain' */
  ControllerLateral_B->IntegralGain = 0.0 * rtb_Add3_k;

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
  ExtU_ControllerLateral_T *ControllerLateral_U = (ExtU_ControllerLateral_T *)
    ControllerLateral_M->inputs;
  ExtY_ControllerLateral_T *ControllerLateral_Y = (ExtY_ControllerLateral_T *)
    ControllerLateral_M->outputs;
  real_T tmp;
  int32_T i;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE += 0.00025 *
    ControllerLateral_B->Switch3_h;

  /* Update for Memory: '<S9>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_dc = ControllerLateral_B->OR;

  /* Update for DiscreteIntegrator: '<S339>/Discrete-Time Integrator' */
  ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l += 0.00025 *
    ControllerLateral_B->Add1_b;
  ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    ControllerLateral_B->Equal;

  /* Update for DiscreteIntegrator: '<S338>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S337>/Constant6'
   *  DiscreteIntegrator: '<S338>/Discrete-Time Integrator'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE += 0.00025 *
    ControllerLateral_B->Add;
  if (ControllerLateral_InstP->ResetComplementary > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)1;
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)1;
  } else {
    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)-1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)2;
    }

    if (ControllerLateral_InstP->ResetComplementary < 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)-1;
    } else if (ControllerLateral_InstP->ResetComplementary == 0.0) {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)0;
    } else {
      ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_l = (int8_T)2;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S338>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S338>/Discrete-Time Integrator' */
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
  for (i = 0; i < 799; i++) {
    ControllerLateral_DW->Delay1_DSTATE_b[i] =
      ControllerLateral_DW->Delay1_DSTATE_b[i + 1];
  }

  ControllerLateral_DW->Delay1_DSTATE_b[799] = ControllerLateral_B->Product1;

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
   *  DiscreteIntegrator: '<S339>/Discrete-Time Integrator'
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

  /* Update for Memory: '<S346>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput = ControllerLateral_B->Gain9;

  /* Update for Memory: '<S346>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput = ControllerLateral_B->Gain10;

  /* Update for Memory: '<S345>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_k = ControllerLateral_B->Gain3_i;

  /* Update for Memory: '<S345>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_n = ControllerLateral_B->Gain10_c;

  /* Update for DiscreteIntegrator: '<S434>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_nb += 0.00025 *
    ControllerLateral_B->Switch_bb;

  /* Update for DiscreteIntegrator: '<S429>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_l += 0.00025 *
    ControllerLateral_B->FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S384>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_p += 0.00025 *
    ControllerLateral_B->Switch_b;

  /* Update for DiscreteIntegrator: '<S379>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_d += 0.00025 *
    ControllerLateral_B->FilterCoefficient_d;

  /* Update for Memory: '<S451>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_l = ControllerLateral_B->Gain2;

  /* Update for Memory: '<S451>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_d = ControllerLateral_B->Gain10_o;

  /* Update for Memory: '<S452>/Memory' */
  ControllerLateral_DW->Memory_PreviousInput_d = ControllerLateral_B->Gain3_i;

  /* Update for Memory: '<S452>/Memory1' */
  ControllerLateral_DW->Memory1_PreviousInput_g = ControllerLateral_B->Gain10_o4;

  /* Update for DiscreteIntegrator: '<S490>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_h += 0.00025 *
    ControllerLateral_B->Switch_g;

  /* Update for DiscreteIntegrator: '<S485>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_i += 0.00025 *
    ControllerLateral_B->FilterCoefficient_l;

  /* Update for Delay: '<S236>/MemoryP' */
  ControllerLateral_DW->icLoad = false;
  memcpy(&ControllerLateral_DW->MemoryP_DSTATE[0], &ControllerLateral_B->SNew[0],
         9U * sizeof(real_T));

  /* Update for Delay: '<S236>/MemoryX' */
  ControllerLateral_DW->icLoad_m = false;
  ControllerLateral_DW->MemoryX_DSTATE[0] = ControllerLateral_B->Add_h[0];
  ControllerLateral_DW->MemoryX_DSTATE[1] = ControllerLateral_B->Add_h[1];
  ControllerLateral_DW->MemoryX_DSTATE[2] = ControllerLateral_B->Add_h[2];

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant11'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_k = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l4 += 0.00025 *
    ControllerLateral_B->Gain_f;
  if (ControllerLateral_InstP->LS_signal > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e = (int8_T)1;
  } else if (ControllerLateral_InstP->LS_signal < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e = (int8_T)-1;
  } else if (ControllerLateral_InstP->LS_signal == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' incorporates:
   *  Inport: '<Root>/PropulsionOn'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator2_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE += 0.00025 *
    ControllerLateral_B->Add_j;
  if (ControllerLateral_U->PropulsionOn > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState = (int8_T)1;
  } else if (ControllerLateral_U->PropulsionOn < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState = (int8_T)-1;
  } else if (ControllerLateral_U->PropulsionOn == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S4>/Constant11'
   *  Outport: '<Root>/x_speed'
   */
  ControllerLateral_DW->DiscreteTimeIntegrator3_IC_LOADING = (uint8_T)0U;
  ControllerLateral_DW->DiscreteTimeIntegrator3_DSTATE += 0.00025 *
    ControllerLateral_Y->x_speed;
  if (ControllerLateral_InstP->LS_signal > 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState = (int8_T)1;
  } else if (ControllerLateral_InstP->LS_signal < 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState = (int8_T)-1;
  } else if (ControllerLateral_InstP->LS_signal == 0.0) {
    ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState = (int8_T)0;
  } else {
    ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S320>/Integrator' */
  ControllerLateral_DW->Integrator_DSTATE_nh += 0.00025 *
    ControllerLateral_B->IntegralGain;

  /* Update for DiscreteIntegrator: '<S315>/Filter' */
  ControllerLateral_DW->Filter_DSTATE_i4 += 0.00025 *
    ControllerLateral_B->FilterCoefficient_b;

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

  {
    real_T varargin_2;
    boolean_T flag;

    /* Constant: '<S342>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pnaevvfpg);

    /* Constant: '<S340>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pnaevv);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pnaevvf);

    /* Constant: '<S343>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);

    /* Constant: '<S341>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pnaevvf);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pnaevvfp);

    /* Constant: '<S22>/Constant' */
    ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage1);
    ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage);

    /* Constant: '<S23>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_p);
    ControllerLateral_MovingAverage_Start(&ControllerLateral_DW->MovingAverage_p);

    /* Constant: '<S24>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pn);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pn);

    /* Constant: '<S25>/Constant' */
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage1_pna);
    ControllerLateral_MovingAverage_Start
      (&ControllerLateral_DW->MovingAverage_pna);

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
      (&ControllerLateral_DW->MovingAverage_pnaev);
    ControllerLateral_MovingAverage1_Start
      (&ControllerLateral_DW->MovingAverage1_pnaev);

    /* Start for MATLABSystem: '<S4>/Moving Average' */
    ControllerLateral_DW->obj_a.matlabCodegenIsDeleted = true;
    ControllerLateral_DW->obj_a.isInitialized = 0;
    ControllerLateral_DW->obj_a.NumChannels = -1;
    ControllerLateral_DW->obj_a.matlabCodegenIsDeleted = false;
    ControllerLateral_DW->objisempty_l = true;
    flag = (boolean_T)(ControllerLateral_DW->obj_a.isInitialized == 1);
    if (flag) {
      ControllerLateral_DW->obj_a.TunablePropsChanged = true;
    }

    ControllerLateral_DW->obj_a.ForgettingFactor = 0.9;
    ControllerLateral_DW->obj_a.isSetupComplete = false;
    ControllerLateral_DW->obj_a.isInitialized = 1;
    ControllerLateral_DW->obj_a.NumChannels = 1;
    varargin_2 = ControllerLateral_DW->obj_a.ForgettingFactor;
    ControllerLateral_DW->obj_a._pobj0.isInitialized = 0;
    flag = (boolean_T)(ControllerLateral_DW->obj_a._pobj0.isInitialized == 1);
    if (flag) {
      ControllerLateral_DW->obj_a._pobj0.TunablePropsChanged = true;
    }

    ControllerLateral_DW->obj_a._pobj0.ForgettingFactor = varargin_2;
    ControllerLateral_DW->obj_a.pStatistic = &ControllerLateral_DW->obj_a._pobj0;
    ControllerLateral_DW->obj_a.isSetupComplete = true;
    ControllerLateral_DW->obj_a.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S4>/Moving Average' */

    /* Start for Enabled SubSystem: '<S264>/Enabled Subsystem' */
    ControllerLateral_DW->EnabledSubsystem_MODE = false;

    /* End of Start for SubSystem: '<S264>/Enabled Subsystem' */

    /* Start for Enabled SubSystem: '<S257>/MeasurementUpdate' */
    ControllerLateral_DW->MeasurementUpdate_MODE = false;

    /* End of Start for SubSystem: '<S257>/MeasurementUpdate' */
  }

  {
    c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj_0;
    c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE = 0.0;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_dc = false;

    /* InitializeConditions for DiscreteIntegrator: '<S339>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S338>/Discrete-Time Integrator1' */
    ControllerLateral_DW->DiscreteTimeIntegrator1_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator1_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S338>/Discrete-Time Integrator' */
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
    for (i = 0; i < 800; i++) {
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

    /* InitializeConditions for Memory: '<S346>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput = 0.0;

    /* InitializeConditions for Memory: '<S346>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput = 0.0;

    /* InitializeConditions for Memory: '<S345>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_k = 0.0;

    /* InitializeConditions for Memory: '<S345>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_n = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S434>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_nb = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S429>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_l = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S384>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_p = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S379>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;

    /* InitializeConditions for Memory: '<S451>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_l = 0.0;

    /* InitializeConditions for Memory: '<S451>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_d = 0.0;

    /* InitializeConditions for Memory: '<S452>/Memory' */
    ControllerLateral_DW->Memory_PreviousInput_d = 0.0;

    /* InitializeConditions for Memory: '<S452>/Memory1' */
    ControllerLateral_DW->Memory1_PreviousInput_g = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S490>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_h = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S485>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_i = 0.0;

    /* InitializeConditions for Delay: '<S236>/MemoryP' */
    ControllerLateral_DW->icLoad = true;

    /* InitializeConditions for Delay: '<S236>/MemoryX' */
    ControllerLateral_DW->icLoad_m = true;

    /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    ControllerLateral_DW->DiscreteTimeIntegrator_PrevResetState_e = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator_IC_LOADING_k = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
    ControllerLateral_DW->DiscreteTimeIntegrator2_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator2_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */
    ControllerLateral_DW->DiscreteTimeIntegrator3_PrevResetState = (int8_T)2;
    ControllerLateral_DW->DiscreteTimeIntegrator3_IC_LOADING = (uint8_T)1U;

    /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
    ControllerLateral_DW->Integrator_DSTATE_nh = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S315>/Filter' */
    ControllerLateral_DW->Filter_DSTATE_i4 = 0.0;

    /* SystemInitialize for MATLAB Function: '<Root>/Lane Switch Transition1' */
    ControllerLateral_DW->mode_old_not_empty = false;
    ControllerLateral_DW->t_old = -1000.0;
    ControllerLateral_DW->mode_memory_old = -1.0;
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevv);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvf);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage1_pnaevvf);
    ControllerLateral_MovingAverage_Init
      (&ControllerLateral_DW->MovingAverage_pnaevvfp);
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
      (&ControllerLateral_DW->MovingAverage_pnaev);
    ControllerLateral_MovingAverage1_Init
      (&ControllerLateral_DW->MovingAverage1_pnaev);

    /* InitializeConditions for MATLABSystem: '<S4>/Moving Average' */
    obj_0 = ControllerLateral_DW->obj_a.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pwN = 1.0;
      obj_0->pmN = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S4>/Moving Average' */
  }
}

/* Model terminate function */
void ControllerLateral_terminate(RT_MODEL_ControllerLateral_T
  * ControllerLateral_M)
{
  DW_ControllerLateral_T *ControllerLateral_DW = ControllerLateral_M->dwork;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *obj_0;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *obj;
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvfp);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpg);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevv);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvf);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvfpg);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfpgh);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage1_pnaevvf);
  ControllerLateral_MovingAverage_Term
    (&ControllerLateral_DW->MovingAverage_pnaevvfp);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_p);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_p);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_pn);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_pn);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage1_pna);
  ControllerLateral_MovingAverage_Term(&ControllerLateral_DW->MovingAverage_pna);

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
    (&ControllerLateral_DW->MovingAverage_pnaev);
  ControllerLateral_MovingAverage1_Term
    (&ControllerLateral_DW->MovingAverage1_pnaev);

  /* Terminate for MATLABSystem: '<S4>/Moving Average' */
  if (!(int32_T)ControllerLateral_DW->obj_a.matlabCodegenIsDeleted) {
    ControllerLateral_DW->obj_a.matlabCodegenIsDeleted = true;
    if ((ControllerLateral_DW->obj_a.isInitialized == 1) && ((int32_T)
         ControllerLateral_DW->obj_a.isSetupComplete)) {
      obj_0 = ControllerLateral_DW->obj_a.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      ControllerLateral_DW->obj_a.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Moving Average' */

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
      int32_T i;
      for (i = 0; i < 9; i++) {
        ControllerLateral_B->SNew[i] = 0.0;
      }

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
      ControllerLateral_B->Gain2 = 0.0;
      ControllerLateral_B->Gain9 = 0.0;
      ControllerLateral_B->Gain10 = 0.0;
      ControllerLateral_B->Gain3_i = 0.0;
      ControllerLateral_B->Gain10_c = 0.0;
      ControllerLateral_B->FilterCoefficient = 0.0;
      ControllerLateral_B->Add = 0.0;
      ControllerLateral_B->FilterCoefficient_d = 0.0;
      ControllerLateral_B->Add1 = 0.0;
      ControllerLateral_B->Switch_b = 0.0;
      ControllerLateral_B->Switch_bb = 0.0;
      ControllerLateral_B->Gain10_o = 0.0;
      ControllerLateral_B->Gain10_o4 = 0.0;
      ControllerLateral_B->FilterCoefficient_l = 0.0;
      ControllerLateral_B->Add1_b = 0.0;
      ControllerLateral_B->Switch_g = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[0] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay2Inport1[1] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[0] = 0.0;
      ControllerLateral_B->TmpSignalConversionAtDelay1Inport1[1] = 0.0;
      ControllerLateral_B->Gain_f = 0.0;
      ControllerLateral_B->FilterCoefficient_b = 0.0;
      ControllerLateral_B->Add_j = 0.0;
      ControllerLateral_B->Add_h[0] = 0.0;
      ControllerLateral_B->Add_h[1] = 0.0;
      ControllerLateral_B->Add_h[2] = 0.0;
      ControllerLateral_B->IntegralGain = 0.0;
      ControllerLateral_B->Switch3_h = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvfpg.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpgh.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvfp.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfpg.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvfp.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaevv.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage_pnaevvf.MovingAverage = 0.0;
      ControllerLateral_B->MovingAverage1_pnaev.MovingAverage1 = 0.0;
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
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator1_DSTATE = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_d = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[0] = 0.0;
    ControllerLateral_DW->Delay1_DSTATE[1] = 0.0;
    ControllerLateral_DW->DelayInput1_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_DSTATE = 0.0;
    ControllerLateral_DW->UD_DSTATE = 0.0;

    {
      int32_T i;
      for (i = 0; i < 800; i++) {
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
    ControllerLateral_DW->Integrator_DSTATE_nb = 0.0;
    ControllerLateral_DW->Filter_DSTATE_l = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_p = 0.0;
    ControllerLateral_DW->Filter_DSTATE_d = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_h = 0.0;
    ControllerLateral_DW->Filter_DSTATE_i = 0.0;

    {
      int32_T i;
      for (i = 0; i < 9; i++) {
        ControllerLateral_DW->MemoryP_DSTATE[i] = 0.0;
      }
    }

    ControllerLateral_DW->MemoryX_DSTATE[0] = 0.0;
    ControllerLateral_DW->MemoryX_DSTATE[1] = 0.0;
    ControllerLateral_DW->MemoryX_DSTATE[2] = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator_DSTATE_l4 = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator2_DSTATE = 0.0;
    ControllerLateral_DW->DiscreteTimeIntegrator3_DSTATE = 0.0;
    ControllerLateral_DW->Integrator_DSTATE_nh = 0.0;
    ControllerLateral_DW->Filter_DSTATE_i4 = 0.0;
    ControllerLateral_DW->Memory_PreviousInput = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_k = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_n = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_l = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_d = 0.0;
    ControllerLateral_DW->Memory_PreviousInput_d = 0.0;
    ControllerLateral_DW->Memory1_PreviousInput_g = 0.0;
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
    ControllerLateral_U->IMU_yaw = 0.0;
    ControllerLateral_U->CoM_y_dot = 0.0;
    ControllerLateral_U->com_acc_x = 0.0;
    ControllerLateral_U->PropulsionOn = 0.0;
    ControllerLateral_U->com_spd_x = 0.0;

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
    ControllerLateral_Y->Complementary_A = 0.0;
    ControllerLateral_Y->Complementary_C = 0.0;
    ControllerLateral_Y->Inertia = 0.0;
    ControllerLateral_Y->x_speed = 0.0;
    ControllerLateral_Y->x_location = 0.0;

    /* previous zero-crossing states */
    {
      ControllerLateral_PrevZCX->UD_Reset_ZCE = UNINITIALIZED_ZCSIG;
      ControllerLateral_PrevZCX->UD_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    }
  }

  return ControllerLateral_M;
}
