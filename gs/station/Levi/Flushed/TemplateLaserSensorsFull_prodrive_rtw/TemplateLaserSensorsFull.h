/*
 * TemplateLaserSensorsFull.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TemplateLaserSensorsFull".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon May 20 13:05:41 2024
 *
 * Target selection: pmp.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TemplateLaserSensorsFull_h_
#define RTW_HEADER_TemplateLaserSensorsFull_h_
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
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
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

/* instance parameters, for system '<Root>' */
typedef struct {
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
} InstP_TemplateLaserSensorsFull_T;

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
} ExtY_TemplateLaserSensorsFull_T;

/* Real-time Model Data Structure */
struct tag_RTM_TemplateLaserSensorsFull_T {
  const char_T *errorStatus;
  ExtU_TemplateLaserSensorsFull_T *inputs;
  ExtY_TemplateLaserSensorsFull_T *outputs;
  InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP_ref;
};

/* instance parameters */
extern InstP_TemplateLaserSensorsFull_T TemplateLaserSensorsFull_InstP;

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

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
 */
#endif                              /* RTW_HEADER_TemplateLaserSensorsFull_h_ */
