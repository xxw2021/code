#include "Allh.h"










void SWSen_ValueInit(void)//
{
  //
  SWChn_ValueInit();
  
  //
  MC33972Input_ValueInit();
  
}//



void SWSen_Update_10ms(void)//
{
  //
  SWChn_Update_10ms();
  
  //
  MC33972_Update_10ms();
}//