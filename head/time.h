#include <reg51.h>
#include "types.h"
		  
#ifndef __TIME_H_
#define __TIME_H_

#define START 1
#define STOP  0

extern bit START_FLAG;

extern void setTimer(u8 );
#endif