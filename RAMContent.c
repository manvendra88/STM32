#include<stdint.h>        					//when you want to use uint8/32 keywords :)
#include "Board_LED.h"						// Headers are compiled during Pre-Processor compilation
#include "Board_Buttons.h"					// They don't use RAM

void delay (void)						// Function lives in FLASH as it will be converted into instructions
{
	uint32_t i;					// Local Vars are stored in stack memory which is part of RAM
							// But stack doesn't grow or shrink when code is not running
							// It will only consume RAM during run time
	for (i=0; i<500000; i++);			// for loop for delay
}

void fun3 (void)
{
	void (*jumpaddr) (void) = 0x00000000;
	jumpaddr();
	// int *p represents a pointer variable that holds the address (pointer) of a variable which is intger type.
	// Similarly jumpaddr is a function pointer that holds the address of a function which doesn't take any
	// arguements nor does it take any return value. We have initalized this function pointer to some invalid address
	// We can also initialize it to &delay. And then, if we derefrence this pointer by calling jumpaddr()
	// Controls comes to the delay function. Since, we have assigned an invalid address, we will be trapped into 
	// We will be trapped in hard-fault-handeler.
}


void fun2 (void)
{
	fun3();
}


void fun1 (void)
{
	fun2();
}
int main (void)
{
//	Buttons_Initialize();
	LED_Initialize(); // In this function, all variables are local
	
//	fun1();
	while (1)											// Don't forget that otherwise your program just execute once
	{
//	if (Buttons_GetState()==1)
//	{
	LED_On(1);	// This function although contains global variable, they are constants that are stored in FLASH
	delay();
	LED_Off(1);
	delay();
//	}
	}	
	return 0;
}
