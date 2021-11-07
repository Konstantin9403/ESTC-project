#include "led.h"
#include "button.h"
#include "gpio_types.h"

const int count_blinky[] = COUNT_BLINKY;
const uint8_t gpio_led_list[LEDS_COUNT] = LIST_LEDS;

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

void gpio_leds_init(void)
{
    for (uint32_t i = 0; i < LEDS_COUNT; i++)
    {
        nrf_gpio_cfg_output(gpio_led_list[i]);
        gpio_led_off(i);
    }

    return;
}

void gpio_led_off(uint32_t led_idx)
{
    ASSERT(led_idx < LEDS_NUMBER);
    nrf_gpio_pin_write(gpio_led_list[led_idx], 1);
    return;
}

void gpio_led_on(uint32_t led_idx)
{
    ASSERT(led_idx < LEDS_NUMBER);
    nrf_gpio_pin_write(gpio_led_list[led_idx], 0);
    return;
}

void gpio_led_invert(uint32_t led_idx)
{
    ASSERT(led_idx < LEDS_NUMBER);
    nrf_gpio_pin_toggle(gpio_led_list[led_idx]);
    return;
}

void gpio_led_blink_count(const uint32_t led_idx)
{
    uint32_t count = count_blinky[led_idx] * 2;
    for (uint32_t i = 0; i < count; i++)
    {
        gpio_led_invert(led_idx);
        nrf_delay_ms(500);
    }
    return;
}

void gpio_leds_blink_count_if_pressed(void)
{
    static uint32_t blink_count = 0;
    static uint32_t led_idx = 0;
    static uint32_t led_time = TIME_ACTION_LED; //500mc

    if (!gpio_button_state_get())
        return;

    if (led_time < TIME_ACTION_LED)
    {
        TIME_DELAY(led_time);
        return;
    }

    if (blink_count < count_blinky[led_idx] * 2)
    {
        gpio_led_invert(led_idx);
        led_time = 0;
        blink_count++;
    }

    //increment led_idx
    if (blink_count == count_blinky[led_idx] * 2)
    {
        blink_count = 0;
        if (led_idx < LEDS_NUMBER - 1)
            led_idx++;
        else
            led_idx = 0;
    }

    return;
}
