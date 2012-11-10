#include <reg51.h>
#include "../head/1602.h"
#include "../head/types.h"


void main()
{
	u8 a = 12;
	init_1602();
	write_data(0x31);
	write_com(0x01);
	write_char("1602&595");
//	print("a%a%a%",a,a,a);
	while(1)
	{
	}
}