/*
 * GPIO_private.h
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define _RW_  volatile               //  Read / Write
#define _WO_  volatile               //  Write Only
#define _RO_  volatile const         //  Read Only


/********************************** START:Processor Specific Details ********************************/


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHBPERIPH_BASEADDR						0x40018000U


#define GPIOA_BASEADDR                   (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR                   (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR 					 (APB2PERIPH_BASEADDR + 0x1000)



///********************************** peripheral register definition structures ********************************/
//
//
///*
// * Note : Registers of a peripheral are specific to MCU
// * e.g : Number of Registers of SPI peripheral of STM32F4x family of MCUs may be different(more or less)
// * Compared to number of registers of SPI peripheral of STM32Lx or STM32F0x family of MCUs
// * Please check your Device RM
// */
//
//typedef struct
//{
//	_RW_ u32 CRL;                        /*!< GPIO port mode register,                    	Address offset: 0x00      */
//	_RW_ u32 CRH;                       /*!< TODO,     										Address offset: 0x04      */
//	_RW_ u32 IDR;
//	_RW_ u32 ODR;
//	_RW_ u32 BSRR;
//	_RW_ u32 BRR;
//	_RW_ u32 LCKR;
//
//} GPIO_RegDef_t;
//
//
///*
// * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
// */
//
//#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
//#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
//#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
















#endif /* GPIO_PRIVATE_H_ */
