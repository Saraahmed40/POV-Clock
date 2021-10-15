#ifndef  LED_INTERFACE_H
#define  LED_INTERFACE_H


/*
Options of pins :-
PIN0
PIN1
PIN2
PIN3
PIN4
PIN5
PIN6
PIN7

*/



void HLED_voidTurnOn(u8 Copy_u8PIN, u8 PORT_LED);
void HLED_voidTurnOff(u8 Copy_u8PIN, u8 PORT_LED);
void HLED_voidToggle(u8 Copy_u8PIN, u8 PORT_LED);

#endif
