/*
 * PIDcontroller4CoreCentralizedTestReadyMotor.h
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

#ifndef RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_h_
#define RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef PIDcontroller4CoreCentralizedTestReadyMotor_COMMON_INCLUDES_
#define PIDcontroller4CoreCentralizedTestReadyMotor_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif        /* PIDcontroller4CoreCentralizedTestReadyMotor_COMMON_INCLUDES_ */

#include "PIDcontroller4CoreCentralizedTestReadyMotor_types.h"

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

#ifndef rtmGetPIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref
#define rtmGetPIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref(rtm) ((rtm)->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref)
#endif

#ifndef rtmSetPIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref
#define rtmSetPIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref(rtm, val) ((rtm)->PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref = (val))
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

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define PIDcontroller4CoreCentralizedTestReadyMotor_M_TYPE RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T

/* Block signals for system '<S26>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S26>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block states (default storage) for system '<S26>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T obj;/* '<S26>/Moving Average' */
  boolean_T objisempty;                /* '<S26>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S38>/FindCoordinates' */
typedef struct {
  real_T avg_g;                        /* '<S38>/FindCoordinates' */
  real_T pitch;                        /* '<S38>/FindCoordinates' */
  real_T roll;                         /* '<S38>/FindCoordinates' */
} B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S3>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S3>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T;

