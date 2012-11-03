#ifndef __INTRINS_H__
#define __INTRINS_H__

extern void          _nop_     (void);

#endif

#ifndef __TYPES_H__
#define __TYPES_H__
#include "types.h"
#endif



#ifndef __DELAY_H__
#define __DELAY_H__



//void UsDelay(u32);
//void MsDelay(u32);														  
#define	MS	1000
#ifndef __DELAY__
#define __DELAY__
#define UsDelay(x)	do{u32 i = x;\
						while( i--)_nop_();}while(0);
#define	MsDelay(x)	do{u32 i = MS;\
						while( i--)\
						UsDelay(x);}while(0);
#endif
#endif