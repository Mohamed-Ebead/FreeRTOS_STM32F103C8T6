/*
 * Tasks_interface.h
 *
 *  Created on: Sep 5, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TASKS_INTERFACE_H_
#define TASKS_INTERFACE_H_

/**-------------------------------------------------------------------------------------------------------**/

TaskHandle_t xTaskHandle1 = NULL ;
TaskHandle_t xTaskHandle2 = NULL ;


void RTOS_Delay_ms (u32 delay_in_ms) ;

void vBlink200_Handler     (void* params) ;
void vBlink1000_Handler    (void* params) ;

/**-------------------------------------------------------------------------------------------------------**/




#endif /* TASKS_INTERFACE_H_ */





