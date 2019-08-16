#include <stdio.h>
#include <stdint.h>
 
typedef struct {
        uint32_t MODER;
        uint32_t OTYPER;
} GPIO_TypeDef;
 
#define GPIOA ((GPIO_TypeDef *) 0x40020000U)
 
int main(void) {
        printf("GPIOA_MODER location: %p \n", &(GPIOA->MODER));
        printf("GPIOA_OTYPER location: %p \n", &(GPIOA->OTYPER));
        return 0;
}
Output:
GPIOA_MODER location: 0x40020000 
GPIOA_OTYPER location: 0x40020004 
