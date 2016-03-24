################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/(11-09)\ AirProject.cpp \
../src/Commands.cpp \
../src/Planes.cpp \
../src/ReadInt.cpp \
../src/ReadString.cpp 

OBJS += \
./src/(11-09)\ AirProject.o \
./src/Commands.o \
./src/Planes.o \
./src/ReadInt.o \
./src/ReadString.o 

CPP_DEPS += \
./src/(11-09)\ AirProject.d \
./src/Commands.d \
./src/Planes.d \
./src/ReadInt.d \
./src/ReadString.d 


# Each subdirectory must supply rules for building sources it contributes
src/(11-09)\ AirProject.o: ../src/(11-09)\ AirProject.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/(11-09) AirProject.d" -MT"src/(11-09)\ AirProject.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


