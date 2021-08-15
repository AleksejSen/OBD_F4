/*
 * printf.c
 *
 *  Created on: Apr 13, 2021
 *      Author: alex
 */
#define USB
//#define UART

#include "printf.h"

#ifdef UART
#include "usart.h"
#endif


/*Printf stuff:*/
#ifdef UART
int __io_putchar(int ch) {
	uint8_t c[1];
	c[0] = ch & 0x00FF;

	HAL_UART_Transmit(&huart2, &*c, 1, 10);

	return ch;
}
#endif

int _write(int file, char *ptr, int len) {

#ifdef USB
	CDC_Transmit_FS((uint8_t*) ptr, len);
#endif

#ifdef UART
	int DataIdx;
	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		__io_putchar(*ptr++);
	}
#endif
	return len;
}

