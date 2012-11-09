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
	tracing(2);
	engine(STOP, SPEED);

	while(1);
	{
		while(sensor_0)engine(FORWARD, SPEED);
		engine(STOP, SPEED);
	}
	
}