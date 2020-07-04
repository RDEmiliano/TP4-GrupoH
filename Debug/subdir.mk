################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Pelicula.cpp \
../main.cpp \
../menu.cpp \
../utilidades.cpp 

OBJS += \
./Pelicula.o \
./main.o \
./menu.o \
./utilidades.o 

CPP_DEPS += \
./Pelicula.d \
./main.d \
./menu.d \
./utilidades.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


