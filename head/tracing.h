#include <reg51.h>
#include "types.h"
#include "drivers.h"
#include "delay.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define SENSOR	P2	//P2^0-p2^5
#define T_L		0
#define	T_R		1
#define	T_BACK	3

#define	T_STAT	0
#define	T_TEMPA	1
#define	T_TEMPB	2

#define SPEED	70

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

#endif