
#ifndef PWR_H
#define PWR_H

#include "memory.h"

#define PWR_CR1        ((volatile unsigned int *)(PWR + 0x00))
#define PWR_CR2        ((volatile unsigned int *)(PWR + 0x04))
#define PWR_CR3        ((volatile unsigned int *)(PWR + 0x08))
#define PWR_CR4        ((volatile unsigned int *)(PWR + 0x0C))
#define PWR_SR1        ((volatile unsigned int *)(PWR + 0x10))
#define PWR_SR2        ((volatile unsigned int *)(PWR + 0x14))
#define PWR_SCR        ((volatile unsigned int *)(PWR + 0x18))
#define PWR_PUCRA      ((volatile unsigned int *)(PWR + 0x20))
#define PWR_PDCRA      ((volatile unsigned int *)(PWR + 0x24))
#define PWR_PUCRB      ((volatile unsigned int *)(PWR + 0x28))
#define PWR_PDCRB      ((volatile unsigned int *)(PWR + 0x2C))
#define PWR_PUCRC      ((volatile unsigned int *)(PWR + 0x30))
#define PWR_PDCRC      ((volatile unsigned int *)(PWR + 0x34))
#define PWR_PUCRD      ((volatile unsigned int *)(PWR + 0x38))
#define PWR_PDCRD      ((volatile unsigned int *)(PWR + 0x3C))
#define PWR_PUCRE      ((volatile unsigned int *)(PWR + 0x40))
#define PWR_PDCRE      ((volatile unsigned int *)(PWR + 0x44))
#define PWR_PUCRF      ((volatile unsigned int *)(PWR + 0x48))
#define PWR_PDCRF      ((volatile unsigned int *)(PWR + 0x4C))

#endif

