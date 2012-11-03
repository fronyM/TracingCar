#include "tracing.h"
#include "types.h"

u8 count = 0; //已寻线数

void found_path(u8 const locate)
{
	if(locate == 0 ){		//stat
		while(SENSOR == 0x3F){
			run(u, 50);	
		}
	}else if(locate == 1){	//temp stopA
		
	}else if(locate == 2){	//temp stopB
	
	}		
}
/*
* 	sum	要寻线数
*
*
*
*/
void tracing(u8 const sum)
{
	while(sum != count){		//未寻到sum条线
		if(((SENSOR^4 && SENSOR^5) || (SENSOR^0 && SENSOR^1)) && (SENSOR^2 && SENSOR^3)){
			count++;
		}else{
			if((SENSOR^2 && SENSOR^3)){		//不在线上
				if(SENSOR^1){	//左偏移
					motor(r, 50);
				}else if(SENSOR^4){	//右偏移
					motor(l,50);				
				}	
			}else{					//在线上
				run(u, 50);
			}
		}
	}	
}