################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hw/vl53l1/vl53l1_api.c \
../Hw/vl53l1/vl53l1_api_calibration.c \
../Hw/vl53l1/vl53l1_api_core.c \
../Hw/vl53l1/vl53l1_api_debug.c \
../Hw/vl53l1/vl53l1_api_preset_modes.c \
../Hw/vl53l1/vl53l1_api_strings.c \
../Hw/vl53l1/vl53l1_core.c \
../Hw/vl53l1/vl53l1_core_support.c \
../Hw/vl53l1/vl53l1_error_strings.c \
../Hw/vl53l1/vl53l1_platform.c \
../Hw/vl53l1/vl53l1_register_funcs.c \
../Hw/vl53l1/vl53l1_sensor.c \
../Hw/vl53l1/vl53l1_silicon_core.c \
../Hw/vl53l1/vl53l1_wait.c 

OBJS += \
./Hw/vl53l1/vl53l1_api.o \
./Hw/vl53l1/vl53l1_api_calibration.o \
./Hw/vl53l1/vl53l1_api_core.o \
./Hw/vl53l1/vl53l1_api_debug.o \
./Hw/vl53l1/vl53l1_api_preset_modes.o \
./Hw/vl53l1/vl53l1_api_strings.o \
./Hw/vl53l1/vl53l1_core.o \
./Hw/vl53l1/vl53l1_core_support.o \
./Hw/vl53l1/vl53l1_error_strings.o \
./Hw/vl53l1/vl53l1_platform.o \
./Hw/vl53l1/vl53l1_register_funcs.o \
./Hw/vl53l1/vl53l1_sensor.o \
./Hw/vl53l1/vl53l1_silicon_core.o \
./Hw/vl53l1/vl53l1_wait.o 

C_DEPS += \
./Hw/vl53l1/vl53l1_api.d \
./Hw/vl53l1/vl53l1_api_calibration.d \
./Hw/vl53l1/vl53l1_api_core.d \
./Hw/vl53l1/vl53l1_api_debug.d \
./Hw/vl53l1/vl53l1_api_preset_modes.d \
./Hw/vl53l1/vl53l1_api_strings.d \
./Hw/vl53l1/vl53l1_core.d \
./Hw/vl53l1/vl53l1_core_support.d \
./Hw/vl53l1/vl53l1_error_strings.d \
./Hw/vl53l1/vl53l1_platform.d \
./Hw/vl53l1/vl53l1_register_funcs.d \
./Hw/vl53l1/vl53l1_sensor.d \
./Hw/vl53l1/vl53l1_silicon_core.d \
./Hw/vl53l1/vl53l1_wait.d 


# Each subdirectory must supply rules for building sources it contributes
Hw/vl53l1/%.o Hw/vl53l1/%.su: ../Hw/vl53l1/%.c Hw/vl53l1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Hw/I2C_PCF8574_LCD -I../Hw/vl53l1 -I../core -I../platform -I../inc -I../platform/inc -I../core/inc -I../../Core/Inc -I../App -I../Hw -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hw-2f-vl53l1

clean-Hw-2f-vl53l1:
	-$(RM) ./Hw/vl53l1/vl53l1_api.d ./Hw/vl53l1/vl53l1_api.o ./Hw/vl53l1/vl53l1_api.su ./Hw/vl53l1/vl53l1_api_calibration.d ./Hw/vl53l1/vl53l1_api_calibration.o ./Hw/vl53l1/vl53l1_api_calibration.su ./Hw/vl53l1/vl53l1_api_core.d ./Hw/vl53l1/vl53l1_api_core.o ./Hw/vl53l1/vl53l1_api_core.su ./Hw/vl53l1/vl53l1_api_debug.d ./Hw/vl53l1/vl53l1_api_debug.o ./Hw/vl53l1/vl53l1_api_debug.su ./Hw/vl53l1/vl53l1_api_preset_modes.d ./Hw/vl53l1/vl53l1_api_preset_modes.o ./Hw/vl53l1/vl53l1_api_preset_modes.su ./Hw/vl53l1/vl53l1_api_strings.d ./Hw/vl53l1/vl53l1_api_strings.o ./Hw/vl53l1/vl53l1_api_strings.su ./Hw/vl53l1/vl53l1_core.d ./Hw/vl53l1/vl53l1_core.o ./Hw/vl53l1/vl53l1_core.su ./Hw/vl53l1/vl53l1_core_support.d ./Hw/vl53l1/vl53l1_core_support.o ./Hw/vl53l1/vl53l1_core_support.su ./Hw/vl53l1/vl53l1_error_strings.d ./Hw/vl53l1/vl53l1_error_strings.o ./Hw/vl53l1/vl53l1_error_strings.su ./Hw/vl53l1/vl53l1_platform.d ./Hw/vl53l1/vl53l1_platform.o ./Hw/vl53l1/vl53l1_platform.su ./Hw/vl53l1/vl53l1_register_funcs.d ./Hw/vl53l1/vl53l1_register_funcs.o ./Hw/vl53l1/vl53l1_register_funcs.su ./Hw/vl53l1/vl53l1_sensor.d ./Hw/vl53l1/vl53l1_sensor.o ./Hw/vl53l1/vl53l1_sensor.su ./Hw/vl53l1/vl53l1_silicon_core.d ./Hw/vl53l1/vl53l1_silicon_core.o ./Hw/vl53l1/vl53l1_silicon_core.su ./Hw/vl53l1/vl53l1_wait.d ./Hw/vl53l1/vl53l1_wait.o ./Hw/vl53l1/vl53l1_wait.su

.PHONY: clean-Hw-2f-vl53l1

