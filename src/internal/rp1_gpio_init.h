/**
 *  @file rp1_gpio.h
 *
 * @brief Header file for gpio, roi and pads register control.
 *
 * @copyright Copyrigh (c) 2026 Zakaris Keszthelyi. All rights reserved.
 *
 */  
       

#ifndef RP1_GPIO_H
#define RP1_GPIO_H
#include <stdio.h>
#include "registers.h"
#include "gpio_types.h"
#include "rp1_init.h"

typedef enum{
	GPIO0,
	GPIO1,
	GPIO2,
	GPIO3,
	GPIO4,
	GPIO5,
	GPIO6,
	GPIO7,
	GPIO8,
	GPIO9,
	GPIO10,
	GPIO11,
	GPIO12,
	GPIO13,
	GPIO14,
	GPIO15,
	GPIO16,
	GPIO17,
	GPIO18,
	GPIO19,
	GPIO20,
	GPIO21,
	GPIO22,
	GPIO23,
	GPIO24,
	GPIO25,
	GPIO26,
	GPIO27
}rp1_gpio_select_t;

typedef struct{
	volatile rp1_gpio_ctrl_reg_t* GPIO_CTRL;
	volatile rp1_gpio_status_reg_t* GPIO_STATUS;
	volatile rp1_pads_ctrl_reg_t* PAD_REG;
	uint32_t rio_pin_mask;
}gpio_handle_t;

typedef struct{
    volatile uintptr_t rio_out;
    volatile uintptr_t rio_oe;
    volatile uintptr_t rio_in;
}rio_handle_t;

rp1_pads_voltage_select_reg_t pads_voltage_select;

extern rio_handle_t rio_handle;
extern rp1_pads_voltage_select_reg_t pads_voltage_select;

int rp1_gpio_init(rp1_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel);
int rp1_gpio_close(gpio_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel);


#endif /* RP1_GPIO_H */
