/*
 * PIDcontroller4CoreCentralizedTestReadyMotor_types.h
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

#ifndef RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_types_h_
#define RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_types_h_
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

#ifndef typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
#define typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T

typedef struct tag_exMDxz3Pb2GQFd4LoM3MEF
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

#endif
/* typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T
#define typedef_cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T;

#endif     /* typedef_cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T */

#ifndef struct_tag_wcQblj24YHhNa9ubUPc1MC
#define struct_tag_wcQblj24YHhNa9ubUPc1MC

struct tag_wcQblj24YHhNa9ubUPc1MC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T inputVarSize[2];
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    _pobj0;
};

#endif                                 /* struct_tag_wcQblj24YHhNa9ubUPc1MC */

#ifndef typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
#define typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T

typedef struct tag_wcQblj24YHhNa9ubUPc1MC
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

#endif
/* typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T */

#ifndef struct_tag_oNML0yXaLdzzprxo6lWyjD
#define struct_tag_oNML0yXaLdzzprxo6lWyjD

struct tag_oNML0yXaLdzzprxo6lWyjD
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3999];
  real_T pCumRevIndex;
};

#endif                                 /* struct_tag_oNML0yXaLdzzprxo6lWyjD */

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T

typedef struct tag_oNML0yXaLdzzprxo6lWyjD
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T;

#endif
/* typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T */

#ifndef struct_tag_kbilpLwfaLlRnpRAwxOaOF
#define struct_tag_kbilpLwfaLlRnpRAwxOaOF

struct tag_kbilpLwfaLlRnpRAwxOaOF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_T
    _pobj0;
};

#endif                                 /* struct_tag_kbilpLwfaLlRnpRAwxOaOF */

#ifndef typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T
#define typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T

typedef struct tag_kbilpLwfaLlRnpRAwxOaOF
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T;

#endif
/* typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T */

#ifndef struct_tag_yisOdoARUpGNKHDiLfyTVG
#define struct_tag_yisOdoARUpGNKHDiLfyTVG

struct tag_yisOdoARUpGNKHDiLfyTVG
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[999];
  real_T pCumRevIndex;
};

#endif                                 /* struct_tag_yisOdoARUpGNKHDiLfyTVG */

#ifndef typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
#define typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T

typedef struct tag_yisOdoARUpGNKHDiLfyTVG
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T;

#endif
/* typedef_c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T */

#ifndef struct_tag_jWjnTAWDw8p7EyVA8rvPLF
#define struct_tag_jWjnTAWDw8p7EyVA8rvPLF

struct tag_jWjnTAWDw8p7EyVA8rvPLF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T inputVarSize;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
    *pStatistic;
  int32_T NumChannels;
  c_dsp_private_SlidingWindowAverageCG_PIDcontroller4CoreCentralizedTestReadyMotor_n_T
    _pobj0;
};

#endif                                 /* struct_tag_jWjnTAWDw8p7EyVA8rvPLF */

#ifndef typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T
#define typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T

typedef struct tag_jWjnTAWDw8p7EyVA8rvPLF
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T;

#endif
/* typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T */

#ifndef struct_tag_H13tmzM6XzHD6H2GNsHxeD
#define struct_tag_H13tmzM6XzHD6H2GNsHxeD

struct tag_H13tmzM6XzHD6H2GNsHxeD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T inputVarSize;
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    _pobj0;
};

#endif                                 /* struct_tag_H13tmzM6XzHD6H2GNsHxeD */

#ifndef typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3x_T
#define typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3x_T

typedef struct tag_H13tmzM6XzHD6H2GNsHxeD
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3x_T;

#endif
/* typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3x_T */

#ifndef struct_tag_9kf6zCdkeEb92izkAONXwH
#define struct_tag_9kf6zCdkeEb92izkAONXwH

struct tag_9kf6zCdkeEb92izkAONXwH
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN[4];
  real_T plambda;
};

#endif                                 /* struct_tag_9kf6zCdkeEb92izkAONXwH */

#ifndef typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
#define typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T

typedef struct tag_9kf6zCdkeEb92izkAONXwH
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T;

#endif
/* typedef_c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T */

#ifndef struct_tag_J1PLg0AH15F0TpD1DWRs5C
#define struct_tag_J1PLg0AH15F0TpD1DWRs5C

struct tag_J1PLg0AH15F0TpD1DWRs5C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_PIDcontroller4CoreCentralizedTestReadyMotor_T inputVarSize[2];
  real_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    _pobj0;
};

#endif                                 /* struct_tag_J1PLg0AH15F0TpD1DWRs5C */

#ifndef typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
#define typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T

typedef struct tag_J1PLg0AH15F0TpD1DWRs5C
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T;

#endif
/* typedef_dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_PIDcontroller4CoreCentralizedTestReadyMotor_T
  RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T;

#endif     /* RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_types_h_ */
