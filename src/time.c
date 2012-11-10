#include "../head/1602.h"
#include "../head/time.h"

static u8 count = 0;
static u8 sec = 0;
static u8 min = 0;
bit READY_FLAG = 0;
static bit F_FLAG = 0;

void initTimer0(void)
{
    TMOD = 0x01;
    TH0 = 0x4C;
    TL0 = 0x00;
    EA = 1;
    ET0 = 1;
    TR0 = 0;
}

void setTimer(u8 act)
{
    if(act == START)
	    TR0 = 1;
	if(act == STOP)
	    TR0 = 0;
    if(act == WAIT) {
        READY_FLAG = 0;
        F_FLAG = 0;
    }
}

void timePrint()
{
	write_com(CLR);
	write_data(0x31);
	write_com(0x01);
	write_char("Time: ");
	write_number(min);
	write_char(":");
	write_number(sec);

}
void main(void)
{
    
    init_1602();
	initTimer0();
	write_data(0xaa);

//	timePrint();
	setTimer(START);
	while(1);
}

void Timer0Interrupt(void) interrupt 1
{
	count ++;
	TH0 = 0x4C;
    TL0 = 0x00;
	if(count >= 20) {
	    count = 0;
		sec++;
		timePrint();
		if(sec == 30 && F_FLAG == 0) {
		    F_FLAG = 1;
			START_FLAG = 1;
		}
		if (sec >= 60) {
		    sec = 0;
			min ++;
		}
	}
}
