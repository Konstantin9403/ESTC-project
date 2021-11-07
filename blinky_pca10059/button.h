#ifndef BUTTON_H
#define BUTTON_H

#include "nrf_gpio.h"

void gpio_buttons_init(void);

bool gpio_button_state_get(void);

#endif // BUTTON_H