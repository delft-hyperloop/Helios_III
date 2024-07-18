/*
 * PIDcontroller4CoreCentralizedTestReadyMotor.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIDcontroller4CoreCentralizedTestReadyMotor".
 *
 * Model version              : 6.284
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jun 28 16:03:05 2024
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

/* Block signals for system '<S24>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S24>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block states (default storage) for system '<S24>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T obj;/* '<S24>/Moving Average' */
  boolean_T objisempty;                /* '<S24>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S36>/FindCoordinates' */
typedef struct {
  real_T avg_g;                        /* '<S36>/FindCoordinates' */
  real_T pitch;                        /* '<S36>/FindCoordinates' */
  real_T roll;                         /* '<S36>/FindCoordinates' */
} B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S70>/Moving Average1' */
typedef struct {
  real_T MovingAverage1;               /* '<S70>/Moving Average1' */
} B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block states (default storage) for system '<S70>/Moving Average1' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T obj;/* '<S70>/Moving Average1' */
  boolean_T objisempty;                /* '<S70>/Moving Average1' */
} DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S71>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S71>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T;

/* Block states (default storage) for system '<S71>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3_T
    obj;                               /* '<S71>/Moving Average' */
  boolean_T objisempty;                /* '<S71>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T;

/* Block signals for system '<S405>/Correct1' */
typedef struct {
  boolean_T blockOrdering;             /* '<S406>/Correct' */
} B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<S405>/Output' */
typedef struct {
  real_T DataStoreRead[6];             /* '<S407>/Data Store Read' */
  boolean_T uBlockOrdering;            /* '<S407>/uBlockOrdering' */
} B_Output_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals for system '<Root>/Moving Average' */
typedef struct {
  real_T MovingAverage[3];             /* '<Root>/Moving Average' */
} B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T;

/* Block states (default storage) for system '<Root>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e3x_T
    obj;                               /* '<Root>/Moving Average' */
  boolean_T objisempty;                /* '<Root>/Moving Average' */
} DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T;

