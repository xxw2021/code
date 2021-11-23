#include "Allh.h"




//-------------------MSCANModuleInit------------------------
//实现CAN模块硬件以及相关数据的初始化
//执行：   MSCANHardwareInit();     MSCANDataInit();
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
  
  //配置后设定MSCAN4 CANA PM5-PM4 Pin100-101
  //          MSCAN1 CANC PM3-PM2 Pin102-103
  //          MSCAN0 CANB PM1-PM0 Pin104-105  
}//





//----------------MSCANHardwareInit-------------------------
//实现各路CAN的硬件初始化
//执行： MSCAN0Init();   MSCAN1Init();   MSCAN4Init();   
//----------------------------------------------------------
void MSCANHardwareInit(void)//
{
  //
  MSCAN0_Init();
  //MSCAN1_Init();
  MSCAN4_Init();
}





//----------------MSCANDataInit-------------------------------
//实现CAN相关数据的初始化
//执行：
//------------------------------------------------------------
void MSCANDataInit(void)//
{
  //
   
  
}//






