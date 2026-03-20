#include "pads.h"
#include "gpio_types.h"


static const int rp1_pads_voltage_select_lookup[] = {
    [RP1_PADS_SET_VOLTAGE_3V3] = 0x00,
    [RP1_PADS_SET_VOLTAGE_1V8] = 0x01
};

static const int rp1_pads_drive_lookup[] = {
    [RP1_PADS_DRIVE_2MA] = 0x00,
    [RP1_PADS_DRIVE_4MA] = 0x01,
    [RP1_PADS_DRIVE_8MA] = 0x02,
    [RP1_PADS_DRIVE_12MA] = 0x03
};

void pads_set_voltage(rp1_handle_t* handle, rp1_pads_voltage_select_t sel){
    uint32_t select = rp1_pads_voltage_select_lookup[sel];
    rp1_pads_voltage_select_reg_t reg = *(volatile rp1_pads_voltage_select_reg_t*)handle->voltage_ctrl;
    reg.bit.VOLTAGE_SEL = select;
    *((volatile rp1_pads_voltage_select_reg_t*)handle->voltage_ctrl) = reg;
}

void pads_set_drive(gpio_handle_t* handle, rp1_pads_drive_t sel){
    uint32_t select = rp1_pads_drive_lookup[sel];
    rp1_pads_ctrl_reg_t reg = *(volatile rp1_pads_ctrl_reg_t*)handle->PAD_REG;
    reg.bit.DRIVE = select;
    *(handle->PAD_REG) = reg;
}

void pads_output_enable(gpio_handle_t* handle){
    rp1_pads_ctrl_reg_t reg = *(volatile rp1_pads_ctrl_reg_t*)handle->PAD_REG;
    reg.bit.OD = 0;
    reg.bit.IE = 1;
    *(handle->PAD_REG) = reg;
}

void pads_output_disable(gpio_handle_t* handle){
    rp1_pads_ctrl_reg_t reg = *(volatile rp1_pads_ctrl_reg_t*)handle->PAD_REG;
    reg.bit.OD = 1;
    reg.bit.IE = 0;
    *(handle->PAD_REG) = reg;
}
