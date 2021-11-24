#include "Allh.h"


#include <string.h>
#include "xgate.h"

#pragma push

/* this variable definition is to demonstrate how to share data between XGATE and S12X */
#pragma DATA_SEG SHARED_DATA
volatile int shared_counter; /* volatile because both cores are accessing it. */

/* Two stacks in XGATE core3 */ 
#pragma DATA_SEG XGATE_STK_L
word XGATE_STACK_L[1]; 
#pragma DATA_SEG XGATE_STK_H
word XGATE_STACK_H[1];

#pragma pop

#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */

static void SetupXGATE(void) {
  /* initialize the XGATE vector block and
     set the XGVBR register to its start address */
  XGVBR= (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);

  /* switch software trigger 0 interrupt to XGATE */
  ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x81); /* RQST=1 and PRIO=1 */

  /* when changing your derivative to non-core3 one please remove next five lines */
  XGISPSEL= 1;
  XGISP31= (unsigned int)(void*__far)(XGATE_STACK_L + 1);
  XGISPSEL= 2;
  XGISP74= (unsigned int)(void*__far)(XGATE_STACK_H + 1);
  XGISPSEL= 0;

  /* enable XGATE mode and interrupts */
  XGMCTL= 0xFBC1; /* XGE | XGFRZ | XGIE */

  /* force execution of software trigger 0 handler */
  XGSWT= 0x0101;
}


unsigned int i=0;
unsigned int j=0;
unsigned char a=0;

void delay(void)//
{
  //
  for(i=0;i<1000;i++)//
  {
    //
    for(j=0;j<5000;j++)//
    {
      //
    }// 
  }//
}//



unsigned char sw1=0;
unsigned char sw2=0;
unsigned char sw3=0;
unsigned char sw4=0;

unsigned char sw5=0;
unsigned char sw6=0;
unsigned char sw7=0;
unsigned char sw8=0;

unsigned char sw9=0;
unsigned char sw10=0;
unsigned char sw11=0;
unsigned char sw12=0;


unsigned int ADV0,ADV1,ADV2,ADV3,ADV4,ADV5,ADV6,ADV7,ADV8,ADV9,ADV10,ADV11,ADV12,ADV13,ADV14,ADV15,ADV16;



 
unsigned int mc1,mc2,mc3,mc4,mc5,mc6,mc7,mc8,mc9,mc10,mc11,mc12,mc13,mc14,mc15,mc16,mc17,mc18,mc19,mc20,mc21,mc22,mc23,mc24,mc25,mc26,mc27,mc28,mc29,mc30,mc31,mc32;

unsigned long mc33972_bitall;



unsigned long temp_idbuff;


void main(void) {
  /* put your own code here */
  
 // SetupXGATE();15:09
  
  Hardware_InitFunc();
  
  Value_Init();
  

	EnableInterrupts;
	
	BoardPwrCtrl = 1;


  for(;;) {
    
  
   CCP_DAQTask();
  
   temp_idbuff ++;

 


  /***
  mc1 = MC33972Bit_SG0;
  mc2 = MC33972Bit_SG1; 
  mc3 = MC33972Bit_SG2; 
  mc4 = MC33972Bit_SG3; 
  mc5 = MC33972Bit_SG4;
  mc6 =  MC33972Bit_SG5;
  mc7 =  MC33972Bit_SG6;
  mc8 =  MC33972Bit_SG7;
  mc9 =  MC33972Bit_SG8;
  mc10 = MC33972Bit_SG9;
  mc11 = MC33972Bit_SG10;
  mc12 = MC33972Bit_SG11;
  mc13 = MC33972Bit_SG12;
  mc14 = MC33972Bit_SG13;
  mc15 = MC33972Bit_SP0;
  mc16 = MC33972Bit_SP1;
  
  mc17 =  MC33972Bit_SP2;
  mc18 =  MC33972Bit_SP3;
  mc19 =  MC33972Bit_SP4;
  mc20 =  MC33972Bit_SP5;
  mc21 =  MC33972Bit_SP6;
  mc22 =  MC33972Bit_SP7;
  mc23 =  MC33972Bit_IntFlag;
  mc24 =  MC33972Bit_ThemFlag;
  mc25 =  MC33972Bit_SP8;
  mc26 =  MC33972Bit_SP9;
  mc27 =  MC33972Bit_SP10;
  mc28 =  MC33972Bit_SP11;
  mc29 =  MC33972Bit_SP12;
  mc30 =  MC33972Bit_SP13;
  mc31 =  MC33972Bit_SP14;
  mc32 =  MC33972Bit_SP15;  
  *****/
  
    
  
  
  ADV0=ATD0DR7;      //AD1    
  ADV1=ATD0DR15;     //AD2    
  ADV2=ATD0DR12;     //AD3
  ADV3=ATD0DR5;     //AD4
  
  
  ADV4=ATD0DR13;    //AD5
  ADV5=ATD0DR6;     //AD6    
  ADV6=ATD0DR14;    //AD7
  ADV7=ATD0DR7;     //AD8
  
  
  ADV8=ATD0DR15;    //AD9
  ADV9=ATD0DR15;    //AD10
  ADV10=ATD0DR15;    //AD11
  ADV11=ATD0DR15;    //AD12
  
  
  ADV12=ATD0DR15;    //ADR1
  ADV13=ATD0DR15;    //ADR2
  ADV14=ATD0DR15;    //ADR3
  ADV15=ATD0DR15;    //ADR4
  
  
  
  sw1 = PTT_PTT2;
	sw2 = PTT_PTT3;
	sw3 = PTT_PTT4;
	sw4 = PTT_PTT5;
	
	sw5 = PTT_PTT6;
	sw6 = PTT_PTT7;
	sw7 = PTS_PTS2;
	sw8 = PTS_PTS3;
	
	sw9 = PTS_PTS0;
	sw10 = PTS_PTS1;
	sw11 = PTM_PTM7;
	sw12 = PTM_PTM6;
  
  
  
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
