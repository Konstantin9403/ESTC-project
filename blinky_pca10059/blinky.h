#ifndef BLINKY_H
#define BLINKY_H

#include "nrf_delay.h"
#include "boards.h"
#include "nrf_gpio.h"

#include "gpio_types.h"

#define COUNT_BLINKY {6, 5, 8, 0}

extern const int count_blinky[];

void led_blink_count(const uint32_t led_idx);

//for gpio
void gpio_leds_init(void);

void gpio_led_off(uint32_t led_idx);

void gpio_led_invert(uint32_t led_idx);

void gpio_led_blink_count(const uint32_t led_idx);

#endif // BLINKY_H