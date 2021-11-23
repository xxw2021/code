#include "Allh.h"



unsigned char EngAnly_stEngStartedStUB;
unsigned char EngAnly_stEngStartedConditionUB;
unsigned int EngAnly_20msEngStartedTimerUW;
unsigned int EngAnly_20msEngStartedTimeUWC;
unsigned int EngAnly_20msEngStoppedTimerUW;
unsigned int EngAnly_20msEngStoppedTimeUWC;
unsigned int EngAnly_rpmIdleSpdUW;
unsigned int EngAnly_rpmMaxSpdlmtUW;
unsigned int EngAnly_rpmEngStopSpdThrUW;
unsigned int EngAnly_rpmEngStartSpdThrUWC;
unsigned int EngAnly_rpmEngStopSpdThrUWC;


unsigned int EngAnly_rpmMtrStartSpdThrUW;
//发动机特性转速及扭矩
unsigned int EngAnly_rpmOptimalSpdUpperlmtUW;
unsigned int EngAnly_rpmOptimalSpdLowerlmtUW; 
unsigned int EngAnly_nmMaxTrqlmtUW;
unsigned int EngAnly_nmOptimalTrqUpperlmtUW;
unsigned int EngAnly_nmOptimalTrqLowerlmtUW;
unsigned char EngAnly_pctOptimalTrqPctUpperlmtUB;
unsigned char EngAnly_pctOptimalTrqPctLowerlmtUB;   
//模式相关转速及扭矩
unsigned int EngAnly_rpmParkGenSpdUW=1200;
//整车状态相关转速
unsigned int EngAnly_rpmSpdByWheelUW;
//发动机控制类转速及扭矩
unsigned int EngAnly_rpmTargetSpdUW;
unsigned int EngAnly_rpmSpdCtrlingUW;
unsigned int EngAnly_rpmSpdlmtingUW;
unsigned int EngAnly_nmTargetTrqUW;
unsigned char EngAnly_pctTargerTrqPctUB;
unsigned char EngAnly_pctTrqPctCtrlingUB;
unsigned char EngAnly_pctTrqPctlmtingUB;
unsigned char EngAnly_pctDriveGenTrqPctCompUB;


unsigned char EngAnly_pctAccelPedalPosBeforeUB;
unsigned int EngAnly_pctAccelPedalPosNowUW;
unsigned int EngAnly_pctAccelPedalPosIncStepUW;
unsigned char EngAnly_pctAccelPedalPosNowUB;




//10ms滤波使用变量
unsigned char EngAnly_pctAccelPedalPosIncStepUBC;
unsigned int EngAnly_numAccelPedalPosIncStepTimerUW;
unsigned int EngAnly_numAccelPedalPosIncStepTimeUWC;




unsigned char ECUEEC2_pctAccelPedalPosUB;




//发动机相关状态数据的初始化
void EngAnly_ValueInit(void)//
{
  //

  EngAnly_stEngStartedConditionUB = 0;
  EngAnly_20msEngStartedTimerUW = 0;
  EngAnly_20msEngStartedTimeUWC = 500/ms20StepTime;     //20*40=800ms 20ms*100 = 2s
  EngAnly_20msEngStoppedTimerUW = 0;
  EngAnly_20msEngStoppedTimeUWC = 600/ms20StepTime;   //20*20=400ms
  EngAnly_rpmIdleSpdUW = 0;
  EngAnly_rpmMaxSpdlmtUW = 0;
  EngAnly_rpmEngStopSpdThrUW = 80;
  EngAnly_rpmEngStartSpdThrUWC = 550;
  EngAnly_rpmEngStopSpdThrUWC = 100;
  
  EngAnly_rpmMtrStartSpdThrUW = 590;
  //发动机特性转速及扭矩
  EngAnly_rpmOptimalSpdUpperlmtUW = 0;
  EngAnly_rpmOptimalSpdLowerlmtUW = 0; 
  EngAnly_nmMaxTrqlmtUW = 0;
  EngAnly_nmOptimalTrqUpperlmtUW = 0;
  EngAnly_nmOptimalTrqLowerlmtUW = 0;
  EngAnly_pctOptimalTrqPctUpperlmtUB = 0;
  EngAnly_pctOptimalTrqPctLowerlmtUB = 0;   
  //模式相关转速及扭矩
  EngAnly_rpmParkGenSpdUW = 1200;
  //整车状态相关转速
  EngAnly_rpmSpdByWheelUW = 0;
  //发动机控制类转速及扭矩
  EngAnly_rpmTargetSpdUW = 0;
  EngAnly_rpmSpdCtrlingUW = 0;
  EngAnly_rpmSpdlmtingUW = 0;
  EngAnly_nmTargetTrqUW = 0;
  EngAnly_pctTargerTrqPctUB = 0;
  EngAnly_pctTrqPctCtrlingUB = 0;
  EngAnly_pctTrqPctlmtingUB = 0;
  EngAnly_pctDriveGenTrqPctCompUB = 0;
  
  EngAnly_pctAccelPedalPosBeforeUB = 0;
  EngAnly_pctAccelPedalPosNowUW = 0;
  
  //油门踏板开度变化step 10ms变化  10   1%    0.5%  1s变化50%
  EngAnly_pctAccelPedalPosIncStepUW = 10;    
  EngAnly_pctAccelPedalPosNowUB = 0;
  

  //10ms滤波值定量分析      
  //10ms变化1%   1s变化100%      
  //20ms变化1%   1s变化50%
  //30ms变化1%   1s变化33%
  //40ms变化1%   1s变化25%  
  EngAnly_pctAccelPedalPosIncStepUBC = 1;
  EngAnly_numAccelPedalPosIncStepTimerUW = 0;
  EngAnly_numAccelPedalPosIncStepTimeUWC = 3;
}//















