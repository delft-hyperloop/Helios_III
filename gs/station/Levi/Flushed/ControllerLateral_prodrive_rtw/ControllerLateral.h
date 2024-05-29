/*
 * ControllerLateral.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControllerLateral".
 *
 * Model version              : 6.194
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon May 20 14:18:02 2024
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
#include <stddef.h>
#include <string.h>
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

/* Block signals for system '<S14>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S14>/Moving Average' */
} B_MovingAverage_ControllerLateral_T;

/* Block states (default storage) for system '<S14>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_T obj;/* '<S14>/Moving Average' */
  boolean_T objisempty;                /* '<S14>/Moving Average' */
} DW_MovingAverage_ControllerLateral_T;

/* Block signals for system '<S72>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S72>/Moving Average' */
} B_MovingAverage_ControllerLateral_c_T;

/* Block states (default storage) for system '<S72>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_e_T obj;/* '<S72>/Moving Average' */
  boolean_T objisempty;                /* '<S72>/Moving Average' */
} DW_MovingAverage_ControllerLateral_f_T;

/* Block signals for system '<Root>/MATLAB Function' */
typedef struct {
  real_T current;                      /* '<Root>/MATLAB Function' */
} B_MATLABFunction_ControllerLateral_T;

/* Block signals (default storage) */
typedef struct {
  real_T Tsamp;                        /* '<S159>/Tsamp' */
  real_T Product1;                     /* '<S15>/Product1' */
  real_T NProdOut;                     /* '<S114>/NProd Out' */
  real_T Tsamp_c;                      /* '<S210>/Tsamp' */
  real_T NProdOut_k;                   /* '<S56>/NProd Out' */
  real_T Switch;                       /* '<S44>/Switch' */
  real_T Switch_l;                     /* '<S102>/Switch' */
  real_T SumI4;                        /* '<S155>/SumI4' */
  real_T SumI4_e;                      /* '<S206>/SumI4' */
  real_T TmpSignalConversionAtDelay1Inport1[2];
  real_T Switch3;                      /* '<S8>/Switch3' */
  boolean_T OR;                        /* '<S8>/OR' */
  boolean_T Equal;                     /* '<S8>/Equal' */
  boolean_T Equal_p;                   /* '<S16>/Equal' */
  boolean_T Equal_m;                   /* '<S14>/Equal' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pnaevvf;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaevvfpg;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pnaevv;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaevvfp;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pnaev;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaevvf;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pnae;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnaevv;/* '<S72>/Moving Average' */
  B_MATLABFunction_ControllerLateral_T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
  B_MATLABFunction_ControllerLateral_T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
  B_MovingAverage_ControllerLateral_T MovingAverage_pnaev;/* '<S14>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pna;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pnae;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_pn;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pna;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1_p;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_pn;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage1;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_c_T MovingAverage_p;/* '<S72>/Moving Average' */
  B_MovingAverage_ControllerLateral_T MovingAverage;/* '<S14>/Moving Average' */
} B_ControllerLateral_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_ControllerLateral_h_T obj;/* '<S11>/Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE[2];             /* '<Root>/Delay1' */
  real_T Integrator_DSTATE;            /* '<S164>/Integrator' */
  real_T UD_DSTATE;                    /* '<S157>/UD' */
  real_T Delay1_DSTATE_b[400];         /* '<S15>/Delay1' */
  real_T Integrator_DSTATE_n;          /* '<S111>/Integrator' */
  real_T Filter_DSTATE;                /* '<S106>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S215>/Integrator' */
  real_T UD_DSTATE_o;                  /* '<S208>/UD' */
  real_T Integrator_DSTATE_k;          /* '<S53>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S48>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S11>/Discrete-Time Integrator' */
  real_T mode_old;                     /* '<Root>/Lane Switch Transition1' */
  real_T t_old;                        /* '<Root>/Lane Switch Transition1' */
  real_T mode_memory_old;              /* '<Root>/Lane Switch Transition1' */
  int32_T clockTickCounter;            /* '<S15>/Pulse Generator' */
  int32_T counter;                     /* '<S15>/Sine Wave1' */
  int32_T counter_k;                   /* '<S15>/Sine Wave2' */
  uint32_T m_bpIndex[2];               /* '<S13>/2-D Lookup Table3' */
  uint32_T m_bpIndex_b[2];             /* '<S12>/2-D Lookup Table3' */
  uint32_T m_bpIndex_j[10];            /* '<S13>/2-D Lookup Table2' */
  uint32_T m_Cache01[9];               /* '<S13>/2-D Lookup Table2' */
  uint32_T m_Cache02;                  /* '<S13>/2-D Lookup Table2' */
  uint32_T m_bpIndex_e;                /* '<S13>/2-D Lookup Table1' */
  uint32_T m_bpIndex_l[10];            /* '<S12>/2-D Lookup Table2' */
  uint32_T m_Cache01_d[9];             /* '<S12>/2-D Lookup Table2' */
  uint32_T m_Cache02_g;                /* '<S12>/2-D Lookup Table2' */
  uint32_T m_bpIndex_p;                /* '<S12>/2-D Lookup Table1' */
  int8_T Integrator_PrevResetState;    /* '<S164>/Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S111>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S106>/Filter' */
  int8_T Integrator_PrevResetState_m;  /* '<S215>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S53>/Integrator' */
  int8_T Filter_PrevResetState_g;      /* '<S48>/Filter' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S11>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput;      /* '<S8>/Memory' */
  boolean_T objisempty;                /* '<S11>/Moving Average' */
  boolean_T mode_old_not_empty;        /* '<Root>/Lane Switch Transition1' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pnaevvf;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaevvfpg;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pnaevv;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaevvfp;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pnaev;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaevvf;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pnae;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnaevv;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage_pnaev;/* '<S14>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pna;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pnae;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_pn;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pna;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1_p;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_pn;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage1;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_f_T MovingAverage_p;/* '<S72>/Moving Average' */
  DW_MovingAverage_ControllerLateral_T MovingAverage;/* '<S14>/Moving Average' */
} DW_ControllerLateral_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState UD_Reset_ZCE;             /* '<S157>/UD' */
  ZCSigState UD_Reset_ZCE_d;           /* '<S208>/UD' */
} PrevZCX_ControllerLateral_T;

