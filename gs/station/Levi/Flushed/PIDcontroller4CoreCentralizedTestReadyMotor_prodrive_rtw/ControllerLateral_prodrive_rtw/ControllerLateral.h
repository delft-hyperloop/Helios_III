/*
 * ControllerLateral.h
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

#ifndef RTW_HEADER_ControllerLateral_h_
#define RTW_HEADER_ControllerLateral_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ControllerLateral_COMMON_INCLUDES_
#define ControllerLateral_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ControllerLateral_COMMON_INCLUDES_ */

#include "ControllerLateral_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetControllerLateral_InstP_ref
#define rtmGetControllerLateral_InstP_ref(rtm) ((rtm)->ControllerLateral_InstP_ref)
#endif

#ifndef rtmSetControllerLateral_InstP_ref
#define rtmSetControllerLateral_InstP_ref(rtm, val) ((rtm)->ControllerLateral_InstP_ref = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define ControllerLateral_M_TYPE       RT_MODEL_ControllerLateral_T

/* Block signals for system '<S22>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S22>/Moving Average' */
} B_MovingAverage_ControllerLateral_T;

/* Block states (default storage) for system '<S22>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_T obj;/* '<S22>/Moving Average' */
  boolean_T objisempty;                /* '<S22>/Moving Average' */
} DW_MovingAverage_ControllerLateral_T;

/* Block signals for system '<S27>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S27>/Moving Average' */
} B_MovingAverage_ControllerLateral_c_T;

/* Block states (default storage) for system '<S27>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_e_T obj;/* '<S27>/Moving Average' */
  boolean_T objisempty;                /* '<S27>/Moving Average' */
} DW_MovingAverage_ControllerLateral_f_T;

/* Block signals for system '<S27>/Moving Average1' */
typedef struct {
  real_T MovingAverage1;               /* '<S27>/Moving Average1' */
} B_MovingAverage1_ControllerLateral_T;

/* Block states (default storage) for system '<S27>/Moving Average1' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_e3_T obj;/* '<S27>/Moving Average1' */
  boolean_T objisempty;                /* '<S27>/Moving Average1' */
} DW_MovingAverage1_ControllerLateral_T;

