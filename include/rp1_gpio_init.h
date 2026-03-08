#ifndef RP1_GPIO_H
#define RP1_GPIO_H

#include <stdio.h>
#include <endian.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "registers.h"

#define RP1_BASE_OFFSET 0x40000000u;

typedef struct{
    uintptr_t base_mem;
    size_t map_size;
    int file_descriptor;
} rp1_handler_t;

int rp1_init(rp1_handle_t *handle);
int rp1_close(rp1_handle_t *handle);
int get_physical_base_mem(uintptr_t* out_addr);

#endif /*RP1_GPIO_H*/
