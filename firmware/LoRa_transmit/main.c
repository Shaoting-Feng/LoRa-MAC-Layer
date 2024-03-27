#include "driverlib.h"
#include <libraries/board.h>
#include <stdio.h>
#include <msp430.h>
#include <stdbool.h>
#include <driverlib.h>
#include <settings.h>
#include <libraries/clock.h>
#include <task.h>
#include <libraries/uart.h>
//#include "testmini.h"
#include <utils/utils.h>
//#include <app/task.h>
Board_t SD_PHY;
MCU_States_t MCU_State = MCU_STATE_INIT;
#define modem   0

void main (void)
{
    WDT_A_hold(WDT_A_BASE);
    PMM_unlockLPM5();
    task_lora_test();
}
