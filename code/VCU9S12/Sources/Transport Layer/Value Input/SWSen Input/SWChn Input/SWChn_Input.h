#ifndef SWCHN_INPUT_H
#define SWCHN_INPUT_H


#define SWLH_numTotalCh  12


extern unsigned char _Btm_SWLH_Enable[SWLH_numTotalCh];
extern unsigned char SWLH_Timer1[SWLH_numTotalCh];
extern unsigned char SWLH_Timer0[SWLH_numTotalCh];
extern unsigned char PINRAW_SWLH[SWLH_numTotalCh];
extern unsigned char _Btm_SWLH_VB[SWLH_numTotalCh];





//SL=   SH=~
#define  PINRAW_SWLH_1    PORTA_PA5        //PA5   
#define  PINRAW_SWLH_2    PTT_PTT0         //PT0
#define  PINRAW_SWLH_3    PTT_PTT1         //PT1
#define  PINRAW_SWLH_4    PORTA_PA4        //PA4
#define  PINRAW_SWLH_5    PORTA_PA3        //PA3
#define  PINRAW_SWLH_6    PORTA_PA2        //PA2

#define  PINRAW_SWLH_7    PTT_PTT5        //PT5
#define  PINRAW_SWLH_8    PTT_PTT3        //PT3
#define  PINRAW_SWLH_9    ~PTT_PTT6        //PT6
#define  PINRAW_SWLH_10   ~PTT_PTT7        //PT7
#define  PINRAW_SWLH_11   ~PTT_PTT2        //PT2
#define  PINRAW_SWLH_12   ~PTT_PTT4        //PT4





void SWChn_ValueInit(void);
void SWChn_Update_10ms(void);
void SWChn_ChnEnable(void);




#endif