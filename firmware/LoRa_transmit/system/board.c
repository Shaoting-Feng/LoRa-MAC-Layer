/*Description: SD_PHY board functionality implementations*/
#include <libraries/board.h>
#include <libraries/gpio.h>
#include <stdio.h>
#include <settings.h>

/**#############################Vatiables and Types#############################**/

/* LoRa Radio driver structure initialization */
const struct sx1276_Radio_s sx1276Radio =
{
    SX1276Init,
    SX1276GetStatus,
    SX1276SetModem,
    SX1276SetChannel,
    SX1276IsChannelFree,
    SX1276Random,
    SX1276SetRxConfig,
    SX1276SetTxConfig,
    SX1276CheckRfFrequency,
    SX1276GetTimeOnAir,
    SX1276Send,
    SX1276SetSleep,
    SX1276SetStby,
    SX1276SetRx,
    SX1276StartCad,
    SX1276ReadRssi,
    SX1276Write,
    SX1276Read,
    SX1276WriteBuffer,
    SX1276ReadBuffer,
    SX1276SetMaxPayloadLength
};

//DioIrqHandler *DioIrq2[] = { NULL, NULL,
//                            NULL, NULL,
//                            NULL, NULL };

/**#############################Functions#############################**/

void BoardInitMcu( void )
{
    SpiInit();

    BoardIoInit();
    BoardIoIrqInit();
    //TimerInit();
}

void delay_ns(uint32_t nsTime)
{
    nsTime = (uint32_t) ceil(nsTime / 1000.0);
    int i;
    for(i=0; i<nsTime; i++)
        __delay_cycles(1);
}

void delay_us(uint32_t usTime)
{
    int i;
    for (i=0; i<usTime; i++)
        __delay_cycles(CYCLES_us);
}

void BoardIoInit( void )
{


#ifdef PLATFORM_SD_PHY
/* Special Pins */
    P4SEL0 &= ~BIT3;
    P4SEL1 &= ~BIT3;
//    GPIO_disableInterrupt(GPIO_PORT_P4, GPIO_PIN3);
//    GPIO_selectInterruptEdge(GPIO_PORT_P4, GPIO_PIN3, GPIO_LOW_TO_HIGH_TRANSITION);
#endif

/*#############################################################################################################################
//  LoRa
#############################################################################################################################*/
#ifdef PLATFORM_SD_PHY
    // LoRa Radio SPI NSS pin
    GpioInit(&SX1276.Spi.NSS, PIN_SX1276_SPI_NSS.portOut, PIN_SX1276_SPI_NSS.portIn, PIN_SX1276_SPI_NSS.portDir, PIN_SX1276_SPI_NSS.pin, PIN_SX1276_SPI_NSS.portNumber, PIN_OUTPUT, true);

    //added for power test
    GpioInit(&SX1276.Spi.MISO, PIN_SX1276_SPI_MISO.portOut, PIN_SX1276_SPI_MISO.portIn, PIN_SX1276_SPI_MISO.portDir, PIN_SX1276_SPI_MISO.pin, PIN_SX1276_SPI_MISO.portNumber, PIN_INPUT, false);
    GpioInit(&SX1276.Spi.MOSI, PIN_SX1276_SPI_MOSI.portOut, PIN_SX1276_SPI_MOSI.portIn, PIN_SX1276_SPI_MOSI.portDir, PIN_SX1276_SPI_MOSI.pin, PIN_SX1276_SPI_MOSI.portNumber, PIN_OUTPUT, false);
    GpioInit(&SX1276.Spi.SCLK, PIN_SX1276_SPI_SCLK.portOut, PIN_SX1276_SPI_SCLK.portIn, PIN_SX1276_SPI_SCLK.portDir, PIN_SX1276_SPI_SCLK.pin, PIN_SX1276_SPI_SCLK.portNumber, PIN_OUTPUT, false);
//    //
    // LoRa Radio Pins
    GpioInit(&SX1276.Reset, PIN_SX1276_NRESET.portOut, PIN_SX1276_NRESET.portIn, PIN_SX1276_NRESET.portDir, PIN_SX1276_NRESET.pin, PIN_SX1276_NRESET.portNumber, PIN_OUTPUT, true);
    GpioInit(&SX1276.DIO0, PIN_SX1276_DIO0.portOut, PIN_SX1276_DIO0.portIn, PIN_SX1276_DIO0.portDir, PIN_SX1276_DIO0.pin, PIN_SX1276_DIO0.portNumber, PIN_INPUT, false);

    //LEDs
    GpioInit(&SD_PHY.LED_D1, PIN_LED_D1.portOut, PIN_LED_D1.portIn, PIN_LED_D1.portDir, PIN_LED_D1.pin, PIN_LED_D1.portNumber, PIN_OUTPUT, false);
    GpioInit(&SD_PHY.LED_D2, PIN_LED_D2.portOut, PIN_LED_D2.portIn, PIN_LED_D2.portDir, PIN_LED_D2.pin, PIN_LED_D2.portNumber, PIN_OUTPUT, false);

    //FPGA
    GpioInit(&SD_PHY.FPGA.CLK,    PIN_FPGA_CLK.portOut,  PIN_FPGA_CLK.portIn,   PIN_FPGA_CLK.portDir,  PIN_FPGA_CLK.pin,  PIN_FPGA_CLK.portNumber,   PIN_OUTPUT, false);
    GpioInit(&SD_PHY.FPGA.DATA,    PIN_FPGA_DATA.portOut,  PIN_FPGA_DATA.portIn,   PIN_FPGA_DATA.portDir,  PIN_FPGA_DATA.pin,  PIN_FPGA_DATA.portNumber,   PIN_OUTPUT, false);

#endif

}

void BoardIoIrqInit()
{
    /* LoRa IRQ */
    GpioSetInterrupt(&SX1276.DIO0, IRQ_RISING_EDGE);

}
