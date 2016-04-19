################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/9-28\ Functions\ and\ Parameters.cpp \
../src/ArrayFunctions.cpp \
../src/Functions.cpp 

OBJS += \
./src/9-28\ Functions\ and\ Parameters.o \
./src/ArrayFunctions.o \
./src/Functions.o 

CPP_DEPS += \
./src/9-28\ Functions\ and\ Parameters.d \
./src/ArrayFunctions.d \
./src/Functions.d 


# Each subdirectory must supply rules for building sources it contributes
src/9-28\ Functions\ and\ Parameters.o: ../src/9-28\ Functions\ and\ Parameters.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/9-28 Functions and Parameters.d" -MT"src/9-28\ Functions\ and\ Parameters.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


