/**
 *  @file gpio_structs.h
 *
 * @brief PADS register mapping and state enums.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 *
 */

#ifndef PADS_STRUCTS_H
#define PADS_STRUCTS_H

typedef enum{
    RP1_PADS_SET_VOLTAGE_3V3 = 0x00,
    RP1_PADS_SET_VOLTAGE_1V8 = 0x01
}rp1_pads_voltage_select_t;

typedef enum{
    RP1_PADS_DRIVE_2MA = 0x00,
    RP1_PADS_DRIVE_4MA = 0x01,
    RP1_PADS_DRIVE_8MA = 0x02,
    RP1_PADS_DRIVE_12MA = 0x03
}rp1_pads_drive_t;

typedef union{
    struct{
        uint32_t VOLTAGE_SEL : 1;
        uint32_t _reserved0 : 31;
    }bit;
    uint32_t word;
}rp1_pads_voltage_select_reg_t;

typedef union{
    struct{
        uint32_t SLEWFAST : 1;
        uint32_t SCHMITT : 1;
        uint32_t PDE : 1;
        uint32_t PUE : 1;
        uint32_t DRIVE : 2;
        uint32_t IE : 1;
        uint32_t OD : 1;
        uint32_t _reserved0 : 24;
    }bit;
    uint32_t word;
}rp1_pads_ctrl_reg_t;

#endif /* PADS_STRUCTS_H */


