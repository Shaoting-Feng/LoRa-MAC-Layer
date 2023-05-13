// added by Shaoting

#ifndef CRC_CONFIGURE_H
#define CRC_CONFIGURE_H

#include <stdint.h>
#include <stdbool.h>

/******************************************************************************
 * Name:    CRC-8               x8+x2+x+1
 * Poly:    0x33
 * Init:    0x00
 * Refin:   False
 * Refout:  False
 * Xorout:  0x00
 * Note:
 *****************************************************************************/
uint8_t crc8 (uint8_t *data, uint16_t length);
bool crc8_check (uint8_t *data, uint16_t length);  // length refer to the length without crc which is 16

#endif
