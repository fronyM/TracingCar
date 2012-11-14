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
			MsDelay(DELAY);
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
			MsDelay(DELAY);
		}while(!FOUND_WHITE);
	
	}
	engine(STOP, SPEED);

}

void a_line()
{
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
	case FORWARD :
		break;
	case L_BACKWARD:
		engine(L_BACKWARD, SPEED);
		while(!ON_WAY);
		break;
	case R_BACKWARD:
		engine(R_BACKWARD, SPEED);
		while(!ON_WAY);
		break;
	default:break;
	}
	engine(STOP, SPEED);
}

void to_tempa()
{
	turn(BACKWARD);
	switch(car.current){
	case TG_A:
		turn(RIGHT);
   		turn(RIGHT);

		a_line();
		a_line();
		a_line();
		a_line();
		a_line();

		break;
	case TG_B:
		turn(LEFT);
		turn(LEFT);

		a_line();
		a_line();
		a_line();
		a_line();

		break;
	case TG_C:
		turn(RIGHT);
		turn(RIGHT);

		a_line();
		a_line();
		a_line();

		break;
	case TG_D:
		turn(LEFT);
		turn(LEFT);

		a_line();
		a_line();

		break;
	case TG_E:
		turn(RIGHT);
		turn(RIGHT);

		a_line();

		break;
	case TG_F:
		turn(LEFT);
		turn(LEFT);


		break;
	default:break;
	}
	found_line(BLACK);
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
}


void to_tempb()
{
	turn(BACKWARD);
	switch(car.current){
	case TG_A:
		turn(RIGHT);
   		turn(RIGHT);

		a_line();
		a_line();
		a_line();
		a_line();
		a_line();

		break;
	case TG_B:
		turn(LEFT);
		turn(LEFT);

		a_line();
		a_line();
		a_line();
		a_line();


		break;
	case TG_C:
		turn(RIGHT);
		turn(RIGHT);

		a_line();
		a_line();
		a_line();


		break;
	case TG_D:
		turn(LEFT);
		turn(LEFT);

		a_line();
		a_line();


		break;
	case TG_E:
		turn(RIGHT);
		turn(RIGHT);

		a_line();


		break;
	case TG_F:
		turn(BACKWARD);
		turn(LEFT);
		turn(LEFT);

		break;
	default:break;
	}

	found_line(BLACK);
	turn(LEFT);

	a_line();
	found_line(BLACK);
	turn(LEFT);

	found_line(BLACK);
	engine(LEFT, SPEED);
	while(FOUND_BLACK);
	on_black();
	car.current = TG_TEMPB;
	car.status = 1;


	engine(STOP, SPEED);

}


void to_start()
{
	if(car.current == TG_A || car.current == TG_C || car.current == TG_E)
		turn(L_BACKWARD);
	else if(car.current == TG_B || car.current == TG_D || car.current == TG_F)
		turn(R_BACKWARD);
	switch(car.current)
	{
	case TG_A:	 
		a_line();
		a_line();
		a_line();
		a_line();
		a_line();
		break;	
	case TG_B:
		a_line();
		a_line();
		a_line();
		a_line();
		break;	
	case TG_C:
		a_line();
		a_line();
		a_line();
		break;	
	case TG_D:
		a_line();
		a_line();
		break;	
	case TG_E:
		a_line();
		break;	
	case TG_F:
		break;
	default:
		break;	
	}
	found_line(BLACK);
	turn(LEFT);
	found_line(BLACK);
	on_black();
	found_line(BLACK);
	turn(LEFT);
	found_line(BLACK);
	on_black();
	found_line(WHITE);
}
void to(u8 tg)
{
	switch(tg){
	case TG_A:
		found_line(BLACK);
		turn(LEFT);
		a_line();	
	
		turn(LEFT);
		found_line(WHITE);
		car.current = TG_A;
		break;
	case TG_B:
		found_line(BLACK);
		turn(LEFT);
	
		a_line();
		
		found_line(BLACK);
		turn(RIGHT);
		found_line(WHITE);
		car.current = TG_B;
		break;
	case TG_C:
	  	found_line(BLACK);
		turn(LEFT);
	
		a_line();
		a_line();
	
		found_line(BLACK);
		turn(LEFT);
		found_line(WHITE);
		car.current = TG_C;
		break;
	case TG_D:
		found_line(BLACK);
		turn(LEFT);
	
		a_line();
		a_line();
		a_line();
	
	
		found_line(BLACK);
		turn(RIGHT);
		found_line(WHITE);
		car.current = TG_D;
		break;
	case TG_E:
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
		break;
	case TG_F:
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
		break;
	case TG_TEMPA:
		to_tempa();
		break;
	case TG_TEMPB:
		to_tempb();
		break;
	case TG_START:
		to_start();
		break;
	default:break;





		
	}
}

void back(u8 tg)
{
	turn(BACKWARD);
	turn(R_BACKWARD);
	found_line(BLACK);
	turn(RIGHT);
	engine(FORWARD, SPEED);
	while(!RIGHT_A);
	if(car.current == TG_F)
		turn(LEFT);
	else
		turn(RIGHT);
	switch(tg){
	case TG_A:
		a_line();
		a_line();
		a_line();
		a_line();
		a_line();
	
		turn(RIGHT);
		found_line(WHITE);
		car.current = TG_A;
		break;
	case TG_B:
		a_line();
		a_line();
		a_line();
		a_line();
	
		turn(LEFT);
		found_line(WHITE);
		car.current = TG_B;
		break;
	case TG_C:
		a_line();
		a_line();
		a_line();
	
		turn(RIGHT);
		found_line(WHITE);
		car.current = TG_C;
		break;
	case TG_D:			
		a_line();//**********
		a_line();
	
		turn(LEFT);
		found_line(WHITE);
		car.current = TG_D;
		break;
	case TG_E:	
		a_line();

		turn(RIGHT);
		found_line(WHITE);
		car.current = TG_E;
		break;
	case TG_F:	
	
		found_line(WHITE);
		car.current = TG_F;
		break;
	default:break;
	}
	engine(STOP, SPEED);
}




void tracing(u8 const tg)
{
	if(car.current == TG_TEMPA || car.current == TG_TEMPB)
		back(tg);
	else
		to(tg);	
}


void target(u8 const tg)
{
	tracing(tg);
//	while(1)engine(RIGHT, SPEED);
//	MsDelay(10);		
}
