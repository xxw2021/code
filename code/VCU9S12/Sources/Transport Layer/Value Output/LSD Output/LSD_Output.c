#include "Allh.h"







unsigned char PwrDrv_stViceStopUB;
unsigned char PwrDrv_stViceStartUB;







void LSDOutput_ValueInit(void)//
{
  //
  TLE7230Ctl_ValueInit();
                                                
  
  PwrDrv_stViceStopUB = 0;
  PwrDrv_stViceStartUB = 0;
}//




void LSDOutput_Update_10ms(void)//
{
  //
  TLE7230Ctl_BitReset();
  
  
  
  //
  PwrDrv_ViceStop_Update(); 
  //
  PwrDrv_ViceStart_Update();
  
  
  
  
  //
  PwrDrv_TLE7230Ctrl_Update();
}//






void PwrDrv_TLE7230Ctrl_Update(void)//
{
  //
  TLE7230_Rxdata=TLE7230_Ctl_Tx(Bit_RlyL_ALL);
}//





void PwrDrv_ViceStop_Update(void)//
{
  //
  if(PwrDrv_stViceStopUB == 1)//
  {
    //
    Bit_RlyL1 = 1; 
  }//
  else//
  {
    //
    Bit_RlyL1 = 0;    
  }// 
}//
  


void PwrDrv_ViceStart_Update(void)//
{
  //
  if(PwrDrv_stViceStartUB == 1)//
  {
    //
    Bit_RlyL2 = 1; 
  }//
  else//
  {
    //
    Bit_RlyL2 = 0;    
  }//
}//
  



