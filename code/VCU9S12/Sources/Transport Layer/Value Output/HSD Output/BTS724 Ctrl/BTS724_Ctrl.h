#ifndef BTS724_CTRL_H
#define BTS724_CTRL_H



//进行引脚与的端口的宏定义





#define  HighSideDrv_Chn1   PTP_PTP1    //HSP1   PP6 Pin114       PP1
#define  HighSideDrv_Chn2   PTP_PTP0    //HSP2   PP5 Pin119       PP0
#define  HighSideDrv_Chn3   PORTK_PK3   //HSP3   PP0 Pin89        PK3
#define  HighSideDrv_Chn4   PORTK_PK1   //HSP4   PA4 Pin118       PK1
                           
#define  HighSideDrv_Chn5   PTP_PTP5    //HSP5   PP2 Pin115       PP5
#define  HighSideDrv_Chn6   PTP_PTP4    //HSP6   PP1 Pin121       PP4
#define  HighSideDrv_Chn7   PORTK_PK5   //HSP7   PB4 Pin110       PK5
#define  HighSideDrv_Chn8   PTJ_PTJ0    //HSP8   PB3 Pin111       PJ0
  
#define  HighSideDrv_Chn9   PORTB_PB0   //HSP9   PB2 Pin105       PB0
#define  HighSideDrv_Chn10  PORTB_PB3   //HSP10  PA6 Pin97        PB3
#define  HighSideDrv_Chn11  PORTB_PB4   //HSP11  PA3 Pin96        PB4
#define  HighSideDrv_Chn12  PORTB_PB7   //HSP12  PA0 Pin116       PB7
  
#define  HighSideDrv_Chn13  PTP_PTP7    //HSP13  PP4 Pin117       PP7
#define  HighSideDrv_Chn14  PTP_PTP6    //HSP14  PP3 Pin120       PP6
#define  HighSideDrv_Chn15  PTP_PTP3    //HSP15  PK7 Pin112       PP2
#define  HighSideDrv_Chn16  PTP_PTP2    //HSP16  PP7 Pin113       PS6



#define HighSideFB_Chn1    PTS_PTS5    //PS5
#define HighSideFB_Chn2    PTS_PTS4    //PS4
#define HighSideFB_Chn3    PORTK_PK2   //PK2
#define HighSideFB_Chn4    PORTK_PK0   //PK0

#define HighSideFB_Chn5    PTS_PTS2    //PS2
#define HighSideFB_Chn6    PTS_PTS3    //PS3
#define HighSideFB_Chn7    PORTK_PK4   //PK4
#define HighSideFB_Chn8    PTJ_PTJ1    //PJ1

#define HighSideFB_Chn9    PORTB_PB1   //PB1
#define HighSideFB_Chn10   PORTB_PB2   //PB2
#define HighSideFB_Chn11   PORTB_PB5   //PB5
#define HighSideFB_Chn12   PORTB_PB6   //PB6

#define HighSideFB_Chn13   PTM_PTM7    //PM7
#define HighSideFB_Chn14   PTM_PTM6    //PM6
#define HighSideFB_Chn15   PORTK_PK7   //PK7
#define HighSideFB_Chn16   PTS_PTS6    //PS6
 









extern unsigned char _Btm_BTS724_Enable[16];
extern unsigned char _Btm_BTS724_VB[16];


void BTS724Ctl_ValueInit(void);



void BTS724_ChEnable_Config(void);

void BTS724Ctl_RlyCtrlUpdate_10ms(void);




#endif