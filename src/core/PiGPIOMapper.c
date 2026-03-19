#include "PiGPIOMapper.h"
#include "gpio.h"
#include "pads.h"
#include "rp1_init.h"
#include "rp1_gpio_init.h"
#include <stdio.h>
#include <stdlib.h>

rp1_handle_t* init_gpio(void){
    rp1_handle_t *rp1_handle = malloc(sizeof(rp1_handle_t));

    if(rp1_handle == NULL){
        perror("failed to allocate memory for chip handle\n\r");
        return NULL;
    }
    else{
        printf("handle address: %p\n\r", (void*)rp1_handle);
    }

    if(rp1_init(rp1_handle) == 0){
        printf("rp1 chip opened...\n\r");
        return rp1_handle;
    }
    else{
        perror("rp1 chip failed to open...\n\r");
    }
}

void close_chip(rp1_handle_t *handle){
    rp1_close(handle);
    free(handle);
}

gpio_handle_t* create_gpio_pin(rp1_handle_t *rp1_handle, rp1_gpio_select_t gpio){
    gpio_handle_t *gpio_handle = malloc(sizeof(gpio_handle_t));
    if(rp1_gpio_init(rp1_handle, gpio_handle, gpio) == 0){
        printf("gpio is opened\n\r");
        return gpio_handle;
    }
    else{
        perror("gpio failed to open\n\r");
    }
}

int set_gpio_output(gpio_handle_t *gpio_handle, gpio_output_t output){
    gpio_func_select(gpio_handle, RP1_GPIO_FUNCSEL_ALT0);
    if(output == HIGH){
        rio_set_oe_state(&rio_handle, RP1_RIO_OE_ENABLE);
        rio_set_out_state(&rio_handle, RP1_RIO_OUT_HIGH);
        printf("gpio is set high");
    }
    else if(output == LOW){
        rio_clr_out_state(&rio_handle, RP1_RIO_OUT_HIGH);
        rio_clr_oe_state(&rio_handle, RP1_RIO_OE_ENABLE);
        printf("gpio is set low");
    }

    return 0;
}
