//Making HSE as SYSCLCK

#include <stdint.h>
#include "stm32f407xx.h"

int main ()
{
	//1. Turn on the HSE Oscillator
	RCC_TypeDef *pRCC;
	pRCC = RCC;
	
	pRCC->CR |= (1<<16);
	
	//2. Wait until the HSE becomes Stable, Crystal takes more time to settle
	while ( !(pRCC->CR & (1<<17))); //Until the RDY bit is 1
	
	
	pRCC->CFGR &= ~(0x03 << 0);
	pRCC->CFGR |= (0x1 << 0);
	

	
	
	//2. Select the HSE as SYSCLCK
	return 0;
}
}