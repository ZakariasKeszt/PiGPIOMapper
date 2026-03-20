/**
 *  @file rp1_gpio.h
 *
 * @brief Header file for gpio, roi and pads register control.
 *
 * @copyright Copyrigh (c) 2026 Zakaris Keszthelyi. All rights reserved.
 *
 */


#ifndef RP1_GPIO_INIT_H
#define RP1_GPIO_INIT_H

#include <stdio.h>
#include <stdlib.h>
#include "PiGPIOMapper.h"
#include "registers.h"
#include "gpio_types.h"
#include "rp1_init.h"


typedef struct gpio_handle_s{
	volatile rp1_gpio_ctrl_reg_t* GPIO_CTRL;
	volatile rp1_gpio_status_reg_t* GPIO_STATUS;
	volatile rp1_pads_ctrl_reg_t* PAD_REG;
	uint32_t rio_pin_mask;
}gpio_handle_t;

typedef struct rio_handle_s{
    volatile uint32_t* rio_out;
    volatile uint32_t* rio_oe;
    volatile uint32_t* rio_in;
}rio_handle_t;

extern rp1_pads_voltage_select_reg_t pads_voltage_select;
extern rio_handle_t rio_handle;

int rp1_gpio_init(rp1_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel);
int rp1_gpio_close(gpio_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel);


#endif /* RP1_GPIO_INIT_H */
