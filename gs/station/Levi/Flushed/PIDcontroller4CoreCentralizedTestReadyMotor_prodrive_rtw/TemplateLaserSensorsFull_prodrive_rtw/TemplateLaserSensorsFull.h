/*
 * TemplateLaserSensorsFull.h
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

#ifndef RTW_HEADER_TemplateLaserSensorsFull_h_
#define RTW_HEADER_TemplateLaserSensorsFull_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef TemplateLaserSensorsFull_COMMON_INCLUDES_
#define TemplateLaserSensorsFull_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                           /* TemplateLaserSensorsFull_COMMON_INCLUDES_ */

#include "TemplateLaserSensorsFull_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetTemplateLaserSensorsFull_InstP_ref
#define rtmGetTemplateLaserSensorsFull_InstP_ref(rtm) ((rtm)->TemplateLaserSensorsFull_InstP_ref)
#endif

#ifndef rtmSetTemplateLaserSensorsFull_InstP_ref
#define rtmSetTemplateLaserSensorsFull_InstP_ref(rtm, val) ((rtm)->TemplateLaserSensorsFull_InstP_ref = (val))
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

#define TemplateLaserSensorsFull_M_TYPE RT_MODEL_TemplateLaserSensorsFull_T

/* Block signals for system '<S1>/Moving Average' */
typedef struct {
  real_T MovingAverage;                /* '<S1>/Moving Average' */
} B_MovingAverage_TemplateLaserSensorsFull_T;

/* Block states (default storage) for system '<S1>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_T obj;/* '<S1>/Moving Average' */
  boolean_T objisempty;                /* '<S1>/Moving Average' */
} DW_MovingAverage_TemplateLaserSensorsFull_T;

/* Block signals for system '<S3>/Moving Average2' */
typedef struct {
  real_T MovingAverage2;               /* '<S3>/Moving Average2' */
} B_MovingAverage2_TemplateLaserSensorsFull_T;

/* Block states (default storage) for system '<S3>/Moving Average2' */
typedef struct {
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e_T obj;/* '<S3>/Moving Average2' */
  boolean_T objisempty;                /* '<S3>/Moving Average2' */
} DW_MovingAverage2_TemplateLaserSensorsFull_T;

/* Block signals for system '<S21>/Moving Average6' */
typedef struct {
  real_T MovingAverage6;               /* '<S21>/Moving Average6' */
} B_MovingAverage6_TemplateLaserSensorsFull_T;

/* Block states (default storage) for system '<S21>/Moving Average6' */
typedef struct {
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T obj;/* '<S21>/Moving Average6' */
  boolean_T objisempty;                /* '<S21>/Moving Average6' */
} DW_MovingAverage6_TemplateLaserSensorsFull_T;

/* Block signals for system '<S21>/Moving Average7' */
typedef struct {
  real_T MovingAverage7;               /* '<S21>/Moving Average7' */
} B_MovingAverage7_TemplateLaserSensorsFull_T;

/* Block states (default storage) for system '<S21>/Moving Average7' */
typedef struct {
  dsp_simulink_MovingAverage_TemplateLaserSensorsFull_e3_T obj;/* '<S21>/Moving Average7' */
  boolean_T objisempty;                /* '<S21>/Moving Average7' */
} DW_MovingAverage7_TemplateLaserSensorsFull_T;

