#include "Allh.h"



//------------------------------------------------
// CAN0 -> CAN_B -> CAN2_Pin -> Pin47 48
void MSCAN0_Init(void)
{
  CAN0CTL0_INITRQ = 1;                 //Set MSCAN to init Md
  
  while (CAN0CTL1_INITAK==0) ;         //waitting MSCAN to init Md
  CAN0CTL1_CANE = 1;                   //enable msCAN module       1:enabled     0:disabled
  CAN0CTL1_CLKSRC = 0;                 //Clock Source (16MHz)      1:Bus         0:OSC
  CAN0CTL1_LOOPB = 0;                  //Loop Back Self Test Md  1:enabled     0:disabled
  CAN0CTL1_LISTEN = 0;                 //Listen Only Md          1:Listen Only 0:Normal Md
  CAN0CTL1_WUPM = 0;                   //Wake-Up Md              1:>Twup       0:Any Signal wake up
  
  CAN0BTR0_BRP = 1;                    //Baud Rate Prescaler
  CAN0BTR0_SJW = 0;                    //SJW = (SJW+1)*Tq = Tq
  CAN0BTR1_SAMP = 1;                   //Sampling 1: 3 samples  0:1 sample per bit
  CAN0BTR1_TSEG_10= 12;                //Tseg1=12+1=13
  CAN0BTR1_TSEG_20= 1;                 //Tseg2=1+1=2
  
  CAN0IDAC_IDAM0 = 0;                  //00:2*32bit 01:4*16bit  
  CAN0IDAC_IDAM1 = 0;                  //10:8*8bit  11:closed,no message is acceped
  
  //MSCAN ID acceptance Registers
  //not compare all
  CAN0IDAR0 =0x00;    
  CAN0IDAR1 =0x00;       
  CAN0IDAR2 =0x00;          
  CAN0IDAR3 =0x00;          
  
  CAN0IDAR4 = 0x00;  
  CAN0IDAR5 = 0x00;  
  CAN0IDAR6 = 0x00;                
  CAN0IDAR7 = 0x00;
                                                
  //MSCAN ID mask registers 
  //not mask all                
  CAN0IDMR0 = 0xff;      
  CAN0IDMR1 = 0xff;   
  CAN0IDMR2 = 0xff;   
  CAN0IDMR3 = 0xff;                                                        
                                                                      
  CAN0IDMR4 = 0xff; 
  CAN0IDMR5 = 0xff;
  CAN0IDMR6 = 0xff;
  CAN0IDMR7 = 0xff;
   
  CAN0CTL0_INITRQ = 0;   //back to normal Md
  
  while (CAN0CTL1_INITAK==1) ; //waitting for normal Md  
  
  while (CAN0CTL0_SYNCH==0) ;  //waitting for synch
  
  CAN0RIER = 1;      //enable can rx interrupt
  CAN0TIER = 0;      //disable can tx interrupt
}