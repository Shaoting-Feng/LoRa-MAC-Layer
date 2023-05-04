// added by Shaoting
#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

bool timeout_flag;
bool timerstart_sleep;
bool timerstart_wait;
bool duty_flag;
int random_num;

/**#######################External functions######################**/
void timerinitial(void);
void settimer_sleep(void);
void settimer_wait(void);
void endtimer_sleep(void);
#endif
