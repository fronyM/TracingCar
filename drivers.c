#include "drivers.h"
#include "types.h"

u8 powerL = 0, powerR = 0;

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

void engine(u8 act, u8 power)
{
	switch(act) {
	    case FORWARD : A1 = 1; A2 = 0; B1 = 1; B2 = 0; powerL = power; powerR = power; break;
		case BACKWARD: A1 = 0; A2 = 0; B1 = 1; B2 = 0; powerL = power; powerR = power; break;
		case LEFT    : A1 = 1; A2 = 0; B1 = 1; B2 = 1; powerL = power; powerR = 0; break;
		case RIGHT   : A1 = 1; A2 = 1; B1 = 1; B2 = 0; powerL = 0; powerR = power; break;
		case STOP    : A1 = 1; A2 = 1; B1 = 1; B2 = 1; powerL = power; powerR = power; break;
	}
}

//void main(){
//	timerInit();
//	engine(0, 20, 10);
//	while(1);
//}

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
