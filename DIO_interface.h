#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA        0
#define PORTB        1
#define PORTC        2
#define PORTD        3

#define OUTPUT 1          /*set PORT direction*/
#define INPUT  0
       

#define HIGH   1
#define LOW    0

 /*set pin direction
 set port value 
 set pin direction
 set pin value 
 tog pin value 
 get pin value*/
 
 /* SET PIN VALUE*/
 #define PIN0  0
 #define PIN1  1
 #define PIN2  2
 #define PIN3  3
 #define PIN4  4
 #define PIN5  5 
 #define PIN6  6
 #define PIN7  7
 
 
 
 // port functions
 void MDIO_voidSetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirection);   //PortID= PortA,PortB,PortC,PortD
 void MDIO_voidSetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue);
 
 // PIN FUNCTIONS
 void MDIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId, u8 copy_u8PinDirection);
 void MDIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);
 void MDIO_voidTogPinValue(u8 copy_u8PortId, u8 copy_u8PinId);
 u8 MDIO_U8GETPinValue(u8 copy_u8PortId,u8 copy_u8PinId);
 
#endif