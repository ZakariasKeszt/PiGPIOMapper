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
        perror("failed to allocate memory for chip handle\n");
        return NULL;
    }
    else{
        printf("handle address: %p\n", (void*)rp1_handle);
    }

    if(rp1_init(rp1_handle) == 0){
        printf("rp1 chip opened...\n");
        return rp1_handle;
    }
    else{
        perror("rp1 chip failed to open...\n");
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

void set_gpio_output_high(gpio_handle_t *gpio_handle){
    pads_output_enable(gpio_handle);
    gpio_func_select(gpio_handle, RP1_GPIO_FUNCSEL_ALT5);
    rio_set_oe(&rio_handle, gpio_handle);
    rio_set_out(&rio_handle, gpio_handle);
    printf("gpio is set high");
}

void set_gpio_output_low(gpio_handle_t *gpio_handle){
    pads_output_disable(gpio_handle);
    gpio_func_select(gpio_handle, RP1_GPIO_FUNCSEL_ALT5);
    rio_clr_out(&rio_handle, gpio_handle);
    rio_clr_oe(&rio_handle, gpio_handle);
    printf("gpio is set high");
}
