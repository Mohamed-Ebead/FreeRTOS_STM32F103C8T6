/*
 * Button_program.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"

/**-------------------------------------------------------------------------------*/

void Button1_voidInit        (void)
{
	GPIO_Handle_t GPIO_Button ;
	GPIO_Button.pGPIOx = BUTTON1_PORT ;
	GPIO_Button.GPIO_PinConfig.GPIO_PinNumber = BUTTON1_PIN ;
	GPIO_Button.GPIO_PinConfig.GPIO_PinMode = INPUT_PULLUP_PULLDOWN ;

	GPIO_vidInit(&GPIO_Button) ;

//	switch (BUTTON1_CONNECT)
	//{
	//case PULLUP :
		GPIO_WriteToOutputPin(BUTTON1_PORT ,BUTTON1_PIN , GPIO_PIN_SET );//break ;
//	case PULLDOWN :
	//	GPIO_WriteToOutputPin(BUTTON1_PORT ,BUTTON1_PIN , GPIO_PIN_RESET );break ;
//	default : break ;
	//}

}

/**-------------------------------------------------------------------------------*/

u8   Button1_GetCurrentStatus (void)
{
	u8 Local_u8ButtonStatus = NOT_PRESSED ;
	/*switch (BUTTON1_CONNECT)
	{
	case PULLDOWN :
		if ( GPIO_ReadFromInputPin(BUTTON1_PORT ,BUTTON1_PIN ))
		{
			Local_u8ButtonStatus = PRESSED ;
		}
		else
		{
			// NOT PRESSED
		}
		break ;
	case PULLUP :
		if ( ! GPIO_ReadFromInputPin(BUTTON1_PORT ,BUTTON1_PIN ))
		{
			Local_u8ButtonStatus = PRESSED ;
		}
		else
		{
			// NOT PRESSED
		}
		break ;
	}*/
	if ( ! GPIO_ReadFromInputPin(BUTTON1_PORT ,BUTTON1_PIN ))
	{
		Local_u8ButtonStatus = PRESSED ;
	}
	else
	{
		// NOT PRESSED
	}

	return Local_u8ButtonStatus ;

}

/**-------------------------------------------------------------------------------*/


