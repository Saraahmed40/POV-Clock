#ifndef DIO_PRIVATE_H     // for guarding 
#define DIO_PRIVATE_H

#if NUMBER_OF_PINS == 8
/*set PORT direction*/
#define OUTPUT      0xFF
#define INPUT       0x00
/*set PORT Value*/
#define HIGH        0xFF
#define LOW         0x00

#elif NUMBER_OF_PINS == 16
#define OUTPUT      0xFFFF
#define INPUT       0x0000
/*set PORT Value*/
#define HIGH        0xFFFF
#define LOW         0x0000

#endif

#endif
