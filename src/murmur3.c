#include <stdlib.h>

#include "murmur3.h"

#define MM3_C1 0xcc9e2d51
#define MM3_C2 0x1b873593
#define MM3_C3 0x85ebca6b
#define MM3_C4 0xc2b2ae35

#define MM3_R1 15
#define MM3_R2 13

#define MM3_M 5
#define MM3_N 0xe6546b64

#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))

int
murmur3(void* data, uint32_t len, uint32_t seed, uint32_t* out_hash)
{
	uint32_t* runner;
	uint32_t i;
	uint32_t hash;
	uint32_t block; 

	if (data == NULL)
		return MURMUR3_E_NULL;

	if (len == 0)
		return MURMUR3_E_LENGTH;

	hash = seed;
	runner = (uint32_t*)data;

	for (i = 0; i < len/4; i++, runner++) {
		block = *runner;
		block *= MM3_C1;
		block = ROTATE_LEFT(block, MM3_R1);
		block *= MM3_C2;

		hash ^= block;
		hash = ROTATE_LEFT(hash, MM3_R2);
		hash = hash * MM3_M + MM3_N;
	}

	block = (*runner) & ((1 << ((len & 3)*8))-1);
	block *= MM3_C1;
	block = ROTATE_LEFT(block, MM3_R1);
	block *= MM3_C2;

	hash ^= block;
	hash ^= len;
	hash ^= (hash >> 16);
	hash *= MM3_C3;
	hash ^= (hash >> 13);
	hash *= MM3_C4;
	hash ^= (hash >> 16);

	*out_hash = hash;
	return MURMUR3_OK;
}

