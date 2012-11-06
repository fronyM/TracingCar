#include "drivers.h"
#include "tracing/tracing.h"
#include "zigbee/zigbee.h"
#include "zigbee/car.h"
#include <reg51.h>

void init()
{
	init_serial();
	PWMInit();
	found_path(T_STAT);
	while(!(sensor_0 || sensor_1 || sensor_2 || sensor_3 || sensor_4 || sensor_5));
}

void main()
{
	init();
	tracing(1);
	engine(STOP, 99);
	while(1);
	{
	//	engine(FORWARD, 99);

	}	
}