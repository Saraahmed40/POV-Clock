#ifndef TIMER_config_H     // for guarding 
#define TIMER_config_H

/*Options of Wave generation mode Bit Description
       1-NORMAL_WAVEFORM                
       2-PWM_PHASECORRECT_WAVEFORM     
       3-CTC_WAVEFORM                   
       4-FAST_PWM_WAVEFORM 
*/
#define WAVEFORM_GENERATION_MODE      CTC_WAVEFORM

/*Options of Compare OUTPUT mode NON PWM MODE
       1- NON_PWM_NORMAL_PORT_OPERATION_OC0       
       2- NON_PWM_TOGGLE_OC0_ONCOMPARE_MATCH      
       3- NON_PWM_CLEAR_OC0_ONCOMPARE_MATCH       
       4- NON_PWM_SET_OC0_ONCOMPARE_MATCH  
*/
/*
 * Options of Compare OUTPUT mode:
 *     1- NON_PWM_NORMAL_PORT_OPERATION_OC0
       2- NON_PWM_TOGGLE_OC0_ONCOMPARE_MATCH
       3- NON_PWM_CLEAR_OC0_ONCOMPARE_MATCH
       4- NON_PWM_SET_OC0_ONCOMPARE_MATCH

       5- FAST_PWM_NORMAL_PORT_OPERATION_OC0
       6- FAST_PWM_CLEAR_OC0_ONCOMPARE_MATCH
       7- FAST_PWM_SET_OC0_ONCOMPARE_MATCH

       8- PHASE_PWM_NORMAL_PORT_OPERATION_OC0
       9- PHASE_PWM_CLEAR_OC0_ONCOMPARE_MATCH
       10- PHASE_PWM_SET_OC0_ONCOMPARE_MATCH
 */
#define COMPARE_OUTPUTMODE              NON_PWM_NORMAL_PORT_OPERATION_OC0              //FAST_PWM_CLEAR_OC0_ONCOMPARE_MATCH


/*Options of Clock select Bit Description
       1-NO_CLK                 
       2-CLK_NOPRESCALER         
       3-CLK_PRESCALER_8         
       4-CLK_PRESCALER_64        
       5-CLK_PRESCALER_265       
       6-CLK_PRESCALER_1024      
       7-EXTCLK_FALLING_EDGE     
       8-EXTCLK_RISING_EDGE      
*/
#define CLOCK_SELECT                  CLK_PRESCALER_8
/*options of which interrupt
 *  1-TIMSK_TOIE0    overflow interrupt enable
 *  2-TIMSK_OCIE0    Output compare match interrupt enable
 * */
//#define TIMER_INTERRUPT               TIMSK_OCIE0

#if ( WAVEFORM_GENERATION_MODE == CTC_WAVEFORM )
/* Set top value for compare match mode*/
#define TIMER0_CTC_TOP_VAL      255
#endif


#define TIMER0_COMPARE_VAL            250// 240
#define TIMER0_NUM_COMPARE_COUNTS      3500//3200
#define TIMER0_NUM_OVERFLOW        367
#define DESIRED_VAL         260  /*FOR OVERFLOW*/
#endif