/* Block states (default storage) for system '<S3>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T obj;/* '<S3>/Moving Average' */
  boolean_T objisempty;                /* '<S3>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T;

/* Block signals for system '<Root>/Moving Average' */
typedef struct {
  real_T MovingAverage[3];             /* '<Root>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T;

/* Block states (default storage) for system '<Root>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T
    obj;                               /* '<Root>/Moving Average' */
  boolean_T objisempty;                /* '<Root>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T;

/* Block signals for system '<S22>/Cap requested current1' */
typedef struct {
  real_T out_req_I;                    /* '<S22>/Cap requested current1' */
} B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals (default storage) */
typedef struct {
  real_T Tsamp;                        /* '<S508>/Tsamp' */
  real_T Tsamp_b;                      /* '<S458>/Tsamp' */
  real_T Product1;                     /* '<S32>/Product1' */
  real_T Gain;                         /* '<S32>/Gain' */
  real_T Subtract5;                    /* '<S74>/Subtract5' */
  real_T Delay1[4];                    /* '<Root>/Delay1' */
  real_T Switch;                       /* '<S74>/Switch' */
  real_T Tsamp_k;                      /* '<S155>/Tsamp' */
  real_T Switch1;                      /* '<S419>/Switch1' */
  real_T Switch1_j;                    /* '<S420>/Switch1' */
  real_T Switch1_e;                    /* '<S421>/Switch1' */
  real_T Switch1_a;                    /* '<S422>/Switch1' */
  real_T Switch1_o;                    /* '<S423>/Switch1' */
  real_T Switch1_g;                    /* '<S424>/Switch1' */
  real_T Switch_k;                     /* '<S416>/Switch' */
  real_T Switch1_n;                    /* '<S425>/Switch1' */
  real_T Switch_c;                     /* '<S417>/Switch' */
  real_T Tom;                          /* '<S6>/To m' */
  real_T Tomm;                         /* '<S6>/To mm' */
  real_T Subtract1;                    /* '<S8>/Subtract1' */
  real_T Switch1_jz[3];                /* '<Root>/Switch1' */
  real_T error;                        /* '<S33>/Sum' */
  real_T NProdOut;                     /* '<S111>/NProd Out' */
  real_T Divide1;                      /* '<S33>/Divide1' */
  real_T Switch_n;                     /* '<S3>/Switch' */
  real_T Gravity;                      /* '<S3>/Gravity' */
  real_T Subtract5_o;                  /* '<S183>/Subtract5' */
  real_T Switch_o;                     /* '<S183>/Switch' */
  real_T Tsamp_m;                      /* '<S264>/Tsamp' */
  real_T setpointpitch;                /* '<S34>/Plus' */
  real_T Gain2;                        /* '<S34>/Gain2' */
  real_T NProdOut_e;                   /* '<S221>/NProd Out' */
  real_T Product;                      /* '<S34>/Product' */
  real_T Gain1;                        /* '<S3>/Gain1' */
  real_T Subtract5_l;                  /* '<S291>/Subtract5' */
  real_T Switch_p;                     /* '<S291>/Switch' */
  real_T Tsamp_h;                      /* '<S372>/Tsamp' */
  real_T setpointroll;                 /* '<S36>/Add' */
  real_T Gain3;                        /* '<S36>/Gain3' */
  real_T Gain2_e;                      /* '<S36>/Gain2' */
  real_T NProdOut_k;                   /* '<S329>/NProd Out' */
  real_T Product_h;                    /* '<S36>/Product' */
  real_T Add;                          /* '<S23>/Add' */
  real_T Gain4;                        /* '<S3>/Gain4' */
  real_T Add2;                         /* '<S3>/Add2' */
  real_T Switch1_h;                    /* '<S426>/Switch1' */
  real_T Flip1[30];                    /* '<S27>/Flip1' */
  real_T Max;                          /* '<S27>/Max' */
  real_T Subtract4;                    /* '<S27>/Subtract4' */
  real_T Switch2_i;                    /* '<S27>/Switch2' */
  real_T Flip1_g[30];                  /* '<S28>/Flip1' */
  real_T Max_l;                        /* '<S28>/Max' */
  real_T Subtract4_i;                  /* '<S28>/Subtract4' */
  real_T Switch2_n;                    /* '<S28>/Switch2' */
  real_T Flip1_k[30];                  /* '<S29>/Flip1' */
  real_T Max_e;                        /* '<S29>/Max' */
  real_T Subtract4_a;                  /* '<S29>/Subtract4' */
  real_T Switch2_h;                    /* '<S29>/Switch2' */
  real_T Flip1_h[30];                  /* '<S30>/Flip1' */
  real_T Max_j;                        /* '<S30>/Max' */
  real_T Subtract4_e;                  /* '<S30>/Subtract4' */
  real_T Switch2_e;                    /* '<S30>/Switch2' */
  real_T Subtract2;                    /* '<S17>/Subtract2' */
  real_T Tsamp_kb;                     /* '<S561>/Tsamp' */
  real_T Sum;                          /* '<S575>/Sum' */
  real_T Subtract2_e;                  /* '<S18>/Subtract2' */
  real_T Tsamp_k0;                     /* '<S614>/Tsamp' */
  real_T Sum_d;                        /* '<S628>/Sum' */
  real_T Subtract2_f;                  /* '<S20>/Subtract2' */
  real_T Tsamp_o;                      /* '<S720>/Tsamp' */
  real_T Sum_b;                        /* '<S734>/Sum' */
  real_T Subtract2_c;                  /* '<S19>/Subtract2' */
  real_T Tsamp_g;                      /* '<S667>/Tsamp' */
  real_T Sum_c;                        /* '<S681>/Sum' */
  real_T Delay2[3];                    /* '<Root>/Delay2' */
  real_T Sum1;                         /* '<S397>/Sum1' */
  real_T Delay1_i;                     /* '<S27>/Delay1' */
  real_T Delay;                        /* '<S27>/Delay' */
  real_T Switch4;                      /* '<S27>/Switch4' */
  real_T Switch6;                      /* '<S27>/Switch6' */
  real_T Switch3;                      /* '<S27>/Switch3' */
  real_T Switch5;                      /* '<S27>/Switch5' */
  real_T Switch7;                      /* '<S27>/Switch7' */
  real_T Delay1_e;                     /* '<S28>/Delay1' */
  real_T Delay_p;                      /* '<S28>/Delay' */
  real_T Switch4_c;                    /* '<S28>/Switch4' */
  real_T Switch6_e;                    /* '<S28>/Switch6' */
  real_T Switch3_m;                    /* '<S28>/Switch3' */
  real_T Switch5_g;                    /* '<S28>/Switch5' */
  real_T Switch7_e;                    /* '<S28>/Switch7' */
  real_T Delay1_o;                     /* '<S29>/Delay1' */
  real_T Delay_pt;                     /* '<S29>/Delay' */
  real_T Switch4_g;                    /* '<S29>/Switch4' */
  real_T Switch6_l;                    /* '<S29>/Switch6' */
  real_T Switch3_a;                    /* '<S29>/Switch3' */
  real_T Switch5_a;                    /* '<S29>/Switch5' */
  real_T Switch7_d;                    /* '<S29>/Switch7' */
  real_T Delay1_g;                     /* '<S30>/Delay1' */
  real_T Delay_pj;                     /* '<S30>/Delay' */
  real_T Switch4_k;                    /* '<S30>/Switch4' */
  real_T Switch6_n;                    /* '<S30>/Switch6' */
  real_T Switch3_p;                    /* '<S30>/Switch3' */
  real_T Switch5_c;                    /* '<S30>/Switch5' */
  real_T Switch7_a;                    /* '<S30>/Switch7' */
  real_T Switch_l;                     /* '<S99>/Switch' */
  real_T error_h;                      /* '<S72>/Switch3' */
  real_T SumI4;                        /* '<S151>/SumI4' */
  real_T Switch_j;                     /* '<S209>/Switch' */
  real_T SumI4_c;                      /* '<S260>/SumI4' */
  real_T Switch_d;                     /* '<S317>/Switch' */
  real_T SumI4_o;                      /* '<S368>/SumI4' */
  real_T Gain_g;                       /* '<S6>/Gain' */
  real_T Switch_e[4];                  /* '<S6>/Switch' */
  real_T Switch1_eg;                   /* '<S6>/Switch1' */
  real_T Switch2_k;                    /* '<S6>/Switch2' */
  real_T Saturation;                   /* '<S8>/Saturation' */
  real_T Gain2_c;                      /* '<S8>/Gain2' */
  real_T Gain5;                        /* '<S8>/Gain5' */
  real_T Gain6;                        /* '<S8>/Gain6' */
  real_T Subtract;                     /* '<S8>/Subtract' */
  real_T Switch_dt;                    /* '<S555>/Switch' */
  real_T Switch_em;                    /* '<S608>/Switch' */
  real_T Switch_lx;                    /* '<S661>/Switch' */
  real_T Switch_c5;                    /* '<S714>/Switch' */
  real_T TmpSignalConversionAtDelay1Inport1[4];/* '<Root>/Data Center' */
  real_T TmpSignalConversionAtDelay2Inport1[3];/* '<Root>/Kalman Input Adjustments' */
  real_T SumI4_g;                      /* '<S454>/SumI4' */
  real_T SumI4_k;                      /* '<S504>/SumI4' */
  real_T Switch3_h;                    /* '<S16>/Switch3' */
  real_T Product_i[3];                 /* '<S23>/Product' */
  real_T Product1_l;                   /* '<S23>/Product1' */
  real_T Product2;                     /* '<S23>/Product2' */
  real_T DataStoreRead[6];             /* '<S401>/Data Store Read' */
  boolean_T Equal;                     /* '<S16>/Equal' */
  boolean_T Equal_k;                   /* '<S73>/Equal' */
  boolean_T Equal_a;                   /* '<S34>/Equal' */
  boolean_T OR;                        /* '<S23>/OR' */
  boolean_T Equal_km;                  /* '<S36>/Equal' */
  boolean_T Equal_l;                   /* '<S6>/Equal' */
  boolean_T Equal1;                    /* '<S6>/Equal1' */
  boolean_T Equal2;                    /* '<S6>/Equal2' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent3;           /* '<S22>/Cap requested current3' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent2;           /* '<S22>/Cap requested current2' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent1;           /* '<S22>/Cap requested current1' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_ka;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_kw;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_h;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zz;      /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_k;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5z;       /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_f;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5;        /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_n;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh;         /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_e;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
    MovingAverage1_pnaevvfpg;          /* '<Root>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
    MovingAverage_c;                   /* '<Root>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T
    MovingAverage1_pnaevvfp;           /* '<S3>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T
    MovingAverage_pnaevvfpgh5zzhe;     /* '<S3>/Moving Average' */
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_FindCoordinates_d;              /* '<S39>/FindCoordinates' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zzh;      /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zz;       /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5z;        /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvf;            /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5;         /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevv;             /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh;          /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaev;              /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpg;           /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnae;               /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfp;            /* '<S26>/Moving Average' */
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_FindCoordinates;                /* '<S38>/FindCoordinates' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvf;             /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevv;              /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaev;               /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pna;                /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnae;                /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pn;                 /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pna;                 /* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1_p;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_pn;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_p;/* '<S26>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage;/* '<S26>/Moving Average' */
} B_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T obj;/* '<S397>/Moving Average' */
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o1_T
    obj_i;                             /* '<S409>/Moving Average' */
  real_T Delay1_DSTATE;                /* '<S16>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S513>/Integrator' */
  real_T UD_DSTATE;                    /* '<S506>/UD' */
  real_T Integrator_DSTATE_j;          /* '<S463>/Integrator' */
  real_T UD_DSTATE_p;                  /* '<S456>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S16>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S71>/Delay' */
  real_T Delay1_DSTATE_e[400];         /* '<S32>/Delay1' */
  real_T Delay_DSTATE_k[400];          /* '<S32>/Delay' */
  real_T Delay1_DSTATE_ez[4];          /* '<Root>/Delay1' */
  real_T Integrator_DSTATE_jc;         /* '<S160>/Integrator' */
  real_T UD_DSTATE_f;                  /* '<S153>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S72>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S72>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S8>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S108>/Integrator' */
  real_T Filter_DSTATE;                /* '<S103>/Filter' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S23>/Discrete-Time Integrator3' */
  real_T Integrator_DSTATE_l;          /* '<S269>/Integrator' */
  real_T UD_DSTATE_o;                  /* '<S262>/UD' */
  real_T Delay_DSTATE_h;               /* '<S179>/Delay' */
  real_T Integrator_DSTATE_c;          /* '<S218>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S213>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S23>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_lg;         /* '<S377>/Integrator' */
  real_T UD_DSTATE_l;                  /* '<S370>/UD' */
  real_T Delay_DSTATE_m;               /* '<S288>/Delay' */
  real_T Integrator_DSTATE_lw;         /* '<S326>/Integrator' */
  real_T Filter_DSTATE_h;              /* '<S321>/Filter' */
  real_T DiscreteTimeIntegrator1_DSTATE_k;/* '<S23>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S23>/Discrete-Time Integrator2' */
  real_T Delay3_DSTATE;                /* '<S27>/Delay3' */
  real_T Delay2_DSTATE;                /* '<S27>/Delay2' */
  real_T Delay3_DSTATE_g;              /* '<S28>/Delay3' */
  real_T Delay2_DSTATE_l;              /* '<S28>/Delay2' */
  real_T Delay3_DSTATE_p;              /* '<S29>/Delay3' */
  real_T Delay2_DSTATE_g;              /* '<S29>/Delay2' */
  real_T Delay3_DSTATE_k;              /* '<S30>/Delay3' */
  real_T Delay2_DSTATE_f;              /* '<S30>/Delay2' */
  real_T Integrator_DSTATE_h;          /* '<S566>/Integrator' */
  real_T UD_DSTATE_g;                  /* '<S559>/UD' */
  real_T Integrator_DSTATE_d;          /* '<S619>/Integrator' */
  real_T UD_DSTATE_e;                  /* '<S612>/UD' */
  real_T Integrator_DSTATE_p;          /* '<S725>/Integrator' */
  real_T UD_DSTATE_h;                  /* '<S718>/UD' */
  real_T Integrator_DSTATE_m;          /* '<S672>/Integrator' */
  real_T UD_DSTATE_ei;                 /* '<S665>/UD' */
  real_T Delay2_DSTATE_d[3];           /* '<Root>/Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S397>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE_c;              /* '<S27>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S27>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_d[2];            /* '<S27>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_c;/* '<S27>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_c5;             /* '<S28>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S28>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_a[2];            /* '<S28>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_p;/* '<S28>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_b;              /* '<S29>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S29>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_e[2];            /* '<S29>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_b;/* '<S29>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_g;              /* '<S30>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S30>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_k1[2];           /* '<S30>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_m;/* '<S30>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTATE_l;/* '<S8>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator3_DSTATE_g;/* '<S8>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S8>/Discrete-Time Integrator4' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA[3];              /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB[3];              /* '<Root>/Derivative' */
  real_T TimeStampA_l;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_g[3];            /* '<Root>/Derivative1' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_l[3];            /* '<Root>/Derivative1' */
  real_T P[36];                        /* '<S399>/DataStoreMemory - P' */
  real_T x[6];                         /* '<S399>/DataStoreMemory - x' */
  int32_T clockTickCounter;            /* '<S32>/Pulse Generator' */
  int32_T counter;                     /* '<S32>/Sine Wave4' */
  int32_T counter_h;                   /* '<S32>/Sine Wave5' */
  int32_T counter_o;                   /* '<S32>/Sine Wave6' */
  int32_T counter_a;                   /* '<S32>/Sine Wave7' */
  int32_T counter_i;                   /* '<S32>/Sine Wave1' */
  int32_T counter_m;                   /* '<S32>/Sine Wave2' */
  int32_T counter_n;                   /* '<S32>/Sine Wave3' */
  uint32_T m_bpIndex[5];               /* '<S406>/2-D Lookup Table3' */
  uint32_T m_Cache01;                  /* '<S406>/2-D Lookup Table3' */
  uint32_T m_Cache02[4];               /* '<S406>/2-D Lookup Table3' */
  uint32_T m_bpIndex_f[31];            /* '<S27>/2-D Lookup Table2' */
  uint32_T m_Cache01_m[30];            /* '<S27>/2-D Lookup Table2' */
  uint32_T m_Cache02_p;                /* '<S27>/2-D Lookup Table2' */
  uint32_T m_bpIndex_fj;               /* '<S27>/2-D Lookup Table1' */
  uint32_T m_bpIndex_g[31];            /* '<S28>/2-D Lookup Table2' */
  uint32_T m_Cache01_b[30];            /* '<S28>/2-D Lookup Table2' */
  uint32_T m_Cache02_i;                /* '<S28>/2-D Lookup Table2' */
  uint32_T m_bpIndex_gr;               /* '<S28>/2-D Lookup Table1' */
  uint32_T m_bpIndex_e[31];            /* '<S29>/2-D Lookup Table2' */
  uint32_T m_Cache01_n[30];            /* '<S29>/2-D Lookup Table2' */
  uint32_T m_Cache02_j;                /* '<S29>/2-D Lookup Table2' */
  uint32_T m_bpIndex_h;                /* '<S29>/2-D Lookup Table1' */
  uint32_T m_bpIndex_o[31];            /* '<S30>/2-D Lookup Table2' */
  uint32_T m_Cache01_f[30];            /* '<S30>/2-D Lookup Table2' */
  uint32_T m_Cache02_o;                /* '<S30>/2-D Lookup Table2' */
  uint32_T m_bpIndex_ep;               /* '<S30>/2-D Lookup Table1' */
  uint32_T m_bpIndex_k[2];             /* '<S21>/2-D Lookup Table2' */
  uint32_T m_bpIndex_a[2];             /* '<S21>/2-D Lookup Table1' */
  uint32_T m_bpIndex_c[2];             /* '<S21>/2-D Lookup Table3' */
  uint32_T m_bpIndex_j[2];             /* '<S21>/2-D Lookup Table4' */
  int8_T Integrator_PrevResetState;    /* '<S513>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S463>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S16>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_n;  /* '<S160>/Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S72>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_n;/* '<S72>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_o;/* '<S8>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S108>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S103>/Filter' */
  int8_T DiscreteTimeIntegrator3_PrevResetState;/* '<S23>/Discrete-Time Integrator3' */
  int8_T Integrator_PrevResetState_g;  /* '<S269>/Integrator' */
  int8_T Integrator_PrevResetState_g0; /* '<S218>/Integrator' */
  int8_T Filter_PrevResetState_j;      /* '<S213>/Filter' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S23>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_m;  /* '<S377>/Integrator' */
  int8_T Integrator_PrevResetState_ns; /* '<S326>/Integrator' */
  int8_T Filter_PrevResetState_k;      /* '<S321>/Filter' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_h;/* '<S23>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevResetState;/* '<S23>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator_PrevResetState_j;/* '<S397>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S27>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_l;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S28>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_m;/* '<S28>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_m;/* '<S29>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_n;/* '<S29>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_d;/* '<S30>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_e;/* '<S30>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_o;/* '<S8>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator3_PrevResetState_f;/* '<S8>/Discrete-Time Integrator3' */
  int8_T DiscreteTimeIntegrator4_PrevResetState;/* '<S8>/Discrete-Time Integrator4' */
  boolean_T objisempty;                /* '<S409>/Moving Average' */
  boolean_T objisempty_n;              /* '<S397>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_ka;                  /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_kw;                  /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_h;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zz;      /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_k;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5z;       /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_f;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5;        /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_n;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh;         /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_e;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
    MovingAverage1_pnaevvfpg;          /* '<Root>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
    MovingAverage_c;                   /* '<Root>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T
    MovingAverage1_pnaevvfp;           /* '<S3>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T
    MovingAverage_pnaevvfpgh5zzhe;     /* '<S3>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zzh;      /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zz;       /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5z;        /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvf;            /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5;         /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevv;             /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh;          /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaev;              /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpg;           /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnae;               /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfp;            /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvf;             /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevv;              /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaev;               /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pna;                /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnae;                /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pn;                 /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pna;                 /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_p;                  /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pn;                  /* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_p;/* '<S26>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage;/* '<S26>/Moving Average' */
} DW_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState UD_Reset_ZCE;             /* '<S506>/UD' */
  ZCSigState UD_Reset_ZCE_g;           /* '<S456>/UD' */
  ZCSigState UD_Reset_ZCE_a;           /* '<S153>/UD' */
  ZCSigState UD_Reset_ZCE_n;           /* '<S262>/UD' */
  ZCSigState UD_Reset_ZCE_k;           /* '<S370>/UD' */
} PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* instance parameters, for system '<Root>' */
typedef struct {
  real_T Airgap_GainSchedulingEnabled[5];/* Variable: Airgap_GainSchedulingEnabled
                                          * Referenced by:
                                          *   '<S31>/Constant4'
                                          *   '<S71>/Constant4'
                                          *   '<S426>/Constant4'
                                          *   '<S125>/Constant4'
                                          *   '<S48>/Constant4'
                                          *   '<S49>/Constant4'
                                          *   '<S50>/Constant4'
                                          *   '<S51>/Constant4'
                                          *   '<S52>/Constant4'
                                          *   '<S53>/Constant4'
                                          *   '<S54>/Constant4'
                                          *   '<S63>/Constant4'
                                          *   '<S64>/Constant4'
                                          *   '<S65>/Constant4'
                                          *   '<S66>/Constant4'
                                          *   '<S67>/Constant4'
                                          *   '<S68>/Constant4'
                                          *   '<S69>/Constant4'
                                          *   '<S419>/Constant4'
                                          *   '<S420>/Constant4'
                                          *   '<S421>/Constant4'
                                          *   '<S422>/Constant4'
                                          *   '<S423>/Constant4'
                                          *   '<S424>/Constant4'
                                          *   '<S425>/Constant4'
                                          */
  real_T CoMIntegrals[3];              /* Variable: CoMIntegrals
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T F_array[2];                   /* Variable: F_array
                                        * Referenced by:
                                        *   '<S31>/n-D Lookup Table'
                                        *   '<S426>/n-D Lookup Table'
                                        *   '<S48>/n-D Lookup Table'
                                        *   '<S49>/n-D Lookup Table'
                                        *   '<S50>/n-D Lookup Table'
                                        *   '<S51>/n-D Lookup Table'
                                        *   '<S52>/n-D Lookup Table'
                                        *   '<S53>/n-D Lookup Table'
                                        *   '<S54>/n-D Lookup Table'
                                        *   '<S63>/n-D Lookup Table'
                                        *   '<S64>/n-D Lookup Table'
                                        *   '<S65>/n-D Lookup Table'
                                        *   '<S66>/n-D Lookup Table'
                                        *   '<S67>/n-D Lookup Table'
                                        *   '<S68>/n-D Lookup Table'
                                        *   '<S69>/n-D Lookup Table'
                                        *   '<S419>/n-D Lookup Table'
                                        *   '<S420>/n-D Lookup Table'
                                        *   '<S421>/n-D Lookup Table'
                                        *   '<S422>/n-D Lookup Table'
                                        *   '<S423>/n-D Lookup Table'
                                        *   '<S424>/n-D Lookup Table'
                                        *   '<S425>/n-D Lookup Table'
                                        */
  real_T GS_breakpoints[3];            /* Variable: GS_breakpoints
                                        * Referenced by:
                                        *   '<S71>/n-D Lookup Table'
                                        *   '<S71>/n-D Lookup Table1'
                                        *   '<S179>/n-D Lookup Table'
                                        *   '<S179>/n-D Lookup Table1'
                                        *   '<S288>/n-D Lookup Table'
                                        *   '<S288>/n-D Lookup Table1'
                                        */
  real_T G_K_d_array[3];               /* Variable: G_K_d_array
                                        * Referenced by: '<S71>/n-D Lookup Table1'
                                        */
  real_T G_K_p_array[3];               /* Variable: G_K_p_array
                                        * Referenced by: '<S71>/n-D Lookup Table'
                                        */
  real_T G_Tc_array[2];                /* Variable: G_Tc_array
                                        * Referenced by:
                                        *   '<S125>/n-D Lookup Table'
                                        *   '<S184>/n-D Lookup Table'
                                        *   '<S292>/n-D Lookup Table'
                                        */
  real_T HEMS_Plane_Offsets[4];        /* Variable: HEMS_Plane_Offsets
                                        * Referenced by:
                                        *   '<S15>/Constant'
                                        *   '<S410>/Constant3'
                                        *   '<S410>/Constant4'
                                        */
  real_T MismatchingKalmanAGPR[3];     /* Variable: MismatchingKalmanAGPR
                                        * Referenced by:
                                        *   '<S8>/Gain2'
                                        *   '<S8>/Gain5'
                                        *   '<S8>/Gain6'
                                        */
  real_T P_K_d_array[3];               /* Variable: P_K_d_array
                                        * Referenced by: '<S179>/n-D Lookup Table1'
                                        */
  real_T P_K_p_array[3];               /* Variable: P_K_p_array
                                        * Referenced by: '<S179>/n-D Lookup Table'
                                        */
  real_T Pitch_GainSchedulingEnabled[5];/* Variable: Pitch_GainSchedulingEnabled
                                         * Referenced by:
                                         *   '<S179>/Constant4'
                                         *   '<S184>/Constant4'
                                         */
  real_T R_K_d_array[3];               /* Variable: R_K_d_array
                                        * Referenced by: '<S288>/n-D Lookup Table1'
                                        */
  real_T R_K_p_array[3];               /* Variable: R_K_p_array
                                        * Referenced by: '<S288>/n-D Lookup Table'
                                        */
  real_T Roll_GainSchedulingEnabled[5];/* Variable: Roll_GainSchedulingEnabled
                                        * Referenced by:
                                        *   '<S288>/Constant4'
                                        *   '<S292>/Constant4'
                                        */
  real_T SineSwitches[3];              /* Variable: SineSwitches
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T AirgapFilter;                 /* Variable: AirgapFilter
                                        * Referenced by:
                                        *   '<S44>/Constant1'
                                        *   '<S59>/Constant1'
                                        *   '<S415>/Constant1'
                                        */
  real_T BaseRefAirgap;                /* Variable: BaseRefAirgap
                                        * Referenced by:
                                        *   '<S72>/Base Ref Airgap'
                                        *   '<S72>/Base Ref Airgap1'
                                        */
  real_T BeamErrorTime;                /* Variable: BeamErrorTime
                                        * Referenced by: '<S32>/Pulse Generator'
                                        */
  real_T BeamOffsets;                  /* Variable: BeamOffsets
                                        * Referenced by:
                                        *   '<S32>/Constant6'
                                        *   '<S32>/Sine Wave1'
                                        *   '<S32>/Sine Wave2'
                                        *   '<S32>/Sine Wave3'
                                        *   '<S32>/Sine Wave4'
                                        *   '<S32>/Sine Wave5'
                                        *   '<S32>/Sine Wave6'
                                        *   '<S32>/Sine Wave7'
                                        */
  real_T BeamOffsetsBackDelay;         /* Variable: BeamOffsetsBackDelay
                                        * Referenced by: '<S32>/Constant4'
                                        */
  real_T BeamOffsetsFactor;            /* Variable: BeamOffsetsFactor
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T CurrentIntegralAG;            /* Variable: CurrentIntegralAG
                                        * Referenced by: '<S157>/Integral Gain'
                                        */
  real_T CurrentIntegralP;             /* Variable: CurrentIntegralP
                                        * Referenced by:
                                        *   '<S460>/Integral Gain'
                                        *   '<S510>/Integral Gain'
                                        *   '<S266>/Integral Gain'
                                        */
  real_T CurrentIntegralR;             /* Variable: CurrentIntegralR
                                        * Referenced by: '<S374>/Integral Gain'
                                        */
  real_T DoubleFilter;                 /* Variable: DoubleFilter
                                        * Referenced by:
                                        *   '<S40>/Constant1'
                                        *   '<S41>/Constant1'
                                        *   '<S42>/Constant1'
                                        *   '<S43>/Constant1'
                                        *   '<S55>/Constant1'
                                        *   '<S56>/Constant1'
                                        *   '<S57>/Constant1'
                                        *   '<S58>/Constant1'
                                        *   '<S411>/Constant1'
                                        *   '<S412>/Constant1'
                                        *   '<S413>/Constant1'
                                        *   '<S414>/Constant1'
                                        */
  real_T EMSRollIntegral;              /* Variable: EMSRollIntegral
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T EMS_Moment_Arm_Z;             /* Variable: EMS_Moment_Arm_Z
                                        * Referenced by: '<S23>/Constant5'
                                        */
  real_T ForgettingFactor;             /* Variable: ForgettingFactor
                                        * Referenced by:
                                        *   '<S48>/Constant'
                                        *   '<S49>/Constant'
                                        *   '<S50>/Constant'
                                        *   '<S51>/Constant'
                                        *   '<S63>/Constant'
                                        *   '<S64>/Constant'
                                        *   '<S65>/Constant'
                                        *   '<S66>/Constant'
                                        *   '<S419>/Constant'
                                        *   '<S420>/Constant'
                                        *   '<S421>/Constant'
                                        *   '<S422>/Constant'
                                        */
  real_T ForgettingFactorAirgap;       /* Variable: ForgettingFactorAirgap
                                        * Referenced by:
                                        *   '<S52>/Constant'
                                        *   '<S67>/Constant'
                                        *   '<S423>/Constant'
                                        */
  real_T ForgettingFactorLinpos;       /* Variable: ForgettingFactorLinpos
                                        * Referenced by:
                                        *   '<S31>/Constant'
                                        *   '<S426>/Constant'
                                        */
  real_T ForgettingFactorPitch;        /* Variable: ForgettingFactorPitch
                                        * Referenced by:
                                        *   '<S53>/Constant'
                                        *   '<S68>/Constant'
                                        *   '<S424>/Constant'
                                        */
  real_T ForgettingFactorRoll;         /* Variable: ForgettingFactorRoll
                                        * Referenced by:
                                        *   '<S54>/Constant'
                                        *   '<S69>/Constant'
                                        *   '<S425>/Constant'
                                        */
  real_T G_K_d;                        /* Variable: G_K_d
                                        * Referenced by: '<S71>/Constant3'
                                        */
  real_T G_K_i;                        /* Variable: G_K_i
                                        * Referenced by: '<S71>/Constant2'
                                        */
  real_T G_K_p;                        /* Variable: G_K_p
                                        * Referenced by: '<S71>/Constant1'
                                        */
  real_T G_T_c;                        /* Variable: G_T_c
                                        * Referenced by: '<S125>/N'
                                        */
  real_T I_K_d;                        /* Variable: I_K_d
                                        * Referenced by:
                                        *   '<S17>/Constant3'
                                        *   '<S18>/Constant3'
                                        *   '<S19>/Constant3'
                                        *   '<S20>/Constant3'
                                        */
  real_T I_K_i;                        /* Variable: I_K_i
                                        * Referenced by:
                                        *   '<S17>/Constant2'
                                        *   '<S18>/Constant2'
                                        *   '<S19>/Constant2'
                                        *   '<S20>/Constant2'
                                        */
  real_T I_K_p;                        /* Variable: I_K_p
                                        * Referenced by:
                                        *   '<S17>/Constant1'
                                        *   '<S18>/Constant1'
                                        *   '<S19>/Constant1'
                                        *   '<S20>/Constant1'
                                        */
  real_T Kalman_F;                     /* Variable: Kalman_F
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Kalman_I;                     /* Variable: Kalman_I
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Kalman_P;                     /* Variable: Kalman_P
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T Kalman_R;                     /* Variable: Kalman_R
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T LandingAirgap;                /* Variable: LandingAirgap
                                        * Referenced by: '<S72>/Constant3'
                                        */
  real_T LandingTime;                  /* Variable: LandingTime
                                        * Referenced by:
                                        *   '<S16>/Switch4'
                                        *   '<S72>/Gain1'
                                        */
  real_T LinposFilter;                 /* Variable: LinposFilter
                                        * Referenced by: '<S409>/Constant1'
                                        */
  real_T LinposOn;                     /* Variable: LinposOn
                                        * Referenced by: '<S410>/Constant5'
                                        */
  real_T M_f;                          /* Variable: M_f
                                        * Referenced by:
                                        *   '<S21>/Gain'
                                        *   '<S27>/Gain'
                                        *   '<S28>/Gain'
                                        *   '<S29>/Gain'
                                        *   '<S30>/Gain'
                                        */
  real_T Mass;                         /* Variable: Mass
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<S6>/Constant'
                                        *   '<S6>/Constant9'
                                        *   '<S23>/Constant6'
                                        *   '<S33>/Constant1'
                                        *   '<S34>/Gain'
                                        *   '<S36>/Gain'
                                        */
  real_T MeasureCurrent;               /* Variable: MeasureCurrent
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T MismatchedHEMSKalman;         /* Variable: MismatchedHEMSKalman
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T MismatchedHEMSLateral;        /* Variable: MismatchedHEMSLateral
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T MotorAirgapOffset;            /* Variable: MotorAirgapOffset
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T OperatingMode;                /* Variable: OperatingMode
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T P_K_d;                        /* Variable: P_K_d
                                        * Referenced by: '<S179>/Constant3'
                                        */
  real_T P_K_i;                        /* Variable: P_K_i
                                        * Referenced by: '<S179>/Constant2'
                                        */
  real_T P_K_p;                        /* Variable: P_K_p
                                        * Referenced by: '<S179>/Constant1'
                                        */
  real_T P_T_c;                        /* Variable: P_T_c
                                        * Referenced by: '<S184>/N'
                                        */
  real_T PitchFilter;                  /* Variable: PitchFilter
                                        * Referenced by:
                                        *   '<S45>/Constant1'
                                        *   '<S60>/Constant1'
                                        *   '<S416>/Constant1'
                                        */
  real_T PodHeight;                    /* Variable: PodHeight
                                        * Referenced by:
                                        *   '<S34>/2'
                                        *   '<S36>/2'
                                        */
  real_T PodHeightFactor;              /* Variable: PodHeightFactor
                                        * Referenced by:
                                        *   '<S34>/Gain4'
                                        *   '<S36>/Gain5'
                                        */
  real_T PodLength;                    /* Variable: PodLength
                                        * Referenced by: '<S34>/3'
                                        */
  real_T PodLengthFactor;              /* Variable: PodLengthFactor
                                        * Referenced by: '<S34>/Gain3'
                                        */
  real_T PodWidth;                     /* Variable: PodWidth
                                        * Referenced by: '<S36>/1'
                                        */
  real_T PodWidthFactor;               /* Variable: PodWidthFactor
                                        * Referenced by: '<S36>/Gain4'
                                        */
  real_T Polarity;                     /* Variable: Polarity
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        */
  real_T PropulsionCurrent;            /* Variable: PropulsionCurrent
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T PropulsionOn;                 /* Variable: PropulsionOn
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T R_K_d;                        /* Variable: R_K_d
                                        * Referenced by: '<S288>/Constant3'
                                        */
  real_T R_K_i;                        /* Variable: R_K_i
                                        * Referenced by: '<S288>/Constant2'
                                        */
  real_T R_K_p;                        /* Variable: R_K_p
                                        * Referenced by: '<S288>/Constant1'
                                        */
  real_T R_T_c;                        /* Variable: R_T_c
                                        * Referenced by: '<S292>/N'
                                        */
  real_T RefPitch;                     /* Variable: RefPitch
                                        * Referenced by: '<S34>/Base Ref Airgap1'
                                        */
  real_T RefRoll;                      /* Variable: RefRoll
                                        * Referenced by: '<S36>/Base Ref Airgap1'
                                        */
  real_T ReferenceMass;                /* Variable: ReferenceMass
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Reference_P_Inertia;          /* Variable: Reference_P_Inertia
                                        * Referenced by: '<S34>/Reference_P_Inertia'
                                        */
  real_T Reference_R_Inertia;          /* Variable: Reference_R_Inertia
                                        * Referenced by: '<S36>/Reference_R_Inertia'
                                        */
  real_T ResetArms;                    /* Variable: ResetArms
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T RollFilter;                   /* Variable: RollFilter
                                        * Referenced by:
                                        *   '<S46>/Constant1'
                                        *   '<S61>/Constant1'
                                        *   '<S417>/Constant1'
                                        */
  real_T RunTime;                      /* Variable: RunTime
                                        * Referenced by: '<S16>/Constant13'
                                        */
  real_T SineTime;                     /* Variable: SineTime
                                        * Referenced by:
                                        *   '<S32>/Sine Wave1'
                                        *   '<S32>/Sine Wave2'
                                        *   '<S32>/Sine Wave3'
                                        *   '<S32>/Sine Wave4'
                                        *   '<S32>/Sine Wave5'
                                        *   '<S32>/Sine Wave6'
                                        *   '<S32>/Sine Wave7'
                                        */
  real_T SkipKalman;                   /* Variable: SkipKalman
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T StartingAirgap;               /* Variable: StartingAirgap
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T StartupTime;                  /* Variable: StartupTime
                                        * Referenced by:
                                        *   '<S16>/Constant3'
                                        *   '<S72>/Gain'
                                        *   '<S72>/Saturation'
                                        */
  real_T Undo_0current;                /* Variable: Undo_0current
                                        * Referenced by:
                                        *   '<S74>/Constant'
                                        *   '<S183>/Constant'
                                        *   '<S291>/Constant'
                                        */
  real_T X_Arm_Offset;                 /* Variable: X_Arm_Offset
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Y_Arm_Offset;                 /* Variable: Y_Arm_Offset
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T motorforce_on;                /* Variable: motorforce_on
                                        * Referenced by:
                                        *   '<S395>/Constant5'
                                        *   '<S396>/Constant5'
                                        */
  real_T var_ag_dot;                   /* Variable: var_ag_dot
                                        * Referenced by: '<S398>/Constant4'
                                        */
  real_T var_ag_proc;                  /* Variable: var_ag_proc
                                        * Referenced by: '<S398>/Constant7'
                                        */
  real_T var_ag_sens;                  /* Variable: var_ag_sens
                                        * Referenced by: '<S398>/Constant1'
                                        */
  real_T var_pitch_dot;                /* Variable: var_pitch_dot
                                        * Referenced by: '<S398>/Constant6'
                                        */
  real_T var_pitch_proc;               /* Variable: var_pitch_proc
                                        * Referenced by: '<S398>/Constant9'
                                        */
  real_T var_pitch_sens;               /* Variable: var_pitch_sens
                                        * Referenced by: '<S398>/Constant3'
                                        */
  real_T var_roll_dot;                 /* Variable: var_roll_dot
                                        * Referenced by: '<S398>/Constant5'
                                        */
  real_T var_roll_proc;                /* Variable: var_roll_proc
                                        * Referenced by: '<S398>/Constant8'
                                        */
  real_T var_roll_sens;                /* Variable: var_roll_sens
                                        * Referenced by: '<S398>/Constant2'
                                        */
  uint32_T MagnetFailure;              /* Variable: MagnetFailure
                                        * Referenced by: '<S406>/Constant1'
                                        */
} InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S4>/Gain' */
  const real_T Gain1;                  /* '<S4>/Gain1' */
} ConstB_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0,3.5])
   * Referenced by:
   *   '<S31>/n-D Lookup Table'
   *   '<S426>/n-D Lookup Table'
   *   '<S125>/n-D Lookup Table'
   *   '<S184>/n-D Lookup Table'
   *   '<S292>/n-D Lookup Table'
   *   '<S48>/n-D Lookup Table'
   *   '<S49>/n-D Lookup Table'
   *   '<S50>/n-D Lookup Table'
   *   '<S51>/n-D Lookup Table'
   *   '<S52>/n-D Lookup Table'
   *   '<S53>/n-D Lookup Table'
   *   '<S54>/n-D Lookup Table'
   *   '<S63>/n-D Lookup Table'
   *   '<S64>/n-D Lookup Table'
   *   '<S65>/n-D Lookup Table'
   *   '<S66>/n-D Lookup Table'
   *   '<S67>/n-D Lookup Table'
   *   '<S68>/n-D Lookup Table'
   *   '<S69>/n-D Lookup Table'
   *   '<S419>/n-D Lookup Table'
   *   '<S420>/n-D Lookup Table'
   *   '<S421>/n-D Lookup Table'
   *   '<S422>/n-D Lookup Table'
   *   '<S423>/n-D Lookup Table'
   *   '<S424>/n-D Lookup Table'
   *   '<S425>/n-D Lookup Table'
   */
  real_T pooled4[2];

  /* Pooled Parameter (Expression: MotorPositionPoints)
   * Referenced by:
   *   '<S3>/Constant2'
   *   '<S3>/Constant6'
   */
  real_T pooled16[39];

  /* Expression: MotorLiftPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[1210];

  /* Expression: MotorCurrentPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[22];

  /* Expression: MotorBreakPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp02Data[55];

  /* Pooled Parameter (Expression: BEAM_FORCE_Z_POS)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S29>/2-D Lookup Table2'
   *   '<S30>/2-D Lookup Table2'
   *   '<S406>/2-D Lookup Table3'
   */
  real_T pooled27[10530];

  /* Pooled Parameter (Expression: CURRENT)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S27>/Constant'
   *   '<S27>/Constant20'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/Constant'
   *   '<S28>/Constant20'
   *   '<S28>/2-D Lookup Table2'
   *   '<S29>/Constant'
   *   '<S29>/Constant20'
   *   '<S29>/2-D Lookup Table2'
   *   '<S30>/Constant'
   *   '<S30>/Constant20'
   *   '<S30>/2-D Lookup Table2'
   *   '<S406>/2-D Lookup Table3'
   */
  real_T pooled28[30];

  /* Pooled Parameter (Expression: LEVI_AIRGAP)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S29>/2-D Lookup Table2'
   *   '<S30>/2-D Lookup Table2'
   *   '<S406>/2-D Lookup Table3'
   */
  real_T pooled29[351];

  /* Expression: p.InitialCovariance
   * Referenced by: '<S399>/DataStoreMemory - P'
   */
  real_T DataStoreMemoryP_InitialValue[36];

  /* Expression: p.InitialState
   * Referenced by: '<S399>/DataStoreMemory - x'
   */
  real_T DataStoreMemoryx_InitialValue[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S29>/2-D Lookup Table2'
   *   '<S30>/2-D Lookup Table2'
   *   '<S406>/2-D Lookup Table3'
   */
  uint32_T pooled37[2];
} ConstP_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T G_A;                          /* '<Root>/G_A' */
  real_T G_B;                          /* '<Root>/G_B' */
  real_T G_C;                          /* '<Root>/G_C' */
  real_T G_D;                          /* '<Root>/G_D' */
  real_T I_A_m;                        /* '<Root>/I_A_m' */
  real_T I_B_m;                        /* '<Root>/I_B_m' */
  real_T I_C_m;                        /* '<Root>/I_C_m' */
  real_T I_D_m;                        /* '<Root>/I_D_m' */
  real_T VerticalAxisState;            /* '<Root>/VerticalAxisState' */
  real_T Vr1;                          /* '<Root>/Vr1' */
  real_T Vr2;                          /* '<Root>/Vr2' */
  real_T Vr3;                          /* '<Root>/Vr3' */
  real_T Vr4;                          /* '<Root>/Vr4' */
  real_T Vt1;                          /* '<Root>/Vt1' */
  real_T Vt2;                          /* '<Root>/Vt2' */
  real_T Vt3;                          /* '<Root>/Vt3' */
  real_T Vt4;                          /* '<Root>/Vt4' */
  real_T EMS_F_Front;                  /* '<Root>/EMS_F_Front' */
  real_T EMS_F_Back;                   /* '<Root>/EMS_F_Back' */
} ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T I_A;                          /* '<Root>/I_A' */
  real_T ActualReferenceAirgap;        /* '<Root>/ActualReferenceAirgap' */
  real_T Mode;                         /* '<Root>/Mode' */
  real_T Airgap;                       /* '<Root>/Airgap' */
  real_T Acceleration[3];              /* '<Root>/Acceleration' */
  real_T CalculatedForce[3];           /* '<Root>/Calculated Force' */
  real_T Speed[3];                     /* '<Root>/Speed' */
  real_T I_B;                          /* '<Root>/I_B' */
  real_T I_C;                          /* '<Root>/I_C' */
  real_T I_D;                          /* '<Root>/I_D' */
  real_T Pitch;                        /* '<Root>/Pitch' */
  real_T Roll;                         /* '<Root>/Roll' */
  real_T G_Factor;                     /* '<Root>/G_Factor' */
  real_T P_Factor;                     /* '<Root>/P_Factor' */
  real_T R_Factor;                     /* '<Root>/R_Factor' */
  real_T Linpos[4];                    /* '<Root>/Linpos' */
  real_T Filtered_Gaps[4];             /* '<Root>/Filtered_Gaps' */
  real_T PitchError;                   /* '<Root>/PitchError' */
  real_T BeamErrorOutput[3];           /* '<Root>/BeamErrorOutput' */
  real_T ControlSIgnals[3];            /* '<Root>/Control SIgnals' */
  real_T ExternalForces[3];            /* '<Root>/External Forces' */
  real_T HEMSForces[4];                /* '<Root>/HEMSForces' */
  real_T motorfrontback[2];            /* '<Root>/motorfrontback' */
  real_T RefPitchOut;                  /* '<Root>/RefPitchOut' */
  real_T RefRollOut;                   /* '<Root>/RefRollOut' */
  real_T DataBeforeKalman[3];          /* '<Root>/DataBeforeKalman' */
  real_T Power;                        /* '<Root>/Power' */
  real_T Power_avg;                    /* '<Root>/Power_avg' */
  real_T Energy;                       /* '<Root>/Energy' */
  real_T CalculatedTPR[3];             /* '<Root>/CalculatedTPR' */
  real_T Arms[3];                      /* '<Root>/Arms' */
  real_T CalculatedMass;               /* '<Root>/CalculatedMass' */
} ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Real-time Model Data Structure */
struct tag_RTM_PIDcontroller4CoreCentralizedTestReadyMotor_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_PIDcontroller4CoreCentralizedTestReadyMotor_T *blockIO;
  PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T *prevZCSigState;
  ExtU_PIDcontroller4CoreCentralizedTestReadyMotor_T *inputs;
  ExtY_PIDcontroller4CoreCentralizedTestReadyMotor_T *outputs;
  DW_PIDcontroller4CoreCentralizedTestReadyMotor_T *dwork;
  InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T
    *PIDcontroller4CoreCentralizedTestReadyMotor_InstP_ref;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* instance parameters */
