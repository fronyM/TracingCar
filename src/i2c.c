#include "../head/i2c.h"

void InitI2c()
{
	scl = 1;
	UsDelay(1);
	sda = 1;
	UsDelay(5);
}

void StartI2c()
{
	InitI2c();
	sda = 0;
	UsDelay(5);
	scl = 0;
}

void StopI2c()
{
	sda = 0;
	UsDelay(1);
	scl = 1;
	UsDelay(5);
	sda = 1;
	UsDelay(5);
}

void SendI2c(u8 info)
{
	u8 i = 0;
	do{
		for( i = 0; i < 8; i++){
			sda = (info >> (7 - i)) & 0x01;
			UsDelay(1);
			scl = 1;
			UsDelay(5);
			scl = 0;
			UsDelay(1);
		}
	}while(AcknowledgeI2c());
		
}

u8 RecvI2c()
{
	u8 info = 0x00,  i;
	for( i = 8; i > 0; i--){
		scl = 1;
		UsDelay(5);		
		if(sda)info += 1;
		info <<= 1;
		scl = 0;
		UsDelay(5);	
	} 
	return info;
}


u8 AcknowledgeI2c()			//from ic
{
	sda = 1;
	UsDelay(1);
	scl = 1;
	UsDelay(5);
	if (sda){
		scl = 1;
		UsDelay(1);
		return 1; 	//no ack
	}else{
		scl = 0;
		UsDelay(1);
		return 0; 			// ack
	}
}

void PcAcknowledgeI2c(u8 flag)	   // 1 noAck 0 ack
{
	sda = flag & 0x01;
	UsDelay(1);
	scl = 1;
	UsDelay(5);
	scl = 0;
	UsDelay(1);
	
}