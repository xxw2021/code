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
//SW1-14Ϊ����Ч������
#define Btm_AMTDmSW_INH_VB      SW_UNION_ALL[0].Bits.data0      //AMT Dm��������
#define Bottom_NeutralSW_INH_VB    SW_UNION_ALL[0].Bits.data1  //�յ��źŽ�����HCU
#define Btm_AMTRmSW_INH_VB      SW_UNION_ALL[0].Bits.data2      //AMT Rm��������
#define Bottom_BrakeSW_INH_VB      SW_UNION_ALL[0].Bits.data3    //�ƶ��źŽ�����HCU
#define Btm_AMTDSW_INH_VB       SW_UNION_ALL[0].Bits.data4     //AMT D��������

#define SW6_Replace                SW_UNION_ALL[0].Bits.data5
#define Btm_AMTNSW_INH_VB       SW_UNION_ALL[0].Bits.data6               //AMT N��������
#define SW8_Replace                SW_UNION_ALL[0].Bits.data7
#define Btm_AMTRSW_INH_VB       SW_UNION_ALL[1].Bits.data0                 //AMT R��������
#define Btm_ONSW_INH_VB         SW_UNION_ALL[1].Bits.data1           //ON�ϵ磬�����ϵ��жϵ�
#define Btm_AMTMupSW_INH_VB     SW_UNION_ALL[1].Bits.data2                 //AMT M+��������

#define SW12_Replace               SW_UNION_ALL[1].Bits.data3
#define Btm_AMTAMSW_INH_VB      SW_UNION_ALL[1].Bits.data4        //AMT AM����������
#define Btm_AMTMdownSW_INH_VB   SW_UNION_ALL[1].Bits.data5      //AMT M-����������
//SW15-18Ϊ����Ч������
#define Btm_HandBrakeSW_INL_VB               SW_UNION_ALL[1].Bits.data6
#define SW16_Replace               SW_UNION_ALL[1].Bits.data7
#define SW17_Replace               SW_UNION_ALL[2].Bits.data0
#define SW18_Replace               SW_UNION_ALL[2].Bits.data1

//SW19-30Ϊ�ߵ���Ч���л��ı���
#define Bottom_ReverseSW_INH_VB    SW_UNION_ALL[2].Bits.data2    //������������
#define Bottom_StartSW_INH_VB      SW_UNION_ALL[2].Bits.data3  //Start��������

#define Btm_CCSResumeSW_INH_VB  SW_UNION_ALL[2].Bits.data4    //CCS_Resume����������
#define Btm_CCSONSW_INH_VB      SW_UNION_ALL[2].Bits.data5     //CCS_ON����������
#define Btm_CCSSetdownSW_INH_VB SW_UNION_ALL[2].Bits.data6    //CCS_Set-����������
#define Btm_CCSSetupSW_INH_VB   SW_UNION_ALL[2].Bits.data7       //CCS_Set+����������
#define Btm_ParkChgSW_INH_VB  SW_UNION_ALL[3].Bits.data0     //ͣ�����������

#define SW26_Replace               SW_UNION_ALL[3].Bits.data1
#define SW27_Replace               SW_UNION_ALL[3].Bits.data2
#define SW28_Replace               SW_UNION_ALL[3].Bits.data3
#define Btm_AMTRampSW_INH_VB    SW_UNION_ALL[3].Bits.data4      //�µ����أ��������Ը�λ
#define Btm_AMTRampupSW_INH_VB  SW_UNION_ALL[3].Bits.data5    //���𿪹أ��Ը�λ






  
  
void GPIO_Init(void);    












#endif