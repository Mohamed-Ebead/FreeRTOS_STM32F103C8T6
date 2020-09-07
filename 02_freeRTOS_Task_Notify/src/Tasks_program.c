/*
 * Tasks_program.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "Led_interface.h"
#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"

#include "RCC_interface.h"

//extern TaskHandle_t xTaskHandle1  ;
extern TaskHandle_t xTaskHandle2  ;

/**-------------------------------------------------------------------------------------------------------**/


void RTOS_Delay_ms (u32 delay_in_ms)
{
	u32 current_tick_count = xTaskGetTickCount();

	u32 delay_in_ticks = (delay_in_ms * configTICK_RATE_HZ ) /1000 ;

	while(xTaskGetTickCount() <  (current_tick_count + delay_in_ticks));

}


/**-------------------------------------------------------------------------------------------------------**/

void vButton_Handler (void* params)
{
	while (1)
	{
		if( Button1_GetCurrentStatus() == PRESSED )
		{
			//we will come here if button is pressed

			//lets wait here for 100ms to compensate for the button debouncing
			RTOS_Delay_ms( (u32)150 ) ;

			//lets send the notification to led_task
			xTaskNotify ( xTaskHandle2 , 0x0 , eIncrement )  ;
		}

	}

}

/**-------------------------------------------------------------------------------------------------------**/

void vLed_Handler (void* params)
{

	while (1)
	{
		//lets wait until we receive any notification event from button_Task

		if ( xTaskNotifyWait(0,0,NULL,portMAX_DELAY) == pdTRUE )
		{
			//we received the notification . so lets toggle the LED
			RedLed_Toggle()  ;

		}

	}

}

/**-------------------------------------------------------------------------------------------------------**/

/**-------------------------------------------------------------------------------------------------------**/


