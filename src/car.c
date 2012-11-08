#include "../head/car.h"


bit begin = 0;
u8 count = 0, temp;
car_t car = { 1,0,0};
u8 car_recv[] = {HEAD_H, HEAD_L, 0x00, 0x00, 0x00};
u8 car_send[] = {HEAD_H, 0x01, MASTER, 0x00, 0x00};



void i_serial() interrupt 4
{
//	P1 = car.x;
	temp = SBUF;							  	
	if(RI)
	{
	//	P1 = temp;
		if(count < 3){
			if((count == 2) && (temp == car.number)){
				count++;	
			}else if((count == 1) && (temp == HEAD_L)){
				count++;
			}else if((count == 0) && (temp == HEAD_H)){
				count++;
			}else{
				count = 0;
			}			
		}else{
			if(count == 4){
				car.y = temp;
				count = 0;
				INIT_CAR();
			}else{
				car.x = temp;
				count++;			
			}	
		}
		RI=0;
	}
	
}
