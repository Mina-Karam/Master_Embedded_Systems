################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/Courses/ES_Online_Diploma_KS/Codes/Master_Embedded_System/Unit_7_MCU_Essential_Peripherals/Lesson_3_GPIO_Part3/Section/STM32F103x6_Driver/HAL/S7_Segment" -I"D:/Courses/ES_Online_Diploma_KS/Codes/Master_Embedded_System/Unit_7_MCU_Essential_Peripherals/Lesson_3_GPIO_Part3/Section/STM32F103x6_Driver/MCAL/GPIO" -I"D:/Courses/ES_Online_Diploma_KS/Codes/Master_Embedded_System/Unit_7_MCU_Essential_Peripherals/Lesson_3_GPIO_Part3/Section/STM32F103x6_Driver/Services" -I"D:/Courses/ES_Online_Diploma_KS/Codes/Master_Embedded_System/Unit_7_MCU_Essential_Peripherals/Lesson_3_GPIO_Part3/Section/STM32F103x6_Driver/HAL/Keypad" -I"D:/Courses/ES_Online_Diploma_KS/Codes/Master_Embedded_System/Unit_7_MCU_Essential_Peripherals/Lesson_3_GPIO_Part3/Section/STM32F103x6_Driver/HAL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o

.PHONY: clean-Src

