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


void vButton_Handler (void* params) ;
void vLed_Handler    (void* params) ;

/**-------------------------------------------------------------------------------------------------------**/

#endif /* TASKS_INTERFACE_H_ */
