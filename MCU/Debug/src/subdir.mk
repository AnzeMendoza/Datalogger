################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Led.c \
../src/cr_startup_lpc175x_6x.c \
../src/debounce.c \
../src/gpio.c \
../src/keyboardInfotronic.c \
../src/nvic.c \
../src/pinsel.c \
../src/pll.c \
../src/systick.c \
../src/timerMachine.c \
../src/uart.c 

OBJS += \
./src/Led.o \
./src/cr_startup_lpc175x_6x.o \
./src/debounce.o \
./src/gpio.o \
./src/keyboardInfotronic.o \
./src/nvic.o \
./src/pinsel.o \
./src/pll.o \
./src/systick.o \
./src/timerMachine.o \
./src/uart.o 

C_DEPS += \
./src/Led.d \
./src/cr_startup_lpc175x_6x.d \
./src/debounce.d \
./src/gpio.d \
./src/keyboardInfotronic.d \
./src/nvic.d \
./src/pinsel.d \
./src/pll.d \
./src/systick.d \
./src/timerMachine.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


