################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Class\ Notes.cpp 

OBJS += \
./src/Class\ Notes.o 

CPP_DEPS += \
./src/Class\ Notes.d 


# Each subdirectory must supply rules for building sources it contributes
src/Class\ Notes.o: ../src/Class\ Notes.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Class Notes.d" -MT"src/Class\ Notes.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


