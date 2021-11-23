//--------------------------------------------------------------------------*
//�ļ���: PWM.h                                                             *
//˵  ��: ��ͷ�ļ�ΪPWM������ͷ�ļ�                                         *
//        ����Ҫ�õ�PWM�ĵط���ֱ�� Include "PWM.h"                         *
//        Ϊ�˱����ظ�������ͬ���ļ���ʹ��#ifndef...#define...#endinf�䷨   *
//--------------------------------------------------------------------------*

#ifndef PWM_INIT_H
#define PWM_INIT_H


#ifndef PWMable
#define PWMable
#define PWMEnable     PWME |= (1<<5)   //PWMEnable:PWMͨ����Ч
#define PWMDisEnable  PWME &= ~(1<<5)  //PWMDisEnable:PWMͨ����Ч
#endif

//��������������
extern void PWMInit(void);
extern void PWMSetting(uint8 period, uint8 duty);


void PWM_Init(void);


#endif