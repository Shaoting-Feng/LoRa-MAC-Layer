// added by Shaoting
// 用于ACK包的构建

#ifndef ACK_CONFIGURE_H
#define ACK_CONFIGURE_H

#include <stdint.h>

// 声明全局变量 ACK_buffer
extern uint8_t ACK_buffer[1];

// 声明函数 ACK_Configure
void ACK_Configure(int CMD_TYPE);

#endif // ACK_CONFIGURE_H