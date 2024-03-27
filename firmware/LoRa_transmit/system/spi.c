/*
Description: Implements the generic SPI driver
*/
#include <libraries/spi.h>
#include <libraries/uart.h>
/**#############################Functions#############################**/
void SpiInit(void) {

#ifdef PLATFORM_SD_PHY
    ////######### LoRa Radio SPI #############
//  Configure SPI pins
//  Configure Pins for UCA0CLK
////######################################
    UCB0CTLW0 |= UCSWRST;

    P1SEL1 |= BIT6 + BIT7;
    P1SEL0 &= ~(BIT6 + BIT7);
    P2SEL1 |= BIT2;
    P2SEL0 &= ~BIT2;

    //Initialize Master
    EUSCI_B_SPI_initMasterParam lora_param = {0};
    lora_param.selectClockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK;
    lora_param.clockSourceFrequency = CS_getSMCLK();;
    lora_param.desiredSpiClock = 500000;
    lora_param.msbFirst = EUSCI_B_SPI_MSB_FIRST;
    lora_param.clockPhase = EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT;
    lora_param.clockPolarity = EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH;
    lora_param.spiMode = EUSCI_B_SPI_3PIN;

    /* Configuring SPI in 3wire master mode */
    EUSCI_B_SPI_initMaster(EUSCI_B0_BASE, &lora_param);

    /* Enable SPI module */
    EUSCI_B_SPI_enable(EUSCI_B0_BASE);



    /* Enabling interrupts */
    EUSCI_B_SPI_enableInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_RECEIVE_INTERRUPT);
//    EUSCI_B_SPI_enableInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT);
//    EUSCI_B_SPI_clearInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT);
//    EUSCI_B_SPI_clearInterrupt(EUSCI_B0_BASE, EUSCI_B_SPI_RECEIVE_INTERRUPT);
    UCB0CTLW0 &= ~UCSWRST;
    //注意开全局中断

    //SPI_enableInterrupt(EUSCI_B2_BASE, EUSCI_B_SPI_RECEIVE_INTERRUPT);
    //Interrupt_enableInterrupt(INT_EUSCIB2);

    //TX buffer ready?
    while (!(EUSCI_B_SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));

#endif
}

//非中断实现SpiInOut_LoRa
//uint8_t SpiInOut_LoRa(Spi_t *obj, uint8_t outData) {
//    /* SPI send data */
//    UCB0TXBUF = outData;
//    //__no_operation();
//    while(!(UCB0IFG & UCTXIFG));
//    while(!(UCB0IFG & UCRXIFG));
//    SPI_RXData_LoRa = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);
////    __enable_irq();
////    PCM_gotoLPM0();
////    __bis_SR_register(LPM3_bits + GIE);
//    return SPI_RXData_LoRa;
//}

//中断实现SpiInOut_LoRa
uint8_t SpiInOut_LoRa(Spi_t *obj, uint8_t outData) {
//    uart_write("in SpiInOut_LoRa \n");
    UCB0TXBUF = outData;
    __no_operation();

    __bis_SR_register(LPM0_bits + GIE);
    return SPI_RXData_LoRa;
}


//******************************************************************************
//
//This is the EUSCI_A2 interrupt vector service routine.
//
//******************************************************************************


//注意：只有使用中断版本的Spi_InOutLora时才需要使用下面的中断函数，否则直接注释掉
#pragma vector = USCI_B0_VECTOR
__interrupt void EUSCIB0_IRQHandler(void)
{

    uint16_t status = UCB0IFG & UCB0IE & (UCTXIFG | UCRXIFG);

    UCB0IFG &= ~status;

    while (!(EUSCI_B_SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));

    SPI_RXData_LoRa = UCB0RXBUF;

    /* exit from LPM0 */
    __bic_SR_register_on_exit(LPM0_bits);
}