/* Block signals (default storage) */
typedef struct {
  real_T Tsamp;                        /* '<S163>/Tsamp' */
  real_T Product1;                     /* '<S16>/Product1' */
  real_T NProdOut;                     /* '<S64>/NProd Out' */
  real_T Tsamp_c;                      /* '<S214>/Tsamp' */
  real_T NProdOut_k;                   /* '<S116>/NProd Out' */
  real_T Delay1;                       /* '<S14>/Delay1' */
  real_T Delay;                        /* '<S14>/Delay' */
  real_T Switch4;                      /* '<S14>/Switch4' */
  real_T Switch3;                      /* '<S14>/Switch3' */
  real_T Switch5;                      /* '<S14>/Switch5' */
  real_T Delay1_f;                     /* '<S15>/Delay1' */
  real_T Delay_d;                      /* '<S15>/Delay' */
  real_T Switch4_b;                    /* '<S15>/Switch4' */
  real_T Switch3_m;                    /* '<S15>/Switch3' */
  real_T Switch5_e;                    /* '<S15>/Switch5' */
  real_T Switch;                       /* '<S52>/Switch' */
  real_T Switch_a;                     /* '<S104>/Switch' */
  real_T SumI4;                        /* '<S159>/SumI4' */
  real_T SumI4_e;                      /* '<S210>/SumI4' */
  real_T Gain2;                        /* '<S337>/Gain2' */
  real_T Gain9;                        /* '<S338>/Gain9' */
  real_T Gain10;                       /* '<S346>/Gain10' */
  real_T Gain3_i;                      /* '<S337>/Gain3' */
  real_T Gain10_c;                     /* '<S345>/Gain10' */
  real_T FilterCoefficient;            /* '<S437>/Filter Coefficient' */
  real_T Add;                          /* '<S338>/Add' */
  real_T FilterCoefficient_d;          /* '<S387>/Filter Coefficient' */
  real_T Add1;                         /* '<S338>/Add1' */
  real_T Switch_b;                     /* '<S375>/Switch' */
  real_T Switch_bb;                    /* '<S425>/Switch' */
  real_T Gain10_o;                     /* '<S451>/Gain10' */
  real_T Gain10_o4;                    /* '<S452>/Gain10' */
  real_T FilterCoefficient_l;          /* '<S493>/Filter Coefficient' */
  real_T Add1_b;                       /* '<S339>/Add1' */
  real_T Switch_g;                     /* '<S481>/Switch' */
  real_T TmpSignalConversionAtDelay2Inport1[2];/* '<Root>/Array interpolation' */
  real_T TmpSignalConversionAtDelay1Inport1[2];
  real_T Gain_f;                       /* '<S4>/Gain' */
  real_T FilterCoefficient_b;          /* '<S323>/Filter Coefficient' */
  real_T Add_j;                        /* '<S4>/Add' */
  real_T Add_h[3];                     /* '<S257>/Add' */
  real_T IntegralGain;                 /* '<S317>/Integral Gain' */
  real_T Switch3_h;                    /* '<S9>/Switch3' */
  real_T SNew[9];           /* '<S238>/Discrete-Time SqrtKF - Calculate SLMZ' */
  boolean_T OR;                        /* '<S9>/OR' */
  boolean_T Equal;                     /* '<S9>/Equal' */
  boolean_T OR_h;                      /* '<S130>/OR' */
  boolean_T Equal_p;                   /* '<S17>/Equal' */
  boolean_T Equal_b;                   /* '<S18>/Equal' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfpg;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfp;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpg;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvf;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfp;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevv;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvf;/* '<S22>/Moving Average' */
  B_MovingAverage1_ControllerLateral_T MovingAverage1_pnaev;/* '<S27>/Moving Average1' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaev;/* '<S27>/Moving Average' */
  B_MovingAverage1_ControllerLateral_T MovingAverage1_pnae;/* '<S27>/Moving Average1' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnae;/* '<S27>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pna;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pna;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pn;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pn;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_p;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_p;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage;/* '<S22>/Moving Average' */
} B_ControllerLateral_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_h_T obj;/* '<S12>/Moving Average' */
  dsp_simulink_MovingAverage_ControllerLateral_e_T obj_a;/* '<S4>/Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S339>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S338>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S338>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE[2];             /* '<Root>/Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S134>/Delay Input1' */
  real_T Integrator_DSTATE;            /* '<S168>/Integrator' */
  real_T UD_DSTATE;                    /* '<S161>/UD' */
  real_T Delay1_DSTATE_b[800];         /* '<S16>/Delay1' */
  real_T Integrator_DSTATE_n;          /* '<S61>/Integrator' */
  real_T Filter_DSTATE;                /* '<S56>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S219>/Integrator' */
  real_T UD_DSTATE_o;                  /* '<S212>/UD' */
  real_T Integrator_DSTATE_m;          /* '<S113>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S108>/Filter' */
  real_T Delay2_DSTATE;                /* '<S15>/Delay2' */
  real_T Delay2_DSTATE_i;              /* '<S14>/Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S12>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE_f;              /* '<S14>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S14>/Discrete-Time Integrator' */
  real_T Delay_DSTATE[2];              /* '<S14>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_b;/* '<S14>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_j;              /* '<S15>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S15>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_g[2];            /* '<S15>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_n;/* '<S15>/Discrete-Time Integrator1' */
  real_T Delay2_DSTATE_f[2];           /* '<Root>/Delay2' */
  real_T Integrator_DSTATE_nb;         /* '<S434>/Integrator' */
  real_T Filter_DSTATE_l;              /* '<S429>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S384>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S379>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S490>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S485>/Filter' */
  real_T MemoryP_DSTATE[9];            /* '<S236>/MemoryP' */
  real_T MemoryX_DSTATE[3];            /* '<S236>/MemoryX' */
  real_T DiscreteTimeIntegrator_DSTATE_l4;/* '<S4>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S4>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S4>/Discrete-Time Integrator3' */
  real_T Integrator_DSTATE_nh;         /* '<S320>/Integrator' */
  real_T Filter_DSTATE_i4;             /* '<S315>/Filter' */
  real_T Memory_PreviousInput;         /* '<S346>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S346>/Memory1' */
  real_T Memory_PreviousInput_k;       /* '<S345>/Memory' */
  real_T Memory1_PreviousInput_n;      /* '<S345>/Memory1' */
  real_T Memory_PreviousInput_l;       /* '<S451>/Memory' */
  real_T Memory1_PreviousInput_d;      /* '<S451>/Memory1' */
  real_T Memory_PreviousInput_d;       /* '<S452>/Memory' */
  real_T Memory1_PreviousInput_g;      /* '<S452>/Memory1' */
  real_T mode_old;                     /* '<Root>/Lane Switch Transition1' */
  real_T t_old;                        /* '<Root>/Lane Switch Transition1' */
  real_T mode_memory_old;              /* '<Root>/Lane Switch Transition1' */
  int32_T clockTickCounter;            /* '<S16>/Pulse Generator' */
  int32_T counter;                     /* '<S16>/Sine Wave1' */
  int32_T counter_k;                   /* '<S16>/Sine Wave2' */
  uint32_T m_bpIndex[15];              /* '<S15>/2-D Lookup Table2' */
  uint32_T m_Cache01[14];              /* '<S15>/2-D Lookup Table2' */
  uint32_T m_Cache02;                  /* '<S15>/2-D Lookup Table2' */
  uint32_T m_bpIndex_m;                /* '<S15>/2-D Lookup Table1' */
  uint32_T m_bpIndex_o[15];            /* '<S14>/2-D Lookup Table2' */
  uint32_T m_Cache01_k[14];            /* '<S14>/2-D Lookup Table2' */
  uint32_T m_Cache02_m;                /* '<S14>/2-D Lookup Table2' */
  uint32_T m_bpIndex_i;                /* '<S14>/2-D Lookup Table1' */
  uint32_T m_bpIndex_g[2];             /* '<S15>/2-D Lookup Table3' */
  uint32_T m_bpIndex_ge[2];            /* '<S14>/2-D Lookup Table3' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S133>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S339>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S338>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_l;/* '<S338>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S168>/Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S61>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S56>/Filter' */
  int8_T Integrator_PrevResetState_m;  /* '<S219>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S113>/Integrator' */
  int8_T Filter_PrevResetState_j;      /* '<S108>/Filter' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_a;/* '<S14>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_j;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_o;/* '<S15>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_e;/* '<S4>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator2_PrevResetState;/* '<S4>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator3_PrevResetState;/* '<S4>/Discrete-Time Integrator3' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S339>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOADING;/* '<S338>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_n;/* '<S338>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_k;/* '<S4>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator2_IC_LOADING;/* '<S4>/Discrete-Time Integrator2' */
  uint8_T DiscreteTimeIntegrator3_IC_LOADING;/* '<S4>/Discrete-Time Integrator3' */
  boolean_T Memory_PreviousInput_dc;   /* '<S9>/Memory' */
  boolean_T icLoad;                    /* '<S236>/MemoryP' */
  boolean_T icLoad_m;                  /* '<S236>/MemoryX' */
  boolean_T objisempty;                /* '<S12>/Moving Average' */
  boolean_T mode_old_not_empty;        /* '<Root>/Lane Switch Transition1' */
  boolean_T objisempty_l;              /* '<S4>/Moving Average' */
  boolean_T EnabledSubsystem_MODE;     /* '<S264>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S257>/MeasurementUpdate' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfpg;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfp;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpg;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvf;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfp;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevv;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvf;/* '<S22>/Moving Average' */
  DW_MovingAverage1_ControllerLateral_T MovingAverage1_pnaev;/* '<S27>/Moving Average1' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaev;/* '<S27>/Moving Average' */
  DW_MovingAverage1_ControllerLateral_T MovingAverage1_pnae;/* '<S27>/Moving Average1' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnae;/* '<S27>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pna;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pna;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pn;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pn;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_p;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_p;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage;/* '<S22>/Moving Average' */
} DW_ControllerLateral_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState UD_Reset_ZCE;             /* '<S161>/UD' */
  ZCSigState UD_Reset_ZCE_d;           /* '<S212>/UD' */
} PrevZCX_ControllerLateral_T;

