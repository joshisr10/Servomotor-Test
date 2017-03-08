################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dxl_sdk/dxl_hal.c \
../dxl_sdk/dynamixel.c 

OBJS += \
./dxl_sdk/dxl_hal.o \
./dxl_sdk/dynamixel.o 

C_DEPS += \
./dxl_sdk/dxl_hal.d \
./dxl_sdk/dynamixel.d 


# Each subdirectory must supply rules for building sources it contributes
dxl_sdk/%.o: ../dxl_sdk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/user/workspace.kds/motorTest/Static_Code/System" -I"C:/Users/user/workspace.kds/motorTest/Static_Code/PDD" -I"C:/Users/user/workspace.kds/motorTest/Static_Code/IO_Map" -I"E:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/user/workspace.kds/motorTest/Sources" -I"C:/Users/user/workspace.kds/motorTest/Generated_Code" -I"C:/Users/user/workspace.kds/motorTest/dxl_sdk" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


