################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(10-26)BinarySearch.cpp \
../src/BinarySFunc.cpp 

OBJS += \
./src/(10-26)BinarySearch.o \
./src/BinarySFunc.o 

CPP_DEPS += \
./src/(10-26)BinarySearch.d \
./src/BinarySFunc.d 


# Each subdirectory must supply rules for building sources it contributes
src/(10-26)BinarySearch.o: ../src/(10-26)BinarySearch.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(10-26)BinarySearch.d" -MT"src/(10-26)BinarySearch.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


