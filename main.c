#include<stdint.h>

// FLASH Address = 0x80000000; RAM Address = 0x20000000
// Constant data is stored in Flash while Global variables (not const) in RAM


char const my_data[]= "I love Embedded Programming";

#define SRAM 0x20000000

int main (void)
{

	for(int i=0; i< sizeof(my_data) ; i++)
	{
		*((uint8_t *)SRAM +i )= my_data[i];
	}
	
	return 0;
}
