#include "../head/drivers.h"
#include "../head/tracing.h"
#include "../head/zigbee.h"
#include "../head/car.h"
#include "../head/1602.h"
#include <reg51.h>

void init()
{
	init_serial();
	init_1602();
	PWMInit();
	found_path(T_STAT);
	while(!(T_RIGHT || T_LEFT || T_MID));
}

void main()
{
	init();
//	write_data(0x31);
//	write_com(0x80+0x40);
//	write_char("1602&595");


	tracing(1);
	engine(STOP, 99);

	while(1);
	{
	//	engine(FORWARD, 99);

	}	
}