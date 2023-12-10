#include "driver/gpio.h"

#define GPIO_OUTPUT_IO GPIO_NUM_2

uint32_t level = 0;

esp_err_t outlet_init()
{
    gpio_config_t io_conf = {};

    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = 1ULL << GPIO_OUTPUT_IO;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

    gpio_config(&io_conf);
}

uint32_t outlet_value_read()
{
    return level;
}

esp_err_t outlet_value_write_on()
{
    level = 1;

    return gpio_set_level(GPIO_OUTPUT_IO, level);
}

esp_err_t outlet_value_write_off()
{
    level = 0;

    return gpio_set_level(GPIO_OUTPUT_IO, level);
}

esp_err_t outlet_value_write_toggle()
{
    level = !level;

    return gpio_set_level(GPIO_OUTPUT_IO, level);
}