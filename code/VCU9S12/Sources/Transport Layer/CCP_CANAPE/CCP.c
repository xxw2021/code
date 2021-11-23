#include "ccp.h"
//APE
 
CCP_BYTE ccpStationId[] = CCP_STATION_ID;


#pragma DATA_SEG __GPAGE_SEG PAGED_RAM

struct ccp ccp;
CCP_MsgTBuf_struct CCP_TMsgBuf;

#pragma DATA_SEG DEFAULT


/*--------------------------------------------------------------------------*/
/* Initialization */
/*--------------------------------------------------------------------------*/

void ccpInit( void ) 
{
    CCP_BYTEPTR p;
    CCP_BYTEPTR pl;
    
    CCP_TMsgBuf.m_PWriteFIFO = 0;
    CCP_TMsgBuf.m_PReadFIFO = 0;
    p = (CCP_BYTEPTR)&ccp;
    pl = p+sizeof(ccp);
    while (p<pl) *p++ = 0;
    
}

CCP_BYTE   CCP_TransOneDataFrame(CCP_BYTEFARPTR msg)
{
    CCP_BYTE   l_selectchannel , l_return ;

    if(((CCP_TMsgBuf.m_PWriteFIFO+1)%CCP_SEND_QUEUE_SIZE) != CCP_TMsgBuf.m_PReadFIFO)  
    {    
        l_selectchannel = CCP_TMsgBuf.m_PWriteFIFO;
        CCP_TMsgBuf.m_msg[l_selectchannel][0] = msg[0];
        CCP_TMsgBuf.m_msg[l_selectchannel][1] = msg[1];
        CCP_TMsgBuf.m_msg[l_selectchannel][2] = msg[2];
        CCP_TMsgBuf.m_msg[l_selectchannel][3] = msg[3];
        CCP_TMsgBuf.m_msg[l_selectchannel][4] = msg[4];
        CCP_TMsgBuf.m_msg[l_selectchannel][5] = msg[5];
        CCP_TMsgBuf.m_msg[l_selectchannel][6] = msg[6];
        CCP_TMsgBuf.m_msg[l_selectchannel][7] = msg[7];
        CCP_TMsgBuf.m_PWriteFIFO = (CCP_BYTE)((CCP_TMsgBuf.m_PWriteFIFO+1)%((CCP_BYTE)CCP_SEND_QUEUE_SIZE));
        l_return = 1;  
    }
    else   // CCP���ͻ���������CCP��Ҫ������������
    {
        l_return = 0;          
    }
    return  l_return;
}

CCP_BYTE   CCP_GetOneDataFrame(CCP_BYTE msg[8])
{
    CCP_BYTE  L_readFifo , L_return = 0;
    
    if(CCP_TMsgBuf.m_PWriteFIFO != CCP_TMsgBuf.m_PReadFIFO)
    {
        L_readFifo =  CCP_TMsgBuf.m_PReadFIFO;  
        msg[0] = CCP_TMsgBuf.m_msg[L_readFifo][0];
        msg[1] = CCP_TMsgBuf.m_msg[L_readFifo][1];
        msg[2] = CCP_TMsgBuf.m_msg[L_readFifo][2];
        msg[3] = CCP_TMsgBuf.m_msg[L_readFifo][3];
        msg[4] = CCP_TMsgBuf.m_msg[L_readFifo][4];
        msg[5] = CCP_TMsgBuf.m_msg[L_readFifo][5];
        msg[6] = CCP_TMsgBuf.m_msg[L_readFifo][6];
        msg[7] = CCP_TMsgBuf.m_msg[L_readFifo][7];
        CCP_TMsgBuf.m_PReadFIFO = (CCP_BYTE)((CCP_TMsgBuf.m_PReadFIFO + 1)%((CCP_BYTE)CCP_SEND_QUEUE_SIZE));
        L_return = 1;  
    }
    else
    {
        L_return = 0;   
    }
    
    return  L_return;
}

void ccpSendCrm( void ) 
{
    CCP_TransOneDataFrame(ccp.Crm);
}


