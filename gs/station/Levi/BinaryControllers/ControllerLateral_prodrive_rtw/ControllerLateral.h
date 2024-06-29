/*
 * ControllerLateral.h
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

/* Block signals for system '<S17>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S17>/Moving Average' */
} B_MovingAverage_ControllerLateral_ca_T;

/* Block states (default storage) for system '<S17>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_e3x_T obj;/* '<S17>/Moving Average' */
  boolean_T objisempty;                /* '<S17>/Moving Average' */
} DW_MovingAverage_ControllerLateral_fw_T;

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
  real_T Gain3_i;                      /* '<S236>/Gain3' */
  real_T Gain10;                       /* '<S244>/Gain10' */
  real_T diff2;                        /* '<S237>/Subtract4' */
  real_T FilterCoefficient;            /* '<S382>/Filter Coefficient' */
  real_T Add;                          /* '<S237>/Add' */
  real_T diff1;                        /* '<S237>/Subtract3' */
  real_T FilterCoefficient_o;          /* '<S286>/Filter Coefficient' */
  real_T Add1;                         /* '<S237>/Add1' */
  real_T FilterCoefficient_n;          /* '<S334>/Filter Coefficient' */
  real_T Gain2;                        /* '<S236>/Gain2' */
  real_T Gain9;                        /* '<S237>/Gain9' */
  real_T Gain10_e;                     /* '<S245>/Gain10' */
  real_T Add2;                         /* '<S237>/Add2' */
  real_T FilterCoefficient_p;          /* '<S430>/Filter Coefficient' */
  real_T Add6;                         /* '<S237>/Add6' */
  real_T Gain10_o;                     /* '<S445>/Gain10' */
  real_T diff2_k;                      /* '<S238>/Subtract4' */
  real_T FilterCoefficient_e;          /* '<S582>/Filter Coefficient' */
  real_T Add_c;                        /* '<S238>/Add' */
  real_T diff1_k;                      /* '<S238>/Subtract3' */
  real_T FilterCoefficient_ow;         /* '<S486>/Filter Coefficient' */
  real_T Add1_b;                       /* '<S238>/Add1' */
  real_T FilterCoefficient_f;          /* '<S534>/Filter Coefficient' */
  real_T Gain10_ol;                    /* '<S444>/Gain10' */
  real_T Add2_a;                       /* '<S238>/Add2' */
  real_T FilterCoefficient_k;          /* '<S630>/Filter Coefficient' */
  real_T Add6_g;                       /* '<S238>/Add6' */
  real_T TmpSignalConversionAtDelay2Inport1[2];/* '<Root>/Array interpolation' */
  real_T TmpSignalConversionAtDelay1Inport1[2];
  real_T Gain_k;                       /* '<S7>/Gain' */
  real_T Switch3_h;                    /* '<S9>/Switch3' */
  boolean_T OR;                        /* '<S9>/OR' */
  boolean_T Equal;                     /* '<S9>/Equal' */
  boolean_T OR_h;                      /* '<S130>/OR' */
  boolean_T Equal_p;                   /* '<S17>/Equal' */
  boolean_T Equal_b;                   /* '<S18>/Equal' */
  boolean_T OR_hn;                     /* '<S7>/OR' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfpg;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh5;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfp;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvf;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpg;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage1_pnaevv;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfp;/* '<S22>/Moving Average' */
  B_MovingAverage_ControllerLateral_ca_T MovingAverage_pnaevvf;/* '<S17>/Moving Average' */
  B_MovingAverage1_ControllerLateral_T MovingAverage1_pnaev;/* '<S27>/Moving Average1' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaevv;/* '<S27>/Moving Average' */
  B_MovingAverage_ControllerLateral_ca_T MovingAverage_pnaev;/* '<S17>/Moving Average' */
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
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S238>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S238>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_g;/* '<S237>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S237>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE[2];             /* '<Root>/Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S134>/Delay Input1' */
  real_T Integrator_DSTATE;            /* '<S168>/Integrator' */
  real_T UD_DSTATE;                    /* '<S161>/UD' */
  real_T Delay1_DSTATE_b[400];         /* '<S16>/Delay1' */
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
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S251>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S250>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_m1;         /* '<S379>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S374>/Filter' */
  real_T Integrator_DSTATE_ok;         /* '<S283>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S278>/Filter' */
  real_T Integrator_DSTATE_f;          /* '<S331>/Integrator' */
  real_T Filter_DSTATE_dy;             /* '<S326>/Filter' */
  real_T Integrator_DSTATE_or;         /* '<S427>/Integrator' */
  real_T Filter_DSTATE_g;              /* '<S422>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_fq;/* '<S451>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S450>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S579>/Integrator' */
  real_T Filter_DSTATE_a1;             /* '<S574>/Filter' */
  real_T Integrator_DSTATE_a;          /* '<S483>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S478>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S531>/Integrator' */
  real_T Filter_DSTATE_dv;             /* '<S526>/Filter' */
  real_T Integrator_DSTATE_i;          /* '<S627>/Integrator' */
  real_T Filter_DSTATE_b5;             /* '<S622>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_ls;/* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_m;/* '<S7>/Discrete-Time Integrator1' */
  real_T Memory_PreviousInput;         /* '<S244>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S244>/Memory1' */
  real_T Memory_PreviousInput_k;       /* '<S245>/Memory' */
  real_T Memory1_PreviousInput_n;      /* '<S245>/Memory1' */
  real_T Memory_PreviousInput_d;       /* '<S445>/Memory' */
  real_T Memory1_PreviousInput_g;      /* '<S445>/Memory1' */
  real_T Memory_PreviousInput_l;       /* '<S444>/Memory' */
  real_T Memory1_PreviousInput_d;      /* '<S444>/Memory1' */
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
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S238>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S238>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_m;/* '<S237>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_l;/* '<S237>/Discrete-Time Integrator' */
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
  int8_T DiscreteTimeIntegrator_PrevResetState_k;/* '<S251>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_m;/* '<S250>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_c;/* '<S451>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S450>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_lt;/* '<S7>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_m4;/* '<S7>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOADING;/* '<S238>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S238>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOADING_o;/* '<S237>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING_n;/* '<S237>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput_dc;   /* '<S9>/Memory' */
  boolean_T objisempty;                /* '<S12>/Moving Average' */
  boolean_T mode_old_not_empty;        /* '<Root>/Lane Switch Transition1' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfpg;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh5;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvfp;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpgh;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevvf;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfpg;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage1_pnaevv;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaevvfp;/* '<S22>/Moving Average' */
  DW_MovingAverage_ControllerLateral_fw_T MovingAverage_pnaevvf;/* '<S17>/Moving Average' */
  DW_MovingAverage1_ControllerLateral_T MovingAverage1_pnaev;/* '<S27>/Moving Average1' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaevv;/* '<S27>/Moving Average' */
  DW_MovingAverage_ControllerLateral_fw_T MovingAverage_pnaev;/* '<S17>/Moving Average' */
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
  real_T ForgetFactor_Highpass_Lat;    /* Variable: ForgetFactor_Highpass_Lat
                                        * Referenced by:
                                        *   '<S244>/Gain10'
                                        *   '<S245>/Gain10'
                                        *   '<S444>/Gain10'
                                        *   '<S445>/Gain10'
                                        */
  real_T FrontGain;                    /* Variable: FrontGain
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T LS_curved_AG;                 /* Variable: LS_curved_AG
                                        * Referenced by:
                                        *   '<S243>/Mode 1 AG4'
                                        *   '<S243>/Mode 1 AG5'
                                        */
  real_T LS_mode;                      /* Variable: LS_mode
                                        * Referenced by:
                                        *   '<Root>/Constant2'
                                        *   '<Root>/Constant5'
                                        *   '<Root>/Lane Switch Mode'
                                        *   '<S236>/Constant'
                                        *   '<S236>/Constant4'
                                        *   '<S27>/Constant6'
                                        *   '<S79>/Constant6'
                                        */
  real_T LS_straight_AG;               /* Variable: LS_straight_AG
                                        * Referenced by:
                                        *   '<S243>/Mode 1 AG'
                                        *   '<S243>/Mode 1 AG6'
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
                                        *   '<S239>/Constant1'
                                        *   '<S240>/Constant1'
                                        *   '<S241>/Constant1'
                                        *   '<S242>/Constant1'
                                        *   '<S22>/Constant1'
                                        *   '<S23>/Constant1'
                                        *   '<S24>/Constant1'
                                        *   '<S25>/Constant1'
                                        */
  real_T LateralForgettingFactor;      /* Variable: LateralForgettingFactor
                                        * Referenced by:
                                        *   '<S239>/Constant'
                                        *   '<S240>/Constant'
                                        *   '<S241>/Constant'
                                        *   '<S242>/Constant'
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
                                        * Referenced by: '<S236>/Constant6'
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
  real_T UseComplementaryBD;           /* Variable: UseComplementaryBD
                                        * Referenced by: '<S236>/Constant5'
                                        */
  real_T kalman_xdotdot_gain;          /* Variable: kalman_xdotdot_gain
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T kalman_yawdot_gain;           /* Variable: kalman_yawdot_gain
                                        * Referenced by: '<S236>/Gain3'
                                        */
  real_T kalman_ydotdot_gain;          /* Variable: kalman_ydotdot_gain
                                        * Referenced by: '<S236>/Gain2'
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
} InstP_ControllerLateral_T;

/* Constant parameters (default storage) */
typedef struct {
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
  real_T pooled24[14];

  /* Pooled Parameter (Expression: -EMS_FORCE)
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  real_T pooled25[1414];

  /* Pooled Parameter (Expression: EMS_AIRGAP)
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  real_T pooled26[101];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S14>/2-D Lookup Table2'
   *   '<S14>/2-D Lookup Table3'
   *   '<S15>/2-D Lookup Table2'
   *   '<S15>/2-D Lookup Table3'
   */
  uint32_T pooled32[2];
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
  real_T IMU_x;                        /* '<Root>/IMU_x' */
  real_T IMU_yaw;                      /* '<Root>/IMU_yaw' */
  real_T IMU_y;                        /* '<Root>/IMU_y' */
  boolean_T PropulsionOn;              /* '<Root>/PropulsionOn' */
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
  real_T x_speed;                      /* '<Root>/x_speed' */
  real_T x_location;                   /* '<Root>/x_location' */
  real_T Complementary_A;              /* '<Root>/Complementary_A' */
  real_T Complementary_C;              /* '<Root>/Complementary_C' */
  real_T Inertia;                      /* '<Root>/Inertia' */
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
 * '<S4>'   : 'ControllerLateral/Lane Switch Transition1'
 * '<S5>'   : 'ControllerLateral/MATLAB Function'
 * '<S6>'   : 'ControllerLateral/MATLAB Function1'
 * '<S7>'   : 'ControllerLateral/Propulsion'
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
 * '<S236>' : 'ControllerLateral/Sensors/Subsystem1'
 * '<S237>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter'
 * '<S238>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1'
 * '<S239>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals'
 * '<S240>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals1'
 * '<S241>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals2'
 * '<S242>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals3'
 * '<S243>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem'
 * '<S244>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Highpass1'
 * '<S245>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Highpass2'
 * '<S246>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1'
 * '<S247>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2'
 * '<S248>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3'
 * '<S249>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4'
 * '<S250>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Subsystem1'
 * '<S251>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/Subsystem3'
 * '<S252>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup'
 * '<S253>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/D Gain'
 * '<S254>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter'
 * '<S255>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter ICs'
 * '<S256>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/I Gain'
 * '<S257>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain'
 * '<S258>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain Fdbk'
 * '<S259>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator'
 * '<S260>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator ICs'
 * '<S261>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Copy'
 * '<S262>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Gain'
 * '<S263>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/P Copy'
 * '<S264>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Parallel P Gain'
 * '<S265>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Reset Signal'
 * '<S266>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation'
 * '<S267>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation Fdbk'
 * '<S268>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum'
 * '<S269>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum Fdbk'
 * '<S270>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode'
 * '<S271>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode Sum'
 * '<S272>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Integral'
 * '<S273>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Ngain'
 * '<S274>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/postSat Signal'
 * '<S275>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/preSat Signal'
 * '<S276>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Anti-windup/Passthrough'
 * '<S277>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/D Gain/Internal Parameters'
 * '<S278>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S279>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S280>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/I Gain/Internal Parameters'
 * '<S281>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain/Passthrough'
 * '<S282>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S283>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator/Discrete'
 * '<S284>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Integrator ICs/Internal IC'
 * '<S285>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Copy/Disabled'
 * '<S286>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/N Gain/Internal Parameters'
 * '<S287>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/P Copy/Disabled'
 * '<S288>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S289>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Reset Signal/Disabled'
 * '<S290>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation/Passthrough'
 * '<S291>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Saturation Fdbk/Disabled'
 * '<S292>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum/Sum_PID'
 * '<S293>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Sum Fdbk/Disabled'
 * '<S294>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode/Disabled'
 * '<S295>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S296>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S297>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S298>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/postSat Signal/Forward_Path'
 * '<S299>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller1/preSat Signal/Forward_Path'
 * '<S300>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup'
 * '<S301>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/D Gain'
 * '<S302>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter'
 * '<S303>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter ICs'
 * '<S304>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/I Gain'
 * '<S305>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain'
 * '<S306>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain Fdbk'
 * '<S307>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator'
 * '<S308>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator ICs'
 * '<S309>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Copy'
 * '<S310>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Gain'
 * '<S311>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/P Copy'
 * '<S312>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Parallel P Gain'
 * '<S313>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Reset Signal'
 * '<S314>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation'
 * '<S315>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation Fdbk'
 * '<S316>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum'
 * '<S317>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum Fdbk'
 * '<S318>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode'
 * '<S319>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode Sum'
 * '<S320>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Integral'
 * '<S321>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Ngain'
 * '<S322>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/postSat Signal'
 * '<S323>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/preSat Signal'
 * '<S324>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Anti-windup/Passthrough'
 * '<S325>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/D Gain/Internal Parameters'
 * '<S326>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S327>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S328>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/I Gain/Internal Parameters'
 * '<S329>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain/Passthrough'
 * '<S330>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S331>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator/Discrete'
 * '<S332>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Integrator ICs/Internal IC'
 * '<S333>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Copy/Disabled'
 * '<S334>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/N Gain/Internal Parameters'
 * '<S335>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/P Copy/Disabled'
 * '<S336>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S337>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Reset Signal/Disabled'
 * '<S338>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation/Passthrough'
 * '<S339>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Saturation Fdbk/Disabled'
 * '<S340>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum/Sum_PID'
 * '<S341>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Sum Fdbk/Disabled'
 * '<S342>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode/Disabled'
 * '<S343>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S344>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S345>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S346>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/postSat Signal/Forward_Path'
 * '<S347>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller2/preSat Signal/Forward_Path'
 * '<S348>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Anti-windup'
 * '<S349>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/D Gain'
 * '<S350>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Filter'
 * '<S351>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Filter ICs'
 * '<S352>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/I Gain'
 * '<S353>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Ideal P Gain'
 * '<S354>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Ideal P Gain Fdbk'
 * '<S355>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Integrator'
 * '<S356>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Integrator ICs'
 * '<S357>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/N Copy'
 * '<S358>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/N Gain'
 * '<S359>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/P Copy'
 * '<S360>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Parallel P Gain'
 * '<S361>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Reset Signal'
 * '<S362>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Saturation'
 * '<S363>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Saturation Fdbk'
 * '<S364>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Sum'
 * '<S365>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Sum Fdbk'
 * '<S366>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tracking Mode'
 * '<S367>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tracking Mode Sum'
 * '<S368>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tsamp - Integral'
 * '<S369>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tsamp - Ngain'
 * '<S370>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/postSat Signal'
 * '<S371>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/preSat Signal'
 * '<S372>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Anti-windup/Passthrough'
 * '<S373>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/D Gain/Internal Parameters'
 * '<S374>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Filter/Disc. Forward Euler Filter'
 * '<S375>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S376>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/I Gain/Internal Parameters'
 * '<S377>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Ideal P Gain/Passthrough'
 * '<S378>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S379>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Integrator/Discrete'
 * '<S380>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Integrator ICs/Internal IC'
 * '<S381>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/N Copy/Disabled'
 * '<S382>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/N Gain/Internal Parameters'
 * '<S383>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/P Copy/Disabled'
 * '<S384>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S385>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Reset Signal/Disabled'
 * '<S386>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Saturation/Passthrough'
 * '<S387>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Saturation Fdbk/Disabled'
 * '<S388>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Sum/Sum_PID'
 * '<S389>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Sum Fdbk/Disabled'
 * '<S390>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tracking Mode/Disabled'
 * '<S391>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S392>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S393>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S394>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/postSat Signal/Forward_Path'
 * '<S395>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller3/preSat Signal/Forward_Path'
 * '<S396>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Anti-windup'
 * '<S397>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/D Gain'
 * '<S398>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Filter'
 * '<S399>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Filter ICs'
 * '<S400>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/I Gain'
 * '<S401>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Ideal P Gain'
 * '<S402>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Ideal P Gain Fdbk'
 * '<S403>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Integrator'
 * '<S404>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Integrator ICs'
 * '<S405>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/N Copy'
 * '<S406>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/N Gain'
 * '<S407>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/P Copy'
 * '<S408>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Parallel P Gain'
 * '<S409>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Reset Signal'
 * '<S410>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Saturation'
 * '<S411>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Saturation Fdbk'
 * '<S412>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Sum'
 * '<S413>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Sum Fdbk'
 * '<S414>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tracking Mode'
 * '<S415>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tracking Mode Sum'
 * '<S416>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tsamp - Integral'
 * '<S417>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tsamp - Ngain'
 * '<S418>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/postSat Signal'
 * '<S419>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/preSat Signal'
 * '<S420>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Anti-windup/Passthrough'
 * '<S421>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/D Gain/Internal Parameters'
 * '<S422>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Filter/Disc. Forward Euler Filter'
 * '<S423>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Filter ICs/Internal IC - Filter'
 * '<S424>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/I Gain/Internal Parameters'
 * '<S425>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Ideal P Gain/Passthrough'
 * '<S426>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S427>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Integrator/Discrete'
 * '<S428>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Integrator ICs/Internal IC'
 * '<S429>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/N Copy/Disabled'
 * '<S430>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/N Gain/Internal Parameters'
 * '<S431>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/P Copy/Disabled'
 * '<S432>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S433>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Reset Signal/Disabled'
 * '<S434>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Saturation/Passthrough'
 * '<S435>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Saturation Fdbk/Disabled'
 * '<S436>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Sum/Sum_PID'
 * '<S437>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Sum Fdbk/Disabled'
 * '<S438>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tracking Mode/Disabled'
 * '<S439>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S440>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S441>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S442>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/postSat Signal/Forward_Path'
 * '<S443>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter/PID Controller4/preSat Signal/Forward_Path'
 * '<S444>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Highpass1'
 * '<S445>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Highpass2'
 * '<S446>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1'
 * '<S447>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2'
 * '<S448>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3'
 * '<S449>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4'
 * '<S450>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Subsystem1'
 * '<S451>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/Subsystem3'
 * '<S452>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup'
 * '<S453>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/D Gain'
 * '<S454>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter'
 * '<S455>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter ICs'
 * '<S456>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/I Gain'
 * '<S457>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain'
 * '<S458>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain Fdbk'
 * '<S459>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator'
 * '<S460>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator ICs'
 * '<S461>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Copy'
 * '<S462>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Gain'
 * '<S463>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/P Copy'
 * '<S464>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Parallel P Gain'
 * '<S465>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Reset Signal'
 * '<S466>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation'
 * '<S467>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation Fdbk'
 * '<S468>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum'
 * '<S469>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum Fdbk'
 * '<S470>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode'
 * '<S471>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode Sum'
 * '<S472>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Integral'
 * '<S473>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Ngain'
 * '<S474>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/postSat Signal'
 * '<S475>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/preSat Signal'
 * '<S476>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Anti-windup/Passthrough'
 * '<S477>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/D Gain/Internal Parameters'
 * '<S478>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S479>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S480>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/I Gain/Internal Parameters'
 * '<S481>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S482>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S483>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator/Discrete'
 * '<S484>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Integrator ICs/Internal IC'
 * '<S485>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Copy/Disabled'
 * '<S486>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/N Gain/Internal Parameters'
 * '<S487>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/P Copy/Disabled'
 * '<S488>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S489>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Reset Signal/Disabled'
 * '<S490>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation/Passthrough'
 * '<S491>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S492>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum/Sum_PID'
 * '<S493>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Sum Fdbk/Disabled'
 * '<S494>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode/Disabled'
 * '<S495>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S496>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S497>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S498>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/postSat Signal/Forward_Path'
 * '<S499>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller1/preSat Signal/Forward_Path'
 * '<S500>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup'
 * '<S501>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/D Gain'
 * '<S502>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter'
 * '<S503>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter ICs'
 * '<S504>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/I Gain'
 * '<S505>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain'
 * '<S506>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain Fdbk'
 * '<S507>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator'
 * '<S508>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator ICs'
 * '<S509>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Copy'
 * '<S510>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Gain'
 * '<S511>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/P Copy'
 * '<S512>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Parallel P Gain'
 * '<S513>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Reset Signal'
 * '<S514>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation'
 * '<S515>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation Fdbk'
 * '<S516>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum'
 * '<S517>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum Fdbk'
 * '<S518>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode'
 * '<S519>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode Sum'
 * '<S520>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Integral'
 * '<S521>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Ngain'
 * '<S522>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/postSat Signal'
 * '<S523>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/preSat Signal'
 * '<S524>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Anti-windup/Passthrough'
 * '<S525>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/D Gain/Internal Parameters'
 * '<S526>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S527>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S528>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/I Gain/Internal Parameters'
 * '<S529>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain/Passthrough'
 * '<S530>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S531>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator/Discrete'
 * '<S532>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Integrator ICs/Internal IC'
 * '<S533>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Copy/Disabled'
 * '<S534>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/N Gain/Internal Parameters'
 * '<S535>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/P Copy/Disabled'
 * '<S536>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S537>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Reset Signal/Disabled'
 * '<S538>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation/Passthrough'
 * '<S539>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Saturation Fdbk/Disabled'
 * '<S540>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum/Sum_PID'
 * '<S541>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Sum Fdbk/Disabled'
 * '<S542>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode/Disabled'
 * '<S543>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S544>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S545>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S546>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/postSat Signal/Forward_Path'
 * '<S547>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller2/preSat Signal/Forward_Path'
 * '<S548>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Anti-windup'
 * '<S549>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/D Gain'
 * '<S550>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Filter'
 * '<S551>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Filter ICs'
 * '<S552>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/I Gain'
 * '<S553>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Ideal P Gain'
 * '<S554>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Ideal P Gain Fdbk'
 * '<S555>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Integrator'
 * '<S556>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Integrator ICs'
 * '<S557>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/N Copy'
 * '<S558>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/N Gain'
 * '<S559>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/P Copy'
 * '<S560>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Parallel P Gain'
 * '<S561>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Reset Signal'
 * '<S562>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Saturation'
 * '<S563>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Saturation Fdbk'
 * '<S564>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Sum'
 * '<S565>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Sum Fdbk'
 * '<S566>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tracking Mode'
 * '<S567>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tracking Mode Sum'
 * '<S568>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tsamp - Integral'
 * '<S569>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tsamp - Ngain'
 * '<S570>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/postSat Signal'
 * '<S571>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/preSat Signal'
 * '<S572>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Anti-windup/Passthrough'
 * '<S573>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/D Gain/Internal Parameters'
 * '<S574>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Filter/Disc. Forward Euler Filter'
 * '<S575>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S576>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/I Gain/Internal Parameters'
 * '<S577>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Ideal P Gain/Passthrough'
 * '<S578>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S579>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Integrator/Discrete'
 * '<S580>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Integrator ICs/Internal IC'
 * '<S581>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/N Copy/Disabled'
 * '<S582>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/N Gain/Internal Parameters'
 * '<S583>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/P Copy/Disabled'
 * '<S584>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S585>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Reset Signal/Disabled'
 * '<S586>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Saturation/Passthrough'
 * '<S587>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Saturation Fdbk/Disabled'
 * '<S588>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Sum/Sum_PID'
 * '<S589>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Sum Fdbk/Disabled'
 * '<S590>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tracking Mode/Disabled'
 * '<S591>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S592>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S593>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S594>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/postSat Signal/Forward_Path'
 * '<S595>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller3/preSat Signal/Forward_Path'
 * '<S596>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Anti-windup'
 * '<S597>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/D Gain'
 * '<S598>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Filter'
 * '<S599>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Filter ICs'
 * '<S600>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/I Gain'
 * '<S601>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Ideal P Gain'
 * '<S602>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Ideal P Gain Fdbk'
 * '<S603>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Integrator'
 * '<S604>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Integrator ICs'
 * '<S605>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/N Copy'
 * '<S606>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/N Gain'
 * '<S607>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/P Copy'
 * '<S608>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Parallel P Gain'
 * '<S609>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Reset Signal'
 * '<S610>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Saturation'
 * '<S611>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Saturation Fdbk'
 * '<S612>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Sum'
 * '<S613>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Sum Fdbk'
 * '<S614>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tracking Mode'
 * '<S615>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tracking Mode Sum'
 * '<S616>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tsamp - Integral'
 * '<S617>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tsamp - Ngain'
 * '<S618>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/postSat Signal'
 * '<S619>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/preSat Signal'
 * '<S620>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Anti-windup/Passthrough'
 * '<S621>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/D Gain/Internal Parameters'
 * '<S622>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Filter/Disc. Forward Euler Filter'
 * '<S623>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Filter ICs/Internal IC - Filter'
 * '<S624>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/I Gain/Internal Parameters'
 * '<S625>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Ideal P Gain/Passthrough'
 * '<S626>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S627>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Integrator/Discrete'
 * '<S628>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Integrator ICs/Internal IC'
 * '<S629>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/N Copy/Disabled'
 * '<S630>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/N Gain/Internal Parameters'
 * '<S631>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/P Copy/Disabled'
 * '<S632>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S633>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Reset Signal/Disabled'
 * '<S634>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Saturation/Passthrough'
 * '<S635>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Saturation Fdbk/Disabled'
 * '<S636>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Sum/Sum_PID'
 * '<S637>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Sum Fdbk/Disabled'
 * '<S638>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tracking Mode/Disabled'
 * '<S639>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S640>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S641>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S642>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/postSat Signal/Forward_Path'
 * '<S643>' : 'ControllerLateral/Sensors/Subsystem1/Complementary Filter1/PID Controller4/preSat Signal/Forward_Path'
 * '<S644>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem'
 * '<S645>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1'
 * '<S646>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant'
 * '<S647>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant1'
 * '<S648>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant'
 * '<S649>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant1'
 * '<S650>' : 'ControllerLateral/Startup Timer/Compare To Constant'
 * '<S651>' : 'ControllerLateral/Subsystem/MATLAB Function'
 * '<S652>' : 'ControllerLateral/Subsystem1/MATLAB Function'
 * '<S653>' : 'ControllerLateral/Subsystem7/Subsystem3'
 * '<S654>' : 'ControllerLateral/Subsystem7/Subsystem4'
 * '<S655>' : 'ControllerLateral/Subsystem7/Subsystem5'
 * '<S656>' : 'ControllerLateral/Subsystem7/Subsystem6'
 */
#endif                                 /* RTW_HEADER_ControllerLateral_h_ */
