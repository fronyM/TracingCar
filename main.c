#include "drivers.h"
#include "tracing/tracing.h"
#include <reg51.h>

sbit sensor_0 = SENSOR^0;  //ÓÒ ¡ú ×ó
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;

void init()
{
	timerInit();
	found_path(STAT);
}

void main()
{
	init();
	while(1)
	{
		tracing(1);
		turn(R);
	}	
}