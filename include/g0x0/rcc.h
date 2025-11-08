
#ifndef RCC_H
#define RCC_H

#include "memory.h"

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define GPIODEN 3
#define GPIOEEN 4
#define GPIOFEN 5

#define RCC_CR             ((volatile unsigned int *)(RCC + 0x00))
#define RCC_ICSCR          ((volatile unsigned int *)(RCC + 0x04))
#define RCC_CFGR           ((volatile unsigned int *)(RCC + 0x08))
#define RCC_PLLCFGR        ((volatile unsigned int *)(RCC + 0x0C))
#define RCC_CIER           ((volatile unsigned int *)(RCC + 0x18))
#define RCC_CIFR           ((volatile unsigned int *)(RCC + 0x1C))
#define RCC_CICR           ((volatile unsigned int *)(RCC + 0x20))
#define RCC_IOPRSTR        ((volatile unsigned int *)(RCC + 0x24))
#define RCC_AHBRSTR        ((volatile unsigned int *)(RCC + 0x28))
#define RCC_APBRSTR1       ((volatile unsigned int *)(RCC + 0x2C))
#define RCC_APBRSTR2       ((volatile unsigned int *)(RCC + 0x30))
#define RCC_IOPENR         ((volatile unsigned int *)(RCC + 0x34))
#define RCC_AHBENR         ((volatile unsigned int *)(RCC + 0x38))
#define RCC_APBENR1        ((volatile unsigned int *)(RCC + 0x3C))
#define RCC_APBENR2        ((volatile unsigned int *)(RCC + 0x40))
#define RCC_IOPSMENR       ((volatile unsigned int *)(RCC + 0x44))
#define RCC_AHBSMENR       ((volatile unsigned int *)(RCC + 0x48))
#define RCC_APBSMENR1      ((volatile unsigned int *)(RCC + 0x4C))
#define RCC_APBSMENR2      ((volatile unsigned int *)(RCC + 0x50))
#define RCC_CCIPR          ((volatile unsigned int *)(RCC + 0x54))
#define RCC_CCIPR2         ((volatile unsigned int *)(RCC + 0x58))
#define RCC_BDCR           ((volatile unsigned int *)(RCC + 0x5C))
#define RCC_CSR            ((volatile unsigned int *)(RCC + 0x60))

#endif

