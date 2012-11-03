#include "types.h"

#ifndef __REG51_H__
#ifndef __REG51_H___
#define __REG51_H___

/*  BYTE Register  */
sfr P0   = 0x80;
sfr P1   = 0x90;
sfr P2   = 0xA0;
sfr P3   = 0xB0;
sbit CY   = 0xD7;

#endif
#endif


#ifndef __I2C_H__
#define __I2C_H__
#define SDA sda
#define SCL scl

sbit scl = P2^1;
sbit sda = P2^0;


extern void InitI2c();
void StartI2c();
void StopI2c();
void SendI2c(u8);
u8 RecvI2c();
u8 AcknowledgeI2c();
void PcAcknowledgeI2c(u8);	   // 1 noAck 0 ack
#endif
