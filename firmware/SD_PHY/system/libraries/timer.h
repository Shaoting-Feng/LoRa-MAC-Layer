// added by Shaoting
#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool timeout_flag;
bool timerstart_sleep;
bool timerstart_wait;
bool duty_flag;

uint16_t random_num;
uint16_t RandomCnt;

/**#######################External functions######################**/
void timerinitial(void);
void settimer_sleep(void);
void settimer_wait(void);
void endtimer_sleep(void);
#endif
