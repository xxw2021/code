#include "Allh.h"

#define DUMMY_DATA 0xFF

uchar CCS_isActive;
uchar PCC_isActive;
uchar CCS_state_Last;

ccs_off_reason_t CCS_OffReason = UNKNOW_REASON; // CCS shut off reason
uchar CCS_numCurrGear;
uint CCS_kmphSetSpeed;
uint CCS_kmphSetSpeed_Last;

pcc_off_reason_t PCC_OffReason = UNKNOW_REASON; // PCC shut off reason
int PCC_nmNextSegTrq;
uint PCC_msNextSegTime;
uchar PCC_numRcmdGear;
uchar PCC_kmphExitSpeed; 

uchar s32k144_tx_buf[4];
uchar s32k144_rx_buf[4];

void S32K144_Init(void)//
{
//
  //CCS_isActive = FALSE; 
  CCS_state_Last = 0;
  PCC_isActive = FALSE;
  CCS_kmphSetSpeed = 0xFFFF;   
  PCC_numRcmdGear = 0xFF;
  //g_ccs_tgt_spd = 0xaabb;
  PCC_nmNextSegTrq = 0xFFFF;
  PCC_msNextSegTime = 0xFFFF;   
}//

/*
uchar func_CRC8(uchar *pBuffer, int length) 
{
  uchar crc8=0;
  uchar i;
  
  if (( NULL == pBuffer )||( 0 == length ))
  {
    return 0;
  }
  
  while (length--)
  {
    crc8 ^= *pBuffer++;
    for(i = 0;i < 8;i++)
    {
      if(crc8 & 0x80)
      {
        crc8 = (crc8 << 1) ^ 0x31;
      }
      else 
        crc8 <<= 1;
    }
  }
  return crc8;
}
*/

uchar func_ModCheck(uchar *pBuffer, int length)//校验
{
    uchar tmp = 0;
    while (length--)
    {
        tmp += (tmp + *pBuffer++) % 16;

    }
    return (uchar)tmp%16; 
}

void func_FormatFrame(uchar cmdID, uchar nDataLen, uchar *pDataContent, uchar *pFrameBuf)//给报文发送缓冲区赋值
{
    *pFrameBuf = 0xE0 | cmdID;
    // memcpy(pFrameBuf, pDataContent, nDataLen);
    *(pFrameBuf+1) = *pDataContent;
    *(pFrameBuf+2) = *(pDataContent+1);
    *(pFrameBuf+3) = *(pDataContent+2) << 4 | func_ModCheck(pDataContent, 3);
}

