#ifndef ADC_REGISTERS_H     // for guarding 
#define ADC_REGISTERS_H

/* ADC Control and Status Register */
#define ADCSRA_REG       *((volatile u8*) 0x26) 

#define ADCSRA_ADEN                     7        /*ADC ENABLE by writing one*/
#define ADCSRA_ADSC                     6        /*ADC start conversion  */
#define ADCSRA_ADATA                    5       // ADC triggle auto enable 
#define ADCSRA_ADIF                     4       // ADC interrupt flag
#define ADCSRA_ADIE                     3       // ADC interrupt Enable
#define ADCSRA_ADPS2                    2       /* ADC prescaler select bits  (0:2)*/
#define ADCSRA_ADPS1                    1
#define ADCSRA_ADPS0                    0

/*two registers to store the result*/
#define ADCH_REG       *((volatile u8*) 0x25)
#define ADCL_REG       *((volatile u8*) 0x24)
#define ADC_READ       *((volatile u16*) 0x24)

/*ADC MULTIPLEXER SELECTION REGISER */
#define ADMUX_REG      *((volatile u8 *)0x27)
#define ADMUX_MUX0         0                      /* Analog channel and selection bits*/
#define ADMUX_MUX1         1
#define ADMUX_MUX2         2
#define ADMUX_MUX3         3
#define ADMUX_MUX4         4
#define ADMUX_ADLAR        5                        /* ADC LEFT ADJUST LAYER*/
#define ADMUX_REFS0        6                       /*VOLTAGE REFRENCE SELECTION BITS */
#define ADMUX_REFS1        7

#define SPFIOR_REG      *((volatile u8 *)0x50)
#define SPFIOR_RES         4             /*reseved bit*/
#define SPFIOR_ADTS0       5            /*ADC AUTO TRIGGLE SOURCE*/
#define SPFIOR_ADTS1       6
#define SPFIOR_ADTS2       7


#endif
