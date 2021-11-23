#include   "Allh.h" 

unsigned char CCPRun=0;

  
CCP_DWORD ccpGetCalPage( void )
{
    return 0x5000;
}
 
void ccpSetCalPage( CCP_DWORD a )
{
    
    return ;
}
 
CCP_BYTE ccpFlashProgramm( CCP_BYTEPTR data, CCP_BYTEPTR a, CCP_BYTE size )
{
    return 0;
}

void ccpFlashClear( CCP_BYTEPTR a, CCP_DWORD size )
{
    return;
}

void CCP_DAQTask(void)
{
    CAN_Msg_struct   L_numCCPMsgSTRUCT;
    CCP_BYTE Msg[8];
    
    CCPRun=1;
    
    if(CAN4TXMsgPossible())
    {
        if(CCP_GetOneDataFrame(Msg))
        {
            //发送ID 0x18FF1803
            //接收ID 0x18FF1923
            L_numCCPMsgSTRUCT.m_id0 = 0x03;
            L_numCCPMsgSTRUCT.m_id1 = 0x18;
            L_numCCPMsgSTRUCT.m_id2 = 0xff;
            L_numCCPMsgSTRUCT.m_id3 = 0x18;
            L_numCCPMsgSTRUCT.m_data0 = Msg[0];
            L_numCCPMsgSTRUCT.m_data1 = Msg[1];
            L_numCCPMsgSTRUCT.m_data2 = Msg[2];
            L_numCCPMsgSTRUCT.m_data3 = Msg[3];
            L_numCCPMsgSTRUCT.m_data4 = Msg[4];
            L_numCCPMsgSTRUCT.m_data5 = Msg[5];
            L_numCCPMsgSTRUCT.m_data6 = Msg[6];
            L_numCCPMsgSTRUCT.m_data7 = Msg[7];
            L_numCCPMsgSTRUCT.m_datalength = 8;
            L_numCCPMsgSTRUCT.m_rtr  = 0;
            CAN4TransmitMsg(&L_numCCPMsgSTRUCT);
        }
    }
}

CCP_BYTEFARPTR  ccpGetPointer(CCP_BYTE addr_ext , CCP_DWORD address)        
{                                                                
    CCP_DWORD   globalAddress;
    
    // 在此处要将逻辑地址转换为全局地址，用全局地址去寻址。
    if(((address >= 0x780000) && (address <= 0x79ffff)) ||
       ((address >= 0x7e0000) && (address <= 0x7fffff)))
    {
        globalAddress = address;    
    }
    else if((address >= 0x13f000) && (address <= 0x13ffff))
    {
        globalAddress = address; 
    }
    else if((address>=0x2000)&&(address<0x4000))
    {
        globalAddress = (CCP_DWORD)0xfe000 + address - (CCP_DWORD)0x2000;    
    }
    else if((address >= 0xfc000) && (address <= 0xfdfff))
    {
        globalAddress = address; 
    }
    else
    {
        globalAddress = 0;
    }
    
    return (CCP_BYTEFARPTR)globalAddress;
}

void ccpUserBackground( void )
{

}

uchar ccpDisableNormalOperation( uchar * a, uint s )
{
    _asm("SEI");
    return 1;
}

uchar  ccpUnlock(uchar * a)
{
  return 0;
}

CCP_DWORD ccpGetSeed( CCP_BYTE resourceMask )
{
  return 0;
}