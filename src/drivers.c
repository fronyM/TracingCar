#include "../head/drivers.h"

void PWMInit()
{
    CCON=0x00;
    CH=0;
    CL=0;
    CMOD=0x00;
    CR=1;
}

void PWM0(u8 Fosc_0)      //Fosc_0为占空比设置形参
{
    static tmp = 0;
    if(tmp != 100 - Fosc_0) { 
        tmp = 100 -Fosc_0;
        CCAP0H=CCAP0L=((tmp)*25)/10; 
        CCAPM0=0X42;                        //8位PWM输出，无中断
        PCA_PWM0=0x00;
    }
}

void PWM1(u8 Fosc_1)   
{
    static tmp = 0;
    if(tmp != 100 - Fosc_1) {
        tmp = 100 -Fosc_1;
        CCAP1H=CCAP1L=((tmp)*25)/10; 
        CCAPM1=0X42; 
        PCA_PWM1=0x00;                    //8位PWM输出，无中断
    }
}

void engine(u8 act, u8 power)
{
	switch(act) {
	    case FORWARD : A1 = 1; A2 = 0; B1 = 1; B2 = 0; PWM0(power); PWM1(power); break;
        case BACKWARD: A1 = 0; A2 = 1; B1 = 0; B2 = 1; PWM0(power); PWM1(power); break;
	    case LEFT    : A1 = 1; A2 = 0; B1 = 1; B2 = 1; PWM0(power); PWM1(0); break;
	    case RIGHT   : A1 = 1; A2 = 1; B1 = 1; B2 = 0; PWM0(0); PWM1(power); break;
	    case STOP    : A1 = 1; A2 = 1; B1 = 1; B2 = 1; PWM0(0); PWM1(0); break;
		case L_BACKWARD: A1 = 0; A2 = 1; B1 = 1; B2 = 1; PWM0(power); PWM1(power); break;
        case R_BACKWARD: A1 = 1; A2 = 1; B1 = 0; B2 = 1; PWM0(power); PWM1(power); break;

	}
}

//void engineBackward(u8 act, u8 power) 
//{
//    switch(act) {
//	    case L_BACKWARD: A1 = 0; A2 = 1; B1 = 1; B2 = 1; PWM0(power); PWM1(power); break;
//        case R_BACKWARD: A1 = 1; A2 = 1; B1 = 0; B2 = 1; PWM0(power); PWM1(power); break;
//	}    
//}
//void main(){
//	PWMInit();
//	engine(0, 20);
//	while(1);
//}