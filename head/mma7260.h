#include "types.h"
#include "i2c.h"
#include "delay.h"

#ifndef __MMA7620_H__
#define __MMA7620_H__

#define	MMA7620_W	0x90
#define MMA7620_R	0x91

#define CHANNEL0	0x00
#define CHANNEL1	0x01
#define CHANNEL2	0x02
#define CHANNEL3	0x03




u8 RecvMMA7620(u8);	   //CHANNEL(0-3)

#endif