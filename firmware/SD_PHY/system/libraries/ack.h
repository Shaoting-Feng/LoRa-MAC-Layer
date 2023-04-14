// added by Shaoting
// 用于ACK包的构建
// 不会灵活调用c++的库函数，实现得非常愚蠢

#ifndef ACK_CONFIGURE_H
#define ACK_CONFIGURE_H

#include <stdint.h>

// 声明全局变量 ACK_buffer
extern uint8_t ACK_buffer[6];

// 声明函数 ACK_Configure
void ACK_Configure(char id_record[]);

#endif // ACK_CONFIGURE_H