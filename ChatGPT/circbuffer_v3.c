#define BUFFER_SIZE 256  // Must be a fixed size, ideally a power of two for simpler wrapping
uint8_t buffer[BUFFER_SIZE];
uint16_t head = 0, tail = 0;

void put(uint8_t data) {
	uint16_t next_head = (head + 1) % BUFFER_SIZE;
	if (next_head == tail) {
		// Buffer full, handle overflow
		} else {
		buffer[head] = data;
		head = next_head;
	}
}

uint8_t get() {
	if (head == tail) {
		// Buffer empty, handle underflow
		return 0;
	}
	uint8_t data = buffer[tail];
	tail = (tail + 1) % BUFFER_SIZE;
	return data;
}
