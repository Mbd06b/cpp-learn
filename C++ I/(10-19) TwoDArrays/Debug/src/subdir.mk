################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(10-19)\ TwoDArrays.cpp 

OBJS += \
./src/(10-19)\ TwoDArrays.o 

CPP_DEPS += \
./src/(10-19)\ TwoDArrays.d 


# Each subdirectory must supply rules for building sources it contributes
src/(10-19)\ TwoDArrays.o: ../src/(10-19)\ TwoDArrays.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(10-19) TwoDArrays.d" -MT"src/(10-19)\ TwoDArrays.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


