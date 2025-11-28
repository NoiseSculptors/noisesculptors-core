
#ifndef QSPI_H
#define QSPI_H

#include "memory.h"
#include <stddef.h>

void init_qspi(uint8_t prescaler);
void init_qspi_80MHz(void);
void init_qspi_pll2(uint8_t prescaler);
void init_qspi_pll2_104MHz(void);
void qspi_memory_map_mode(void);
int32_t qspi_read(uint32_t addr, void *buf, size_t len);
void qspi_write_flash_qpi(uint32_t addr, const uint32_t *src, uint32_t size);

#define QUADSPI_CR      (volatile unsigned int *)(QUADSPI + 0x00)
#define QUADSPI_DCR     (volatile unsigned int *)(QUADSPI + 0x04)
#define QUADSPI_SR      (volatile unsigned int *)(QUADSPI + 0x08)
#define QUADSPI_FCR     (volatile unsigned int *)(QUADSPI + 0x0C)
#define QUADSPI_DLR     (volatile unsigned int *)(QUADSPI + 0x10)
#define QUADSPI_CCR     (volatile unsigned int *)(QUADSPI + 0x14)
#define QUADSPI_AR      (volatile unsigned int *)(QUADSPI + 0x18)
#define QUADSPI_ABR     (volatile unsigned int *)(QUADSPI + 0x1C)
#define QUADSPI_DR      (volatile unsigned int *)(QUADSPI + 0x20)
#define QUADSPI_PSMKR   (volatile unsigned int *)(QUADSPI + 0x24)
#define QUADSPI_PSMAR   (volatile unsigned int *)(QUADSPI + 0x28)
#define QUADSPI_PIR     (volatile unsigned int *)(QUADSPI + 0x2C)
#define QUADSPI_LPTR    (volatile unsigned int *)(QUADSPI + 0x30)

#endif

