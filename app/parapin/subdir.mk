################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../parapin/parapin.cc 
OBJS += \
./parapin/parapin.o 

CC_DEPS += \
./parapin/parapin.d 


# Each subdirectory must supply rules for building sources it contributes
parapin/%.o: ../parapin/%.cc
	@echo -e 'Building file [$<] : \c'
#	@echo 'Invoking: GCC C++ Compiler'
	@g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo -e '\033[32mOK\033[0m'
#	@echo 'Finished building: $<'
