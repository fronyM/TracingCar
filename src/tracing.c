#include "../head/tracing.h"



void modulation()
{
	if(!(((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3))){
		do{
			while(sensor_0 || sensor_1){
				engine(LEFT, SPEED);
				if((((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3)))break;
			}
			while(sensor_4 || sensor_5){
				engine(RIGHT, SPEED);
				if((((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3)))break;
			}
			while(!(sensor_0 || sensor_1 || sensor_4 || sensor_5))
			{
				engine(FORWARD, SPEED);
				if((((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3)))break;
			}
		}while(!(((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3)));
	}

	while(sensor_0 || sensor_1 || sensor_4 || sensor_5){
		if(sensor_0 && sensor_1){
			do{
				if(sensor_4 || sensor_5){
					engine(RIGHT, SPEED);
					while(sensor_4 || sensor_5);
				}else if(!sensor_3){
					engine(LEFT, SPEED);
					while(sensor_3);
				}
				engine(FORWARD, SPEED);
			}while(sensor_0 || sensor_1);
		}else if(sensor_4 && sensor_5){
			do{
				if(sensor_0 || sensor_1){
					engine(LEFT, SPEED);
					while(sensor_0 || sensor_1);
				}else if(!sensor_2){
					engine(RIGHT, SPEED);
					while(sensor_2);
				}
				engine(FORWARD, SPEED);
			}while(sensor_4 || sensor_5);
		
		}
	}
	UsDelay(200);	
}

void tracing(u8 const count)
{
	u8 i;
	if(count){
		for(i = 0; i < count;)
		{
			modulation();
			i++;
		}
	}else{
		engine(FORWARD, SPEED);
		while(sensor_0 || sensor_1 || sensor_2 || sensor_3 || sensor_4 || sensor_5);
	}
}