/* instance parameters, for system '<Root>' */
typedef struct {
  real_T LateralOffsetsHEMSMotor[5];   /* Variable: LateralOffsetsHEMSMotor
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T LateralSineSwitches[2];       /* Variable: LateralSineSwitches
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T ReferenceLateralOffsets[2];   /* Variable: ReferenceLateralOffsets
                                        * Referenced by: '<S19>/Setpoint'
                                        */
  real_T BackGain;                     /* Variable: BackGain
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T BeamErrorTime;                /* Variable: BeamErrorTime
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  real_T CurrentIntegralLat;           /* Variable: CurrentIntegralLat
                                        * Referenced by:
                                        *   '<S165>/Integral Gain'
                                        *   '<S216>/Integral Gain'
                                        */
  real_T FrontGain;                    /* Variable: FrontGain
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T LS_curved_AG;                 /* Variable: LS_curved_AG
                                        * Referenced by:
                                        *   '<S344>/Mode 1 AG4'
                                        *   '<S344>/Mode 1 AG5'
                                        */
  real_T LS_mode;                      /* Variable: LS_mode
                                        * Referenced by:
                                        *   '<Root>/Constant2'
                                        *   '<Root>/Constant5'
                                        *   '<Root>/Lane Switch Mode'
                                        *   '<S337>/Constant'
                                        *   '<S337>/Constant4'
                                        *   '<S27>/Constant6'
                                        *   '<S79>/Constant6'
                                        */
  real_T LS_signal;                    /* Variable: LS_signal
                                        * Referenced by: '<S4>/Constant11'
                                        */
  real_T LS_straight_AG;               /* Variable: LS_straight_AG
                                        * Referenced by:
                                        *   '<S344>/Mode 1 AG'
                                        *   '<S344>/Mode 1 AG6'
                                        */
  real_T L_K_d;                        /* Variable: L_K_d
                                        * Referenced by:
                                        *   '<S27>/Constant3'
                                        *   '<S79>/Constant3'
                                        */
  real_T L_K_i;                        /* Variable: L_K_i
                                        * Referenced by:
                                        *   '<S27>/Constant11'
                                        *   '<S27>/Constant2'
                                        *   '<S27>/Constant9'
                                        *   '<S79>/Constant11'
                                        *   '<S79>/Constant2'
                                        *   '<S79>/Constant9'
                                        */
  real_T L_K_p;                        /* Variable: L_K_p
                                        * Referenced by:
                                        *   '<S27>/Constant1'
                                        *   '<S79>/Constant1'
                                        */
  real_T L_T_c;                        /* Variable: L_T_c
                                        * Referenced by:
                                        *   '<S27>/N'
                                        *   '<S79>/N'
                                        */
  real_T LandingTime;                  /* Variable: LandingTime
                                        * Referenced by: '<S9>/Switch4'
                                        */
  real_T LateralBeamOffsets;           /* Variable: LateralBeamOffsets
                                        * Referenced by:
                                        *   '<S16>/Constant6'
                                        *   '<S16>/Sine Wave1'
                                        *   '<S16>/Sine Wave2'
                                        */
  real_T LateralBeamOffsetsBackDelay;  /* Variable: LateralBeamOffsetsBackDelay
                                        * Referenced by: '<S16>/Constant4'
                                        */
  real_T LateralBeamOffsetsFactor;     /* Variable: LateralBeamOffsetsFactor
                                        * Referenced by: '<S16>/Sine Wave2'
                                        */
  real_T LateralDoubleFilter;          /* Variable: LateralDoubleFilter
                                        * Referenced by:
                                        *   '<S340>/Constant1'
                                        *   '<S341>/Constant1'
                                        *   '<S342>/Constant1'
                                        *   '<S343>/Constant1'
                                        *   '<S22>/Constant1'
                                        *   '<S23>/Constant1'
                                        *   '<S24>/Constant1'
                                        *   '<S25>/Constant1'
                                        */
  real_T LateralForgettingFactor;      /* Variable: LateralForgettingFactor
                                        * Referenced by:
                                        *   '<S340>/Constant'
                                        *   '<S341>/Constant'
                                        *   '<S342>/Constant'
                                        *   '<S343>/Constant'
                                        *   '<S22>/Constant'
                                        *   '<S23>/Constant'
                                        *   '<S24>/Constant'
                                        *   '<S25>/Constant'
                                        */
  real_T LateralOperatingMode;         /* Variable: LateralOperatingMode
                                        * Referenced by:
                                        *   '<Root>/Constant8'
                                        *   '<S9>/Constant1'
                                        */
  real_T M_f;                          /* Variable: M_f
                                        * Referenced by:
                                        *   '<S14>/Gain'
                                        *   '<S15>/Gain'
                                        */
  real_T Mass;                         /* Variable: Mass
                                        * Referenced by:
                                        *   '<S3>/Gain'
                                        *   '<S11>/Beta'
                                        *   '<S17>/Constant1'
                                        *   '<S18>/Constant1'
                                        */
  real_T MeasureCurrent;               /* Variable: MeasureCurrent
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PodLength;                    /* Variable: PodLength
                                        * Referenced by: '<S3>/2'
                                        */
  real_T PodWidth;                     /* Variable: PodWidth
                                        * Referenced by: '<S3>/1'
                                        */
  real_T PolarityBack;                 /* Variable: PolarityBack
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain3'
                                        */
  real_T PolarityFront;                /* Variable: PolarityFront
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain2'
                                        */
  real_T ReferenceMass;                /* Variable: ReferenceMass
                                        * Referenced by:
                                        *   '<S17>/Constant'
                                        *   '<S18>/Constant'
                                        */
  real_T ResetComplementary;           /* Variable: ResetComplementary
                                        * Referenced by: '<S337>/Constant6'
                                        */
  real_T RunTime;                      /* Variable: RunTime
                                        * Referenced by: '<S9>/Constant13'
                                        */
  real_T SemiCentralized;              /* Variable: SemiCentralized
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T SineTime;                     /* Variable: SineTime
                                        * Referenced by:
                                        *   '<S16>/Sine Wave1'
                                        *   '<S16>/Sine Wave2'
                                        */
  real_T StartupTime;                  /* Variable: StartupTime
                                        * Referenced by:
                                        *   '<S9>/Constant13'
                                        *   '<S9>/Constant3'
                                        */
  real_T StopDeIntegral;               /* Variable: StopDeIntegral
                                        * Referenced by:
                                        *   '<S27>/Constant16'
                                        *   '<S79>/Constant16'
                                        */
  real_T UseBothEMS;                   /* Variable: UseBothEMS
                                        * Referenced by:
                                        *   '<S13>/Constant'
                                        *   '<S27>/Constant13'
                                        *   '<S79>/Constant13'
                                        */
  real_T kalman_xdotdot_gain;          /* Variable: kalman_xdotdot_gain
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S4>/Gain1'
                                        */
  real_T kalman_yawdot_gain;           /* Variable: kalman_yawdot_gain
                                        * Referenced by: '<S337>/Gain3'
                                        */
  real_T kalman_ydotdot_gain;          /* Variable: kalman_ydotdot_gain
                                        * Referenced by: '<S337>/Gain2'
                                        */
  real_T lat_zero_reset;               /* Variable: lat_zero_reset
                                        * Referenced by: '<S130>/Constant3'
                                        */
  real_T lateral_over_vertical_force_hems;
                                   /* Variable: lateral_over_vertical_force_hems
                                    * Referenced by: '<S10>/Constant'
                                    */
  real_T lateral_over_vertical_force_motor;
                                  /* Variable: lateral_over_vertical_force_motor
                                   * Referenced by: '<S10>/Constant1'
                                   */
  real_T t_trans;                      /* Variable: t_trans
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T x_location_raw;               /* Variable: x_location_raw
                                        * Referenced by: '<S4>/Constant1'
                                        */
} InstP_ControllerLateral_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: pInitialization.Qbar
   * Referenced by: '<S258>/Qbar_'
   */
  real_T Qbar_Value[9];

  /* Expression: pInitialization.Rbar
   * Referenced by: '<S258>/Rbar_'
   */
  real_T Rbar_Value[4];

  /* Expression: [1 HardwareTimeStep 0.5*HardwareTimeStep^2; 0 1 HardwareTimeStep; 0 0 1]
   * Referenced by: '<S4>/A'
   */
  real_T A_Value[9];

  /* Expression: [1 0 0; 0 0 1]
   * Referenced by: '<S4>/C'
   */
  real_T C_Value[6];

  /* Expression: pInitialization.P0
   * Referenced by: '<S236>/P0'
   */
  real_T P0_Value[9];

  /* Pooled Parameter (Expression: EMS_CURRENT)
   * Referenced by:
   *   '<S14>/Constant'
   *   '<S14>/2-D Lookup Table1'
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/Constant'
   *   '<S15>/2-D Lookup Table1'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  real_T pooled27[14];

  /* Pooled Parameter (Expression: -EMS_FORCE)
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  real_T pooled28[1414];

  /* Pooled Parameter (Expression: EMS_AIRGAP)
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  real_T pooled29[101];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  uint32_T pooled36[2];
} ConstP_ControllerLateral_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T G_A2;                         /* '<Root>/G_A2' */
  real_T G_B2;                         /* '<Root>/G_B2' */
  real_T G_C2;                         /* '<Root>/G_C2' */
  real_T G_D2;                         /* '<Root>/G_D2' */
  real_T motor1;                       /* '<Root>/motor1' */
  real_T motor2;                       /* '<Root>/motor2' */
  real_T hems1;                        /* '<Root>/hems1' */
  real_T hems2;                        /* '<Root>/hems2' */
  real_T hems3;                        /* '<Root>/hems3' */
  real_T hems4;                        /* '<Root>/hems4' */
  real_T I_Front_m;                    /* '<Root>/I_Front_m' */
  real_T I_Back_m;                     /* '<Root>/I_Back_m' */
  real_T LateralAxisState;             /* '<Root>/LateralAxisState' */
  real_T VrF;                          /* '<Root>/VrF' */
  real_T VrB;                          /* '<Root>/VrB' */
  real_T VtF;                          /* '<Root>/VtF' */
  real_T VtB;                          /* '<Root>/VtB' */
  real_T IMU_yaw;                      /* '<Root>/IMU_yaw' */
  real_T CoM_y_dot;                    /* '<Root>/CoM_y_dot' */
  real_T com_acc_x;                    /* '<Root>/com_acc_x' */
  real_T PropulsionOn;                 /* '<Root>/PropulsionOn' */
  real_T com_spd_x;                    /* '<Root>/com_spd_x' */
} ExtU_ControllerLateral_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mode;                         /* '<Root>/Mode' */
  real_T LinposLateral[4];             /* '<Root>/Linpos Lateral' */
  real_T Filtered_GapsLateral[4];      /* '<Root>/Filtered_Gaps Lateral' */
  real_T ControlSIgnalsLateral[2];     /* '<Root>/Control SIgnals Lateral' */
  real_T ControlSignalsLateralFinal[2];
                                    /* '<Root>/Control Signals Lateral Final' */
  real_T OffsetFront;                  /* '<Root>/OffsetFront' */
  real_T OffsetBack;                   /* '<Root>/OffsetBack' */
  real_T RefOutFront;                  /* '<Root>/RefOutFront' */
  real_T RefOutBack;                   /* '<Root>/RefOutBack' */
  real_T I_Demand_Front;               /* '<Root>/I_Demand_Front' */
  real_T I_Demand_Back;                /* '<Root>/I_Demand_Back' */
  real_T Power_Lat;                    /* '<Root>/Power_Lat' */
  real_T Power_Lat_avg;                /* '<Root>/Power_Lat_avg' */
  real_T Energy_Lat;                   /* '<Root>/Energy_Lat' */
  real_T EMS_F_Front;                  /* '<Root>/EMS_F_Front' */
  real_T EMS_F_Back;                   /* '<Root>/EMS_F_Back' */
  real_T L_K_i_out[2];                 /* '<Root>/L_K_i_out' */
  real_T uncapped_current;             /* '<Root>/uncapped_current' */
  real_T LS_mode_vert;                 /* '<Root>/LS_mode_vert' */
  real_T Complementary_B;              /* '<Root>/Complementary_B' */
  real_T Complementary_D;              /* '<Root>/Complementary_D' */
  real_T Complementary_A;              /* '<Root>/Complementary_A' */
  real_T Complementary_C;              /* '<Root>/Complementary_C' */
  real_T Inertia;                      /* '<Root>/Inertia' */
  real_T x_speed;                      /* '<Root>/x_speed' */
  real_T x_location;                   /* '<Root>/x_location' */
} ExtY_ControllerLateral_T;

