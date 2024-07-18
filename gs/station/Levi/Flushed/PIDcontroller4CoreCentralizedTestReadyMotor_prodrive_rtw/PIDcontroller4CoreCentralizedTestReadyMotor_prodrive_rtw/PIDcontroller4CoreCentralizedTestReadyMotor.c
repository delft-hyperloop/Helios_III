/*
 * PIDcontroller4CoreCentralizedTestReadyMotor.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIDcontroller4CoreCentralizedTestReadyMotor".
 *
 * Model version              : 6.332
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Wed Jul 17 17:34:20 2024
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
static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
   *obj, real_T u);

/* Forward declaration for local functions */
static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_h
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
   *obj, real_T u);

/* Forward declaration for local functions */
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

/* Forward declaration for local functions */
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
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(real_T *a,
  real_T *b, real_T *c, real_T *s);
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

/* Forward declaration for local functions */
static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
   *obj);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cx(int32_T n,
  const real_T x[12], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_m(real_T A[12],
  real_T tau[3], int32_T jpvt[3]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm_c(const real_T x
  [3]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b(int32_T n,
  const real_T x[9], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_b(int32_T n,
  real_T a, real_T x[9], int32_T ix0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4(int32_T n,
  const real_T x[3], int32_T ix0);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(int32_T n,
  const real_T x[9], int32_T ix0, const real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(int32_T n,
  real_T a, int32_T ix0, real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bh(int32_T n,
  real_T a, real_T x[3], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_gl(int32_T n,
  real_T a, const real_T x[9], int32_T ix0, real_T y[3], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_glf(int32_T n,
  real_T a, const real_T x[3], int32_T ix0, real_T y[9], int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(real_T a,
  real_T x[9], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(real_T *a,
  real_T *b, real_T *c, real_T *s);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(real_T x[9],
  int32_T ix0, int32_T iy0, real_T c, real_T s);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap_m(real_T x[9],
  int32_T ix0, int32_T iy0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd_i(const real_T A[9],
  real_T U[9], real_T s[3], real_T V[9]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z(int32_T n,
  const real_T x[27], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_n(int32_T m,
  int32_T n, const real_T A[27], int32_T ia0, const real_T x[27], int32_T ix0,
  real_T y[3]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_j(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[3], real_T A[27],
  int32_T ia0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor_p(const real_T
  A[18], const real_T S[36], const real_T Ns[9], real_T b_S[9]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_i(const real_T
  A[9], real_T B[18]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_im(const real_T
  A[9], real_T B[18]);
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z1(int32_T n,
  const real_T x[54], int32_T ix0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_nv(int32_T m,
  int32_T n, const real_T A[54], int32_T ia0, const real_T x[54], int32_T ix0,
  real_T y[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_jf(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[6], real_T A[54],
  int32_T ia0);
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_h(real_T A[54],
  real_T tau[6]);
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr_g(const real_T A[54],
  real_T Q[54], real_T R[36]);
static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_o
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
   *obj, real_T u);
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

real_T look1_pbinlgpw(real_T u0, const real_T bp0[], const real_T table[],
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
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  if (u0 < bp0[maxIndex]) {
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

uint32_T plook_binxpg(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                      *fraction, uint32_T *prevIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  if (u < bp[maxIndex]) {
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

  /* InitializeConditions for MATLABSystem: '<S39>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S39>/Moving Average' */
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
  /* Start for MATLABSystem: '<S39>/Moving Average' */
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

  /* MATLABSystem: '<S39>/Moving Average' */
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

  /* MATLABSystem: '<S39>/Moving Average' */
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

  /* Terminate for MATLABSystem: '<S39>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S39>/Moving Average' */
}

/* Function for MATLAB Function: '<S37>/FindCoordinates' */
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

/* Function for MATLAB Function: '<S37>/FindCoordinates' */
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

/* Function for MATLAB Function: '<S37>/FindCoordinates' */
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
 *    '<S37>/FindCoordinates'
 *    '<S38>/FindCoordinates'
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

  /* MATLAB Function 'Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/FindCoordinates': '<S46>:1' */
  /* '<S46>:1:5' */
  /* '<S46>:1:6' */
  /* '<S46>:1:8' */
  /* '<S46>:1:11' */
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

  /* SignalConversion generated from: '<S46>/ SFunction ' */
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

  /* '<S46>:1:16' */
  /* '<S46>:1:17' */
  /* '<S46>:1:18' */
  /* '<S46>:1:21' */
  X[0] = 1.0;
  X[1] = 0.0;
  X[2] = C[0];

  /* '<S46>:1:22' */
  /* '<S46>:1:23' */
  Y[0] = 0.0;
  Y[1] = 1.0;
  Y[2] = C[1];

  /* '<S46>:1:24' */
  /* '<S46>:1:33' */
  /* '<S46>:1:34' */
  /* '<S46>:1:43' */
  /* '<S46>:1:44' */
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
 *    '<S37>/FindCoordinates'
 *    '<S38>/FindCoordinates'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates_Term(void)
{
}

static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
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

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Init
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S71>/Moving Average1' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 3999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S71>/Moving Average1' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Start
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  /* Start for MATLABSystem: '<S71>/Moving Average1' */
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
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1(real_T rtu_0,
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB,
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;
  int32_T i;

  /* MATLABSystem: '<S71>/Moving Average1' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 3999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 3999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* MATLABSystem: '<S71>/Moving Average1' */
  localB->MovingAverage1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl
    (obj, rtu_0);
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Term
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj;

  /* Terminate for MATLABSystem: '<S71>/Moving Average1' */
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

  /* End of Terminate for MATLABSystem: '<S71>/Moving Average1' */
}

static real_T
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_h
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
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
  if (obj->pCumRevIndex != 999.0) {
    cumRevIndex = obj->pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (k = 997; k >= 0; k--) {
      obj->pCumSumRev[k] += obj->pCumSumRev[k + 1];
    }
  }

  y = z / 1000.0;
  obj->pCumSum = csum;
  obj->pCumRevIndex = cumRevIndex;
  return y;
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
    *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S72>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S72>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  /* Start for MATLABSystem: '<S72>/Moving Average' */
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
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T *localB,
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
    *obj;
  int32_T i;

  /* MATLABSystem: '<S72>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* MATLABSystem: '<S72>/Moving Average' */
  localB->MovingAverage =
    PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_h
    (obj, rtu_0);
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
    *obj;

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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_ju(real_T a,
  real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/* Function for MATLAB Function: '<S406>/Correct' */
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

/*
 * System initialize for enable system:
 *    '<S405>/Correct1'
 *    '<S414>/Correct1'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Init
  (B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  /* SystemInitialize for Outport: '<S406>/yBlockOrdering' */
  localB->blockOrdering = false;
}

/*
 * Output and update for enable system:
 *    '<S405>/Correct1'
 *    '<S414>/Correct1'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1(boolean_T rtu_Enable,
  const real_T rtu_yMeas[3], const real_T rtu_R[9], boolean_T rtu_uBlockOrdering,
  real_T rtd_P[36], real_T rtd_x[6],
  B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  real_T a__1[54];
  real_T y_0[54];
  real_T A[36];
  real_T y[36];
  real_T C[18];
  real_T K[18];
  real_T b_C[18];
  real_T dHdx[18];
  real_T R[9];
  real_T Ss[9];
  real_T V[9];
  real_T imvec[6];
  real_T s[3];
  real_T epsilon;
  real_T rtu_yMeas_idx_1;
  real_T rtu_yMeas_idx_2;
  int32_T R_tmp;
  int32_T aoffset;
  int32_T c_k;
  int32_T coffset;
  int32_T i;
  boolean_T p;

  /* Outputs for Enabled SubSystem: '<S405>/Correct1' incorporates:
   *  EnablePort: '<S406>/Enable'
   */
  if (rtu_Enable) {
    /* MATLAB Function: '<S406>/Correct' incorporates:
     *  DataStoreRead: '<S406>/Data Store ReadP'
     *  DataStoreRead: '<S406>/Data Store ReadX'
     */
    localB->blockOrdering = rtu_uBlockOrdering;

    /* MATLAB Function 'Extras/EKFCorrect/Correct': '<S409>:1' */
    /* '<S409>:1:11' */
    p = true;
    for (c_k = 0; c_k < 9; c_k++) {
      if (((int32_T)p) && ((!(int32_T)rtIsInf(rtu_R[c_k])) && (!(int32_T)rtIsNaN
            (rtu_R[c_k])))) {
      } else {
        p = false;
      }
    }

    if (p) {
      PIDcontroller4CoreCentralizedTestReadyMotor_svd(rtu_R, Ss, s, V);
    } else {
      s[0] = (rtNaN);
      s[1] = (rtNaN);
      s[2] = (rtNaN);
      for (c_k = 0; c_k < 9; c_k++) {
        V[c_k] = (rtNaN);
      }
    }

    for (c_k = 0; c_k < 9; c_k++) {
      Ss[c_k] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_k = 0; c_k < 9; c_k++) {
      Ss[c_k] = sqrt(Ss[c_k]);
    }

    for (c_k = 0; c_k < 3; c_k++) {
      for (i = 0; i < 3; i++) {
        R_tmp = i + 3 * c_k;
        R[R_tmp] = 0.0;
        R[R_tmp] += Ss[3 * c_k] * V[i];
        R[R_tmp] += Ss[3 * c_k + 1] * V[i + 3];
        R[R_tmp] += Ss[3 * c_k + 2] * V[i + 6];
      }
    }

    s[0] = rtd_x[1];
    s[1] = rtd_x[3];
    s[2] = rtd_x[5];
    for (c_k = 0; c_k < 6; c_k++) {
      for (i = 0; i < 6; i++) {
        imvec[i] = rtd_x[i];
      }

      epsilon = 1.4901161193847656E-8 * fabs(rtd_x[c_k]);
      if ((1.4901161193847656E-8 > epsilon) || ((int32_T)rtIsNaN(epsilon))) {
        epsilon = 1.4901161193847656E-8;
      }

      imvec[c_k] = rtd_x[c_k] + epsilon;
      dHdx[3 * c_k] = (imvec[1] - s[0]) / epsilon;
      dHdx[3 * c_k + 1] = (imvec[3] - s[1]) / epsilon;
      dHdx[3 * c_k + 2] = (imvec[5] - s[2]) / epsilon;
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor(dHdx, rtd_P, R, Ss);
    for (c_k = 0; c_k < 6; c_k++) {
      for (i = 0; i < 6; i++) {
        coffset = c_k + 6 * i;
        A[coffset] = 0.0;
        for (R_tmp = 0; R_tmp < 6; R_tmp++) {
          A[coffset] += rtd_P[6 * R_tmp + c_k] * rtd_P[6 * R_tmp + i];
        }
      }
    }

    for (c_k = 0; c_k < 3; c_k++) {
      for (i = 0; i < 6; i++) {
        coffset = c_k + 3 * i;
        K[coffset] = 0.0;
        for (R_tmp = 0; R_tmp < 6; R_tmp++) {
          K[coffset] += A[6 * R_tmp + i] * dHdx[3 * R_tmp + c_k];
        }
      }
    }

    for (c_k = 0; c_k < 6; c_k++) {
      C[3 * c_k] = K[3 * c_k];
      i = 3 * c_k + 1;
      C[i] = K[i];
      i = 3 * c_k + 2;
      C[i] = K[i];
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_trisolve(Ss, C);
    for (c_k = 0; c_k < 6; c_k++) {
      b_C[3 * c_k] = C[3 * c_k];
      i = 3 * c_k + 1;
      b_C[i] = C[i];
      i = 3 * c_k + 2;
      b_C[i] = C[i];
    }

    for (c_k = 0; c_k < 3; c_k++) {
      V[3 * c_k] = Ss[c_k];
      V[3 * c_k + 1] = Ss[c_k + 3];
      V[3 * c_k + 2] = Ss[c_k + 6];
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_e(V, b_C);
    for (c_k = 0; c_k < 3; c_k++) {
      for (i = 0; i < 6; i++) {
        K[i + 6 * c_k] = b_C[3 * i + c_k];
      }
    }

    for (c_k = 0; c_k < 18; c_k++) {
      C[c_k] = -K[c_k];
    }

    for (c_k = 0; c_k < 6; c_k++) {
      for (i = 0; i < 6; i++) {
        R_tmp = i + 6 * c_k;
        A[R_tmp] = 0.0;
        A[R_tmp] += dHdx[3 * c_k] * C[i];
        A[R_tmp] += dHdx[3 * c_k + 1] * C[i + 6];
        A[R_tmp] += dHdx[3 * c_k + 2] * C[i + 12];
      }
    }

    for (c_k = 0; c_k < 6; c_k++) {
      R_tmp = 6 * c_k + c_k;
      A[R_tmp]++;
    }

    for (c_k = 0; c_k < 6; c_k++) {
      coffset = c_k * 6;
      for (i = 0; i < 6; i++) {
        aoffset = i * 6;
        epsilon = 0.0;
        for (R_tmp = 0; R_tmp < 6; R_tmp++) {
          epsilon += A[R_tmp * 6 + c_k] * rtd_P[aoffset + R_tmp];
        }

        y[coffset + i] = epsilon;
      }
    }

    for (c_k = 0; c_k < 3; c_k++) {
      for (i = 0; i < 6; i++) {
        coffset = c_k + 3 * i;
        C[coffset] = 0.0;
        C[coffset] += R[3 * c_k] * K[i];
        C[coffset] += R[3 * c_k + 1] * K[i + 6];
        C[coffset] += R[3 * c_k + 2] * K[i + 12];
      }
    }

    for (c_k = 0; c_k < 6; c_k++) {
      for (i = 0; i < 6; i++) {
        y_0[i + 9 * c_k] = y[6 * c_k + i];
      }

      y_0[9 * c_k + 6] = C[3 * c_k];
      y_0[9 * c_k + 7] = C[3 * c_k + 1];
      y_0[9 * c_k + 8] = C[3 * c_k + 2];
    }

    PIDcontroller4CoreCentralizedTestReadyMotor_qr(y_0, a__1, A);

    /* '<S409>:1:135' */
    epsilon = rtu_yMeas[0] - rtd_x[1];
    rtu_yMeas_idx_1 = rtu_yMeas[1] - rtd_x[3];
    rtu_yMeas_idx_2 = rtu_yMeas[2] - rtd_x[5];
    for (c_k = 0; c_k < 6; c_k++) {
      /* DataStoreWrite: '<S406>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S406>/Correct'
       */
      for (i = 0; i < 6; i++) {
        rtd_P[i + 6 * c_k] = A[6 * i + c_k];
      }

      /* End of DataStoreWrite: '<S406>/Data Store WriteP' */

      /* DataStoreWrite: '<S406>/Data Store WriteX' incorporates:
       *  DataStoreRead: '<S406>/Data Store ReadX'
       *  MATLAB Function: '<S406>/Correct'
       */
      rtd_x[c_k] += (K[c_k + 6] * rtu_yMeas_idx_1 + K[c_k] * epsilon) + K[c_k +
        12] * rtu_yMeas_idx_2;
    }
  }

  /* End of Outputs for SubSystem: '<S405>/Correct1' */
}

/*
 * Termination for enable system:
 *    '<S405>/Correct1'
 *    '<S414>/Correct1'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Term(void)
{
}

/*
 * Output and update for atomic system:
 *    '<S405>/Output'
 *    '<S414>/Output'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Output(boolean_T
  rtu_uBlockOrdering, const real_T rtd_x[6],
  B_Output_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  int32_T i;
  for (i = 0; i < 6; i++) {
    /* DataStoreRead: '<S407>/Data Store Read' */
    localB->DataStoreRead[i] = rtd_x[i];
  }

  /* Inport: '<S407>/uBlockOrdering' */
  /* MATLAB Function 'Extended Kalman Filter/Output/MATLAB Function': '<S410>:1' */
  /* '<S410>:1:4' */
  localB->uBlockOrdering = rtu_uBlockOrdering;
}

/*
 * Termination for atomic system:
 *    '<S405>/Output'
 *    '<S414>/Output'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Output_Term(void)
{
}

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_mce(real_T a,
  real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(real_T *a,
  real_T *b, real_T *c, real_T *s)
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(&b_s[qjj], &rt,
          &ztest, &sqds);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(&b_s[qjj], &rt,
          &ztest, &sqds);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(&rt, &ztest, &sqds,
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_b(&rt, &ztest, &sqds,
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/* Function for MATLAB Function: '<S408>/Predict' */
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

/*
 * Output and update for atomic system:
 *    '<S405>/Predict'
 *    '<S414>/Predict'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Predict(const real_T rtu_Q[36],
  const real_T rtu_uState[12], real_T rtd_P[36], real_T rtd_x[6])
{
  real_T Ss[36];
  real_T V[36];
  real_T V_0[36];
  real_T s[6];
  int32_T V_tmp;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  boolean_T p;

  /* MATLAB Function: '<S408>/Predict' */
  /* MATLAB Function 'Extended Kalman Filter/Predict/Predict': '<S411>:1' */
  /* '<S411>:1:11' */
  p = true;
  for (i = 0; i < 36; i++) {
    if (((int32_T)p) && ((!(int32_T)rtIsInf(rtu_Q[i])) && (!(int32_T)rtIsNaN
          (rtu_Q[i])))) {
    } else {
      p = false;
    }
  }

  if (p) {
    PIDcontroller4CoreCentralizedTestReadyMotor_svd_a(rtu_Q, Ss, s, V);
  } else {
    for (i = 0; i < 6; i++) {
      s[i] = (rtNaN);
    }

    for (i = 0; i < 36; i++) {
      V[i] = (rtNaN);
    }
  }

  for (i = 0; i < 36; i++) {
    Ss[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    Ss[i + 6 * i] = s[i];
  }

  for (i = 0; i < 36; i++) {
    Ss[i] = sqrt(Ss[i]);
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      V_0[i_0 + 6 * i] = 0.0;
    }

    for (i_1 = 0; i_1 < 6; i_1++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        V_tmp = 6 * i + i_0;
        V_0[V_tmp] += V[6 * i_1 + i_0] * Ss[6 * i + i_1];
      }
    }
  }

  /* DataStoreWrite: '<S408>/Data Store WriteX' incorporates:
   *  DataStoreWrite: '<S408>/Data Store WriteP'
   *  MATLAB Function: '<S408>/Predict'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_EKFPredictorAdditive_predict(V_0,
    rtd_x, rtd_P, rtu_uState);

  /* '<S411>:1:123' */
}

/*
 * Termination for atomic system:
 *    '<S405>/Predict'
 *    '<S414>/Predict'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Predict_Term(void)
{
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
 *    '<S24>/Cap requested current1'
 *    '<S24>/Cap requested current2'
 *    '<S24>/Cap requested current3'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(real_T
  rtu_measured_I, real_T rtu_requested_I, real_T rtu_max_delta,
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB)
{
  /* MATLAB Function 'Subsystem5/Cap requested current1': '<S549>:1' */
  if (rtu_requested_I - rtu_measured_I > rtu_max_delta) {
    /* '<S549>:1:4' */
    /* '<S549>:1:5' */
    localB->out_req_I = rtu_measured_I + rtu_max_delta;
  } else if (rtu_measured_I - rtu_requested_I > rtu_max_delta) {
    /* '<S549>:1:6' */
    /* '<S549>:1:7' */
    localB->out_req_I = rtu_measured_I - rtu_max_delta;
  } else {
    /* '<S549>:1:9' */
    localB->out_req_I = rtu_requested_I;
  }
}

/*
 * Termination for atomic system:
 *    '<S24>/Cap requested current1'
 *    '<S24>/Cap requested current2'
 *    '<S24>/Cap requested current3'
 */
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1_Term(void)
{
}

static void PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
  (dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
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

/* Function for MATLAB Function: '<S428>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cx(int32_T n,
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

/* Function for MATLAB Function: '<S428>/FindCoordinates' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_m(real_T A[12],
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
    scale = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cx(3 - k, A, ii +
      2);
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
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cx
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
          vn1[ii] = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_cx(3 - k,
            A, pvt + 2);
          vn2[ii] = vn1[ii];
        } else {
          vn1[ii] *= sqrt(smax);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S428>/FindCoordinates' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_norm_c(const real_T x
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

/* Function for MATLAB Function: '<S417>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_b(int32_T n,
  real_T a, real_T x[9], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S417>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(int32_T n,
  const real_T x[9], int32_T ix0, const real_T y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(int32_T n,
  real_T a, int32_T ix0, real_T y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bh(int32_T n,
  real_T a, real_T x[3], int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_gl(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_glf(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(real_T a,
  real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(real_T *a,
  real_T *b, real_T *c, real_T *s)
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(real_T x[9],
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xswap_m(real_T x[9],
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_svd_i(const real_T A[9],
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
  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b(3, b_A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (fabs(b_s[0]) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_b(3, 1.0 / b_s[0], b_A,
        1);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(3,
        -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(3, b_A, 1, b_A,
        qjj + 1) / b_A[0]), 1, b_A, qjj + 1);
    }

    e[d] = b_A[qjj];
  }

  while (qq + 1 < 4) {
    U[qq] = b_A[qq];
    qq++;
  }

  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4(2, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      nrm = -nrm;
    }

    e[0] = nrm;
    if (fabs(nrm) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bh(2, 1.0 / nrm, e, 2);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_gl(2, e[qq], b_A, 3 * qq
        + 2, work, 2);
    }

    for (qq = 1; qq + 1 < 4; qq++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_glf(2, -e[qq] / e[1],
        work, 2, b_A, 3 * qq + 2);
    }
  }

  for (qq = 1; qq + 1 < 4; qq++) {
    V[qq] = e[qq];
  }

  apply_transform = false;
  nrm = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b(2, b_A, 5);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      b_s[1] = -nrm;
    } else {
      b_s[1] = nrm;
    }

    if (fabs(b_s[1]) >= 1.0020841800044864E-292) {
      PIDcontroller4CoreCentralizedTestReadyMotor_xscal_b(2, 1.0 / b_s[1], b_A,
        5);
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
      PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(2,
        -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(2, b_A, 5, b_A,
        qjj + 1) / b_A[4]), 5, b_A, qjj + 1);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(3 - d,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(3 - d, U, qq + 1,
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xaxpy_g(2,
          -(PIDcontroller4CoreCentralizedTestReadyMotor_xdotc_c(2, V, 2, V, qjj)
            / V[1]), 2, V, qjj);
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
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(nrm, U, 1);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] *= nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(nrm, V, 4);
  }

  e[0] = ztest;
  ztest = b_A[7];
  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    ztest = b_A[7] / nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(nrm, U, 4);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[2] = b_A[8] * nrm;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(nrm, V, 7);
  }

  e[1] = ztest;
  if (b_s[2] != 0.0) {
    rt = fabs(b_s[2]);
    nrm = b_s[2] / rt;
    b_s[2] = rt;
    PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(nrm, U, 7);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(&b_s[qjj], &rt,
          &ztest, &sqds);
        if (qjj + 1 > d + 1) {
          rt = -sqds * e[0];
          e[0] *= ztest;
        }

        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(V, 3 * qjj + 1, 3 *
          (m + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[d - 1];
      e[d - 1] = 0.0;
      for (qjj = d; qjj < m + 2; qjj++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(&b_s[qjj], &rt,
          &ztest, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(U, 3 * qjj + 1, 3 *
          (d - 1) + 1, ztest, sqds);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(&rt, &ztest, &sqds,
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(V, 3 * (qjj - 1) + 1,
          3 * qjj + 1, sqds, smm1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xrotg_bk(&rt, &ztest, &sqds,
          &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        PIDcontroller4CoreCentralizedTestReadyMotor_xrot_k(U, 3 * (qjj - 1) + 1,
          3 * qjj + 1, sqds, smm1);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[d] < 0.0) {
        b_s[d] = -b_s[d];
        PIDcontroller4CoreCentralizedTestReadyMotor_xscal_bha(-1.0, V, 3 * d + 1);
      }

      qq = d + 1;
      while ((d + 1 < 3) && (b_s[d] < b_s[qq])) {
        rt = b_s[d];
        b_s[d] = b_s[qq];
        b_s[qq] = rt;
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap_m(V, 3 * d + 1, 3 * (d
          + 1) + 1);
        PIDcontroller4CoreCentralizedTestReadyMotor_xswap_m(U, 3 * d + 1, 3 * (d
          + 1) + 1);
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

/* Function for MATLAB Function: '<S417>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_n(int32_T m,
  int32_T n, const real_T A[27], int32_T ia0, const real_T x[27], int32_T ix0,
  real_T y[3])
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_j(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[3], real_T A[27],
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor_p(const real_T
  A[18], const real_T S[36], const real_T Ns[9], real_T b_S[9])
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
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z(8, b_A, 2);
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
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z
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
    PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_n(knt, aoffset, b_A, 10,
      b_A, 1, work);
    PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_j(knt, aoffset, -tau_idx_0,
      1, work, b_A, 10);
  }

  b_A[0] = s;
  s = b_A[10];
  tau_idx_0 = 0.0;
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z(7, b_A, 12);
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
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z
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
    PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_n(knt, aoffset, b_A, 20,
      b_A, 11, work);
    PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_j(knt, aoffset, -tau_idx_0,
      11, work, b_A, 20);
  }

  b_A[10] = s;
  s = b_A[20];
  beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z(6, b_A, 22);
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
                            PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_i(const real_T
  A[9], real_T B[18])
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_im(const real_T
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

/* Function for MATLAB Function: '<S417>/Correct' */
static real_T PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z1(int32_T n,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_nv(int32_T m,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_jf(int32_T m,
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

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_h(real_T A[54],
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
    beta1 = PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z1(8 - i, A, ii
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
                              PIDcontroller4CoreCentralizedTestReadyMotor_xnrm2_b4z1
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_nv(knt, lastc, A, ii +
          10, A, ii + 1, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_jf(knt, lastc, -tau[i],
          ii + 1, work, A, ii + 10);
      }

      A[ii] = b_atmp;
    }
  }
}

/* Function for MATLAB Function: '<S417>/Correct' */
static void PIDcontroller4CoreCentralizedTestReadyMotor_qr_g(const real_T A[54],
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
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqrf_h(b_A, tau);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_xgemv_nv(lastv, lastc, b_A,
          itau, b_A, itau - 9, work);
        PIDcontroller4CoreCentralizedTestReadyMotor_xgerc_jf(lastv, lastc,
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
  PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_o
  (c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
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
  real_T rtb_Derivative[3];
  real_T rtb_Derivative1[3];
  real_T rtb_avg_g;
  real_T rtb_pitch_j;
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
  real_T rtb_error;
  real_T rtb_Switch_n;
  real_T rtb_ZeroOrderHold1[12];
  real_T rtb_ZeroOrderHold[3];
  real_T rtb_CreateDiagonalMatrix[9];
  real_T rtb_ZeroOrderHold_b[3];
  real_T rtb_CreateDiagonalMatrix_g[9];
  real_T rtb_Switch_n4;
  real_T rtb_Switch_ph;
  real_T rtb_CreateDiagonalMatrix1[36];
  real_T rtb_ZeroOrderHold1_k[12];
  real_T rtb_CreateDiagonalMatrix1_c[36];
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *obj;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj_0;
  real_T a__1[54];
  real_T y_0[54];
  real_T rtb_Add_e[39];
  real_T rtb_uDLookupTable1_gs[39];
  real_T A_0[36];
  real_T y[36];
  real_T rtb_Flip[30];
  real_T rtb_Flip_d[30];
  real_T rtb_Flip_l[30];
  real_T rtb_Flip_n[30];
  real_T rtb_uDLookupTable2_bl[30];
  real_T rtb_uDLookupTable2_c[30];
  real_T rtb_uDLookupTable2_j[30];
  real_T rtb_uDLookupTable2_p[30];
  real_T C_0[18];
  real_T K[18];
  real_T b_C[18];
  real_T dHdx[18];
  real_T A[12];
  real_T R[9];
  real_T Ss[9];
  real_T V[9];
  real_T rtb_CreateDiagonalMatrix2[9];
  real_T imvec[6];
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
  real_T F1;
  real_T F3;
  real_T rtb_Add1_d;
  real_T rtb_Add1_f;
  real_T rtb_Add1_n;
  real_T rtb_Add2_c;
  real_T rtb_Add2_h;
  real_T rtb_Add3_l;
  real_T rtb_Add4_n;
  real_T rtb_Add_l;
  real_T rtb_DiscreteTimeIntegrator1_c;
  real_T rtb_DiscreteTimeIntegrator1_il;
  real_T rtb_DiscreteTimeIntegrator1_o;
  real_T rtb_DiscreteTimeIntegrator1_o2;
  real_T rtb_DiscreteTimeIntegrator_c;
  real_T rtb_DiscreteTimeIntegrator_j2;
  real_T rtb_DiscreteTimeIntegrator_lo;
  real_T rtb_DiscreteTimeIntegrator_o1;
  real_T rtb_DiscreteTimeIntegrator_p;
  real_T rtb_Divide;
  real_T rtb_Divide1;
  real_T rtb_Divide_k;
  real_T rtb_F_array_idx_3;
  real_T rtb_Gain1_gt;
  real_T rtb_Gain2;
  real_T rtb_Gain_do;
  real_T rtb_Gain_m;
  real_T rtb_IProdOut;
  real_T rtb_IProdOut_h;
  real_T rtb_IProdOut_k;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_2;
  real_T rtb_Product_idx_3;
  real_T rtb_Subtract2_f;
  real_T rtb_Subtract_idx_0;
  real_T rtb_Subtract_idx_1;
  real_T rtb_Subtract_idx_2;
  real_T rtb_Subtract_idx_3;
  real_T rtb_Sum;
  real_T rtb_Sum_ac;
  real_T rtb_Sum_eh;
  real_T rtb_Sum_gy;
  real_T rtb_Sum_h;
  real_T rtb_Sum_ku;
  real_T rtb_Sum_o;
  real_T rtb_Sum_pc;
  real_T rtb_Switch1;
  real_T rtb_Switch1_d;
  real_T rtb_Switch1_o;
  real_T rtb_Switch2_idx_0;
  real_T rtb_Switch2_idx_1;
  real_T rtb_Switch2_idx_2;
  real_T rtb_Switch_gj;
  real_T rtb_Switch_juh;
  real_T rtb_Switch_k_idx_0;
  real_T rtb_Switch_k_idx_1;
  real_T rtb_Switch_k_idx_2;
  real_T rtb_Switch_k_idx_3;
  real_T rtb_Switch_ka;
  real_T rtb_Switch_kb;
  real_T rtb_Switch_my;
  real_T rtb_Switch_pa;
  real_T rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;
  real_T rtb_TrigonometricFunction;
  real_T rtb_error_m;
  real_T rtb_out_req_I;
  real_T rtb_uDLookupTable1;
  real_T rtb_uDLookupTable1_c;
  real_T rtb_uDLookupTable1_e;
  real_T rtb_uDLookupTable1_m;
  real_T rtb_uDLookupTable1_n;
  real_T rtb_uDLookupTable2;
  real_T rtb_uDLookupTable3;
  real_T rtb_uDLookupTable4;
  real_T rtb_z_out_idx_0;
  real_T rtb_z_out_idx_1;
  real_T rtb_z_out_idx_2;
  real_T rtb_z_out_idx_3;
  real_T tol;
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
  boolean_T p_tmp;

  /* RelationalOperator: '<Root>/Equal' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode == 2.0);

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

  /* Product: '<S32>/Divide' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   */
  rtb_Divide = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ReferenceMass;

  /* RelationalOperator: '<S22>/Equal' incorporates:
   *  Constant: '<S22>/Constant14'
   *  Delay: '<S22>/Delay1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE == 2.0);

  /* DiscreteIntegrator: '<S531>/Integrator' */
  p_tmp = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE = 0.0;
  }

  /* SampleTimeMath: '<S526>/Tsamp' incorporates:
   *  Gain: '<S523>/Derivative Gain'
   *
   * About '<S526>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp = 0.0;

  /* Delay: '<S524>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Sum: '<S540>/Sum' incorporates:
   *  Delay: '<S524>/UD'
   *  DiscreteIntegrator: '<S531>/Integrator'
   *  Sum: '<S524>/Diff'
   */
  rtb_Sum = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp -
             PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE) +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE;

  /* DiscreteIntegrator: '<S481>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j = 0.0;
  }

  /* SampleTimeMath: '<S476>/Tsamp' incorporates:
   *  Gain: '<S473>/Derivative Gain'
   *
   * About '<S476>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b = 0.0;

  /* Delay: '<S474>/UD' incorporates:
   *  Delay: '<S524>/UD'
   */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_g =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Sum: '<S490>/Sum' incorporates:
   *  Delay: '<S474>/UD'
   *  DiscreteIntegrator: '<S481>/Integrator'
   *  Sum: '<S474>/Diff'
   */
  rtb_Sum_pc = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b -
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p) +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j;

  /* Switch: '<S22>/Switch1' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant13'
   *  Constant: '<S22>/Constant3'
   *  Sum: '<S22>/Add1'
   *  Sum: '<S22>/Subtract3'
   *  Switch: '<S22>/Switch6'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode != 0.0) {
    rtb_Switch1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode;
  } else if ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime +
              PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RunTime) -
             rtb_Sum_pc > 0.0) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     *  Sum: '<S22>/Subtract'
     *  Switch: '<S22>/Switch6'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime - rtb_Sum
        > 0.0) {
      rtb_Switch1 =
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->OperatingMode;
    } else {
      rtb_Switch1 = 1.0;
    }

    /* End of Switch: '<S22>/Switch' */
  } else {
    /* Switch: '<S22>/Switch6' incorporates:
     *  Constant: '<S22>/Constant12'
     */
    rtb_Switch1 = 3.0;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  if (((int32_T)p_tmp) && ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
       == 1)) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
      = 0.0;
  }

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S22>/Constant4'
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Sum: '<S22>/Subtract1'
   *  Switch: '<S22>/Switch4'
   */
  if (rtb_Switch1 - 3.0 != 0.0) {
    /* Outport: '<Root>/Mode' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = rtb_Switch1;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
       > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LandingTime) {
    /* Switch: '<S22>/Switch4' incorporates:
     *  Constant: '<S22>/Constant7'
     *  Outport: '<Root>/Mode'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = 2.0;
  } else {
    /* Outport: '<Root>/Mode' incorporates:
     *  Constant: '<S22>/Constant6'
     *  Switch: '<S22>/Switch4'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode = 3.0;
  }

  /* End of Switch: '<S22>/Switch2' */

  /* DiscretePulseGenerator: '<S31>/Pulse Generator' */
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

  /* End of DiscretePulseGenerator: '<S31>/Pulse Generator' */

  /* Product: '<S31>/Product1' incorporates:
   *  Constant: '<S31>/Constant6'
   *  Constant: '<S31>/Constant9'
   *  Sum: '<S31>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1 = ((real_T)
    rtb_PulseGenerator - 1.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S47>/Switch1' incorporates:
     *  Lookup_n-D: '<S47>/n-D Lookup Table'
     */
    rtb_Switch1_m = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S47>/Switch1' incorporates:
     *  Constant: '<S47>/Constant'
     */
    rtb_Switch1_m =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S47>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1, rtb_Switch1_m,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage,
     rtb_Switch1_m,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S39>/Switch' */
    rtb_Switch =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage.MovingAverage;
  } else {
    /* Switch: '<S39>/Switch' */
    rtb_Switch =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Gain: '<S31>/Gain' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsFactor *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S48>/Switch1' incorporates:
     *  Lookup_n-D: '<S48>/n-D Lookup Table'
     */
    rtb_Switch1_e = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S48>/Switch1' incorporates:
     *  Constant: '<S48>/Constant'
     */
    rtb_Switch1_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S48>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain, rtb_Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage,
     rtb_Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S40>/Switch' */
    rtb_Switch_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p.MovingAverage;
  } else {
    /* Switch: '<S40>/Switch' */
    rtb_Switch_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Switch: '<S31>/Switch7' incorporates:
   *  Constant: '<S31>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsBackDelay >
      0.0) {
    /* Switch: '<S31>/Switch7' incorporates:
     *  Delay: '<S31>/Delay1'
     */
    rtb_Switch7 =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[0];
  } else {
    /* Switch: '<S31>/Switch7' */
    rtb_Switch7 = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;
  }

  /* End of Switch: '<S31>/Switch7' */

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S49>/Switch1' incorporates:
     *  Lookup_n-D: '<S49>/n-D Lookup Table'
     */
    rtb_Switch1_p = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S49>/Switch1' incorporates:
     *  Constant: '<S49>/Constant'
     */
    rtb_Switch1_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S49>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Switch7,
    rtb_Switch1_p,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage,
     rtb_Switch1_p,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S41>/Switch' */
    rtb_Switch_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn.MovingAverage;
  } else {
    /* Switch: '<S41>/Switch' */
    rtb_Switch_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsetsBackDelay >
      0.0) {
    /* Switch: '<S31>/Switch' incorporates:
     *  Delay: '<S31>/Delay'
     */
    rtb_Switch_i = PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE
      [0];
  } else {
    /* Switch: '<S31>/Switch' */
    rtb_Switch_i = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Switch: '<S50>/Switch1' incorporates:
   *  Constant: '<S50>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S50>/Switch1' incorporates:
     *  Lookup_n-D: '<S50>/n-D Lookup Table'
     */
    rtb_Switch1_j = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S50>/Switch1' incorporates:
     *  Constant: '<S50>/Constant'
     */
    rtb_Switch1_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S50>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Switch_i,
    rtb_Switch1_j,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage,
     rtb_Switch1_j,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S42>/Switch' */
    rtb_Switch_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna.MovingAverage;
  } else {
    /* Switch: '<S42>/Switch' */
    rtb_Switch_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage;
  }

  /* End of Switch: '<S42>/Switch' */

  /* MATLAB Function: '<S37>/FindCoordinates' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S37>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(rtb_Switch,
    rtb_Switch_e, rtb_Switch_b, rtb_Switch_j, 0.465, 0.392, 0.1596,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates);

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S51>/Switch1' incorporates:
     *  Lookup_n-D: '<S51>/n-D Lookup Table'
     */
    rtb_Switch1_c = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S51>/Switch1' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_Switch1_c =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S51>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g,
     rtb_Switch1_c,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S52>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S52>/Switch1' incorporates:
     *  Lookup_n-D: '<S52>/n-D Lookup Table'
     */
    rtb_Switch1_f = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S52>/Switch1' incorporates:
     *  Constant: '<S52>/Constant'
     */
    rtb_Switch1_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S52>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch,
     rtb_Switch1_f,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S53>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S53>/Switch1' incorporates:
     *  Lookup_n-D: '<S53>/n-D Lookup Table'
     */
    rtb_Switch1_k = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S53>/Constant'
     */
    rtb_Switch1_k =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S53>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll,
     rtb_Switch1_k,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);

  /* Sin: '<S31>/Sine Wave4' */
  rtb_SineWave4 = sin((real_T)
                      PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter *
                      2.0 * 3.1415926535897931 / 4000.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S62>/Switch1' incorporates:
     *  Lookup_n-D: '<S62>/n-D Lookup Table'
     */
    rtb_Switch1_js = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S62>/Switch1' incorporates:
     *  Constant: '<S62>/Constant'
     */
    rtb_Switch1_js =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S62>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave4,
    rtb_Switch1_js,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage,
     rtb_Switch1_js,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S54>/Switch' */
    rtb_Switch_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf.MovingAverage;
  } else {
    /* Switch: '<S54>/Switch' */
    rtb_Switch_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Sin: '<S31>/Sine Wave5' */
  rtb_SineWave5 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h
                       + 1000.0) * 2.0 * 3.1415926535897931 / 4000.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S63>/Switch1' incorporates:
   *  Constant: '<S63>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Lookup_n-D: '<S63>/n-D Lookup Table'
     */
    rtb_Switch1_em = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Switch1_em =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S63>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave5,
    rtb_Switch1_em,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage,
     rtb_Switch1_em,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S55>/Switch' */
    rtb_Switch_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp.MovingAverage;
  } else {
    /* Switch: '<S55>/Switch' */
    rtb_Switch_f =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Sin: '<S31>/Sine Wave6' */
  rtb_SineWave6 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o
                       + 3000.0) * 2.0 * 3.1415926535897931 / 4000.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Lookup_n-D: '<S64>/n-D Lookup Table'
     */
    rtb_Switch1_a = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S64>/Constant'
     */
    rtb_Switch1_a =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S64>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave6,
    rtb_Switch1_a,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage,
     rtb_Switch1_a,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S56>/Switch' */
    rtb_Switch_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg.MovingAverage;
  } else {
    /* Switch: '<S56>/Switch' */
    rtb_Switch_p =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Sin: '<S31>/Sine Wave7' */
  rtb_SineWave7 = sin(((real_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a
                       + 2000.0) * 2.0 * 3.1415926535897931 / 4000.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;

  /* Switch: '<S65>/Switch1' incorporates:
   *  Constant: '<S65>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S65>/Switch1' incorporates:
     *  Lookup_n-D: '<S65>/n-D Lookup Table'
     */
    rtb_Switch1_jf = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S65>/Switch1' incorporates:
     *  Constant: '<S65>/Constant'
     */
    rtb_Switch1_jf =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S65>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_SineWave7,
    rtb_Switch1_jf,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage,
     rtb_Switch1_jf,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    /* Switch: '<S57>/Switch' */
    rtb_Switch_iu =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh.MovingAverage;
  } else {
    /* Switch: '<S57>/Switch' */
    rtb_Switch_iu =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage;
  }

  /* End of Switch: '<S57>/Switch' */

  /* MATLAB Function: '<S38>/FindCoordinates' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(rtb_Switch_o,
    rtb_Switch_f, rtb_Switch_p, rtb_Switch_iu, 0.465, 0.392, 0.1596,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d);

  /* Switch: '<S66>/Switch1' incorporates:
   *  Constant: '<S66>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Lookup_n-D: '<S66>/n-D Lookup Table'
     */
    rtb_Switch1_cv = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Constant: '<S66>/Constant'
     */
    rtb_Switch1_cv =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S66>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g,
     rtb_Switch1_cv,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S67>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S67>/Switch1' incorporates:
     *  Lookup_n-D: '<S67>/n-D Lookup Table'
     */
    rtb_Switch1_i = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S67>/Switch1' incorporates:
     *  Constant: '<S67>/Constant'
     */
    rtb_Switch1_i =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S67>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch,
     rtb_Switch1_i,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);

  /* Switch: '<S68>/Switch1' incorporates:
   *  Constant: '<S68>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Lookup_n-D: '<S68>/n-D Lookup Table'
     */
    rtb_Switch1_ab = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S68>/Constant'
     */
    rtb_Switch1_ab =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S68>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll,
     rtb_Switch1_ab,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S31>/Constant2'
   *  Constant: '<S31>/Constant3'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S31>/Subtract2'
   *  Switch: '<S31>/Switch3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 7.0 != 0.0) {
    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S58>/Constant1'
     *  Sum: '<S31>/Subtract1'
     *  Switch: '<S58>/Switch'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 6.0 != 0.0) {
      /* Switch: '<S31>/Switch4' incorporates:
       *  Constant: '<S31>/Constant7'
       *  Constant: '<S43>/Constant1'
       *  Sum: '<S31>/Subtract6'
       *  Switch: '<S43>/Switch'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 5.0 != 0.0) {
        rtb_Switch2_idx_0 = 0.0;
        rtb_Switch2_idx_1 = 0.0;
        rtb_Switch2_idx_2 = 0.0;
      } else {
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter !=
            0.0) {
          /* Switch: '<S43>/Switch' */
          rtb_Switch2_idx_0 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae.MovingAverage;
        } else {
          rtb_Switch2_idx_0 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g;
        }

        /* Switch: '<S44>/Switch' incorporates:
         *  Constant: '<S44>/Constant1'
         *  Switch: '<S43>/Switch'
         */
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter !=
            0.0) {
          rtb_Switch2_idx_1 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev.MovingAverage;
        } else {
          rtb_Switch2_idx_1 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch;
        }

        /* End of Switch: '<S44>/Switch' */

        /* Switch: '<S45>/Switch' incorporates:
         *  Constant: '<S45>/Constant1'
         */
        if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0)
        {
          rtb_Switch2_idx_2 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv.MovingAverage;
        } else {
          rtb_Switch2_idx_2 =
            PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll;
        }

        /* End of Switch: '<S45>/Switch' */
      }

      /* End of Switch: '<S31>/Switch4' */
    } else {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter != 0.0)
      {
        /* Switch: '<S58>/Switch' */
        rtb_Switch2_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5.MovingAverage;
      } else {
        rtb_Switch2_idx_0 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g;
      }

      /* Switch: '<S59>/Switch' incorporates:
       *  Constant: '<S59>/Constant1'
       *  Switch: '<S58>/Switch'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter != 0.0)
      {
        rtb_Switch2_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z.MovingAverage;
      } else {
        rtb_Switch2_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch;
      }

      /* End of Switch: '<S59>/Switch' */

      /* Switch: '<S60>/Switch' incorporates:
       *  Constant: '<S60>/Constant1'
       */
      if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0)
      {
        rtb_Switch2_idx_2 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz.MovingAverage;
      } else {
        rtb_Switch2_idx_2 =
          PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll;
      }

      /* End of Switch: '<S60>/Switch' */
    }

    /* End of Switch: '<S31>/Switch1' */
  } else {
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[0] !=
        0.0) {
      /* Switch: '<S31>/Switch3' incorporates:
       *  Sin: '<S31>/Sine Wave1'
       */
      rtb_Switch2_idx_0 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i * 2.0 *
        3.1415926535897931 / 4000.0) *
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets;
    } else {
      rtb_Switch2_idx_0 = 0.0;
    }

    /* Switch: '<S31>/Switch5' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant3'
     *  Sin: '<S31>/Sine Wave2'
     *  Switch: '<S31>/Switch3'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[1] !=
        0.0) {
      rtb_Switch2_idx_1 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m * 2.0 *
        3.1415926535897931 / 4000.0) *
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets *
         0.00136986216);
    } else {
      rtb_Switch2_idx_1 = 0.0;
    }

    /* End of Switch: '<S31>/Switch5' */

    /* Switch: '<S31>/Switch6' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant3'
     *  Sin: '<S31>/Sine Wave3'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SineSwitches[2] !=
        0.0) {
      rtb_Switch2_idx_2 = sin((real_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n * 2.0 *
        3.1415926535897931 / 4000.0) *
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BeamOffsets *
         0.00270269612);
    } else {
      rtb_Switch2_idx_2 = 0.0;
    }

    /* End of Switch: '<S31>/Switch6' */
  }

  /* End of Switch: '<S31>/Switch2' */

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
     *  Sum: '<S36>/Sum'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch = ((rtb_Switch_k_idx_0
      + rtb_Switch_k_idx_1) + rtb_Switch_k_idx_2) + rtb_Switch_k_idx_3;
  }

  /* End of Switch: '<S74>/Switch' */

  /* DiscreteIntegrator: '<S161>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc = 0.0;
  }

  /* SampleTimeMath: '<S156>/Tsamp' incorporates:
   *  Gain: '<S153>/Derivative Gain'
   *
   * About '<S156>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch * 4000.0;

  /* Delay: '<S154>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_a =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Sum: '<S170>/Sum' incorporates:
   *  Delay: '<S154>/UD'
   *  DiscreteIntegrator: '<S161>/Integrator'
   *  Gain: '<S166>/Proportional Gain'
   *  Sum: '<S154>/Diff'
   */
  rtb_Sum_gy = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f);

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
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
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      = 0.0;
  }

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S72>/Constant2'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S72>/Subtract2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 3.0 != 0.0) {
    /* Switch: '<S72>/Switch1' incorporates:
     *  Saturate: '<S72>/Saturation'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
      /* Switch: '<S72>/Switch2' incorporates:
       *  Constant: '<S72>/Base Ref Airgap'
       */
      rtb_error =
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap;
    } else {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
          > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime) {
        /* Saturate: '<S72>/Saturation' */
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime;
      } else if
          (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
           < 0.0) {
        /* Saturate: '<S72>/Saturation' */
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
      } else {
        /* Saturate: '<S72>/Saturation' */
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE;
      }

      /* Switch: '<S72>/Switch2' incorporates:
       *  Constant: '<S72>/Base Ref Airgap'
       *  Constant: '<S72>/Constant'
       *  Gain: '<S72>/Gain'
       *  Product: '<S72>/Product'
       *  Saturate: '<S72>/Saturation'
       *  Sum: '<S72>/Subtract'
       *  Sum: '<S72>/Subtract1'
       */
      rtb_error = 1.0 /
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartupTime *
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 *
        (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap -
         PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartingAirgap) +
        PIDcontroller4CoreCentralizedTestReadyMotor_InstP->StartingAirgap;
    }

    /* End of Switch: '<S72>/Switch1' */
  } else {
    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S72>/Base Ref Airgap1'
     *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
     *  Gain: '<S72>/Gain1'
     *  Sum: '<S72>/Subtract4'
     */
    rtb_error = 1.0 /
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LandingTime *
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
      + PIDcontroller4CoreCentralizedTestReadyMotor_InstP->BaseRefAirgap;
  }

  /* End of Switch: '<S72>/Switch2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(rtb_error,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);

  /* Switch: '<S74>/Switch1' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S74>/Constant2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = rtb_Sum_gy;
  }

  /* End of Switch: '<S74>/Switch1' */

  /* Outport: '<Root>/ActualReferenceAirgap' incorporates:
   *  Sum: '<S32>/Add1'
   *  Sum: '<S32>/Add4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ActualReferenceAirgap =
    (rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 +
     PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh.MovingAverage)
    + rtb_Switch2_idx_0;

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nl
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nl
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_l
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_j2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

  /* DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
  }

  /* DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->DiscreteTimeIntegrator =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a;

  /* Gain: '<S415>/Gain10' incorporates:
   *  Delay: '<S415>/Delay'
   *  Delay: '<S415>/Delay1'
   *  Sum: '<S415>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->y_i1 =
    ((PIDcontroller4CoreCentralizedTestReadyMotor_B->DiscreteTimeIntegrator -
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_a) +
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d) * 0.999999;

  /* Gain: '<S412>/Gain1' incorporates:
   *  Inport: '<Root>/IMU_roll'
   */
  rtb_Gain1_gt =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->kalman_rolldot_gain *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_roll;

  /* Gain: '<S412>/Gain2' incorporates:
   *  Inport: '<Root>/IMU_pitch'
   */
  rtb_Gain2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->kalman_pitchdot_gain *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_pitch;

  /* S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix2' incorporates:
   *  Constant: '<S412>/Constant1'
   *  Constant: '<S412>/Constant2'
   *  Constant: '<S412>/Constant3'
   *  SignalConversion generated from: '<S412>/Create Diagonal Matrix2'
   */
  for (i = 0; i < 9; i++) {
    rtb_CreateDiagonalMatrix2[i] = 0.0;
  }

  rtb_CreateDiagonalMatrix2[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_IMU;
  rtb_CreateDiagonalMatrix2[4] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_IMU;
  rtb_CreateDiagonalMatrix2[8] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_IMU;

  /* End of S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix2' */

  /* RelationalOperator: '<S8>/Equal' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_f = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* Gain: '<S21>/Gain' incorporates:
   *  Inport: '<Root>/G_A'
   *  Inport: '<Root>/G_B'
   *  Inport: '<Root>/G_C'
   *  Inport: '<Root>/G_D'
   */
  rtb_Gain[0] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_A;
  rtb_Gain[1] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_B;
  rtb_Gain[2] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_C;
  rtb_Gain[3] = 1000.0 * PIDcontroller4CoreCentralizedTestReadyMotor_U->G_D;

  /* Switch: '<S437>/Switch1' incorporates:
   *  Constant: '<S437>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S437>/Switch1' incorporates:
     *  Lookup_n-D: '<S437>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S437>/Switch1' incorporates:
     *  Constant: '<S437>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S437>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[0],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);

  /* Switch: '<S429>/Switch' incorporates:
   *  Constant: '<S429>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_juh =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e.MovingAverage;
  } else {
    rtb_Switch_juh =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage;
  }

  /* End of Switch: '<S429>/Switch' */

  /* Switch: '<S438>/Switch1' incorporates:
   *  Constant: '<S438>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S438>/Switch1' incorporates:
     *  Lookup_n-D: '<S438>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S438>/Switch1' incorporates:
     *  Constant: '<S438>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S438>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[1],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzh,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzh.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);

  /* Switch: '<S430>/Switch' incorporates:
   *  Constant: '<S430>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_pa =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n.MovingAverage;
  } else {
    rtb_Switch_pa =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzh.MovingAverage;
  }

  /* End of Switch: '<S430>/Switch' */

  /* Switch: '<S439>/Switch1' incorporates:
   *  Constant: '<S439>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S439>/Switch1' incorporates:
     *  Lookup_n-D: '<S439>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S439>/Switch1' incorporates:
     *  Constant: '<S439>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S439>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[2],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzhe,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzhe);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzhe.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);

  /* Switch: '<S431>/Switch' incorporates:
   *  Constant: '<S431>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_my =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f.MovingAverage;
  } else {
    rtb_Switch_my =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzhe.MovingAverage;
  }

  /* End of Switch: '<S431>/Switch' */

  /* Switch: '<S440>/Switch1' incorporates:
   *  Constant: '<S440>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S440>/Switch1' incorporates:
     *  Lookup_n-D: '<S440>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S440>/Switch1' incorporates:
     *  Constant: '<S440>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactor;
  }

  /* End of Switch: '<S440>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_Gain[3],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_g,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_g);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_g.MovingAverage,
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);

  /* Switch: '<S432>/Switch' incorporates:
   *  Constant: '<S432>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->DoubleFilter != 0.0) {
    rtb_Switch_ka =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k.MovingAverage;
  } else {
    rtb_Switch_ka =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_g.MovingAverage;
  }

  /* End of Switch: '<S432>/Switch' */

  /* MATLAB Function: '<S428>/FindCoordinates' incorporates:
   *  Constant: '<S428>/Constant'
   *  Constant: '<S428>/Constant1'
   *  Constant: '<S428>/Constant2'
   *  Constant: '<S428>/Constant4'
   *  Sum: '<S428>/Add'
   */
  /* MATLAB Function 'Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/FindCoordinates': '<S436>:1' */
  /* '<S436>:1:5' */
  /* '<S436>:1:6' */
  /* '<S436>:1:8' */
  /* '<S436>:1:11' */
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
  PIDcontroller4CoreCentralizedTestReadyMotor_xgeqp3_m(A, X, jpvt);
  rankA = 0;
  tol = 8.8817841970012523E-15 * fabs(A[0]);
  while ((rankA < 3) && (!(fabs(A[(rankA << 2) + rankA]) <= tol))) {
    rankA++;
  }

  zz[0] = (rtb_Switch_juh -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[0]) / 1000.0;
  zz[2] = (rtb_Switch_pa -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[1]) / 1000.0;
  zz[1] = (rtb_Switch_my -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[2]) / 1000.0;
  zz[3] = (rtb_Switch_ka -
           PIDcontroller4CoreCentralizedTestReadyMotor_InstP->
           HEMS_Plane_Offsets[3]) / 1000.0;
  C[0] = 0.0;
  if (X[0] != 0.0) {
    tol = zz[0];
    for (i = 1; i + 1 < 5; i++) {
      tol += A[i] * zz[i];
    }

    tol *= X[0];
    if (tol != 0.0) {
      zz[0] -= tol;
      for (i = 1; i + 1 < 5; i++) {
        zz[i] -= A[i] * tol;
      }
    }
  }

  C[1] = 0.0;
  if (X[1] != 0.0) {
    tol = zz[1];
    for (i = 2; i + 1 < 5; i++) {
      tol += A[i + 4] * zz[i];
    }

    tol *= X[1];
    if (tol != 0.0) {
      zz[1] -= tol;
      for (i = 2; i + 1 < 5; i++) {
        zz[i] -= A[i + 4] * tol;
      }
    }
  }

  C[2] = 0.0;
  if (X[2] != 0.0) {
    tol = zz[2];
    for (i = 3; i + 1 < 5; i++) {
      tol += A[i + 8] * zz[i];
    }

    tol *= X[2];
    if (tol != 0.0) {
      zz[2] -= tol;
      for (i = 3; i + 1 < 5; i++) {
        zz[i] -= A[i + 8] * tol;
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

  /* '<S436>:1:16' */
  /* '<S436>:1:17' */
  /* '<S436>:1:18' */
  /* '<S436>:1:21' */
  X[0] = 1.0;
  X[1] = 0.0;
  X[2] = C[0];

  /* '<S436>:1:22' */
  /* '<S436>:1:23' */
  Y[0] = 0.0;
  Y[1] = 1.0;
  Y[2] = C[1];

  /* '<S436>:1:24' */
  /* '<S436>:1:33' */
  rtb_z_out_idx_0 = ((C[0] * 0.3054 + C[1] * -0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_1 = ((C[0] * 0.3054 + C[1] * 0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_2 = ((C[0] * -0.3054 + C[1] * -0.392) + C[2]) * 1000.0;
  rtb_z_out_idx_3 = ((C[0] * -0.3054 + C[1] * 0.392) + C[2]) * 1000.0;

  /* '<S436>:1:34' */
  /* '<S436>:1:43' */
  /* '<S436>:1:44' */
  rtb_avg_g = (((rtb_z_out_idx_0 + rtb_z_out_idx_1) + rtb_z_out_idx_2) +
               rtb_z_out_idx_3) / 4.0;
  if (-C[0] < 0.0) {
    rtb_Subtract_idx_0 = -1.0;
  } else if (-C[0] > 0.0) {
    rtb_Subtract_idx_0 = 1.0;
  } else if (-C[0] == 0.0) {
    rtb_Subtract_idx_0 = 0.0;
  } else {
    rtb_Subtract_idx_0 = (rtNaN);
  }

  rtb_pitch_j = acos(1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm_c(X))
    * rtb_Subtract_idx_0;
  if (-C[1] < 0.0) {
    rtb_Subtract_idx_0 = -1.0;
  } else if (-C[1] > 0.0) {
    rtb_Subtract_idx_0 = 1.0;
  } else if (-C[1] == 0.0) {
    rtb_Subtract_idx_0 = 0.0;
  } else {
    rtb_Subtract_idx_0 = (rtNaN);
  }

  rtb_roll = acos(-(-1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_norm_c(Y)))
    * rtb_Subtract_idx_0;

  /* End of MATLAB Function: '<S428>/FindCoordinates' */

  /* Switch: '<S428>/Switch1' incorporates:
   *  Constant: '<S428>/Constant3'
   *  Constant: '<S428>/Constant5'
   *  Sum: '<S428>/Add1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LinposOn != 0.0) {
    rtb_z_out_idx_0 +=
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[0];
    rtb_z_out_idx_1 +=
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[1];
    rtb_z_out_idx_2 +=
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[2];
    rtb_z_out_idx_3 +=
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[3];
  } else {
    rtb_z_out_idx_0 = rtb_Switch_juh;
    rtb_z_out_idx_1 = rtb_Switch_pa;
    rtb_z_out_idx_2 = rtb_Switch_my;
    rtb_z_out_idx_3 = rtb_Switch_ka;
  }

  /* End of Switch: '<S428>/Switch1' */

  /* Switch: '<S444>/Switch1' incorporates:
   *  Constant: '<S444>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S444>/Switch1' incorporates:
     *  Lookup_n-D: '<S444>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S444>/Switch1' incorporates:
     *  Constant: '<S444>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorLinpos;
  }

  /* End of Switch: '<S444>/Switch1' */

  /* MATLABSystem: '<S427>/Moving Average' incorporates:
   *  Switch: '<S428>/Switch1'
   */
  tol = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.ForgettingFactor;
  p_tmp = false;
  if ((tol == PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h) ||
      (((int32_T)rtIsNaN(tol)) && ((int32_T)rtIsNaN
        (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h)))) {
    p_tmp = true;
  }

  if (!(int32_T)p_tmp) {
    p_tmp = (boolean_T)
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isInitialized == 1);
    if (p_tmp) {
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
    p_tmp = (boolean_T)(obj->isInitialized == 1);
    if (p_tmp) {
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

  tol = obj->pwN;
  zz[0] = obj->pmN[0];
  zz[1] = obj->pmN[1];
  zz[2] = obj->pmN[2];
  zz[3] = obj->pmN[3];
  F1 = obj->plambda;
  rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 1.0 - 1.0 / tol;
  F3 = 1.0 / tol;
  zz[0] = rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 * zz[0] +
    F3 * rtb_z_out_idx_0;
  zz[1] = rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 * zz[1] +
    F3 * rtb_z_out_idx_1;
  zz[2] = rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 * zz[2] +
    F3 * rtb_z_out_idx_2;
  zz[3] = rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 * zz[3] +
    F3 * rtb_z_out_idx_3;
  obj->pwN = F1 * tol + 1.0;
  obj->pmN[0] = zz[0];
  obj->pmN[1] = zz[1];
  obj->pmN[2] = zz[2];
  obj->pmN[3] = zz[3];

  /* Switch: '<S427>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S427>/Constant1'
   *  MATLABSystem: '<S427>/Moving Average'
   *  Sum: '<S21>/Subtract'
   */
  p_tmp = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LinposFilter != 0.0);
  if (p_tmp) {
    rtb_z_out_idx_0 = zz[0];
    rtb_z_out_idx_1 = zz[1];
  }

  /* Sum: '<S21>/Subtract' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtb_Subtract_idx_0 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[0] +
    rtb_z_out_idx_0;
  rtb_Subtract_idx_1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[1] +
    rtb_z_out_idx_1;

  /* Switch: '<S427>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  MATLABSystem: '<S427>/Moving Average'
   *  Sum: '<S21>/Subtract'
   */
  if (p_tmp) {
    rtb_z_out_idx_2 = zz[2];
    rtb_z_out_idx_3 = zz[3];
  }

  /* Sum: '<S21>/Subtract' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtb_Subtract_idx_2 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[2] +
    rtb_z_out_idx_2;
  rtb_Subtract_idx_3 =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->HEMS_Plane_Offsets[3] +
    rtb_z_out_idx_3;

  /* Lookup_n-D: '<S23>/2-D Lookup Table2' */
  rtb_uDLookupTable2 = look2_pbinlxpw(rtb_Switch_k_idx_0, rtb_Subtract_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled41, 30U);

  /* Delay: '<Root>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[0];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[2];

  /* Lookup_n-D: '<S23>/2-D Lookup Table1' */
  rtb_uDLookupTable1 = look2_pbinlxpw(rtb_Switch_k_idx_1, rtb_Subtract_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_a,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled41, 30U);

  /* Lookup_n-D: '<S23>/2-D Lookup Table3' */
  rtb_uDLookupTable3 = look2_pbinlxpw(rtb_Switch_k_idx_2, rtb_Subtract_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_c,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled41, 30U);

  /* Lookup_n-D: '<S23>/2-D Lookup Table4' */
  rtb_uDLookupTable4 = look2_pbinlxpw(rtb_Switch_k_idx_3, rtb_Subtract_idx_3,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_j,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled41, 30U);

  /* Gain: '<S23>/Gain' */
  tol = 1.0 / PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f;

  /* Product: '<S23>/Product' incorporates:
   *  Gain: '<S23>/Gain'
   *  Sum: '<S23>/Add'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S23>/Add2'
   *  Sum: '<S23>/Add3'
   *  Sum: '<S23>/Add4'
   *  Sum: '<S23>/Add5'
   *  Sum: '<S23>/Add6'
   *  Sum: '<S23>/Add7'
   */
  rtb_Product_idx_0 = ((rtb_uDLookupTable2 +
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1])
                       - PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * tol * PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Product_idx_1 = ((rtb_uDLookupTable1 +
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1])
                       + PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * tol * PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Product_idx_2 = ((rtb_uDLookupTable3 -
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1])
                       - PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * tol * PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];
  rtb_Product_idx_3 = ((rtb_uDLookupTable4 -
                        PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1])
                       + PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2])
    * tol * PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0];

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S25>/Constant2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchedHEMSKalman >
      0.0) {
    rtb_z_out_idx_0 = rtb_Product_idx_0;
    rtb_z_out_idx_1 = rtb_Product_idx_1;
    rtb_z_out_idx_2 = rtb_Product_idx_2;
    rtb_z_out_idx_3 = rtb_Product_idx_3;
  } else {
    rtb_z_out_idx_0 = rtb_uDLookupTable2;
    rtb_z_out_idx_1 = rtb_uDLookupTable1;
    rtb_z_out_idx_2 = rtb_uDLookupTable3;
    rtb_z_out_idx_3 = rtb_uDLookupTable4;
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Switch: '<S8>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_f) {
    /* Switch: '<S8>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[3] = 0.0;
  } else {
    /* Switch: '<S8>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[0] = rtb_z_out_idx_0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[1] = rtb_z_out_idx_1;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[2] = rtb_z_out_idx_2;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[3] = rtb_z_out_idx_3;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Gain: '<S35>/Gain5' incorporates:
   *  Constant: '<S35>/2'
   *  Gain: '<S33>/Gain4'
   *  Math: '<S35>/Square1'
   */
  tol = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeight *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeight *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodHeightFactor;

  /* Gain: '<S35>/Gain' incorporates:
   *  Constant: '<S35>/1'
   *  Gain: '<S35>/Gain4'
   *  Gain: '<S35>/Gain5'
   *  Math: '<S35>/Square'
   *  Sum: '<S35>/Sum1'
   */
  rtb_Gain_do = (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidth *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidth *
                 PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodWidthFactor
                 + tol) *
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass / 12.0);

  /* Gain: '<S33>/Gain' incorporates:
   *  Constant: '<S33>/3'
   *  Gain: '<S33>/Gain3'
   *  Math: '<S33>/Square'
   *  Sum: '<S33>/Sum1'
   */
  rtb_Gain_m = (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLength *
                PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLength *
                PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PodLengthFactor
                + tol) *
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass / 12.0);

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S8>/Constant9'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_h = 9.81 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* RelationalOperator: '<S8>/Equal1' incorporates:
   *  Constant: '<S8>/Constant5'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1 = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn != 0.0) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rtb_Switch_n =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionCurrent;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    rtb_Switch_n = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1(rtb_Switch_n,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage2,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage2);

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S5>/Constant'
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

  /* Outport: '<Root>/MotorAGAdjust' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->MotorAGAdjust =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE;

  /* Switch: '<S441>/Switch1' incorporates:
   *  Constant: '<S441>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S441>/Switch1' incorporates:
     *  Lookup_n-D: '<S441>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S441>/Switch1' incorporates:
     *  Constant: '<S441>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorAirgap;
  }

  /* End of Switch: '<S441>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_avg_g,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_h,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);

  /* Switch: '<S433>/Switch' incorporates:
   *  Constant: '<S433>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->AirgapFilter != 0.0) {
    rtb_Switch_gj =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_h.MovingAverage;
  } else {
    rtb_Switch_gj = rtb_avg_g;
  }

  /* End of Switch: '<S433>/Switch' */

  /* Sum: '<S3>/Add3' incorporates:
   *  Constant: '<S3>/Constant'
   *  Outport: '<Root>/MotorAGAdjust'
   *  Sum: '<S3>/Subtract'
   */
  rtb_Add3_l = (rtb_Switch_gj -
                PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MotorAirgapOffset)
    - PIDcontroller4CoreCentralizedTestReadyMotor_Y->MotorAGAdjust;

  /* Switch: '<S442>/Switch1' incorporates:
   *  Constant: '<S442>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S442>/Switch1' incorporates:
     *  Lookup_n-D: '<S442>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S442>/Switch1' incorporates:
     *  Constant: '<S442>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorPitch;
  }

  /* End of Switch: '<S442>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_pitch_j,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_kw,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);

  /* Switch: '<S434>/Switch' incorporates:
   *  Constant: '<S434>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PitchFilter != 0.0) {
    /* Switch: '<S434>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_kw.MovingAverage;
  } else {
    /* Switch: '<S434>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k = rtb_pitch_j;
  }

  /* End of Switch: '<S434>/Switch' */

  /* Trigonometry: '<S3>/Trigonometric Function' */
  rtb_TrigonometricFunction = sin
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k);

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Gain: '<S3>/Gain'
   *  Product: '<S3>/Product'
   */
  for (i = 0; i < 39; i++) {
    rtb_Add_e[i] = PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled17[i]
      * rtb_TrigonometricFunction * -1000.0 + rtb_Add3_l;
  }

  /* End of Sum: '<S3>/Add' */

  /* Lookup_n-D: '<S3>/1-D Lookup Table1' incorporates:
   *  MATLABSystem: '<S3>/Moving Average2'
   */
  bpIndices[0U] = plook_binx
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage2.MovingAverage1,
     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_bp01Data,
     16U, &tol);
  fractions[0U] = tol;
  for (i = 0; i < 39; i++) {
    bpIndices[1U] = plook_binx(rtb_Add_e[i],
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_bp02Data,
      54U, &tol);
    fractions[1U] = tol;
    rtb_uDLookupTable1_gs[i] = intrp2d_l_pw(bpIndices, fractions,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.uDLookupTable1_tableData,
      17U);
  }

  /* End of Lookup_n-D: '<S3>/1-D Lookup Table1' */

  /* Switch: '<S401>/Switch1' incorporates:
   *  Constant: '<S401>/Constant5'
   *  Constant: '<S401>/Constant7'
   *  Gain: '<S3>/Gain2'
   *  Sum: '<S3>/Sum'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->motorforce_on != 0.0) {
    /* Sum: '<S3>/Sum' */
    tol = -0.0;
    for (aoffset = 0; aoffset < 39; aoffset++) {
      tol += rtb_uDLookupTable1_gs[aoffset];
    }

    rtb_Switch1_d = 0.025641025641025633 * tol;
  } else {
    rtb_Switch1_d = 0.0;
  }

  /* End of Switch: '<S401>/Switch1' */

  /* Switch: '<S8>/Switch1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1) {
    /* Switch: '<S8>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_d =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_h;
  } else {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Sum: '<S8>/Add6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_d = rtb_Switch1_d;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* RelationalOperator: '<S8>/Equal2' incorporates:
   *  Constant: '<S8>/Constant7'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2 = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* Switch: '<S400>/Switch1' incorporates:
   *  Constant: '<S400>/Constant5'
   *  Constant: '<S400>/Constant7'
   *  Gain: '<S3>/Gain3'
   *  Sum: '<S3>/Sum2'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->motorforce_on != 0.0) {
    /* Sum: '<S3>/Sum2' */
    tol = -0.0;
    for (aoffset = 0; aoffset < 39; aoffset++) {
      /* Sum: '<S3>/Sum2' incorporates:
       *  Constant: '<S3>/Constant6'
       *  Product: '<S3>/Product2'
       */
      tol += PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled17[aoffset]
        * rtb_uDLookupTable1_gs[aoffset];
    }

    rtb_Switch1_o = 0.025641025641025633 * tol;
  } else {
    rtb_Switch1_o = 0.0;
  }

  /* End of Switch: '<S400>/Switch1' */

  /* Logic: '<S5>/OR' incorporates:
   *  Constant: '<S5>/Constant'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->OR = (boolean_T)
    ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ResetArms != 0.0) ||
     ((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c));

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
   */
  p_tmp = (boolean_T)!(int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
  }

  /* Sum: '<S5>/Add2' incorporates:
   *  Constant: '<S5>/Constant3'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  rtb_Add2_c = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->X_Arm_Offset +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p;

  /* Product: '<S3>/Gravity' incorporates:
   *  Constant: '<S3>/Gravitational constant [m//s^2]'
   *  Constant: '<S3>/Mass [kg]'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity = -9.81 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Product: '<S3>/Product3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1 = -(rtb_Add2_c *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity);

  /* Sum: '<S3>/Add1' */
  rtb_Add1_d = rtb_Switch1_o +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1;

  /* Switch: '<S8>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_o = 0.0;
  } else {
    /* Switch: '<S8>/Switch2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_o = rtb_Add1_d;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
  }

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant5'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->EMS_Moment_Arm_Z +
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k;

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S5>/Constant4'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
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

  /* ZeroOrderHold: '<S412>/Zero-Order Hold1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   */
  rtb_ZeroOrderHold1[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[0];
  rtb_ZeroOrderHold1[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[1];
  rtb_ZeroOrderHold1[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[2];
  rtb_ZeroOrderHold1[3] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[3];
  rtb_ZeroOrderHold1[4] = rtb_Gain_do;
  rtb_ZeroOrderHold1[5] = rtb_Gain_m;
  rtb_ZeroOrderHold1[6] = 0.392;
  rtb_ZeroOrderHold1[7] = 0.3054;
  rtb_ZeroOrderHold1[8] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  rtb_ZeroOrderHold1[9] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_d;
  rtb_ZeroOrderHold1[10] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_o;
  rtb_ZeroOrderHold1[11] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Gain: '<S8>/To m' incorporates:
   *  Gain: '<S7>/To m'
   */
  rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.001 *
    rtb_Switch_gj;

  /* Gain: '<S8>/To m' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom =
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Switch: '<S443>/Switch1' incorporates:
   *  Constant: '<S443>/Constant4'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Airgap_GainSchedulingEnabled
      [4] != 0.0) {
    /* Switch: '<S443>/Switch1' incorporates:
     *  Lookup_n-D: '<S443>/n-D Lookup Table'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n = look1_binlxpw(0.0,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled7,
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->F_array, 1U);
  } else {
    /* Switch: '<S443>/Switch1' incorporates:
     *  Constant: '<S443>/Constant'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->ForgettingFactorRoll;
  }

  /* End of Switch: '<S443>/Switch1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(rtb_roll,
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_ka,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);

  /* Switch: '<S435>/Switch' incorporates:
   *  Constant: '<S435>/Constant1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RollFilter != 0.0) {
    /* Switch: '<S435>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_ka.MovingAverage;
  } else {
    /* Switch: '<S435>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c = rtb_roll;
  }

  /* End of Switch: '<S435>/Switch' */

  /* ZeroOrderHold: '<S412>/Zero-Order Hold' */
  rtb_ZeroOrderHold[0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom;
  rtb_ZeroOrderHold[1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;
  rtb_ZeroOrderHold[2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;

  /* Switch: '<S413>/Switch1' incorporates:
   *  Inport: '<Root>/LS_mode'
   *  Switch: '<S413>/Switch2'
   *  Switch: '<S413>/Switch3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    /* SignalConversion generated from: '<S412>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S413>/Constant1'
     *  Constant: '<S413>/Constant2'
     *  Constant: '<S413>/Constant3'
     */
    tol = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_sens_LS;
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_sens_LS;
    F3 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_sens_LS;
  } else {
    /* SignalConversion generated from: '<S412>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S413>/Constant7'
     *  Constant: '<S413>/Constant8'
     *  Constant: '<S413>/Constant9'
     */
    tol = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_sens;
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_sens;
    F3 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_sens;
  }

  /* End of Switch: '<S413>/Switch1' */

  /* S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix' */
  for (i = 0; i < 9; i++) {
    rtb_CreateDiagonalMatrix[i] = 0.0;
  }

  rtb_CreateDiagonalMatrix[0] = tol;
  rtb_CreateDiagonalMatrix[4] = F1;
  rtb_CreateDiagonalMatrix[8] = F3;

  /* End of S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix' */

  /* Outputs for Enabled SubSystem: '<S414>/Correct1' */
  /* Constant: '<S414>/Enable1' incorporates:
   *  Constant: '<S414>/BlockOrdering'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Correct1(true, rtb_ZeroOrderHold,
    rtb_CreateDiagonalMatrix, true,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1_l);

  /* End of Outputs for SubSystem: '<S414>/Correct1' */

  /* Outputs for Enabled SubSystem: '<S414>/Correct2' incorporates:
   *  EnablePort: '<S417>/Enable'
   */
  /* MATLAB Function: '<S417>/Correct' incorporates:
   *  DataStoreRead: '<S417>/Data Store ReadP'
   *  DataStoreRead: '<S417>/Data Store ReadX'
   *  S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix2'
   *  SignalConversion generated from: '<S421>/ SFunction '
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->blockOrdering =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1_l.blockOrdering;

  /* MATLAB Function 'Extras/EKFCorrect/Correct': '<S421>:1' */
  /* '<S421>:1:11' */
  p_tmp = true;
  for (i = 0; i < 9; i++) {
    tol = rtb_CreateDiagonalMatrix2[i];
    if (((int32_T)p_tmp) && ((!(int32_T)rtIsInf(tol)) && (!(int32_T)rtIsNaN(tol))))
    {
    } else {
      p_tmp = false;
    }
  }

  if (p_tmp) {
    PIDcontroller4CoreCentralizedTestReadyMotor_svd_i(rtb_CreateDiagonalMatrix2,
      Ss, X, V);
  } else {
    X[0] = (rtNaN);
    X[1] = (rtNaN);
    X[2] = (rtNaN);
    for (i = 0; i < 9; i++) {
      V[i] = (rtNaN);
    }
  }

  for (i = 0; i < 9; i++) {
    Ss[i] = 0.0;
  }

  Ss[0] = X[0];
  Ss[4] = X[1];
  Ss[8] = X[2];
  for (i = 0; i < 9; i++) {
    Ss[i] = sqrt(Ss[i]);
  }

  for (i = 0; i < 3; i++) {
    for (b_j = 0; b_j < 3; b_j++) {
      rankA = b_j + 3 * i;
      R[rankA] = 0.0;
      R[rankA] += Ss[3 * i] * V[b_j];
      R[rankA] += Ss[3 * i + 1] * V[b_j + 3];
      R[rankA] += Ss[3 * i + 2] * V[b_j + 6];
    }
  }

  X[0] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[0];
  X[1] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[2];
  X[2] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[4];
  for (b_j = 0; b_j < 6; b_j++) {
    for (i = 0; i < 6; i++) {
      imvec[i] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[i];
    }

    tol = 1.4901161193847656E-8 * fabs
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[b_j]);
    if ((1.4901161193847656E-8 > tol) || ((int32_T)rtIsNaN(tol))) {
      tol = 1.4901161193847656E-8;
    }

    imvec[b_j] = PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[b_j] + tol;
    dHdx[3 * b_j] = (imvec[0] - X[0]) / tol;
    dHdx[3 * b_j + 1] = (imvec[2] - X[1]) / tol;
    dHdx[3 * b_j + 2] = (imvec[4] - X[2]) / tol;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_qrFactor_p(dHdx,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h, R, Ss);
  for (i = 0; i < 6; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      A_0[b_j + 6 * i] = 0.0;
    }
  }

  for (rankA = 0; rankA < 6; rankA++) {
    for (i = 0; i < 6; i++) {
      for (b_j = 0; b_j < 6; b_j++) {
        aoffset = 6 * i + b_j;
        A_0[aoffset] += PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[6 *
          rankA + b_j] * PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[6 *
          rankA + i];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      aoffset = i + 3 * b_j;
      K[aoffset] = 0.0;
      for (rankA = 0; rankA < 6; rankA++) {
        K[aoffset] += A_0[6 * rankA + b_j] * dHdx[3 * rankA + i];
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

  PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_i(Ss, C_0);
  for (b_j = 0; b_j < 6; b_j++) {
    b_C[3 * b_j] = C_0[3 * b_j];
    i = 3 * b_j + 1;
    b_C[i] = C_0[i];
    i = 3 * b_j + 2;
    b_C[i] = C_0[i];
  }

  for (i = 0; i < 3; i++) {
    V[3 * i] = Ss[i];
    V[3 * i + 1] = Ss[i + 3];
    V[3 * i + 2] = Ss[i + 6];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_trisolve_im(V, b_C);
  for (i = 0; i < 3; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      K[b_j + 6 * i] = b_C[3 * b_j + i];
    }
  }

  for (i = 0; i < 18; i++) {
    C_0[i] = -K[i];
  }

  for (i = 0; i < 6; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      rankA = b_j + 6 * i;
      A_0[rankA] = 0.0;
      A_0[rankA] += dHdx[3 * i] * C_0[b_j];
      A_0[rankA] += dHdx[3 * i + 1] * C_0[b_j + 6];
      A_0[rankA] += dHdx[3 * i + 2] * C_0[b_j + 12];
    }
  }

  for (i = 0; i < 6; i++) {
    rankA = 6 * i + i;
    A_0[rankA]++;
  }

  for (b_j = 0; b_j < 6; b_j++) {
    coffset = b_j * 6;
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      tol = 0.0;
      for (rankA = 0; rankA < 6; rankA++) {
        tol += A_0[rankA * 6 + b_j] *
          PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[aoffset + rankA];
      }

      y[coffset + i] = tol;
    }
  }

  for (i = 0; i < 3; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      aoffset = i + 3 * b_j;
      C_0[aoffset] = 0.0;
      C_0[aoffset] += R[3 * i] * K[b_j];
      C_0[aoffset] += R[3 * i + 1] * K[b_j + 6];
      C_0[aoffset] += R[3 * i + 2] * K[b_j + 12];
    }
  }

  for (i = 0; i < 6; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      y_0[b_j + 9 * i] = y[6 * i + b_j];
    }

    y_0[9 * i + 6] = C_0[3 * i];
    y_0[9 * i + 7] = C_0[3 * i + 1];
    y_0[9 * i + 8] = C_0[3 * i + 2];
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_qr_g(y_0, a__1, A_0);

  /* '<S421>:1:135' */
  tol = PIDcontroller4CoreCentralizedTestReadyMotor_B->y_i1 -
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[0];
  F1 = rtb_Gain1_gt - PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[2];
  F3 = rtb_Gain2 - PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[4];
  for (i = 0; i < 6; i++) {
    /* DataStoreWrite: '<S417>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S417>/Correct'
     */
    for (b_j = 0; b_j < 6; b_j++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[b_j + 6 * i] = A_0[6 *
        b_j + i];
    }

    /* End of DataStoreWrite: '<S417>/Data Store WriteP' */

    /* DataStoreWrite: '<S417>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S417>/Data Store ReadX'
     *  MATLAB Function: '<S417>/Correct'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[i] += (K[i + 6] * F1 +
      K[i] * tol) + K[i + 12] * F3;
  }

  /* End of Outputs for SubSystem: '<S414>/Correct2' */

  /* Outputs for Atomic SubSystem: '<S414>/Output' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Output
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->blockOrdering,
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->Output_n);

  /* End of Outputs for SubSystem: '<S414>/Output' */

  /* Sum: '<S8>/Add1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add1_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output_n.DataStoreRead[1] -
    rtb_DiscreteTimeIntegrator_j2;

  /* Gain: '<S8>/To mm' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm = 1000.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add1_l;

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_i
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_i
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_g
      = 0.0;
  }

  /* Sum: '<S8>/Add4' incorporates:
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add4 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output_n.DataStoreRead[5] -
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_g;

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator2' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState_b
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState_b
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE_l
      = 0.0;
  }

  /* Sum: '<S8>/Add5' incorporates:
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Add5 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output_n.DataStoreRead[3] -
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE_l;

  /* Gain: '<S7>/To m' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom_h =
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* ZeroOrderHold: '<S403>/Zero-Order Hold' */
  rtb_ZeroOrderHold_b[0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom_h;
  rtb_ZeroOrderHold_b[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;
  rtb_ZeroOrderHold_b[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;

  /* Switch: '<S404>/Switch1' incorporates:
   *  Inport: '<Root>/LS_mode'
   *  Switch: '<S404>/Switch2'
   *  Switch: '<S404>/Switch3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    /* SignalConversion generated from: '<S403>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S404>/Constant1'
     *  Constant: '<S404>/Constant2'
     *  Constant: '<S404>/Constant3'
     */
    tol = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_sens_LS;
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_sens_LS;
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_sens_LS;
  } else {
    /* SignalConversion generated from: '<S403>/Create Diagonal Matrix' incorporates:
     *  Constant: '<S404>/Constant7'
     *  Constant: '<S404>/Constant8'
     *  Constant: '<S404>/Constant9'
     */
    tol = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_sens;
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_sens;
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_sens;
  }

  /* End of Switch: '<S404>/Switch1' */

  /* S-Function (sdspdiag2): '<S403>/Create Diagonal Matrix' */
  for (i = 0; i < 9; i++) {
    rtb_CreateDiagonalMatrix_g[i] = 0.0;
  }

  rtb_CreateDiagonalMatrix_g[0] = tol;
  rtb_CreateDiagonalMatrix_g[4] =
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;
  rtb_CreateDiagonalMatrix_g[8] = F1;

  /* End of S-Function (sdspdiag2): '<S403>/Create Diagonal Matrix' */

  /* Outputs for Enabled SubSystem: '<S405>/Correct1' */
  /* Constant: '<S405>/Enable1' incorporates:
   *  Constant: '<S405>/BlockOrdering'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Correct1(true, rtb_ZeroOrderHold_b,
    rtb_CreateDiagonalMatrix_g, true,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->P,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1);

  /* End of Outputs for SubSystem: '<S405>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S405>/Output' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Output
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1.blockOrdering,
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->x,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->Output);

  /* End of Outputs for SubSystem: '<S405>/Output' */

  /* Gain: '<S7>/To mm' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d = 1000.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[1];

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  if ((int32_T)
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_o
      == 1) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
      = 0.0;
  }

  /* Sum: '<S10>/Subtract1' incorporates:
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
   *  Gain: '<S10>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d -
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_I *
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Switch: '<Root>/Switch1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->UseIMU > 0.0) {
    /* Switch: '<Root>/Switch2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add4;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add5;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->SkipKalman !=
             0.0) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Switch: '<Root>/Switch2'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0] = rtb_Switch_gj;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;
  } else {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[5];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2] =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[3];
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Sum: '<S32>/Sum' incorporates:
   *  Outport: '<Root>/ActualReferenceAirgap'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->error =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->ActualReferenceAirgap -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0];

  /* RelationalOperator: '<S73>/Equal' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S108>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S103>/Filter'
   */
  p_tmp = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_o
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S103>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_k) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState <=
        0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE = 0.0;
  }

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S70>/Constant3'
   *  Constant: '<S70>/Constant4'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_d_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_d;
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Product: '<S111>/NProd Out' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/N'
   *  DiscreteIntegrator: '<S103>/Filter'
   *  Product: '<S102>/DProd Out'
   *  Product: '<S125>/Divide'
   *  Sum: '<S103>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->error *
     rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE) *
    (6.2831853071795862 /
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_T_c);

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S70>/Constant1'
   *  Constant: '<S70>/Constant5'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_p_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_p;
  }

  /* End of Switch: '<S70>/Switch1' */

  /* Sum: '<S117>/Sum' incorporates:
   *  DiscreteIntegrator: '<S108>/Integrator'
   *  Product: '<S113>/PProd Out'
   */
  rtb_Sum_h = (PIDcontroller4CoreCentralizedTestReadyMotor_B->error *
               rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 +
               PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut;

  /* Product: '<S32>/Divide1' incorporates:
   *  Sum: '<S32>/Add'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1 = rtb_Divide *
    rtb_Sum_h;

  /* Sum: '<S3>/Add4' incorporates:
   *  Sum: '<S3>/Sum1'
   */
  rtb_Add4_n = rtb_Switch1_d +
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity;

  /* Sum: '<S34>/Add' */
  rtb_Add_l = (0.0 - PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1) -
    rtb_Add4_n;

  /* Logic: '<S184>/AND' incorporates:
   *  Constant: '<S184>/Constant'
   *  Constant: '<S184>/Constant2'
   *  Delay: '<S184>/Delay'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->AND = (boolean_T)
    ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LowAirgapPropellingSwitch
      != 0.0) &&
     (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn != 0.0) &&
     ((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_o));

  /* Sum: '<S185>/Subtract5' incorporates:
   *  Constant: '<S185>/Constant4'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - -1.0;

  /* Switch: '<S185>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o != 0.0) {
    /* Switch: '<S185>/Switch' incorporates:
     *  Constant: '<S185>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o = 0.0;
  } else {
    /* Switch: '<S185>/Switch' incorporates:
     *  Gain: '<S36>/Gain1'
     *  Sum: '<S36>/Subtract'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o =
      -(((rtb_Switch_k_idx_0 + rtb_Switch_k_idx_1) - rtb_Switch_k_idx_2) -
        rtb_Switch_k_idx_3);
  }

  /* End of Switch: '<S185>/Switch' */

  /* DiscreteIntegrator: '<S272>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
  }

  /* SampleTimeMath: '<S267>/Tsamp' incorporates:
   *  Gain: '<S264>/Derivative Gain'
   *
   * About '<S267>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o * 4000.0;

  /* Delay: '<S265>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_n =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Sum: '<S281>/Sum' incorporates:
   *  Delay: '<S265>/UD'
   *  DiscreteIntegrator: '<S272>/Integrator'
   *  Gain: '<S277>/Proportional Gain'
   *  Sum: '<S265>/Diff'
   */
  rtb_Sum_ac = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o);

  /* Constant: '<S33>/Base Ref Airgap1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RefPitch,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S184>/Constant1'
   *  Constant: '<S185>/Constant'
   *  Gain: '<S178>/Gain1'
   *  Gain: '<S179>/Gain1'
   *  Gain: '<S237>/Gain1'
   *  Sum: '<S33>/Plus1'
   *  Switch: '<S185>/Switch1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->AND) {
    rtb_Switch_kb = 0.017453292519943295 *
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingPitch;
  } else {
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0)
    {
      /* Switch: '<S185>/Switch1' incorporates:
       *  Constant: '<S185>/Constant2'
       */
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
    } else {
      /* Switch: '<S185>/Switch1' */
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = rtb_Sum_ac;
    }

    rtb_Switch_kb = 0.017453292519943295 *
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 +
      0.017453292519943295 *
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe.MovingAverage;
  }

  /* End of Switch: '<S184>/Switch' */

  /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->AND) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_k
        <= 0)) || ((!(int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->AND)
                   && ((int32_T)
                       PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_k
                       == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
  }

  /* MATLABSystem: '<S184>/Moving Average1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.TunablePropsChanged)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.TunablePropsChanged =
      false;
  }

  obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.pStatistic;
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

  tol =
    PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_o
    (obj_0, rtb_Switch_kb);

  /* End of MATLABSystem: '<S184>/Moving Average1' */

  /* Switch: '<S184>/Switch1' incorporates:
   *  Constant: '<S184>/Constant4'
   *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator1'
   *  RelationalOperator: '<S184>/GreaterThan1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionRampTime) {
    tol = rtb_Switch_kb;
  }

  /* End of Switch: '<S184>/Switch1' */

  /* Sum: '<S33>/Plus' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch =
    rtb_Switch2_idx_1 + tol;

  /* Sum: '<S33>/Subtract' */
  rtb_error_m = PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1];

  /* Gain: '<S33>/Gain2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 = 952.0 * rtb_error_m;

  /* RelationalOperator: '<S33>/Equal' incorporates:
   *  Constant: '<S33>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S220>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S215>/Filter'
   */
  p_tmp = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
  }

  /* DiscreteIntegrator: '<S215>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j <=
        0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
  }

  /* Switch: '<S180>/Switch2' incorporates:
   *  Constant: '<S180>/Constant3'
   *  Constant: '<S180>/Constant4'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_d_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_d;
  }

  /* End of Switch: '<S180>/Switch2' */

  /* Product: '<S223>/NProd Out' incorporates:
   *  Constant: '<S186>/Constant'
   *  Constant: '<S186>/N'
   *  DiscreteIntegrator: '<S215>/Filter'
   *  Product: '<S186>/Divide'
   *  Product: '<S214>/DProd Out'
   *  Sum: '<S215>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 *
     rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i) *
    (6.2831853071795862 /
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_T_c);

  /* Switch: '<S180>/Switch1' incorporates:
   *  Constant: '<S180>/Constant1'
   *  Constant: '<S180>/Constant5'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_p_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_p;
  }

  /* End of Switch: '<S180>/Switch1' */

  /* Sum: '<S229>/Sum' incorporates:
   *  DiscreteIntegrator: '<S220>/Integrator'
   *  Product: '<S225>/PProd Out'
   */
  rtb_Sum_o = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 *
               rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 +
               PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e;

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Reference_P_Inertia'
   *  Gain: '<S33>/Gain1'
   *  Product: '<S33>/Divide'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product = rtb_Gain_m /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Reference_P_Inertia *
    (2.049 * rtb_Sum_o);

  /* Sum: '<S34>/Add1' */
  rtb_Add1_f = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product -
    rtb_Add1_d;

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<S9>/LongDistance'
   */
  rtb_Divide_k = rtb_Add1_f / 0.3054;

  /* Logic: '<S294>/AND' incorporates:
   *  Constant: '<S294>/Constant'
   *  Constant: '<S294>/Constant2'
   *  Delay: '<S294>/Delay'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->AND_i = (boolean_T)
    ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LowAirgapPropellingSwitch
      != 0.0) &&
     (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn != 0.0) &&
     ((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m));

  /* Constant: '<S35>/Base Ref Airgap1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->RefRoll,
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);

  /* Sum: '<S295>/Subtract5' incorporates:
   *  Constant: '<S295>/Constant4'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - -1.0;

  /* Switch: '<S295>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l != 0.0) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S295>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p = 0.0;
  } else {
    /* Switch: '<S295>/Switch' incorporates:
     *  Gain: '<S36>/Gain'
     *  Sum: '<S36>/Subtract1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p =
      -(((rtb_Switch_k_idx_1 - rtb_Switch_k_idx_0) - rtb_Switch_k_idx_2) +
        rtb_Switch_k_idx_3);
  }

  /* End of Switch: '<S295>/Switch' */

  /* DiscreteIntegrator: '<S382>/Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
  }

  /* SampleTimeMath: '<S377>/Tsamp' incorporates:
   *  Gain: '<S374>/Derivative Gain'
   *
   * About '<S377>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h = 0.0 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p * 4000.0;

  /* Delay: '<S375>/UD' */
  if ((((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k == 1)
       != (int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
      ((int32_T)
       PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k != 3))
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_PrevZCX->UD_Reset_ZCE_k =
    (ZCSigState)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Sum: '<S391>/Sum' incorporates:
   *  Delay: '<S375>/UD'
   *  DiscreteIntegrator: '<S382>/Integrator'
   *  Gain: '<S387>/Proportional Gain'
   *  Sum: '<S375>/Diff'
   */
  rtb_Sum_eh = (0.0 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg)
    + (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h -
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l);

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S295>/Constant'
   *  Switch: '<S295>/Switch1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->AND_i) {
    /* Switch: '<S294>/Switch' incorporates:
     *  Constant: '<S294>/Constant1'
     *  Gain: '<S347>/Gain1'
     */
    rtb_Switch_n4 = 0.017453292519943295 *
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingRoll;
  } else {
    if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Undo_0current != 0.0)
    {
      /* Switch: '<S295>/Switch1' incorporates:
       *  Constant: '<S295>/Constant2'
       */
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
    } else {
      /* Switch: '<S295>/Switch1' */
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = rtb_Sum_eh;
    }

    /* Switch: '<S294>/Switch' incorporates:
     *  Gain: '<S289>/Gain1'
     *  Gain: '<S290>/Gain1'
     *  Sum: '<S35>/Add1'
     */
    rtb_Switch_n4 = 0.017453292519943295 *
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh.MovingAverage
      + 0.017453292519943295 *
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;
  }

  /* End of Switch: '<S294>/Switch' */

  /* DiscreteIntegrator: '<S294>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->AND_i) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_g
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->AND_i) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_g
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1(rtb_Switch_n4,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);

  /* Switch: '<S294>/Switch1' incorporates:
   *  Constant: '<S294>/Constant4'
   *  DiscreteIntegrator: '<S294>/Discrete-Time Integrator1'
   *  RelationalOperator: '<S294>/GreaterThan1'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionRampTime) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = rtb_Switch_n4;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5.MovingAverage1;
  }

  /* End of Switch: '<S294>/Switch1' */

  /* Sum: '<S35>/Add' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll =
    rtb_Switch2_idx_2 +
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Gain: '<S35>/Gain2' incorporates:
   *  Gain: '<S35>/Gain3'
   *  Sum: '<S35>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2]) * 401.61 *
    1.02;

  /* RelationalOperator: '<S35>/Equal' incorporates:
   *  Constant: '<S35>/Constant2'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* DiscreteIntegrator: '<S330>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S325>/Filter'
   */
  p_tmp = (boolean_T)!(int32_T)
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
        <= 0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
  }

  /* DiscreteIntegrator: '<S325>/Filter' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k <=
        0)) || (((int32_T)p_tmp) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k ==
        1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
  }

  /* Switch: '<S291>/Switch2' incorporates:
   *  Constant: '<S291>/Constant3'
   *  Constant: '<S291>/Constant4'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_d_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_d;
  }

  /* End of Switch: '<S291>/Switch2' */

  /* Product: '<S333>/NProd Out' incorporates:
   *  Constant: '<S296>/Constant'
   *  Constant: '<S296>/N'
   *  DiscreteIntegrator: '<S325>/Filter'
   *  Product: '<S296>/Divide'
   *  Product: '<S324>/DProd Out'
   *  Sum: '<S325>/SumD'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
     rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 -
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h) *
    (6.2831853071795862 /
     PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_T_c);

  /* Switch: '<S291>/Switch1' incorporates:
   *  Constant: '<S291>/Constant1'
   *  Constant: '<S291>/Constant5'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_p_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_p;
  }

  /* End of Switch: '<S291>/Switch1' */

  /* Sum: '<S339>/Sum' incorporates:
   *  DiscreteIntegrator: '<S330>/Integrator'
   *  Product: '<S335>/PProd Out'
   */
  rtb_Sum_ku = (PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
                rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 +
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw)
    + PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k;

  /* Product: '<S35>/Product' incorporates:
   *  Constant: '<S35>/Reference_R_Inertia'
   *  Gain: '<S35>/Gain1'
   *  Product: '<S35>/Divide'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h = rtb_Gain_do /
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Reference_R_Inertia *
    (1.02 * rtb_Sum_ku);

  /* Sum: '<S34>/Add2' */
  rtb_Add2_h = PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h -
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Product: '<S9>/Divide1' incorporates:
   *  Constant: '<S9>/LatDistance'
   */
  rtb_Divide1 = rtb_Add2_h / 0.392;

  /* Lookup_n-D: '<S424>/2-D Lookup Table3' incorporates:
   *  Constant: '<S424>/Constant'
   */
  bpIndices_0[0U] = plook_binxp(0.0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26, 29U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01);
  fractions_0[0U] = tol;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Subtract_idx_0 > 25.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 25.0;
  } else if (rtb_Subtract_idx_0 < 5.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 5.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      rtb_Subtract_idx_0;
  }

  /* Lookup_n-D: '<S424>/2-D Lookup Table3' */
  bpIndices_0[1U] = plook_binxp
    (rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1,
     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[0]);
  fractions_0[1U] = tol;
  rtb_Switch_k_idx_0 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Subtract_idx_1 > 25.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 25.0;
  } else if (rtb_Subtract_idx_1 < 5.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 5.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      rtb_Subtract_idx_1;
  }

  /* Lookup_n-D: '<S424>/2-D Lookup Table3' */
  bpIndices_0[1U] = plook_binxp
    (rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1,
     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[1]);
  fractions_0[1U] = tol;
  rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = intrp2d_l_pw
    (bpIndices_0, fractions_0,
     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Subtract_idx_2 > 25.0) {
    rtb_Switch_k_idx_1 = 25.0;
  } else if (rtb_Subtract_idx_2 < 5.0) {
    rtb_Switch_k_idx_1 = 5.0;
  } else {
    rtb_Switch_k_idx_1 = rtb_Subtract_idx_2;
  }

  /* Lookup_n-D: '<S424>/2-D Lookup Table3' */
  bpIndices_0[1U] = plook_binxp(rtb_Switch_k_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[2]);
  fractions_0[1U] = tol;
  rtb_Switch_k_idx_1 = intrp2d_l_pw(bpIndices_0, fractions_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Subtract_idx_3 > 25.0) {
    rtb_Switch_k_idx_2 = 25.0;
  } else if (rtb_Subtract_idx_3 < 5.0) {
    rtb_Switch_k_idx_2 = 5.0;
  } else {
    rtb_Switch_k_idx_2 = rtb_Subtract_idx_3;
  }

  /* Lookup_n-D: '<S424>/2-D Lookup Table3' */
  bpIndices_0[1U] = plook_binxp(rtb_Switch_k_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02[3]);
  fractions_0[1U] = tol;
  tol = intrp2d_l_pw(bpIndices_0, fractions_0,
                     PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25,
                     30U);

  /* MATLAB Function: '<S424>/MATLAB Function' incorporates:
   *  Constant: '<S424>/Constant1'
   *  Lookup_n-D: '<S424>/2-D Lookup Table3'
   */
  /* MATLAB Function 'Force Solver/Force Divider1/MATLAB Function': '<S425>:1' */
  /* '<S425>:1:2' */
  /* '<S425>:1:3' */
  /* '<S425>:1:4' */
  /* '<S425>:1:5' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MagnetFailure != 0U) {
    /* '<S425>:1:7' */
    /* '<S425>:1:8' */
    tol = (rtb_Divide1 + rtb_Add_l) / 2.0 -
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

    /* '<S425>:1:9' */
    F1 = (rtb_Divide_k - rtb_Divide1) / 2.0 + tol;

    /* '<S425>:1:10' */
    F3 = (rtb_Add_l - rtb_Divide_k) / 2.0 - tol;
  } else {
    /* '<S425>:1:12' */
    rtb_Switch_k_idx_2 = rtb_Switch_k_idx_0 * rtb_Switch_k_idx_0;
    rtb_Switch_k_idx_3 =
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 *
      rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;
    F1 = rtb_Switch_k_idx_2 * 2.0;
    F3 = F1 * rtb_Switch_k_idx_3;
    rtb_F_array_idx_3 = rtb_Switch_k_idx_2 * rtb_Switch_k_idx_3;
    tol_tmp = rtb_F_array_idx_3 * tol;
    tol_tmp_0 = rtb_Switch_k_idx_1 * rtb_Switch_k_idx_1;
    rtb_Switch_k_idx_2 *= tol_tmp_0;
    tol_tmp_1 = rtb_Switch_k_idx_2 * tol;
    tol_tmp_tmp = rtb_Switch_k_idx_3 * tol_tmp_0;
    tol_tmp_2 = tol_tmp_tmp * tol;
    tol_tmp_3 = tol * tol;
    tol = (((((((((F3 * tol_tmp_0 - F3 * rtb_Switch_k_idx_1 * tol) + tol_tmp *
                  rtb_Add_l) - tol_tmp * rtb_Divide_k) - F1 *
                rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 *
                tol_tmp_0 * tol) + tol_tmp_1 * rtb_Add_l) + tol_tmp_1 *
              rtb_Divide1) + 2.0 * rtb_Switch_k_idx_0 * rtb_Switch_k_idx_3 *
             tol_tmp_0 * tol) - tol_tmp_2 * rtb_Divide_k) + tol_tmp_2 *
           rtb_Divide1) * tol / ((((rtb_F_array_idx_3 * tol_tmp_0 +
      rtb_F_array_idx_3 * tol_tmp_3) + rtb_Switch_k_idx_2 * tol_tmp_3) +
      tol_tmp_tmp * tol_tmp_3) * 2.0);

    /* '<S425>:1:13' */
    F1 = (rtb_Divide_k - rtb_Divide1) / 2.0 + tol;

    /* '<S425>:1:14' */
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = (rtb_Divide1
      + rtb_Add_l) / 2.0 - tol;

    /* '<S425>:1:15' */
    F3 = (rtb_Add_l - rtb_Divide_k) / 2.0 - tol;
  }

  /* '<S425>:1:18' */
  rtb_F_array_idx_3 = tol;

  /* DSPFlip: '<S27>/Flip1' incorporates:
   *  Constant: '<S27>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i];
  }

  /* End of DSPFlip: '<S27>/Flip1' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Subtract_idx_0 > 25.0) {
    rtb_Switch_k_idx_0 = 25.0;
  } else if (rtb_Subtract_idx_0 < 14.0) {
    rtb_Switch_k_idx_0 = 14.0;
  } else {
    rtb_Switch_k_idx_0 = rtb_Subtract_idx_0;
  }

  if (rtb_Subtract_idx_1 > 25.0) {
    rtb_Switch_k_idx_1 = 25.0;
  } else if (rtb_Subtract_idx_1 < 14.0) {
    rtb_Switch_k_idx_1 = 14.0;
  } else {
    rtb_Switch_k_idx_1 = rtb_Subtract_idx_1;
  }

  if (rtb_Subtract_idx_2 > 25.0) {
    rtb_Switch_k_idx_2 = 25.0;
  } else if (rtb_Subtract_idx_2 < 14.0) {
    rtb_Switch_k_idx_2 = 14.0;
  } else {
    rtb_Switch_k_idx_2 = rtb_Subtract_idx_2;
  }

  if (rtb_Subtract_idx_3 > 25.0) {
    rtb_Switch_k_idx_3 = 25.0;
  } else if (rtb_Subtract_idx_3 < 14.0) {
    rtb_Switch_k_idx_3 = 14.0;
  } else {
    rtb_Switch_k_idx_3 = rtb_Subtract_idx_3;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Lookup_n-D: '<S27>/2-D Lookup Table2' incorporates:
   *  Constant: '<S27>/Constant'
   */
  bpIndices_1[1U] = plook_binxpg(rtb_Switch_k_idx_0,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_p);
  fractions_1[1U] = tol;
  for (i = 0; i < 30; i++) {
    bpIndices_1[0U] = plook_binxpg
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26, 29U, &tol,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_m[i]);
    fractions_1[0U] = tol;
    rtb_uDLookupTable2_p[i] = intrp2d_l_pw(bpIndices_1, fractions_1,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);
  }

  /* End of Lookup_n-D: '<S27>/2-D Lookup Table2' */

  /* DSPFlip: '<S27>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip[i] = rtb_uDLookupTable2_p[29 - i];
    rtb_Flip[29 - i] = rtb_uDLookupTable2_p[i];
  }

  /* End of DSPFlip: '<S27>/Flip' */

  /* Lookup_n-D: '<S27>/2-D Lookup Table1' incorporates:
   *  Gain: '<S27>/Gain'
   *  MATLAB Function: '<S424>/MATLAB Function'
   */
  rtb_uDLookupTable1_n = look1_pbinlgpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * F1, &rtb_Flip[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_fj, 27U);

  /* MinMax: '<S27>/Max' incorporates:
   *  Delay: '<S27>/Delay2'
   *  Delay: '<S27>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l))) {
    /* MinMax: '<S27>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE;
  } else {
    /* MinMax: '<S27>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l;
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
      if (rtb_uDLookupTable1_n > 9.0) {
        F1 = 9.0;
      } else if (rtb_uDLookupTable1_n < -9.0) {
        F1 = -9.0;
      } else {
        F1 = rtb_uDLookupTable1_n;
      }

      /* Saturate: '<S27>/Saturation' */
      if (F1 > 5.6) {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 5.6;
      } else if (F1 < -5.6) {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = -5.6;
      } else {
        /* Switch: '<S27>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = F1;
      }

      /* End of Saturate: '<S27>/Saturation' */
    } else if (rtb_uDLookupTable1_n > 9.0) {
      /* Saturate: '<S27>/Saturation1' incorporates:
       *  Switch: '<S27>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 9.0;
    } else if (rtb_uDLookupTable1_n < -9.0) {
      /* Saturate: '<S27>/Saturation1' incorporates:
       *  Switch: '<S27>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = -9.0;
    } else {
      /* Switch: '<S27>/Switch2' incorporates:
       *  Saturate: '<S27>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i =
        rtb_uDLookupTable1_n;
    }

    /* End of Switch: '<S27>/Switch' */
  } else {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 0.0;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* MATLAB Function: '<S24>/Cap requested current' incorporates:
   *  Constant: '<S24>/Ampere'
   */
  /* MATLAB Function 'Subsystem5/Cap requested current': '<S548>:1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i - rtb_Gain1[0] >
      3.0) {
    /* '<S548>:1:4' */
    /* '<S548>:1:5' */
    rtb_out_req_I = rtb_Gain1[0] + 3.0;
  } else if (rtb_Gain1[0] -
             PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i > 3.0) {
    /* '<S548>:1:6' */
    /* '<S548>:1:7' */
    rtb_out_req_I = rtb_Gain1[0] - 3.0;
  } else {
    /* '<S548>:1:9' */
    rtb_out_req_I = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i;
  }

  /* End of MATLAB Function: '<S24>/Cap requested current' */

  /* DSPFlip: '<S28>/Flip1' incorporates:
   *  Constant: '<S28>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_c[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_c[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i];
  }

  /* End of DSPFlip: '<S28>/Flip1' */

  /* Lookup_n-D: '<S28>/2-D Lookup Table2' incorporates:
   *  Constant: '<S28>/Constant'
   */
  bpIndices_2[1U] = plook_binxpg(rtb_Switch_k_idx_1,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_m);
  fractions_2[1U] = tol;
  for (i = 0; i < 30; i++) {
    bpIndices_2[0U] = plook_binxpg
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26, 29U, &tol,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_l[i]);
    fractions_2[0U] = tol;
    rtb_uDLookupTable2_bl[i] = intrp2d_l_pw(bpIndices_2, fractions_2,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);
  }

  /* End of Lookup_n-D: '<S28>/2-D Lookup Table2' */

  /* DSPFlip: '<S28>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_n[i] = rtb_uDLookupTable2_bl[29 - i];
    rtb_Flip_n[29 - i] = rtb_uDLookupTable2_bl[i];
  }

  /* End of DSPFlip: '<S28>/Flip' */

  /* Lookup_n-D: '<S28>/2-D Lookup Table1' incorporates:
   *  Gain: '<S28>/Gain'
   *  MATLAB Function: '<S424>/MATLAB Function'
   */
  rtb_uDLookupTable1_c = look1_pbinlgpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f *
     rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1, &rtb_Flip_n[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_c[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_g, 27U);

  /* MinMax: '<S28>/Max' incorporates:
   *  Delay: '<S28>/Delay2'
   *  Delay: '<S28>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_m >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b))) {
    /* MinMax: '<S28>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_m;
  } else {
    /* MinMax: '<S28>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b;
  }

  /* End of MinMax: '<S28>/Max' */

  /* Sum: '<S28>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_d =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S28>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_d != 0.0) {
    /* Switch: '<S28>/Switch' incorporates:
     *  Saturate: '<S28>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j != 0.0) {
      /* Saturate: '<S28>/Saturation1' */
      if (rtb_uDLookupTable1_c > 9.0) {
        F1 = 9.0;
      } else if (rtb_uDLookupTable1_c < -9.0) {
        F1 = -9.0;
      } else {
        F1 = rtb_uDLookupTable1_c;
      }

      /* Saturate: '<S28>/Saturation' */
      if (F1 > 5.6) {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = 5.6;
      } else if (F1 < -5.6) {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = -5.6;
      } else {
        /* Switch: '<S28>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = F1;
      }

      /* End of Saturate: '<S28>/Saturation' */
    } else if (rtb_uDLookupTable1_c > 9.0) {
      /* Saturate: '<S28>/Saturation1' incorporates:
       *  Switch: '<S28>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = 9.0;
    } else if (rtb_uDLookupTable1_c < -9.0) {
      /* Saturate: '<S28>/Saturation1' incorporates:
       *  Switch: '<S28>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = -9.0;
    } else {
      /* Switch: '<S28>/Switch2' incorporates:
       *  Saturate: '<S28>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot =
        rtb_uDLookupTable1_c;
    }

    /* End of Switch: '<S28>/Switch' */
  } else {
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = 0.0;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* MATLAB Function: '<S24>/Cap requested current1' incorporates:
   *  Constant: '<S24>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[1],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent1);

  /* DSPFlip: '<S29>/Flip1' incorporates:
   *  Constant: '<S29>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_p[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_p[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i];
  }

  /* End of DSPFlip: '<S29>/Flip1' */

  /* Lookup_n-D: '<S29>/2-D Lookup Table2' incorporates:
   *  Constant: '<S29>/Constant'
   */
  bpIndices_3[1U] = plook_binxpg(rtb_Switch_k_idx_2,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_i);
  fractions_3[1U] = tol;
  for (i = 0; i < 30; i++) {
    bpIndices_3[0U] = plook_binxpg
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26, 29U, &tol,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_f[i]);
    fractions_3[0U] = tol;
    rtb_uDLookupTable2_j[i] = intrp2d_l_pw(bpIndices_3, fractions_3,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);
  }

  /* End of Lookup_n-D: '<S29>/2-D Lookup Table2' */

  /* DSPFlip: '<S29>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_l[i] = rtb_uDLookupTable2_j[29 - i];
    rtb_Flip_l[29 - i] = rtb_uDLookupTable2_j[i];
  }

  /* End of DSPFlip: '<S29>/Flip' */

  /* Lookup_n-D: '<S29>/2-D Lookup Table1' incorporates:
   *  Gain: '<S29>/Gain'
   *  MATLAB Function: '<S424>/MATLAB Function'
   */
  rtb_uDLookupTable1_e = look1_pbinlgpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * F3, &rtb_Flip_l[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_p[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_m, 27U);

  /* MinMax: '<S29>/Max' incorporates:
   *  Delay: '<S29>/Delay2'
   *  Delay: '<S29>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_i >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g))) {
    /* MinMax: '<S29>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_b =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_i;
  } else {
    /* MinMax: '<S29>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_b =
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
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_b != 0.0) {
      /* Saturate: '<S29>/Saturation1' */
      if (rtb_uDLookupTable1_e > 9.0) {
        F1 = 9.0;
      } else if (rtb_uDLookupTable1_e < -9.0) {
        F1 = -9.0;
      } else {
        F1 = rtb_uDLookupTable1_e;
      }

      /* Saturate: '<S29>/Saturation' */
      if (F1 > 5.6) {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = 5.6;
      } else if (F1 < -5.6) {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = -5.6;
      } else {
        /* Switch: '<S29>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = F1;
      }

      /* End of Saturate: '<S29>/Saturation' */
    } else if (rtb_uDLookupTable1_e > 9.0) {
      /* Saturate: '<S29>/Saturation1' incorporates:
       *  Switch: '<S29>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = 9.0;
    } else if (rtb_uDLookupTable1_e < -9.0) {
      /* Saturate: '<S29>/Saturation1' incorporates:
       *  Switch: '<S29>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = -9.0;
    } else {
      /* Switch: '<S29>/Switch2' incorporates:
       *  Saturate: '<S29>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c =
        rtb_uDLookupTable1_e;
    }

    /* End of Switch: '<S29>/Switch' */
  } else {
    /* Switch: '<S29>/Switch2' incorporates:
     *  Constant: '<S29>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = 0.0;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* MATLAB Function: '<S24>/Cap requested current2' incorporates:
   *  Constant: '<S24>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[2],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent2);

  /* DSPFlip: '<S30>/Flip1' incorporates:
   *  Constant: '<S30>/Constant20'
   */
  for (i = 0; i < 15; i++) {
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_o[i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[29 - i];
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_o[29 - i] =
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i];
  }

  /* End of DSPFlip: '<S30>/Flip1' */

  /* Lookup_n-D: '<S30>/2-D Lookup Table2' incorporates:
   *  Constant: '<S30>/Constant'
   */
  bpIndices_4[1U] = plook_binxpg(rtb_Switch_k_idx_3,
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled27, 350U, &tol,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache02_k);
  fractions_4[1U] = tol;
  for (i = 0; i < 30; i++) {
    bpIndices_4[0U] = plook_binxpg
      (PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26[i],
       PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled26, 29U, &tol,
       &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_Cache01_o[i]);
    fractions_4[0U] = tol;
    rtb_uDLookupTable2_c[i] = intrp2d_l_pw(bpIndices_4, fractions_4,
      PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled25, 30U);
  }

  /* End of Lookup_n-D: '<S30>/2-D Lookup Table2' */

  /* DSPFlip: '<S30>/Flip' */
  for (i = 0; i < 15; i++) {
    rtb_Flip_d[i] = rtb_uDLookupTable2_c[29 - i];
    rtb_Flip_d[29 - i] = rtb_uDLookupTable2_c[i];
  }

  /* End of DSPFlip: '<S30>/Flip' */

  /* Lookup_n-D: '<S30>/2-D Lookup Table1' incorporates:
   *  Gain: '<S30>/Gain'
   */
  rtb_uDLookupTable1_m = look1_pbinlgpw
    (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->M_f * rtb_F_array_idx_3,
     &rtb_Flip_d[2], &PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_o[2],
     &PIDcontroller4CoreCentralizedTestReadyMotor_DW->m_bpIndex_e, 27U);

  /* MinMax: '<S30>/Max' incorporates:
   *  Delay: '<S30>/Delay2'
   *  Delay: '<S30>/Delay3'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_o >
       PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo) ||
      ((int32_T)rtIsNaN
       (PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo))) {
    /* MinMax: '<S30>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_i =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_o;
  } else {
    /* MinMax: '<S30>/Max' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_i =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo;
  }

  /* End of MinMax: '<S30>/Max' */

  /* Sum: '<S30>/Subtract4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Outport: '<Root>/Mode'
   *  Sum: '<S27>/Subtract4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_n =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode - 2.0;

  /* Switch: '<S30>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_n != 0.0) {
    /* Switch: '<S30>/Switch' incorporates:
     *  Saturate: '<S30>/Saturation1'
     */
    if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_i != 0.0) {
      /* Saturate: '<S30>/Saturation1' */
      if (rtb_uDLookupTable1_m > 9.0) {
        F1 = 9.0;
      } else if (rtb_uDLookupTable1_m < -9.0) {
        F1 = -9.0;
      } else {
        F1 = rtb_uDLookupTable1_m;
      }

      /* Saturate: '<S30>/Saturation' */
      if (F1 > 5.6) {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = 5.6;
      } else if (F1 < -5.6) {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = -5.6;
      } else {
        /* Switch: '<S30>/Switch2' */
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = F1;
      }

      /* End of Saturate: '<S30>/Saturation' */
    } else if (rtb_uDLookupTable1_m > 9.0) {
      /* Saturate: '<S30>/Saturation1' incorporates:
       *  Switch: '<S30>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = 9.0;
    } else if (rtb_uDLookupTable1_m < -9.0) {
      /* Saturate: '<S30>/Saturation1' incorporates:
       *  Switch: '<S30>/Switch2'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = -9.0;
    } else {
      /* Switch: '<S30>/Switch2' incorporates:
       *  Saturate: '<S30>/Saturation1'
       */
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a =
        rtb_uDLookupTable1_m;
    }

    /* End of Switch: '<S30>/Switch' */
  } else {
    /* Switch: '<S30>/Switch2' incorporates:
     *  Constant: '<S30>/Constant6'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = 0.0;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* MATLAB Function: '<S24>/Cap requested current3' incorporates:
   *  Constant: '<S24>/Ampere'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(rtb_Gain1[3],
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a, 3.0,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent3);

  /* Switch: '<Root>/Switch3' incorporates:
   *  Gain: '<Root>/Gain'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal) {
    /* Outport: '<Root>/I_A' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_A = 0.0;
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
    F3 = 0.0;
    rtb_F_array_idx_3 = 0.0;
  } else {
    /* Outport: '<Root>/I_A' incorporates:
     *  Gain: '<Root>/Gain'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_A =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
      rtb_out_req_I;
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent1.out_req_I;
    F3 = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent2.out_req_I;
    rtb_F_array_idx_3 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Polarity *
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_Caprequestedcurrent3.out_req_I;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Outport: '<Root>/Airgap' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Airgap =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0];

  /* Derivative: '<Root>/Derivative' incorporates:
   *  Derivative: '<Root>/Derivative1'
   */
  tol = PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA >= tol) &&
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB >= tol)) {
    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative[0] = 0.0;
    rtb_Derivative[1] = 0.0;
    rtb_Derivative[2] = 0.0;
  } else {
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA;
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA;
    if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA <
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB) {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB < tol) {
        F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB;
        lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
      }
    } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA >= tol)
    {
      F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB;
      lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB;
    }

    F1 = tol - F1;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative[0] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0] - (*lastU)[0])
      / F1;
    rtb_Derivative[1] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1] - (*lastU)[1])
      / F1;
    rtb_Derivative[2] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2] - (*lastU)[2])
      / F1;
  }

  /* End of Derivative: '<Root>/Derivative' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(rtb_Derivative,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);

  /* Derivative: '<Root>/Derivative1' */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l >= tol) &&
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b >= tol)) {
    /* Derivative: '<Root>/Derivative1' */
    rtb_Derivative1[0] = 0.0;
    rtb_Derivative1[1] = 0.0;
    rtb_Derivative1[2] = 0.0;
  } else {
    F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l;
    lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeA_g;
    if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l <
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b) {
      if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b < tol) {
        F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b;
        lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
      }
    } else if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l >=
               tol) {
      F1 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b;
      lastU = &PIDcontroller4CoreCentralizedTestReadyMotor_DW->LastUAtTimeB_l;
    }

    F1 = tol - F1;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  MATLABSystem: '<Root>/Moving Average'
     */
    rtb_Derivative1[0] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [0] - (*lastU)[0]) / F1;
    rtb_Derivative1[1] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [1] - (*lastU)[1]) / F1;
    rtb_Derivative1[2] =
      (PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
       [2] - (*lastU)[2]) / F1;
  }

  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(rtb_Derivative1,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);

  /* Outport: '<Root>/Acceleration' incorporates:
   *  MATLABSystem: '<Root>/Moving Average1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
    [0];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
    [1];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Acceleration[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
    [2];

  /* Outport: '<Root>/Calculated Force' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/Moving Average1'
   *  Product: '<Root>/Product'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
    [0] * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
    [1] * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedForce[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
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

  /* Outport: '<Root>/I_B' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_B =
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Outport: '<Root>/I_C' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_C = F3;

  /* Outport: '<Root>/I_D' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->I_D = rtb_F_array_idx_3;

  /* Outport: '<Root>/Pitch' incorporates:
   *  Gain: '<S11>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Pitch = 57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1];

  /* Outport: '<Root>/Roll' incorporates:
   *  Gain: '<S12>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Roll = 57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2];

  /* Outport: '<Root>/Linpos' incorporates:
   *  Sum: '<S21>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[0] = rtb_Subtract_idx_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[1] = rtb_Subtract_idx_1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[2] = rtb_Subtract_idx_2;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Linpos[3] = rtb_Subtract_idx_3;

  /* Outport: '<Root>/PitchError' incorporates:
   *  Gain: '<S182>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->PitchError = 57.295779513082323
    * rtb_error_m;

  /* Outport: '<Root>/BeamErrorOutput' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[0] =
    rtb_Switch2_idx_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[1] =
    57.295779513082323 * rtb_Switch2_idx_1;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->BeamErrorOutput[2] =
    57.295779513082323 * rtb_Switch2_idx_2;

  /* Outport: '<Root>/Control SIgnals' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[0] = rtb_Add_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[1] = rtb_Add1_f;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ControlSIgnals[2] = rtb_Add2_h;

  /* Outport: '<Root>/External Forces' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[0] = rtb_Add4_n;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[1] = rtb_Add1_d;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->ExternalForces[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant3'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchedHEMSLateral >
      0.0) {
    /* Outport: '<Root>/HEMSForces' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[0] =
      rtb_Product_idx_0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[1] =
      rtb_Product_idx_1;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[2] =
      rtb_Product_idx_2;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[3] =
      rtb_Product_idx_3;
  } else {
    /* Outport: '<Root>/HEMSForces' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[0] =
      rtb_uDLookupTable2;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[1] =
      rtb_uDLookupTable1;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[2] =
      rtb_uDLookupTable3;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->HEMSForces[3] =
      rtb_uDLookupTable4;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'Calculate External Force/MATLAB Function': '<S399>:1' */
  /* '<S399>:1:4' */
  /* '<S399>:1:5' */
  /* '<S399>:1:7' */
  tol = rtb_uDLookupTable1_gs[0];

  /* '<S399>:1:8' */
  F1 = rtb_uDLookupTable1_gs[20];
  for (i = 0; i < 18; i++) {
    tol += rtb_uDLookupTable1_gs[i + 1];
    F1 += rtb_uDLookupTable1_gs[i + 21];
  }

  /* Outport: '<Root>/motorfrontback' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* '<S399>:1:10' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[0] = tol / 19.0 /
    2.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->motorfrontback[1] = F1 / 19.0 /
    2.0;

  /* Outport: '<Root>/DataBeforeKalman' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S16>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[0] =
    rtb_Switch_gj;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[1] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->DataBeforeKalman[2] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c;

  /* Sum: '<S402>/Sum1' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<S402>/Abs'
   *  Gain: '<S402>/Gain1'
   *  Inport: '<Root>/Vr1'
   *  Inport: '<Root>/Vr2'
   *  Inport: '<Root>/Vr3'
   *  Inport: '<Root>/Vr4'
   *  Inport: '<Root>/Vt1'
   *  Inport: '<Root>/Vt2'
   *  Inport: '<Root>/Vt3'
   *  Inport: '<Root>/Vt4'
   *  Product: '<S402>/Product'
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

  /* MATLABSystem: '<S402>/Moving Average' */
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
   *  MATLABSystem: '<S402>/Moving Average'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Power_avg =
    PIDcontroller4CoreCentralizedTestReadyMotor_SlidingWindowAverageCG_stepImpl_o
    (obj_0, PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1);

  /* DiscreteIntegrator: '<S402>/Discrete-Time Integrator' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
      = 0.0;
  }

  /* Outport: '<Root>/Energy' incorporates:
   *  DiscreteIntegrator: '<S402>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Energy =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i;

  /* Sum: '<S4>/Add' */
  tol = ((rtb_uDLookupTable2 + rtb_uDLookupTable1) + rtb_uDLookupTable3) +
    rtb_uDLookupTable4;

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/LongDistance'
   *  Product: '<S4>/Product'
   */
  rtb_Switch2_idx_0 = ((rtb_uDLookupTable2 * 0.3054 + rtb_uDLookupTable1 *
                        0.3054) + rtb_uDLookupTable3 *
                       PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain)
    + rtb_uDLookupTable4 *
    PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/LatDistance'
   *  Product: '<S4>/Product1'
   */
  rtb_Switch2_idx_1 = ((PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain1
                        * rtb_uDLookupTable2 + 0.392 * rtb_uDLookupTable1) +
                       PIDcontroller4CoreCentralizedTestReadyMotor_ConstB.Gain1 *
                       rtb_uDLookupTable3) + 0.392 * rtb_uDLookupTable4;

  /* Outport: '<Root>/CalculatedTPR' incorporates:
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[0] = tol;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[1] =
    rtb_Switch2_idx_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedTPR[2] =
    rtb_Switch2_idx_1;

  /* Outport: '<Root>/IMU_kalman_output' incorporates:
   *  Gain: '<S17>/Gain'
   *  Gain: '<S18>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[1] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Add4;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[2] =
    57.295779513082323 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Add5;

  /* Outport: '<Root>/Kalman_Output' incorporates:
   *  Gain: '<S19>/Gain'
   *  Gain: '<S20>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[1] =
    57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[5];
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[2] =
    57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[3];

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

  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g;

  /* End of DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  /* Delay: '<S27>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[0];

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
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    /* Switch: '<S27>/Switch7' incorporates:
     *  Sum: '<S27>/Subtract9'
     *  Switch: '<S27>/Switch9'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 = (real_T)
      !(rtb_Switch_k_idx_0 - 17.0 > 0.0);
  } else {
    /* Switch: '<S27>/Switch7' incorporates:
     *  Constant: '<S27>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 = 0.0;
  }

  /* End of Switch: '<S27>/Switch7' */

  /* Delay: '<S28>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_au;

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_o1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h;

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  /* Delay: '<S28>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0];

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_d
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_il =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_d;

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  /* Switch: '<S28>/Switch4' incorporates:
   *  Constant: '<S28>/Constant11'
   *  Sum: '<S28>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g = (real_T)
    (rtb_DiscreteTimeIntegrator_o1 - 1.0 >= 0.0);

  /* Switch: '<S28>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g != 0.0) {
    /* Switch: '<S28>/Switch6' incorporates:
     *  Constant: '<S28>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_a = 0.0;
  } else {
    /* Switch: '<S28>/Switch6' incorporates:
     *  Constant: '<S28>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_a = -1.0;
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
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h = 1.0;
  } else {
    /* Switch: '<S28>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_a;
  }

  /* End of Switch: '<S28>/Switch3' */

  /* Switch: '<S28>/Switch5' incorporates:
   *  Constant: '<S28>/Constant12'
   *  Sum: '<S28>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c = (real_T)
    (rtb_DiscreteTimeIntegrator1_il - 1.0 >= 0.0);

  /* Switch: '<S28>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    /* Switch: '<S28>/Switch7' incorporates:
     *  Sum: '<S28>/Subtract9'
     *  Switch: '<S28>/Switch9'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_h = (real_T)
      !(rtb_Switch_k_idx_1 - 17.0 > 0.0);
  } else {
    /* Switch: '<S28>/Switch7' incorporates:
     *  Constant: '<S28>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_h = 0.0;
  }

  /* End of Switch: '<S28>/Switch7' */

  /* Delay: '<S29>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_l;

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_lo =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr;

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  /* Delay: '<S29>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[0];

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_e
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_e;

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  /* Switch: '<S29>/Switch4' incorporates:
   *  Constant: '<S29>/Constant11'
   *  Sum: '<S29>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_n = (real_T)
    (rtb_DiscreteTimeIntegrator_lo - 1.0 >= 0.0);

  /* Switch: '<S29>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_n != 0.0) {
    /* Switch: '<S29>/Switch6' incorporates:
     *  Constant: '<S29>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_j = 0.0;
  } else {
    /* Switch: '<S29>/Switch6' incorporates:
     *  Constant: '<S29>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_j = -1.0;
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
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m = 1.0;
  } else {
    /* Switch: '<S29>/Switch3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_j;
  }

  /* End of Switch: '<S29>/Switch3' */

  /* Switch: '<S29>/Switch5' incorporates:
   *  Constant: '<S29>/Constant12'
   *  Sum: '<S29>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_d = (real_T)
    (rtb_DiscreteTimeIntegrator1_c - 1.0 >= 0.0);

  /* Switch: '<S29>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    /* Switch: '<S29>/Switch7' incorporates:
     *  Sum: '<S29>/Subtract9'
     *  Switch: '<S29>/Switch9'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e = (real_T)
      !(rtb_Switch_k_idx_2 - 17.0 > 0.0);
  } else {
    /* Switch: '<S29>/Switch7' incorporates:
     *  Constant: '<S29>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e = 0.0;
  }

  /* End of Switch: '<S29>/Switch7' */

  /* Delay: '<S30>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g;

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator_p =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op;

  /* End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  /* Delay: '<S30>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[0];

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
        <= 0)) || ((PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f <=
                    0.0) && ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_h
      = 0.0;
  }

  rtb_DiscreteTimeIntegrator1_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_h;

  /* End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  /* Switch: '<S30>/Switch4' incorporates:
   *  Constant: '<S30>/Constant11'
   *  Sum: '<S30>/Subtract6'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_f = (real_T)
    (rtb_DiscreteTimeIntegrator_p - 1.0 >= 0.0);

  /* Switch: '<S30>/Switch6' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_f != 0.0) {
    /* Switch: '<S30>/Switch6' incorporates:
     *  Constant: '<S30>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_b = 0.0;
  } else {
    /* Switch: '<S30>/Switch6' incorporates:
     *  Constant: '<S30>/Constant17'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_b = -1.0;
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
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_b;
  }

  /* End of Switch: '<S30>/Switch3' */

  /* Switch: '<S30>/Switch5' incorporates:
   *  Constant: '<S30>/Constant12'
   *  Sum: '<S30>/Subtract7'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g = (real_T)
    (rtb_DiscreteTimeIntegrator1_o - 1.0 >= 0.0);

  /* Switch: '<S30>/Switch7' incorporates:
   *  Outport: '<Root>/Mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode != 0.0) {
    /* Switch: '<S30>/Switch7' incorporates:
     *  Sum: '<S30>/Subtract9'
     *  Switch: '<S30>/Switch9'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_p = (real_T)
      !(rtb_Switch_k_idx_3 - 17.0 > 0.0);
  } else {
    /* Switch: '<S30>/Switch7' incorporates:
     *  Constant: '<S30>/Constant5'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_p = 0.0;
  }

  /* End of Switch: '<S30>/Switch7' */
  /* Switch: '<S70>/Switch3' incorporates:
   *  Constant: '<S70>/Constant2'
   *  Constant: '<S70>/Constant6'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_i_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->G_K_i;
  }

  /* End of Switch: '<S70>/Switch3' */

  /* Product: '<S105>/IProd Out' */
  rtb_IProdOut = PIDcontroller4CoreCentralizedTestReadyMotor_B->error *
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Signum: '<S99>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0) {
    F1 = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    F1 = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    F1 = 0.0;
  } else {
    F1 = (rtNaN);
  }

  /* End of Signum: '<S99>/SignPreIntegrator' */

  /* DataTypeConversion: '<S99>/DataTypeConv2' */
  rtb_Switch2_idx_2 = fabs(F1);
  if (rtb_Switch2_idx_2 < 4.503599627370496E+15) {
    if (rtb_Switch2_idx_2 >= 0.5) {
      F1 = floor(F1 + 0.5);
    } else {
      F1 *= 0.0;
    }
  }

  if (rtIsNaN(F1)) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = fmod(F1,
      256.0);
  }

  /* DeadZone: '<S101>/DeadZone' */
  if (rtb_Sum_h >= (rtMinusInf)) {
    rtb_Switch2_idx_2 = 0.0;
  } else {
    rtb_Switch2_idx_2 = (rtNaN);
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
  if ((0.0 * rtb_Sum_h != rtb_Switch2_idx_2) &&
      ((rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 : (int32_T)
        (int8_T)(uint8_T)
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1) == 0)) {
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

  /* Sum: '<S152>/SumI4' incorporates:
   *  Gain: '<S152>/Kb'
   *  Gain: '<S158>/Integral Gain'
   *  Sum: '<S152>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4 = (rtb_Sum_gy -
    rtb_Sum_gy) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralAG *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch;

  /* DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S71>/Constant2'
   */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
        <= 0)) ||
      ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <= 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_it
      = 0.0;
  }

  /* RelationalOperator: '<S71>/GreaterThan' incorporates:
   *  Constant: '<S71>/Constant3'
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_it
     > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingTime);

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant'
   *  Constant: '<S71>/Constant2'
   *  Delay: '<S71>/Delay'
   *  Logic: '<S71>/AND'
   */
  if ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->LowAirgapPropellingSwitch
       != 0.0) &&
      (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn != 0.0) &&
      ((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_g))
  {
    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S71>/Constant1'
     */
    rtb_Switch_ph =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingAirgap;
  } else {
    /* Switch: '<S71>/Switch' */
    rtb_Switch_ph = 0.0;
  }

  /* End of Switch: '<S71>/Switch' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1(rtb_Switch_ph,
    &PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfp,
    &PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);

  /* Switch: '<S180>/Switch3' incorporates:
   *  Constant: '<S180>/Constant2'
   *  Constant: '<S180>/Constant6'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_i_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->P_K_i;
  }

  /* End of Switch: '<S180>/Switch3' */

  /* Product: '<S217>/IProd Out' */
  rtb_IProdOut_k = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 *
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Signum: '<S211>/SignPreIntegrator' */
  if (rtb_IProdOut_k < 0.0) {
    F1 = -1.0;
  } else if (rtb_IProdOut_k > 0.0) {
    F1 = 1.0;
  } else if (rtb_IProdOut_k == 0.0) {
    F1 = 0.0;
  } else {
    F1 = (rtNaN);
  }

  /* End of Signum: '<S211>/SignPreIntegrator' */

  /* DataTypeConversion: '<S211>/DataTypeConv2' */
  rtb_Switch2_idx_2 = fabs(F1);
  if (rtb_Switch2_idx_2 < 4.503599627370496E+15) {
    if (rtb_Switch2_idx_2 >= 0.5) {
      F1 = floor(F1 + 0.5);
    } else {
      F1 *= 0.0;
    }
  }

  if (rtIsNaN(F1)) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = fmod(F1,
      256.0);
  }

  /* DeadZone: '<S213>/DeadZone' */
  if (rtb_Sum_o >= (rtMinusInf)) {
    rtb_Switch2_idx_2 = 0.0;
  } else {
    rtb_Switch2_idx_2 = (rtNaN);
  }

  /* End of DeadZone: '<S213>/DeadZone' */

  /* Switch: '<S211>/Switch' incorporates:
   *  DataTypeConversion: '<S211>/DataTypeConv1'
   *  DataTypeConversion: '<S211>/DataTypeConv2'
   *  Gain: '<S211>/ZeroGain'
   *  Logic: '<S211>/AND3'
   *  RelationalOperator: '<S211>/Equal1'
   *  RelationalOperator: '<S211>/NotEqual'
   */
  if ((0.0 * rtb_Sum_o != rtb_Switch2_idx_2) &&
      ((rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 : (int32_T)
        (int8_T)(uint8_T)
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1) == 0)) {
    /* Switch: '<S211>/Switch' incorporates:
     *  Constant: '<S211>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j = 0.0;
  } else {
    /* Switch: '<S211>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j = rtb_IProdOut_k;
  }

  /* End of Switch: '<S211>/Switch' */

  /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S184>/Constant2'
   */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
        <= 0)) ||
      ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <= 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_j
      = 0.0;
  }

  /* RelationalOperator: '<S184>/GreaterThan' incorporates:
   *  Constant: '<S184>/Constant3'
   *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan_n = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_j
     > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingTime);

  /* Sum: '<S263>/SumI4' incorporates:
   *  Gain: '<S263>/Kb'
   *  Gain: '<S269>/Integral Gain'
   *  Sum: '<S263>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_c = (rtb_Sum_ac -
    rtb_Sum_ac) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o;

  /* Switch: '<S291>/Switch3' incorporates:
   *  Constant: '<S291>/Constant2'
   *  Constant: '<S291>/Constant6'
   *  Inport: '<Root>/LS_mode'
   */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode != 0.0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_i_LS;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->R_K_i;
  }

  /* End of Switch: '<S291>/Switch3' */

  /* Product: '<S327>/IProd Out' */
  rtb_IProdOut_h = PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e *
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Signum: '<S321>/SignPreIntegrator' */
  if (rtb_IProdOut_h < 0.0) {
    F1 = -1.0;
  } else if (rtb_IProdOut_h > 0.0) {
    F1 = 1.0;
  } else if (rtb_IProdOut_h == 0.0) {
    F1 = 0.0;
  } else {
    F1 = (rtNaN);
  }

  /* End of Signum: '<S321>/SignPreIntegrator' */

  /* DataTypeConversion: '<S321>/DataTypeConv2' */
  rtb_Switch2_idx_2 = fabs(F1);
  if (rtb_Switch2_idx_2 < 4.503599627370496E+15) {
    if (rtb_Switch2_idx_2 >= 0.5) {
      F1 = floor(F1 + 0.5);
    } else {
      F1 *= 0.0;
    }
  }

  if (rtIsNaN(F1)) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = fmod(F1,
      256.0);
  }

  /* DeadZone: '<S323>/DeadZone' */
  if (rtb_Sum_ku >= (rtMinusInf)) {
    rtb_Switch2_idx_2 = 0.0;
  } else {
    rtb_Switch2_idx_2 = (rtNaN);
  }

  /* End of DeadZone: '<S323>/DeadZone' */

  /* Switch: '<S321>/Switch' incorporates:
   *  DataTypeConversion: '<S321>/DataTypeConv1'
   *  DataTypeConversion: '<S321>/DataTypeConv2'
   *  Gain: '<S321>/ZeroGain'
   *  Logic: '<S321>/AND3'
   *  RelationalOperator: '<S321>/Equal1'
   *  RelationalOperator: '<S321>/NotEqual'
   */
  if ((0.0 * rtb_Sum_ku != rtb_Switch2_idx_2) &&
      ((rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 < 0.0 ?
        (int32_T)(int8_T)-(int32_T)(int8_T)(uint8_T)
        -rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 : (int32_T)
        (int8_T)(uint8_T)
        rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1) == 0)) {
    /* Switch: '<S321>/Switch' incorporates:
     *  Constant: '<S321>/Constant1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d = 0.0;
  } else {
    /* Switch: '<S321>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d = rtb_IProdOut_h;
  }

  /* End of Switch: '<S321>/Switch' */

  /* DiscreteIntegrator: '<S294>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S294>/Constant2'
   */
  if (((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
        <= 0)) ||
      ((PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <= 0.0) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
        == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_in
      = 0.0;
  }

  /* RelationalOperator: '<S294>/GreaterThan' incorporates:
   *  Constant: '<S294>/Constant3'
   *  DiscreteIntegrator: '<S294>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan_f = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_in
     > PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropellingTime);

  /* Sum: '<S373>/SumI4' incorporates:
   *  Gain: '<S373>/Kb'
   *  Gain: '<S379>/Integral Gain'
   *  Sum: '<S373>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_o = (rtb_Sum_eh -
    rtb_Sum_eh) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralR *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p;

  /* RelationalOperator: '<S7>/Equal' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_l = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* RelationalOperator: '<S7>/Equal1' incorporates:
   *  Constant: '<S7>/Constant5'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1_p = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* RelationalOperator: '<S7>/Equal2' incorporates:
   *  Constant: '<S7>/Constant7'
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2_g = (boolean_T)
    (PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode == 2.0);

  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Sum: '<S5>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_g = 9.81 *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* SignalConversion generated from: '<S403>/Create Diagonal Matrix1' incorporates:
   *  Constant: '<S403>/Constant4'
   *  Constant: '<S403>/Constant5'
   *  Constant: '<S403>/Constant6'
   *  Constant: '<S403>/Constant7'
   *  Constant: '<S403>/Constant8'
   *  Constant: '<S403>/Constant9'
   *  SignalConversion generated from: '<S412>/Create Diagonal Matrix1'
   */
  imvec[0] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_dot;
  imvec[1] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_ag_proc;
  imvec[2] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_dot;
  imvec[3] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_roll_proc;
  imvec[4] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_dot;
  imvec[5] = PIDcontroller4CoreCentralizedTestReadyMotor_InstP->var_pitch_proc;

  /* S-Function (sdspdiag2): '<S403>/Create Diagonal Matrix1' incorporates:
   *  SignalConversion generated from: '<S403>/Create Diagonal Matrix1'
   */
  for (i = 0; i < 36; i++) {
    rtb_CreateDiagonalMatrix1[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    rtb_CreateDiagonalMatrix1[i * 7] = imvec[i];
  }

  /* End of S-Function (sdspdiag2): '<S403>/Create Diagonal Matrix1' */

  /* Switch: '<S7>/Switch' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_l) {
    /* Switch: '<S7>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] = 0.0;
  } else {
    /* Switch: '<S7>/Switch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0] = rtb_z_out_idx_0;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1] = rtb_z_out_idx_1;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2] = rtb_z_out_idx_2;
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3] = rtb_z_out_idx_3;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Switch: '<S7>/Switch1' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal1_p) {
    /* Switch: '<S7>/Switch1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_g;
  } else {
    /* Switch: '<S7>/Switch1' incorporates:
     *  Sum: '<S7>/Add1'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg = rtb_Switch1_d;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Switch: '<S7>/Switch2' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal2_g) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant8'
     */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k = 0.0;
  } else {
    /* Switch: '<S7>/Switch2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k = rtb_Add1_d;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* ZeroOrderHold: '<S403>/Zero-Order Hold1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   */
  rtb_ZeroOrderHold1_k[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[0];
  rtb_ZeroOrderHold1_k[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[1];
  rtb_ZeroOrderHold1_k[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[2];
  rtb_ZeroOrderHold1_k[3] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_e[3];
  rtb_ZeroOrderHold1_k[4] = rtb_Gain_do;
  rtb_ZeroOrderHold1_k[5] = rtb_Gain_m;
  rtb_ZeroOrderHold1_k[6] = 0.392;
  rtb_ZeroOrderHold1_k[7] = 0.3054;
  rtb_ZeroOrderHold1_k[8] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  rtb_ZeroOrderHold1_k[9] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_eg;
  rtb_ZeroOrderHold1_k[10] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_k;
  rtb_ZeroOrderHold1_k[11] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Outputs for Atomic SubSystem: '<S405>/Predict' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Predict(rtb_CreateDiagonalMatrix1,
    rtb_ZeroOrderHold1_k, PIDcontroller4CoreCentralizedTestReadyMotor_DW->P,
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->x);

  /* End of Outputs for SubSystem: '<S405>/Predict' */

  /* Delay: '<S8>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_m =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_c;

  /* Delay: '<S8>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_j =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_n;

  /* Delay: '<S8>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2_n =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_c;

  /* Gain: '<S8>/Gain1' incorporates:
   *  Sum: '<S8>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1_k =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2_n -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->IMU_integration_gain;

  /* Gain: '<S8>/Gain2' incorporates:
   *  Sum: '<S8>/Add2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_d =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_j -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->IMU_integration_gain;

  /* Gain: '<S8>/Gain3' incorporates:
   *  Sum: '<S8>/Add'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_m -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->IMU_integration_gain;

  /* S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix1' incorporates:
   *  SignalConversion generated from: '<S412>/Create Diagonal Matrix1'
   */
  for (i = 0; i < 36; i++) {
    rtb_CreateDiagonalMatrix1_c[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    rtb_CreateDiagonalMatrix1_c[i * 7] = imvec[i];
  }

  /* End of S-Function (sdspdiag2): '<S412>/Create Diagonal Matrix1' */

  /* Outputs for Atomic SubSystem: '<S414>/Predict' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Predict
    (rtb_CreateDiagonalMatrix1_c, rtb_ZeroOrderHold1,
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h,
     PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n);

  /* End of Outputs for SubSystem: '<S414>/Predict' */

  /* Gain: '<S412>/Gain' incorporates:
   *  Inport: '<Root>/IMU_z'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->kalman_zdotdot_gain *
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_z;

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_ll
      = 0.0;
  }

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator3' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
      = 0.0;
  }

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator4' */
  if ((((int32_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
       ((int32_T)
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
        <= 0)) || ((!(int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c) &&
                   ((int32_T)
                    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
                    == 1))) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
      = 0.0;
  }

  /* Saturate: '<S10>/Saturation' */
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d > 40.0) {
    /* Saturate: '<S10>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 40.0;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d < 1.0) {
    /* Saturate: '<S10>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 1.0;
  } else {
    /* Saturate: '<S10>/Saturation' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation =
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Saturate: '<S10>/Saturation1' */
  if (rtb_Switch_gj > 40.0) {
    rtb_Switch2_idx_2 = 40.0;
  } else if (rtb_Switch_gj < 1.0) {
    rtb_Switch2_idx_2 = 1.0;
  } else {
    rtb_Switch2_idx_2 = rtb_Switch_gj;
  }

  /* End of Saturate: '<S10>/Saturation1' */

  /* Gain: '<S10>/Gain2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Gain: '<S10>/Gain1'
   *  Product: '<S10>/Divide'
   *  Sum: '<S10>/Subtract2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation /
     rtb_Switch2_idx_2 - 1.0) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_F *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[0];

  /* Gain: '<S10>/Gain5' incorporates:
   *  Gain: '<S10>/Gain3'
   *  Sum: '<S10>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[5] -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_P *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[1];

  /* Gain: '<S10>/Gain6' incorporates:
   *  Gain: '<S10>/Gain4'
   *  Sum: '<S10>/Add2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6 =
    (PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[3] -
     PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Kalman_R *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MismatchingKalmanAGPR[2];

  /* Sum: '<S10>/Subtract' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d - rtb_Switch_gj;

  /* SignalConversion generated from: '<Root>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay1Inport1
    [3] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a;

  /* SignalConversion generated from: '<Root>/Delay2' incorporates:
   *  Constant: '<S10>/Constant1'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator4'
   *  Sum: '<S10>/Add'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_ll
    + 1.0;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g;
  PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE;

  /* Outport: '<Root>/G_Factor' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->G_Factor = rtb_Divide;

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/Constant3'
   *  RelationalOperator: '<S33>/Equal1'
   */
  if (rtb_Sum_o != 0.0) {
    rtb_Switch2_idx_2 = rtb_Sum_o;
  } else {
    rtb_Switch2_idx_2 = 1.0;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Outport: '<Root>/P_Factor' incorporates:
   *  Product: '<S33>/Divide1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->P_Factor =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product / rtb_Switch2_idx_2;

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S35>/Constant3'
   *  RelationalOperator: '<S35>/Equal1'
   */
  if (rtb_Sum_ku != 0.0) {
    rtb_Switch2_idx_2 = rtb_Sum_ku;
  } else {
    rtb_Switch2_idx_2 = 1.0;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Outport: '<Root>/R_Factor' incorporates:
   *  Product: '<S35>/Divide1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->R_Factor =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h / rtb_Switch2_idx_2;

  /* Outport: '<Root>/Filtered_Gaps' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[0] =
    rtb_Switch_juh;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[1] =
    rtb_Switch_pa;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[2] =
    rtb_Switch_my;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Filtered_Gaps[3] =
    rtb_Switch_ka;

  /* Outport: '<Root>/RefPitchOut' incorporates:
   *  Gain: '<S183>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefPitchOut =
    57.295779513082323 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch;

  /* Outport: '<Root>/RefRollOut' incorporates:
   *  Gain: '<S293>/Gain'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->RefRollOut = 57.295779513082323
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll;

  /* Outport: '<Root>/Arms' */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[0] = rtb_Add2_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[1] = rtb_Add1_n;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->Arms[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add;

  /* Outport: '<Root>/CalculatedMass' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Sum: '<S5>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->CalculatedMass =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;

  /* Outport: '<Root>/MMOI' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Sum: '<S5>/Add3'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->Mass;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[1] = rtb_Gain_m;
  PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[2] = rtb_Gain_do;

  /* Sum: '<S5>/Subtract' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  rtb_Switch2_idx_1 -= PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S5>/Subtract'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[0] = (tol -
    rtb_Add4_n) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[0];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1] =
    (rtb_Switch2_idx_0 - rtb_Add1_d) *
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CoMIntegrals[2] *
    rtb_Switch2_idx_1;

  /* Product: '<S5>/Product1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->EMSRollIntegral *
    rtb_Switch2_idx_1;

  /* Step: '<S5>/Step1' incorporates:
   *  Step: '<S5>/Step'
   */
  rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->Timing.t[0];
  if (rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 < 3.0) {
    i = 0;
  } else {
    i = -1;
  }

  /* End of Step: '<S5>/Step1' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant7'
   *  Constant: '<S5>/Constant8'
   *  Step: '<S5>/Step'
   *  Sum: '<S5>/Add5'
   */
  if (!(rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 < 1.0) + i >
      0) {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 =
      PIDcontroller4CoreCentralizedTestReadyMotor_InstP->MotorAGIntegrals;
  } else {
    rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1 = 0.0;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Product: '<S5>/Product2' incorporates:
   *  Gain: '<S5>/Gain'
   *  Sum: '<S4>/Add'
   *  Sum: '<S5>/Add4'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Product2 = (tol + rtb_Add4_n) *
    -rtb_TmpSignalConversionAtCreateDiagonalMatrixInport1_c_idx_1;

  /* Sum: '<S472>/SumI4' incorporates:
   *  Gain: '<S472>/Kb'
   *  Gain: '<S478>/Integral Gain'
   *  Sum: '<S472>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g = (rtb_Sum_pc -
    rtb_Sum_pc) * 0.01 +
    PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP;

  /* Sum: '<S522>/SumI4' incorporates:
   *  Gain: '<S522>/Kb'
   *  Gain: '<S528>/Integral Gain'
   *  Sum: '<S522>/SumI2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k = (rtb_Sum - rtb_Sum) *
    0.01 + PIDcontroller4CoreCentralizedTestReadyMotor_InstP->CurrentIntegralP;

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S22>/Constant4'
   *  Sum: '<S22>/Subtract1'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h5 = (real_T)
    !(rtb_Switch1 - 3.0 != 0.0);
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
  int_T idxDelay;

  /* Update for Delay: '<S22>/Delay1' incorporates:
   *  Outport: '<Root>/Mode'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Mode;

  /* Update for DiscreteIntegrator: '<S531>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S524>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp;

  /* Update for DiscreteIntegrator: '<S481>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S474>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_b;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h5;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;
  for (idxDelay = 0; idxDelay < 1599; idxDelay++) {
    /* Update for Delay: '<S31>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[idxDelay] =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[idxDelay +
      1];

    /* Update for Delay: '<S31>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE[idxDelay] =
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE[idxDelay + 1];
  }

  /* Update for Delay: '<S31>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[1599] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1;

  /* Update for Delay: '<S31>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE[1599] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain;

  /* Update for Sin: '<S31>/Sine Wave4' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave4' */

  /* Update for Sin: '<S31>/Sine Wave5' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave5' */

  /* Update for Sin: '<S31>/Sine Wave6' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave6' */

  /* Update for Sin: '<S31>/Sine Wave7' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave7' */

  /* Update for Sin: '<S31>/Sine Wave1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave1' */

  /* Update for Sin: '<S31>/Sine Wave2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave2' */

  /* Update for Sin: '<S31>/Sine Wave3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n++;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n == 4000) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n = 0;
  }

  /* End of Update for Sin: '<S31>/Sine Wave3' */

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

  /* Update for DiscreteIntegrator: '<S161>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S154>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_f =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_k;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE
    += 0.00025;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_b
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->error_h;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_l
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nl
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S415>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_a =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->DiscreteTimeIntegrator;

  /* Update for Delay: '<S415>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->y_i1;

  /* Update for Delay: '<Root>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [0];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[2] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->TmpSignalConversionAtDelay2Inport1
    [2];

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S5>/Constant'
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

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->OR;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_g
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_d;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_i
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE_l
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState_b
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
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

  /* Update for Delay: '<S184>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan_n;

  /* Update for DiscreteIntegrator: '<S272>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S265>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m;

  /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
    += 0.00025;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_k
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->AND;

  /* Update for DiscreteIntegrator: '<S220>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c += 0.00025
    * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_j;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0 =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;

  /* Update for DiscreteIntegrator: '<S215>/Filter' incorporates:
   *  DiscreteIntegrator: '<S220>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_a;

  /* Update for Delay: '<S294>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan_f;

  /* Update for DiscreteIntegrator: '<S382>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S531>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_o;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S375>/UD' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h;

  /* Update for DiscreteIntegrator: '<S294>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
    += 0.00025;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_g
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->AND_i;

  /* Update for DiscreteIntegrator: '<S330>/Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw +=
    0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_d;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;

  /* Update for DiscreteIntegrator: '<S325>/Filter' incorporates:
   *  DiscreteIntegrator: '<S330>/Integrator'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h += 0.00025 *
    PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k =
    (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_km;

  /* Update for Delay: '<S27>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7;

  /* Update for Delay: '<S27>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4;

  /* Update for Delay: '<S28>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_m =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_h;

  /* Update for Delay: '<S28>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g;

  /* Update for Delay: '<S29>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_i =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e;

  /* Update for Delay: '<S29>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_n;

  /* Update for Delay: '<S30>/Delay3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_o =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_p;

  /* Update for Delay: '<S30>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_f;

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

  (*lastU)[0] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0];
  (*lastU)[1] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1];
  (*lastU)[2] = PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2];

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

  /* Update for DiscreteIntegrator: '<S402>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_j
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for Delay: '<S27>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
  }

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
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[1] =
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
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_au =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c;

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Update for Delay: '<S28>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c;

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_d
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S29>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_l =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_d;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */

  /* Update for Delay: '<S29>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_d;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_e
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_n;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S30>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      >= 1.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 1.0;
  } else if
      (PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
       <= 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 0.0;
  }

  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */

  /* Update for Delay: '<S30>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[0] =
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[1];
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[1] =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_h
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_f;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f < 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f == 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */

  /* Update for Delay: '<S71>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_g =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->GreaterThan;

  /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S71>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_it
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn ==
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S184>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_j
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn ==
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S294>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S294>/Constant2'
   */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_in
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn;
  if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn > 0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
      = (int8_T)1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn <
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
      = (int8_T)-1;
  } else if (PIDcontroller4CoreCentralizedTestReadyMotor_InstP->PropulsionOn ==
             0.0) {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
      = (int8_T)0;
  } else {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
      = (int8_T)2;
  }

  /* End of Update for DiscreteIntegrator: '<S294>/Discrete-Time Integrator' */

  /* Update for Delay: '<S8>/Delay' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add1_l;

  /* Update for Delay: '<S8>/Delay1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_n =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add4;

  /* Update for Delay: '<S8>/Delay2' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_c =
    PIDcontroller4CoreCentralizedTestReadyMotor_B->Add5;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_ll
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator3' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator4' */
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
    += 0.00025 * PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6;
  PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
    = (int8_T)PIDcontroller4CoreCentralizedTestReadyMotor_B->Equal_c;

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
  ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_Y =
    (ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *)
    PIDcontroller4CoreCentralizedTestReadyMotor_M->outputs;
  B_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_B =
    PIDcontroller4CoreCentralizedTestReadyMotor_M->blockIO;

  {
    int32_T i;
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzhe);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_g);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);

    /* Start for MATLABSystem: '<S427>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted
      = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.isInitialized = 0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.NumChannels = -1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.matlabCodegenIsDeleted
      = false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->objisempty = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_SystemCore_setup_o
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage2);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);

    /* Constant: '<S33>/Base Ref Airgap1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

    /* Start for MATLABSystem: '<S184>/Moving Average1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.matlabCodegenIsDeleted
      = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isInitialized = 0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.NumChannels = -1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.matlabCodegenIsDeleted
      = false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->objisempty_i = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isSetupComplete =
      false;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isInitialized = 1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.NumChannels = 1;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b._pobj0.isInitialized =
      0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.pStatistic =
      &PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b._pobj0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isSetupComplete = true;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.TunablePropsChanged =
      false;

    /* Constant: '<S35>/Base Ref Airgap1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);

    /* Start for MATLABSystem: '<S402>/Moving Average' */
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
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Start
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);

    /* Start for DataStoreMemory: '<S405>/DataStoreMemory - P' */
    memcpy(&PIDcontroller4CoreCentralizedTestReadyMotor_DW->P[0],
           &PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled38[0], 36U *
           sizeof(real_T));

    /* Start for DataStoreMemory: '<S405>/DataStoreMemory - x' */
    for (i = 0; i < 6; i++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->x[i] =
        PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled39[i];
    }

    /* End of Start for DataStoreMemory: '<S405>/DataStoreMemory - x' */

    /* Start for DataStoreMemory: '<S414>/DataStoreMemory - P' */
    memcpy(&PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[0],
           &PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled38[0], 36U *
           sizeof(real_T));

    /* Start for DataStoreMemory: '<S414>/DataStoreMemory - x' */
    for (i = 0; i < 6; i++) {
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[i] =
        PIDcontroller4CoreCentralizedTestReadyMotor_ConstP.pooled39[i];
    }

    /* End of Start for DataStoreMemory: '<S414>/DataStoreMemory - x' */

    /* ConstCode for Outport: '<Root>/PIDD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->PIDD = -0.0;

    /* ConstCode for Outport: '<Root>/F_Mismatch' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->F_Mismatch = 0.0;
  }

  {
    c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
      *obj;
    c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
      *obj_0;
    int32_T i;

    /* InitializeConditions for Delay: '<S22>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S531>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S524>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S481>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_j = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_b =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S474>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_p = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscretePulseGenerator: '<S31>/Pulse Generator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->clockTickCounter = 0;
    for (i = 0; i < 1600; i++) {
      /* InitializeConditions for Delay: '<S31>/Delay1' */
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[i] = 0.0;

      /* InitializeConditions for Delay: '<S31>/Delay' */
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE[i] = 0.0;
    }

    /* InitializeConditions for Sin: '<S31>/Sine Wave4' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave5' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_h = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave6' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_o = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave7' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_a = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_i = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_m = 0;

    /* InitializeConditions for Sin: '<S31>/Sine Wave3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->counter_n = 0;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_ez[3] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_jc = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_n =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S154>/UD' */
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
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nl
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_h
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S415>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_a = 0.0;

    /* InitializeConditions for Delay: '<S415>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d = 0.0;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[2] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_p
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_h
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_i
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_PrevResetState_b
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
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

    /* InitializeConditions for Delay: '<S184>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_o = false;

    /* InitializeConditions for DiscreteIntegrator: '<S272>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S265>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_k
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S220>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_g0
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S215>/Filter' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_j =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S294>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_m = false;

    /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_m =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S375>/UD' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S294>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_g
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S330>/Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_PrevResetState_ns
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S325>/Filter' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_PrevResetState_k =
      (int8_T)2;

    /* InitializeConditions for Delay: '<S27>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE = 0.0;

    /* InitializeConditions for Delay: '<S27>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_m = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_i = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_o = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo = 0.0;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA = (rtInf);
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampA_l = (rtInf);
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->TimeStampB_b = (rtInf);

    /* InitializeConditions for DiscreteIntegrator: '<S402>/Discrete-Time Integrator' */
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
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_au = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_n2
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_d
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_f
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S29>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_l = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_hw
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_e
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_d
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S30>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_b
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[0] = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[0] = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[0] = 0.0;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[1] = 0.0;

    /* InitializeConditions for Delay: '<S28>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] = 0.0;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[1] = 0.0;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[1] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_h
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_m
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S71>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_g = false;

    /* InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_it
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_l
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_j
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_nr
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S294>/Discrete-Time Integrator' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_in
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_PrevResetState_ns
      = (int8_T)2;

    /* InitializeConditions for Delay: '<S8>/Delay' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_c = 0.0;

    /* InitializeConditions for Delay: '<S8>/Delay1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_n = 0.0;

    /* InitializeConditions for Delay: '<S8>/Delay2' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_c = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_ll
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_PrevResetState_o
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator3' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_PrevResetState_f
      = (int8_T)2;

    /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator4' */
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator4_PrevResetState
      = (int8_T)2;

    /* SystemInitialize for Enabled SubSystem: '<S414>/Correct1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1_l);

    /* End of SystemInitialize for SubSystem: '<S414>/Correct1' */

    /* SystemInitialize for Enabled SubSystem: '<S414>/Correct2' */
    /* SystemInitialize for Outport: '<S417>/yBlockOrdering' */
    PIDcontroller4CoreCentralizedTestReadyMotor_B->blockOrdering = false;

    /* End of SystemInitialize for SubSystem: '<S414>/Correct2' */

    /* SystemInitialize for Enabled SubSystem: '<S405>/Correct1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_B->Correct1);

    /* End of SystemInitialize for SubSystem: '<S405>/Correct1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzhe);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_g);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);

    /* InitializeConditions for MATLABSystem: '<S427>/Moving Average' */
    obj = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_i.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pwN = 1.0;
      obj->pmN[0] = 0.0;
      obj->pmN[1] = 0.0;
      obj->pmN[2] = 0.0;
      obj->pmN[3] = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S427>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage2);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

    /* InitializeConditions for MATLABSystem: '<S184>/Moving Average1' */
    obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 3999; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S184>/Moving Average1' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);

    /* InitializeConditions for MATLABSystem: '<S402>/Moving Average' */
    obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 3999; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S402>/Moving Average' */
    PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Init
      (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);
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
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *obj_0;
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_p);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pn);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pna);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnae);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaev);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfp);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevv);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpg);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvf);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5z);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zz);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_e);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_n);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5zzhe);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_f);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_g);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_k);

  /* Terminate for MATLABSystem: '<S427>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S427>/Moving Average' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage2);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_h);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_kw);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_ka);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_pnaevvfpgh5zzhe);

  /* Terminate for MATLABSystem: '<S184>/Moving Average1' */
  if (!(int32_T)
      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.matlabCodegenIsDeleted)
  {
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.matlabCodegenIsDeleted
      = true;
    if ((PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isInitialized ==
         1) && ((int32_T)
                PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.isSetupComplete))
    {
      obj_0 = PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      PIDcontroller4CoreCentralizedTestReadyMotor_DW->obj_b.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S184>/Moving Average1' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage_c);
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfpgh5z);

  /* Terminate for MATLABSystem: '<S402>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<S402>/Moving Average' */
  PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Term
    (&PIDcontroller4CoreCentralizedTestReadyMotor_DW->MovingAverage1_pnaevvfp);
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
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_c[i] = 0.0;
      }

      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_p[i] = 0.0;
      }

      for (i = 0; i < 30; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Flip1_o[i] = 0.0;
      }

      for (i = 0; i < 6; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Output_n.DataStoreRead[i]
          = 0.0;
      }

      for (i = 0; i < 6; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_B->Output.DataStoreRead[i] =
          0.0;
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
      PIDcontroller4CoreCentralizedTestReadyMotor_B->DiscreteTimeIntegrator =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->y_i1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_n[3] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gravity = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch1_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add1_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Add5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tom_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tomm_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_g[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->error = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Divide1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_m = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointpitch = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract5_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch_p = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Tsamp_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->setpointroll = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->NProdOut_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_ot = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_b = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Max_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract4_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch2_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Sum1 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_i = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_b = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_o = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_a = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_h = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_m = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_e = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_f = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch4_f = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch6_b = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_p = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch5_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch7_p = 0.0;
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
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay_m = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay1_j = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Delay2_n = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain1_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_d = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain3 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Saturation = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain2_c = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain5 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Gain6 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Subtract = 0.0;
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
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product_i[2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product1_l = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Product2 = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_g = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->SumI4_k = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->Switch3_h5 = 0.0;
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
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_g.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_k.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzhe.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_f.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zzh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_n.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5zz.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_e.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5z.MovingAverage
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [0] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [1] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_c.MovingAverage
        [2] = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage2.MovingAverage1
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh5.MovingAverage1
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfpgh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzhe.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zzh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvfp.MovingAverage1
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.avg_g =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.pitch =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates_d.roll =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5zz.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5z.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh5.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevvf.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpgh.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaevv.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfpg.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnaev.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvfp.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pnae.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevvf.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.avg_g =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.pitch =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->sf_FindCoordinates.roll =
        0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaevv.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnaev.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pnae.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pna.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pna.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_pn.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_pn.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1_p.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage_p.MovingAverage
        = 0.0;
      PIDcontroller4CoreCentralizedTestReadyMotor_B->MovingAverage1.MovingAverage
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

    {
      int32_T i;
      for (i = 0; i < 1600; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_e[i] = 0.0;
      }
    }

    {
      int32_T i;
      for (i = 0; i < 1600; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE[i] = 0.0;
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
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_a
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_a = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator3_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_p
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_k
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator2_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_o
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_n = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_o = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_b
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_i = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lg = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->UD_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_l
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Integrator_DSTATE_lw = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Filter_DSTATE_h = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_m = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_b = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_i = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay3_DSTATE_o = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_bo = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_i
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_g
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_d0[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_c
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_au = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_h
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_e[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_d
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_l = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_gr
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_i[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_e
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_g = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_op
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_k[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_h
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_it
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_j
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator_DSTATE_in
      = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay1_DSTATE_n = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->Delay2_DSTATE_c = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_DW->DiscreteTimeIntegrator1_DSTATE_ll
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

    {
      int32_T i;
      for (i = 0; i < 36; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->P_h[i] = 0.0;
      }
    }

    {
      int32_T i;
      for (i = 0; i < 6; i++) {
        PIDcontroller4CoreCentralizedTestReadyMotor_DW->x_n[i] = 0.0;
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
    PIDcontroller4CoreCentralizedTestReadyMotor_U->LS_mode = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_z = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_pitch = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_U->IMU_roll = 0.0;

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
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->MotorAGAdjust = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->IMU_kalman_output[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->MMOI[2] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->PIDD = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->F_Mismatch = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[0] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[1] = 0.0;
    PIDcontroller4CoreCentralizedTestReadyMotor_Y->Kalman_Output[2] = 0.0;

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
