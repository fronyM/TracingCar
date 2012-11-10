#include "../head/tracing.h"

void found_line(u8 const colour)
{
	if(BLACK == colour){
		do{
			do{
				while(RIGHT_O){
					engine(LEFT, SPEED);
					if(FOUND_BLACK)break;

				}
				while(LEFT_O){
					engine(RIGHT, SPEED);
					if(FOUND_BLACK)break;
				}
				while(ON_WAY)
				{
					engine(FORWARD, SPEED);
					if(FOUND_BLACK)break;
				}
				break;
			}while(!FOUND_BLACK);
			MsDelay(20);
		}while(!FOUND_BLACK);
	}else if(WHITE == colour){
		do{
			do{
				while(RIGHT_O){
					engine(LEFT, SPEED);
					if(FOUND_WHITE)break;

				}
				while(LEFT_O){
					engine(RIGHT, SPEED);
					if(FOUND_WHITE)break;
				}
				while(ON_WAY)
				{
					engine(FORWARD, SPEED);
					if(FOUND_WHITE)break;
				}
				break;
			}while(!FOUND_WHITE);
			MsDelay(20);
		}while(!FOUND_WHITE);
	
	}

}



void modulation()
{
	found_line(BLACK);
	


	if(FOUND_WHITE){
		engine(RIGHT, SPEED);
		while(MID_A);
	}else{
		do{
			if(RIGHT_A){
				do{
					if(LEFT_O){
						engine(RIGHT, SPEED);
						while(LEFT_O);
					}else if(!sensor_3){
						engine(LEFT, SPEED);
						while(!sensor_3);
					}
					engine(FORWARD, SPEED);
				}while(RIGHT_O);    
			}else if(LEFT_A){
				do{
					if(RIGHT_O){
						engine(LEFT, SPEED);
						while(RIGHT_O);
					}else if(!sensor_2){
						engine(RIGHT, SPEED);
						while(!sensor_2);
					}
					engine(FORWARD, SPEED);
				}while(LEFT_O);		
			}
		}while(NO_WAY);
	}
	engine(STOP, SPEED);
}

void tracing(u8 const count)
{
	u8 i;
	if(count){
		for(i = 0; i < count;)
		{
			modulation();
			i++;
			car.current = i;
			P0 = i;
		}
	}else{
		engine(FORWARD, SPEED);
		while(sensor_0 || sensor_1 || sensor_2 || sensor_3 || sensor_4 || sensor_5);
	}
}

void turn(u8 const direction,u8 const colour)
{
	switch(direction){
	case RIGHT :break;
		engine(LEFT, SPEED);
		do{
			while(!sensor_1);
			MsDelay(30);
		}while(!sensor_1);
		if(BLACK == colour)
			found_line(BLACK);
		else
			found_line(WHITE);
		break;
		
	case LEFT :
		engine(RIGHT, SPEED);
		do{
			while(!sensor_5);
			MsDelay(30);
		}while(!sensor_5);
		if(BLACK == colour)
			found_line(BLACK);
		else
			found_line(WHITE);
		break;
	case BACKWARD :break;
	case FORWARD :break;
	default:break;
	}
	engine(STOP, SPEED);
}



void target(u8 const tg)
{
	tracing(tg);
	turn(LEFT, WHITE);
	MsDelay(10);
	turn(RIGHT, BLACK);		
}
