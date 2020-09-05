/*
 * RCC_program.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*-----------------------------------------------------------------------------------------*/
/**
 * @fun    : RCC_void_EnableClock
 * @brief  : This function enables clock for a specific peripheral
 * @param  : Copy_u8BusID
 * @param  : Copy_u8PeriphID
 * @return :none
 */
void RCC_void_EnableClock (u8 Copy_u8BusID , u8 Copy_u8PeriphID )
{
	if (Copy_u8PeriphID <= 31 )
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : SET_BIT ( RCC_AHBENR  , Copy_u8PeriphID ) ; break ;
			case RCC_APB1 : SET_BIT ( RCC_APB1ENR , Copy_u8PeriphID ) ; break ;
			case RCC_APB2 : SET_BIT ( RCC_APB2ENR , Copy_u8PeriphID ) ; break ;
		}

	}
	else
	{
		// error Copy_u8PeriphID
	}

}

/*-----------------------------------------------------------------------------------------*/
/**
 * @fun    : RCC_void_DisableClock
 * @brief  : This function disables clock for a specific peripheral
 * @param  : Copy_u8BusID
 * @param  : Copy_u8PeriphID
 * @return :
 * @note   :
 */
void RCC_void_DisableClock (u8 Copy_u8BusID , u8 Copy_u8PeriphID )
{
	if (Copy_u8PeriphID <= 31 )
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : CLR_BIT ( RCC_AHBENR  , Copy_u8PeriphID ) ; break ;
			case RCC_APB1 : CLR_BIT ( RCC_APB1ENR , Copy_u8PeriphID ) ; break ;
			case RCC_APB2 : CLR_BIT ( RCC_APB2ENR , Copy_u8PeriphID ) ; break ;
		}

	}
	else
	{
		// error Copy_u8PeriphID
	}

}
/*-----------------------------------------------------------------------------------------*/
/**
 * @fun   : RCC_voidInitSysClock
 * @brief : this function initialized the system clock based on the configuration file "RCC_config.h"
 * @note  :
 */
void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
			RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x00050000; /* Enable HSE with bypass */
			RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
			RCC_CFGR = 0x00000000;

	#elif   RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			  RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
			  SET_BIT(RCC_CFGR,PLLSRC_BIT) ; /*HSI oscillator clock / 2 selected as PLL input clock*/

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
			  RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
			  CLR_BIT(RCC_CFGR,PLLSRC_BIT) ; /*HSE oscillator clock selected as PLL input clock*/
			  SET_BIT(RCC_CFGR,PLLXTPRE_BIT) ; /*HSE clock divided by 2*/

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_DIV_2
			  RCC_CR   = 0x00050000; /* Enable HSE with bypass */
			  SET_BIT(RCC_CFGR,PLLSRC_BIT) ;/*HSE oscillator clock selected as PLL input clock*/
			  CLR_BIT(RCC_CFGR,PLLXTPRE_BIT) ; /*HSE clock not divided*/

		#endif
		if (RCC_PLL_MUL_VAL >= 2 )
		{
			 RCC_CFGR |= ((RCC_PLL_MUL_VAL - 2 ) << PLLMUL_BIT ) ;  /* SET PLL multiplier */
		}
		else
		{
			RCC_CFGR |= (( 0b0000 ) << PLLMUL_BIT ) ;  /* SET PLL multiplier */
		}
			 SET_BIT(RCC_CR , PLLON_BIT) ;  /* enable PLL */

	#else
		#error("Invalid Clock type")
	#endif
}

/*-----------------------------------------------------------------------------------------*/




