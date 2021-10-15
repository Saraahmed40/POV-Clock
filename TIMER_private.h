#ifndef TIMER_PRIVATE_H     // for guarding 
#define TIMER_PRIVATE_H

/*Wave generation mode Bit Description*/
#define NORMAL_WAVEFORM                0
#define PWM_PHASECORRECT_WAVEFORM      1
#define CTC_WAVEFORM                   2 
#define FAST_PWM_WAVEFORM              3


/*Compare OUTPUT mode NON PWM MODE*/
#define NON_PWM_NORMAL_PORT_OPERATION_OC0       0
#define NON_PWM_TOGGLE_OC0_ONCOMPARE_MATCH      1
#define NON_PWM_CLEAR_OC0_ONCOMPARE_MATCH       2
#define NON_PWM_SET_OC0_ONCOMPARE_MATCH         3

/*Compare OUTPUT mode FAST PWM MODE*/
#define FAST_PWM_NORMAL_PORT_OPERATION_OC0      4
/*revseved bit is 1*/
#define FAST_PWM_CLEAR_OC0_ONCOMPARE_MATCH      5
#define FAST_PWM_SET_OC0_ONCOMPARE_MATCH        6

/*Compare OUTPUT Phase CORRECT PWM MODE*/
#define PHASE_PWM_NORMAL_PORT_OPERATION_OC0      7
/*revseved bit is 1*/
#define PHASE_PWM_CLEAR_OC0_ONCOMPARE_MATCH      8
#define PHASE_PWM_SET_OC0_ONCOMPARE_MATCH        9

/*Clock select Bit Description*/
#define NO_CLK                  0
#define CLK_NOPRESCALER         1
#define CLK_PRESCALER_8         2
#define CLK_PRESCALER_64        3
#define CLK_PRESCALER_256       4
#define CLK_PRESCALER_1024      5
#define EXTCLK_FALLING_EDGE     6
#define EXTCLK_RISING_EDGE      7

/*Bit mask for clock select*/
#define MASK_CLK        0XF8       // 0b11111000


void __vector_10(void)     __attribute__((signal));     /*Compare Match Mode ISR*/
void __vector_11(void)     __attribute__((signal));     /*overflow ISR*/



#endif
