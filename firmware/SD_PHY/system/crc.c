// added by Shaoting

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define POLY 0x33

uint8_t crc8 (uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0;        // Initial value
    while (length--) {
        crc ^= *data++;        // crc ^= *data; data++;
        for (i = 0; i < 8; i++) {
            if (crc & 0x80)
                crc = (crc << 1) ^ POLY;
            else
                crc <<= 1;
        }
    }
    return crc;
}

bool crc8_check (uint8_t *data, uint16_t length) 
{
    uint8_t i;
    uint8_t crc = 0;        // Initial value
    while (length--) {
        crc ^= *data++;        // crc ^= *data; data++;
        for (i = 0; i < 8; i++) {
            if (crc & 0x80)
                crc = (crc << 1) ^ POLY;
            else
                crc <<= 1;
        }
    }
    if (crc == *data) return true;
    else return false;
}