unsigned long S32K144_Transfer(uchar *pDataTx, uint *pDataRx)  //9S12SP发送、中断接收程序
{
  uint tx_dataBuf;
  uint rx_dataBuf;
  
  uchar i=0;
  schar j=0;
  
  /*uchar spicmd[8];
  spicmd[0] = 0xE9;
  spicmd[1] = cmdID;
  memcpy(&spicmd[2], pDataContent, 4);
  spicmd[6] = func_CRC8(&spicmd[1], 5);
  spicmd[7] = 0xFE;
  */
  
  PTH_PTH3=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  PTH_PTH3=0;

  //for ( j=0; j<4; j+=2 )
  for ( j=3; j >= 0; j-=2 )
  {
  
    i=0;
    //tx_dataBuf = (s32k144_tx_buf[j] << 8) | s32k144_tx_buf[j+1];
    tx_dataBuf = (s32k144_tx_buf[j] << 8) | s32k144_tx_buf[j-1];
	do
	{
	  i++;
	}
	while(SPI1SR_SPTEF==0 && i<100); //check tx_dataBuf SPI状态寄存器中断标志位
	SPI1DR= tx_dataBuf;        //write tx_dataBuf	
	i=0;
	do
	{
		i++;
	}
	while(SPI1SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	//*(uint *)(s32k144_rx_buf+j)=SPI1DR;              //return rx_dataBuf
  rx_dataBuf = SPI1DR;
  s32k144_rx_buf[j] = (uchar)(rx_dataBuf >> 8);
  s32k144_rx_buf[j-1] = (uchar)(rx_dataBuf & 0xFF);
  
  }

  PTH_PTH3=1;
}

unsigned long S32K144_Transfer_Char(uchar *pDataTx, uint *pDataRx) 
{
  //
  uchar i=0;
  schar j=0;
  
  PTH_PTH3=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  PTH_PTH3=0;

  for ( j = 4; j > 0; j-- )
  {
    i=0;
    do
    {
      i++;
    }
    while(SPI1SR_SPTEF==0&&i<100);//check tx_dataBuf
    SPI1DR=*(pDataRx+j-1);              //write tx_dataBuf
    
    i=0;
    do
    {
      i++;
    }
    while(SPI1SR_SPIF==0&&i<100);  //check rx_dataBuf
    *(pDataTx+j-1)=(uchar)SPI1DR;                  //return rx_dataBuf
  }
  
  PTH_PTH3=1;
    return;                  //return rx_dataBuf
}//

void S32K144_SetCCSSpd(uint ccs_tgtspd) //把CCS设定的目标车速发送到S32K144
{
    uchar DataContent[3] = {0};
    DataContent[0] = (uchar)(ccs_tgtspd >> 8);
    DataContent[1] = (uchar)ccs_tgtspd;
    DataContent[2] = CrCtl_enPCC_UB;//DUMMY_DATA;
    func_FormatFrame(CCS_SET_TGT_SPD, 3, DataContent, s32k144_tx_buf);//给报文发送缓冲区赋值
    S32K144_Transfer(s32k144_rx_buf, s32k144_tx_buf);
    //S32K144_Transfer_Char(s32k144_rx_buf, s32k144_tx_buf);
}
void S32K144_SetMFLvState(void) //robin add 190717
{
    uchar DataContent[3] = {0};
    uchar MFLv_State;
    DataContent[0] =  0x55; // DUMMY_DATA
    DataContent[1] =  0xaa; // DUMMY_DATA;(uchar)ccs_tgtspd;
    DataContent[2] =  0x80;//
    DataContent[2] =  DataContent[2] || (MFLv_setUpBL<<7); //MFLV状态发送
  //DataContent[2] =  DataContent[2] || (MFLv_setDownBL<<6);
 // DataContent[2] =  DataContent[2] || MFLv_resBL<<5;
 // DataContent[2] =  DataContent[2] || MFLv_swtBL<<4;
    
    func_FormatFrame(CCS_MFLV_STATE, 3, DataContent, s32k144_tx_buf);//给报文发送缓冲区赋值
    
    S32K144_Transfer(s32k144_rx_buf, s32k144_tx_buf);
}
void S32K144_GetCCSState(uint Instruction_control) //robin add 190717 
{
   uchar DataContent[3] = {0};
   
   
   
}
void S32K144_SetCCSOff(uchar Tx_Data)//把CCS退出原因发送到S32K144 
{
    uchar DataContent[3] = {0};
    DataContent[0] = 0x55; // DUMMY_DATA;
    DataContent[1] = 0xaa; // DUMMY_DATA;
    DataContent[2] = DUMMY_DATA & 0xF0;
    func_FormatFrame(CCS_SET_OFF_RSN, 3, DataContent, s32k144_tx_buf);
    S32K144_Transfer(s32k144_rx_buf, s32k144_tx_buf);
}

uint S32K144_GetPCCSpd(uint Tx_Data) 
{
    uchar cmdRx = 0xF;

    uchar DataContent[3] = {0};
    DataContent[0] = 0x55; // DUMMY_DATA;
    DataContent[1] = 0xaa; // DUMMY_DATA;
    DataContent[2] = (uchar)CCS_OffReason; //DUMMY_DATA & 0xF0;
    func_FormatFrame(PCC_NEXT_SEG_SPD, 3, DataContent, s32k144_tx_buf); 
    S32K144_Transfer(s32k144_rx_buf, s32k144_tx_buf);

    // verify if PCC is on and get PCC target speed
    if ((s32k144_rx_buf[0] & 0xF0) == 0xE0)
    {
        cmdRx = s32k144_rx_buf[0] & 0x0F; 
        //判断接收到的cmdID
        if (cmdRx == PCC_OFF_RSN)
        {
            PCC_isActive = FALSE;
            CCS_kmphSetSpeed = 0xFFFF;
            PCC_numRcmdGear = 0x0F;
        } else if (cmdRx == PCC_NEXT_SEG_SPD) //接收正确
        {
            PCC_isActive = TRUE;
            CCS_kmphSetSpeed = (s32k144_rx_buf[1]) << 8 | s32k144_rx_buf[2];
            PCC_numRcmdGear = s32k144_rx_buf[3] >> 4;
        }
    }                                                               
}                                                               

uint S32K144_GetPCCRslt(uint Tx_Data) 
{
    uchar cmdRx = 0xF;

    uchar DataContent[3] = {0};
    DataContent[0] = (uchar)(Tx_Data >>8);//0x55; // DUMMY_DATA;
    DataContent[1] = (uchar)Tx_Data;//0xaa; // DUMMY_DATA;
    DataContent[2] = (uchar)CrCtl_enPCC_UB; //DUMMY_DATA & 0xF0;
    func_FormatFrame(CCS_GET_PCC_RSLT, 3, DataContent, s32k144_tx_buf);
    S32K144_Transfer(s32k144_rx_buf, s32k144_tx_buf);

    // verify if PCC is on and get PCC target speed
    if ((s32k144_rx_buf[0] & 0xF0) == 0xE0)
    {
        cmdRx = s32k144_rx_buf[0] & 0x0F;
        if (cmdRx == PCC_OFF_RSN)
        {
            PCC_isActive = FALSE;
            PCC_nmNextSegTrq = 0xFFFF;
            PCC_msNextSegTime = 0xFFFF;
            PCC_kmphExitSpeed = s32k144_rx_buf[1]; 
            PCC_OffReason = s32k144_rx_buf[3] >> 4;
        } else if (cmdRx == PCC_NEXT_SEG_TOR)
        {
            PCC_isActive = TRUE;
            //PCC_nmNextSegTrq = (s32k144_rx_buf[1]) << 8 | s32k144_rx_buf[2];
            PCC_nmNextSegTrq = s32k144_rx_buf[2];
            PCC_numRcmdGear = s32k144_rx_buf[3] >> 4;
            PCC_OffReason = 0;
        } else if (cmdRx == PCC_NEXT_SEG_TIME) 
        {
            PCC_isActive = TRUE;
            PCC_msNextSegTime = (s32k144_rx_buf[1]) << 8 | s32k144_rx_buf[2];
            PCC_numRcmdGear = s32k144_rx_buf[3] >> 4;
        }
    }                                                               
}  

//uint S32K144_GetPCCRslt(uchar *enable_flag, uchar *step_idx, uchar *para_idx, uint *ret_value) 
//{}

/*
uint16 s32k144cmd;
uint16 s32k144data;
uint16 s32k144cmd_tx = 0;
uint16 s32k144data_tx = 16;
//====================================
unsigned long S32K144_Tx_CMD(unsigned int Tx_CMD,unsigned int Tx_Data)//
{
  //
  uchar i=0;
  
  uint32  rxCMD;
  uint32  rxDATA;
  uint32 rxlong;  
  
	PTH_PTH3=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  PTH_PTH3=0;

  i=0;
	do
	{
	  i++;
	}
	while(SPI1SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI1DR=Tx_CMD;        //write tx_dataBuf	
	
	i=0;
	do
	{
		i++;
	}
	while(SPI1SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxCMD=SPI1DR;              //return rx_dataBuf

  
  i=0;
	do
	{
	  i++;
	}
	while(SPI1SR_SPTEF==0 && i<100); //check tx_dataBuf
	SPI1DR=Tx_Data;        //write tx_dataBuf
	
	i=0;
	do
	{
		i++;
	}
	while(SPI1SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxDATA=SPI1DR;              //return rx_dataBuf


  rxlong = rxCMD*256 + rxDATA/256;

  s32k144cmd = rxCMD;
  s32k144data = rxDATA;

  PTH_PTH3=1; 

  return rxlong;
}//

uint16 SPIS32K144_Tx_Word(uint16 txdata)
{
	uchar i;
	uint16 rxdata;

	PTH_PTH3=1;
  asm nop;
  asm nop;
  asm nop;
  asm nop;
  PTH_PTH3=0;

  i=0;
	do
	{
	  i++;
	}
	while(SPI1SR_SPTEF==0 && i<100); //check tx_dataBuf
	i=0;
	SPI1DR=txdata;        //write tx_dataBuf
	
	do
	{
		i++;
	}
	while(SPI1SR_SPIF==0 && i<100); //check rx_dataBuf
	i=0;
	rxdata=SPI1DR;              //return rx_dataBuf
	
	PTH_PTH3=1; 
	
	return rxdata;
}
*/

uint spd = 0;
void S32K144_SPI_Process(void)//
{
    if (1 == CrCtl_enPCC_UB || 2 == CrCtl_enPCC_UB)
    {
        //CCS_state_Last = CrCtl_enPCC_UB;
        if ((CCS_state_Last != CrCtl_enPCC_UB) || (CCS_kmphSetSpeed_Last != CrCtl_vSetPointTrgt_kmphUB))
        {
            S32K144_SetCCSSpd(CrCtl_vSetPointTrgt_kmphUB);
            CCS_kmphSetSpeed_Last = CrCtl_vSetPointTrgt_kmphUB;
            CCS_state_Last = CrCtl_enPCC_UB;
        } else {
            S32K144_GetPCCRslt(CrCtl_vSetPointTrgt_kmphUB); 
        }

    } else {
        if ((CCS_state_Last != CrCtl_enPCC_UB))
        {
            S32K144_SetCCSOff(CCS_OffReason);
            CCS_state_Last = CrCtl_enPCC_UB;
        } else {
            S32K144_GetPCCRslt(CrCtl_vSetPointTrgt_kmphUB); 
        }
       
    }
  //spd += 1;
  //S32K144_SetCCSSPD(spd);
  //S32K144_GetPCCRslt(PCC_nmNextSegTrq); 
}//