void   ccpSetMTA(CCP_BYTE  MtaNum , CCP_BYTEFARPTR addrPtr)
{
    ccp.MTA[MtaNum] = addrPtr;
}
CCP_BYTE ccpWriteMTA(CCP_BYTE MtaNum, CCP_BYTE size, CCP_BYTEFARPTR d ) 
{
    /* EEPROM write access */
    #ifdef CCP_WRITE_EEPROM

    CCP_BYTE r = ccpCheckWriteEEPROM(ccp.MTA[MtaNum],size,d);
    if (r) 
    { 
        ccp.MTA[MtaNum] += size;
        return r;
    }

    #endif

    /* Checked ram memory write access */
    #ifdef CCP_WRITE_PROTECTION

    if (!ccpCheckWriteAccess(ccp.MTA[MtaNum],size)) 
    {
        ccp.MTA[MtaNum] += size;
        return CCP_WRITE_DENIED;
    }

    #endif

    while(size-->0) 
    {
        *(ccp.MTA[MtaNum]) = *d;
        ccp.MTA[MtaNum]++;
        d++;
    }
    return CCP_WRITE_OK;
}

/* Read n bytes */
void ccpReadMTA( CCP_BYTE n, CCP_BYTE size, CCP_BYTEFARPTR d ) 
{
    #ifdef CCP_READ_EEPROM
    
    if (ccpCheckReadEEPROM(ccp.MTA[n],size,d)) 
    {
        ccp.MTA[n] += size;
        return;
    }
    
    #endif
    
    while (size-->0) 
    {
        *d = *(ccp.MTA[n]);
        d++;
        ccp.MTA[n]++;
    }
}

CCP_BYTE ccpClearDaqList( CCP_BYTE daq ) 
{
    CCP_BYTEPTR p;
    CCP_BYTEPTR pl;

    if (daq>=CCP_MAX_DAQ) return 0;
    p = (CCP_BYTEPTR)&ccp.DaqList[daq];
    pl = p+sizeof(ccpDaqList_t);
    while (p<pl) *p++ = 0;
    ccp.SessionStatus |= SS_DAQ;
    return CCP_MAX_ODT;
}

/* Prepare DAQ */
CCP_BYTE ccpPrepareDaq(  CCP_BYTE daq, CCP_BYTE last, CCP_BYTE eventChannel, CCP_WORD prescaler ) 
{
    if (daq>=CCP_MAX_DAQ) return 0;
    ccp.DaqList[daq].eventChannel = eventChannel;
    if (prescaler==0) prescaler = 1;
    ccp.DaqList[daq].prescaler = prescaler;
    ccp.DaqList[daq].cycle = 1;
    ccp.DaqList[daq].last = last;
    ccp.DaqList[daq].flags = DAQ_FLAG_PREPARED;
    return 1;
}

/* Start DAQ */
CCP_BYTE ccpStartDaq( CCP_BYTE daq ) 
{
    if (daq>=CCP_MAX_DAQ) return 0;
    ccp.DaqList[daq].flags = DAQ_FLAG_START;
    ccp.SessionStatus |= SS_RUN;

    return 1;
}

/* Start all prepared DAQs */
void ccpStartAllPreparedDaq(void) 
{
    CCP_BYTE q;

    for (q=0;q<CCP_MAX_DAQ;q++) 
    {
        if (ccp.DaqList[q].flags==DAQ_FLAG_PREPARED) ccp.DaqList[q].flags = DAQ_FLAG_START;
    }
    ccp.SessionStatus |= SS_RUN;
  
}

void ccpStopDaq ( CCP_BYTE daq ) 
{
    CCP_BYTE i;

    if (daq>=CCP_MAX_DAQ) return;
    ccp.DaqList[daq].flags = 0;

    for (i=0;i<CCP_MAX_DAQ;i++) 
    {
        if (ccp.DaqList[i].flags&DAQ_FLAG_START) return;
    }

    ccp.SessionStatus &= ~SS_RUN;
}

/* Stop all DAQs */
void ccpStopAllDaq( void ) 
{
    CCP_BYTE q;

    for (q=0;q<CCP_MAX_DAQ;q++) ccp.DaqList[q].flags = 0;
    ccp.SessionStatus &= ~SS_RUN;
}


CCP_BYTE  ccpSampleAndTransmitDtm( CCP_BYTE pid, CCP_BYTE daq, CCP_BYTE odt ) 
{ 
    CCP_BYTE dtm[8];
    CCP_BYTEFARPTR p;
    CCP_BYTE s;
    CCP_BYTE *d,*dl;
    ccpOdtEntry_t *e,*el;

    dtm[0] = pid;
    e = &ccp.DaqList[daq].odt[odt][0];
    el = e+8;
    d = &dtm[1];
    dl = d+7;
    while (d<dl && e<el && e->ptr) 
    {
        p = e->ptr;
        s = e->siz;  
        if (s==4) 
        {
          *(CCP_DWORD*)d = *(CCP_DWORDPTR)p;
        }
        else if (s==2) 
        {
          *(CCP_WORD*)d = *(CCP_WORDPTR)p;
        } 
        else 
        {
          *d = *p;
        }
        d += s;
        e++;
    }
    return CCP_TransOneDataFrame(dtm);
    
}

