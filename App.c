/*
 * App.c
 *
 *  Created on: Oct 11, 2021
 *      Author: ranam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"

void MTIMER_voidISR_compare(void);
void Calulate_Digits(u8 hours, u8 Minutes, u8 Seconds);

static u8	Local_u8Hours	= 12,
			Local_u8Minutes = 15,
			Local_u8Seconds	= 0;
u8 Digit1_u8Hours, Digit2_u8Hours, Digit1_u8Minutes, Digit2_u8Minutes, Digit1_u8Seconds, Digit2_u8Seconds;

void Seconds_Arrow_Display(void);
void Minutes_Arrow_Display(void);
void Hours_Arrow_Display(void);

void Frame_Display(void);
void drawMinuteMarker(void);
void drawHoursMarker(void);
void drawQuarterMarker(void);

void Clear_Display(void);


int main(void)
{
	MTIMER0_voidInitialize();
	u8 HallSensor_Value, Clock_Position, Counter = 0;

	/*PIN for Hall Sensor*/
	MDIO_voidSetPinDirection(PORTA, PIN0, INPUT);
	MDIO_voidSetPinValue(PORTA, PIN0, HIGH);

	if (Local_u8Hours == 12)
	{

		Local_u8Hours=0;
	}

	while(1)
	{
		Frame_Display();
		MADC_syncvoidReadvalue(ADC0, &HallSensor_Value);
		while(HallSensor_Value == LOW)
		{
			MADC_syncvoidReadvalue(ADC0, &HallSensor_Value);
		}

		Clock_Position = 30;
		while(Counter <60)
		{
			drawMinuteMarker();

			/*
			 * if(Clock_Position == 0)
			 * */
			if((Clock_Position == 0) || (Clock_Position == 5) || (Clock_Position == 10)||(Clock_Position == 15)
			|| (Clock_Position == 20) || (Clock_Position == 25)|| (Clock_Position == 30)||(Clock_Position == 35)
			|| (Clock_Position == 40) || (Clock_Position == 45)|| (Clock_Position == 50)||(Clock_Position == 55))
			{
				drawHoursMarker();
			}

			if ((Clock_Position == 0) || (Clock_Position == 15)
			|| (Clock_Position == 30) || (Clock_Position == 45))
			{
				drawQuarterMarker();
			}

			if ((Clock_Position == 5*Local_u8Hours)
			|| ( (Clock_Position == 0) && (Local_u8Hours == 0) ))
			{
				drawHoursMarker();
			}

			if(Clock_Position == Local_u8Minutes)
			{
				Minutes_Arrow_Display();
			}
			if(Clock_Position == Local_u8Seconds)
			{
				Seconds_Arrow_Display();
			}
			Counter++;
			Clock_Position++;
			if(Clock_Position == 60)
			{
				Clock_Position = 0;
			}

			MADC_syncvoidReadvalue(ADC0, &HallSensor_Value);
			while(HallSensor_Value == HIGH)
			{
				MADC_syncvoidReadvalue(ADC0, &HallSensor_Value);
			}

		}


	}



	return 0;
}
void Seconds_Arrow_Display(void)
{
	 HLED_voidTurnOn(PIN0, PORTC);
	 HLED_voidTurnOn(PIN1, PORTC);
	 HLED_voidTurnOn(PIN2, PORTC);
	 HLED_voidTurnOn(PIN3, PORTC);
	 HLED_voidTurnOn(PIN4, PORTC);
	 HLED_voidTurnOn(PIN5, PORTC);
	 HLED_voidTurnOn(PIN6, PORTC);
	 HLED_voidTurnOn(PIN7, PORTC);

	 HLED_voidTurnOn(PIN0, PORTB);
	 HLED_voidTurnOn(PIN1, PORTB);
	 HLED_voidTurnOn(PIN2, PORTB);
	 HLED_voidTurnOn(PIN3, PORTB);
}

void Minutes_Arrow_Display(void)
{
	 HLED_voidTurnOn(PIN0, PORTC);
	 HLED_voidTurnOn(PIN1, PORTC);
	 HLED_voidTurnOn(PIN2, PORTC);
	 HLED_voidTurnOn(PIN3, PORTC);
	 HLED_voidTurnOn(PIN4, PORTC);
	 HLED_voidTurnOn(PIN5, PORTC);
	 HLED_voidTurnOn(PIN6, PORTC);
	 HLED_voidTurnOn(PIN7, PORTC);

}

void Hours_Arrow_Display(void)
{
	 HLED_voidTurnOn(PIN0, PORTC);
	 HLED_voidTurnOn(PIN1, PORTC);
	 HLED_voidTurnOn(PIN2, PORTC);
	 HLED_voidTurnOn(PIN3, PORTC);
	 HLED_voidTurnOn(PIN4, PORTC);

}

void Frame_Display(void)
{
	HLED_voidTurnOn(PIN7, PORTB);
}

void drawMinuteMarker(void)
{
	HLED_voidTurnOn(PIN6, PORTB);
}

void drawHoursMarker(void)
{
	HLED_voidTurnOn(PIN4, PORTB);
	HLED_voidTurnOn(PIN5, PORTB);
}

void drawQuarterMarker(void)
{
	 HLED_voidTurnOn(PIN6, PORTB);
}

void Clear_Display(void)
{
	 HLED_voidTurnOff(PIN0, PORTC);
	 HLED_voidTurnOff(PIN1, PORTC);
	 HLED_voidTurnOff(PIN2, PORTC);
	 HLED_voidTurnOff(PIN3, PORTC);
	 HLED_voidTurnOff(PIN4, PORTC);
	 HLED_voidTurnOff(PIN5, PORTC);
	 HLED_voidTurnOff(PIN6, PORTC);
	 HLED_voidTurnOff(PIN7, PORTC);

	 HLED_voidTurnOff(PIN0, PORTB);
	 HLED_voidTurnOff(PIN1, PORTB);
	 HLED_voidTurnOff(PIN2, PORTB);
	 HLED_voidTurnOff(PIN3, PORTB);
	 HLED_voidTurnOff(PIN4, PORTB);
	 HLED_voidTurnOff(PIN5, PORTB);
	 HLED_voidTurnOff(PIN6, PORTB);
	 HLED_voidTurnOff(PIN7, PORTB);

}

void MTIMER_voidISR_compare(void)
{

		Local_u8Seconds++;

		if(Local_u8Seconds == 60)
		{
			Local_u8Seconds=0;
			Local_u8Minutes++;
		}

		if(Local_u8Minutes == 60)
		{
			Local_u8Minutes=0;
			Local_u8Hours++;
		}
		if(Local_u8Hours ==12)
		{
			Local_u8Hours=0;
		}

}


void Calulate_Digits(u8 hours, u8 Minutes, u8 Seconds)
{
	Digit1_u8Hours  = hours % 10;
	Digit2_u8Hours  = hours / 10;


	Digit1_u8Minutes  = Minutes % 10;
	Digit2_u8Minutes  = Minutes / 10;


	Digit1_u8Seconds = Seconds % 10;
	Digit2_u8Seconds = Seconds / 10;

}
