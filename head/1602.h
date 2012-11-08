#include <reg51.h>
#include "delay.h"
#include <stdarg.h>
#include <stdlib.h>
#include "types.h"
		  

#ifndef __1602_H_
#define __1602_H_

#define CR	0x80+0x40
#define CLR	0x01

extern void print(u8 *, ...);
extern void init_1602();
extern void write_data(u8);
extern void write_com(u8);
extern void write_char(u8 *);


#endif