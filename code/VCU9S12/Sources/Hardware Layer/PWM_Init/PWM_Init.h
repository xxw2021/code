//--------------------------------------------------------------------------*
//文件名: PWM.h                                                             *
//说  明: 该头文件为PWM构件的头文件                                         *
//        在需要用到PWM的地方，直接 Include "PWM.h"                         *
//        为了避免重复包含相同的文件，使用#ifndef...#define...#endinf句法   *
//--------------------------------------------------------------------------*

#ifndef PWM_INIT_H
#define PWM_INIT_H


#ifndef PWMable
#define PWMable
#define PWMEnable     PWME |= (1<<5)   //PWMEnable:PWM通道有效
#define PWMDisEnable  PWME &= ~(1<<5)  //PWMDisEnable:PWM通道无效
#endif

//构件函数声明区
extern void PWMInit(void);
extern void PWMSetting(uint8 period, uint8 duty);


void PWM_Init(void);


#endif