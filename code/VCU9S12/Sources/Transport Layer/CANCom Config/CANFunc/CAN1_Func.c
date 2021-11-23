#include "Allh.h"

                               




void CAN1Func_ValueInit(void)//
{
  //
  
  
}//


unsigned char CANMeter_TX(unsigned long id,unsigned char priority,unsigned char length,unsigned char *txdata) 
{
  unsigned char index;
  unsigned char txBuf=0x00;
  
  
  if(!CAN1TFLG)
  return ERR_Buf_FULL;
  
  CAN1TBSEL=CAN1TFLG;
  
  
  CAN1TBSEL = CAN1TFLG;        //Select lowest empty Buf  
  txBuf = CAN1TBSEL;    // Backup selected Buf
  
  // Load Id to IDR Registers  
  *((unsigned long *) ((unsigned long)(&CAN1TIDR0)))= id; 
  
  for (index=0;index<length;index++) 
  { 
   *(&CAN1TDSR0 + index) = txdata[index];   // Load data to Tx Buf  
                                           // Data Segment Registers 
  } 
  CAN1TDLR = length;                               // Set Data Length Code 
  CAN1TTBPR = priority;                    // Set Priority  
  CAN1TFLG = txBuf;                              // Start transmission  
  return NO_ERR; 
}



unsigned char CANMtr_TX(unsigned long id,unsigned char priority,unsigned char length,unsigned char *txdata) 
{
  unsigned char index;
  unsigned char txBuf=0x00;
  
  
  if(!CAN1TFLG)
  return ERR_Buf_FULL;
  
  CAN1TBSEL=CAN1TFLG;
  
  
  CAN1TBSEL = CAN1TFLG;        //Select lowest empty Buf  
  txBuf = CAN1TBSEL;    // Backup selected Buf
  
  // Load Id to IDR Registers  
  *((unsigned long *) ((unsigned long)(&CAN1TIDR0)))= id; 
  
  for (index=0;index<length;index++) 
  { 
   *(&CAN1TDSR0 + index) = txdata[index];   // Load data to Tx Buf  
                                           // Data Segment Registers 
  } 
  CAN1TDLR = length;                               // Set Data Length Code 
  CAN1TTBPR = priority;                    // Set Priority  
  CAN1TFLG = txBuf;                              // Start transmission  
  return NO_ERR; 
}






#pragma CODE_SEG __NEAR_SEG NON_BANKED

interrupt 42 void MSCAN1_Receive_ISR(void)//
{
  //
}

#pragma CODE_SEG DEFAULT  