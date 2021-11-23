#ifndef _MC33972_INIT_H_
#define _MC33972_INIT_H_




#define MC33972_CS     PTH_PTH7
#define MC33972_INT    PORTA_PA0



extern unsigned int mc33972_1;
extern unsigned int mc33972_2;
extern unsigned int mc33972_3;
extern unsigned int mc33972_4;

extern unsigned long SPIMC33972_Tx_CMD(unsigned int Tx_CMD,unsigned int Tx_Data);
extern uchar SPIMC33972_Tx_Char(unsigned char txvalue);
extern uint16 SPIMC33972_Tx_Word(uint16 txdata);

void MC33972_ValueInit(void);   
void MC33972_Init(void);    
void MC33972_Reset(void); 
void MC33972_SPSet(void);                                               
void MC33972_SPWUISet(void);
void MC33972_SGWUISet(void);
void MC33972_SPMtlcSet(void);
void MC33972_SGMtlcSet(void);
void MC33972_SPWCTSet(void);
void MC33972_SGWCTSet(void);
void MC33972_SPTriStSet(void);
void MC33972_SGTriStSet(void);

void SPIMC33972_Tx_CMD_Func(void);




//Switch Status Command    空闲状态发送
#define MC33972CMD_SWSt           0b0000000000000000
//Setting Command     set sp bat=0  gnd=1
#define MC33972CMD_SPStSet        0b0000000000000001
//SP Wake_Up Interrupt 
#define MC33972CMD_SPWUISet       0b0000000000000010
//SG Wake_Up Interrupt 
#define MC33972CMD_SGWUISet       0b0000000000000011
//SP Metallic Command
#define MC33972CMD_SPMtlcSet      0b0000000000000100
//SG Metallic Command
#define MC33972CMD_SGMtlcSet      0b0000000000000101
//Analog Command
#define MC33972CMD_AnaSet         0b0000000000000110
//SP Wetting Current Timer
#define MC33972CMD_SPWCTSet       0b0000000000000111
//SG Wetting Current Timer
#define MC33972CMD_SGWCTSet       0b0000000000001000
//SP Tri_State Command
#define MC33972CMD_SPTriStSet     0b0000000000001001
//SG Tri_State Command
#define MC33972CMD_SGTriStSet     0b0000000000001010
//Reset Command
#define MC33972CMD_Reset          0b0000000001111111




//CMD Setting 设定SP端口的状态
typedef union {
  byte  Byte;
  
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
}MC33972_SPSET_Union;

extern  MC33972_SPSET_Union  MC33972_SPSET;

#define  MC33972Bit_SPSETALL       MC33972_SPSET.Byte
#define  MC33972Bit_SPSET0         MC33972_SPSET.Bits.data0
#define  MC33972Bit_SPSET1         MC33972_SPSET.Bits.data1
#define  MC33972Bit_SPSET2         MC33972_SPSET.Bits.data2
#define  MC33972Bit_SPSET3         MC33972_SPSET.Bits.data3
#define  MC33972Bit_SPSET4         MC33972_SPSET.Bits.data4
#define  MC33972Bit_SPSET5         MC33972_SPSET.Bits.data5
#define  MC33972Bit_SPSET6         MC33972_SPSET.Bits.data6
#define  MC33972Bit_SPSET7         MC33972_SPSET.Bits.data7



//设定SP引脚的wake_up/Interrupt Cmd
typedef union {
  byte  Byte;
  
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
}MC33972_SPWUICmd_Union;

extern  MC33972_SPWUICmd_Union  MC33972_SPWUICmd;

#define  MC33972Bit_SPWUICmdALL       MC33972_SPWUICmd.Byte
#define  MC33972Bit_SPWUICmd0         MC33972_SPWUICmd.Bits.data0
#define  MC33972Bit_SPWUICmd1         MC33972_SPWUICmd.Bits.data1
#define  MC33972Bit_SPWUICmd2         MC33972_SPWUICmd.Bits.data2
#define  MC33972Bit_SPWUICmd3         MC33972_SPWUICmd.Bits.data3
#define  MC33972Bit_SPWUICmd4         MC33972_SPWUICmd.Bits.data4
#define  MC33972Bit_SPWUICmd5         MC33972_SPWUICmd.Bits.data5
#define  MC33972Bit_SPWUICmd6         MC33972_SPWUICmd.Bits.data6
#define  MC33972Bit_SPWUICmd7         MC33972_SPWUICmd.Bits.data7



