/*
 * PIDcontroller4CoreCentralizedTestReadyMotor.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIDcontroller4CoreCentralizedTestReadyMotor".
 *
 * Model version              : 6.240
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon May 20 17:30:36 2024
 *
 * Target selection: pmp.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIDcontroller4CoreCentralizedTestReadyMotor.h"
#include "PIDcontroller4CoreCentralizedTestReadyMotor_private.h"

/* Forward declaration for local functions */
static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *obj);

/* Forward declaration for local functions */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2(int32_T n, const
  real_T x[12], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3(real_T A[12],
  real_T tau[3], int32_T jpvt[3]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm(const real_T x[3]);

/* Forward declaration for local functions */
static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o1_T
   *obj);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_l(int32_T n,
  const real_T x[12], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_i(real_T A[12],
  real_T tau[3], int32_T jpvt[3]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm_l(const real_T x
  [3]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_c(int32_T n,
  const real_T x[9], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal(int32_T n, real_T
  a, real_T x[9], int32_T ix0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_ci(int32_T n,
  const real_T x[3], int32_T ix0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(int32_T n, const
  real_T x[9], int32_T ix0, const real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(int32_T n, real_T
  a, int32_T ix0, real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_j(int32_T n,
  real_T a, real_T x[3], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_p(int32_T n,
  real_T a, const real_T x[9], int32_T ix0, real_T y[3], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_pe(int32_T n,
  real_T a, const real_T x[3], int32_T ix0, real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(real_T a,
  real_T x[9], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(real_T *a, real_T *
  b, real_T *c, real_T *s);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot(real_T x[9],
  int32_T ix0, int32_T iy0, real_T c, real_T s);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap(real_T x[9],
  int32_T ix0, int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd(const real_T A[9],
  real_T U[9], real_T s[3], real_T V[9]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic(int32_T n,
  const real_T x[27], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv(int32_T m, int32_T
  n, const real_T A[27], int32_T ia0, const real_T x[27], int32_T ix0, real_T y
  [3]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc(int32_T m, int32_T
  n, real_T alpha1, int32_T ix0, const real_T y[3], real_T A[27], int32_T ia0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor(const real_T A
  [18], const real_T S[36], const real_T Ns[9], real_T b_S[9]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve(const real_T A
  [9], real_T B[18]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_e(const real_T
  A[9], real_T B[18]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cica(int32_T n,
  const real_T x[54], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_f(int32_T m,
  int32_T n, const real_T A[54], int32_T ia0, const real_T x[54], int32_T ix0,
  real_T y[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_o(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[6], real_T A[54],
  int32_T ia0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf(real_T A[54],
  real_T tau[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr(const real_T A[54],
  real_T Q[54], real_T R[36]);
static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
   *obj, real_T u);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i(int32_T n,
  const real_T x[36], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_m(int32_T n,
  real_T a, real_T x[36], int32_T ix0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_n(int32_T n,
  const real_T x[36], int32_T ix0, const real_T y[36], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_d(int32_T n,
  real_T a, int32_T ix0, real_T y[36], int32_T iy0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4(int32_T n,
  const real_T x[6], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(real_T a,
  real_T x[36], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mc(int32_T n,
  real_T a, real_T x[6], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dt(int32_T n,
  real_T a, const real_T x[36], int32_T ix0, real_T y[6], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dtk(int32_T n,
  real_T a, const real_T x[6], int32_T ix0, real_T y[36], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(real_T x[36],
  int32_T ix0, int32_T iy0, real_T c, real_T s);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap_f(real_T x[36],
  int32_T ix0, int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd_a(const real_T A[36],
  real_T U[36], real_T s[6], real_T V[36]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_ssTF_vertical_kalman_leo
  (real_T x[6], const real_T u[12]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4w(int32_T n,
  const real_T x[72], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_d(int32_T m,
  int32_T n, const real_T A[72], int32_T ia0, const real_T x[72], int32_T ix0,
  real_T y[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_h(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[6], real_T A[72],
  int32_T ia0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_j(real_T A[72],
  real_T tau[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr_b(const real_T A[72],
  real_T Q[72], real_T R[36]);
static void
  PIDcontroller4CoreCentralizedTestReadyMotor_EKFPredictorAdditive_predict(const
  real_T Qs[36], real_T x[6], real_T S[36], const real_T varargin_1[12]);
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

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

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

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
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

static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *obj)
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
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S26>/Moving Average' */
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
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  /* Start for MATLABSystem: '<S26>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup(&localDW->obj);
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
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(real_T rtu_0,
  real_T rtu_1, B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *localB, DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  real_T lambda;
  real_T pmLocal;
  real_T varargin_1;
  boolean_T p;

  /* MATLABSystem: '<S26>/Moving Average' */
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

  /* MATLABSystem: '<S26>/Moving Average' */
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
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* Terminate for MATLABSystem: '<S26>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S26>/Moving Average' */
}

/* Function for MATLAB Function: '<S38>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2(int32_T n, const
  real_T x[12], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
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

  return y;
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

/* Function for MATLAB Function: '<S38>/FindCoordinates' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3(real_T A[12],
  real_T tau[3], int32_T jpvt[3])
{
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  real_T absxk;
  real_T scale;
  real_T smax;
  real_T t;
  int32_T b_ix;
  int32_T c_ix;
  int32_T exitg1;
  int32_T g;
  int32_T ia;
  int32_T iac;
  int32_T ii;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T pvt;
  boolean_T exitg2;
  jpvt[0] = 1;
  tau[0] = 0.0;
  work[0] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  for (pvt = 1; pvt < 5; pvt++) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }
  }

  vn1[0] = scale * sqrt(smax);
  vn2[0] = vn1[0];
  jpvt[1] = 2;
  tau[1] = 0.0;
  work[1] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  while (pvt <= 8) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }

    pvt++;
  }

  vn1[1] = scale * sqrt(smax);
  vn2[1] = vn1[1];
  jpvt[2] = 3;
  tau[2] = 0.0;
  work[2] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  while (pvt <= 12) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }

    pvt++;
  }

  vn1[2] = scale * sqrt(smax);
  vn2[2] = vn1[2];
  for (k = 0; k < 3; k++) {
    iy = k << 2;
    ii = iy + k;
    pvt = 0;
    if (3 - k > 1) {
      ix = k;
      smax = fabs(vn1[k]);
      for (b_ix = 2; b_ix <= 3 - k; b_ix++) {
        ix++;
        scale = fabs(vn1[ix]);
        if (scale > smax) {
          pvt = b_ix - 1;
          smax = scale;
        }
      }
    }

    pvt += k;
    if (pvt != k) {
      b_ix = pvt << 2;
      smax = A[b_ix];
      A[b_ix] = A[iy];
      A[iy] = smax;
      smax = A[b_ix + 1];
      A[b_ix + 1] = A[iy + 1];
      A[iy + 1] = smax;
      smax = A[b_ix + 2];
      A[b_ix + 2] = A[iy + 2];
      A[iy + 2] = smax;
      smax = A[b_ix + 3];
      A[b_ix + 3] = A[iy + 3];
      A[iy + 3] = smax;
      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[k];
      jpvt[k] = ix;
      vn1[pvt] = vn1[k];
      vn2[pvt] = vn2[k];
    }

    smax = A[ii];
    tau[k] = 0.0;
    scale = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2(3 - k, A, ii + 2);
    if (scale != 0.0) {
      scale = rt_hypotd_snf(A[ii], scale);
      if (A[ii] >= 0.0) {
        scale = -scale;
      }

      if (fabs(scale) < 1.0020841800044864E-292) {
        pvt = 0;
        do {
          pvt++;
          ix = (ii - k) + 4;
          for (b_ix = ii + 1; b_ix < ix; b_ix++) {
            A[b_ix] *= 9.9792015476736E+291;
          }

          scale *= 9.9792015476736E+291;
          smax *= 9.9792015476736E+291;
        } while ((fabs(scale) < 1.0020841800044864E-292) && (pvt < 20));

        scale = rt_hypotd_snf(smax,
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2
                              (3 - k, A, ii + 2));
        if (smax >= 0.0) {
          scale = -scale;
        }

        tau[k] = (scale - smax) / scale;
        smax = 1.0 / (smax - scale);
        for (b_ix = ii + 1; b_ix < ix; b_ix++) {
          A[b_ix] *= smax;
        }

        for (ix = 0; ix < pvt; ix++) {
          scale *= 1.0020841800044864E-292;
        }

        smax = scale;
      } else {
        tau[k] = (scale - A[ii]) / scale;
        smax = 1.0 / (A[ii] - scale);
        pvt = (ii - k) + 4;
        for (ix = ii + 1; ix < pvt; ix++) {
          A[ix] *= smax;
        }

        smax = scale;
      }
    }

    A[ii] = smax;
    if (k + 1 < 3) {
      smax = A[ii];
      A[ii] = 1.0;
      if (tau[k] != 0.0) {
        pvt = 4 - k;
        ix = (ii - k) + 3;
        while ((pvt > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        ix = 1 - k;
        exitg2 = false;
        while ((!exitg2) && (ix + 1 > 0)) {
          b_ix = ((ix << 2) + ii) + 4;
          iy = b_ix;
          do {
            exitg1 = 0;
            if (iy + 1 <= b_ix + pvt) {
              if (A[iy] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              ix--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 0;
        ix = -1;
      }

      if (pvt > 0) {
        if (ix + 1 != 0) {
          for (b_ix = 0; b_ix <= ix; b_ix++) {
            work[b_ix] = 0.0;
          }

          b_ix = 0;
          iy = ((ix << 2) + ii) + 5;
          for (iac = ii + 5; iac <= iy; iac += 4) {
            c_ix = ii;
            scale = 0.0;
            g = (iac + pvt) - 1;
            for (ia = iac; ia <= g; ia++) {
              scale += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[b_ix] += scale;
            b_ix++;
          }
        }

        if (!(-tau[k] == 0.0)) {
          b_ix = ii + 4;
          iy = 0;
          for (iac = 0; iac <= ix; iac++) {
            if (work[iy] != 0.0) {
              scale = work[iy] * -tau[k];
              c_ix = ii;
              g = pvt + b_ix;
              for (ia = b_ix; ia < g; ia++) {
                A[ia] += A[c_ix] * scale;
                c_ix++;
              }
            }

            iy++;
            b_ix += 4;
          }
        }
      }

      A[ii] = smax;
    }

    for (ii = k + 1; ii + 1 < 4; ii++) {
      pvt = (ii << 2) + k;
      if (vn1[ii] != 0.0) {
        smax = fabs(A[pvt]) / vn1[ii];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        scale = vn1[ii] / vn2[ii];
        scale = scale * scale * smax;
        if (scale <= 1.4901161193847656E-8) {
          vn1[ii] = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2(3 - k, A,
            pvt + 2);
          vn2[ii] = vn1[ii];
        } else {
          vn1[ii] *= sqrt(smax);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S38>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/*
 * Output and update for atomic system:
 *    '<S38>/FindCoordinates'
 *    '<S39>/FindCoordinates'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(real_T rtu_z,
  real_T rtu_z_b, real_T rtu_z_l, real_T rtu_z_j, real_T rtu_hl, real_T rtu_hw,
  real_T rtu_l_offset,
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  real_T A[12];
  real_T zz[4];
  real_T C[3];
  real_T X[3];
  real_T Y[3];
  real_T avg_g_tmp;
  real_T avg_g_tmp_0;
  real_T avg_g_tmp_1;
  real_T tol;
  int32_T jpvt[3];
  int32_T C_tmp;
  int32_T c_i;
  int32_T rankA;

  /* MATLAB Function 'Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/FindCoordinates': '<S47>:1' */
  /* '<S47>:1:5' */
  /* '<S47>:1:6' */
  /* '<S47>:1:8' */
  /* '<S47>:1:11' */
  A[0] = rtu_hl;
  A[4] = -rtu_hw;
  A[8] = 1.0;
  A[1] = -rtu_hl;
  A[5] = -rtu_hw;
  A[9] = 1.0;
  A[2] = rtu_hl;
  A[6] = rtu_hw;
  A[10] = 1.0;
  A[3] = -rtu_hl;
  A[7] = rtu_hw;
  A[11] = 1.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3(A, X, jpvt);
  rankA = 0;
  tol = 8.8817841970012523E-15 * fabs(A[0]);
  while ((rankA < 3) && (!(fabs(A[(rankA << 2) + rankA]) <= tol))) {
    rankA++;
  }

  /* SignalConversion generated from: '<S47>/ SFunction ' */
  zz[0] = rtu_z / 1000.0;
  zz[2] = rtu_z_b / 1000.0;
  zz[1] = rtu_z_l / 1000.0;
  zz[3] = rtu_z_j / 1000.0;
  C[0] = 0.0;
  if (X[0] != 0.0) {
    tol = zz[0];
    for (c_i = 1; c_i + 1 < 5; c_i++) {
      tol += A[c_i] * zz[c_i];
    }

    tol *= X[0];
    if (tol != 0.0) {
      zz[0] -= tol;
      for (c_i = 1; c_i + 1 < 5; c_i++) {
        zz[c_i] -= A[c_i] * tol;
      }
    }
  }

  C[1] = 0.0;
  if (X[1] != 0.0) {
    tol = zz[1];
    for (c_i = 2; c_i + 1 < 5; c_i++) {
      tol += A[c_i + 4] * zz[c_i];
    }

    tol *= X[1];
    if (tol != 0.0) {
      zz[1] -= tol;
      for (c_i = 2; c_i + 1 < 5; c_i++) {
        zz[c_i] -= A[c_i + 4] * tol;
      }
    }
  }

  C[2] = 0.0;
  if (X[2] != 0.0) {
    tol = zz[2];
    for (c_i = 3; c_i + 1 < 5; c_i++) {
      tol += A[c_i + 8] * zz[c_i];
    }

    tol *= X[2];
    if (tol != 0.0) {
      zz[2] -= tol;
      for (c_i = 3; c_i + 1 < 5; c_i++) {
        zz[c_i] -= A[c_i + 8] * tol;
      }
    }
  }

  for (c_i = 0; c_i < rankA; c_i++) {
    C[jpvt[c_i] - 1] = zz[c_i];
  }

  for (rankA--; rankA + 1 > 0; rankA--) {
    C_tmp = rankA << 2;
    C[jpvt[rankA] - 1] /= A[C_tmp + rankA];
    for (c_i = 0; c_i < rankA; c_i++) {
      C[jpvt[c_i] - 1] -= A[C_tmp + c_i] * C[jpvt[rankA] - 1];
    }
  }

  /* '<S47>:1:16' */
  /* '<S47>:1:17' */
  /* '<S47>:1:18' */
  /* '<S47>:1:21' */
  X[0] = 1.0;
  X[1] = 0.0;
  X[2] = C[0];

  /* '<S47>:1:22' */
  /* '<S47>:1:23' */
  Y[0] = 0.0;
  Y[1] = 1.0;
  Y[2] = C[1];

  /* '<S47>:1:24' */
  /* '<S47>:1:33' */
  /* '<S47>:1:34' */
  /* '<S47>:1:43' */
  /* '<S47>:1:44' */
  tol = (rtu_hl - rtu_l_offset) * C[0];
  avg_g_tmp = C[1] * -rtu_hw;
  avg_g_tmp_0 = (-rtu_hl + rtu_l_offset) * C[0];
  avg_g_tmp_1 = C[1] * rtu_hw;
  localB->avg_g = (((((tol + avg_g_tmp) + C[2]) * 1000.0 + ((tol + avg_g_tmp_1)
    + C[2]) * 1000.0) + ((avg_g_tmp_0 + avg_g_tmp) + C[2]) * 1000.0) +
                   ((avg_g_tmp_0 + avg_g_tmp_1) + C[2]) * 1000.0) / 4.0;
  if (-C[0] < 0.0) {
    tol = -1.0;
  } else if (-C[0] > 0.0) {
    tol = 1.0;
  } else if (-C[0] == 0.0) {
    tol = 0.0;
  } else {
    tol = (rtNaN);
  }

  localB->pitch = acos(1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm(X))
    * tol;
  if (-C[1] < 0.0) {
    tol = -1.0;
  } else if (-C[1] > 0.0) {
    tol = 1.0;
  } else if (-C[1] == 0.0) {
    tol = 0.0;
  } else {
    tol = (rtNaN);
  }

  localB->roll = acos(-(-1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm
                        (Y))) * tol;
}

/*
 * Termination for atomic system:
 *    '<S38>/FindCoordinates'
 *    '<S39>/FindCoordinates'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates_Term(void)
{
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 49; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  /* Start for MATLABSystem: '<S3>/Moving Average' */
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
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T *localB,
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  real_T csumrev[49];
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S3>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 49; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 49; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 49; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  csum += rtu_0;
  z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 49.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 47; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  obj->pCumSum = csum;
  for (i = 0; i < 49; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<S3>/Moving Average' */
  localB->MovingAverage = z / 50.0;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* Terminate for MATLABSystem: '<S3>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S3>/Moving Average' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW)
{
  real_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  flag = (boolean_T)(localDW->obj.isInitialized == 1);
  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.ForgettingFactor = 0.999;
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

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(const real_T
  rtu_0[3], B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
  *localB, DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
  *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  real_T b;
  real_T c;
  real_T lambda;
  boolean_T flag;

  /* MATLABSystem: '<Root>/Moving Average' */
  if (localDW->obj.ForgettingFactor != 0.999) {
    flag = (boolean_T)(localDW->obj.isInitialized == 1);
    if (flag) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = 0.999;
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

  b = obj->pwN;
  c = obj->pmN;
  lambda = obj->plambda;
  c = (1.0 - 1.0 / b) * c + 1.0 / b * rtu_0[0];
  b = lambda * b + 1.0;

  /* MATLABSystem: '<Root>/Moving Average' */
  localB->MovingAverage[0] = c;

  /* MATLABSystem: '<Root>/Moving Average' */
  c = (1.0 - 1.0 / b) * c + 1.0 / b * rtu_0[1];
  b = lambda * b + 1.0;

  /* MATLABSystem: '<Root>/Moving Average' */
  localB->MovingAverage[1] = c;

  /* MATLABSystem: '<Root>/Moving Average' */
  c = (1.0 - 1.0 / b) * c + 1.0 / b * rtu_0[2];
  obj->pwN = lambda * b + 1.0;
  obj->pmN = c;

  /* MATLABSystem: '<Root>/Moving Average' */
  localB->MovingAverage[2] = c;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average' */
}

/*
 * Output and update for atomic system:
 *    '<S22>/Cap requested current1'
 *    '<S22>/Cap requested current2'
 *    '<S22>/Cap requested current3'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(real_T
  rtu_measured_I, real_T rtu_requested_I, real_T rtu_max_delta,
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  /* MATLAB Function 'Subsystem5/Cap requested current1': '<S743>:1' */
  if (rtu_requested_I - rtu_measured_I > rtu_max_delta) {
    /* '<S743>:1:4' */
    /* '<S743>:1:5' */
    localB->out_req_I = rtu_measured_I + rtu_max_delta;
  } else if (rtu_measured_I - rtu_requested_I > rtu_max_delta) {
    /* '<S743>:1:6' */
    /* '<S743>:1:7' */
    localB->out_req_I = rtu_measured_I - rtu_max_delta;
  } else {
    /* '<S743>:1:9' */
    localB->out_req_I = rtu_requested_I;
  }
}

/*
 * Termination for atomic system:
 *    '<S22>/Cap requested current1'
 *    '<S22>/Cap requested current2'
 *    '<S22>/Cap requested current3'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1_Term(void)
{
}

static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o1_T
   *obj)
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
  obj->NumChannels = 4;
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

/* Function for MATLAB Function: '<S410>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_l(int32_T n,
  const real_T x[12], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
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

  return y;
}

/* Function for MATLAB Function: '<S410>/FindCoordinates' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_i(real_T A[12],
  real_T tau[3], int32_T jpvt[3])
{
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  real_T absxk;
  real_T scale;
  real_T smax;
  real_T t;
  int32_T b_ix;
  int32_T c_ix;
  int32_T exitg1;
  int32_T g;
  int32_T ia;
  int32_T iac;
  int32_T ii;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T pvt;
  boolean_T exitg2;
  jpvt[0] = 1;
  tau[0] = 0.0;
  work[0] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  for (pvt = 1; pvt < 5; pvt++) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }
  }

  vn1[0] = scale * sqrt(smax);
  vn2[0] = vn1[0];
  jpvt[1] = 2;
  tau[1] = 0.0;
  work[1] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  while (pvt <= 8) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }

    pvt++;
  }

  vn1[1] = scale * sqrt(smax);
  vn2[1] = vn1[1];
  jpvt[2] = 3;
  tau[2] = 0.0;
  work[2] = 0.0;
  smax = 0.0;
  scale = 3.3121686421112381E-170;
  while (pvt <= 12) {
    absxk = fabs(A[pvt - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      smax = smax * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      smax += t * t;
    }

    pvt++;
  }

  vn1[2] = scale * sqrt(smax);
  vn2[2] = vn1[2];
  for (k = 0; k < 3; k++) {
    iy = k << 2;
    ii = iy + k;
    pvt = 0;
    if (3 - k > 1) {
      ix = k;
      smax = fabs(vn1[k]);
      for (b_ix = 2; b_ix <= 3 - k; b_ix++) {
        ix++;
        scale = fabs(vn1[ix]);
        if (scale > smax) {
          pvt = b_ix - 1;
          smax = scale;
        }
      }
    }

    pvt += k;
    if (pvt != k) {
      b_ix = pvt << 2;
      smax = A[b_ix];
      A[b_ix] = A[iy];
      A[iy] = smax;
      smax = A[b_ix + 1];
      A[b_ix + 1] = A[iy + 1];
      A[iy + 1] = smax;
      smax = A[b_ix + 2];
      A[b_ix + 2] = A[iy + 2];
      A[iy + 2] = smax;
      smax = A[b_ix + 3];
      A[b_ix + 3] = A[iy + 3];
      A[iy + 3] = smax;
      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[k];
      jpvt[k] = ix;
      vn1[pvt] = vn1[k];
      vn2[pvt] = vn2[k];
    }

    smax = A[ii];
    tau[k] = 0.0;
    scale = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_l(3 - k, A, ii + 2);
    if (scale != 0.0) {
      scale = rt_hypotd_snf(A[ii], scale);
      if (A[ii] >= 0.0) {
        scale = -scale;
      }

      if (fabs(scale) < 1.0020841800044864E-292) {
        pvt = 0;
        do {
          pvt++;
          ix = (ii - k) + 4;
          for (b_ix = ii + 1; b_ix < ix; b_ix++) {
            A[b_ix] *= 9.9792015476736E+291;
          }

          scale *= 9.9792015476736E+291;
          smax *= 9.9792015476736E+291;
        } while ((fabs(scale) < 1.0020841800044864E-292) && (pvt < 20));

        scale = rt_hypotd_snf(smax,
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_l
                              (3 - k, A, ii + 2));
        if (smax >= 0.0) {
          scale = -scale;
        }

        tau[k] = (scale - smax) / scale;
        smax = 1.0 / (smax - scale);
        for (b_ix = ii + 1; b_ix < ix; b_ix++) {
          A[b_ix] *= smax;
        }

        for (ix = 0; ix < pvt; ix++) {
          scale *= 1.0020841800044864E-292;
        }

        smax = scale;
      } else {
        tau[k] = (scale - A[ii]) / scale;
        smax = 1.0 / (A[ii] - scale);
        pvt = (ii - k) + 4;
        for (ix = ii + 1; ix < pvt; ix++) {
          A[ix] *= smax;
        }

        smax = scale;
      }
    }

    A[ii] = smax;
    if (k + 1 < 3) {
      smax = A[ii];
      A[ii] = 1.0;
      if (tau[k] != 0.0) {
        pvt = 4 - k;
        ix = (ii - k) + 3;
        while ((pvt > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        ix = 1 - k;
        exitg2 = false;
        while ((!exitg2) && (ix + 1 > 0)) {
          b_ix = ((ix << 2) + ii) + 4;
          iy = b_ix;
          do {
            exitg1 = 0;
            if (iy + 1 <= b_ix + pvt) {
              if (A[iy] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              ix--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 0;
        ix = -1;
      }

      if (pvt > 0) {
        if (ix + 1 != 0) {
          for (b_ix = 0; b_ix <= ix; b_ix++) {
            work[b_ix] = 0.0;
          }

          b_ix = 0;
          iy = ((ix << 2) + ii) + 5;
          for (iac = ii + 5; iac <= iy; iac += 4) {
            c_ix = ii;
            scale = 0.0;
            g = (iac + pvt) - 1;
            for (ia = iac; ia <= g; ia++) {
              scale += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[b_ix] += scale;
            b_ix++;
          }
        }

        if (!(-tau[k] == 0.0)) {
          b_ix = ii + 4;
          iy = 0;
          for (iac = 0; iac <= ix; iac++) {
            if (work[iy] != 0.0) {
              scale = work[iy] * -tau[k];
              c_ix = ii;
              g = pvt + b_ix;
              for (ia = b_ix; ia < g; ia++) {
                A[ia] += A[c_ix] * scale;
                c_ix++;
              }
            }

            iy++;
            b_ix += 4;
          }
        }
      }

      A[ii] = smax;
    }

    for (ii = k + 1; ii + 1 < 4; ii++) {
      pvt = (ii << 2) + k;
      if (vn1[ii] != 0.0) {
        smax = fabs(A[pvt]) / vn1[ii];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        scale = vn1[ii] / vn2[ii];
        scale = scale * scale * smax;
        if (scale <= 1.4901161193847656E-8) {
          vn1[ii] = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_l(3 - k, A,
            pvt + 2);
          vn2[ii] = vn1[ii];
        } else {
          vn1[ii] *= sqrt(smax);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S410>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm_l(const real_T x
  [3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S400>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_c(int32_T n,
  const real_T x[9], int32_T ix0)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal(int32_T n, real_T
  a, real_T x[9], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_ci(int32_T n,
  const real_T x[3], int32_T ix0)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(int32_T n, const
  real_T x[9], int32_T ix0, const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(int32_T n, real_T
  a, int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_j(int32_T n,
  real_T a, real_T x[3], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_p(int32_T n,
  real_T a, const real_T x[9], int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_pe(int32_T n,
  real_T a, const real_T x[3], int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(real_T a,
  real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(real_T *a, real_T *
  b, real_T *c, real_T *s)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot(real_T x[9],
  int32_T ix0, int32_T iy0, real_T c, real_T s)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap(real_T x[9],
  int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd(const real_T A[9],
  real_T U[9], real_T s[3], real_T V[9])
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
  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_c(3, b_A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (fabs(b_s[0]) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal(3, 1.0 / b_s[0], b_A, 1);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(3,
        -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(3, b_A, 1, b_A, qjj
        + 1) / b_A[0]), 1, b_A, qjj + 1);
    }

    e[d] = b_A[qjj];
  }

  while (qq + 1 < 4) {
    U[qq] = b_A[qq];
    qq++;
  }

  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_ci(2, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      nrm = -nrm;
    }

    e[0] = nrm;
    if (fabs(nrm) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_j(2, 1.0 / nrm, e, 2);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_p(2, e[qq], b_A, 3 * qq
        + 2, work, 2);
    }

    for (qq = 1; qq + 1 < 4; qq++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_pe(2, -e[qq] / e[1],
        work, 2, b_A, 3 * qq + 2);
    }
  }

  for (qq = 1; qq + 1 < 4; qq++) {
    V[qq] = e[qq];
  }

  apply_transform = false;
  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_c(2, b_A, 5);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      b_s[1] = -nrm;
    } else {
      b_s[1] = nrm;
    }

    if (fabs(b_s[1]) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal(2, 1.0 / b_s[1], b_A, 5);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(2,
        -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(2, b_A, 5, b_A, qjj
        + 1) / b_A[4]), 5, b_A, qjj + 1);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(3 - d,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(3 - d, U, qq + 1,
          U, qjj) / U[qq]), qq + 1, U, qjj);
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
      for (d = 2; d < 4; d++) {
        qjj = (d - 1) * 3 + 2;
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy(2,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc(2, V, 2, V, qjj) /
            V[1]), 2, V, qjj);
      }
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
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(nrm, U, 1);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] *= nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(nrm, V, 4);
  }

  e[0] = ztest;
  ztest = b_A[7];
  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    ztest = b_A[7] / nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(nrm, U, 4);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[2] = b_A[8] * nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(nrm, V, 7);
  }

  e[1] = ztest;
  if (b_s[2] != 0.0) {
    rt = fabs(b_s[2]);
    nrm = b_s[2] / rt;
    b_s[2] = rt;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(nrm, U, 7);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&b_s[qjj], &rt, &ztest,
          &sqds);
        if (qjj + 1 > d + 1) {
          rt = -sqds * e[0];
          e[0] *= ztest;
        }

        PIDcontroller4CoreCentralizedTestReadyMotor_xrot(V, 3 * qjj + 1, 3 * (m
          + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[d - 1];
      e[d - 1] = 0.0;
      for (qjj = d; qjj < m + 2; qjj++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&b_s[qjj], &rt, &ztest,
          &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot(U, 3 * qjj + 1, 3 * (d
          - 1) + 1, ztest, sqds);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&rt, &ztest, &sqds,
          &smm1);
        if (qjj > d + 1) {
          e[0] = rt;
        }

        ztest = e[qjj - 1];
        emm1 = b_s[qjj - 1];
        rt = emm1 * sqds + ztest * smm1;
        e[qjj - 1] = ztest * sqds - emm1 * smm1;
        ztest = smm1 * b_s[qjj];
        b_s[qjj] *= sqds;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot(V, 3 * (qjj - 1) + 1, 3
          * qjj + 1, sqds, smm1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&rt, &ztest, &sqds,
          &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot(U, 3 * (qjj - 1) + 1, 3
          * qjj + 1, sqds, smm1);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[d] < 0.0) {
        b_s[d] = -b_s[d];
        PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(-1.0, V, 3 * d + 1);
      }

      qq = d + 1;
      while ((d + 1 < 3) && (b_s[d] < b_s[qq])) {
        rt = b_s[d];
        b_s[d] = b_s[qq];
        b_s[qq] = rt;
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap(V, 3 * d + 1, 3 * (d +
          1) + 1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap(U, 3 * d + 1, 3 * (d +
          1) + 1);
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

/* Function for MATLAB Function: '<S400>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic(int32_T n,
  const real_T x[27], int32_T ix0)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv(int32_T m, int32_T
  n, const real_T A[27], int32_T ia0, const real_T x[27], int32_T ix0, real_T y
  [3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 9 + ia0;
    for (iac = ia0; iac <= b; iac += 9) {
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc(int32_T m, int32_T
  n, real_T alpha1, int32_T ix0, const real_T y[3], real_T A[27], int32_T ia0)
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
      jA += 9;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor(const real_T A
  [18], const real_T S[36], const real_T Ns[9], real_T b_S[9])
{
  real_T b_A[27];
  real_T y[18];
  real_T R[9];
  real_T work[3];
  real_T beta1;
  real_T s;
  real_T tau_idx_0;
  int32_T aoffset;
  int32_T coffset;
  int32_T coltop;
  int32_T exitg1;
  int32_T j;
  int32_T knt;
  boolean_T exitg2;
  for (j = 0; j < 3; j++) {
    coffset = j * 6;
    for (knt = 0; knt < 6; knt++) {
      aoffset = knt * 6;
      s = 0.0;
      for (coltop = 0; coltop < 6; coltop++) {
        s += A[coltop * 3 + j] * S[aoffset + coltop];
      }

      y[coffset + knt] = s;
      b_A[knt + 9 * j] = y[6 * j + knt];
    }

    b_A[9 * j + 6] = Ns[j];
    b_A[9 * j + 7] = Ns[j + 3];
    b_A[9 * j + 8] = Ns[j + 6];
    work[j] = 0.0;
  }

  s = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic(8, b_A, 2);
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
        for (coltop = 1; coltop < 9; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(s,
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic
                            (8, b_A, 2));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (coltop = 1; coltop < 9; coltop++) {
        b_A[coltop] *= s;
      }

      while (aoffset <= knt - 1) {
        beta1 *= 1.0020841800044864E-292;
        aoffset++;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      s = 1.0 / (b_A[0] - beta1);
      for (aoffset = 1; aoffset < 9; aoffset++) {
        b_A[aoffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 9;
    aoffset = 0;
    while ((knt > 0) && (b_A[aoffset + 8] == 0.0)) {
      knt--;
      aoffset--;
    }

    aoffset = 2;
    exitg2 = false;
    while ((!exitg2) && (aoffset > 0)) {
      coltop = (aoffset - 1) * 9 + 9;
      j = coltop;
      do {
        exitg1 = 0;
        if (j + 1 <= coltop + knt) {
          if (b_A[j] != 0.0) {
            exitg1 = 1;
          } else {
            j++;
          }
        } else {
          aoffset--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    aoffset = 0;
  }

  if (knt > 0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_xgemv(knt, aoffset, b_A, 10, b_A,
      1, work);
    PIDcontroller4CoreCentralizedTestReadyMotor_xgerc(knt, aoffset, -tau_idx_0,
      1, work, b_A, 10);
  }

  b_A[0] = s;
  s = b_A[10];
  tau_idx_0 = 0.0;
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic(7, b_A, 12);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[10], beta1);
    if (b_A[10] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 11; coltop < 18; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(s,
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic
                            (7, b_A, 12));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (coltop = 11; coltop < 18; coltop++) {
        b_A[coltop] *= s;
      }

      for (aoffset = 0; aoffset < knt; aoffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[10]) / beta1;
      s = 1.0 / (b_A[10] - beta1);
      for (aoffset = 11; aoffset < 18; aoffset++) {
        b_A[aoffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[10] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 8;
    aoffset = 9;
    while ((knt > 0) && (b_A[aoffset + 8] == 0.0)) {
      knt--;
      aoffset--;
    }

    aoffset = 1;
    j = 19;
    do {
      exitg1 = 0;
      if (j + 1 <= 19 + knt) {
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
    PIDcontroller4CoreCentralizedTestReadyMotor_xgemv(knt, aoffset, b_A, 20, b_A,
      11, work);
    PIDcontroller4CoreCentralizedTestReadyMotor_xgerc(knt, aoffset, -tau_idx_0,
      11, work, b_A, 20);
  }

  b_A[10] = s;
  s = b_A[20];
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic(6, b_A, 22);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[20], beta1);
    if (b_A[20] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (coltop = 21; coltop < 27; coltop++) {
          b_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(s,
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cic
                            (6, b_A, 22));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      s = 1.0 / (s - beta1);
      for (coltop = 21; coltop < 27; coltop++) {
        b_A[coltop] *= s;
      }

      for (aoffset = 0; aoffset < knt; aoffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      s = 1.0 / (b_A[20] - beta1);
      for (aoffset = 21; aoffset < 27; aoffset++) {
        b_A[aoffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[20] = s;
  R[0] = b_A[0];
  for (coffset = 1; coffset + 1 < 4; coffset++) {
    R[coffset] = 0.0;
  }

  for (coffset = 0; coffset < 2; coffset++) {
    R[coffset + 3] = b_A[coffset + 9];
  }

  while (coffset + 1 < 4) {
    R[coffset + 3] = 0.0;
    coffset++;
  }

  for (coffset = 0; coffset < 3; coffset++) {
    R[coffset + 6] = b_A[coffset + 18];
  }

  for (knt = 0; knt < 3; knt++) {
    b_S[3 * knt] = R[knt];
    b_S[3 * knt + 1] = R[knt + 3];
    b_S[3 * knt + 2] = R[knt + 6];
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve(const real_T A
  [9], real_T B[18])
{
  real_T tmp;
  int32_T i;
  int32_T j;
  int32_T jBcol;
  int32_T tmp_0;
  for (j = 0; j < 6; j++) {
    jBcol = 3 * j;
    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
      for (i = 2; i < 4; i++) {
        tmp_0 = (i + jBcol) - 1;
        B[tmp_0] -= A[i - 1] * B[jBcol];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[4];
      B[jBcol + 2] -= B[jBcol + 1] * A[5];
    }

    if (B[jBcol + 2] != 0.0) {
      B[jBcol + 2] /= A[8];
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_e(const real_T
  A[9], real_T B[18])
{
  real_T tmp;
  int32_T i;
  int32_T j;
  int32_T jBcol;
  int32_T tmp_0;
  for (j = 0; j < 6; j++) {
    jBcol = 3 * j;
    tmp = B[jBcol + 2];
    if (tmp != 0.0) {
      B[jBcol + 2] = tmp / A[8];
      for (i = 0; i < 2; i++) {
        tmp_0 = i + jBcol;
        B[tmp_0] -= B[jBcol + 2] * A[i + 6];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[4];
      B[jBcol] -= B[jBcol + 1] * A[3];
    }

    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cica(int32_T n,
  const real_T x[54], int32_T ix0)
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_f(int32_T m,
  int32_T n, const real_T A[54], int32_T ia0, const real_T x[54], int32_T ix0,
  real_T y[6])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 9 + ia0;
    for (iac = ia0; iac <= b; iac += 9) {
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

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_o(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[6], real_T A[54],
  int32_T ia0)
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
      jA += 9;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf(real_T A[54],
  real_T tau[6])
{
  real_T work[6];
  real_T b_atmp;
  real_T beta1;
  int32_T coltop;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T ii;
  int32_T knt;
  int32_T lastc;
  boolean_T exitg2;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    ii = i * 9 + i;
    b_atmp = A[ii];
    tau[i] = 0.0;
    beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cica(8 - i, A, ii
      + 2);
    if (beta1 != 0.0) {
      beta1 = rt_hypotd_snf(A[ii], beta1);
      if (A[ii] >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          lastc = ii - i;
          for (coltop = ii + 1; coltop < lastc + 9; coltop++) {
            A[coltop] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          b_atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(b_atmp,
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cica
                              (8 - i, A, ii + 2));
        if (b_atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[i] = (beta1 - b_atmp) / beta1;
        b_atmp = 1.0 / (b_atmp - beta1);
        lastc = ii - i;
        for (coltop = ii + 1; coltop < lastc + 9; coltop++) {
          A[coltop] *= b_atmp;
        }

        for (lastc = 0; lastc < knt; lastc++) {
          beta1 *= 1.0020841800044864E-292;
        }

        b_atmp = beta1;
      } else {
        tau[i] = (beta1 - A[ii]) / beta1;
        b_atmp = 1.0 / (A[ii] - beta1);
        knt = ii - i;
        for (lastc = ii + 1; lastc < knt + 9; lastc++) {
          A[lastc] *= b_atmp;
        }

        b_atmp = beta1;
      }
    }

    A[ii] = b_atmp;
    if (i + 1 < 6) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      if (tau[i] != 0.0) {
        knt = 9 - i;
        lastc = ii - i;
        while ((knt > 0) && (A[lastc + 8] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 5 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 9 + ii) + 9;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + knt) {
              if (A[ia] != 0.0) {
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_f(knt, lastc, A, ii +
          10, A, ii + 1, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_o(knt, lastc, -tau[i],
          ii + 1, work, A, ii + 10);
      }

      A[ii] = b_atmp;
    }
  }
}

/* Function for MATLAB Function: '<S400>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr(const real_T A[54],
  real_T Q[54], real_T R[36])
{
  real_T b_A[54];
  real_T tau[6];
  real_T work[6];
  int32_T coltop;
  int32_T d_i;
  int32_T exitg1;
  int32_T ia;
  int32_T itau;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 54U * sizeof(real_T));
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf(b_A, tau);
  for (itau = 0; itau < 6; itau++) {
    for (d_i = 0; d_i <= itau; d_i++) {
      R[d_i + 6 * itau] = b_A[9 * itau + d_i];
    }

    for (d_i = itau + 1; d_i + 1 < 7; d_i++) {
      R[d_i + 6 * itau] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (d_i = 5; d_i >= 0; d_i--) {
    itau = (d_i * 9 + d_i) + 10;
    if (d_i + 1 < 6) {
      b_A[itau - 10] = 1.0;
      if (tau[d_i] != 0.0) {
        lastv = 9 - d_i;
        lastc = itau - d_i;
        while ((lastv > 0) && (b_A[lastc - 2] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 5 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 9 + itau;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (b_A[ia - 1] != 0.0) {
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
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_f(lastv, lastc, b_A,
          itau, b_A, itau - 9, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_o(lastv, lastc,
          -tau[d_i], itau - 9, work, b_A, itau);
      }
    }

    lastv = (itau - d_i) - 1;
    for (lastc = itau - 9; lastc < lastv; lastc++) {
      b_A[lastc] *= -tau[d_i];
    }

    b_A[itau - 10] = 1.0 - tau[d_i];
    for (lastv = 0; lastv < d_i; lastv++) {
      b_A[(itau - lastv) - 11] = 0.0;
    }
  }

  for (itau = 0; itau < 6; itau++) {
    memcpy(&Q[itau * 9], &b_A[itau * 9], 9U * sizeof(real_T));
  }
}

static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
   *obj, real_T u)
{
  real_T csum;
  real_T cumRevIndex;
  real_T y;
  real_T z;
  int32_T k;
  csum = obj->pCumSum + u;
  z = obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] + csum;
  obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] = u;
  if (obj->pCumRevIndex != 3999.0) {
    cumRevIndex = obj->pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (k = 3997; k >= 0; k--) {
      obj->pCumSumRev[k] += obj->pCumSumRev[k + 1];
    }
  }

  y = z / 4000.0;
  obj->pCumSum = csum;
  obj->pCumRevIndex = cumRevIndex;
  return y;
}

/* Function for MATLAB Function: '<S402>/Predict' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i(int32_T n,
  const real_T x[36], int32_T ix0)
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

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_m(int32_T n,
  real_T a, real_T x[36], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_n(int32_T n,
  const real_T x[36], int32_T ix0, const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_d(int32_T n,
  real_T a, int32_T ix0, real_T y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4(int32_T n,
  const real_T x[6], int32_T ix0)
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

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(real_T a,
  real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mc(int32_T n,
  real_T a, real_T x[6], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dt(int32_T n,
  real_T a, const real_T x[36], int32_T ix0, real_T y[6], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dtk(int32_T n,
  real_T a, const real_T x[6], int32_T ix0, real_T y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(real_T x[36],
  int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  real_T temp_tmp_0;
  real_T temp_tmp_2;
  int32_T k;
  int32_T temp_tmp;
  int32_T temp_tmp_1;
  for (k = 0; k < 6; k++) {
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap_f(real_T x[36],
  int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T k;
  int32_T temp_tmp;
  int32_T tmp;
  for (k = 0; k < 6; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd_a(const real_T A[36],
  real_T U[36], real_T s[6], real_T V[36])
{
  real_T b_A[36];
  real_T b_s[6];
  real_T e[6];
  real_T work[6];
  real_T emm1;
  real_T nrm;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T exitg1;
  int32_T i;
  int32_T k_ii;
  int32_T qjj;
  int32_T qp1jj;
  int32_T qp1q;
  int32_T qq;
  boolean_T apply_transform;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }

  for (i = 0; i < 36; i++) {
    U[i] = 0.0;
    V[i] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    qq = 6 * i + i;
    apply_transform = false;
    nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i(6 - i, b_A, qq + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq] < 0.0) {
        b_s[i] = -nrm;
      } else {
        b_s[i] = nrm;
      }

      if (fabs(b_s[i]) >= 1.0020841800044864E-292) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xscal_m(6 - i, 1.0 / b_s[i],
          b_A, qq + 1);
      } else {
        qp1q = (qq - i) + 6;
        for (qjj = qq; qjj < qp1q; qjj++) {
          b_A[qjj] /= b_s[i];
        }
      }

      b_A[qq]++;
      b_s[i] = -b_s[i];
    } else {
      b_s[i] = 0.0;
    }

    for (qp1q = i + 1; qp1q + 1 < 7; qp1q++) {
      qjj = 6 * qp1q + i;
      if (apply_transform) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_d(6 - i,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_n(6 - i, b_A, qq +
          1, b_A, qjj + 1) / b_A[i + 6 * i]), qq + 1, b_A, qjj + 1);
      }

      e[qp1q] = b_A[qjj];
    }

    for (qq = i; qq + 1 < 7; qq++) {
      U[qq + 6 * i] = b_A[6 * i + qq];
    }

    if (i + 1 <= 4) {
      nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4(5 - i, e, i + 2);
      if (nrm == 0.0) {
        e[i] = 0.0;
      } else {
        if (e[i + 1] < 0.0) {
          e[i] = -nrm;
        } else {
          e[i] = nrm;
        }

        nrm = e[i];
        if (fabs(e[i]) >= 1.0020841800044864E-292) {
          PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mc(5 - i, 1.0 / e[i],
            e, i + 2);
        } else {
          for (qq = i + 1; qq < 6; qq++) {
            e[qq] /= nrm;
          }
        }

        e[i + 1]++;
        e[i] = -e[i];
        for (qq = i + 1; qq + 1 < 7; qq++) {
          work[qq] = 0.0;
        }

        for (qq = i + 1; qq + 1 < 7; qq++) {
          PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dt(5 - i, e[qq], b_A,
            (i + 6 * qq) + 2, work, i + 2);
        }

        for (qq = i + 1; qq + 1 < 7; qq++) {
          PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_dtk(5 - i, -e[qq] /
            e[i + 1], work, i + 2, b_A, (i + 6 * qq) + 2);
        }
      }

      for (qq = i + 1; qq + 1 < 7; qq++) {
        V[qq + 6 * i] = e[qq];
      }
    }
  }

  i = 4;
  b_s[5] = b_A[35];
  e[4] = b_A[34];
  e[5] = 0.0;
  for (qq = 0; qq < 6; qq++) {
    U[qq + 30] = 0.0;
  }

  U[35] = 1.0;
  for (qp1q = 4; qp1q >= 0; qp1q--) {
    qq = 6 * qp1q + qp1q;
    if (b_s[qp1q] != 0.0) {
      for (qp1jj = qp1q + 1; qp1jj + 1 < 7; qp1jj++) {
        qjj = (6 * qp1jj + qp1q) + 1;
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_d(6 - qp1q,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_n(6 - qp1q, U, qq
          + 1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (qjj = qp1q; qjj + 1 < 7; qjj++) {
        qp1jj = 6 * qp1q + qjj;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (qq = 0; qq < qp1q; qq++) {
        U[qq + 6 * qp1q] = 0.0;
      }
    } else {
      for (qjj = 0; qjj < 6; qjj++) {
        U[qjj + 6 * qp1q] = 0.0;
      }

      U[qq] = 1.0;
    }
  }

  for (qq = 5; qq >= 0; qq--) {
    if ((qq + 1 <= 4) && (e[qq] != 0.0)) {
      qp1q = (6 * qq + qq) + 2;
      for (qjj = qq + 1; qjj + 1 < 7; qjj++) {
        qp1jj = (6 * qjj + qq) + 2;
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_d(5 - qq,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_n(5 - qq, V, qp1q,
          V, qp1jj) / V[qp1q - 1]), qp1q, V, qp1jj);
      }
    }

    for (qp1q = 0; qp1q < 6; qp1q++) {
      V[qp1q + 6 * qq] = 0.0;
    }

    V[qq + 6 * qq] = 1.0;
  }

  for (qq = 0; qq < 6; qq++) {
    ztest = e[qq];
    if (b_s[qq] != 0.0) {
      rt = fabs(b_s[qq]);
      nrm = b_s[qq] / rt;
      b_s[qq] = rt;
      if (qq + 1 < 6) {
        ztest /= nrm;
      }

      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(nrm, U, 6 * qq + 1);
    }

    if ((qq + 1 < 6) && (ztest != 0.0)) {
      rt = fabs(ztest);
      nrm = rt / ztest;
      ztest = rt;
      b_s[qq + 1] *= nrm;
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(nrm, V, 6 * (qq + 1)
        + 1);
    }

    e[qq] = ztest;
  }

  qq = 0;
  nrm = 0.0;
  for (qp1q = 0; qp1q < 6; qp1q++) {
    ztest = fabs(b_s[qp1q]);
    rt = fabs(e[qp1q]);
    if ((ztest > rt) || ((int32_T)rtIsNaN(rt))) {
      rt = ztest;
    }

    if ((!(nrm > rt)) && (!(int32_T)rtIsNaN(rt))) {
      nrm = rt;
    }
  }

  while ((i + 2 > 0) && (qq < 75)) {
    qp1jj = i + 1;
    do {
      exitg1 = 0;
      qp1q = qp1jj;
      if (qp1jj == 0) {
        exitg1 = 1;
      } else {
        rt = fabs(e[qp1jj - 1]);
        if ((rt <= (fabs(b_s[qp1jj - 1]) + fabs(b_s[qp1jj])) *
             2.2204460492503131E-16) || ((rt <= 1.0020841800044864E-292) || ((qq
               > 20) && (rt <= 2.2204460492503131E-16 * nrm)))) {
          e[qp1jj - 1] = 0.0;
          exitg1 = 1;
        } else {
          qp1jj--;
        }
      }
    } while (exitg1 == 0);

    if (i + 1 == qp1jj) {
      qp1jj = 4;
    } else {
      qjj = i + 2;
      k_ii = i + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= qp1jj)) {
        qjj = k_ii;
        if (k_ii == qp1jj) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (k_ii < i + 2) {
            rt = fabs(e[k_ii - 1]);
          }

          if (k_ii > qp1jj + 1) {
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

      if (qjj == qp1jj) {
        qp1jj = 3;
      } else if (i + 2 == qjj) {
        qp1jj = 1;
      } else {
        qp1jj = 2;
        qp1q = qjj;
      }
    }

    switch (qp1jj) {
     case 1:
      rt = e[i];
      e[i] = 0.0;
      for (qjj = i; qjj + 1 >= qp1q + 1; qjj--) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&b_s[qjj], &rt, &ztest,
          &sqds);
        if (qjj + 1 > qp1q + 1) {
          emm1 = e[qjj - 1];
          rt = emm1 * -sqds;
          e[qjj - 1] = emm1 * ztest;
        }

        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(V, 6 * qjj + 1, 6 *
          (i + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[qp1q - 1];
      e[qp1q - 1] = 0.0;
      for (qjj = qp1q; qjj < i + 2; qjj++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&b_s[qjj], &rt, &ztest,
          &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(U, 6 * qjj + 1, 6 *
          (qp1q - 1) + 1, ztest, sqds);
      }
      break;

     case 3:
      sqds = b_s[i + 1];
      ztest = fabs(sqds);
      rt = fabs(b_s[i]);
      if ((ztest > rt) || ((int32_T)rtIsNaN(rt))) {
        rt = ztest;
      }

      ztest = fabs(e[i]);
      if ((rt > ztest) || ((int32_T)rtIsNaN(ztest))) {
        ztest = rt;
      }

      rt = fabs(b_s[qp1q]);
      if ((ztest > rt) || ((int32_T)rtIsNaN(rt))) {
        rt = ztest;
      }

      ztest = fabs(e[qp1q]);
      if ((rt > ztest) || ((int32_T)rtIsNaN(ztest))) {
        ztest = rt;
      }

      rt = sqds / ztest;
      smm1 = b_s[i] / ztest;
      emm1 = e[i] / ztest;
      sqds = b_s[qp1q] / ztest;
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
      ztest = e[qp1q] / ztest * sqds;
      for (qjj = qp1q + 1; qjj <= i + 1; qjj++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&rt, &ztest, &sqds,
          &smm1);
        if (qjj > qp1q + 1) {
          e[qjj - 2] = rt;
        }

        emm1 = e[qjj - 1];
        ztest = b_s[qjj - 1];
        rt = ztest * sqds + emm1 * smm1;
        e[qjj - 1] = emm1 * sqds - ztest * smm1;
        ztest = smm1 * b_s[qjj];
        b_s[qjj] *= sqds;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(V, 6 * (qjj - 1) + 1,
          6 * qjj + 1, sqds, smm1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg(&rt, &ztest, &sqds,
          &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_l(U, 6 * (qjj - 1) + 1,
          6 * qjj + 1, sqds, smm1);
      }

      e[i] = rt;
      qq++;
      break;

     default:
      if (b_s[qp1q] < 0.0) {
        b_s[qp1q] = -b_s[qp1q];
        PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(-1.0, V, 6 * qp1q
          + 1);
      }

      qq = qp1q + 1;
      while ((qp1q + 1 < 6) && (b_s[qp1q] < b_s[qq])) {
        rt = b_s[qp1q];
        b_s[qp1q] = b_s[qq];
        b_s[qq] = rt;
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap_f(V, 6 * qp1q + 1, 6 *
          (qp1q + 1) + 1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap_f(U, 6 * qp1q + 1, 6 *
          (qp1q + 1) + 1);
        qp1q = qq;
        qq++;
      }

      qq = 0;
      i--;
      break;
    }
  }

  for (i = 0; i < 6; i++) {
    s[i] = b_s[i];
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_ssTF_vertical_kalman_leo
  (real_T x[6], const real_T u[12])
{
  real_T tmp;
  real_T x_0;
  real_T x_1;
  real_T x_2;
  real_T x_3;
  real_T x_4;
  real_T x_5;
  real_T x_6;
  real_T x_7;
  x_0 = x[1];
  x_1 = x[0];
  x_2 = x[2];
  x_3 = x[3];
  x_4 = x[2];
  x_5 = x[4];
  x_6 = x[5];
  x_7 = x[4];
  tmp = u[0] + u[1];
  x[0] += (9.81 - (((tmp + u[2]) + u[3]) + u[9]) / u[8]) * 0.00025;
  x[1] = x_1 * 0.00025 + x_0;
  x[2] = ((((-u[0] + u[1]) - u[2]) + u[3]) * (u[6] / u[4]) + u[11] / u[4]) *
    0.00025 + x_2;
  x[3] = x_4 * 0.00025 + x_3;
  x[4] = (((tmp - u[2]) - u[3]) * (u[7] / u[5]) + u[10] / u[5]) * 0.00025 + x_5;
  x[5] = x_7 * 0.00025 + x_6;
}

/* Function for MATLAB Function: '<S402>/Predict' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4w(int32_T n,
  const real_T x[72], int32_T ix0)
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

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_d(int32_T m,
  int32_T n, const real_T A[72], int32_T ia0, const real_T x[72], int32_T ix0,
  real_T y[6])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 12 + ia0;
    for (iac = ia0; iac <= b; iac += 12) {
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

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_h(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[6], real_T A[72],
  int32_T ia0)
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
      jA += 12;
    }
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_j(real_T A[72],
  real_T tau[6])
{
  real_T work[6];
  real_T b_atmp;
  real_T beta1;
  int32_T coltop;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T ii;
  int32_T knt;
  int32_T lastc;
  boolean_T exitg2;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    ii = i * 12 + i;
    b_atmp = A[ii];
    tau[i] = 0.0;
    beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4w(11 - i, A, ii
      + 2);
    if (beta1 != 0.0) {
      beta1 = rt_hypotd_snf(A[ii], beta1);
      if (A[ii] >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          lastc = ii - i;
          for (coltop = ii + 1; coltop < lastc + 12; coltop++) {
            A[coltop] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          b_atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(b_atmp,
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_i4w
                              (11 - i, A, ii + 2));
        if (b_atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[i] = (beta1 - b_atmp) / beta1;
        b_atmp = 1.0 / (b_atmp - beta1);
        lastc = ii - i;
        for (coltop = ii + 1; coltop < lastc + 12; coltop++) {
          A[coltop] *= b_atmp;
        }

        for (lastc = 0; lastc < knt; lastc++) {
          beta1 *= 1.0020841800044864E-292;
        }

        b_atmp = beta1;
      } else {
        tau[i] = (beta1 - A[ii]) / beta1;
        b_atmp = 1.0 / (A[ii] - beta1);
        knt = ii - i;
        for (lastc = ii + 1; lastc < knt + 12; lastc++) {
          A[lastc] *= b_atmp;
        }

        b_atmp = beta1;
      }
    }

    A[ii] = b_atmp;
    if (i + 1 < 6) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      if (tau[i] != 0.0) {
        knt = 12 - i;
        lastc = ii - i;
        while ((knt > 0) && (A[lastc + 11] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 5 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 12 + ii) + 12;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + knt) {
              if (A[ia] != 0.0) {
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_d(knt, lastc, A, ii +
          13, A, ii + 1, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_h(knt, lastc, -tau[i],
          ii + 1, work, A, ii + 13);
      }

      A[ii] = b_atmp;
    }
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr_b(const real_T A[72],
  real_T Q[72], real_T R[36])
{
  real_T b_A[72];
  real_T tau[6];
  real_T work[6];
  int32_T coltop;
  int32_T d_i;
  int32_T exitg1;
  int32_T ia;
  int32_T itau;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 72U * sizeof(real_T));
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_j(b_A, tau);
  for (itau = 0; itau < 6; itau++) {
    for (d_i = 0; d_i <= itau; d_i++) {
      R[d_i + 6 * itau] = b_A[12 * itau + d_i];
    }

    for (d_i = itau + 1; d_i + 1 < 7; d_i++) {
      R[d_i + 6 * itau] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (d_i = 5; d_i >= 0; d_i--) {
    itau = (d_i * 12 + d_i) + 13;
    if (d_i + 1 < 6) {
      b_A[itau - 13] = 1.0;
      if (tau[d_i] != 0.0) {
        lastv = 12 - d_i;
        lastc = itau - d_i;
        while ((lastv > 0) && (b_A[lastc - 2] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 5 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 12 + itau;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (b_A[ia - 1] != 0.0) {
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
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_d(lastv, lastc, b_A,
          itau, b_A, itau - 12, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_h(lastv, lastc,
          -tau[d_i], itau - 12, work, b_A, itau);
      }
    }

    lastv = (itau - d_i) - 1;
    for (lastc = itau - 12; lastc < lastv; lastc++) {
      b_A[lastc] *= -tau[d_i];
    }

    b_A[itau - 13] = 1.0 - tau[d_i];
    for (lastv = 0; lastv < d_i; lastv++) {
      b_A[(itau - lastv) - 14] = 0.0;
    }
  }

  for (itau = 0; itau < 6; itau++) {
    memcpy(&Q[itau * 12], &b_A[itau * 12], 12U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S402>/Predict' */
static void
  PIDcontroller4CoreCentralizedTestReadyMotor_EKFPredictorAdditive_predict(const
  real_T Qs[36], real_T x[6], real_T S[36], const real_T varargin_1[12])
{
  real_T a__1[72];
  real_T y_0[72];
  real_T Jacobian[36];
  real_T y[36];
  real_T imvec[6];
  real_T z[6];
  real_T epsilon;
  int32_T aoffset;
  int32_T coffset;
  int32_T i;
  int32_T j;
  int32_T k;
  for (i = 0; i < 6; i++) {
    z[i] = x[i];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_ssTF_vertical_kalman_leo(z,
    varargin_1);
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 6; i++) {
      imvec[i] = x[i];
    }

    epsilon = 1.4901161193847656E-8 * fabs(x[j]);
    if ((1.4901161193847656E-8 > epsilon) || ((int32_T)rtIsNaN(epsilon))) {
      epsilon = 1.4901161193847656E-8;
    }

    imvec[j] = x[j] + epsilon;
    PIDcontroller4CoreCentralizedTestReadyMotor_ssTF_vertical_kalman_leo(imvec,
      varargin_1);
    for (i = 0; i < 6; i++) {
      Jacobian[i + 6 * j] = (imvec[i] - z[i]) / epsilon;
    }
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_ssTF_vertical_kalman_leo(x,
    varargin_1);
  for (j = 0; j < 6; j++) {
    coffset = j * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      epsilon = 0.0;
      for (k = 0; k < 6; k++) {
        epsilon += Jacobian[k * 6 + j] * S[aoffset + k];
      }

      y[coffset + i] = epsilon;
      k = i + 12 * j;
      y_0[k] = y[6 * j + i];
      y_0[k + 6] = Qs[6 * i + j];
    }
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_qr_b(y_0, a__1, Jacobian);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 6; j++) {
      S[j + 6 * i] = Jacobian[6 * j + i];
    }
  }
}

/* Model output function */
void PIDcontroller4CoreCentralizedTestReadyMotor_output
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M)
{
  B_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_B =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO;
  DW_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_DW =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork;
  InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_InstP =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref;
  PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->prevZCSigState;
  ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_U =
    (ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
    PIDcontroller4CoreCentralizedTestReadyMotor_M->inputs;
  ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_Y =
    (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
    PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs;

  /* local block i/o variables */
  real_T rtb_Gain1[4];
  real_T rtb_Gain[4];
  real_T rtb_Gain2;
  real_T rtb_Gain3_a;
  real_T rtb_Derivative[3];
  real_T rtb_Derivative1[3];
  real_T rtb_avg_g;
  real_T rtb_pitch_e;
  real_T rtb_roll;
  real_T rtb_Switch1_m;
  real_T rtb_Switch;
  real_T rtb_Switch1_e;
  real_T rtb_Switch_e;
  real_T rtb_Switch7;
  real_T rtb_Switch1_p;
  real_T rtb_Switch_b;
  real_T rtb_Switch_i;
  real_T rtb_Switch1_j;
  real_T rtb_Switch_j;
  real_T rtb_Switch1_c;
  real_T rtb_Switch1_f;
  real_T rtb_Switch1_k;
  real_T rtb_SineWave4;
  real_T rtb_Switch1_js;
  real_T rtb_Switch_o;
  real_T rtb_SineWave5;
  real_T rtb_Switch1_em;
  real_T rtb_Switch_f;
  real_T rtb_SineWave6;
  real_T rtb_Switch1_a;
  real_T rtb_Switch_p;
  real_T rtb_SineWave7;
  real_T rtb_Switch1_jf;
  real_T rtb_Switch_iu;
  real_T rtb_Switch1_cv;
  real_T rtb_Switch1_i;
  real_T rtb_Switch1_ab;
  real_T rtb_Switch1_fn;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *obj;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *obj_0;
  real_T Ss_1[54];
  real_T a__1[54];
  real_T rtb_Add_e[39];
  real_T rtb_uDLookupTable1[39];
  real_T A_0[36];
  real_T A_1[36];
  real_T Ss_0[36];
  real_T rtb_CreateDiagonalMatrix1[36];
  real_T rtb_Flip[30];
  real_T rtb_Flip_a[30];
  real_T rtb_Flip_l[30];
  real_T rtb_Flip_p[30];
  real_T rtb_uDLookupTable2[30];
  real_T rtb_uDLookupTable2_bq[30];
  real_T rtb_uDLookupTable2_e5[30];
  real_T rtb_uDLookupTable2_j[30];
  real_T C_0[18];
  real_T K[18];
  real_T b_C[18];
  real_T dHdx[18];
  real_T A[12];
  real_T R[9];
  real_T Ss[9];
  real_T V[9];
  real_T rtb_CreateDiagonalMatrix[9];
  real_T imvec[6];
  real_T rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[6];
  real_T zz[4];
  real_T C[3];
  real_T X[3];
  real_T Y[3];
  real_T (*lastU)[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T fractions_1[2];
  real_T fractions_2[2];
  real_T fractions_3[2];
  real_T fractions_4[2];
  real_T rtb_Add1;
  real_T rtb_Add1_k;
  real_T rtb_Add1_n;
  real_T rtb_Add2;
  real_T rtb_Add2_m;
  real_T rtb_Add3;
  real_T rtb_Add_l;
  real_T rtb_DeadZone_c;
  real_T rtb_DeadZone_f;
  real_T rtb_DeadZone_fg;
  real_T rtb_DeadZone_m;
  real_T rtb_DiscreteTimeIntegrator1_f;
  real_T rtb_DiscreteTimeIntegrator1_g;
  real_T rtb_DiscreteTimeIntegrator1_j;
  real_T rtb_DiscreteTimeIntegrator1_o2;
  real_T rtb_DiscreteTimeIntegrator_c;
  real_T rtb_DiscreteTimeIntegrator_d;
  real_T rtb_DiscreteTimeIntegrator_e2;
  real_T rtb_DiscreteTimeIntegrator_ov;
  real_T rtb_Divide;
  real_T rtb_Divide1;
  real_T rtb_Divide_k;
  real_T rtb_F_array_idx_0;
  real_T rtb_F_array_idx_1;
  real_T rtb_F_array_idx_2;
  real_T rtb_F_array_idx_3;
  real_T rtb_Gain_mn;
  real_T rtb_Gain_no;
  real_T rtb_IProdOut;
  real_T rtb_IProdOut_c2;
  real_T rtb_IProdOut_cg;
  real_T rtb_IProdOut_g;
  real_T rtb_IProdOut_hj;
  real_T rtb_IProdOut_k;
  real_T rtb_IProdOut_m;
  real_T rtb_Saturation;
  real_T rtb_Saturation_gd;
  real_T rtb_Saturation_gj;
  real_T rtb_Saturation_k_idx_0;
  real_T rtb_Saturation_k_idx_2;
  real_T rtb_Subtract2_f;
  real_T rtb_Subtract_c;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T rtb_Sum_a4;
  real_T rtb_Sum_ac;
  real_T rtb_Sum_gy;
  real_T rtb_Sum_h;
  real_T rtb_Sum_ih;
  real_T rtb_Sum_oi;
  real_T rtb_Sum_pc;
  real_T rtb_Switch1;
  real_T rtb_Switch1_d;
  real_T rtb_Switch1_j1_idx_0;
  real_T rtb_Switch1_j1_idx_1;
  real_T rtb_Switch2_idx_0;
  real_T rtb_Switch2_idx_1;
  real_T rtb_Switch2_idx_2;
  real_T rtb_Switch_ds;
  real_T rtb_Switch_gn;
  real_T rtb_Switch_k1;
  real_T rtb_Switch_k_idx_0;
  real_T rtb_Switch_k_idx_1;
  real_T rtb_Switch_k_idx_2;
  real_T rtb_Switch_k_idx_3;
  real_T rtb_Switch_od;
  real_T rtb_Switch_ph;
  real_T rtb_TrigonometricFunction;
  real_T rtb_ZeroCurrentForces_idx_3;
  real_T rtb_error;
  real_T rtb_error_m;
  real_T rtb_out_req_I;
  real_T rtb_uDLookupTable1_h;
  real_T rtb_uDLookupTable1_j;
  real_T rtb_uDLookupTable1_l;
  real_T rtb_uDLookupTable1_os;
  real_T rtb_uDLookupTable1_p;
  real_T rtb_uDLookupTable2_cw;
  real_T rtb_uDLookupTable3;
  real_T rtb_uDLookupTable4;
  real_T rtb_z_out_idx_0;
  real_T rtb_z_out_idx_1;
  real_T rtb_z_out_idx_2;
  real_T rtb_z_out_idx_3;
  real_T tol_tmp;
  real_T tol_tmp_0;
  real_T tol_tmp_1;
  real_T tol_tmp_2;
  real_T tol_tmp_3;
  real_T tol_tmp_tmp;
  int32_T jpvt[3];
  int32_T aoffset;
  int32_T b_j;
  int32_T coffset;
  int32_T i;
  int32_T rankA;
  int32_T rtb_PulseGenerator;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  uint32_T bpIndices_1[2];
  uint32_T bpIndices_2[2];
  uint32_T bpIndices_3[2];
  uint32_T bpIndices_4[2];
  boolean_T p;
  boolean_T tmp;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/I_A_m'
   *  Inport: '<Root>/I_B_m'
   *  Inport: '<Root>/I_C_m'
   *  Inport: '<Root>/I_D_m'
   */
  rtb_Gain1[0] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_A_m;
  rtb_Gain1[1] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_B_m;
  rtb_Gain1[2] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_C_m;
  rtb_Gain1[3] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_D_m;

  /* Product: '<S33>/Divide' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant1'
   */
  rtb_Divide = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ReferenceMass;

  /* RelationalOperator: '<S16>/Equal' incorporates:
   *  Constant: '<S16>/Constant14'
   *  Delay: '<S16>/Delay1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE == 2.0);

  /* DiscreteIntegrator: '<S513>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE = 0.0;
  }

  /* SampleTimeMath: '<S508>/Tsamp' incorporates:
   *  Gain: '<S505>/Derivative Gain'
   *
   * About '<S508>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp = 0.0;

  /* Delay: '<S506>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Sum: '<S522>/Sum' incorporates:
   *  Delay: '<S506>/UD'
   *  DiscreteIntegrator: '<S513>/Integrator'
   *  Sum: '<S506>/Diff'
   */
  rtb_Sum = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp -
             PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE) +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE;

  /* DiscreteIntegrator: '<S463>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j = 0.0;
  }

  /* SampleTimeMath: '<S458>/Tsamp' incorporates:
   *  Gain: '<S455>/Derivative Gain'
   *
   * About '<S458>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b = 0.0;

  /* Delay: '<S456>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Sum: '<S472>/Sum' incorporates:
   *  Delay: '<S456>/UD'
   *  DiscreteIntegrator: '<S463>/Integrator'
   *  Sum: '<S456>/Diff'
   */
  rtb_Sum_pc = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b -
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p) +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j;

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant13'
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S16>/Subtract3'
   *  Switch: '<S16>/Switch6'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode != 0.0) {
    rtb_Switch1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode;
  } else if ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime +
              PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RunTime) -
             rtb_Sum_pc > 0.0) {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant2'
     *  Constant: '<S16>/Constant3'
     *  Sum: '<S16>/Subtract'
     *  Switch: '<S16>/Switch6'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime - rtb_Sum
        > 0.0) {
      rtb_Switch1 =
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode;
    } else {
      rtb_Switch1 = 1.0;
    }

    /* End of Switch: '<S16>/Switch' */
  } else {
    /* Switch: '<S16>/Switch6' incorporates:
     *  Constant: '<S16>/Constant12'
     */
    rtb_Switch1 = 3.0;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  if ((!(int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
       == 1)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
      = 0.0;
  }

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/Constant4'
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   *  Sum: '<S16>/Subtract1'
   *  Switch: '<S16>/Switch4'
   */
  if (rtb_Switch1 - 3.0 != 0.0) {
    /* Outport: '<Root>/Mode' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = rtb_Switch1;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
       > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LandingTime) {
    /* Switch: '<S16>/Switch4' incorporates:
     *  Constant: '<S16>/Constant7'
     *  Outport: '<Root>/Mode'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = 2.0;
  } else {
    /* Outport: '<Root>/Mode' incorporates:
     *  Constant: '<S16>/Constant6'
     *  Switch: '<S16>/Switch4'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = 3.0;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* DiscretePulseGenerator: '<S32>/Pulse Generator' */
  rtb_PulseGenerator = ((real_T)
                        PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter
                        <
                        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamErrorTime
                        / 0.00025) &&
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter >= 0) ? 2 :
    0;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter >=
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamErrorTime * 2.0 /
      0.00025 - 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter = 0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S32>/Pulse Generator' */

  /* Product: '<S32>/Product1' incorporates:
   *  Constant: '<S32>/Constant6'
   *  Constant: '<S32>/Constant9'
   *  Sum: '<S32>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1 = ((real_T)
    rtb_PulseGenerator - 1.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Abs: '<S71>/Abs' incorporates:
   *  Delay: '<S71>/Delay'
   */
  rtb_ZeroCurrentForces_idx_3 = fabs
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE);

  /* Saturate: '<S71>/Saturation' */
  if (rtb_ZeroCurrentForces_idx_3 > 5.0) {
    rtb_Saturation = 5.0;
  } else {
    rtb_Saturation = rtb_ZeroCurrentForces_idx_3;
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S48>/Switch1' incorporates:
     *  Lookup_n-D: '<S48>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_m = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S48>/Switch1' incorporates:
     *  Constant: '<S48>/Constant'
     */
    rtb_Switch1_m =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S48>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1, rtb_Switch1_m,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage,
     rtb_Switch1_m,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S40>/Switch' */
    rtb_Switch =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p.MovingAverage;
  } else {
    /* Switch: '<S40>/Switch' */
    rtb_Switch =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Gain: '<S32>/Gain' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsFactor *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S49>/Switch1' incorporates:
     *  Lookup_n-D: '<S49>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_e = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S49>/Switch1' incorporates:
     *  Constant: '<S49>/Constant'
     */
    rtb_Switch1_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S49>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain, rtb_Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage,
     rtb_Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S41>/Switch' */
    rtb_Switch_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn.MovingAverage;
  } else {
    /* Switch: '<S41>/Switch' */
    rtb_Switch_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Switch: '<S32>/Switch7' incorporates:
   *  Constant: '<S32>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsBackDelay >
      0.0) {
    /* Switch: '<S32>/Switch7' incorporates:
     *  Delay: '<S32>/Delay1'
     */
    rtb_Switch7 =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[0];
  } else {
    /* Switch: '<S32>/Switch7' */
    rtb_Switch7 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;
  }

  /* End of Switch: '<S32>/Switch7' */

  /* Switch: '<S50>/Switch1' incorporates:
   *  Constant: '<S50>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S50>/Switch1' incorporates:
     *  Lookup_n-D: '<S50>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_p = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S50>/Switch1' incorporates:
     *  Constant: '<S50>/Constant'
     */
    rtb_Switch1_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S50>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Switch7,
    rtb_Switch1_p,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage,
     rtb_Switch1_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S42>/Switch' */
    rtb_Switch_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna.MovingAverage;
  } else {
    /* Switch: '<S42>/Switch' */
    rtb_Switch_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsBackDelay >
      0.0) {
    /* Switch: '<S32>/Switch' incorporates:
     *  Delay: '<S32>/Delay'
     */
    rtb_Switch_i =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[0];
  } else {
    /* Switch: '<S32>/Switch' */
    rtb_Switch_i = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S51>/Switch1' incorporates:
     *  Lookup_n-D: '<S51>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_j = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S51>/Switch1' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_Switch1_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S51>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Switch_i,
    rtb_Switch1_j,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage,
     rtb_Switch1_j,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S43>/Switch' */
    rtb_Switch_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae.MovingAverage;
  } else {
    /* Switch: '<S43>/Switch' */
    rtb_Switch_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage;
  }

  /* End of Switch: '<S43>/Switch' */

  /* MATLAB Function: '<S38>/FindCoordinates' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(rtb_Switch,
    rtb_Switch_e, rtb_Switch_b, rtb_Switch_j, 0.465, 0.392, 0.1596,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates);

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S52>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S52>/Switch1' incorporates:
     *  Lookup_n-D: '<S52>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_c = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S52>/Switch1' incorporates:
     *  Constant: '<S52>/Constant'
     */
    rtb_Switch1_c =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S52>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g,
     rtb_Switch1_c,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S53>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S53>/Switch1' incorporates:
     *  Lookup_n-D: '<S53>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_f = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S53>/Constant'
     */
    rtb_Switch1_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S53>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch,
     rtb_Switch1_f,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);

  /* Switch: '<S54>/Switch1' incorporates:
   *  Constant: '<S54>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S54>/Switch1' incorporates:
     *  Lookup_n-D: '<S54>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_k = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S54>/Switch1' incorporates:
     *  Constant: '<S54>/Constant'
     */
    rtb_Switch1_k =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S54>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll,
     rtb_Switch1_k,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);

  /* Sin: '<S32>/Sine Wave4' */
  rtb_SineWave4 = sin((real_T)
                      PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter *
                      2.0 * 3.1415926535897931 / floor
                      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime
                       / 0.00025)) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S63>/Switch1' incorporates:
   *  Constant: '<S63>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Lookup_n-D: '<S63>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_js = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Switch1_js =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S63>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave4,
    rtb_Switch1_js,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage,
     rtb_Switch1_js,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S55>/Switch' */
    rtb_Switch_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp.MovingAverage;
  } else {
    /* Switch: '<S55>/Switch' */
    rtb_Switch_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Sin: '<S32>/Sine Wave5' */
  rtb_SineWave5 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h
                       + 1000.0) * 2.0 * 3.1415926535897931 / floor
                      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime
                       / 0.00025)) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Lookup_n-D: '<S64>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_em = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S64>/Constant'
     */
    rtb_Switch1_em =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S64>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave5,
    rtb_Switch1_em,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage,
     rtb_Switch1_em,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S56>/Switch' */
    rtb_Switch_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg.MovingAverage;
  } else {
    /* Switch: '<S56>/Switch' */
    rtb_Switch_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Sin: '<S32>/Sine Wave6' */
  rtb_SineWave6 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o
                       + 3000.0) * 2.0 * 3.1415926535897931 / floor
                      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime
                       / 0.00025)) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S65>/Switch1' incorporates:
   *  Constant: '<S65>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S65>/Switch1' incorporates:
     *  Lookup_n-D: '<S65>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_a = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S65>/Switch1' incorporates:
     *  Constant: '<S65>/Constant'
     */
    rtb_Switch1_a =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S65>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave6,
    rtb_Switch1_a,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage,
     rtb_Switch1_a,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S57>/Switch' */
    rtb_Switch_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh.MovingAverage;
  } else {
    /* Switch: '<S57>/Switch' */
    rtb_Switch_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Sin: '<S32>/Sine Wave7' */
  rtb_SineWave7 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a
                       + 2000.0) * 2.0 * 3.1415926535897931 / floor
                      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime
                       / 0.00025)) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S66>/Switch1' incorporates:
   *  Constant: '<S66>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Lookup_n-D: '<S66>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_jf = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Switch1_jf =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S66>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave7,
    rtb_Switch1_jf,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage,
     rtb_Switch1_jf,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S58>/Switch' */
    rtb_Switch_iu =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5.MovingAverage;
  } else {
    /* Switch: '<S58>/Switch' */
    rtb_Switch_iu =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage;
  }

  /* End of Switch: '<S58>/Switch' */

  /* MATLAB Function: '<S39>/FindCoordinates' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(rtb_Switch_o,
    rtb_Switch_f, rtb_Switch_p, rtb_Switch_iu, 0.465, 0.392, 0.1596,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d);

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S67>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S67>/Switch1' incorporates:
     *  Lookup_n-D: '<S67>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_cv = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S67>/Switch1' incorporates:
     *  Constant: '<S67>/Constant'
     */
    rtb_Switch1_cv =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S67>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g,
     rtb_Switch1_cv,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);

  /* Switch: '<S68>/Switch1' incorporates:
   *  Constant: '<S68>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Lookup_n-D: '<S68>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_i = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S68>/Constant'
     */
    rtb_Switch1_i =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S68>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch,
     rtb_Switch1_i,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S69>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S69>/Switch1' incorporates:
     *  Lookup_n-D: '<S69>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_ab = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S69>/Switch1' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_Switch1_ab =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S69>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll,
     rtb_Switch1_ab,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);

  /* Switch: '<S32>/Switch2' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant3'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S32>/Subtract2'
   *  Switch: '<S32>/Switch3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 7.0 != 0.0) {
    /* Switch: '<S32>/Switch1' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S59>/Constant1'
     *  Sum: '<S32>/Subtract1'
     *  Switch: '<S59>/Switch'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 6.0 != 0.0) {
      /* Switch: '<S32>/Switch4' incorporates:
       *  Constant: '<S32>/Constant7'
       *  Constant: '<S44>/Constant1'
       *  Sum: '<S32>/Subtract6'
       *  Switch: '<S44>/Switch'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 5.0 != 0.0) {
        rtb_Switch2_idx_0 = 0.0;
        rtb_Switch2_idx_1 = 0.0;
        rtb_Switch2_idx_2 = 0.0;
      } else {
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter !=
            0.0) {
          /* Switch: '<S44>/Switch' */
          rtb_Switch2_idx_0 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev.MovingAverage;
        } else {
          rtb_Switch2_idx_0 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g;
        }

        /* Switch: '<S45>/Switch' incorporates:
         *  Constant: '<S45>/Constant1'
         *  Switch: '<S44>/Switch'
         */
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter !=
            0.0) {
          rtb_Switch2_idx_1 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv.MovingAverage;
        } else {
          rtb_Switch2_idx_1 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch;
        }

        /* End of Switch: '<S45>/Switch' */

        /* Switch: '<S46>/Switch' incorporates:
         *  Constant: '<S46>/Constant1'
         */
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0)
        {
          rtb_Switch2_idx_2 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf.MovingAverage;
        } else {
          rtb_Switch2_idx_2 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll;
        }

        /* End of Switch: '<S46>/Switch' */
      }

      /* End of Switch: '<S32>/Switch4' */
    } else {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter != 0.0)
      {
        /* Switch: '<S59>/Switch' */
        rtb_Switch2_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z.MovingAverage;
      } else {
        rtb_Switch2_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g;
      }

      /* Switch: '<S60>/Switch' incorporates:
       *  Constant: '<S60>/Constant1'
       *  Switch: '<S59>/Switch'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter != 0.0)
      {
        rtb_Switch2_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz.MovingAverage;
      } else {
        rtb_Switch2_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch;
      }

      /* End of Switch: '<S60>/Switch' */

      /* Switch: '<S61>/Switch' incorporates:
       *  Constant: '<S61>/Constant1'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0)
      {
        rtb_Switch2_idx_2 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh.MovingAverage;
      } else {
        rtb_Switch2_idx_2 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll;
      }

      /* End of Switch: '<S61>/Switch' */
    }

    /* End of Switch: '<S32>/Switch1' */
  } else {
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[0] !=
        0.0) {
      /* Switch: '<S32>/Switch3' incorporates:
       *  Sin: '<S32>/Sine Wave1'
       */
      rtb_Switch2_idx_0 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i * 2.0 *
        3.1415926535897931 / floor
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime / 0.00025))
        * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;
    } else {
      rtb_Switch2_idx_0 = 0.0;
    }

    /* Switch: '<S32>/Switch5' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S32>/Constant3'
     *  Sin: '<S32>/Sine Wave2'
     *  Switch: '<S32>/Switch3'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[1] !=
        0.0) {
      rtb_Switch2_idx_1 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m * 2.0 *
        3.1415926535897931 / floor
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime / 0.00025))
        * (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets *
           0.00136986216);
    } else {
      rtb_Switch2_idx_1 = 0.0;
    }

    /* End of Switch: '<S32>/Switch5' */

    /* Switch: '<S32>/Switch6' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S32>/Constant3'
     *  Sin: '<S32>/Sine Wave3'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[2] !=
        0.0) {
      rtb_Switch2_idx_2 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n * 2.0 *
        3.1415926535897931 / floor
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime / 0.00025))
        * (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets *
           0.00270269612);
    } else {
      rtb_Switch2_idx_2 = 0.0;
    }

    /* End of Switch: '<S32>/Switch6' */
  }

  /* End of Switch: '<S32>/Switch2' */

  /* Sum: '<S74>/Subtract5' incorporates:
   *  Constant: '<S74>/Constant4'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5 =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - -1.0;

  /* Delay: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[0];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MeasureCurrent != 0.0)
  {
    rtb_Switch_k_idx_0 = rtb_Gain1[0];
  } else {
    rtb_Switch_k_idx_0 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[0];
  }

  /* Delay: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[1];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MeasureCurrent != 0.0)
  {
    rtb_Switch_k_idx_1 = rtb_Gain1[1];
  } else {
    rtb_Switch_k_idx_1 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[1];
  }

  /* Delay: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[2];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MeasureCurrent != 0.0)
  {
    rtb_Switch_k_idx_2 = rtb_Gain1[2];
  } else {
    rtb_Switch_k_idx_2 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[2];
  }

  /* Delay: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[3] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[3];

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MeasureCurrent != 0.0)
  {
    rtb_Switch_k_idx_3 = rtb_Gain1[3];
  } else {
    rtb_Switch_k_idx_3 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[3];
  }

  /* Switch: '<S74>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5 != 0.0) {
    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S74>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch = 0.0;
  } else {
    /* Switch: '<S74>/Switch' incorporates:
     *  Sum: '<S37>/Sum'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch = ((rtb_Switch_k_idx_0
      + rtb_Switch_k_idx_1) + rtb_Switch_k_idx_2) + rtb_Switch_k_idx_3;
  }

  /* End of Switch: '<S74>/Switch' */

  /* DiscreteIntegrator: '<S160>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc = 0.0;
  }

  /* SampleTimeMath: '<S155>/Tsamp' incorporates:
   *  Gain: '<S152>/Derivative Gain'
   *
   * About '<S155>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch * 4000.0;

  /* Delay: '<S153>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Sum: '<S169>/Sum' incorporates:
   *  Delay: '<S153>/UD'
   *  DiscreteIntegrator: '<S160>/Integrator'
   *  Gain: '<S165>/Proportional Gain'
   *  Sum: '<S153>/Diff'
   */
  rtb_Sum_gy = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f);

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
      = 0.0;
  }

  /* End of DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */

  /* Sum: '<S72>/Subtract2' incorporates:
   *  Constant: '<S72>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  rtb_Subtract2_f = PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 3.0;

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      = 0.0;
  }

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S72>/Base Ref Airgap1'
   *  Constant: '<S72>/Constant2'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   *  Gain: '<S72>/Gain1'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S72>/Subtract2'
   *  Sum: '<S72>/Subtract4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 3.0 != 0.0) {
    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Base Ref Airgap'
     *  Constant: '<S72>/Constant'
     *  Gain: '<S72>/Gain'
     *  Product: '<S72>/Product'
     *  Saturate: '<S72>/Saturation'
     *  Sum: '<S72>/Subtract'
     *  Sum: '<S72>/Subtract1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
      rtb_error =
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap;
    } else {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
          > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime) {
        /* Saturate: '<S72>/Saturation' */
        rtb_Switch1_j1_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime;
      } else if
          (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
           < 0.0) {
        /* Saturate: '<S72>/Saturation' */
        rtb_Switch1_j1_idx_0 = 0.0;
      } else {
        /* Saturate: '<S72>/Saturation' */
        rtb_Switch1_j1_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE;
      }

      rtb_error = 1.0 /
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime *
        rtb_Switch1_j1_idx_0 *
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap -
         PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartingAirgap) +
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartingAirgap;
    }

    /* End of Switch: '<S72>/Switch1' */
  } else {
    rtb_error = 1.0 /
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LandingTime *
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      + PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* Switch: '<S74>/Switch1' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S74>/Constant2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = rtb_Sum_gy;
  }

  /* End of Switch: '<S74>/Switch1' */

  /* Outport: '<Root>/ActualReferenceAirgap' incorporates:
   *  Sum: '<S33>/Add1'
   *  Sum: '<S33>/Add4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ActualReferenceAirgap =
    (rtb_Switch1_j1_idx_0 + rtb_error) + rtb_Switch2_idx_0;

  /* Gain: '<S15>/Gain' incorporates:
   *  Inport: '<Root>/G_A'
   *  Inport: '<Root>/G_B'
   *  Inport: '<Root>/G_C'
   *  Inport: '<Root>/G_D'
   */
  rtb_Gain[0] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_A;
  rtb_Gain[1] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_B;
  rtb_Gain[2] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_C;
  rtb_Gain[3] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_D;

  /* Switch: '<S419>/Switch1' incorporates:
   *  Constant: '<S419>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S419>/Switch1' incorporates:
     *  Lookup_n-D: '<S419>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S419>/Switch1' incorporates:
     *  Constant: '<S419>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S419>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[0],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);

  /* Switch: '<S411>/Switch' incorporates:
   *  Constant: '<S411>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_ph =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e.MovingAverage;
  } else {
    rtb_Switch_ph =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh.MovingAverage;
  }

  /* End of Switch: '<S411>/Switch' */

  /* Switch: '<S420>/Switch1' incorporates:
   *  Constant: '<S420>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S420>/Switch1' incorporates:
     *  Lookup_n-D: '<S420>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S420>/Switch1' incorporates:
     *  Constant: '<S420>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S420>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[1],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);

  /* Switch: '<S412>/Switch' incorporates:
   *  Constant: '<S412>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_k1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n.MovingAverage;
  } else {
    rtb_Switch_k1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5.MovingAverage;
  }

  /* End of Switch: '<S412>/Switch' */

  /* Switch: '<S421>/Switch1' incorporates:
   *  Constant: '<S421>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S421>/Switch1' incorporates:
     *  Lookup_n-D: '<S421>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S421>/Switch1' incorporates:
     *  Constant: '<S421>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S421>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[2],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);

  /* Switch: '<S413>/Switch' incorporates:
   *  Constant: '<S413>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_ds =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f.MovingAverage;
  } else {
    rtb_Switch_ds =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage;
  }

  /* End of Switch: '<S413>/Switch' */

  /* Switch: '<S422>/Switch1' incorporates:
   *  Constant: '<S422>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S422>/Switch1' incorporates:
     *  Lookup_n-D: '<S422>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S422>/Switch1' incorporates:
     *  Constant: '<S422>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S422>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[3],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);

  /* Switch: '<S414>/Switch' incorporates:
   *  Constant: '<S414>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_gn =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k.MovingAverage;
  } else {
    rtb_Switch_gn =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage;
  }

  /* End of Switch: '<S414>/Switch' */

  /* MATLAB Function: '<S410>/FindCoordinates' incorporates:
   *  Constant: '<S410>/Constant'
   *  Constant: '<S410>/Constant1'
   *  Constant: '<S410>/Constant2'
   *  Constant: '<S410>/Constant4'
   *  Sum: '<S410>/Add'
   */
  /* MATLAB Function 'Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/FindCoordinates': '<S418>:1' */
  /* '<S418>:1:5' */
  /* '<S418>:1:6' */
  /* '<S418>:1:8' */
  /* '<S418>:1:11' */
  A[0] = 0.465;
  A[4] = -0.392;
  A[8] = 1.0;
  A[1] = -0.465;
  A[5] = -0.392;
  A[9] = 1.0;
  A[2] = 0.465;
  A[6] = 0.392;
  A[10] = 1.0;
  A[3] = -0.465;
  A[7] = 0.392;
  A[11] = 1.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_i(A, X, jpvt);
  rankA = 0;
  rtb_ZeroCurrentForces_idx_3 = 8.8817841970012523E-15 * fabs(A[0]);
  while ((rankA < 3) && (!(fabs(A[(rankA << 2) + rankA]) <=
           rtb_ZeroCurrentForces_idx_3))) {
    rankA++;
  }

  zz[0] = (rtb_Switch_ph -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[0]) / 1000.0;
  zz[2] = (rtb_Switch_k1 -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[1]) / 1000.0;
  zz[1] = (rtb_Switch_ds -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[2]) / 1000.0;
  zz[3] = (rtb_Switch_gn -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[3]) / 1000.0;
  C[0] = 0.0;
  if (X[0] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = zz[0];
    for (i = 1; i + 1 < 5; i++) {
      rtb_ZeroCurrentForces_idx_3 += A[i] * zz[i];
    }

    rtb_ZeroCurrentForces_idx_3 *= X[0];
    if (rtb_ZeroCurrentForces_idx_3 != 0.0) {
      zz[0] -= rtb_ZeroCurrentForces_idx_3;
      for (i = 1; i + 1 < 5; i++) {
        zz[i] -= A[i] * rtb_ZeroCurrentForces_idx_3;
      }
    }
  }

  C[1] = 0.0;
  if (X[1] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = zz[1];
    for (i = 2; i + 1 < 5; i++) {
      rtb_ZeroCurrentForces_idx_3 += A[i + 4] * zz[i];
    }

    rtb_ZeroCurrentForces_idx_3 *= X[1];
    if (rtb_ZeroCurrentForces_idx_3 != 0.0) {
      zz[1] -= rtb_ZeroCurrentForces_idx_3;
      for (i = 2; i + 1 < 5; i++) {
        zz[i] -= A[i + 4] * rtb_ZeroCurrentForces_idx_3;
      }
    }
  }

  C[2] = 0.0;
  if (X[2] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = zz[2];
    for (i = 3; i + 1 < 5; i++) {
      rtb_ZeroCurrentForces_idx_3 += A[i + 8] * zz[i];
    }

    rtb_ZeroCurrentForces_idx_3 *= X[2];
    if (rtb_ZeroCurrentForces_idx_3 != 0.0) {
      zz[2] -= rtb_ZeroCurrentForces_idx_3;
      for (i = 3; i + 1 < 5; i++) {
        zz[i] -= A[i + 8] * rtb_ZeroCurrentForces_idx_3;
      }
    }
  }

  for (i = 0; i < rankA; i++) {
    C[jpvt[i] - 1] = zz[i];
  }

  for (b_j = rankA - 1; b_j + 1 > 0; b_j--) {
    rankA = b_j << 2;
    C[jpvt[b_j] - 1] /= A[rankA + b_j];
    for (i = 0; i < b_j; i++) {
      C[jpvt[i] - 1] -= A[rankA + i] * C[jpvt[b_j] - 1];
    }
  }

  /* '<S418>:1:16' */
  /* '<S418>:1:17' */
  /* '<S418>:1:18' */
  /* '<S418>:1:21' */
  X[0] = 1.0;
  X[1] = 0.0;
  X[2] = C[0];

  /* '<S418>:1:22' */
  /* '<S418>:1:23' */
  Y[0] = 0.0;
  Y[1] = 1.0;
  Y[2] = C[1];

  /* '<S418>:1:24' */
  /* '<S418>:1:33' */
  rtb_z_out_idx_0 = ((C[0] * 0.3054 + C[1] * -0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_1 = ((C[0] * 0.3054 + C[1] * 0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_2 = ((C[0] * -0.3054 + C[1] * -0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_3 = ((C[0] * -0.3054 + C[1] * 0.392) + C[2]) * 1000.0;

  /* '<S418>:1:34' */
  /* '<S418>:1:43' */
  /* '<S418>:1:44' */
  rtb_avg_g = (((rtb_z_out_idx_0 + rtb_z_out_idx_1) + rtb_z_out_idx_2) +
               rtb_z_out_idx_3) / 4.0;
  if (-C[0] < 0.0) {
    rtb_ZeroCurrentForces_idx_3 = -1.0;
  } else if (-C[0] > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (-C[0] == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  rtb_pitch_e = acos(1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm_l(X))
    * rtb_ZeroCurrentForces_idx_3;
  if (-C[1] < 0.0) {
    rtb_ZeroCurrentForces_idx_3 = -1.0;
  } else if (-C[1] > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (-C[1] == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  rtb_roll = acos(-(-1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm_l(Y)))
    * rtb_ZeroCurrentForces_idx_3;

  /* End of MATLAB Function: '<S410>/FindCoordinates' */

  /* Switch: '<S423>/Switch1' incorporates:
   *  Constant: '<S423>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S423>/Switch1' incorporates:
     *  Lookup_n-D: '<S423>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S423>/Switch1' incorporates:
     *  Constant: '<S423>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S423>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_avg_g,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_h,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);

  /* Switch: '<S415>/Switch' incorporates:
   *  Constant: '<S415>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter != 0.0) {
    rtb_Switch_od =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_h.MovingAverage;
  } else {
    rtb_Switch_od = rtb_avg_g;
  }

  /* End of Switch: '<S415>/Switch' */

  /* Switch: '<S424>/Switch1' incorporates:
   *  Constant: '<S424>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S424>/Switch1' incorporates:
     *  Lookup_n-D: '<S424>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S424>/Switch1' incorporates:
     *  Constant: '<S424>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S424>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_pitch_e,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_kw,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);

  /* Switch: '<S416>/Switch' incorporates:
   *  Constant: '<S416>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter != 0.0) {
    /* Switch: '<S416>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_kw.MovingAverage;
  } else {
    /* Switch: '<S416>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k = rtb_pitch_e;
  }

  /* End of Switch: '<S416>/Switch' */

  /* Switch: '<S425>/Switch1' incorporates:
   *  Constant: '<S425>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S425>/Switch1' incorporates:
     *  Lookup_n-D: '<S425>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S425>/Switch1' incorporates:
     *  Constant: '<S425>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S425>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_roll,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_ka,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);

  /* Switch: '<S417>/Switch' incorporates:
   *  Constant: '<S417>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0) {
    /* Switch: '<S417>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_ka.MovingAverage;
  } else {
    /* Switch: '<S417>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c = rtb_roll;
  }

  /* End of Switch: '<S417>/Switch' */

  /* Gain: '<S6>/To m' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom = 0.001 * rtb_Switch_od;

  /* S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix' incorporates:
   *  Constant: '<S398>/Constant1'
   *  Constant: '<S398>/Constant2'
   *  Constant: '<S398>/Constant3'
   *  SignalConversion generated from: '<S398>/Create Diagonal Matrix'
   */
  for (i = 0; i < 9; i++) {
    rtb_CreateDiagonalMatrix[i] = 0.0;
  }

  rtb_CreateDiagonalMatrix[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_sens;
  rtb_CreateDiagonalMatrix[4] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_sens;
  rtb_CreateDiagonalMatrix[8] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_sens;

  /* End of S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix' */

  /* Outputs for Enabled SubSystem: '<S399>/Correct1' incorporates:
   *  EnablePort: '<S400>/Enable'
   */
  /* MATLAB Function: '<S400>/Correct' incorporates:
   *  DataStoreRead: '<S400>/Data Store ReadP'
   *  DataStoreRead: '<S400>/Data Store ReadX'
   *  S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix'
   *  ZeroOrderHold: '<S398>/Zero-Order Hold'
   */
  /* MATLAB Function 'Extras/EKFCorrect/Correct': '<S403>:1' */
  /* '<S403>:1:11' */
  p = true;
  for (i = 0; i < 9; i++) {
    rtb_ZeroCurrentForces_idx_3 = rtb_CreateDiagonalMatrix[i];
    if (((int32_T)p) && ((!(int32_T)rtIsInf(rtb_ZeroCurrentForces_idx_3)) &&
                         (!(int32_T)rtIsNaN(rtb_ZeroCurrentForces_idx_3)))) {
    } else {
      p = false;
    }
  }

  if (p) {
    PIDcontroller4CoreCentralizedTestReadyMotor_svd(rtb_CreateDiagonalMatrix, Ss,
      X, V);
  } else {
    X[0] = (rtNaN);
    X[1] = (rtNaN);
    X[2] = (rtNaN);
    for (b_j = 0; b_j < 9; b_j++) {
      V[b_j] = (rtNaN);
    }
  }

  for (b_j = 0; b_j < 9; b_j++) {
    Ss[b_j] = 0.0;
  }

  Ss[0] = X[0];
  Ss[4] = X[1];
  Ss[8] = X[2];
  for (i = 0; i < 9; i++) {
    Ss[i] = sqrt(Ss[i]);
  }

  for (b_j = 0; b_j < 3; b_j++) {
    for (i = 0; i < 3; i++) {
      rankA = i + 3 * b_j;
      R[rankA] = 0.0;
      R[rankA] += Ss[3 * b_j] * V[i];
      R[rankA] += Ss[3 * b_j + 1] * V[i + 3];
      R[rankA] += Ss[3 * b_j + 2] * V[i + 6];
    }
  }

  X[0] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[1];
  X[1] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[3];
  X[2] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[5];
  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      imvec[i] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i];
    }

    rtb_ZeroCurrentForces_idx_3 = 1.4901161193847656E-8 * fabs
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[b_j]);
    if ((1.4901161193847656E-8 > rtb_ZeroCurrentForces_idx_3) || ((int32_T)
         rtIsNaN(rtb_ZeroCurrentForces_idx_3))) {
      rtb_ZeroCurrentForces_idx_3 = 1.4901161193847656E-8;
    }

    imvec[b_j] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[b_j] +
      rtb_ZeroCurrentForces_idx_3;
    dHdx[3 * b_j] = (imvec[1] - X[0]) / rtb_ZeroCurrentForces_idx_3;
    dHdx[3 * b_j + 1] = (imvec[3] - X[1]) / rtb_ZeroCurrentForces_idx_3;
    dHdx[3 * b_j + 2] = (imvec[5] - X[2]) / rtb_ZeroCurrentForces_idx_3;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor(dHdx,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->P, R, Ss);
  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      A_0[i + 6 * b_j] = 0.0;
    }
  }

  for (rankA = 0; rankA < 6; rankA++) {
    for (b_j = 0; b_j < 6; b_j++) {
      for (i = 0; i < 6; i++) {
        aoffset = 6 * b_j + i;
        A_0[aoffset] += PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[6 *
          rankA + i] * PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[6 *
          rankA + b_j];
      }
    }
  }

  for (b_j = 0; b_j < 3; b_j++) {
    for (i = 0; i < 6; i++) {
      aoffset = b_j + 3 * i;
      K[aoffset] = 0.0;
      for (rankA = 0; rankA < 6; rankA++) {
        K[aoffset] += A_0[6 * rankA + i] * dHdx[3 * rankA + b_j];
      }
    }
  }

  for (b_j = 0; b_j < 6; b_j++) {
    C_0[3 * b_j] = K[3 * b_j];
    rankA = 3 * b_j + 1;
    C_0[rankA] = K[rankA];
    rankA = 3 * b_j + 2;
    C_0[rankA] = K[rankA];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_trisolve(Ss, C_0);
  for (b_j = 0; b_j < 6; b_j++) {
    b_C[3 * b_j] = C_0[3 * b_j];
    i = 3 * b_j + 1;
    b_C[i] = C_0[i];
    i = 3 * b_j + 2;
    b_C[i] = C_0[i];
  }

  for (b_j = 0; b_j < 3; b_j++) {
    V[3 * b_j] = Ss[b_j];
    V[3 * b_j + 1] = Ss[b_j + 3];
    V[3 * b_j + 2] = Ss[b_j + 6];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_e(V, b_C);
  for (b_j = 0; b_j < 3; b_j++) {
    for (i = 0; i < 6; i++) {
      K[i + 6 * b_j] = b_C[3 * i + b_j];
    }
  }

  for (b_j = 0; b_j < 18; b_j++) {
    C_0[b_j] = -K[b_j];
  }

  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      aoffset = i + 6 * b_j;
      A_0[aoffset] = 0.0;
      A_0[aoffset] += dHdx[3 * b_j] * C_0[i];
      A_0[aoffset] += dHdx[3 * b_j + 1] * C_0[i + 6];
      A_0[aoffset] += dHdx[3 * b_j + 2] * C_0[i + 12];
    }
  }

  for (i = 0; i < 6; i++) {
    aoffset = 6 * i + i;
    A_0[aoffset]++;
  }

  for (b_j = 0; b_j < 6; b_j++) {
    coffset = b_j * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      rtb_ZeroCurrentForces_idx_3 = 0.0;
      for (rankA = 0; rankA < 6; rankA++) {
        rtb_ZeroCurrentForces_idx_3 += A_0[rankA * 6 + b_j] *
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[aoffset + rankA];
      }

      Ss_0[coffset + i] = rtb_ZeroCurrentForces_idx_3;
    }
  }

  for (b_j = 0; b_j < 3; b_j++) {
    for (i = 0; i < 6; i++) {
      aoffset = b_j + 3 * i;
      C_0[aoffset] = 0.0;
      C_0[aoffset] += R[3 * b_j] * K[i];
      C_0[aoffset] += R[3 * b_j + 1] * K[i + 6];
      C_0[aoffset] += R[3 * b_j + 2] * K[i + 12];
    }
  }

  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      Ss_1[i + 9 * b_j] = Ss_0[6 * b_j + i];
    }

    Ss_1[9 * b_j + 6] = C_0[3 * b_j];
    Ss_1[9 * b_j + 7] = C_0[3 * b_j + 1];
    Ss_1[9 * b_j + 8] = C_0[3 * b_j + 2];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_qr(Ss_1, a__1, A_0);

  /* '<S403>:1:135' */
  rtb_ZeroCurrentForces_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom -
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[1];
  rtb_Switch1_j1_idx_0 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c
    - PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[3];
  rtb_Switch1_j1_idx_1 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k
    - PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[5];

  /* Outputs for Atomic SubSystem: '<S399>/Output' */
  for (i = 0; i < 6; i++) {
    /* DataStoreWrite: '<S400>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S400>/Correct'
     */
    for (b_j = 0; b_j < 6; b_j++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[b_j + 6 * i] = A_0[6 *
        b_j + i];
    }

    /* End of DataStoreWrite: '<S400>/Data Store WriteP' */

    /* DataStoreWrite: '<S400>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S400>/Data Store ReadX'
     *  MATLAB Function: '<S400>/Correct'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i] += (K[i + 6] *
      rtb_Switch1_j1_idx_0 + K[i] * rtb_ZeroCurrentForces_idx_3) + K[i + 12] *
      rtb_Switch1_j1_idx_1;

    /* DataStoreRead: '<S401>/Data Store Read' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i];
  }

  /* End of Outputs for SubSystem: '<S399>/Output' */
  /* End of Outputs for SubSystem: '<S399>/Correct1' */

  /* Gain: '<S6>/To mm' */
  /* MATLAB Function 'Extended Kalman Filter/Output/MATLAB Function': '<S404>:1' */
  /* '<S404>:1:4' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm = 1000.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[1];

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  if ((int32_T)
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_o
      == 1) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
      = 0.0;
  }

  /* Sum: '<S8>/Subtract1' incorporates:
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
   *  Gain: '<S8>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm -
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_I *
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SkipKalman != 0.0) {
    /* Switch: '<Root>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0] = rtb_Switch_od;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;
  } else {
    /* Switch: '<Root>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[5];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[3];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S33>/Sum' incorporates:
   *  Outport: '<Root>/ActualReferenceAirgap'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->error =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ActualReferenceAirgap -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0];

  /* RelationalOperator: '<S73>/Equal' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S108>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S103>/Filter'
   */
  p = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o
        <= 0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S103>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState <=
        0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE = 0.0;
  }

  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S71>/Constant3'
   *  Constant: '<S71>/Constant4'
   *  Lookup_n-D: '<S71>/n-D Lookup Table1'
   *  Saturate: '<S71>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [2] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_d_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_d;
  }

  /* End of Switch: '<S71>/Switch2' */

  /* Switch: '<S125>/Switch1' incorporates:
   *  Constant: '<S125>/Constant4'
   *  Constant: '<S125>/N'
   *  Lookup_n-D: '<S125>/n-D Lookup Table'
   *  Saturate: '<S71>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [3] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_Tc_array, 1U);
  } else {
    rtb_ZeroCurrentForces_idx_3 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_T_c;
  }

  /* End of Switch: '<S125>/Switch1' */

  /* Product: '<S111>/NProd Out' incorporates:
   *  Constant: '<S125>/Constant'
   *  DiscreteIntegrator: '<S103>/Filter'
   *  Product: '<S102>/DProd Out'
   *  Product: '<S125>/Divide'
   *  Sum: '<S103>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->error * rtb_Switch1_j1_idx_0
     - PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE) *
    (6.2831853071795862 / rtb_ZeroCurrentForces_idx_3);

  /* Switch: '<S71>/Switch1' incorporates:
   *  Constant: '<S71>/Constant1'
   *  Constant: '<S71>/Constant4'
   *  Lookup_n-D: '<S71>/n-D Lookup Table'
   *  Saturate: '<S71>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [0] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_p_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_p;
  }

  /* End of Switch: '<S71>/Switch1' */

  /* Sum: '<S117>/Sum' incorporates:
   *  DiscreteIntegrator: '<S108>/Integrator'
   *  Product: '<S113>/PProd Out'
   */
  rtb_Sum_h = (PIDcontroller4CoreCentralizedTestReadyMotor_B->error *
               rtb_Switch1_j1_idx_0 +
               PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut;

  /* Product: '<S33>/Divide1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1 = rtb_Divide *
    rtb_Sum_h;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn != 0.0) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionCurrent;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Subtract' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Subtract_c = rtb_Switch_od -
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MotorAirgapOffset;

  /* Trigonometry: '<S3>/Trigonometric Function' */
  rtb_TrigonometricFunction = sin
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k);

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Gain: '<S3>/Gain'
   *  Product: '<S3>/Product'
   */
  for (i = 0; i < 39; i++) {
    rtb_Add_e[i] = PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled16[i]
      * rtb_TrigonometricFunction * -1000.0 + rtb_Subtract_c;
  }

  /* End of Sum: '<S3>/Add' */

  /* Lookup_n-D: '<S3>/1-D Lookup Table1' incorporates:
   *  Switch: '<S3>/Switch'
   */
  bpIndices[0U] = plook_binx
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n,
     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_bp01Data,
     21U, &rtb_ZeroCurrentForces_idx_3);
  fractions[0U] = rtb_ZeroCurrentForces_idx_3;
  for (i = 0; i < 39; i++) {
    bpIndices[1U] = plook_binx(rtb_Add_e[i],
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_bp02Data,
      54U, &rtb_ZeroCurrentForces_idx_3);
    fractions[1U] = rtb_ZeroCurrentForces_idx_3;
    rtb_uDLookupTable1[i] = intrp2d_l_pw(bpIndices, fractions,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_tableData,
      22U);
  }

  /* End of Lookup_n-D: '<S3>/1-D Lookup Table1' */

  /* Sum: '<S3>/Sum' */
  rtb_ZeroCurrentForces_idx_3 = -0.0;
  for (aoffset = 0; aoffset < 39; aoffset++) {
    rtb_ZeroCurrentForces_idx_3 += rtb_uDLookupTable1[aoffset];
  }

  /* Gain: '<S3>/Gain2' incorporates:
   *  Sum: '<S3>/Sum'
   */
  rtb_Gain2 = 0.025641025641025661 * rtb_ZeroCurrentForces_idx_3;
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(rtb_Gain2,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfp,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);

  /* Switch: '<S396>/Switch1' incorporates:
   *  Constant: '<S396>/Constant5'
   *  Constant: '<S396>/Constant7'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->motorforce_on != 0.0) {
    rtb_Switch1_d =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfp.MovingAverage;
  } else {
    rtb_Switch1_d = 0.0;
  }

  /* End of Switch: '<S396>/Switch1' */

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S23>/Constant'
   */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms
                    <= 0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
      = 0.0;
  }

  /* Sum: '<S23>/Add3' incorporates:
   *  Constant: '<S23>/Constant6'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator3'
   */
  rtb_Add3 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass -
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE;

  /* Product: '<S3>/Gravity' incorporates:
   *  Constant: '<S3>/Gravitational constant [m//s^2]'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity = -9.81 * rtb_Add3;

  /* Sum: '<S3>/Sum1' */
  rtb_Sum1 = rtb_Switch1_d +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity;

  /* Sum: '<S35>/Add' */
  rtb_Add_l = (0.0 - PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1) -
    rtb_Sum1;

  /* Gain: '<S34>/Gain4' incorporates:
   *  Constant: '<S34>/2'
   *  Gain: '<S36>/Gain5'
   *  Math: '<S34>/Square1'
   */
  rtb_Switch1_j1_idx_1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeight *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeight *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeightFactor;

  /* Gain: '<S34>/Gain' incorporates:
   *  Constant: '<S34>/3'
   *  Gain: '<S34>/Gain3'
   *  Gain: '<S34>/Gain4'
   *  Math: '<S34>/Square'
   *  Sum: '<S34>/Sum1'
   */
  rtb_Gain_no = (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLength *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLength *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLengthFactor
                 + rtb_Switch1_j1_idx_1) *
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass / 12.0);

  /* Sum: '<S183>/Subtract5' incorporates:
   *  Constant: '<S183>/Constant4'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - -1.0;

  /* Switch: '<S183>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o != 0.0) {
    /* Switch: '<S183>/Switch' incorporates:
     *  Constant: '<S183>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o = 0.0;
  } else {
    /* Switch: '<S183>/Switch' incorporates:
     *  Gain: '<S37>/Gain1'
     *  Sum: '<S37>/Subtract'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o =
      -(((rtb_Switch_k_idx_0 + rtb_Switch_k_idx_1) - rtb_Switch_k_idx_2) -
        rtb_Switch_k_idx_3);
  }

  /* End of Switch: '<S183>/Switch' */

  /* DiscreteIntegrator: '<S269>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
  }

  /* SampleTimeMath: '<S264>/Tsamp' incorporates:
   *  Gain: '<S261>/Derivative Gain'
   *
   * About '<S264>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o * 4000.0;

  /* Delay: '<S262>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Sum: '<S278>/Sum' incorporates:
   *  Delay: '<S262>/UD'
   *  DiscreteIntegrator: '<S269>/Integrator'
   *  Gain: '<S274>/Proportional Gain'
   *  Sum: '<S262>/Diff'
   */
  rtb_Sum_ac = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o);

  /* Switch: '<S183>/Switch1' incorporates:
   *  Constant: '<S183>/Constant'
   *  Constant: '<S183>/Constant2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = rtb_Sum_ac;
  }

  /* End of Switch: '<S183>/Switch1' */

  /* Sum: '<S34>/Plus' incorporates:
   *  Constant: '<S34>/Base Ref Airgap1'
   *  Gain: '<S177>/Gain1'
   *  Gain: '<S178>/Gain1'
   *  Sum: '<S34>/Plus1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch =
    (0.017453292519943295 * rtb_Switch1_j1_idx_0 + 0.017453292519943295 *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RefPitch) +
    rtb_Switch2_idx_1;

  /* Sum: '<S34>/Subtract' */
  rtb_error_m = PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1];

  /* Gain: '<S34>/Gain2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 = 952.0 * rtb_error_m;

  /* Abs: '<S179>/Abs' incorporates:
   *  Delay: '<S179>/Delay'
   */
  rtb_ZeroCurrentForces_idx_3 = fabs
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_h);

  /* Saturate: '<S179>/Saturation' */
  if (rtb_ZeroCurrentForces_idx_3 > 5.0) {
    rtb_Saturation_gj = 5.0;
  } else {
    rtb_Saturation_gj = rtb_ZeroCurrentForces_idx_3;
  }

  /* End of Saturate: '<S179>/Saturation' */

  /* RelationalOperator: '<S34>/Equal' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S218>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S213>/Filter'
   */
  p = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
        <= 0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
  }

  /* DiscreteIntegrator: '<S213>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j <=
        0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
  }

  /* Switch: '<S179>/Switch2' incorporates:
   *  Constant: '<S179>/Constant3'
   *  Constant: '<S179>/Constant4'
   *  Lookup_n-D: '<S179>/n-D Lookup Table1'
   *  Saturate: '<S179>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Pitch_GainSchedulingEnabled
      [3] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation_gj,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_d_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_d;
  }

  /* End of Switch: '<S179>/Switch2' */

  /* Switch: '<S184>/Switch1' incorporates:
   *  Constant: '<S184>/Constant4'
   *  Constant: '<S184>/N'
   *  Lookup_n-D: '<S184>/n-D Lookup Table'
   *  Saturate: '<S179>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Pitch_GainSchedulingEnabled
      [4] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = look1_binlxpw(rtb_Saturation_gj,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_Tc_array, 1U);
  } else {
    rtb_ZeroCurrentForces_idx_3 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_T_c;
  }

  /* End of Switch: '<S184>/Switch1' */

  /* Product: '<S221>/NProd Out' incorporates:
   *  Constant: '<S184>/Constant'
   *  DiscreteIntegrator: '<S213>/Filter'
   *  Product: '<S184>/Divide'
   *  Product: '<S212>/DProd Out'
   *  Sum: '<S213>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 * rtb_Switch1_j1_idx_0
     - PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i) *
    (6.2831853071795862 / rtb_ZeroCurrentForces_idx_3);

  /* Switch: '<S179>/Switch1' incorporates:
   *  Constant: '<S179>/Constant1'
   *  Constant: '<S179>/Constant4'
   *  Lookup_n-D: '<S179>/n-D Lookup Table'
   *  Saturate: '<S179>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Pitch_GainSchedulingEnabled
      [0] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation_gj,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_p_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_p;
  }

  /* End of Switch: '<S179>/Switch1' */

  /* Sum: '<S227>/Sum' incorporates:
   *  DiscreteIntegrator: '<S218>/Integrator'
   *  Product: '<S223>/PProd Out'
   */
  rtb_Sum_ih = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 *
                rtb_Switch1_j1_idx_0 +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e;

  /* Product: '<S34>/Product' incorporates:
   *  Constant: '<S34>/Reference_P_Inertia'
   *  Gain: '<S34>/Gain1'
   *  Product: '<S34>/Divide'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product = rtb_Gain_no /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Reference_P_Inertia *
    (2.049 * rtb_Sum_ih);

  /* Sum: '<S3>/Sum2' */
  rtb_ZeroCurrentForces_idx_3 = -0.0;
  for (aoffset = 0; aoffset < 39; aoffset++) {
    /* Sum: '<S3>/Sum2' incorporates:
     *  Constant: '<S3>/Constant6'
     *  Product: '<S3>/Product2'
     */
    rtb_ZeroCurrentForces_idx_3 +=
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled16[aoffset] *
      rtb_uDLookupTable1[aoffset];
  }

  /* Gain: '<S3>/Gain3' incorporates:
   *  Sum: '<S3>/Sum2'
   */
  rtb_Gain3_a = 0.025641025641025661 * rtb_ZeroCurrentForces_idx_3;
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(rtb_Gain3_a,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

  /* Logic: '<S23>/OR' incorporates:
   *  Constant: '<S23>/Constant'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->OR = (boolean_T)
    ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms != 0.0) ||
     ((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal));

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator2'
   */
  p = (boolean_T)!(int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
        <= 0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
  }

  /* Sum: '<S23>/Add2' incorporates:
   *  Constant: '<S23>/Constant3'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   */
  rtb_Add2 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->X_Arm_Offset +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Product: '<S3>/Product3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1 = -(rtb_Add2 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity);

  /* Switch: '<S395>/Switch1' incorporates:
   *  Constant: '<S395>/Constant5'
   *  Constant: '<S395>/Constant7'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->motorforce_on != 0.0) {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe.MovingAverage;
  } else {
    rtb_Switch1_j1_idx_0 = 0.0;
  }

  /* End of Switch: '<S395>/Switch1' */

  /* Sum: '<S3>/Add1' */
  rtb_Add1 = rtb_Switch1_j1_idx_0 +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1;

  /* Sum: '<S35>/Add1' */
  rtb_Add1_k = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product - rtb_Add1;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/LongDistance'
   */
  rtb_Divide_k = rtb_Add1_k / 0.3054;

  /* Gain: '<S36>/Gain' incorporates:
   *  Constant: '<S36>/1'
   *  Gain: '<S36>/Gain4'
   *  Math: '<S36>/Square'
   *  Sum: '<S36>/Sum1'
   */
  rtb_Gain_mn = (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidth *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidth *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidthFactor
                 + rtb_Switch1_j1_idx_1) *
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass / 12.0);

  /* Sum: '<S291>/Subtract5' incorporates:
   *  Constant: '<S291>/Constant4'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - -1.0;

  /* Switch: '<S291>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l != 0.0) {
    /* Switch: '<S291>/Switch' incorporates:
     *  Constant: '<S291>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p = 0.0;
  } else {
    /* Switch: '<S291>/Switch' incorporates:
     *  Gain: '<S37>/Gain'
     *  Sum: '<S37>/Subtract1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p =
      -(((rtb_Switch_k_idx_1 - rtb_Switch_k_idx_0) - rtb_Switch_k_idx_2) +
        rtb_Switch_k_idx_3);
  }

  /* End of Switch: '<S291>/Switch' */

  /* DiscreteIntegrator: '<S377>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
  }

  /* SampleTimeMath: '<S372>/Tsamp' incorporates:
   *  Gain: '<S369>/Derivative Gain'
   *
   * About '<S372>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p * 4000.0;

  /* Delay: '<S370>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Sum: '<S386>/Sum' incorporates:
   *  Delay: '<S370>/UD'
   *  DiscreteIntegrator: '<S377>/Integrator'
   *  Gain: '<S382>/Proportional Gain'
   *  Sum: '<S370>/Diff'
   */
  rtb_Sum_a4 = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l);

  /* Switch: '<S291>/Switch1' incorporates:
   *  Constant: '<S291>/Constant'
   *  Constant: '<S291>/Constant2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = rtb_Sum_a4;
  }

  /* End of Switch: '<S291>/Switch1' */

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Base Ref Airgap1'
   *  Gain: '<S286>/Gain1'
   *  Gain: '<S287>/Gain1'
   *  Sum: '<S36>/Add1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll =
    (0.017453292519943295 *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RefRoll +
     0.017453292519943295 * rtb_Switch1_j1_idx_0) + rtb_Switch2_idx_2;

  /* Gain: '<S36>/Gain3' incorporates:
   *  Sum: '<S36>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2]) * 401.61;

  /* Gain: '<S36>/Gain2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e = 1.02 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3;

  /* Abs: '<S288>/Abs' incorporates:
   *  Delay: '<S288>/Delay'
   */
  rtb_ZeroCurrentForces_idx_3 = fabs
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m);

  /* Saturate: '<S288>/Saturation' */
  if (rtb_ZeroCurrentForces_idx_3 > 5.0) {
    rtb_Saturation_gd = 5.0;
  } else {
    rtb_Saturation_gd = rtb_ZeroCurrentForces_idx_3;
  }

  /* End of Saturate: '<S288>/Saturation' */

  /* RelationalOperator: '<S36>/Equal' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S326>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S321>/Filter'
   */
  tmp = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
        <= 0)) || (((int32_T)tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
  }

  /* DiscreteIntegrator: '<S321>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k <=
        0)) || (((int32_T)tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
  }

  /* Switch: '<S288>/Switch2' incorporates:
   *  Constant: '<S288>/Constant3'
   *  Constant: '<S288>/Constant4'
   *  Lookup_n-D: '<S288>/n-D Lookup Table1'
   *  Saturate: '<S288>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Roll_GainSchedulingEnabled
      [3] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation_gd,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_d_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_d;
  }

  /* End of Switch: '<S288>/Switch2' */

  /* Switch: '<S292>/Switch1' incorporates:
   *  Constant: '<S292>/Constant4'
   *  Constant: '<S292>/N'
   *  Lookup_n-D: '<S292>/n-D Lookup Table'
   *  Saturate: '<S288>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Roll_GainSchedulingEnabled
      [4] != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = look1_binlxpw(rtb_Saturation_gd,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_Tc_array, 1U);
  } else {
    rtb_ZeroCurrentForces_idx_3 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_T_c;
  }

  /* End of Switch: '<S292>/Switch1' */

  /* Product: '<S329>/NProd Out' incorporates:
   *  Constant: '<S292>/Constant'
   *  DiscreteIntegrator: '<S321>/Filter'
   *  Product: '<S292>/Divide'
   *  Product: '<S320>/DProd Out'
   *  Sum: '<S321>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
     rtb_Switch1_j1_idx_0 -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h) *
    (6.2831853071795862 / rtb_ZeroCurrentForces_idx_3);

  /* Switch: '<S288>/Switch1' incorporates:
   *  Constant: '<S288>/Constant1'
   *  Constant: '<S288>/Constant4'
   *  Lookup_n-D: '<S288>/n-D Lookup Table'
   *  Saturate: '<S288>/Saturation'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Roll_GainSchedulingEnabled
      [0] != 0.0) {
    rtb_Switch1_j1_idx_0 = look1_binlxpw(rtb_Saturation_gd,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->GS_breakpoints,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_p_array, 2U);
  } else {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_p;
  }

  /* End of Switch: '<S288>/Switch1' */

  /* Sum: '<S335>/Sum' incorporates:
   *  DiscreteIntegrator: '<S326>/Integrator'
   *  Product: '<S331>/PProd Out'
   */
  rtb_Sum_oi = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
                rtb_Switch1_j1_idx_0 +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k;

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S36>/Reference_R_Inertia'
   *  Gain: '<S36>/Gain1'
   *  Product: '<S36>/Divide'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h = rtb_Gain_mn /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Reference_R_Inertia *
    (1.02 * rtb_Sum_oi);

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
        <= 0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S23>/Constant5'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->EMS_Moment_Arm_Z +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k;

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator2' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
        <= 0)) || (((int32_T)p) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
  }

  /* Sum: '<S23>/Add1' incorporates:
   *  Constant: '<S23>/Constant4'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator2'
   */
  rtb_Add1_n = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Y_Arm_Offset +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE;

  /* Gain: '<S3>/Gain4' incorporates:
   *  Product: '<S3>/Product4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain4 = -(rtb_Add1_n *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity);

  /* Sum: '<S3>/Add2' incorporates:
   *  Inport: '<Root>/EMS_F_Back'
   *  Inport: '<Root>/EMS_F_Front'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Sum of Elements'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Add *
     PIDcontroller4CoreCentralizedTestReadyMotor_U->EMS_F_Front +
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Add *
     PIDcontroller4CoreCentralizedTestReadyMotor_U->EMS_F_Back) +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain4;

  /* Sum: '<S35>/Add2' */
  rtb_Add2_m = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/LatDistance'
   */
  rtb_Divide1 = rtb_Add2_m / 0.392;

  /* Switch: '<S410>/Switch1' incorporates:
   *  Constant: '<S410>/Constant3'
   *  Constant: '<S410>/Constant5'
   *  Sum: '<S410>/Add1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LinposOn != 0.0) {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[0] +
      rtb_z_out_idx_0;
    rtb_Switch1_j1_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[1] +
      rtb_z_out_idx_1;
    rtb_z_out_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[2] +
      rtb_z_out_idx_2;
    rtb_z_out_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[3] +
      rtb_z_out_idx_3;
  } else {
    rtb_Switch1_j1_idx_0 = rtb_Switch_ph;
    rtb_Switch1_j1_idx_1 = rtb_Switch_k1;
    rtb_z_out_idx_1 = rtb_Switch_ds;
    rtb_z_out_idx_0 = rtb_Switch_gn;
  }

  /* End of Switch: '<S410>/Switch1' */

  /* Switch: '<S426>/Switch1' incorporates:
   *  Constant: '<S426>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S426>/Switch1' incorporates:
     *  Lookup_n-D: '<S426>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h = look1_binlxpw
      (rtb_Saturation,
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
       PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S426>/Switch1' incorporates:
     *  Constant: '<S426>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorLinpos;
  }

  /* End of Switch: '<S426>/Switch1' */

  /* MATLABSystem: '<S409>/Moving Average' incorporates:
   *  Switch: '<S410>/Switch1'
   */
  rtb_ZeroCurrentForces_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.ForgettingFactor;
  p = false;
  if ((rtb_ZeroCurrentForces_idx_3 ==
       PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h) || (((int32_T)
        rtIsNaN(rtb_ZeroCurrentForces_idx_3)) && ((int32_T)rtIsNaN
        (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h)))) {
    p = true;
  }

  if (!(int32_T)p) {
    p = (boolean_T)
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isInitialized == 1);
    if (p) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.TunablePropsChanged =
        true;
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.ForgettingFactor =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.TunablePropsChanged)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.TunablePropsChanged =
      false;
    obj = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.pStatistic;
    p = (boolean_T)(obj->isInitialized == 1);
    if (p) {
      obj->TunablePropsChanged = true;
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_DW->
      obj_i.pStatistic->ForgettingFactor =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.ForgettingFactor;
  }

  obj = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN[0] = 0.0;
    obj->pmN[1] = 0.0;
    obj->pmN[2] = 0.0;
    obj->pmN[3] = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN[0] = 0.0;
    obj->pmN[1] = 0.0;
    obj->pmN[2] = 0.0;
    obj->pmN[3] = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  rtb_ZeroCurrentForces_idx_3 = obj->pwN;
  zz[0] = obj->pmN[0];
  zz[1] = obj->pmN[1];
  zz[2] = obj->pmN[2];
  zz[3] = obj->pmN[3];
  rtb_F_array_idx_1 = obj->plambda;
  rtb_z_out_idx_3 = 1.0 - 1.0 / rtb_ZeroCurrentForces_idx_3;
  rtb_z_out_idx_2 = 1.0 / rtb_ZeroCurrentForces_idx_3;
  zz[0] = rtb_z_out_idx_3 * zz[0] + rtb_z_out_idx_2 * rtb_Switch1_j1_idx_0;
  zz[1] = rtb_z_out_idx_3 * zz[1] + rtb_z_out_idx_2 * rtb_Switch1_j1_idx_1;
  zz[2] = rtb_z_out_idx_3 * zz[2] + rtb_z_out_idx_2 * rtb_z_out_idx_1;
  zz[3] = rtb_z_out_idx_3 * zz[3] + rtb_z_out_idx_2 * rtb_z_out_idx_0;
  obj->pwN = rtb_F_array_idx_1 * rtb_ZeroCurrentForces_idx_3 + 1.0;
  obj->pmN[0] = zz[0];
  obj->pmN[1] = zz[1];
  obj->pmN[2] = zz[2];
  obj->pmN[3] = zz[3];

  /* Switch: '<S409>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S409>/Constant1'
   *  MATLABSystem: '<S409>/Moving Average'
   *  Sum: '<S15>/Subtract'
   */
  p = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LinposFilter != 0.0);
  if (p) {
    rtb_Switch1_j1_idx_0 = zz[0];
  }

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Switch1_j1_idx_0 +=
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[0];

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch1_j1_idx_0 > 25.0) {
    rtb_Saturation_k_idx_0 = 25.0;
  } else if (rtb_Switch1_j1_idx_0 < 5.0) {
    rtb_Saturation_k_idx_0 = 5.0;
  } else {
    rtb_Saturation_k_idx_0 = rtb_Switch1_j1_idx_0;
  }

  /* Sum: '<S15>/Subtract' */
  rtb_z_out_idx_3 = rtb_Switch1_j1_idx_0;

  /* Switch: '<S409>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  MATLABSystem: '<S409>/Moving Average'
   *  Sum: '<S15>/Subtract'
   */
  if (p) {
    rtb_Switch1_j1_idx_1 = zz[1];
  }

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Switch1_j1_idx_0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[1] +
    rtb_Switch1_j1_idx_1;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch1_j1_idx_0 > 25.0) {
    rtb_Switch1_j1_idx_1 = 25.0;
  } else if (rtb_Switch1_j1_idx_0 < 5.0) {
    rtb_Switch1_j1_idx_1 = 5.0;
  } else {
    rtb_Switch1_j1_idx_1 = rtb_Switch1_j1_idx_0;
  }

  /* Sum: '<S15>/Subtract' */
  rtb_z_out_idx_2 = rtb_Switch1_j1_idx_0;

  /* Switch: '<S409>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  MATLABSystem: '<S409>/Moving Average'
   *  Sum: '<S15>/Subtract'
   */
  if (p) {
    rtb_z_out_idx_1 = zz[2];
  }

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Switch1_j1_idx_0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[2] +
    rtb_z_out_idx_1;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch1_j1_idx_0 > 25.0) {
    rtb_Saturation_k_idx_2 = 25.0;
  } else if (rtb_Switch1_j1_idx_0 < 5.0) {
    rtb_Saturation_k_idx_2 = 5.0;
  } else {
    rtb_Saturation_k_idx_2 = rtb_Switch1_j1_idx_0;
  }

  /* Sum: '<S15>/Subtract' */
  rtb_z_out_idx_1 = rtb_Switch1_j1_idx_0;

  /* Switch: '<S409>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  MATLABSystem: '<S409>/Moving Average'
   *  Sum: '<S15>/Subtract'
   */
  if (p) {
    rtb_z_out_idx_0 = zz[3];
  }

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Switch1_j1_idx_0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[3] +
    rtb_z_out_idx_0;

  /* Lookup_n-D: '<S406>/2-D Lookup Table3' incorporates:
   *  Constant: '<S406>/Constant'
   *  Saturate: '<S7>/Saturation'
   */
  bpIndices_0[0U] = plook_binxp(0.0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28, 29U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01);
  fractions_0[0U] = rtb_ZeroCurrentForces_idx_3;
  bpIndices_0[1U] = plook_binxp(rtb_Saturation_k_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[0]);
  fractions_0[1U] = rtb_ZeroCurrentForces_idx_3;
  rtb_z_out_idx_0 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  bpIndices_0[1U] = plook_binxp(rtb_Switch1_j1_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[1]);
  fractions_0[1U] = rtb_ZeroCurrentForces_idx_3;
  rtb_Switch1_j1_idx_1 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  bpIndices_0[1U] = plook_binxp(rtb_Saturation_k_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[2]);
  fractions_0[1U] = rtb_ZeroCurrentForces_idx_3;
  rtb_Saturation_k_idx_0 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch1_j1_idx_0 > 25.0) {
    rtb_Saturation_k_idx_2 = 25.0;
  } else if (rtb_Switch1_j1_idx_0 < 5.0) {
    rtb_Saturation_k_idx_2 = 5.0;
  } else {
    rtb_Saturation_k_idx_2 = rtb_Switch1_j1_idx_0;
  }

  /* Lookup_n-D: '<S406>/2-D Lookup Table3' */
  bpIndices_0[1U] = plook_binxp(rtb_Saturation_k_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[3]);
  fractions_0[1U] = rtb_ZeroCurrentForces_idx_3;
  rtb_ZeroCurrentForces_idx_3 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);

  /* MATLAB Function: '<S406>/MATLAB Function' incorporates:
   *  Constant: '<S406>/Constant1'
   *  Lookup_n-D: '<S406>/2-D Lookup Table3'
   */
  /* MATLAB Function 'Force Solver/Force Divider1/MATLAB Function': '<S407>:1' */
  /* '<S407>:1:2' */
  /* '<S407>:1:3' */
  /* '<S407>:1:4' */
  /* '<S407>:1:5' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MagnetFailure == 0U) {
    /* '<S407>:1:9' */
    rtb_Saturation_k_idx_2 = rtb_z_out_idx_0 * rtb_z_out_idx_0;
    rtb_F_array_idx_1 = rtb_Switch1_j1_idx_1 * rtb_Switch1_j1_idx_1;
    rtb_F_array_idx_2 = rtb_Saturation_k_idx_2 * 2.0;
    rtb_F_array_idx_3 = rtb_F_array_idx_2 * rtb_F_array_idx_1;
    rtb_F_array_idx_0 = rtb_Saturation_k_idx_2 * rtb_F_array_idx_1;
    tol_tmp = rtb_F_array_idx_0 * rtb_ZeroCurrentForces_idx_3;
    tol_tmp_0 = rtb_Saturation_k_idx_0 * rtb_Saturation_k_idx_0;
    rtb_Saturation_k_idx_2 *= tol_tmp_0;
    tol_tmp_1 = rtb_Saturation_k_idx_2 * rtb_ZeroCurrentForces_idx_3;
    tol_tmp_tmp = rtb_F_array_idx_1 * tol_tmp_0;
    tol_tmp_2 = tol_tmp_tmp * rtb_ZeroCurrentForces_idx_3;
    tol_tmp_3 = rtb_ZeroCurrentForces_idx_3 * rtb_ZeroCurrentForces_idx_3;
    rtb_ZeroCurrentForces_idx_3 = (((((((((rtb_F_array_idx_3 * tol_tmp_0 -
      rtb_F_array_idx_3 * rtb_Saturation_k_idx_0 * rtb_ZeroCurrentForces_idx_3)
      + tol_tmp * rtb_Add_l) - tol_tmp * rtb_Divide_k) - rtb_F_array_idx_2 *
      rtb_Switch1_j1_idx_1 * tol_tmp_0 * rtb_ZeroCurrentForces_idx_3) +
      tol_tmp_1 * rtb_Add_l) + tol_tmp_1 * rtb_Divide1) + 2.0 * rtb_z_out_idx_0 *
      rtb_F_array_idx_1 * tol_tmp_0 * rtb_ZeroCurrentForces_idx_3) - tol_tmp_2 *
      rtb_Divide_k) + tol_tmp_2 * rtb_Divide1) * rtb_ZeroCurrentForces_idx_3 /
      ((((rtb_F_array_idx_0 * tol_tmp_0 + rtb_F_array_idx_0 * tol_tmp_3) +
         rtb_Saturation_k_idx_2 * tol_tmp_3) + tol_tmp_tmp * tol_tmp_3) * 2.0);
  } else {
    /* '<S407>:1:7' */
  }

  /* '<S407>:1:11' */
  /* '<S407>:1:12' */
  /* '<S407>:1:13' */
  /* '<S407>:1:14' */
  rtb_F_array_idx_0 = (rtb_Divide_k - rtb_Divide1) / 2.0 +
    rtb_ZeroCurrentForces_idx_3;
  rtb_F_array_idx_1 = (rtb_Divide1 + rtb_Add_l) / 2.0 -
    rtb_ZeroCurrentForces_idx_3;
  rtb_F_array_idx_2 = (rtb_Add_l - rtb_Divide_k) / 2.0 -
    rtb_ZeroCurrentForces_idx_3;
  rtb_F_array_idx_3 = rtb_ZeroCurrentForces_idx_3;

  /* End of MATLAB Function: '<S406>/MATLAB Function' */

  /* DSPFlip: '<S27>/Flip1' incorporates:
   *  Constant: '<S27>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i];
  }

  /* End of DSPFlip: '<S27>/Flip1' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_z_out_idx_3 > 25.0) {
    rtb_Saturation_k_idx_2 = 25.0;
  } else if (rtb_z_out_idx_3 < 5.0) {
    rtb_Saturation_k_idx_2 = 5.0;
  } else {
    rtb_Saturation_k_idx_2 = rtb_z_out_idx_3;
  }

  if (rtb_z_out_idx_2 > 25.0) {
    rtb_z_out_idx_0 = 25.0;
  } else if (rtb_z_out_idx_2 < 5.0) {
    rtb_z_out_idx_0 = 5.0;
  } else {
    rtb_z_out_idx_0 = rtb_z_out_idx_2;
  }

  if (rtb_z_out_idx_1 > 25.0) {
    rtb_Switch1_j1_idx_1 = 25.0;
  } else if (rtb_z_out_idx_1 < 5.0) {
    rtb_Switch1_j1_idx_1 = 5.0;
  } else {
    rtb_Switch1_j1_idx_1 = rtb_z_out_idx_1;
  }

  if (rtb_Switch1_j1_idx_0 > 25.0) {
    rtb_Saturation_k_idx_0 = 25.0;
  } else if (rtb_Switch1_j1_idx_0 < 5.0) {
    rtb_Saturation_k_idx_0 = 5.0;
  } else {
    rtb_Saturation_k_idx_0 = rtb_Switch1_j1_idx_0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Lookup_n-D: '<S27>/2-D Lookup Table2' incorporates:
   *  Constant: '<S27>/Constant'
   */
  bpIndices_1[1U] = plook_binxp(rtb_Saturation_k_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_p);
  fractions_1[1U] = rtb_ZeroCurrentForces_idx_3;
  for (i = 0; i < 30; i++) {
    bpIndices_1[0U] = plook_binxp
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28, 29U,
       &rtb_ZeroCurrentForces_idx_3,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_m[i]);
    fractions_1[0U] = rtb_ZeroCurrentForces_idx_3;
    rtb_uDLookupTable2[i] = intrp2d_l_pw(bpIndices_1, fractions_1,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  }

  /* End of Lookup_n-D: '<S27>/2-D Lookup Table2' */

  /* DSPFlip: '<S27>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip[i] = rtb_uDLookupTable2[29 - i];
    rtb_Flip[29 - i] = rtb_uDLookupTable2[i];
  }

  /* End of DSPFlip: '<S27>/Flip' */

  /* Lookup_n-D: '<S27>/2-D Lookup Table1' incorporates:
   *  Gain: '<S27>/Gain'
   */
  rtb_uDLookupTable1_l = look1_pbinlxpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * rtb_F_array_idx_0,
     rtb_Flip, PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_fj, 29U);

  /* MinMax: '<S27>/Max' incorporates:
   *  Delay: '<S27>/Delay2'
   *  Delay: '<S27>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE))) {
    /* MinMax: '<S27>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE;
  } else {
    /* MinMax: '<S27>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE;
  }

  /* End of MinMax: '<S27>/Max' */

  /* Sum: '<S27>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4 =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S27>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4 != 0.0) {
    /* Switch: '<S27>/Switch' incorporates:
     *  Saturate: '<S27>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max != 0.0) {
      /* Saturate: '<S27>/Saturation1' */
      if (rtb_uDLookupTable1_l > 9.0) {
        rtb_ZeroCurrentForces_idx_3 = 9.0;
      } else if (rtb_uDLookupTable1_l < -9.0) {
        rtb_ZeroCurrentForces_idx_3 = -9.0;
      } else {
        rtb_ZeroCurrentForces_idx_3 = rtb_uDLookupTable1_l;
      }

      /* Saturate: '<S27>/Saturation' */
      if (rtb_ZeroCurrentForces_idx_3 > 5.6) {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 5.6;
      } else if (rtb_ZeroCurrentForces_idx_3 < -5.6) {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = -5.6;
      } else {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i =
          rtb_ZeroCurrentForces_idx_3;
      }

      /* End of Saturate: '<S27>/Saturation' */
    } else if (rtb_uDLookupTable1_l > 9.0) {
      /* Saturate: '<S27>/Saturation1' incorporates:
       *  Switch: '<S27>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 9.0;
    } else if (rtb_uDLookupTable1_l < -9.0) {
      /* Saturate: '<S27>/Saturation1' incorporates:
       *  Switch: '<S27>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = -9.0;
    } else {
      /* Switch: '<S27>/Switch2' incorporates:
       *  Saturate: '<S27>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i =
        rtb_uDLookupTable1_l;
    }

    /* End of Switch: '<S27>/Switch' */
  } else {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 0.0;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* MATLAB Function: '<S22>/Cap requested current' incorporates:
   *  Constant: '<S22>/Ampere'
   */
  /* MATLAB Function 'Subsystem5/Cap requested current': '<S742>:1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i - rtb_Gain1[0] >
      3.0) {
    /* '<S742>:1:4' */
    /* '<S742>:1:5' */
    rtb_out_req_I = rtb_Gain1[0] + 3.0;
  } else if (rtb_Gain1[0] -
             PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i > 3.0) {
    /* '<S742>:1:6' */
    /* '<S742>:1:7' */
    rtb_out_req_I = rtb_Gain1[0] - 3.0;
  } else {
    /* '<S742>:1:9' */
    rtb_out_req_I = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i;
  }

  /* End of MATLAB Function: '<S22>/Cap requested current' */

  /* DSPFlip: '<S28>/Flip1' incorporates:
   *  Constant: '<S28>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_g[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_g[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i];
  }

  /* End of DSPFlip: '<S28>/Flip1' */

  /* Lookup_n-D: '<S28>/2-D Lookup Table2' incorporates:
   *  Constant: '<S28>/Constant'
   */
  bpIndices_2[1U] = plook_binxp(rtb_z_out_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_i);
  fractions_2[1U] = rtb_ZeroCurrentForces_idx_3;
  for (i = 0; i < 30; i++) {
    bpIndices_2[0U] = plook_binxp
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28, 29U,
       &rtb_ZeroCurrentForces_idx_3,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_b[i]);
    fractions_2[0U] = rtb_ZeroCurrentForces_idx_3;
    rtb_uDLookupTable2_e5[i] = intrp2d_l_pw(bpIndices_2, fractions_2,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  }

  /* End of Lookup_n-D: '<S28>/2-D Lookup Table2' */

  /* DSPFlip: '<S28>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_a[i] = rtb_uDLookupTable2_e5[29 - i];
    rtb_Flip_a[29 - i] = rtb_uDLookupTable2_e5[i];
  }

  /* End of DSPFlip: '<S28>/Flip' */

  /* Lookup_n-D: '<S28>/2-D Lookup Table1' incorporates:
   *  Gain: '<S28>/Gain'
   */
  rtb_uDLookupTable1_h = look1_pbinlxpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * rtb_F_array_idx_1,
     rtb_Flip_a, PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_g,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_gr, 29U);

  /* MinMax: '<S28>/Max' incorporates:
   *  Delay: '<S28>/Delay2'
   *  Delay: '<S28>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_g >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l))) {
    /* MinMax: '<S28>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_l =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_g;
  } else {
    /* MinMax: '<S28>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_l =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l;
  }

  /* End of MinMax: '<S28>/Max' */

  /* Sum: '<S28>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_i =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S28>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_i != 0.0) {
    /* Switch: '<S28>/Switch' incorporates:
     *  Saturate: '<S28>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_l != 0.0) {
      /* Saturate: '<S28>/Saturation1' */
      if (rtb_uDLookupTable1_h > 9.0) {
        rtb_ZeroCurrentForces_idx_3 = 9.0;
      } else if (rtb_uDLookupTable1_h < -9.0) {
        rtb_ZeroCurrentForces_idx_3 = -9.0;
      } else {
        rtb_ZeroCurrentForces_idx_3 = rtb_uDLookupTable1_h;
      }

      /* Saturate: '<S28>/Saturation' */
      if (rtb_ZeroCurrentForces_idx_3 > 5.6) {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = 5.6;
      } else if (rtb_ZeroCurrentForces_idx_3 < -5.6) {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = -5.6;
      } else {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n =
          rtb_ZeroCurrentForces_idx_3;
      }

      /* End of Saturate: '<S28>/Saturation' */
    } else if (rtb_uDLookupTable1_h > 9.0) {
      /* Saturate: '<S28>/Saturation1' incorporates:
       *  Switch: '<S28>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = 9.0;
    } else if (rtb_uDLookupTable1_h < -9.0) {
      /* Saturate: '<S28>/Saturation1' incorporates:
       *  Switch: '<S28>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = -9.0;
    } else {
      /* Switch: '<S28>/Switch2' incorporates:
       *  Saturate: '<S28>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n =
        rtb_uDLookupTable1_h;
    }

    /* End of Switch: '<S28>/Switch' */
  } else {
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = 0.0;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* MATLAB Function: '<S22>/Cap requested current1' incorporates:
   *  Constant: '<S22>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[1],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent1);

  /* DSPFlip: '<S29>/Flip1' incorporates:
   *  Constant: '<S29>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_k[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_k[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i];
  }

  /* End of DSPFlip: '<S29>/Flip1' */

  /* Lookup_n-D: '<S29>/2-D Lookup Table2' incorporates:
   *  Constant: '<S29>/Constant'
   */
  bpIndices_3[1U] = plook_binxp(rtb_Switch1_j1_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_j);
  fractions_3[1U] = rtb_ZeroCurrentForces_idx_3;
  for (i = 0; i < 30; i++) {
    bpIndices_3[0U] = plook_binxp
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28, 29U,
       &rtb_ZeroCurrentForces_idx_3,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_n[i]);
    fractions_3[0U] = rtb_ZeroCurrentForces_idx_3;
    rtb_uDLookupTable2_bq[i] = intrp2d_l_pw(bpIndices_3, fractions_3,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  }

  /* End of Lookup_n-D: '<S29>/2-D Lookup Table2' */

  /* DSPFlip: '<S29>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_l[i] = rtb_uDLookupTable2_bq[29 - i];
    rtb_Flip_l[29 - i] = rtb_uDLookupTable2_bq[i];
  }

  /* End of DSPFlip: '<S29>/Flip' */

  /* Lookup_n-D: '<S29>/2-D Lookup Table1' incorporates:
   *  Gain: '<S29>/Gain'
   */
  rtb_uDLookupTable1_j = look1_pbinlxpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * rtb_F_array_idx_2,
     rtb_Flip_l, PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_k,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_h, 29U);

  /* MinMax: '<S29>/Max' incorporates:
   *  Delay: '<S29>/Delay2'
   *  Delay: '<S29>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_p >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g))) {
    /* MinMax: '<S29>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_p;
  } else {
    /* MinMax: '<S29>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g;
  }

  /* End of MinMax: '<S29>/Max' */

  /* Sum: '<S29>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_a =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S29>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_a != 0.0) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Saturate: '<S29>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_e != 0.0) {
      /* Saturate: '<S29>/Saturation1' */
      if (rtb_uDLookupTable1_j > 9.0) {
        rtb_ZeroCurrentForces_idx_3 = 9.0;
      } else if (rtb_uDLookupTable1_j < -9.0) {
        rtb_ZeroCurrentForces_idx_3 = -9.0;
      } else {
        rtb_ZeroCurrentForces_idx_3 = rtb_uDLookupTable1_j;
      }

      /* Saturate: '<S29>/Saturation' */
      if (rtb_ZeroCurrentForces_idx_3 > 5.6) {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = 5.6;
      } else if (rtb_ZeroCurrentForces_idx_3 < -5.6) {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = -5.6;
      } else {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h =
          rtb_ZeroCurrentForces_idx_3;
      }

      /* End of Saturate: '<S29>/Saturation' */
    } else if (rtb_uDLookupTable1_j > 9.0) {
      /* Saturate: '<S29>/Saturation1' incorporates:
       *  Switch: '<S29>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = 9.0;
    } else if (rtb_uDLookupTable1_j < -9.0) {
      /* Saturate: '<S29>/Saturation1' incorporates:
       *  Switch: '<S29>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = -9.0;
    } else {
      /* Switch: '<S29>/Switch2' incorporates:
       *  Saturate: '<S29>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h =
        rtb_uDLookupTable1_j;
    }

    /* End of Switch: '<S29>/Switch' */
  } else {
    /* Switch: '<S29>/Switch2' incorporates:
     *  Constant: '<S29>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = 0.0;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* MATLAB Function: '<S22>/Cap requested current2' incorporates:
   *  Constant: '<S22>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[2],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent2);

  /* DSPFlip: '<S30>/Flip1' incorporates:
   *  Constant: '<S30>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_h[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_h[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i];
  }

  /* End of DSPFlip: '<S30>/Flip1' */

  /* Lookup_n-D: '<S30>/2-D Lookup Table2' incorporates:
   *  Constant: '<S30>/Constant'
   */
  bpIndices_4[1U] = plook_binxp(rtb_Saturation_k_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29, 350U,
    &rtb_ZeroCurrentForces_idx_3,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_o);
  fractions_4[1U] = rtb_ZeroCurrentForces_idx_3;
  for (i = 0; i < 30; i++) {
    bpIndices_4[0U] = plook_binxp
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28, 29U,
       &rtb_ZeroCurrentForces_idx_3,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_f[i]);
    fractions_4[0U] = rtb_ZeroCurrentForces_idx_3;
    rtb_uDLookupTable2_j[i] = intrp2d_l_pw(bpIndices_4, fractions_4,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 30U);
  }

  /* End of Lookup_n-D: '<S30>/2-D Lookup Table2' */

  /* DSPFlip: '<S30>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_p[i] = rtb_uDLookupTable2_j[29 - i];
    rtb_Flip_p[29 - i] = rtb_uDLookupTable2_j[i];
  }

  /* End of DSPFlip: '<S30>/Flip' */

  /* Lookup_n-D: '<S30>/2-D Lookup Table1' incorporates:
   *  Gain: '<S30>/Gain'
   */
  rtb_uDLookupTable1_p = look1_pbinlxpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * rtb_F_array_idx_3,
     rtb_Flip_p, PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_h,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_ep, 29U);

  /* MinMax: '<S30>/Max' incorporates:
   *  Delay: '<S30>/Delay2'
   *  Delay: '<S30>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_k >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f))) {
    /* MinMax: '<S30>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_k;
  } else {
    /* MinMax: '<S30>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f;
  }

  /* End of MinMax: '<S30>/Max' */

  /* Sum: '<S30>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_e =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S30>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_e != 0.0) {
    /* Switch: '<S30>/Switch' incorporates:
     *  Saturate: '<S30>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j != 0.0) {
      /* Saturate: '<S30>/Saturation1' */
      if (rtb_uDLookupTable1_p > 9.0) {
        rtb_ZeroCurrentForces_idx_3 = 9.0;
      } else if (rtb_uDLookupTable1_p < -9.0) {
        rtb_ZeroCurrentForces_idx_3 = -9.0;
      } else {
        rtb_ZeroCurrentForces_idx_3 = rtb_uDLookupTable1_p;
      }

      /* Saturate: '<S30>/Saturation' */
      if (rtb_ZeroCurrentForces_idx_3 > 5.6) {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = 5.6;
      } else if (rtb_ZeroCurrentForces_idx_3 < -5.6) {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = -5.6;
      } else {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e =
          rtb_ZeroCurrentForces_idx_3;
      }

      /* End of Saturate: '<S30>/Saturation' */
    } else if (rtb_uDLookupTable1_p > 9.0) {
      /* Saturate: '<S30>/Saturation1' incorporates:
       *  Switch: '<S30>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = 9.0;
    } else if (rtb_uDLookupTable1_p < -9.0) {
      /* Saturate: '<S30>/Saturation1' incorporates:
       *  Switch: '<S30>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = -9.0;
    } else {
      /* Switch: '<S30>/Switch2' incorporates:
       *  Saturate: '<S30>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e =
        rtb_uDLookupTable1_p;
    }

    /* End of Switch: '<S30>/Switch' */
  } else {
    /* Switch: '<S30>/Switch2' incorporates:
     *  Constant: '<S30>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = 0.0;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* MATLAB Function: '<S22>/Cap requested current3' incorporates:
   *  Constant: '<S22>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[3],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent3);

  /* Gain: '<Root>/Gain' */
  rtb_ZeroCurrentForces_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity * rtb_out_req_I;
  rtb_F_array_idx_2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent1.out_req_I;
  rtb_F_array_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent2.out_req_I;
  rtb_F_array_idx_0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent3.out_req_I;

  /* Sum: '<S17>/Subtract2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2 = 0.0 -
    rtb_ZeroCurrentForces_idx_3;

  /* SampleTimeMath: '<S561>/Tsamp' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Product: '<S558>/DProd Out'
   *
   * About '<S561>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_kb =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_d * 4000.0;

  /* Sum: '<S575>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Delay: '<S559>/UD'
   *  DiscreteIntegrator: '<S566>/Integrator'
   *  Product: '<S571>/PProd Out'
   *  Sum: '<S559>/Diff'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2 *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_p +
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_h) +
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_kb -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_g);

  /* Outport: '<Root>/I_A' incorporates:
   *  Sum: '<S17>/Subtract3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_A =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum +
    rtb_ZeroCurrentForces_idx_3;

  /* Outport: '<Root>/Airgap' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Airgap =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0];

  /* Derivative: '<Root>/Derivative' incorporates:
   *  Derivative: '<Root>/Derivative1'
   */
  rtb_ZeroCurrentForces_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA >=
       rtb_ZeroCurrentForces_idx_3) &&
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB >=
       rtb_ZeroCurrentForces_idx_3)) {
    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative[0] = 0.0;
    rtb_Derivative[1] = 0.0;
    rtb_Derivative[2] = 0.0;
  } else {
    rtb_F_array_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA;
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA;
    if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA <
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB) {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB <
          rtb_ZeroCurrentForces_idx_3) {
        rtb_F_array_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB;
        lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
      }
    } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA >=
               rtb_ZeroCurrentForces_idx_3) {
      rtb_F_array_idx_1 =
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB;
      lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
    }

    rtb_F_array_idx_1 = rtb_ZeroCurrentForces_idx_3 - rtb_F_array_idx_1;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative[0] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0] - (*lastU)[0])
      / rtb_F_array_idx_1;
    rtb_Derivative[1] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1] - (*lastU)[1])
      / rtb_F_array_idx_1;
    rtb_Derivative[2] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2] - (*lastU)[2])
      / rtb_F_array_idx_1;
  }

  /* End of Derivative: '<Root>/Derivative' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(rtb_Derivative,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);

  /* Derivative: '<Root>/Derivative1' */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l >=
       rtb_ZeroCurrentForces_idx_3) &&
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b >=
       rtb_ZeroCurrentForces_idx_3)) {
    /* Derivative: '<Root>/Derivative1' */
    rtb_Derivative1[0] = 0.0;
    rtb_Derivative1[1] = 0.0;
    rtb_Derivative1[2] = 0.0;
  } else {
    rtb_F_array_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l;
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g;
    if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l <
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b) {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b <
          rtb_ZeroCurrentForces_idx_3) {
        rtb_F_array_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b;
        lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
      }
    } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l >=
               rtb_ZeroCurrentForces_idx_3) {
      rtb_F_array_idx_1 =
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b;
      lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
    }

    rtb_F_array_idx_1 = rtb_ZeroCurrentForces_idx_3 - rtb_F_array_idx_1;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  MATLABSystem: '<Root>/Moving Average'
     */
    rtb_Derivative1[0] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [0] - (*lastU)[0]) / rtb_F_array_idx_1;
    rtb_Derivative1[1] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [1] - (*lastU)[1]) / rtb_F_array_idx_1;
    rtb_Derivative1[2] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [2] - (*lastU)[2]) / rtb_F_array_idx_1;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(rtb_Derivative1,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpg);

  /* Outport: '<Root>/Acceleration' incorporates:
   *  MATLABSystem: '<Root>/Moving Average1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [0];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [1];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [2];

  /* Outport: '<Root>/Calculated Force' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/Moving Average1'
   *  Product: '<Root>/Product'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [0] * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [1] * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
    [2] * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* Outport: '<Root>/Speed' incorporates:
   *  MATLABSystem: '<Root>/Moving Average'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[0];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[2];

  /* Sum: '<S18>/Subtract2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_e = 0.0 -
    rtb_F_array_idx_2;

  /* SampleTimeMath: '<S614>/Tsamp' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Product: '<S611>/DProd Out'
   *
   * About '<S614>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_e *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_d * 4000.0;

  /* Sum: '<S628>/Sum' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Delay: '<S612>/UD'
   *  DiscreteIntegrator: '<S619>/Integrator'
   *  Product: '<S624>/PProd Out'
   *  Sum: '<S612>/Diff'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_e *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_p +
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_d) +
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k0 -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_e);

  /* Outport: '<Root>/I_B' incorporates:
   *  Sum: '<S18>/Subtract3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_B =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d + rtb_F_array_idx_2;

  /* Sum: '<S20>/Subtract2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_f = 0.0 -
    rtb_F_array_idx_3;

  /* SampleTimeMath: '<S720>/Tsamp' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Product: '<S717>/DProd Out'
   *
   * About '<S720>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_f *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_d * 4000.0;

  /* Sum: '<S734>/Sum' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Delay: '<S718>/UD'
   *  DiscreteIntegrator: '<S725>/Integrator'
   *  Product: '<S730>/PProd Out'
   *  Sum: '<S718>/Diff'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_f *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_p +
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_p) +
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_o -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_h);

  /* Outport: '<Root>/I_C' incorporates:
   *  Sum: '<S20>/Subtract3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_C =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b + rtb_F_array_idx_3;

  /* Sum: '<S19>/Subtract2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_c = 0.0 -
    rtb_F_array_idx_0;

  /* SampleTimeMath: '<S667>/Tsamp' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Product: '<S664>/DProd Out'
   *
   * About '<S667>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_c *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_d * 4000.0;

  /* Sum: '<S681>/Sum' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Delay: '<S665>/UD'
   *  DiscreteIntegrator: '<S672>/Integrator'
   *  Product: '<S677>/PProd Out'
   *  Sum: '<S665>/Diff'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_c *
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_p +
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_m) +
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_g -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_ei);

  /* Outport: '<Root>/I_D' incorporates:
   *  Sum: '<S19>/Subtract3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_D =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c + rtb_F_array_idx_0;

  /* Outport: '<Root>/Pitch' incorporates:
   *  Gain: '<S9>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Pitch = 57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1];

  /* Outport: '<Root>/Roll' incorporates:
   *  Gain: '<S10>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Roll = 57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2];

  /* Outport: '<Root>/Linpos' incorporates:
   *  Sum: '<S15>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[0] = rtb_z_out_idx_3;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[1] = rtb_z_out_idx_2;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[2] = rtb_z_out_idx_1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[3] =
    rtb_Switch1_j1_idx_0;

  /* Outport: '<Root>/PitchError' incorporates:
   *  Gain: '<S181>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->PitchError = 57.295779513082323
    * rtb_error_m;

  /* Outport: '<Root>/BeamErrorOutput' incorporates:
   *  Gain: '<S11>/Gain'
   *  Gain: '<S12>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[0] =
    rtb_Switch2_idx_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[1] =
    57.295779513082323 * rtb_Switch2_idx_1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[2] =
    57.295779513082323 * rtb_Switch2_idx_2;

  /* Outport: '<Root>/Control SIgnals' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[0] = rtb_Add_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[1] = rtb_Add1_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[2] = rtb_Add2_m;

  /* Outport: '<Root>/External Forces' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[0] = rtb_Sum1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[1] = rtb_Add1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Lookup_n-D: '<S21>/2-D Lookup Table2' */
  rtb_uDLookupTable2_cw = look2_pbinlxpw(rtb_Switch_k_idx_0, rtb_z_out_idx_3,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_k,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled37, 30U);

  /* Delay: '<Root>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[0];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[2];

  /* Lookup_n-D: '<S21>/2-D Lookup Table1' */
  rtb_uDLookupTable1_os = look2_pbinlxpw(rtb_Switch_k_idx_1, rtb_z_out_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_a,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled37, 30U);

  /* Lookup_n-D: '<S21>/2-D Lookup Table3' */
  rtb_uDLookupTable3 = look2_pbinlxpw(rtb_Switch_k_idx_2, rtb_z_out_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_c,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled37, 30U);

  /* Lookup_n-D: '<S21>/2-D Lookup Table4' */
  rtb_uDLookupTable4 = look2_pbinlxpw(rtb_Switch_k_idx_3, rtb_Switch1_j1_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled28,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled29,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_j,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled37, 30U);

  /* Gain: '<S21>/Gain' */
  rtb_ZeroCurrentForces_idx_3 = 1.0 /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f;

  /* Product: '<S21>/Product' incorporates:
   *  Gain: '<S21>/Gain'
   *  Sum: '<S21>/Add'
   *  Sum: '<S21>/Add1'
   *  Sum: '<S21>/Add2'
   *  Sum: '<S21>/Add3'
   *  Sum: '<S21>/Add4'
   *  Sum: '<S21>/Add5'
   *  Sum: '<S21>/Add6'
   *  Sum: '<S21>/Add7'
   */
  rtb_Switch_k_idx_0 = ((rtb_uDLookupTable2_cw +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1]) -
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * rtb_ZeroCurrentForces_idx_3 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Switch_k_idx_1 = ((rtb_uDLookupTable1_os +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1]) +
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * rtb_ZeroCurrentForces_idx_3 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Switch_k_idx_2 = ((rtb_uDLookupTable3 -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1]) -
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * rtb_ZeroCurrentForces_idx_3 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Switch_k_idx_3 = ((rtb_uDLookupTable4 -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1]) +
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * rtb_ZeroCurrentForces_idx_3 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/Constant3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchedHEMSLateral >
      0.0) {
    /* Outport: '<Root>/HEMSForces' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[0] =
      rtb_Switch_k_idx_0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[1] =
      rtb_Switch_k_idx_1;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[2] =
      rtb_Switch_k_idx_2;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[3] =
      rtb_Switch_k_idx_3;
  } else {
    /* Outport: '<Root>/HEMSForces' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[0] =
      rtb_uDLookupTable4;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[1] =
      rtb_uDLookupTable3;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[2] =
      rtb_uDLookupTable1_os;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[3] =
      rtb_uDLookupTable2_cw;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'Calculate External Force/MATLAB Function': '<S394>:1' */
  /* '<S394>:1:4' */
  /* '<S394>:1:5' */
  /* '<S394>:1:7' */
  rtb_ZeroCurrentForces_idx_3 = rtb_uDLookupTable1[0];

  /* '<S394>:1:8' */
  rtb_F_array_idx_1 = rtb_uDLookupTable1[20];
  for (i = 0; i < 18; i++) {
    rtb_ZeroCurrentForces_idx_3 += rtb_uDLookupTable1[i + 1];
    rtb_F_array_idx_1 += rtb_uDLookupTable1[i + 21];
  }

  /* Outport: '<Root>/motorfrontback' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* '<S394>:1:10' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[0] =
    rtb_ZeroCurrentForces_idx_3 / 19.0 / 2.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[1] =
    rtb_F_array_idx_1 / 19.0 / 2.0;

  /* Outport: '<Root>/DataBeforeKalman' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[0] =
    rtb_Switch_od;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[1] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[2] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;

  /* Sum: '<S397>/Sum1' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<S397>/Abs'
   *  Gain: '<S397>/Gain1'
   *  Inport: '<Root>/Vr1'
   *  Inport: '<Root>/Vr2'
   *  Inport: '<Root>/Vr3'
   *  Inport: '<Root>/Vr4'
   *  Inport: '<Root>/Vt1'
   *  Inport: '<Root>/Vt2'
   *  Inport: '<Root>/Vt3'
   *  Inport: '<Root>/Vt4'
   *  Product: '<S397>/Product'
   *  Sum: '<Root>/Subtract2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1 = ((fabs
    (PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr1 -
     PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt1) * fabs(rtb_Gain1[0]) *
    2.0 + fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr2 -
               PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt2) * fabs
    (rtb_Gain1[1]) * 2.0) + fabs
    (PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr3 -
     PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt3) * fabs(rtb_Gain1[2]) *
    2.0) + fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr4 -
                PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt4) * fabs
    (rtb_Gain1[3]) * 2.0;

  /* Outport: '<Root>/Power' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Power =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1;

  /* MATLABSystem: '<S397>/Moving Average' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.TunablePropsChanged) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.TunablePropsChanged =
      false;
  }

  obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.pStatistic;
  if (obj_0->isInitialized != 1) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1;
    obj_0->pCumSum = 0.0;
    for (i = 0; i < 3999; i++) {
      obj_0->pCumSumRev[i] = 0.0;
    }

    obj_0->pCumRevIndex = 1.0;
    obj_0->isSetupComplete = true;
    obj_0->pCumSum = 0.0;
    for (i = 0; i < 3999; i++) {
      obj_0->pCumSumRev[i] = 0.0;
    }

    obj_0->pCumRevIndex = 1.0;
  }

  /* Outport: '<Root>/Power_avg' incorporates:
   *  MATLABSystem: '<S397>/Moving Average'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Power_avg =
    PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
    (obj_0, PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1);

  /* DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
      = 0.0;
  }

  /* Outport: '<Root>/Energy' incorporates:
   *  DiscreteIntegrator: '<S397>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Energy =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i;

  /* Sum: '<S4>/Add' */
  rtb_Switch2_idx_0 = ((rtb_uDLookupTable4 + rtb_uDLookupTable3) +
                       rtb_uDLookupTable1_os) + rtb_uDLookupTable2_cw;

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/LongDistance'
   *  Product: '<S4>/Product'
   */
  rtb_Switch2_idx_1 = ((rtb_uDLookupTable4 * 0.3054 + rtb_uDLookupTable3 *
                        0.3054) + rtb_uDLookupTable1_os *
                       PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain)
    + rtb_uDLookupTable2_cw *
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/LatDistance'
   *  Product: '<S4>/Product1'
   */
  rtb_Switch2_idx_2 = ((PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain1
                        * rtb_uDLookupTable4 + 0.392 * rtb_uDLookupTable3) +
                       PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain1 *
                       rtb_uDLookupTable1_os) + 0.392 * rtb_uDLookupTable2_cw;

  /* Outport: '<Root>/CalculatedTPR' incorporates:
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[0] =
    rtb_Switch2_idx_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[1] =
    rtb_Switch2_idx_1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[2] =
    rtb_Switch2_idx_2;

  /* Delay: '<S27>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c;

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g;

  /* End of DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  /* Delay: '<S27>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[0];

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay > 0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay <= 0.0)
                   && ((int32_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
                       == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_o2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c;

  /* End of DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  /* Switch: '<S27>/Switch4' incorporates:
   *  Constant: '<S27>/Constant11'
   *  Sum: '<S27>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4 = (real_T)
    (rtb_DiscreteTimeIntegrator_c - 1.0 >= 0.0);

  /* Switch: '<S27>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4 != 0.0) {
    /* Switch: '<S27>/Switch6' incorporates:
     *  Constant: '<S27>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6 = 0.0;
  } else {
    /* Switch: '<S27>/Switch6' incorporates:
     *  Constant: '<S27>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6 = -1.0;
  }

  /* End of Switch: '<S27>/Switch6' */

  /* Switch: '<S27>/Switch3' incorporates:
   *  Abs: '<S27>/Abs3'
   *  Constant: '<S27>/Constant9'
   *  Inport: '<Root>/I_A_m'
   *  Sum: '<S27>/Subtract5'
   */
  if (fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->I_A_m) - 5.6 > 0.0) {
    /* Switch: '<S27>/Switch3' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3 = 1.0;
  } else {
    /* Switch: '<S27>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3 =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6;
  }

  /* End of Switch: '<S27>/Switch3' */

  /* Switch: '<S27>/Switch5' incorporates:
   *  Constant: '<S27>/Constant12'
   *  Sum: '<S27>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5 = (real_T)
    (rtb_DiscreteTimeIntegrator1_o2 - 1.0 >= 0.0);

  /* Switch: '<S27>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract8'
   *  Sum: '<S27>/Subtract9'
   *  Switch: '<S27>/Switch8'
   *  Switch: '<S27>/Switch9'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = (real_T)!(13.0 - rtb_Saturation_k_idx_2 > 0.0);
    rtb_Switch1_j1_idx_0 = (real_T)!(rtb_Saturation_k_idx_2 - 17.0 > 0.0);

    /* MinMax: '<S27>/Max1' incorporates:
     *  Sum: '<S27>/Subtract8'
     *  Sum: '<S27>/Subtract9'
     *  Switch: '<S27>/Switch8'
     *  Switch: '<S27>/Switch9'
     */
    if (rtb_ZeroCurrentForces_idx_3 < rtb_Switch1_j1_idx_0) {
      /* Switch: '<S27>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 =
        rtb_ZeroCurrentForces_idx_3;
    } else {
      /* Switch: '<S27>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 =
        rtb_Switch1_j1_idx_0;
    }

    /* End of MinMax: '<S27>/Max1' */
  } else {
    /* Switch: '<S27>/Switch7' incorporates:
     *  Constant: '<S27>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 = 0.0;
  }

  /* End of Switch: '<S27>/Switch7' */

  /* Delay: '<S28>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c5;

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_m
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_e2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_m;

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  /* Delay: '<S28>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[0];

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_p
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_j =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_p;

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  /* Switch: '<S28>/Switch4' incorporates:
   *  Constant: '<S28>/Constant11'
   *  Sum: '<S28>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_c = (real_T)
    (rtb_DiscreteTimeIntegrator_e2 - 1.0 >= 0.0);

  /* Switch: '<S28>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_c != 0.0) {
    /* Switch: '<S28>/Switch6' incorporates:
     *  Constant: '<S28>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_e = 0.0;
  } else {
    /* Switch: '<S28>/Switch6' incorporates:
     *  Constant: '<S28>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_e = -1.0;
  }

  /* End of Switch: '<S28>/Switch6' */

  /* Switch: '<S28>/Switch3' incorporates:
   *  Abs: '<S28>/Abs3'
   *  Constant: '<S28>/Constant9'
   *  Inport: '<Root>/I_B_m'
   *  Sum: '<S28>/Subtract5'
   */
  if (fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->I_B_m) - 5.6 > 0.0) {
    /* Switch: '<S28>/Switch3' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m = 1.0;
  } else {
    /* Switch: '<S28>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_e;
  }

  /* End of Switch: '<S28>/Switch3' */

  /* Switch: '<S28>/Switch5' incorporates:
   *  Constant: '<S28>/Constant12'
   *  Sum: '<S28>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g = (real_T)
    (rtb_DiscreteTimeIntegrator1_j - 1.0 >= 0.0);

  /* Switch: '<S28>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   *  Sum: '<S28>/Subtract8'
   *  Sum: '<S28>/Subtract9'
   *  Switch: '<S28>/Switch8'
   *  Switch: '<S28>/Switch9'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = (real_T)!(13.0 - rtb_z_out_idx_0 > 0.0);
    rtb_Switch1_j1_idx_0 = (real_T)!(rtb_z_out_idx_0 - 17.0 > 0.0);

    /* MinMax: '<S28>/Max1' incorporates:
     *  Sum: '<S28>/Subtract8'
     *  Sum: '<S28>/Subtract9'
     *  Switch: '<S28>/Switch8'
     *  Switch: '<S28>/Switch9'
     */
    if (rtb_ZeroCurrentForces_idx_3 < rtb_Switch1_j1_idx_0) {
      /* Switch: '<S28>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e =
        rtb_ZeroCurrentForces_idx_3;
    } else {
      /* Switch: '<S28>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e =
        rtb_Switch1_j1_idx_0;
    }

    /* End of MinMax: '<S28>/Max1' */
  } else {
    /* Switch: '<S28>/Switch7' incorporates:
     *  Constant: '<S28>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e = 0.0;
  }

  /* End of Switch: '<S28>/Switch7' */

  /* Delay: '<S29>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_b;

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_d
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_d =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_d;

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  /* Delay: '<S29>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0];

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_f =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b;

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  /* Switch: '<S29>/Switch4' incorporates:
   *  Constant: '<S29>/Constant11'
   *  Sum: '<S29>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g = (real_T)
    (rtb_DiscreteTimeIntegrator_d - 1.0 >= 0.0);

  /* Switch: '<S29>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g != 0.0) {
    /* Switch: '<S29>/Switch6' incorporates:
     *  Constant: '<S29>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_l = 0.0;
  } else {
    /* Switch: '<S29>/Switch6' incorporates:
     *  Constant: '<S29>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_l = -1.0;
  }

  /* End of Switch: '<S29>/Switch6' */

  /* Switch: '<S29>/Switch3' incorporates:
   *  Abs: '<S29>/Abs3'
   *  Constant: '<S29>/Constant9'
   *  Inport: '<Root>/I_C_m'
   *  Sum: '<S29>/Subtract5'
   */
  if (fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->I_C_m) - 5.6 > 0.0) {
    /* Switch: '<S29>/Switch3' incorporates:
     *  Constant: '<S29>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_a = 1.0;
  } else {
    /* Switch: '<S29>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_a =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_l;
  }

  /* End of Switch: '<S29>/Switch3' */

  /* Switch: '<S29>/Switch5' incorporates:
   *  Constant: '<S29>/Constant12'
   *  Sum: '<S29>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_a = (real_T)
    (rtb_DiscreteTimeIntegrator1_f - 1.0 >= 0.0);

  /* Switch: '<S29>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   *  Sum: '<S29>/Subtract8'
   *  Sum: '<S29>/Subtract9'
   *  Switch: '<S29>/Switch8'
   *  Switch: '<S29>/Switch9'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = (real_T)!(13.0 - rtb_Switch1_j1_idx_1 > 0.0);
    rtb_Switch1_j1_idx_0 = (real_T)!(rtb_Switch1_j1_idx_1 - 17.0 > 0.0);

    /* MinMax: '<S29>/Max1' incorporates:
     *  Sum: '<S29>/Subtract8'
     *  Sum: '<S29>/Subtract9'
     *  Switch: '<S29>/Switch8'
     *  Switch: '<S29>/Switch9'
     */
    if (rtb_ZeroCurrentForces_idx_3 < rtb_Switch1_j1_idx_0) {
      /* Switch: '<S29>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_d =
        rtb_ZeroCurrentForces_idx_3;
    } else {
      /* Switch: '<S29>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_d =
        rtb_Switch1_j1_idx_0;
    }

    /* End of MinMax: '<S29>/Max1' */
  } else {
    /* Switch: '<S29>/Switch7' incorporates:
     *  Constant: '<S29>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_d = 0.0;
  }

  /* End of Switch: '<S29>/Switch7' */

  /* Delay: '<S30>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g;

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_ov =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a;

  /* End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  /* Delay: '<S30>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[0];

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_m
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_m;

  /* End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  /* Switch: '<S30>/Switch4' incorporates:
   *  Constant: '<S30>/Constant11'
   *  Sum: '<S30>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_k = (real_T)
    (rtb_DiscreteTimeIntegrator_ov - 1.0 >= 0.0);

  /* Switch: '<S30>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_k != 0.0) {
    /* Switch: '<S30>/Switch6' incorporates:
     *  Constant: '<S30>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_n = 0.0;
  } else {
    /* Switch: '<S30>/Switch6' incorporates:
     *  Constant: '<S30>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_n = -1.0;
  }

  /* End of Switch: '<S30>/Switch6' */

  /* Switch: '<S30>/Switch3' incorporates:
   *  Abs: '<S30>/Abs3'
   *  Constant: '<S30>/Constant9'
   *  Inport: '<Root>/I_D_m'
   *  Sum: '<S30>/Subtract5'
   */
  if (fabs(PIDcontroller4CoreCentralizedTestReadyMotor_U->I_D_m) - 5.6 > 0.0) {
    /* Switch: '<S30>/Switch3' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p = 1.0;
  } else {
    /* Switch: '<S30>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_n;
  }

  /* End of Switch: '<S30>/Switch3' */

  /* Switch: '<S30>/Switch5' incorporates:
   *  Constant: '<S30>/Constant12'
   *  Sum: '<S30>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c = (real_T)
    (rtb_DiscreteTimeIntegrator1_g - 1.0 >= 0.0);

  /* Switch: '<S30>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   *  Sum: '<S30>/Subtract8'
   *  Sum: '<S30>/Subtract9'
   *  Switch: '<S30>/Switch8'
   *  Switch: '<S30>/Switch9'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_ZeroCurrentForces_idx_3 = (real_T)!(13.0 - rtb_Saturation_k_idx_0 > 0.0);
    rtb_Switch1_j1_idx_0 = (real_T)!(rtb_Saturation_k_idx_0 - 17.0 > 0.0);

    /* MinMax: '<S30>/Max1' incorporates:
     *  Sum: '<S30>/Subtract8'
     *  Sum: '<S30>/Subtract9'
     *  Switch: '<S30>/Switch8'
     *  Switch: '<S30>/Switch9'
     */
    if (rtb_ZeroCurrentForces_idx_3 < rtb_Switch1_j1_idx_0) {
      /* Switch: '<S30>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_a =
        rtb_ZeroCurrentForces_idx_3;
    } else {
      /* Switch: '<S30>/Switch7' */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_a =
        rtb_Switch1_j1_idx_0;
    }

    /* End of MinMax: '<S30>/Max1' */
  } else {
    /* Switch: '<S30>/Switch7' incorporates:
     *  Constant: '<S30>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_a = 0.0;
  }

  /* End of Switch: '<S30>/Switch7' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S31>/Switch1' incorporates:
     *  Lookup_n-D: '<S31>/n-D Lookup Table'
     *  Saturate: '<S71>/Saturation'
     */
    rtb_Switch1_fn = look1_binlxpw(rtb_Saturation,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled4,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/Constant'
     */
    rtb_Switch1_fn =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorLinpos;
  }

  /* End of Switch: '<S31>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(0.0, rtb_Switch1_fn,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);

  /* Product: '<S105>/IProd Out' incorporates:
   *  Constant: '<S71>/Constant2'
   */
  rtb_IProdOut = PIDcontroller4CoreCentralizedTestReadyMotor_B->error *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_i;

  /* Signum: '<S99>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0) {
    rtb_ZeroCurrentForces_idx_3 = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S99>/SignPreIntegrator' */

  /* DataTypeConversion: '<S99>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_ZeroCurrentForces_idx_3);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* DeadZone: '<S101>/DeadZone' */
  if (rtb_Sum_h >= (rtMinusInf)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of DeadZone: '<S101>/DeadZone' */

  /* Switch: '<S99>/Switch' incorporates:
   *  DataTypeConversion: '<S99>/DataTypeConv1'
   *  DataTypeConversion: '<S99>/DataTypeConv2'
   *  Gain: '<S99>/ZeroGain'
   *  Logic: '<S99>/AND3'
   *  RelationalOperator: '<S99>/Equal1'
   *  RelationalOperator: '<S99>/NotEqual'
   */
  if ((0.0 * rtb_Sum_h != rtb_ZeroCurrentForces_idx_3) && ((rtb_Switch1_j1_idx_0
        < 0.0 ? (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)(uint8_T)rtb_Switch1_j1_idx_0) ==
       0)) {
    /* Switch: '<S99>/Switch' incorporates:
     *  Constant: '<S99>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_l = 0.0;
  } else {
    /* Switch: '<S99>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_l = rtb_IProdOut;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Switch: '<S72>/Switch3' */
  if (rtb_Subtract2_f != 0.0) {
    /* Switch: '<S72>/Switch3' incorporates:
     *  Constant: '<S72>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->error_h = 0.0;
  } else {
    /* Switch: '<S72>/Switch3' incorporates:
     *  Constant: '<S72>/Base Ref Airgap1'
     *  Constant: '<S72>/Constant3'
     *  Sum: '<S72>/Subtract3'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->error_h =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LandingAirgap -
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap;
  }

  /* End of Switch: '<S72>/Switch3' */

  /* Sum: '<S151>/SumI4' incorporates:
   *  Gain: '<S151>/Kb'
   *  Gain: '<S157>/Integral Gain'
   *  Sum: '<S151>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4 = (rtb_Sum_gy -
    rtb_Sum_gy) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralAG *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch;

  /* Switch: '<S179>/Switch' incorporates:
   *  Constant: '<S179>/Constant2'
   *  Gain: '<S179>/Gain'
   *  Outport: '<Root>/Mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_i;
  } else {
    rtb_Switch1_j1_idx_0 = 0.05 *
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_i;
  }

  /* End of Switch: '<S179>/Switch' */

  /* Product: '<S215>/IProd Out' */
  rtb_IProdOut_hj = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 *
    rtb_Switch1_j1_idx_0;

  /* Signum: '<S209>/SignPreIntegrator' */
  if (rtb_IProdOut_hj < 0.0) {
    rtb_ZeroCurrentForces_idx_3 = -1.0;
  } else if (rtb_IProdOut_hj > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_IProdOut_hj == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S209>/SignPreIntegrator' */

  /* DataTypeConversion: '<S209>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_ZeroCurrentForces_idx_3);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* DeadZone: '<S211>/DeadZone' */
  if (rtb_Sum_ih >= (rtMinusInf)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of DeadZone: '<S211>/DeadZone' */

  /* Switch: '<S209>/Switch' incorporates:
   *  DataTypeConversion: '<S209>/DataTypeConv1'
   *  DataTypeConversion: '<S209>/DataTypeConv2'
   *  Gain: '<S209>/ZeroGain'
   *  Logic: '<S209>/AND3'
   *  RelationalOperator: '<S209>/Equal1'
   *  RelationalOperator: '<S209>/NotEqual'
   */
  if ((0.0 * rtb_Sum_ih != rtb_ZeroCurrentForces_idx_3) &&
      ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)(uint8_T)rtb_Switch1_j1_idx_0) ==
       0)) {
    /* Switch: '<S209>/Switch' incorporates:
     *  Constant: '<S209>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j = 0.0;
  } else {
    /* Switch: '<S209>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j = rtb_IProdOut_hj;
  }

  /* End of Switch: '<S209>/Switch' */

  /* Sum: '<S260>/SumI4' incorporates:
   *  Gain: '<S260>/Kb'
   *  Gain: '<S266>/Integral Gain'
   *  Sum: '<S260>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_c = (rtb_Sum_ac -
    rtb_Sum_ac) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o;

  /* Switch: '<S288>/Switch' incorporates:
   *  Constant: '<S288>/Constant2'
   *  Gain: '<S288>/Gain'
   *  Outport: '<Root>/Mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    rtb_Switch1_j1_idx_0 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_i;
  } else {
    rtb_Switch1_j1_idx_0 = 0.05 *
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_i;
  }

  /* End of Switch: '<S288>/Switch' */

  /* Product: '<S323>/IProd Out' */
  rtb_IProdOut_g = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
    rtb_Switch1_j1_idx_0;

  /* Signum: '<S317>/SignPreIntegrator' */
  if (rtb_IProdOut_g < 0.0) {
    rtb_ZeroCurrentForces_idx_3 = -1.0;
  } else if (rtb_IProdOut_g > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_IProdOut_g == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S317>/SignPreIntegrator' */

  /* DataTypeConversion: '<S317>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_ZeroCurrentForces_idx_3);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* DeadZone: '<S319>/DeadZone' */
  if (rtb_Sum_oi >= (rtMinusInf)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of DeadZone: '<S319>/DeadZone' */

  /* Switch: '<S317>/Switch' incorporates:
   *  DataTypeConversion: '<S317>/DataTypeConv1'
   *  DataTypeConversion: '<S317>/DataTypeConv2'
   *  Gain: '<S317>/ZeroGain'
   *  Logic: '<S317>/AND3'
   *  RelationalOperator: '<S317>/Equal1'
   *  RelationalOperator: '<S317>/NotEqual'
   */
  if ((0.0 * rtb_Sum_oi != rtb_ZeroCurrentForces_idx_3) &&
      ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)(uint8_T)rtb_Switch1_j1_idx_0) ==
       0)) {
    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S317>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d = 0.0;
  } else {
    /* Switch: '<S317>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d = rtb_IProdOut_g;
  }

  /* End of Switch: '<S317>/Switch' */

  /* Sum: '<S368>/SumI4' incorporates:
   *  Gain: '<S368>/Kb'
   *  Gain: '<S374>/Integral Gain'
   *  Sum: '<S368>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_o = (rtb_Sum_a4 -
    rtb_Sum_a4) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralR *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p;

  /* RelationalOperator: '<S6>/Equal' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_l = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* RelationalOperator: '<S6>/Equal1' incorporates:
   *  Constant: '<S6>/Constant5'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1 = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* RelationalOperator: '<S6>/Equal2' incorporates:
   *  Constant: '<S6>/Constant7'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2 = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* Gain: '<S6>/Gain' incorporates:
   *  Constant: '<S6>/Constant9'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_g = 9.81 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* SignalConversion generated from: '<S398>/Create Diagonal Matrix1' incorporates:
   *  Constant: '<S398>/Constant4'
   *  Constant: '<S398>/Constant5'
   *  Constant: '<S398>/Constant6'
   *  Constant: '<S398>/Constant7'
   *  Constant: '<S398>/Constant8'
   *  Constant: '<S398>/Constant9'
   */
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_dot;
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_proc;
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_dot;
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[3] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_proc;
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[4] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_dot;
  rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[5] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_proc;

  /* S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix1' */
  for (i = 0; i < 36; i++) {
    rtb_CreateDiagonalMatrix1[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    rtb_CreateDiagonalMatrix1[i * 7] =
      rtb_TmpSignalConversionAtCreateDiagonalMatrix1Inport1[i];
  }

  /* End of S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix1' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Switch: '<S24>/Switch2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_l) {
    /* Switch: '<S6>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] = 0.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchedHEMSKalman >
       0.0) {
    /* Switch: '<S24>/Switch2' incorporates:
     *  Switch: '<S6>/Switch'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] =
      rtb_Switch_k_idx_0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] =
      rtb_Switch_k_idx_1;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] =
      rtb_Switch_k_idx_2;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] =
      rtb_Switch_k_idx_3;
  } else {
    /* Switch: '<S6>/Switch' incorporates:
     *  Switch: '<S24>/Switch2'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] =
      rtb_uDLookupTable4;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] =
      rtb_uDLookupTable3;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] =
      rtb_uDLookupTable1_os;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] =
      rtb_uDLookupTable2_cw;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S6>/Switch1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1) {
    /* Switch: '<S6>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_g;
  } else {
    /* Switch: '<S6>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg = rtb_Switch1_d;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S6>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k = 0.0;
  } else {
    /* Switch: '<S6>/Switch2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k = rtb_Add1;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S399>/Predict' */
  /* MATLAB Function: '<S402>/Predict' incorporates:
   *  S-Function (sdspdiag2): '<S398>/Create Diagonal Matrix1'
   */
  /* MATLAB Function 'Extended Kalman Filter/Predict/Predict': '<S405>:1' */
  /* '<S405>:1:11' */
  p = true;
  for (i = 0; i < 36; i++) {
    rtb_Switch_k_idx_0 = rtb_CreateDiagonalMatrix1[i];
    if (((int32_T)p) && ((!(int32_T)rtIsInf(rtb_Switch_k_idx_0)) && (!(int32_T)
          rtIsNaN(rtb_Switch_k_idx_0)))) {
    } else {
      p = false;
    }
  }

  if (p) {
    PIDcontroller4CoreCentralizedTestReadyMotor_svd_a(rtb_CreateDiagonalMatrix1,
      Ss_0, imvec, A_0);
  } else {
    for (i = 0; i < 6; i++) {
      imvec[i] = (rtNaN);
    }

    for (b_j = 0; b_j < 36; b_j++) {
      A_0[b_j] = (rtNaN);
    }
  }

  for (b_j = 0; b_j < 36; b_j++) {
    Ss_0[b_j] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    Ss_0[i + 6 * i] = imvec[i];
  }

  for (i = 0; i < 36; i++) {
    Ss_0[i] = sqrt(Ss_0[i]);
  }

  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      A_1[i + 6 * b_j] = 0.0;
    }

    for (rankA = 0; rankA < 6; rankA++) {
      for (i = 0; i < 6; i++) {
        aoffset = 6 * b_j + i;
        A_1[aoffset] += A_0[6 * rankA + i] * Ss_0[6 * b_j + rankA];
      }
    }
  }

  /* End of Outputs for SubSystem: '<S399>/Predict' */

  /* ZeroOrderHold: '<S398>/Zero-Order Hold1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  A[0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0];
  A[1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1];
  A[2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2];
  A[3] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3];
  A[4] = rtb_Gain_mn;
  A[5] = rtb_Gain_no;
  A[6] = 0.392;
  A[7] = 0.3054;
  A[8] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  A[9] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg;
  A[10] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k;
  A[11] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Outputs for Atomic SubSystem: '<S399>/Predict' */
  /* DataStoreWrite: '<S402>/Data Store WriteX' incorporates:
   *  DataStoreWrite: '<S402>/Data Store WriteP'
   *  MATLAB Function: '<S402>/Predict'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_EKFPredictorAdditive_predict(A_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->P, A);

  /* End of Outputs for SubSystem: '<S399>/Predict' */

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  /* '<S405>:1:123' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
  }

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator3' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
      = 0.0;
  }

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator4' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
      = 0.0;
  }

  /* Saturate: '<S8>/Saturation' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm > 40.0) {
    /* Saturate: '<S8>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 40.0;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm < 1.0) {
    /* Saturate: '<S8>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 1.0;
  } else {
    /* Saturate: '<S8>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Saturate: '<S8>/Saturation1' */
  if (rtb_Switch_od > 40.0) {
    rtb_Switch_k_idx_0 = 40.0;
  } else if (rtb_Switch_od < 1.0) {
    rtb_Switch_k_idx_0 = 1.0;
  } else {
    rtb_Switch_k_idx_0 = rtb_Switch_od;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* Gain: '<S8>/Gain2' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S8>/Divide'
   *  Sum: '<S8>/Subtract2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation /
     rtb_Switch_k_idx_0 - 1.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_F *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[0];

  /* Gain: '<S8>/Gain5' incorporates:
   *  Gain: '<S8>/Gain3'
   *  Sum: '<S8>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[5] -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_P *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[1];

  /* Gain: '<S8>/Gain6' incorporates:
   *  Gain: '<S8>/Gain4'
   *  Sum: '<S8>/Add2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[3] -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_R *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[2];

  /* Sum: '<S8>/Subtract' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm - rtb_Switch_od;

  /* DeadZone: '<S557>/DeadZone' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum >= (rtMinusInf)) {
    rtb_DeadZone_m = 0.0;
  } else {
    rtb_DeadZone_m = PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum -
      (rtMinusInf);
  }

  /* End of DeadZone: '<S557>/DeadZone' */

  /* Product: '<S563>/IProd Out' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  rtb_IProdOut_m = PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_i;

  /* Signum: '<S555>/SignPreSat' */
  if (rtb_DeadZone_m > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_DeadZone_m == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S555>/SignPreSat' */

  /* DataTypeConversion: '<S555>/DataTypeConv1' */
  if (rtb_ZeroCurrentForces_idx_3 < 4.503599627370496E+15) {
    if (rtb_ZeroCurrentForces_idx_3 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  /* Signum: '<S555>/SignPreIntegrator' */
  if (rtb_IProdOut_m < 0.0) {
    rtb_Switch_k_idx_0 = -1.0;
  } else if (rtb_IProdOut_m > 0.0) {
    rtb_Switch_k_idx_0 = 1.0;
  } else if (rtb_IProdOut_m == 0.0) {
    rtb_Switch_k_idx_0 = 0.0;
  } else {
    rtb_Switch_k_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S555>/SignPreIntegrator' */

  /* DataTypeConversion: '<S555>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_Switch_k_idx_0);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_Switch_k_idx_0 = floor(rtb_Switch_k_idx_0 + 0.5);
    } else {
      rtb_Switch_k_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch_k_idx_0)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_Switch_k_idx_0, 256.0);
  }

  /* DataTypeConversion: '<S555>/DataTypeConv1' */
  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* Switch: '<S555>/Switch' incorporates:
   *  DataTypeConversion: '<S555>/DataTypeConv1'
   *  DataTypeConversion: '<S555>/DataTypeConv2'
   *  Gain: '<S555>/ZeroGain'
   *  Logic: '<S555>/AND3'
   *  RelationalOperator: '<S555>/Equal1'
   *  RelationalOperator: '<S555>/NotEqual'
   */
  if ((0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum !=
       rtb_DeadZone_m) && ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)
        -(int32_T)(int8_T)(uint8_T)-rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)
        (uint8_T)rtb_Switch1_j1_idx_0) == (int32_T)(int8_T)(uint8_T)
       rtb_ZeroCurrentForces_idx_3)) {
    /* Switch: '<S555>/Switch' incorporates:
     *  Constant: '<S555>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_dt = 0.0;
  } else {
    /* Switch: '<S555>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_dt = rtb_IProdOut_m;
  }

  /* End of Switch: '<S555>/Switch' */

  /* DeadZone: '<S610>/DeadZone' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d >= (rtMinusInf)) {
    rtb_DeadZone_f = 0.0;
  } else {
    rtb_DeadZone_f = PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d -
      (rtMinusInf);
  }

  /* End of DeadZone: '<S610>/DeadZone' */

  /* Product: '<S616>/IProd Out' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  rtb_IProdOut_k = PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_e *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_i;

  /* Signum: '<S608>/SignPreSat' */
  if (rtb_DeadZone_f > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_DeadZone_f == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S608>/SignPreSat' */

  /* DataTypeConversion: '<S608>/DataTypeConv1' */
  if (rtb_ZeroCurrentForces_idx_3 < 4.503599627370496E+15) {
    if (rtb_ZeroCurrentForces_idx_3 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  /* Signum: '<S608>/SignPreIntegrator' */
  if (rtb_IProdOut_k < 0.0) {
    rtb_Switch_k_idx_0 = -1.0;
  } else if (rtb_IProdOut_k > 0.0) {
    rtb_Switch_k_idx_0 = 1.0;
  } else if (rtb_IProdOut_k == 0.0) {
    rtb_Switch_k_idx_0 = 0.0;
  } else {
    rtb_Switch_k_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S608>/SignPreIntegrator' */

  /* DataTypeConversion: '<S608>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_Switch_k_idx_0);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_Switch_k_idx_0 = floor(rtb_Switch_k_idx_0 + 0.5);
    } else {
      rtb_Switch_k_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch_k_idx_0)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_Switch_k_idx_0, 256.0);
  }

  /* DataTypeConversion: '<S608>/DataTypeConv1' */
  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* Switch: '<S608>/Switch' incorporates:
   *  DataTypeConversion: '<S608>/DataTypeConv1'
   *  DataTypeConversion: '<S608>/DataTypeConv2'
   *  Gain: '<S608>/ZeroGain'
   *  Logic: '<S608>/AND3'
   *  RelationalOperator: '<S608>/Equal1'
   *  RelationalOperator: '<S608>/NotEqual'
   */
  if ((0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d !=
       rtb_DeadZone_f) && ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)
        -(int32_T)(int8_T)(uint8_T)-rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)
        (uint8_T)rtb_Switch1_j1_idx_0) == (int32_T)(int8_T)(uint8_T)
       rtb_ZeroCurrentForces_idx_3)) {
    /* Switch: '<S608>/Switch' incorporates:
     *  Constant: '<S608>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_em = 0.0;
  } else {
    /* Switch: '<S608>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_em = rtb_IProdOut_k;
  }

  /* End of Switch: '<S608>/Switch' */

  /* DeadZone: '<S663>/DeadZone' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c >= (rtMinusInf)) {
    rtb_DeadZone_fg = 0.0;
  } else {
    rtb_DeadZone_fg = PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c -
      (rtMinusInf);
  }

  /* End of DeadZone: '<S663>/DeadZone' */

  /* Product: '<S669>/IProd Out' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  rtb_IProdOut_c2 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_c *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_i;

  /* Signum: '<S661>/SignPreSat' */
  if (rtb_DeadZone_fg > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_DeadZone_fg == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S661>/SignPreSat' */

  /* DataTypeConversion: '<S661>/DataTypeConv1' */
  if (rtb_ZeroCurrentForces_idx_3 < 4.503599627370496E+15) {
    if (rtb_ZeroCurrentForces_idx_3 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  /* Signum: '<S661>/SignPreIntegrator' */
  if (rtb_IProdOut_c2 < 0.0) {
    rtb_Switch_k_idx_0 = -1.0;
  } else if (rtb_IProdOut_c2 > 0.0) {
    rtb_Switch_k_idx_0 = 1.0;
  } else if (rtb_IProdOut_c2 == 0.0) {
    rtb_Switch_k_idx_0 = 0.0;
  } else {
    rtb_Switch_k_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S661>/SignPreIntegrator' */

  /* DataTypeConversion: '<S661>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_Switch_k_idx_0);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_Switch_k_idx_0 = floor(rtb_Switch_k_idx_0 + 0.5);
    } else {
      rtb_Switch_k_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch_k_idx_0)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_Switch_k_idx_0, 256.0);
  }

  /* DataTypeConversion: '<S661>/DataTypeConv1' */
  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* Switch: '<S661>/Switch' incorporates:
   *  DataTypeConversion: '<S661>/DataTypeConv1'
   *  DataTypeConversion: '<S661>/DataTypeConv2'
   *  Gain: '<S661>/ZeroGain'
   *  Logic: '<S661>/AND3'
   *  RelationalOperator: '<S661>/Equal1'
   *  RelationalOperator: '<S661>/NotEqual'
   */
  if ((0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c !=
       rtb_DeadZone_fg) && ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)
        -(int32_T)(int8_T)(uint8_T)-rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)
        (uint8_T)rtb_Switch1_j1_idx_0) == (int32_T)(int8_T)(uint8_T)
       rtb_ZeroCurrentForces_idx_3)) {
    /* Switch: '<S661>/Switch' incorporates:
     *  Constant: '<S661>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_lx = 0.0;
  } else {
    /* Switch: '<S661>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_lx = rtb_IProdOut_c2;
  }

  /* End of Switch: '<S661>/Switch' */

  /* DeadZone: '<S716>/DeadZone' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b >= (rtMinusInf)) {
    rtb_DeadZone_c = 0.0;
  } else {
    rtb_DeadZone_c = PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b -
      (rtMinusInf);
  }

  /* End of DeadZone: '<S716>/DeadZone' */

  /* Product: '<S722>/IProd Out' incorporates:
   *  Constant: '<S20>/Constant2'
   */
  rtb_IProdOut_cg = PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_f *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->I_K_i;

  /* Signum: '<S714>/SignPreSat' */
  if (rtb_DeadZone_c > 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 1.0;
  } else if (rtb_DeadZone_c == 0.0) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = (rtNaN);
  }

  /* End of Signum: '<S714>/SignPreSat' */

  /* DataTypeConversion: '<S714>/DataTypeConv1' */
  if (rtb_ZeroCurrentForces_idx_3 < 4.503599627370496E+15) {
    if (rtb_ZeroCurrentForces_idx_3 >= 0.5) {
      rtb_ZeroCurrentForces_idx_3 = floor(rtb_ZeroCurrentForces_idx_3 + 0.5);
    } else {
      rtb_ZeroCurrentForces_idx_3 *= 0.0;
    }
  }

  /* Signum: '<S714>/SignPreIntegrator' */
  if (rtb_IProdOut_cg < 0.0) {
    rtb_Switch_k_idx_0 = -1.0;
  } else if (rtb_IProdOut_cg > 0.0) {
    rtb_Switch_k_idx_0 = 1.0;
  } else if (rtb_IProdOut_cg == 0.0) {
    rtb_Switch_k_idx_0 = 0.0;
  } else {
    rtb_Switch_k_idx_0 = (rtNaN);
  }

  /* End of Signum: '<S714>/SignPreIntegrator' */

  /* DataTypeConversion: '<S714>/DataTypeConv2' */
  rtb_Switch1_j1_idx_0 = fabs(rtb_Switch_k_idx_0);
  if (rtb_Switch1_j1_idx_0 < 4.503599627370496E+15) {
    if (rtb_Switch1_j1_idx_0 >= 0.5) {
      rtb_Switch_k_idx_0 = floor(rtb_Switch_k_idx_0 + 0.5);
    } else {
      rtb_Switch_k_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(rtb_Switch_k_idx_0)) {
    rtb_Switch1_j1_idx_0 = 0.0;
  } else {
    rtb_Switch1_j1_idx_0 = fmod(rtb_Switch_k_idx_0, 256.0);
  }

  /* DataTypeConversion: '<S714>/DataTypeConv1' */
  if (rtIsNaN(rtb_ZeroCurrentForces_idx_3)) {
    rtb_ZeroCurrentForces_idx_3 = 0.0;
  } else {
    rtb_ZeroCurrentForces_idx_3 = fmod(rtb_ZeroCurrentForces_idx_3, 256.0);
  }

  /* Switch: '<S714>/Switch' incorporates:
   *  DataTypeConversion: '<S714>/DataTypeConv1'
   *  DataTypeConversion: '<S714>/DataTypeConv2'
   *  Gain: '<S714>/ZeroGain'
   *  Logic: '<S714>/AND3'
   *  RelationalOperator: '<S714>/Equal1'
   *  RelationalOperator: '<S714>/NotEqual'
   */
  if ((0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b !=
       rtb_DeadZone_c) && ((rtb_Switch1_j1_idx_0 < 0.0 ? (int32_T)(int8_T)
        -(int32_T)(int8_T)(uint8_T)-rtb_Switch1_j1_idx_0 : (int32_T)(int8_T)
        (uint8_T)rtb_Switch1_j1_idx_0) == (int32_T)(int8_T)(uint8_T)
       rtb_ZeroCurrentForces_idx_3)) {
    /* Switch: '<S714>/Switch' incorporates:
     *  Constant: '<S714>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c5 = 0.0;
  } else {
    /* Switch: '<S714>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c5 = rtb_IProdOut_cg;
  }

  /* End of Switch: '<S714>/Switch' */

  /* SignalConversion generated from: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [3] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e;

  /* SignalConversion generated from: '<Root>/Delay2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator4'
   *  Sum: '<S8>/Add'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
    + 1.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE;

  /* Outport: '<Root>/G_Factor' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->G_Factor = rtb_Divide;

  /* Outport: '<Root>/P_Factor' incorporates:
   *  Product: '<S34>/Divide1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->P_Factor =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product / rtb_Sum_ih;

  /* Outport: '<Root>/R_Factor' incorporates:
   *  Product: '<S36>/Divide1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->R_Factor =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h / rtb_Sum_oi;

  /* Outport: '<Root>/Filtered_Gaps' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[0] =
    rtb_Switch_ph;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[1] =
    rtb_Switch_k1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[2] =
    rtb_Switch_ds;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[3] =
    rtb_Switch_gn;

  /* Outport: '<Root>/RefPitchOut' incorporates:
   *  Gain: '<S182>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefPitchOut =
    57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch;

  /* Outport: '<Root>/RefRollOut' incorporates:
   *  Gain: '<S290>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefRollOut = 57.295779513082323
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll;

  /* Outport: '<Root>/Arms' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[0] = rtb_Add2;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[1] = rtb_Add1_n;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add;

  /* Outport: '<Root>/CalculatedMass' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedMass = rtb_Add3;

  /* Sum: '<S454>/SumI4' incorporates:
   *  Gain: '<S454>/Kb'
   *  Gain: '<S460>/Integral Gain'
   *  Sum: '<S454>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g = (rtb_Sum_pc -
    rtb_Sum_pc) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP;

  /* Sum: '<S504>/SumI4' incorporates:
   *  Gain: '<S504>/Kb'
   *  Gain: '<S510>/Integral Gain'
   *  Sum: '<S504>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k = (rtb_Sum - rtb_Sum) *
    0.01 + PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP;

  /* Switch: '<S16>/Switch3' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Sum: '<S16>/Subtract1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h = (real_T)
    !(rtb_Switch1 - 3.0 != 0.0);

  /* Sum: '<S23>/Subtract' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  rtb_Switch2_idx_2 -= PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Sum: '<S23>/Subtract'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Sum'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[0] =
    (rtb_Switch2_idx_0 - rtb_Sum1) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[0];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1] =
    (rtb_Switch2_idx_1 - rtb_Add1) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[2] *
    rtb_Switch2_idx_2;

  /* Product: '<S23>/Product1' incorporates:
   *  Constant: '<S23>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->EMSRollIntegral *
    rtb_Switch2_idx_2;

  /* Product: '<S23>/Product2' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Sum: '<S23>/Add4'
   *  Sum: '<S4>/Add'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product2 = (rtb_Switch2_idx_0 +
    rtb_Sum1) * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals
    [0];
}

/* Model update function */
void PIDcontroller4CoreCentralizedTestReadyMotor_update
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M)
{
  B_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_B =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO;
  DW_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_DW =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork;
  InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_InstP =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref;
  ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_Y =
    (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
    PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs;
  real_T (*lastU)[3];
  real_T tmp;
  int_T idxDelay;

  /* Update for Delay: '<S16>/Delay1' incorporates:
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode;

  /* Update for DiscreteIntegrator: '<S513>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S506>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp;

  /* Update for DiscreteIntegrator: '<S463>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S456>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b;

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S71>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->error;
  for (idxDelay = 0; idxDelay < 399; idxDelay++) {
    /* Update for Delay: '<S32>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[idxDelay] =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[idxDelay +
      1];

    /* Update for Delay: '<S32>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[idxDelay] =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[idxDelay +
      1];
  }

  /* Update for Delay: '<S32>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[399] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;

  /* Update for Delay: '<S32>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[399] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain;

  /* Update for Sin: '<S32>/Sine Wave4' incorporates:
   *  Sin: '<S32>/Sine Wave1'
   *  Sin: '<S32>/Sine Wave2'
   *  Sin: '<S32>/Sine Wave3'
   *  Sin: '<S32>/Sine Wave5'
   *  Sin: '<S32>/Sine Wave6'
   *  Sin: '<S32>/Sine Wave7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter++;
  tmp = floor(PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineTime /
              0.00025);
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter == tmp) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter = 0;
  }

  /* End of Update for Sin: '<S32>/Sine Wave4' */

  /* Update for Sin: '<S32>/Sine Wave5' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h = 0;
  }

  /* Update for Sin: '<S32>/Sine Wave6' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o = 0;
  }

  /* Update for Sin: '<S32>/Sine Wave7' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a = 0;
  }

  /* Update for Sin: '<S32>/Sine Wave1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i = 0;
  }

  /* Update for Sin: '<S32>/Sine Wave2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m = 0;
  }

  /* Update for Sin: '<S32>/Sine Wave3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n++;
  if ((real_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n == tmp)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n = 0;
  }

  /* Update for Delay: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [0];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [2];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[3] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [3];

  /* Update for DiscreteIntegrator: '<S160>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S153>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
    += 0.00025;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->error_h;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_o
    = (int8_T)0;

  /* Update for DiscreteIntegrator: '<S108>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k;

  /* Update for DiscreteIntegrator: '<S103>/Filter' incorporates:
   *  DiscreteIntegrator: '<S108>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S23>/Constant'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product2;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms < 0.0)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms == 0.0)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S269>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S262>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m;

  /* Update for Delay: '<S179>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_h =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2;

  /* Update for DiscreteIntegrator: '<S218>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0 =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;

  /* Update for DiscreteIntegrator: '<S213>/Filter' incorporates:
   *  DiscreteIntegrator: '<S218>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for DiscreteIntegrator: '<S377>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S513>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_o;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S370>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h;

  /* Update for Delay: '<S288>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3;

  /* Update for DiscreteIntegrator: '<S326>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;

  /* Update for DiscreteIntegrator: '<S321>/Filter' incorporates:
   *  DiscreteIntegrator: '<S326>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for Delay: '<S27>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7;

  /* Update for Delay: '<S27>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4;

  /* Update for Delay: '<S28>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e;

  /* Update for Delay: '<S28>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_c;

  /* Update for Delay: '<S29>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_p =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_d;

  /* Update for Delay: '<S29>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g;

  /* Update for Delay: '<S30>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_k =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_a;

  /* Update for Delay: '<S30>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_k;

  /* Update for DiscreteIntegrator: '<S566>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_h += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_dt;

  /* Update for Delay: '<S559>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_kb;

  /* Update for Derivative: '<Root>/Derivative' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA == (rtInf)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB ==
             (rtInf)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA <
             PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
  }

  (*lastU)[0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0];
  (*lastU)[1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1];
  (*lastU)[2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2];

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative1' incorporates:
   *  MATLABSystem: '<Root>/Moving Average'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l == (rtInf)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b ==
             (rtInf)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l <
             PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
  }

  (*lastU)[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[0];
  (*lastU)[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[1];
  (*lastU)[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->
    MovingAverage_c.MovingAverage[2];

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for DiscreteIntegrator: '<S619>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_d += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_em;

  /* Update for Delay: '<S612>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_e =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k0;

  /* Update for DiscreteIntegrator: '<S725>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_p += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c5;

  /* Update for Delay: '<S718>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_h =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_o;

  /* Update for DiscreteIntegrator: '<S672>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_m += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_lx;

  /* Update for Delay: '<S665>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_ei =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_g;

  /* Update for Delay: '<Root>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [0];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [2];

  /* Update for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for Delay: '<S27>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */

  /* Update for Delay: '<S27>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S28>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c5 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g;

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_m
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Update for Delay: '<S28>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g;

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_p
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_c;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S29>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_b =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_a;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_d
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_a;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */

  /* Update for Delay: '<S29>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_a;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S30>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */

  /* Update for Delay: '<S30>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_m
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_k;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator4' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTick0)) {
    ++PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTickH0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTick0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.stepSize0 +
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTickH0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.stepSize0 *
    4294967296.0;

  {
    /* Update absolute timer for sample time: [0.00025s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.00025, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTick1++;
    if (!PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTick1) {
      PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void PIDcontroller4CoreCentralizedTestReadyMotor_initialize
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M)
{
  DW_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_DW =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork;

  {
    int32_T i;
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

    /* Start for MATLABSystem: '<S409>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted
      = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isInitialized = 0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.NumChannels = -1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted
      = false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->objisempty = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpg);

    /* Start for MATLABSystem: '<S397>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.matlabCodegenIsDeleted =
      true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isInitialized = 0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.NumChannels = -1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.matlabCodegenIsDeleted =
      false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->objisempty_n = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isSetupComplete = false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isInitialized = 1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.NumChannels = 1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj._pobj0.isInitialized = 0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.pStatistic =
      &PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj._pobj0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isSetupComplete = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.TunablePropsChanged =
      false;
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);

    /* Start for DataStoreMemory: '<S399>/DataStoreMemory - P' */
    memcpy(&PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[0],
           &PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.DataStoreMemoryP_InitialValue
           [0], 36U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S399>/DataStoreMemory - x' */
    for (i = 0; i < 6; i++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i] =
        PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.DataStoreMemoryx_InitialValue
        [i];
    }

    /* End of Start for DataStoreMemory: '<S399>/DataStoreMemory - x' */
  }

  {
    c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
      *obj;
    c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
      *obj_0;
    int32_T i;

    /* InitializeConditions for Delay: '<S16>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S513>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S506>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S463>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S456>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscretePulseGenerator: '<S32>/Pulse Generator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter = 0;

    /* InitializeConditions for Delay: '<S71>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE = 0.0;
    for (i = 0; i < 400; i++) {
      /* InitializeConditions for Delay: '<S32>/Delay1' */
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[i] = 0.0;

      /* InitializeConditions for Delay: '<S32>/Delay' */
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[i] = 0.0;
    }

    /* InitializeConditions for Sin: '<S32>/Sine Wave4' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave5' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave6' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave7' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m = 0;

    /* InitializeConditions for Sin: '<S32>/Sine Wave3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n = 0;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[3] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S153>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_o
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o =
      (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Filter' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState =
      (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S269>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S262>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;

    /* InitializeConditions for Delay: '<S179>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_h = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S218>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S213>/Filter' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j =
      (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S370>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;

    /* InitializeConditions for Delay: '<S288>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S326>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S321>/Filter' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k =
      (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S27>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE = 0.0;

    /* InitializeConditions for Delay: '<S27>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_g = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_p = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_k = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S566>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_h = 0.0;

    /* InitializeConditions for Delay: '<S559>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_g = 0.0;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA = (rtInf);
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l = (rtInf);
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b = (rtInf);

    /* InitializeConditions for DiscreteIntegrator: '<S619>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_d = 0.0;

    /* InitializeConditions for Delay: '<S612>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_e = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S725>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_p = 0.0;

    /* InitializeConditions for Delay: '<S718>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_h = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S672>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_m = 0.0;

    /* InitializeConditions for Delay: '<S665>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_ei = 0.0;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[2] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S397>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S27>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_g
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_l
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S28>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c5 = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_m
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S29>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_b = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_d
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_m
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_n
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S30>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_d
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[0] = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[0] = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[0] = 0.0;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[1] = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[1] = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[1] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_m
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_e
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator4' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
      = (int8_T)2;
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

    /* InitializeConditions for MATLABSystem: '<S409>/Moving Average' */
    obj = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pwN = 1.0;
      obj->pmN[0] = 0.0;
      obj->pmN[1] = 0.0;
      obj->pmN[2] = 0.0;
      obj->pmN[3] = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S409>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpg);

    /* InitializeConditions for MATLABSystem: '<S397>/Moving Average' */
    obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 3999; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S397>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);
  }
}

/* Model terminate function */
void PIDcontroller4CoreCentralizedTestReadyMotor_terminate
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T
   * PIDcontroller4CoreCentralizedTestReadyMotor_M)
{
  DW_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_DW =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *obj;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *obj_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

  /* Terminate for MATLABSystem: '<S409>/Moving Average' */
  if (!(int32_T)
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted
      = true;
    if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isInitialized ==
         1) && ((int32_T)
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isSetupComplete))
    {
      obj = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S409>/Moving Average' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpg);

  /* Terminate for MATLABSystem: '<S397>/Moving Average' */
  if (!(int32_T)
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.matlabCodegenIsDeleted)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.matlabCodegenIsDeleted =
      true;
    if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isInitialized == 1)
        && ((int32_T)
            PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.isSetupComplete))
    {
      obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S397>/Moving Average' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo);

  /* model code */
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->inputs);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M->prevZCSigState);

  /* Free instance parameters */
  rt_FREE
    (PIDcontroller4CoreCentralizedTestReadyMotor_M->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref);
  rt_FREE(PIDcontroller4CoreCentralizedTestReadyMotor_M);
}

/* Model data allocation function */
RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *PIDcontroller4CoreCentralizedTestReadyMotor(void)
{
  RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_M;
  PIDcontroller4CoreCentralizedTestReadyMotor_M =
    (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
    (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T));
  if (PIDcontroller4CoreCentralizedTestReadyMotor_M == NULL) {
    return NULL;
  }

  (void) memset((char *)PIDcontroller4CoreCentralizedTestReadyMotor_M, 0,
                sizeof(RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T));

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,
                       rt_SolverInfo);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr
      (PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
       &PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.simTimeStep);
    rtsiSetTPtr(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
                &rtmGetTPtr(PIDcontroller4CoreCentralizedTestReadyMotor_M));
    rtsiSetStepSizePtr(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
                       &PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr
      (PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
       (&rtmGetErrorStatus(PIDcontroller4CoreCentralizedTestReadyMotor_M)));
    rtsiSetRTModelPtr(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
                      PIDcontroller4CoreCentralizedTestReadyMotor_M);
  }

  rtsiSetSolverName(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
                    "FixedStepDiscrete");

  /* block I/O */
  {
    B_PIDcontroller4CoreCentralizedTestReadyMotor_T *b =
      (B_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (B_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,b);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO = (b);
  }

  /* Initialize instance parameters */
  {
    InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T *group__InstP =
      (InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,
                       group__InstP);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref
      = (group__InstP);
    (void) memcpy(group__InstP,
                  &PIDcontroller4CoreCentralizedTestReadyMotor_InstP,
                  sizeof(InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T));
  }

  /* states (dwork) */
  {
    DW_PIDcontroller4CoreCentralizedTestReadyMotor_T *dwork =
      (DW_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (DW_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,dwork);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_U =
      (ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,
                       PIDcontroller4CoreCentralizedTestReadyMotor_U);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->inputs =
      (((ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
        PIDcontroller4CoreCentralizedTestReadyMotor_U));
  }

  /* external outputs */
  {
    ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_Y =
      (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,
                       PIDcontroller4CoreCentralizedTestReadyMotor_Y);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs =
      (PIDcontroller4CoreCentralizedTestReadyMotor_Y);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T *zc =
      (PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T *) malloc(sizeof
      (PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    rt_VALIDATE_MEMORY(PIDcontroller4CoreCentralizedTestReadyMotor_M,zc);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->prevZCSigState = (zc);
  }

  {
    B_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_B =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO;
    DW_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_DW =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->dwork;
    PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX =
      PIDcontroller4CoreCentralizedTestReadyMotor_M->prevZCSigState;
    ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_U =
      (ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
      PIDcontroller4CoreCentralizedTestReadyMotor_M->inputs;
    ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *PIDcontroller4CoreCentralizedTestReadyMotor_Y =
      (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
      PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtsiSetSimTimeStep(PIDcontroller4CoreCentralizedTestReadyMotor_M->solverInfo,
                       MAJOR_TIME_STEP);
    rtmSetTPtr(PIDcontroller4CoreCentralizedTestReadyMotor_M,
               &PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.tArray[0]);
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.stepSize0 = 0.00025;

    /* block I/O */
    (void) memset(((void *) PIDcontroller4CoreCentralizedTestReadyMotor_B), 0,
                  sizeof(B_PIDcontroller4CoreCentralizedTestReadyMotor_T));

    {
      int32_T i;
      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[i] = 0.0;
      }

      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_g[i] = 0.0;
      }

      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_k[i] = 0.0;
      }

      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_h[i] = 0.0;
      }

      for (i = 0; i < 6; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->DataStoreRead[i] = 0.0;
      }

      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1[3] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_jz[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->error = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_kb = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k0 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_f = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_b = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract2_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_p = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pt = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_pj = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->error_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_dt = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_em = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_lx = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
        [3] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent3.out_req_I
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent2.out_req_I
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent1.out_req_I
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_ka.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_kw.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_h.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpg.MovingAverage
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfp.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage.MovingAverage
        = 0.0;
    }

    /* states (dwork) */
    (void) memset((void *)PIDcontroller4CoreCentralizedTestReadyMotor_DW, 0,
                  sizeof(DW_PIDcontroller4CoreCentralizedTestReadyMotor_T));
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE = 0.0;

    {
      int32_T i;
      for (i = 0; i < 400; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[i] = 0.0;
      }
    }

    {
      int32_T i;
      for (i = 0; i < 400; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[i] = 0.0;
      }
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[3] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_p = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_k = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_f = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_d = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_e = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_p = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_ei = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_d[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c5 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_m
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_a[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_b = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_d
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k1[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_m
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l[2] = 0.0;

    {
      int32_T i;
      for (i = 0; i < 36; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[i] = 0.0;
      }
    }

    {
      int32_T i;
      for (i = 0; i < 6; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i] = 0.0;
      }
    }

    /* external inputs */
    PIDcontroller4CoreCentralizedTestReadyMotor_U->G_A = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->G_B = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->G_C = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->G_D = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_A_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_B_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_C_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->I_D_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->VerticalAxisState = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr1 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr2 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr3 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vr4 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt1 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt2 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt3 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->Vt4 = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->EMS_F_Front = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->EMS_F_Back = 0.0;

    /* external outputs */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_A = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ActualReferenceAirgap = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Airgap = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Speed[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_B = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_C = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_D = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Pitch = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Roll = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->G_Factor = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->P_Factor = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->R_Factor = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[3] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[3] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->PitchError = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[3] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefPitchOut = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefRollOut = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Power = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Power_avg = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Energy = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedMass = 0.0;

    /* previous zero-crossing states */
    {
      PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE =
        UNINITIALIZED_ZCSIG;
      PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g =
        UNINITIALIZED_ZCSIG;
      PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a =
        UNINITIALIZED_ZCSIG;
      PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n =
        UNINITIALIZED_ZCSIG;
      PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k =
        UNINITIALIZED_ZCSIG;
    }
  }

  return PIDcontroller4CoreCentralizedTestReadyMotor_M;
}
