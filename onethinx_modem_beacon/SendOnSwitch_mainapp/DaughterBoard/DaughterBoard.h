#ifndef DEMOKIT01_H
#define DEMOKIT01_H	
 
#include <stdint.h>
#include <stdbool.h>

#define LED_OFF 0
#define LED_ON 1

#define LED_R1_SET(value)		Cy_GPIO_Write( P10_0_PORT, P10_0_PIN, value )
#define LED_R1_INV				Cy_GPIO_Inv( P10_0_PORT, P10_0_PIN )

#define LED_R2_SET(value)		Cy_GPIO_Write( P11_5_PORT, P11_5_PIN, value )
#define LED_R2_INV				Cy_GPIO_Inv( P11_5_PORT, P11_5_PIN )

#define LED_B_SET(value)			Cy_GPIO_Write( P11_7_PORT, P11_7_PIN, value )
#define LED_B_INV				Cy_GPIO_Inv( P11_7_PORT, P11_7_PIN )

#endif /* DEMOKIT01_H */

