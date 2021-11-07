#ifndef LED_H
#define LED_H

#include "nrf_delay.h"
#include "boards.h"
#include "nrf_gpio.h"

#define COUNT_BLINKY        {6, 5, 8, 0}
#define TIME_ACTION_LED     500000 //500mc time delay
#define TIME_DELAY_LED      500 //500mkc time delay

#define TIME_DELAY(delay)   ({              \
    nrf_delay_us(TIME_DELAY_LED);           \
    delay+=TIME_DELAY_LED;                  \
})

extern const int count_blinky[];

void led_blink_count(const uint32_t led_idx);

//for gpio
void gpio_leds_init(void);

void gpio_led_off(uint32_t led_idx);

void gpio_led_invert(uint32_t led_idx);

void gpio_led_blink_count(const uint32_t led_idx);

void gpio_leds_blink_count_if_pressed(void);

#endif // LED_H