/* instance parameters, for system '<Root>' */
typedef struct {
  real_T LateralOffsetsHEMSMotor[5];   /* Variable: LateralOffsetsHEMSMotor
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T LateralSineSwitches[2];       /* Variable: LateralSineSwitches
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T ReferenceLateralOffsets[2];   /* Variable: ReferenceLateralOffsets
                                        * Referenced by: '<S17>/Setpoint'
                                        */
  real_T BackGain;                     /* Variable: BackGain
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T BeamErrorTime;                /* Variable: BeamErrorTime
                                        * Referenced by: '<S15>/Pulse Generator'
                                        */
  real_T CurrentIntegralLat;           /* Variable: CurrentIntegralLat
                                        * Referenced by:
                                        *   '<S161>/Integral Gain'
                                        *   '<S212>/Integral Gain'
                                        */
  real_T FrontGain;                    /* Variable: FrontGain
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T LS_curved_AG;                 /* Variable: LS_curved_AG
                                        * Referenced by:
                                        *   '<S237>/Mode 1 AG4'
                                        *   '<S237>/Mode 1 AG5'
                                        */
  real_T LS_mode;                      /* Variable: LS_mode
                                        * Referenced by: '<Root>/Lane Switch Mode'
                                        */
  real_T LS_straight_AG;               /* Variable: LS_straight_AG
                                        * Referenced by:
                                        *   '<S237>/Mode 1 AG'
                                        *   '<S237>/Mode 1 AG6'
                                        */
  real_T L_K_d;                        /* Variable: L_K_d
                                        * Referenced by:
                                        *   '<S19>/Constant3'
                                        *   '<S77>/Constant3'
                                        */
  real_T L_K_i;                        /* Variable: L_K_i
                                        * Referenced by:
                                        *   '<S19>/Constant2'
                                        *   '<S77>/Constant2'
                                        */
  real_T L_K_p;                        /* Variable: L_K_p
                                        * Referenced by:
                                        *   '<S19>/Constant1'
                                        *   '<S77>/Constant1'
                                        */
  real_T L_T_c;                        /* Variable: L_T_c
                                        * Referenced by:
                                        *   '<S19>/N'
                                        *   '<S77>/N'
                                        */
  real_T LandingTime;                  /* Variable: LandingTime
                                        * Referenced by: '<S8>/Switch4'
                                        */
  real_T LateralBeamOffsets;           /* Variable: LateralBeamOffsets
                                        * Referenced by:
                                        *   '<S15>/Constant6'
                                        *   '<S15>/Sine Wave1'
                                        *   '<S15>/Sine Wave2'
                                        */
  real_T LateralBeamOffsetsBackDelay;  /* Variable: LateralBeamOffsetsBackDelay
                                        * Referenced by: '<S15>/Constant4'
                                        */
  real_T LateralBeamOffsetsFactor;     /* Variable: LateralBeamOffsetsFactor
                                        * Referenced by: '<S15>/Sine Wave2'
                                        */
  real_T LateralDoubleFilter;          /* Variable: LateralDoubleFilter
                                        * Referenced by:
                                        *   '<S233>/Constant1'
                                        *   '<S234>/Constant1'
                                        *   '<S235>/Constant1'
                                        *   '<S236>/Constant1'
                                        *   '<S72>/Constant1'
                                        *   '<S73>/Constant1'
                                        *   '<S74>/Constant1'
                                        *   '<S75>/Constant1'
                                        */
  real_T LateralForgettingFactor;      /* Variable: LateralForgettingFactor
                                        * Referenced by:
                                        *   '<S233>/Constant'
                                        *   '<S234>/Constant'
                                        *   '<S235>/Constant'
                                        *   '<S236>/Constant'
                                        *   '<S72>/Constant'
                                        *   '<S73>/Constant'
                                        *   '<S74>/Constant'
                                        *   '<S75>/Constant'
                                        */
  real_T LateralOperatingMode;         /* Variable: LateralOperatingMode
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T M_f;                          /* Variable: M_f
                                        * Referenced by:
                                        *   '<S12>/Gain'
                                        *   '<S13>/Gain'
                                        */
  real_T Mass;                         /* Variable: Mass
                                        * Referenced by:
                                        *   '<S3>/Gain'
                                        *   '<S10>/Beta'
                                        *   '<S14>/Constant1'
                                        *   '<S16>/Constant1'
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
                                        *   '<S14>/Constant'
                                        *   '<S16>/Constant'
                                        */
  real_T RunTime;                      /* Variable: RunTime
                                        * Referenced by: '<S8>/Constant13'
                                        */
  real_T SemiCentralized;              /* Variable: SemiCentralized
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T SineTime;                     /* Variable: SineTime
                                        * Referenced by:
                                        *   '<S15>/Sine Wave1'
                                        *   '<S15>/Sine Wave2'
                                        */
  real_T StartupTime;                  /* Variable: StartupTime
                                        * Referenced by:
                                        *   '<S8>/Constant13'
                                        *   '<S8>/Constant3'
                                        */
  real_T lateral_over_vertical_force_hems;
                                   /* Variable: lateral_over_vertical_force_hems
                                    * Referenced by: '<S9>/Constant'
                                    */
  real_T lateral_over_vertical_force_motor;
                                  /* Variable: lateral_over_vertical_force_motor
                                   * Referenced by: '<S9>/Constant1'
                                   */
  real_T t_trans;                      /* Variable: t_trans
                                        * Referenced by: '<Root>/Constant4'
                                        */
} InstP_ControllerLateral_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: EMS_CURRENT)
   * Referenced by:
   *   '<S12>/Constant'
   *   '<S12>/2-D Lookup Table1'
   *   '<S12>/2-D Lookup Table2'
   *   '<S12>/2-D Lookup Table3'
   *   '<S13>/Constant'
   *   '<S13>/2-D Lookup Table1'
   *   '<S13>/2-D Lookup Table2'
   *   '<S13>/2-D Lookup Table3'
   */
  real_T pooled4[9];

  /* Pooled Parameter (Expression: -EMS_FORCE)
   * Referenced by:
   *   '<S12>/2-D Lookup Table2'
   *   '<S12>/2-D Lookup Table3'
   *   '<S13>/2-D Lookup Table2'
   *   '<S13>/2-D Lookup Table3'
   */
  real_T pooled5[909];

  /* Pooled Parameter (Expression: EMS_AIRGAP)
   * Referenced by:
   *   '<S12>/2-D Lookup Table2'
   *   '<S12>/2-D Lookup Table3'
   *   '<S13>/2-D Lookup Table2'
   *   '<S13>/2-D Lookup Table3'
   */
  real_T pooled6[101];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S12>/2-D Lookup Table2'
   *   '<S12>/2-D Lookup Table3'
   *   '<S13>/2-D Lookup Table2'
   *   '<S13>/2-D Lookup Table3'
   */
  uint32_T pooled19[2];
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
 * '<S7>'   : 'ControllerLateral/Sensors'
 * '<S8>'   : 'ControllerLateral/Startup Timer'
 * '<S9>'   : 'ControllerLateral/Subsystem'
 * '<S10>'  : 'ControllerLateral/Subsystem1'
 * '<S11>'  : 'ControllerLateral/Subsystem2'
 * '<S12>'  : 'ControllerLateral/Array interpolation/Subsystem1'
 * '<S13>'  : 'ControllerLateral/Array interpolation/Subsystem2'
 * '<S14>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID'
 * '<S15>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator'
 * '<S16>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID'
 * '<S17>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem'
 * '<S18>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1'
 * '<S19>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Gain Scheduling1'
 * '<S20>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Anti-windup'
 * '<S21>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/D Gain'
 * '<S22>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Filter'
 * '<S23>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Filter ICs'
 * '<S24>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/I Gain'
 * '<S25>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Ideal P Gain'
 * '<S26>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Ideal P Gain Fdbk'
 * '<S27>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Integrator'
 * '<S28>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Integrator ICs'
 * '<S29>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/N Copy'
 * '<S30>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/N Gain'
 * '<S31>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/P Copy'
 * '<S32>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Parallel P Gain'
 * '<S33>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Reset Signal'
 * '<S34>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Saturation'
 * '<S35>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Saturation Fdbk'
 * '<S36>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Sum'
 * '<S37>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Sum Fdbk'
 * '<S38>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tracking Mode'
 * '<S39>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tracking Mode Sum'
 * '<S40>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tsamp - Integral'
 * '<S41>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tsamp - Ngain'
 * '<S42>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/postSat Signal'
 * '<S43>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/preSat Signal'
 * '<S44>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S45>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S46>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S47>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/D Gain/External Parameters'
 * '<S48>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Filter/Disc. Forward Euler Filter'
 * '<S49>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Filter ICs/Internal IC - Filter'
 * '<S50>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/I Gain/External Parameters'
 * '<S51>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S52>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S53>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Integrator/Discrete'
 * '<S54>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Integrator ICs/Internal IC'
 * '<S55>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/N Copy/Disabled'
 * '<S56>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/N Gain/External Parameters'
 * '<S57>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/P Copy/Disabled'
 * '<S58>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S59>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Reset Signal/External Reset'
 * '<S60>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Saturation/Enabled'
 * '<S61>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S62>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Sum/Sum_PID'
 * '<S63>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Sum Fdbk/Disabled'
 * '<S64>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tracking Mode/Disabled'
 * '<S65>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S66>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S67>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S68>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/postSat Signal/Forward_Path'
 * '<S69>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Back PID/Airgap controller1/preSat Signal/Forward_Path'
 * '<S70>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1'
 * '<S71>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2'
 * '<S72>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals'
 * '<S73>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem1/Filter Noisy Signals1'
 * '<S74>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals'
 * '<S75>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/BeamOffsetsGenerator/Subsystem2/Filter Noisy Signals1'
 * '<S76>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1'
 * '<S77>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Gain Scheduling1'
 * '<S78>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup'
 * '<S79>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/D Gain'
 * '<S80>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter'
 * '<S81>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter ICs'
 * '<S82>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/I Gain'
 * '<S83>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain'
 * '<S84>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain Fdbk'
 * '<S85>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator'
 * '<S86>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator ICs'
 * '<S87>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Copy'
 * '<S88>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Gain'
 * '<S89>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/P Copy'
 * '<S90>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Parallel P Gain'
 * '<S91>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Reset Signal'
 * '<S92>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation'
 * '<S93>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation Fdbk'
 * '<S94>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum'
 * '<S95>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum Fdbk'
 * '<S96>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode'
 * '<S97>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode Sum'
 * '<S98>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Integral'
 * '<S99>'  : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Ngain'
 * '<S100>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/postSat Signal'
 * '<S101>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/preSat Signal'
 * '<S102>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S103>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S104>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S105>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/D Gain/External Parameters'
 * '<S106>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter/Disc. Forward Euler Filter'
 * '<S107>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Filter ICs/Internal IC - Filter'
 * '<S108>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/I Gain/External Parameters'
 * '<S109>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain/Passthrough'
 * '<S110>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Ideal P Gain Fdbk/Disabled'
 * '<S111>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator/Discrete'
 * '<S112>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Integrator ICs/Internal IC'
 * '<S113>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Copy/Disabled'
 * '<S114>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/N Gain/External Parameters'
 * '<S115>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/P Copy/Disabled'
 * '<S116>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Parallel P Gain/External Parameters'
 * '<S117>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Reset Signal/External Reset'
 * '<S118>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation/Enabled'
 * '<S119>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Saturation Fdbk/Disabled'
 * '<S120>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum/Sum_PID'
 * '<S121>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Sum Fdbk/Disabled'
 * '<S122>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode/Disabled'
 * '<S123>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tracking Mode Sum/Passthrough'
 * '<S124>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Integral/Passthrough'
 * '<S125>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/Tsamp - Ngain/Passthrough'
 * '<S126>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/postSat Signal/Forward_Path'
 * '<S127>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Front PID/Airgap controller1/preSat Signal/Forward_Path'
 * '<S128>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder'
 * '<S129>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1'
 * '<S130>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2'
 * '<S131>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Anti-windup'
 * '<S132>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/D Gain'
 * '<S133>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter'
 * '<S134>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter ICs'
 * '<S135>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/I Gain'
 * '<S136>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain'
 * '<S137>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk'
 * '<S138>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator'
 * '<S139>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator ICs'
 * '<S140>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Copy'
 * '<S141>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Gain'
 * '<S142>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/P Copy'
 * '<S143>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Parallel P Gain'
 * '<S144>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Reset Signal'
 * '<S145>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation'
 * '<S146>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk'
 * '<S147>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum'
 * '<S148>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum Fdbk'
 * '<S149>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode'
 * '<S150>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum'
 * '<S151>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral'
 * '<S152>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain'
 * '<S153>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/postSat Signal'
 * '<S154>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/preSat Signal'
 * '<S155>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Anti-windup/Back Calculation'
 * '<S156>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/D Gain/Internal Parameters'
 * '<S157>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator'
 * '<S158>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S159>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S160>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S161>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/I Gain/Internal Parameters'
 * '<S162>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S163>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S164>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator/Discrete'
 * '<S165>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Integrator ICs/Internal IC'
 * '<S166>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S167>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/N Gain/Passthrough'
 * '<S168>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/P Copy/Disabled'
 * '<S169>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S170>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Reset Signal/External Reset'
 * '<S171>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation/Enabled'
 * '<S172>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S173>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum/Sum_PID'
 * '<S174>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Sum Fdbk/Disabled'
 * '<S175>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode/Disabled'
 * '<S176>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S177>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S178>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S179>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/postSat Signal/Forward_Path'
 * '<S180>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder/Airgap controller2/preSat Signal/Forward_Path'
 * '<S181>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2'
 * '<S182>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Anti-windup'
 * '<S183>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/D Gain'
 * '<S184>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter'
 * '<S185>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter ICs'
 * '<S186>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/I Gain'
 * '<S187>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain'
 * '<S188>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain Fdbk'
 * '<S189>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator'
 * '<S190>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator ICs'
 * '<S191>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Copy'
 * '<S192>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Gain'
 * '<S193>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/P Copy'
 * '<S194>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Parallel P Gain'
 * '<S195>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Reset Signal'
 * '<S196>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation'
 * '<S197>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation Fdbk'
 * '<S198>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum'
 * '<S199>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum Fdbk'
 * '<S200>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode'
 * '<S201>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode Sum'
 * '<S202>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Integral'
 * '<S203>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Ngain'
 * '<S204>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/postSat Signal'
 * '<S205>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/preSat Signal'
 * '<S206>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Anti-windup/Back Calculation'
 * '<S207>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/D Gain/Internal Parameters'
 * '<S208>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator'
 * '<S209>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator/Tsamp'
 * '<S210>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S211>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Filter ICs/Internal IC - Differentiator'
 * '<S212>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/I Gain/Internal Parameters'
 * '<S213>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain/Passthrough'
 * '<S214>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Ideal P Gain Fdbk/Disabled'
 * '<S215>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator/Discrete'
 * '<S216>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Integrator ICs/Internal IC'
 * '<S217>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Copy/Disabled wSignal Specification'
 * '<S218>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/N Gain/Passthrough'
 * '<S219>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/P Copy/Disabled'
 * '<S220>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Parallel P Gain/Internal Parameters'
 * '<S221>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Reset Signal/External Reset'
 * '<S222>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation/Enabled'
 * '<S223>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Saturation Fdbk/Disabled'
 * '<S224>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum/Sum_PID'
 * '<S225>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Sum Fdbk/Disabled'
 * '<S226>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode/Disabled'
 * '<S227>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tracking Mode Sum/Passthrough'
 * '<S228>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Integral/Passthrough'
 * '<S229>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/Tsamp - Ngain/Passthrough'
 * '<S230>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/postSat Signal/Forward_Path'
 * '<S231>' : 'ControllerLateral/Calculate Control Signals (PIDs)/Subsystem/ZeroCurrentFInder1/Airgap controller2/preSat Signal/Forward_Path'
 * '<S232>' : 'ControllerLateral/Sensors/Subsystem1'
 * '<S233>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals'
 * '<S234>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals1'
 * '<S235>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals2'
 * '<S236>' : 'ControllerLateral/Sensors/Subsystem1/Filter Noisy Signals3'
 * '<S237>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem'
 * '<S238>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem'
 * '<S239>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1'
 * '<S240>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant'
 * '<S241>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem/Compare To Constant1'
 * '<S242>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant'
 * '<S243>' : 'ControllerLateral/Sensors/Subsystem1/Subsystem/Subsystem1/Compare To Constant1'
 * '<S244>' : 'ControllerLateral/Startup Timer/Compare To Constant'
 * '<S245>' : 'ControllerLateral/Subsystem/MATLAB Function'
 * '<S246>' : 'ControllerLateral/Subsystem1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_ControllerLateral_h_ */
