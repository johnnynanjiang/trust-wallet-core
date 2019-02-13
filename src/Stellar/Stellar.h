#ifndef TRUST_STELLAR_H
#define TRUST_STELLAR_H

#include <string>

std::string getString(uint8_t * charArray, int size);

void decodePublicKey(const char * publicKeyHash, uint8_t * decodedInBase32, int size);

void decodeAndDissectPublicKey(const char * publicKeyHash, uint8_t version[], uint8_t payload[], uint8_t checksum[]);

#endif