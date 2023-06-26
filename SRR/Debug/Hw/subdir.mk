################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hw/NHD_C0220BIZ.c 

OBJS += \
./Hw/NHD_C0220BIZ.o 

C_DEPS += \
./Hw/NHD_C0220BIZ.d 


# Each subdirectory must supply rules for building sources it contributes
Hw/%.o Hw/%.su Hw/%.cyclo: ../Hw/%.c Hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Hw/Potentiometer -I../Hw/I2C_PCF8574_LCD -I../Hw/vl53l1 -I../core -I../platform -I../inc -I../platform/inc -I../core/inc -I../../Core/Inc -I../App -I../Hw -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hw

clean-Hw:
	-$(RM) ./Hw/NHD_C0220BIZ.cyclo ./Hw/NHD_C0220BIZ.d ./Hw/NHD_C0220BIZ.o ./Hw/NHD_C0220BIZ.su

.PHONY: clean-Hw