//设定SG引脚的wake_up/Interrupt Cmd
typedef union {

  word  Byte;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1; 
    
    byte data8      :1;
    byte data9      :1;
    byte data10     :1;
    byte data11     :1;
    byte data12     :1;
    byte data13     :1;
    byte data14     :1;
    byte data15     :1;    
  }Bits;
}MC33972_SGWUICmd_Union;

extern  MC33972_SGWUICmd_Union  MC33972_SGWUICmd;

#define  MC33972Bit_SGWUICmdALL       MC33972_SGWUICmd.Byte
#define  MC33972Bit_SGWUICmd0         MC33972_SGWUICmd.Bits.data0
#define  MC33972Bit_SGWUICmd1         MC33972_SGWUICmd.Bits.data1
#define  MC33972Bit_SGWUICmd2         MC33972_SGWUICmd.Bits.data2
#define  MC33972Bit_SGWUICmd3         MC33972_SGWUICmd.Bits.data3
#define  MC33972Bit_SGWUICmd4         MC33972_SGWUICmd.Bits.data4
#define  MC33972Bit_SGWUICmd5         MC33972_SGWUICmd.Bits.data5
#define  MC33972Bit_SGWUICmd6         MC33972_SGWUICmd.Bits.data6
#define  MC33972Bit_SGWUICmd7         MC33972_SGWUICmd.Bits.data7

#define  MC33972Bit_SGWUICmd8         MC33972_SGWUICmd.Bits.data8
#define  MC33972Bit_SGWUICmd9         MC33972_SGWUICmd.Bits.data9
#define  MC33972Bit_SGWUICmd10        MC33972_SGWUICmd.Bits.data10
#define  MC33972Bit_SGWUICmd11        MC33972_SGWUICmd.Bits.data11
#define  MC33972Bit_SGWUICmd12        MC33972_SGWUICmd.Bits.data12
#define  MC33972Bit_SGWUICmd13        MC33972_SGWUICmd.Bits.data13
#define  MC33972Bit_SGWUICmd14        MC33972_SGWUICmd.Bits.data14
#define  MC33972Bit_SGWUICmd15        MC33972_SGWUICmd.Bits.data15





//设定SP引脚的Metallic Cmd
typedef union {
  byte  Byte;
  
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
}MC33972_SPMTLCCmd_Union;

extern  MC33972_SPMTLCCmd_Union  MC33972_SPMTLCCmd;

#define  MC33972Bit_SPMTLCCmdALL       MC33972_SPMTLCCmd.Byte
#define  MC33972Bit_SPMTLCCmd0         MC33972_SPMTLCCmd.Bits.data0
#define  MC33972Bit_SPMTLCCmd1         MC33972_SPMTLCCmd.Bits.data1
#define  MC33972Bit_SPMTLCCmd2         MC33972_SPMTLCCmd.Bits.data2
#define  MC33972Bit_SPMTLCCmd3         MC33972_SPMTLCCmd.Bits.data3
#define  MC33972Bit_SPMTLCCmd4         MC33972_SPMTLCCmd.Bits.data4
#define  MC33972Bit_SPMTLCCmd5         MC33972_SPMTLCCmd.Bits.data5
#define  MC33972Bit_SPMTLCCmd6         MC33972_SPMTLCCmd.Bits.data6
#define  MC33972Bit_SPMTLCCmd7         MC33972_SPMTLCCmd.Bits.data7



//设定SG引脚的Metallic Cmd
typedef union {

  word  Byte;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1; 
    
    byte data8      :1;
    byte data9      :1;
    byte data10     :1;
    byte data11     :1;
    byte data12     :1;
    byte data13     :1;
    byte data14     :1;
    byte data15     :1;    
  }Bits;
}MC33972_SGMTLCCmd_Union;

