/*Description: Implements the generic gpio driver
*/
#include <libraries/board.h>
#include <libraries/gpio.h>

// added by Shaoting
#include <libraries/timer.h>


/**########################Variables and Types############################**/
//static GpioIrqHandler* Irq_P1[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P2[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P3[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
//static GpioIrqHandler* Irq_P4[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static uint8_t lora_irq_mask = 0x08;
uint32_t port6_irq_status;

// added by Shaoting
// 鐢ㄤ簬鍦ㄦ帴鏀剁鍙戦�丄CK
uint8_t transmit_cnt_2 = 0;

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


    if (port4_irq_status & lora_irq_mask)
    // 鍙戠幇鍙戝拰鏀舵煡interrupt鐨勫墠涓よ鏄竴鏍风殑
    {
        if (MCU_State == MCU_STATE_BR_RX_WAIT)
        {
            // added by Shaoting
            __bic_SR_register_on_exit(LPM4_bits);
            endtimer_sleep();

            MCU_State = MCU_STATE_BR_RX;
            GpioToggle(&SD_PHY.LED_D2);
        }

        // added by Shaoting
        else if (MCU_State == MCU_STATE_BR_TX_WAIT_2) {
            MCU_State = MCU_STATE_BR_TX_2;
        }
    }

    GPIO_clearInterrupt(GPIO_PORT_P4, GPIO_PIN3);

//    MAP_Interrupt_enableMaster();
}




