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




void RTOS_Delay_ms (u32 delay_in_ms)
{
	u32 current_tick_count = xTaskGetTickCount();

	u32 delay_in_ticks = (delay_in_ms * configTICK_RATE_HZ ) /1000 ;

	while(xTaskGetTickCount() <  (current_tick_count + delay_in_ticks));

}



/**-------------------------------------------------------------------------------------------------------**/

void vBlink200_Handler (void* params)
{
	while (1)
	{
		RTOS_Delay_ms(200)  ;
		RedLed_Toggle()  ;

	}

}

/**-------------------------------------------------------------------------------------------------------**/

void vBlink1000_Handler (void* params)
{

	while (1)
	{

		if( Button1_GetCurrentStatus() == PRESSED )
		{
			//button is pressed on the nucleo board
		    //Task2 deletes itself
		    vTaskDelete(NULL);
		}
		else
		{

			//button is not pressed on the nucleo board
		    //lets toggle the led for every 1 sec

			RTOS_Delay_ms(1000)  ;
		    RedLed_Toggle()   ;
		}


	}

}

/**-------------------------------------------------------------------------------------------------------**/

/**-------------------------------------------------------------------------------------------------------**/


