#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_interface.h"
#include"TIMER_registers.h"
#include"TIMER_private.h"
#include"TIMER_config.h"

/**************************
 * Private Global Objects *
 **************************/
static void (*G_TimerFuncNotification)(void) = NULL;

/*Function to initialize timer0*/
void MTIMER0_voidInitialize(void)
{
/*Choose which waveform generation mode*/
#if (WAVEFORM_GENERATION_MODE == NORMAL_WAVEFORM)
	CLR_BIT(TCCR0_REG, TCCR0_WGM00);
	CLR_BIT(TCCR0_REG, TCCR0_WGM01);
	/*Set Initial value */
//	TCNT0_REG = TIMER0_PRELOAD;


#elif(WAVEFORM_GENERATION_MODE == PWM_PHASECORRECT_WAVEFORM )
	SET_BIT(TCCR0_REG, TCCR0_WGM00);
	CLR_BIT(TCCR0_REG, TCCR0_WGM01);


#elif(WAVEFORM_GENERATION_MODE == CTC_WAVEFORM )
	CLR_BIT(TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TCCR0_REG,TCCR0_WGM01);
	/*Set compare match value */
	OCR0_REG = TIMER0_COMPARE_VAL;
	/*Set Initial value */
	//TCNT0_REG = TIMER0_PRELOAD;


#elif(WAVEFORM_GENERATION_MODE == FAST_PWM_WAVEFORM)
	SET_BIT(TCCR0_REG, TCCR0_WGM00);
	SET_BIT(TCCR0_REG, TCCR0_WGM01);
#else
#error wrong waveform generation mode
#endif

/*ENABLE which compare match mode*/
#if ((COMPARE_OUTPUTMODE == NON_PWM_NORMAL_PORT_OPERATION_OC0) || (COMPARE_OUTPUTMODE == FAST_PWM_NORMAL_PORT_OPERATION_OC0) ||( COMPARE_OUTPUTMODE ==PHASE_PWM_NORMAL_PORT_OPERATION_OC0))
	CLR_BIT(TCCR0_REG, TCCR0_COM00);
	CLR_BIT(TCCR0_REG, TCCR0_COM01);

#elif (COMPARE_OUTPUTMODE ==NON_PWM_TOGGLE_OC0_ONCOMPARE_MATCH)
	SET_BIT(TCCR0_REG, TCCR0_COM00);
	CLR_BIT(TCCR0_REG, TCCR0_COM01);

#elif ((COMPARE_OUTPUTMODE == NON_PWM_CLEAR_OC0_ONCOMPARE_MATCH)|| (COMPARE_OUTPUTMODE == FAST_PWM_CLEAR_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == PHASE_PWM_CLEAR_OC0_ONCOMPARE_MATCH))
	CLR_BIT(TCCR0_REG, TCCR0_COM00);
	SET_BIT(TCCR0_REG, TCCR0_COM01);

#elif ((COMPARE_OUTPUTMODE == NON_PWM_SET_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == FAST_PWM_SET_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == PHASE_PWM_SET_OC0_ONCOMPARE_MATCH))
	SET_BIT(TCCR0_REG, TCCR0_COM00);
	SET_BIT(TCCR0_REG, TCCR0_COM01);
#else
#error wrong compare match mode
#endif


/*CHOOSE CLOCK SELECT*/
	TCCR0_REG &=MASK_CLK;
	TCCR0_REG |=CLOCK_SELECT;

}

u8 MTIMER0_u8MeasureAsync(void (*ptr_TimerFuncLogic)(void))
{
	u8 Local_u8StateError = OK;
	if(ptr_TimerFuncLogic == NULL)
	{
		Local_u8StateError = NULL_POINTER;
	}
	else
	{
/* Enable the Interrupt for the required mode */

#if(WAVEFORM_GENERATION_MODE == NORMAL_WAVEFORM)
		/*enable flag overflow interrupt*/
		SET_BIT(TIMSK_REG, TIMSK_TOIE0 );

#elif(WAVEFORM_GENERATION_MODE == CTC_WAVEFORM)
		/*enable flag compare match interrupt*/
		SET_BIT(TIMSK_REG, TIMSK_OCIE0);
#endif
		G_TimerFuncNotification = ptr_TimerFuncLogic;
}
	return Local_u8StateError;
}

#if(WAVEFORM_GENERATION_MODE == CTC_WAVEFORM)     /*optimization for memory address --> if interrupts are not dependent*/

/*ISR FUNCTION FOR COMPARE MATCH MODE*/
void __vector_10(void)
{
	static volatile u32 Local_u32CompareCounter;
	Local_u32CompareCounter++;
	if(Local_u32CompareCounter == TIMER0_NUM_COMPARE_COUNTS)
	{
		/*Set Initial value */
		//TCNT0_REG = TIMER0_PRELOAD;
	if(G_TimerFuncNotification != NULL)
	{
		G_TimerFuncNotification();
	}
	Local_u32CompareCounter =0;
	}

}

/* another method ISR FUNCTION FOR COMPARE MATCH MODE ---> in app write the method 1*/
//void __vector_10(void)
//{
//	if(G_TimerFuncNotification != NULL)
//	{
//	G_TimerFuncNotification();
//	}
//}

#elif(WAVEFORM_GENERATION_MODE == NORMAL_WAVEFORM)

/*ISR FUNCTION FOR overflow MATCH MODE*/
void __vector_11(void)
{
	static volatile u32 Local_u32overflowCounter;
	Local_u32overflowCounter++;
	if(Local_u32overflowCounter == TIMER0_NUM_OVERFLOW)
	{
		/*Set Initial value */
		//TCNT0_REG = TIMER0_PRELOAD;
	if(G_TimerFuncNotification != NULL)
	{
		G_TimerFuncNotification();
	}
	Local_u32overflowCounter =0;
	}

}
#endif







