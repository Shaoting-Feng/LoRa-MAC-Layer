//Description: Implements the generic clock driver
#include <libraries/clock.h>

/**########################Internal functions############################**/
//uint32_t ClockGetDivider(uint32_t clockSource, uint32_t freq)

/**#######################External functions######################**/
void ClockInit( void )
{
//    SD_PHY.Clock.LFX = false;
//    SD_PHY.Clock.HFX = false;
//    SD_PHY.Clock.LFX_Freq = 0;
//    SD_PHY.Clock.HFX_Freq = 0;
//    SD_PHY.Clock.Source = 0;
    SD_PHY.Clock.MCLK = 0;
    SD_PHY.Clock.ACLK = 0;
    SD_PHY.Clock.MODCLK = 0;
    SD_PHY.Clock.SMCLK = 0;
    SD_PHY.Clock.VLOCLK = 0;

    /* Initializing the clock source as follows:
     *      MCLK = MODOSC = 24MHz  ***  MCLK = DCO = 8MHZ
     *      ACLK = REFO/2 = 16kHz  ***  ACLK = VLOCLK = 10KHZ
     *      HSMCLK = DCO/2 = 1.5Mhz *** MODCLK = DCO / 8 = 1MHZ
     *      SMCLK = DCO/4 = 12MHz   ***  SMCLK = DCO / 2 =  4MHZ
     *      BCLK  = REFO = 32kHz   ***  VLOCLK = VLOCLK = 10KHZ
     *
     *added by zhangchi:we'll select the low frequency DCO option,which is 8MHZ
    */
    CS_setDCOFreq(CS_DCORSEL_0, CS_DCOFSEL_6);
    ClockSet(CLK_MCLK,      CS_DCOCLK_SELECT ,   CS_CLOCK_DIVIDER_1, true);
    ClockSet(CLK_ACLK,      CS_VLOCLK_SELECT,  CS_CLOCK_DIVIDER_1, true);//VLO is 10khz
    ClockSet(CLK_MODCLK,    CS_DCOCLK_SELECT,   CS_CLOCK_DIVIDER_8, true);
    ClockSet(CLK_SMCLK,     CS_DCOCLK_SELECT,   CS_CLOCK_DIVIDER_2, true);
    //ClockSet(CLK_VLOCLK,      CS_VLOCLK_SELECT,  CS_CLOCK_DIVIDER_1, true);
    //printf("ACLK: %d\n", CS_getACLK());
    //printf("SMCLK: %d\n", CS_getSMCLK());
}
//
//void ClockEnableHFXT(void)
//{
//    /* Configuring pins for peripheral/crystal usage and LED for output */
//    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(PIN_CLK_HFXIN.portNumber,
//            PIN_CLK_HFXIN.pin | PIN_CLK_HFXOUT.pin, GPIO_PRIMARY_MODULE_FUNCTION);
//
//    MAP_CS_setExternalClockSourceFrequency(32000,48000000);
//
//    /* Starting HFXT in non-bypass mode without a timeout. Before we start
//    * we have to change VCORE to 1 to support the 48MHz frequency */
//    MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
//    MAP_FlashCtl_setWaitState(FLASH_BANK0, 2);
//    MAP_FlashCtl_setWaitState(FLASH_BANK1, 2);
//    CS_startHFXT(false);
//    TinySDR.Clock.HFX = true;
//    ClockSetSource(CS_HFXTCLK_SELECT);
//    SD_PHY.Clock.HFX_Freq = 48000000;
//}
//
//void ClockEnableLFXT(void)
//{
//    /* Configuring pins for peripheral/crystal usage and LED for output */
//    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(PIN_CLK_LFXIN.portNumber,
//            PIN_CLK_LFXIN.pin | PIN_CLK_LFXOUT.pin, GPIO_PRIMARY_MODULE_FUNCTION);
//
//    MAP_CS_setExternalClockSourceFrequency(32000,48000000);
//
//    /* Starting LFXT in non-bypass mode without a timeout. */
//    CS_startLFXT(false);
//    TinySDR.Clock.LFX = true;
//    ClockSetSource(CS_LFXTCLK_SELECT);
//    TinySDR.Clock.LFX_Freq = 32000;
//}

//void ClockSetSource(uint32_t source)
//{
//    SD_PHY.Clock.Source = source;
//}

void ClockSet(Clock_Types_t type, uint16_t clockSource, uint16_t divider, bool enable)
{
    switch (type)
    {
        case CLK_MCLK:
            if (enable == false)
            {
                SD_PHY.Clock.MCLK = 0;
                CS_disableClockRequest(CS_MCLK);
            }
            else
            {
                CS_initClockSignal(CS_MCLK, clockSource, divider);
                SD_PHY.Clock.MCLK = CS_getMCLK();
            }
            break;
        case CLK_ACLK:
            if (enable == false)
            {
                SD_PHY.Clock.ACLK = 0;
                CS_disableClockRequest(CS_ACLK);
            }
            else
            {
                CS_initClockSignal(CS_ACLK, clockSource, divider);
                SD_PHY.Clock.ACLK = CS_getACLK();
            }
            break;
        case CLK_MODCLK:
            if (enable == false)
            {
                SD_PHY.Clock.MODCLK = 0;
                CS_disableClockRequest(CS_MODOSC);
            }
            else
            {
                CS_initClockSignal(CS_MODOSC, clockSource, divider);
                SD_PHY.Clock.MODCLK = 1500000;//CS_getMODCLK();
            }
            break;
        case CLK_SMCLK:
            if (enable == false)
            {
                SD_PHY.Clock.SMCLK = 0;
                CS_disableClockRequest(CS_SMCLK);
            }
            else
            {
                CS_initClockSignal(CS_SMCLK, clockSource, divider);
                SD_PHY.Clock.SMCLK = CS_getSMCLK();
            }
            break;
        default:
            break;
    }
}

//uint32_t ClockGetDivider(uint32_t clockSource, uint32_t freq)
//{
//  uint32_t sourceFreq;
//  uint32_t divider;
//
//  if (TinySDR.Clock.Source == CS_HFXTCLK_SELECT)
//  {
//      sourceFreq = TinySDR.Clock.HFX_Freq;
//  }
//  else if (TinySDR.Clock.Source == CS_LFXTCLK_SELECT)
//  {
//      sourceFreq = TinySDR.Clock.LFX_Freq;
//  }
//  else if (TinySDR.Clock.Source == CS_DCOCLK_SELECT)
//  {
//      //TODO
//      sourceFreq = 0;
//  }
//
//  divider = source/freq;
//  return divider;
//}
