#include <reg51.h>
#include "types.h"
#ifndef __DRIVERS_H__
#define __DRIVERS_H__


sfr CCON   = 0xD8;   //PCA 控制寄存器。    CF    CR    -     -     -     -    CCF1  CCF0   00xx,xx00
//-----------------------
sbit CF     = CCON^7; //PCA计数器溢出标志,由硬件或软件置位,必须由软件清0。
sbit CR     = CCON^6; //1:允许 PCA 计数器计数, 必须由软件清0。
//
//
sbit CCF1   = CCON^1; //PCA 模块1 中断标志, 由硬件置位, 必须由软件清0。
sbit CCF0   = CCON^0; //PCA 模块0 中断标志, 由硬件置位, 必须由软件清0。
//-----------------------
sfr CMOD  = 0xD9; //PCA 工作模式寄存器。   CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,x000
/*
CIDL: idle 状态时 PCA 计数器是否继续计数, 0: 继续计数, 1: 停止计数。

CPS2: PCA 计数器脉冲源选择位 2。
CPS1: PCA 计数器脉冲源选择位 1。
CPS0: PCA 计数器脉冲源选择位 0。
   CPS2   CPS1   CPS0
    0      0      0    系统时钟频率 fosc/12。
    0      0      1    系统时钟频率 fosc/2。
    0      1      0    Timer0 溢出。
    0      1      1    由 ECI/P3.4 脚输入的外部时钟，最大 fosc/2。
    1      0      0    系统时钟频率，  Fosc/1
    1      0      1    系统时钟频率/4，Fosc/4
    1      1      0    系统时钟频率/6，Fosc/6
    1      1      1    系统时钟频率/8，Fosc/8

ECF: PCA计数器溢出中断允许位, 1--允许 CF(CCON.7) 产生中断。
*/
//-----------------------
sfr CL     = 0xE9; //PCA 计数器低位                                                        0000,0000
sfr CH     = 0xF9; //PCA 计数器高位                                                        0000,0000
//-----------------------
//                                         7     6      5      4     3     2     1     0     Reset Value
sfr CCAPM0 = 0xDA; //PCA 模块0 PWM 寄存器  -   ECOM0  CAPP0  CAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000
sfr CCAPM1 = 0xDB; //PCA 模块1 PWM 寄存器  -   ECOM1  CAPP1  CAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000

//ECOMn = 1:允许比较功能。
//CAPPn = 1:允许上升沿触发捕捉功能。
//CAPNn = 1:允许下降沿触发捕捉功能。
//MATn  = 1:当匹配情况发生时, 允许 CCON 中的 CCFn 置位。
//TOGn  = 1:当匹配情况发生时, CEXn 将翻转。
//PWMn  = 1:将 CEXn 设置为 PWM 输出。
//ECCFn = 1:允许 CCON 中的 CCFn 触发中断。

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   未启用任何功能。
//  x      1      0     0     0     0     x   0x21   16位CEXn上升沿触发捕捉功能。
//  x      0      1     0     0     0     x   0x11   16位CEXn下降沿触发捕捉功能。
//  x      1      1     0     0     0     x   0x31   16位CEXn边沿(上、下沿)触发捕捉功能。
//  1      0      0     1     0     0     x   0x49   16位软件定时器。
//  1      0      0     1     1     0     x   0x4d   16位高速脉冲输出。
//  1      0      0     0     0     1     0   0x42   8位 PWM。

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   无此操作
//  1      0      0     0     0     1     0   0x42   普通8位PWM, 无中断
//  1      1      0     0     0     1     1   0x63   PWM输出由低变高可产生中断
//  1      0      1     0     0     1     1   0x53   PWM输出由高变低可产生中断
//  1      1      1     0     0     1     1   0x73   PWM输出由低变高或由高变低都可产生中断

//-----------------------
sfr CCAP0L = 0xEA; //PCA 模块 0 的捕捉/比较寄存器低 8 位。                                    0000,0000
sfr CCAP0H = 0xFA; //PCA 模块 0 的捕捉/比较寄存器高 8 位。                                    0000,0000
sfr CCAP1L = 0xEB; //PCA 模块 1 的捕捉/比较寄存器低 8 位。                                    0000,0000
sfr CCAP1H = 0xFB; //PCA 模块 1 的捕捉/比较寄存器高 8 位。                                    0000,0000
//-----------------------
//                                                       7   6   5   4   3   2    1     0    Reset Value
sfr PCA_PWM0 = 0xF2; //PCA 模块0 PWM 寄存器。            -   -   -   -   -   -  EPC0H EPC0L   xxxx,xx00
sfr PCA_PWM1 = 0xF3; //PCA 模块1 PWM 寄存器。            -   -   -   -   -   -  EPC1H EPC1L   xxxx,xx00
//PCA_PWMn:    7      6      5      4      3      2      1      0
//             -      -      -      -      -      -    EPCnH  EPCnL
//B7-B2: 保留
//B1(EPCnH): 在 PWM 模式下，与 CCAPnH 组成 9 位数。
//B0(EPCnL): 在 PWM 模式下，与 CCAPnL 组成 9 位数。


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
