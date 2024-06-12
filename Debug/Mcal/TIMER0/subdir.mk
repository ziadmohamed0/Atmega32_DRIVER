################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/TIMER0/TIMER0_Prog.c 

OBJS += \
./Mcal/TIMER0/TIMER0_Prog.o 

C_DEPS += \
./Mcal/TIMER0/TIMER0_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/TIMER0/%.o: ../Mcal/TIMER0/%.c Mcal/TIMER0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