/* Real-time Model Data Structure */
struct tag_RTM_ControllerLateral_T {
  const char_T *errorStatus;
  B_ControllerLateral_T *blockIO;
  PrevZCX_ControllerLateral_T *prevZCSigState;
  ExtU_ControllerLateral_T *inputs;
  ExtY_ControllerLateral_T *outputs;
  DW_ControllerLateral_T *dwork;
  InstP_ControllerLateral_T *ControllerLateral_InstP_ref;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

/* instance parameters */
extern InstP_ControllerLateral_T ControllerLateral_InstP;

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Constant parameters (default storage) */
extern const ConstP_ControllerLateral_T ControllerLateral_ConstP;

/* Model entry point functions */
extern RT_MODEL_ControllerLateral_T *ControllerLateral(void);
extern void ControllerLateral_initialize(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M);
extern void ControllerLateral_output(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M);
extern void ControllerLateral_update(RT_MODEL_ControllerLateral_T *const
  ControllerLateral_M);
extern void ControllerLateral_terminate(RT_MODEL_ControllerLateral_T
  * ControllerLateral_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControllerLateral'
 * '<S1>'   : 'ControllerLateral/Array interpolation'
 * '<S2>'   : 'ControllerLateral/Calculate Control Signals (PIDs)'
 * '<S3>'   : 'ControllerLateral/Constants and Calculations'
 * '<S4>'   : 'ControllerLateral/Guus Filter (for Localization)'
 * '<S5>'   : 'ControllerLateral/Lane Switch Transition1'
 * '<S6>'   : 'ControllerLateral/MATLAB Function'
 * '<S7>'   : 'ControllerLateral/MATLAB Function1'
 * '<S8>'   : 'ControllerLateral/Sensors'
 * '<S9>'   : 'ControllerLateral/Startup Timer'
 * '<S10>'  : 'ControllerLateral/Subsystem'
 * '<S11>'  : 'ControllerLateral/Subsystem1'
 * '<S12>'  : 'ControllerLateral/Subsystem2'
 * '<S13>'  : 'ControllerLateral/Subsystem7'
 * '<S14>'  : 'ControllerLateral/Array interpolation/Subsystem1'
 * '<S15>'  : 'ControllerLateral/Array interpolation/Subsystem2'
 * '<S16>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator'
 * '<S17>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID'
 * '<S18>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1'
 * '<S19>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem'
 * '<S20>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1'
 * '<S21>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2'
 * '<S22>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals'
 * '<S23>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1'
 * '<S24>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals'
 * '<S25>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1'
 * '<S26>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1'
 * '<S27>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Gain Scheduling1'
 * '<S28>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup'
 * '<S29>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/D Gain'
 * '<S30>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter'
 * '<S31>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter ICs'
 * '<S32>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/I Gain'
 * '<S33>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain'
 * '<S34>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain Fdbk'
 * '<S35>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator'
 * '<S36>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator ICs'
 * '<S37>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Copy'
 * '<S38>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Gain'
 * '<S39>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/P Copy'
 * '<S40>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Parallel P Gain'
 * '<S41>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Reset Signal'
 * '<S42>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation'
 * '<S43>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation Fdbk'
 * '<S44>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum'
 * '<S45>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum Fdbk'
 * '<S46>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode'
 * '<S47>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode Sum'
 * '<S48>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Integral'
 * '<S49>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Ngain'
 * '<S50>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/postSat Signal'
 * '<S51>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/preSat Signal'
 * '<S52>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S53>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S54>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S55>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/D Gain/External Parameters'
 * '<S56>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter/Disc. Forward Euler Filter'
 * '<S57>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter ICs/Internal IC - Filter'
 * '<S58>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/I Gain/External Parameters'
 * '<S59>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S60>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S61>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator/Discrete'
 * '<S62>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator ICs/Internal IC'
 * '<S63>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Copy/Disabled'
 * '<S64>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Gain/External Parameters'
 * '<S65>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/P Copy/Disabled'
 * '<S66>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S67>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Reset Signal/External Reset'
 * '<S68>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation/Enabled'
 * '<S69>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S70>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum/Sum_PID'
 * '<S71>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum Fdbk/Disabled'
 * '<S72>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode/Disabled'
 * '<S73>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S74>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S75>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S76>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/postSat Signal/Forward_Path'
 * '<S77>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/preSat Signal/Forward_Path'
 * '<S78>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1'
 * '<S79>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Gain Scheduling1'
 * '<S80>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Anti-windup'
 * '<S81>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/D Gain'
 * '<S82>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Filter'
 * '<S83>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Filter ICs'
 * '<S84>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/I Gain'
 * '<S85>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Ideal P Gain'
 * '<S86>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Ideal P Gain Fdbk'
 * '<S87>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Integrator'
 * '<S88>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Integrator ICs'
 * '<S89>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/N Copy'
 * '<S90>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/N Gain'
 * '<S91>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/P Copy'
 * '<S92>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Parallel P Gain'
 * '<S93>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Reset Signal'
 * '<S94>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Saturation'
 * '<S95>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Saturation Fdbk'
 * '<S96>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Sum'
 * '<S97>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Sum Fdbk'
 * '<S98>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tracking Mode'
 * '<S99>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tracking Mode Sum'
 * '<S100>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tsamp - Integral'
 * '<S101>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tsamp - Ngain'
 * '<S102>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/postSat Signal'
 * '<S103>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/preSat Signal'
 * '<S104>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S105>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S106>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S107>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/D Gain/External Parameters'
 * '<S108>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Filter/Disc. Forward Euler Filter'
 * '<S109>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Filter ICs/Internal IC - Filter'
 * '<S110>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/I Gain/External Parameters'
 * '<S111>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S112>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S113>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Integrator/Discrete'
 * '<S114>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Integrator ICs/Internal IC'
 * '<S115>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/N Copy/Disabled'
 * '<S116>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/N Gain/External Parameters'
 * '<S117>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/P Copy/Disabled'
 * '<S118>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S119>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Reset Signal/External Reset'
 * '<S120>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Saturation/Enabled'
 * '<S121>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S122>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Sum/Sum_PID'
 * '<S123>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Sum Fdbk/Disabled'
 * '<S124>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tracking Mode/Disabled'
 * '<S125>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S126>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S127>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S128>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/postSat Signal/Forward_Path'
 * '<S129>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID1/Airgap controller1/preSat Signal/Forward_Path'
 * '<S130>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder'
 * '<S131>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1'
 * '<S132>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2'
 * '<S133>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Detect Change'
 * '<S134>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Detect Change1'
 * '<S135>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S136>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S137>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S138>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S139>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S140>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S141>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S142>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S143>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S144>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S145>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S146>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S147>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S148>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S149>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S150>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S151>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S152>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S153>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S154>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S155>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S156>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S157>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S158>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S159>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S160>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S161>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S162>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S163>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S164>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S165>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S166>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S167>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S168>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S169>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S170>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S171>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S172>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S173>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S174>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S175>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S176>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S177>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S178>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S179>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S180>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S181>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S182>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S183>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S184>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S185>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2'
 * '<S186>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Anti-windup'
 * '<S187>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/D Gain'
 * '<S188>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter'
 * '<S189>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter ICs'
 * '<S190>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/I Gain'
 * '<S191>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain'
 * '<S192>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain Fdbk'
 * '<S193>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator'
 * '<S194>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator ICs'
 * '<S195>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Copy'
 * '<S196>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Gain'
 * '<S197>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/P Copy'
 * '<S198>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Parallel P Gain'
 * '<S199>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Reset Signal'
 * '<S200>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation'
 * '<S201>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation Fdbk'
 * '<S202>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum'
 * '<S203>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum Fdbk'
 * '<S204>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode'
 * '<S205>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode Sum'
 * '<S206>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Integral'
 * '<S207>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Ngain'
 * '<S208>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/postSat Signal'
 * '<S209>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/preSat Signal'
 * '<S210>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Anti-windup/Back Calculation'
 * '<S211>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/D Gain/Internal Parameters'
 * '<S212>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator'
 * '<S213>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S214>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S215>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S216>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/I Gain/Internal Parameters'
 * '<S217>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S218>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S219>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator/Discrete'
 * '<S220>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator ICs/Internal IC'
 * '<S221>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S222>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Gain/Passthrough'
 * '<S223>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/P Copy/Disabled'
 * '<S224>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S225>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Reset Signal/External Reset'
 * '<S226>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation/Enabled'
 * '<S227>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S228>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum/Sum_PID'
 * '<S229>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum Fdbk/Disabled'
 * '<S230>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode/Disabled'
 * '<S231>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S232>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S233>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S234>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/postSat Signal/Forward_Path'
 * '<S235>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/preSat Signal/Forward_Path'
 * '<S236>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter'
 * '<S237>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller'
 * '<S238>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CalculatePL'
 * '<S239>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CalculateYhat'
 * '<S240>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CovarianceOutputConfigurator'
 * '<S241>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionA'
 * '<S242>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionB'
 * '<S243>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionC'
 * '<S244>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionD'
 * '<S245>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionEnable'
 * '<S246>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionG'
 * '<S247>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionH'
 * '<S248>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionN'
 * '<S249>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionP'
 * '<S250>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionP0'
 * '<S251>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionQ'
 * '<S252>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionR'
 * '<S253>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionReset'
 * '<S254>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionX'
 * '<S255>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionX0'
 * '<S256>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/DataTypeConversionu'
 * '<S257>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/Observer'
 * '<S258>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ReducedQRN'
 * '<S259>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/Reset'
 * '<S260>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/Reshapeyhat'
 * '<S261>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ScalarExpansionP0'
 * '<S262>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ScalarExpansionQ'
 * '<S263>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ScalarExpansionR'
 * '<S264>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/UseCurrentEstimator'
 * '<S265>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkA'
 * '<S266>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkB'
 * '<S267>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkC'
 * '<S268>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkD'
 * '<S269>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkEnable'
 * '<S270>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkG'
 * '<S271>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkH'
 * '<S272>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkN'
 * '<S273>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkP0'
 * '<S274>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkQ'
 * '<S275>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkR'
 * '<S276>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkReset'
 * '<S277>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checkX0'
 * '<S278>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checku'
 * '<S279>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/checky'
 * '<S280>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CalculatePL/Discrete-Time SqrtKF - Calculate SLMZ'
 * '<S281>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CalculateYhat/Ground'
 * '<S282>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S283>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S284>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/Observer/MeasurementUpdate'
 * '<S285>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ReducedQRN/DataTypeConversionNbar'
 * '<S286>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ReducedQRN/DataTypeConversionQbar'
 * '<S287>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/ReducedQRN/DataTypeConversionRbar'
 * '<S288>' : 'ControllerLateral/Guus Filter (for Localization)/Guus Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S289>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Anti-windup'
 * '<S290>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/D Gain'
 * '<S291>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Filter'
 * '<S292>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Filter ICs'
 * '<S293>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/I Gain'
 * '<S294>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Ideal P Gain'
 * '<S295>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Ideal P Gain Fdbk'
 * '<S296>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Integrator'
 * '<S297>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Integrator ICs'
 * '<S298>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/N Copy'
 * '<S299>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/N Gain'
 * '<S300>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/P Copy'
 * '<S301>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Parallel P Gain'
 * '<S302>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Reset Signal'
 * '<S303>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Saturation'
 * '<S304>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Saturation Fdbk'
 * '<S305>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Sum'
 * '<S306>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Sum Fdbk'
 * '<S307>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tracking Mode'
 * '<S308>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tracking Mode Sum'
 * '<S309>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tsamp - Integral'
 * '<S310>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tsamp - Ngain'
 * '<S311>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/postSat Signal'
 * '<S312>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/preSat Signal'
 * '<S313>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Anti-windup/Passthrough'
 * '<S314>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/D Gain/Internal Parameters'
 * '<S315>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S316>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S317>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/I Gain/Internal Parameters'
 * '<S318>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Ideal P Gain/Passthrough'
 * '<S319>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S320>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Integrator/Discrete'
 * '<S321>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Integrator ICs/Internal IC'
 * '<S322>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/N Copy/Disabled'
 * '<S323>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/N Gain/Internal Parameters'
 * '<S324>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/P Copy/Disabled'
 * '<S325>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S326>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Reset Signal/Disabled'
 * '<S327>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Saturation/Passthrough'
 * '<S328>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Saturation Fdbk/Disabled'
 * '<S329>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Sum/Sum_PID'
 * '<S330>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Sum Fdbk/Disabled'
 * '<S331>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tracking Mode/Disabled'
 * '<S332>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S333>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tsamp - Integral/Passthrough'
 * '<S334>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S335>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/postSat Signal/Forward_Path'
 * '<S336>' : 'ControllerLateral/Guus Filter (for Localization)/PID Controller/preSat Signal/Forward_Path'
 * '<S337>' : 'ControllerLateral/Sensors/Subsystem1'
 * '<S338>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter'
 * '<S339>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1'
 * '<S340>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals'
 * '<S341>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals1'
 * '<S342>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals2'
 * '<S343>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals3'
 * '<S344>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem'
 * '<S345>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Highpass1'
 * '<S346>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Highpass2'
 * '<S347>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1'
 * '<S348>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2'
 * '<S349>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Subsystem1'
 * '<S350>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Subsystem3'
 * '<S351>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup'
 * '<S352>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/D Gain'
 * '<S353>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter'
 * '<S354>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter ICs'
 * '<S355>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/I Gain'
 * '<S356>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain'
 * '<S357>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain Fdbk'
 * '<S358>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator'
 * '<S359>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator ICs'
 * '<S360>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Copy'
 * '<S361>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Gain'
 * '<S362>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/P Copy'
 * '<S363>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Parallel P Gain'
 * '<S364>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Reset Signal'
 * '<S365>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation'
 * '<S366>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation Fdbk'
 * '<S367>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum'
 * '<S368>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum Fdbk'
 * '<S369>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode'
 * '<S370>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode Sum'
 * '<S371>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Integral'
 * '<S372>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Ngain'
 * '<S373>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/postSat Signal'
 * '<S374>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/preSat Signal'
 * '<S375>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S376>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S377>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S378>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/D Gain/Internal Parameters'
 * '<S379>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S380>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S381>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/I Gain/Internal Parameters'
 * '<S382>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain/Passthrough'
 * '<S383>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S384>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator/Discrete'
 * '<S385>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator ICs/Internal IC'
 * '<S386>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Copy/Disabled'
 * '<S387>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Gain/Internal Parameters'
 * '<S388>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/P Copy/Disabled'
 * '<S389>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S390>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Reset Signal/Disabled'
 * '<S391>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation/Enabled'
 * '<S392>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation Fdbk/Disabled'
 * '<S393>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum/Sum_PID'
 * '<S394>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum Fdbk/Disabled'
 * '<S395>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode/Disabled'
 * '<S396>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S397>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S398>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S399>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/postSat Signal/Forward_Path'
 * '<S400>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/preSat Signal/Forward_Path'
 * '<S401>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup'
 * '<S402>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/D Gain'
 * '<S403>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter'
 * '<S404>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter ICs'
 * '<S405>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/I Gain'
 * '<S406>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain'
 * '<S407>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain Fdbk'
 * '<S408>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator'
 * '<S409>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator ICs'
 * '<S410>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Copy'
 * '<S411>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Gain'
 * '<S412>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/P Copy'
 * '<S413>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Parallel P Gain'
 * '<S414>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Reset Signal'
 * '<S415>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation'
 * '<S416>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation Fdbk'
 * '<S417>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum'
 * '<S418>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum Fdbk'
 * '<S419>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode'
 * '<S420>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode Sum'
 * '<S421>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Integral'
 * '<S422>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Ngain'
 * '<S423>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/postSat Signal'
 * '<S424>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/preSat Signal'
 * '<S425>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S426>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S427>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S428>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/D Gain/Internal Parameters'
 * '<S429>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S430>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S431>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/I Gain/Internal Parameters'
 * '<S432>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain/Passthrough'
 * '<S433>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S434>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator/Discrete'
 * '<S435>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator ICs/Internal IC'
 * '<S436>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Copy/Disabled'
 * '<S437>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Gain/Internal Parameters'
 * '<S438>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/P Copy/Disabled'
 * '<S439>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S440>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Reset Signal/Disabled'
 * '<S441>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation/Enabled'
 * '<S442>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation Fdbk/Disabled'
 * '<S443>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum/Sum_PID'
 * '<S444>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum Fdbk/Disabled'
 * '<S445>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode/Disabled'
 * '<S446>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S447>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S448>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S449>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/postSat Signal/Forward_Path'
 * '<S450>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/preSat Signal/Forward_Path'
 * '<S451>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Highpass1'
 * '<S452>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Highpass2'
 * '<S453>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1'
 * '<S454>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2'
 * '<S455>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Subsystem1'
 * '<S456>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Subsystem3'
 * '<S457>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup'
 * '<S458>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/D Gain'
 * '<S459>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter'
 * '<S460>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter ICs'
 * '<S461>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/I Gain'
 * '<S462>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain'
 * '<S463>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain Fdbk'
 * '<S464>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator'
 * '<S465>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator ICs'
 * '<S466>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Copy'
 * '<S467>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Gain'
 * '<S468>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/P Copy'
 * '<S469>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Parallel P Gain'
 * '<S470>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Reset Signal'
 * '<S471>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation'
 * '<S472>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation Fdbk'
 * '<S473>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum'
 * '<S474>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum Fdbk'
 * '<S475>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode'
 * '<S476>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode Sum'
 * '<S477>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Integral'
 * '<S478>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Ngain'
 * '<S479>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/postSat Signal'
 * '<S480>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/preSat Signal'
 * '<S481>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S482>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S483>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S484>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/D Gain/Internal Parameters'
 * '<S485>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S486>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S487>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/I Gain/Internal Parameters'
 * '<S488>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S489>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S490>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator/Discrete'
 * '<S491>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator ICs/Internal IC'
 * '<S492>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Copy/Disabled'
 * '<S493>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Gain/Internal Parameters'
 * '<S494>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/P Copy/Disabled'
 * '<S495>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S496>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Reset Signal/Disabled'
 * '<S497>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation/Enabled'
 * '<S498>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S499>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum/Sum_PID'
 * '<S500>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum Fdbk/Disabled'
 * '<S501>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode/Disabled'
 * '<S502>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S503>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S504>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S505>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/postSat Signal/Forward_Path'
 * '<S506>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/preSat Signal/Forward_Path'
 * '<S507>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup'
 * '<S508>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/D Gain'
 * '<S509>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter'
 * '<S510>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter ICs'
 * '<S511>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/I Gain'
 * '<S512>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain'
 * '<S513>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain Fdbk'
 * '<S514>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator'
 * '<S515>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator ICs'
 * '<S516>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Copy'
 * '<S517>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Gain'
 * '<S518>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/P Copy'
 * '<S519>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Parallel P Gain'
 * '<S520>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Reset Signal'
 * '<S521>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation'
 * '<S522>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation Fdbk'
 * '<S523>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum'
 * '<S524>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum Fdbk'
 * '<S525>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode'
 * '<S526>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode Sum'
 * '<S527>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Integral'
 * '<S528>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Ngain'
 * '<S529>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/postSat Signal'
 * '<S530>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/preSat Signal'
 * '<S531>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S532>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S533>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S534>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/D Gain/Internal Parameters'
 * '<S535>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S536>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S537>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/I Gain/Internal Parameters'
 * '<S538>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain/Passthrough'
 * '<S539>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S540>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator/Discrete'
 * '<S541>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator ICs/Internal IC'
 * '<S542>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Copy/Disabled'
 * '<S543>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Gain/Internal Parameters'
 * '<S544>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/P Copy/Disabled'
 * '<S545>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S546>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Reset Signal/Disabled'
 * '<S547>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation/Enabled'
 * '<S548>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation Fdbk/Disabled'
 * '<S549>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum/Sum_PID'
 * '<S550>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum Fdbk/Disabled'
 * '<S551>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode/Disabled'
 * '<S552>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S553>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S554>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S555>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/postSat Signal/Forward_Path'
 * '<S556>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/preSat Signal/Forward_Path'
 * '<S557>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem'
 * '<S558>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1'
 * '<S559>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant'
 * '<S560>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant1'
 * '<S561>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant'
 * '<S562>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant1'
 * '<S563>' : 'ControllerLateral/Startup Timer/Compare To Constant'
 * '<S564>' : 'ControllerLateral/Subsystem/MATLAB Function'
 * '<S565>' : 'ControllerLateral/Subsystem1/MATLAB Function'
 * '<S566>' : 'ControllerLateral/Subsystem7/Subsystem3'
 * '<S567>' : 'ControllerLateral/Subsystem7/Subsystem4'
 * '<S568>' : 'ControllerLateral/Subsystem7/Subsystem5'
 * '<S569>' : 'ControllerLateral/Subsystem7/Subsystem6'
 */
#endif                                 /* RTW_HEADER_ControllerLateral_h_ */
