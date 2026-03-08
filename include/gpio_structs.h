/**
 *  @file gpio_structs.h
 *
 * @brief GPIO register mapping and state enums.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 *
 */

#ifndef GPIO_STRUCTS_H
#define GPIO_STRUCTS_H


typedef enum{
    RP1_GPIO_IRQOVERRIDE_DEF =   0x00,
    RP1_GPIO_IRQOVERRIDE_INV =   0x01,
    RP1_GPIO_IRQOVERRIDE_LOW =   0x02,
    RP1_GPIO_IRQOVERRIDE_HIGH =  0x03
}rp1_gpio_irqoverride_t;

typedef enum{
    RP1_GPIO_IRQRESET_NONE =     0x00,
    RP1_GPIO_IRQRESET_RESET =    0x01
}rp1_gpio_irqreset_t;

typedef enum{
    RP1_GPIO_OEOVERRIDE_DEF =        0x00,
    RP1_GPIO_OEOVERRIDE_INV_DEF =    0x01,
    RP1_GPIO_OEOVERRIDE_DIS =        0x02,
    RP1_GPIO_OEOVERRIDE_EN =         0x03
}rp1_gpio_oeoverride_t;

typedef enum{
    RP1_GPIO_INOVERRIDE_DEF =        0x00,
    RP1_GPIO_INOVERRIDE_INV_DEF =    0x01,
    RP1_GPIO_INOVERRIDE_LOW =        0x02,
    RP1_GPIO_INOVERRIDE_HIGH =       0x03
}rp1_gpio_inoverride_t;

typedef enum{
    RP1_GPIO_OUTOVERRIDE_DEF =       0x00,
    RP1_GPIO_OUTOVERRIDE_INV_DEF =   0x01,
    RP1_GPIO_OUTOVERRIDE_LOW =       0x02,
    RP1_GPIO_OUTOVERRIDE_HIGH =      0x03
}rp1_gpio_outoverride_t;

typedef enum{
    RP1_GPIO_FUNCSEL_ALT0 = 0x00,
    RP1_GPIO_FUNCSEL_ALT1 = 0x01,
    RP1_GPIO_FUNCSEL_ALT2 = 0x02,
    RP1_GPIO_FUNCSEL_ALT3 = 0x03,
    RP1_GPIO_FUNCSEL_ALT4 = 0x04,
    RP1_GPIO_FUNCSEL_ALT5 = 0x05,
    RP1_GPIO_FUNCSEL_ALT6 = 0x06,
    RP1_GPIO_FUNCSEL_ALT7 = 0x07,
    RP1_GPIO_FUNCSEL_ALT8 = 0x08
}rp1_gpio_funcsel_t;

typedef union{
    struct{
        uint32_t FUNCSEL : 5;
        uint32_t F_M : 7;
        uint32_t OUTOVER : 2;
        uint32_t OEOVER : 2;
        uint32_t INOVER : 2;
        uint32_t _reserved0 : 2;
        uint32_t IRQMASK_EDGE_LOW : 1;
        uint32_t IRQMASK_EDGE_HIGH : 1;
        uint32_t IRQMASK_LEVEL_LOW : 1;
        uint32_t IRQMASK_LEVEL_HIGH : 1;
        uint32_t IRQMASK_F_EDGE_LOW : 1;
        uint32_t IRQMASK_F_EDGE_HIGH : 1;
        uint32_t IRQMASK_DB_LEVEL_LOW : 1;
        uint32_t IRQMASK_DB_LEVEL_HIGH : 1;
        uint32_t IRQRESET : 1;
        uint32_t _reserved1 : 1;
        uint32_t IRQOVER : 2;
    }bit;
    uint32_t word;
}rp1_gpio_ctrl_reg_t;

typedef union{
    struct{
        uint32_t _reserved0 : 8;
        uint32_t OUTFROMPERI : 1;
        uint32_t OUTTOPAD : 1;
        uint32_t _reserved1 : 2;
        uint32_t OEFROMPERI : 1;
        uint32_t OETOPAD : 1;
        uint32_t _reserved2 : 2;
        uint32_t INISDIRECT : 1;
        uint32_t INFROMPAD : 1;
        uint32_t INFILTERED : 1;
        uint32_t INTOPERI : 1;
        uint32_t EVENT_EDGE_LOW : 1;
        uint32_t EVENT_EDGE_HIGH : 1;
        uint32_t EVENT_LEVEL_LOW : 1;
        uint32_t EVENT_LEVEL_HIGH : 1;
        uint32_t EVENT_F_EDGE_LOW : 1;
        uint32_t EVENT_F_EDGE_HIGH : 1;
        uint32_t EVENT_DB_LEVEL_LOW : 1;
        uint32_t EVENT_DB_LEVEL_HIGH : 1;
        uint32_t IRQCOMBINED : 1;
        uint32_t IRQTOPROC : 1;
        uint32_t _reserved3 : 2;


    }bit;
    uint32_t word;
}rp1_gpio_status_reg_t;

typedef struct{
    rp1_gpio_status_reg_t GPIO_STATUS;
    rp1_gpio_ctrl_reg_t GPIO_CTRL;
}rp1_gpio_t;


#endif /* GPIO_STRUCTS_H */