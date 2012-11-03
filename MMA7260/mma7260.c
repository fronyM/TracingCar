#include "i2c.h"
#include "types.h"
#include "delay.h"
#include "mma7260.h"

u8 RecvMMA7620(u8 Channel)	 //CHENNEL(0-3)
{
	u8 info = 0x00;
	StartI2c();
	SendI2c(MMA7620_W);
	SendI2c(Channel);
	StartI2c();
	SendI2c(MMA7620_R);
	info = RecvI2c();
	PcAcknowledgeI2c(1); //noAck from pc
	StopI2c(); 
	return info;
}