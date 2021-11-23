/*****************************************************************************
| Project Name:   C C P - Driver
| File Name:      CCP.H
|
| Description: 
|
|-----------------------------------------------------------------------------
|                     C O P Y R I G H T
|-----------------------------------------------------------------------------
| 
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


#ifndef __CCP_H_
#define __CCP_H_

#include "CCPPAR.H"

#ifndef C_DISABLE_CCP

/* Declare CCP-protocol version */
#define CCP_VERSION_MAJOR   0x02
#define CCP_VERSION_MINOR   0x01


/* Declare module implementation version number */
#define CCP_DRIVER_VERSION 142
#define CCP_DRIVER_BUGFIX_VERSION 0


/* Basic */
#define CC_CONNECT           0x01
#define CC_SET_MTA           0x02
#define CC_DNLOAD            0x03
#define CC_UPLOAD            0x04
#define CC_TEST              0x05 /* V2.1 */
#define CC_START_STOP        0x06
#define CC_DISCONNECT        0x07
#define CC_START_STOP_ALL    0x08 /* V2.1 */
#define CC_SHORT_UPLOAD      0x0F
#define CC_GET_DAQ_SIZE      0x14
#define CC_SET_DAQ_PTR       0x15
#define CC_WRITE_DAQ         0x16
#define CC_EXCHANGE_ID       0x17
#define CC_GET_CCP_VERSION   0x1B /* V2.1 */
#define CC_DNLOAD6           0x23

/* Optional */
#define CC_GET_CAL_PAGE      0x09
#define CC_SET_S_STATUS      0x0C
#define CC_GET_S_STATUS      0x0D
#define CC_BUILD_CHKSUM      0x0E
#define CC_CLEAR_MEMORY      0x10
#define CC_SET_CAL_PAGE      0x11
#define CC_GET_SEED          0x12
#define CC_UNLOCK            0x13
#define CC_PROGRAM           0x18
#define CC_MOVE_MEMORY       0x19
#define CC_DIAG_SERVICE      0x20
#define CC_ACTION_SERVICE    0x21
#define CC_PROGRAM6          0x22 

/* Vector extensions */
#define CC_PROGRAM_PREPARE   0x1E   /* Prepare for flash kernel download */
#define CC_PROGRAM_START     0x1F   /* Start flash kernel at MTA[0] */

/* Returncodes */
#define CRC_OK                 0x00

/* C1 */      
#define CRC_CMD_BUSY           0x10
#define CRC_DAQ_BUSY           0x11
#define CRC_KEY_REQUEST        0x18
#define CRC_STATUS_REQUEST     0x19

/* C2 */
#define CRC_COLD_START_REQUEST 0x20
#define CRC_CAL_INIT_REQUEST   0x21
#define CRC_DAQ_INIT_REQUEST   0x22
#define CRC_CODE_REQUEST       0x23

/* C3 (Errors) */
#define CRC_CMD_UNKNOWN        0x30
#define CRC_CMD_SYNTAX         0x31
#define CRC_OUT_OF_RANGE       0x32
#define CRC_ACCESS_DENIED      0x33
#define CRC_OVERLOAD           0x34
#define CRC_ACCESS_LOCKED      0x35


/* Session Status */
#define SS_CAL                0x01
#define SS_DAQ                0x02
#define SS_RESUME             0x04
#define SS_TMP_DISCONNECTED   0x10
#define SS_CONNECTED          0x20
#define SS_STORE              0x40
#define SS_RUN                0x80

/* Priviledge Level */
#define PL_CAL 0x01
#define PL_DAQ 0x02
#define PL_PGM 0x40

/* Broadcast Station Address */
#define CCP_BROADCAST_STATION_ADDR 0



typedef struct ccpOdtEntry 
{
  CCP_BYTEFARPTR    ptr;
  CCP_BYTE          siz;
  
} ccpOdtEntry_t;

typedef struct ccpDaqList 
{
  ccpOdtEntry_t   odt[CCP_MAX_ODT][7];
  CCP_WORD        prescaler;
  CCP_WORD        cycle;
  CCP_BYTE        eventChannel;
  CCP_BYTE        last;
  CCP_BYTE        flags;
  
} ccpDaqList_t;

/* DAQ list */
#define DAQ_FLAG_START    0x01
#define DAQ_FLAG_SEND     0x02
#define DAQ_FLAG_PREPARED 0x04
#define DAQ_FLAG_OVERRUN  0x80

typedef struct 
{
  CCP_BYTE b[8];
  
} ccpMsg_t;

typedef struct 
{
  CCP_BYTE     len;
  CCP_BYTE     rp;
  ccpMsg_t     msg[CCP_SEND_QUEUE_SIZE];
  
} ccpQueue_t;

