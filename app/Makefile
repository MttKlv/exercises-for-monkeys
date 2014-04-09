################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init


# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include session/subdir.mk
-include exercises/subdir.mk
-include parapin/subdir.mk
-include objects.mk

RM 		:= rm -rf
CXX 		 = g++
DEFINES 	 = -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CXXFLAGS	 = -g -pipe -Wall -W -D_REENTRANT $(DEFINES)
INCPATH		 = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/X11R6/include -I.
LIBS         	+= -L/usr/lib -L/usr/X11R6/lib -lQtOpenGL -lQtGui -lQtCore -lGLU -lGL -lpthread

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: display

# Tool invocations
display: $(OBJS) $(USER_OBJS)
	@echo -e 'Building target: $@ : \c'
#	@echo 'Invoking: GCC C++ Linker'
	g++  -o" display" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo -e '[\033[32mDone\033[0m]'
#	@echo 'Finished building target: $@'


# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) display
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
