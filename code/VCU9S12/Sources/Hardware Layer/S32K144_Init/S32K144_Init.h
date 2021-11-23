#ifndef _S32K144_INIT_H_
#define _S32K144_INIT_H_

#define   CCS_SET_OFF_RSN   0b0100     //cmdID
#define   CCS_SET_TGT_SPD   0b0101     //cmdID
#define   CCS_GET_PCC_RSLT   0b0110    //cmdID
     
#define   PCC_OFF_RSN        0b1000   //cmdID                                                                             
#define   PCC_NEXT_SEG_SPD   0b1001   //cmdID
#define   PCC_NEXT_SEG_TOR   0b1001   //cmdID
#define   PCC_NEXT_SEG_TIME  0b1010   //cmdID

#define   CCS_MFLV_STATE     0b1011   //cmdID



typedef enum {
    CRCTL_NOSHOFFCONACTV = 0x0U,
    CRCTL_CUT,
    CRCTL_RMPONE,
    CRCTL_RMPTWO,
    CRCTL_GEAR_CHANGE,
    UNKNOW_REASON = 0xFU
 } ccs_off_reason_t;

typedef enum {
    PCC_UNKNOW_REASON = 0xFU
} pcc_off_reason_t;

extern uchar PCC_isActive;
extern int PCC_nmNextSegTrq;
extern uchar PCC_kmphExitSpeed;
/*
typedef struct PCC_SPI_COMMAND
{       
  uchar FrameHead;         //Frame head = 0xE9
  uchar CmdID;             //Cmd Type
  uchar DataContent[4];    //
  uchar FrameCRC;          //CRC
  uchar FrameTail;         //Frame tail = 0xFE
}PCCspiCommand;
*/

uint16 SPIS32K144_Tx_Word(uint16 txdata);

extern pcc_off_reason_t PCC_OffReason;    //added by xmy 20190617

#endif
