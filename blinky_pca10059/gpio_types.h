#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#define LEDS_COUNT          4  
//gpio for LED
#define GPIO_LED1_G         NRF_GPIO_PIN_MAP(0, 6)
#define GPIO_LED2_R         NRF_GPIO_PIN_MAP(0, 8)
#define GPIO_LED2_G         NRF_GPIO_PIN_MAP(1, 9)
#define GPIO_LED2_B         NRF_GPIO_PIN_MAP(0, 12)

#define LIST_LEDS           {GPIO_LED1_G, GPIO_LED2_R, GPIO_LED2_G, GPIO_LED2_B}

extern const uint8_t gpio_led_list[LEDS_COUNT];

#endif // GPIO_TYPES_H