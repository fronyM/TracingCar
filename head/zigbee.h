#include "types.h"
#include "../head/types.h"
#include <reg51.h>

#ifndef __ZIGBEE_H_
#define __ZIGBEE_H_



extern void init_serial();
extern void send_info(u8 const *, u8);
extern void send_byte(u8 const);

#endif