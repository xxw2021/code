#ifndef GPIO_INIT_H
#define GPIO_INIT_H





#define GPIO_Dir_In    0
#define GPIO_Dir_Out   1

#define GPIO_Init_Low      0
#define GPIO_Init_High     1  


#define BoardPwrCtrl      PORTA_PA7




//-------------swtich replace--------------------
//define replace name of the SW
typedef union
{
  byte Byte;
  struct{
    byte data0 :1;
    byte data1 :1;
    byte data2 :1;
    byte data3 :1;
    byte data4 :1;
    byte data5 :1;
    byte data6 :1;
    byte data7 :1;
  }Bits;
}SW_UNION;

extern SW_UNION SW_UNION_ALL[4];
//SW1-14为高有效开关量
#define Btm_AMTDmSW_INH_VB      SW_UNION_ALL[0].Bits.data0      //AMT Dm挡开关量
#define Bottom_NeutralSW_INH_VB    SW_UNION_ALL[0].Bits.data1  //空挡信号接入至HCU
#define Btm_AMTRmSW_INH_VB      SW_UNION_ALL[0].Bits.data2      //AMT Rm挡开关量
#define Bottom_BrakeSW_INH_VB      SW_UNION_ALL[0].Bits.data3    //制动信号接入至HCU
#define Btm_AMTDSW_INH_VB       SW_UNION_ALL[0].Bits.data4     //AMT D挡开关量

#define SW6_Replace                SW_UNION_ALL[0].Bits.data5
#define Btm_AMTNSW_INH_VB       SW_UNION_ALL[0].Bits.data6               //AMT N挡开关量
#define SW8_Replace                SW_UNION_ALL[0].Bits.data7
#define Btm_AMTRSW_INH_VB       SW_UNION_ALL[1].Bits.data0                 //AMT R挡开关量
#define Btm_ONSW_INH_VB         SW_UNION_ALL[1].Bits.data1           //ON上电，进行上电判断等
#define Btm_AMTMupSW_INH_VB     SW_UNION_ALL[1].Bits.data2                 //AMT M+挡开关量

#define SW12_Replace               SW_UNION_ALL[1].Bits.data3
#define Btm_AMTAMSW_INH_VB      SW_UNION_ALL[1].Bits.data4        //AMT AM开关量输入
#define Btm_AMTMdownSW_INH_VB   SW_UNION_ALL[1].Bits.data5      //AMT M-开关量输入
//SW15-18为低有效开关量
#define Btm_HandBrakeSW_INL_VB               SW_UNION_ALL[1].Bits.data6
#define SW16_Replace               SW_UNION_ALL[1].Bits.data7
#define SW17_Replace               SW_UNION_ALL[2].Bits.data0
#define SW18_Replace               SW_UNION_ALL[2].Bits.data1

//SW19-30为高低有效可切换的变量
#define Bottom_ReverseSW_INH_VB    SW_UNION_ALL[2].Bits.data2    //倒档开关输入
#define Bottom_StartSW_INH_VB      SW_UNION_ALL[2].Bits.data3  //Start开关输入

#define Btm_CCSResumeSW_INH_VB  SW_UNION_ALL[2].Bits.data4    //CCS_Resume开关量输入
#define Btm_CCSONSW_INH_VB      SW_UNION_ALL[2].Bits.data5     //CCS_ON开关量输入
#define Btm_CCSSetdownSW_INH_VB SW_UNION_ALL[2].Bits.data6    //CCS_Set-开关量输入
#define Btm_CCSSetupSW_INH_VB   SW_UNION_ALL[2].Bits.data7       //CCS_Set+开关量输入
#define Btm_ParkChgSW_INH_VB  SW_UNION_ALL[3].Bits.data0     //停车充电允许开关

#define SW26_Replace               SW_UNION_ALL[3].Bits.data1
#define SW27_Replace               SW_UNION_ALL[3].Bits.data2
#define SW28_Replace               SW_UNION_ALL[3].Bits.data3
#define Btm_AMTRampSW_INH_VB    SW_UNION_ALL[3].Bits.data4      //坡道开关，带锁非自复位
#define Btm_AMTRampupSW_INH_VB  SW_UNION_ALL[3].Bits.data5    //坡起开关，自复位






  
  
void GPIO_Init(void);    












#endif