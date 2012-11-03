#include <regx52.h>
#include "drivers.h"
#include "types.h"


void timerInit()
{
    TMOD = 0x22;
    TH0 = 0x00;
    TL0 = 0xA4;
	TH1 = 0x00;
    TL1 = 0xA4;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
	ET1 = 1;
    TR1 = 1;
}

void engine(u8 act, u8 power1, u8 power2)
{
    powerL = power1;
	powerR = power2;
	switch(act) {
	    case u: A1 = 1; A2 = 0; B1 = 1; B2 = 0; break;
		case d: A1 = 0; A2 = 0; B1 = 1; B2 = 0; break;
		case l: A1 = 1; A2 = 0; B1 = 0; B2 = 0; break;
		case r: A1 = 0; A2 = 1; B1 = 0; B2 = 1; break;
		case s: A1 = 0; A2 = 0; B1 = 0; B2 = 0; break;
	}
}

void main(){
	timerInit();
	engine(0, 20, 10);
	while(1);
}

void timer0() interrupt 1
{
    static u8 count = 0;
	if(count < 100)
	    count++;
    else
	    count = 0;
    if(count < powerL)
	    EN1 = 1;
    else
	    EN1 = 0;
}

void timer1() interrupt 3
{
    static u8 count = 0;
	if(count < 100)
	    count++;
    else
	    count = 0;
    if(count < powerR)
	    EN2 = 1;
    else
	    EN2 = 0;
}