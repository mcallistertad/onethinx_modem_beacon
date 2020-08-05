################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/ATinterface.c \
../Source/BLE_Task.c \
../Source/LED_Task.c \
../Source/main.c 

OBJS += \
./Source/ATinterface.o \
./Source/BLE_Task.o \
./Source/LED_Task.o \
./Source/main.o 

C_DEPS += \
./Source/ATinterface.d \
./Source/BLE_Task.d \
./Source/LED_Task.d \
./Source/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCY8C6347BZI_BLD53 -DDEBUG -DAPP_NAME='"SendOnSwitch_cm4"' -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/OnethinxCore" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/common" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/single_cm4_softfp" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/include" -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/GeneratedSource" -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_low" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_high" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/linker/cm4" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/base" -std=gnu11 -mfpu=fpv4-sp-d16 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


