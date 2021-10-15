#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_registers.h"
#include"DIO_interface.h"
#include"DIO_private.h"
#include"LED_interface.h"
#include"LED_config.h"




void HLED_voidTurnOn(u8 Copy_u8PIN, u8 PORT_LED)
{
	 MDIO_voidSetPinDirection(PORT_LED,Copy_u8PIN, OUTPUT);
	 MDIO_voidSetPinValue(PORT_LED,Copy_u8PIN, HIGH);
}


void HLED_voidTurnOff(u8 Copy_u8PIN, u8 PORT_LED)
{
	 MDIO_voidSetPinDirection(PORT_LED,Copy_u8PIN, OUTPUT);
	 MDIO_voidSetPinValue(PORT_LED, Copy_u8PIN, LOW);
}

void HLED_voidToggle(u8 Copy_u8PIN, u8 PORT_LED)
{
	 MDIO_voidSetPinDirection(PORT_LED,Copy_u8PIN, OUTPUT);
	 TOG_BIT(PORT_LED, Copy_u8PIN);
//if(GET_BIT(PINA_REG, Copy_u8PIN)==0)
//	 MDIO_voidSetPinValue(PORT_LED,Copy_u8PIN, HIGH);
//
//else if(GET_BIT(PINA_REG, Copy_u8PIN)==1)
//	 MDIO_voidSetPinValue(PORT_LED,Copy_u8PIN, LOW);

}



