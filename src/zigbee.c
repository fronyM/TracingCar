#include <reg51.h>
#include "../head/zigbee.h"
#include "../head/types.h"


	
void init_serial()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	ES=1;
	EA=1;	
}


void send_info(u8 *info ,u8 count)
{
	while(count--)
	{
		SBUF = *(info++);
		while(!TI);
		TI=0;
	}
}




