#include<stdint.h>        					//when you want to use uint8/32 keywords :)
#include "Board_LED.h"
#include "Board_Buttons.h"

void delay (void)
{
	uint32_t i;
	for (i=0; i<500000; i++);			// for loop for delay
}
int main (void)
{
	Buttons_Initialize();
	LED_Initialize();
	while (1)											// Don't forget that otherwise your program just execute once
	{
	if (Buttons_GetState()==1)
	{
	LED_On(1);
	delay();
	LED_Off(1);
	delay();
	}
	}	
	return 0;
}