typedef  struct  
{
    CCP_BYTE    m_msg[CCP_SEND_QUEUE_SIZE][8];
    CCP_BYTE    m_PWriteFIFO;
    CCP_BYTE    m_PReadFIFO;       
}CCP_MsgTBuf_struct;

/*--------------------------------------------------------------------------*/
/* CCP Driver Variables, Type Definition */
/*--------------------------------------------------------------------------*/

#define CCP_MAX_MTA 2
#define CCP_INTERNAL_MTA (CCP_MAX_MTA-1)

/* Return values for ccpWriteMTA and ccpCheckWriteEEPROM */
#define CCP_WRITE_DENIED  0
#define CCP_WRITE_OK      1
#define CCP_WRITE_PENDING 2
#define CCP_WRITE_ERROR   3

/* Bitmasks for ccp.SendStatus */
#define CCP_CRM_REQUEST  0x01
#define CCP_DTM_REQUEST  0x02
#define CCP_USR_REQUEST  0x04
#define CCP_CMD_PENDING  0x08
#define CCP_CRM_PENDING  0x10
#define CCP_DTM_PENDING  0x20
#define CCP_USR_PENDING  0x40
#define CCP_TX_PENDING   0x80
#define CCP_SEND_PENDING (CCP_DTM_PENDING|CCP_CRM_PENDING|CCP_USR_PENDING)

struct ccp 
{
    CCP_BYTE  Crm[8];                         /* CRM Command Return Message buffer */
    CCP_BYTE  SessionStatus;
    CCP_BYTE  SendStatus;
    CCP_BYTEFARPTR  MTA[CCP_MAX_MTA];         /* Memory Transfer Address */
    ccpOdtEntry_t * DaqListPtr;               /* Pointer for SET_DAQ_PTR, make it near to save RAM  */
    ccpDaqList_t    DaqList[CCP_MAX_DAQ];     /* DAQ list */
    CCP_BYTE  UserSessionStatus;              /* Used for GET/SET_SESSION_STATUS */
    CCP_BYTE  ProtectionStatus;               /* Resource Protection Status */

    #if defined( CCP_CPUTYPE_32BIT )
      CCP_DWORD  CheckSumSize;                /* Counter for checksum calculation */
    #else
      CCP_WORD   CheckSumSize;                 /* Counter for checksum calculation */
    #endif

};

extern struct ccp ccp;
extern CCP_MsgTBuf_struct CCP_TMsgBuf;

void   ccpInit( void );
void   ccpDaq( CCP_BYTE eventChannel );
void   ccpCommand( CCP_BYTE msg[8] );
void   ccpSendCrm( void );
void   CCP_TestCmdPro(CCP_BYTE com[8]);
void   CCP_ConnectCmdPro(CCP_BYTE com[8]);
void   CCP_DisconnectCmdPro(CCP_BYTE com[8]);
void   CCP_SetMtaCmdPro(CCP_BYTE com[8]);
void   CCP_ExchangeidCmdPro(CCP_BYTE com[8]);
void   CCP_DNLoadCmdPro(CCP_BYTE com[8]);
void   CCP_DNLoad6CmdPro(CCP_BYTE com[8]);
void   CCP_UPLoadCmdPro(CCP_BYTE com[8]);
void   CCP_WriteDaqCmdPro(CCP_BYTE com[8]);
void   CCP_SetDaqPtrCmdPro(CCP_BYTE com[8]);
void   CCP_GetDaqSizeCmdPro(CCP_BYTE com[8]);
void   CCP_SetDaqPtrCmdPro(CCP_BYTE com[8]);
void   CCP_WriteDaqCmdPro(CCP_BYTE com[8]);
void   CCP_StartStopCmdPro(CCP_BYTE com[8]) ;
void   CCP_StartStopAllCmdPro(CCP_BYTE com[8]);                                                                 
CCP_BYTE   CCP_TransOneDataFrame(CCP_BYTE msg[8]);
CCP_BYTE   CCP_GetOneDataFrame(CCP_BYTE msg[8]);

extern CCP_BYTE ccpBackground( void );
extern void ccpUserBackground( void );
extern CCP_BYTEFARPTR ccpGetPointer( CCP_BYTE addr_ext, CCP_DWORD address );
extern void ccpFlashClear( CCP_BYTEPTR a, CCP_DWORD size );
extern CCP_BYTE ccpFlashProgramm( CCP_BYTEPTR data, CCP_BYTEPTR a, CCP_BYTE size );
extern CCP_DWORD ccpGetCalPage( void );
extern void ccpSetCalPage( CCP_DWORD a );
extern CCP_DWORD ccpGetSeed( CCP_BYTE resourceMask );
extern CCP_BYTE  ccpUnlock( CCP_BYTE *key );






#endif

#endif
