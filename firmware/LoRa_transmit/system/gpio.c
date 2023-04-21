/*Description: Implements the generic gpio driver
*/
#include <libraries/board.h>
#include <libraries/gpio.h>
#include <libraries/uart.h>
uint8_t transmit_cnt = 0;
extern bool timeout_flag;
/**########################Variables and Types############################**/
//static GpioIrqHandler* Irq_P1[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P2[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P3[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P4[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static uint8_t lora_irq_mask = 0x08;
uint32_t port6_irq_status;

/**########################Functions############################**/
uint8_t getMSB(uint8_t num)
{
    uint8_t tmp = num;  // Temporary copy of the variable
    uint8_t cnt = 0;      // Bit counter
    if (tmp != 0)    // To avoid infinite loops
        while (!(tmp & 0x01))
        {
            tmp >>= 1;
            cnt++;
        }
    return cnt;
}
void GpioInit(Gpio_t* g, volatile uint8_t* portOut, volatile uint8_t* portIn, volatile uint8_t* portDir, uint8_t pin, uint8_t portNumber, PinModes mode, bool value) {
    /* Save to struct */
    if (g != NULL) {
        g->out = portOut;
        g->in  = portIn;
        g->pin = pin;
    }

    /* Set Value */
    if (value) *portOut |=  pin;
    else       *portOut &= ~pin;

    /* Set Direction */
    if (mode == PIN_INPUT)  *portDir &= ~pin;
    if (mode == PIN_OUTPUT) *portDir |=  pin;

    /* Set port number */
    g->portNumber = portNumber;
}

void GpioSetInterrupt(Gpio_t* g, IrqModes irqMode) {
    if (irqMode == IRQ_RISING_EDGE)
    {
        GPIO_setAsInputPinWithPullDownResistor(g->portNumber, g->pin);
        GPIO_selectInterruptEdge(g->portNumber, g->pin, GPIO_LOW_TO_HIGH_TRANSITION);
    }
    else
    {
        GPIO_setAsInputPinWithPullDownResistor(g->portNumber, g->pin);
        GPIO_selectInterruptEdge(g->portNumber, g->pin, GPIO_HIGH_TO_LOW_TRANSITION);
    }
    GPIO_clearInterrupt(g->portNumber, g->pin);
    GPIO_enableInterrupt(g->portNumber, g->pin);
    //MAP_Interrupt_enableInterrupt(INT_PORT1 + (g->portNumber-GPIO_PORT_P1));
}

void GpioRemoveInterrupt(Gpio_t* g){

}

void GpioWrite(Gpio_t* g, bool value) {
    if (value) *(g->out) |=   g->pin;
    else       *(g->out) &= ~(g->pin);
}

void GpioToggle(Gpio_t* g) {
    *(g->out) ^= g->pin;
}

bool GpioRead(Gpio_t* g) {
    return !!(*(g->in) & g->pin);
}

/* GPIO ISR, LoRa DIO0 */
#pragma vector = PORT4_VECTOR
__interrupt void PORT4_IRQHandler(void)
{
//  MAP_Interrupt_disableMaster();
    uint16_t port4_irq_status = GPIO_getInterruptStatus(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P6, port4_irq_status);

// added by ZY
    uart_write("Correctly transmitted! interrupt\n");
    if (port4_irq_status & lora_irq_mask)
    {
        if (MCU_State == MCU_STATE_BR_TX_WAIT)
        {
            MCU_State = MCU_STATE_BR_RX_INIT;
            uart_write("TX_WAIT -> RX_INIT\n");
        }
        
        // added by Shaoting
        if (MCU_State == MCU_STATE_BR_RX_WAIT) {
            MCU_State = MCU_STATE_BR_RX;
            uart_write("ACK received!\n");
        }

        /*
        if (MCU_State == MCU_STATE_BR_RX_WAIT && timeout_flag != 1)
        {
            MCU_State = MCU_STATE_BR_RX;
            GpioToggle(&SD_PHY.LED_D2);
            uart_write("3");
        }
        
        if (MCU_State == MCU_STATE_BR_RX_WAIT && timeout_flag == 1)
        {
            uart_write("Time Out!\n");
            MCU_State = MCU_STATE_BR_TX_INIT;
            uart_write("4");
        }
        */
    }

    GPIO_clearInterrupt(GPIO_PORT_P4, GPIO_PIN3);
    GpioToggle(&SD_PHY.LED_D1);
//    MAP_Interrupt_enableMaster();
}

#pragma vector = USCI_A0_VECTOR
__interrupt void UART_Receive_ISR(void) {

    if(EUSCI_A_UART_getInterruptStatus(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)) {
        EUSCI_A_UART_clearInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG);
        BR_buffer[transmit_cnt++] = UCA0RXBUF;
        if (transmit_cnt == 16) {
            GpioToggle(&SD_PHY.LED_D2);
            transmit_cnt = 0;
            if (MCU_State == MCU_STATE_UART_WAIT)
            {
                MCU_State = MCU_STATE_BR_TX_INIT;
            }
        }

    }
}


