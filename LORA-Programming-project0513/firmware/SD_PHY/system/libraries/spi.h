/*
Description: Implements the generic SPI driver
*/
#ifndef _SYSTEM_SPI_H_
#define _SYSTEM_SPI_H_
#include <msp430.h>
#include <stdio.h>
#include <stdint.h>
#include <settings.h>
#include <driverlib.h>

/**#############################Variables and Types#############################**/
volatile unsigned char SPI_RXData_IQ;
volatile unsigned char SPI_RXData_LoRa;
volatile unsigned char SPI_RXData_FPGA;
volatile unsigned char SPI_RXData_Flash;

/* SPI object type definition */
typedef struct Spi_s
{
    Gpio_t MOSI;
    Gpio_t MISO;
    Gpio_t SCLK;
    Gpio_t NSS;
}Spi_t;

/**#############################Functions#############################**/
void SpiInit(void);

uint8_t SpiInOut_IQRadio(Spi_t *obj, uint8_t outData);

uint8_t SpiInOut_LoRa(Spi_t *obj, uint8_t outData);

uint8_t fpgaSpiInOut(uint8_t outData);

uint8_t flashSpiInOut(uint8_t outData);

#endif
