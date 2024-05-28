# Copyright 1994-2013 The MathWorks, Inc.
#
# File    : pmp_gmake.tmf   
#
# Abstract:
#	Template makefile for building a UNIX-based stand-alone generic 
#       real-time version of Simulink model using generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is -O.
#	  CPP_OPTS       - C++ compiler options.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see pmp.tlc
#
#       This file is based on grt_unix.tmf and modified to fit pmp.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "C:\Program Files\MATLAB\R2021a\bin/win64/gmake"
HOST            = ANY
BUILD           = yes
SYS_TARGET_FILE = pmp.tlc
COMPILER_TOOL_CHAIN = linux


#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done
#  PMP_LOCATION        - Path to where PMP is located
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  TGT_FCN_LIB         - Target Funtion library to use
#  MODELREFS           - List of referenced models

MODEL                = PIDcontroller4CoreCentralizedTestReadyMotor
MODULES              = $(subst rt_main.c , ,$(subst rt_malloc_main.c , ,PIDcontroller4CoreCentralizedTestReadyMotor_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c simulink_core.cpp))
MAKEFILE             = PIDcontroller4CoreCentralizedTestReadyMotor.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2021a
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2021a
MATLAB_BIN           = C:\Program Files\MATLAB\R2021a\bin
START_DIR            = C:\Users\ZBOOK1~1\Desktop\DH08VE~1\ITB208~1
S_FUNCTIONS_LIB      = 
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 0
COMPUTER             = PCWIN64
BUILDARGS            =  PMP_TOP_LEVEL_MODEL="PIDcontroller4CoreCentralizedTestReadyMotor" PMP_SAMPLEPERIOD="0.0002500000" PMP_IS_SLAVE="off" INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DRT_MALLOC -DTID01EQ=1"
MULTITASKING         = 0
MAT_FILE             = 0

PMP_LOCATION_S       = C:/PROGRA~1/PRODRI~1/9310~1.C8C/matlab/simulink
PMP_LOCATION         = $(subst \ , ,$(PMP_LOCATION_S))
PMP_LOCATION_D       = $(subst \ ,\\ ,$(PMP_LOCATION_S))
PMP_TOOLCHAIN        = armv8a_64
PMP_XML_FILENAME     = prodrive_simulink_pb.xml
PMP_IS_WINDOWS       = 1
PMP_IS_BUILT_IN      = off
PMP_IS_DEBUG         = off

ifeq "$(PMP_IS_WINDOWS)" "1"
CMD=cmd /C
else
CMD=sh -c
ifneq ($(filter Windows,$(PMP_TOOLCHAIN)),)
WINEDRIVE=z:
endif
endif

MEXEXT               = mexw64
TGT_FCN_LIB          = None
MODELREFS            = 
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 

CODE_INTERFACE_PACKAGING = Reusable function

CLASSIC_INTERFACE    = 0
# Optional for GRT
ALLOCATIONFCN        = 1
ONESTEPFCN           = 0
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 1
START_EXPAND_RULES   = 
END_EXPAND_RULES     = 
END_EXPAND_RULES     = 
MODELLIB             = 

# To enable debugging:
ifeq "$(PMP_IS_DEBUG)" "on"
DEBUG_BUILD         = 1
else
DEBUG_BUILD         = 0
endif


#--------------------------- Model and reference models -----------------------
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
# MODELREF_TARGET_TYPE       = NONE
MODELREF_TARGET_TYPE      = RTW

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

MATLAB_INCLUDE_DIRS  = $(MATLAB_ROOT)/simulink/include $(MATLAB_ROOT)/extern/include $(MATLAB_ROOT)/rtw/c/src

ifneq (,$(findstring R2019,$(MATLAB_ROOT)))
	PHYSMOD_MATH_DIR := pm_math
else
	PHYSMOD_MATH_DIR := sm/math
endif

# Additional file include paths
ADD_INCLUDES = \
	$(START_DIR) \
	$(START_DIR)\PIDcontroller4CoreCentralizedTestReadyMotor_prodrive_rtw \
	$(MATLAB_ROOT)\extern\include \
	$(MATLAB_ROOT)\simulink\include \
	$(MATLAB_ROOT)\rtw\c\src \
	$(MATLAB_ROOT)\toolbox\dsp\include \
	$(MATLAB_ROOT)\toolbox\dsp\extern\src\export\include\src \
	$(MATLAB_ROOT)\toolbox\dsp\extern\src\export\include \
	$(MATLAB_ROOT)\toolbox\shared\dsp\vision\matlab\include \
 $(PMP_LOCATION_S)

