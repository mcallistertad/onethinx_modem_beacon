/*
 * BLE_Task.c
 *
 *  Created on: 8 Mar 2020
 *      Author: tadmcallister
 */

/* Header file includes */
#include <math.h>
#include "stdio.h"
#include "BLE_task.h"
#include "LED_Task.h"

/***************************************
*       Function Prototypes
***************************************/
void BleFindMe_Init(void);
void BleFindMe_Process(void);
void StackEventHandler(uint32 event, void* eventParam);
void IasEventHandler(uint32 event, void* eventParam);

/*******************************************************************************
* Variables to keep track of BLE connection handle
*******************************************************************************/
cy_stc_ble_conn_handle_t    appConnHandle;

/* IAS alert level value. This value is picked up in the main execution loop
   for driving the alert (Blue) LED. */
uint8 alertLevel = 0;
uint8 handler_cnt = 0;
bool handler_flag = false;
bool tog_once = false;


/* BLESS ISR config for CM4 only */
cy_stc_sysint_t blessIsrCfg =
{
        /* The BLESS interrupt */
        .intrSrc = bless_interrupt_IRQn,

        /* The interrupt priority number */
        .intrPriority = 1u
};


/*******************************************************************************
* Function Name: BlessInterrupt
****************************************************************************/
static void BlessInterrupt(void)
{
    /* Call interrupt processing */
    Cy_BLE_BlessIsrHandler();
}



/*******************************************************************************
* Function Name: BleFindMe_Init()
*******************************************************************************/
void BleFindMe_Init(void)
{
    cy_en_ble_api_result_t          apiResult;
    cy_stc_ble_stack_lib_version_t  stackVersion;

    /* Hook interrupt service routines for BLESS */
    (void) Cy_SysInt_Init(&blessIsrCfg, &BlessInterrupt);

    /* Store pointer to blessIsrCfg in BLE configuration structure */
    cy_ble_config.hw->blessIsrConfig = &blessIsrCfg;

    /* Register the generic event handler */
    Cy_BLE_RegisterEventCallback(StackEventHandler);

    /* Initialize the BLE host */
    apiResult = Cy_BLE_Init(&cy_ble_config);

    if(apiResult != CY_BLE_SUCCESS)
    {
        /* BLE stack initialization failed, check configuration,
           notify error and halt CPU in debug mode */

    }
    else
    {
    		/* Init Successful */
    }

    /* Enable BLE */
    apiResult = Cy_BLE_Enable();

    if(apiResult != CY_BLE_SUCCESS)
    {
        /* BLE stack initialization failed, check configuration,
           notify error and halt CPU in debug mode */
    }
    else
    {
        /* success */
    }

    /* Enable BLE Low Power Mode (LPM) */
    // Cy_BLE_EnableLowPowerMode();

    /* get BLE stack version */
    apiResult = Cy_BLE_GetStackLibraryVersion(&stackVersion);
    if(apiResult != CY_BLE_SUCCESS)
    {
        // DEBUG_PRINTF("Cy_BLE_GetStackLibraryVersion API Error: 0x%2.2x \r\n", apiResult);
    }
    else
    {
        // DEBUG_PRINTF("Stack Version: %d.%d.%d.%d \r\n", stackVersion.majorVersion,
        // stackVersion.minorVersion, stackVersion.patch, stackVersion.buildNumber);
    }

    /* Register IAS event handler */
    Cy_BLE_IAS_RegisterAttrCallback(IasEventHandler);

}

/*******************************************************************************
* Function Name: BleFindMe_Process()
********************************************************************************
*
* Summary:
*   This function processes the BLE events and configures the device to enter
*   low power mode as required.
*
* Parameters:
*  None
*
* Return:
*   None
*
*******************************************************************************/
void BleFindMe_Process(void)
{
    status_led_data_t   statusLedData;
    BaseType_t rtosApiResult;

    /* Cy_Ble_ProcessEvents() allows BLE stack to process pending events */
    Cy_BLE_ProcessEvents();

    /* Update Alert Level value on the R LED */
    switch(alertLevel)
    {
        case CY_BLE_NO_ALERT:
            /* turn the LED OFF in case of no alert */
            statusLedData.orangeLed = LED_TURN_OFF;
            /* reset tog */
            tog_once = false;
            break;

        case CY_BLE_MILD_ALERT:
        		/* toggle the LED in case of mild alert */
        		if (!tog_once) {
        			statusLedData.orangeLed = LED_TOGGLE_EN;
        		}
        		/* set tog so toggle state not overwritten on iteration */
        		tog_once = true;
            break;

        case CY_BLE_HIGH_ALERT:
            /* turn the LED ON in case of high alert */
            statusLedData.orangeLed = LED_TURN_ON;
            /* reset tog */
            tog_once = false;
            break;

        /* Do nothing in all other cases */
        default:
            break;
    }
    /* send LED data to queue */
    rtosApiResult = xQueueSend(statusLedDataQ, &statusLedData,0u);
}

