################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/LCD/LCD_Config.c \
../HALL/LCD/LCD_Prog.c 

OBJS += \
./HALL/LCD/LCD_Config.o \
./HALL/LCD/LCD_Prog.o 

C_DEPS += \
./HALL/LCD/LCD_Config.d \
./HALL/LCD/LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/LCD/%.o: ../HALL/LCD/%.c HALL/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


