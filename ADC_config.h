#ifndef ADC_CONFIG_H     // for guarding 
#define ADC_CONFIG_H

/*
 * CHOOSE WHICH OPTION OF ADC_PRESCALER
 *        1-DIV_BY_2
 *        2-DIV_BY_4
 *        3-DIV_BY_8
 *        4-DIV_BY_16
 *        5-DIV_BY_32
 *        6-DIV_BY_64
 *        7-DIV_BY_128

 */
#define ADC_PRESCALER      DIV_BY_128
/*
 * CHOOSE WHICH OPTION OF ADC_ADJUST IN ADC DATA REGISTER
 *           1- LEFT _ADJUST
 *           2- RIGHT_ADJUST
 * */
#define ADC_ADJUST          LEFT_ADJUST
/*
 * CHOOSE WHICH OPTION OF NUMBER OF BITS IN ADC DATA REGISTER
 *         1- NUM_BIT_8
 *         2- NUM_BIT_10
 * */
#define NUMBER_BITS         NUM_BIT_8
#define ADC_u8TimeOUT       50000

//#define ADC_ISRSource     ADC_ChainChannel_Async


#endif
