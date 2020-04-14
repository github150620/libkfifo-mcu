# libkfifo-mcu
* For UART receive data.
* Not thread safe, but it's safe to 'put' in IRQ and 'get' in main().

## How to use
```
#include "kfifo.h"

#include "stm8s003f.h"

struct kfifo fifo;
unsigned char fifo_buffer[128]; // The size of fifo_buffer MUST BE 2^n.

unsigned char buf[32];

@far @interrupt void UART1_RCV_IRQHandler(void) {
  kfifo_put_byte(&fifo, UART1_DR);
}

void main() {
  kfifo_init(&fifo, fifo_buffer, sizeof(fifo_buffer));

  while (1) {
    kfifo_get(&fifo, buf);
    ...
   }
}
```
