#ifndef MUSART_PRIVITE_H_
#define MUSART_PRIVITE_H_
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#define SetValuReg(x,y,z)    x&=(0<<y)|(z<<y);

typedef struct{
   u32 volatile USART_SR;
   u32 volatile USART_DR;
   u32 volatile USART_BRR;
   u32 volatile USART_CR1;
   u32 volatile USART_CR2;
   u32 volatile USART_CR3;
   u32 volatile USART_GTPR;
}MUSART_REGbank;

#define MUSART   ((volatile MUSART_REGbank*)0x40013800)





#define UE_USART_enable  1
#define UE_USART_disable 0

#define Data_8_bits 0
#define Data_9_bits 1

#define Idle_Line 0
#define Address_Mark 1


#define Parity_control_disabled  0
#define Parity_control_enabled   1

#define Even_parity  0
#define Odd_parity   1


#define Interrupt_inhibited  0
#define USART_interrupt      1

#define Interrupt_inhibited  0
#define USART_interrupt      1


#define Interrupt_inhibited  0
#define USART_interrupt      1
/*
#define Interrupt_inhibited  0
#define USART_interrupt      1

#define Interrupt_inhibited   0
#define USART_interrupt       1
*/
#define Interrupt_inhibited  0
#define USART_interrupt      1

#define Transmitter_disabled  0
#define Transmitter_enabled   1

#define Receiver_disable     0
#define Receiver_enabled      1

#define Receiver_active_mode  0
#define Receiver_in_mute_mode 1

#define No_break_character_transmitted 0
#define Break_character_btransmitted   1

#define LIN_mode_disabled 0
#define LIN_mode_enabled  1


#define one_Stop_bit          0b00
#define  half_Stop_bit        0b01
#define twoStop_bits          0b10  
#define one_andHalf_Stop_bit  0b11


#define  CK_pin_disabled   0
#define  CK_pin_enabled    1

#define Steady_low_value   0
#define Steady_high_value  1

#define  first_clock_transition  0
#define second_clock_transition  1

#define clock_pulse_Not_output_CK_pin  0
#define clock_pulse_output_CK_pin  1

#define LBDIE_Interrupt_inhibited 0
#define LBDIE_Interrupt_Enable    1

#define bit_break_detection10   0
#define bit_break_detection11   1

#define Address_USART_node 0B000

#define CTS_Interrupt_inhibited  0
#define CTS_interrupt            1 

#define CTS_hardware_disabled    0
#define CTS_mode_enabled         1

#define RTS_hardware_disabled  0
#define RTS_interrupt_enabled  1

#define DMA_mode_enabled   1
#define DMA_mode_disabled  0

#define DMA_mode_enabled   1
#define DMA_mode_disabled  0

#define Smartcard_Mode_disabled 0
#define Smartcard_Mode_enabled  1

#define NACK_transmission_disabled 0
#define NACK_transmission_enabled  1

#define Half_duplex_mode_not_selected 0
#define Half_duplex_mode_selected     1


#define Normal_mode    0
#define Low_power_mode 1

#define IrDA_disabled 0
#define IrDA_enabled  1

#define Error_Interrupt_inhibited  0
#define Error_interrupt            1 



#endif
