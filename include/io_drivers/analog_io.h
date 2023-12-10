#include "driver/gpio.h"

#define RED GPIO_NUM_3
#define GREEN GPIO_NUM_5
#define BLUE GPIO_NUM_6

uint32_t red = 0;
uint32_t green = 0;
uint32_t blue = 0;

esp_err_t analog_io_init()
{
    gpio_config_t io_conf = {};

    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = 1ULL << RED;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

    if (gpio_config(&io_conf) == ESP_ERR_INVALID_ARG)
    {
        return ESP_ERR_INVALID_ARG;
    }

    io_conf.pin_bit_mask = 1ULL << GREEN;

    if (gpio_config(&io_conf) == ESP_ERR_INVALID_ARG)
    {
        return ESP_ERR_INVALID_ARG;
    }

    io_conf.pin_bit_mask = 1ULL << BLUE;

    return gpio_config(&io_conf);
}

uint32_t analog_io_value_read_red()
{
    return red;
}

uint32_t analog_io_value_read_green()
{
    return green;
}

uint32_t analog_io_value_read_blue()
{
    return blue;
}

esp_err_t analog_io_value_write_red(uint32_t value)
{
    if (value > 255)
    {
        return ESP_ERR_INVALID_ARG;
    }

    red = value;

    return gpio_set_level(RED, red);
}

esp_err_t analog_io_value_write_green(uint32_t value)
{
    if (value > 255)
    {
        return ESP_ERR_INVALID_ARG;
    }

    green = value;

    return gpio_set_level(GREEN, green);
}

esp_err_t analog_io_value_write_blue(uint32_t value)
{
    if (value > 255)
    {
        return ESP_ERR_INVALID_ARG;
    }

    blue = value;

    return gpio_set_level(BLUE, blue);
}