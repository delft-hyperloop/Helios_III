/*
 * TemplateLaserSensorsFull_types.h
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

#ifndef RTW_HEADER_TemplateLaserSensorsFull_types_h_
#define RTW_HEADER_TemplateLaserSensorsFull_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_dxzJ4cFi6d5TncbGE46u2C
#define struct_tag_dxzJ4cFi6d5TncbGE46u2C

struct tag_dxzJ4cFi6d5TncbGE46u2C
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[7999];
  real_T pCumRevIndex;
};

#endif                                 /* struct_tag_dxzJ4cFi6d5TncbGE46u2C */

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T

typedef struct tag_dxzJ4cFi6d5TncbGE46u2C
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T;

#endif
   /* typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_TemplateLaserSensorsFull_T
#define typedef_cell_wrap_TemplateLaserSensorsFull_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_TemplateLaserSensorsFull_T;

#endif                        /* typedef_cell_wrap_TemplateLaserSensorsFull_T */

#ifndef struct_tag_UDKDp3vse1c9wb5qvJGrWG
#define struct_tag_UDKDp3vse1c9wb5qvJGrWG

struct tag_UDKDp3vse1c9wb5qvJGrWG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_TemplateLaserSensorsFull_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T _pobj0;
};

#endif                                 /* struct_tag_UDKDp3vse1c9wb5qvJGrWG */

#ifndef typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_T
#define typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_T

typedef struct tag_UDKDp3vse1c9wb5qvJGrWG
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_T;

#endif       /* typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_T */

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

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T

typedef struct tag_wF0FRePRqwb1KERDRGXJOB
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T;

#endif
/* typedef_c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T */

#ifndef struct_tag_FsmzB1ZuAHwoRkOFQx86U
#define struct_tag_FsmzB1ZuAHwoRkOFQx86U

struct tag_FsmzB1ZuAHwoRkOFQx86U
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_TemplateLaserSensorsFull_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_n_T _pobj0;
};

#endif                                 /* struct_tag_FsmzB1ZuAHwoRkOFQx86U */

#ifndef typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e_T
#define typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e_T

typedef struct tag_FsmzB1ZuAHwoRkOFQx86U
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e_T;

#endif     /* typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e_T */

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

#ifndef typedef_c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T
#define typedef_c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T

typedef struct tag_exMDxz3Pb2GQFd4LoM3MEF
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T;

#endif
/* typedef_c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T */

#ifndef struct_tag_H13tmzM6XzHD6H2GNsHxeD
#define struct_tag_H13tmzM6XzHD6H2GNsHxeD

struct tag_H13tmzM6XzHD6H2GNsHxeD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_TemplateLaserSensorsFull_T inputVarSize;
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T _pobj0;
};

#endif                                 /* struct_tag_H13tmzM6XzHD6H2GNsHxeD */

#ifndef typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T
#define typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T

typedef struct tag_H13tmzM6XzHD6H2GNsHxeD
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T;

#endif    /* typedef_dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_TemplateLaserSensorsFull_T
  RT_MODEL_TemplateLaserSensorsFull_T;

#endif                        /* RTW_HEADER_TemplateLaserSensorsFull_types_h_ */
