// added by Shaoting
// 用于ACK包的构建

#include <stdint.h>

extern uint8_t ACK_buffer[1];
extern int tag;

void ACK_Configure(int CMD_TYPE) {
    if (CMD_TYPE == 2) {
        ACK_buffer[0] = 0x00 + tag * 0x10;
    }
    else if (CMD_TYPE == 0 || CMD_TYPE == 1) {
        ACK_buffer[0] = 0xf0;
    }
}
