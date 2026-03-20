#include "gpio.h"
#include "PiGPIOMapper.h"

static const int rp1_gpio_irqoverride_lookup[] = {
    [RP1_GPIO_IRQOVERRIDE_DEF] =   0x00,
    [RP1_GPIO_IRQOVERRIDE_INV] =   0x01,
    [RP1_GPIO_IRQOVERRIDE_LOW] =   0x02,
    [RP1_GPIO_IRQOVERRIDE_HIGH] =  0x03
};

static const int rp1_gpio_irqreset_lookup[] = {
    [RP1_GPIO_IRQRESET_NONE] =     0x00,
    [RP1_GPIO_IRQRESET_RESET] =    0x01
};

static const int rp1_gpio_inoverride_lookup[] = {
    [RP1_GPIO_INOVERRIDE_DEF] =        0x00,
    [RP1_GPIO_INOVERRIDE_INV_DEF] =    0x01,
    [RP1_GPIO_INOVERRIDE_LOW] =        0x02,
    [RP1_GPIO_INOVERRIDE_HIGH] =       0x03
};

static const int rp1_gpio_oeoverride_lookup[] = {
    [RP1_GPIO_OEOVERRIDE_DEF] =        0x00,
    [RP1_GPIO_OEOVERRIDE_INV_DEF] =    0x01,
    [RP1_GPIO_OEOVERRIDE_DIS] =        0x02,
    [RP1_GPIO_OEOVERRIDE_EN] =         0x03
};

static const int rp1_gpio_outoverride_lookup[] = {
    [RP1_GPIO_OUTOVERRIDE_DEF] =        0x00,
    [RP1_GPIO_OUTOVERRIDE_INV_DEF] =    0x01,
    [RP1_GPIO_OUTOVERRIDE_LOW] =        0x02,
    [RP1_GPIO_OUTOVERRIDE_HIGH] =       0x03
};

static const int rp1_gpio_funcsel_lookup[] = {
    [RP1_GPIO_FUNCSEL_ALT0] = 0x00,
    [RP1_GPIO_FUNCSEL_ALT1] = 0x01,
    [RP1_GPIO_FUNCSEL_ALT2] = 0x02,
    [RP1_GPIO_FUNCSEL_ALT3] = 0x03,
    [RP1_GPIO_FUNCSEL_ALT4] = 0x04,
    [RP1_GPIO_FUNCSEL_ALT5] = 0x05,
    [RP1_GPIO_FUNCSEL_ALT6] = 0x06,
    [RP1_GPIO_FUNCSEL_ALT7] = 0x07,
    [RP1_GPIO_FUNCSEL_ALT8] = 0x08
};


void gpio_func_select(gpio_handle_t* handle, rp1_gpio_funcsel_t sel){
    uint32_t select = rp1_gpio_funcsel_lookup[sel];
    handle->GPIO_CTRL->bit.FUNCSEL = select;
}

void gpio_set_irqoverride(gpio_handle_t* handle, rp1_gpio_irqoverride_t state){
    uint32_t select = rp1_gpio_irqoverride_lookup[state];
    handle->GPIO_CTRL->bit.IRQOVER = select;
}

void gpio_set_irqreset(gpio_handle_t* handle, rp1_gpio_irqreset_t state){
    uint32_t select = rp1_gpio_irqreset_lookup[state];
    handle->GPIO_CTRL->bit.IRQRESET = select;
}

void gpio_set_oeoverride(gpio_handle_t* handle, rp1_gpio_oeoverride_t state){
    uint32_t select = rp1_gpio_oeoverride_lookup[state];
    handle->GPIO_CTRL->bit.OEOVER = select;
}

void gpio_set_inoverride(gpio_handle_t* handle, rp1_gpio_inoverride_t state){
    uint32_t select = rp1_gpio_inoverride_lookup[state];
    handle->GPIO_CTRL->bit.INOVER = select;
}

void gpio_set_outoverride(gpio_handle_t* handle, rp1_gpio_outoverride_t state){
    uint32_t select = rp1_gpio_outoverride_lookup[state];
    handle->GPIO_CTRL->bit.OUTOVER = select;
}



void rio_set_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_out + RP1_SET_OFFSET) = mask;
}

void rio_set_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_in + RP1_SET_OFFSET) = mask;
}

void rio_set_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_oe + RP1_SET_OFFSET) = mask;
}

void rio_clr_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_out + RP1_CLR_OFFSET) = mask;
}

void rio_clr_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_in + RP1_CLR_OFFSET) = mask;
}

void rio_clr_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_oe + RP1_CLR_OFFSET) = mask;
}

void rio_xor_out(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_out + RP1_XOR_OFFSET) = mask;
}

void rio_xor_in(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_in + RP1_XOR_OFFSET) = mask;
}

void rio_xor_oe(rio_handle_t* rio_handle, gpio_handle_t* gpio_handle){
    uint32_t mask = gpio_handle->rio_pin_mask;
    *(volatile uint32_t*)((uintptr_t)rio_handle->rio_oe + RP1_XOR_OFFSET) = mask;
}
