#include "../head/zigbee.h"
#include "../head/types.h"
#include "../head/delay.h"
#include <reg51.h>
#include "../head/car.h"


u8 number[] = {0xaa, 0x02, 0xaa};

void main()
{
	init_serial();

	send_info(number,3);
	while(1){ 
		while(begin){
			P1 = car.x;
			send_info(number,1);	
		}
//		MsDelay(100);
//
//		while(begin)
//		{
//			P1 = car.x;
//			send_info(number,3);
//		}*/
	} 
}