void ccpDaq( CCP_BYTE eventChannel )
{
    CCP_BYTE q,o;
    CCP_BYTE j;
    if (!(ccp.SessionStatus&SS_RUN)) return;
    for (o=0,q=0; q<CCP_MAX_DAQ; o+=CCP_MAX_ODT,q++) 
    {
        if (!(ccp.DaqList[q].flags&DAQ_FLAG_START)) continue;
        if (ccp.DaqList[q].eventChannel!=eventChannel) continue;
        for (j=0;j<=ccp.DaqList[q].last;j++) 
        {
            ccpSampleAndTransmitDtm((o+j),q,j);
        }  
    }
}

/*--------------------------------------------------------------------------*/
/* Command Processor */
/*--------------------------------------------------------------------------*/
/********************************************************************/
// Description:
//    �ú������ڴ���CCP CONNECT����
//
// ��������CRO����
// byte    description  
//  0      ������ 0x01
//  1      �������������ֵ
//  2~3    CCPվ��ַ( intel��ʽ )
//  4~7    δ����      
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    δ����
/********************************************************************/
void  CCP_ConnectCmdPro(CCP_BYTE com[8])
{
    CCP_WORD stationAddr = com[2];
    
    stationAddr <<= 8;
    stationAddr += com[3];  
    if (stationAddr==CCP_STATION_ADDR||stationAddr==CCP_BROADCAST_STATION_ADDR) 
    { 
        if (!(ccp.SessionStatus&SS_TMP_DISCONNECTED)) 
        {
            ccpStopAllDaq();
            ccp.SendStatus = 0; /* Clear all transmission flags */
        }
        ccp.SessionStatus |= SS_CONNECTED;
        ccp.SessionStatus &= ~SS_TMP_DISCONNECTED;
        ccp.Crm[0] = 0xFF;
        ccp.Crm[1] = CRC_OK;
        ccp.Crm[2] = com[1];
        ccp.Crm[3] = 0xFE;
        *(CCP_WORD*)&ccp.Crm[4] = CCP_STATION_ADDR;
        *(CCP_WORD*)&ccp.Crm[6] = CCP_BROADCAST_STATION_ADDR;
    }
    else 
    {
        if (ccp.SessionStatus&SS_CONNECTED) 
        {
            ccp.SessionStatus &= ~SS_CONNECTED;
            ccp.SessionStatus |= SS_TMP_DISCONNECTED;
        }
    }
}

void  CCP_TestCmdPro(CCP_BYTE com[8])
{  
    CCP_WORD stationAddr = com[2];
    
    stationAddr <<= 8;
    stationAddr += com[3];  
    if (stationAddr==CCP_STATION_ADDR||stationAddr==CCP_BROADCAST_STATION_ADDR) 
    { 
        ccp.Crm[0] = 0xFF;
        ccp.Crm[1] = CRC_OK;
        ccp.Crm[2] = com[1];
        ccp.Crm[3] = 0xFE;
        *(CCP_WORD*)&ccp.Crm[4] = CCP_STATION_ADDR;
        *(CCP_WORD*)&ccp.Crm[6] = CCP_BROADCAST_STATION_ADDR;
    }
    else 
    {
        if (ccp.SessionStatus&SS_CONNECTED) 
        {
            ccp.SessionStatus &= ~SS_CONNECTED;
            ccp.SessionStatus |= SS_TMP_DISCONNECTED;
        }
    }
}

