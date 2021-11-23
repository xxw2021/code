#include   "Allh.h" 
  
CCP_DWORD ccpGetCalPage( void )
{
    return 0x5000;
}
 
void ccpSetCalPage( CCP_DWORD a )
{
    return ;
}
 
CCP_BYTE ccpFlashProgramm( CCP_BYTEPTR data, CCP_MTABYTEPTR a, CCP_BYTE size )
{
    return 0;
}

void ccpFlashClear( CCP_MTABYTEPTR a, CCP_DWORD size )
{
    return;
}

void ccpSend( uchar *msg )
{
    CAN_Msg_struct   L_numCCPMsgSTRUCT;
    //∑¢ÀÕID 0x18FF1803
    //Ω” ’ID 0x18FF1923
    L_numCCPMsgSTRUCT.m_id0 = 0x03;
    L_numCCPMsgSTRUCT.m_id1 = 0x18;
    L_numCCPMsgSTRUCT.m_id2 = 0xff;
    L_numCCPMsgSTRUCT.m_id3 = 0x18;
    L_numCCPMsgSTRUCT.m_data0 = *msg++;
    L_numCCPMsgSTRUCT.m_data1 = *msg++;
    L_numCCPMsgSTRUCT.m_data2 = *msg++;
    L_numCCPMsgSTRUCT.m_data3 = *msg++;
    L_numCCPMsgSTRUCT.m_data4 = *msg++;
    L_numCCPMsgSTRUCT.m_data5 = *msg++;
    L_numCCPMsgSTRUCT.m_data6 = *msg++;
    L_numCCPMsgSTRUCT.m_data7 = *msg++;
    L_numCCPMsgSTRUCT.m_datalength = 8;
    L_numCCPMsgSTRUCT.m_rtr  = 0;
    CAN4TransmitMsg(&L_numCCPMsgSTRUCT);
}


uchar * ccpGetPointer( uchar addr_ext, uint addr )       // get Pointer into
{                                                            // normal C
    return (MTABYTEPTR) addr;
}

void ccpUserBackground( void )
{

}

uchar ccpDisableNormalOperation( uchar * a, uint s )
{
    _asm("SEI");
    return 1;
}