/* Block signals (default storage) */
typedef struct {
  real_T StoredPitchOffset;            /* '<S6>/Switch' */
  real_T StoredRollOffset;             /* '<S6>/Switch1' */
  real_T Switch4;                      /* '<S3>/Switch4' */
  real_T Switch4_n;                    /* '<S4>/Switch4' */
  real_T Switch4_nk;                   /* '<S5>/Switch4' */
  real_T Add4[3];                      /* '<S2>/Add4' */
  real_T Switch;                       /* '<S1>/Switch' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaevvf;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaevvf;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaevv;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaevv;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaev;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaev;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnae;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnae;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pna;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pna;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pn;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pn;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_p;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_p;/* '<S21>/Moving Average6' */
  B_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7;/* '<S21>/Moving Average7' */
  B_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6;/* '<S21>/Moving Average6' */
  B_MovingAverage_TemplateLaserSensorsFull_T MovingAverage1;/* '<S1>/Moving Average' */
  B_MovingAverage_TemplateLaserSensorsFull_T MovingAverage_p;/* '<S1>/Moving Average' */
  B_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2_pn;/* '<S3>/Moving Average2' */
  B_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2_p;/* '<S3>/Moving Average2' */
  B_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2;/* '<S3>/Moving Average2' */
  B_MovingAverage_TemplateLaserSensorsFull_T MovingAverage;/* '<S1>/Moving Average' */
} B_TemplateLaserSensorsFull_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S6>/Delay1' */
  real_T Delay_DSTATE;                 /* '<S6>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S2>/Discrete-Time Integrator' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S3>/Memory' */
  real_T Memory_PreviousInput_j;       /* '<S4>/Memory' */
  real_T Memory_PreviousInput_p;       /* '<S5>/Memory' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S2>/Discrete-Time Integrator' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaevvf;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaevvf;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaevv;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaevv;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnaev;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnaev;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pnae;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pnae;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pna;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pna;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_pn;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_pn;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7_p;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6_p;/* '<S21>/Moving Average6' */
  DW_MovingAverage7_TemplateLaserSensorsFull_T MovingAverage7;/* '<S21>/Moving Average7' */
  DW_MovingAverage6_TemplateLaserSensorsFull_T MovingAverage6;/* '<S21>/Moving Average6' */
  DW_MovingAverage_TemplateLaserSensorsFull_T MovingAverage1;/* '<S1>/Moving Average' */
  DW_MovingAverage_TemplateLaserSensorsFull_T MovingAverage_p;/* '<S1>/Moving Average' */
  DW_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2_pn;/* '<S3>/Moving Average2' */
  DW_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2_p;/* '<S3>/Moving Average2' */
  DW_MovingAverage2_TemplateLaserSensorsFull_T MovingAverage2;/* '<S3>/Moving Average2' */
  DW_MovingAverage_TemplateLaserSensorsFull_T MovingAverage;/* '<S1>/Moving Average' */
} DW_TemplateLaserSensorsFull_T;

