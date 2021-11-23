#include "Allh.h"








void ValueOutput_ValueInit(void)//
{
  //
  CANInfoOutput_ValueInit();
  
  HSDOutput_ValueInit();
  
  LSDOutput_ValueInit();
}//





void ValueOutput_Update_10ms(void)//
{
  //
  CANInfo_Output_10ms();
   
  HSDOutput_Update_10ms();
  
  LSDOutput_Update_10ms();  
}//

void ValueOutput_Update_50ms(void)//
{

  CANInfo_Output_50ms();

}




void ValueOutput_Update_100ms(void)//
{
  //
  CANInfo_Output_100ms(); 
  
}//




























