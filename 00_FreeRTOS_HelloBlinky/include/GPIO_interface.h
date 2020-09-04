/*
 * GPIO_interface.h
 *
 *  Created on: Aug 16, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define _RW_  volatile               //  Read / Write
#define _WO_  volatile               //  Write Only
#define _RO_  volatile const         //  Read Only

typedef struct
{
	_RW_ u32 CRL;                        /*!< GPIO port mode register,                    	Address offset: 0x00      */
	_RW_ u32 CRH;                       /*!< TODO,     										Address offset: 0x04      */
	_RW_ u32 IDR;
	_RW_ u32 ODR;
	_RW_ u32 BSRR;
	_RW_ u32 BRR;
	_RW_ u32 LCKR;

} GPIO_RegDef_t;


/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)


/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
	u8 GPIO_PinNumber;
	u8 GPIO_PinMode;			  /*!< possible values from @GPIO_PIN_MODES >*/

}GPIO_PinConfig_t;


/*
 * This is a Configuration structure for a GPIO Nibble
 */
typedef struct
{
	u8 GPIO_NibbleNumber;
	u16 GPIO_NibbleMode;			  /*!< possible values from @GPIO_PIN_MODES >*/

}GPIO_NibbleConfig_t;


/*
 * This is a Configuration structure for a GPIO Byte
 */
typedef struct
{
	u8 GPIO_ByteNumber;
	u32 GPIO_ByteMode;			  /*!< possible values from @GPIO_PIN_MODES >*/

}GPIO_ByteConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t GPIO_PinConfig;   /*!< This holds GPIO pin configuration settings >*/
	GPIO_NibbleConfig_t GPIO_NippleConfig ;
	GPIO_ByteConfig_t GPIO_ByteConfig ;

}GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
/*------------------------------------------ PIN MODES ------------------------------------------*/
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10
#define OUTPUT_10MHZ_PP           0b0001
#define OUTPUT_10MHZ_OD           0b0101
#define OUTPUT_10MHZ_AFPP         0b1001
#define OUTPUT_10MHZ_AFOD         0b1101

//For Speed 2
#define OUTPUT_2MHZ_PP            0b0010
#define OUTPUT_2MHZ_OD            0b0110
#define OUTPUT_2MHZ_AFPP          0b1010
#define OUTPUT_2MHZ_AFOD          0b1110

//For Speed 50
#define OUTPUT_50MHZ_PP           0b0011
#define OUTPUT_50MHZ_OD           0b0111
#define OUTPUT_50MHZ_AFPP         0b1011
#define OUTPUT_50MHZ_AFOD         0b1111

/************************************************************************************************/
/*------------------------------------------ NIPPLE MODES ------------------------------------------*/

#define GPIO_NIPPLE_0             0          // BIT0 >> BIT3
#define GPIO_NIPPLE_1             1			 // BIT4 >> BIT7
#define GPIO_NIPPLE_2             2			 // BIT8 >> BIT11
#define GPIO_NIPPLE_3             3			 // BIT12 >> BIT15


#define GPIO_NIBBLE_INPUT_ANLOG               0x0000
#define GPIO_NIBBLE_INPUT_FLOATING            0x4444
#define GPIO_NIBBLE_INPUT_PULLUP_PULLDOWN     0x8888

//For Speed 10
#define GPIO_NIBBLE_OUTPUT_10MHZ_PP           0x1111
#define GPIO_NIBBLE_OUTPUT_10MHZ_OD           0x5555
#define GPIO_NIBBLE_OUTPUT_10MHZ_AFPP         0x9999
#define GPIO_NIBBLE_OUTPUT_10MHZ_AFOD         0xDDDD

//For Speed 2
#define GPIO_NIBBLE_OUTPUT_2MHZ_PP            0X2222
#define GPIO_NIBBLE_OUTPUT_2MHZ_OD            0x6666
#define GPIO_NIBBLE_OUTPUT_2MHZ_AFPP          0xAAAA
#define GPIO_NIBBLE_OUTPUT_2MHZ_AFOD          0xEEEE

//For Speed 50
#define GPIO_NIBBLE_OUTPUT_50MHZ_PP           0x3333
#define GPIO_NIBBLE_OUTPUT_50MHZ_OD           0x7777
#define GPIO_NIBBLE_OUTPUT_50MHZ_AFPP         0xBBBB
#define GPIO_NIBBLE_OUTPUT_50MHZ_AFOD         0xFFFF

/************************************************************************************************/
/************************************************************************************************/
/*------------------------------------------ Byte MODES ------------------------------------------*/

#define GPIO_LOWER_BYTE             0            // BIT0 >> BIT7
#define GPIO_HIGHER_BYTE            1			 // BIT8 >> BIT15



#define GPIO_BYTE_INPUT_ANLOG               0x00000000
#define GPIO_BYTE_INPUT_FLOATING            0x44444444
#define GPIO_BYTE_INPUT_PULLUP_PULLDOWN     0x88888888

//For Speed 10
#define GPIO_BYTE_OUTPUT_10MHZ_PP           0x11111111
#define GPIO_BYTE_OUTPUT_10MHZ_OD           0x55555555
#define GPIO_BYTE_OUTPUT_10MHZ_AFPP         0x99999999
#define GPIO_BYTE_OUTPUT_10MHZ_AFOD         0xDDDDDDDD

//For Speed 2BYTE
#define GPIO_BYTE_OUTPUT_2MHZ_PP            0X22222222
#define GPIO_BYTE_OUTPUT_2MHZ_OD            0x66666666
#define GPIO_BYTE_OUTPUT_2MHZ_AFPP          0xAAAAAAAA
#define GPIO_BYTE_OUTPUT_2MHZ_AFOD          0xEEEEEEEE

//For Speed 50
#define GPIO_BYTE_OUTPUT_50MHZ_PP           0x33333333
#define GPIO_BYTE_OUTPUT_50MHZ_OD           0x77777777
#define GPIO_BYTE_OUTPUT_50MHZ_AFPP         0xBBBBBBBB
#define GPIO_BYTE_OUTPUT_50MHZ_AFOD         0xFFFFFFFF

/************************************************************************************************/


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, u8 EnorDi);

/*
 * Init and De-init
 */
void GPIO_vidInit(GPIO_Handle_t *pGPIOHandle);
void GPIO_vidDeInit(GPIO_RegDef_t *pGPIOx);

/*
 * NIPPLE initialization
 */
void GPIO_vidInitNibble(GPIO_Handle_t *pGPIOHandle );

/*
 * Byte initialization
 */
void GPIO_vidInitByte(GPIO_Handle_t *pGPIOHandle );

/*
 * PIN Data read and write
 */
u8 GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber, u8 Value);

/*
 * PORT Data read and write
 */
u16 GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, u16 Value);

/*
 * BYTE Data write
 */
void GPIO_WriteToOutputByte(GPIO_RegDef_t *pGPIOx ,u8 ByteNumber ,u8 Value) ;


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, u8 PinNumber);


//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET          RESET
#define FLAG_SET 			SET



#endif /* GPIO_INTERFACE_H_ */
