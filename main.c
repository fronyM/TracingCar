#include "drivers.h"
#include "tracing/tracing.h"
#include "zigbee/zigbee.h"
#include "zigbee/car.h"
#include <reg51.h>

sbit sensor_0 = SENSOR^0;  //ÓÒ ¡ú ×ó
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;

void init()
{
	init_serial();
	PWMInit();
	found_path(STAT);
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