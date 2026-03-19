/**
 *  @file registers.h
 *
 * @brief RP1 Register Mapping
 *
 * @par This header file provides base addresses and register offsets for:
 *     - GPIO pin STATUS/CONTROL registers (GPIO0...GPIO27)
 *     - PAD registers
 *     - Interrupt registers
 *     - PWM registers
 *
 * @par Design choices:
 *     - Explicit offsets are provided for grep-ability and hardware function use.
 *     - Macros provided for dynamic indexing.
 *
 * @copyright Copyright (c) 2026 Zakariás Keszthelyi. All rights reserved.
 */

#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

/* ---- Base adresses ---- */
#define RP1_GPIO_BASE       0xd0000u
#define RP1_PADS_BASE       0xf0000u
#define RP1_SYS_RIO_BASE    0xe0000u
#define RP1_PWM0_BASE       0x98000u
#define RP1_PWM1_BASE       0x9c000u

/* ---- Explicit offsets (GPIO0..GPIO27) ---- */
#define RP1_GPIO0_STATUS_OFFSET     0x0000u
#define RP1_GPIO0_CONTROL_OFFSET    0x0004u
#define RP1_GPIO1_STATUS_OFFSET     0x0008u
#define RP1_GPIO1_CONTROL_OFFSET    0x000cu
#define RP1_GPIO2_STATUS_OFFSET     0x0010u
#define RP1_GPIO2_CONTROL_OFFSET    0x0014u
#define RP1_GPIO3_STATUS_OFFSET     0x0018u
#define RP1_GPIO3_CONTROL_OFFSET    0x001cu
#define RP1_GPIO4_STATUS_OFFSET     0x0020u
#define RP1_GPIO4_CONTROL_OFFSET    0x0024u
#define RP1_GPIO5_STATUS_OFFSET     0x0028u
#define RP1_GPIO5_CONTROL_OFFSET    0x002cu
#define RP1_GPIO6_STATUS_OFFSET     0x0030u
#define RP1_GPIO6_CONTROL_OFFSET    0x0034u
#define RP1_GPIO7_STATUS_OFFSET     0x0038u
#define RP1_GPIO7_CONTROL_OFFSET    0x003cu
#define RP1_GPIO8_STATUS_OFFSET     0x0040u
#define RP1_GPIO8_CONTROL_OFFSET    0x0044u
#define RP1_GPIO9_STATUS_OFFSET     0x0048u
#define RP1_GPIO9_CONTROL_OFFSET    0x004cu
#define RP1_GPIO10_STATUS_OFFSET    0x0050u
#define RP1_GPIO10_CONTROL_OFFSET   0x0054u
#define RP1_GPIO11_STATUS_OFFSET    0x0058u
#define RP1_GPIO11_CONTROL_OFFSET   0x005cu
#define RP1_GPIO12_STATUS_OFFSET    0x0060u
#define RP1_GPIO12_CONTROL_OFFSET   0x0064u
#define RP1_GPIO13_STATUS_OFFSET    0x0068u
#define RP1_GPIO13_CONTROL_OFFSET   0x006cu
#define RP1_GPIO14_STATUS_OFFSET    0x0070u
#define RP1_GPIO14_CONTROL_OFFSET   0x0074u
#define RP1_GPIO15_STATUS_OFFSET    0x0078u
#define RP1_GPIO15_CONTROL_OFFSET   0x007cu
#define RP1_GPIO16_STATUS_OFFSET    0x0080u
#define RP1_GPIO16_CONTROL_OFFSET   0x0084u
#define RP1_GPIO17_STATUS_OFFSET    0x0088u
#define RP1_GPIO17_CONTROL_OFFSET   0x008cu
#define RP1_GPIO18_STATUS_OFFSET    0x0090u
#define RP1_GPIO18_CONTROL_OFFSET   0x0094u
#define RP1_GPIO19_STATUS_OFFSET    0x0098u
#define RP1_GPIO19_CONTROL_OFFSET   0x009cu
#define RP1_GPIO20_STATUS_OFFSET    0x00a0u
#define RP1_GPIO20_CONTROL_OFFSET   0x00a4u
#define RP1_GPIO21_STATUS_OFFSET    0x00a8u
#define RP1_GPIO21_CONTROL_OFFSET   0x00acu
#define RP1_GPIO22_STATUS_OFFSET    0x00b0u
#define RP1_GPIO22_CONTROL_OFFSET   0x00b4u
#define RP1_GPIO23_STATUS_OFFSET    0x00b8u
#define RP1_GPIO23_CONTROL_OFFSET   0x00bcu
#define RP1_GPIO24_STATUS_OFFSET    0x00c0u
#define RP1_GPIO24_CONTROL_OFFSET   0x00c4u
#define RP1_GPIO25_STATUS_OFFSET    0x00c8u
#define RP1_GPIO25_CONTROL_OFFSET   0x00ccu
#define RP1_GPIO26_STATUS_OFFSET    0x00d0u
#define RP1_GPIO26_CONTROL_OFFSET   0x00d4u
#define RP1_GPIO27_STATUS_OFFSET    0x00d8u
#define RP1_GPIO27_CONTROL_OFFSET   0x00dcu

