/*
 * Led_program.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "Led_interface.h"
#include "led_config.h"

/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/
void RedLed_Init       (void)
{
	GPIO_Handle_t RedLed;
	RedLed.pGPIOx = RED_LED_PORT;
	RedLed.GPIO_PinConfig.GPIO_PinNumber = RED_LED_PIN ;
	RedLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&RedLed);

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Init     (void)
{
	GPIO_Handle_t GreenLed;
	GreenLed.pGPIOx = GREEN_LED_PORT;
	GreenLed.GPIO_PinConfig.GPIO_PinNumber = GREEN_LED_PIN;
	GreenLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&GreenLed);

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_Init    (void)
{
	GPIO_Handle_t YellowLed;
	YellowLed.pGPIOx = YELLOW_LED_PORT;
	YellowLed.GPIO_PinConfig.GPIO_PinNumber = YELLOW_LED_PIN;
	YellowLed.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_PP;
	GPIO_vidInit(&YellowLed);

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_Toggle     (void)
{
	GPIO_ToggleOutputPin(RED_LED_PORT,RED_LED_PIN) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_Toggle   (void)
{
	GPIO_ToggleOutputPin(GREEN_LED_PORT,GREEN_LED_PIN) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_Toggle  (void)
{
	GPIO_ToggleOutputPin(YELLOW_LED_PORT,YELLOW_LED_PIN) ;

}

/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOn     (void)
{
	GPIO_WriteToOutputPin(RED_LED_PORT,RED_LED_PIN,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOn   (void)
{
	GPIO_WriteToOutputPin(GREEN_LED_PORT,GREEN_LED_PIN,GPIO_PIN_SET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_TurnOn  (void)
{
	GPIO_WriteToOutputPin(YELLOW_LED_PORT,YELLOW_LED_PIN,GPIO_PIN_SET) ;

}
/*****************************************************************************************************/
/**--------------------------------------------------------------------------------------------------*/

void RedLed_TurnOff    (void)
{
	GPIO_WriteToOutputPin(RED_LED_PORT,RED_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void GreenLed_TurnOff  (void)
{
	GPIO_WriteToOutputPin(GREEN_LED_PORT,GREEN_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/

void YellowLed_TurnOff (void)
{
	GPIO_WriteToOutputPin(YELLOW_LED_PORT,YELLOW_LED_PIN,GPIO_PIN_RESET) ;

}

/**--------------------------------------------------------------------------------------------------*/
/*****************************************************************************************************/