/* instance parameters, for system '<Root>' */
typedef struct {
  real_T CalibrateIMU;                 /* Variable: CalibrateIMU
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T IMU_Filter;                   /* Variable: IMU_Filter
                                        * Referenced by:
                                        *   '<S21>/Moving Average6'
                                        *   '<S23>/Moving Average6'
                                        *   '<S25>/Moving Average6'
                                        *   '<S27>/Moving Average6'
                                        *   '<S29>/Moving Average6'
                                        *   '<S31>/Moving Average6'
                                        *   '<S33>/Moving Average6'
                                        *   '<S35>/Moving Average6'
                                        */
  real_T IMU_SecondFilter;             /* Variable: IMU_SecondFilter
                                        * Referenced by:
                                        *   '<S21>/Moving Average7'
                                        *   '<S23>/Moving Average7'
                                        *   '<S25>/Moving Average7'
                                        *   '<S27>/Moving Average7'
                                        *   '<S29>/Moving Average7'
                                        *   '<S31>/Moving Average7'
                                        *   '<S33>/Moving Average7'
                                        *   '<S35>/Moving Average7'
                                        */
  real_T a_A;                          /* Variable: a_A
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T a_A2;                         /* Variable: a_A2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T a_B;                          /* Variable: a_B
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T a_B2;                         /* Variable: a_B2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T a_C;                          /* Variable: a_C
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T a_C2;                         /* Variable: a_C2
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T a_D;                          /* Variable: a_D
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T a_D2;                         /* Variable: a_D2
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T b_A;                          /* Variable: b_A
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T b_A2;                         /* Variable: b_A2
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T b_B;                          /* Variable: b_B
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T b_B2;                         /* Variable: b_B2
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T b_C;                          /* Variable: b_C
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T b_C2;                         /* Variable: b_C2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T b_D;                          /* Variable: b_D
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T b_D2;                         /* Variable: b_D2
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T kalman_pitchdot_gain;         /* Variable: kalman_pitchdot_gain
                                        * Referenced by: '<Root>/Gain17'
                                        */
  real_T kalman_rolldot_gain;          /* Variable: kalman_rolldot_gain
                                        * Referenced by: '<Root>/Gain15'
                                        */
  real_T kalman_xdotdot_gain;          /* Variable: kalman_xdotdot_gain
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain19'
                                        *   '<Root>/Gain20'
                                        *   '<S6>/Gain3'
                                        *   '<S6>/Gain8'
                                        */
  real_T kalman_yawdot_gain;           /* Variable: kalman_yawdot_gain
                                        * Referenced by: '<Root>/Gain16'
                                        */
  real_T kalman_ydotdot_gain;          /* Variable: kalman_ydotdot_gain
                                        * Referenced by:
                                        *   '<Root>/Gain14'
                                        *   '<Root>/Gain21'
                                        *   '<Root>/Gain22'
                                        *   '<S6>/Gain6'
                                        *   '<S6>/Gain9'
                                        */
  real_T kalman_zdotdot_gain;          /* Variable: kalman_zdotdot_gain
                                        * Referenced by:
                                        *   '<Root>/Gain18'
                                        *   '<Root>/Gain23'
                                        *   '<Root>/Gain24'
                                        *   '<S6>/Gain5'
                                        *   '<S6>/Gain7'
                                        */
  real_T remove_IMU_bias_g;            /* Variable: remove_IMU_bias_g
                                        * Referenced by:
                                        *   '<S3>/Constant9'
                                        *   '<S4>/Constant9'
                                        *   '<S5>/Constant9'
                                        *   '<S6>/Constant'
                                        */
} InstP_TemplateLaserSensorsFull_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain2[3];               /* '<S2>/Gain2' */
} ConstB_TemplateLaserSensorsFull_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Voltage_A;                    /* '<Root>/Voltage_A' */
  real_T Voltage_B;                    /* '<Root>/Voltage_B' */
  real_T Voltage_C;                    /* '<Root>/Voltage_C' */
  real_T Voltage_D;                    /* '<Root>/Voltage_D' */
  real_T Voltage_A2;                   /* '<Root>/Voltage_A2' */
  real_T Voltage_B2;                   /* '<Root>/Voltage_B2' */
  real_T Voltage_C2;                   /* '<Root>/Voltage_C2' */
  real_T Voltage_D2;                   /* '<Root>/Voltage_D2' */
  real_T VerticalAxisControllerState_In;
                                   /* '<Root>/VerticalAxisControllerState_In' */
  real_T LateralAxisControllerState_In;
                                    /* '<Root>/LateralAxisControllerState_In' */
  real_T IMU1;                         /* '<Root>/IMU1' */
  real_T IMU2;                         /* '<Root>/IMU2' */
  real_T IMU3;                         /* '<Root>/IMU3' */
  real_T IMU4;                         /* '<Root>/IMU4' */
  real_T IMU5;                         /* '<Root>/IMU5' */
  real_T IMU6;                         /* '<Root>/IMU6' */
  real_T IMU7;                         /* '<Root>/IMU7' */
  real_T IMU8;                         /* '<Root>/IMU8' */
  real_T Pitch;                        /* '<Root>/Pitch' */
  real_T Roll;                         /* '<Root>/Roll' */
} ExtU_TemplateLaserSensorsFull_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T G_A;                          /* '<Root>/G_A' */
  real_T G_B;                          /* '<Root>/G_B' */
  real_T G_C;                          /* '<Root>/G_C' */
  real_T G_D;                          /* '<Root>/G_D' */
  real_T G_A2;                         /* '<Root>/G_A2' */
  real_T G_B2;                         /* '<Root>/G_B2' */
  real_T G_C2;                         /* '<Root>/G_C2' */
  real_T G_D2;                         /* '<Root>/G_D2' */
  real_T VerticalAxisControllerState_Out;
                                  /* '<Root>/VerticalAxisControllerState_Out' */
  real_T LateralAxisControllerState_Out;
                                   /* '<Root>/LateralAxisControllerState_Out' */
  real_T IMU_x;                        /* '<Root>/IMU_x' */
  real_T IMU_y;                        /* '<Root>/IMU_y' */
  real_T IMU_pitch;                    /* '<Root>/IMU_pitch' */
  real_T IMU_z;                        /* '<Root>/IMU_z' */
  real_T IMU_roll;                     /* '<Root>/IMU_roll' */
  real_T IMU_yaw;                      /* '<Root>/IMU_yaw' */
  real_T IMU_temp;                     /* '<Root>/IMU_temp' */
  real_T IMU_out8;                     /* '<Root>/IMU_out8' */
  real_T Vx;                           /* '<Root>/Vx' */
  real_T Vz;                           /* '<Root>/Vz' */
  real_T Vy;                           /* '<Root>/Vy' */
  real_T IOval_to_mV;                  /* '<Root>/IOval_to_mV' */
  real_T com_spd_x;                    /* '<Root>/com_spd_x' */
  real_T com_spd_y;                    /* '<Root>/com_spd_y' */
  real_T com_spd_z;                    /* '<Root>/com_spd_z' */
  real_T com_acc_x;                    /* '<Root>/com_acc_x' */
  real_T com_acc_y;                    /* '<Root>/com_acc_y' */
  real_T com_acc_z;                    /* '<Root>/com_acc_z' */
} ExtY_TemplateLaserSensorsFull_T;

/* Real-time Model Data Structure */
struct tag_RTM_TemplateLaserSensorsFull_T {
  const char_T *errorStatus;
  B_TemplateLaserSensorsFull_T *blockIO;
  ExtU_TemplateLaserSensorsFull_T *inputs;
  ExtY_TemplateLaserSensorsFull_T *outputs;
  DW_TemplateLaserSensorsFull_T *dwork;
  InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP_ref;
};

