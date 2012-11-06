#include "../head/tracing.h"


void found_path(u8 const locate)
{
	if(locate == T_STAT ){		//stat
		while(SENSOR == ~0x3F){
			engine(FORWARD, 99);	
		}
	}else if(locate == T_TEMPA){	//temp stopA
		
	}else if(locate == T_TEMPB){	//temp stopB
	
	}		
}

void modulation()
{
	if(sensor_2 && sensor_3){
		engine(FORWARD, 99);						 
	}else{
		while(!T_ONLINE){				//��������
			if(T_RIGHT){				//��ƫ��
				engine(RIGHT, 99);		//�����ҵ��
			}else if(T_LEFT){			//��ƫ��
				engine(LEFT, 99);		//��������			   
			}	
		}
	}
	engine(FORWARD, 99);	
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
		if(T_FOUND){
			while(T_RIGHT || T_LEFT)
				modulation();
			count++;
		}
		modulation();
	}
	
}
void turn(u8 direction)
{
	switch(direction){
	case T_L:
			engine(RIGHT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	case T_R:
			engine(LEFT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	case T_BACK:
			engine(LEFT, 99);
			while(!(sensor_2 && sensor_3));
			break;
	default:break;
	}
	engine(STOP, 99);
}