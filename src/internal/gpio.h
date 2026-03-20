/**
 *  @file gpio.h
 *
 * @brief GPIO register mapping and state enums.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 *
 */

#ifndef GPIO_H
#define GPIO_H

#include "rp1_gpio_init.h"

typedef enum{
    RP1_GPIO_IRQOVERRIDE_DEF,
    RP1_GPIO_IRQOVERRIDE_INV,
    RP1_GPIO_IRQOVERRIDE_LOW,
    RP1_GPIO_IRQOVERRIDE_HIGH
}rp1_gpio_irqoverride_t;

typedef enum{
    RP1_GPIO_IRQRESET_NONE,
    RP1_GPIO_IRQRESET_RESET
}rp1_gpio_irqreset_t;

typedef enum{
    RP1_GPIO_OEOVERRIDE_DEF,
    RP1_GPIO_OEOVERRIDE_INV_DEF,
    RP1_GPIO_OEOVERRIDE_DIS,
    RP1_GPIO_OEOVERRIDE_EN
}rp1_gpio_oeoverride_t;

typedef enum{
    RP1_GPIO_INOVERRIDE_DEF,
    RP1_GPIO_INOVERRIDE_INV_DEF,
    RP1_GPIO_INOVERRIDE_LOW,
    RP1_GPIO_INOVERRIDE_HIGH
}rp1_gpio_inoverride_t;

typedef enum{
    RP1_GPIO_OUTOVERRIDE_DEF,
    RP1_GPIO_OUTOVERRIDE_INV_DEF,
    RP1_GPIO_OUTOVERRIDE_LOW,
    RP1_GPIO_OUTOVERRIDE_HIGH
}rp1_gpio_outoverride_t;

typedef enum{
    RP1_GPIO_FUNCSEL_ALT0,
    RP1_GPIO_FUNCSEL_ALT1,
    RP1_GPIO_FUNCSEL_ALT2,
    RP1_GPIO_FUNCSEL_ALT3,
    RP1_GPIO_FUNCSEL_ALT4,
    RP1_GPIO_FUNCSEL_ALT5,
    RP1_GPIO_FUNCSEL_ALT6,
    RP1_GPIO_FUNCSEL_ALT7,
    RP1_GPIO_FUNCSEL_ALT8
}rp1_gpio_funcsel_t;



void gpio_func_select(gpio_handle_t* handle, rp1_gpio_funcsel_t sel);
void gpio_set_irqoverride(gpio_handle_t* handle, rp1_gpio_irqoverride_t state);
void gpio_set_irqreset(gpio_handle_t* handle, rp1_gpio_irqreset_t state);
void gpio_set_oeoverride(gpio_handle_t* handle, rp1_gpio_oeoverride_t state);
void gpio_set_inoverride(gpio_handle_t* handle, rp1_gpio_inoverride_t state);
void gpio_set_outoverride(gpio_handle_t* handle, rp1_gpio_outoverride_t state);

void rio_set_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_set_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_set_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_clr_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_clr_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_clr_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_xor_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_xor_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
void rio_xor_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle);
#endif /* GPIO_H */
