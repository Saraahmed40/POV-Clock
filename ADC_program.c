#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"ADC_registers.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_config.h"

/**************************
 * Private Global Objects *
 **************************/

/* hold the address of result to be updated */
static u16 *copy_u16ADCValue= NULL;

/* hold the address of the function to be called back */
static void (*ADC_CallBackFUNC)(void)=NULL;

static u8  *ADC_u8ptrChainChannelArr = NULL;
static u16 *ADC_u16ptrResultChannelArr = NULL;
static u8 ADC_u8ptrSizeChannel;
static u8 ADC_u8IndexChannel;
static u8 ADC_u8ISRSource;

u8 ADC_u8Busystate = IDLE;

void MADC_voidINT(void)
{
	/*  AVCC with an external capacitors at AREF PIN */
	SET_BIT(ADMUX_REG, ADMUX_REFS0);
	CLR_BIT(ADMUX_REG, ADMUX_REFS1);
	   
   /* ADC Prescaler select bits*/

    /*
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS0);
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS1);
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS2);
    */

   /* when making user to choose which configuration for prescaler make both of these lines*/
    ADCSRA_REG &= CLRMASK_ADCSRA;
    ADCSRA_REG |= ADC_PRESCALER;
	   
	 /*Activate left adjust result*/
#if(ADC_ADJUST == LEFT_ADJUST)
     SET_BIT(ADMUX_REG, ADMUX_ADLAR );

#elif(ADC_ADJUST == RIGHT_ADJUST)
	   /*Activate right adjust result*/
       CLR_BIT(ADMUX_REG, ADMUX_ADLAR );
#else
#error wrong in configration in ADC
#endif

	   /*enable ADC --> Its better to activate enable pin at the end of initial function */
      SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
	
}

u16 MADC_syncvoidReadvalue(u8 copy_u8Channel, u16 *copy_u16ptrReading)
{
	u32 Local_u32counter=0;
	u8 Local_StateError=OK;

	if(ADC_u8Busystate == IDLE){
		ADC_u8Busystate = BUSY;
	/*clear the first 5 bits  --> BY USING BIT MASKING */
	    ADMUX_REG &= CLRMASK_ADMUX;
	
	/* set the required channel into bits mux */
	   ADMUX_REG |= copy_u8Channel;
	
	/*start conversion*/
	   SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
	
	   while ((GET_BIT(ADCSRA_REG, ADCSRA_ADIF)!=TRUE) && (Local_u32counter!= ADC_u8TimeOUT) )
	   {
		Local_u32counter++;
	   }
	/* if flag has an error
	 * loop is broken bc time out is reached */
	   if (Local_u32counter==ADC_u8TimeOUT)
	   {
		 Local_StateError = NOT_OK;
	   }

	   else
	   {
		/* Loop is broken bc flag is raised */
		 /*Clear flag */
		 SET_BIT(ADCSRA_REG, ADCSRA_ADIF);
         if (NUMBER_BITS == NUM_BIT_8){
        	 *copy_u16ptrReading = ADCH_REG;
         }

         else if (NUMBER_BITS == NUM_BIT_10)
         {
	         //VALUE= ADCL_REG|ADCH_REG>>8;
        	 *copy_u16ptrReading = ADC_READ;
         }
         ADC_u8Busystate = IDLE;
	 }

	}
	else
	{
		Local_StateError = ERROR_BUSYSTATE;
	}
	 return Local_StateError ;
	 /*#if (NUMBER_BITS == NUM_BIT_8)
	  * *copy_u16ptrReading = ADCH_REG;


	 #elif (NUMBER_BITS == NUM_BIT_10)
	 	 //VALUE= ADCL_REG|ADCH_REG>>8;

	 	 *copy_u16ptrReading = ADC_READ;
	 #endif
	 */

}

