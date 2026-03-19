#include "PiGPIOMapper.h"
#include "gpio.h"
#include "pads.h"
#include "rp1_init.h"
#include "rp1_gpio_init.h"
#include <stdio.h>


rp1_handle_t* init_gpio(void){
    rp1_handle_t *rp1_handle;
    if(rp1_init(rp1_handle) == 0){
        printf("rp1 chip opened...");
        return rp1_handle;
    }
    else{
        perror("rp1 chip failed to open...");
    }
}

gpio_handle_t* create_gpio_pin(rp1_handle_t *rp1_handle, rp1_gpio_select_t gpio){
    gpio_handle_t *gpio_handle;
    if(rp1_gpio_init(rp1_handle, gpio_handle, gpio) == 0){
        printf("gpio &d is opened", (int)gpio);
        return gpio_handle;
    }
    else{
        perror("gpio failed to open");
    }
}

int set_gpio_output(gpio_handle_t gpio_handle, gpio_output_t output){
    gpio_func_select(&gpio_handle, RP1_GPIO_FUNCSEL_ALT0);
    if(output == HIGH){
        rio_set_oe_state(&rio_handle, RP1_RIO_OE_ENABLE);
        rio_set_out_state(&rio_handle, RP1_RIO_OUT_HIGH);
    }
    else if(output == LOW){
        rio_clr_out_state(&rio_handle, RP1_RIO_OUT_HIGH);
        rio_clr_oe_state(&rio_handle, RP1_RIO_OE_ENABLE);
    }

    return 0;
}
