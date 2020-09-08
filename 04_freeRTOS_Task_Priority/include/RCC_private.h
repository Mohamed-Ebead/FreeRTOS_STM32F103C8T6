/**
 *
 *  Created on: Aug 11, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC      1
#define RCC_HSI         2
#define RCC_PLL         3


/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2           0
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2   1
#define RCC_PLL_IN_HSE_RC_DIV_2        2
#define RCC_PLL_IN_HSE                 3



#define PLLXTPRE_BIT          17       /*HSE divider for PLL entry*/
#define PLLSRC_BIT            16       /*PLL entry clock source*/

#define PLLON_BIT       24
#define PLLMUL_BIT      18

#define RCC_CR      	(*((volatile u32*)0x40021000))
#define RCC_CFGR     	(*((volatile u32*)0x40021004))
#define RCC_CIR      	(*((volatile u32*)0x40021008))
#define RCC_APB2RSTR 	(*((volatile u32*)0x4002100C))
#define RCC_APB1RSTS 	(*((volatile u32*)0x40021010))
#define RCC_AHBENR   	(*((volatile u32*)0x40021014))
#define RCC_APB2ENR 	(*((volatile u32*)0x40021018))
#define RCC_APB1ENR 	(*((volatile u32*)0x4002101C))
#define RCC_BDCR     	(*((volatile u32*)0x40021020))
#define RCC_CSR      	(*((volatile u32*)0x40021024))




#endif   /* RCC_PRIVATE_H_*/