/*******************************************************************************
* Function Name: StackEventHandler()
********************************************************************************
*
* Summary:
*   This is an event callback function to receive events from the BLE Component.
*
* Parameters:
*  uint32 event:      event from the BLE component
*  void* eventParam:  parameters related to the event
*
* Return:
*   None
*
*******************************************************************************/
void StackEventHandler(uint32 event, void* eventParam)
{
    status_led_data_t   statusLedData;
    BaseType_t rtosApiResult;
    cy_en_ble_api_result_t      apiResult;
    uint8 i;

    switch (event)
	{
        /* There are some events generated by the BLE component
        *  that are not required for this code example. */

        /**********************************************************
        *                       General Events
        ***********************************************************/
		/* This event is received when the BLE stack is started */
        case CY_BLE_EVT_STACK_ON:

            /* Enter into discoverable mode so that remote device can search it */
            apiResult = Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            if(apiResult != CY_BLE_SUCCESS)
            {
                //DEBUG_PRINTF("Start Advertisement API Error: %d \r\n", apiResult);
                /* Execution does not continue beyond this point */
            }
            else
            {
                //DEBUG_PRINTF("Start Advertisement API Success: %d \r\n", apiResult);
                statusLedData.redLed = LED_TURN_ON;
                alertLevel = CY_BLE_NO_ALERT;
            }

            /* Get address of the device */
            apiResult = Cy_BLE_GAP_GetBdAddress();
            if(apiResult != CY_BLE_SUCCESS)
            {
                //DEBUG_PRINTF("Cy_BLE_GAP_GetBdAddress API Error: %d \r\n", apiResult);
            }
            else
            {
                //DEBUG_PRINTF("Cy_BLE_GAP_GetBdAddress API Success: %d \r\n", apiResult);
            }

            break;

        /* This event is received when there is a timeout */
        case CY_BLE_EVT_TIMEOUT:
            break;

        /* This event indicates that some internal HW error has occurred */
		case CY_BLE_EVT_HARDWARE_ERROR:
			break;

        /*  This event will be triggered by host stack if BLE stack is busy or
         *  not busy. Parameter corresponding to this event will be the state
    	 	 *  of BLE stack.
         *  BLE stack busy = CYBLE_STACK_STATE_BUSY,
    	 	 *  BLE stack not busy = CYBLE_STACK_STATE_FREE
         */
    	case CY_BLE_EVT_STACK_BUSY_STATUS:
            //DEBUG_PRINTF("CY_BLE_EVT_STACK_BUSY_STATUS: %x\r\n", *(uint8 *)eventParam);
            break;

        /* This event indicates completion of Set LE event mask */
        case CY_BLE_EVT_LE_SET_EVENT_MASK_COMPLETE:
            //DEBUG_PRINTF("CY_BLE_EVT_LE_SET_EVENT_MASK_COMPLETE \r\n");

            break;

        /* This event indicates set device address command completed */
        case CY_BLE_EVT_SET_DEVICE_ADDR_COMPLETE:
            //DEBUG_PRINTF("CY_BLE_EVT_SET_DEVICE_ADDR_COMPLETE \r\n");
            break;

        /* This event indicates get device address command completed
           successfully */
        case CY_BLE_EVT_GET_DEVICE_ADDR_COMPLETE:
            //DEBUG_PRINTF("CY_BLE_EVT_GET_DEVICE_ADDR_COMPLETE: ");
            for(i = CY_BLE_GAP_BD_ADDR_SIZE; i > 0u; i--)
            {
                //DEBUG_PRINTF("%2.2x", ((cy_stc_ble_bd_addrs_t *)((cy_stc_ble_events_param_generic_t *)eventParam)->eventParams)->publicBdAddr[i-1]);
            }
            break;

        /* This event indicates set Tx Power command completed */
        case CY_BLE_EVT_SET_TX_PWR_COMPLETE:
            //DEBUG_PRINTF("CY_BLE_EVT_SET_TX_PWR_COMPLETE \r\n");
            break;

        /* This event indicates that stack shutdown is complete */
        case CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE:
            /* Code execution will not reach here */
            /* Device wakes up from hibernate and performs reset sequence
               when the reset switch or SW2 switch on the kit is pressed */
            break;

        /**********************************************************
        *                       GAP Events
        ***********************************************************/

        /* This event indicates peripheral device has started/stopped
           advertising */
        case CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP:

            if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_ADVERTISING)
            {
                /* advertisement started */
                statusLedData.redLed = LED_TURN_ON;
            }
            else if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_STOPPED)
            {
                /* advertisement stopped */
                statusLedData.redLed = LED_TURN_OFF;
            }
            break;

        /* This event is generated at the GAP Peripheral end after connection
           is completed with peer Central device */
        case CY_BLE_EVT_GAP_DEVICE_CONNECTED:
            break;

        /* This event is generated when disconnected from remote device or
           failed to establish connection */
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            if(Cy_BLE_GetConnectionState(appConnHandle) == CY_BLE_CONN_STATE_DISCONNECTED)
            {
                alertLevel = CY_BLE_NO_ALERT;
                // statusLedData.redLed = LED_TURN_OFF;

                /* Enter into discoverable mode so that remote device can search it */
                apiResult = Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
                if(apiResult != CY_BLE_SUCCESS)
                {
                    //DEBUG_PRINTF("Start Advertisement API Error: %d \r\n", apiResult);
                    /* Execution does not continue beyond this point */
                }
                else
                {
                    //DEBUG_PRINTF("Start Advertisement API Success: %d \r\n", apiResult);
                    statusLedData.redLed = LED_TURN_ON;
                }

            }
            break;

        /* This event is generated at the GAP Central and the peripheral end
           after connection parameter update is requested from the host to
           the controller */
        case CY_BLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE:
            break;

        /* This event is triggered instead of 'CY_BLE_EVT_GAP_DEVICE_CONNECTED',
           if Link Layer Privacy is enabled in component customizer */
        case CY_BLE_EVT_GAP_ENHANCE_CONN_COMPLETE:

            /* BLE link is established */
            /* This event will be triggered since link layer privacy is enabled */
            if(Cy_BLE_GetState() == CY_BLE_STATE_ON)
            {
                statusLedData.redLed = LED_TURN_OFF;
            }
            break;

        /**********************************************************
        *                       GATT Events
        ***********************************************************/

        /* This event is generated at the GAP Peripheral end after connection
           is completed with peer Central device */
        case CY_BLE_EVT_GATT_CONNECT_IND:
            appConnHandle = *(cy_stc_ble_conn_handle_t *)eventParam;
            break;

        /* This event is generated at the GAP Peripheral end after
           disconnection */
        case CY_BLE_EVT_GATT_DISCONNECT_IND:
            break;

        /* This event is triggered when 'GATT MTU Exchange Request'
           received from GATT client device */
        case CY_BLE_EVT_GATTS_XCNHG_MTU_REQ:
            break;

        /* This event is triggered when a read received from GATT
           client device */
        case CY_BLE_EVT_GATTS_READ_CHAR_VAL_ACCESS_REQ:
            break;

        /**********************************************************
        *                       Other Events
        ***********************************************************/
        default:
        		break;
	}

    /* send StackEventHandler LED data to queue */
    rtosApiResult = xQueueSend(statusLedDataQ, &statusLedData,0u);
}

/*******************************************************************************
* Function Name: IasEventHandler
********************************************************************************
*
* Summary:
*  This is an event callback function to receive events from the BLE Component,
*  which are specific to Immediate Alert Service.
*
* Parameters:
*  uint32 event:      event from the BLE component
*  void* eventParams: parameters related to the event
*
* Return:
*  None
*
*******************************************************************************/
void IasEventHandler(uint32 event, void *eventParam)
{
    /* Alert Level Characteristic write event */
    if(event == CY_BLE_EVT_IASS_WRITE_CHAR_CMD)
    {
        /* Read the updated Alert Level value from the GATT database */
        Cy_BLE_IASS_GetCharacteristicValue(CY_BLE_IAS_ALERT_LEVEL,
            sizeof(alertLevel), &alertLevel);
    }
}

void BLE_TASK(void *pvParameters)
{

	/* bluetooth init */
	BleFindMe_Init();

	for (;;)
	{
		BleFindMe_Process();
		taskYIELD();
	}
}

/* [] END OF FILE */
