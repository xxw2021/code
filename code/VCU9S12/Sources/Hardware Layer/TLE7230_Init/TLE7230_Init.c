#include "Allh.h"



uint16 TLE7230_Rxdata;
TLE7230_Ctl_Union TLE7230_Ctrl_Byte;






void TLE7230_ValueInit(void)//
{
  //
  TLE7230_Rxdata = 0;
  Bit_RlyL_ALL = 0;
}//


 
//--------------TLE7230Init-----------------------
void TLE7230Init(void) 
{
  TLE7230_RST=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  
  TLE7230_CS=1;
  TLE7230_IN=0;
  TLE7230Ctl_AllRly_OFF();
}




//-------------------------------------
//TLE7230 SPI
//Send data     word
//Return data   word
uint16 TLE7230_Ctl_Tx(uchar TLE7230_Txword) 
{
  uint16 TLE7230_Rxword;
  uint16 TxWord_Comb;
  
  TxWord_Comb= 0xc7*256 +TLE7230_Txword;
  
  TLE7230_CS=0;
  asm NOP;
  asm NOP;
  asm NOP;
  TLE7230_Rxword=SPI7230_Tx_Word(TxWord_Comb);
  TLE7230_CS=1;
  asm NOP;
  asm NOP;
  asm NOP;
  return TLE7230_Rxword;
}





//-----------SPI2 tx_Char  TLE3230----------------------
//SPI Transmit Char
//Send value    char
//Return value  char
uchar SPI7230_Tx_Char(uchar txvalue)
{
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
}




//-----------SPI2 tx_Char   TLE7230----------------------
//SPI2 Transmit Word
//Send value   word
//Return value word
uint16 SPI7230_Tx_Word(uint16 txdata)
{
	uchar i;
	uint16 rxdata;

	TLE7230_CS=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  TLE7230_CS=0;
	
	
  i=0;
	do
	{
	  i++;
	}
	while(SPI2SR_SPTEF==0&&i<100); //check tx_dataBuf
	i=0;
	SPI2DR=txdata;        //write tx_dataBuf
	
	do
	{
		i++;
	}
	while(SPI2SR_SPIF==0&&i<100); //check rx_dataBuf
	i=0;
	rxdata=SPI2DR;              //return rx_dataBuf
	
	TLE7230_CS=1; 
	
	return rxdata;
}













    