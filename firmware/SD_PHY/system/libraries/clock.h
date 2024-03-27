//Description: Implements the generic clock driver
#ifndef _SYSTEM_CLOCK_H_
#define _SYSTEM_CLOCK_H_

#include <driverlib.h>
#include <settings.h>
#include <libraries/board.h>

/**########################Variables and Types############################**/
typedef enum
{
    CLK_MCLK = 0,
    CLK_ACLK,
    CLK_MODCLK,
    CLK_SMCLK,
    CLK_VLOCLK
} Clock_Types_t;

/**########################External functions############################**/
void ClockInit( void );
//void ClockEnableLFXT(void);
//void ClockEnableHFXT(void);
//void ClockSetSource(uint32_t source);
void ClockSet(Clock_Types_t type, uint16_t clockSource, uint16_t divider, bool enable);


#endif
