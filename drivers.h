#ifndef __DRIVERS_H__
#define __DRIVERS_H__

#include "types.h"

sbit A1=P1^0;    // left engine postive input
sbit A2=P1^1;	   // left engine negative input
sbit B1=P1^2;	   // right engine postive input 
sbit B2=P1^3;	   // right engine negative input
sbit EN1=P1^4;   // enable for left engine
sbit EN2=P1^5;   // enable for right engine


extern unsigned char powerL = 0, powerR = 0;

extern void engine(u8 act, u8 power1, u8 power2);

#endif