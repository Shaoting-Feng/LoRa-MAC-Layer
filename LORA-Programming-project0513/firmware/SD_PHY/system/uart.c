//Description: implement uart
#include <libraries/clock.h>
#include <libraries/uart.h>

void uart_write(char *pbuff) {
    int len = strlen(pbuff);
    int i = 0;
    for (i = 0; i < len; i++) {
        while (UCA0STATW & UCBUSY);
        EUSCI_A_UART_transmitData(EUSCI_A0_BASE, pbuff[i]);
    }
}

//以3位十进制输出num
void uart_printNum(uint8_t num) {
    // deleted by Shaoting
    // char buff[4] = "000\n";//{'0','0','0','\n'};

    // added by Shaoting
    char buff[] = {'0', '0', '0', '\n', '\0'};//{'0','0','0','\n'};

    int i = 0;
    for (i = 0; i < 3; i++) {
        buff[2 - i] = num % 10 + '0';
        num /= 10;
    }
    uart_write(buff);
}

void uart_printhex8(uint8_t n) {
  char buf[2 + 1];
  char *str = &buf[3 - 1];

  *str = '\0';

  uint8_t base = 16;

  do {
    uint8_t m = n;
    n /= base;
    char c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  uart_write(str);
}

void initUART(void) {
        UCA0CTL1 |= UCSWRST;
        EUSCI_A_UART_enable(EUSCI_A0_BASE);

        EUSCI_A_UART_initParam uart_param = {0};
        uart_param.selectClockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK;
        uart_param.clockPrescalar = 2;
        uart_param.firstModReg = 2;
        uart_param.secondModReg = 0xbb;
        uart_param.parity = EUSCI_A_UART_NO_PARITY;
        uart_param.msborLsbFirst = EUSCI_A_UART_LSB_FIRST;
        uart_param.numberofStopBits = EUSCI_A_UART_ONE_STOP_BIT;
        uart_param.uartMode = EUSCI_A_UART_MODE;
        uart_param.overSampling = EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION ;
        EUSCI_A_UART_init(EUSCI_A0_BASE, &uart_param);

        if (STATUS_FAIL == EUSCI_A_UART_init(EUSCI_A0_BASE, &uart_param)) {
            return;
        }

        P2SEL1 |= BIT0 + BIT1;
        P2SEL0 &= ~(BIT0 + BIT1);
        UCA0CTL1 &= ~UCSWRST;
        //EUSCI_A_UART_disable(EUSCI_A0_BASE);
        //EUSCI_A_UART_clearInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_TRANSMIT_COMPLETE_INTERRUPT_FLAG);
        //EUSCI_A_UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
}
