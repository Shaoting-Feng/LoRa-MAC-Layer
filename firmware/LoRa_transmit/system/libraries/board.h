#ifndef _SYSTEM_BOARD_H_
#define _SYSTEM_BOARD_H_

#include <sx1276/sx1276.h>
#include <libraries/spi.h>
//#include <libraries/timer.h>
//#include <libraries/power.h>
#include <libraries/gpio.h>
#include <settings.h>

/**#############################Vatiables and Types#############################**/
typedef struct
{
    Gpio_t      CLK;
    Gpio_t      DATA;
}FPGA_t;


typedef struct
{
    Gpio_t      A0;
    Gpio_t      A1;
    Switch_t    RF09_Mode;
}RF_SW_t;

typedef struct RF_PA_s
{
    Gpio_t      CPS;
    Gpio_t      CTX;
    Gpio_t      CRX;
    Gpio_t      CSD;
}RF_PA_t;

typedef struct Clock_s
{
//    bool        LFX;
//    bool        HFX;
//    uint32_t    Source;
//    uint32_t    HFX_Freq;
//    uint32_t    LFX_Freq;

    uint32_t    MCLK;
    uint32_t    ACLK;
    uint32_t    MODCLK;
    uint32_t    SMCLK;
    uint32_t    VLOCLK;
}Clock_t;

typedef struct Board_s
{
    Gpio_t              LED_D1;
    Gpio_t              LED_D2;

    FPGA_t              FPGA;
//    FLASH_t             FLASH;

//    Gpio_t              D2_CTL1;
//    Gpio_t              D2_CTL2;
//    Gpio_t              D2_CTL3;
//    Gpio_t              PWR_3P0;
//
//    RF_SW_t             RF09_SW;
//    RF_PA_t             PA09;
//    RF_PA_t             PA24;

    //I2C_t               IF_I2C;
    Clock_t             Clock;
}Board_t;



extern SX1276_t SX1276;
extern Board_t SD_PHY;

/**#############################External Functions#############################**/\
//void BoardPWRInit(void);
void BoardInitMcu( void );
void delay_ns(uint32_t nsTime);

void delay_us(uint32_t msTime);
void delay_ms(uint32_t msTime);

void BoardIoInit( void );
void BoardIoIrqInit( void );


#endif
