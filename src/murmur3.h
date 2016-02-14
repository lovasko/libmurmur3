#ifndef MURMUR3_H
#define MURMUR3_H

#include <stdint.h>

#define MURMUR3_OK       0
#define MURMUR3_E_NULL   1
#define MURMUR3_E_LENGTH 2

/**
 * Perform the Murmur3 non-cryptographic hash function.
 *
 * @param[in] data data to hash
 * @param[in] len length of the data in bytes
 * @param[in] seed parametrization of the hash function
 * @param[out] out_hash hash of the data
 * @return MURMUR3_OK on success, MURMUR3_E_* otherwise
 */
int murmur3(void* data, uint32_t len, uint32_t seed, uint32_t* out_hash);

#endif

