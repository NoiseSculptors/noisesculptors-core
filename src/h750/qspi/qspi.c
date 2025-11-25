
#include "delay.h"
#include "gpio.h"
#include "init.h"
#include "qspi.h"
#include "rcc.h"
#include <stdint.h>

static uint8_t pll2_enabled = 0;

/* https://www.st.com/resource/en/errata_sheet/es0445-stm32h745xig-stm32h755xi-stm32h747xig-stm32h757xi-device-errata-stmicroelectronics.pdf */

/* The code below have to be executed upon reset and upon switching from
 * memory-mapped to any other mode */
void qspi_st_workaround(void)
{
    // Save QSPI_CR and QSPI_CCR values if necessary
    *QUADSPI_CR = 0; // ensure that prescaling factor is not at maximum, and
                       // disable the perip heral
    while(*QUADSPI_SR & 0x20){}; // wait for BUSY flag to fall if not already low
    *QUADSPI_CR = 0xFF000001; // set maximum prescaling factor, and enable
                                // the peripheral
    *QUADSPI_CCR = 0x20000000; // activate the free-running clock
    *QUADSPI_CCR = 0x20000000; // repeat the previous instruction to prevent
                                 // a back-to-back disable
    // The following command must complete less than 127 kernel clocks after
    // the first write to the QSPI_CCR register
    *QUADSPI_CR = 0; // disable QSPI
    while(*QUADSPI_SR & 0x20){}; // wait for busy to fall
    // Restore CR and CCR values if necessary
}

static void qspi_send_instruction(uint8_t instruction)
{
    *QUADSPI_CCR =
            (0x4u<<18)    // 22:18 DCYC    no of dummy cycles 
           |(0x2u<<12)    // 13:12 ADSIZE  address size (2: 24bit)
           |(0x1u<<8)     // 9:8   IMODE   instruction mode
           |instruction;  // 7:0

    while(*QUADSPI_SR & (1<<5)) // BUSY
        __asm__("nop");
}

