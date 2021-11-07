#include "button.h"
#include "gpio_types.h"

void gpio_buttons_init(void)
{
    nrf_gpio_cfg_input(GPIO_BUTTON, BUTTON_PULL);
    return;
}

bool gpio_button_state_get(void)
{
    bool state = nrf_gpio_pin_read(GPIO_BUTTON) ? true : false;
    return (state == false);
}