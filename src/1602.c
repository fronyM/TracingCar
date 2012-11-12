#include "../head/1602.h"

//sbit sck = P0^0;
//sbit ser = P0^1;
//sbit rck = P0^2;


char code int2charLCD[] = "0123456789";


//void print(u8 *c, ...)
//{
//	va_list args;
//	u8 *s;
//	u8 va;
//	va_start(args, c);
//	for(s = c; *s != '\0'; s++){
//		if(*s == '%'){
//			va = va_arg(args, u8);
//			write_data(va);
//			continue;
//		}
//		write_data(*s);
//	}
//}

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

	DATA_1602 = com;

	UsDelay(200);
	lcde = 1;
	UsDelay(800);
	lcde = 0;
	UsDelay(100);	
}

void write_data(u8 dat)
{
//	u8 i ;
	rs = 1;
	rw = 0;
	lcde = 0;

	DATA_1602 = dat;

	UsDelay(200);
	lcde = 1;
	UsDelay(800);
	lcde = 0;
	UsDelay(100);	
}

void write_char(u8 *c)
{
	while(*c != '\0')
		write_data(*(c++));
}

void write_number(char number)
{
	unsigned char x,y;
	x=number/10;
	y=number-10*x;
	write_data(int2charLCD[x]);
	write_data(int2charLCD[y]);
}
