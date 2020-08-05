/*******************************************************************************
* File Name: cycfg_pins.h
*
* Description:
* Pin configuration
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"
#include "cy_smartio.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ioss_0_port_0_pin_0_PORT GPIO_PRT0
#define ioss_0_port_0_pin_0_PIN 0U
#define ioss_0_port_0_pin_0_NUM 0U
#define ioss_0_port_0_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_0_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_0_HSIOM
	#define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_0_IRQ ioss_interrupts_gpio_0_IRQn
#define ioss_0_port_0_pin_1_PORT GPIO_PRT0
#define ioss_0_port_0_pin_1_PIN 1U
#define ioss_0_port_0_pin_1_NUM 1U
#define ioss_0_port_0_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_0_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_1_HSIOM
	#define ioss_0_port_0_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_1_IRQ ioss_interrupts_gpio_0_IRQn
#define ioss_0_port_0_pin_4_PORT GPIO_PRT0
#define ioss_0_port_0_pin_4_PIN 4U
#define ioss_0_port_0_pin_4_NUM 4U
#define ioss_0_port_0_pin_4_DRIVEMODE CY_GPIO_DM_PULLUP
#define ioss_0_port_0_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_4_HSIOM
	#define ioss_0_port_0_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_4_IRQ ioss_interrupts_gpio_0_IRQn
#define LED_R1_PORT GPIO_PRT10
#define LED_R1_PIN 0U
#define LED_R1_NUM 0U
#define LED_R1_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define LED_R1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_0_HSIOM
	#define ioss_0_port_10_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_R1_HSIOM ioss_0_port_10_pin_0_HSIOM
#define LED_R1_IRQ ioss_interrupts_gpio_10_IRQn
#define ioss_0_port_10_pin_1_PORT GPIO_PRT10
#define ioss_0_port_10_pin_1_PIN 1U
#define ioss_0_port_10_pin_1_NUM 1U
#define ioss_0_port_10_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_10_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_1_HSIOM
	#define ioss_0_port_10_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_1_IRQ ioss_interrupts_gpio_10_IRQn
#define LED_R2_PORT GPIO_PRT11
#define LED_R2_PIN 5U
#define LED_R2_NUM 5U
#define LED_R2_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define LED_R2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_11_pin_5_HSIOM
	#define ioss_0_port_11_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_R2_HSIOM ioss_0_port_11_pin_5_HSIOM
#define LED_R2_IRQ ioss_interrupts_gpio_11_IRQn
#define LED_B_PORT GPIO_PRT11
#define LED_B_PIN 7U
#define LED_B_NUM 7U
#define LED_B_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_B_INIT_DRIVESTATE 0
#ifndef ioss_0_port_11_pin_7_HSIOM
	#define ioss_0_port_11_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_B_HSIOM ioss_0_port_11_pin_7_HSIOM
#define LED_B_IRQ ioss_interrupts_gpio_11_IRQn
#define ioss_0_port_12_pin_4_PORT GPIO_PRT12
#define ioss_0_port_12_pin_4_PIN 4U
#define ioss_0_port_12_pin_4_NUM 4U
#define ioss_0_port_12_pin_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_12_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_4_HSIOM
	#define ioss_0_port_12_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_12_pin_4_IRQ ioss_interrupts_gpio_12_IRQn
#define ioss_0_port_12_pin_5_PORT GPIO_PRT12
#define ioss_0_port_12_pin_5_PIN 5U
#define ioss_0_port_12_pin_5_NUM 5U
#define ioss_0_port_12_pin_5_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_12_pin_5_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_5_HSIOM
	#define ioss_0_port_12_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_12_pin_5_IRQ ioss_interrupts_gpio_12_IRQn
#define ioss_0_port_1_pin_4_PORT GPIO_PRT1
#define ioss_0_port_1_pin_4_PIN 4U
#define ioss_0_port_1_pin_4_NUM 4U
#define ioss_0_port_1_pin_4_DRIVEMODE CY_GPIO_DM_PULLUP
#define ioss_0_port_1_pin_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_4_HSIOM
	#define ioss_0_port_1_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_1_pin_4_IRQ ioss_interrupts_gpio_1_IRQn
#define ioss_0_port_6_pin_0_PORT GPIO_PRT6
#define ioss_0_port_6_pin_0_PIN 0U
#define ioss_0_port_6_pin_0_NUM 0U
#define ioss_0_port_6_pin_0_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define ioss_0_port_6_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_0_HSIOM
	#define ioss_0_port_6_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_0_IRQ ioss_interrupts_gpio_6_IRQn
#define ioss_0_port_6_pin_1_PORT GPIO_PRT6
#define ioss_0_port_6_pin_1_PIN 1U
#define ioss_0_port_6_pin_1_NUM 1U
#define ioss_0_port_6_pin_1_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define ioss_0_port_6_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_1_HSIOM
	#define ioss_0_port_6_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_1_IRQ ioss_interrupts_gpio_6_IRQn
#define UART_RX_PORT GPIO_PRT9
#define UART_RX_PIN 0U
#define UART_RX_NUM 0U
#define UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_0_HSIOM
	#define ioss_0_port_9_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define UART_RX_HSIOM ioss_0_port_9_pin_0_HSIOM
#define UART_RX_IRQ ioss_interrupts_gpio_9_IRQn
#define UART_TX_PORT GPIO_PRT9
#define UART_TX_PIN 1U
#define UART_TX_NUM 1U
#define UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_1_HSIOM
	#define ioss_0_port_9_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define UART_TX_HSIOM ioss_0_port_9_pin_1_HSIOM
#define UART_TX_IRQ ioss_interrupts_gpio_9_IRQn
#define ioss_0_port_9_smartio_0_HW SMARTIO_PRT9

extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_0_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_1_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_4_config;
extern const cy_stc_gpio_pin_config_t LED_R1_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_1_config;
extern const cy_stc_gpio_pin_config_t LED_R2_config;
extern const cy_stc_gpio_pin_config_t LED_B_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_12_pin_4_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_12_pin_5_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_1_pin_4_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_0_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_1_config;
extern const cy_stc_gpio_pin_config_t UART_RX_config;
extern const cy_stc_gpio_pin_config_t UART_TX_config;
extern const cy_stc_smartio_config_t ioss_0_port_9_smartio_0_config;

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
