#include "Allh.h"     //head file 


unsigned int  counter_Ent, counter_Ext;
unsigned int  PCC_State_Bef = 0;


void PCCStateDetect(void)          // Robin190525
{ 
  //--------����PCC�ı�־λ����ֵ��PCC_State--------/
  unsigned int PCC_State_Curr;        //��ǰѲ��״̬
  PCC_State_Curr = CrCtl_stActive_BL;
  if(PCC_State_Curr==PCC_Active)
   {
    
    LED1_Control = LED_ON;        // PP2   �Ӳ��H16
    LED2_Control = LED_OFF;       // PP3   �Ӳ��H15
   
   } 
  else if(PCC_State_Curr==PCC_Exist) 
   {
    
    LED1_Control = LED_OFF;       // PP2
    LED2_Control = LED_ON;        // PP3
   
   }
  if( PCC_State_Curr==1 && PCC_State_Bef==0 ) //����Ѳ����������ʾ����,���������0->1
   {
    counter_Ent = 1 ;  //����Ѳ�����������ƿ�ʼ������־
   }
  if(counter_Ent !=0 )  //������Ѳ��������־
   {
      counter_Ent=counter_Ent++;
      if(counter_Ent < 3) 
      {
      
         Buzzer_Control = Buzzer_ON;   // PK3   �Ӳ��H3
    
      } 
     else if (counter_Ent > 5)
       { 
         
         Buzzer_Control = Buzzer_OFF;
         counter_Ent = 0;
       }
   }
  if( PCC_State_Curr==0 && PCC_State_Bef==1 )  //�˳�Ѳ����������ʾ���� ,����½���1->0��������
   {
      counter_Ext = 1 ;  //�˳�Ѳ�����������ƿ�ʼ������־
   }
  if (counter_Ext !=0 ) //����˳�Ѳ��������־
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