################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DHT22.c \
../Src/LCD.c \
../Src/Servo.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DHT22.o \
./Src/LCD.o \
./Src/Servo.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DHT22.d \
./Src/LCD.d \
./Src/Servo.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L476RGTx -c -I../Inc -I"C:/Users/Magee/Downloads/Update5_12.1/TemperatureReadingFanV2/CMSIS/Include" -I"C:/Users/Magee/Downloads/Update5_12.1/TemperatureReadingFanV2/CMSIS/Device/ST/STM32L4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DHT22.cyclo ./Src/DHT22.d ./Src/DHT22.o ./Src/DHT22.su ./Src/LCD.cyclo ./Src/LCD.d ./Src/LCD.o ./Src/LCD.su ./Src/Servo.cyclo ./Src/Servo.d ./Src/Servo.o ./Src/Servo.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

