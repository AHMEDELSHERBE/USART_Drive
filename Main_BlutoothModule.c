#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "delay.h"
#include "RCC_interface.h"
#include"MUSART_interface.h"
int main()
{	MGPIO_voidSetPinDirection(PORTA,3,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(PORTA,2,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
   void MUSARTIntivoid();
	void MUSARTSetvoid_boudRate(9600);
	while(1)
	{
	  u8 Data_in = Receive_u8Char();	/* receive data from Bluetooth device*/
		if(Data_in =='1')
		{
			MGPIO_voidSetPinValue(PORTA,3,1);;	/* Turn ON LED */
			Sendu8String("LED_ON");/* send status of LED i.e. LED ON */
			
		}
		else if(Data_in =='2')
		{
			MGPIO_voidSetPinValue(PORTA,3,0);
			Sendu8String("LED_OFF"); /* send status of LED i.e. LED OFF */
		}
		else
			Sendu8String("Select proper option"); /* send message for selecting proper op	
		
		
		
		
	}	
}