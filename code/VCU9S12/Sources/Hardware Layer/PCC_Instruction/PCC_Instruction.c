#include "Allh.h"     //head file 


unsigned int  counter_Ent, counter_Ext;
unsigned int  PCC_State_Bef = 0;


void PCCStateDetect(void)          // Robin190525
{ 
  //--------检测进PCC的标志位，赋值给PCC_State--------/
  unsigned int PCC_State_Curr;        //当前巡航状态
  PCC_State_Curr = CrCtl_stActive_BL;
  if(PCC_State_Curr==PCC_Active)
   {
    
    LED1_Control = LED_ON;        // PP2   接插件H16
    LED2_Control = LED_OFF;       // PP3   接插件H15
   
   } 
  else if(PCC_State_Curr==PCC_Exist) 
   {
    
    LED1_Control = LED_OFF;       // PP2
    LED2_Control = LED_ON;        // PP3
   
   }
  if( PCC_State_Curr==1 && PCC_State_Bef==0 ) //进入巡航蜂鸣器提示控制,检测上升沿0->1
   {
    counter_Ent = 1 ;  //进入巡航蜂鸣器控制开始计数标志
   }
  if(counter_Ent !=0 )  //检测进入巡航计数标志
   {
      counter_Ent=counter_Ent++;
      if(counter_Ent < 3) 
      {
      
         Buzzer_Control = Buzzer_ON;   // PK3   接插件H3
    
      } 
     else if (counter_Ent > 5)
       { 
         
         Buzzer_Control = Buzzer_OFF;
         counter_Ent = 0;
       }
   }
  if( PCC_State_Curr==0 && PCC_State_Bef==1 )  //退出巡航蜂鸣器提示控制 ,检测下降沿1->0，响两次
   {
      counter_Ext = 1 ;  //退出巡航蜂鸣器控制开始计数标志
   }
  if (counter_Ext !=0 ) //检测退出巡航计数标志
  {  
      counter_Ext = counter_Ext++;
      if(counter_Ext < 3) 
        {
      
         Buzzer_Control = Buzzer_ON;   // PK3   3
    
        } 
      else if( 3 < counter_Ext && counter_Ext < 5 ) 
         { 
         
         Buzzer_Control = Buzzer_OFF;
       
         }
      else if( 5 < counter_Ext && counter_Ext < 7) 
         { 
         
         Buzzer_Control = Buzzer_ON;
       
         } 
       
      else if(counter_Ext > 8 )
        {
          Buzzer_Control = Buzzer_OFF;
          counter_Ext = 0;       
        }
   
   }
  PCC_State_Bef = PCC_State_Curr;

} 