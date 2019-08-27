/*
 * stm32f4029_gpio.c
 *
 *  Created on: 20-Aug-2019
 *      Author: Manu
 */

#include"stm32f42901_gpio.h"


/*******************************The driver supports the following APIs****************************/


/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none
 */


/*Peripheral clock enable*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi) 					//to enable/disable the peripheral //For a given GPIO base address, we are going to enable or disable the clock //En or Di for enabling and disabling the clock. Defined in the MCU Spec header file
{
	if(EnorDi == ENABLE)
	{
				if(pGPIOx==GPIOA)				//If user wants to enable clock for GPIOA, then call this
				{
				GPIOA_PCLK_EN();
				}else if (pGPIOx == GPIOB)
				{
					GPIOB_PCLK_EN();
				}else if (pGPIOx == GPIOC)
				{
					GPIOC_PCLK_EN();
				}else if (pGPIOx == GPIOD)
				{
					GPIOD_PCLK_EN();
				}else if (pGPIOx == GPIOE)
				{
					GPIOE_PCLK_EN();
				}else if (pGPIOx == GPIOF)
				{
					GPIOF_PCLK_EN();
				}else if (pGPIOx == GPIOG)
				{
					GPIOG_PCLK_EN();
				}else if (pGPIOx == GPIOH)
				{
					GPIOH_PCLK_EN();
				}else if (pGPIOx == GPIOI)
				{
					GPIOI_PCLK_EN();
				}

	}
	else
	{
		/**Not doing it as of now **/
	}


}

/*Initialization*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	uint32_t temp=0;

	//1. Configure the mode
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
	//Non-interrupt zone
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->MODER &= ~ (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);	//to clear that pair of bits first, we need to AND it with negation of 11 shifted to that pinNumber
	pGPIOHandle->pGPIOx->MODER |= temp;		//bit-wise or because we don't want to change other bits of the moder reg

	}

	else
	{
	//Interrupt Zone - >later
	}

	temp=0;

	//2. Configure the speed
	temp=pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed);
	pGPIOHandle->pGPIOx->OSPEEDR &= ~ (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp=0;


	//3. Configure the pupd settings
	temp=pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed);
	pGPIOHandle->pGPIOx->PUPDR &= ~ (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp=0;


	//4. Configure the output type
	temp=pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType);
	pGPIOHandle->pGPIOx->OTYPER &= ~ (0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp=0;


	//5. Configure the alternate type
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1,temp2;
		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)/8;
		temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~ (0xF << (4*temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] = pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2);
	}


}

//To DeInit all register, we mean reset all the registers of a peripheral , we have to refer to the respective RCC Register
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)											//To send the register back to its reset state using RCC_PeripheralResetRegister by making its bit 1 for the corresponding peripheral
{
					if(pGPIOx==GPIOA)				//If user wants to enable clock for GPIOA, then call this
					{
						GPIOA_REG_RESET();
					}else if (pGPIOx == GPIOB)
					{
						GPIOB_REG_RESET();
					}else if (pGPIOx == GPIOC)
					{
						GPIOC_REG_RESET();
					}else if (pGPIOx == GPIOD)
					{
						GPIOD_REG_RESET();
					}else if (pGPIOx == GPIOE)
					{
						GPIOE_REG_RESET();
					}else if (pGPIOx == GPIOF)
					{
						GPIOF_REG_RESET();
					}else if (pGPIOx == GPIOG)
					{
						GPIOG_REG_RESET();
					}else if (pGPIOx == GPIOH)
					{
						GPIOH_PCLK_EN();
					}else if (pGPIOx == GPIOI)
					{
						GPIOI_REG_RESET();
					}

}

/*Read & Write */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
int8_t value;
//value = (pGPIOx->IDR >> PinNumber) &= (0x00000001); 		//From the whole GPIO-IDR register, we want to abstract the data of a certain pin, for that we first shift the whole register to the right for PinNumber times so that the concerened register comes to the zeroth position and then mask all the other bits by multiplying the whole thing with 0x00000001 so that the value becomes nothing but what is written in the unit digit which is nothing but what is the value of corresponding bit in the IDR Register
//uint8_t value;

value = (uint8_t )((pGPIOx->IDR  >> PinNumber) & 0x00000001 ) ;


return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) 								//16 because the port is 16 bit long
{
uint16_t value;
value = (uint16_t) pGPIOx->IDR ;								// Maybe, another uint16_t is written to convert pGPIOx->IDR to int
return value;

}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value )
{
	if(Value == GPIO_PIN_SET)
	{
	pGPIOx->ODR |= (1<<PinNumber);	//We need to write 1 to the PinNumber. For that go to ODR and register and OR that register with a number that has 1 shifted to the position equal to the pinnumber
	}
	else
	{
	pGPIOx->ODR &= ~(1<<PinNumber); //To write 0, negate the number and AND it with it.
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber); //Long form of which is : pGPIOx->ODR = pGPIOx->ODR ^= (1 << PinNumber); //If the pin number is 0 then xor will make it 1 and vice-versa
}

/*Interrupt*/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)			//Grouping can also be considered
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}

