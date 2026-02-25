#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

//  RP1 Register Mapping
//_____________________________________________________________________________
//
//  This header file provides base addresses and register offsets for:
//      - GPIO pin STATUS/CONTROL registers (GPIO0...GPIO27)
//      - PAD registers
//      - Interrupt registers
//      - PWM registers
//
//  Design choices:
//      - Explicit offsets are provided for grep-ability and hardware function use.
//      - Macros provided for dynamic indexing.
//      - Inline helper functions included for register READ/WRITE and bit manipulation.

// ---- Base adresses ----
#define RP1_GPIO_BASE       0x400d0000u
#define RP1_PADS_BASE       0x400f0000u
#define RP1_SYS_RIO_BASE    0x400e0000u

#define RP1_PWM0_BASE       0x40098000u
#define RP1_PWM1_BASE       0x4009c000u


// ---- Register offsets ----
//_____________________________________________________________________________
//
// Each GPIO(0..27) exposes two 32-bit registers at RP1_GPIO_BASE:
//      STATUS:    offset = 0x000 + 8*n
//      CONTROL:   offset = 0x004 + 8*n
//
// Use either the explicit constants (e.g., RP1_GPIO7_STATUS_OFFSET)
// or the macros (e.g., RP1_GPIO_STATUS_OFFSET(15)) for dynamic indexing.
//
// NOTE: This header doesn’t define the bitfields of STATUS/CONTROL registers,
// only offsets.

// ---- Macros for GPIO dynamic indexing ----
#define RP1_GPIO_STATUS_OFFSET(n)   ((uint32_t)(0x000u+((uint32_t)(n)*0x8u)))
#define RP1_GPIO_CONTROL_OFFSET(n)  ((uint32_t)(0x004u+((uint32_t)(n)*0x8u)))

// ---- Explicit offsets (GPIO0..GPIO27) ----
#define RP1_GPIO0_STATUS_OFFSET     0x000u
#define RP1_GPIO0_CONTROL_OFFSET    0x004u
#define RP1_GPIO1_STATUS_OFFSET     0x008u
#define RP1_GPIO1_CONTROL_OFFSET    0x00cu
#define RP1_GPIO2_STATUS_OFFSET     0x010u
#define RP1_GPIO2_CONTROL_OFFSET    0x014u
#define RP1_GPIO3_STATUS_OFFSET     0x018u
#define RP1_GPIO3_CONTROL_OFFSET    0x01cu
#define RP1_GPIO4_STATUS_OFFSET     0x020u
#define RP1_GPIO4_CONTROL_OFFSET    0x024u
#define RP1_GPIO5_STATUS_OFFSET     0x028u
#define RP1_GPIO5_CONTROL_OFFSET    0x02cu
#define RP1_GPIO6_STATUS_OFFSET     0x030u
#define RP1_GPIO6_CONTROL_OFFSET    0x034u
#define RP1_GPIO7_STATUS_OFFSET     0x038u
#define RP1_GPIO7_CONTROL_OFFSET    0x03cu
#define RP1_GPIO8_STATUS_OFFSET     0x040u
#define RP1_GPIO8_CONTROL_OFFSET    0x044u
#define RP1_GPIO9_STATUS_OFFSET     0x048u
#define RP1_GPIO9_CONTROL_OFFSET    0x04cu
#define RP1_GPIO10_STATUS_OFFSET    0x050u
#define RP1_GPIO10_CONTROL_OFFSET   0x054u
#define RP1_GPIO11_STATUS_OFFSET    0x058u
#define RP1_GPIO11_CONTROL_OFFSET   0x05cu
#define RP1_GPIO12_STATUS_OFFSET    0x060u
#define RP1_GPIO12_CONTROL_OFFSET   0x064u
#define RP1_GPIO13_STATUS_OFFSET    0x068u
#define RP1_GPIO13_CONTROL_OFFSET   0x06cu
#define RP1_GPIO14_STATUS_OFFSET    0x070u
#define RP1_GPIO14_CONTROL_OFFSET   0x074u
#define RP1_GPIO15_STATUS_OFFSET    0x078u
#define RP1_GPIO15_CONTROL_OFFSET   0x07cu
#define RP1_GPIO16_STATUS_OFFSET    0x080u
#define RP1_GPIO16_CONTROL_OFFSET   0x084u
#define RP1_GPIO17_STATUS_OFFSET    0x088u
#define RP1_GPIO17_CONTROL_OFFSET   0x08cu
#define RP1_GPIO18_STATUS_OFFSET    0x090u
#define RP1_GPIO18_CONTROL_OFFSET   0x094u
#define RP1_GPIO19_STATUS_OFFSET    0x098u
#define RP1_GPIO19_CONTROL_OFFSET   0x09cu
#define RP1_GPIO20_STATUS_OFFSET    0x0a0u
#define RP1_GPIO20_CONTROL_OFFSET   0x0a4u
#define RP1_GPIO21_STATUS_OFFSET    0x0a8u
#define RP1_GPIO21_CONTROL_OFFSET   0x0acu
#define RP1_GPIO22_STATUS_OFFSET    0x0b0u
#define RP1_GPIO22_CONTROL_OFFSET   0x0b4u
#define RP1_GPIO23_STATUS_OFFSET    0x0b8u
#define RP1_GPIO23_CONTROL_OFFSET   0x0bcu
#define RP1_GPIO24_STATUS_OFFSET    0x0c0u
#define RP1_GPIO24_CONTROL_OFFSET   0x0c4u
#define RP1_GPIO25_STATUS_OFFSET    0x0c8u
#define RP1_GPIO25_CONTROL_OFFSET   0x0ccu
#define RP1_GPIO26_STATUS_OFFSET    0x0d0u
#define RP1_GPIO26_CONTROL_OFFSET   0x0d4u
#define RP1_GPIO27_STATUS_OFFSET    0x0d8u
#define RP1_GPIO27_CONTROL_OFFSET   0x0dcu

