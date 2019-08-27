/*
 * stm32f42901_gpio.h
 *
 *  Created on: 20-Aug-2019
 *      Author: Manu
 */

#ifndef SRC_STM32F42901_GPIO_H_
#define SRC_STM32F42901_GPIO_H_

#include"stm32f42901.h"

typedef struct
{

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			//Check its possible values from @GPIO_PIN_MODES
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx; 				// To get the base address of the GPIO
	GPIO_PinConfig_t GPIO_PinConfig; 	// To hold GPIO Pin configuration settings

}GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15


//GPIO pin handle modes
//@GPIO_PIN_MODES
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3


#define GPIO_MODE_IT_FT 4			//Falling edge trigger
#define GPIO_MODE_IT_RT 5			//Rising edge trigger
#define GPIO_MODE_IT_RFT 6			//Rising Falling edge trigger


/*
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1


/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3


/*
 * GPIO pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

//Under input mode itself, the gpio pin can get interrupts on rising or falling edge


/*******************************The driver supports the following APIs****************************/

/*Peripheral clock enable*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);  					//to enable/disable the peripheral //For a given GPIO base address, we are going to enable or disable the clock //En or Di for enabling and disabling the clock. Defined in the MCU Spec header file


/*Initialization*/
void GPIO_Init(GPIO_Handle_t *pGP);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);											//To send the register back to its reset state using RCC_PeripheralResetRegister by making its bit 1 for the corresponding peripheral

/*Read & Write */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);  								//16 because the port is 16 bit long
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value );
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*Interrupt*/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);			//Grouping can also be considered
void GPIO_IRQHandling(uint8_t PinNumber);




#endif /* SRC_STM32F42901_GPIO_H_ */
