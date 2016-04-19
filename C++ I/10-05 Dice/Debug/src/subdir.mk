################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/10-05\ Dice.cpp \
../src/dice.cpp 

OBJS += \
./src/10-05\ Dice.o \
./src/dice.o 

CPP_DEPS += \
./src/10-05\ Dice.d \
./src/dice.d 


# Each subdirectory must supply rules for building sources it contributes
src/10-05\ Dice.o: ../src/10-05\ Dice.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/10-05 Dice.d" -MT"src/10-05\ Dice.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


