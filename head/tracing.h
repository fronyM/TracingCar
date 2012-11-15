#include <reg51.h>
#include "types.h"
#include "drivers.h"
#include "delay.h"
#include "car.h"
#include "interface.h"
#include "1602.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define T_L		0
#define	T_R		1
#define	T_BACK	3

#define	TG_START	0
#define	TG_TEMPA	1
#define	TG_TEMPB	2

#define TG_A		3	
#define	TG_B		4
#define TG_C		5
#define	TG_D		6
#define TG_E		7
#define TG_F		8

#define SPEED	80
#define DELAY	1

#define	RIGHT_A			(sensor_0 && sensor_1)
#define	RIGHT_O			(sensor_0 || sensor_1)
#define	LEFT_A			(sensor_4 && sensor_5)
#define	LEFT_O			(sensor_4 || sensor_5)
#define	MID_A			(sensor_2 && sensor_3)
#define	MID_O			(sensor_2 || sensor_3)
#define FOUND_BLACK		(((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3))
#define FOUND_WHITE		(!(sensor_0 || sensor_1 || sensor_2 || sensor_3 || sensor_4 || sensor_5))
#define	ON_WAY			(!(sensor_0 || sensor_1 || sensor_4 || sensor_5) && sensor_2 && sensor_3)
#define	NO_WAY			(sensor_0 || sensor_1 || sensor_4 || sensor_5)	
#define	SENSOR_2		(!(sensor_0 || sensor_1 || sensor_3 || sensor_4 || sensor_5) && sensor_2)
#define	SENSOR_3		(!(sensor_0 || sensor_1 || sensor_2 || sensor_4 || sensor_5) && sensor_3)

#define	BLACK			0
#define	WHITE			1
	

sbit sensor_0 = SENSOR^0;  //×ó ¡ú ÓÒ		 0	1	2	3	4	5
sbit sensor_1 = SENSOR^1;  //				 x	x	1	1	x	x		T_ONWAY	=	(~(sensor_0 || sensor_1) && ~(sensor_4 || sensor_5) && (sensor_2 && sensor_3))	
sbit sensor_2 = SENSOR^2;  //				 x	1	x	x	x	x		T_RIGHT	=	(sensor_1)  
sbit sensor_3 = SENSOR^3;  //				 x	x	x	x	1	x		T_LEFT	=	(sensor_4)	
sbit sensor_4 = SENSOR^4;  //				 1	1	1	1	x	x		T_FOUND	
sbit sensor_5 = SENSOR^5;  //				 x	x	1	1	1	1		T_FOUND	=	(((sensor_0 && sensor_1) || (sensor_4 && sensor_5)) && (sensor_2 && sensor_3))
sbit sensor_6 = SENSOR^6;
sbit sensor_7 = SENSOR^7;

extern void found_path(u8 const);
extern void Locate(u8 const);
extern void tracing(u8 const);
extern void target(u8 const);
extern void found_line(u8 const);
//extern void modulation();
extern void turn(u8 const);
extern void on_black();
extern void a_line();
extern void to(u8);
extern void second_to(u8);
//extern u8 current;

#endif