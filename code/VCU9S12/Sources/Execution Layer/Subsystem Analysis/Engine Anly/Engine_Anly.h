#ifndef ENGINE_ANLY_H
#define ENGINE_ANLY_H




 
 
#define EngRTTrqSt_TooLow       1
#define EngRTTrqSt_Low          2
#define EngRTTrqSt_Optimal      3

#define EngRTSpdSt_Idle          1
#define EngRTSpdSt_Low           2
#define EngRTSpdSt_Optimal       3
#define EngRTSpdSt_High          4
#define EngRTSpdSt_ToHigh        5

 
    
#define  EngAnly_stEngStartedStUB_Started    1
#define  EngAnly_stEngStartedStUB_unStarted  0



#define EngAnly_Started        1
#define EngAnly_unStarted      0







extern unsigned char EngAnly_stEngStartedStUB;



extern unsigned int EngAnly_rpmIdleSpdUW;
extern unsigned int EngAnly_rpmMaxSpdlmtUW;
extern unsigned int EngAnly_rpmEngStopSpdThrUW;
extern unsigned int EngAnly_rpmEngStartSpdThrUWC;
extern unsigned int EngAnly_rpmMtrStartSpdThrUW;

extern unsigned int EngAnly_rpmEngStopSpdThrUWC;


  //����������ת�ټ�Ť��
extern unsigned int EngAnly_rpmOptimalSpdUpperlmtUW;
extern unsigned int EngAnly_rpmOptimalSpdLowerlmtUW; 
extern unsigned int EngAnly_nmMaxTrqlmtUW;
extern unsigned int EngAnly_nmOptimalTrqUpperlmtUW;
extern unsigned int EngAnly_nmOptimalTrqLowerlmtUW;
extern unsigned char EngAnly_pctOptimalTrqPctUpperlmtUB;
extern unsigned char EngAnly_pctOptimalTrqPctLowerlmtUB;  


 
  //ģʽ���ת�ټ�Ť��
extern unsigned int EngAnly_rpmParkGenSpdUW;
  //����״̬���ת��
extern unsigned int EngAnly_rpmSpdByWheelUW;
  //������������ת�ټ�Ť��
extern unsigned int EngAnly_rpmTargetSpdUW;
extern unsigned int EngAnly_rpmSpdCtrlingUW;
extern unsigned int EngAnly_rpmSpdlmtingUW;
extern unsigned int EngAnly_nmTargetTrqUW;
extern unsigned char EngAnly_pctTargerTrqPctUB;
extern unsigned char EngAnly_pctTrqPctCtrlingUB;
extern unsigned char EngAnly_pctTrqPctlmtingUB;
extern unsigned char EngAnly_pctDriveGenTrqPctCompUB;

extern unsigned char ECUEEC2_pctAccelPedalPosUB;



void EngAnly_AccelPeadlPosSmoothing_10ms(void);
void EngAnly_Update_10ms(void);
void EngAnly_Update_20ms(void);
void EngAnly_Update_100ms(void);
                    


void EngAnly_ValueInit(void);

void EngAnly_EngStartedStUpdate_20ms(void);





#endif