/* Block signals for system '<S22>/Cap requested current1' */
typedef struct {
  real_T out_req_I;                    /* '<S22>/Cap requested current1' */
} B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block signals (default storage) */
typedef struct {
  real_T Tsamp;                        /* '<S525>/Tsamp' */
  real_T Tsamp_b;                      /* '<S475>/Tsamp' */
  real_T Product1;                     /* '<S30>/Product1' */
  real_T Gain;                         /* '<S30>/Gain' */
  real_T Subtract5;                    /* '<S73>/Subtract5' */
  real_T Delay1[4];                    /* '<Root>/Delay1' */
  real_T Switch;                       /* '<S73>/Switch' */
  real_T Tsamp_k;                      /* '<S155>/Tsamp' */
  real_T Gain_l;                       /* '<S412>/Gain' */
  real_T Switch1_a;                    /* '<S436>/Switch1' */
  real_T Switch1_j;                    /* '<S437>/Switch1' */
  real_T Switch1_e;                    /* '<S438>/Switch1' */
  real_T Switch1_a4;                   /* '<S439>/Switch1' */
  real_T Switch1_h;                    /* '<S443>/Switch1' */
  real_T Delay2[3];                    /* '<Root>/Delay2' */
  real_T Switch_n[4];                  /* '<S8>/Switch' */
  real_T Gain_h;                       /* '<S8>/Gain' */
  real_T Switch1_o;                    /* '<S440>/Switch1' */
  real_T Switch1_g;                    /* '<S441>/Switch1' */
  real_T Switch_k;                     /* '<S433>/Switch' */
  real_T Switch1_d;                    /* '<S8>/Switch1' */
  real_T Gravity;                      /* '<S3>/Gravity' */
  real_T Gain1;                        /* '<S3>/Gain1' */
  real_T Switch2_o;                    /* '<S8>/Switch2' */
  real_T Add;                          /* '<S5>/Add' */
  real_T Gain4;                        /* '<S3>/Gain4' */
  real_T Add2;                         /* '<S3>/Add2' */
  real_T Tom;                          /* '<S8>/To m' */
  real_T Switch1_n;                    /* '<S442>/Switch1' */
  real_T Switch_c;                     /* '<S434>/Switch' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T Tomm;                         /* '<S8>/To mm' */
  real_T Add4;                         /* '<S8>/Add4' */
  real_T Add5;                         /* '<S8>/Add5' */
  real_T Tom_h;                        /* '<S7>/To m' */
  real_T Tomm_d;                       /* '<S7>/To mm' */
  real_T Subtract1;                    /* '<S10>/Subtract1' */
  real_T Switch2_g[3];                 /* '<Root>/Switch2' */
  real_T error;                        /* '<S31>/Sum' */
  real_T NProdOut;                     /* '<S111>/NProd Out' */
  real_T Sum;                          /* '<S117>/Sum' */
  real_T Gain_g;                       /* '<S74>/Gain' */
  real_T x_i1;                         /* '<S177>/Memory' */
  real_T y_i1;                         /* '<S177>/Memory1' */
  real_T Gain10;                       /* '<S177>/Gain10' */
  real_T Subtract5_o;                  /* '<S185>/Subtract5' */
  real_T Switch_o;                     /* '<S185>/Switch' */
  real_T Tsamp_m;                      /* '<S267>/Tsamp' */
  real_T setpointpitch;                /* '<S32>/Plus' */
  real_T Gain2;                        /* '<S32>/Gain2' */
  real_T NProdOut_e;                   /* '<S223>/NProd Out' */
  real_T Product;                      /* '<S32>/Product' */
  real_T Subtract5_l;                  /* '<S295>/Subtract5' */
  real_T Switch_p;                     /* '<S295>/Switch' */
  real_T Tsamp_h;                      /* '<S377>/Tsamp' */
  real_T setpointroll;                 /* '<S34>/Add' */
  real_T Gain2_e;                      /* '<S34>/Gain2' */
  real_T NProdOut_k;                   /* '<S333>/NProd Out' */
  real_T Product_h;                    /* '<S34>/Product' */
  real_T Flip1[30];                    /* '<S25>/Flip1' */
  real_T Max;                          /* '<S25>/Max' */
  real_T Subtract4;                    /* '<S25>/Subtract4' */
  real_T Switch2_i;                    /* '<S25>/Switch2' */
  real_T Flip1_c[30];                  /* '<S26>/Flip1' */
  real_T Max_j;                        /* '<S26>/Max' */
  real_T Subtract4_d;                  /* '<S26>/Subtract4' */
  real_T Switch2_ot;                   /* '<S26>/Switch2' */
  real_T Flip1_p[30];                  /* '<S27>/Flip1' */
  real_T Max_b;                        /* '<S27>/Max' */
  real_T Subtract4_a;                  /* '<S27>/Subtract4' */
  real_T Switch2_c;                    /* '<S27>/Switch2' */
  real_T Flip1_o[30];                  /* '<S28>/Flip1' */
  real_T Max_i;                        /* '<S28>/Max' */
  real_T Subtract4_n;                  /* '<S28>/Subtract4' */
  real_T Switch2_a;                    /* '<S28>/Switch2' */
  real_T Sum1;                         /* '<S402>/Sum1' */
  real_T Delay1_i;                     /* '<S25>/Delay1' */
  real_T Delay;                        /* '<S25>/Delay' */
  real_T Switch4;                      /* '<S25>/Switch4' */
  real_T Switch6;                      /* '<S25>/Switch6' */
  real_T Switch3;                      /* '<S25>/Switch3' */
  real_T Switch5;                      /* '<S25>/Switch5' */
  real_T Switch7;                      /* '<S25>/Switch7' */
  real_T Delay1_b;                     /* '<S26>/Delay1' */
  real_T Delay_o;                      /* '<S26>/Delay' */
  real_T Switch4_g;                    /* '<S26>/Switch4' */
  real_T Switch6_a;                    /* '<S26>/Switch6' */
  real_T Switch3_h;                    /* '<S26>/Switch3' */
  real_T Switch5_c;                    /* '<S26>/Switch5' */
  real_T Switch7_h;                    /* '<S26>/Switch7' */
  real_T Delay1_h;                     /* '<S27>/Delay1' */
  real_T Delay_g;                      /* '<S27>/Delay' */
  real_T Switch4_n;                    /* '<S27>/Switch4' */
  real_T Switch6_j;                    /* '<S27>/Switch6' */
  real_T Switch3_m;                    /* '<S27>/Switch3' */
  real_T Switch5_d;                    /* '<S27>/Switch5' */
  real_T Switch7_e;                    /* '<S27>/Switch7' */
  real_T Delay1_n;                     /* '<S28>/Delay1' */
  real_T Delay_f;                      /* '<S28>/Delay' */
  real_T Switch4_f;                    /* '<S28>/Switch4' */
  real_T Switch6_b;                    /* '<S28>/Switch6' */
  real_T Switch3_p;                    /* '<S28>/Switch3' */
  real_T Switch5_g;                    /* '<S28>/Switch5' */
  real_T Switch7_p;                    /* '<S28>/Switch7' */
  real_T Switch_l;                     /* '<S99>/Switch' */
  real_T error_h;                      /* '<S71>/Switch3' */
  real_T SumI4;                        /* '<S151>/SumI4' */
  real_T Switch_j;                     /* '<S211>/Switch' */
  real_T SumI4_c;                      /* '<S263>/SumI4' */
  real_T Switch_d;                     /* '<S321>/Switch' */
  real_T SumI4_o;                      /* '<S373>/SumI4' */
  real_T Gain_gj;                      /* '<S7>/Gain' */
  real_T Switch_e[4];                  /* '<S7>/Switch' */
  real_T Switch1_eg;                   /* '<S7>/Switch1' */
  real_T Switch2_k;                    /* '<S7>/Switch2' */
  real_T Delay_m;                      /* '<S8>/Delay' */
  real_T Delay1_j;                     /* '<S8>/Delay1' */
  real_T Delay2_n;                     /* '<S8>/Delay2' */
  real_T Gain1_k;                      /* '<S8>/Gain1' */
  real_T Gain2_d;                      /* '<S8>/Gain2' */
  real_T Gain3;                        /* '<S8>/Gain3' */
  real_T Saturation;                   /* '<S10>/Saturation' */
  real_T Gain2_c;                      /* '<S10>/Gain2' */
  real_T Gain5;                        /* '<S10>/Gain5' */
  real_T Gain6;                        /* '<S10>/Gain6' */
  real_T Subtract;                     /* '<S10>/Subtract' */
  real_T TmpSignalConversionAtDelay1Inport1[4];/* '<Root>/Data Center' */
  real_T TmpSignalConversionAtDelay2Inport1[3];/* '<Root>/Kalman Input Adjustments' */
  real_T Gain_c;                       /* '<S5>/Gain' */
  real_T Product_i[3];                 /* '<S5>/Product' */
  real_T Product1_l;                   /* '<S5>/Product1' */
  real_T Product2;                     /* '<S5>/Product2' */
  real_T SumI4_g;                      /* '<S471>/SumI4' */
  real_T SumI4_k;                      /* '<S521>/SumI4' */
  real_T Switch3_h5;                   /* '<S20>/Switch3' */
  boolean_T Equal;                     /* '<Root>/Equal' */
  boolean_T AND;                       /* '<S70>/AND' */
  boolean_T Equal_c;                   /* '<S20>/Equal' */
  boolean_T Equal_f;                   /* '<S8>/Equal' */
  boolean_T Equal1;                    /* '<S8>/Equal1' */
  boolean_T Equal2;                    /* '<S8>/Equal2' */
  boolean_T OR;                        /* '<S5>/OR' */
  boolean_T Equal_k;                   /* '<S72>/Equal' */
  boolean_T AND_e;                     /* '<S184>/AND' */
  boolean_T Equal_a;                   /* '<S32>/Equal' */
  boolean_T AND_i;                     /* '<S294>/AND' */
  boolean_T Equal_km;                  /* '<S34>/Equal' */
  boolean_T GreaterThan;               /* '<S70>/GreaterThan' */
  boolean_T GreaterThan_n;             /* '<S184>/GreaterThan' */
  boolean_T GreaterThan_f;             /* '<S294>/GreaterThan' */
  boolean_T Equal_l;                   /* '<S7>/Equal' */
  boolean_T Equal1_p;                  /* '<S7>/Equal1' */
  boolean_T Equal2_g;                  /* '<S7>/Equal2' */
  boolean_T blockOrdering;             /* '<S416>/Correct' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent3;           /* '<S22>/Cap requested current3' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent2;           /* '<S22>/Cap requested current2' */
  B_Caprequestedcurrent1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_Caprequestedcurrent1;           /* '<S22>/Cap requested current1' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_kaa;                 /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_ka;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_kw;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1_g;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_h;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zzhe;    /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_k;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zzh;     /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_f;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zz;      /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_n;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
    MovingAverage1_pnaevvfpgh5z;       /* '<Root>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_ca_T
    MovingAverage_e;                   /* '<Root>/Moving Average' */
  B_Output_PIDcontroller4CoreCentralizedTestReadyMotor_T Output_n;/* '<S414>/Output' */
  B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T Correct1_l;/* '<S414>/Correct1' */
  B_Output_PIDcontroller4CoreCentralizedTestReadyMotor_T Output;/* '<S405>/Output' */
  B_Correct1_PIDcontroller4CoreCentralizedTestReadyMotor_T Correct1;/* '<S405>/Correct1' */
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage2;/* '<S70>/Moving Average1' */
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5;        /* '<S70>/Moving Average1' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T
    MovingAverage1_pnaevvfpgh;         /* '<S71>/Moving Average' */
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpg;          /* '<S70>/Moving Average1' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T
    MovingAverage_g;                   /* '<S71>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_c_T
    MovingAverage_pnaevvfpgh5zzhe;     /* '<S71>/Moving Average' */
  B_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfp;           /* '<S70>/Moving Average1' */
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_FindCoordinates_d;              /* '<S37>/FindCoordinates' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zzh;      /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zz;       /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5z;        /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvf;            /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5;         /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevv;             /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh;          /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaev;              /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpg;           /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnae;               /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfp;            /* '<S24>/Moving Average' */
  B_FindCoordinates_PIDcontroller4CoreCentralizedTestReadyMotor_T
    sf_FindCoordinates;                /* '<S36>/FindCoordinates' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvf;             /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevv;              /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaev;               /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pna;                /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnae;                /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pn;                 /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pna;                 /* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1_p;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_pn;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_p;/* '<S24>/Moving Average' */
  B_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage;/* '<S24>/Moving Average' */
} B_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_e_T obj;/* '<S402>/Moving Average' */
  dsp_simulink_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_o_T
    obj_i;                             /* '<S426>/Moving Average' */
  real_T Delay1_DSTATE;                /* '<S20>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S530>/Integrator' */
  real_T UD_DSTATE;                    /* '<S523>/UD' */
  real_T Integrator_DSTATE_j;          /* '<S480>/Integrator' */
  real_T UD_DSTATE_p;                  /* '<S473>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE_e[400];         /* '<S30>/Delay1' */
  real_T Delay_DSTATE[400];            /* '<S30>/Delay' */
  real_T Delay1_DSTATE_ez[4];          /* '<Root>/Delay1' */
  real_T Integrator_DSTATE_jc;         /* '<S160>/Integrator' */
  real_T UD_DSTATE_f;                  /* '<S153>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S71>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S71>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_f;/* '<S70>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S8>/Discrete-Time Integrator' */
  real_T Delay2_DSTATE[3];             /* '<Root>/Delay2' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S5>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S5>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE_k;/* '<S5>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S5>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator1_DSTATE_g;/* '<S8>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE_l;/* '<S8>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S10>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S108>/Integrator' */
  real_T Filter_DSTATE;                /* '<S103>/Filter' */
  real_T Integrator_DSTATE_l;          /* '<S272>/Integrator' */
  real_T UD_DSTATE_o;                  /* '<S265>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE_b;/* '<S184>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE_c;          /* '<S220>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S215>/Filter' */
  real_T Integrator_DSTATE_lg;         /* '<S382>/Integrator' */
  real_T UD_DSTATE_l;                  /* '<S375>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE_l;/* '<S294>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE_lw;         /* '<S330>/Integrator' */
  real_T Filter_DSTATE_h;              /* '<S325>/Filter' */
  real_T Delay3_DSTATE;                /* '<S25>/Delay3' */
  real_T Delay2_DSTATE_l;              /* '<S25>/Delay2' */
  real_T Delay3_DSTATE_m;              /* '<S26>/Delay3' */
  real_T Delay2_DSTATE_b;              /* '<S26>/Delay2' */
  real_T Delay3_DSTATE_i;              /* '<S27>/Delay3' */
  real_T Delay2_DSTATE_g;              /* '<S27>/Delay2' */
  real_T Delay3_DSTATE_o;              /* '<S28>/Delay3' */
  real_T Delay2_DSTATE_bo;             /* '<S28>/Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S402>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE_c;              /* '<S25>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S25>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_d[2];            /* '<S25>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_c;/* '<S25>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_a;              /* '<S26>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S26>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_e[2];            /* '<S26>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_d;/* '<S26>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_l;              /* '<S27>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_gr;/* '<S27>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_i[2];            /* '<S27>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_e;/* '<S27>/Discrete-Time Integrator1' */
  real_T Delay1_DSTATE_g;              /* '<S28>/Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_op;/* '<S28>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_k[2];            /* '<S28>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE_h;/* '<S28>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_it;/* '<S70>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S184>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_in;/* '<S294>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_c;               /* '<S8>/Delay' */
  real_T Delay1_DSTATE_n;              /* '<S8>/Delay1' */
  real_T Delay2_DSTATE_c;              /* '<S8>/Delay2' */
  real_T DiscreteTimeIntegrator1_DSTATE_ll;/* '<S10>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator3_DSTATE_g;/* '<S10>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S10>/Discrete-Time Integrator4' */
  real_T Memory_PreviousInput;         /* '<S177>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S177>/Memory1' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA[3];              /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB[3];              /* '<Root>/Derivative' */
  real_T TimeStampA_l;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_g[3];            /* '<Root>/Derivative1' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_l[3];            /* '<Root>/Derivative1' */
  real_T P[36];                        /* '<S405>/DataStoreMemory - P' */
  real_T x[6];                         /* '<S405>/DataStoreMemory - x' */
  real_T P_h[36];                      /* '<S414>/DataStoreMemory - P' */
  real_T x_n[6];                       /* '<S414>/DataStoreMemory - x' */
  int32_T clockTickCounter;            /* '<S30>/Pulse Generator' */
  int32_T counter;                     /* '<S30>/Sine Wave4' */
  int32_T counter_h;                   /* '<S30>/Sine Wave5' */
  int32_T counter_o;                   /* '<S30>/Sine Wave6' */
  int32_T counter_a;                   /* '<S30>/Sine Wave7' */
  int32_T counter_i;                   /* '<S30>/Sine Wave1' */
  int32_T counter_m;                   /* '<S30>/Sine Wave2' */
  int32_T counter_n;                   /* '<S30>/Sine Wave3' */
  uint32_T m_bpIndex[2];               /* '<S21>/2-D Lookup Table2' */
  uint32_T m_bpIndex_a[2];             /* '<S21>/2-D Lookup Table1' */
  uint32_T m_bpIndex_c[2];             /* '<S21>/2-D Lookup Table3' */
  uint32_T m_bpIndex_j[2];             /* '<S21>/2-D Lookup Table4' */
  uint32_T m_bpIndex_b[5];             /* '<S423>/2-D Lookup Table3' */
  uint32_T m_Cache01;                  /* '<S423>/2-D Lookup Table3' */
  uint32_T m_Cache02[4];               /* '<S423>/2-D Lookup Table3' */
  uint32_T m_bpIndex_f[31];            /* '<S25>/2-D Lookup Table2' */
  uint32_T m_Cache01_m[30];            /* '<S25>/2-D Lookup Table2' */
  uint32_T m_Cache02_p;                /* '<S25>/2-D Lookup Table2' */
  uint32_T m_bpIndex_fj;               /* '<S25>/2-D Lookup Table1' */
  uint32_T m_bpIndex_l[31];            /* '<S26>/2-D Lookup Table2' */
  uint32_T m_Cache01_l[30];            /* '<S26>/2-D Lookup Table2' */
  uint32_T m_Cache02_m;                /* '<S26>/2-D Lookup Table2' */
  uint32_T m_bpIndex_g;                /* '<S26>/2-D Lookup Table1' */
  uint32_T m_bpIndex_a2[31];           /* '<S27>/2-D Lookup Table2' */
  uint32_T m_Cache01_f[30];            /* '<S27>/2-D Lookup Table2' */
  uint32_T m_Cache02_i;                /* '<S27>/2-D Lookup Table2' */
  uint32_T m_bpIndex_m;                /* '<S27>/2-D Lookup Table1' */
  uint32_T m_bpIndex_n[31];            /* '<S28>/2-D Lookup Table2' */
  uint32_T m_Cache01_o[30];            /* '<S28>/2-D Lookup Table2' */
  uint32_T m_Cache02_k;                /* '<S28>/2-D Lookup Table2' */
  uint32_T m_bpIndex_e;                /* '<S28>/2-D Lookup Table1' */
  boolean_T Delay_DSTATE_g;            /* '<S70>/Delay' */
  boolean_T Delay_DSTATE_o;            /* '<S184>/Delay' */
  boolean_T Delay_DSTATE_m;            /* '<S294>/Delay' */
  int8_T Integrator_PrevResetState;    /* '<S530>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S480>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S20>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_n;  /* '<S160>/Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S71>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_n;/* '<S71>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_n;/* '<S70>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_nl;/* '<S8>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator3_PrevResetState;/* '<S5>/Discrete-Time Integrator3' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S5>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_h;/* '<S5>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevResetState;/* '<S5>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_i;/* '<S8>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevResetState_b;/* '<S8>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator_PrevResetState_o;/* '<S10>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S108>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S103>/Filter' */
  int8_T Integrator_PrevResetState_g;  /* '<S272>/Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_k;/* '<S184>/Discrete-Time Integrator1' */
  int8_T Integrator_PrevResetState_g0; /* '<S220>/Integrator' */
  int8_T Filter_PrevResetState_j;      /* '<S215>/Filter' */
  int8_T Integrator_PrevResetState_m;  /* '<S382>/Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_g;/* '<S294>/Discrete-Time Integrator1' */
  int8_T Integrator_PrevResetState_ns; /* '<S330>/Integrator' */
  int8_T Filter_PrevResetState_k;      /* '<S325>/Filter' */
  int8_T DiscreteTimeIntegrator_PrevResetState_j;/* '<S402>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S25>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_l;/* '<S25>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_n2;/* '<S26>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_f;/* '<S26>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S27>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_d;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_b;/* '<S28>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_m;/* '<S28>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState_l;/* '<S70>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_nr;/* '<S184>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_ns;/* '<S294>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevResetState_o;/* '<S10>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator3_PrevResetState_f;/* '<S10>/Discrete-Time Integrator3' */
  int8_T DiscreteTimeIntegrator4_PrevResetState;/* '<S10>/Discrete-Time Integrator4' */
  boolean_T objisempty;                /* '<S426>/Moving Average' */
  boolean_T objisempty_n;              /* '<S402>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_kaa;                 /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_ka;                  /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_kw;                  /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_g;                  /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_h;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zzhe;    /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_k;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zzh;     /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_f;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5zz;      /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_n;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
    MovingAverage1_pnaevvfpgh5z;       /* '<Root>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_fw_T
    MovingAverage_e;                   /* '<Root>/Moving Average' */
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage2;/* '<S70>/Moving Average1' */
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpgh5;        /* '<S70>/Moving Average1' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T
    MovingAverage1_pnaevvfpgh;         /* '<S71>/Moving Average' */
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfpg;          /* '<S70>/Moving Average1' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T
    MovingAverage_g;                   /* '<S71>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_f_T
    MovingAverage_pnaevvfpgh5zzhe;     /* '<S71>/Moving Average' */
  DW_MovingAverage1_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvfp;           /* '<S70>/Moving Average1' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zzh;      /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5zz;       /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5z;        /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevvf;            /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh5;         /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaevv;             /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpgh;          /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnaev;              /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfpg;           /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pnae;               /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvfp;            /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevvf;             /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaevv;              /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnaev;               /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pna;                /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pnae;                /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_pn;                 /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pna;                 /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage1_p;                  /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T
    MovingAverage_pn;                  /* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage1;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage_p;/* '<S24>/Moving Average' */
  DW_MovingAverage_PIDcontroller4CoreCentralizedTestReadyMotor_T MovingAverage;/* '<S24>/Moving Average' */
} DW_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState UD_Reset_ZCE;             /* '<S523>/UD' */
  ZCSigState UD_Reset_ZCE_g;           /* '<S473>/UD' */
  ZCSigState UD_Reset_ZCE_a;           /* '<S153>/UD' */
  ZCSigState UD_Reset_ZCE_n;           /* '<S265>/UD' */
  ZCSigState UD_Reset_ZCE_k;           /* '<S375>/UD' */
} PrevZCX_PIDcontroller4CoreCentralizedTestReadyMotor_T;