u8 MADC_AsyncvoidReadvalue(u8 copy_u8Channel, u16 *copy_u16ptrReading, void (*ptr_copyValueNotification_func)(void))
{
	u8 Local_StateError = OK;
	if(ADC_u8Busystate == IDLE){
		/*TO CHECK POINTER IS POINTING TO NULL OR TO SOMETHING */
	   if(copy_u16ptrReading == NULL || ptr_copyValueNotification_func==NULL)
       {
		Local_StateError = NULL_POINTER;
       }
	    else
	   {
	    /* make ADC_u8Busystate busy not to  begin another conversion (1st conversion is not finished)  */
		ADC_u8Busystate = BUSY;
		ADC_u8ISRSource = ADC_SingleChannel_Async;

		/* Initialize the global pointer to variable with
	   the address of the variable to be updated */

		copy_u16ADCValue = copy_u16ptrReading;
		ADC_CallBackFUNC = ptr_copyValueNotification_func;

		/*clear the first 5 bits  --> BY USING BIT MASKING */
		ADMUX_REG &= CLRMASK_ADMUX;

		/* set the required channel into bits mux */
		ADMUX_REG |= copy_u8Channel;

		/*start conversion*/
		SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

		/*Enable interrupt ADC*/
		SET_BIT(ADCSRA_REG, ADCSRA_ADIE);
	 }
	}
	else
	{
		Local_StateError = ERROR_BUSYSTATE;
	}
	return Local_StateError;
}
u8 MADC_u8Asyncchain_channel(chainChannel *copy_chainChannel)
{
	u8 Local_StateError = OK;
	if(copy_chainChannel == NULL)
	{
		Local_StateError = NULL_POINTER;
	}
	else
	{
		if(ADC_u8Busystate == IDLE)
		{
			ADC_u8Busystate = BUSY;
			ADC_u8ISRSource = ADC_ChainChannel_Async;

			/*Initialize global channel array*/
			ADC_u8ptrChainChannelArr = copy_chainChannel->Channel;

			/*Initialize global result channel array*/
			ADC_u16ptrResultChannelArr = copy_chainChannel->ResultChannel;

			/*Initialize global channel size*/
			ADC_u8ptrSizeChannel = copy_chainChannel-> SizeChannel;

			/*Initialize global notification function*/
			ADC_CallBackFUNC = copy_chainChannel-> NotificationFunc;

			/*SET required channel*/

			ADC_u8IndexChannel =0;
			/*clear the first 5 bits  --> BY USING BIT MASKING */
			ADMUX_REG &= CLRMASK_ADMUX;

			/* set the required channel into bits mux */
			ADMUX_REG |= ADC_u8ptrChainChannelArr[ADC_u8IndexChannel];

			/*start Conversion */
			SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

			/*Enable interrupt ADC*/
			SET_BIT(ADCSRA_REG, ADCSRA_ADIE);

		}
	}
	return Local_StateError;
}
/**************************************
 * ISR Definition Call-Back Mechanism *
 **************************************/

void __vector_16(void)
{
	/*check ADC ISR source */
	if(ADC_u8ISRSource == ADC_SingleChannel_Async )
	{

	/* READ ADC VALUE*/
	  if (NUMBER_BITS == NUM_BIT_8){
	  	 *copy_u16ADCValue = ADCH_REG;
	  }

	  else if (NUMBER_BITS == NUM_BIT_10)
	  {
		 //VALUE= ADCL_REG|ADCH_REG>>8;
	      *copy_u16ADCValue = ADC_READ;
      }

	/* make ADC_u8Busystate idlE because conversion is finised */
	ADC_u8Busystate= IDLE;

	/*CALL BACK NOTIFICATION FUNCTION GLOBAL*/
	ADC_CallBackFUNC();

	/*Disable interrupt ADC*/
	CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
	}

	else if (ADC_u8ISRSource == ADC_ChainChannel_Async )
	{
		/*Read ADC VALUE*/
		if(NUMBER_BITS == NUM_BIT_8)
		{
			/*read the current ADC conversion*/
			ADC_u8ptrChainChannelArr[ADC_u8IndexChannel] = ADCH_REG;
			ADC_u8IndexChannel++;

			/*Check the chain is finished conversion for all ADC channels */
			if (ADC_u8IndexChannel == ADC_u8ptrSizeChannel)
			{
				/* make ADC_u8Busystate idlE because conversion is finised */
				ADC_u8Busystate= IDLE;

				/*CALL BACK NOTIFICATION FUNCTION GLOBAL*/
				ADC_CallBackFUNC();

				/*Disable interrupt ADC*/
				CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
			}
			else
			{
				/*SET New required channel*/

				ADC_u8IndexChannel =0;
				/*clear the first 5 bits  --> BY USING BIT MASKING */
				ADMUX_REG &= CLRMASK_ADMUX;

				/* set the New required channel into bits mux */
				ADMUX_REG |= ADC_u8ptrChainChannelArr[ADC_u8IndexChannel];

				/*start NewConversion */
				SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

			}

		}
		else if(NUMBER_BITS == NUM_BIT_10)
		{
			/*read the current ADC conversion*/
			ADC_u8ptrChainChannelArr[ADC_u8IndexChannel] = ADC_READ;
			ADC_u8IndexChannel++;

			/*Check the chain is finished conversion for all ADC channels */
			if (ADC_u8IndexChannel == ADC_u8ptrSizeChannel)
			{
				/* make ADC_u8Busystate idlE because conversion is finised */
				ADC_u8Busystate= IDLE;

				/*CALL BACK NOTIFICATION FUNCTION GLOBAL*/
				ADC_CallBackFUNC();

				/*Disable interrupt ADC*/
				CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
			}
			else
			{
				/*SET New required channel*/
				/*clear the first 5 bits  --> BY USING BIT MASKING */
				ADMUX_REG &= CLRMASK_ADMUX;

				/* set the New required channel into bits mux */
				ADMUX_REG |= ADC_u8ptrChainChannelArr[ADC_u8IndexChannel];

				/*start NewConversion */
				SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

			}
		}
	}
}








