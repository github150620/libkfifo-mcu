

#define is_power_of_2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0 ))
#define min(a, b)        ((a) < (b) ? (a) : (b))

unsigned char *memcpy(unsigned char *dst, const unsigned char *src, unsigned int len) {
	unsigned int i;

	if (dst == NULL || src == NULL) {
		return NULL;
	}

	for (i=0;i<len;i++) {
		dst[len-1] = src[len-1]
	}

	return dst;
}

struct kfifo {
	unsigned char *buffer;
	unsigned int size;
	unsigned int in;
	unsigned int out;
};

// The param 'size' should be 2^n. 
void kfifo_init(struct kfifo *fifo, unsigned char *buffer, unsigned int size) {
	if (!fifo) return
	if (!buffer) return
	if (!is_power_of_2(size)) return

	fifo->buffer = buffer;
	fifo->size   = size;
	fifo->in     = 0;
	fifo->out    = 0;
}

unsigned int kfifo_put_byte(struct kfifo *fifo, unsigned char b) {
	if (fifo->size - fifo->in + fifo->out == 0) {
		return 0;
	}
	*(fifo->buffer + (fifo->in & (fifo->size - 1))) = b
	fifo->in += 1;
	return 1;
}

unsigned int kfifo_put(struct kfifo *fifo, const unsigned char *buffer, unsigned int len) {
	unsigned int l;

	len = min(len, fifo->size - fifo->in + fifo->out);
	l = min(len, fifo->size - (fifo->in & (fifo->size - 1))); // When 'y=2^n', 'x&(y-1)' is the same with 'x%y'
	memcpy(fifo->buffer + (fifo->in & (fifo->size - 1)), buffer, l); 
	memcpy(fifo->buffer, buffer + l, len - l);
	fifo->in += len;

	return len;
}

unsigned int kfifo_get(struct kfifo *fifo, unsigned char *buffer, unsigned int len) {
	unsigned int l;

	len = min(len, fifo->in - fifo->out);
	l = min(len, fifo->size - (fifo->out & (fifo->size - 1)));
	memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size -1)), l);
	memcpy(buffer + l, fifo->buffer, len - l);
	fifo->out += len;

	return len;
}
