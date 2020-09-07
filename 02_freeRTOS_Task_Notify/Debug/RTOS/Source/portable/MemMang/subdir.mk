################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./RTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./RTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/Source/portable/MemMang/%.o: ../RTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"E:\IMT_ARM\Work_Space\freeRTOS_2_Task_Notify\RTOS\Config" -I"E:\IMT_ARM\Work_Space\freeRTOS_2_Task_Notify\include" -I"E:\IMT_ARM\Work_Space\freeRTOS_2_Task_Notify\RTOS\Source\include" -I"E:\IMT_ARM\Work_Space\freeRTOS_2_Task_Notify\RTOS\Source\portable\GCC\ARM_CM3" -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


