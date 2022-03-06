################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/stm32f103x6_EXTI_driver.c \
../MCAL/stm32f103x6_GPIO_driver.c \
../MCAL/stm32f103x6_RCC_driver.c \
../MCAL/stm32f103x6_SPI_driver.c \
../MCAL/stm32f103x6_USART_driver.c 

OBJS += \
./MCAL/stm32f103x6_EXTI_driver.o \
./MCAL/stm32f103x6_GPIO_driver.o \
./MCAL/stm32f103x6_RCC_driver.o \
./MCAL/stm32f103x6_SPI_driver.o \
./MCAL/stm32f103x6_USART_driver.o 

C_DEPS += \
./MCAL/stm32f103x6_EXTI_driver.d \
./MCAL/stm32f103x6_GPIO_driver.d \
./MCAL/stm32f103x6_RCC_driver.d \
./MCAL/stm32f103x6_SPI_driver.d \
./MCAL/stm32f103x6_USART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/My Projects/ARM/STM32F103x6-Driver/APP/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/MCAL/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/Keypad" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/LCD" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/S7_Segment" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/stm32f103x6_EXTI_driver.d ./MCAL/stm32f103x6_EXTI_driver.o ./MCAL/stm32f103x6_GPIO_driver.d ./MCAL/stm32f103x6_GPIO_driver.o ./MCAL/stm32f103x6_RCC_driver.d ./MCAL/stm32f103x6_RCC_driver.o ./MCAL/stm32f103x6_SPI_driver.d ./MCAL/stm32f103x6_SPI_driver.o ./MCAL/stm32f103x6_USART_driver.d ./MCAL/stm32f103x6_USART_driver.o

.PHONY: clean-MCAL

