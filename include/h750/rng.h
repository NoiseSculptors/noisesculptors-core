#ifndef RNG_H
#define RNG_H

#include "memory.h"

void init_rng(void);
unsigned rng_rnd(void);

#define RNG_CR           (volatile unsigned int *)(RNG + 0x00)
#define RNG_SR           (volatile unsigned int *)(RNG + 0x04)
#define RNG_DR           (volatile unsigned int *)(RNG + 0x08)

#endif
