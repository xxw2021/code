#ifndef _TLE7230_INIT_H_
#define _TLE7230_INIT_H_



extern uint16 TLE7230_Rxdata;





#define TLE7230_CS      PTJ_PTJ7
#define TLE7230_IN      PTJ_PTJ6   
#define TLE7230_RST     PTS_PTS7   




typedef union {
  byte Ctl_Byte;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1;
  }Bits;
}TLE7230_Ctl_Union;


extern  TLE7230_Ctl_Union TLE7230_Ctrl_Byte;


#define  Bit_RlyL_ALL   TLE7230_Ctrl_Byte.Ctl_Byte
#define  Bit_RlyL1      TLE7230_Ctrl_Byte.Bits.data0
#define  Bit_RlyL2      TLE7230_Ctrl_Byte.Bits.data1
#define  Bit_RlyL3      TLE7230_Ctrl_Byte.Bits.data2
#define  Bit_RlyL4      TLE7230_Ctrl_Byte.Bits.data3
#define  Bit_RlyL5      TLE7230_Ctrl_Byte.Bits.data4
#define  Bit_RlyL6      TLE7230_Ctrl_Byte.Bits.data5
#define  Bit_RlyL7      TLE7230_Ctrl_Byte.Bits.data6
#define  Bit_RlyL8      TLE7230_Ctrl_Byte.Bits.data7

  


 

void TLE7230_ValueInit(void);

uint16 SPI7230_Tx_Word(uint16 txdata);
uchar SPI7230_Tx_Char(uchar txvalue);

void TLE7230Init(void); 
uint16 TLE7230_Ctl_Tx(uchar TLE7230_Txword); 




















#endif