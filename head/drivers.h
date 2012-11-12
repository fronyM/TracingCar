#include <reg51.h>
#include "types.h"
#include "interface.h"
#ifndef __DRIVERS_H__
#define __DRIVERS_H__



#define FORWARD	    0
#define BACKWARD	1
#define	LEFT    	2
#define	RIGHT	    3
#define	STOP	    4

extern void PWMInit();

extern void engine(u8 act, u8 power);
#endif
