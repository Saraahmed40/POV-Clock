#ifndef TIMER_INTERFACE_H     // for guarding 
#define TIMER_INTERFACE_H


//#define TIMER0_PRELOAD           252  /*FOR OVERFLOW*/

void MTIMER0_voidInitialize(void);
u8 MTIMER0_u8MeasureAsync(void (*ptr_TimerFuncLogic)(void));







#endif
