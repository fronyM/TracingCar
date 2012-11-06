#include "mma7260.h"
#include "i2c.h"
#include "delay.h"
#include "MMA7260.H"

//u8 data display[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0xc5,0xa1,0x86,0x8e};


void main()
{

	u8 i = 0;
//	InitI2c();
	while(1)
	{			
//		for( i = 0; i < 15; i++){
//			P0 = display[i];
//			MsDelay(100);
//		}
		P0 = RecvMMA7620(CHANNEL0);
//		MsDelay(100);
	}
}