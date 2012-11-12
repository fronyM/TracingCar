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
				while(SENSOR_2)
				{
					engine(LEFT, SPEED);
					if(FOUND_BLACK)break;					
				}
				while(SENSOR_3)
				{
					engine(RIGHT, SPEED);
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
				while(SENSOR_2)
				{
					engine(LEFT, SPEED);
					if(FOUND_BLACK)break;					
				}
				while(SENSOR_3)
				{
					engine(RIGHT, SPEED);
					if(FOUND_BLACK)break;					
				}

				break;
			}while(!FOUND_WHITE);
			MsDelay(20);
		}while(!FOUND_WHITE);
	
	}
	engine(STOP, SPEED);

}

void a_line(){
	found_line(BLACK);
	on_black();
}

void on_black()
{
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
	engine(STOP, SPEED);
}

////void modulation()
////{
////	found_line(BLACK);
////	
////	if(FOUND_WHITE){
//////		if(car.current == 0)
//////		{
//////			engine(LEFT, SPEED);
//////			do{
//////				MsDelay(DELAY);
//////			}while(!ON_WAY);
//////		}
////	}else{
////		on_black();
////	}
////	engine(STOP, SPEED);
////}

void turn(u8 const direction)
{
	switch(direction){
	case RIGHT :
		engine(RIGHT, SPEED);
		while(!(sensor_5 || sensor_0));

		while(!ON_WAY);
		break;
		
	case LEFT :
		engine(LEFT, SPEED);
		while(!(sensor_5 || sensor_0));

		while(!ON_WAY);
		break;
	case BACKWARD :
		engine(BACKWARD, SPEED);
		while(!(RIGHT_A || LEFT_A));
		break;
	case FORWARD :break;
	default:break;
	}
	engine(STOP, SPEED);
}
void to_a()
{
	found_line(BLACK);
//	on_black();
	turn(LEFT);
	a_line();


	turn(LEFT);
	found_line(WHITE);
	car.current = TG_A;

}

void to_b()
{
	found_line(BLACK);
	turn(LEFT);

	a_line();
	

	found_line(BLACK);
	turn(RIGHT);
	found_line(WHITE);
	car.current = TG_B;

}

void to_c()
{
	found_line(BLACK);
	turn(LEFT);

	a_line();
	a_line();

	found_line(BLACK);
	turn(LEFT);
	found_line(WHITE);
	car.current = TG_C;

}

void to_d()
{
	found_line(BLACK);
	turn(LEFT);

	a_line();
	a_line();
	a_line();


	found_line(BLACK);
	turn(RIGHT);
	found_line(WHITE);
	car.current = TG_D;
}


void to_e()
{
	found_line(BLACK);
	turn(LEFT);

	a_line();
	a_line();
	a_line();
	a_line();


	found_line(BLACK);
	turn(LEFT);
	found_line(WHITE);
	car.current = TG_E;
}

void to_f()
{
	found_line(BLACK);
	turn(LEFT);

	a_line();
	a_line();
	a_line();
	a_line();
	a_line();

	found_line(BLACK);
	turn(RIGHT);
	found_line(WHITE);
	car.current = TG_F;
}

void to_tempa()
{
	switch(car.current){
	case TG_A:
		turn(BACKWARD);
		turn(RIGHT);
   		turn(RIGHT);
/*		a_line();
		a_line();
		a_line();
		a_line();
		a_line();
		found_line(BLACK);
		turn(LEFT);
		found_line(BLACK);
		engine(LEFT, SPEED);
		while(FOUND_BLACK);
		on_black();
*/
		engine(STOP, SPEED);
		break;
	case TG_B:
		turn(BACKWARD);
		turn(LEFT);
		turn(LEFT);
		break;
	case TG_C:
		turn(BACKWARD);
		turn(RIGHT);
		turn(RIGHT);
		break;
	case TG_D:
		turn(BACKWARD);
		turn(LEFT);
		turn(LEFT);
		break;
	case TG_E:
		turn(BACKWARD);
		turn(RIGHT);
		turn(RIGHT);
		break;
	case TG_F:
		turn(BACKWARD);
		turn(LEFT);
		turn(LEFT);
		break;
	default:break;
	}
}

void to_tempb()
{

}


void tracing(u8 const tg)
{
/*
	u8 i;
	if(count){
		for(i = 0; i < count;){
			found_line(BLACK);
			car.current = ++i;
			if(car.current == TG_A - 1 || car.current == TG_F + 1){
				turn(LEFT);
			}
		}
	}else{
		engine(FORWARD, SPEED);
		while(sensor_0 || sensor_1 || sensor_2 || sensor_3 || sensor_4 || sensor_5);
	}
	engine(STOP, SPEED);
*/
//	u8 count;
	switch(tg){
	case TG_A:
		to_a();
		break;
		
	case TG_B:
		to_b();
		break;

	case TG_C:
		to_c();
		break;

	case TG_D:
		to_d();
		break;

	case TG_E:
		to_e();
		break;

	case TG_F:
		to_f();
		break;

	case TG_TEMPA:
		to_tempa();
		break;

	case TG_TEMPB:
		to_tempb();
		break;

	default:break;
	}
	
}

void target(u8 const tg)
{
	tracing(tg);
//	while(1)engine(RIGHT, SPEED);
//	MsDelay(10);		
}