// ---- Interrupt offsets ----
#define RP1_INTR_RAW_OFFSET     0x100   // Raw Interrupts
#define RP1_PROC0_INTE_OFFSET   0x104   // Interrupt Enable for proc0
#define RP1_PROC0_INTF_OFFSET   0x108   // Interrupt Force for proc0
#define RP1_PROC0_INTS_OFFSET   0x10c   // Interrupt Status for proc0
#define RP1_PROC1_INTE_OFFSET   0x110   // Interrupt Enable for proc1
#define RP1_PROC1_INTF_OFFSET   0x114   // Interrupt Force for proc1
#define RP1_PROC1_INTS_OFFSET   0x118   // Interrupt Status for proc1
#define RP1_PCIE_INTE_OFFSET    0x11c   // Interrupt Enable for pcie
#define RP1_PCIE_INTF_OFFSET    0x120   // Interrupt Force for pcie
#define RP1_PCIE_INTS_OFFSET    0x124   // Interrupt Status for pcie

// ---- Macro for Pads dynamic indexing ----
#define RP1_PAD_GPIO(n)   ((uint32_t)(0x04u+((uint32_t)(n)*0x04u)))

// ---- Pads offsets ----
#define RP1_VOLTAGE_SELECT_PAD  0x00u   // Voltage select, per bank control
#define RP1_GPIO0_PAD           0x04u
#define RP1_GPIO1_PAD           0x08u
#define RP1_GPIO2_PAD           0x0cu
#define RP1_GPIO3_PAD           0x10u
#define RP1_GPIO4_PAD           0x14u
#define RP1_GPIO5_PAD           0x18u
#define RP1_GPIO6_PAD           0x1cu
#define RP1_GPIO7_PAD           0x20u
#define RP1_GPIO8_PAD           0x24u
#define RP1_GPIO9_PAD           0x28u
#define RP1_GPIO10_PAD          0x2cu
#define RP1_GPIO11_PAD          0x30u
#define RP1_GPIO12_PAD          0x34u
#define RP1_GPIO13_PAD          0x38u
#define RP1_GPIO14_PAD          0x3cu
#define RP1_GPIO15_PAD          0x40u
#define RP1_GPIO16_PAD          0x44u
#define RP1_GPIO17_PAD          0x48u
#define RP1_GPIO18_PAD          0x4cu
#define RP1_GPIO19_PAD          0x50u
#define RP1_GPIO20_PAD          0x54u
#define RP1_GPIO21_PAD          0x58u
#define RP1_GPIO22_PAD          0x5cu
#define RP1_GPIO23_PAD          0x60u
#define RP1_GPIO24_PAD          0x64u
#define RP1_GPIO25_PAD          0x68u
#define RP1_GPIO26_PAD          0x6cu
#define RP1_GPIO27_PAD          0x70u

