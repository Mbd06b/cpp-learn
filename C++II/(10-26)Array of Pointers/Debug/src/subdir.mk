################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(10-26)Array\ of\ Pointers.cpp 

OBJS += \
./src/(10-26)Array\ of\ Pointers.o 

CPP_DEPS += \
./src/(10-26)Array\ of\ Pointers.d 


# Each subdirectory must supply rules for building sources it contributes
src/(10-26)Array\ of\ Pointers.o: ../src/(10-26)Array\ of\ Pointers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(10-26)Array of Pointers.d" -MT"src/(10-26)Array\ of\ Pointers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


