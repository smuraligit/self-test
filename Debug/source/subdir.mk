################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/funtemplate.cpp \
../source/llist.cpp \
../source/refer.cpp \
../source/refer1.cpp \
../source/virtual.cpp 

OBJS += \
./source/funtemplate.o \
./source/llist.o \
./source/refer.o \
./source/refer1.o \
./source/virtual.o 

CPP_DEPS += \
./source/funtemplate.d \
./source/llist.d \
./source/refer.d \
./source/refer1.d \
./source/virtual.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


