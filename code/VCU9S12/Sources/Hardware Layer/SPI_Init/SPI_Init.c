#include "Allh.h"     



     


void SPI_Init(void) 
{  
  //MODRR=0b01000000;
        //||||||||
        //||||||CAN0  PM0 1
        //||||||
        //|||||
        //||||
        //|||
        //||SPI1  PP0 1 2
        //|SPI2   PP4 5 6
        //  
   //-----------------SPI1 SPIBR_Max=5MHz----------------------------
   SPI1CR2=0b01000010;
           //||||||||
           //|||||||SPC0  Serial Pin Ctrl Bit0
           //||||||SPISWAI SPI Stop in Wait Md Bit 0>not wait 1>wait
           //|||||X
           //||||BIDIROE Output Enable in the BMO
           //|||MODFEN Md Fault Enable Bit 0>SS not used by SPI   1>SS is used by SPI 
           //||X
           //|XFRW Transfer Width 0>8  1>16
           //X   
   SPI1BR=0x03; //0x43; //0x01;          //Clock=Busclock/((SPPR+1)*2^(SPR+1))
                         //     =8/((0+1)*2^(1+1))=2M

   
   SPI1CR1=0b01010100;
           //||||||||
           //|||||||LSBFE LSB-First Enable  0>most-least  1>least-most
           //||||||SSOE  SS Pin                                                                                               /
           //|||||CPHA  SPI Clock Phase Bit 0>135 1>246
           //||||CPOL SPI Clock Polarity Bit 0>High  1>Low
           //|||MSTR SPI Master/Slave Md Select  0>SPI Slave Md  1>SPI Master Md
           //||SPTIE SPI Transmit Interrupt Enable 0>Disable 1>Enable
           //|SPE  SPI Sys Enable Bit   0>SPI Disable 1>SPI Enable
           //SPIE  SPI Interrupt Enable Bit 0>Disable 1>Enable  








  //-------------------------------SPI2  SPIBR_Max=2.5M
   SPI2CR2=0b01000010;
           //||||||||
           //|||||||SPC0  Serial Pin Ctrl Bit0
           //||||||SPISWAI SPI Stop in Wait Md Bit 0>not wait 1>wait
           //|||||X
           //||||BIDIROE Output Enable in the BMO
           //|||MODFEN Md Fault Enable Bit 0>SS not used by SPI   1>SS is used by SPI 
           //||X
           //|XFRW Transfer Width 0>8  1>16
           //X   
   SPI2BR=0x01;          //Clock=Busclock/((SPPR+1)*2^(SPR+1))
                         //     =8/((0+1)*2^(2+1))=1M
   SPI2CR1=0b01010100;
           //||||||||
           //|||||||LSBFE LSB-First Enable  0>most-least  1>least-most
           //||||||SSOE  SS Pin
           //|||||CPHA  SPI Clock Phase Bit 0>135 1>246
           //||||CPOL SPI Clock Polarity Bit 0>High  1>Low
           //|||MSTR SPI Master/Slave Md Select  0>SPI Slave Md  1>SPI Master Md
           //||SPTIE SPI Transmit Interrupt Enable 0>Disable 1>Enable
           //|SPE  SPI Sys Enable Bit   0>SPI Disable 1>SPI Enable
           //SPIE  SPI Interrupt Enable Bit 0>Disable 1>Enable  



 SPIPort_Init();
}


//设定端口的初始化内容
void SPIPort_Init(void)//
{
  //
  //TLE7230
  DDRJ_DDRJ6 = GPIO_Dir_Out;    //TLE7230_IN
  DDRJ_DDRJ7 = GPIO_Dir_Out;    //TLE7230_CS
  DDRS_DDRS7= GPIO_Dir_Out;    //TLE7230_RST
  
  PTS_PTS7 = 0;
  PTJ_PTJ7 = 0;
  PTJ_PTJ6 = 0;
  
  
  //MC33972
  DDRH_DDRH7 = GPIO_Dir_Out;    //MC33972_CS
  DDRA_DDRA0 = GPIO_Dir_In;     //MC33972_INT
  
  PTH_PTH7 = 0;
  PORTA_PA0 = 0;
  
  
  //COM_S32K
  DDRH_DDRH3 = GPIO_Dir_Out;    //COM_9S2_S32
  PTH_PTH3 = 0;
  
}//








