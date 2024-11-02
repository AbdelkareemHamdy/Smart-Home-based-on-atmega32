################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
LSS += \
SmartHome_testing.lss \

FLASH_IMAGE += \
SmartHome_testing.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SmartHome_testing.elf secondary-outputs

# Tool invocations
SmartHome_testing.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SmartHome_testing.map -mmcu=atmega32 -o "SmartHome_testing.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SmartHome_testing.lss: SmartHome_testing.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SmartHome_testing.elf  >"SmartHome_testing.lss"
	@echo 'Finished building: $@'
	@echo ' '

SmartHome_testing.hex: SmartHome_testing.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SmartHome_testing.elf  "SmartHome_testing.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SmartHome_testing.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SmartHome_testing.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SmartHome_testing.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
