#ifndef  MCU_INIT_H
#define  MCU_INIT_H
    
#define  Enable_RTI_Interrupt    CRGINT = CRGINT | 0x80;      /*Enable RTI Interrupt*/


void MCU_Init(void);   



#endif