/* instance parameters, for system '<Root>' */
typedef struct {
  real_T Airgap_GainSchedulingEnabled[5];/* Variable: Airgap_GainSchedulingEnabled
                                          * Referenced by:
                                          *   '<S29>/Constant4'
                                          *   '<S443>/Constant4'
                                          *   '<S46>/Constant4'
                                          *   '<S47>/Constant4'
                                          *   '<S48>/Constant4'
                                          *   '<S49>/Constant4'
                                          *   '<S50>/Constant4'
                                          *   '<S51>/Constant4'
                                          *   '<S52>/Constant4'
                                          *   '<S61>/Constant4'
                                          *   '<S62>/Constant4'
                                          *   '<S63>/Constant4'
                                          *   '<S64>/Constant4'
                                          *   '<S65>/Constant4'
                                          *   '<S66>/Constant4'
                                          *   '<S67>/Constant4'
                                          *   '<S436>/Constant4'
                                          *   '<S437>/Constant4'
                                          *   '<S438>/Constant4'
                                          *   '<S439>/Constant4'
                                          *   '<S440>/Constant4'
                                          *   '<S441>/Constant4'
                                          *   '<S442>/Constant4'
                                          */
  real_T CoMIntegrals[3];              /* Variable: CoMIntegrals
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T F_array[2];                   /* Variable: F_array
                                        * Referenced by:
                                        *   '<S29>/n-D Lookup Table'
                                        *   '<S443>/n-D Lookup Table'
                                        *   '<S46>/n-D Lookup Table'
                                        *   '<S47>/n-D Lookup Table'
                                        *   '<S48>/n-D Lookup Table'
                                        *   '<S49>/n-D Lookup Table'
                                        *   '<S50>/n-D Lookup Table'
                                        *   '<S51>/n-D Lookup Table'
                                        *   '<S52>/n-D Lookup Table'
                                        *   '<S61>/n-D Lookup Table'
                                        *   '<S62>/n-D Lookup Table'
                                        *   '<S63>/n-D Lookup Table'
                                        *   '<S64>/n-D Lookup Table'
                                        *   '<S65>/n-D Lookup Table'
                                        *   '<S66>/n-D Lookup Table'
                                        *   '<S67>/n-D Lookup Table'
                                        *   '<S436>/n-D Lookup Table'
                                        *   '<S437>/n-D Lookup Table'
                                        *   '<S438>/n-D Lookup Table'
                                        *   '<S439>/n-D Lookup Table'
                                        *   '<S440>/n-D Lookup Table'
                                        *   '<S441>/n-D Lookup Table'
                                        *   '<S442>/n-D Lookup Table'
                                        */
  real_T HEMS_Plane_Offsets[4];        /* Variable: HEMS_Plane_Offsets
                                        * Referenced by:
                                        *   '<S19>/Constant'
                                        *   '<S427>/Constant3'
                                        *   '<S427>/Constant4'
                                        */
  real_T MismatchingKalmanAGPR[3];     /* Variable: MismatchingKalmanAGPR
                                        * Referenced by:
                                        *   '<S10>/Gain2'
                                        *   '<S10>/Gain5'
                                        *   '<S10>/Gain6'
                                        */
  real_T SineSwitches[3];              /* Variable: SineSwitches
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T AirgapFilter;                 /* Variable: AirgapFilter
                                        * Referenced by:
                                        *   '<S42>/Constant1'
                                        *   '<S57>/Constant1'
                                        *   '<S432>/Constant1'
                                        */
  real_T BaseRefAirgap;                /* Variable: BaseRefAirgap
                                        * Referenced by:
                                        *   '<S71>/Base Ref Airgap'
                                        *   '<S71>/Base Ref Airgap1'
                                        */
  real_T BeamErrorTime;                /* Variable: BeamErrorTime
                                        * Referenced by: '<S30>/Pulse Generator'
                                        */
  real_T BeamOffsets;                  /* Variable: BeamOffsets
                                        * Referenced by:
                                        *   '<S30>/Constant6'
                                        *   '<S30>/Sine Wave1'
                                        *   '<S30>/Sine Wave2'
                                        *   '<S30>/Sine Wave3'
                                        *   '<S30>/Sine Wave4'
                                        *   '<S30>/Sine Wave5'
                                        *   '<S30>/Sine Wave6'
                                        *   '<S30>/Sine Wave7'
                                        */
  real_T BeamOffsetsBackDelay;         /* Variable: BeamOffsetsBackDelay
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T BeamOffsetsFactor;            /* Variable: BeamOffsetsFactor
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T CurrentIntegralAG;            /* Variable: CurrentIntegralAG
                                        * Referenced by: '<S157>/Integral Gain'
                                        */
  real_T CurrentIntegralP;             /* Variable: CurrentIntegralP
                                        * Referenced by:
                                        *   '<S477>/Integral Gain'
                                        *   '<S527>/Integral Gain'
                                        *   '<S269>/Integral Gain'
                                        */
  real_T CurrentIntegralR;             /* Variable: CurrentIntegralR
                                        * Referenced by: '<S379>/Integral Gain'
                                        */
  real_T DoubleFilter;                 /* Variable: DoubleFilter
                                        * Referenced by:
                                        *   '<S38>/Constant1'
                                        *   '<S39>/Constant1'
                                        *   '<S40>/Constant1'
                                        *   '<S41>/Constant1'
                                        *   '<S53>/Constant1'
                                        *   '<S54>/Constant1'
                                        *   '<S55>/Constant1'
                                        *   '<S56>/Constant1'
                                        *   '<S428>/Constant1'
                                        *   '<S429>/Constant1'
                                        *   '<S430>/Constant1'
                                        *   '<S431>/Constant1'
                                        */
  real_T EMSRollIntegral;              /* Variable: EMSRollIntegral
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T EMS_Moment_Arm_Z;             /* Variable: EMS_Moment_Arm_Z
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T ForgetFactor_Highpass_Lat;    /* Variable: ForgetFactor_Highpass_Lat
                                        * Referenced by: '<S177>/Gain10'
                                        */
  real_T ForgettingFactor;             /* Variable: ForgettingFactor
                                        * Referenced by:
                                        *   '<S46>/Constant'
                                        *   '<S47>/Constant'
                                        *   '<S48>/Constant'
                                        *   '<S49>/Constant'
                                        *   '<S61>/Constant'
                                        *   '<S62>/Constant'
                                        *   '<S63>/Constant'
                                        *   '<S64>/Constant'
                                        *   '<S436>/Constant'
                                        *   '<S437>/Constant'
                                        *   '<S438>/Constant'
                                        *   '<S439>/Constant'
                                        */
  real_T ForgettingFactorAirgap;       /* Variable: ForgettingFactorAirgap
                                        * Referenced by:
                                        *   '<S50>/Constant'
                                        *   '<S65>/Constant'
                                        *   '<S440>/Constant'
                                        */
  real_T ForgettingFactorLinpos;       /* Variable: ForgettingFactorLinpos
                                        * Referenced by:
                                        *   '<S29>/Constant'
                                        *   '<S443>/Constant'
                                        */
  real_T ForgettingFactorPitch;        /* Variable: ForgettingFactorPitch
                                        * Referenced by:
                                        *   '<S51>/Constant'
                                        *   '<S66>/Constant'
                                        *   '<S441>/Constant'
                                        */
  real_T ForgettingFactorRoll;         /* Variable: ForgettingFactorRoll
                                        * Referenced by:
                                        *   '<S52>/Constant'
                                        *   '<S67>/Constant'
                                        *   '<S442>/Constant'
                                        */
  real_T G_K_a;                        /* Variable: G_K_a
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real_T G_K_d;                        /* Variable: G_K_d
                                        * Referenced by: '<S69>/Constant4'
                                        */
  real_T G_K_d_LS;                     /* Variable: G_K_d_LS
                                        * Referenced by: '<S69>/Constant3'
                                        */
  real_T G_K_i;                        /* Variable: G_K_i
                                        * Referenced by: '<S69>/Constant6'
                                        */
  real_T G_K_i_LS;                     /* Variable: G_K_i_LS
                                        * Referenced by: '<S69>/Constant2'
                                        */
  real_T G_K_p;                        /* Variable: G_K_p
                                        * Referenced by: '<S69>/Constant1'
                                        */
  real_T G_K_p_LS;                     /* Variable: G_K_p_LS
                                        * Referenced by: '<S69>/Constant5'
                                        */
  real_T G_T_c;                        /* Variable: G_T_c
                                        * Referenced by:
                                        *   '<S125>/N'
                                        *   '<S186>/N'
                                        *   '<S296>/N'
                                        */
  real_T IMU_integration_gain;         /* Variable: IMU_integration_gain
                                        * Referenced by:
                                        *   '<S8>/Gain1'
                                        *   '<S8>/Gain2'
                                        *   '<S8>/Gain3'
                                        */
  real_T Kalman_F;                     /* Variable: Kalman_F
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Kalman_I;                     /* Variable: Kalman_I
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Kalman_P;                     /* Variable: Kalman_P
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Kalman_R;                     /* Variable: Kalman_R
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T LandingAirgap;                /* Variable: LandingAirgap
                                        * Referenced by: '<S71>/Constant3'
                                        */
  real_T LandingTime;                  /* Variable: LandingTime
                                        * Referenced by:
                                        *   '<S20>/Switch4'
                                        *   '<S71>/Gain1'
                                        */
  real_T LinposFilter;                 /* Variable: LinposFilter
                                        * Referenced by: '<S426>/Constant1'
                                        */
  real_T LinposOn;                     /* Variable: LinposOn
                                        * Referenced by: '<S427>/Constant5'
                                        */
  real_T LowAirgapPropellingSwitch;    /* Variable: LowAirgapPropellingSwitch
                                        * Referenced by:
                                        *   '<S70>/Constant'
                                        *   '<S184>/Constant'
                                        *   '<S294>/Constant'
                                        */
  real_T M_f;                          /* Variable: M_f
                                        * Referenced by:
                                        *   '<S21>/Gain'
                                        *   '<S25>/Gain'
                                        *   '<S26>/Gain'
                                        *   '<S27>/Gain'
                                        *   '<S28>/Gain'
                                        */
  real_T Mass;                         /* Variable: Mass
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<S3>/Mass [kg]'
                                        *   '<S5>/Constant6'
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant9'
                                        *   '<S8>/Constant'
                                        *   '<S8>/Constant9'
                                        *   '<S31>/Constant1'
                                        *   '<S32>/Gain'
                                        *   '<S34>/Gain'
                                        */
  real_T MeasureCurrent;               /* Variable: MeasureCurrent
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T MismatchedHEMSKalman;         /* Variable: MismatchedHEMSKalman
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T MismatchedHEMSLateral;        /* Variable: MismatchedHEMSLateral
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T MotorAGIntegrals;             /* Variable: MotorAGIntegrals
                                        * Referenced by: '<S5>/Constant7'
                                        */
  real_T MotorAirgapOffset;            /* Variable: MotorAirgapOffset
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T OperatingMode;                /* Variable: OperatingMode
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<S20>/Constant1'
                                        */
  real_T P_K_d;                        /* Variable: P_K_d
                                        * Referenced by: '<S180>/Constant4'
                                        */
  real_T P_K_d_LS;                     /* Variable: P_K_d_LS
                                        * Referenced by: '<S180>/Constant3'
                                        */
  real_T P_K_i;                        /* Variable: P_K_i
                                        * Referenced by: '<S180>/Constant6'
                                        */
  real_T P_K_i_LS;                     /* Variable: P_K_i_LS
                                        * Referenced by: '<S180>/Constant2'
                                        */
  real_T P_K_p;                        /* Variable: P_K_p
                                        * Referenced by: '<S180>/Constant1'
                                        */
  real_T P_K_p_LS;                     /* Variable: P_K_p_LS
                                        * Referenced by: '<S180>/Constant5'
                                        */
  real_T PitchFilter;                  /* Variable: PitchFilter
                                        * Referenced by:
                                        *   '<S43>/Constant1'
                                        *   '<S58>/Constant1'
                                        *   '<S433>/Constant1'
                                        */
  real_T PodHeight;                    /* Variable: PodHeight
                                        * Referenced by:
                                        *   '<S32>/2'
                                        *   '<S34>/2'
                                        */
  real_T PodHeightFactor;              /* Variable: PodHeightFactor
                                        * Referenced by:
                                        *   '<S32>/Gain4'
                                        *   '<S34>/Gain5'
                                        */
  real_T PodLength;                    /* Variable: PodLength
                                        * Referenced by: '<S32>/3'
                                        */
  real_T PodLengthFactor;              /* Variable: PodLengthFactor
                                        * Referenced by: '<S32>/Gain3'
                                        */
  real_T PodWidth;                     /* Variable: PodWidth
                                        * Referenced by: '<S34>/1'
                                        */
  real_T PodWidthFactor;               /* Variable: PodWidthFactor
                                        * Referenced by: '<S34>/Gain4'
                                        */
  real_T Polarity;                     /* Variable: Polarity
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        */
  real_T PropellingAirgap;             /* Variable: PropellingAirgap
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T PropellingPitch;              /* Variable: PropellingPitch
                                        * Referenced by: '<S184>/Constant1'
                                        */
  real_T PropellingRoll;               /* Variable: PropellingRoll
                                        * Referenced by: '<S294>/Constant1'
                                        */
  real_T PropellingTime;               /* Variable: PropellingTime
                                        * Referenced by:
                                        *   '<S70>/Constant3'
                                        *   '<S184>/Constant3'
                                        *   '<S294>/Constant3'
                                        */
  real_T PropulsionCurrent;            /* Variable: PropulsionCurrent
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T PropulsionOn;                 /* Variable: PropulsionOn
                                        * Referenced by:
                                        *   '<S3>/Constant3'
                                        *   '<S70>/Constant2'
                                        *   '<S184>/Constant2'
                                        *   '<S294>/Constant2'
                                        */
  real_T PropulsionRampTime;           /* Variable: PropulsionRampTime
                                        * Referenced by:
                                        *   '<S70>/Constant4'
                                        *   '<S184>/Constant4'
                                        *   '<S294>/Constant4'
                                        */
  real_T R_K_d;                        /* Variable: R_K_d
                                        * Referenced by: '<S291>/Constant4'
                                        */
  real_T R_K_d_LS;                     /* Variable: R_K_d_LS
                                        * Referenced by: '<S291>/Constant3'
                                        */
  real_T R_K_i;                        /* Variable: R_K_i
                                        * Referenced by: '<S291>/Constant6'
                                        */
  real_T R_K_i_LS;                     /* Variable: R_K_i_LS
                                        * Referenced by: '<S291>/Constant2'
                                        */
  real_T R_K_p_LS;                     /* Variable: R_K_p_LS
                                        * Referenced by: '<S291>/Constant5'
                                        */
  real_T RefPitch;                     /* Variable: RefPitch
                                        * Referenced by: '<S32>/Base Ref Airgap1'
                                        */
  real_T RefRoll;                      /* Variable: RefRoll
                                        * Referenced by: '<S34>/Base Ref Airgap1'
                                        */
  real_T ReferenceMass;                /* Variable: ReferenceMass
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Reference_P_Inertia;          /* Variable: Reference_P_Inertia
                                        * Referenced by: '<S32>/Reference_P_Inertia'
                                        */
  real_T Reference_R_Inertia;          /* Variable: Reference_R_Inertia
                                        * Referenced by: '<S34>/Reference_R_Inertia'
                                        */
  real_T ResetArms;                    /* Variable: ResetArms
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T RollFilter;                   /* Variable: RollFilter
                                        * Referenced by:
                                        *   '<S44>/Constant1'
                                        *   '<S59>/Constant1'
                                        *   '<S434>/Constant1'
                                        */
  real_T RunTime;                      /* Variable: RunTime
                                        * Referenced by: '<S20>/Constant13'
                                        */
  real_T SineTime;                     /* Variable: SineTime
                                        * Referenced by:
                                        *   '<S30>/Sine Wave1'
                                        *   '<S30>/Sine Wave2'
                                        *   '<S30>/Sine Wave3'
                                        *   '<S30>/Sine Wave4'
                                        *   '<S30>/Sine Wave5'
                                        *   '<S30>/Sine Wave6'
                                        *   '<S30>/Sine Wave7'
                                        */
  real_T SkipKalman;                   /* Variable: SkipKalman
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T StartingAirgap;               /* Variable: StartingAirgap
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T StartupTime;                  /* Variable: StartupTime
                                        * Referenced by:
                                        *   '<S20>/Constant3'
                                        *   '<S71>/Gain'
                                        *   '<S71>/Saturation'
                                        */
  real_T Undo_0current;                /* Variable: Undo_0current
                                        * Referenced by:
                                        *   '<S73>/Constant'
                                        *   '<S185>/Constant'
                                        *   '<S295>/Constant'
                                        */
  real_T UseIMU;                       /* Variable: UseIMU
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T X_Arm_Offset;                 /* Variable: X_Arm_Offset
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Y_Arm_Offset;                 /* Variable: Y_Arm_Offset
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T kalman_pitchdot_gain;         /* Variable: kalman_pitchdot_gain
                                        * Referenced by: '<S412>/Gain2'
                                        */
  real_T kalman_rolldot_gain;          /* Variable: kalman_rolldot_gain
                                        * Referenced by: '<S412>/Gain1'
                                        */
  real_T kalman_zdotdot_gain;          /* Variable: kalman_zdotdot_gain
                                        * Referenced by:
                                        *   '<S412>/Gain'
                                        *   '<S74>/Gain'
                                        */
  real_T motorforce_on;                /* Variable: motorforce_on
                                        * Referenced by:
                                        *   '<S400>/Constant5'
                                        *   '<S401>/Constant5'
                                        */
  real_T var_ag_IMU;                   /* Variable: var_ag_IMU
                                        * Referenced by: '<S412>/Constant1'
                                        */
  real_T var_ag_dot;                   /* Variable: var_ag_dot
                                        * Referenced by:
                                        *   '<S403>/Constant4'
                                        *   '<S412>/Constant4'
                                        */
  real_T var_ag_proc;                  /* Variable: var_ag_proc
                                        * Referenced by:
                                        *   '<S403>/Constant7'
                                        *   '<S412>/Constant7'
                                        */
  real_T var_ag_sens;                  /* Variable: var_ag_sens
                                        * Referenced by:
                                        *   '<S404>/Constant7'
                                        *   '<S413>/Constant7'
                                        */
  real_T var_ag_sens_LS;               /* Variable: var_ag_sens_LS
                                        * Referenced by:
                                        *   '<S404>/Constant1'
                                        *   '<S413>/Constant1'
                                        */
  real_T var_pitch_IMU;                /* Variable: var_pitch_IMU
                                        * Referenced by: '<S412>/Constant3'
                                        */
  real_T var_pitch_dot;                /* Variable: var_pitch_dot
                                        * Referenced by:
                                        *   '<S403>/Constant6'
                                        *   '<S412>/Constant6'
                                        */
  real_T var_pitch_proc;               /* Variable: var_pitch_proc
                                        * Referenced by:
                                        *   '<S403>/Constant9'
                                        *   '<S412>/Constant9'
                                        */
  real_T var_pitch_sens;               /* Variable: var_pitch_sens
                                        * Referenced by:
                                        *   '<S404>/Constant9'
                                        *   '<S413>/Constant9'
                                        */
  real_T var_pitch_sens_LS;            /* Variable: var_pitch_sens_LS
                                        * Referenced by:
                                        *   '<S404>/Constant3'
                                        *   '<S413>/Constant3'
                                        */
  real_T var_roll_IMU;                 /* Variable: var_roll_IMU
                                        * Referenced by: '<S412>/Constant2'
                                        */
  real_T var_roll_dot;                 /* Variable: var_roll_dot
                                        * Referenced by:
                                        *   '<S403>/Constant5'
                                        *   '<S412>/Constant5'
                                        */
  real_T var_roll_proc;                /* Variable: var_roll_proc
                                        * Referenced by:
                                        *   '<S403>/Constant8'
                                        *   '<S412>/Constant8'
                                        */
  real_T var_roll_sens;                /* Variable: var_roll_sens
                                        * Referenced by:
                                        *   '<S404>/Constant8'
                                        *   '<S413>/Constant8'
                                        */
  real_T var_roll_sens_LS;             /* Variable: var_roll_sens_LS
                                        * Referenced by:
                                        *   '<S404>/Constant2'
                                        *   '<S413>/Constant2'
                                        */
  uint32_T MagnetFailure;              /* Variable: MagnetFailure
                                        * Referenced by: '<S423>/Constant1'
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
   *   '<S29>/n-D Lookup Table'
   *   '<S443>/n-D Lookup Table'
   *   '<S46>/n-D Lookup Table'
   *   '<S47>/n-D Lookup Table'
   *   '<S48>/n-D Lookup Table'
   *   '<S49>/n-D Lookup Table'
   *   '<S50>/n-D Lookup Table'
   *   '<S51>/n-D Lookup Table'
   *   '<S52>/n-D Lookup Table'
   *   '<S61>/n-D Lookup Table'
   *   '<S62>/n-D Lookup Table'
   *   '<S63>/n-D Lookup Table'
   *   '<S64>/n-D Lookup Table'
   *   '<S65>/n-D Lookup Table'
   *   '<S66>/n-D Lookup Table'
   *   '<S67>/n-D Lookup Table'
   *   '<S436>/n-D Lookup Table'
   *   '<S437>/n-D Lookup Table'
   *   '<S438>/n-D Lookup Table'
   *   '<S439>/n-D Lookup Table'
   *   '<S440>/n-D Lookup Table'
   *   '<S441>/n-D Lookup Table'
   *   '<S442>/n-D Lookup Table'
   */
  real_T pooled4[2];

  /* Pooled Parameter (Expression: MotorPositionPoints)
   * Referenced by:
   *   '<S3>/Constant2'
   *   '<S3>/Constant6'
   */
  real_T pooled17[39];

  /* Pooled Parameter (Expression: BEAM_FORCE_Z_POS)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S25>/2-D Lookup Table2'
   *   '<S26>/2-D Lookup Table2'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S423>/2-D Lookup Table3'
   */
  real_T pooled25[10530];

  /* Pooled Parameter (Expression: CURRENT)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S25>/Constant'
   *   '<S25>/Constant20'
   *   '<S25>/2-D Lookup Table2'
   *   '<S26>/Constant'
   *   '<S26>/Constant20'
   *   '<S26>/2-D Lookup Table2'
   *   '<S27>/Constant'
   *   '<S27>/Constant20'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/Constant'
   *   '<S28>/Constant20'
   *   '<S28>/2-D Lookup Table2'
   *   '<S423>/2-D Lookup Table3'
   */
  real_T pooled26[30];

  /* Pooled Parameter (Expression: LEVI_AIRGAP)
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S25>/2-D Lookup Table2'
   *   '<S26>/2-D Lookup Table2'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S423>/2-D Lookup Table3'
   */
  real_T pooled27[351];

  /* Expression: MotorLiftPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[935];

  /* Expression: MotorCurrentPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[17];

  /* Expression: MotorBreakPoints
   * Referenced by: '<S3>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp02Data[55];

  /* Pooled Parameter (Expression: p.InitialCovariance)
   * Referenced by:
   *   '<S405>/DataStoreMemory - P'
   *   '<S414>/DataStoreMemory - P'
   */
  real_T pooled38[36];

  /* Expression: p.InitialState
   * Referenced by: '<S405>/DataStoreMemory - x'
   */
  real_T DataStoreMemoryx_InitialValue[6];

  /* Expression: p.InitialState
   * Referenced by: '<S414>/DataStoreMemory - x'
   */
  real_T DataStoreMemoryx_InitialValue_p[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S21>/2-D Lookup Table1'
   *   '<S21>/2-D Lookup Table2'
   *   '<S21>/2-D Lookup Table3'
   *   '<S21>/2-D Lookup Table4'
   *   '<S25>/2-D Lookup Table2'
   *   '<S26>/2-D Lookup Table2'
   *   '<S27>/2-D Lookup Table2'
   *   '<S28>/2-D Lookup Table2'
   *   '<S423>/2-D Lookup Table3'
   */
  uint32_T pooled40[2];
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
  real_T LS_mode;                      /* '<Root>/LS_mode' */
  real_T IMU_z;                        /* '<Root>/IMU_z' */
  real_T IMU_pitch;                    /* '<Root>/IMU_pitch' */
  real_T IMU_roll;                     /* '<Root>/IMU_roll' */
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
  real_T MotorAGAdjust;                /* '<Root>/MotorAGAdjust' */
  real_T IMU_kalman_output[3];         /* '<Root>/IMU_kalman_output' */
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
 * '<S5>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/CoM Finder & Motor AG Finder'
 * '<S6>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Data Center'
 * '<S7>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter'
 * '<S8>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU'
 * '<S9>'   : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver'
 * '<S10>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Kalman Input Adjustments'
 * '<S11>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees'
 * '<S12>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees1'
 * '<S13>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees2'
 * '<S14>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees3'
 * '<S15>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees4'
 * '<S16>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees5'
 * '<S17>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees6'
 * '<S18>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Radians to Degrees7'
 * '<S19>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors'
 * '<S20>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer'
 * '<S21>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem4'
 * '<S22>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5'
 * '<S23>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/SwitchMismatch'
 * '<S24>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Filter Noisy Signals'
 * '<S25>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference'
 * '<S26>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference1'
 * '<S27>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference2'
 * '<S28>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Subsystem Reference3'
 * '<S29>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Array interpolation/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S30>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator'
 * '<S31>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS'
 * '<S32>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID'
 * '<S33>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/Remove external force'
 * '<S34>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID'
 * '<S35>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/Subsystem'
 * '<S36>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1'
 * '<S37>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2'
 * '<S38>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals'
 * '<S39>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1'
 * '<S40>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals2'
 * '<S41>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals3'
 * '<S42>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals4'
 * '<S43>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals5'
 * '<S44>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals6'
 * '<S45>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/FindCoordinates'
 * '<S46>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S47>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S48>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S49>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S50>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S51>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S52>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S53>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals'
 * '<S54>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1'
 * '<S55>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals2'
 * '<S56>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals3'
 * '<S57>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals4'
 * '<S58>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals5'
 * '<S59>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals6'
 * '<S60>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/FindCoordinates'
 * '<S61>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S62>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S63>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S64>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S65>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S66>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S67>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S68>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Airgap controller1'
 * '<S69>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/LS mode Gain'
 * '<S70>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/RampUpMotor'
 * '<S71>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Reference Airgap Base'
 * '<S72>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/Reset'
 * '<S73>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/ZeroCurrentFInder'
 * '<S74>'  : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/pidD'
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
 * '<S125>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/LS mode Gain/PIDFilter Scheduling'
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
 * '<S177>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PIDS/pidD/Highpass1'
 * '<S178>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Degrees to Radians'
 * '<S179>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Degrees to Radians1'
 * '<S180>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/LS mode Gain'
 * '<S181>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller'
 * '<S182>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Radians to Degrees'
 * '<S183>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Radians to Degrees1'
 * '<S184>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/RampUpMotor1'
 * '<S185>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder'
 * '<S186>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/LS mode Gain/PIDFilter Scheduling'
 * '<S187>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup'
 * '<S188>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/D Gain'
 * '<S189>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter'
 * '<S190>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter ICs'
 * '<S191>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/I Gain'
 * '<S192>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain'
 * '<S193>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain Fdbk'
 * '<S194>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator'
 * '<S195>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator ICs'
 * '<S196>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Copy'
 * '<S197>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Gain'
 * '<S198>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/P Copy'
 * '<S199>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Parallel P Gain'
 * '<S200>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Reset Signal'
 * '<S201>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation'
 * '<S202>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation Fdbk'
 * '<S203>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum'
 * '<S204>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum Fdbk'
 * '<S205>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode'
 * '<S206>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode Sum'
 * '<S207>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Integral'
 * '<S208>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Ngain'
 * '<S209>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/postSat Signal'
 * '<S210>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/preSat Signal'
 * '<S211>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel'
 * '<S212>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S213>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S214>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/D Gain/External Parameters'
 * '<S215>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter/Disc. Forward Euler Filter'
 * '<S216>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Filter ICs/Internal IC - Filter'
 * '<S217>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/I Gain/External Parameters'
 * '<S218>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain/Passthrough'
 * '<S219>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Ideal P Gain Fdbk/Disabled'
 * '<S220>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator/Discrete'
 * '<S221>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Integrator ICs/Internal IC'
 * '<S222>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Copy/Disabled'
 * '<S223>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/N Gain/External Parameters'
 * '<S224>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/P Copy/Disabled'
 * '<S225>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Parallel P Gain/External Parameters'
 * '<S226>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Reset Signal/External Reset'
 * '<S227>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation/Enabled'
 * '<S228>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Saturation Fdbk/Disabled'
 * '<S229>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum/Sum_PID'
 * '<S230>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Sum Fdbk/Disabled'
 * '<S231>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode/Disabled'
 * '<S232>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tracking Mode Sum/Passthrough'
 * '<S233>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Integral/Passthrough'
 * '<S234>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/Tsamp - Ngain/Passthrough'
 * '<S235>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/postSat Signal/Forward_Path'
 * '<S236>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/Pitch controller/preSat Signal/Forward_Path'
 * '<S237>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/RampUpMotor1/Degrees to Radians'
 * '<S238>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2'
 * '<S239>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S240>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S241>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S242>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S243>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S244>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S245>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S246>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S247>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S248>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S249>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S250>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S251>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S252>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S253>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S254>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S255>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S256>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S257>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S258>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S259>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S260>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S261>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S262>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S263>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S264>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S265>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S266>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S267>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S268>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S269>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S270>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S271>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S272>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S273>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S274>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S275>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S276>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S277>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S278>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S279>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S280>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S281>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S282>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S283>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S284>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S285>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S286>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S287>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S288>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/PitchPID/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S289>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Degrees to Radians'
 * '<S290>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Degrees to Radians1'
 * '<S291>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/LS mode Gain'
 * '<S292>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller'
 * '<S293>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Radians to Degrees'
 * '<S294>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/RampUpMotor1'
 * '<S295>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder'
 * '<S296>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/LS mode Gain/PIDFilter Scheduling'
 * '<S297>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup'
 * '<S298>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/D Gain'
 * '<S299>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter'
 * '<S300>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter ICs'
 * '<S301>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/I Gain'
 * '<S302>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain'
 * '<S303>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain Fdbk'
 * '<S304>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator'
 * '<S305>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator ICs'
 * '<S306>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Copy'
 * '<S307>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Gain'
 * '<S308>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/P Copy'
 * '<S309>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Parallel P Gain'
 * '<S310>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Reset Signal'
 * '<S311>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation'
 * '<S312>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation Fdbk'
 * '<S313>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum'
 * '<S314>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum Fdbk'
 * '<S315>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode'
 * '<S316>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode Sum'
 * '<S317>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Integral'
 * '<S318>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Ngain'
 * '<S319>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/postSat Signal'
 * '<S320>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/preSat Signal'
 * '<S321>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel'
 * '<S322>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S323>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S324>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/D Gain/External Parameters'
 * '<S325>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter/Disc. Forward Euler Filter'
 * '<S326>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Filter ICs/Internal IC - Filter'
 * '<S327>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/I Gain/External Parameters'
 * '<S328>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain/Passthrough'
 * '<S329>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Ideal P Gain Fdbk/Disabled'
 * '<S330>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator/Discrete'
 * '<S331>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Integrator ICs/Internal IC'
 * '<S332>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Copy/Disabled'
 * '<S333>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/N Gain/External Parameters'
 * '<S334>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/P Copy/Disabled'
 * '<S335>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Parallel P Gain/External Parameters'
 * '<S336>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Reset Signal/External Reset'
 * '<S337>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation/Enabled'
 * '<S338>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Saturation Fdbk/Disabled'
 * '<S339>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum/Sum_PID'
 * '<S340>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Sum Fdbk/Disabled'
 * '<S341>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode/Disabled'
 * '<S342>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tracking Mode Sum/Passthrough'
 * '<S343>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Integral/Passthrough'
 * '<S344>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/Tsamp - Ngain/Passthrough'
 * '<S345>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/postSat Signal/Forward_Path'
 * '<S346>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/Pitch controller/preSat Signal/Forward_Path'
 * '<S347>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/RampUpMotor1/Degrees to Radians'
 * '<S348>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2'
 * '<S349>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S350>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S351>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S352>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S353>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S354>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S355>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S356>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S357>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S358>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S359>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S360>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S361>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S362>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S363>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S364>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S365>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S366>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S367>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S368>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S369>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S370>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S371>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S372>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S373>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S374>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S375>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S376>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S377>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S378>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S379>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S380>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S381>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S382>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S383>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S384>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S385>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S386>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S387>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S388>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S389>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S390>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S391>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S392>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S393>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S394>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S395>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S396>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S397>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S398>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate Control Signals (PIDs)/RollPID/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S399>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/MATLAB Function'
 * '<S400>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/Turn motor force//torque on'
 * '<S401>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Calculate External Force/Turn motor force//torque on1'
 * '<S402>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Data Center/Power Measurements'
 * '<S403>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter'
 * '<S404>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Covar scheduling'
 * '<S405>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter'
 * '<S406>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Correct1'
 * '<S407>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Output'
 * '<S408>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Predict'
 * '<S409>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Correct1/Correct'
 * '<S410>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Output/MATLAB Function'
 * '<S411>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter/Kalman Filter/Extended Kalman Filter/Predict/Predict'
 * '<S412>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter'
 * '<S413>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Covar scheduling'
 * '<S414>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter'
 * '<S415>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Correct1'
 * '<S416>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Correct2'
 * '<S417>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Output'
 * '<S418>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Predict'
 * '<S419>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Correct1/Correct'
 * '<S420>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Correct2/Correct'
 * '<S421>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Output/MATLAB Function'
 * '<S422>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Extended Kalman Filter IMU/Kalman Filter/Extended Kalman Filter/Predict/Predict'
 * '<S423>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver/Force Divider1'
 * '<S424>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Force Solver/Force Divider1/MATLAB Function'
 * '<S425>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll'
 * '<S426>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Filter Noisy Signals1'
 * '<S427>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1'
 * '<S428>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals'
 * '<S429>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals1'
 * '<S430>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals2'
 * '<S431>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals3'
 * '<S432>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals4'
 * '<S433>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals5'
 * '<S434>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals6'
 * '<S435>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/FindCoordinates'
 * '<S436>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals/Moving Average Filter Scheduling'
 * '<S437>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S438>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals2/Moving Average Filter Scheduling'
 * '<S439>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals3/Moving Average Filter Scheduling'
 * '<S440>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals4/Moving Average Filter Scheduling'
 * '<S441>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals5/Moving Average Filter Scheduling'
 * '<S442>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Calculate Airgap, linpos, pitch and roll/Subsystem1/Filter Noisy Signals6/Moving Average Filter Scheduling'
 * '<S443>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Sensors/Filter Noisy Signals1/Moving Average Filter Scheduling'
 * '<S444>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1'
 * '<S445>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2'
 * '<S446>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Compare To Constant'
 * '<S447>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Anti-windup'
 * '<S448>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/D Gain'
 * '<S449>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter'
 * '<S450>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter ICs'
 * '<S451>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/I Gain'
 * '<S452>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain'
 * '<S453>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain Fdbk'
 * '<S454>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator'
 * '<S455>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator ICs'
 * '<S456>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Copy'
 * '<S457>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Gain'
 * '<S458>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/P Copy'
 * '<S459>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Parallel P Gain'
 * '<S460>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Reset Signal'
 * '<S461>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation'
 * '<S462>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation Fdbk'
 * '<S463>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum'
 * '<S464>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum Fdbk'
 * '<S465>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode'
 * '<S466>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode Sum'
 * '<S467>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Integral'
 * '<S468>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Ngain'
 * '<S469>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/postSat Signal'
 * '<S470>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/preSat Signal'
 * '<S471>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Anti-windup/Back Calculation'
 * '<S472>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/D Gain/Internal Parameters'
 * '<S473>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator'
 * '<S474>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator/Tsamp'
 * '<S475>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S476>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Filter ICs/Internal IC - Differentiator'
 * '<S477>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/I Gain/Internal Parameters'
 * '<S478>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S479>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S480>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator/Discrete'
 * '<S481>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Integrator ICs/Internal IC'
 * '<S482>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Copy/Disabled wSignal Specification'
 * '<S483>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/N Gain/Passthrough'
 * '<S484>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/P Copy/Disabled'
 * '<S485>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Parallel P Gain/Internal Parameters'
 * '<S486>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Reset Signal/External Reset'
 * '<S487>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation/Enabled'
 * '<S488>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S489>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum/Sum_PID'
 * '<S490>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Sum Fdbk/Disabled'
 * '<S491>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode/Disabled'
 * '<S492>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S493>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S494>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S495>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/postSat Signal/Forward_Path'
 * '<S496>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller1/preSat Signal/Forward_Path'
 * '<S497>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Anti-windup'
 * '<S498>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/D Gain'
 * '<S499>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter'
 * '<S500>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter ICs'
 * '<S501>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/I Gain'
 * '<S502>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain'
 * '<S503>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain Fdbk'
 * '<S504>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator'
 * '<S505>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator ICs'
 * '<S506>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Copy'
 * '<S507>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Gain'
 * '<S508>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/P Copy'
 * '<S509>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Parallel P Gain'
 * '<S510>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Reset Signal'
 * '<S511>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation'
 * '<S512>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation Fdbk'
 * '<S513>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum'
 * '<S514>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum Fdbk'
 * '<S515>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode'
 * '<S516>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode Sum'
 * '<S517>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Integral'
 * '<S518>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Ngain'
 * '<S519>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/postSat Signal'
 * '<S520>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/preSat Signal'
 * '<S521>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Anti-windup/Back Calculation'
 * '<S522>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/D Gain/Internal Parameters'
 * '<S523>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator'
 * '<S524>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S525>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S526>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S527>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/I Gain/Internal Parameters'
 * '<S528>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S529>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S530>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator/Discrete'
 * '<S531>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Integrator ICs/Internal IC'
 * '<S532>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S533>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/N Gain/Passthrough'
 * '<S534>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/P Copy/Disabled'
 * '<S535>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S536>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Reset Signal/External Reset'
 * '<S537>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation/Enabled'
 * '<S538>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S539>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum/Sum_PID'
 * '<S540>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Sum Fdbk/Disabled'
 * '<S541>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode/Disabled'
 * '<S542>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S543>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S544>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S545>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/postSat Signal/Forward_Path'
 * '<S546>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Startup Timer/Airgap controller2/preSat Signal/Forward_Path'
 * '<S547>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current'
 * '<S548>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current1'
 * '<S549>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current2'
 * '<S550>' : 'PIDcontroller4CoreCentralizedTestReadyMotor/Subsystem5/Cap requested current3'
 */
#endif           /* RTW_HEADER_PIDcontroller4CoreCentralizedTestReadyMotor_h_ */
