################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../main.o 

CC_SRCS += \
../main.cc 

OBJS += \
./main.o 

CC_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo -e 'Building file [$<] : \t\t\t\c'
#	@echo 'Invoking: GCC C++ Compiler'
	@g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo -e '\033[32mOK\033[0m'
#	@echo 'Finished building: $<'
#	@echo ' '


