#include "rp1_gpio_init.h"
#include "gpio_types.h"


static void rp1_rio_init(rp1_handle_t* handle);
static void rp1_pads_init(rp1_handle_t* handle);

rio_handle_t rio_handle;
rp1_pads_voltage_select_reg_t pads_voltage_select;
int rio_init = 0;
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
    printf("gpio_base:  %p, pad_base: %p\n", (void*)((uintptr_t)handle->base_mem+RP1_GPIO_BASE), (void*)((uintptr_t)handle->base_mem+RP1_PADS_BASE));
    gpio_handle->GPIO_CTRL = (volatile rp1_gpio_ctrl_reg_t*)((uintptr_t)handle->base_mem + RP1_GPIO_BASE + RP1_GPIO_CONTROL_OFFSET(select));
    gpio_handle->GPIO_STATUS = (volatile rp1_gpio_status_reg_t*)((uintptr_t)handle->base_mem + RP1_GPIO_BASE + RP1_GPIO_STATUS_OFFSET(select));
    gpio_handle->PAD_REG = (volatile rp1_pads_ctrl_reg_t*)((uintptr_t)handle->base_mem+RP1_PADS_BASE + RP1_PAD_GPIO(select));
    gpio_handle->rio_pin_mask = (1u << select);
    printf("GPIO_CTRL:   %p\n", (void*)gpio_handle->GPIO_CTRL);
    printf("GPIO_STATUS: %p\n", (void*)gpio_handle->GPIO_STATUS);
    printf("PAD_REG:     %p\n", (void*)gpio_handle->PAD_REG);
    printf("RIO_MASK:    0x%08x\n", gpio_handle->rio_pin_mask);
	rp1_rio_init(handle);

    return 0;
}

static void rp1_rio_init(rp1_handle_t* handle){

    if(!rio_init){
    	rio_handle.rio_out = (volatile uint32_t*)((uintptr_t)handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OUT);
    	rio_handle.rio_oe = (volatile uint32_t*)((uintptr_t)handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_OE);
    	rio_handle.rio_in = (volatile uint32_t*)((uintptr_t)handle->base_mem + RP1_SYS_RIO_BASE + RP1_RIO_IN);
    	printf("RIO_OUT:     %p\n", (void*)rio_handle.rio_out);
        printf("RIO_OE:      %p\n", (void*)rio_handle.rio_oe);
        printf("RIO_IN:      %p\n", (void*)rio_handle.rio_in);
        rio_init = 1;
    }
}