/* instance parameters */
extern InstP_TemplateLaserSensorsFull_T TemplateLaserSensorsFull_InstP;

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern const ConstB_TemplateLaserSensorsFull_T TemplateLaserSensorsFull_ConstB;/* constant block i/o */

/* Model entry point functions */
extern RT_MODEL_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull(void);
extern void TemplateLaserSensorsFull_initialize
  (RT_MODEL_TemplateLaserSensorsFull_T *const TemplateLaserSensorsFull_M);
extern void TemplateLaserSensorsFull_output(RT_MODEL_TemplateLaserSensorsFull_T *
  const TemplateLaserSensorsFull_M);
extern void TemplateLaserSensorsFull_update(RT_MODEL_TemplateLaserSensorsFull_T *
  const TemplateLaserSensorsFull_M);
extern void TemplateLaserSensorsFull_terminate
  (RT_MODEL_TemplateLaserSensorsFull_T * TemplateLaserSensorsFull_M);

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
 * '<Root>' : 'TemplateLaserSensorsFull'
 * '<S1>'   : 'TemplateLaserSensorsFull/Find mV factor (calibration)'
 * '<S2>'   : 'TemplateLaserSensorsFull/IMU offset corrections (Right hand sys)'
 * '<S3>'   : 'TemplateLaserSensorsFull/Remove IMU Bias2'
 * '<S4>'   : 'TemplateLaserSensorsFull/Remove IMU Bias4'
 * '<S5>'   : 'TemplateLaserSensorsFull/Remove IMU Bias5'
 * '<S6>'   : 'TemplateLaserSensorsFull/Subsystem'
 * '<S7>'   : 'TemplateLaserSensorsFull/Subsystem8'
 * '<S8>'   : 'TemplateLaserSensorsFull/acc x'
 * '<S9>'   : 'TemplateLaserSensorsFull/acc y'
 * '<S10>'  : 'TemplateLaserSensorsFull/acc z'
 * '<S11>'  : 'TemplateLaserSensorsFull/temp'
 * '<S12>'  : 'TemplateLaserSensorsFull/velo pitch (x)'
 * '<S13>'  : 'TemplateLaserSensorsFull/velo rol (y)'
 * '<S14>'  : 'TemplateLaserSensorsFull/velo yaw (z)'
 * '<S15>'  : 'TemplateLaserSensorsFull/IMU offset corrections (Right hand sys)/Cross Product6'
 * '<S16>'  : 'TemplateLaserSensorsFull/IMU offset corrections (Right hand sys)/Cross Product7'
 * '<S17>'  : 'TemplateLaserSensorsFull/IMU offset corrections (Right hand sys)/Cross Product8'
 * '<S18>'  : 'TemplateLaserSensorsFull/Subsystem/Degrees to Radians'
 * '<S19>'  : 'TemplateLaserSensorsFull/Subsystem/Degrees to Radians1'
 * '<S20>'  : 'TemplateLaserSensorsFull/Subsystem8/Factor'
 * '<S21>'  : 'TemplateLaserSensorsFull/Subsystem8/Filters'
 * '<S22>'  : 'TemplateLaserSensorsFull/acc x/Factor'
 * '<S23>'  : 'TemplateLaserSensorsFull/acc x/Filters'
 * '<S24>'  : 'TemplateLaserSensorsFull/acc y/Factor'
 * '<S25>'  : 'TemplateLaserSensorsFull/acc y/Filters'
 * '<S26>'  : 'TemplateLaserSensorsFull/acc z/Factor'
 * '<S27>'  : 'TemplateLaserSensorsFull/acc z/Filters'
 * '<S28>'  : 'TemplateLaserSensorsFull/temp/Factor'
 * '<S29>'  : 'TemplateLaserSensorsFull/temp/Filters'
 * '<S30>'  : 'TemplateLaserSensorsFull/velo pitch (x)/Factor'
 * '<S31>'  : 'TemplateLaserSensorsFull/velo pitch (x)/Filters'
 * '<S32>'  : 'TemplateLaserSensorsFull/velo rol (y)/Factor'
 * '<S33>'  : 'TemplateLaserSensorsFull/velo rol (y)/Filters'
 * '<S34>'  : 'TemplateLaserSensorsFull/velo yaw (z)/Factor'
 * '<S35>'  : 'TemplateLaserSensorsFull/velo yaw (z)/Filters'
 */
#endif                              /* RTW_HEADER_TemplateLaserSensorsFull_h_ */
