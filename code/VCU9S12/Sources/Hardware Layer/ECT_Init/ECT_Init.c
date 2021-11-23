#include "Allh.h"



void ECT_Init(void) 
{
  //asm sei
  
     
  //ECT_TSCR1 = 0x80; //启动主定时器，采取正常方式清除标志，最大256分频          
    
  //ECT_TSCR2 = 0x87; //主定时器溢出中断使能
                    //主定时器时钟选择 8M/128=62.5KHz  T=1048ms
                    
                          
  
}