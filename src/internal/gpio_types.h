
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include <stdint.h>
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

#endif /* GPIO_TYPES_H */
