#define is_power_of_2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0 ))

struct kfifo {
	unsigned char *buffer;
	unsigned int size;
	unsigned int in;
	unsigned int out;
};

int kfifo_init(struct kfifo *fifo, unsigned char *buffer, unsigned int size) {
	if (!fifo) return -1;
	if (!buffer) return -1;
	if (!is_power_of_2(size)) return -1;

	fifo->buffer  = buffer;
	fifo->size    = size;
	fifo->in      = 0;
	fifo->out     = 0;
	
	return 0;
}

int kfifo_put(struct kfifo *fifo, char c) {
	if (fifo->in + 1 == fifo->out) return -1;
	
	fifo->buffer[fifo->in & (fifo->size - 1)] = c;
	fifo->in++;
	
	return 0;
}

int kfifo_get(struct kfifo *fifo, char *p) {
	if (fifo->in == fifo->out) return -1;
	
	*p = fifo->buffer[fifo->out & (fifo->size - 1)];
	fifo->out++;
	
	return 0;
}
