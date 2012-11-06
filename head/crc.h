#ifndef	__CRC_H_
#define	__CRC_H_

unsigned int GET_CRC16(unsigned char* btData,unsigned char nLength)
{
	unsigned int CRC = 0xFFFF;
	unsigned char j, Tmp = 0;
	unsigned char i;
	for(i = 0; i < nLength; ++i)
	{     
		CRC ^= btData[i];                      
		for (j = 0; j < 8; ++j)                    
		{                                    
			Tmp = CRC & 0x0001;              
			CRC = CRC >> 1;                  
			if (Tmp) CRC = (CRC ^ 0xA001);     
		}                                    
	}
	return ((CRC >> 8) + (CRC << 8));
}


#endif