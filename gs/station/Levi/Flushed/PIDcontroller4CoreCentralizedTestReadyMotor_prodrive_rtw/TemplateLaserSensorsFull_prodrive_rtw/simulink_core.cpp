#include <cstring>
#include <stdio.h>
#include <string>

// Prodrive Motion Platform Simulink includes
#include "dynamiclibrary_create.h"
#include "stdlib_proxy.h"
#include "dynamiclibrary_callbacks.h"
#include "simulink_library.h"
#include "dynamiclibrary_simulink.h"

extern "C" {

#include "events.h"
#include "TemplateLaserSensorsFull.h"
#include "TemplateLaserSensorsFull_types.h"
#include "TemplateLaserSensorsFull_private.h"

}
// The std_proxy does not work for:
// - Windows simulator (dll)
// - HW (statically linked)
// To overcome the leaks for memory allocated in this file, the memory allocation functions are directly mapped on the callback functions
// Allocations are typically done in this file
// Memory allocated in other files generated by simulink still suffer on these platforms from leaks
#define free(arg)                      PmpInternal::DynamicLibrary::libCallbacks.free(PmpInternal::DynamicLibrary::libCallbacks.handle, arg)
#define malloc(size)                   PmpInternal::DynamicLibrary::libCallbacks.malloc(PmpInternal::DynamicLibrary::libCallbacks.handle, size)
#define calloc(nmemb, size)            PmpInternal::DynamicLibrary::libCallbacks.calloc(PmpInternal::DynamicLibrary::libCallbacks.handle, nmemb, size)
#define realloc(ptr, size)             PmpInternal::DynamicLibrary::libCallbacks.realloc(PmpInternal::DynamicLibrary::libCallbacks.handle, ptr, size)

namespace PmpInternal
{
  namespace DynamicLibrary
  {
    static void ClearDWork(void* ptr, int value, size_t num);
    struct SNamedSignalInfo
    {
      const char * Name;
      PmpInternal::DynamicLibrary::SSignalInfo Info;
    };

    struct SNamedEventInfo
    {
      const char * Name;
      PmpInternal::DynamicLibrary::SEventInfo Info;
    };

    struct CSimulinkCoreTemplateLaserSensorsFull: public PmpInternal::
      DynamicLibrary::ISimulink
    {
      SEventSet events;
      void * modelData;
      CSimulinkCoreTemplateLaserSensorsFull(void * modelData);
      void * operator new(size_t size)
      {
        return malloc(size);
      }

      void operator delete(void * p)
      {
        free(p);
      }
    };

