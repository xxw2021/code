#include "Allh.h"





unsigned char _Btm_BTS724_Enable[16];
unsigned char _Btm_BTS724_VB[16];




void BTS724Ctl_ValueInit(void)//
{
  //
  unsigned char num_valuetemp;
  
  for(num_valuetemp=0;num_valuetemp<16;num_valuetemp++)//
  {
    //
    _Btm_BTS724_Enable[num_valuetemp]=0;
    _Btm_BTS724_VB[num_valuetemp]=0;
  }
  
  BTS724_ChEnable_Config(); 
  //
}






void BTS724_ChEnable_Config(void)//
{
  //使能通道
  _Btm_BTS724_Enable[0]=1;      
  _Btm_BTS724_Enable[1]=1; 
  _Btm_BTS724_Enable[2]=1; 
  _Btm_BTS724_Enable[3]=1;
   
  _Btm_BTS724_Enable[4]=1; 
  _Btm_BTS724_Enable[5]=1; 
  _Btm_BTS724_Enable[6]=1; 
  _Btm_BTS724_Enable[7]=1;
   
  _Btm_BTS724_Enable[8]=1; 
  _Btm_BTS724_Enable[9]=1; 
  _Btm_BTS724_Enable[10]=1; 
  _Btm_BTS724_Enable[11]=1;
   
  _Btm_BTS724_Enable[12]=1; 
  _Btm_BTS724_Enable[13]=1; 
  _Btm_BTS724_Enable[14]=1; 
  _Btm_BTS724_Enable[15]=1;
}//






void BTS724Ctl_RlyCtrlUpdate_10ms(void)//
{
  //
  unsigned char num_Ch=0;
  
  for(num_Ch=0;num_Ch<16;num_Ch++)//
  {
    //
    if(_Btm_BTS724_Enable[num_Ch]==1)//
    {
      //
      if(_Btm_BTS724_VB[num_Ch]==1)//
      {
        //
        switch(num_Ch)//
        {
          //
          case 0://
          {
            //
            HighSideDrv_Chn1=1;
            break;
          }//
          case 1://
          {
            //
            HighSideDrv_Chn2=1;
            break;
          }//
          case 2://
          {
            //
            HighSideDrv_Chn3=1;
            break;
          }//
          case 3://
          {
            //
            HighSideDrv_Chn4=1;
            break;
          }//
          case 4://
          {
            //
            HighSideDrv_Chn5=1;
            break;
          }//
          case 5://
          {
            //
            HighSideDrv_Chn6=1;
            break;
          }//
          case 6://
          {
            //
            HighSideDrv_Chn7=1;
            break;
          }//
          case 7://
          {
            //
            HighSideDrv_Chn8=1;
            break;
          }//
          case 8://
          {
            //
            HighSideDrv_Chn9=1;
            break;
          }//
          case 9://
          {
            //
            HighSideDrv_Chn10=1;
            break;
          }//
          case 10://
          {
            //
            HighSideDrv_Chn11=1;
            break;
          }//
          case 11://
          {
            //
            HighSideDrv_Chn12=1;
            break;
          }//
          case 12://
          {
            //
            HighSideDrv_Chn13=1;
            break;
          }//
          case 13://
          {
            //
            HighSideDrv_Chn14=1;
            break;
          }//
          case 14://
          {
            //
            HighSideDrv_Chn15=1;
            break;
          }//
          case 15://
          {
            //
            HighSideDrv_Chn16=1;
            break;
          }//   
          default://
          {
            //
            break;
          }//
        }//
      }//
      else//端口设定为0
      {
        //
        switch(num_Ch)//
        {
          //
          case 0://
          {
            //
            HighSideDrv_Chn1=0;
            break;
          }//
          case 1://
          {
            //
            HighSideDrv_Chn2=0;
            break;
          }//
          case 2://
          {
            //
            HighSideDrv_Chn3=0;
            break;
          }//
          case 3://
          {
            //
            HighSideDrv_Chn4=0;
            break;
          }//
          case 4://
          {
            //
            HighSideDrv_Chn5=0;
            break;
          }//
          case 5://
          {
            //
            HighSideDrv_Chn6=0;
            break;
          }//
          case 6://
          {
            //
            HighSideDrv_Chn7=0;
            break;
          }//
          case 7://
          {
            //
            HighSideDrv_Chn8=0;
            break;
          }//
          case 8://
          {
            //
            HighSideDrv_Chn9=0;
            break;
          }//
          case 9://
          {
            //
            HighSideDrv_Chn10=0;
            break;
          }//
          case 10://
          {
            //
            HighSideDrv_Chn11=0;
            break;
          }//
          case 11://
          {
            //
            HighSideDrv_Chn12=0;
            break;
          }//
          case 12://
          {
            //
            HighSideDrv_Chn13=0;
            break;
          }//
          case 13://
          {
            //
            HighSideDrv_Chn14=0;
            break;
          }//
          case 14://
          {
            //
            HighSideDrv_Chn15=0;
            break;
          }//
          case 15://
          {
            //
            HighSideDrv_Chn16=0;
            break;
          }// 
          default://
          {
            //
            break;
          }//
        }//
      }//
    }//
    else//
    {
      //端口未使能
    }//    
  }//  
}




