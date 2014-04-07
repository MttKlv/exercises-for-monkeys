################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../session/session.cc ../session/parser.cc  ../session/recorder.cc
OBJS += \
./session/session.o ./session/parser.o ./session/recorder.o

CC_DEPS += \
./session/session.d ./session/parser.d .session/recorder.d


# Each subdirectory must supply rules for building sources it contributes
session/%.o: ../session/%.cc
	@echo -e 'Building file [$<] : \c'
#	@echo 'Invoking: GCC C++ Compiler'
	@g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo -e '\033[32mOK\033[0m'
#	@echo 'Finished building: $<'
