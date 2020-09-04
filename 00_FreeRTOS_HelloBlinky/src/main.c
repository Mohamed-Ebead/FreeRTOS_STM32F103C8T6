

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "Led_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "RCC_interface.h"
#include "semihosting.h"


TaskHandle_t xTaskHandle1 = NULL ;
TaskHandle_t xTaskHandle2 = NULL ;


void vTask1_Handler (void* params) ;
void vTask2_Handler (void* params) ;


void Delay (void)
{
	for(int i = 0 ; i < 600 ; i++ )
{
	for(int j = 0 ; j < 600 ; j++ )
	{
		asm("NOP");
	}
}

}


int main (void)
{
	//initialise_monitor_handles();

	RCC_voidInitSysClock() ;

	RedLed_Init();
	GreenLed_Init();

	xTaskCreate(vTask1_Handler ,"RedLedOn" ,configMINIMAL_STACK_SIZE,NULL ,2,&xTaskHandle1) ;
	xTaskCreate(vTask2_Handler ,"RedLedOFF",configMINIMAL_STACK_SIZE,NULL ,2,&xTaskHandle2) ;

	vTaskStartScheduler() ;


for(;;) ;
}

/**-------------------------------------------------------------------------------------------------------**/

void vTask1_Handler (void* params)
{
	while (1)
	{
		RedLed_Toggle();
		Delay();

	}

}



void vTask2_Handler (void* params)
{

	while (1)
	{
		GreenLed_Toggle();
		Delay();

	}

}