    static void CSimulinkCoreTemplateLaserSensorsFull_SetInputsDataAddress
      (PmpInternal::DynamicLibrary::ISimulink* intf, void* address)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull* >(intf);
      rtmSetU((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData,
              (ExtU_TemplateLaserSensorsFull_T*) address);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetOutputsDataAddress
      (PmpInternal::DynamicLibrary::ISimulink* intf, void* address)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      rtmSetY((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData,
              (ExtY_TemplateLaserSensorsFull_T*) address);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetTestpointsDataAddress
      (PmpInternal::DynamicLibrary::ISimulink* intf, void* address)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      rtmSetBlockIO((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData,
                    (B_TemplateLaserSensorsFull_T*) address);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetUpdatableDataAddress
      (PmpInternal::DynamicLibrary::ISimulink*, const char*, void*)
    {
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetModelUpdatableDefaults
      (PmpInternal::DynamicLibrary::ISimulink*, void*)
    {
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetParametersDataAddress
      (PmpInternal::DynamicLibrary::ISimulink* intf, void* address)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      rtmSetTemplateLaserSensorsFull_InstP_ref
        ((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData,
         (InstP_TemplateLaserSensorsFull_T*) address);

      // Copy in default parameter data
      (void) memcpy(rtmGetTemplateLaserSensorsFull_InstP_ref
                    ((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData),
                    &TemplateLaserSensorsFull_InstP, sizeof
                    (InstP_TemplateLaserSensorsFull_T));
      CSimulinkCoreTemplateLaserSensorsFull_SetModelUpdatableDefaults(self,
        self->modelData);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetEventsDataAddress
      (PmpInternal::DynamicLibrary::ISimulink*, void*)
    {
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetStateDataSize
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return sizeof(DW_TemplateLaserSensorsFull_T);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_SetStateDataAddress
      (PmpInternal::DynamicLibrary::ISimulink* intf, void* address)
    {
      memset(address, 0, CSimulinkCoreTemplateLaserSensorsFull_GetStateDataSize
             (intf));
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      rtmSetRootDWork((RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData,
                      (DW_TemplateLaserSensorsFull_T*) address);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_Init(PmpInternal::
      DynamicLibrary::ISimulink* intf, void* handle)
    {
      PmpInternal::DynamicLibrary::libCallbacks.handle = handle;
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      RT_MODEL_TemplateLaserSensorsFull_T* TemplateLaserSensorsFull_M =
        (RT_MODEL_TemplateLaserSensorsFull_T*) self->modelData;
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
      (void) ClearDWork((void *)TemplateLaserSensorsFull_DW, 0,
                        sizeof(DW_TemplateLaserSensorsFull_T));

      /* external inputs */
      (void)memset(TemplateLaserSensorsFull_U, 0, sizeof
                   (ExtU_TemplateLaserSensorsFull_T));

      /* external outputs */
      (void) memset((void *)TemplateLaserSensorsFull_Y, 0,
                    sizeof(ExtY_TemplateLaserSensorsFull_T));
      TemplateLaserSensorsFull_initialize((RT_MODEL_TemplateLaserSensorsFull_T*)
        self->modelData);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_Output(PmpInternal::
      DynamicLibrary::ISimulink* intf)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      TemplateLaserSensorsFull_output((RT_MODEL_TemplateLaserSensorsFull_T*)
        self->modelData);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_Update(PmpInternal::
      DynamicLibrary::ISimulink* intf)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      TemplateLaserSensorsFull_update((RT_MODEL_TemplateLaserSensorsFull_T*)
        self->modelData);
    }

    static void CSimulinkCoreTemplateLaserSensorsFull_Terminate(PmpInternal::
      DynamicLibrary::ISimulink* intf)
    {
      CSimulinkCoreTemplateLaserSensorsFull* self =
        static_cast<CSimulinkCoreTemplateLaserSensorsFull*>(intf);
      free(self->modelData);
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetInputsDataSize
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return sizeof(ExtU_TemplateLaserSensorsFull_T);
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetOutputsDataSize
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return sizeof(ExtY_TemplateLaserSensorsFull_T);
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetTestpointsDataSize
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return sizeof(B_TemplateLaserSensorsFull_T);
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetParametersDataSize
      (PmpInternal::DynamicLibrary::ISimulink* )
    {
      return sizeof(InstP_TemplateLaserSensorsFull_T);
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetUpdatableDataSize
      (PmpInternal::DynamicLibrary::ISimulink*, const char*)
    {
      return 0;
    }

    static uint32_t CSimulinkCoreTemplateLaserSensorsFull_GetEventsDataSize
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return 0;
    }

    static const SNamedSignalInfo inputOffsets[20] = {
      { "Voltage_A", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_A), EDataTypeDouble } },

      { "Voltage_B", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_B), EDataTypeDouble } },

      { "Voltage_C", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_C), EDataTypeDouble } },

      { "Voltage_D", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_D), EDataTypeDouble } },

      { "Voltage_A2", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_A2), EDataTypeDouble } },

      { "Voltage_B2", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_B2), EDataTypeDouble } },

