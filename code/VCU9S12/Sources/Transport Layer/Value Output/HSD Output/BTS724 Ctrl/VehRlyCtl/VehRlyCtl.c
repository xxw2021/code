#include "Allh.h"


unsigned char RlyTsk_stEDSPwrOnUB;
unsigned char RlyTsk_stStartSWChangeOverRlyUB;
unsigned char RlyTsk_stHCUMainPwrRlyUB;
unsigned char RlyTsk_stACFanRlyUB;


unsigned char RlyTsk_stDCDCEnableUB;


unsigned char RlyTsk_stBMSPwrONUB;
unsigned char RlyTsk_stATSPwrONUB;



//ִ�� 20161122
void VehRlyCtl_ValueInit(void)//
{
  //
  RlyTsk_stEDSPwrOnUB = 0;
  RlyTsk_stStartSWChangeOverRlyUB = 0;
  RlyTsk_stHCUMainPwrRlyUB = 0;
  RlyTsk_stACFanRlyUB = 0;
  RlyTsk_stDCDCEnableUB = 0; 
  
  RlyTsk_stBMSPwrONUB = 0;
  RlyTsk_stATSPwrONUB = 0;
}//





//ִ��20161216
void VehRlyCtl_Update_20ms(void)//
{
  //
 VehRlyCtl_HCUMainPwrRlyCtl(); 
  
 VehRlyCtl_ACFanRlyCtl();
 
   
 VehRlyCtl_StartSWChangeOverRlyCtl();
 
 VehRlyCtl_EDSPwrONCtl();
 
 VehRlyCtl_DCDCEnableCtrl();
 //_Btm_BTS724_VB[13] = 1;
 
 VehRlyCtl_BMSPwrONCtrl();
 
 VehRlyCtl_ATSPwrONCtrl();
}//




//�߱�����  ����ϵͳ�ϵ��ź�  H121   16-2
void VehRlyCtl_EDSPwrONCtl(void)//
{
  //
  if(RlyTsk_stEDSPwrOnUB == 1)//
  {
    //
    _Btm_BTS724_VB[2] = 1;//||||====��Ϊ2  ��ͨ��3  ԭʼΪ1  ��Ϊͨ��2
  }//
  else//
  {
    //
    _Btm_BTS724_VB[2] = 0;
  }// 
}//




//�߱����� Start�����л�   16-9
void VehRlyCtl_StartSWChangeOverRlyCtl(void)//
{
  //
  if((RlyTsk_stStartSWChangeOverRlyUB == 1) && (SysSS_stMtrUB == 0))//
  {
    //
    _Btm_BTS724_VB[8] = 1;
  }//
  else//
  {
    //
    _Btm_BTS724_VB[8] = 0;
  }//
}//






//�߱�����16-13     HCU���̵���
void VehRlyCtl_HCUMainPwrRlyCtl(void)//
{
  //
  if(RlyTsk_stHCUMainPwrRlyUB == 1)//
  {
    //
    _Btm_BTS724_VB[12]=1;   
  }//
  else//
  {
    //
    _Btm_BTS724_VB[12]=0;   
  }//
}//



//�߱����� 16-16  �л���16-15        �յ����ȿ�������
void VehRlyCtl_ACFanRlyCtl(void)//
{
  //
  if((RlyTsk_stACFanRlyUB == 1)&&(SysSS_stACUB == 0))//
  {
    //
    _Btm_BTS724_VB[14]=1; 
  }//
  else//
  {
    //
    _Btm_BTS724_VB[14]=0;
  }//  
}//




//����DCDC 16-14
void VehRlyCtl_DCDCEnableCtrl(void)//
{
  //
  if(RlyTsk_stDCDCEnableUB == 1)//
  {
    //
    _Btm_BTS724_VB[13] = 1;
  }//
  else//
  {
    //
    _Btm_BTS724_VB[13] = 0;
  }// 
}//




//RlyTsk_stBMSPwrONUB     H111����    Y/W
void VehRlyCtl_BMSPwrONCtrl(void)//
{
  //
  if(RlyTsk_stBMSPwrONUB == 1)//
  {
    //
    _Btm_BTS724_VB[9] = 1;
  }//
  else//
  {
    //
    _Btm_BTS724_VB[9] = 0;
  }// 
}//


//RlyTsk_stATSPwrONUB      //H97����  Y/B
void VehRlyCtl_ATSPwrONCtrl(void)//
{
  //
  if(RlyTsk_stATSPwrONUB == 1)//
  {
    //
    _Btm_BTS724_VB[5] = 1;
  }//
  else//
  {
    //
    _Btm_BTS724_VB[5] = 0;
  }//  
}//




























