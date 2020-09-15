

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "semphr.h"

#include "Tasks_interface.h"

#include "Led_interface.h"
#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"

#include "RCC_interface.h"

xSemaphoreHandle Binary_Semaphor = NULL ;


int main (void)
{
	RCC_voidInitSysClock() ;

	Button1_voidInit();
	RedLed_Init();

	Binary_Semaphor = xSemaphoreCreateBinary() ;
	xTaskCreate(vButton_Handler ,"ButtonCheckFlag" ,configMINIMAL_STACK_SIZE,NULL ,2,&xTaskHandle1) ;
	xTaskCreate(vLed_Handler    ,"LedTakeAction"   ,configMINIMAL_STACK_SIZE,NULL ,1,&xTaskHandle2) ;


	vTaskStartScheduler() ;


	while (1)
	{

	}

return 0 ;
}










