#include "Allh.h"





void MSCAN4_Init(void)
{
  
  
  /*设定为 250k  500k的内容
  CAN4CTL0_INITRQ = 1;
  while (CAN4CTL1_INITAK==0) ;
  CAN4CTL1_CANE = 1;                   //enable msCAN module       1:enabled     0:disabled
  CAN4CTL1_CLKSRC = 0;                 //Clock Source (16MHz)      1:Bus         0:OSC
  CAN4CTL1_LOOPB = 0;                  //Loop Back Self Test Md  1:enabled     0:disabled
  CAN4CTL1_LISTEN = 0;                 //Listen Only Md          1:Listen Only 0:Normal Md
  CAN4CTL1_WUPM = 0;                   //Wake-Up Md              1:>Twup       0:Any Signal wake up
  */
  /*******
  CAN4BTR0_BRP = 3;                    //Baud Rate Prescaler
  CAN4BTR0_SJW = 0;                    //SJW = (SJW+1)*Tq = Tq
  CAN4BTR1_SAMP = 1;                   //Sampling 1: 3 samples  0:1 sample per bit
  CAN4BTR1_TSEG_10= 12;                //Tseg1=12+1=13
  CAN4BTR1_TSEG_20= 1;                 //Tseg2=1+1=2
  *******/
  
  //设定   BRP=0 T1=12 T2=1 250k
  //       BRP=0 T1=4  T2=1 500k
  /*设定为500k
  CAN4BTR0_BRP = 0;                    //Baud Rate Prescaler
  CAN4BTR0_SJW = 0;                    //SJW = (SJW+1)*Tq = Tq
  CAN4BTR1_SAMP = 1;                   //Sampling 1: 3 samples  0:1 sample per bit
  CAN4BTR1_TSEG_10= 4;                //Tseg1=12+1=13     
  CAN4BTR1_TSEG_20= 1;                 //Tseg2=1+1=2
  */
  
  // 4Mhz/(1+T1+T2)  
 
 
  //以下设定为1M波特率  采样点80%
  CAN4CTL0_INITRQ = 1;
  while (CAN4CTL1_INITAK==0) ;
  CAN4CTL1_CANE = 1;                   //enable msCAN module       1:enabled     0:disabled
  CAN4CTL1_CLKSRC = 1;                 //Clock Source (16MHz)      1:Bus         0:OSC
  CAN4CTL1_LOOPB = 0;                  //Loop Back Self Test Md  1:enabled     0:disabled
  CAN4CTL1_LISTEN = 0;                 //Listen Only Md          1:Listen Only 0:Normal Md
  CAN4CTL1_WUPM = 0;                   //Wake-Up Md              1:>Twup       0:Any Signal wake up
  
  //设定为1Mhz
  CAN4BTR0_BRP = 1;                    //Baud Rate Prescaler
  CAN4BTR0_SJW = 0;                    //SJW = (SJW+1)*Tq = Tq
  CAN4BTR1_SAMP = 1;                   //Sampling 1: 3 samples  0:1 sample per bit
  CAN4BTR1_TSEG_10= 4;                //Tseg1=12+1=13     
  CAN4BTR1_TSEG_20= 1;                 //Tseg2=1+1=2
  
  
  
  //设定为500k  用于CCP诊断标定
  
  //当设定为250K时的数据如下
  //BitTime=(Precaler value)*(1+tseg1+tseg2)/fcanclk
  //       =(CAN4BTR0_BRP+1)*(1+13+2)/16M=4*10^(-6)s=250K
  //当设定为500K的数据如下
  //BitTime=(Precaler value)*(1+tseg1+tseg2)/fcanclk
  //       =(CAN4BTR0_BRP+1)*(1+13+2)/16M=4*10^(-6)s=250K
  //       =(1+1)*(1+13+2)/16M=4*10^(-6)s=250K
 
  
  CAN4IDAC_IDAM0 = 0;                  //00:2*32bit 01:4*16bit  
  CAN4IDAC_IDAM1 = 0;                  //10:8*8bit  11:closed,no message is acceped
  
  CAN4IDAR0 =0x00;    
  CAN4IDAR1 =0x00;       
  CAN4IDAR2 =0x00;          
  CAN4IDAR3 =0x00;          
  
  CAN4IDAR4 = 0x00;  
  CAN4IDAR5 = 0x00;  
  CAN4IDAR6 = 0x00;                
  CAN4IDAR7 = 0x00;
                                                
  //Config CAN2IDMR0-7                 
  CAN4IDMR0 = 0xff;     
  CAN4IDMR1 = 0xff;    
  CAN4IDMR2 = 0xff;   
  CAN4IDMR3 = 0xff;                                                        
                                                                      
  CAN4IDMR4 = 0xff; 
  CAN4IDMR5 = 0xff;
  CAN4IDMR6 = 0xff;
  CAN4IDMR7 = 0xff;
  CAN4CTL0_INITRQ = 0;
  while (CAN4CTL1_INITAK==1) ;   
  while (CAN4CTL0_SYNCH==0) ;
  CAN4RIER = 1;
  CAN4TIER = 0;   

}