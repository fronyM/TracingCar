#include "tracing.h"
#include "../zigbee/zigbee.h"
#include "../zigbee/car.h"
#include <reg51.h>

void init()
{
	
	while(begin);
	run(u, 50);	
}

void main()
{
	init();
	while(1);
}