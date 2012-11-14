#include "../head/drivers.h"
#include "../head/tracing.h"
#include "../head/zigbee.h"
#include "../head/car.h"
#include "../head/1602.h"
#include "../head/time.h"
#include <reg51.h>

u8 locate[] = {TG_START, TG_TEMPA, TG_TEMPB, TG_A, TG_B, TG_C, TG_D, TG_E, TG_F};
sbit led1 = P2^6;
sbit led2 = P2^7;

void send_current(u8 status)
{
	u8 i;
	for(i = 0; i < 9; i++){
		if(car.current == locate[i]){
			car_send[3] = i;
			break;
		}
		car_send[4] = status;
		send_info(car_send, 5);	 	
	}
}



void init()
{
	PWMInit();
	init_1602();
	initTimer0();
	init_serial();
	timePrint();
	car.current = TG_START;

}


void main()
{
	init();
//	while(!begin);
//	send_byte(car_recv[3]);
//	car_send[3] = car_recv[3];
//	send_info(car_send, 5);	

//	setTimer(START);
	target(TG_B);
	target(TG_TEMPA);
	target(TG_B);
	target(TG_START);
//	turn(BACKWARD);
//	target(TG_A);	
//	target(TG_TEMPA);
/*		found_line(BLACK);
		turn(LEFT);
		found_line(BLACK);
	
		engine(LEFT, SPEED);
	
		while(RIGHT_O);
		on_black();

		engine(RIGHT, SPEED);
		while(!FOUND_WHITE);

		car.current = TG_TEMPA;
		car.status = 1;
	
		engine(STOP, SPEED);  
  */

//	while(RIGHT_O);
//	while(FOUND_BLACK);
//	engine(STOP, SPEED);
//	target(TG_TEMPA);


	while(1);
	{		
	}
	
}