// ---- MMIO helper functions ----
//_____________________________________________________________________________
//
// These functions provide basic register operations and bit manipulations with
// correct casting while improving code readability.
//
// NOTE: REG_SET32 and REG_CLR32 perform non-atomic operations.
static inline volatile uint32_t* REG_ADDR32(uint32_t address){
    return (volatile uint32_t*)address;
}

static inline uint32_t REG_READ32(uint32_t address){
    return *(volatile uint32_t*)address;
}

static inline void REG_WRITE32(uint32_t address, uint32_t value){
    *(volatile uint32_t*)address = value;
}

static inline void REG_SET32(uint32_t address, uint32_t mask){
    *(volatile uint32_t*)address |= mask;
}

static inline void REG_CLR32(uint32_t address, uint32_t mask){
    *(volatile uint32_t*)address &= (~mask);
}

// ---- RIO offsets ----
//_____________________________________________________________________________
//
// NOTE: RIO_IN has a no sync option that is not included in the offsets.
#define RP1_RIO_OUT     0x00u
#define RP1_RIO_OE      0x04u
#define RP1_RIO_IN      0x08u

// ---- Alias offsets ----
//_____________________________________________________________________________
//
// Low speed peripherals provide aliases for atomic operations.
#define RP1_RW_OFFSET   0x0000u
#define RP1_XOR_OFFSET  0x1000u
#define RP1_SET_OFFSET  0x2000u
#define RP1_CLR_OFFSET  0x3000u

// ---- PWM control offsets ----
#define RP1_PWM_GLOBAL_CTRL     0x00u
#define RP1_PWM_FIFO_CTRL       0x04u
#define RP1_PWM_COMMON_RANGE    0x08u
#define RP1_PWM_COMMON_DUTY     0x0cu
#define RP1_PWM_DUTY_FIFO       0x10u
#define RP1_PWM_CHAN0_CTRL      0x14u
#define RP1_PWM_CHAN0_RANGE     0x18u
#define RP1_PWM_CHAN0_PHASE     0x1cu
#define RP1_PWM_CHAN0_DUTY      0x20u
#define RP1_PWM_CHAN1_CTRL      0x24u
#define RP1_PWM_CHAN1_RANGE     0x28u
#define RP1_PWM_CHAN1_PHASE     0x2cu
#define RP1_PWM_CHAN1_DUTY      0x30u
#define RP1_PWM_CHAN2_CTRL      0x34u
#define RP1_PWM_CHAN2_RANGE     0x38u
#define RP1_PWM_CHAN2_PHASE     0x3cu
#define RP1_PWM_CHAN2_DUTY      0x40u
#define RP1_PWM_CHAN3_CTRL      0x44u
#define RP1_PWM_CHAN3_RANGE     0x48u
#define RP1_PWM_CHAN3_PHASE     0x4cu
#define RP1_PWM_CHAN3_DUTY      0x50u
#define RP1_PWM_INTR            0x54u
#define RP1_PWM_INTE            0x58u
#define RP1_PWM_INTF            0x5cu
#define RP1_PWM_INTS            0x60u

#endif
