################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hw/I2C_PCF8574_LCD/i2c-lcd.c 

OBJS += \
./Hw/I2C_PCF8574_LCD/i2c-lcd.o 

C_DEPS += \
./Hw/I2C_PCF8574_LCD/i2c-lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Hw/I2C_PCF8574_LCD/%.o Hw/I2C_PCF8574_LCD/%.su: ../Hw/I2C_PCF8574_LCD/%.c Hw/I2C_PCF8574_LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Hw/I2C_PCF8574_LCD -I../Hw/vl53l1 -I../core -I../platform -I../inc -I../platform/inc -I../core/inc -I../../Core/Inc -I../App -I../Hw -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hw-2f-I2C_PCF8574_LCD

clean-Hw-2f-I2C_PCF8574_LCD:
	-$(RM) ./Hw/I2C_PCF8574_LCD/i2c-lcd.d ./Hw/I2C_PCF8574_LCD/i2c-lcd.o ./Hw/I2C_PCF8574_LCD/i2c-lcd.su

.PHONY: clean-Hw-2f-I2C_PCF8574_LCD

