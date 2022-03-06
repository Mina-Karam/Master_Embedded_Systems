################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/01_GPIO_Test_1_LCD_Keypad.c \
../APP/02_GPIO_Test_2_LEDs_Using_Push_Button.c \
../APP/03_GPIO_Test_3_Keypad_LCD_7_Segment.c \
../APP/04_EXTI_Test_1_LCD_Push_Button.c \
../APP/05_USART_Test_1_Debugging_Using_Polling.c \
../APP/06_USART_Test_2_Debugging_Using_Interrupt.c \
../APP/07_SPI_Debug_Analyze_SPI_Master.c \
../APP/08_SPI_Send_Data_Through_Terminal_Between_2_MCUs.c 

OBJS += \
./APP/01_GPIO_Test_1_LCD_Keypad.o \
./APP/02_GPIO_Test_2_LEDs_Using_Push_Button.o \
./APP/03_GPIO_Test_3_Keypad_LCD_7_Segment.o \
./APP/04_EXTI_Test_1_LCD_Push_Button.o \
./APP/05_USART_Test_1_Debugging_Using_Polling.o \
./APP/06_USART_Test_2_Debugging_Using_Interrupt.o \
./APP/07_SPI_Debug_Analyze_SPI_Master.o \
./APP/08_SPI_Send_Data_Through_Terminal_Between_2_MCUs.o 

C_DEPS += \
./APP/01_GPIO_Test_1_LCD_Keypad.d \
./APP/02_GPIO_Test_2_LEDs_Using_Push_Button.d \
./APP/03_GPIO_Test_3_Keypad_LCD_7_Segment.d \
./APP/04_EXTI_Test_1_LCD_Push_Button.d \
./APP/05_USART_Test_1_Debugging_Using_Polling.d \
./APP/06_USART_Test_2_Debugging_Using_Interrupt.d \
./APP/07_SPI_Debug_Analyze_SPI_Master.d \
./APP/08_SPI_Send_Data_Through_Terminal_Between_2_MCUs.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/My Projects/ARM/STM32F103x6-Driver/APP/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/MCAL/inc" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/Keypad" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/LCD" -I"D:/My Projects/ARM/STM32F103x6-Driver/HAL/S7_Segment" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/01_GPIO_Test_1_LCD_Keypad.d ./APP/01_GPIO_Test_1_LCD_Keypad.o ./APP/02_GPIO_Test_2_LEDs_Using_Push_Button.d ./APP/02_GPIO_Test_2_LEDs_Using_Push_Button.o ./APP/03_GPIO_Test_3_Keypad_LCD_7_Segment.d ./APP/03_GPIO_Test_3_Keypad_LCD_7_Segment.o ./APP/04_EXTI_Test_1_LCD_Push_Button.d ./APP/04_EXTI_Test_1_LCD_Push_Button.o ./APP/05_USART_Test_1_Debugging_Using_Polling.d ./APP/05_USART_Test_1_Debugging_Using_Polling.o ./APP/06_USART_Test_2_Debugging_Using_Interrupt.d ./APP/06_USART_Test_2_Debugging_Using_Interrupt.o ./APP/07_SPI_Debug_Analyze_SPI_Master.d ./APP/07_SPI_Debug_Analyze_SPI_Master.o ./APP/08_SPI_Send_Data_Through_Terminal_Between_2_MCUs.d ./APP/08_SPI_Send_Data_Through_Terminal_Between_2_MCUs.o

.PHONY: clean-APP