extern InstP_PIDcontroller4CoreCentralizedTestReadyMotor_T
  PIDcontroller4CoreCentralizedTestReadyMotor_InstP;

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern const ConstB_PIDcontroller4CoreCentralizedTestReadyMotor_T
  PIDcontroller4CoreCentralizedTestReadyMotor_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_PIDcontroller4CoreCentralizedTestReadyMotor_T
  PIDcontroller4CoreCentralizedTestReadyMotor_ConstP;

/* Model entry point functions */
extern RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T
  *PIDcontroller4CoreCentralizedTestReadyMotor(void);
extern void PIDcontroller4CoreCentralizedTestReadyMotor_initialize
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M);
extern void PIDcontroller4CoreCentralizedTestReadyMotor_output
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M);
extern void PIDcontroller4CoreCentralizedTestReadyMotor_update
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T *const
   PIDcontroller4CoreCentralizedTestReadyMotor_M);
extern void PIDcontroller4CoreCentralizedTestReadyMotor_terminate
  (RT_MODEL_PIDcontroller4CoreCentralizedTestReadyMotor_T
   * PIDcontroller4CoreCentralizedTestReadyMotor_M);

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
 * '<Root>' : 'PIDcontroller4CoreCentralizedTestReadyMotor'
 * '<S1>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation'
 * '<S2>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)'
 * '<S3>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force'
 * '<S4>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/CalculateRollPitchVertical'
 * '<S5>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Data Center'
 * '<S6>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter'
 * '<S7>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver'
 * '<S8>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Kalman Input Adjustments'
 * '<S9>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees'
 * '<S10>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees1'
 * '<S11>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees2'
 * '<S12>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees3'
 * '<S13>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees4'
 * '<S14>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees5'
 * '<S15>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors'
 * '<S16>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer'
 * '<S17>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem'
 * '<S18>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1'
 * '<S19>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2'
 * '<S20>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3'
 * '<S21>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem4'
 * '<S22>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5'
 * '<S23>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem6'
 * '<S24>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/SwitchMismatch'
 * '<S25>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Temperature, Current and Emergency Break'
 * '<S26>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Filter Noisy Signals'
 * '<S27>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference'
 * '<S28>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference1'
 * '<S29>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference2'
 * '<S30>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference3'
 * '<S31>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S32>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator'
 * '<S33>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS'
 * '<S34>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID'
 * '<S35>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/Remove external force'
 * '<S36>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID'
 * '<S37>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/Subsystem'
 * '<S38>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1'
 * '<S39>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2'
 * '<S40>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals'
 * '<S41>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1'
 * '<S42>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals2'
 * '<S43>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals3'
 * '<S44>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals4'
 * '<S45>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals5'
 * '<S46>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals6'
 * '<S47>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/FindCoordinates'
 * '<S48>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S49>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S50>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S51>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S52>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S53>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S54>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S55>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals'
 * '<S56>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1'
 * '<S57>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals2'
 * '<S58>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals3'
 * '<S59>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals4'
 * '<S60>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals5'
 * '<S61>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals6'
 * '<S62>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/FindCoordinates'
 * '<S63>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S64>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S65>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S66>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S67>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S68>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S69>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S70>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1'
 * '<S71>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Gain Scheduling1'
 * '<S72>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Reference Airgap Base'
 * '<S73>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Reset'
 * '<S74>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder'
 * '<S75>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Anti-windup'
 * '<S76>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/D Gain'
 * '<S77>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Filter'
 * '<S78>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Filter ICs'
 * '<S79>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/I Gain'
 * '<S80>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Ideal P Gain'
 * '<S81>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Ideal P Gain Fdbk'
 * '<S82>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Integrator'
 * '<S83>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Integrator ICs'
 * '<S84>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/N Copy'
 * '<S85>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/N Gain'
 * '<S86>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/P Copy'
 * '<S87>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Parallel P Gain'
 * '<S88>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Reset Signal'
 * '<S89>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Saturation'
 * '<S90>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Saturation Fdbk'
 * '<S91>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Sum'
 * '<S92>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Sum Fdbk'
 * '<S93>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tracking Mode'
 * '<S94>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tracking Mode Sum'
 * '<S95>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tsamp - Integral'
 * '<S96>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tsamp - Ngain'
 * '<S97>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/postSat Signal'
 * '<S98>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/preSat Signal'
 * '<S99>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S100>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S101>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S102>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/D Gain/External Parameters'
 * '<S103>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Filter/Disc. Forward Euler Filter'
 * '<S104>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Filter ICs/Internal IC - Filter'
 * '<S105>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/I Gain/External Parameters'
 * '<S106>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S107>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S108>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Integrator/Discrete'
 * '<S109>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Integrator ICs/Internal IC'
 * '<S110>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/N Copy/Disabled'
 * '<S111>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/N Gain/External Parameters'
 * '<S112>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/P Copy/Disabled'
 * '<S113>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S114>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Reset Signal/External Reset'
 * '<S115>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Saturation/Enabled'
 * '<S116>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S117>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Sum/Sum_PID'
 * '<S118>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Sum Fdbk/Disabled'
 * '<S119>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tracking Mode/Disabled'
 * '<S120>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S121>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S122>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S123>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/postSat Signal/Forward_Path'
 * '<S124>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1/preSat Signal/Forward_Path'
 * '<S125>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Gain Scheduling1/PIDFilter Scheduling'
 * '<S126>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2'
 * '<S127>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S128>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S129>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S130>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S131>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S132>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S133>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S134>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S135>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S136>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S137>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S138>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S139>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S140>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S141>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S142>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S143>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S144>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S145>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S146>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S147>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S148>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S149>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S150>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S151>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S152>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S153>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S154>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S155>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S156>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S157>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S158>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S159>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S160>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S161>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S162>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S163>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S164>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S165>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S166>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S167>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S168>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S169>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S170>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S171>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S172>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S173>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S174>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S175>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S176>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S177>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Degrees to Radians'
 * '<S178>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Degrees to Radians1'
 * '<S179>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Gain Scheduling1'
 * '<S180>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller'
 * '<S181>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Radians to Degrees'
 * '<S182>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Radians to Degrees1'
 * '<S183>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder'
 * '<S184>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Gain Scheduling1/PIDFilter Scheduling'
 * '<S185>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup'
 * '<S186>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/D Gain'
 * '<S187>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter'
 * '<S188>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter ICs'
 * '<S189>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/I Gain'
 * '<S190>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain'
 * '<S191>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain Fdbk'
 * '<S192>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator'
 * '<S193>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator ICs'
 * '<S194>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Copy'
 * '<S195>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Gain'
 * '<S196>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/P Copy'
 * '<S197>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Parallel P Gain'
 * '<S198>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Reset Signal'
 * '<S199>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation'
 * '<S200>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation Fdbk'
 * '<S201>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum'
 * '<S202>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum Fdbk'
 * '<S203>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode'
 * '<S204>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode Sum'
 * '<S205>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Integral'
 * '<S206>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Ngain'
 * '<S207>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/postSat Signal'
 * '<S208>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/preSat Signal'
 * '<S209>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel'
 * '<S210>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S211>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S212>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/D Gain/External Parameters'
 * '<S213>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter/Disc. Forward Euler Filter'
 * '<S214>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter ICs/Internal IC - Filter'
 * '<S215>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/I Gain/External Parameters'
 * '<S216>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain/Passthrough'
 * '<S217>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain Fdbk/Disabled'
 * '<S218>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator/Discrete'
 * '<S219>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator ICs/Internal IC'
 * '<S220>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Copy/Disabled'
 * '<S221>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Gain/External Parameters'
 * '<S222>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/P Copy/Disabled'
 * '<S223>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Parallel P Gain/External Parameters'
 * '<S224>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Reset Signal/External Reset'
 * '<S225>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation/Enabled'
 * '<S226>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation Fdbk/Disabled'
 * '<S227>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum/Sum_PID'
 * '<S228>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum Fdbk/Disabled'
 * '<S229>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode/Disabled'
 * '<S230>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode Sum/Passthrough'
 * '<S231>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Integral/Passthrough'
 * '<S232>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Ngain/Passthrough'
 * '<S233>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/postSat Signal/Forward_Path'
 * '<S234>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/preSat Signal/Forward_Path'
 * '<S235>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2'
 * '<S236>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S237>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S238>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S239>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S240>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S241>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S242>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S243>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S244>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S245>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S246>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S247>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S248>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S249>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S250>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S251>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S252>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S253>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S254>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S255>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S256>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S257>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S258>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S259>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S260>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S261>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S262>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S263>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S264>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S265>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S266>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S267>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S268>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S269>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S270>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S271>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S272>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S273>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S274>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S275>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S276>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S277>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S278>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S279>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S280>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S281>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S282>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S283>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S284>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S285>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S286>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Degrees to Radians'
 * '<S287>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Degrees to Radians1'
 * '<S288>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Gain Scheduling1'
 * '<S289>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller'
 * '<S290>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Radians to Degrees'
 * '<S291>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder'
 * '<S292>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Gain Scheduling1/PIDFilter Scheduling'
 * '<S293>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup'
 * '<S294>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/D Gain'
 * '<S295>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter'
 * '<S296>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter ICs'
 * '<S297>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/I Gain'
 * '<S298>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain'
 * '<S299>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain Fdbk'
 * '<S300>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator'
 * '<S301>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator ICs'
 * '<S302>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Copy'
 * '<S303>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Gain'
 * '<S304>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/P Copy'
 * '<S305>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Parallel P Gain'
 * '<S306>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Reset Signal'
 * '<S307>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation'
 * '<S308>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation Fdbk'
 * '<S309>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum'
 * '<S310>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum Fdbk'
 * '<S311>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode'
 * '<S312>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode Sum'
 * '<S313>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Integral'
 * '<S314>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Ngain'
 * '<S315>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/postSat Signal'
 * '<S316>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/preSat Signal'
 * '<S317>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel'
 * '<S318>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S319>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S320>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/D Gain/External Parameters'
 * '<S321>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter/Disc. Forward Euler Filter'
 * '<S322>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter ICs/Internal IC - Filter'
 * '<S323>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/I Gain/External Parameters'
 * '<S324>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain/Passthrough'
 * '<S325>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain Fdbk/Disabled'
 * '<S326>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator/Discrete'
 * '<S327>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator ICs/Internal IC'
 * '<S328>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Copy/Disabled'
 * '<S329>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Gain/External Parameters'
 * '<S330>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/P Copy/Disabled'
 * '<S331>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Parallel P Gain/External Parameters'
 * '<S332>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Reset Signal/External Reset'
 * '<S333>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation/Enabled'
 * '<S334>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation Fdbk/Disabled'
 * '<S335>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum/Sum_PID'
 * '<S336>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum Fdbk/Disabled'
 * '<S337>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode/Disabled'
 * '<S338>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode Sum/Passthrough'
 * '<S339>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Integral/Passthrough'
 * '<S340>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Ngain/Passthrough'
 * '<S341>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/postSat Signal/Forward_Path'
 * '<S342>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/preSat Signal/Forward_Path'
 * '<S343>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2'
 * '<S344>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S345>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S346>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S347>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S348>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S349>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S350>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S351>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S352>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S353>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S354>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S355>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S356>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S357>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S358>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S359>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S360>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S361>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S362>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S363>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S364>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S365>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S366>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S367>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S368>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S369>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S370>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S371>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S372>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S373>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S374>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S375>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S376>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S377>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S378>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S379>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S380>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S381>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S382>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S383>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S384>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S385>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S386>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S387>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S388>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S389>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S390>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S391>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S392>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S393>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S394>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/MATLAB Function'
 * '<S395>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/Turn motor force//torque on'
 * '<S396>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/Turn motor force//torque on1'
 * '<S397>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Data Center/Power Measurements'
 * '<S398>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter'
 * '<S399>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter'
 * '<S400>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Correct1'
 * '<S401>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Output'
 * '<S402>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Predict'
 * '<S403>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Correct1/Correct'
 * '<S404>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Output/MATLAB Function'
 * '<S405>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Predict/Predict'
 * '<S406>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver/Force Divider1'
 * '<S407>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver/Force Divider1/MATLAB Function'
 * '<S408>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll'
 * '<S409>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Filter Noisy Signals1'
 * '<S410>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1'
 * '<S411>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals'
 * '<S412>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals1'
 * '<S413>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals2'
 * '<S414>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals3'
 * '<S415>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals4'
 * '<S416>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals5'
 * '<S417>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals6'
 * '<S418>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/FindCoordinates'
 * '<S419>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S420>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S421>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S422>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S423>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S424>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S425>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S426>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S427>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1'
 * '<S428>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2'
 * '<S429>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Compare To Constant'
 * '<S430>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Anti-windup'
 * '<S431>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/D Gain'
 * '<S432>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter'
 * '<S433>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter ICs'
 * '<S434>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/I Gain'
 * '<S435>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain'
 * '<S436>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain Fdbk'
 * '<S437>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator'
 * '<S438>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator ICs'
 * '<S439>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Copy'
 * '<S440>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Gain'
 * '<S441>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/P Copy'
 * '<S442>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Parallel P Gain'
 * '<S443>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Reset Signal'
 * '<S444>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation'
 * '<S445>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation Fdbk'
 * '<S446>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum'
 * '<S447>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum Fdbk'
 * '<S448>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode'
 * '<S449>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode Sum'
 * '<S450>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Integral'
 * '<S451>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Ngain'
 * '<S452>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/postSat Signal'
 * '<S453>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/preSat Signal'
 * '<S454>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Anti-windup/Back Calculation'
 * '<S455>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/D Gain/Internal Parameters'
 * '<S456>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator'
 * '<S457>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S458>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S459>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S460>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/I Gain/Internal Parameters'
 * '<S461>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S462>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S463>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator/Discrete'
 * '<S464>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator ICs/Internal IC'
 * '<S465>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S466>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Gain/Passthrough'
 * '<S467>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/P Copy/Disabled'
 * '<S468>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Parallel P Gain/Internal Parameters'
 * '<S469>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Reset Signal/External Reset'
 * '<S470>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation/Enabled'
 * '<S471>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S472>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum/Sum_PID'
 * '<S473>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum Fdbk/Disabled'
 * '<S474>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode/Disabled'
 * '<S475>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S476>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S477>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S478>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/postSat Signal/Forward_Path'
 * '<S479>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/preSat Signal/Forward_Path'
 * '<S480>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Anti-windup'
 * '<S481>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/D Gain'
 * '<S482>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter'
 * '<S483>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter ICs'
 * '<S484>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/I Gain'
 * '<S485>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain'
 * '<S486>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain Fdbk'
 * '<S487>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator'
 * '<S488>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator ICs'
 * '<S489>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Copy'
 * '<S490>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Gain'
 * '<S491>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/P Copy'
 * '<S492>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Parallel P Gain'
 * '<S493>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Reset Signal'
 * '<S494>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation'
 * '<S495>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation Fdbk'
 * '<S496>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum'
 * '<S497>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum Fdbk'
 * '<S498>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode'
 * '<S499>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode Sum'
 * '<S500>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Integral'
 * '<S501>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Ngain'
 * '<S502>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/postSat Signal'
 * '<S503>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/preSat Signal'
 * '<S504>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Anti-windup/Back Calculation'
 * '<S505>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/D Gain/Internal Parameters'
 * '<S506>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator'
 * '<S507>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S508>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S509>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S510>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/I Gain/Internal Parameters'
 * '<S511>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S512>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S513>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator/Discrete'
 * '<S514>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator ICs/Internal IC'
 * '<S515>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S516>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Gain/Passthrough'
 * '<S517>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/P Copy/Disabled'
 * '<S518>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S519>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Reset Signal/External Reset'
 * '<S520>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation/Enabled'
 * '<S521>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S522>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum/Sum_PID'
 * '<S523>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum Fdbk/Disabled'
 * '<S524>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode/Disabled'
 * '<S525>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S526>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S527>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S528>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/postSat Signal/Forward_Path'
 * '<S529>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/preSat Signal/Forward_Path'
 * '<S530>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1'
 * '<S531>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Anti-windup'
 * '<S532>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/D Gain'
 * '<S533>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter'
 * '<S534>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter ICs'
 * '<S535>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/I Gain'
 * '<S536>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Ideal P Gain'
 * '<S537>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Ideal P Gain Fdbk'
 * '<S538>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Integrator'
 * '<S539>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Integrator ICs'
 * '<S540>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/N Copy'
 * '<S541>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/N Gain'
 * '<S542>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/P Copy'
 * '<S543>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Parallel P Gain'
 * '<S544>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Reset Signal'
 * '<S545>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Saturation'
 * '<S546>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Saturation Fdbk'
 * '<S547>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Sum'
 * '<S548>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Sum Fdbk'
 * '<S549>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tracking Mode'
 * '<S550>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tracking Mode Sum'
 * '<S551>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tsamp - Integral'
 * '<S552>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tsamp - Ngain'
 * '<S553>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/postSat Signal'
 * '<S554>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/preSat Signal'
 * '<S555>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S556>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S557>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S558>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/D Gain/External Parameters'
 * '<S559>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter/Differentiator'
 * '<S560>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S561>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S562>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S563>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/I Gain/External Parameters'
 * '<S564>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S565>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S566>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Integrator/Discrete'
 * '<S567>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Integrator ICs/Internal IC'
 * '<S568>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S569>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/N Gain/Passthrough'
 * '<S570>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/P Copy/Disabled'
 * '<S571>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S572>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Reset Signal/Disabled'
 * '<S573>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Saturation/Enabled'
 * '<S574>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S575>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Sum/Sum_PID'
 * '<S576>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Sum Fdbk/Disabled'
 * '<S577>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tracking Mode/Disabled'
 * '<S578>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S579>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S580>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S581>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/postSat Signal/Forward_Path'
 * '<S582>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem/Airgap controller1/preSat Signal/Forward_Path'
 * '<S583>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1'
 * '<S584>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Anti-windup'
 * '<S585>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/D Gain'
 * '<S586>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter'
 * '<S587>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter ICs'
 * '<S588>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/I Gain'
 * '<S589>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Ideal P Gain'
 * '<S590>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Ideal P Gain Fdbk'
 * '<S591>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Integrator'
 * '<S592>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Integrator ICs'
 * '<S593>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/N Copy'
 * '<S594>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/N Gain'
 * '<S595>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/P Copy'
 * '<S596>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Parallel P Gain'
 * '<S597>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Reset Signal'
 * '<S598>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Saturation'
 * '<S599>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Saturation Fdbk'
 * '<S600>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Sum'
 * '<S601>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Sum Fdbk'
 * '<S602>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tracking Mode'
 * '<S603>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tracking Mode Sum'
 * '<S604>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tsamp - Integral'
 * '<S605>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tsamp - Ngain'
 * '<S606>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/postSat Signal'
 * '<S607>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/preSat Signal'
 * '<S608>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S609>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S610>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S611>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/D Gain/External Parameters'
 * '<S612>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter/Differentiator'
 * '<S613>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S614>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S615>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S616>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/I Gain/External Parameters'
 * '<S617>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S618>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S619>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Integrator/Discrete'
 * '<S620>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Integrator ICs/Internal IC'
 * '<S621>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S622>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/N Gain/Passthrough'
 * '<S623>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/P Copy/Disabled'
 * '<S624>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S625>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Reset Signal/Disabled'
 * '<S626>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Saturation/Enabled'
 * '<S627>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S628>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Sum/Sum_PID'
 * '<S629>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Sum Fdbk/Disabled'
 * '<S630>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tracking Mode/Disabled'
 * '<S631>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S632>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S633>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S634>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/postSat Signal/Forward_Path'
 * '<S635>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem1/Airgap controller1/preSat Signal/Forward_Path'
 * '<S636>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1'
 * '<S637>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Anti-windup'
 * '<S638>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/D Gain'
 * '<S639>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter'
 * '<S640>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter ICs'
 * '<S641>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/I Gain'
 * '<S642>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Ideal P Gain'
 * '<S643>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Ideal P Gain Fdbk'
 * '<S644>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Integrator'
 * '<S645>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Integrator ICs'
 * '<S646>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/N Copy'
 * '<S647>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/N Gain'
 * '<S648>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/P Copy'
 * '<S649>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Parallel P Gain'
 * '<S650>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Reset Signal'
 * '<S651>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Saturation'
 * '<S652>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Saturation Fdbk'
 * '<S653>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Sum'
 * '<S654>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Sum Fdbk'
 * '<S655>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tracking Mode'
 * '<S656>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tracking Mode Sum'
 * '<S657>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tsamp - Integral'
 * '<S658>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tsamp - Ngain'
 * '<S659>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/postSat Signal'
 * '<S660>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/preSat Signal'
 * '<S661>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S662>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S663>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S664>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/D Gain/External Parameters'
 * '<S665>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter/Differentiator'
 * '<S666>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S667>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S668>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S669>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/I Gain/External Parameters'
 * '<S670>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S671>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S672>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Integrator/Discrete'
 * '<S673>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Integrator ICs/Internal IC'
 * '<S674>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S675>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/N Gain/Passthrough'
 * '<S676>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/P Copy/Disabled'
 * '<S677>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S678>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Reset Signal/Disabled'
 * '<S679>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Saturation/Enabled'
 * '<S680>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S681>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Sum/Sum_PID'
 * '<S682>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Sum Fdbk/Disabled'
 * '<S683>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tracking Mode/Disabled'
 * '<S684>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S685>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S686>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S687>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/postSat Signal/Forward_Path'
 * '<S688>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem2/Airgap controller1/preSat Signal/Forward_Path'
 * '<S689>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1'
 * '<S690>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Anti-windup'
 * '<S691>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/D Gain'
 * '<S692>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter'
 * '<S693>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter ICs'
 * '<S694>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/I Gain'
 * '<S695>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Ideal P Gain'
 * '<S696>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Ideal P Gain Fdbk'
 * '<S697>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Integrator'
 * '<S698>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Integrator ICs'
 * '<S699>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/N Copy'
 * '<S700>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/N Gain'
 * '<S701>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/P Copy'
 * '<S702>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Parallel P Gain'
 * '<S703>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Reset Signal'
 * '<S704>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Saturation'
 * '<S705>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Saturation Fdbk'
 * '<S706>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Sum'
 * '<S707>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Sum Fdbk'
 * '<S708>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tracking Mode'
 * '<S709>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tracking Mode Sum'
 * '<S710>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tsamp - Integral'
 * '<S711>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tsamp - Ngain'
 * '<S712>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/postSat Signal'
 * '<S713>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/preSat Signal'
 * '<S714>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S715>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S716>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S717>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/D Gain/External Parameters'
 * '<S718>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter/Differentiator'
 * '<S719>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S720>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S721>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S722>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/I Gain/External Parameters'
 * '<S723>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S724>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S725>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Integrator/Discrete'
 * '<S726>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Integrator ICs/Internal IC'
 * '<S727>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S728>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/N Gain/Passthrough'
 * '<S729>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/P Copy/Disabled'
 * '<S730>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S731>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Reset Signal/Disabled'
 * '<S732>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Saturation/Enabled'
 * '<S733>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S734>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Sum/Sum_PID'
 * '<S735>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Sum Fdbk/Disabled'
 * '<S736>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tracking Mode/Disabled'
 * '<S737>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S738>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S739>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S740>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/postSat Signal/Forward_Path'
 * '<S741>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem3/Airgap controller1/preSat Signal/Forward_Path'
 * '<S742>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current'
 * '<S743>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current1'
 * '<S744>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current2'
 * '<S745>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current3'
 * '<S746>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Temperature, Current and Emergency Break/Control Airgaps'
 * '<S747>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Temperature, Current and Emergency Break/Control Temperature'
 */
#endif           /* RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_h_ */
