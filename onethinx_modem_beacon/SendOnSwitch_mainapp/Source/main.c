/********************************************************************************
 *    ___             _   _     _			
 *   / _ \ _ __   ___| |_| |__ (_)_ __ __  __
 *  | | | | '_ \ / _ \ __| '_ \| | '_ \\ \/ /
 *  | |_| | | | |  __/ |_| | | | | | | |>  < 
 *   \___/|_| |_|\___|\__|_| |_|_|_| |_/_/\_\
 *
 ********************************************************************************
 *
 * Copyright (c) 2019 Onethinx BV <info@onethinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ********************************************************************************
 *
 * Created by: Rolf Nooteboom on 2019-08-03
 *
 * Library to use AT commands with the Onethinx Core LoRaWAN module
 * 
 * For a description please see:
 * https://github.com/onethinx/OT_ATCommandSet_VScode/blob/master/README.md
 *
 ********************************************************************************/

#include <limits.h>
#include "OnethinxCore01.h"
#include "ATinterface.h"
#include "cycfg.h"
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "LED_Task.h"
#include "BLE_Task.h"

#include "../DaughterBoard/DaughterBoard.h"


/* private definitions */
#define AT_PARSER_STACK_SIZE		(2048u)
#define BLE_TASK_STACK_SIZE		(2048u)
#define LED_TASK_STACK_SIZE		(2048u)
#define MON_TASK_STACK_SIZE		(512u)


/* queue length */
#define STATUS_LED_QUEUE_LEN		(5u)


/* private variables */
BaseType_t xReturned;
TaskHandle_t AT_PARSER_Handle = 	NULL;
TaskHandle_t MON_TASK_Handle = 	NULL;
TaskHandle_t LED_TASK_Handle = 	NULL;
TaskHandle_t BLE_TASK_Handle = 	NULL;


/* handle AT commands from UART */
void AT_PARSER(void *pvParameters)
{

	for(;;)
	{
		ATcomm();
		taskYIELD();
	}
}

/* monitor AT handler/ BLE beacon */
void MON_TASK(void *pvParameters)
{
	 /* Remove warning for unused parameter */
	 (void)pvParameters;

	status_led_data_t   statusLedData;
	BaseType_t rtosApiResult;

	/* enable WDT */
	//	Cy_WDT_Enable();

	for (;;)
	{
		/* toggle led */
		statusLedData.orangeLed = LED_TOGGLE_EN;
		rtosApiResult = xQueueSend(statusLedDataQ, &statusLedData,0u);
		vTaskDelay(2000);
	}
}

int main(void)
{
	/* only for debugging */
#ifdef DEBUG_TRUE
	CyDelay(1000);
#endif

	/* initialize hardware configuration */
	init_cycfg_all();
	
	/* enable global interrupts */
	__enable_irq();

	/* enable uart */
	Cy_SCB_UART_Init( UART_HW, &UART_config, NULL);
	Cy_SCB_UART_Enable( UART_HW );

    /* create the queues and semaphores */
	// bleSemaphore    = xSemaphoreCreateCounting(ULONG_MAX,0u);
	statusLedDataQ  = xQueueCreate(STATUS_LED_QUEUE_LEN, sizeof(status_led_data_t));

	/* create tasks */
	xReturned = xTaskCreate(MON_TASK, "MON_TASK", MON_TASK_STACK_SIZE, NULL, 2, &MON_TASK_Handle);
	xReturned = xTaskCreate(LED_TASK, "LED_TASK", LED_TASK_STACK_SIZE, NULL, 2, &LED_TASK_Handle);
	xReturned = xTaskCreate(AT_PARSER, "AT_PARSER", AT_PARSER_STACK_SIZE, NULL, 1, &AT_PARSER_Handle);
	xReturned = xTaskCreate(BLE_TASK, "BLE_TASK", BLE_TASK_STACK_SIZE, NULL, 1, &BLE_TASK_Handle);

	if( xReturned != pdPASS )
	    {
	        /* task wasn't created.  Use the task's handle to delete the task. */
	        vTaskDelete(AT_PARSER_Handle);

	        /* reset system */
	        NVIC_SystemReset();
	    }

	/* start scheduler */
	vTaskStartScheduler();

	/* reset system if exits scheduler */
	NVIC_SystemReset();

	for (;;)
	{
		NVIC_SystemReset();
	}

}


/* [] END OF FILE */
