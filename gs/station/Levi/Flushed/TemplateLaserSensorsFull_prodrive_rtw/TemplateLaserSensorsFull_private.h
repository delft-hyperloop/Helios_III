/*
 * TemplateLaserSensorsFull_private.h
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

#ifndef RTW_HEADER_TemplateLaserSensorsFull_private_h_
#define RTW_HEADER_TemplateLaserSensorsFull_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "TemplateLaserSensorsFull.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 rtmSetErrorStatus(TemplateLaserSensorsFull_M, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

void TemplateLaserSensorsFull_MovingAverage_Init
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage_Start
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage(real_T rtu_0,
  B_MovingAverage_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage6_Init
  (DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage6_Start(real_T rtp_IMU_Filter,
  DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage6(real_T rtu_0, real_T rtp_IMU_Filter,
  B_MovingAverage6_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage7_Init
  (DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage7_Start(real_T rtp_IMU_SecondFilter,
  DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage7(real_T rtu_0, real_T
  rtp_IMU_SecondFilter, B_MovingAverage7_TemplateLaserSensorsFull_T *localB,
  DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage_Term
  (DW_MovingAverage_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage6_Term
  (DW_MovingAverage6_TemplateLaserSensorsFull_T *localDW);
void TemplateLaserSensorsFull_MovingAverage7_Term
  (DW_MovingAverage7_TemplateLaserSensorsFull_T *localDW);

#endif                      /* RTW_HEADER_TemplateLaserSensorsFull_private_h_ */