/* ---- Interrupt offsets ---- */
#define RP1_INTR_RAW_OFFSET     0x0100u   // Raw Interrupts
#define RP1_PROC0_INTE_OFFSET   0x0104u   // Interrupt Enable for proc0
#define RP1_PROC0_INTF_OFFSET   0x0108u   // Interrupt Force for proc0
#define RP1_PROC0_INTS_OFFSET   0x010cu   // Interrupt Status for proc0
#define RP1_PROC1_INTE_OFFSET   0x0110u   // Interrupt Enable for proc1
#define RP1_PROC1_INTF_OFFSET   0x0114u   // Interrupt Force for proc1
#define RP1_PROC1_INTS_OFFSET   0x0118u   // Interrupt Status for proc1
#define RP1_PCIE_INTE_OFFSET    0x011cu   // Interrupt Enable for pcie
#define RP1_PCIE_INTF_OFFSET    0x0120u   // Interrupt Force for pcie
#define RP1_PCIE_INTS_OFFSET    0x0124u   // Interrupt Status for pcie

/* ---- Pads offsets ---- */
#define RP1_VOLTAGE_SELECT_PAD  0x0000u   // Voltage select, per bank control
#define RP1_GPIO0_PAD           0x0004u
#define RP1_GPIO1_PAD           0x0008u
#define RP1_GPIO2_PAD           0x000cu
#define RP1_GPIO3_PAD           0x0010u
#define RP1_GPIO4_PAD           0x0014u
#define RP1_GPIO5_PAD           0x0018u
#define RP1_GPIO6_PAD           0x001cu
#define RP1_GPIO7_PAD           0x0020u
#define RP1_GPIO8_PAD           0x0024u
#define RP1_GPIO9_PAD           0x0028u
#define RP1_GPIO10_PAD          0x002cu
#define RP1_GPIO11_PAD          0x0030u
#define RP1_GPIO12_PAD          0x0034u
#define RP1_GPIO13_PAD          0x0038u
#define RP1_GPIO14_PAD          0x003cu
#define RP1_GPIO15_PAD          0x0040u
#define RP1_GPIO16_PAD          0x0044u
#define RP1_GPIO17_PAD          0x0048u
#define RP1_GPIO18_PAD          0x004cu
#define RP1_GPIO19_PAD          0x0050u
#define RP1_GPIO20_PAD          0x0054u
#define RP1_GPIO21_PAD          0x0058u
#define RP1_GPIO22_PAD          0x005cu
#define RP1_GPIO23_PAD          0x0060u
#define RP1_GPIO24_PAD          0x0064u
#define RP1_GPIO25_PAD          0x0068u
#define RP1_GPIO26_PAD          0x006cu
#define RP1_GPIO27_PAD          0x0070u

/* ---- RIO offsets ---- */
#define RP1_RIO_OUT     0x0000u
#define RP1_RIO_OE      0x0004u
#define RP1_RIO_IN      0x0008u

/* ---- Alias offsets ---- */
#define RP1_RW_OFFSET   0x0000u
#define RP1_XOR_OFFSET  0x1000u
#define RP1_SET_OFFSET  0x2000u
#define RP1_CLR_OFFSET  0x3000u

/* ---- PWM control registers offsets ---- */
#define RP1_PWM_GLOBAL_CTRL     0x0000u
#define RP1_PWM_FIFO_CTRL       0x0004u
#define RP1_PWM_COMMON_RANGE    0x0008u
#define RP1_PWM_COMMON_DUTY     0x000cu
#define RP1_PWM_DUTY_FIFO       0x0010u
#define RP1_PWM_CHAN0_CTRL      0x0014u
#define RP1_PWM_CHAN0_RANGE     0x0018u
#define RP1_PWM_CHAN0_PHASE     0x001cu
#define RP1_PWM_CHAN0_DUTY      0x0020u
#define RP1_PWM_CHAN1_CTRL      0x0024u
#define RP1_PWM_CHAN1_RANGE     0x0028u
#define RP1_PWM_CHAN1_PHASE     0x002cu
#define RP1_PWM_CHAN1_DUTY      0x0030u
#define RP1_PWM_CHAN2_CTRL      0x0034u
#define RP1_PWM_CHAN2_RANGE     0x0038u
#define RP1_PWM_CHAN2_PHASE     0x003cu
#define RP1_PWM_CHAN2_DUTY      0x0040u
#define RP1_PWM_CHAN3_CTRL      0x0044u
#define RP1_PWM_CHAN3_RANGE     0x0048u
#define RP1_PWM_CHAN3_PHASE     0x004cu
#define RP1_PWM_CHAN3_DUTY      0x0050u
#define RP1_PWM_INTR            0x0054u
#define RP1_PWM_INTE            0x0058u
#define RP1_PWM_INTF            0x005cu
#define RP1_PWM_INTS            0x0060u

/* ---- Macros for GPIO dynamic indexing ---- */
#define RP1_GPIO_STATUS_OFFSET(n)   ((uintptr_t)(0x0000u+((uintptr_t)(n)*0x0008u)))
#define RP1_GPIO_CONTROL_OFFSET(n)  ((uintptr_t)(0x0004u+((uintptr_t)(n)*0x0008u)))

/* ---- Macro for Pads dynamic indexing ---- */
#define RP1_PAD_GPIO(n)   ((uintptr_t)(0x0004u+((uintptr_t)(n)*0x0004u)))

#endif /* REGISTERS_H */
