/*
 * GPIO_program.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

#include "RCC_interface.h"




/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_PeriClockControl                                                                           *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port 						*
 * @param[in]         - base address of the gpio peripheral																*
 * @param[in]         - ENABLE or DISABLE macros																		*
 * @return            -  none												 											*
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, u8 EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if       (pGPIOx == GPIOA)
		{
			RCC_void_EnableClock(RCC_APB2 , RCC_PORTA) ;
		}else if (pGPIOx == GPIOB)
		{
			RCC_void_EnableClock(RCC_APB2 , RCC_PORTB) ;
		}else if (pGPIOx == GPIOC)
		{
			RCC_void_EnableClock(RCC_APB2 , RCC_PORTC) ;
		}
	}
	else
	{
		if	     (pGPIOx == GPIOA)
		{
			RCC_void_DisableClock(RCC_APB2 , RCC_PORTA) ;
		}else if (pGPIOx == GPIOB)
		{
			RCC_void_DisableClock(RCC_APB2 , RCC_PORTB) ;
		}else if (pGPIOx == GPIOC)
		{
			RCC_void_DisableClock(RCC_APB2 , RCC_PORTC) ;
		}
	}

}
/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_PeriClockControl                                                                           *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port 						*
 * @param[in]         - base address of the gpio peripheral																*
 * @param[in]         - ENABLE or DISABLE macros																		*
 * @return            -  none												 											*
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_vidInit(GPIO_Handle_t *pGPIOHandle)
{
	u8 PinNumber = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ;
	u8 PinMode   = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinMode   ) ;


   //enable the peripheral clock

    GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

   //1 . configure the mode , configuration , and the speed of the GPIO pin

    if (PinNumber <= 7)
    {
    	pGPIOHandle->pGPIOx->CRL &= ~( (0b1111) << (4*PinNumber) ) ;
    	pGPIOHandle->pGPIOx->CRL |= ((PinMode)<<(4*(PinNumber))) ;

    }
    else           // GPIO PINS 8 >> 15
    {
    	PinNumber -= 8 ;
    	pGPIOHandle->pGPIOx->CRH &= ~( (0b1111) << (4*PinNumber) ) ;
    	pGPIOHandle->pGPIOx->CRH |= ( (PinMode)<<(4*(PinNumber)) )  ;
    }



}
/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_ReadFromInputPin                                                                           *
 * @brief             - This function reads an input pin 					                                        	*
 * @param[in]         - base address of the gpio peripheral																*
 * @param[in]         - pin number to be read 																       		*
 * @return            -  0 or 1 												 								        *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
u8 GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber)
{
	u8 value;

    value = (u8 )((pGPIOx->IDR  >> PinNumber) & 0x00000001 ) ;

    return value;

}
/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_ReadFromInputPort                                                                          *
 * @brief             - This function reads an input port 					                                        	*
 * @param[in]         - base address of the gpio peripheral																*
 * @return            - uint16 port value  												 							    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
u16 GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return ( (u16)( pGPIOx->IDR ) ) ;
}

/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_WriteToOutputPin                                                                           *
 * @brief             - This function writes to an output pin 					                                      	*
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @param[in]         - macro set 1 or reset 0 														                	*
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber, u8 Value)
{

	if(Value == GPIO_PIN_SET)
	{
		//write 1
		//pGPIOx->ODR |= ( 1 << PinNumber);
		pGPIOx->BSRR = ( 1 << PinNumber);

	}else
	{
		//write 0
		//pGPIOx->ODR &= ~( 1 << PinNumber);
		pGPIOx->BRR = ( 1 << PinNumber);

	}
}
/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_WriteToOutputPort                                                                          *
 * @brief             - This function writes to an output port 					                                      	*
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @param[in]         - uint16 value to be written to output port														*
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, u16 Value)
{
	pGPIOx->ODR  = Value;
}

/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_ToggleOutputPin                                                                            *
 * @brief             - This function toggles an output pin 					                                      	*
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @param[in]         - the pin number to be toggled														            *
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber)
{
	pGPIOx->ODR  ^= ( 1 << PinNumber);
}
/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_vidInitNibble                                                                              *
 * @brief             - This function initializes a nipple of a port					                                *
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_vidInitNibble( GPIO_Handle_t *pGPIOHandle )
{
	u8  u8NibbleNumber = pGPIOHandle->GPIO_NippleConfig.GPIO_NibbleNumber ;
	u16 u16_NibbleMode = pGPIOHandle->GPIO_NippleConfig.GPIO_NibbleMode ;

	//enable the peripheral clock

	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//1 . configure the mode , configuration , and the speed of the GPIO pin


	if ( (u8NibbleNumber == GPIO_NIPPLE_0) || (u8NibbleNumber == GPIO_NIPPLE_1) )
	{
		pGPIOHandle->pGPIOx->CRL &= ~( (0xFFFF) << (16*u8NibbleNumber) ) ;
		pGPIOHandle->pGPIOx->CRL |= ((u16_NibbleMode)<<(16*u8NibbleNumber)) ;
	}
	else if ( (u8NibbleNumber == GPIO_NIPPLE_2) || (u8NibbleNumber == GPIO_NIPPLE_3) )
	{
		pGPIOHandle->pGPIOx->CRH &= ~( (0xFFFF) << (16*(u8NibbleNumber-2)) ) ;
		pGPIOHandle->pGPIOx->CRH |= ((u16_NibbleMode)<<(16*(u8NibbleNumber-2))) ;
	}

}

/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_vidInitByte                                                                              *
 * @brief             - This function initializes a Byte of a port					                                *
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/

void GPIO_vidInitByte(GPIO_Handle_t *pGPIOHandle )
{
	u8  u8_ByteNumber = pGPIOHandle->GPIO_ByteConfig.GPIO_ByteNumber ;
	u32 u32_ByteMode  = pGPIOHandle->GPIO_ByteConfig.GPIO_ByteMode ;

	//enable the peripheral clock

	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//1 . configure the mode , configuration , and the speed of the GPIO pin


	if ( u8_ByteNumber == GPIO_LOWER_BYTE )
	{
		pGPIOHandle->pGPIOx->CRL = u32_ByteMode ;
	}
	else if ( u8_ByteNumber == GPIO_HIGHER_BYTE )
	{
		pGPIOHandle->pGPIOx->CRH |= u32_ByteMode  ;
	}
	else
	{
		// invalid byte
	}

}

/*---------------------------------------------------------------------------------------------------------------------*/
/************************************************************************************************************************
 * @fn      		  - GPIO_vidInitByte                                                                              *
 * @brief             - This function initializes a Byte of a port					                                *
 * @param[in]         - base address of the gpio peripheral	                                                            *
 * @param[in]         - the byte number to be initialized														        *
 * @param[in]         - the byte value to be written                      *
 * @return            -  none  												 						            	    *
 * @Note              -  none	                                                                                        *
 ***********************************************************************************************************************/
void GPIO_WriteToOutputByte(GPIO_RegDef_t *pGPIOx ,u8 ByteNumber ,u8 Value)
{

	if (ByteNumber == GPIO_LOWER_BYTE)
	{
		pGPIOx->ODR &= ~( (0xFF) << 0 );
		pGPIOx->ODR |= ( Value << 0 );
	}
	else if (ByteNumber == GPIO_HIGHER_BYTE)
	{
		pGPIOx->ODR &= ~( (0xFF) << 8 );
		pGPIOx->ODR |= ( Value << 8 );
	}
	else
	{
		// invalid byte
	}


}

/***********************************************************************************************************************/

