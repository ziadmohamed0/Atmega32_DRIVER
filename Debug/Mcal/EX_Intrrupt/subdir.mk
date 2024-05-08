################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/EX_Intrrupt/EX_Prog.c 

OBJS += \
./Mcal/EX_Intrrupt/EX_Prog.o 

C_DEPS += \
./Mcal/EX_Intrrupt/EX_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/EX_Intrrupt/%.o: ../Mcal/EX_Intrrupt/%.c Mcal/EX_Intrrupt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


