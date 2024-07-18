/*
 * TemplateLaserSensorsFull.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TemplateLaserSensorsFull".
 *
 * Model version              : 1.40
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Jul 13 15:26:00 2024
 *
 * Target selection: pmp.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TemplateLaserSensorsFull.h"
#include "TemplateLaserSensorsFull_private.h"

/* Forward declaration for local functions */
static real_T TemplateLaserSensorsFull_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *obj, real_T
   u);
static real_T TemplateLaserSensorsFull_SlidingWindowAverageCG_stepImpl
  (c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *obj, real_T
   u)
{
  real_T csum;
  real_T cumRevIndex;
  real_T y;
  real_T z;
  int32_T k;
  csum = obj->pCumSum + u;
  z = obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] + csum;
  obj->pCumSumRev[(int32_T)obj->pCumRevIndex - 1] = u;
  if (obj->pCumRevIndex != 1999.0) {
    cumRevIndex = obj->pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (k = 1997; k >= 0; k--) {
      obj->pCumSumRev[k] += obj->pCumSumRev[k + 1];
    }
  }

  y = z / 2000.0;
  obj->pCumSum = csum;
  obj->pCumRevIndex = cumRevIndex;
  return y;
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage_Init
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 1999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage_Start
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW)
{
  /* Start for MATLABSystem: '<S1>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage(real_T rtu_0,
  B_MovingAverage_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *obj;
  int32_T i;

  /* MATLABSystem: '<S1>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 1999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 1999; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  /* MATLABSystem: '<S1>/Moving Average' */
  localB->MovingAverage =
    TemplateLaserSensorsFull_SlidingWindowAverageCG_stepImpl(obj, rtu_0);
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage_Term
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_SlidingWindowAverageCG_TemplateLaserSensorsFull_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage6_Init
  (DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;

  /* InitializeConditions for MATLABSystem: '<S15>/Moving Average6' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S15>/Moving Average6' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage6_Start(real_T rtp_IMU_Filter,
  DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW)
{
  real_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<S15>/Moving Average6' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  flag = (boolean_T)(localDW->obj.isInitialized == 1);
  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.ForgettingFactor = rtp_IMU_Filter;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  varargin_2 = localDW->obj.ForgettingFactor;
  localDW->obj._pobj0.isInitialized = 0;
  flag = (boolean_T)(localDW->obj._pobj0.isInitialized == 1);
  if (flag) {
    localDW->obj._pobj0.TunablePropsChanged = true;
  }

  localDW->obj._pobj0.ForgettingFactor = varargin_2;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S15>/Moving Average6' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage6(real_T rtu_0, real_T rtp_IMU_Filter,
  B_MovingAverage6_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;
  boolean_T flag;

  /* MATLABSystem: '<S15>/Moving Average6' */
  if (localDW->obj.ForgettingFactor != rtp_IMU_Filter) {
    flag = (boolean_T)(localDW->obj.isInitialized == 1);
    if (flag) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = rtp_IMU_Filter;
  }

  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
    obj = localDW->obj.pStatistic;
    flag = (boolean_T)(obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
    }

    localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  pmLocal = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * rtu_0;
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = pmLocal;

  /* MATLABSystem: '<S15>/Moving Average6' */
  localB->MovingAverage6 = pmLocal;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage6_Term
  (DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;

  /* Terminate for MATLABSystem: '<S15>/Moving Average6' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Moving Average6' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage7_Init
  (DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;

  /* InitializeConditions for MATLABSystem: '<S15>/Moving Average7' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S15>/Moving Average7' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage7_Start(real_T rtp_IMU_SecondFilter,
  DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW)
{
  real_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<S15>/Moving Average7' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  flag = (boolean_T)(localDW->obj.isInitialized == 1);
  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.ForgettingFactor = rtp_IMU_SecondFilter;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  varargin_2 = localDW->obj.ForgettingFactor;
  localDW->obj._pobj0.isInitialized = 0;
  flag = (boolean_T)(localDW->obj._pobj0.isInitialized == 1);
  if (flag) {
    localDW->obj._pobj0.TunablePropsChanged = true;
  }

  localDW->obj._pobj0.ForgettingFactor = varargin_2;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S15>/Moving Average7' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage7(real_T rtu_0, real_T
  rtp_IMU_SecondFilter, B_MovingAverage7_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;
  boolean_T flag;

  /* MATLABSystem: '<S15>/Moving Average7' */
  if (localDW->obj.ForgettingFactor != rtp_IMU_SecondFilter) {
    flag = (boolean_T)(localDW->obj.isInitialized == 1);
    if (flag) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = rtp_IMU_SecondFilter;
  }

  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
    obj = localDW->obj.pStatistic;
    flag = (boolean_T)(obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
    }

    localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  pmLocal = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * rtu_0;
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = pmLocal;

  /* MATLABSystem: '<S15>/Moving Average7' */
  localB->MovingAverage7 = pmLocal;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void TemplateLaserSensorsFull_MovingAverage7_Term
  (DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW)
{
  c_dsp_private_ExponentialMovingAverage_TemplateLaserSensorsFull_T *obj;

  /* Terminate for MATLABSystem: '<S15>/Moving Average7' */
  if (!(int32_T)localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && ((int32_T)
         localDW->obj.isSetupComplete)) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Moving Average7' */
}

/* Model output function */
void TemplateLaserSensorsFull_output(RT_MODEL_TemplateLaserSensorsFull_T *const
  TemplateLaserSensorsFull_M)
{
  B_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_B =
    TemplateLaserSensorsFull_M->blockIO;
  DW_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_DW =
    TemplateLaserSensorsFull_M->dwork;
  InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP =
    TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref;
  ExtU_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_U =
    (ExtU_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->inputs;
  ExtY_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_Y =
    (ExtY_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->outputs;

  /* local block i/o variables */
  real_T rtb_RollOffset;
  real_T rtb_PitchOffset;
  real_T rtb_Gain11;
  real_T rtb_Gain10;
  real_T rtb_Gain12;
  real_T rtb_IO_valtomV;
  real_T rtb_ActualRoll_h;
  real_T rtb_Gain3_k;
  real_T rtb_Memory;
  real_T rtb_Sqrt;

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

  /* Inport: '<Root>/IMU2' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU2,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pn,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pn);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pn.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pn,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pn);

  /* Memory: '<S1>/Memory' */
  rtb_Memory = TemplateLaserSensorsFull_DW->Memory_PreviousInput;

  /* Gain: '<S5>/Gain6' incorporates:
   *  Gain: '<Root>/Gain9'
   *  Memory: '<S1>/Memory'
   *  Product: '<S18>/Product'
   */
  rtb_Gain3_k = TemplateLaserSensorsFull_B->MovingAverage7_pn.MovingAverage7 *
    TemplateLaserSensorsFull_DW->Memory_PreviousInput * 0.00721917412647993 *
    TemplateLaserSensorsFull_InstP->kalman_ydotdot_gain;

  /* Gain: '<S5>/Gain2' */
  rtb_Sqrt = -0.10196382323551605 * rtb_Gain3_k;

  /* Trigonometry: '<S5>/Asin1' */
  if (rtb_Sqrt > 1.0) {
    rtb_Sqrt = 1.0;
  } else if (rtb_Sqrt < -1.0) {
    rtb_Sqrt = -1.0;
  }

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Inport: '<Root>/Roll'
   *  Trigonometry: '<S5>/Asin1'
   */
  rtb_RollOffset = TemplateLaserSensorsFull_U->Roll - asin(rtb_Sqrt);
  TemplateLaserSensorsFull_MovingAverage(rtb_RollOffset,
    &TemplateLaserSensorsFull_B->MovingAverage_p,
    &TemplateLaserSensorsFull_DW->MovingAverage_p);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (TemplateLaserSensorsFull_InstP->remove_IMU_bias_g > 0.0) {
    /* Switch: '<S5>/Switch1' */
    TemplateLaserSensorsFull_B->StoredRollOffset =
      TemplateLaserSensorsFull_B->MovingAverage_p.MovingAverage;
  } else {
    /* Switch: '<S5>/Switch1' incorporates:
     *  Delay: '<S5>/Delay'
     */
    TemplateLaserSensorsFull_B->StoredRollOffset =
      TemplateLaserSensorsFull_DW->Delay_DSTATE;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* Sum: '<S5>/Subtract3' incorporates:
   *  Inport: '<Root>/Roll'
   */
  rtb_ActualRoll_h = TemplateLaserSensorsFull_B->StoredRollOffset +
    TemplateLaserSensorsFull_U->Roll;

  /* Outport: '<Root>/IMU_x' incorporates:
   *  Gain: '<S5>/Gain4'
   *  Gain: '<S5>/Gain9'
   *  Sum: '<S5>/Remove gravity from y (Not Sure About Sign)'
   *  Trigonometry: '<S5>/Sin1'
   */
  TemplateLaserSensorsFull_Y->IMU_x = (-9.8074 * sin(rtb_ActualRoll_h) +
    rtb_Gain3_k) * TemplateLaserSensorsFull_InstP->kalman_ydotdot_gain;

  /* Inport: '<Root>/IMU1' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU1,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_p,
    &TemplateLaserSensorsFull_DW->MovingAverage6_p);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_p.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_p,
     &TemplateLaserSensorsFull_DW->MovingAverage7_p);

  /* Gain: '<S5>/Gain3' incorporates:
   *  Gain: '<Root>/Gain8'
   *  Product: '<S16>/Product'
   */
  rtb_Gain3_k = TemplateLaserSensorsFull_B->MovingAverage7_p.MovingAverage7 *
    rtb_Memory * 0.00720772668300418 *
    TemplateLaserSensorsFull_InstP->kalman_xdotdot_gain;

  /* Gain: '<S5>/Gain1' */
  rtb_Sqrt = 0.10196382323551605 * rtb_Gain3_k;

  /* Trigonometry: '<S5>/Asin' */
  if (rtb_Sqrt > 1.0) {
    rtb_Sqrt = 1.0;
  } else if (rtb_Sqrt < -1.0) {
    rtb_Sqrt = -1.0;
  }

  /* Sum: '<S5>/Subtract' incorporates:
   *  Inport: '<Root>/Pitch'
   *  Trigonometry: '<S5>/Asin'
   */
  rtb_PitchOffset = TemplateLaserSensorsFull_U->Pitch - asin(rtb_Sqrt);
  TemplateLaserSensorsFull_MovingAverage(rtb_PitchOffset,
    &TemplateLaserSensorsFull_B->MovingAverage1,
    &TemplateLaserSensorsFull_DW->MovingAverage1);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (TemplateLaserSensorsFull_InstP->remove_IMU_bias_g > 0.0) {
    /* Switch: '<S5>/Switch' */
    TemplateLaserSensorsFull_B->StoredPitchOffset =
      TemplateLaserSensorsFull_B->MovingAverage1.MovingAverage;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Delay: '<S5>/Delay1'
     */
    TemplateLaserSensorsFull_B->StoredPitchOffset =
      TemplateLaserSensorsFull_DW->Delay1_DSTATE;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S5>/Subtract2' incorporates:
   *  Inport: '<Root>/Pitch'
   */
  rtb_Sqrt = TemplateLaserSensorsFull_B->StoredPitchOffset +
    TemplateLaserSensorsFull_U->Pitch;

  /* Outport: '<Root>/IMU_y' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain8'
   *  Sum: '<S5>/Remove gravity from x (Not Sure About Sign)'
   *  Trigonometry: '<S5>/Sin'
   */
  TemplateLaserSensorsFull_Y->IMU_y = (9.8074 * sin(rtb_Sqrt) + rtb_Gain3_k) *
    TemplateLaserSensorsFull_InstP->kalman_xdotdot_gain;

  /* Inport: '<Root>/IMU4' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU4,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pna,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pna);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pna.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pna,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pna);

  /* Outport: '<Root>/IMU_z' incorporates:
   *  Gain: '<Root>/mV to acc'
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain7'
   *  Gain: '<S5>/Gravity on Z axis'
   *  Product: '<S20>/Product'
   *  Product: '<S5>/Product'
   *  Sum: '<S5>/Remove Gravity from z'
   *  Trigonometry: '<S5>/Cos'
   *  Trigonometry: '<S5>/Cos1'
   */
  TemplateLaserSensorsFull_Y->IMU_z =
    (TemplateLaserSensorsFull_B->MovingAverage7_pna.MovingAverage7 * rtb_Memory *
     0.018084163697849796 * TemplateLaserSensorsFull_InstP->kalman_zdotdot_gain
     + cos(rtb_Sqrt) * cos(rtb_ActualRoll_h) * 9.8074) *
    TemplateLaserSensorsFull_InstP->kalman_zdotdot_gain;

  /* Inport: '<Root>/IMU5' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU5,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pnaev,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pnaev);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pnaev.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pnaev,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaev);

  /* Gain: '<Root>/Gain11' incorporates:
   *  Product: '<S24>/Product'
   */
  rtb_Gain11 = TemplateLaserSensorsFull_B->MovingAverage7_pnaev.MovingAverage7 *
    rtb_Memory * 8.6333419666753E-5;
  TemplateLaserSensorsFull_MovingAverage(rtb_Gain11,
    &TemplateLaserSensorsFull_B->MovingAverage2,
    &TemplateLaserSensorsFull_DW->MovingAverage2);

  /* Switch: '<S2>/Switch4' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  if (TemplateLaserSensorsFull_InstP->remove_IMU_bias_g > 0.0) {
    /* Switch: '<S2>/Switch4' */
    TemplateLaserSensorsFull_B->Switch4 =
      TemplateLaserSensorsFull_B->MovingAverage2.MovingAverage;
  } else {
    /* Switch: '<S2>/Switch4' incorporates:
     *  Memory: '<S2>/Memory'
     */
    TemplateLaserSensorsFull_B->Switch4 =
      TemplateLaserSensorsFull_DW->Memory_PreviousInput_g;
  }

  /* End of Switch: '<S2>/Switch4' */

  /* Outport: '<Root>/IMU_pitch' incorporates:
   *  Sum: '<S2>/Subtract3'
   */
  TemplateLaserSensorsFull_Y->IMU_pitch = rtb_Gain11 -
    TemplateLaserSensorsFull_B->Switch4;

  /* Inport: '<Root>/IMU3' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU3,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pnaevv,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pnaevv);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pnaevv.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pnaevv,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaevv);

  /* Gain: '<Root>/Gain10' incorporates:
   *  Product: '<S26>/Product'
   */
  rtb_Gain10 = TemplateLaserSensorsFull_B->MovingAverage7_pnaevv.MovingAverage7 *
    rtb_Memory * 8.6281276962899049E-5;
  TemplateLaserSensorsFull_MovingAverage(rtb_Gain10,
    &TemplateLaserSensorsFull_B->MovingAverage2_p,
    &TemplateLaserSensorsFull_DW->MovingAverage2_p);

  /* Switch: '<S3>/Switch4' incorporates:
   *  Constant: '<S3>/Constant9'
   */
  if (TemplateLaserSensorsFull_InstP->remove_IMU_bias_g > 0.0) {
    /* Switch: '<S3>/Switch4' */
    TemplateLaserSensorsFull_B->Switch4_n =
      TemplateLaserSensorsFull_B->MovingAverage2_p.MovingAverage;
  } else {
    /* Switch: '<S3>/Switch4' incorporates:
     *  Memory: '<S3>/Memory'
     */
    TemplateLaserSensorsFull_B->Switch4_n =
      TemplateLaserSensorsFull_DW->Memory_PreviousInput_j;
  }

  /* End of Switch: '<S3>/Switch4' */

  /* Outport: '<Root>/IMU_roll' incorporates:
   *  Sum: '<S3>/Subtract3'
   */
  TemplateLaserSensorsFull_Y->IMU_roll = rtb_Gain10 -
    TemplateLaserSensorsFull_B->Switch4_n;

  /* Inport: '<Root>/IMU6' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU6,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pnaevvf,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pnaevvf.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pnaevvf,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaevvf);

  /* Gain: '<Root>/Gain12' incorporates:
   *  Product: '<S28>/Product'
   */
  rtb_Gain12 = TemplateLaserSensorsFull_B->MovingAverage7_pnaevvf.MovingAverage7
    * rtb_Memory * 8.6400552963538971E-5;
  TemplateLaserSensorsFull_MovingAverage(rtb_Gain12,
    &TemplateLaserSensorsFull_B->MovingAverage2_pn,
    &TemplateLaserSensorsFull_DW->MovingAverage2_pn);

  /* Switch: '<S4>/Switch4' incorporates:
   *  Constant: '<S4>/Constant9'
   */
  if (TemplateLaserSensorsFull_InstP->remove_IMU_bias_g > 0.0) {
    /* Switch: '<S4>/Switch4' */
    TemplateLaserSensorsFull_B->Switch4_nk =
      TemplateLaserSensorsFull_B->MovingAverage2_pn.MovingAverage;
  } else {
    /* Switch: '<S4>/Switch4' incorporates:
     *  Memory: '<S4>/Memory'
     */
    TemplateLaserSensorsFull_B->Switch4_nk =
      TemplateLaserSensorsFull_DW->Memory_PreviousInput_p;
  }

  /* End of Switch: '<S4>/Switch4' */

  /* Outport: '<Root>/IMU_yaw' incorporates:
   *  Sum: '<S4>/Subtract3'
   */
  TemplateLaserSensorsFull_Y->IMU_yaw = rtb_Gain12 -
    TemplateLaserSensorsFull_B->Switch4_nk;

  /* Inport: '<Root>/IMU7' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU7,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6_pnae,
    &TemplateLaserSensorsFull_DW->MovingAverage6_pnae);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6_pnae.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7_pnae,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnae);

  /* Outport: '<Root>/IMU_temp' incorporates:
   *  Product: '<S22>/Product'
   */
  TemplateLaserSensorsFull_Y->IMU_temp =
    TemplateLaserSensorsFull_B->MovingAverage7_pnae.MovingAverage7 * rtb_Memory;

  /* Inport: '<Root>/IMU8' */
  TemplateLaserSensorsFull_MovingAverage6(TemplateLaserSensorsFull_U->IMU8,
    TemplateLaserSensorsFull_InstP->IMU_Filter,
    &TemplateLaserSensorsFull_B->MovingAverage6,
    &TemplateLaserSensorsFull_DW->MovingAverage6);
  TemplateLaserSensorsFull_MovingAverage7
    (TemplateLaserSensorsFull_B->MovingAverage6.MovingAverage6,
     TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_B->MovingAverage7,
     &TemplateLaserSensorsFull_DW->MovingAverage7);

  /* Outport: '<Root>/IMU_out8' incorporates:
   *  Product: '<S14>/Product'
   */
  TemplateLaserSensorsFull_Y->IMU_out8 =
    TemplateLaserSensorsFull_B->MovingAverage7.MovingAverage7 * rtb_Memory;

  /* Outport: '<Root>/Vx' */
  TemplateLaserSensorsFull_Y->Vx =
    TemplateLaserSensorsFull_B->MovingAverage7_p.MovingAverage7;

  /* Outport: '<Root>/Vz' */
  TemplateLaserSensorsFull_Y->Vz =
    TemplateLaserSensorsFull_B->MovingAverage7_pna.MovingAverage7;

  /* Outport: '<Root>/Vy' */
  TemplateLaserSensorsFull_Y->Vy =
    TemplateLaserSensorsFull_B->MovingAverage7_pn.MovingAverage7;

  /* Gain: '<S1>/Cy' */
  rtb_Sqrt = 0.00720772668300418 *
    TemplateLaserSensorsFull_B->MovingAverage7_p.MovingAverage7;

  /* Math: '<S1>/Square' */
  rtb_Gain3_k = rtb_Sqrt * rtb_Sqrt;

  /* Gain: '<S1>/Cx' */
  rtb_Sqrt = 0.00721917412647993 *
    TemplateLaserSensorsFull_B->MovingAverage7_pn.MovingAverage7;

  /* Math: '<S1>/Square1' */
  rtb_ActualRoll_h = rtb_Sqrt * rtb_Sqrt;

  /* Gain: '<S1>/Cz' */
  rtb_Sqrt = 0.018084163697849796 *
    TemplateLaserSensorsFull_B->MovingAverage7_pna.MovingAverage7;

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/g'
   *  Math: '<S1>/Square2'
   *  Sqrt: '<S1>/Sqrt'
   *  Sum: '<S1>/Add9'
   */
  rtb_IO_valtomV = 9.8074 / sqrt((rtb_Gain3_k + rtb_ActualRoll_h) + rtb_Sqrt *
    rtb_Sqrt);
  TemplateLaserSensorsFull_MovingAverage(rtb_IO_valtomV,
    &TemplateLaserSensorsFull_B->MovingAverage,
    &TemplateLaserSensorsFull_DW->MovingAverage);

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (TemplateLaserSensorsFull_InstP->CalibrateIMU > 0.0) {
    /* Switch: '<S1>/Switch' */
    TemplateLaserSensorsFull_B->Switch =
      TemplateLaserSensorsFull_B->MovingAverage.MovingAverage;
  } else {
    /* Switch: '<S1>/Switch' */
    TemplateLaserSensorsFull_B->Switch = rtb_Memory;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/IOval_to_mV' */
  TemplateLaserSensorsFull_Y->IOval_to_mV = rtb_Memory;
}

/* Model update function */
void TemplateLaserSensorsFull_update(RT_MODEL_TemplateLaserSensorsFull_T *const
  TemplateLaserSensorsFull_M)
{
  B_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_B =
    TemplateLaserSensorsFull_M->blockIO;
  DW_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_DW =
    TemplateLaserSensorsFull_M->dwork;

  /* Update for Memory: '<S1>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput =
    TemplateLaserSensorsFull_B->Switch;

  /* Update for Delay: '<S5>/Delay' */
  TemplateLaserSensorsFull_DW->Delay_DSTATE =
    TemplateLaserSensorsFull_B->StoredRollOffset;

  /* Update for Delay: '<S5>/Delay1' */
  TemplateLaserSensorsFull_DW->Delay1_DSTATE =
    TemplateLaserSensorsFull_B->StoredPitchOffset;

  /* Update for Memory: '<S2>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_g =
    TemplateLaserSensorsFull_B->Switch4;

  /* Update for Memory: '<S3>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_j =
    TemplateLaserSensorsFull_B->Switch4_n;

  /* Update for Memory: '<S4>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_p =
    TemplateLaserSensorsFull_B->Switch4_nk;
}

/* Model initialize function */
void TemplateLaserSensorsFull_initialize(RT_MODEL_TemplateLaserSensorsFull_T *
  const TemplateLaserSensorsFull_M)
{
  DW_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_DW =
    TemplateLaserSensorsFull_M->dwork;
  InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP =
    TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref;

  /* Start for Inport: '<Root>/IMU2' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pn);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pn);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage_p);

  /* Start for Inport: '<Root>/IMU1' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_p);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_p);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage1);

  /* Start for Inport: '<Root>/IMU4' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pna);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pna);

  /* Start for Inport: '<Root>/IMU5' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pnaev);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaev);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage2);

  /* Start for Inport: '<Root>/IMU3' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pnaevv);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaevv);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage2_p);

  /* Start for Inport: '<Root>/IMU6' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage2_pn);

  /* Start for Inport: '<Root>/IMU7' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6_pnae);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7_pnae);

  /* Start for Inport: '<Root>/IMU8' */
  TemplateLaserSensorsFull_MovingAverage6_Start
    (TemplateLaserSensorsFull_InstP->IMU_Filter,
     &TemplateLaserSensorsFull_DW->MovingAverage6);
  TemplateLaserSensorsFull_MovingAverage7_Start
    (TemplateLaserSensorsFull_InstP->IMU_SecondFilter,
     &TemplateLaserSensorsFull_DW->MovingAverage7);
  TemplateLaserSensorsFull_MovingAverage_Start
    (&TemplateLaserSensorsFull_DW->MovingAverage);

  /* InitializeConditions for Memory: '<S1>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput = 0.29943502824858759;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  TemplateLaserSensorsFull_DW->Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  TemplateLaserSensorsFull_DW->Delay1_DSTATE = 0.0;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_g = 0.0;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_j = 0.0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  TemplateLaserSensorsFull_DW->Memory_PreviousInput_p = 0.0;
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pn);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pn);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage_p);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_p);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_p);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage1);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pna);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pna);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaev);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaev);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage2);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaevv);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaevv);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage2_p);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage2_pn);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnae);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnae);
  TemplateLaserSensorsFull_MovingAverage6_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage6);
  TemplateLaserSensorsFull_MovingAverage7_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage7);
  TemplateLaserSensorsFull_MovingAverage_Init
    (&TemplateLaserSensorsFull_DW->MovingAverage);
}

/* Model terminate function */
void TemplateLaserSensorsFull_terminate(RT_MODEL_TemplateLaserSensorsFull_T
  * TemplateLaserSensorsFull_M)
{
  DW_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_DW =
    TemplateLaserSensorsFull_M->dwork;
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pn);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pn);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage_p);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_p);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_p);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage1);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pna);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pna);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaev);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaev);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage2);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaevv);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaevv);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage2_p);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnaevvf);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage2_pn);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6_pnae);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7_pnae);
  TemplateLaserSensorsFull_MovingAverage6_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage6);
  TemplateLaserSensorsFull_MovingAverage7_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage7);
  TemplateLaserSensorsFull_MovingAverage_Term
    (&TemplateLaserSensorsFull_DW->MovingAverage);

  /* model code */
  rt_FREE(TemplateLaserSensorsFull_M->blockIO);
  rt_FREE(TemplateLaserSensorsFull_M->inputs);
  rt_FREE(TemplateLaserSensorsFull_M->outputs);
  rt_FREE(TemplateLaserSensorsFull_M->dwork);

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

  /* block I/O */
  {
    B_TemplateLaserSensorsFull_T *b = (B_TemplateLaserSensorsFull_T *) malloc
      (sizeof(B_TemplateLaserSensorsFull_T));
    rt_VALIDATE_MEMORY(TemplateLaserSensorsFull_M,b);
    TemplateLaserSensorsFull_M->blockIO = (b);
  }

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

  /* states (dwork) */
  {
    DW_TemplateLaserSensorsFull_T *dwork = (DW_TemplateLaserSensorsFull_T *)
      malloc(sizeof(DW_TemplateLaserSensorsFull_T));
    rt_VALIDATE_MEMORY(TemplateLaserSensorsFull_M,dwork);
    TemplateLaserSensorsFull_M->dwork = (dwork);
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
    B_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_B =
      TemplateLaserSensorsFull_M->blockIO;
    DW_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_DW =
      TemplateLaserSensorsFull_M->dwork;
    InstP_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_InstP =
      TemplateLaserSensorsFull_M->TemplateLaserSensorsFull_InstP_ref;
    ExtU_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_U =
      (ExtU_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->inputs;
    ExtY_TemplateLaserSensorsFull_T *TemplateLaserSensorsFull_Y =
      (ExtY_TemplateLaserSensorsFull_T *) TemplateLaserSensorsFull_M->outputs;

    /* block I/O */
    (void) memset(((void *) TemplateLaserSensorsFull_B), 0,
                  sizeof(B_TemplateLaserSensorsFull_T));

    /* states (dwork) */
    (void) memset((void *)TemplateLaserSensorsFull_DW, 0,
                  sizeof(DW_TemplateLaserSensorsFull_T));

    /* external inputs */
    (void)memset(TemplateLaserSensorsFull_U, 0, sizeof
                 (ExtU_TemplateLaserSensorsFull_T));

    /* external outputs */
    (void) memset((void *)TemplateLaserSensorsFull_Y, 0,
                  sizeof(ExtY_TemplateLaserSensorsFull_T));
  }

  return TemplateLaserSensorsFull_M;
}
