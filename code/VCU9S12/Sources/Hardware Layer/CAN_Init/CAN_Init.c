#include "Allh.h"




//-------------------MSCANModuleInit------------------------
//ʵ��CANģ��Ӳ���Լ�������ݵĳ�ʼ��
//ִ�У�   MSCANHardwareInit();     MSCANDataInit();
//----------------------------------------------------------
void MSCAN_Init(void)//
{
  //
  MSCAN_ChConfig(); 
  MSCANHardwareInit();
}





void MSCAN_ChConfig(void)//
{
  //
  //MODRR_MODRR2=1;
  //MODRR_MODRR3=0;
  
  //���ú��趨MSCAN4 CANA PM5-PM4 Pin100-101
  //          MSCAN1 CANC PM3-PM2 Pin102-103
  //          MSCAN0 CANB PM1-PM0 Pin104-105  
}//





//----------------MSCANHardwareInit-------------------------
//ʵ�ָ�·CAN��Ӳ����ʼ��
//ִ�У� MSCAN0Init();   MSCAN1Init();   MSCAN4Init();   
//----------------------------------------------------------
void MSCANHardwareInit(void)//
{
  //
  MSCAN0_Init();
  //MSCAN1_Init();
  MSCAN4_Init();
}





//----------------MSCANDataInit-------------------------------
//ʵ��CAN������ݵĳ�ʼ��
//ִ�У�
//------------------------------------------------------------
void MSCANDataInit(void)//
{
  //
   
  
}//






