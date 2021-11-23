#include "Allh.h"



unsigned char SW_Smoothing;

                     
unsigned char _Btm_SWLH_Enable[SWLH_numTotalCh];
unsigned char SWLH_Timer1[SWLH_numTotalCh];
unsigned char SWLH_Timer0[SWLH_numTotalCh];
unsigned char PINRAW_SWLH[SWLH_numTotalCh];
unsigned char _Btm_SWLH_VB[SWLH_numTotalCh];




void SWChn_ValueInit(void)//
{
  //
  unsigned char num_valuetemp; 
  
  SW_Smoothing=4;
  
  for(num_valuetemp=0;num_valuetemp<SWLH_numTotalCh;num_valuetemp++)//
  {
    //
    _Btm_SWLH_Enable[num_valuetemp]=0;
    SWLH_Timer1[num_valuetemp]=0;
    SWLH_Timer0[num_valuetemp]=0;
    PINRAW_SWLH[num_valuetemp]=0;
    _Btm_SWLH_VB[num_valuetemp]=0;  
  }//
  SWChn_ChnEnable();
}//






void SWChn_Update_10ms(void)//
{       
  //
  unsigned char num_Ch=0;
  
  PINRAW_SWLH[0] =  PINRAW_SWLH_1;
  PINRAW_SWLH[1] =  PINRAW_SWLH_2;
  PINRAW_SWLH[2] =  PINRAW_SWLH_3;
  PINRAW_SWLH[3] =  PINRAW_SWLH_4;
  PINRAW_SWLH[4] =  PINRAW_SWLH_5;
  PINRAW_SWLH[5] =  PINRAW_SWLH_6;
  PINRAW_SWLH[6] =  PINRAW_SWLH_7;
  PINRAW_SWLH[7] =  PINRAW_SWLH_8;
  PINRAW_SWLH[8] =  PINRAW_SWLH_9;
  PINRAW_SWLH[9] =  PINRAW_SWLH_10;
  PINRAW_SWLH[10] = PINRAW_SWLH_11;
  PINRAW_SWLH[11] = PINRAW_SWLH_12;

  for(num_Ch=0;num_Ch<12;num_Ch++)//
  {
    //
    if(_Btm_SWLH_Enable[num_Ch]==1)//
    {
      //
      if(PINRAW_SWLH[num_Ch]==1)//
      {
        //
        SWLH_Timer1[num_Ch]++;
        SWLH_Timer0[num_Ch]=0; 
      }//
      else if(PINRAW_SWLH[num_Ch]==0)//
      {
        //
        SWLH_Timer0[num_Ch]++;
        SWLH_Timer1[num_Ch]=0;
      }//
      else//
      {
        //
        SWLH_Timer1[num_Ch]=0;
        SWLH_Timer0[num_Ch]=0;
      }//
      
      if(SWLH_Timer1[num_Ch]>SW_Smoothing)//
      {
        //
        _Btm_SWLH_VB[num_Ch]=1;
        SWLH_Timer1[num_Ch]=0;
        SWLH_Timer0[num_Ch]=0;
      }//
      else if(SWLH_Timer0[num_Ch]>SW_Smoothing)//
      {
        //
        _Btm_SWLH_VB[num_Ch]=0;
        SWLH_Timer1[num_Ch]=0;
        SWLH_Timer0[num_Ch]=0;
      }//
      else//
      {
        //
      }//    
    }//   
  }//
}//





//--------------
//执行   SWCh_ValueInit
void SWChn_ChnEnable(void)//
{
  //
  //数组从0开始 相应的数值减去1
  _Btm_SWLH_Enable[0]=1;  
  _Btm_SWLH_Enable[1]=1;     
  _Btm_SWLH_Enable[2]=1;      
  _Btm_SWLH_Enable[3]=1;     
  _Btm_SWLH_Enable[4]=1;     
  _Btm_SWLH_Enable[5]=1;      
  _Btm_SWLH_Enable[6]=1;        
  _Btm_SWLH_Enable[7]=1;      
  _Btm_SWLH_Enable[8]=1;     
  _Btm_SWLH_Enable[9]=1;      
  _Btm_SWLH_Enable[10]=1;    
  _Btm_SWLH_Enable[11]=1;    
}//




  
  
  
  
  
  
  
  
  
  
  
  




















































  