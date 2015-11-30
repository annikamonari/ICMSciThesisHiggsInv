################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/data_chain.cpp \
../src/histo_plot.cpp \
../src/main.cpp \
../src/tree_leaves.cpp \
../src/variable.cpp \
../src/variables.cpp 

OBJS += \
./src/data_chain.o \
./src/histo_plot.o \
./src/main.o \
./src/tree_leaves.o \
./src/variable.o \
./src/variables.o 

CPP_DEPS += \
./src/data_chain.d \
./src/histo_plot.d \
./src/main.d \
./src/tree_leaves.d \
./src/variable.d \
./src/variables.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Applications/root_v5.34.34/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