extern  MC33972_SGMTLCCmd_Union  MC33972_SGMTLCCmd;

#define  MC33972Bit_SGMTLCCmdALL       MC33972_SGMTLCCmd.Byte
#define  MC33972Bit_SGMTLCCmd0         MC33972_SGMTLCCmd.Bits.data0
#define  MC33972Bit_SGMTLCCmd1         MC33972_SGMTLCCmd.Bits.data1
#define  MC33972Bit_SGMTLCCmd2         MC33972_SGMTLCCmd.Bits.data2
#define  MC33972Bit_SGMTLCCmd3         MC33972_SGMTLCCmd.Bits.data3
#define  MC33972Bit_SGMTLCCmd4         MC33972_SGMTLCCmd.Bits.data4
#define  MC33972Bit_SGMTLCCmd5         MC33972_SGMTLCCmd.Bits.data5
#define  MC33972Bit_SGMTLCCmd6         MC33972_SGMTLCCmd.Bits.data6
#define  MC33972Bit_SGMTLCCmd7         MC33972_SGMTLCCmd.Bits.data7

#define  MC33972Bit_SGMTLCCmd8         MC33972_SGMTLCCmd.Bits.data8
#define  MC33972Bit_SGMTLCCmd9         MC33972_SGMTLCCmd.Bits.data9
#define  MC33972Bit_SGMTLCCmd10        MC33972_SGMTLCCmd.Bits.data10
#define  MC33972Bit_SGMTLCCmd11        MC33972_SGMTLCCmd.Bits.data11
#define  MC33972Bit_SGMTLCCmd12        MC33972_SGMTLCCmd.Bits.data12
#define  MC33972Bit_SGMTLCCmd13        MC33972_SGMTLCCmd.Bits.data13
#define  MC33972Bit_SGMTLCCmd14        MC33972_SGMTLCCmd.Bits.data14
#define  MC33972Bit_SGMTLCCmd15        MC33972_SGMTLCCmd.Bits.data15








//设定SP引脚的Wetting Current timer Cmd
typedef union {
  byte  Byte;
  
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
}MC33972_SPWCCmd_Union;

extern  MC33972_SPWCCmd_Union  MC33972_SPWCCmd;

#define  MC33972Bit_SPWCCmdALL       MC33972_SPWCCmd.Byte
#define  MC33972Bit_SPWCCmd0         MC33972_SPWCCmd.Bits.data0
#define  MC33972Bit_SPWCCmd1         MC33972_SPWCCmd.Bits.data1
#define  MC33972Bit_SPWCCmd2         MC33972_SPWCCmd.Bits.data2
#define  MC33972Bit_SPWCCmd3         MC33972_SPWCCmd.Bits.data3
#define  MC33972Bit_SPWCCmd4         MC33972_SPWCCmd.Bits.data4
#define  MC33972Bit_SPWCCmd5         MC33972_SPWCCmd.Bits.data5
#define  MC33972Bit_SPWCCmd6         MC33972_SPWCCmd.Bits.data6
#define  MC33972Bit_SPWCCmd7         MC33972_SPWCCmd.Bits.data7



//设定SG引脚的Wetting Current timer Cmd
typedef union {

  word  Byte;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1; 
    
    byte data8      :1;
    byte data9      :1;
    byte data10     :1;
    byte data11     :1;
    byte data12     :1;
    byte data13     :1;
    byte data14     :1;
    byte data15     :1;    
  }Bits;
}MC33972_SGWCCmd_Union;

extern  MC33972_SGWCCmd_Union  MC33972_SGWCCmd;

#define  MC33972Bit_SGWCCmdALL       MC33972_SGWCCmd.Byte
#define  MC33972Bit_SGWCCmd0         MC33972_SGWCCmd.Bits.data0
#define  MC33972Bit_SGWCCmd1         MC33972_SGWCCmd.Bits.data1
#define  MC33972Bit_SGWCCmd2         MC33972_SGWCCmd.Bits.data2
#define  MC33972Bit_SGWCCmd3         MC33972_SGWCCmd.Bits.data3
#define  MC33972Bit_SGWCCmd4         MC33972_SGWCCmd.Bits.data4
#define  MC33972Bit_SGWCCmd5         MC33972_SGWCCmd.Bits.data5
#define  MC33972Bit_SGWCCmd6         MC33972_SGWCCmd.Bits.data6
#define  MC33972Bit_SGWCCmd7         MC33972_SGWCCmd.Bits.data7

