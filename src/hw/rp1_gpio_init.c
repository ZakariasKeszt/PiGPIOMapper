#include "rp1_gpio_init.h"
#include "gpio_types.h"


static void rp1_rio_init(rp1_handle_t* handle);
static void rp1_pads_init(rp1_handle_t* handle);
rio_handle_t rio_handle;
rp1_pads_voltage_select_reg_t pads_voltage_select;

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
};

int rp1_gpio_init(rp1_handle_t* handle, gpio_handle_t* gpio_handle, rp1_gpio_select_t sel){
    uint32_t select = (uint32_t)rp1_gpio_select_lookup[sel];
    volatile uintptr_t gpio_base = handle->base_mem+RP1_GPIO_BASE;
    volatile uintptr_t pad_base =  handle->base_mem+RP1_PADS_BASE;

    gpio_handle->GPIO_CTRL = (volatile rp1_gpio_ctrl_reg_t*)gpio_base + RP1_GPIO_CONTROL_OFFSET(select);
    gpio_handle->GPIO_STATUS = (volatile rp1_gpio_status_reg_t*)gpio_base + RP1_GPIO_STATUS_OFFSET(select);
    gpio_handle->PAD_REG = (volatile rp1_pads_ctrl_reg_t*)pad_base + RP1_PAD_GPIO(select);
    gpio_handle->rio_pin_mask = (1u << select);

	rp1_rio_init(handle);
	rp1_pads_init(handle);

    return 0;
}

static void rp1_rio_init(rp1_handle_t* handle){
	rio_handle.rio_out = (volatile uint32_t*)(handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OUT);
	rio_handle.rio_oe = (volatile uint32_t*)(handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OE);
	rio_handle.rio_in = (volatile uint32_t*)(handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_IN);
}

static void rp1_pads_init(rp1_handle_t* handle){
    handle->voltage_ctrl = handle->base_mem + RP1_PADS_BASE + RP1_VOLTAGE_SELECT_PAD;
}
