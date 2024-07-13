################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/RELAY/RELAY_prog.c 

OBJS += \
./HALL/RELAY/RELAY_prog.o 

C_DEPS += \
./HALL/RELAY/RELAY_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/RELAY/%.o: ../HALL/RELAY/%.c HALL/RELAY/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


