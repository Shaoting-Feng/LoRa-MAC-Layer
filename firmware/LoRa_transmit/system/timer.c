// added by Chi
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
#include <libraries/timer.h>
#include <sx1276/sx1276.h>
#include <ota.h>

void timerinitial(void)
{
    Timer_A_initUpModeParam timera = {0};     //upmode
    timera.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;   //SMCK=4MHZ;
    timera.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;  //without additional Frequency division
    timera.timerPeriod = 4000-1;         //period:1ms
    timera.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE; //disable TALE interupt
    timera.captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;//enable CCR0 interupt
    timera.timerClear = TIMER_A_DO_CLEAR;
    timera.startTimer = true; //Start the timer_A immediately after initialization
    //Up mode:
    Timer_A_initUpMode(TIMER_A0_BASE, &timera);
}

void settimer(void)
{
    timerstart = 1;
    timeout_flag = 0;
    uart_write("Timer Start!\n");
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
    static uint16_t TimerCnt = 0;
    static uint16_t TransmitCnt = 0;

    if (timerstart == 1) {  
        TimerCnt ++;
        if (TimerCnt >= 1000) {
            TimerCnt = 0;
            //timeout_flag = 1;

            // added by Shaoting
            if (TransmitCnt < 10){
                if (MCU_State == MCU_STATE_BR_RX_WAIT) {
                    uart_write("Time Out!\n");
                    TransmitCnt ++;
                    MCU_State = MCU_STATE_BR_TX_INIT;
                }
            }
            else {
                TransmitCnt = 0;
                MCU_State = MCU_STATE_BR_TX_INIT;
            }
            timerstart = 0; 
        }
    }
    else {
        TimerCnt = 0;
    }
}
