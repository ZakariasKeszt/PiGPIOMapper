/**
 *  @file rio_structs.h
 *
 * @brief RIO register mapping and state enums.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 *
 */

#ifndef RIO_STRUCTS_H
#define RIO_STRUCTS_H

typedef enum{
    RP1_RIO_OUT_LOW = 0x00;
    RP1_RIO_OUT_HIGH = 0x01;
}rp1_rio_out_state_t;

typedef enum{
    RP1_RIO_OE_DISABLE = 0x00;
    RP1_RIO_OE_ENABLE = 0x01;
}rp1_rio_oe_enable_t;

typedef enum{
    RP1_RIO_IN_DISABLE = 0x00;
    RP1_RIO_IN_ENABLE = 0x01;
}rp1_rio_in_enable_t;

typedef union{
    struct{
        uint32_t RP1_RIO_GPIO0 : 1;
        uint32_t RP1_RIO_GPIO1 : 1;
        uint32_t RP1_RIO_GPIO2 : 1;
        uint32_t RP1_RIO_GPIO3 : 1;
        uint32_t RP1_RIO_GPIO4 : 1;
        uint32_t RP1_RIO_GPIO5 : 1;
        uint32_t RP1_RIO_GPIO6 : 1;
        uint32_t RP1_RIO_GPIO7 : 1;
        uint32_t RP1_RIO_GPIO8 : 1;
        uint32_t RP1_RIO_GPIO9 : 1;
        uint32_t RP1_RIO_GPIO10 : 1;
        uint32_t RP1_RIO_GPIO11 : 1;
        uint32_t RP1_RIO_GPIO12 : 1;
        uint32_t RP1_RIO_GPIO13 : 1;
        uint32_t RP1_RIO_GPIO14 : 1;
        uint32_t RP1_RIO_GPIO15 : 1;
        uint32_t RP1_RIO_GPIO16 : 1;
        uint32_t RP1_RIO_GPIO17 : 1;
        uint32_t RP1_RIO_GPIO18 : 1;
        uint32_t RP1_RIO_GPIO19 : 1;
        uint32_t RP1_RIO_GPIO20 : 1;
        uint32_t RP1_RIO_GPIO21 : 1;
        uint32_t RP1_RIO_GPIO22 : 1;
        uint32_t RP1_RIO_GPIO23 : 1;
        uint32_t RP1_RIO_GPIO24 : 1;
        uint32_t RP1_RIO_GPIO25 : 1;
        uint32_t RP1_RIO_GPIO26 : 1;
        uint32_t RP1_RIO_GPIO27 : 1;
        uint32_t _reserved0 : 4;
    }bit;
    uint32_t word;
}rp1_rio_reg_t;

#endif /* RIO_STRUCTS_H */
