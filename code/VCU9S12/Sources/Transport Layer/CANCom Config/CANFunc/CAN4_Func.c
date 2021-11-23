#include "Allh.h"

//MSCAN4实现CCP诊断等功能，设定波特率为500k

void   CAN4TransmitMsg(CAN_Msg_struct* TP_pMsg)
{
    
    unsigned char v_temp,v_temp2,v_temp3 , Luchar_numCAN4TransmitFlg;

    Luchar_numCAN4TransmitFlg=CAN4TFLG;
    CAN4TBSEL=Luchar_numCAN4TransmitFlg;
    Luchar_numCAN4TransmitFlg=CAN4TBSEL; 
    if(Luchar_numCAN4TransmitFlg != 0)
    {
        if(TP_pMsg->m_rtr == 1)
        {
            v_temp3 = 0x10;
        }
        else
        {
            v_temp3 = 0;
        }
        v_temp2 = TP_pMsg->m_id0;
        v_temp = v_temp2 & 0x80;
        v_temp >>= 7;                // save id7
        v_temp2 <<= 1;
        CAN4TXIDR3 = v_temp2 | v_temp3;
        
        v_temp2 = TP_pMsg->m_id1;
        v_temp3 = v_temp2 & 0x80;
        v_temp3 >>= 7;               // save id15
        v_temp2 <<= 1;
        CAN4TXIDR2 = v_temp2 | v_temp;
        
        v_temp = TP_pMsg->m_id2;
        v_temp >>= 5;
        v_temp2 = TP_pMsg->m_id3;
        v_temp2 <<= 3;
        CAN4TXIDR0 = v_temp2 | v_temp;
        
        v_temp = TP_pMsg->m_id2;
        v_temp2 = v_temp & 0x03;
        v_temp <<= 3;
        v_temp2 <<= 1;
        CAN4TXIDR1 = v_temp | 0x18 | v_temp2 | v_temp3 ;

        CAN4TXDSR0 = TP_pMsg->m_data0;
        CAN4TXDSR1 = TP_pMsg->m_data1;
        CAN4TXDSR2 = TP_pMsg->m_data2;
        CAN4TXDSR3 = TP_pMsg->m_data3;
        CAN4TXDSR4 = TP_pMsg->m_data4;
        CAN4TXDSR5 = TP_pMsg->m_data5;
        CAN4TXDSR6 = TP_pMsg->m_data6;
        CAN4TXDSR7 = TP_pMsg->m_data7; 
        CAN4TXDLR  = TP_pMsg->m_datalength;
        CAN4TFLG = Luchar_numCAN4TransmitFlg;
   }
    
}
 
unsigned char  CAN4TXMsgPossible(void)
{
    return CAN4TFLG; 
}
/********************************************************************/
// Description:
//    用于CAN4控制器的诊断，主要诊断CAN总线控制器、接收计数器及接收缓
// 冲计数器，当发现控制器异常及接收计数器异常时立即报告错误，接收缓冲
// 计数器异常时，报告总线负载过重错误
/********************************************************************/
void   CAN4Diagnostic(void)
{

}




#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt 54 void MSCAN4_Receive_ISR(void)
{  
    UCHAR8  l_id = 0 , l_temp1 = 0 , l_temp2 = 0; 
	  UCHAR8  m_id0 , m_id1 , m_id2 , m_id3;
		ULONG32  m_id = 0;
    UCHAR8 CAN_sVuchar_numCAN4RcvDataBuf_CUR[8];
 
    l_id = CAN4RXIDR2&0x01;
    l_temp1 = l_id << 7;
    l_temp2 = CAN4RXIDR3 >> 1;
    m_id0 = l_temp2 | l_temp1;
    l_id = CAN4RXIDR1&0x01;
    
    l_temp1 = l_id << 7;
    l_temp2 = CAN4RXIDR2 >> 1;
    m_id1 = l_temp2 | l_temp1;
    l_id = CAN4RXIDR1&0xe0;
    l_temp1 = l_id >> 3;
    l_id = (CAN4RXIDR1 >>1)&0x03;
    l_temp2 = l_id | l_temp1;
    l_id = CAN4RXIDR0 & 0x07;
    l_temp1 = l_id << 5;
    m_id2 = l_temp2 | l_temp1;
    m_id3 = CAN4RXIDR0 >> 3;
  	m_id = ((ULONG32)m_id3<<24)+((ULONG32)m_id2<<16)+((ULONG32)m_id1<<8)+((ULONG32)m_id0);
  			
    if((m_id == CCP_CRO_ID)||(m_id == 0)||(m_id == 256))
    {
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[0] =  CAN4RXDSR0;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[1] =  CAN4RXDSR1;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[2] =  CAN4RXDSR2;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[3] =  CAN4RXDSR3;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[4] =  CAN4RXDSR4;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[5] =  CAN4RXDSR5;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[6] =  CAN4RXDSR6;
        CAN_sVuchar_numCAN4RcvDataBuf_CUR[7] =  CAN4RXDSR7;
        ccpCommand(CAN_sVuchar_numCAN4RcvDataBuf_CUR);
    }//
    else//
    {
      //
    }//
    CAN4RFLG_RXF = 1;   //清除接收中断标志位
}
#pragma CODE_SEG DEFAULT  






