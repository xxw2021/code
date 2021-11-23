#include "Allh.h"



volatile Str_Can_RxData_EEC1            RxCANBuf_EEC1[8];
volatile Str_Can_RxData_EEC2            RxCANBuf_EEC2[8];
volatile Str_Can_RxData_EEC3            RxCANBuf_EEC3[8];
volatile Str_Can_RxData_ET1             RxCANBuf_ET1[8];
volatile Str_Can_RxData_LFE             RxCANBuf_LFE[8];
volatile Str_Can_RxData_LFC             RxCANBuf_LFC[8];

volatile Str_Can_RxData_CCVS            RxCANBuf_CCVS[8];
volatile Str_Can_RxData_ETC1            RxCANBuf_ETC1[8];
volatile Str_Can_RxData_ETC2            RxCANBuf_ETC2[8];

volatile Str_Can_RxData_TSC1            TxCANBuf_TSC1[8];
volatile Str_Can_RxData_EBC1            TxCANBuf_EBC1[8];


volatile Str_Can_RxData_AMB             RxCANBuf_AMB[8];
volatile Str_Can_RxData_ERC1            RxCANBuf_ERC1[8];
volatile Str_Can_RxData_TCO1            RxCANBuf_TCO1[8];
volatile Str_Can_RxData_EC1             RxCANBuf_EC1[39];

//robin add 20190708
volatile Str_Can_TxData_CCVS            TxCANBuf_CCVS[8];  //robin add 20190711
volatile Str_Can_TxData_PCC             TxCANBuf_PCC[8];   //robin add 20190711
volatile Str_Can_TxData_TC1             TxCANBuf_TC1[8];   //robin add 20190711



unsigned char EEC1_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char EEC2_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char EEC3_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char ET1_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char LFE_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char LFC_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char CCVS_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char AMB_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char ERC1_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char ETC1_RxBuf[8]={0,0,0,0,0,0,0,0};
unsigned char ETC2_RxBuf[8]={0,0,0,0,0,0,0,0};

unsigned char CCVS_TxBuf[8]={0,0,0,0,0,0,0,0};  //robin add 20190711
unsigned char PCC_TxBuf[8]={0,0,0,0,0,0,0,0};  //robin add 20190711
unsigned char TC1_TxBuf[8]={0,0,0,0,0,0,0,0};  //robin add 20190711

volatile   CAN_MsgBuf_struct   CAN0_MsgReciveBuf;
volatile   CAN_MsgBuf_struct   CAN0_MsgTransmitBuf;







void CAN0Func_ValueInit(void)//
{
  //
  unsigned int temp_index;
  for(temp_index=0;temp_index<8;temp_index++)//
  {
    //
    RxCANBuf_EEC1[temp_index].Byte = 0;
    RxCANBuf_EEC2[temp_index].Byte = 0;
    RxCANBuf_EEC3[temp_index].Byte = 0;
    RxCANBuf_ET1[temp_index].Byte = 0;
    RxCANBuf_LFE[temp_index].Byte = 0;
    RxCANBuf_LFC[temp_index].Byte = 0;
    RxCANBuf_CCVS[temp_index].Byte = 0;
    TxCANBuf_TSC1[temp_index].Byte = 0;
    RxCANBuf_AMB[temp_index].Byte = 0;
    RxCANBuf_ERC1[temp_index].Byte = 0;
    RxCANBuf_TCO1[temp_index].Byte = 0;
    
    RxCANBuf_ETC1[temp_index].Byte = 0;//robin add 190715
    RxCANBuf_ETC2[temp_index].Byte = 0;//robin add 190715
    
    TxCANBuf_CCVS[temp_index].Byte = 0;//robin add 190715
    TxCANBuf_PCC[temp_index].Byte = 0;//robin add 190715
    TxCANBuf_TC1[temp_index].Byte = 0;//robin add 190715
    
    EEC1_RxBuf[temp_index] = 0;
    EEC2_RxBuf[temp_index] = 0;
    EEC3_RxBuf[temp_index] = 0;
    ET1_RxBuf[temp_index] = 0;
    LFE_RxBuf[temp_index] = 0;
    LFC_RxBuf[temp_index] = 0;
    CCVS_RxBuf[temp_index] = 0;
    AMB_RxBuf[temp_index] = 0;
    ERC1_RxBuf[temp_index] = 0;  
  }//
}//









