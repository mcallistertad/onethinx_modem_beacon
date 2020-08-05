/*
 * BLE_Task.h
 *
 *  Created on: 8 Mar 2020
 *      Author: tadmcallister
 */

#ifndef SOURCE_BLE_TASK_H_
#define SOURCE_BLE_TASK_H_

/* Header file includes */
#include "FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "timers.h"
#include "timers.h"
#include "cycfg_ble.h"
#include "stdio.h"

/* Semaphore that unblocks the BLE Task */
extern SemaphoreHandle_t  bleSemaphore;

/* Task_Ble takes care of the BLE module in this code example */
void BLE_TASK(void *pvParameters);

#endif /* SOURCE_BLE_TASK_H_ */
