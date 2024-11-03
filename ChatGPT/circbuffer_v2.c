#define BUFFER_SIZE 8               // Must be a power of two
#define BUFFER_MASK (BUFFER_SIZE - 1) // Mask for wrapping

uint8_t buffer[BUFFER_SIZE];
uint32_t head = 0;
uint32_t tail = 0;

// Add data to the buffer
void put(uint8_t data) {
	if (((head + 1) & BUFFER_MASK) == (tail & BUFFER_MASK)) {
		// Buffer is full
		return;
	}
	buffer[head & BUFFER_MASK] = data;
	head++;
}

// Get data from the buffer
uint8_t get() {
	if (head == tail) {
		// Buffer is empty
		return 0;
	}
	uint8_t data = buffer[tail & BUFFER_MASK];
	tail++;
	return data;
}
