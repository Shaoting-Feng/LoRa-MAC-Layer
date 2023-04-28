// added by Chi
#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

bool timeout_flag;
bool timerstart;
bool duty_flag;

/**#######################External functions######################**/
void timerinitial(void);
void settimer(void);
void endtimer(void);
#endif
