#include "zigbee.h"
#include "types.h"
#include "delay.h"
#include <reg51.h>
#include "car.h"


u8 number[] = {0x01,0x02,0xaa};

void main()
{
	init_serial();


	while(1){
//		send_info(number,3);	
//		MsDelay(100);
//
//		while(begin)
//		{
//			P1 = car.x;
//			send_info(number,3);
//		}
while(begin)P1 = car.x;

	}
}


