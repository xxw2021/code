#include "Allh.h"





void Hardware_InitFunc(void)//
{
  //
  
  MCU_Init();
    
  MODRR_Config();  
    
    
    
  GPIO_Init();
  
  AD_Init();
  
  PIT_Init();
    
  //PWM_Init();
   
  //ECT_Init();
  
  SPI_Init();
  
  S32K144_Init();
  
  TLE7230Init();
  
  MC33972_Init();
  
  MSCAN_Init(); 
  
  ccpInit();   
}//




void MODRR_Config(void)//
{
  //
  //MODRR_MODRR0 = 0;  //CAN0 PM0 PM1
  //MODRR_MODRR1 = 0;
   
  //MODRR_MODRR2 = 1;  //CAN4 PM4 PM5
  //MODRR_MODRR3 = 0;
  
  //MODRR_MODRR4 = 0;  //SPI0 
  //MODRR_MODRR5 = 1;  //SPI1 PH0123
  //MODRR_MODRR6 = 1;  //SPI2 PH4567
  
  MODRR=0b01100100;
}//
  


