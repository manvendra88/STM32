/*
 * stm32f42901.h
 *
 *  Created on: 19-Aug-2019
 *      Author: Manu
 */

#include <stdint.h>

#ifndef INC_STM32F42901_H_
#define INC_STM32F42901_H_

#define __vo volatile

/*Defining base addresses of FLASH and SRAM Memories*/

#define FLASH_BASEADDR 0x8000000U					//FLASH->!28 KB
#define SRAM1_BASEADDR  0x20000000U
#define SRAM SRAM1_BASEADDR							//SRAM1->112 KB
#define SRAM2_BASEADDR 0x2001C000U					//SRAM2->16 KB, it could also be calculated as 0x20000000 + 128 KB (128*1024 in hex C000)
#define ROM_BASEADDR 0x1FFF0000U  					//ROM->30 KB


/*Defining base addresses of AHBx and ABPx buses*/

#define PERIPH_BASE  0x40000000
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE 0x40001000
#define AHB1PERIPH_BASE 0x40002000
#define AHB2PERIPH_BASE 0x50000000

/*Defining base addresses of Peripherals */
#define GPIOA_BASEADDR   (AHB1PERIPH_BASE + 0x0000)		// AHB1PERIPH_BASE + OFFSET (which is 0 as it is the first peripheral hanging to AHB1)
#define GPIOB_BASEADDR 	 (AHB1PERIPH_BASE + 0x0400)		// We aren't uses any prefixes for this layer like DRV_BASEADDRESS because the project is small and the probability of two macros with the defination are not found
#define GPIOC_BASEADDR   (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR 	 (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR   (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR 	 (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR   (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR 	 (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR 	 (AHB1PERIPH_BASE + 0x1C00)
#define RCC_BASEADDR	 (AHB1PERIPH_BASE + 0x2000)


/*Defining base addresses of Peripherals on APB1 */
#define I2C1_BASEADDR 	 (APB1PERIPH_BASE+ 0x5400)
#define I2C2_BASEADDR 	 (APB1PERIPH_BASE+ 0x5800)
#define I2C3_BASEADDR 	 (APB1PERIPH_BASE+ 0x5C00)
#define SPI2_BASEADDR 	 (APB1PERIPH_BASE+ 0x3800)
#define SPI3_BASEADDR 	 (APB1PERIPH_BASE+ 0x3C00)
#define USART2_BASEADDR  (APB1PERIPH_BASE+ 0x4400)
#define USART3_BASEADDR  (APB1PERIPH_BASE+ 0x4800)
#define UART4_BASEADDR   (APB1PERIPH_BASE+ 0x4C00)
#define UART5_BASEADDR 	 (APB1PERIPH_BASE+ 0x5000)		//Difference in USART and UART is USART supports Synch comm and UART can't produce serial clock.

/*Defining base addresses of Peripherals on APB2 */
#define EXT1_BASEADDR 	 (APB2PERIPH_BASE+ 0x3C00)
#define SPI1_BASEADDR 	 (APB2PERIPH_BASE+ 0x33FF)
#define USART1_BASEADDR  (APB1PERIPH_BASE+ 0x1000)
#define USART6_BASEADDR  (APB1PERIPH_BASE+ 0x1400)
#define SYSCFG_BASEADDR  (APB1PERIPH_BASE+ 0x3800)


/*Defining specific register base addresses */

typedef struct {
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
} GPIO_RegDef_t;




/*
 * peripheral register definition structure for RCC
 */
typedef struct
{
  __vo uint32_t CR;            /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t CFGR;          /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t CIR;           /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /*!< TODO,     										Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                       */
  __vo uint32_t APB1RSTR;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /*!< TODO,     										Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  __vo uint32_t AHB1ENR;       /*!< TODO,     										Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /*!< TODO,     										Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /*!< TODO,     										Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                       */
  __vo uint32_t APB1ENR;       /*!< TODO,     										Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /*!< TODO,     										Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  __vo uint32_t AHB1LPENR;     /*!< TODO,     										Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /*!< TODO,     										Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /*!< TODO,     										Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                       */
  __vo uint32_t APB1LPENR;     /*!< TODO,     										Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /*!< RTODO,     										Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                  */
  __vo uint32_t BDCR;          /*!< TODO,     										Address offset: 0x70 */
  __vo uint32_t CSR;           /*!< TODO,     										Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                  */
  __vo uint32_t SSCGR;         /*!< TODO,     										Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /*!< TODO,     										Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /*!< TODO,     										Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /*!< TODO,     										Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /*!< TODO,     										Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /*!< TODO,     										Address offset: 0x94 */

} RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__vo uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	__vo uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	__vo uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	__vo uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	__vo uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */

}EXTI_RegDef_t;


