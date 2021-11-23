#include "Allh.h"




unsigned long MC33972_SWSt;

unsigned char MC33972SM_numCycle;  
                   
unsigned char MC33972Chn_EN[MC33972_numTotalChn];
unsigned char MC33972SM_Timer1[MC33972_numTotalChn];
unsigned char MC33972SM_Timer0[MC33972_numTotalChn];
unsigned char MC33972RAW_SWSt[MC33972_numTotalChn];
unsigned char MC33972SM_SWSt[MC33972_numTotalChn];


unsigned char MC33972Chn_SG0;
unsigned char MC33972Chn_SG1;
unsigned char MC33972Chn_SG2;
unsigned char MC33972Chn_SG3;
unsigned char MC33972Chn_SG4;
unsigned char MC33972Chn_SG5;
unsigned char MC33972Chn_SG6;
unsigned char MC33972Chn_SG7;
unsigned char MC33972Chn_SG8;
unsigned char MC33972Chn_SG9;
unsigned char MC33972Chn_SG10;
unsigned char MC33972Chn_SG11;
unsigned char MC33972Chn_SG12;
unsigned char MC33972Chn_SG13;
unsigned char MC33972Chn_SG14;
unsigned char MC33972Chn_SP1;
unsigned char MC33972Chn_SP2;
unsigned char MC33972Chn_SP3;
unsigned char MC33972Chn_SP4;
unsigned char MC33972Chn_SP5;
unsigned char MC33972Chn_SP6;
unsigned char MC33972Chn_SP7;
unsigned char MC33972Chn_SP8;
unsigned char MC33972_IntFlag;
unsigned char MC33972_ThemFlag;









void MC33972Input_ValueInit(void)//
{
  //
  unsigned char num_valuetemp; 
  
  MC33972_SWSt = 0;
  MC33972SM_numCycle = 2;
 
  
  for(num_valuetemp=0;num_valuetemp<MC33972_numTotalChn;num_valuetemp++)//
  {
    //
    MC33972Chn_EN[num_valuetemp]=0;
    MC33972SM_Timer1[num_valuetemp]=0;
    MC33972SM_Timer0[num_valuetemp]=0;
    MC33972RAW_SWSt[num_valuetemp]=0;
    MC33972SM_SWSt[num_valuetemp]=0;  
  }//
  
  MC33972_ChnEnable();
}//



void MC33972_Update_10ms(void)//
{
  //
  MC33972_SWStUpdate(); //获得芯片SPI信息
  MC33972_SWStInput();  //获取开关量的输入值
  MC33972_SMUpdate();   //开关量进行滤波处理
}//




void MC33972_SWStUpdate(void)//
{
  //
  MC33972_CS = 1;
  SPIMC33972_Tx_CMD_Func();
  MC33972_SWSt = SPIMC33972_Tx_CMD(MC33972CMD_SWSt,0);      
}//



void MC33972_SWStInput(void)//
{
  //
  MC33972Chn_SG1 =  (MC33972_SWSt >> 0) & 1;
  MC33972Chn_SG2 =  (MC33972_SWSt >> 1) & 1;
  MC33972Chn_SG3 =  (MC33972_SWSt >> 2) & 1;
  MC33972Chn_SG4 =  (MC33972_SWSt >> 3) & 1;
  MC33972Chn_SG5 =  (MC33972_SWSt >> 4) & 1;
  MC33972Chn_SG6 =  (MC33972_SWSt >> 5) & 1;
  MC33972Chn_SG7 =  (MC33972_SWSt >> 6) & 1;
  MC33972Chn_SG8 =  (MC33972_SWSt >> 7) & 1;
  MC33972Chn_SG9 =  (MC33972_SWSt >> 8) & 1;
  MC33972Chn_SG10 = (MC33972_SWSt >> 9) & 1;
  MC33972Chn_SG11 = (MC33972_SWSt >> 10) & 1;  
  MC33972Chn_SG12 = (MC33972_SWSt >> 11) & 1;
  MC33972Chn_SG13 = (MC33972_SWSt >> 12) & 1;
  MC33972Chn_SG14 = (MC33972_SWSt >> 13) & 1;
 
  MC33972Chn_SP1 = (MC33972_SWSt >> 14) & 1;
  MC33972Chn_SP2 = (MC33972_SWSt >> 15) & 1;
  
  MC33972Chn_SP3 = (MC33972_SWSt >> 16) & 1;
  MC33972Chn_SP4 = (MC33972_SWSt >> 17) & 1;
  MC33972Chn_SP5 = (MC33972_SWSt >> 18) & 1;
  MC33972Chn_SP6 = (MC33972_SWSt >> 19) & 1;
  MC33972Chn_SP7 = (MC33972_SWSt >> 20) & 1;
  MC33972Chn_SP8 = (MC33972_SWSt >> 21) & 1;
 
  MC33972_IntFlag  = (MC33972_SWSt >> 22) & 1;
  MC33972_ThemFlag = (MC33972_SWSt >> 23) & 1;
 
}//


