CC_SRCS += \
../exercises/exercise.cc ../exercises/basic.cc

OBJS += \
./exercises/exercise.o ./exercises/basic.o

CC_DEPTS += \
./exercises/exercise.d /exercises/basic.d

exercises/%.o: ../exercises/%.cc
	@echo -e 'Building file [$<] : \c'
#	@echo 'Invoking: GCC C++ Compiler'
	@g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo -e '\033[32mOK\033[0m'
#	@echo 'Finished building: $<'