#--------------------------- Tool Specifications -------------------------------

ifneq (,$(filter "Windows NT" windows32,$(OS)))
include $(MATLAB_ROOT)/rtw/c/tools/unixtools.mk
endif

#----------------------------- Real-Time Model ---------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------- Additional Libraries ------------------------------

LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------- Include compiler Settings -----------------------------

ifeq "$(PMP_TOOLCHAIN)" "Simulator on Linux"
	include $(PMP_LOCATION_S)/pmp_linux-x86_64.mk
else ifeq "$(PMP_TOOLCHAIN)" "Simulator on Windows 64 bit"
ARCH=64
ifeq "$(PMP_IS_WINDOWS)" "1"
	include $(PMP_LOCATION_S)/pmp_windows-x86.mk
endif
else ifeq "$(PMP_TOOLCHAIN)" "Simulator on Windows 32 bit"
ARCH=32
ifeq "$(PMP_IS_WINDOWS)" "1"
	include $(PMP_LOCATION_S)/pmp_windows-x86.mk
endif
else ifeq "$(PMP_TOOLCHAIN)" "x86_64"
	include $(PMP_LOCATION_S)/pmp_x86_64.mk  
else ifeq "$(PMP_TOOLCHAIN)" "C674x"
	include $(PMP_LOCATION_S)/pmp_c674x.mk
else ifeq "$(PMP_TOOLCHAIN)" "armv8a_64"
	include $(PMP_LOCATION_S)/pmp_armv8a_64.mk
else
$(error Unsupported Platform: $(PMP_TOOLCHAIN))
endif

# Libraries:

ifeq "$(PMP_TOOLCHAIN)" "Simulator on Windows 32 bit"
OBJFILEEXT=obj
else ifeq "$(PMP_TOOLCHAIN)" "Simulator on Windows 64 bit"
OBJFILEEXT=obj
else
OBJFILEEXT=o
endif





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

#--------------------------------- Rules ---------------------------------------
%.o %.obj : $(MATLAB_ROOT)\rtw\c\src/%.c
	$(CC) $(CFLAGS) $(GCC_WALL_FLAG_MAX) -c $(WINEDRIVE)"$<" $(INCLUDES)

%.o %.obj : $(MATLAB_ROOT)\simulink\src/%.c
	$(CC) $(CFLAGS) $(GCC_WALL_FLAG_MAX) -c $(WINEDRIVE)"$<" $(INCLUDES)



%.o %.obj : $(MATLAB_ROOT)\rtw\c\src/%.cpp
	$(CXX) $(CPPFLAGS) -c $(WINEDRIVE)"$<" $(INCLUDES)
%.o %.obj : $(MATLAB_ROOT)\simulink\src/%.cpp
	$(CXX) $(CPPFLAGS) -c $(WINEDRIVE)"$<" $(INCLUDES)


#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo "### Deleting the generated source code for $(MODEL)"
	@$(RM) $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo "### Deleting the objects and $(PRODUCT)"
	@$(RM) $(LINK_OBJS) $(PRODUCT)

lint  : rtwlib.ln
	@lint -errchk -errhdr=%user -errtags=yes -F -L. -lrtwlib -x -Xc \
	      -erroff=$(LINT_ERROFF) \
	      -D_POSIX_C_SOURCE $(CFLAGS) $(LINT_SRCS)
	@\rm -f $(LINTOPTSFILE)
	@echo
	@echo "### Created lint output only, no executable"
	@echo

rtwlib.ln : $(MAKEFILE) rtw_proj.tmw
	@echo
	@echo "### Linting ..."
	@echo
	@rm -f llib-lrtwlib.ln $(LINTOPTSFILE)
	@echo "-dirout=. -errchk -errhdr=%user " >> $(LINTOPTSFILE)
	@echo "-errtags -F -ortwlib -x -Xc " >> $(LINTOPTSFILE)
	@echo "-erroff=$(LINT_ERROFF) " >> $(LINTOPTSFILE)
	@echo "-D_POSIX_C_SOURCE $(CFLAGS) " >> $(LINTOPTSFILE)
	@for file in $(MATLAB_ROOT)/rtw/c/libsrc/*.c; do \
	  echo "$$file " >> $(LINTOPTSFILE); \
	done
	lint -flagsrc=$(LINTOPTSFILE)

# EOF: prodrive_unix.tmf
