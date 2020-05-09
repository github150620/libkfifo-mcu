#ifndef _KFIFO_H_
#define _KFIFO_H_

struct kfifo {
	unsigned char *buffer;
	unsigned int size;
	unsigned int in;
	unsigned int out;
};

// The 'size' should be 2^n, otherwise return -1.
int kfifo_init(struct kfifo *fifo, unsigned char *buffer, unsigned int size);

int kfifo_put(struct kfifo *fifo, char c);
int kfifo_get(struct kfifo *fifo, char *c);

#endif
