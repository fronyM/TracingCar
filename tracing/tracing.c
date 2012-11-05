#include "tracing.h"
#include "types.h"
#include "../drivers.h"
sbit sensor_0 = SENSOR^0;  //�� �� ��
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;


void found_path(u8 const locate)
{
	if(locate == STAT ){		//stat
		while(SENSOR == ~0x3F){
			engine(FORWARD, 100);	
		}
	}else if(locate == TEMPA){	//temp stopA
		
	}else if(locate == TEMPB){	//temp stopB
	
	}		
}
/*
* 	sum	ҪѰ����
*
*
*
*/
void tracing(u8 const sum)
{
	u8 count = 0; //��Ѱ����
//	while(sum != count){		//δѰ��sum����
	while(1){
//		if(((sensor_4 && sensor_5) || (sensor_0 && sensor_1)) && (sensor_2 && sensor_3)){
		if(sensor_2 && sensor_3){
			engine(FORWARD, 100);
//			while((sensor_4 && sensor_5) || (sensor_0 && sensor_1));
			count++;
				 
		}else{
			while(!(sensor_2 && sensor_3)){		//��������
				if(sensor_0 || sensor_1){	//��ƫ��
					engine(RIGHT, 100);		//�����ҵ��
				}else if(sensor_4 || sensor_5){	//��ƫ��
					engine(LEFT, 100);		//��������		
				}	
			}
		}
	}
	//engine(STOP, 100);
	engine(FORWARD, 100);
	
}
void turn(u8 direction)
{
	switch(direction){
	case L:
			engine(RIGHT, 100);
			while(!(sensor_2 && sensor_3));
			break;
	case R:
			engine(LEFT, 100);
			while(!(sensor_2 && sensor_3));
			break;
	case BACK:
			engine(LEFT, 100);
			while(!(sensor_2 && sensor_3));
			break;
	default:break;
	}
	engine(STOP, 100);
}