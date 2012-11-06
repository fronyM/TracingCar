#include "../head/1602.h"

sbit sck = P0^0;
sbit ser = P0^1;
sbit rck = P0^2;

sbit rs = P0^3;
sbit rw = P0^4;
sbit lcde = P0^5;


void init_1602()
{
	write_com(0x38);
	write_com(0x08);
	write_com(0x01);
	write_com(0x06);
	write_com(0x0c);
}

void write_com(u8 com)
{
	u8 i ;
	rs=0;
	rw=0;
	lcde=0;

	rck=0;
	for(i = 8; i > 0; i--)
	{
		sck=0;
		ser=(com >> ( i - 1))&0x01;
		sck=1;		
	}
	rck=1;

	UsDelay(40);
	lcde=1;
	UsDelay(160);
	lcde=0;
	UsDelay(20);	
}

void write_data(u8 dat)
{
	u8 i ;
	rs = 1;
	rw = 0;
	lcde = 0;

	rck = 0;
	for(i = 8; i > 0; i--)
	{
		sck = 0;
		ser=(dat >> ( i - 1)) & 0x01;
		sck = 1;		
	}
	rck = 1;

	UsDelay(40);
	lcde = 1;
	UsDelay(160);
	lcde = 0;
	UsDelay(20);	
}

void write_char(u8 *c)
{
	while(*c != '\0')
		write_data(*(c++));
}