      { "Voltage_C2", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_C2), EDataTypeDouble } },

      { "Voltage_D2", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Voltage_D2), EDataTypeDouble } },

      { "VerticalAxisControllerState_In", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, VerticalAxisControllerState_In),
          EDataTypeDouble } },

      { "LateralAxisControllerState_In", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, LateralAxisControllerState_In),
          EDataTypeDouble } },

      { "IMU1", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU1), EDataTypeDouble } },

      { "IMU2", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU2), EDataTypeDouble } },

      { "IMU3", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU3), EDataTypeDouble } },

      { "IMU4", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU4), EDataTypeDouble } },

      { "IMU5", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU5), EDataTypeDouble } },

      { "IMU6", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU6), EDataTypeDouble } },

      { "IMU7", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU7), EDataTypeDouble } },

      { "IMU8", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, IMU8), EDataTypeDouble } },

      { "Pitch", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Pitch), EDataTypeDouble } },

      { "Roll", { ESimulinkStructsInput, offsetof
          (ExtU_TemplateLaserSensorsFull_T, Roll), EDataTypeDouble } },
    };

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetInputInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char* name, SSignalInfo&
       info)
    {
      for (unsigned int i = 0; i < 20; ++i) {
        if (strcmp(name, inputOffsets[i].Name) == 0) {
          info = inputOffsets[i].Info;
          return EResultOk;
        }
      }

      return EResultNonExistant;
    }

    static const SNamedSignalInfo outputOffsets[28] = {
      { "G_A", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_A), EDataTypeDouble } },

      { "G_B", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_B), EDataTypeDouble } },

      { "G_C", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_C), EDataTypeDouble } },

      { "G_D", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_D), EDataTypeDouble } },

      { "G_A2", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_A2), EDataTypeDouble } },

      { "G_B2", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_B2), EDataTypeDouble } },

      { "G_C2", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_C2), EDataTypeDouble } },

      { "G_D2", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, G_D2), EDataTypeDouble } },

      { "VerticalAxisControllerState_Out", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, VerticalAxisControllerState_Out),
          EDataTypeDouble } },

      { "LateralAxisControllerState_Out", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, LateralAxisControllerState_Out),
          EDataTypeDouble } },

      { "IMU_x", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_x), EDataTypeDouble } },

      { "IMU_y", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_y), EDataTypeDouble } },

      { "IMU_pitch", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_pitch), EDataTypeDouble } },

      { "IMU_z", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_z), EDataTypeDouble } },

      { "IMU_roll", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_roll), EDataTypeDouble } },

      { "IMU_yaw", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_yaw), EDataTypeDouble } },

      { "IMU_temp", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_temp), EDataTypeDouble } },

      { "IMU_out8", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IMU_out8), EDataTypeDouble } },

      { "Vx", { ESimulinkStructsOutput, offsetof(ExtY_TemplateLaserSensorsFull_T,
          Vx), EDataTypeDouble } },

      { "Vz", { ESimulinkStructsOutput, offsetof(ExtY_TemplateLaserSensorsFull_T,
          Vz), EDataTypeDouble } },

      { "Vy", { ESimulinkStructsOutput, offsetof(ExtY_TemplateLaserSensorsFull_T,
          Vy), EDataTypeDouble } },

      { "IOval_to_mV", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, IOval_to_mV), EDataTypeDouble } },

      { "com_spd_x", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_spd_x), EDataTypeDouble } },

      { "com_spd_y", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_spd_y), EDataTypeDouble } },

      { "com_spd_z", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_spd_z), EDataTypeDouble } },

      { "com_acc_x", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_acc_x), EDataTypeDouble } },

      { "com_acc_y", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_acc_y), EDataTypeDouble } },

      { "com_acc_z", { ESimulinkStructsOutput, offsetof
          (ExtY_TemplateLaserSensorsFull_T, com_acc_z), EDataTypeDouble } },
    };

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetOutputInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char* name, SSignalInfo&
       info)
    {
      for (unsigned int i = 0; i < 28; ++i) {
        if (strcmp(name, outputOffsets[i].Name) == 0) {
          info = outputOffsets[i].Info;
          return EResultOk;
        }
      }

      return EResultNonExistant;
    }

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetTestpointInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char*, SSignalInfo&)
    {
      return EResultNonExistant;
    }

    static const SNamedSignalInfo parameterOffsets[26] = {
      { "CalibrateIMU", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, CalibrateIMU), EDataTypeDouble } },

      { "IMU_Filter", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, IMU_Filter), EDataTypeDouble } },

      { "IMU_SecondFilter", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, IMU_SecondFilter), EDataTypeDouble
        } },

      { "a_A", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_A), EDataTypeDouble } },

      { "a_A2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_A2), EDataTypeDouble } },

      { "a_B", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_B), EDataTypeDouble } },

      { "a_B2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_B2), EDataTypeDouble } },

      { "a_C", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_C), EDataTypeDouble } },

      { "a_C2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_C2), EDataTypeDouble } },

      { "a_D", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_D), EDataTypeDouble } },

      { "a_D2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, a_D2), EDataTypeDouble } },

      { "b_A", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_A), EDataTypeDouble } },

      { "b_A2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_A2), EDataTypeDouble } },

      { "b_B", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_B), EDataTypeDouble } },

      { "b_B2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_B2), EDataTypeDouble } },

      { "b_C", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_C), EDataTypeDouble } },

      { "b_C2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_C2), EDataTypeDouble } },

      { "b_D", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_D), EDataTypeDouble } },

      { "b_D2", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, b_D2), EDataTypeDouble } },

      { "kalman_pitchdot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_pitchdot_gain),
          EDataTypeDouble } },

      { "kalman_rolldot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_rolldot_gain),
          EDataTypeDouble } },

      { "kalman_xdotdot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_xdotdot_gain),
          EDataTypeDouble } },

      { "kalman_yawdot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_yawdot_gain),
          EDataTypeDouble } },

      { "kalman_ydotdot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_ydotdot_gain),
          EDataTypeDouble } },

      { "kalman_zdotdot_gain", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, kalman_zdotdot_gain),
          EDataTypeDouble } },

      { "remove_IMU_bias_g", { ESimulinkStructsParameter, offsetof
          (InstP_TemplateLaserSensorsFull_T, remove_IMU_bias_g), EDataTypeDouble
        } },
    };

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetParameterInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char* name, SSignalInfo&
       info)
    {
      for (unsigned int i = 0; i < 26; ++i) {
        if (strcmp(name, parameterOffsets[i].Name) == 0) {
          info = parameterOffsets[i].Info;
          return EResultOk;
        }
      }

      return EResultNonExistant;
    }

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetUpdatableInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char*, SUpdatableInfo&)
    {
      return EResultNonExistant;
    }

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetEventInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char*, SEventInfo&)
    {
      return EResultNonExistant;
    }

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetStateInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const char*, SSignalInfo&)
    {
      return EResultNonExistant;
    }

    struct OffsetAdmin
    {
      uint32_t Offset;
      uint32_t Size;
    };

    static void ClearDWork(void* ptr, int value, size_t num)
    {
      memset(ptr, value, num);
    }

    static double CSimulinkCoreTemplateLaserSensorsFull_GetSamplePeriod
      (PmpInternal::DynamicLibrary::ISimulink*)
    {
      return 0.00025;
    }

    static const SReflectionInfo reflectionInfo[75] = {
      { "Voltage_A", ESimulinkStructsInput },

      { "Voltage_B", ESimulinkStructsInput },

      { "Voltage_C", ESimulinkStructsInput },

      { "Voltage_D", ESimulinkStructsInput },

      { "Voltage_A2", ESimulinkStructsInput },

      { "Voltage_B2", ESimulinkStructsInput },

      { "Voltage_C2", ESimulinkStructsInput },

      { "Voltage_D2", ESimulinkStructsInput },

      { "VerticalAxisControllerState_In", ESimulinkStructsInput },

      { "LateralAxisControllerState_In", ESimulinkStructsInput },

      { "IMU1", ESimulinkStructsInput },

      { "IMU2", ESimulinkStructsInput },

      { "IMU3", ESimulinkStructsInput },

      { "IMU4", ESimulinkStructsInput },

      { "IMU5", ESimulinkStructsInput },

      { "IMU6", ESimulinkStructsInput },

      { "IMU7", ESimulinkStructsInput },

      { "IMU8", ESimulinkStructsInput },

      { "Pitch", ESimulinkStructsInput },

      { "Roll", ESimulinkStructsInput },

      { "G_A", ESimulinkStructsOutput },

      { "G_B", ESimulinkStructsOutput },

      { "G_C", ESimulinkStructsOutput },

      { "G_D", ESimulinkStructsOutput },

      { "G_A2", ESimulinkStructsOutput },

      { "G_B2", ESimulinkStructsOutput },

      { "G_C2", ESimulinkStructsOutput },

      { "G_D2", ESimulinkStructsOutput },

      { "VerticalAxisControllerState_Out", ESimulinkStructsOutput },

      { "LateralAxisControllerState_Out", ESimulinkStructsOutput },

      { "IMU_x", ESimulinkStructsOutput },

      { "IMU_y", ESimulinkStructsOutput },

      { "IMU_pitch", ESimulinkStructsOutput },

      { "IMU_z", ESimulinkStructsOutput },

      { "IMU_roll", ESimulinkStructsOutput },

      { "IMU_yaw", ESimulinkStructsOutput },

      { "IMU_temp", ESimulinkStructsOutput },

      { "IMU_out8", ESimulinkStructsOutput },

      { "Vx", ESimulinkStructsOutput },

      { "Vz", ESimulinkStructsOutput },

      { "Vy", ESimulinkStructsOutput },

      { "IOval_to_mV", ESimulinkStructsOutput },

      { "com_spd_x", ESimulinkStructsOutput },

      { "com_spd_y", ESimulinkStructsOutput },

      { "com_spd_z", ESimulinkStructsOutput },

      { "com_acc_x", ESimulinkStructsOutput },

      { "com_acc_y", ESimulinkStructsOutput },

      { "com_acc_z", ESimulinkStructsOutput },

      { "CalibrateIMU", ESimulinkStructsParameter },

      { "IMU_Filter", ESimulinkStructsParameter },

      { "IMU_SecondFilter", ESimulinkStructsParameter },

      { "a_A", ESimulinkStructsParameter },

      { "a_A2", ESimulinkStructsParameter },

      { "a_B", ESimulinkStructsParameter },

      { "a_B2", ESimulinkStructsParameter },

      { "a_C", ESimulinkStructsParameter },

      { "a_C2", ESimulinkStructsParameter },

      { "a_D", ESimulinkStructsParameter },

      { "a_D2", ESimulinkStructsParameter },

      { "b_A", ESimulinkStructsParameter },

      { "b_A2", ESimulinkStructsParameter },

      { "b_B", ESimulinkStructsParameter },

      { "b_B2", ESimulinkStructsParameter },

      { "b_C", ESimulinkStructsParameter },

      { "b_C2", ESimulinkStructsParameter },

      { "b_D", ESimulinkStructsParameter },

      { "b_D2", ESimulinkStructsParameter },

      { "kalman_pitchdot_gain", ESimulinkStructsParameter },

      { "kalman_rolldot_gain", ESimulinkStructsParameter },

      { "kalman_xdotdot_gain", ESimulinkStructsParameter },

      { "kalman_yawdot_gain", ESimulinkStructsParameter },

      { "kalman_ydotdot_gain", ESimulinkStructsParameter },

      { "kalman_zdotdot_gain", ESimulinkStructsParameter },

      { "remove_IMU_bias_g", ESimulinkStructsParameter },

      // end with invalid entry as last
      { "", ESimulinkStructsInvalid },
    };

    static EResult CSimulinkCoreTemplateLaserSensorsFull_GetReflectionInfo
      (PmpInternal::DynamicLibrary::ISimulink*, const SReflectionInfo*& info)
    {
      info = reflectionInfo;
      return EResultOk;
    }

    static struct PmpInternal::DynamicLibrary::ISimulinkVTable
      ISimulinkTemplateLaserSensorsFull = {
      CSimulinkCoreTemplateLaserSensorsFull_GetInputsDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetOutputsDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetTestpointsDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetParametersDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetUpdatableDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetEventsDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_GetStateDataSize,
      CSimulinkCoreTemplateLaserSensorsFull_SetInputsDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetOutputsDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetTestpointsDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetParametersDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetUpdatableDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetEventsDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_SetStateDataAddress,
      CSimulinkCoreTemplateLaserSensorsFull_GetInputInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetOutputInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetTestpointInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetParameterInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetUpdatableInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetEventInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetStateInfo,
      CSimulinkCoreTemplateLaserSensorsFull_GetSamplePeriod,
      CSimulinkCoreTemplateLaserSensorsFull_Init,
                // PreInit is not known for simulink. Full init is done instead.
      CSimulinkCoreTemplateLaserSensorsFull_Init,
      CSimulinkCoreTemplateLaserSensorsFull_Update,
      CSimulinkCoreTemplateLaserSensorsFull_Output,
      CSimulinkCoreTemplateLaserSensorsFull_Terminate,
      CSimulinkCoreTemplateLaserSensorsFull_GetReflectionInfo
    };

    CSimulinkCoreTemplateLaserSensorsFull::CSimulinkCoreTemplateLaserSensorsFull
      (void * modelData)
      : modelData(modelData)
    {
      vtable = &ISimulinkTemplateLaserSensorsFull;
      memset(&events, 0, sizeof(events));
    }

    static ISimulink * createCoreTemplateLaserSensorsFull()
    {
      RT_MODEL_TemplateLaserSensorsFull_T * TemplateLaserSensorsFull_M =
        (RT_MODEL_TemplateLaserSensorsFull_T*) malloc(sizeof
        (RT_MODEL_TemplateLaserSensorsFull_T));
      if (TemplateLaserSensorsFull_M == NULL) {
        return NULL;
      }

      (void) memset((char*) TemplateLaserSensorsFull_M, 0, sizeof
                    (RT_MODEL_TemplateLaserSensorsFull_T));
      return new CSimulinkCoreTemplateLaserSensorsFull((void*)
        TemplateLaserSensorsFull_M);
    }

    PmpInternal::DynamicLibrary::ISimulink *
      InternalCreateTemplateLaserSensorsFull(PmpInternal::DynamicLibrary::
      PmpCallbacks * callbacks)
    {
      if (callbacks) {
        // Assignment of large structs is by some compilers translated to memcpy. However, that function is not yet available. So instead use the memcpy in the callback
        callbacks->memcpy(&PmpInternal::DynamicLibrary::libCallbacks, callbacks,
                          sizeof(PmpInternal::DynamicLibrary::libCallbacks));
        uintptr_t * startAddr = (uintptr_t*) callbacks;
        for (uint32_t i = 0; i < sizeof(PmpInternal::DynamicLibrary::
              libCallbacks) / sizeof(uintptr_t*); ++i) {
          if (startAddr == NULL) {
            callbacks->fatalError("Missing function");
          }

          ++startAddr;
        }
      } else {
        memset(&PmpInternal::DynamicLibrary::libCallbacks, 0, sizeof(PmpInternal::
                DynamicLibrary::libCallbacks));
      }

      return createCoreTemplateLaserSensorsFull();
    }
  }                                    // Namespace: DynamicLibrary
}                                      // Namespace: PmpInternal

