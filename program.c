#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_registers.h"
#include "DIO_interface.h"
#include "DIO_private.h"
/* port functions implementation*/
void MDIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case PORTA:
        if(copy_u8PortDirection  == OUTPUT)
		{
		DDRA_REG=0xff;
		}
		else if(copy_u8PortDirection  == INPUT){
			DDRA_REG=0;
		}
		else{
			// invalid direction
		}
		break;
		
		case PORTB: 
		  if(copy_u8PortDirection  == OUTPUT)
		{
		DDRB_REG=0xff;
		}
		else if((copy_u8PortDirection  == INPUT)){
			DDRB_REG=0;
		}
		else{
			// invalid direction
		}
		break;
		
		case PORTC: 
		  if(copy_u8PortDirection  == OUTPUT)
		{
		DDRC_REG=0xff;
		}
		else if((copy_u8PortDirection  == INPUT)){
			DDRC_REG=0;
		}
		else{
			// invalid direction
		}
		break;
		
		case PORTD: 
		  if(copy_u8PortDirection  == OUTPUT)
		{
		DDRD_REG=0xff;
		}
		else if(copy_u8PortDirection  == INPUT){
			DDRD_REG=0;
		}
		else{
			// invalid direction
		}
		break;
	default:
		 /*INVALID PORT ID*/
		 break;
	}
}

void MDIO_voidSetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
		case PORTA:
		if(copy_u8PortValue== HIGH)
		{
			PORTA_REG=0xff;
		}
		else if(copy_u8PortValue== LOW){
			PORTA_REG=0;
		}
		else {
             PORTA_REG=copy_u8PortValue;
		}
		break;
		
	case PORTB:
		if(copy_u8PortValue== HIGH)
		{
			PORTB_REG=0xff;
		}
		else if(copy_u8PortValue== LOW){
			PORTB_REG=0;
		}
		else{
			PORTB_REG=copy_u8PortValue;
		}
		break;
		
	case PORTC:
		if(copy_u8PortValue== HIGH)
		{
			PORTC_REG=0xff;
		}
		else if(copy_u8PortValue== LOW){
			PORTC_REG=0;
		}
		else{
			PORTC_REG=copy_u8PortValue;
		}
		break;
		
	case PORTD:
		if(copy_u8PortValue== HIGH)
		{
			PORTD_REG=0xff;
		}
		else if(copy_u8PortValue== LOW){
			PORTD_REG=0;
		}
		else{
			PORTD_REG=copy_u8PortValue;
		}
		break;
	default:
		 /*INVALID PORT ID*/
		 break;
	}
}

 /* PIN FUNCTIONS IMPLEMENTATION*/
 
 void MDIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId, u8 copy_u8PinDirection)
 {
	 switch (copy_u8PortId)
	 {
		 case PORTA:
		 if ((copy_u8PinDirection==OUTPUT) && (copy_u8PinId<=7)){
			 SET_BIT(DDRA_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinDirection==INPUT )&& (copy_u8PinId<=7)){
			 CLR_BIT(DDRA_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTB:
		 if ((copy_u8PinDirection==OUTPUT) && (copy_u8PinId<=7)){
			 SET_BIT(DDRA_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinDirection== INPUT )&& (copy_u8PinId<=7)){
			 CLR_BIT(DDRB_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTC:
		 if ((copy_u8PinDirection== OUTPUT) && (copy_u8PinId<=7)){
			 SET_BIT(DDRC_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinDirection== INPUT )&& (copy_u8PinId<=7)){
			 CLR_BIT(DDRC_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTD:
		 if ((copy_u8PinDirection== OUTPUT) && (copy_u8PinId<=7)){
			 SET_BIT(DDRD_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinDirection== INPUT )&& (copy_u8PinId<=7)){
			 CLR_BIT(DDRD_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 default:
		 /*INVALID PORT ID*/
		 break;
	 }
	 
 }
 
 void MDIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinId, u8 copy_u8PinValue)
 {
	 	 switch (copy_u8PortId)
	 {
		 case PORTA:
		 if ((copy_u8PinValue==HIGH) && (copy_u8PinId<=7)){
			 SET_BIT(PORTA_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinValue==LOW )&& (copy_u8PinId<=7)){
			 CLR_BIT(PORTA_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTB:
		 if ((copy_u8PinValue==HIGH) && (copy_u8PinId<=7)){
			 SET_BIT(PORTB_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinValue==LOW )&& (copy_u8PinId<=7)){
			 CLR_BIT(PORTB_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTC:
		 if ((copy_u8PinValue==HIGH) && (copy_u8PinId<=7)){
			 SET_BIT(PORTC_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinValue==LOW )&& (copy_u8PinId<=7)){
			 CLR_BIT(PORTC_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTD:
		 if ((copy_u8PinValue==HIGH) && (copy_u8PinId<=7)){
			 SET_BIT(PORTD_REG,copy_u8PinId);
		 }
		 else if((copy_u8PinValue==LOW )&& (copy_u8PinId<=7)){
			 CLR_BIT(PORTD_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 default:
		 /*INVALID PORT ID*/
		 break;
	 }
 }
 
 void MDIO_voidTogPinValue(u8 copy_u8PortId,u8 copy_u8PinId){
	  switch (copy_u8PortId)
	 {
		 case PORTA:
		 if  (copy_u8PinId<=7){
			 TOG_BIT(PORTA_REG,copy_u8PinId);
		 }
          else{
			// invalid direction
		}
		 break;
		 
		 case PORTB:
		 if  (copy_u8PinId<=7){
			 TOG_BIT(PORTB_REG,copy_u8PinId);
		 }
		 
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTC:
		if  (copy_u8PinId<=7){
			 TOG_BIT(PORTC_REG,copy_u8PinId);
		 }
		 else{
			// invalid direction
		}
		 break;
		 
		 case PORTD:
		if  (copy_u8PinId<=7){
			 TOG_BIT(PORTD_REG,copy_u8PinId);
		 }
		 
		 else{
			// invalid direction
		}
		break;
		 default:
		 /*INVALID PORT ID*/
		 break;
	 }
 }
     
 
 

 u8 MDIO_U8GETPinValue(u8 copy_u8PortId,u8 copy_u8PinId)
 {
 	u8 reg_return ;            // Localu8PinState
 	switch (copy_u8PortId)
 	{
 	case PORTA:
 		if  (copy_u8PinId<=7){
 			reg_return=GET_BIT(PINA_REG,copy_u8PinId);
 		}
 		else{
 			// invalid direction
 		}

 		break;

 	case PORTB:
 		if  (copy_u8PinId<=7){
 			reg_return=GET_BIT(PINB_REG,copy_u8PinId);
 		}
 		else{
 			// invalid direction
 		}
 		break;

 	case PORTC:
 		if  (copy_u8PinId<=7){
 			reg_return=GET_BIT(PINC_REG,copy_u8PinId);
 		}
 		else{
 			// invalid direction
 		}
 		break;

 	case PORTD:
 		if  (copy_u8PinId<=7){
 			reg_return=GET_BIT(PIND_REG,copy_u8PinId);
 		}
 		else{
 			// invalid direction
 		}
 		break;
 	default:
 		/*INVALID PORT ID*/
 		break;
 	}

 	return reg_return;
 }

