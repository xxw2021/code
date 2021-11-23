#include   "CAN_Init.h" 
#include   "CCPPAR.h" 
#include   "CCP.h" 
  
void CCP_DAQTask(void)
{           
    CAN_Msg_struct CANMsgS;
    CCP_BYTE Msg[8];

    if(CCP_GetOneDataFrame(Msg))
    {
        CANMsgS.m_data0  = Msg[0];
        CANMsgS.m_data1  = Msg[1];      
        CANMsgS.m_data2  = Msg[2];       
        CANMsgS.m_data3  = Msg[3];            
        CANMsgS.m_data4  = Msg[4];
        CANMsgS.m_data5  = Msg[5];                                          
        CANMsgS.m_data6  = Msg[6];
        CANMsgS.m_data7  = Msg[7]; 
           
        CANMsgS.m_datalength = 8;
        CANMsgS.m_rtr = 0;   //必须用扩展帧  
        //CANMsgS.IDUI = 0x18FF1803;
        CANMsgS.m_id0 = 0x03;
        CANMsgS.m_id1 = 0x18;
        CANMsgS.m_id2 = 0xff;
        CANMsgS.m_id3 = 0x18;
        CAN4TransmitMsg(&CANMsgS);      
    }
}

CCP_BYTEFARPTR  ccpGetPointer(CCP_BYTE pageReg , CCP_DWORD address)        
{                                                                
    CCP_DWORD   gAddrUL = 0;
    
    // 在此处要将逻辑地址转换为全局地址，用全局地址去寻址。
    if((address >= 0xc00)&&(address <= 0xfff))  // eeprom or buffer ram
    {
        gAddrUL = 0x13f000 | address;
    }
    else if((address >= 800)&&(address <= 0xbff))  // dflash or buffer ram
    {
        gAddrUL = (pageReg<<10)|(address & 0x3ff)|(0x100000); 
    }
    else if((address >= 0x2000)&&(address <= 0x3fff)) // unpaged ram
    {
        gAddrUL = 0xfc000 + address;
    }
    else if((address >= 0x4000)&&(address <= 0x7fff))  // unpaged flash1
    {
        gAddrUL = 0x7f0000 | address;
    }
    else if((address >= 0xc000)&&(address <= 0xffff))  // unpaged flash2
    {
        gAddrUL = 0x7f0000 | address;
    }
    else if((address >= 0x1000)&&(address <= 0x1fff)) // paged ram
    {
        gAddrUL = (pageReg<<12)|(address & 0xfff) ;
    }
    else if((address >= 0x8000)&&(address <= 0xbfff)) // paged flash
    {
        gAddrUL = (pageReg<<14)|(address & 0x3fff)|(0x400000); 
    }
    else
    {
        gAddrUL = address;    
    }

    return (CCP_BYTEFARPTR)gAddrUL;
}

uchar  ccpUnlock(uchar * a)
{
    return 1;
}

CCP_DWORD ccpGetSeed( CCP_BYTE resourceMask )
{
    return 0x12345678;
}