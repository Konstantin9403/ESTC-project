#include "blinky.h"

const int count_blinky[] = COUNT_BLINKY;

void led_blink_count(const uint32_t led_idx)
{
    uint32_t count = count_blinky[led_idx] * 2;
    for (uint32_t i = 0; i < count; i++)
    {
        bsp_board_led_invert(led_idx);
        nrf_delay_ms(500);
    }
    return;
}