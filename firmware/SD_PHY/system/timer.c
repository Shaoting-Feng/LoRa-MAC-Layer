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

// added by Shaoting
#include <stdlib.h>
#include <time.h>

extern bool sleep_flag;
extern bool done_flag;


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

    // added by Shaoting
    duty_flag = false;
}

void settimer_sleep(void)
{
    timerstart_sleep = 1;

    // deleted by Shaoting
    // uart_write("Timer Start!\n");
}

// added by Shaoting
void settimer_wait(void)
{
    timerstart_wait = 1;
    srand(time(0));
    random_num = rand() % 1001; // 0 to 1s
}

void endtimer_sleep(void)
{
    if (duty_flag) {
        /*
        __bic_SR_register_on_exit(LPM4_bits);
        */
        uart_write("I have waken up.\n");
        GpioWrite(&SD_PHY.LED_D1, 1);
        duty_flag = false;
    }
    timerstart_sleep = 0;
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
    // uart_write("test\n");

    if (timerstart_sleep == 1 && sleep_flag && done_flag) {
        uart_write("Oops.\n");
        GpioWrite(&SD_PHY.LED_D1, 0);
        __bis_SR_register(LPM4_bits);
    }

    static uint16_t TimerCnt = 0;

    if (timerstart_sleep == 1) {  
        TimerCnt ++;
        // uart_printNum(TimerCnt);
        if (TimerCnt >= 3000) { // go to sleep after 3s without actions
            TimerCnt = 0;

            // added by Shaoting
            if (!duty_flag) {
                uart_write("I am going to bed.\n");
                GpioWrite(&SD_PHY.LED_D1, 0);
                duty_flag = true;
                __bis_SR_register(LPM4_bits + GIE);
            }
            else {
                __bic_SR_register_on_exit(LPM4_bits);
                uart_write("I have waken up.\n");
                GpioWrite(&SD_PHY.LED_D1, 1);
                duty_flag = false;
            }
        }
    }
    else {
        TimerCnt = 0;
    }

    // added by Shaoting
    static uint16_t TimerCnt_wait = 0;

    if (timerstart_wait == 1) {  
        TimerCnt_wait ++;
        if (TimerCnt_wait >= random_num) { 
            TimerCnt_wait = 0;
            if (MCU_State == MCU_STATE_BR_RX) {
                uart_write("I have delayed \n");
                uart_printNum(random_num % 1000);
                uart_write(" \n");
                MCU_State = MCU_STATE_BR_TX_INIT_2;
                TimerCnt_wait = 0;
                timerstart_wait = 0;
            }
        }
    }
    else {
        TimerCnt_wait = 0;
    }
}
