#pragma once

#include "common.h"


struct NF_RingBuffer {
	uint8_t *buffer;

	uint32_t cellSize;
	uint32_t cellCount;

	uint32_t head;
	uint32_t size;

	uint64_t skipCount;

	PKSPIN_LOCK lock;
};

struct NF_RingBuffer_Entry {
	uint8_t *buffer;
	uint32_t size;
};

// NF_RingBuffer_Init initializes a defined NF_RingBuffer object.
void NF_RingBuffer_Init(NF_RingBuffer *rb, uint32_t cellSize, uint32_t cellCount);

// NF_RingBuffer_Dispose disposes of internal NF_RingBuffer resources.
void NF_RingBuffer_Dispose(NF_RingBuffer *rb);

// NF_RingBuffer_Push pushes a block of data on the tail of the buffer.
void NF_RingBuffer_Push(NF_RingBuffer *rb, uint8_t *buffer, uint32_t len);

// NF_RingBuffer_Pop reads what is currently at the head of the buffer.
NF_RingBuffer_Entry NF_RingBuffer_Pop(NF_RingBuffer *rb);