/*
 * peripheral register definition structure for SPI
 */
typedef struct
{
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	__vo uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	__vo uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;


/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP;       /*!< Give a short description,                    Address offset: 0x00      */
	__vo uint32_t PMC;          /*!< TODO,     									  Address offset: 0x04      */
	__vo uint32_t EXTICR[4];    /*!< TODO , 									  Address offset: 0x08-0x14 */
	uint32_t      RESERVED1[2];  /*!< TODO          							  Reserved, 0x18-0x1C    	*/
	__vo uint32_t CMPCR;        /*!< TODO         								  Address offset: 0x20      */
	uint32_t      RESERVED2[2];  /*!<                                             Reserved, 0x24-0x28 	    */
	__vo uint32_t CFGR;         /*!< TODO                                         Address offset: 0x2C   	*/
} SYSCFG_RegDef_t;


/*
 * peripheral register definition structure for I2C
 */
typedef struct
{
  __vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;

/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
} USART_RegDef_t;


/*Peripheral definitions (Peripheral base addresses type-casted to xxx_RegDef_t */

# define GPIOA  ((GPIO_RegDef_t*)GPIOA_BASEADDR) 		//GPIO_RegDef_t *pGPIO = (GPIO_RegDef_t*)GPIOA_BASEADDR; //pGPIO is a pointer that holds the address of type GPIO_Reg_Def_t, so we are type-casting the value 0x40020000 which is nothing but Instead, we just define a MACRO GPIOA = (GPIO_RegDef_t*)GPIOA_BASEADDR and use this pointer to make a pointer var of GPIO_RegDef_t later.
# define GPIOB  ((GPIO_RegDef_t*)GPIOB_BASEADDR)
# define GPIOC  ((GPIO_RegDef_t*)GPIOC_BASEADDR)
# define GPIOD  ((GPIO_RegDef_t*)GPIOD_BASEADDR)
# define GPIOE  ((GPIO_RegDef_t*)GPIOE_BASEADDR)
# define GPIOF  ((GPIO_RegDef_t*)GPIOF_BASEADDR)
# define GPIOG  ((GPIO_RegDef_t*)GPIOG_BASEADDR)
# define GPIOH  ((GPIO_RegDef_t*)GPIOH_BASEADDR)
# define GPIOI  ((GPIO_RegDef_t*)GPIOI_BASEADDR)

# define RCC  				((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1  				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  				((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1  			((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASEADDR)


/*Clock enable MARCOS for GPIOx peripherals*/

#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |=(1<<0)) 			//RCC is a RCC_RegDef_t type, dereferenced to the AHB1ENR and is ORED with left bit shift at 0th position because it corresponds to GPIOA
#define GPIOB_PCLK_EN()		RCC->AHB1ENR |=(1<<1)			// 1 because i want to make 1th bit to be 1
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))

/*Clock enable MARCOS for I2C peripherals*/
#define I2C1_PCLK_EN()	RCC->APB1ENR |=(1<<21)
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))


/*Clock enable MARCOS for SPI peripherals*/
#define SP1_PCLK_EN()	RCC->APB2ENR |=(1<<12)
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/*Clock disable MARCOS for GPIOx peripherals*/
#define GPIOA_PCLK_DI()	RCC->AHB1ENR &= ~(1<<0)			//To reset the bit by negative the set bit at 0th position and then ANDing it

/*MACROS to reset the peripherals */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)
/*Some common MACROS that can be used by many drivers
 *
 */
#define ENABLE 		1
#define DISABLE 	0
#define SET 		ENABLE
#define RESET 		DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET



#include "stm32f42901_gpio.h"







#endif /* INC_STM32F42901_H_ */
