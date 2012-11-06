#include <reg51.h>
#include "types.h"
#ifndef __DRIVERS_H__
#define __DRIVERS_H__


sfr CCON   = 0xD8;   //PCA ���ƼĴ�����    CF    CR    -     -     -     -    CCF1  CCF0   00xx,xx00
//-----------------------
sbit CF     = CCON^7; //PCA�����������־,��Ӳ���������λ,�����������0��
sbit CR     = CCON^6; //1:���� PCA ����������, �����������0��
//
//
sbit CCF1   = CCON^1; //PCA ģ��1 �жϱ�־, ��Ӳ����λ, �����������0��
sbit CCF0   = CCON^0; //PCA ģ��0 �жϱ�־, ��Ӳ����λ, �����������0��
//-----------------------
sfr CMOD  = 0xD9; //PCA ����ģʽ�Ĵ�����   CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,x000
/*
CIDL: idle ״̬ʱ PCA �������Ƿ��������, 0: ��������, 1: ֹͣ������

CPS2: PCA ����������Դѡ��λ 2��
CPS1: PCA ����������Դѡ��λ 1��
CPS0: PCA ����������Դѡ��λ 0��
   CPS2   CPS1   CPS0
    0      0      0    ϵͳʱ��Ƶ�� fosc/12��
    0      0      1    ϵͳʱ��Ƶ�� fosc/2��
    0      1      0    Timer0 �����
    0      1      1    �� ECI/P3.4 ��������ⲿʱ�ӣ���� fosc/2��
    1      0      0    ϵͳʱ��Ƶ�ʣ�  Fosc/1
    1      0      1    ϵͳʱ��Ƶ��/4��Fosc/4
    1      1      0    ϵͳʱ��Ƶ��/6��Fosc/6
    1      1      1    ϵͳʱ��Ƶ��/8��Fosc/8

ECF: PCA����������ж�����λ, 1--���� CF(CCON.7) �����жϡ�
*/
//-----------------------
sfr CL     = 0xE9; //PCA ��������λ                                                        0000,0000
sfr CH     = 0xF9; //PCA ��������λ                                                        0000,0000
//-----------------------
//                                         7     6      5      4     3     2     1     0     Reset Value
sfr CCAPM0 = 0xDA; //PCA ģ��0 PWM �Ĵ���  -   ECOM0  CAPP0  CAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000
sfr CCAPM1 = 0xDB; //PCA ģ��1 PWM �Ĵ���  -   ECOM1  CAPP1  CAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000

//ECOMn = 1:����ȽϹ��ܡ�
//CAPPn = 1:���������ش�����׽���ܡ�
//CAPNn = 1:�����½��ش�����׽���ܡ�
//MATn  = 1:��ƥ���������ʱ, ���� CCON �е� CCFn ��λ��
//TOGn  = 1:��ƥ���������ʱ, CEXn ����ת��
//PWMn  = 1:�� CEXn ����Ϊ PWM �����
//ECCFn = 1:���� CCON �е� CCFn �����жϡ�

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   δ�����κι��ܡ�
//  x      1      0     0     0     0     x   0x21   16λCEXn�����ش�����׽���ܡ�
//  x      0      1     0     0     0     x   0x11   16λCEXn�½��ش�����׽���ܡ�
//  x      1      1     0     0     0     x   0x31   16λCEXn����(�ϡ�����)������׽���ܡ�
//  1      0      0     1     0     0     x   0x49   16λ�����ʱ����
//  1      0      0     1     1     0     x   0x4d   16λ�������������
//  1      0      0     0     0     1     0   0x42   8λ PWM��

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   �޴˲���
//  1      0      0     0     0     1     0   0x42   ��ͨ8λPWM, ���ж�
//  1      1      0     0     0     1     1   0x63   PWM����ɵͱ�߿ɲ����ж�
//  1      0      1     0     0     1     1   0x53   PWM����ɸ߱�Ϳɲ����ж�
//  1      1      1     0     0     1     1   0x73   PWM����ɵͱ�߻��ɸ߱�Ͷ��ɲ����ж�

//-----------------------
sfr CCAP0L = 0xEA; //PCA ģ�� 0 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
sfr CCAP0H = 0xFA; //PCA ģ�� 0 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
sfr CCAP1L = 0xEB; //PCA ģ�� 1 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
sfr CCAP1H = 0xFB; //PCA ģ�� 1 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
//-----------------------
//                                                       7   6   5   4   3   2    1     0    Reset Value
sfr PCA_PWM0 = 0xF2; //PCA ģ��0 PWM �Ĵ�����            -   -   -   -   -   -  EPC0H EPC0L   xxxx,xx00
sfr PCA_PWM1 = 0xF3; //PCA ģ��1 PWM �Ĵ�����            -   -   -   -   -   -  EPC1H EPC1L   xxxx,xx00
//PCA_PWMn:    7      6      5      4      3      2      1      0
//             -      -      -      -      -      -    EPCnH  EPCnL
//B7-B2: ����
//B1(EPCnH): �� PWM ģʽ�£��� CCAPnH ��� 9 λ����
//B0(EPCnL): �� PWM ģʽ�£��� CCAPnL ��� 9 λ����


sbit A1=P1^0;    // left engine postive input
sbit A2=P1^1;	   // left engine negative input
sbit B1=P1^2;	   // right engine postive input 
sbit B2=P1^5;	   // right engine negative input
sbit EN1=P1^3;   // enable for left engine
sbit EN2=P1^4;   // enable for right engine

#define FORWARD	    0
#define BACKWARD	1
#define	LEFT    	2
#define	RIGHT	    3
#define	STOP	    4

extern void PWMInit();

extern void engine(u8 act, u8 power);
#endif
