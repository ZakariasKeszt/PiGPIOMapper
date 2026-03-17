#include "internal/rp1_init.h"

int rp1_init(rp1_handler_t* handle){

    handle.map_size = 0x100000;

    void* rp1_virtual_mem = MAP_FAILED;
    uintptr_t base_mem;
    if(get_physical_base_mem(&base_mem) < 0){
        perror("Failed to map base address");
        return -1;
    }

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if(fd < 0){
        perror("Failed to open /dev/mem (do you have root priviliges?)");
        return -1;
    }

    rp1_virtual_mem = mmap(
        NULL,
        handle.map_size,
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

    handle.file_descriptor = fd;
    handle.base_mem = (uintptr_t)rp1_virtual_mem;

    return 0;
}

int rp1_close(rp1_handler_t* handler){

    if(!handle) return -1;

    if(handle.base_mem != (uintptr_t)MAP_FAILED && handle.base_mem != 0){
        munmap((void*)handle.base_mem, handle.map_size);
        handle.base_mem = (uintptr_t)MAP_FAILED;
    }

    return 0;
}

int get_physical_base_mem(uintptr_t *out_addr){

    uint64_t raw_read;
    int fd = open("/proc/device-tree/axi/pcie@100000/rp1@0/reg", O_RDONLY);
    if(fd < 0) return -1;

    if(read(fd, &raw_read, sizeof(raw_read)) != sizeof(raw_read)){
        close(fd);
        return -1;
    }
    *out_addr = be64toh(raw_read);
    *out_addr+=RP1_BASE_OFFSET;
    close(fd);

    return 0;
}
