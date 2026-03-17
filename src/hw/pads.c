#include "pads.h"

static const int rp1_pads_voltage_select_lookup[] = {
    [RP1_PADS_SET_VOLTAGE_3V3] = 0x00,
    [RP1_PADS_SET_VOLTAGE_1V8] = 0x01
}

static const int rp1_pads_drive_lookup[] = {
    [RP1_PADS_DRIVE_2MA] = 0x00,
    [RP1_PADS_DRIVE_4MA] = 0x01,
    [RP1_PADS_DRIVE_8MA] = 0x02,
    [RP1_PADS_DRIVE_12MA] = 0x03
}
/*
int pads_set_voltage(gpio_handle_t* handle, rp1_pads_voltage_select_t sel){
    uint32_t select = rp1_pads_voltage_select_lookup[sel];
        

}--TODO--*/

int pads_set_drive(gpio_handle_t* handle, rp1_pads_drive_lookup sel){
    uint32_t select = rp1_pads_drive_lookup[sel];
    *(volatile uint32_t*)handle->PAD_REG->bit.DRIVE = select;

    return 0;
}
