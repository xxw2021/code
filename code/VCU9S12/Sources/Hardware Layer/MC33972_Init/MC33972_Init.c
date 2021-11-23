#include "Allh.h"




MC33972_SPSET_Union        MC33972_SPSET;
MC33972_SPWUICmd_Union     MC33972_SPWUICmd;
MC33972_SGWUICmd_Union     MC33972_SGWUICmd;
MC33972_SPMTLCCmd_Union    MC33972_SPMTLCCmd;
MC33972_SGMTLCCmd_Union    MC33972_SGMTLCCmd;
MC33972_SPWCCmd_Union      MC33972_SPWCCmd;
MC33972_SGWCCmd_Union      MC33972_SGWCCmd;
MC33972_SPTriStCmd_Union   MC33972_SPTriStCmd;
MC33972_SGTriStCmd_Union   MC33972_SGTriStCmd;
MC33972_RxData_Union       MC33972_Rx;



unsigned long MC33972_Temp;
                                  //7654321076543210
unsigned int MC33972_SPSet_C    = 0b0000000011111111;

unsigned int MC33972_SPWUISet_C = 0b0000000011111111;
unsigned int MC33972_SGWUISet_C = 0b1111111111111111;
                                 //7654321076543210
unsigned int MC33972_SPMtlcSet_C = 0b0000000011111111;
unsigned int MC33972_SGMtlcSet_C = 0b1111111111111111;
                                  //7654321076543210
unsigned int MC33972_SPWCTSet_C = 0b0000000011111111;
unsigned int MC33972_SGWCTSet_C = 0b1111111111111111;
                                    //7654321076543210
unsigned int MC33972_SPTriStSet_C = 0b0000000011111111;
unsigned int MC33972_SGTriStSet_C = 0b1111111111111111;


void MC33972_ValueInit(void)//
{
  //
  
  
}//

       
void MC33972_Init(void)//
{
  //
  
  MC33972_Reset(); 
  MC33972_SPSet();                                               
  
  MC33972_SPWUISet();
  MC33972_SGWUISet();
  MC33972_SPMtlcSet();
  MC33972_SGMtlcSet();
  MC33972_SPWCTSet();
  MC33972_SGWCTSet();
  MC33972_SPTriStSet();
  MC33972_SGTriStSet(); 
}//
       
       
 
void MC33972_Reset(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_Reset,0);   
}//
 
void MC33972_SPSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SPStSet,MC33972_SPSet_C);   
}//
                                                     
void MC33972_SPWUISet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SPWUISet,MC33972_SPWUISet_C);      
}//
  

void MC33972_SGWUISet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SGWUISet,MC33972_SGWUISet_C);     
}//


void MC33972_SPMtlcSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SPMtlcSet,MC33972_SPMtlcSet_C);      
}//
  

void MC33972_SGMtlcSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SGMtlcSet,MC33972_SGMtlcSet_C);     
}//


void MC33972_SPWCTSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SPWCTSet,MC33972_SPWCTSet_C);      
}//
  

void MC33972_SGWCTSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SGWCTSet,MC33972_SGWCTSet_C);     
}//

void MC33972_SPTriStSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SPTriStSet,MC33972_SPTriStSet_C);      
}//
  

void MC33972_SGTriStSet(void)//
{
  //
  MC33972_CS = 1;
  MC33972_Temp = SPIMC33972_Tx_CMD(MC33972CMD_SGTriStSet,MC33972_SGTriStSet_C);     
}//



unsigned int mc33972_1 = 0;
unsigned int mc33972_2 = 0;
unsigned int mc33972_3 = 0;
unsigned int mc33972_4 = 0;

unsigned int mc33972word;
unsigned int mc33972char;






void SPIMC33972_Tx_CMD_Func(void)//
{
  //
  uchar i=0;
  
  unsigned int rxchar;
  unsigned int rxword;
  
  
  
  
  MC33972_CS=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  MC33972_CS=0;

  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI2DR=0b0000000000000110;        //write tx_dataBuf	
	
	i=0;
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxchar=SPI2DR;              //return rx_dataBuf

  
  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI2DR=0b0000000000100000;        //write tx_dataBuf
	       //8765432187654321
	i=0;
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxword=SPI2DR;              //return rx_dataBuf

  
 
  MC33972_CS=1; 
  
  mc33972word = (unsigned int)rxword;
  mc33972char = (unsigned int)rxchar;
}//



uint16 mc33972cmd;
uint16 mc33972data;

//====================================
//先发送CMD和DataHigh共2个字节，然后DataLow一个字节
unsigned long SPIMC33972_Tx_CMD(unsigned int Tx_CMD,unsigned int Tx_Data)//
{
  //
  uchar i=0;
  
  uint32  rxCMD;
  uint32  rxDATA;
  uint32 rxlong;  
  
	MC33972_CS=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  MC33972_CS=0;

  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI2DR=Tx_CMD;        //write tx_dataBuf	
	
	i=0;
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxCMD=SPI2DR;              //return rx_dataBuf

  
  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI2DR=Tx_Data;        //write tx_dataBuf
	
	i=0;
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxDATA=SPI2DR;              //return rx_dataBuf


  rxlong = rxCMD*256 + rxDATA/256;

  mc33972cmd = rxCMD;
  mc33972data = rxDATA;

  MC33972_CS=1; 

  return rxlong;
}//




uchar SPIMC33972_Tx_Char(unsigned char txvalue)//
{
  //
  uchar i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0&&i<100);//check tx_dataBuf  
	i=0;
	SPI2DR=txvalue;              //write tx_dataBuf
	do
	{
	  i++;
	}
	while(SPI2SR_SPIF==0&&i<100);  //check rx_dataBuf 
	i=0;
	return (uchar)SPI2DR;                  //return rx_dataBuf   
}//



uint16 SPIMC33972_Tx_Word(uint16 txdata)
{
	uchar i;
	uint16 rxdata;

	MC33972_CS=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  MC33972_CS=0;

  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0 && i<100); //check tx_dataBuf
	i=0;
	SPI2DR=txdata;        //write tx_dataBuf
	
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxdata=SPI2DR;              //return rx_dataBuf
	
	MC33972_CS=1; 
	
	return rxdata;
}