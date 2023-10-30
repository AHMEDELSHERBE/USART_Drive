#ifndef MUSART_INTERFACE_H_
#include"STD_TYPES.h"
void MUSARTSetvoid_boudRate(u32 f32boudRate);
void MUSARTIntivoid(void);
void Sendu8String(u8* u8String);
void Send_u8Char(u8  u8Char);
u8 Receive_u8Char(void);
u8* Receive_u8String(void);
#endif
