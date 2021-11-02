#ifndef BLINKY_H
#define BLINKY_H

#include "nrf_delay.h"
#include "boards.h"

#define COUNT_BLINKY {6, 5, 8, 0}

extern const int count_blinky[];

void led_blink_count(const uint32_t led_idx);

#endif // BLINKY_H