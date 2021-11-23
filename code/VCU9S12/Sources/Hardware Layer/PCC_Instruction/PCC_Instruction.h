 #ifndef PCC_INSTRUCTION_H 
 #define PCC_INSTRUCTION_H
 
 
 #define   PCC_Active  1 
 #define   PCC_Exist   0

 #define    LED1_Control     PTP_PTP2
 #define    LED2_Control     PTP_PTP3    
 #define    Buzzer_Control   PORTK_PK3 
 
 #define    LED_ON    1
 #define    LED_OFF   0
 
 
 #define    Buzzer_ON     1
 #define    Buzzer_OFF    0
 

 
 
 void PCCStateDetect(void);
 
 
 
 
 
 #endif