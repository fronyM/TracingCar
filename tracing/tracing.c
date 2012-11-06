#include "tracing.h"
#include "types.h"
#include "../drivers.h"
sbit sensor_0 = SENSOR^0;  //右 → 左
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;


void found_path(u8 const locate)
{
	if(locate == STAT ){		//stat
		while(SENSOR == ~0x3F){
			engine(FORWARD, 99);	
		}
	}else if(locate == TEMPA){	//temp stopA
		
	}else if(locate == TEMPB){	//temp stopB
	
	}		
}

void modulation()
{
	if(sensor_2 && sensor_3){
		engine(FORWARD, 99);						 
	}else{
		while(!(sensor_2 && sensor_3)){		//不在线上
			if(sensor_0 || sensor_1){	//右偏移
				engine(RIGHT, 99);		//驱动右电机
			}else if(sensor_4 || sensor_5){	//左偏移
				engine(LEFT, 99);		//驱动左电机			   
			}	
		}
	}
	engine(FORWARD, 99);	
}

/*
* 	sum	要寻线数
*
*
*
*/
void tracing(u8 const sum)
{
	u8 count = 0; //已寻线数
	while(sum != count){		//未寻到sum条线
		if(((sensor_4 && sensor_5) || (sensor_0 && sensor_1)) && (sensor_2 && sensor_3)){
			while(sensor_0 || sensor_1 || sensor_4 || sensor_5)
				modulation();
			count++;
		}
		modulation();
	}
	
}
void turn(u8 direction)
{
	switch(direction){
	case L:
			engine(RIGHT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	case R:
			engine(LEFT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	case BACK:
			engine(LEFT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	default:break;
	}
	engine(STOP, 99);
}