################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(10-28)\ Structures\ (Cards).cpp \
../src/Card.cpp 

OBJS += \
./src/(10-28)\ Structures\ (Cards).o \
./src/Card.o 

CPP_DEPS += \
./src/(10-28)\ Structures\ (Cards).d \
./src/Card.d 


# Each subdirectory must supply rules for building sources it contributes
src/(10-28)\ Structures\ (Cards).o: ../src/(10-28)\ Structures\ (Cards).cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(10-28) Structures (Cards).d" -MT"src/(10-28)\ Structures\ (Cards).d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


