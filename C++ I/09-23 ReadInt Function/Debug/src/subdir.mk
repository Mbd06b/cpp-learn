################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/09-23\ ReadInt\ Function.cpp \
../src/ReadInt.cpp 

OBJS += \
./src/09-23\ ReadInt\ Function.o \
./src/ReadInt.o 

CPP_DEPS += \
./src/09-23\ ReadInt\ Function.d \
./src/ReadInt.d 


# Each subdirectory must supply rules for building sources it contributes
src/09-23\ ReadInt\ Function.o: ../src/09-23\ ReadInt\ Function.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/09-23 ReadInt Function.d" -MT"src/09-23\ ReadInt\ Function.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


