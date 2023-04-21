//Description: Implements different tasks in SD_PHY
#include <libraries/board.h>
#include <libraries/uart.h>
#include <stdio.h>
#include "msp430.h"
#include <stdbool.h>
#include <driverlib.h>
#include <settings.h>
#include <libraries/clock.h>
#include <libraries/gpio.h>
#include <task.h>
#include <sx1276/sx1276.h>
#include <ota.h>
#include <libraries/timer.h>

/**########################Variables and Types############################**/

/* LoRa radio events function pointer */
void SX1276_OnTxDone(void);
void SX1276_OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);
void SX1276_OnTxTimeout(void);
void SX1276_OnRxTimeout(void);
void SX1276_OnRxError(void);
void SX1276_FhssChangeChannel(uint8_t currentChannel);
void SX1276_CadDone(bool channelActivityDetected);


RadioEvents_t sx1276 =
{
        SX1276_OnTxDone,
        SX1276_OnTxTimeout,
        SX1276_OnRxDone,
        SX1276_OnRxTimeout,
        SX1276_OnRxError,
        SX1276_FhssChangeChannel,
        SX1276_CadDone
};

/* LoRa Settings */
#define RX_TIMEOUT_VALUE                10000
#define LORA_BANDWIDTH                  BW_250
#define LORA_SPREADING_FACTOR           SF_8
#define LORA_CODINGRATE                 CR_6
#define LORA_PREAMBLE_LENGTH            8        // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT             5         // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON      false
#define LORA_IQ_INVERSION               false
#define TX_OUTPUT_POWER                 0

extern uint8_t BR_buffer[200];
extern uint8_t transmit_cnt;
// added by ZY
static uint8_t ACK_buffer[1];
uint8_t packet_size = 0;

void task_lora_test(void)
{
    uint8_t version;

    /*
     * Initialization
     */
    ClockInit();
    BoardInitMcu();
    // added by ZY
    timerinitial();
    initUART();
    GpioWrite(&SD_PHY.LED_D1, 0);
    uart_write("Let's begin!\n");
    uart_printNum(0xff);
    /*
     * Backbone Radio
     */
    SX1276Reset();

    /* Enabling global interrupts */
    __bis_SR_register(GIE);

    uart_write("reset is ok!\n");
    version = SX1276Read(REG_VERSION);
    uart_printNum(version);
    while(version != 0x12)
    {
        GpioWrite(&SD_PHY.LED_D1, true);
        delay_ms(1);
        version = SX1276Read(REG_VERSION);
        uart_printNum(version);
    }
    GpioWrite(&SD_PHY.LED_D1, false);
//    printf("LoRa Ver: 0x%x \n", version);

    MCU_State = MCU_STATE_BR_INIT;
    /* Enabling global interrupts */
    __bis_SR_register(GIE);


    uart_write("Everything is ready!\n");

    while(1)
    {
//      printf("irq: %x\n", SX1276Read(REG_LR_IRQFLAGS));

        switch (MCU_State)
        {
        case MCU_STATE_BR_INIT:
            {
                sx1276Radio.Init(&sx1276);
                sx1276Radio.SetChannel(915000000);

                sx1276Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                                   LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                                   LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                                   true, 0, 0, LORA_IQ_INVERSION, 3000);

                sx1276Radio.SetRxConfig(MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
                                   LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
                                   LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
                                   0, true, 0, 0, LORA_IQ_INVERSION, true);
                MCU_State = MCU_STATE_UART_WAIT;
                transmit_cnt = 0;
//              SX1276SetIRQFlagMask(0xFF);

                SX1276Write(REG_LR_IRQFLAGS, SX1276Read(REG_LR_IRQFLAGS)            | 0xFF);
                SX1276Write(REG_LR_IRQFLAGSMASK, SX1276Read(REG_LR_IRQFLAGSMASK)    | 0xFF);

                break;
            }
        case MCU_STATE_UART_WAIT:
        {
            break;
        }
        case MCU_STATE_BR_TX_INIT:
            {

//              SX1276Write(REG_DIOMAPPING1, 0x40);
 //( SX1276Read( REG_DIOMAPPING1 ) & RFLR_DIOMAPPING1_DIO0_MASK ) | RFLR_DIOMAPPING1_DIO0_01 );
//                SX1276Write(REG_DIOMAPPING1, 0x40);
//                uart_printNum(SX1276Read( REG_DIOMAPPING1 ));
                SX1276SetIRQFlagMask(RFLR_IRQFLAGS_TXDONE_MASK);

//              sx1276Radio.Rx(RX_TIMEOUT_VALUE);
                MCU_State = MCU_STATE_BR_TX_WAIT;
                SX1276Send( BR_buffer, 16 );
// added by ZY
                settimer();
//                GpioToggle(&SD_PHY.LED_D1);
                SX1276Write(RegFifoAddrPtr, SX1276Read(RegFifoRxCurrentAddr));
//                uart_printNum(SX1276Read( REG_DIOMAPPING1 ));


//                if (SX1276Read( REG_DIOMAPPING1 ) == 0x40) {
//                    uart_write("DIO0 initialization OK!");
//                } else {
//                    uart_printNum(SX1276Read( REG_DIOMAPPING1 ));
//                }
//                else {
//                    MCU_State = MCU_STATE_BR_TX_INIT;
//                }

                break;
            }

        case MCU_STATE_BR_TX_WAIT:
            {
//              MAP_PCM_gotoLPM3();
                break;
            }

        case MCU_STATE_BR_TX:
            {
//                uart_write("Correctly transmitted!\n");
//
                MCU_State = MCU_STATE_UART_WAIT;
                break;
            }
// added by ZY
        case MCU_STATE_BR_RX_INIT:
            {
                SX1276SetIRQFlagMask(RFLR_IRQFLAGS_RXDONE_MASK);
                sx1276Radio.Rx(RX_TIMEOUT_VALUE);
                MCU_State = MCU_STATE_BR_RX_WAIT;
                break;
            }
        case MCU_STATE_BR_RX_WAIT:
            {
                break;
            }
        case MCU_STATE_BR_RX:
            {
                uint8_t irqFlags = SX1276Read(REG_LR_IRQFLAGS);

                SX1276Write(RegFifoAddrPtr, SX1276Read(RegFifoRxCurrentAddr));
                packet_size = SX1276ReceivePayload(ACK_buffer);
                if (ACK_buffer[0] != 0xf0)
                {
                    uart_write("Device found.\n");
                }
                MCU_State = MCU_STATE_BR_TX;
                break;
            }

        default:
            {
                MCU_State = MCU_STATE_BR_TX_INIT;
                break;
            }
        }
    }
}



/* SX1276 callbake functions */
void SX1276_OnTxDone(void)
{
    return;
}
void SX1276_OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
    return;
}
void SX1276_OnTxTimeout(void)
{
    return;
}
void SX1276_OnRxTimeout(void)
{
    return;
}
void SX1276_OnRxError(void)
{
    return;
}
void SX1276_FhssChangeChannel(uint8_t currentChannel)
{
    return;
}
void SX1276_CadDone(bool channelActivityDetected)
{
    return;
}
