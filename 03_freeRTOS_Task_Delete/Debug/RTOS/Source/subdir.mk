################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/Source/croutine.c \
../RTOS/Source/event_groups.c \
../RTOS/Source/list.c \
../RTOS/Source/queue.c \
../RTOS/Source/stream_buffer.c \
../RTOS/Source/tasks.c \
../RTOS/Source/timers.c 

OBJS += \
./RTOS/Source/croutine.o \
./RTOS/Source/event_groups.o \
./RTOS/Source/list.o \
./RTOS/Source/queue.o \
./RTOS/Source/stream_buffer.o \
./RTOS/Source/tasks.o \
./RTOS/Source/timers.o 

C_DEPS += \
./RTOS/Source/croutine.d \
./RTOS/Source/event_groups.d \
./RTOS/Source/list.d \
./RTOS/Source/queue.d \
./RTOS/Source/stream_buffer.d \
./RTOS/Source/tasks.d \
./RTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/Source/%.o: ../RTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"E:\IMT_ARM\Work_Space\freeRTOS_3_Task_Delete\RTOS\Config" -I"E:\IMT_ARM\Work_Space\freeRTOS_3_Task_Delete\include" -I"E:\IMT_ARM\Work_Space\freeRTOS_3_Task_Delete\RTOS\Source\include" -I"E:\IMT_ARM\Work_Space\freeRTOS_3_Task_Delete\RTOS\Source\portable\GCC\ARM_CM3" -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


