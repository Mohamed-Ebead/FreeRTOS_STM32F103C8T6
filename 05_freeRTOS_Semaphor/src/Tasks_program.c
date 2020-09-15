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
#include "semphr.h"

#include "Led_interface.h"
#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"

#include "RCC_interface.h"

extern xSemaphoreHandle Binary_Semaphor  ;


/**-------------------------------------------------------------------------------------------------------**/

void vButton_Handler (void* params)
{
	/* A semaphore is going to be used to guard a shared resource. In this case a
		Binary type . */

	xSemaphoreGive(Binary_Semaphor) ;


	while (1)
	{


			if ( Button1_GetCurrentStatus() == PRESSED )
			{
				xSemaphoreGive(Binary_Semaphor) ;
			}
			else
			{
				xSemaphoreTake(Binary_Semaphor ,100 ) ;
			}
			//vTaskDelayUntil( &LastWakeTime  , pdMS_TO_TICKS(50) ) ;

		vTaskDelay( pdMS_TO_TICKS(100) ) ;

	}

}

/**-------------------------------------------------------------------------------------------------------**/

void vLed_Handler (void* params)
{

	while (1)
	{
		if (xSemaphoreTake(Binary_Semaphor ,0 ) == pdPASS)
		{
			RedLed_Toggle() ;
			xSemaphoreGive(Binary_Semaphor) ;
		}
		else
		{

		}
		vTaskDelay(200) ;


	}

}

/**-------------------------------------------------------------------------------------------------------**/


