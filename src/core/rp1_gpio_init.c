#include "internal/rp1_gpio_init.h"

static bool rio_init_true = 0;
rio_handle_t rio_handle;

static const int rp1_gpio_select_lookup[] = {
    [GPIO0] = 0,
	[GPIO1] = 1,
	[GPIO2] = 2,
	[GPIO3] = 3,
	[GPIO4] = 4,
	[GPIO5] = 5,
	[GPIO6] = 6,
	[GPIO7] = 7,
	[GPIO8] = 8,
	[GPIO9] = 9,
	[GPIO10] = 10,
	[GPIO11] = 11,
	[GPIO12] = 12,
	[GPIO13] = 13,
	[GPIO14] = 14,
	[GPIO15] = 15,
	[GPIO16] = 16,
	[GPIO17] = 17,
	[GPIO18] = 18,
	[GPIO19] = 19,
	[GPIO20] = 20,
	[GPIO21] = 21,
	[GPIO22] = 22,
	[GPIO23] = 23,
	[GPIO24] = 24,
	[GPIO25] = 25,
	[GPIO26] = 26,
	[GPIO27] = 27
}

int rp1_gpio_init(rp1_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel){
    uint32_t select = (uint32_t)rp1_gpio_select_lookup[sel];
    volatile uintptr_t gpio_base = handle->base_mem+RP1_GPIO_BASE;
    volatile uintptr_t pad_base =  handle->base_mem+RP1_PADS_BASE;

    gpio_handle->GPIO_CTRL = gpio_base + RP1_GPIO_CONTROL_OFFSET(select);
    gpio_handle->GPIO_STATUS = gpio_base + RP1_GPIO_STATUS_OFFSET(select);
    gpio_handle->PAD_REG = pad_base + RP1_PAD_GPIO(select);
    gpio_handle->rio_pin_mask = (1u << select);

	if(!rio_init_true){
		rp1_rio_init();
	}
    
    return 0;
}

static void rp1_rio_init(rp1_handle_t* handle){
	rio_handle.rio_out = rp1_handle.base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OUT;
	rio_handle.rio_oe = rp1_handle.base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OE;
	rio_handle.rio_in = rp1_handle.base_mem + RP1_SYS_RIO_BASE + RP1_RIO_IN;
	rio_init_true = 1;
}
/*
static void rp1_pads_init(rp1_handle_t* handle){
    pads_voltage_select.bit.DRIVE = rp1_handle.base_mem +
*/
