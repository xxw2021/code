#include "Allh.h"







//----------离合器占空比控制相关--------------
//时间基准在0.1ms的时钟中执行  基准4次为占空比变化1
//基础时钟BasicTimer_ClutchSlowClose每隔四周期占空比时钟ClutchCtl_Duty_Timer变化一次
//阀体打开，执行至对应设定值HEVClutchRTSt.SlowCloseDuty时，关闭。执行至100时，再次打开，完成一个循环




//--------------PIT规划--------------------------------
//PIT1   10KHz    0.1ms    作为时间基准，优先级最高
//PIT2   100Hz    10ms     为时间基准的100倍，作为安全策略等的执行，执行StUpdate
//PIT3   25Hz     40ms     作为任务的执行函数MainStep的执行
//PIT4   10Hz     100ms     备用










//#pragma TRAP_PROC SAVE_ALL_REGS
#pragma CODE_SEG __NEAR_SEG NON_BANKED
//-----------------------------------------------------------
//1000Hz    1ms   时间基准  
//安全策略的相关处理
//
//-----------------------------------------------------------
void interrupt 66 PIT0_Int(void)  
{
  PITTF=0x01;
  

  StepConnect_1ms();  
}
#pragma CODE_SEG DEFAULT














uint8_T  Step50ms=0;



#pragma CODE_SEG __NEAR_SEG NON_BANKED
//--------------------------------------------------------------
//10ms  主程序执行时钟
//
//--------------------------------------------------------------
void interrupt 67 PIT1_Int(void) 
{
  DisableInterrupts;
  
  StepConnect_10ms();
  
  if(Step50ms++==6) 
  {
    Step50ms=0;
    StepConnect_50ms();
  } //robin 修改添加190711 
  
  PITTF=0x02;  
  EnableInterrupts;
}
#pragma CODE_SEG DEFAULT








#pragma CODE_SEG __NEAR_SEG NON_BANKED
//-----------------------------------------------------
//20ms    作为任务的执行时钟
//        执行主要任务内容
//
//-----------------------------------------------------
void interrupt 68 PIT2_Int(void) 
{
  PITTF=0x04; 
  
  StepConnect_20ms();
}
#pragma CODE_SEG DEFAULT
















#pragma CODE_SEG __NEAR_SEG NON_BANKED
//当前为100ms
void interrupt 69 PIT3_Int(void) 
{
  
  StepConnect_100ms();
  
  PITTF=0x08;
}
#pragma CODE_SEG DEFAULT 


















