

#ifndef MUSART_CFIGRATION_H_
#define MUSART_CFIGRATION_H_
/*
UE_USART_enable  1
UE_USART_disable  0
 */
#define USART_State          UE_USART_enable


/*
    Data_8_bits
    Data_9_bits
*/
#define USART_DataFramming   Data_8_bits

/*
     Idle_Line
     Address-Mark
*/
#define Wakeup_state         Idle_Line

/*
 Parity_control_disabled
 Parity_control_enabled
 */
 #define Parity_controlE   Parity_control_enabled
 
 /*
 Even_parity
 Odd_parity
 */
#define Chack_parity_State    Even_parity
/*
 Interrupt_inhibited 
 USART_interrupt 
*/
#define enable_PE_interrupt  Interrupt_inhibited /*is generated whenever PE=1 in the USART_SR register*/
/*
Interrupt_inhibited
USART_interrupt

*/

#define enable_Px_interrupt   Interrupt_inhibited /*is generated whenever TXE=1 in the USART_SR register*/

#define enable_TCIE  Interrupt_inhibited   /*is generated whenever TC=1 in the USART_SR register*/
#define RXNE_interrupt_enable Interrupt_inhibited  /*is generated whenever ORE=1 or RXNE=1 in the USART_SR register*/
#define IDLE_interrupt_enable Interrupt_inhibited  /*is generated whenever IDLE=1 in the USART_SR register*/
/*
Transmitter_disabled  
Transmitter_enabled   
*/
#define TransmitterE  Transmitter_enabled
/*
Receiver_sdisabled  
Receiver_enabled  
*/
#define ReceiverEnabled  Receiver_enabled
/*
 Receiver_active_mode 
 Receiver_in_mute_mode 
*/
#define Receiver_mode   Receiver_active_mode
/*
Receiver_active_mode  
Receiver_in_mute_mode
*/
#define break_character_transmitted  No_break_character_transmitted
/*
No_break_character_transmitted 
Break_character_btransmitted
*/
#define LIN_mode_enable LIN_mode_disabled 
/*
LIN_mode_disabled 0
LIN_mode_enabled
*/
#define STOP_Fram  one_Stop_bit
/*one_Stop_bit         
  half_Stop_bit        
 twoStop_bits            
 one_andHalf_Stop_bit 
*/


#define Clock_enable  CK_pin_disabled  

#define Steadyclkvalue  Steady_low_value 
#define Clock_phase     first_clock_transition

#define LIN_break_detection LBDIE_Interrupt_inhibited  /*generated whenever LBD=1 in the USART_SR register*/

#define LIN_break_detection_length bit_break_detection10

#define SET_Address_USART_node 0B000

#define CTS_interrupt_enable CTS_Interrupt_inhibited

#define CTS_enable  CTS_hardware_disabled 

#define RTS_enable  RTS_hardware_disabled

#define DMA_enable_transmitter DMA_mode_disabled 

#define DMA_enable_receiver    DMA_mode_disabled 

#define Smartcard_mode_enable   Smartcard_Mode_disabled

#define Smartcard_NACK_enable  NACK_transmission_disabled 

#define Half_duplex_selection Half_duplex_mode_not_selected

#define IrDA_low_power Normal_mode

#define IrDA_mode_enable IrDA_disabled 

#define Error_interrupt_enable  Error_Interrupt_inhibited 

#define TransmitterE Transmitter_enabled

#define ReceiverEnabled Receiver_enabled

#endif
