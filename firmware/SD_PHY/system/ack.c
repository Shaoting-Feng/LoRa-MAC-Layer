// added by Shaoting
// 用于ACK包的构建
// 不会灵活调用c++的库函数，实现得非常愚蠢

#include <stdint.h>

extern uint8_t ACK_buffer[6];

void ACK_Configure(char id_record[]) {
    ACK_buffer[0] = 'A';
    ACK_buffer[1] = 'C';
    ACK_buffer[2] = 'K';
    // 128 64 32 16 8 4 2 1
    ACK_buffer[3] = 128 * id_record[0] + 64 * id_record[1] + 32 * id_record[2] + 16 * id_record[3] + 8 * id_record[4] + 4 * id_record[5] + 2 * id_record[6] + id_record[7];
    ACK_buffer[4] = 128 * id_record[8] + 64 * id_record[9] + 32 * id_record[10] + 16 * id_record[11] + 8 * id_record[12] + 4 * id_record[13] + 2 * id_record[14] + id_record[15];
}