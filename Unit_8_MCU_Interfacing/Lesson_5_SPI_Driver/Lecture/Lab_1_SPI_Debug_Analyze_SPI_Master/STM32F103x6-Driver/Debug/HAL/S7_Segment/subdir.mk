################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/S7_Segment/S7_Segment.c 

OBJS += \
./HAL/S7_Segment/S7_Segment.o 

C_DEPS += \
./HAL/S7_Segment/S7_Segment.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/S7_Segment/%.o: ../HAL/S7_Segment/%.c HAL/S7_Segment/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/My Projects/ARM/STM32F103x6-Driver/APP/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/MCAL/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/Keypad" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/LCD" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/S7_Segment" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-S7_Segment

clean-HAL-2f-S7_Segment:
	-$(RM) ./HAL/S7_Segment/S7_Segment.d ./HAL/S7_Segment/S7_Segment.o

.PHONY: clean-HAL-2f-S7_Segment

