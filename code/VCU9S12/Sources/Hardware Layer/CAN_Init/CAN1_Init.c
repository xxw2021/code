#include "Allh.h"



//------------------------------------------------
// CAN2 -> CAN_C -> CAN3_Pin -> Pin64 65
void MSCAN1_Init(void)
{
  CAN1CTL0_INITRQ = 1;
  while (CAN1CTL1_INITAK==0) ;
  CAN1CTL1_CANE = 1;                   //enable msCAN module       1:enabled     0:disabled
  CAN1CTL1_CLKSRC = 0;                 //Clock Source (16MHz)      1:Bus         0:OSC
  CAN1CTL1_LOOPB = 0;                  //Loop Back Self Test Md  1:enabled     0:disabled
  CAN1CTL1_LISTEN = 0;                 //Listen Only Md          1:Listen Only 0:Normal Md
  CAN1CTL1_WUPM = 0;                   //Wake-Up Md              1:>Twup       0:Any Signal wake up
  
  
  //…Ë∂®   BRP=0 T1=12 T2=1 250k
  //       BRP=0 T1=4  T2=1 500k
  //       BRP=1 T1=4  T2=1 1000k 
  CAN1BTR0_BRP = 1;                    //Baud Rate Prescaler
  CAN1BTR0_SJW = 0;                    //SJW = (SJW+1)*Tq = Tq
  CAN1BTR1_SAMP = 1;                   //Sampling 1: 3 samples  0:1 sample per bit
  CAN1BTR1_TSEG_10= 4;                //Tseg1=12+1=13
  CAN1BTR1_TSEG_20= 1;                 //Tseg2=1+1=2
  
  
  
  CAN1IDAC_IDAM0 = 0;                  //00:2*32bit 01:4*16bit  
  CAN1IDAC_IDAM1 = 0;                  //10:8*8bit  11:closed,no message is acceped
  
  CAN1IDAR0 =0x00;    
  CAN1IDAR1 =0x00;       
  CAN1IDAR2 =0x00;          
  CAN1IDAR3 =0x00;          
  
  CAN1IDAR4 = 0x00;  
  CAN1IDAR5 = 0x00;  
  CAN1IDAR6 = 0x00;                
  CAN1IDAR7 = 0x00;
                                                
  //Config CAN1IDMR0-7                 
  CAN1IDMR0 = 0xff;      
  CAN1IDMR1 = 0xff;   
  CAN1IDMR2 = 0xff;   
  CAN1IDMR3 = 0xff;                                                        
                                                                      
  CAN1IDMR4 = 0xff; 
  CAN1IDMR5 = 0xff;
  CAN1IDMR6 = 0xff;
  CAN1IDMR7 = 0xff;
  CAN1CTL0_INITRQ = 0;
  while (CAN1CTL1_INITAK==1) ;   
  while (CAN1CTL0_SYNCH==0) ;
  CAN1RIER = 1;
  CAN1TIER = 0;     

}