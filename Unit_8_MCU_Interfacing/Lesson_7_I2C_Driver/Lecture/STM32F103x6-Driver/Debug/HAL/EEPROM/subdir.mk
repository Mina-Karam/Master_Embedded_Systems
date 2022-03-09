################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM/I2C_Slave_EEPROM.c 

OBJS += \
./HAL/EEPROM/I2C_Slave_EEPROM.o 

C_DEPS += \
./HAL/EEPROM/I2C_Slave_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM/%.o: ../HAL/EEPROM/%.c HAL/EEPROM/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/My Projects/ARM/STM32F103x6-Driver/APP/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/EEPROM" -I"D:/My Projects/ARM/STM32F103x6-Driver/MCAL/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/Keypad" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/LCD" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/S7_Segment" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-EEPROM

clean-HAL-2f-EEPROM:
	-$(RM) ./HAL/EEPROM/I2C_Slave_EEPROM.d ./HAL/EEPROM/I2C_Slave_EEPROM.o

.PHONY: clean-HAL-2f-EEPROM

