#include <reg51.h>
#include "delay.h"


#ifndef __1602_H_
#define __1602_H_

extern void init_1602();
extern void write_data(u8);
extern void write_com(u8);
extern void write_char(u8 *);

#endif