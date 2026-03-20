/**
 *  @file pads.h
 *
 * @brief PADS register mapping and state enums.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 *
 */

#ifndef PADS_H
#define PADS_H

#include "rp1_gpio_init.h"

typedef enum{
    RP1_PADS_SET_VOLTAGE_3V3,
    RP1_PADS_SET_VOLTAGE_1V8
}rp1_pads_voltage_select_t;

typedef enum{
    RP1_PADS_DRIVE_2MA,
    RP1_PADS_DRIVE_4MA,
    RP1_PADS_DRIVE_8MA,
    RP1_PADS_DRIVE_12MA
}rp1_pads_drive_t;

void pads_set_voltage(rp1_handle_t* handle, rp1_pads_voltage_select_t select);
void pads_set_drive(gpio_handle_t* handle, rp1_pads_drive_t select);
void pads_output_enable(gpio_handle_t* handle);
void pads_output_disable(gpio_handle_t* handle);

#endif /* PADS_H */
