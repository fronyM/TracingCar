#include "tracing.h"
#include "types.h"

u8 count = 0; //��Ѱ����

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
* 	sum	ҪѰ����
*
*
*
*/
void tracing(u8 const sum)
{
	while(sum != count){		//δѰ��sum����
		if(((SENSOR^4 && SENSOR^5) || (SENSOR^0 && SENSOR^1)) && (SENSOR^2 && SENSOR^3)){
			count++;
		}else{
			if((SENSOR^2 && SENSOR^3)){		//��������
				if(SENSOR^1){	//��ƫ��
					motor(r, 50);
				}else if(SENSOR^4){	//��ƫ��
					motor(l,50);				
				}	
			}else{					//������
				run(u, 50);
			}
		}
	}	
}