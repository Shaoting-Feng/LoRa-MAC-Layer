#ifndef _SYSTEM_UART_H_
#define _SYSTEM_UART_H_


#include "driverlib.h"
#include "stdint.h"
#include <string.h>


void uart_write(char *pbuff);
void initUART(void);
void uart_printNum(uint8_t num);
void uart_printhex8(uint8_t n);
#endif
