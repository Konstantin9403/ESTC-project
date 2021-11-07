#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "boards.h"

#include "led.h"
#include "button.h"

//init gpio LED and BUTTON
#define GPIO_INIT(init_flags) 

#define gpio_init(init_flags) ({                                \
    if (init_flags & BSP_INIT_LEDS)    { gpio_leds_init(); }    \
    if (init_flags & BSP_INIT_BUTTONS) { gpio_buttons_init(); } \
})

//LEDs
#define LEDS_COUNT          4  
//gpio for LED
#define GPIO_LED1_G         NRF_GPIO_PIN_MAP(0, 6)
#define GPIO_LED2_R         NRF_GPIO_PIN_MAP(0, 8)
#define GPIO_LED2_G         NRF_GPIO_PIN_MAP(1, 9)
#define GPIO_LED2_B         NRF_GPIO_PIN_MAP(0, 12)

#define LIST_LEDS           {GPIO_LED1_G, GPIO_LED2_R, GPIO_LED2_G, GPIO_LED2_B}

extern const uint8_t gpio_led_list[LEDS_COUNT];


//BUTTONs
#define BUTTONS_COUNT 1
//gpio for BUTTON
#define GPIO_BUTTON       NRF_GPIO_PIN_MAP(1,6)

#endif // GPIO_TYPES_H