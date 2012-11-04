#include <reg51.h>
#include "types.h"

					
#ifndef	__TRACING_H_
#define __TRACING_H_

#define SENSOR	P2	//P2^0-p2^5
#define L		0
#define	R		1
#define	BACK	3

#define	STAT	0
#define	TEMPA	1
#define	TEMPB	2

extern void found_path(u8 const);
extern void Locate(u8 const);
extern void tracing(u8 const);
void turn(u8);


#endif