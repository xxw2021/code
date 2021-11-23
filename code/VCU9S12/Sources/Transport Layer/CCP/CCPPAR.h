/*----------------------------------------------------------------------------
| File:
|   ccppar.h
|
| Project:
|   CCP driver example
|   CANape CAN Calibration Tool
|
| Description:
|   Customization header for ccp.c
|   See CCP.DOC for a complete description of all options
|
 ----------------------------------------------------------------------------*/
#include "ccpexe.h"
#include <hidef.h>
                       
#ifndef __CCPPAR_H__
#define __CCPPAR_H__

#define CCP_MOTOROLA

typedef  unsigned char    CCP_BYTE; 
typedef  unsigned int     CCP_WORD;     
typedef  unsigned long    CCP_DWORD ;   
typedef  unsigned char*   CCP_BYTEPTR;  
typedef  unsigned char*__far  CCP_BYTEFARPTR ; 
typedef  unsigned long*__far  CCP_DWORDPTR; 
typedef  unsigned int*__far   CCP_WORDPTR;  

/* CCP ���������� */
/*
  ��������
 1��CRO��DTO��ID
 2��CCP��վ��ַ CCP_STATION_ADDR
 3��CCP��վID   CCP_STATION_ID
 4�������жϺ���
 5������DAQ����
 6������DAQ�ķ���ģʽSend Queue
 7������Seed and Key �Ĺ���
 8������궨ֵУ�飨Checksum Calculation��
 9������CRCУ��
 10������Flash ��̹���
 11������Flash ��̹���
*/

/************1��CRO��DTO��ID*************/
/*----------------------------------------------------------------------------*/
#define CCP_DTO_ID        0x18FF1803           /* CAN identifier ECU -> Master */
#define CCP_CRO_ID        0x18FF1923           /* CAN identifier Master -> ECU */
/*----------------------------------------------------------------------------*/

/************2��CCP��վ��ַ CCP_STATION_ADDR*************/
/*----------------------------------------------------------------------------*/
 #define CCP_STATION_ADDR  0x3900 /* CCP Identifiers and Address */    
    /**************************************************** 
      Define CCP_STATION_ADDR in Intel Format 
      High/Low byte swapped on motorola machines !!! (0x3900) 
      ע��Motorola ��Ƭ���ĸߵ��ֽڴ洢˳�� ���ֽڣ��ߵ�ַ�������ֽڣ��͵�ַ��
    *****************************************************/
/*----------------------------------------------------------------------------*/

/************3��CCP��վID   CCP_STATION_ID*************/   
/*----------------------------------------------------------------------------*/
#define CCP_STATION_ID    "FAWTCU"  /* Plug&Play station identification */
    /******************************************************
    ��Ҫ��������ECU����İ汾��MCS�ݴ�ʶ�����Ӧ�����ݿ�
    ******************************************************/
/*----------------------------------------------------------------------------*/

/************4�������жϺ���*************/   
/*----------------------------------------------------------------------------*/

/* Has to be defined if ccpSendCallBack may interrupt ccpDaq */

#define CCP_DISABLE_INTERRUPT EnableInterrupts;
#define CCP_ENABLE_INTERRUPT  DisableInterrupts;
/*----------------------------------------------------------------------------*/

/************5������DAQ����*************/ 
/*----------------------------------------------------------------------------*/
/* CCP Data Acuisition Parameters */
#define CCP_DAQ                   /* MACRO_ENABLE synchronous data aquisition in ccpDaq() */
#define CCP_MAX_ODT 18             /* Number of ODTs in each DAQ lists */
#define CCP_MAX_DAQ 1             /* Number of DAQ lists */
/*
ÿ��ODT������7�������ֽڵĵ�ַ��Ϣ
ÿ��DAQ������õ�4���ֽ�
ÿ��DAQ�б��п��Բ����Ĳ������ֽ�֮�͵ļ���(canape��ÿ��ͨ���������ֽڲ��ܳ�����ֵ��
CCP_MAX_ODT��7
�ܹ����Բ����Ĳ������ֽ�֮�ͣ�
7*CCP_MAX_ODT*CCP_MAX_DAQ
*/
/*----------------------------------------------------------------------------*/

/************6������DAQ�ķ���ģʽSend Queue*************/
/*----------------------------------------------------------------------------*/
//#define CCP_SEND_SINGLE
/* Use the transmit queue in CCP.C */
/* Complete sampling is done in ccpDaq(x) and the messages are written into the queue */

#define CCP_SEND_QUEUE    //���÷��Ͷ���ģʽ
#define CCP_SEND_QUEUE_SIZE (CCP_MAX_ODT*CCP_MAX_DAQ + 5)
#define CCP_RECI_QUEUE_SIZE 5

