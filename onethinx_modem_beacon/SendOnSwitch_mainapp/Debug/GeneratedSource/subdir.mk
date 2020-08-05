################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GeneratedSource/cycfg.c \
../GeneratedSource/cycfg_ble.c \
../GeneratedSource/cycfg_clocks.c \
../GeneratedSource/cycfg_peripherals.c \
../GeneratedSource/cycfg_pins.c \
../GeneratedSource/cycfg_platform.c \
../GeneratedSource/cycfg_routing.c 

OBJS += \
./GeneratedSource/cycfg.o \
./GeneratedSource/cycfg_ble.o \
./GeneratedSource/cycfg_clocks.o \
./GeneratedSource/cycfg_peripherals.o \
./GeneratedSource/cycfg_pins.o \
./GeneratedSource/cycfg_platform.o \
./GeneratedSource/cycfg_routing.o 

C_DEPS += \
./GeneratedSource/cycfg.d \
./GeneratedSource/cycfg_ble.d \
./GeneratedSource/cycfg_clocks.d \
./GeneratedSource/cycfg_peripherals.d \
./GeneratedSource/cycfg_pins.d \
./GeneratedSource/cycfg_platform.d \
./GeneratedSource/cycfg_routing.d 


# Each subdirectory must supply rules for building sources it contributes
GeneratedSource/%.o: ../GeneratedSource/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCY8C6347BZI_BLD53 -DDEBUG -DAPP_NAME='"SendOnSwitch_cm4"' -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/OnethinxCore" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/common" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/single_cm4_softfp" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/include" -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/GeneratedSource" -I"/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_low" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_high" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/linker/cm4" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/base" -std=gnu11 -mfpu=fpv4-sp-d16 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


