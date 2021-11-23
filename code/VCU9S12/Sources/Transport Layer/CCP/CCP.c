/*****************************************************************************
| Project Name:   CCP - Driver
| File Name:      CCP.C
|
| Description: 
|   Implements the CCP module
|
|-----------------------------------------------------------------------------
|                      C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c)  2001-2003  .     All rights reserved.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
|             
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
|  Date       Version  Author  Description
| ----------  -------  ------  -----------------------------------------------
|    
|***************************************************************************/

/* CCP Definitions and Parameters */
#include "ccp.h"


CCP_BYTE ccpStationId[] = CCP_STATION_ID;
struct ccp ccp;
CCP_MsgTBuf_struct CCP_TMsgBuf;

/*--------------------------------------------------------------------------*/
/* Background Processing */
/* Used for Checksum Calculation */
/*--------------------------------------------------------------------------*/

/* Table for CCITT checksum calculation */
#ifdef CCP_CHECKSUM_CCITT
   CCP_MEMROM0 CCP_ROM CCP_WORD CRC16CCITTtab[256] = {

    0x0000,0x1189,0x2312,0x329B,0x4624,0x57AD,0x6536,0x74BF,
    0x8C48,0x9DC1,0xAF5A,0xBED3,0xCA6C,0xDBE5,0xE97E,0xF8F7,
    0x1081,0x0108,0x3393,0x221A,0x56A5,0x472C,0x75B7,0x643E,
    0x9CC9,0x8D40,0xBFDB,0xAE52,0xDAED,0xCB64,0xF9FF,0xE876,
    0x2102,0x308B,0x0210,0x1399,0x6726,0x76AF,0x4434,0x55BD,
    0xAD4A,0xBCC3,0x8E58,0x9FD1,0xEB6E,0xFAE7,0xC87C,0xD9F5,
    0x3183,0x200A,0x1291,0x0318,0x77A7,0x662E,0x54B5,0x453C,
    0xBDCB,0xAC42,0x9ED9,0x8F50,0xFBEF,0xEA66,0xD8FD,0xC974,
    0x4204,0x538D,0x6116,0x709F,0x0420,0x15A9,0x2732,0x36BB,
    0xCE4C,0xDFC5,0xED5E,0xFCD7,0x8868,0x99E1,0xAB7A,0xBAF3,
    0x5285,0x430C,0x7197,0x601E,0x14A1,0x0528,0x37B3,0x263A,
    0xDECD,0xCF44,0xFDDF,0xEC56,0x98E9,0x8960,0xBBFB,0xAA72,
    0x6306,0x728F,0x4014,0x519D,0x2522,0x34AB,0x0630,0x17B9,
    0xEF4E,0xFEC7,0xCC5C,0xDDD5,0xA96A,0xB8E3,0x8A78,0x9BF1,
    0x7387,0x620E,0x5095,0x411C,0x35A3,0x242A,0x16B1,0x0738,
    0xFFCF,0xEE46,0xDCDD,0xCD54,0xB9EB,0xA862,0x9AF9,0x8B70,
    0x8408,0x9581,0xA71A,0xB693,0xC22C,0xD3A5,0xE13E,0xF0B7,
    0x0840,0x19C9,0x2B52,0x3ADB,0x4E64,0x5FED,0x6D76,0x7CFF,
    0x9489,0x8500,0xB79B,0xA612,0xD2AD,0xC324,0xF1BF,0xE036,
    0x18C1,0x0948,0x3BD3,0x2A5A,0x5EE5,0x4F6C,0x7DF7,0x6C7E,
    0xA50A,0xB483,0x8618,0x9791,0xE32E,0xF2A7,0xC03C,0xD1B5,
    0x2942,0x38CB,0x0A50,0x1BD9,0x6F66,0x7EEF,0x4C74,0x5DFD,
    0xB58B,0xA402,0x9699,0x8710,0xF3AF,0xE226,0xD0BD,0xC134,
    0x39C3,0x284A,0x1AD1,0x0B58,0x7FE7,0x6E6E,0x5CF5,0x4D7C,
    0xC60C,0xD785,0xE51E,0xF497,0x8028,0x91A1,0xA33A,0xB2B3,
    0x4A44,0x5BCD,0x6956,0x78DF,0x0C60,0x1DE9,0x2F72,0x3EFB,
    0xD68D,0xC704,0xF59F,0xE416,0x90A9,0x8120,0xB3BB,0xA232,
    0x5AC5,0x4B4C,0x79D7,0x685E,0x1CE1,0x0D68,0x3FF3,0x2E7A,
    0xE70E,0xF687,0xC41C,0xD595,0xA12A,0xB0A3,0x8238,0x93B1,
    0x6B46,0x7ACF,0x4854,0x59DD,0x2D62,0x3CEB,0x0E70,0x1FF9,
    0xF78F,0xE606,0xD49D,0xC514,0xB1AB,0xA022,0x92B9,0x8330,
    0x7BC7,0x6A4E,0x58D5,0x495C,0x3DE3,0x2C6A,0x1EF1,0x0F78
  };