void MC33972_SMUpdate(void)//
{
  //
  unsigned char num_Ch = 0;
  
  
  MC33972RAW_SWSt[0] = MC33972Bit_SG0;
  MC33972RAW_SWSt[1] = MC33972Bit_SG1;
  MC33972RAW_SWSt[2] = MC33972Bit_SG2;
  MC33972RAW_SWSt[3] = MC33972Bit_SG3;
  
  MC33972RAW_SWSt[4] = MC33972Bit_SG4;
  MC33972RAW_SWSt[5] = MC33972Bit_SG5;
  MC33972RAW_SWSt[6] = MC33972Bit_SG6;
  MC33972RAW_SWSt[7] = MC33972Bit_SG7;
  
  MC33972RAW_SWSt[8] = MC33972Bit_SG8;
  MC33972RAW_SWSt[9] = MC33972Bit_SG9;
  MC33972RAW_SWSt[10] = MC33972Bit_SG10;
  MC33972RAW_SWSt[11] = MC33972Bit_SG11;
  
  MC33972RAW_SWSt[12] = MC33972Bit_SG12;
  MC33972RAW_SWSt[13] = MC33972Bit_SG13;
  MC33972RAW_SWSt[14] = MC33972Bit_SP0;
  MC33972RAW_SWSt[15] = MC33972Bit_SP1;
  
  MC33972RAW_SWSt[16] = MC33972Bit_SP2;
  MC33972RAW_SWSt[17] = MC33972Bit_SP3;
  MC33972RAW_SWSt[18] = MC33972Bit_SP4;
  MC33972RAW_SWSt[19] = MC33972Bit_SP5;
  
  MC33972RAW_SWSt[20] = MC33972Bit_SP6;
  MC33972RAW_SWSt[21] = MC33972Bit_SP7;
  
  
  
  for(num_Ch=0;num_Ch<22;num_Ch++)//
  {
    //
    if(MC33972Chn_EN[num_Ch]==1)//
    {
      //
      if(MC33972RAW_SWSt[num_Ch]==1)//
      {
        //
        MC33972SM_Timer1[num_Ch]++;
        MC33972SM_Timer0[num_Ch]=0; 
      }//
      else if(MC33972RAW_SWSt[num_Ch]==0)//
      {
        //
        MC33972SM_Timer0[num_Ch]++;
        MC33972SM_Timer1[num_Ch]=0;
      }//
      else//
      {
        //
        MC33972SM_Timer1[num_Ch]=0;
        MC33972SM_Timer0[num_Ch]=0;
      }//
      
      if(MC33972SM_Timer1[num_Ch]>MC33972SM_numCycle)//
      {
        //
        MC33972SM_SWSt[num_Ch]=1;
        MC33972SM_Timer1[num_Ch]=0;
        MC33972SM_Timer0[num_Ch]=0;
      }//
      else if(MC33972SM_Timer0[num_Ch]>MC33972SM_numCycle)//
      {
        //
        MC33972SM_SWSt[num_Ch]=0;
        MC33972SM_Timer1[num_Ch]=0;
        MC33972SM_Timer0[num_Ch]=0;
      }//
      else//
      {
        //
      }//    
    }//   
  }//
  
  
  
  
  
  
}//



void MC33972_ChnEnable(void)//
{
  //
  MC33972Chn_EN[0] = 1;
  MC33972Chn_EN[1] = 1;
  MC33972Chn_EN[2] = 1;
  MC33972Chn_EN[3] = 1;
  
  MC33972Chn_EN[4] = 1;
  MC33972Chn_EN[5] = 1;
  MC33972Chn_EN[6] = 1;
  MC33972Chn_EN[7] = 1;
  
  MC33972Chn_EN[8] = 1;
  MC33972Chn_EN[9] = 1;
  MC33972Chn_EN[10] = 1;
  MC33972Chn_EN[11] = 1;
  
  MC33972Chn_EN[12] = 1;
  MC33972Chn_EN[13] = 1;
  MC33972Chn_EN[14] = 1;
  MC33972Chn_EN[15] = 1;
  
  MC33972Chn_EN[16] = 1;
  MC33972Chn_EN[17] = 1;
  MC33972Chn_EN[18] = 1;
  MC33972Chn_EN[19] = 1;
  
  MC33972Chn_EN[20] = 1;
  MC33972Chn_EN[21] = 1;
}//



