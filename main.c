#include "../head/drivers.h"
#include "../head/tracing.h"
#include "../head/zigbee.h"
#include "../head/car.h"
#include "../head/1602.h"
#include <reg51.h>

void init()
{
	PWMInit();
}

void main()
{
	init();	
//	engine(FORWARD, 99);
	target(TG_F);
//	target(TG_TEMPA);
	engine(STOP, SPEED);
//
	while(1);
	{
		while(sensor_0)engine(FORWARD, SPEED);
		engine(STOP, SPEED);
	}
	
}