#include <regx52.h>
#include "drivers.h"
#include "types.h"


void InitTimer0(void)
{
    TMOD |= 0x02;
    TH0 = 0x00;
    TL0 = 0xF7;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void InitTimer1(void)
{
    TMOD |= 0x20;
    TH1 = 0x00;
    TL1 = 0x0F7;
    EA = 1;
    ET1 = 1;
    TR1 = 1;
}

void engine(u8 act, u8 power1, u8 power2)
{
    powerL = power1;
	powerR = power2;
	switch(act) {
	    case 0: A1 = 1; A2 = 0; B1 = 1; B2 = 0; break;
		case 1: A1 = 0; A2 = 0; B1 = 1; B2 = 0; break;
		case 2: A1 = 1; A2 = 0; B1 = 0; B2 = 0; break;
		case 3: A1 = 0; A2 = 1; B1 = 0; B2 = 1; break;
	}
}

void main(){
	InitTimer0();
	InitTimer1();
}

void timer0() interrupt 1
{
    static u8 count = 0;
    TH0 = 0x00;
    TL0 = 0xF7;
	if(count < 100)
	    count++;
    else
	    count = 0;
    if(count < powerL)
	    EN1 = 0;
    else
	    EN1 = 1;
}

void timer1() interrupt 3
{
    static u8 count = 0;
    TH1 = 0x00;
    TL1 = 0x0F7;
	if(count < 100)
	    count++;
    else
	    count = 0;
    if(count < powerR)
	    EN2 = 0;
    else
	    EN2 = 1;
}