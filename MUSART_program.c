#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include"MUSART_configration.h"
#include"MUSART_interface.h"
#include"MUSART_privite.h"


void MUSARTSetvoid_boudRate( u32 f32boudRate)
{
	SET_BIT(MUSART->USART_CR1,13);
	
  u32 u32FltNum=(u32)f32boudRate-(u32)f32boudRate;
	u32FltNum *=16;
	MUSART->USART_BRR=0x00000000;
	MUSART->USART_BRR|=(u32)u32FltNum;
	MUSART->USART_BRR|=(u32)f32boudRate<<4;
	
}

void MUSARTIntivoid(void){
	/*make USART Enable or disable */
#if USART_State == UE_USART_enable
	MUSART->USART_SR=0;
	SET_BIT(MUSART->USART_CR1,13);

#elif USART_State == UE_USART_disable
	CLEAR_BIT(MUSART->USART_CR1,13);
#endif

/*Data are 8bits*/
#if USART_DataFramming == Data_8_bits
	CLEAR_BIT(MUSART->USART_CR1,12);

/*Data bits are 9bits*/
#elif USART_DataFramming == Data_9_bits
	SET_BIT(MUSART->USART_CR1,12);
#endif

/*select Idle_Line mode */
#if Wakeup_state == Idle_Line
	CLEAR_BIT(MUSART->USART_CR1,11);

/*select Address-Mark mode*/
#elif  Wakeup_state == Address-Mark
	SET_BIT(MUSART->USART_CR1,11);
#endif
/*to ADD parity bits to usart fram*/
#if Parity_controlE == Parity_control_enabled
	SET_BIT(MUSART->USART_CR1,10);
	#if Chack_parity_State==Even_parity
	    CLEAR_BIT(MUSART->USART_CR1,9);
	#elif Chack_parity_State== Odd_parity
	    SET_BIT(MUSART->USART_CR1,10);
	#endif

/*to clear parity*/
#elif Parity_controlE ==  Parity_control_disabled
	CLEAR_BIT(MUSART->USART_CR1,10);

#endif
  /*inttrupt generate if sender register empty*/
#if  enable_Px_interrupt == Interrupt_inhibited
	CLEAR_BIT(MUSART->USART_CR1,7);

#elif  enable_Px_interrupt == USART_interrupt 
	SET_BIT(MUSART->USART_CR1,7);

#endif
/*inttrupt generate if sender register complete*/
#if enable_TCIE == Interrupt_inhibited
	CLEAR_BIT(MUSART->USART_CR1,6);
#elif enable_TCIE == USART_interrupt 
	SET_BIT(MUSART->USART_CR1,6);
	
#endif
/*inttrupt generate if receiver register complete*/
#if RXNE_interrupt_enable == Interrupt_inhibited
	CLEAR_BIT(MUSART->USART_CR1,5);
#elif RXNE_interrupt_enable == USART_interrupt 
	SET_BIT(MUSART->USART_CR1,5);
#endif
/*enable or disable  transmitter mode*/
#if TransmitterE==Transmitter_enabled
	SET_BIT(MUSART->USART_CR1,3);

#elif TransmitterE==Transmitter_disabled
	CLEAR_BIT(MUSART->USART_CR1,3);
#endif
#if ReceiverEnabled == Receiver_enabled
	SET_BIT(MUSART->USART_CR1,2);
#elif
	ReceiverEnabled == Receiver_disable
	CLEAR_BIT(MUSART->USART_CR1,2);
#endif


	
set_registerValue(STOP_Fram,12,MUSART->USART_CR2); /* sets STOP_Fram Value in bits 12,13*/
	
}


void Send_u8Char(u8  u8Char)
{
MUSART->USART_DR=u8Char;
MUSART->USART_DR;
while(!GET_BIT(MUSART->USART_SR,6));
MUSART->USART_DR;
CLEAR_BIT(MUSART->USART_SR,6);


}


void Sendu8String(u8* u8String){
	u8 u8CharElement=0;
while(u8String[u8CharElement]!='\0'){
Send_u8Char(u8String[u8CharElement]);
u8CharElement++;
}
}


u8 Receive_u8Char(void){
	u8 u8Char;
while(!GET_BIT(MUSART->USART_SR,5));
u8Char=(u8)MUSART->USART_DR;
CLEAR_BIT(MUSART->USART_SR,5);
return u8Char;

}


u8* Receive_u8String(void){
u8 u8CharElement=0;
u8* Ru8String;
while(Ru8String[u8CharElement]!='\0'){
Ru8String[u8CharElement]=Receive_u8Char();
u8CharElement++;

}
return (Ru8String);



}
