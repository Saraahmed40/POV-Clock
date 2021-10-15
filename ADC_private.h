#ifndef ADC_PRIVATE_H     // for guarding 
#define ADC_PRIVATE_H

#define DIV_BY_2             0
#define DIV_BY_4             2
#define DIV_BY_8             3
#define DIV_BY_16            4
#define DIV_BY_32            5
#define DIV_BY_64            6
#define DIV_BY_128           7

#define LEFT_ADJUST          1
#define RIGHT_ADJUST         0

#define NUM_BIT_8            8
#define NUM_BIT_10           10

#define CLRMASK_ADMUX           240   //0b11100000
#define CLRMASK_ADCSRA          248   //0b11111000

#define IDLE                 0
#define BUSY                 1


#define ADC_SingleChannel_Async     0
#define ADC_ChainChannel_Async      1

void __vector_16(void)    __attribute__((signal));
#endif 
