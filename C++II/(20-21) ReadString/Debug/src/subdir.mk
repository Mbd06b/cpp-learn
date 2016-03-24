################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(20-21)\ ReadString.cpp \
../src/ReadString.cpp 

OBJS += \
./src/(20-21)\ ReadString.o \
./src/ReadString.o 

CPP_DEPS += \
./src/(20-21)\ ReadString.d \
./src/ReadString.d 


# Each subdirectory must supply rules for building sources it contributes
src/(20-21)\ ReadString.o: ../src/(20-21)\ ReadString.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(20-21) ReadString.d" -MT"src/(20-21)\ ReadString.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


