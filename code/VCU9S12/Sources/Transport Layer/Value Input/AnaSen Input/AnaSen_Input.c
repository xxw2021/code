#include "Allh.h"






unsigned int PINRAW_AD[AD_numTotalCh];
unsigned char ADBUFtemp_Ch[AD_numTotalCh];
unsigned int ADSmoothing_ADD[AD_numTotalCh];
unsigned int ADBUF_CH1[AD_numTotalCh][AD_Smoothing];
unsigned char _Btm_ADChn_Enable[AD_numTotalCh];
unsigned int _Btm_ADAverageUW[AD_numTotalCh];



void ADCh_ValueInit(void)//
{
  //
  unsigned char temp_i,temp_j;

 
  for(temp_i=0;temp_i<AD_numTotalCh;temp_i++)//
  {
    //
    _Btm_ADChn_Enable[temp_i]=0;
    PINRAW_AD[temp_i]=0;
    ADBUFtemp_Ch[temp_i]=0;
    ADSmoothing_ADD[temp_i]=0;
    _Btm_ADAverageUW[temp_i]=0;
    
    for(temp_j=0;temp_j<AD_Smoothing;temp_j++)//
    {
      //
      ADBUF_CH1[temp_i][temp_j]=0;
    }//    
  }//
  
  ADSen_ChConfig();    
}//





void ADCh_Update_10ms(void)//
{
  //
  unsigned char num_Ch;
  unsigned char num_smoothing;

  //获得寄存器当前值


  PINRAW_AD[0]=ATD0DR0;      //MC33972_AD    
  PINRAW_AD[1]=ATD0DR10;     //AD1    
  PINRAW_AD[2]=ATD0DR3;      //AD2
  PINRAW_AD[3]=ATD0DR11;     //AD3
  
  
  PINRAW_AD[4]=ATD0DR4;      //AD4
  PINRAW_AD[5]=ATD0DR8;      //AD5    
  PINRAW_AD[6]=ATD0DR1;      //AD6
  PINRAW_AD[7]=ATD0DR9;      //AD7
  
  
  PINRAW_AD[8]=ATD0DR2;      //AD8
 
  PINRAW_AD[11]=ATD0DR6;     //ADR1
  PINRAW_AD[12]=ATD0DR13;    //ADR2
  PINRAW_AD[13]=ATD0DR5;     //ADR3
  PINRAW_AD[14]=ATD0DR12;    //ADR4
 
  
  
  
  for(num_Ch=0;num_Ch<AD_numTotalCh;num_Ch++)//
  {
    //
    if(_Btm_ADChn_Enable[num_Ch]==1)//
    {
      //
      ADBUF_CH1[num_Ch][ADBUFtemp_Ch[num_Ch]]=PINRAW_AD[num_Ch];
      ADBUFtemp_Ch[num_Ch]++;
      
      if(ADBUFtemp_Ch[num_Ch]>=AD_Smoothing)//
      ADBUFtemp_Ch[num_Ch]=0;
      
      
      ADSmoothing_ADD[num_Ch]=0;
      for(num_smoothing=0;num_smoothing<AD_Smoothing;num_smoothing++)//
      ADSmoothing_ADD[num_Ch]=ADSmoothing_ADD[num_Ch]+ADBUF_CH1[num_Ch][num_smoothing];
      
      _Btm_ADAverageUW[num_Ch] = ADSmoothing_ADD[num_Ch] / AD_Smoothing;   
    }//
    else//
    {
      //
    }//   
  } 
}//




//AD通道使能  0
void ADSen_ChConfig(void)//
{
  //
  _Btm_ADChn_Enable[0] = 1;
  _Btm_ADChn_Enable[1] = 1;
  _Btm_ADChn_Enable[2] = 1;
  _Btm_ADChn_Enable[3] = 1;
  _Btm_ADChn_Enable[4] = 1;
  _Btm_ADChn_Enable[5] = 1;
  _Btm_ADChn_Enable[6] = 1;
  _Btm_ADChn_Enable[7] = 1;
  _Btm_ADChn_Enable[8] = 1;
  _Btm_ADChn_Enable[9] = 1;
  _Btm_ADChn_Enable[10] = 1;
  _Btm_ADChn_Enable[11] = 1;
  _Btm_ADChn_Enable[12] = 1;
  _Btm_ADChn_Enable[13] = 1;
  _Btm_ADChn_Enable[14] = 1;
  _Btm_ADChn_Enable[15] = 1;
}//












