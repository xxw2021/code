#include "Allh.h"







//----------�����ռ�ձȿ������--------------
//ʱ���׼��0.1ms��ʱ����ִ��  ��׼4��Ϊռ�ձȱ仯1
//����ʱ��BasicTimer_ClutchSlowCloseÿ��������ռ�ձ�ʱ��ClutchCtl_Duty_Timer�仯һ��
//����򿪣�ִ������Ӧ�趨ֵHEVClutchRTSt.SlowCloseDutyʱ���رա�ִ����100ʱ���ٴδ򿪣����һ��ѭ��




//--------------PIT�滮--------------------------------
//PIT1   10KHz    0.1ms    ��Ϊʱ���׼�����ȼ����
//PIT2   100Hz    10ms     Ϊʱ���׼��100������Ϊ��ȫ���Եȵ�ִ�У�ִ��StUpdate
//PIT3   25Hz     40ms     ��Ϊ�����ִ�к���MainStep��ִ��
//PIT4   10Hz     100ms     ����










//#pragma TRAP_PROC SAVE_ALL_REGS
#pragma CODE_SEG __NEAR_SEG NON_BANKED
//-----------------------------------------------------------
//1000Hz    1ms   ʱ���׼  
//��ȫ���Ե���ش���
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
//10ms  ������ִ��ʱ��
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
  } //robin �޸����190711 
  
  PITTF=0x02;  
  EnableInterrupts;
}
#pragma CODE_SEG DEFAULT








#pragma CODE_SEG __NEAR_SEG NON_BANKED
//-----------------------------------------------------
//20ms    ��Ϊ�����ִ��ʱ��
//        ִ����Ҫ��������
//
//-----------------------------------------------------
void interrupt 68 PIT2_Int(void) 
{
  PITTF=0x04; 
  
  StepConnect_20ms();
}
#pragma CODE_SEG DEFAULT
















#pragma CODE_SEG __NEAR_SEG NON_BANKED
//��ǰΪ100ms
void interrupt 69 PIT3_Int(void) 
{
  
  StepConnect_100ms();
  
  PITTF=0x08;
}
#pragma CODE_SEG DEFAULT 


















