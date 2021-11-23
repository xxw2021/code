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
 #define CCP_STATION_ADDR  0x39 /* CCP Identifiers and Address */    
    /**************************************************** 
      Define CCP_STATION_ADDR in Intel Format 
      High/Low byte swapped on motorola machines !!! (0x3900) 
      ע��Motorola ��Ƭ���ĸߵ��ֽڴ洢˳�� ���ֽڣ��ߵ�ַ�������ֽڣ��͵�ַ��
    *****************************************************/
/*----------------------------------------------------------------------------*/

/************3��CCP��վID   CCP_STATION_ID*************/   
/*----------------------------------------------------------------------------*/
#define CCP_STATION_ID    "VCU"  /* Plug&Play station identification */

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
#define CCP_MAX_ODT 23             /* Number of ODTs in each DAQ lists */
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

#endif