#define  MC33972Bit_SGWCCmd8         MC33972_SGWCCmd.Bits.data8
#define  MC33972Bit_SGWCCmd9         MC33972_SGWCCmd.Bits.data9
#define  MC33972Bit_SGWCCmd10        MC33972_SGWCCmd.Bits.data10
#define  MC33972Bit_SGWCCmd11        MC33972_SGWCCmd.Bits.data11
#define  MC33972Bit_SGWCCmd12        MC33972_SGWCCmd.Bits.data12
#define  MC33972Bit_SGWCCmd13        MC33972_SGWCCmd.Bits.data13
#define  MC33972Bit_SGWCCmd14        MC33972_SGWCCmd.Bits.data14
#define  MC33972Bit_SGWCCmd15        MC33972_SGWCCmd.Bits.data15




//TriSt
//设定SP引脚的TriState Cmd
typedef union {
  byte  Byte;
  
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
}MC33972_SPTriStCmd_Union;

extern  MC33972_SPTriStCmd_Union  MC33972_SPTriStCmd;

#define  MC33972Bit_SPTriStCmdALL       MC33972_SPTriStCmd.Byte
#define  MC33972Bit_SPTriStCmd0         MC33972_SPTriStCmd.Bits.data0
#define  MC33972Bit_SPTriStCmd1         MC33972_SPTriStCmd.Bits.data1
#define  MC33972Bit_SPTriStCmd2         MC33972_SPTriStCmd.Bits.data2
#define  MC33972Bit_SPTriStCmd3         MC33972_SPTriStCmd.Bits.data3
#define  MC33972Bit_SPTriStCmd4         MC33972_SPTriStCmd.Bits.data4
#define  MC33972Bit_SPTriStCmd5         MC33972_SPTriStCmd.Bits.data5
#define  MC33972Bit_SPTriStCmd6         MC33972_SPTriStCmd.Bits.data6
#define  MC33972Bit_SPTriStCmd7         MC33972_SPTriStCmd.Bits.data7



//设定SG引脚的TriState Cmd
typedef union {

  word  Byte;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1; 
    
    byte data8      :1;
    byte data9      :1;
    byte data10     :1;
    byte data11     :1;
    byte data12     :1;
    byte data13     :1;
    byte data14     :1;
    byte data15     :1;    
  }Bits;
}MC33972_SGTriStCmd_Union;

extern  MC33972_SGTriStCmd_Union  MC33972_SGTriStCmd;

#define  MC33972Bit_SGTriStCmdALL       MC33972_SGTriStCmd.Byte
#define  MC33972Bit_SGTriStCmd0         MC33972_SGTriStCmd.Bits.data0
#define  MC33972Bit_SGTriStCmd1         MC33972_SGTriStCmd.Bits.data1
#define  MC33972Bit_SGTriStCmd2         MC33972_SGTriStCmd.Bits.data2
#define  MC33972Bit_SGTriStCmd3         MC33972_SGTriStCmd.Bits.data3
#define  MC33972Bit_SGTriStCmd4         MC33972_SGTriStCmd.Bits.data4
#define  MC33972Bit_SGTriStCmd5         MC33972_SGTriStCmd.Bits.data5
#define  MC33972Bit_SGTriStCmd6         MC33972_SGTriStCmd.Bits.data6
#define  MC33972Bit_SGTriStCmd7         MC33972_SGTriStCmd.Bits.data7

