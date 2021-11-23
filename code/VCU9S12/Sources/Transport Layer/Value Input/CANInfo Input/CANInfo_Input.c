#include "Allh.h"





unsigned int CANInput_numCfmTimeUW = 100;
unsigned int CANInput_numUnCfmTimeUW = 100;


//超时标志位
unsigned char CANTimeout_stECUUB;    
unsigned char CANTimeout_stMeterUB;  
unsigned char CANTimeout_stEC1UB;  




//超时时间
//ECU
unsigned int CANTimeout_numECUTimerUW;
unsigned int CANTimeout_numECUTimeUWC;
//
unsigned int CANTimeout_numMeterTimerUW;
unsigned int CANTimeout_numMeterTimeUWC;




//报文接收成功标志位
unsigned char CANInputUpdt_stECUAMBUB;
unsigned char CANInputUpdt_stECUCCVSUB;





unsigned char CANInputUpdt_stECUEEC1UB;
unsigned char CANInputUpdt_stECUEEC2UB;
unsigned char CANInputUpdt_stECUEEC3UB;
unsigned char CANInputUpdt_stECUERC1UB;
unsigned char CANInputUpdt_stECUET1UB;
unsigned char CANInputUpdt_stECULFCUB;
unsigned char CANInputUpdt_stECULFEUB;
unsigned char CANInputUpdt_stECUEC1UB;

unsigned char CANInputUpdt_stECUETC1UB;//robin add 190715
unsigned char CANInputUpdt_stECUETC2UB;//robin add 190715

unsigned char CANInputUpdt_stMeterTCO11UB;
unsigned char CANInputUpdt_stMeterTCO12UB;







void CANInfoInput_ValueInit(void)//
{
  //
  ECU2HCU_ValueInit();
  
  //
  Meter2HCU_ValueInit();
   
}//










void CANInfo_InputUpdate_10ms(void)//
{
  //
  ECU2HCU_Update_10ms();
  
  
  //
  Meter2HCU_Update_10ms();
}//



void CANInfo_InputUpdate_20ms(void)//
{
  //
}//



void CANInfo_InputUpdate_50ms(void)//
{
  //
}//


void CANInfo_InputUpdate_100ms(void)//
{
  //
}//



void CANInfo_InputUpdate_1000ms(void)//
{
  //
}//
















