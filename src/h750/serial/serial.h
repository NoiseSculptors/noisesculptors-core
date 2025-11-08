#ifndef SERIAL_H
#define SERIAL_H

#include "init.h"

/*
Used by qspi on Calibrator750 so choose some other pair:
PC11 QUADSPI_BK2_NCS
PE7  QUADSPI_BK2_IO0
PE8  QUADSPI_BK2_IO1

Used on Rocket Calibrator prototype
#define USART3_PB11_RX_PB10_TX ... RX TX 3V3 GND

Define only one:
#define LPUART1_PA10_RX_PA9_TX
#define LPUART1_PB7_RX_PB6_TX
#define UART4_PA1_RX_PA0_TX
#define UART4_PB8_RX_PB9_TX
#define UART4_PC11_RX_PC10_TX
#define UART4_PD0_RX_PD1_TX
#define UART5_PB12_RX_PB13_TX
#define UART5_PB5_RX_PB6_TX
#define UART5_PD2_RX_PC12_TX
#define UART7_PB3_RX_PB4_TX
#define UART7_PE7_RX_PE8_TX
#define UART7_PA8_RX_PA15_TX
#define UART8_PE0_RX_PE1_TX
#define USART1_PA10_RX_PA9_TX
#define USART1_PB15_RX_PB14_TX
#define USART1_PB7_RX_PB6_TX
#define USART2_PA3_RX_PA2_TX
#define USART2_PD6_RX_PD5_TX
#define USART3_PB11_RX_PB10_TX
#define USART3_PC11_RX_PC10_TX
#define USART3_PD9_RX_PD8_TX
#define USART6_PC7_RX_PC6_TX
*/

/* for example 
#define USART3_PB11_RX_PB10_TX
*/

#define USART1_PA10_RX_PA9_TX


void init_serial(const clock_info_t *, unsigned baud);
void serial_write_char(int c);
int serial_read_char(void);

/* if you use more than one */
void init_lpuart1_pa10_pa9(const clock_info_t *, unsigned);
void init_lpuart1_pb7_pb6(const clock_info_t *, unsigned);
void init_uart4_pa1_pa0(const clock_info_t *, unsigned);
void init_uart4_pb8_pb9(const clock_info_t *, unsigned);
void init_uart4_pc11_pc10(const clock_info_t *, unsigned);
void init_uart4_pd0_pd1(const clock_info_t *, unsigned);
void init_uart5_pb12_pb13(const clock_info_t *, unsigned);
void init_uart5_pb5_pb6(const clock_info_t *, unsigned);
void init_uart5_pd2_pc12(const clock_info_t *, unsigned);
void init_uart7_pb3_pb4(const clock_info_t *, unsigned);
void init_uart7_pe7_pe8(const clock_info_t *, unsigned);
void init_uart7_pa8_pa15(const clock_info_t *, unsigned);
void init_uart8_pe0_pe1(const clock_info_t *, unsigned);
void init_usart1_pa10_pa9(const clock_info_t *, unsigned);
void init_usart1_pb15_pb14(const clock_info_t *, unsigned);
void init_usart1_pb7_pb6(const clock_info_t *, unsigned);
void init_usart2_pa3_pa2(const clock_info_t *, unsigned);
void init_usart2_pd6_pd5(const clock_info_t *, unsigned);
void init_usart3_pb11_pb10(const clock_info_t *, unsigned);
void init_usart3_pc11_pc10(const clock_info_t *, unsigned);
void init_usart3_pd9_pd8(const clock_info_t *, unsigned);
void init_usart6_pc7_pc6(const clock_info_t *, unsigned);

void lpuart1_write_char(int c);
void uart4_write_char(int c);
void uart5_write_char(int c);
void uart7_write_char(int c);
void uart8_write_char(int c);
void usart1_write_char(int c);
void usart2_write_char(int c);
void usart3_write_char(int c);
void usart6_write_char(int c);

int lpuart1_read_char(void);
int uart4_read_char(void);
int uart5_read_char(void);
int uart7_read_char(void);
int uart8_read_char(void);
int usart1_read_char(void);
int usart2_read_char(void);
int usart3_read_char(void);
int usart6_read_char(void);

#endif
