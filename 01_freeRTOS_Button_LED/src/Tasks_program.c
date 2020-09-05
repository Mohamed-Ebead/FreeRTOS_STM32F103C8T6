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

extern u8 ButtonStatusFlag ;

/**-------------------------------------------------------------------------------------------------------**/

void vButton_Handler (void* params)
{
	while (1)
	{
		ButtonStatusFlag = Button1_GetCurrentStatus();

	}

}

/**-------------------------------------------------------------------------------------------------------**/

void vLed_Handler (void* params)
{

	while (1)
	{
		if (ButtonStatusFlag == PRESSED)
		{
			RedLed_TurnOn()  ;
		}
		else
		{
			RedLed_TurnOff() ;
		}

	}

}

/**-------------------------------------------------------------------------------------------------------**/


