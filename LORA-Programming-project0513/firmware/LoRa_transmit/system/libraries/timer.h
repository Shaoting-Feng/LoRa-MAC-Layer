// added by Chi
#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

#include <stdint.h>

bool timeout_flag;
bool timerstart;

bool timerstart2;
//uint16_t TransmitCnt;

/**#######################External functions######################**/
void timerinitial(void);
void settimer(void);
void settimer2(void);
void closetimer(void);
#endif
