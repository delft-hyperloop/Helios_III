/*
 * PIDcontroller4CoreCentralizedTestReadyMotor_private.h
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

#ifndef RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_private_h_
#define RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "PIDcontroller4CoreCentralizedTestReadyMotor.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 rtmSetErrorStatus(PIDcontroller4CoreCentralizedTestReadyMotor_M, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T look2_pbinlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], uint32_T prevIndex[], const uint32_T
  maxIndex[], uint32_T stride);
extern real_T look1_pbinlgpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
extern real_T intrp2d_l_pw(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride);
extern uint32_T plook_binxp(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex);
extern uint32_T plook_binxpg(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex);
extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
extern uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage(real_T rtu_0,
  real_T rtu_1, B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *localB, DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates(real_T rtu_z,
  real_T rtu_z_b, real_T rtu_z_l, real_T rtu_z_j, real_T rtu_hl, real_T rtu_hw,
  real_T rtu_l_offset,
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Init
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Start
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1(real_T rtu_0,
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB,
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_n_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_i_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_p(real_T rtu_0,
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T *localB,
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Init
  (B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB);
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1(boolean_T rtu_Enable,
  const real_T rtu_yMeas[3], const real_T rtu_R[9], boolean_T rtu_uBlockOrdering,
  real_T rtd_P[36], real_T rtd_x[6],
  B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB);
void PIDcontroller4CoreCentralizedTestReadyMotor_Output(boolean_T
  rtu_uBlockOrdering, const real_T rtd_x[6],
  B_Output_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB);
void PIDcontroller4CoreCentralizedTestReadyMotor_Predict(const real_T rtu_Q[36],
  const real_T rtu_uState[12], real_T rtd_P[36], real_T rtd_x[6]);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_e_Init
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_m_Start
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_pn(const real_T
  rtu_0[3], B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
  *localB, DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
  *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1(real_T
  rtu_measured_I, real_T rtu_requested_I, real_T rtu_max_delta,
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localB);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_FindCoordinates_Term(void);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage1_Term
  (DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_j_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_Correct1_Term(void);
void PIDcontroller4CoreCentralizedTestReadyMotor_Output_Term(void);
void PIDcontroller4CoreCentralizedTestReadyMotor_Predict_Term(void);
void PIDcontroller4CoreCentralizedTestReadyMotor_MovingAverage_l_Term
  (DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T *localDW);
void PIDcontroller4CoreCentralizedTestReadyMotor_Caprequestedcurrent1_Term(void);

#endif   /* RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_private_h_ */
