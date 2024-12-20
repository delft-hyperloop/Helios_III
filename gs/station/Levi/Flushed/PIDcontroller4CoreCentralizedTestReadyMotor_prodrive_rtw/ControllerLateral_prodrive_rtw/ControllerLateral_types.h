/*
 * ControllerLateral_types.h
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

#ifndef RTW_HEADER_ControllerLateral_types_h_
#define RTW_HEADER_ControllerLateral_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef struct_tag_exMDxz3Pb2GQFd4LoM3MEF
#define struct_tag_exMDxz3Pb2GQFd4LoM3MEF

struct tag_exMDxz3Pb2GQFd4LoM3MEF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
};

#endif                                 /* struct_tag_exMDxz3Pb2GQFd4LoM3MEF */

#ifndef typedef_c_dsp_private_ExponentialMovingAverage_ControllerLateral_T
#define typedef_c_dsp_private_ExponentialMovingAverage_ControllerLateral_T

typedef struct tag_exMDxz3Pb2GQFd4LoM3MEF
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T;

#endif  /* typedef_c_dsp_private_ExponentialMovingAverage_ControllerLateral_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_ControllerLateral_T
#define typedef_cell_wrap_ControllerLateral_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_ControllerLateral_T;

#endif                               /* typedef_cell_wrap_ControllerLateral_T */

#ifndef struct_tag_wcQblj24YHhNa9ubUPc1MC
#define struct_tag_wcQblj24YHhNa9ubUPc1MC

struct tag_wcQblj24YHhNa9ubUPc1MC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ControllerLateral_T inputVarSize[2];
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T _pobj0;
};

#endif                                 /* struct_tag_wcQblj24YHhNa9ubUPc1MC */

#ifndef typedef_dsp_simulink_MovingAverage_ControllerLateral_T
#define typedef_dsp_simulink_MovingAverage_ControllerLateral_T

typedef struct tag_wcQblj24YHhNa9ubUPc1MC
  dsp_simulink_MovingAverage_ControllerLateral_T;

#endif              /* typedef_dsp_simulink_MovingAverage_ControllerLateral_T */

#ifndef struct_tag_H13tmzM6XzHD6H2GNsHxeD
#define struct_tag_H13tmzM6XzHD6H2GNsHxeD

struct tag_H13tmzM6XzHD6H2GNsHxeD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ControllerLateral_T inputVarSize;
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_ControllerLateral_T _pobj0;
};

#endif                                 /* struct_tag_H13tmzM6XzHD6H2GNsHxeD */

#ifndef typedef_dsp_simulink_MovingAverage_ControllerLateral_e_T
#define typedef_dsp_simulink_MovingAverage_ControllerLateral_e_T

typedef struct tag_H13tmzM6XzHD6H2GNsHxeD
  dsp_simulink_MovingAverage_ControllerLateral_e_T;

#endif            /* typedef_dsp_simulink_MovingAverage_ControllerLateral_e_T */

#ifndef struct_tag_2803fWPGKBjzzsFVzgNw5E
#define struct_tag_2803fWPGKBjzzsFVzgNw5E

struct tag_2803fWPGKBjzzsFVzgNw5E
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[499];
  real_T pCumRevIndex;
};

#endif                                 /* struct_tag_2803fWPGKBjzzsFVzgNw5E */

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T

typedef struct tag_2803fWPGKBjzzsFVzgNw5E
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T;

#endif    /* typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T */

#ifndef struct_tag_ebsv9rqyK1ClrFfq2SZdaD
#define struct_tag_ebsv9rqyK1ClrFfq2SZdaD

struct tag_ebsv9rqyK1ClrFfq2SZdaD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ControllerLateral_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_T _pobj0;
};

#endif                                 /* struct_tag_ebsv9rqyK1ClrFfq2SZdaD */

#ifndef typedef_dsp_simulink_MovingAverage_ControllerLateral_e3_T
#define typedef_dsp_simulink_MovingAverage_ControllerLateral_e3_T

typedef struct tag_ebsv9rqyK1ClrFfq2SZdaD
  dsp_simulink_MovingAverage_ControllerLateral_e3_T;

#endif           /* typedef_dsp_simulink_MovingAverage_ControllerLateral_e3_T */

#ifndef struct_tag_wF0FRePRqwb1KERDRGXJOB
#define struct_tag_wF0FRePRqwb1KERDRGXJOB

struct tag_wF0FRePRqwb1KERDRGXJOB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[1999];
  real_T pCumRevIndex;
};

#endif                                 /* struct_tag_wF0FRePRqwb1KERDRGXJOB */

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T

typedef struct tag_wF0FRePRqwb1KERDRGXJOB
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T;

#endif  /* typedef_c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T */

#ifndef struct_tag_FsmzB1ZuAHwoRkOFQx86U
#define struct_tag_FsmzB1ZuAHwoRkOFQx86U

struct tag_FsmzB1ZuAHwoRkOFQx86U
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ControllerLateral_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_ControllerLateral_h_T _pobj0;
};

#endif                                 /* struct_tag_FsmzB1ZuAHwoRkOFQx86U */

#ifndef typedef_dsp_simulink_MovingAverage_ControllerLateral_h_T
#define typedef_dsp_simulink_MovingAverage_ControllerLateral_h_T

typedef struct tag_FsmzB1ZuAHwoRkOFQx86U
  dsp_simulink_MovingAverage_ControllerLateral_h_T;

#endif            /* typedef_dsp_simulink_MovingAverage_ControllerLateral_h_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_ControllerLateral_T RT_MODEL_ControllerLateral_T;

#endif                               /* RTW_HEADER_ControllerLateral_types_h_ */
