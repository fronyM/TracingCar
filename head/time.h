#include <reg51.h>
#include "types.h"
		  
#ifndef __TIME_H_
#define __TIME_H_

#define STOP  0
#define START 1
#define WAIT  2

extern bit READY_FLAG;

extern void setTimer(u8 );
#endif
