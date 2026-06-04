/* trampoline.S — flash-resident forwarder into RAM app
 * - Do NOT modify MSP; we keep the MSP loaded from this trampoline's flash vector.
 * - Read only PC from APP_BASE[1], set VTOR=APP_BASE, then branch.
 * - Optional: small sanity check on PC (non-zero, Thumb).
 *
 * Configurable via -D defines from CMake:
 *   APP_BASE  : RAM app vector base (default 0x24000000 for H750 AXI; 0x20000000 for G0)
 */

.syntax unified
.thumb

/* SCB registers */
.set SCB_VTOR,    0xE000ED08
.set SCB_ICIALLU, 0xE000EF50

/* turn on Szrapnel's LCD and LED */
/* LCD LED PB14 low active */
.set GPIOB_MODER, 0x58020400
/* LCD EN PD10 low active */
.set GPIOD_MODER, 0x58020C00
.set RCC_AHB4ENR, 0x580244e0

/* Szrapnel's LCD 

/* ---- minimal vector table in flash (for this trampoline) ----
 * word0: MSP value used by core on reset (adjust per part/linker)
 * word1: this Reset_Handler | 1 (Thumb)
 */
.section .isr_vector, "a", %progbits
.align  2
.word  STACK_TOP
.word  Reset_Handler + 1

.text
.thumb
.align 2
.global Reset_Handler
.type   Reset_Handler, %function

Reset_Handler:

    /* r0 := APP_BASE (RAM vector) */
    ldr   r0, =APP_BASE

    /* Load PC from APP_BASE[1] */
    ldr   r2, [r0, #4]

    /* Sanity: if zero, trap */
    cmp   r2, #0
    beq   .Ltrap

    /* Ensure Thumb bit set (in case image forgot) */
    lsls  r3, r2, #31       /* test bit0 by shifting left 31 -> N flag if bit0=1 */
    bne   .Lthumb_ok
    adds  r2, #1

.Lthumb_ok:

    /* VTOR := APP_BASE so exceptions go to RAM app */
    ldr   r3, =SCB_VTOR
    str   r0, [r3]
    dsb   sy
    isb

    /* Invalidate I-cache  */
    ldr   r3, =SCB_ICIALLU
    movs  r4, #0
    str   r4, [r3]
    dsb   sy
    isb

    /* Turn on GPIOB and GPIOD clocks */
    ldr   r3, =RCC_AHB4ENR
    ldr   r5, [r3]
    movs  r4, #10           /* Turn on GPIOD (bit 3) and GPIOB (bit 1) */
    orrs  r4, r5, r4
    str   r4, [r3]

    /* Turn on LCD LED (PB14) */
    ldr   r3, =GPIOB_MODER
    ldr   r4, [r3]
    movs  r5, #1
    lsls  r5, r5, #29       /* Target bit 29 */
    bics  r4, r4, r5        /* Clears bit 29 (11 -> 01 Output) */
    str   r4, [r3]

    /* Turn on LCD Power (PD10) */
    ldr   r3, =GPIOD_MODER
    ldr   r4, [r3]
    lsrs  r5, r5, #8        /* Shift bit 29 down by 8 positions to make it bit 21 */
    bics  r4, r4, r5        /* Clears bit 21 (11 -> 01 Output) */
    str   r4, [r3]

    /* Jump to RAM app Reset_Handler (keep current MSP) */
    bx    r2

.Ltrap:

    /* Hang if PC invalid */
    b     .Ltrap

.size Reset_Handler, .-Reset_Handler

