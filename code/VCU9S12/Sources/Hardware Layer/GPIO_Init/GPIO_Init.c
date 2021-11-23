#include "Allh.h"     //head file















//-------GPIOInit-----------------------
//用于端口方向及初始状态初始化
void GPIO_Init(void)//
{
  //
  //板子上电控制
  DDRA_DDRA7 = GPIO_Dir_Out;
  BoardPwrCtrl = 0;
  
  //---------------SWLH1_1-12--------------
  DDRA_DDRA5 = GPIO_Dir_In;    //PA5   
  DDRT_DDRT0 = GPIO_Dir_In;    //PT0
  DDRT_DDRT1 = GPIO_Dir_In;    //PT1
  DDRA_DDRA4 = GPIO_Dir_In;    //PA4
  DDRA_DDRA3 = GPIO_Dir_In;    //PA3
  DDRA_DDRA2 = GPIO_Dir_In;    //PA2
  DDRT_DDRT5 = GPIO_Dir_In;    //PT5
  DDRT_DDRT3 = GPIO_Dir_In;    //PT3
  DDRT_DDRT6 = GPIO_Dir_In;    //PT6
  DDRT_DDRT7 = GPIO_Dir_In;    //PT7
  DDRT_DDRT2 = GPIO_Dir_In;    //PT2
  DDRT_DDRT4 = GPIO_Dir_In;    //PT4
  
  
  //配置SCI SPI   SPI等片选的内容
  PTFRR=0b00000000;    
  
  
  //--------BTS723------------------
  DDRP_DDRP1  = GPIO_Dir_Out;    //PP1
  DDRP_DDRP0  = GPIO_Dir_Out;    //PP0
  DDRK_DDRK3  = GPIO_Dir_Out;    //PK3
  DDRK_DDRK1  = GPIO_Dir_Out;    //PK1
  
  DDRP_DDRP5  = GPIO_Dir_Out;    //PP5
  DDRP_DDRP4  = GPIO_Dir_Out;    //PP4
  DDRK_DDRK5  = GPIO_Dir_Out;    //PK5
  DDRJ_DDRJ1  = GPIO_Dir_Out;    //PJ0

  DDRB_DDRB0  = GPIO_Dir_Out;    //PB0
  DDRB_DDRB3  = GPIO_Dir_Out;    //PB3
  DDRB_DDRB4  = GPIO_Dir_Out;    //PB4
  DDRB_DDRB7  = GPIO_Dir_Out;    //PB7

  DDRP_DDRP7  = GPIO_Dir_Out;    //PP7
  DDRP_DDRP6  = GPIO_Dir_Out;    //PP6
  DDRP_DDRP3  = GPIO_Dir_Out;    //PP2
  DDRP_DDRP2  = GPIO_Dir_Out;    //PS6



  //进行BTS723端口的初始化配置
  PTP_PTP1 = 0;    // PP1
  PTP_PTP0 = 0;    // PP0
  PORTK_PK3 = 0;   // PK3
  PORTK_PK1 = 0;   // PK1

  PTP_PTP5 = 0;    // PP5
  PTP_PTP4 = 0;    // PP4
  PORTK_PK5 = 0;   // PK5
  PTJ_PTJ0 = 0;    // PJ0

  PORTB_PB0 = 0;   // PB0
  PORTB_PB3 = 0;   // PB3
  PORTB_PB4 = 0;   // PB4
  PORTB_PB7 = 0;   // PB7

  PTP_PTP7 = 0;    // PP7
  PTP_PTP6 = 0;    // PP6
  PTP_PTP2 = 0;    // PP2
  PTS_PTS6 = 0;    // PS6


  //设定端口的状态反馈引脚

  DDRS_DDRS5 = GPIO_Dir_In;   // PS5
  DDRS_DDRS4 = GPIO_Dir_In;   // PS4
  DDRK_DDRK2 = GPIO_Dir_In;   // PK2
  DDRK_DDRK0 = GPIO_Dir_In;   // PK0

  DDRS_DDRS2 = GPIO_Dir_In;   // PS2
  DDRS_DDRS3 = GPIO_Dir_In;   // PS3
  DDRK_DDRK4 = GPIO_Dir_In;   // PK4
  DDRJ_DDRJ1 = GPIO_Dir_In;   // PJ1

  DDRB_DDRB1 = GPIO_Dir_In;   // PB1
  DDRB_DDRB2 = GPIO_Dir_In;   // PB2
  DDRB_DDRB5 = GPIO_Dir_In;   // PB5
  DDRB_DDRB6 = GPIO_Dir_In;   // PB6

  DDRM_DDRM7 = GPIO_Dir_In;   // PM7
  DDRM_DDRM6 = GPIO_Dir_In;   // PM6
  DDRK_DDRK7 = GPIO_Dir_In;   // PK7
  DDRS_DDRS6 = GPIO_Dir_In;   // PS6                     
}


































