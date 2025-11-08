
#include "delay.h"
#include "dwt.h"
#include "init.h"
#include <stdint.h>


static uint32_t sysclk_hz; /* cached CPU clock (Hz) */

void init_dwt(const clock_info_t *ci)
{
    sysclk_hz = ci->sysclk_hz;

    *DWT_CYCCNT = 0;
    *DEMCR |= (1u << 24);  /* enable trace and debug block */
    *DWT_CTRL  |= 1u;      /* enable cycle counter */
}

void dwt_start(void)
{
    *DWT_CYCCNT = 0;       /* reset counter */
}

uint32_t dwt_now(void)
{
    return *DWT_CYCCNT;
}

double dwt_cycles_to_s(uint32_t cycles)
{
    return (double)cycles/(double)sysclk_hz;
}

double dwt_cycles_to_ms(uint32_t cycles)
{
    return (double)cycles/((double)sysclk_hz/(double)1000.0);
}

double dwt_cycles_to_us(uint32_t cycles)
{
    return (double)cycles/((double)sysclk_hz/(double)1000000.0);
}

