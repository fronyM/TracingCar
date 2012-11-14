#include "types.h"
#include "zigbee.h"
#include <reg51.h>
#include "types.h"


#ifndef __CAR_H__
#define __CAR_H__

/*************
*	haed of infomation
**************/
#define	HEAD_H	0xff
#define	HEAD_L	0xff
#define	MASTER	0x00
#define	CAR_1	0x01
#define	CAR_2	0x02

/*************
*	locate of infomation
**************/
#define	AA	0X00
#define	BB	0X01
#define	CC	0X02
#define	DD	0X03
#define	EE	0X04
#define	FF	0X05
#define LA	0x06
#define	LB	0x07


/***************
*	status of infomation
***************/
#define	RECV	0x00
#define	PAUSE	0x01
#define	RETURN	0x02
 

#define INIT_CAR()				do{	car_recv[2] = car.number;		\
									car_recv[3] = car.x;			\
									car_recv[4] = car.y;			\
									begin = 1;}while(0)

#define CAR_SEND(x,status)		do{	car_send[3] = x;				\
									car_send[4] = status;			\
									send_info(car_send,5);}while(0)

	
typedef struct Car{
	u8 number;
	u8 x;
	u8 y;
	u8 current;
	u8 status;
} car_t;

extern car_t car;
//extern u8 car_recv[];
//extern void init_car();
extern bit begin;
extern u8 car_send[];
extern u8 car_recv[];


#endif