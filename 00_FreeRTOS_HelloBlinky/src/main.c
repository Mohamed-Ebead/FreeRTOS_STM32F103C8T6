

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "Led_interface.h"

#include "RCC_interface.h"

/**-------------------------------------------------------------------------------------------------------**/


TaskHandle_t xTaskHandle1 = NULL ;
TaskHandle_t xTaskHandle2 = NULL ;


void vTask1_Handler (void* params) ;
void vTask2_Handler (void* params) ;

/**-------------------------------------------------------------------------------------------------------**/


int main (void)
{
	RCC_voidInitSysClock() ;

	RedLed_Init();
	GreenLed_Init();

	RedLed_TurnOn() ;
	GreenLed_TurnOff() ;

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
		vTaskDelay(1000) ;

	}

}



void vTask2_Handler (void* params)
{

	while (1)
	{
		GreenLed_Toggle();
		vTaskDelay(1000) ;

	}

}

/**-------------------------------------------------------------------------------------------------------**/












