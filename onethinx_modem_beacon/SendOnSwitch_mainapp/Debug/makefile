################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/gcc/subdir.mk
-include psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/subdir.mk
-include psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/MemMang/subdir.mk
-include psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F/subdir.mk
-include psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/subdir.mk
-include psoc6sw-1.1/components/psoc6mw/ble/common/subdir.mk
-include psoc6sw-1.1/components/psoc6mw/ble/subdir.mk
-include Source/subdir.mk
-include OnethinxCore/subdir.mk
-include GeneratedSource/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SendOnSwitch_mainapp.elf secondary-outputs

dependents:
	-cd /Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/psoc6pdl_Cortex-M4/Debug && $(MAKE) clean all

# Tool invocations
SendOnSwitch_mainapp.elf: $(OBJS) $(USER_OBJS) /Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/psoc6pdl_Cortex-M4/Debug/libpsoc6pdl_Cortex-M4.a
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -T "/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/cy8c6xx7_cm4_dual.ld" -Xlinker --gc-sections -Wl,-Map,"SendOnSwitch_mainapp.map" --specs=nano.specs -ffat-lto-objects -g --enable-objc-gc -mfpu=fpv4-sp-d16 -o "SendOnSwitch_mainapp.elf" -Wl,--start-group $(OBJS) $(USER_OBJS) $(LIBS) -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) SendOnSwitch_mainapp.elf
	-@echo ' '

post-build:
	-/Applications/ModusToolbox_1.1/tools/modus-shell-1.0/bin/bash --norc --noprofile /Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/makefiles/platforms/PSoC6_cm4_single/cymcuelftool_postbuild.bash /Applications/ModusToolbox_1.1/tools/cymcuelftool-1.0/bin/cymcuelftool /Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/SendOnSwitch_mainapp/Debug/SendOnSwitch_mainapp.elf ARM_CM4
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents post-build
/Users/tadmcallister/Onethinx/Onethinx_Modem/OnethinxATCommand/psoc6pdl_Cortex-M4/Debug/libpsoc6pdl_Cortex-M4.a:

-include ../makefile.targets
