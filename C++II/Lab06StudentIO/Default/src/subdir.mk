################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MainStudentIO.cpp \
../src/Name.cpp \
../src/Student.cpp \
../src/myStringclass.cpp 

OBJS += \
./src/MainStudentIO.o \
./src/Name.o \
./src/Student.o \
./src/myStringclass.o 

CPP_DEPS += \
./src/MainStudentIO.d \
./src/Name.d \
./src/Student.d \
./src/myStringclass.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


