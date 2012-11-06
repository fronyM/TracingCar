#include <reg51.h>
#include "types.h"
#include "drivers.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define SENSOR	P2	//P2^0-p2^5
#define T_L		0
#define	T_R		1
#define	T_BACK	3

#define	T_STAT	0
#define	T_TEMPA	1
#define	T_TEMPB	2

#define	T_RIGHT		(sensor_0 || sensor_1)
#define	T_LEFT		(sensor_4 || sensor_5)
#define	T_MID		(sensor_2 && sensor_3)
#define	T_ONLINE	(T_MID && ~(T_RIGHT || T_LEFT))
#define	T_FOUND		(T_MID && (T_RIGHT || T_LEFT))

sbit sensor_0 = SENSOR^0;  //×ó ¡ú ÓÒ
sbit sensor_1 = SENSOR^1;
sbit sensor_2 = SENSOR^2;
sbit sensor_3 = SENSOR^3;
sbit sensor_4 = SENSOR^4;
sbit sensor_5 = SENSOR^5;

extern void found_path(u8 const);
extern void Locate(u8 const);
extern void tracing(u8 const);
void turn(u8);


#endif