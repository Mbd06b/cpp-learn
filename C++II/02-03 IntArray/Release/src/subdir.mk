################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/02-03\ IntArray.cpp \
../src/IntArray.cpp 

OBJS += \
./src/02-03\ IntArray.o \
./src/IntArray.o 

CPP_DEPS += \
./src/02-03\ IntArray.d \
./src/IntArray.d 


# Each subdirectory must supply rules for building sources it contributes
src/02-03\ IntArray.o: ../src/02-03\ IntArray.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/02-03 IntArray.d" -MT"src/02-03\ IntArray.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