#define  MC33972Bit_SGTriStCmd8         MC33972_SGTriStCmd.Bits.data8
#define  MC33972Bit_SGTriStCmd9         MC33972_SGTriStCmd.Bits.data9
#define  MC33972Bit_SGTriStCmd10        MC33972_SGTriStCmd.Bits.data10
#define  MC33972Bit_SGTriStCmd11        MC33972_SGTriStCmd.Bits.data11
#define  MC33972Bit_SGTriStCmd12        MC33972_SGTriStCmd.Bits.data12
#define  MC33972Bit_SGTriStCmd13        MC33972_SGTriStCmd.Bits.data13
#define  MC33972Bit_SGTriStCmd14        MC33972_SGTriStCmd.Bits.data14
#define  MC33972Bit_SGTriStCmd15        MC33972_SGTriStCmd.Bits.data15




//设定SPI回馈信号
typedef union {

  unsigned long  rxswst;
  
  struct {
    byte data0     :1;
    byte data1     :1;
    byte data2     :1;
    byte data3     :1;
    byte data4     :1;
    byte data5     :1;
    byte data6     :1;
    byte data7     :1; 
    
    byte data8      :1;
    byte data9      :1;
    byte data10     :1;
    byte data11     :1;
    byte data12     :1;
    byte data13     :1;
    byte data14     :1;
    byte data15     :1; 
    
    byte data16     :1;
    byte data17     :1;
    byte data18     :1;
    byte data19     :1;
    byte data20     :1;
    byte data21     :1;
    byte data22     :1;
    byte data23     :1;
    
    byte data24     :1;
    byte data25     :1;
    byte data26     :1;
    byte data27     :1;
    byte data28     :1;
    byte data29     :1;
    byte data30     :1;
    byte data31     :1;
            
  }Bits;
}MC33972_RxData_Union;

extern  MC33972_RxData_Union    MC33972_Rx;

#define  MC33972Bit_ALL         MC33972_Rx.rxswst
#define  MC33972Bit_SG0         MC33972_Rx.Bits.data0
#define  MC33972Bit_SG1         MC33972_Rx.Bits.data1
#define  MC33972Bit_SG2         MC33972_Rx.Bits.data2
#define  MC33972Bit_SG3         MC33972_Rx.Bits.data3
#define  MC33972Bit_SG4         MC33972_Rx.Bits.data4
#define  MC33972Bit_SG5         MC33972_Rx.Bits.data5
#define  MC33972Bit_SG6         MC33972_Rx.Bits.data6
#define  MC33972Bit_SG7         MC33972_Rx.Bits.data7

#define  MC33972Bit_SG8         MC33972_Rx.Bits.data8
#define  MC33972Bit_SG9         MC33972_Rx.Bits.data9
#define  MC33972Bit_SG10        MC33972_Rx.Bits.data10
#define  MC33972Bit_SG11        MC33972_Rx.Bits.data11
#define  MC33972Bit_SG12        MC33972_Rx.Bits.data12
#define  MC33972Bit_SG13        MC33972_Rx.Bits.data13
#define  MC33972Bit_SP0         MC33972_Rx.Bits.data14
#define  MC33972Bit_SP1         MC33972_Rx.Bits.data15


#define  MC33972Bit_SP2         MC33972_Rx.Bits.data16
#define  MC33972Bit_SP3         MC33972_Rx.Bits.data17
#define  MC33972Bit_SP4         MC33972_Rx.Bits.data18
#define  MC33972Bit_SP5         MC33972_Rx.Bits.data19
#define  MC33972Bit_SP6         MC33972_Rx.Bits.data20
#define  MC33972Bit_SP7         MC33972_Rx.Bits.data21
#define  MC33972Bit_IntFlag     MC33972_Rx.Bits.data22
#define  MC33972Bit_ThemFlag    MC33972_Rx.Bits.data23


#define  MC33972Bit_SP8         MC33972_Rx.Bits.data24
#define  MC33972Bit_SP9         MC33972_Rx.Bits.data25
#define  MC33972Bit_SP10        MC33972_Rx.Bits.data26
#define  MC33972Bit_SP11        MC33972_Rx.Bits.data27
#define  MC33972Bit_SP12        MC33972_Rx.Bits.data28
#define  MC33972Bit_SP13        MC33972_Rx.Bits.data29
#define  MC33972Bit_SP14        MC33972_Rx.Bits.data30
#define  MC33972Bit_SP15        MC33972_Rx.Bits.data31







#endif