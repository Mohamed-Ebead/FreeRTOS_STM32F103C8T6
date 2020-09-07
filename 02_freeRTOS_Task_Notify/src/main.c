

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "Tasks_interface.h"

#include "Led_interface.h"
#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"

#include "RCC_interface.h"




int main (void)
{
	RCC_voidInitSysClock() ;

	Button1_voidInit();
	RedLed_Init();

	xTaskCreate(vButton_Handler ,"ButtonCheckFlag" ,500,NULL ,2,&xTaskHandle1) ;
	xTaskCreate(vLed_Handler    ,"LedTakeAction"   ,500,NULL ,2,&xTaskHandle2) ;

	vTaskStartScheduler() ;


	while (1)
	{

	}

return 0 ;
}









