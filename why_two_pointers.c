void GPIOD_SetPin(uint8_t pin) {
    GPIOD->BSRR |= (1 << pin);
}
versus

void GPIO_SetPin(GPIO_Typedef *gpio, uint8_t pin) {
    gpio->BSRR |= (1 << pin);
}

//The first one restricts it's usage to a single peripheral. The latter is more generic, any can be used with any GPIO port.
