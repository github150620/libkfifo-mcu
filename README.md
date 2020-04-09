# libkfifo-mcu
* Designed For UART receive data.
* Not thread safe, but it's safe to 'put' in IRQ and 'get' in main().

## How to use
```
#include "kfifo.h"

struct kfifo fifo;
unsigned char fifo_buffer[128];

unsigned char buf[32];

void main() {
  kfifo_init(&fifo, fifo_buffer, sizeof(fifo_buffer));

  kfifo_put_byte(&fifo, 'A');
  kfifo_put_byte(&fifo, 'B');
  kfifo_put_byte(&fifo, 'C');
  
  kfifo_get(&fifo, buf);
  ...
}
```