//------------------------CANMain_TX----------------------
//主CAN，本CAN节点有CU、仪表等
unsigned char CANMain_TX(unsigned long id,unsigned char priority,unsigned char length,unsigned char *txdata) 
{
  unsigned char index;
  unsigned char txBuf=0x00;
  
  
  //if(!CAN0TFLG)
  //return ERR_Buf_FULL;
  
  CAN0TBSEL=CAN0TFLG;
  
  
  CAN0TBSEL = CAN0TFLG;        //Select lowest empty Buf  
  txBuf = CAN0TBSEL;    // Backup selected Buf
  
  // Load Id to IDR Registers  
  *((unsigned long *) ((unsigned long)(&CAN0TIDR0)))= id; 
  
  for (index=0;index<length;index++) 
  { 
   *(&CAN0TDSR0 + index) = txdata[index];   // Load data to Tx Buf  
                                           // Data Segment Registers 
  } 
  CAN0TDLR = length;                               // Set Data Length Code 
  CAN0TTBPR = priority;                    // Set Priority  
  CAN0TFLG = txBuf;                              // Start transmission  
  return NO_ERR; 
}




#pragma CODE_SEG __NEAR_SEG NON_BANKED

interrupt 38 void MSCAN0_Receive_ISR (void)
{
  unsigned char length,index;
  
  unsigned int  temp_canpgn;
  unsigned char temp_cansa;

  
  length = (CAN0RXDLR & 0x0F);
    
  temp_cansa=CAN0RXIDR3/2 + (CAN0RXIDR2%2)*128;
  temp_canpgn = (CAN0RXIDR2/2)%16 +((CAN0RXIDR1%2) * 8 + (CAN0RXIDR2/32))*16 + ((((CAN0RXIDR1/32)%4) * 4 + (CAN0RXIDR1/2)%4 ) + ((CAN0RXIDR0 % 8) * 2 + (CAN0RXIDR1 / 128))*16)*256;  
  
  //EEC1
  if(temp_canpgn == CANPGN_EEC1)//
  {
    //
    for(index=0; index<length; index++) 
    {
      RxCANBuf_EEC1[index].Byte= *(&CAN0RXDSR0 + index); 
    }//
    CANInputUpdt_stECUEEC1UB = 1;   
  }//
  //EEC2
  if(temp_canpgn == CANPGN_EEC2)//
  {
    //
    for(index=0; index<length; index++)
  	{
      RxCANBuf_EEC2[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECUEEC2UB = 1;
  }//
  
  //EEC3
  if(temp_canpgn == CANPGN_EEC3)//
  {
    //
    for(index=0; index<length; index++)
  	{
      RxCANBuf_EEC3[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECUEEC3UB = 1;
  }//
  //ET1
  if(temp_canpgn == CANPGN_ET1)//
  {
    //
    for(index=0; index<length; index++)
    {
      RxCANBuf_ET1[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECUET1UB = 1;
  }//
  //LFE
  if(temp_canpgn == CANPGN_LFE)//
  {
    //
    for(index=0; index<length; index++)
    {
      RxCANBuf_LFE[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECULFEUB = 1;
  }//
  //LFC
  if(temp_canpgn == CANPGN_LFC)//
  {
    //
    if(temp_canpgn == CANPGN_ERC1)//
    //
    for(index=0; index<length; index++)
  	{
      RxCANBuf_LFC[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECULFCUB = 1;
  }//
//ETC1 robin add 190715
  if(temp_canpgn == CANPGN_ETC1) 
  {
   for(index=0; index<length; index++)
  	{
      RxCANBuf_ETC1[index].Byte= *(&CAN0RXDSR0 + index);
    }
   CANInputUpdt_stECUETC1UB = 1;
  }
 
//ETC2 robin add 190715 
  if(temp_canpgn == CANPGN_ETC2) 
  {
  
   for(index=0; index<length; index++)
  	{
      RxCANBuf_ETC2[index].Byte= *(&CAN0RXDSR0 + index);
    }
     CANInputUpdt_stECUETC2UB = 1;
  }
  
  //CCVS
  if(temp_canpgn == CANPGN_CCVS)//
  {
    //
    if(temp_cansa == CANSA_ECU)//
    {
    //
    for(index=0; index<length; index++)
    {
      RxCANBuf_CCVS[index].Byte= *(&CAN0RXDSR0 + index);//Fixed by xmy 20190626
    }
    CANInputUpdt_stECUCCVSUB = 1;
    }
  }//
  //for(index=0; index<length; index++)
    //{
      //RxCANBuf_CCVS[index].Byte= *(&CAN0RXDSR0 + index);
    //}
   // CANInputUpdt_stECUCCVSUB = 1;
 // }//
  //AMB
  if(temp_canpgn == CANPGN_AMB)//
  {
    //
    for(index=0; index<length; index++)
    {
      RxCANBuf_AMB[index].Byte= *(&CAN0RXDSR0 + index);
    }                          
    CANInputUpdt_stECUAMBUB = 1;
  }//
  //ERC1
  if(temp_canpgn == CANPGN_ERC1)//
  {
    //
    for(index=0; index<length; index++)
    {
    
      RxCANBuf_ERC1[index].Byte= *(&CAN0RXDSR0 + index);
    }
    CANInputUpdt_stECUERC1UB = 1;
  }//
  //EC1
  if(temp_canpgn == CANPGN_Data_EC1)//
  {
    //
    if(temp_cansa == CANSA_ECU)//
    {
      //
      if(CAN0RXDSR0 == 1)//
      {
        //
        RxCANBuf_EC1[0].Byte = CAN0RXDSR1;
        RxCANBuf_EC1[1].Byte = CAN0RXDSR2;
        RxCANBuf_EC1[2].Byte = CAN0RXDSR3;
        RxCANBuf_EC1[3].Byte = CAN0RXDSR4;
        RxCANBuf_EC1[4].Byte = CAN0RXDSR5;
        RxCANBuf_EC1[5].Byte = CAN0RXDSR6;
        RxCANBuf_EC1[6].Byte = CAN0RXDSR7;
        
      }//
      else if(CAN0RXDSR0 == 2)//
      {
        //
        RxCANBuf_EC1[7].Byte = CAN0RXDSR1;
        RxCANBuf_EC1[8].Byte = CAN0RXDSR2;
        RxCANBuf_EC1[9].Byte = CAN0RXDSR3;
        RxCANBuf_EC1[10].Byte = CAN0RXDSR4;
        RxCANBuf_EC1[11].Byte = CAN0RXDSR5;
        RxCANBuf_EC1[12].Byte = CAN0RXDSR6;
        RxCANBuf_EC1[13].Byte = CAN0RXDSR7;
      }//
      else if(CAN0RXDSR0 == 3)//
      {
        //
        RxCANBuf_EC1[14].Byte = CAN0RXDSR1;
        RxCANBuf_EC1[15].Byte = CAN0RXDSR2;
        RxCANBuf_EC1[16].Byte = CAN0RXDSR3;
        RxCANBuf_EC1[17].Byte = CAN0RXDSR4;
        RxCANBuf_EC1[18].Byte = CAN0RXDSR5;
        RxCANBuf_EC1[19].Byte = CAN0RXDSR6;
        RxCANBuf_EC1[20].Byte = CAN0RXDSR7;
      }//
      else if(CAN0RXDSR0 == 4)//
      {
        //
        RxCANBuf_EC1[21].Byte = CAN0RXDSR1;
        RxCANBuf_EC1[22].Byte = CAN0RXDSR2;
        RxCANBuf_EC1[23].Byte = CAN0RXDSR3;
        RxCANBuf_EC1[24].Byte = CAN0RXDSR4;
        RxCANBuf_EC1[25].Byte = CAN0RXDSR5;
        RxCANBuf_EC1[26].Byte = CAN0RXDSR6;
        RxCANBuf_EC1[27].Byte = CAN0RXDSR7;
      }//
      else//
      {
        //
      }//
      CANInputUpdt_stECUEC1UB = 1;
    }//
  }//
  //TCO1
  if(temp_canpgn == CANPGN_TCO1)//
  {
    //
    if(temp_cansa == CANSA_Meter1)//
    {
      //
      CANInputUpdt_stMeterTCO11UB = 1;
    }//
    else if(temp_cansa == CANSA_Meter2)//
    {
      //
      CANInputUpdt_stMeterTCO12UB = 1;
    }//
    else//
    {
      //
    }//
    
    for(index=0; index<length; index++)
    {
    
      RxCANBuf_TCO1[index].Byte= *(&CAN0RXDSR0 + index);
    } 
  }//
 
  CAN0RFLG_RXF = 1;
}//

#pragma CODE_SEG DEFAULT  