#ifndef ADC_INTERFACE_H     // for guarding 
#define ADC_INTERFACE_H

/* ADC PINS */
#define ADC0   0
#define ADC1   1
#define ADC2   2
#define ADC3   3
#define ADC4   4
#define ADC5   5 
#define ADC6   6
#define ADC7   7

typedef struct
{
	u8 *Channel;
	u16 *ResultChannel;
	u8  SizeChannel;
	void (*NotificationFunc)(void);

}chainChannel;




void MADC_voidINT(void);
u16 MADC_syncvoidReadvalue(u8 copy_u8Channel, u16 *copy_u16ptrReading);

/*registration function  void (*ptr_copyValueNotification_func)(void)*/
u8 MADC_AsyncvoidReadvalue(u8 copy_u8Channel, u16 *copy_u16ptrReading, void (*ptr_copyValueNotification_func)(void));

u8 MADC_u8Asyncchain_channel(chainChannel *copy_chainChannel);



#endif 