#endif

#ifndef CCP_CHECKSUM_BLOCKSIZE
  #define CCP_CHECKSUM_BLOCKSIZE 256
#endif

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

CCP_BYTE   CCP_TransOneDataFrame(CCP_BYTE msg[8])
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

CCP_BYTE ccpWriteMTA(CCP_BYTE MtaNum, CCP_BYTE size, CCP_BYTEPTR d ) 
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
void ccpReadMTA( CCP_BYTE n, CCP_BYTE size, CCP_BYTEPTR d ) 
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

CCP_BYTE ccpBackground( void ) 
{
    ccpUserBackground();
    
    #ifdef CCP_CHECKSUM

    if (ccp.CheckSumSize) 
    {
        register CCP_BYTE n;
        #ifndef CCP_CHECKSUM_CCITT
          register CCP_BYTE b;
        #endif

        if (ccp.CheckSumSize<=(CCP_CHECKSUM_BLOCKSIZE-1)) 
        {
            n = (CCP_BYTE)ccp.CheckSumSize;
            ccp.CheckSumSize = 0;
        } 
        else 
        {
            n = 0;
            ccp.CheckSumSize -= CCP_CHECKSUM_BLOCKSIZE;
        }

        do 
        {
          #ifdef CCP_CHECKSUM_CCITT

          /* CRC */
          #ifdef CCP_MOTOROLA
            (*(CCP_WORD*)&ccp.Crm[4]) = CRC16CCITTtab[ccp.Crm[5] ^ *(ccp.MTA[CCP_INTERNAL_MTA]++)] ^ ccp.Crm[4];
          #else
            (*(CCP_WORD*)&ccp.Crm[4]) = CRC16CCITTtab[ccp.Crm[4] ^ *(ccp.MTA[CCP_INTERNAL_MTA]++)] ^ ccp.Crm[5];
          #endif

          #else
            
          b = *(ccp.MTA[CCP_INTERNAL_MTA]);
          *(CCP_CHECKSUM_TYPE*)&ccp.Crm[4] += b;
          ccp.MTA[CCP_INTERNAL_MTA]++;

          #endif
        } while (--n!=0);

        if (ccp.CheckSumSize) 
        {
           return 1; /* Still pending */
        }
        //ccpSendCrm();
    } 
    #endif
    return 0;
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
//    �ú������ڴ���CCP CLEAR_MEMORY���������ִ��FLASH/EEPROM����
// ������FLASH/EEPROM�ĵ�ַ��MTA0ָ����
//
// ��������CRO����
// byte    description  
//  0      ������ 0x10
//  1      �������������ֵ
//  2~5    Ҫ������MEMORY��С
//  6~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3~7    δ���� 
//
// ע�⣺
/********************************************************************/
void   CCP_ClearMemoryCmdPro(CCP_BYTE com[8])
{
    CCP_DWORD s;

    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
      if (!(ccp.ProtectionStatus&PL_PGM))
        ccp.Crm[1] = CRC_ACCESS_DENIED;
      else
    #endif

    #ifdef CCP_BOOTLOADER
      /* Transfer control to the CCP bootloader */
      ccpBootLoaderStartup(&ccp,com); /* Never returns */
    #else
      /* Clear flash sector */
      #ifdef CCP_MOTOROLA
        s = (*(CCP_WORD*)&com[4]) | ((*(CCP_WORD*)&com[2])<<16);
      #else
        s = (*(CCP_WORD*)&com[2]) | ((*(CCP_WORD*)&com[4])<<16);
      #endif
      ccpFlashClear(ccp.MTA[0],s);
    #endif

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
//    �ú������ڴ���CCP SELECT_CAL_PAGE��������MTA0ָ��ִ�е�
// ��ַ��Ϊ�궨ҳָ���ַ��
//
// ��������CRO����
// byte    description  
//  0      ������ 0x11
//  1      �������������ֵ
//  2~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������루�������0�� 
//  2      �������������ֵ
//  3~7    δ����      
//
// ע��
//    
/********************************************************************/
void   CCP_SelectCaliPageCmdPro(CCP_BYTE com[8])
{
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccpSetCalPage((CCP_DWORD)ccp.MTA[0]);
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP GET_ACTIVE_CAL_PAGE����������ǰ�ӻ�����
// �ı궨�������׵�ַ���ظ�����
//
// ��������CRO����
// byte    description  
//  0      ������ 0x09
//  1      �������������ֵ
//  2~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      ������� 
//  2      �������������ֵ
//  3      ��ǰ��ı궨��������ַ����չ��ַ  
//  4~7    ��ǰ��ı궨�������׵�ַ 
//
// ע��
//    
/********************************************************************/
void   CCP_GetActiveCaliPageCmdPro(CCP_BYTE com[8])
{
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    ccp.Crm[3] = 0;  
    *(CCP_DWORD*)&ccp.Crm[4] = ccpGetCalPage();  
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP PROGRAM��������ָ�������ݱ�̵�FLASH/
// EEPROM�У�FLASH/EEPROM�ĵ�ַ��MTA0ָ��ָ�������������MTA0ָ�����
// ���ӣ�������Ϊд����ֽ���Ŀ��
//
// ��������CRO����
// byte    description  
//  0      ������ 0x18
//  1      �������������ֵ
//  2      ��д������ݵ��ֽ���
//  3~7    ��д������ݣ����5���ֽ�
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      �������
//  2      �������������ֵ
//  3      д�����ݺ����չ��ַ after post-increment 
//  4~7    д�����ݺ�ĵ�ַָ�� after post-increment 
//
// ע��
//    
/********************************************************************/
void   CCP_ProgramCmdPro(CCP_BYTE com[8])
{
    CCP_BYTE r;
    #define size com[2]
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
    
    if (!(ccp.ProtectionStatus&PL_PGM)) 
    {
      ccp.Crm[1] = CRC_ACCESS_DENIED;
      r = 0;
    }
      
    #endif
    
    r = ccpFlashProgramm(&com[3],ccp.MTA[0],size);
    ccp.MTA[0] += size;
    if (r==CCP_WRITE_PENDING) return; /* FLASH write pending */
    #undef size
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP PROGRAM6��������6���ֽڵ����ݱ�̵�FLASH/
// EEPROM�У�FLASH/EEPROM�ĵ�ַ��MTA0ָ��ָ�������������MTA0ָ�����
// ���ӣ�������Ϊ6���ֽڡ�
//
// ��������CRO����
// byte    description  
//  0      ������ 0x18
//  1      �������������ֵ
//  2~7    ��д������ݣ���6���ֽ�--����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      �������
//  2      �������������ֵ
//  3      д�����ݺ����չ��ַ after post-increment 
//  4~7    д�����ݺ�ĵ�ַָ�� after post-increment 
//
// ע��
//    
/********************************************************************/
void   CCP_Program6CmdPro(CCP_BYTE com[8])
{
    CCP_BYTE r;
    
    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    #ifdef CCP_SEED_KEY
    if (!(ccp.ProtectionStatus&PL_PGM)) 
    {
        ccp.Crm[1] = CRC_ACCESS_DENIED;
        r = 0;
    }
    else
    #endif
    r = ccpFlashProgramm(&com[2],ccp.MTA[0],6);
    ccp.MTA[0] += 6;
    if (r==CCP_WRITE_PENDING) return; /* FLASH write pending */
            
}

/********************************************************************/
// Description:
//    �ú������ڴ���CCP BUILD_CHKSUM����������һ������ָ����������
// ����CHECK_SUM���㣬����������ء����������׵�ַ��MTA0ָ��ָ����
//
// ��������CRO����
// byte    description  
//  0      ������ 0x0e
//  1      �������������ֵ
//  2~5    ����CHECK SUM��������ݵ��ֽ���
//  6~7    δ����
// �ӻ�����DTO����
// byte    description  
//  0      ������ 0xff
//  1      �������
//  2      �������������ֵ
//  3      CHECK SUM������ֽ���
//  4~7    CHECK SUM��� 
//
// ע��
//  CCP��׼�в�û�й涨�����CHECK SUM�㷨�����㷨�����û��Զ���ġ�  
/********************************************************************/
void   CCP_BuildCheckSumCmdPro(CCP_BYTE com[8])
{
    CCP_DWORD s;

    ccp.Crm[0] = 0xFF;
    ccp.Crm[1] = CRC_OK;
    ccp.Crm[2] = com[1];
    
    /* Initialize Responce */
    ccp.Crm[3] = sizeof(CCP_CHECKSUM_TYPE); /* Checksum Size */
    #ifdef CCP_CHECKSUM_CCITT               /* Checksum */
      *(CCP_DWORD*)&ccp.Crm[4] = 0xFFFFFFFF;
    #else
      *(CCP_DWORD*)&ccp.Crm[4] = 0;
    #endif
    ccp.MTA[CCP_INTERNAL_MTA] = ccp.MTA[0];        /* MTA[0] is not affected */
    #ifdef CCP_MOTOROLA
      s = (*(CCP_WORD*)&com[4]) | ((*(CCP_WORD*)&com[2])<<16);
    #else
      s = (*(CCP_WORD*)&com[2]) | ((*(CCP_WORD*)&com[4])<<16);
    #endif
   
    ccp.CheckSumSize = s;

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
            case CC_CLEAR_MEMORY:  
            {
                CCP_ClearMemoryCmdPro(com);
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
            case CC_SET_CAL_PAGE:  
            {
                CCP_SelectCaliPageCmdPro(com);
                break;
            }
            case CC_GET_CAL_PAGE:  
            {
                CCP_GetActiveCaliPageCmdPro(com);
                break;
            }
            case CC_PROGRAM:  
            {
                CCP_ProgramCmdPro(com); 
                break; 
            }
            case CC_PROGRAM6:  
            {
                CCP_Program6CmdPro(com);
                break;
            }
            case CC_BUILD_CHKSUM:  
            {
                CCP_BuildCheckSumCmdPro(com);  
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




