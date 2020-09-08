

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "Tasks_interface.h"
#include "Task_priority.h"


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

	xTaskCreate(vBlink200_Handler  ,"Blink_200_ms"  ,500,NULL ,TASK1_PRIORITY,&xTaskHandle1) ;
	xTaskCreate(vBlink1000_Handler ,"Blink_1000_ms" ,500,NULL ,TASK2_PRIORITY,&xTaskHandle2) ;

	vTaskStartScheduler() ;


	while (1)
	{

	}

return 0 ;
}