void EngAnly_Update_10ms(void)//
{
  //
  EngAnly_AccelPeadlPosSmoothing_10ms();
  
}//

void EngAnly_Update_20ms(void)//
{
  //
  EngAnly_EngStartedStUpdate_20ms();

}//

void EngAnly_Update_100ms(void)//
{
  //

}//








//EngAnly_pctAccelPedalPosBeforeUB
//踩油门时进行step加减   松油门时直接下降
//输入  ECUEEC2_pctAccelPedalPosRAWUB
//输出  ECUEEC2_pctAccelPedalPosUB;
//滤波值     EngAnly_pctAccelPedalPosIncStepUBC = 1;    
//           EngAnly_numAccelPedalPosIncStepTimerUW = 1;
//           EngAnly_numAccelPedalPosIncStepTimeUWC = 3;
             
//10ms滤波值定量分析      
//10ms变化1%   1s变化100%      
//20ms变化1%   1s变化50%
//30ms变化1%   1s变化33%
//40ms变化1%   1s变化25%
void EngAnly_AccelPeadlPosSmoothing_10ms(void)//
{
  //
  if(ECUEEC2_pctAccelPedalPosRAWUB > ECUEEC2_pctAccelPedalPosUB)//
  {
    //
    EngAnly_numAccelPedalPosIncStepTimerUW ++;
    
    if(EngAnly_numAccelPedalPosIncStepTimerUW > EngAnly_numAccelPedalPosIncStepTimeUWC)//
    {
      //
      ECUEEC2_pctAccelPedalPosUB = ECUEEC2_pctAccelPedalPosUB + EngAnly_pctAccelPedalPosIncStepUBC;
      EngAnly_numAccelPedalPosIncStepTimerUW = 0;
    }//  
  }//
  else//
  {
    //
    ECUEEC2_pctAccelPedalPosUB = ECUEEC2_pctAccelPedalPosRAWUB;
  }//  
}//








//更新变量  EngAnly_stEngStartedStUB   当发动机自主旋转转速超过阈值一定时间认为发动机已经起动
//更新变量  MdST_stEngStartedMdUB
//调用中
void EngAnly_EngStartedStUpdate_20ms(void)//
{
  //  
  if((ECUEEC1_rpmEngSpdUW > EngAnly_rpmEngStartSpdThrUWC) 
  && (SWSen_stONSWUB == 1))//
  {
    //
    EngAnly_20msEngStartedTimerUW ++;
    EngAnly_20msEngStoppedTimerUW = 0;
    
    if(EngAnly_20msEngStartedTimerUW > EngAnly_20msEngStartedTimeUWC)//
    {
      //
      EngAnly_20msEngStartedTimerUW = 0;
      
      //执行锁定操作
      EngAnly_stEngStartedStUB = 1; 
    }//
    
  }//
  else if(ECUEEC1_rpmEngSpdUW < EngAnly_rpmEngStopSpdThrUWC)//
  {
    //
    EngAnly_20msEngStartedTimerUW = 0;
    EngAnly_20msEngStoppedTimerUW ++;
    
    if(EngAnly_20msEngStoppedTimerUW > EngAnly_20msEngStoppedTimeUWC)//
    {
      //
      EngAnly_20msEngStoppedTimerUW = 0;
      
      //执行状态锁定
      EngAnly_stEngStartedStUB = 0;
    }// 
    
  }//
  else//
  {
    //其余状态暂时冗余
    
  }//
}//
                                   













