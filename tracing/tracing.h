#include <reg51.h>
#include "types.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define SENSOR	P1	//P1^0-p1^5

extern void Locate(u8 const);
extern void tracing(u8 const);


#endif