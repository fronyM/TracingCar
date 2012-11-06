#include <reg51.h>
#include "1602.h"


void main()
{
	Init_1602();
	Write_Data(0x31);
	Write_Com(0x80+0x40);
	Write_Char("1602&595");
	while(1)
	{
	}
}