// For built in blocks these do not have to be external symbols on the dll
#ifndef BUILT_IN_BLOCK

PMP_DLL_ATTR
  uint32_t GetVersion()
{
  return PmpInternal::DynamicLibrary::major_version;
}

PMP_DLL_ATTR
  void GetIntfVersion(uint32_t* major, uint32_t* minor)
{
  *major = PmpInternal::DynamicLibrary::major_version;
  *minor = PmpInternal::DynamicLibrary::minor_version;
}

PMP_DLL_ATTR
  PmpInternal::DynamicLibrary::ISimulink * Create(PmpInternal::DynamicLibrary::
  PmpCallbacks * callbacks)
{
  return PmpInternal::DynamicLibrary::InternalCreateTemplateLaserSensorsFull
    (callbacks);
}

#else

// registrar is only used in combination with builtin blocks.
#ifdef USE_REGISTRAR
#include "simulink_registrar.h"

class StaticInit
{
 public:
  StaticInit()
  {
    SimulinkRegistrar_Add("TemplateLaserSensorsFull", &PmpInternal::
                          DynamicLibrary::InternalCreateTemplateLaserSensorsFull);
  }
};

static StaticInit staticInit;

#else

extern "C" VISIBLE PmpInternal::DynamicLibrary::ISimulink *
  CreateSimulinkTemplateLaserSensorsFull(PmpInternal::DynamicLibrary::
  PmpCallbacks * callbacks)
{
  return PmpInternal::DynamicLibrary::InternalCreateTemplateLaserSensorsFull
    (callbacks);
}

#endif
#endif