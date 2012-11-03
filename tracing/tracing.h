#include <reg51.h>
#include "types.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define SENSOR	P2	//P2^0-p2^5

extern void Locate(u8 const);
extern void tracing(u8 const);


#endif