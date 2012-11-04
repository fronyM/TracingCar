#include "tracing.h"
#include "types.h"
#include "../drivers.h"
sbit sensor_0 = SENSOR^0;
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;


void found_path(u8 const locate)
{
	if(locate == 0 ){		//stat
		while(SENSOR == 0x3F){
			engine(FORWARD, 100);	
		}
	}else if(locate == 1){	//temp stopA
		
	}else if(locate == 2){	//temp stopB
	
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
	while(sum != count){		//δѰ��sum����
		if(((sensor_4 && sensor_5) || (sensor_0 && sensor_1)) && (sensor_2 && sensor_3)){
			count++;	 
		}else{
			if((sensor_2 && sensor_3)){		//��������
				if(sensor_1){	//��ƫ��
					engine(RIGHT, 100);
				}else if(sensor_4){	//��ƫ��
					engine(LEFT, 100);				
				}	
			}else{					//������
				engine(FORWARD, 100);
			}
		}
	}	
}