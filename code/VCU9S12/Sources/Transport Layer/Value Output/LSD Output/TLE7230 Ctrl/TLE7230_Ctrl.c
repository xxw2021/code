#include "Allh.h"







void TLE7230Ctl_ValueInit(void)//
{
  //
  TLE7230Ctl_AllRly_OFF();
}//






void TLE7230Ctl_BitReset(void)//
{
  //
  Bit_RlyL1=0;
  Bit_RlyL2=0;
  Bit_RlyL3=0;
  Bit_RlyL4=0;
  Bit_RlyL5=0;
  Bit_RlyL6=0;
  Bit_RlyL7=0;
  Bit_RlyL8=0; 
}//



//----------RlyL_AllOff-------------------
//Set RlyL all off
void TLE7230Ctl_AllRly_OFF(void) 
{
  Bit_RlyL1=0;
  Bit_RlyL2=0;
  Bit_RlyL3=0;
  Bit_RlyL4=0;
  Bit_RlyL5=0;
  Bit_RlyL6=0;
  Bit_RlyL7=0;
  Bit_RlyL8=0;
  TLE7230_Rxdata=TLE7230_Ctl_Tx(Bit_RlyL_ALL); 
}




//----------RlyL_AllOn----------------
//Set All RlyL to On
void TLE7230Ctl_AllRly_ON(void)//
{
  //
  Bit_RlyL1=1;
  Bit_RlyL2=1;
  Bit_RlyL3=1;
  Bit_RlyL4=1;
  Bit_RlyL5=1;
  Bit_RlyL6=1;
  Bit_RlyL7=1;
  Bit_RlyL8=1;
  TLE7230_Rxdata=TLE7230_Ctl_Tx(Bit_RlyL_ALL);    
}//





