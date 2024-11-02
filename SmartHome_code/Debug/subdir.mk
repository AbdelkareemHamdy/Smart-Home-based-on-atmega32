################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPuser_program.c \
../DIO_Program.c \
../Dio.c \
../GIE_program.c \
../Lcd.c \
../Timer1_program.c \
../USART_program.c \
../app2_program.c \
../main.c \
../smart_door_program.c 

OBJS += \
./APPuser_program.o \
./DIO_Program.o \
./Dio.o \
./GIE_program.o \
./Lcd.o \
./Timer1_program.o \
./USART_program.o \
./app2_program.o \
./main.o \
./smart_door_program.o 

C_DEPS += \
./APPuser_program.d \
./DIO_Program.d \
./Dio.d \
./GIE_program.d \
./Lcd.d \
./Timer1_program.d \
./USART_program.d \
./app2_program.d \
./main.d \
./smart_door_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