void init_qspi(uint8_t prescaler)
{
    qspi_st_workaround();

    *RCC_CR &= ~(1<<26); /* erase PLL2ON */

    /* QSPISEL clock source:
        0:rcc_hclk3 (default)
        1:pll1_q_ck
        2:pll2_r_ck
        3:per_ck */
    *RCC_D1CCIPR &= ~(3u<<4);

    if(pll2_enabled){
        /* pll2 to 208MHz */
        pll_2_start(PLLSRC_HSE, 2, 16, 0u, 104, 104, 1, 26000000u);
        *RCC_D1CCIPR |= (2u<<4);
    }

    *RCC_AHB4ENR |= (0x1u<<GPIOBEN) | (0x1u<<GPIOCEN) | (0x1u<<GPIOEEN);

    *RCC_AHB3ENR |= (0x1u << 14); // QSPIEN

    while(*QUADSPI_SR & (1<<5)) // BUSY
        __asm__("nop");

    /*
    PB2   QSPI_CLK  AF9
    PC11  BK2_NCS  AF9
    PE7   BK2_IO0  AF10
    PE8   BK2_IO1  AF10
    PE9   BK2_IO2  AF10
    PE10  BK2_IO3  AF10
    */

    *GPIOB_MODER &= ~(0x3u<<(MODER2));
    *GPIOB_MODER |=  (0x2u<<(MODER2));
    *GPIOB_OSPEEDR |=(0x1u<<(OSPEED2));
    *GPIOB_AFRL  &= ~(0xFu<<(AFR2));
    *GPIOB_AFRL  |=  (0x9u<<(AFR2));

    *GPIOC_MODER &= ~(0x3u<<(MODER11));
    *GPIOC_MODER |=  (0x2u<<(MODER11));
    *GPIOC_OSPEEDR |=(0x1u<<(OSPEED11));
    *GPIOC_AFRH  &= ~(0xFu<<(AFR11));
    *GPIOC_AFRH  |=  (0x9u<<AFR11);

    *GPIOE_MODER &= ~((0x3u<<(MODER7))|(0x3u<<(MODER8))|(0x3u<<(MODER9))|(0x3u<<(MODER10)));
    *GPIOE_MODER |=   (0x2u<<(MODER7))|(0x2u<<(MODER8))|(0x2u<<(MODER9))|(0x2u<<(MODER10));
    *GPIOE_OSPEEDR |= (0x1u<<(OSPEED7))|(0x1u<<(OSPEED8))|(0x1u<<(OSPEED9))|(0x1u<<(OSPEED10));
    *GPIOE_AFRL  &= ~(0xFu<<AFR7);
    *GPIOE_AFRL  |=  (0xAu<<AFR7);
    *GPIOE_AFRH  &= ~((0xFu<<AFR8)|(0xFu<<AFR9)|(0xFu<<AFR10));
    *GPIOE_AFRH  |=    (0xAu<<AFR8)|(0xAu<<AFR9)|(0xAu<<AFR10);

    *QUADSPI_DCR |=
        (0x17<<16) // 20:16 FSIZE   (2^23+1)/1024/1024 = 16MB (spi flash size)
      | (0x7u<<8)  // 10:8  CSHT    chip select high time
      | (0x1u<<0); // 0     CKMODE  1 CLK stays high while NCS high (mode 3)

    *QUADSPI_CR =
      (prescaler<<24) // 31:24 PRESCALER clock prescaler 
           |(0x7u<<8) // 12:8  FTHRES FIFO threshold flag setting
                      //       level for in indirect mode 
           |(0x1u<<7) //  7    FSEL 0:BK1 1:BK2 selection
           |(0x0u<<6) //  6    DFM dual flash mode
           |(0x1u<<4) //  4    SSHIFT 0: no shift 1: half cycle shift
           |(0x0u<<3) //  3    TCEN enable timeout mode for memory
                      //       mapped mode to lower flash consumption
           |(0x0u<<1) //  1    ABORT 1: abort requested
           |(0x1u<<0);//  0    EN QUADSPI enabled 

    /* switch the flash chip from SPI mode to QPI mode */
    qspi_send_instruction(0x38); // 0x38 Enter QPI Mode

}

void init_qspi_pll2_clock_source_qspi_104MHz(void)
{
    pll2_enabled = 1;
    init_qspi(1); /* prescaler 1, 208MHz/2 = 104MHz */
}

void qspi_memory_map_mode(void)
{
   *QUADSPI_CCR =
            (0x3u<<26)  // 27:26 FMODE   functional mode (3: memory mapped)
           |(0x3u<<24)  // 25:24 DMODE   data mode (3: data on 4 lines)
           |(0x0u<<18)  // 22:18 DCYC    no of dummy cycles 
           |(0x0u<<16)  // 17:16 ABSIZE  alternate byte size (0: 8bit)
           |(0x0u<<14)  // 15:14 ABMODE  alternate byte mode (0: no alt. bytes)
           |(0x3u<<12)  // 13:12 ADSIZE  address size (3: 32bit)
           |(0x3u<<10)  // 11:10 ADMODE  address mode (3: addr on 4 lines)
           |(0x1u<<8)   // 9:8   IMODE   instruction mode
           |(0xe3<<0);  // 7:0   instruction

/* 8.2.13 Octal Word Read Quad I/O (E3h)
The Octal Word Read Quad I/O (E3h) instruction is similar to the Fast Read Quad
I/O (EBh) instruction except that the lower four Address bits (A0, A1, A2, A3)
must equal 0.

*** As a result, the dummy clocks are not required,***

which further reduces the instruction overhead allowing even faster random
access for code execution (XIP). The Quad Enable bit (QE) of Status Register-2
must be set to enable the Octal Word Read Quad I/O Instruction. */

    while(*QUADSPI_SR & (1<<5)) // BUSY
        __asm__("nop");
}

