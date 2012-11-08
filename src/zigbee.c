#include "../head/zigbee.h"



	
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

void send_byte(u8 const b)
{
	SBUF = b;
	while(!TI);
	TI=0;


}


void send_info(u8 const *info ,u8 count)
{
	u8 i;
	for(i = 0; i < count; i++){
		send_byte(*(info++));
	}
}




