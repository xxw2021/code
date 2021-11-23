#include "Allh.h"





unsigned char PwrDrv_stACFanRlyUB;




void HSDOutput_ValueInit(void)//
{
  //
  BTS724Ctl_ValueInit();
  
  
  
  
  
  
  
  
  
  
  PwrDrv_stACFanRlyUB = 0;
  
}//
  













void HSDOutput_Update_10ms(void)//
{
  //
  BTS724Ctl_RlyCtrlUpdate_10ms(); 
}//











void PwrDrv_ACFanRlyCtrl_Update(void)//
{
  //
  if(PwrDrv_stACFanRlyUB == 1)//
  {
    //
    _Btm_BTS724_VB[0] = 1;
  }//
  else//
  {
    //
    _Btm_BTS724_VB[0] = 0;
  }//  
}//
  






