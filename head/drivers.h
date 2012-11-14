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
#define L_BACKWARD	5
#define R_BACKWARD	6

extern void PWMInit();

extern void engine(u8 act, u8 power);
//extern void engineBackward(u8 act, u8 power);
#endif
