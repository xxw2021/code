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
    else   // CCP发送缓冲区满，CCP需要在这里做处理
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
//    该函数用于处理CCP CONNECT命令
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x01
//  1      命令计数器计数值
//  2~3    CCP站地址( intel格式 )
//  4~7    未定义      
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    未定义
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
//    该函数用于处理CCP SET_MTA命令
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x02
//  1      命令计数器计数值
//  2      MTA0 用于命令DNLOAD, UPLOAD, DNLOAD_6 , SELECT_CAL_PAGE,
//         CLEAR_MEMORY PROGRAM and PROGRAM_6； MTA1用于命令MOVE
//  3      地址扩展
//  4~7    地址（ unsigned long ）
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
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
//    该函数用于处理CCP EXCHANGE_ID命令，该命令执行结束后，主机会在下
// 个命令中利用UPLOAD命令要求从机上传它的ID，因此，执行EXCHANGE_ID命令
// 后，从机自动的设定MTA0指针指向从机ID的存储地址。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x17
//  1      命令计数器计数值
//  2~7    CCP主机ID信息
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      从机ID的字节数目 
//  4      可选项（特定） 
//  5      Resource Availability Mask
//  6      Resource Protection Mask 
//
// 注：
//      Bit 7  6  5 4 3 2  1   0
//          x PGM x x x x DAQ CAL
// ECU 内部的资源是否可以用CCP进行标定、采集或编程通过该字节中的对上位机反馈：
// Resource Availability Mask:
// 1：   当CAL位为1时表明该ECU可以被标定
// 2：   当DAQ位为1时表明上位机可以采集当前ECU内部的数据
// Resource Protection Mask:
// 3：   当PGM位为1时表明可以对ECU的内存进行编程   
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
//    该函数用于处理CCP DNLOAD命令，将标定数据下载到ECU内部RAM中，
// 执行该命令前，必须执行SET_MTA命令，设定要写入的数据的RAM首地址
// 命令执行后必须返回 MTA0 address (after post-increment)
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x02
//  1      命令计数器计数值
//  2      该命令包含的数据字节数目--最大5个字节
//  3      数据
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      写入数据后的扩展地址 after post-increment 
//  4~7    写入数据后的地址指针 after post-increment 
//
// 注意：
//    该函数并没有按照标准返回DTO，需要根据ccpWriteMTA函数的返回值
// 来确定DTO
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
//    该函数用于处理CCP DNLOAD6命令，六个字节的数据将被拷贝到以MTA0为
// 起始地址的内存单元中去，使用DNLOAD_6命令前必须传送SET_MTA命令命令
// 执行结束后，MTA0指针增量为6。命令执行后必须返回 MTA0 address 
// (after post-increment)
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x02
//  1      命令计数器计数值
//  2      数据，6个字节
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      写入数据后的扩展地址 after post-increment 
//  4~7    写入数据后的地址指针 after post-increment 
//
// 注意：
//    该函数并没有按照标准返回DTO，需要根据ccpWriteMTA函数的返回值
// 来确定DTO
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
//    该函数用于处理CCP UPLOAD命令，该命令将向上位机上传一定字节数目的
// 数据，使用UPLOAD命令前必须传送SET_MTA命令设定MTA0地址，命令结束后，
// MTA0指针增量为上传的字节数目。命令执行后必须返回 MTA0 address 
// (after post-increment)
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x04
//  1      命令计数器计数值
//  2      需要上传的数据BLOCK字节数目
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      写入数据后的扩展地址 after post-increment 
//  4~7    写入数据后的地址指针 after post-increment 
//
// 注意：
//    该函数并没有按照标准返回DTO。
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
//    该函数用于处理CCP SHORT_UP命令，该命令传送1~5个字节的数据到上位机
// 该命令中包含待上传数据的首地址，命令执行结束后，MTA0的值不变。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x0F
//  1      命令计数器计数值
//  2      需要上传的数据BLOCK字节数目
//  3      待上传数据的地址扩展
// 4~7     待上传数据的地址（ unsigned long ）
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    需上传的数据内容
//
// 注意：
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
//    该函数用于处理CCP GET_DAQ_SIZE命令，该命令要求下位机返回主机指定
// 的DAQ list列表中包含的ODT数目，从机情况DAQ List列表中的内容。如果主
// 机指定的DAQ List列表号不可用，那么从机返回的ODT数目为0。当多ECU同时
// 标定时，该命令可以指定不同ECU中DTO的CAN报文ID.
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x14
//  1      命令计数器计数值
//  2      DAQ List列表号
//  3      未使用
// 4~7     DTO CAN报文ID
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      该DAQ List中ODT的数目
//  4      该DAQ List中第一个ODT的PID号     
//
// 注意：
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
//    该函数用于处理CCP SET_DAQ_PTR命令，该命令用于设定DAQ List列表
// 指针，为WRITE_DAQ命令做准备。命令执行结束后，当前DAQ_LIST_POINTER
// 指针指向指定的DAQ List列表中ODT中的指定元素。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x15
//  1      命令计数器计数值
//  2      指定DAQ List列表号
//  3      指定该DAQ List列表中ODT号
//  4      指定该ODT表中的元素号
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    没使用    
//
// 注意：
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
//    该函数用于处理CCP WRITE_DAQ命令，该命令和SET_DAQ_PTR命令联合起来
// 初始化ECU内部的DAQ List列表。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x16
//  1      命令计数器计数值
//  2      Size of DAQ element in bytes（即被采样变量的字节数目） 
//  3      Address extension of DAQ element(被采样变量的扩展地址)   
//  4~7    Address of DAQ element(被采样变量的地址)   
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    没使用    
//
// 注意：
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
//    该函数用于处理CCP START_STOP命令，该命令指定DAQ List列表中的
// 0~Last ODT number号的所有ODT均被设定到指定的MODE状态。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x06
//  1      命令计数器计数值
//  2      Mode : 0x01 start/0x00 stop/0x02 prepare data tranmission 
//  3      DAQ list number  
//  4      Last ODT number 
//  5      Event Channel No.
//  6~7    Transmission rate prescaler
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    没使用    
//
// 注意：
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
//    该函数用于处理CCP START_STOP_ALL命令。该命令用于启动所有的DAQ列表
// 进行采集，这些DAQ列表在该命令之前已经被START_STOP命令配置为 prepared 
// to start状态。同时该命令可以停止当前已经或准备启动的所有DAQ列表。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x08
//  1      命令计数器计数值
//  2      Mode : 0x00 stops, 0x01 starts data transmission
//  3~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    未定义 
//
// 注意：
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
//    该函数用于处理CCP CLEAR_MEMORY命令。该命令执行FLASH/EEPROM擦除
// 操作，FLASH/EEPROM的地址由MTA0指定。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x10
//  1      命令计数器计数值
//  2~5    要擦除的MEMORY大小
//  6~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    未定义 
//
// 注意：
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
//    该函数用于处理CCP SET_S_STATUS命令。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x0c
//  1      命令计数器计数值
//  2      Session status bits
//  3~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3~7    未定义 
//
// 注：
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
//    该函数用于处理CCP GET_S_STATUS命令。主机获取当前从机的标定状态
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x0d
//  1      命令计数器计数值
//  2~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      Session status
//  4      additional status information qualifier
//  5      additional status information (optional)
//  6~7    未定义      
//
// 注：
//    如果字节5为零，那么字节4没有意义。如果不为零，那么字节4的意义由
// 用户自定义，CCP标准协议不包括对这两个字节的解释。
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
//    该函数用于处理CCP GET_CCP_VERSION命令。该命令用于识别主从机的CCP
// 版本。该命令必须在EXCHANGE_ID命令之前执行。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x1b
//  1      命令计数器计数值
//  2      Main Protocol version (desired)
//  3      Release within version (desired)
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      Main Protocol version as implemented
//  4      Release within version as implemented
//  5~7    未定义      
//
// 注：
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
//    该函数用于处理CCP SELECT_CAL_PAGE命令。该命令将MTA0指针执行的
// 地址作为标定页指针地址。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x11
//  1      命令计数器计数值
//  2~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码（必须等于0） 
//  2      命令计数器计数值
//  3~7    未定义      
//
// 注：
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
//    该函数用于处理CCP GET_ACTIVE_CAL_PAGE命令。该命令将当前从机激活
// 的标定数据区首地址返回给主机
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x09
//  1      命令计数器计数值
//  2~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      当前活动的标定数据区地址的扩展地址  
//  4~7    当前活动的标定数据区首地址 
//
// 注：
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
//    该函数用于处理CCP PROGRAM命令。该命令将指定的数据编程到FLASH/
// EEPROM中，FLASH/EEPROM的地址由MTA0指针指定。命令结束后MTA0指针变量
// 增加，增加量为写入的字节数目。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x18
//  1      命令计数器计数值
//  2      待写入的数据的字节数
//  3~7    待写入的数据，最大5个字节
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码
//  2      命令计数器计数值
//  3      写入数据后的扩展地址 after post-increment 
//  4~7    写入数据后的地址指针 after post-increment 
//
// 注：
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
//    该函数用于处理CCP PROGRAM6命令。该命令将6个字节的数据编程到FLASH/
// EEPROM中，FLASH/EEPROM的地址由MTA0指针指定。命令结束后MTA0指针变量
// 增加，增加量为6个字节。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x18
//  1      命令计数器计数值
//  2~7    待写入的数据，共6个字节--必须
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码
//  2      命令计数器计数值
//  3      写入数据后的扩展地址 after post-increment 
//  4~7    写入数据后的地址指针 after post-increment 
//
// 注：
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
//    该函数用于处理CCP BUILD_CHKSUM命令。该命令对一段主机指定的数据区
// 进行CHECK_SUM运算，并将结果返回。数据区的首地址有MTA0指针指定。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x0e
//  1      命令计数器计数值
//  2~5    进行CHECK SUM运算的数据的字节数
//  6~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码
//  2      命令计数器计数值
//  3      CHECK SUM结果的字节数
//  4~7    CHECK SUM结果 
//
// 注：
//  CCP标准中并没有规定具体的CHECK SUM算法，该算法是由用户自定义的。  
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
//    该函数用于处理CCP GET_SEED命令。该命令用于主机向从机请求某一种
// 操作权限（标定、监控、FLASH刷写等）
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x12
//  1      命令计数器计数值
//  2      Requested slave resource or function
//  3~7    未定义
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      Protection status (TRUE or FALSE)
//  4~7    seed data
//
// 注：
//     如果Protection status为FALSE，那么表明ECU对该操作是完全禁止的，
// 接下来主机也不需要采用UNLOCK命令对该请求解锁了。当Protection status
// 为TRUE时，主机根据上传的SEED利用UNLOCK命令进行解锁。
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
//    该函数用于处理CCP UNLOCK命令。该命令用于主机向从机传送其利用SEED
// 计算出来的KEY，从而解锁从机的某项功能。
//
// 主机发送CRO命令
// byte    description  
//  0      命令码 0x123
//  1      命令计数器计数值
//  2~7    KEY data
// 从机返回DTO命令
// byte    description  
//  0      命令码 0xff
//  1      命令返回码 
//  2      命令计数器计数值
//  3      Current Resource Mask(参考 Exchange_ID命令中对MASK的定义)
//  4~7    未定义
//
// 注：
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




