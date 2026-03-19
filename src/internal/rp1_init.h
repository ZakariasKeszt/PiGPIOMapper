#ifndef RP1_INIT_H
#define RP1_INIT_H

#include <stdio.h>
#include <endian.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "gpio_types.h"

#define RP1_BASE_OFFSET 0x40000000u;

typedef struct rp1_handle_s{
    volatile uintptr_t base_mem;
    volatile uintptr_t voltage_ctrl;
    size_t map_size;
    int file_descriptor;
} rp1_handle_t;

int rp1_init(rp1_handle_t *handle);
int rp1_close(rp1_handle_t *handle);

#endif /*RP1_INIT_H*/