void  CCP_DisconnectCmdPro(CCP_BYTE com[8])
{ 
    CCP_BYTE   ccpDisconnectCmdType = com[2];
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.SessionStatus &= ~SS_CONNECTED;
    if (ccpDisconnectCmdType==0x00) 
    { 
        ccp.SessionStatus |= SS_TMP_DISCONNECTED;
    } 
    else 
    {           
        ccpStopAllDaq();
        ccp.ProtectionStatus = 0;  
    }         
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP SET_MTA����
//
// ��������CRO����
// byte    description  
//  0      ������ 0x02
//  1      �������������ֵ
//  2      MTA0 ��������DNLOAD, UPLOAD, DNLOAD_6 , SELECT_CAL_PAGE,
//         CLEAR_MEMORY PROGRAM and PROGRAM_6�� MTA1��������MOVE
//  3      ��ַ��չ
//  4~7    ��ַ�� unsigned long ��
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
/********************************************************************/
void   CCP_SetMtaCmdPro(CCP_BYTE com[8])
{
    CCP_BYTE   mtaType = com[2];
    CCP_DWORD  address = (*(CCP_DWORD*)&com[4]);
    CCP_BYTE   addressExt = com[3];
  
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    if (mtaType<CCP_MAX_MTA-1) 
    {
        ccpSetMTA(mtaType , ccpGetPointer(addressExt,address));
    } 
    else 
    {
        ccp.Crm[1] = CRC_OUT_OF_RANGE;
    }
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP EXCHANGE_ID���������ִ�н���������������
// ������������UPLOAD����Ҫ��ӻ��ϴ�����ID����ˣ�ִ��EXCHANGE_ID����
// �󣬴ӻ��Զ����趨MTA0ָ��ָ��ӻ�ID�Ĵ洢��ַ��
//
// ��������CRO����
// byte    description  
//  0      ������ 0x17
//  1      �������������ֵ
//  2~7    CCP����ID��Ϣ
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      �ӻ�ID���ֽ���Ŀ 
//  4      ��ѡ��ض��� 
//  5      Resource Availability Mask
//  6      Resource Protection Mask 
//
// ע��
//      Bit 7  6  5 4 3 2  1   0
//          x PGM x x x x DAQ CAL
// ECU �ڲ�����Դ�Ƿ������CCP���б궨���ɼ�����ͨ�����ֽ��еĶ���λ��������
// Resource Availability Mask:
// 1��   ��CALλΪ1ʱ������ECU���Ա��궨
// 2��   ��DAQλΪ1ʱ������λ�����Բɼ���ǰECU�ڲ�������
// Resource Protection Mask:
// 3��   ��PGMλΪ1ʱ�������Զ�ECU���ڴ���б��   
/********************************************************************/
void   CCP_ExchangeidCmdPro(CCP_BYTE com[8])
{
    CCP_BYTE i;
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];

    for(i=0;ccpStationId[i]!=0;i++) ;
    
    ccp.Crm[3] = i;      /* Lenght of slave device identifier */
    ccp.Crm[4] = 0;
    ccp.Crm[5] = PL_CAL; /* Default: Calibration available */
    ccp.Crm[6] = 0;      /* Default: No Protection */
    
    #ifdef CCP_SEED_KEY
    
    ccp.Crm[6] |= PL_CAL;   /* Protected Calibration */
    
    #endif
   
    ccp.Crm[5] |= PL_DAQ;     /* Data Acquisition */
    
    #ifdef CCP_SEED_KEY 
      ccp.Crm[6] |= PL_DAQ;   /* Protected Data Acquisition */
    #endif
 
    #if defined(CCP_PROGRAM)||defined(CCP_BOOTLOADER_DOWNLOAD)  
      ccp.Crm[5] |= PL_PGM;     /* Flash Programming */
      #ifdef CCP_SEED_KEY
        ccp.Crm[6] |= PL_PGM;   /* Protected Flash Programming */
      #endif  
    #endif
    
    ccp.Crm[7] = CCP_DRIVER_VERSION; /* Driver version number */
    ccpSetMTA(0,(CCP_BYTEFARPTR)ccpStationId);  
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP DNLOAD������궨�������ص�ECU�ڲ�RAM�У�
// ִ�и�����ǰ������ִ��SET_MTA����趨Ҫд������ݵ�RAM�׵�ַ
// ����ִ�к���뷵�� MTA0 address (after post-increment)
//
// ��������CRO����
// byte    description  
//  0      ������ 0x02
//  1      �������������ֵ
//  2      ����������������ֽ���Ŀ--���5���ֽ�
//  3      ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      д�����ݺ����չ��ַ after post-increment 
//  4~7    д�����ݺ�ĵ�ַָ�� after post-increment 
//
// ע�⣺
//    �ú�����û�а��ձ�׼����DTO����Ҫ����ccpWriteMTA�����ķ���ֵ
// ��ȷ��DTO
/********************************************************************/
void   CCP_DNLoadCmdPro(CCP_BYTE com[8])
{ 
    CCP_BYTE returnVal , sizeofData;
    sizeofData = com[2];
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
      
    #ifdef CCP_SEED_KEY
    if (!(ccp.ProtectionStatus&PL_CAL)) 
    {
        ccp.Crm[1] = CRC_ACCESS_DENIED;
        r = 0;
    }
    #endif
    
    returnVal = ccpWriteMTA(0,sizeofData,&com[3]);
    
    if (returnVal==CCP_WRITE_PENDING) 
        return;  
    if (returnVal==CCP_WRITE_DENIED||returnVal==CCP_WRITE_ERROR) 
        ccp.Crm[1] = CRC_ACCESS_DENIED;       
          
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP DNLOAD6��������ֽڵ����ݽ�����������MTA0Ϊ
// ��ʼ��ַ���ڴ浥Ԫ��ȥ��ʹ��DNLOAD_6����ǰ���봫��SET_MTA��������
// ִ�н�����MTA0ָ������Ϊ6������ִ�к���뷵�� MTA0 address 
// (after post-increment)
//
// ��������CRO����
// byte    description  
//  0      ������ 0x02
//  1      �������������ֵ
//  2      ���ݣ�6���ֽ�
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      д�����ݺ����չ��ַ after post-increment 
//  4~7    д�����ݺ�ĵ�ַָ�� after post-increment 
//
// ע�⣺
//    �ú�����û�а��ձ�׼����DTO����Ҫ����ccpWriteMTA�����ķ���ֵ
// ��ȷ��DTO
/********************************************************************/
void   CCP_DNLoad6CmdPro(CCP_BYTE com[8])
{
    CCP_BYTE returnVal;
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
      if (!(ccp.ProtectionStatus&PL_CAL)) 
      {
        ccp.Crm[1] = CRC_ACCESS_DENIED;
        r = 0;
      }
    #endif
    
    returnVal = ccpWriteMTA(0,6,(CCP_BYTEFARPTR)&com[2]);

    if (returnVal==CCP_WRITE_PENDING) 
        return;  
    if (returnVal==CCP_WRITE_DENIED||returnVal==CCP_WRITE_ERROR) 
        ccp.Crm[1] = CRC_ACCESS_DENIED; 
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP UPLOAD������������λ���ϴ�һ���ֽ���Ŀ��
// ���ݣ�ʹ��UPLOAD����ǰ���봫��SET_MTA�����趨MTA0��ַ�����������
// MTA0ָ������Ϊ�ϴ����ֽ���Ŀ������ִ�к���뷵�� MTA0 address 
// (after post-increment)
//
// ��������CRO����
// byte    description  
//  0      ������ 0x04
//  1      �������������ֵ
//  2      ��Ҫ�ϴ�������BLOCK�ֽ���Ŀ
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      д�����ݺ����չ��ַ after post-increment 
//  4~7    д�����ݺ�ĵ�ַָ�� after post-increment 
//
// ע�⣺
//    �ú�����û�а��ձ�׼����DTO��
/********************************************************************/
void   CCP_UPLoadCmdPro(CCP_BYTE com[8])
{
    CCP_BYTE sizeofBytes = com[2];
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccpReadMTA(0,sizeofBytes,&ccp.Crm[3]);
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP SHORT_UP����������1~5���ֽڵ����ݵ���λ��
// �������а������ϴ����ݵ��׵�ַ������ִ�н�����MTA0��ֵ���䡣
//
// ��������CRO����
// byte    description  
//  0      ������ 0x0F
//  1      �������������ֵ
//  2      ��Ҫ�ϴ�������BLOCK�ֽ���Ŀ
//  3      ���ϴ����ݵĵ�ַ��չ
// 4~7     ���ϴ����ݵĵ�ַ�� unsigned long ��
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    ���ϴ�����������
//
// ע�⣺
/********************************************************************/
void   CCP_ShortUPLoadCmdPro(CCP_BYTE com[8])
{
    #define size    com[2]
    #define addrExt com[3]
    #define addr    (*(CCP_DWORD*)&com[4])
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccpSetMTA(CCP_INTERNAL_MTA,ccpGetPointer(addrExt,addr));
    ccpReadMTA(CCP_INTERNAL_MTA,size,&ccp.Crm[3]);
    

    #undef size
    #undef addrExt
    #undef addr
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP GET_DAQ_SIZE���������Ҫ����λ����������ָ��
// ��DAQ list�б��а�����ODT��Ŀ���ӻ����DAQ List�б��е����ݡ������
// ��ָ����DAQ List�б�Ų����ã���ô�ӻ����ص�ODT��ĿΪ0������ECUͬʱ
// �궨ʱ�����������ָ����ͬECU��DTO��CAN����ID.
//
// ��������CRO����
// byte    description  
//  0      ������ 0x14
//  1      �������������ֵ
//  2      DAQ List�б��
//  3      δʹ��
// 4~7     DTO CAN����ID
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      ��DAQ List��ODT����Ŀ
//  4      ��DAQ List�е�һ��ODT��PID��     
//
// ע�⣺
/********************************************************************/
void   CCP_GetDaqSizeCmdPro(CCP_BYTE com[8])
{
    #define daqList com[2]
    #define daqId   (*(CCP_DWORD*)&com[4])

    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccpStopDaq(daqList); /* Stop this daq list */
    ccp.Crm[3] = ccpClearDaqList(daqList); /* Number of  ODTs */
    ccp.Crm[4] = daqList*CCP_MAX_ODT; /* PID of the first ODT */

    #undef daqList
    #undef daqId
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP SET_DAQ_PTR��������������趨DAQ List�б�
// ָ�룬ΪWRITE_DAQ������׼��������ִ�н����󣬵�ǰDAQ_LIST_POINTER
// ָ��ָ��ָ����DAQ List�б���ODT�е�ָ��Ԫ�ء�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x15
//  1      �������������ֵ
//  2      ָ��DAQ List�б��
//  3      ָ����DAQ List�б���ODT��
//  4      ָ����ODT���е�Ԫ�غ�
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    ûʹ��    
//
// ע�⣺
/********************************************************************/
void   CCP_SetDaqPtrCmdPro(CCP_BYTE com[8])
{
    #define comDaq  com[2]
    #define comOdt  com[3]
    #define comIdx  com[4]
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    if (comDaq>=CCP_MAX_DAQ||comOdt>=CCP_MAX_ODT||comIdx>7) 
    {
        ccp.Crm[1] = CRC_CMD_SYNTAX;
        ccp.DaqListPtr = 0;
    } 
    else 
    {
        ccp.DaqListPtr = &ccp.DaqList[comDaq].odt[comOdt][comIdx];
    }


    #undef comDaq
    #undef comOdt
    #undef comIdx
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP WRITE_DAQ����������SET_DAQ_PTR������������
// ��ʼ��ECU�ڲ���DAQ List�б�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x16
//  1      �������������ֵ
//  2      Size of DAQ element in bytes�����������������ֽ���Ŀ�� 
//  3      Address extension of DAQ element(��������������չ��ַ)   
//  4~7    Address of DAQ element(�����������ĵ�ַ)   
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    ûʹ��    
//
// ע�⣺
/********************************************************************/
void   CCP_WriteDaqCmdPro(CCP_BYTE com[8])
{
    #define writeDaqSize    com[2]
    #define writeDaqAddrExt com[3]
    #define writeDaqAddr    (*(CCP_DWORD*)&com[4])
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    if ((writeDaqSize!=1&&writeDaqSize!=2&&writeDaqSize!=4)|| ccp.DaqListPtr==0) 
    {
        ccp.Crm[1] = CRC_CMD_SYNTAX;
    }
    else 
    {
        ccp.DaqListPtr->ptr = (CCP_BYTEFARPTR)ccpGetPointer(writeDaqAddrExt,writeDaqAddr);
        ccp.DaqListPtr->siz = writeDaqSize;
    }


    #undef writeDaqSize
    #undef writeDaqAddrExt
    #undef writeDaqAddr          
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP START_STOP���������ָ��DAQ List�б��е�
// 0~Last ODT number�ŵ�����ODT�����趨��ָ����MODE״̬��
//
// ��������CRO����
// byte    description  
//  0      ������ 0x06
//  1      �������������ֵ
//  2      Mode : 0x01 start/0x00 stop/0x02 prepare data tranmission 
//  3      DAQ list number  
//  4      Last ODT number 
//  5      Event Channel No.
//  6~7    Transmission rate prescaler
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    ûʹ��    
//
// ע�⣺
/********************************************************************/
void   CCP_StartStopCmdPro(CCP_BYTE com[8])
{

    #define ssCmd                 com[2]  /* Start or Stop */
    #define ssDaq                 com[3]  /* DAQ list */
    #define ssLast                com[4]  /* Last ODT to send */
    #define ssEventChannel        com[5]  /* Event Channel Number */
    #define ssPrescaler (*(CCP_WORD*)&com[6]) /* Prescaler */

    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
      if (!(ccp.ProtectionStatus&PL_DAQ))
        ccp.Crm[1] = CRC_ACCESS_DENIED;
    #endif
    
    if (!(ccp.SessionStatus&SS_DAQ)) 
    { 
        ccp.Crm[1] = CRC_DAQ_INIT_REQUEST;
    }
    else 
    {
        switch (ssCmd) 
        {
            case 0: /* stop */
              ccpStopDaq(ssDaq);
              break;
            case 1: /* start */
              ccpPrepareDaq(ssDaq,ssLast,ssEventChannel,ssPrescaler);
              ccpStartDaq(ssDaq);
              break;
            case 2: /* prepare */
              ccpPrepareDaq(ssDaq,ssLast,ssEventChannel,ssPrescaler);
              break;
            default:
              ccp.Crm[1] = CRC_CMD_SYNTAX;
              break;
        }
    }
    
    #undef ssCmd
    #undef ssDaq
    #undef ssLast
    #undef ssEventChannel
    #undef ssPrescaler
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP START_STOP_ALL��������������������е�DAQ�б�
// ���вɼ�����ЩDAQ�б��ڸ�����֮ǰ�Ѿ���START_STOP��������Ϊ prepared 
// to start״̬��ͬʱ���������ֹͣ��ǰ�Ѿ���׼������������DAQ�б�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x08
//  1      �������������ֵ
//  2      Mode : 0x00 stops, 0x01 starts data transmission
//  3~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    δ���� 
//
// ע�⣺
/********************************************************************/
void   CCP_StartStopAllCmdPro(CCP_BYTE com[8])
{
    #define ssCmd                 com[2]  /* Start or Stop */

    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
      if (!(ccp.ProtectionStatus&PL_DAQ))
        ccp.Crm[1] = CRC_ACCESS_DENIED;
    #endif
    
    if (!(ccp.SessionStatus&SS_DAQ)) 
    { /* Not initialized */
     ccp.Crm[1] = CRC_DAQ_INIT_REQUEST;
    } 
    else 
    {
        switch (ssCmd) 
        {
            case 0: /* Stop */
              ccpStopAllDaq();
              break;
            case 1: /* Start */
              ccpStartAllPreparedDaq();
              break;
            default:
              ccp.Crm[1] = CRC_CMD_SYNTAX;
              break;
        }
    }
    
    #undef ssCmd
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP SET_S_STATUS���
//
// ��������CRO����
// byte    description  
//  0      ������ 0x0c
//  1      �������������ֵ
//  2      Session status bits
//  3~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    δ���� 
//
// ע��
// Bit 7    6    5   4   3    2     1   0
//    RUN STORE res res res RESUME DAQ CAL
//
// bit 0 CAL Calibration data initialized
// bit 1 DAQ DAQ list(s) initialized
// bit 2 RESUME Request to save DAQ setup during shutdown in ECU.
//       ECU automatically restarts DAQ after startup.
// bit 6 STORE Request to save calibration data during shut-down in ECU
// Bit 7 RUN Session in progress
// bit 3..5 res reserved
/********************************************************************/
void   CCP_SetSessionStatusCmdPro(CCP_BYTE com[8])
{
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.SessionStatus &= ~(SS_STORE|SS_RESUME);
    ccp.SessionStatus |= (com[2]&(SS_STORE|SS_RESUME));
    ccp.UserSessionStatus = com[2];
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP GET_S_STATUS���������ȡ��ǰ�ӻ��ı궨״̬
//
// ��������CRO����
// byte    description  
//  0      ������ 0x0d
//  1      �������������ֵ
//  2~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      Session status
//  4      additional status information qualifier
//  5      additional status information (optional)
//  6~7    δ����      
//
// ע��
//    ����ֽ�5Ϊ�㣬��ô�ֽ�4û�����塣�����Ϊ�㣬��ô�ֽ�4��������
// �û��Զ��壬CCP��׼Э�鲻�������������ֽڵĽ��͡�
/********************************************************************/
void   CCP_GetSessionStatusCmdPro(CCP_BYTE com[8])
{
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.Crm[3] = ccp.UserSessionStatus;
    ccp.Crm[4] = 0;  
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP GET_CCP_VERSION�������������ʶ�����ӻ���CCP
// �汾�������������EXCHANGE_ID����֮ǰִ�С�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x1b
//  1      �������������ֵ
//  2      Main Protocol version (desired)
//  3      Release within version (desired)
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      Main Protocol version as implemented
//  4      Release within version as implemented
//  5~7    δ����      
//
// ע��
//    
/********************************************************************/
void   CCP_GetCcpVersionCmdPro(CCP_BYTE com[8])
{
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.Crm[3] = CCP_VERSION_MAJOR;
    ccp.Crm[4] = CCP_VERSION_MINOR;           
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP GET_SEED�������������������ӻ�����ĳһ��
// ����Ȩ�ޣ��궨����ء�FLASHˢд�ȣ�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x12
//  1      �������������ֵ
//  2      Requested slave resource or function
//  3~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      Protection status (TRUE or FALSE)
//  4~7    seed data
//
// ע��
//     ���Protection statusΪFALSE����ô����ECU�Ըò�������ȫ��ֹ�ģ�
// ����������Ҳ����Ҫ����UNLOCK����Ը���������ˡ���Protection status
// ΪTRUEʱ�����������ϴ���SEED����UNLOCK������н�����
/********************************************************************/
void   CCP_GetSeedCmdPro(CCP_BYTE com[8])
{
    #define privilegeLevel com[2]
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.Crm[3] = 0; /* Protection Status: No key required */
    
    *(CCP_DWORD*)&ccp.Crm[4] = 0;
    
    #ifdef CCP_SEED_KEY
 
    switch (privilegeLevel) 
    {
        case PL_CAL:
          ccp.Crm[3] = (0==(ccp.ProtectionStatus&PL_CAL)); 
          *(CCP_DWORD*)&ccp.Crm[4] = ccpGetSeed(PL_CAL);
          break;
        case PL_PGM:
          ccp.Crm[3] = (0==(ccp.ProtectionStatus&PL_PGM)); 
          *(CCP_DWORD*)&ccp.Crm[4] = ccpGetSeed(PL_PGM);
          break;
        case PL_DAQ:
          ccp.Crm[3] = (0==(ccp.ProtectionStatus&PL_DAQ));  
          *(CCP_DWORD*)&ccp.Crm[4] = ccpGetSeed(PL_DAQ);
          break;
        default:
          ccp.Crm[1] = CRC_CMD_SYNTAX;
    }
    
    #endif
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP UNLOCK�������������������ӻ�����������SEED
// ���������KEY���Ӷ������ӻ���ĳ��ܡ�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x123
//  1      �������������ֵ
//  2~7    KEY data
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      Current Resource Mask(�ο� Exchange_ID�����ж�MASK�Ķ���)
//  4~7    δ����
//
// ע��
/********************************************************************/
void   CCP_UnlockCmdPro(CCP_BYTE com[8])
{
    #define key com[2] /* Key may be up to 6 Bytes */
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    ccp.ProtectionStatus |= ccpUnlock(&com[2]); /* Reset the appropriate resource protection mask bit */
    ccp.Crm[3] = ccp.ProtectionStatus; /* Current Protection Status */              
}

void ccpCommand(CCP_BYTE com[8]) 
{
    CCP_BYTE cmd = com[0];

    if (cmd==CC_CONNECT) 
    {
        CCP_ConnectCmdPro(com);
    }
    else if(cmd==CC_TEST)
    {
        CCP_TestCmdPro(com);   
    }
    else if(ccp.SessionStatus&SS_CONNECTED) 
    {
        switch (cmd) 
        {
            case CC_DISCONNECT:
            {
                CCP_DisconnectCmdPro(com);
                break;
            }
            case CC_EXCHANGE_ID:  
            {
                CCP_ExchangeidCmdPro(com); 
                break;   
            }
            case CC_SET_MTA:  
            {
                CCP_SetMtaCmdPro(com);
                break;  
            }
            case CC_DNLOAD: 
            {
                CCP_DNLoadCmdPro(com);
                break;
            }
            case CC_DNLOAD6: 
            {
                CCP_DNLoad6CmdPro(com);
                break;  
            }
            case CC_UPLOAD:  
            {
                CCP_UPLoadCmdPro(com);
                break;  
            }
            case CC_SHORT_UPLOAD:  
            {
                CCP_ShortUPLoadCmdPro(com); 
                break; 
            }
            case CC_GET_DAQ_SIZE:  
            {
                CCP_GetDaqSizeCmdPro(com);
                break; 
            }
            case CC_SET_DAQ_PTR: 
            {
                CCP_SetDaqPtrCmdPro(com);
                break;  
            }
            case CC_WRITE_DAQ: 
            {
                CCP_WriteDaqCmdPro(com);
                break;
            }
            case CC_START_STOP: 
            {
                CCP_StartStopCmdPro(com);
                break;
            }
            case CC_START_STOP_ALL:  
            {
                CCP_StartStopAllCmdPro(com);
                break;  
            }
            case CC_SET_S_STATUS:  
            {
                CCP_SetSessionStatusCmdPro(com);
                break;
            }
            case CC_GET_S_STATUS:  
            {
                CCP_GetSessionStatusCmdPro(com);
                break;
            }
            case CC_GET_CCP_VERSION:  
            {
                CCP_GetCcpVersionCmdPro(com);
                break;  
            }
            case CC_GET_SEED:  
            {
                CCP_GetSeedCmdPro(com);
                break;   
            }
            case CC_UNLOCK:  
            {
                CCP_UnlockCmdPro(com);
                break;   
            }
            default:  
            {
                ccp.Crm[1] = CRC_CMD_UNKNOWN;
                break;
            }
        } /* end switch */
    } /* end if */
    else 
    {
        return;
    }
    ccpSendCrm();
}




