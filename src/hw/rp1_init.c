#include "rp1_init.h"

int rp1_init(rp1_handle_t* handle){

    handle->map_size = 0x100000;

    void* rp1_virtual_mem = MAP_FAILED;
    uintptr_t base_mem = 0x1F00000000;


    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if(fd < 0){
        perror("Failed to open /dev/mem (do you have root priviliges?)");
        return -1;
    }

    rp1_virtual_mem = mmap(
        NULL,
        handle->map_size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd,
        base_mem
    );

    close(fd);

    if(rp1_virtual_mem == MAP_FAILED){
        perror("mmap failed");
        return -1;
    }

    handle->file_descriptor = fd;
    handle->base_mem = (uintptr_t)rp1_virtual_mem;

    return 0;
}

int rp1_close(rp1_handle_t* handle){

    if(!handle) return -1;

    if(handle->base_mem != (uintptr_t)MAP_FAILED && handle->base_mem != 0){
        munmap((void*)handle->base_mem, handle->map_size);
        handle->base_mem = (uintptr_t)MAP_FAILED;
    }

    return 0;
}
