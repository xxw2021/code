#include "Allh.h"




/*--------------------------------------------------------------------------------
整车CAN拓扑如下
                                     VCU        Meter
                                     ||         ||
                                     ||         ||
    ---------------------------------|----------|----------------------
    ----|--------------|------------------------------|-----------------整车CAN
        ||             ||                             ||   
        ||             ||                             ||  
       ABS            ECU                            TBOX 

---------------------------------------------------------------------------------*/



//---------------CANFlag--------------------------
//CAN相关的标志位     包含：CAN错误标志位  CAN发送允许标志位

//发动机报文发送管理
//unsigned char CANTxAllow_stECUTSC1UB;
//unsigned char CANTxAllow_stECUEBC1UB;
unsigned char CANTxErr_stECUTSC1UB;
unsigned char CANTxErr_stECUEBC1UB;


unsigned char CANTxErr_stECUCCVSUB;//robin修改添加
unsigned char CANTxErr_stECUPCCUB;//robin修改添加

unsigned char CANTxErr_stECUTC1UB;//robin修改添加


//TBOX报文发送管理
unsigned char CANTxAllow_stTBoxUB;
unsigned char CANTxErr_stTboxUB; 





void CANCom_Config(void)//
{
  //
  CANTxAllow_stECUTSC1UB = 0;
  CANTxAllow_stECUEBC1UB = 0;
  CANTxErr_stECUTSC1UB = 0;
  CANTxErr_stECUEBC1UB = 0;
  CANTxAllow_stTBoxUB = 0;
  CANTxErr_stTboxUB = 0;
  //robin add 190711
  CANTxErr_stECUCCVSUB = 0;  
  CANTxErr_stECUPCCUB = 0; 
  CANTxErr_stECUTC1UB = 0; 

}//








//从CANID到canbuff状态 
unsigned long CANID2CANIDBuff(unsigned long Raw_CANID)//
{
  //
  unsigned long temp_buff;
   
  unsigned long temp_rawidbyte1;
  unsigned long temp_rawidbyte2;
  unsigned long temp_rawidbyte3;
  unsigned long temp_rawidbyte4;
  
  unsigned long temp_idbuffbyte1;
  unsigned long temp_idbuffbyte2;
  unsigned long temp_idbuffbyte3;
  unsigned long temp_idbuffbyte4;
  
  temp_rawidbyte1 = (Raw_CANID % 256);
  temp_rawidbyte2 = ((Raw_CANID / 256) % 256);
  temp_rawidbyte3 = ((Raw_CANID / 65536) % 256);
  temp_rawidbyte4 = (Raw_CANID / 16777216);
  
  temp_idbuffbyte1 = (temp_rawidbyte1 & 0b01111111) * 2;
  temp_idbuffbyte2 = (temp_rawidbyte2 & 0b01111111) * 2 + (temp_rawidbyte1 & 0b10000000) / 128;
  temp_idbuffbyte3 = (temp_rawidbyte3 & 0b00011100) * 8 + 0b00011000 + (temp_rawidbyte3 & 0b00000011) * 2 + (temp_rawidbyte2 & 0b10000000) / 128;
  temp_idbuffbyte4 = (temp_rawidbyte4 & 0b00011111) * 8 + (temp_rawidbyte3 & 0b11100000) / 32;
  
  temp_buff = temp_idbuffbyte1 + temp_idbuffbyte2 * 256 + temp_idbuffbyte3 * 65536 + temp_idbuffbyte4 * 16777216;
  return temp_buff;
}//


