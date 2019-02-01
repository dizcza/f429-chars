/*
 * char_patterns.h
 *
 *  Created on: Jan 31, 2019
 *      Author: Danylo Ulianych
 */

#ifndef CHAR_PATTERNS_H_
#define CHAR_PATTERNS_H_

#define ALPHABET_SIZE 26
#define PATTERN_SIZE  50

#include <stdint.h>

extern const uint8_t ALPHABET[ALPHABET_SIZE];

extern const uint16_t PATTERN_COORDS_X[ALPHABET_SIZE][PATTERN_SIZE];
extern const uint16_t PATTERN_COORDS_Y[ALPHABET_SIZE][PATTERN_SIZE];

#endif /* CHAR_PATTERNS_H_ */