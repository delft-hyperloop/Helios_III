/*
 * TemplateLaserSensorsFull.c
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

#include "TemplateLaserSensorsFull.h"
#include "TemplateLaserSensorsFull_private.h"

/* Model output function */
void TemplateLaserSensorsFull_output(RT_MODEL_TemplateLaserSensorsFull_T *const
  TemplateLaserSensorsFull_M)
{
  InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP =
    TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref;
  ExtU_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_U =
    (ExtU_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->inputs;
  ExtY_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_Y =
    (ExtY_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->outputs;

  /* Outport: '<Root>/G_A' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Voltage_A'
   *  Sum: '<Root>/Add'
   */
  TemplateLaserSensorsFull_Y->G_A = TemplateLaserSensorsFull_InstP->a_A *
    TemplateLaserSensorsFull_U->Voltage_A + TemplateLaserSensorsFull_InstP->b_A;

  /* Outport: '<Root>/G_B' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain1'
   *  Inport: '<Root>/Voltage_B'
   *  Sum: '<Root>/Add1'
   */
  TemplateLaserSensorsFull_Y->G_B = TemplateLaserSensorsFull_InstP->a_B *
    TemplateLaserSensorsFull_U->Voltage_B + TemplateLaserSensorsFull_InstP->b_B;

  /* Outport: '<Root>/G_C' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain2'
   *  Inport: '<Root>/Voltage_C'
   *  Sum: '<Root>/Add2'
   */
  TemplateLaserSensorsFull_Y->G_C = TemplateLaserSensorsFull_InstP->a_C *
    TemplateLaserSensorsFull_U->Voltage_C + TemplateLaserSensorsFull_InstP->b_C;

  /* Outport: '<Root>/G_D' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain3'
   *  Inport: '<Root>/Voltage_D'
   *  Sum: '<Root>/Add3'
   */
  TemplateLaserSensorsFull_Y->G_D = TemplateLaserSensorsFull_InstP->a_D *
    TemplateLaserSensorsFull_U->Voltage_D + TemplateLaserSensorsFull_InstP->b_D;

  /* Outport: '<Root>/G_A2' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<Root>/Gain4'
   *  Inport: '<Root>/Voltage_A2'
   *  Sum: '<Root>/Add4'
   */
  TemplateLaserSensorsFull_Y->G_A2 = TemplateLaserSensorsFull_InstP->a_A2 *
    TemplateLaserSensorsFull_U->Voltage_A2 +
    TemplateLaserSensorsFull_InstP->b_A2;

  /* Outport: '<Root>/G_B2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Gain: '<Root>/Gain5'
   *  Inport: '<Root>/Voltage_B2'
   *  Sum: '<Root>/Add5'
   */
  TemplateLaserSensorsFull_Y->G_B2 = TemplateLaserSensorsFull_InstP->a_B2 *
    TemplateLaserSensorsFull_U->Voltage_B2 +
    TemplateLaserSensorsFull_InstP->b_B2;

  /* Outport: '<Root>/G_C2' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Gain: '<Root>/Gain6'
   *  Inport: '<Root>/Voltage_C2'
   *  Sum: '<Root>/Add6'
   */
  TemplateLaserSensorsFull_Y->G_C2 = TemplateLaserSensorsFull_InstP->a_C2 *
    TemplateLaserSensorsFull_U->Voltage_C2 +
    TemplateLaserSensorsFull_InstP->b_C2;

  /* Outport: '<Root>/G_D2' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Gain: '<Root>/Gain7'
   *  Inport: '<Root>/Voltage_D2'
   *  Sum: '<Root>/Add7'
   */
  TemplateLaserSensorsFull_Y->G_D2 = TemplateLaserSensorsFull_InstP->a_D2 *
    TemplateLaserSensorsFull_U->Voltage_D2 +
    TemplateLaserSensorsFull_InstP->b_D2;

  /* Outport: '<Root>/VerticalAxisControllerState_Out' incorporates:
   *  Inport: '<Root>/VerticalAxisControllerState_In'
   */
  TemplateLaserSensorsFull_Y->VerticalAxisControllerState_Out =
    TemplateLaserSensorsFull_U->VerticalAxisControllerState_In;

  /* Outport: '<Root>/LateralAxisControllerState_Out' incorporates:
   *  Inport: '<Root>/LateralAxisControllerState_In'
   */
  TemplateLaserSensorsFull_Y->LateralAxisControllerState_Out =
    TemplateLaserSensorsFull_U->LateralAxisControllerState_In;
}

/* Model update function */
void TemplateLaserSensorsFull_update(RT_MODEL_TemplateLaserSensorsFull_T *const
  TemplateLaserSensorsFull_M)
{
  UNUSED_PARAMETER(TemplateLaserSensorsFull_M);

  /* (no update code required) */
}

/* Model initialize function */
void TemplateLaserSensorsFull_initialize(RT_MODEL_TemplateLaserSensorsFull_T *
  const TemplateLaserSensorsFull_M)
{
  UNUSED_PARAMETER(TemplateLaserSensorsFull_M);
}

/* Model terminate function */
void TemplateLaserSensorsFull_terminate(RT_MODEL_TemplateLaserSensorsFull_T
  * TemplateLaserSensorsFull_M)
{
  /* model code */
  rt_FREE(TemplateLaserSensorsFull_M->inputs);
  rt_FREE(TemplateLaserSensorsFull_M->outputs);

  /* Free instance parameters */
  rt_FREE(TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref);
  rt_FREE(TemplateLaserSensorsFull_M);
}

/* Model data allocation function */
RT_MODEL_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull(void)
{
  RT_MODEL_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_M;
  TemplateLaserSensorsFull_M = (RT_MODEL_TemplateLaserSensorsFull_T *) malloc
    (sizeof(RT_MODEL_TemplateLaserSensorsFull_T));
  if (TemplateLaserSensorsFull_M == NULL) {
    return NULL;
  }

  (void) memset((char *)TemplateLaserSensorsFull_M, 0,
                sizeof(RT_MODEL_TemplateLaserSensorsFull_T));

  /* Initialize instance parameters */
  {
    InstP_TemplateLaserSensorsFull_T *group__InstP =
      (InstP_TemplateLaserSensorsFull_T *) malloc(sizeof
      (InstP_TemplateLaserSensorsFull_T));
    rt_VALIDATE_MEMORY(TemplateLaserSensorsFull_M,group__InstP);
    TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref =
      (group__InstP);
    (void) memcpy(group__InstP, &TemplateLaserSensorsFull_InstP,
                  sizeof(InstP_TemplateLaserSensorsFull_T));
  }

  /* external inputs */
  {
    ExtU_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_U =
      (ExtU_TemplateLaserSensorsFull_T *) malloc(sizeof
      (ExtU_TemplateLaserSensorsFull_T));
    rt_VALIDATE_MEMORY(TemplateLaserSensorsFull_M,TemplateLaserSensorsFull_U);
    TemplateLaserSensorsFull_M->inputs = (((ExtU_TemplateLaserSensorsFull_T *)
      TemplateLaserSensorsFull_U));
  }

  /* external outputs */
  {
    ExtY_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_Y =
      (ExtY_TemplateLaserSensorsFull_T *) malloc(sizeof
      (ExtY_TemplateLaserSensorsFull_T));
    rt_VALIDATE_MEMORY(TemplateLaserSensorsFull_M,TemplateLaserSensorsFull_Y);
    TemplateLaserSensorsFull_M->outputs = (TemplateLaserSensorsFull_Y);
  }

  {
    ExtU_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_U =
      (ExtU_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->inputs;
    ExtY_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_Y =
      (ExtY_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->outputs;

    /* external inputs */
    (void)memset(TemplateLaserSensorsFull_U, 0, sizeof
                 (ExtU_TemplateLaserSensorsFull_T));

    /* external outputs */
    (void) memset((void *)TemplateLaserSensorsFull_Y, 0,
                  sizeof(ExtY_TemplateLaserSensorsFull_T));
  }

  return TemplateLaserSensorsFull_M;
}
