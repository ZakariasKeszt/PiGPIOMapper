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

typedef enum{
    RP1_RIO_OUT_LOW,
    RP1_RIO_OUT_HIGH
}rp1_rio_out_state_t;

typedef enum{
    RP1_RIO_OE_DISABLE,
    RP1_RIO_OE_ENABLE
}rp1_rio_oe_enable_t;

typedef enum{
    RP1_RIO_IN_DISABLE,
    RP1_RIO_IN_ENABLE
}rp1_rio_in_enable_t;

int gpio_func_select(gpio_handle_t* handle, rp1_gpio_funcsel_t sel);
int gpio_set_irqoverride(gpio_handle_t* handle, rp1_gpio_irqoverride_t state);
int gpio_set_irqreset(gpio_handle_t* handle, rp1_gpio_irqreset_t state);
int gpio_set_oeoverride(gpio_handle_t* handle, rp1_gpio_oeoverride_t state);
int gpio_set_inoverride(gpio_handle_t* handle, rp1_gpio_inoverride_t state);
int gpio_set_outoverride(gpio_handle_t* handle, rp1_gpio_outoverride_t state);

int rio_set_out_state(rio_handle_t* handle, rp1_rio_out_state_t state);
int rio_set_oe_state(rio_handle_t* handle, rp1_rio_oe_enable_t enable);
int rio_set_in_state(rio_handle_t* handle, rp1_rio_in_enable_t enable);
int rio_clr_out_state(rio_handle_t* handle, rp1_rio_out_state_t state);
int rio_clr_oe_state(rio_handle_t* handle, rp1_rio_oe_enable_t state);
int rio_clr_in_state(rio_handle_t* handle, rp1_rio_in_enable_t state);
int rio_xor_out_state(rio_handle_t* handle, rp1_rio_out_state_t state);
int rio_xor_oe_state(rio_handle_t* handle, rp1_rio_oe_enable_t state);
int rio_xor_in_state(rio_handle_t* handle, rp1_rio_in_enable_t state);

#endif /* GPIO_H */