/*
  CCP_SEND_QUEUE_SIZE����Сֵ�� CCP_MAX_ODT*CCP_MAX_DAQ
  Ӱ������ֵ��������ODT�ĸ�������������ʱ�����߸��ɣ�
  һ�㶨��CCP_SEND_QUEUE_SIZE���ʴ�С�ķ����ǲ�������ķ������������ӣ�ֱ�����������ݶ�ʧ
*/
#define CCP_SEND_QUEUE_OVERRUN_INDICATION
/*
���ܣ�����CCP_SEND_QUEUE_OVERRUN_INDICATION
      CANape����ָʾ���Ͷ������ʱ����ʧ�����ݣ��ݴˣ�����CCP_SEND_QUEUE_SIZE�Ĵ�С�������DAQ��ͨ���� 
������ ��CANape��ѡ��overload dectection
*/
/*----------------------------------------------------------------------------*/

#define  CCP_SET_SESSION_STATUS
 /************7������Seed and Key �Ĺ���*************/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/************8������궨ֵУ�飨Checksum Calculation)*************/
/*----------------------------------------------------------------------------*/
/* Implement the memory checksum feature */
/* The checksum will be calculated in ccpBackground() */
/* This may be implementation specific */
#define CCP_CHECKSUM
#define CCP_CHECKSUM_TYPE CCP_WORD
/*
����checksum calulation
���ܣ�ʹCANape��OFFLINE״̬Ҳ���޸ı궨��������תΪONLINE״̬ʱ��
      �ܹ����µ�TCU��RAM�У�������ѡ�񲻸�����CANape��RAMѡ���У�
      ������Ҫ����RAM��checksum�ĶΣ����Է�Ϊ�ö�Σ�TCU����ʱ
      ��̨����.����Ķξ��ǲ������ڵĵ�ַ�ռ�(CANape��).
������1����main������ѭ���м���ccpBackground��������
      2����CANape�в�������ת����ҪУ��ҪУ���RAM����
*/
/*----------------------------------------------------------------------------*/


/************9������CRCУ��*************/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/

/************10������Flash ��̹���*************/
/*----------------------------------------------------------------------------*/
/* Activate the flash programming kernel download feature */
/* This is a CCP extension for CANape */
/* #define CCP_BOOTLOADER_DOWNLOAD */
#define CCP_BOOTLOADER_DOWNLOAD
#define CCP_PROGRAM
/*
���ַ�����Flash���б��
1��#define CCP_PROGRAM��Ȼ���Լ���д��Flash��̵ĺ�����������
   ccpFlashClear,ccpFlashProgramm,ccpSetCalPage�� CANape��Flash entry��Ϊ"derect"
2������FlashKernel����CANape��ѡ���Ӧ�Ŀ��������͵�fkl�ļ�
   ����FlashKernel��#define CCP_BOOTLOADER_DOWNLOAD
*/
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* CCP Options */


/* Indicate queue overruns in the msb of pid */
/* Will be displayed in CANape's status bar if CANAPE.INI: [asap1a] check_overflow=1 */

/* Transmit only one message in one call to ccpDaq() */

/* #define CCP_SEND_SINGLE */


/* Allow an ODT entry size >1 */
/* Not recommended for CANape, this will only need additional RAM space */
/* #define CCP_ODT_ENTRY_SIZE */
#define CCP_ODT_ENTRY_SIZE

/* Use GET_SEED and UNLOCK */
/* This is usually user dependant, just a skeleton here */
/* #define CCP_SEED_KEY*/


/* Use a 16 bit CRC algorithm */
/* Note:
   This will need additional 512 byte of ROM
   CCP_CHECKSUM_TYPE has to be WORD !
*/
/*#define CCP_CHECKSUM_CCITT*/     //����CRC У�鹦��
/*#define CCP_MOTOROLA*/          //ǰ���Ѿ�����CCP_MOTOROLA
 /*********************************
CANape,Options|Driver parameters.Go to tab CCP Parameters. Set the
corresponding calculation algorithm.
**********************************/


//#define  CCP_CHECKSUM_BLOCKSIZE    //�ı�CRCУ��Ŀ�Ĵ�С,�����壬��256
/*************************************************
����ʵʱ�Ե�Ҫ��checksum������ccpCommand()�����㣬
���ȱ��ֳɿ飨��СCCP_CHECKSUM_BLOCKSIZE����
Ȼ��ֱ���ccpBackground()������
*************************************************/

/* Check for pending CCP commands in ccpBackground() */
/* #ifdef CCP_CMD_NOT_IN_INTERRUPT */

/* MACRO_ENABLE Memory Write Protection */
/* #define CCP_WRITE_PROTECTION*/

/* MACRO_ENABLE EEPROM Read/Write Access */
/* #define CCP_WRITE_EEPROM */
/* #define CCP_READ_EEPROM */

#endif
