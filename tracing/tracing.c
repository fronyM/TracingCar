#include "tracing.h"
#include "types.h"
#include "../drivers.h"



void found_path(u8 const locate)
{
	if(locate == 0 ){		//stat
		while(SENSOR == 0x3F){
			engine(u, 100, 100);	
		}
	}else if(locate == 1){	//temp stopA
		
	}else if(locate == 2){	//temp stopB
	
	}		
}
/*
* 	sum	ҪѰ����
*
*
*
*/
void tracing(u8 const sum)
{
	u8 count = 0; //��Ѱ����
	while(sum != count){		//δѰ��sum����
		if(((SENSOR^4 && SENSOR^5) || (SENSOR^0 && SENSOR^1)) && (SENSOR^2 && SENSOR^3)){
			count++;	 
		}else{
			if((SENSOR^2 && SENSOR^3)){		//��������
				if(SENSOR^1){	//��ƫ��
					engine(r, 100, 100);
				}else if(SENSOR^4){	//��ƫ��
					engine(l, 100, 100);				
				}	
			}else{					//������
				engine(r, 100, 100);
			}
		}
	}	
}