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

/* CCP 参数的配置 */
/*
  基本参数
 1、CRO和DTO的ID
 2、CCP的站地址 CCP_STATION_ADDR
 3、CCP的站ID   CCP_STATION_ID
 4、定义中断函数
 5、定义DAQ参数
 6、定义DAQ的发送模式Send Queue
 7、定义Seed and Key 的功能
 8、定义标定值校验（Checksum Calculation）
 9、定义CRC校验
 10、定义Flash 编程功能
 11、定义Flash 编程功能
*/

/************1、CRO和DTO的ID*************/
/*----------------------------------------------------------------------------*/
#define CCP_DTO_ID        0x18FF1803           /* CAN identifier ECU -> Master */
#define CCP_CRO_ID        0x18FF1923           /* CAN identifier Master -> ECU */
/*----------------------------------------------------------------------------*/

/************2、CCP的站地址 CCP_STATION_ADDR*************/
/*----------------------------------------------------------------------------*/
 #define CCP_STATION_ADDR  0x3900 /* CCP Identifiers and Address */    
    /**************************************************** 
      Define CCP_STATION_ADDR in Intel Format 
      High/Low byte swapped on motorola machines !!! (0x3900) 
      注：Motorola 单片机的高低字节存储顺序： 低字节（高地址）：高字节（低地址）
    *****************************************************/
/*----------------------------------------------------------------------------*/

/************3、CCP的站ID   CCP_STATION_ID*************/   
/*----------------------------------------------------------------------------*/
#define CCP_STATION_ID    "FAWTCU"  /* Plug&Play station identification */
    /******************************************************
    主要用于区别ECU软件的版本，MCS据此识别相对应的数据库
    ******************************************************/
/*----------------------------------------------------------------------------*/

/************4、定义中断函数*************/   
/*----------------------------------------------------------------------------*/

/* Has to be defined if ccpSendCallBack may interrupt ccpDaq */

#define CCP_DISABLE_INTERRUPT EnableInterrupts;
#define CCP_ENABLE_INTERRUPT  DisableInterrupts;
/*----------------------------------------------------------------------------*/

/************5、定义DAQ参数*************/ 
/*----------------------------------------------------------------------------*/
/* CCP Data Acuisition Parameters */
#define CCP_DAQ                   /* MACRO_ENABLE synchronous data aquisition in ccpDaq() */
#define CCP_MAX_ODT 18             /* Number of ODTs in each DAQ lists */
#define CCP_MAX_DAQ 1             /* Number of DAQ lists */
/*
每个ODT包含了7各数据字节的地址信息
每个DAQ额外会用到4各字节
每个DAQ列表中可以测量的参数的字节之和的计算(canape中每个通道测量的字节不能超过此值）
CCP_MAX_ODT×7
总共可以测量的参数的字节之和：
7*CCP_MAX_ODT*CCP_MAX_DAQ
*/
/*----------------------------------------------------------------------------*/

/************6、定义DAQ的发送模式Send Queue*************/
/*----------------------------------------------------------------------------*/
//#define CCP_SEND_SINGLE
/* Use the transmit queue in CCP.C */
/* Complete sampling is done in ccpDaq(x) and the messages are written into the queue */

#define CCP_SEND_QUEUE    //启用发送队列模式
#define CCP_SEND_QUEUE_SIZE (CCP_MAX_ODT*CCP_MAX_DAQ + 5)
#define CCP_RECI_QUEUE_SIZE 5

/*
  CCP_SEND_QUEUE_SIZE的最小值是 CCP_MAX_ODT*CCP_MAX_DAQ
  影响它的值的因素有ODT的个数，和总线延时（总线负荷）
  一般定义CCP_SEND_QUEUE_SIZE合适大小的方法是采用试验的方法，不断增加，直至不再有数据丢失
*/
#define CCP_SEND_QUEUE_OVERRUN_INDICATION
/*
功能：定义CCP_SEND_QUEUE_OVERRUN_INDICATION
      CANape可以指示发送队列溢出时所丢失的数据，据此，增加CCP_SEND_QUEUE_SIZE的大小，或减少DAQ的通读数 
方法： 在CANape中选择overload dectection
*/
/*----------------------------------------------------------------------------*/

#define  CCP_SET_SESSION_STATUS
 /************7、定义Seed and Key 的功能*************/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/************8、定义标定值校验（Checksum Calculation)*************/
/*----------------------------------------------------------------------------*/
/* Implement the memory checksum feature */
/* The checksum will be calculated in ccpBackground() */
/* This may be implementation specific */
#define CCP_CHECKSUM
#define CCP_CHECKSUM_TYPE CCP_WORD
/*
允许checksum calulation
功能：使CANape在OFFLINE状态也能修改标定参数，当转为ONLINE状态时，
      能够更新到TCU的RAM中，或者是选择不更新在CANape的RAM选项中，
      插入需要计算RAM的checksum的段，可以分为好多段，TCU空闲时
      后台运行.插入的段就是参数所在的地址空间(CANape中).
方法：1、在main函数的循环中加入ccpBackground（）函数
      2、在CANape中插入离线转在线要校验要校验的RAM区域
*/
/*----------------------------------------------------------------------------*/


/************9、定义CRC校验*************/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/

/************10、定义Flash 编程功能*************/
/*----------------------------------------------------------------------------*/
/* Activate the flash programming kernel download feature */
/* This is a CCP extension for CANape */
/* #define CCP_BOOTLOADER_DOWNLOAD */
#define CCP_BOOTLOADER_DOWNLOAD
#define CCP_PROGRAM
/*
两种方法对Flash进行编程
1、#define CCP_PROGRAM，然后自己编写对Flash编程的函数，包括：
   ccpFlashClear,ccpFlashProgramm,ccpSetCalPage， CANape中Flash entry设为"derect"
2、利用FlashKernel，在CANape中选择对应的控制器类型的fkl文件
   启用FlashKernel：#define CCP_BOOTLOADER_DOWNLOAD
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
/*#define CCP_CHECKSUM_CCITT*/     //允许CRC 校验功能
/*#define CCP_MOTOROLA*/          //前端已经定义CCP_MOTOROLA
 /*********************************
CANape,Options|Driver parameters.Go to tab CCP Parameters. Set the
corresponding calculation algorithm.
**********************************/


//#define  CCP_CHECKSUM_BLOCKSIZE    //改变CRC校验的块的大小,不定义，则256
/*************************************************
由于实时性的要求，checksum不会在ccpCommand()中运算，
将先被分成块（大小CCP_CHECKSUM_BLOCKSIZE），
然后分别在ccpBackground()中运算
*************************************************/

/* Check for pending CCP commands in ccpBackground() */
/* #ifdef CCP_CMD_NOT_IN_INTERRUPT */

/* MACRO_ENABLE Memory Write Protection */
/* #define CCP_WRITE_PROTECTION*/

/* MACRO_ENABLE EEPROM Read/Write Access */
/* #define CCP_WRITE_EEPROM */
/* #define CCP_READ_EEPROM */

#endif
