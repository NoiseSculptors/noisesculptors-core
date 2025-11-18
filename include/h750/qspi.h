#ifndef QSPI_H
#define QSPI_H

#include <stddef.h>

void init_qspi_bk2(unsigned prescaler);
int qspi_bk2_read(uint32_t addr, void *buf, size_t len);
int qspi_bk2_prog(uint32_t addr, const void *buf, size_t len);
int qspi_bk2_erase_sector_4k(uint32_t addr);
int qspi_read_jedec_id(uint8_t id[3]);
/* Optional: erase 64K block if your flash supports it */
int qspi_bk2_erase_block_64k(uint32_t addr);
/* Optional: full chip erase – be careful with this :) */
int qspi_bk2_erase_chip(void);
/* Convenience: get base offset of N-th 128KiB chunk */
uint32_t qspi_bk2_chunk128k_base(unsigned index);
/*  Optional: enable memory-mapped read/XIP from BK2 at 0x9000_0000          */
void qspi_bk2_enable_mmap_read(void);

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
