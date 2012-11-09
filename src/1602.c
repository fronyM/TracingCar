#include "../head/1602.h"

//sbit sck = P0^0;
//sbit ser = P0^1;
//sbit rck = P0^2;

sbit rs = P1^6;
sbit rw = P1^7;
sbit lcde = P2^6;


void print(u8 *c, ...)
{
	va_list args;
	u8 *s;
	u8 va;
	va_start(args, c);
	for(s = c; *s != '\0'; s++){
		if(*s == '%'){
			va = va_arg(args, u8);
			write_data(va);
			continue;
		}
		write_data(*s);
	}
}

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
//	u8 i ;
	rs=0;
	rw=0;
	lcde=0;

	P0 = com;

	UsDelay(40);
	lcde=1;
	UsDelay(160);
	lcde=0;
	UsDelay(20);	
}

void write_data(u8 dat)
{
//	u8 i ;
	rs = 1;
	rw = 0;
	lcde = 0;

	P0 = dat;

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


