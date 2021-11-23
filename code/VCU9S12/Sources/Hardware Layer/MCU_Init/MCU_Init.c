#include "Allh.h"



  
void MCU_Init(void)
{   
  //config clock
    asm sei  
     //SYNR    = 1;    
     //REFDV   = 3;      //fVCO=2*foscclk*(SYNR+1)/(REFDV+1)
                        //    =2*16*32/64=16    2*16*16/32=16
                        //S12XEP100 XTAL=16MHz 
                        //fPLL=fVCO 16MHz
                        //BusClock=fPLL/2=8MHz
     //aaa=111;
     
     SYNR    = 3;    
     REFDV   = 3;
     
     
     //当前设定为  2*4*4/2=16MHz   Bus=8MHzs   2*8*4/4=16  bus8
     
     
     while((CRGFLG & 0x08) !=0x08);
     
     //aaa=222;
     CLKSEL |= 0x80;    //clock select
}