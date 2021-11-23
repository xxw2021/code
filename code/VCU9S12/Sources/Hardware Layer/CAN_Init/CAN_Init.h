#ifndef CAN_INIT_H
#define CAN_INIT_H





#define   MACRO_MSCAN_BufSIZE   16




typedef struct can_msg
{
  //
  unsigned char m_id0;
  unsigned char m_id1;
  unsigned char m_id2;
  unsigned char m_id3;
  unsigned char m_data0;
  unsigned char m_data1;
  unsigned char m_data2;
  unsigned char m_data3;
  unsigned char m_data4;
  unsigned char m_data5;
  unsigned char m_data6;
  unsigned char m_data7;
  unsigned char m_datalength;
  unsigned char m_rtr;
}CAN_Msg_struct;

typedef struct
{
  //
  CAN_Msg_struct m_msg[MACRO_MSCAN_BufSIZE];
  unsigned char m_PWriteFIFO;
  unsigned char m_PReadFIFO;
}CAN_MsgBuf_struct;
  


void MSCAN_Init(void); //����MSCANHardwareInit() ��MSCANDataInit()
void MSCANHardwareInit(void);    //����MSCAN0Init()   MSCAN1Init()   MSCAN4Init()
void MSCANDataInit(void);       //�����Ĵ����ȵĳ�ʼ��
void MSCAN_ChConfig(void);
void MSCAN0_Init(void);
void MSCAN1_Init(void);
void MSCAN4_Init(void);


#endif