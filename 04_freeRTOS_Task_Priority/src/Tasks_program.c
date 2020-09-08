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


#include "Task_priority.h"

extern TaskHandle_t xTaskHandle1  ;
extern TaskHandle_t xTaskHandle2  ;



void RTOS_Delay_ms (u32 delay_in_ms)
{
	u32 current_tick_count = xTaskGetTickCount();

	u32 delay_in_ticks = (delay_in_ms * configTICK_RATE_HZ ) /1000 ;

	while(xTaskGetTickCount() <  (current_tick_count + delay_in_ticks));

}



/**-------------------------------------------------------------------------------------------------------**/

void vBlink200_Handler (void* params)
{

	//u8 Priority1  , Priority2 = 0 ;

	while (1)
	{

		if( Button1_GetCurrentStatus() == PRESSED )
		{

			vTaskPrioritySet(xTaskHandle1,TASK1_PRIORITY);
			vTaskPrioritySet(xTaskHandle2,TASK2_PRIORITY);

		/*	Priority1 = uxTaskPriorityGet(xTaskHandle1);
			Priority2 = uxTaskPriorityGet(xTaskHandle2);

			//switch prio
			vTaskPrioritySet(xTaskHandle1,Priority2);
			vTaskPrioritySet(xTaskHandle2,Priority1);*/
		}
		else
		{
			RedLed_Toggle()  ;
			RTOS_Delay_ms(200)  ;
		}


	}

}

/**-------------------------------------------------------------------------------------------------------**/

void vBlink1000_Handler (void* params)
{
	//u8 Priority1  , Priority2 = 0 ;

	while (1)
	{

		if( Button1_GetCurrentStatus() == PRESSED )
		{
			//switch prio
			vTaskPrioritySet(xTaskHandle1,TASK2_PRIORITY);
			vTaskPrioritySet(xTaskHandle2,TASK1_PRIORITY);


		/*	Priority1 = uxTaskPriorityGet(xTaskHandle1);
			Priority2 = uxTaskPriorityGet(xTaskHandle2);

			vTaskPrioritySet(xTaskHandle1,Priority2);
			vTaskPrioritySet(xTaskHandle2,Priority1);*/

		}
		else
		{
		    //lets toggle the led for every 1 sec
		    RedLed_Toggle()   ;
		    RTOS_Delay_ms(1000)  ;
		}


	}

}

/**-------------------------------------------------------------------------------------------------------**/

/**-------------------------------------------------------------------------------------------------------**/


