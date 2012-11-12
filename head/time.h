#include <reg51.h>
#include "types.h"
#include "car.h"
		  
#ifndef __TIME_H_
#define __TIME_H_

#define P  0
#define START 1
#define WAIT  2

extern bit READY_FLAG;

extern void setTimer(u8 );
extern void initTimer0();
extern void timePrint();
#endif
