#ifndef _KFIFO_H_
#define _KFIFO_H_

struct kfifo {
	unsigned char *buffer;
	unsigned int size;
	unsigned int in;
	unsigned int out;
};

// The param 'size' should be 2^n.
void kfifo_init(struct kfifo *fifo, unsigned char *buffer, unsigned int size);

unsigned int kfifo_put_byte(struct kfifo *fifo, unsigned char b);
unsigned int kfifo_put(struct kfifo *fifo, const unsigned char *buffer, unsigned int len);
unsigned int kfifo_get(struct kfifo *fifo, unsigned char *buffer, unsigned int len);

#endif
