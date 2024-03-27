/*
Description: Radio General Implementation
*/
#ifndef _RADIO_H_
#define _RADIO_H_

/**#############################Types and Variables#############################**/
typedef struct {
    void    ( *TxDone )( void );
    void    ( *TxTimeout )( void );
    void    ( *RxDone )( uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr );
    void    ( *RxTimeout )( void );
    void    ( *RxError )( void );
    void ( *FhssChangeChannel )( uint8_t currentChannel );
    void ( *CadDone ) ( bool channelActivityDetected );
}RadioEvents_t;



#endif
