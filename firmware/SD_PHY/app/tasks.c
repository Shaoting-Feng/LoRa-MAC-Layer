/* Description: Implements different tasks in SD_PHY */
#include <libraries/board.h>
#include <libraries/uart.h>
#include <stdio.h>
#include "msp430.h"
#include <stdbool.h>
#include <driverlib.h>
#include <settings.h>
#include <libraries/clock.h>
#include <task.h>
#include <sx1276/sx1276.h>
#include <ota.h>

// added by Shaoting
#include <libraries/ack.h>

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
#define LORA_PREAMBLE_LENGTH            8         // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT             5         // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON      false
#define LORA_IQ_INVERSION               false
#define TX_OUTPUT_POWER                 0

uint8_t packet_size = 0;
static uint8_t BR_buffer[RFLR_PAYLOADMAXLENGTH];

// added by Shaoting
extern uint8_t ACK_buffer[1];
extern uint8_t transmit_cnt_2;
bool sleep_flag;

void task_lora_test(void)
{
    uint8_t version;
//    uint16_t packet_size;

    /*
     * Initialization
     */
    ClockInit();
    BoardInitMcu();
    initUART();
    GpioWrite(&SD_PHY.LED_D1, 0);
    uart_write("Let's begin!\n");
    /*
     * Backbone Radio
     */
    SX1276Reset();

    /* Enabling global interrupts */
    __bis_SR_register(GIE);

    uart_write("Reset is ok!\n");
    version = SX1276Read(REG_VERSION);

    // deleted by Shaoting
    // uart_printNum(version);

    while(version != 0x12)
    {
//        GpioWrite(&SD_PHY.LED_D1, true);
        delay_ms(1);
        version = SX1276Read(REG_VERSION);

        // deleted by Shaoting
        // uart_printNum(version);
    }
//    GpioWrite(&SD_PHY.LED_D1, false);
//    printf("LoRa Ver: 0x%x \n", version);

    MCU_State = MCU_STATE_BR_INIT;


    uint8_t irqFlags;

    uart_write("Everything is ready!\n");

    // added by Shaoting
    sleep_flag = false;

    while(1)
    {

        switch (MCU_State)
        {
        case MCU_STATE_BR_INIT: // 鍙戠�?鐨凚R_INIT鍙�?鍏跺浜唗ransmit_cnt鐨勮缃�?
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
                MCU_State = MCU_STATE_BR_RX_INIT;
//              SX1276SetIRQFlagMask(0xFF);

                // added by Shaoting
                transmit_cnt_2 = 0;

                SX1276Write(REG_LR_IRQFLAGS, SX1276Read(REG_LR_IRQFLAGS)            | 0xFF);
                SX1276Write(REG_LR_IRQFLAGSMASK, SX1276Read(REG_LR_IRQFLAGSMASK)    | 0xFF);

                break;
            }
        case MCU_STATE_BR_RX_INIT:
            {
                SX1276SetIRQFlagMask(RFLR_IRQFLAGS_RXDONE_MASK);

                sx1276Radio.Rx(RX_TIMEOUT_VALUE);

                MCU_State = MCU_STATE_BR_RX_WAIT;
                break;
            }
        case MCU_STATE_BR_RX_WAIT:
            {
//              MAP_PCM_gotoLPM3();
                break;
            }
        case MCU_STATE_BR_RX:
            {
                irqFlags = SX1276Read(REG_LR_IRQFLAGS);

                SX1276Write(RegFifoAddrPtr, SX1276Read(RegFifoRxCurrentAddr));
                packet_size = SX1276ReceivePayload(BR_buffer);

                // deleted by Shaoting
                // uart_write("Already received!\n");
                // uart_printNum(irqFlags);

                if((irqFlags & RFLR_IRQFLAGS_PAYLOADCRCERROR_MASK) != RFLR_IRQFLAGS_PAYLOADCRCERROR)
                {
                    // deleted by Shaoting
                    // uart_write("Correctly received!\n");

                    // added by Shaoting
                    uart_write("Correctly received a packet.\n");

                    GpioWrite(&SD_PHY.FPGA.DATA, 0);
                    uint8_t tmp;
                    int i,j;

                    // added by Shaoting
                    // id setted as NO.2
                    if (BR_buffer[0] >= 0x20 && BR_buffer[0] <= 0x2f) { // id matches
                        uart_write("This is my packet.\n");
                        if (BR_buffer[0] == 0x24) { // normal transmission

                            for (i = 1; i <= 14; i++) { // 渚濇妫�鏌ユ瘡涓�瀛�?�妭锛屼篃灏辨槸BR_buffer�?�?1-14椤癸紝鍥犱负绗�0椤�?�槸璁剧疆濂界殑
                                tmp = BIT7;
                                for (j = 0; j < 8; ++j) { // 渚濇妫�鏌ユ瘡涓�椤圭�?8涓猙it
                                    // 鍦⊿D_PHY.FPGA.DATA閲岄潰渚濇鍐�14*8涓�1鎴栬��0
                                    // 鏍�?�嵁domain6锛�?�reamble鍗�3涓瓧鑺傦紝id鍗�2涓瓧鑺傦紝type鍗�0.5涓瓧鑺傦紝鍓╀笅鐨�?槸ramdata
                                    if (BR_buffer[i] & tmp) {
                                        GpioWrite(&SD_PHY.FPGA.DATA, 1);
                                    } else {
                                        GpioWrite(&SD_PHY.FPGA.DATA, 0);
                                    }
                                    delay_us(50);
                                    GpioWrite(&SD_PHY.FPGA.CLK, 1);
                                    delay_us(100);
                                    GpioWrite(&SD_PHY.FPGA.CLK, 0);
                                    delay_us(50);
                                    tmp = tmp >> 1;
                                }
                            }
                            GpioWrite(&SD_PHY.FPGA.DATA, 0);
                            for (i = 14; i <= 107; i++) {
                                for (j = 0; j < 8; ++j) {
                                    delay_us(50);
                                    GpioWrite(&SD_PHY.FPGA.CLK, 1);
                                    delay_us(100);
                                    GpioWrite(&SD_PHY.FPGA.CLK, 0);
                                    delay_us(50);
                                }
                            }

                            ACK_Configure(1);
                        }
                        else if (BR_buffer[0] == 0x20) { // go to sleep
                            ACK_Configure(0);
                            sleep_flag = true;

                            // deleted by Shaoting
                            // SetSwitchMode(SDPHY_MODE);
                        }
                        else if (BR_buffer[0] == 0x28) { // broadcast
                            ACK_Configure(2);
                        }

                        // added by Shaoting
                        MCU_State = MCU_STATE_BR_TX_INIT_2;
                    }
                    else {
                        uart_write("This is not my packet.\n");
                        MCU_State = MCU_STATE_BR_RX_INIT;
                    }

                    // deleted by Shaoting
                    // SX1276SetIRQFlagMask(RFLR_IRQFLAGS_PAYLOADCRCERROR_MASK + RFLR_IRQFLAGS_RXDONE_MASK);
                    // MCU_State = MCU_STATE_BR_RX_INIT;
                    // break;
                }
                else
                {
                    // deleted by Shaoting
                    // SX1276SetIRQFlagMask(RFLR_IRQFLAGS_PAYLOADCRCERROR_MASK + RFLR_IRQFLAGS_RXDONE_MASK);
                    
                    MCU_State = MCU_STATE_BR_RX_INIT;

                    // added by Shaoting
                    uart_write("Incorrectly received!\n");
                }
                SX1276SetIRQFlagMask(RFLR_IRQFLAGS_PAYLOADCRCERROR_MASK + RFLR_IRQFLAGS_RXDONE_MASK);
                break;
        }

        // added by Shaoting
        // 涓烘敹绔坊鍔犫�滃彂閫佲�濈姸�?�?
        case MCU_STATE_BR_TX_INIT_2:
            {
                SX1276SetIRQFlagMask(RFLR_IRQFLAGS_TXDONE_MASK);
                // 璁剧疆SX1276鏃犵嚎鏀跺彂鑺墖鐨�?腑鏂爣蹇椾綅鎺╃爜锛圛RQ Flag Mask锛�?�负鍙戦�佸�?鎴愶紙TXDONE锛�?�爣蹇椾綅鎺╃爜
                // 浠ヤ究灞忚斀闄や簡鍙戦�佸畬鎴愭爣蹇椾綅浠ュ鐨�?叾浠栨�?�鏈変腑鏂�傝繖鏄负浜嗛槻�?�㈠�?鏁版嵁鍙戦�佹湡闂村彂鐢熷叾浠栦腑鏂�屽�?�鍝嶆暟鎹紶杈撶殑瀹屾暣鎬�?
                MCU_State = MCU_STATE_BR_TX_WAIT_2;
                
                SX1276Send(ACK_buffer, 1);
                SX1276Write(RegFifoAddrPtr, SX1276Read(RegFifoRxCurrentAddr));
                // RegFifoAddrPtr 鏄竴涓瘎瀛樺櫒鍦板潃锛岀敤浜庢寚绢��? SX1276 鑺墖涓殑 FIFO 鍐呭瓨涓殑褰撳墠鎸�?拡浣嶇疆锛屽嵆涓嬩�?�涓璇�?�彇鎴栧啓鍏ョ殑瀛�?�妭鐨勪綅缃�?
                // RegFifoRxCurrentAddr 鏄竴涓瘎瀛樺櫒鍦板潃锛岀敤浜庢寚绢�哄綋鍓嶆帴鏀跺埌鐨勬暟鎹寘鍦��IFO涓殑鍦板潃

                // 鍦ㄨ皟鐢⊿X1276Send鍑芥暟鍚�?紝鍙戦�佺殑鏁版嵁琚啓鍏X1276鑺墖鐨�?IFO瀵勫瓨鍣ㄤ腑锛屽悓鏃禨X1276鑺墖鐨�?IFO鎸囬拡涔熸寚鍚戜簡鍙戦�佹暟鎹殑鏈熬銆�
                // 涓轰簡纭繚鍙戦�佸�?鎴愬悗鑳藉姝ｅ父鎺ユ敹鏁版嵁锛岄渶瑕佸�?FIFO鎸囬拡閲嶆柊鎸囧悜鎺ユ敹鏁版嵁鐨�?捣濮嬩綅缃��
                // 鍥犳锛岃繖鏉rite璇彞灏辨槸灏咶IFO鎸囬拡閲嶆柊鎸囧悜RegFifoRxCurrentAddr鐨勪綅缃紝浠ヤ究鎺ユ敹鏁版嵁銆�?
                break;
            }
        case MCU_STATE_BR_TX_WAIT_2:
            {
                break;
            }
        case MCU_STATE_BR_TX_2:
            {
                uart_write("Sent the ACK package!\n");
                if (sleep_flag) __bis_SR_register(LPM4_bits);
                MCU_State = MCU_STATE_BR_RX_INIT;
                break;
            }

        default:
            {
                MCU_State = MCU_STATE_BR_RX_INIT;
                break;
            }
        }
    }
}

/* SX1276 callback functions */
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
