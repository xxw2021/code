#include "Allh.h"





               
unsigned char  ECUTSC1_stEngOverrideCtrlMdUB;
unsigned int   ECUTSC1_rpmSpdDmdLmtUW;
unsigned char  ECUTSC1_pctTrqDmdLmtUB;
signed char    ECUTSC1_pctTrqDmdLmtSB; //added by Leo

//----------------------------CCVS---------------------------------
//robin add 190711
unsigned char ECUCCVSTX_swTwoSpdAxleSWUB;
unsigned char ECUCCVSTX_swParkingBrakeSWUB;
unsigned char ECUCCVSTX_swCCSPauseSWUB;
unsigned int  ECUCCVSTX_kmphWheelBasedVehSpdIUW;
unsigned char ECUCCVSTX_stCCSActiveUB;
unsigned char ECUCCVSTX_stCCSEnableSWUB;
unsigned char ECUCCVSTX_swBrakeSWUB;
unsigned char ECUCCVSTX_swClutchSWUB;
unsigned char ECUCCVSTX_swCCSSetSWUB;
unsigned char ECUCCVSTX_swCCSCoastSWUB;
unsigned char ECUCCVSTX_swCCSResumeSWUB;
unsigned char ECUCCVSTX_swCCSAccelSWUB;
unsigned char ECUCCVSTX_kmphCCSSetSpdUB;		
unsigned char ECUCCVSTX_stCCSPTOStUB; 		
unsigned char ECUCCVSTX_stCCSCtlStUB;		
unsigned char ECUCCVSTX_swEngIdleIncrementSWUB;
unsigned char ECUCCVSTX_swEngIdleDecrementSWUB;
unsigned char ECUCCVSTX_swEngTestMdSWUB;
unsigned char ECUCCVSTX_swEngShutdownOrSWUB;// robin修改添加190624
//----------------------------PCC---------------------------------
//robin add 190711
unsigned char ECUPCC_kmphForwardVehicleSpdUB;
unsigned char ECUPCC_mDistanceToForwardVehicleUB;
unsigned char ECUPCC_kmphACCSetSpdUB;
unsigned char ECUPCC_stACCModeUB;
unsigned char ECUPCC_mACCSetDistanceUB;
unsigned char ECUPCC_stRoadCurvatureUB;
unsigned char ECUPCC_stPCCStateUB;
unsigned char ECUPCC_stACCShutoffWarningUB;
unsigned char ECUPCC_stACCDisAlertUB;  // robin修改添加190708
//----------------------------TC1---------------------------------
//robin add 190711
unsigned char    TransGearShiftInhibitRqUB;         
unsigned char    TorqueConverterLockupDisableRqUB;  
unsigned char    DisengageDrivelineRqUB;  
unsigned char    RqedPercentClutchSlipUB;        
unsigned char    TransRqedGearUB;                  
unsigned char    DisengageDiffLockRqFrontAxle1UB;  
unsigned char    DisengageDiffLockRqRearAxle1UB; 
unsigned char    DisengageDiffLockRqRearAxle2UB; 
unsigned char    DisengageDiffLockRqCentralUB;     
unsigned char    DisengageDiffLockRqCentralFrontUB; 
unsigned char    DisengageDiffLockRqCentralRearUB;  
unsigned char    TransMode1UB;                     
unsigned char    TransMode2UB;                
unsigned char    TransMode3UB;                  
unsigned char    TransMode4UB;             
unsigned char    TrnsShftSlctorDisplayModeSwitchUB;    // robin修改添加190708



unsigned char EngTsk_numSpdTrqlmtUB;

unsigned char  ECUEBC1_stEngShutDownSWUB;


unsigned char CANTxAllow_stECUTSC1UB;
unsigned char CANTxAllow_stRtdrTSC1UB; //added by Leo
unsigned char CANTxAllow_stECUEBC1UB;
unsigned char CANTxAllow_stECUCCVSUB;
unsigned char CANTxAllow_stECUPCCUB;
unsigned char CANTxAllow_stECUTC1UB;

void CANTxECU_ValueInit(void)//
{
  //
  ECUTSC1_stEngOverrideCtrlMdUB = 0;
  ECUTSC1_rpmSpdDmdLmtUW = 0;
  ECUTSC1_pctTrqDmdLmtUB = 0;
  
  ECUEBC1_stEngShutDownSWUB = 0;
  
   //----------------------------CCVS---------------------------------
  ECUCCVSTX_swTwoSpdAxleSWUB = 0;
  ECUCCVSTX_swParkingBrakeSWUB = 0;
  ECUCCVSTX_swCCSPauseSWUB = 0;
  ECUCCVSTX_kmphWheelBasedVehSpdIUW = 0;
  ECUCCVSTX_stCCSActiveUB = 0;
  ECUCCVSTX_stCCSEnableSWUB = 0;
  ECUCCVSTX_swBrakeSWUB = 0;
  ECUCCVSTX_swClutchSWUB = 0;
  ECUCCVSTX_swCCSSetSWUB = 0;
  ECUCCVSTX_swCCSCoastSWUB = 0;
  ECUCCVSTX_swCCSResumeSWUB = 0;
  ECUCCVSTX_swCCSAccelSWUB = 0;
  ECUCCVSTX_kmphCCSSetSpdUB = 0;		
  ECUCCVSTX_stCCSPTOStUB = 0; 		
  ECUCCVSTX_stCCSCtlStUB = 0;		
  ECUCCVSTX_swEngIdleIncrementSWUB = 0;
  ECUCCVSTX_swEngIdleDecrementSWUB = 0;
  ECUCCVSTX_swEngTestMdSWUB = 0;
  ECUCCVSTX_swEngShutdownOrSWUB = 0;//CCVS报文参数值初始化_robin修改添加
   //----------------------------PCCState---------------------------------
  ECUPCC_kmphForwardVehicleSpdUB= 0;
  ECUPCC_mDistanceToForwardVehicleUB= 0;
  ECUPCC_kmphACCSetSpdUB= 0;
  ECUPCC_stACCModeUB= 0;
  ECUPCC_mACCSetDistanceUB= 0;
  ECUPCC_stRoadCurvatureUB= 0;
  ECUPCC_stPCCStateUB= 0;
  ECUPCC_stACCShutoffWarningUB= 0;
  ECUPCC_stACCDisAlertUB= 0;  // robin190708
  //----------------------------TC1---------------------------------------
  TransGearShiftInhibitRqUB= 0;         
  TorqueConverterLockupDisableRqUB= 0;  
  DisengageDrivelineRqUB= 0;  
  RqedPercentClutchSlipUB= 0;        
  TransRqedGearUB= 0;                  
  DisengageDiffLockRqFrontAxle1UB= 0;  
  DisengageDiffLockRqRearAxle1UB= 0; 
  DisengageDiffLockRqRearAxle2UB= 0; 
  DisengageDiffLockRqCentralUB= 0;     
  DisengageDiffLockRqCentralFrontUB= 0; 
  DisengageDiffLockRqCentralRearUB= 0;  
  TransMode1UB= 0;                     
  TransMode2UB= 0;                
  TransMode3UB= 0;                  
  TransMode4UB= 0;             
  TrnsShftSlctorDisplayModeSwitchUB= 0;  //robin修改添加190710
  
  CANTxAllow_stECUTSC1UB = 0;
  CANTxAllow_stECUEBC1UB = 0; 
  
  CANTxAllow_stECUCCVSUB= 1;//robin add 190711 //测试设置，如有需求初始化为0
  CANTxAllow_stECUPCCUB= 1; //robin add 190711
  CANTxAllow_stECUTC1UB= 1; //robin add 190711
  
}//




void CANTx2ECU_10ms(void)//
{
  //   
  if(CANTxAllow_stECUTSC1UB == 1)//
  {
    // 
    
    ECUCAN_InterfaceOut_TSC1Update();    
    
    CANTxErr_stECUTSC1UB = CANMain_TX(CANIDBuf_TSC1,CANPBuf_TSC1,CANLBuf_TSC1,(unsigned char *)TxCANBuf_TSC1);
  }
}//

//TSC1 RR 控负扭矩 用于锡柴发动机 added by Leo
void CANTx2Rtdr_50ms(void)
{
	//   
	if (CANTxAllow_stRtdrTSC1UB == 1)//
	{
		// 

		ECUCAN_InterfaceOut_TSC1Update();

		CANTxErr_stECUTSC1UB = CANMain_TX(CANIDBuf_TSC1_RR, CANPBuf_TSC1, CANLBuf_TSC1, (unsigned char *)TxCANBuf_TSC1);
	}
}//



//TSC1 TE 控正扭矩 潍柴 added by Leo
void CANTx2ECUWc_10ms(void)
{
	//   
	if (CANTxAllow_stECUTSC1UB == 1)//
	{
		// 

		ECUCAN_InterfaceOutWc_TSC1Update();

		CANTxErr_stECUTSC1UB = CANMain_TX(CANIDBuf_TSC1_TE, CANPBuf_TSC1, CANLBuf_TSC1, (unsigned char *)TxCANBuf_TSC1);
	}
}//


//TSC1 VR 控负扭矩 用于潍柴发动机 added by Leo
void CANTx2RtdrWc_50ms(void)
{
	//   
	if (CANTxAllow_stRtdrTSC1UB == 1)//
	{
		// 

		ECUCAN_InterfaceOutWc_TSC1Update();

		CANTxErr_stECUTSC1UB = CANMain_TX(CANIDBuf_TSC1_VR, CANPBuf_TSC1, CANLBuf_TSC1, (unsigned char *)TxCANBuf_TSC1);
	}
}//

void CANTx2ECU_50ms(void)  // TC1 50ms发送修改robin190711
{
	if (CANTxAllow_stECUTC1UB == 1)
	{
      ECUCAN_InterfaceOut_TC1Update();//robin190708修改添加    
      CANTxErr_stECUTC1UB = CANMain_TX(CANIDBuf_TC1,CANPBuf_TC1,CANLBuf_TC1,(unsigned char *)TxCANBuf_TC1);
	}
}



void CANTx2ECU_100ms(void)//
{
  uint8_T txEmptyBuf;  //robin修改添加
 
  if(CANTxAllow_stECUEBC1UB == 1)//
  {
    // 
    
       ECUCAN_InterfaceOut_EBC1Update();    
    
       //CANTxErr_stECUEBC1UB = CANMain_TX(CANIDBuf_EBC1,CANPBuf_EBC1,CANLBuf_EBC1,(unsigned char *)TxCANBuf_EBC1);
  }
  //   
 
//robin add 190711
 if(CANTxAllow_stECUCCVSUB == 1)//
  {
        ECUCAN_InterfaceOut_CCVSUpdate();
        CANTxErr_stECUCCVSUB = CANMain_TX(CANIDBuf_CCVS,CANPBuf_CCVS,CANLBuf_CCVS,(unsigned char *)TxCANBuf_CCVS);//修改添加
  }
//寻找空闲缓冲区 robin190711
do
   {
         CAN0TBSEL= CAN0TFLG;
         txEmptyBuf= CAN0TBSEL;
   }
while(!txEmptyBuf); //robin190711修改添加 TFL为1发送缓冲区为空
if(CANTxAllow_stECUPCCUB == 1)
   {
        ECUCAN_InterfaceOut_PCCUpdate();//ACC1 robin190708修改添加
        CANTxErr_stECUPCCUB = CANMain_TX(CANIDBuf_PCC,CANPBuf_PCC,CANLBuf_PCC,(unsigned char *)TxCANBuf_PCC);//修改添}加
   }
  
  
  
}//








void ECUCAN_InterfaceOut_EBC1Update(void)//
{
  //
  Btm_ECUEBC1_EngShutDown_Byte0 = 0xff;             
  Btm_ECUEBC1_EngShutDown_Byte1 = 0xff;             
  Btm_ECUEBC1_EngShutDown_Byte2 = 0xff;            

  Btm_ECUEBC1_EngShutDown_41Bits = 3;           
  Btm_ECUEBC1_EngShutDown_42Bits = 3;                          
  Btm_ECUEBC1_EngShutDown_44Bits = 3;            

  Btm_ECUEBC1_EngShutDown_Byte4 = 0xff;             
  Btm_ECUEBC1_EngShutDown_Byte5 = 0xff;             
  Btm_ECUEBC1_EngShutDown_Byte6 = 0xff;             
  Btm_ECUEBC1_EngShutDown_Byte7 = 0xff;             


  if(ECUEBC1_stEngShutDownSWUB == 1)//
  {
    //
    Btm_ECUEBC1_EngShutDown_2Bits = 1;
  }//
  else//
  {
    //
    Btm_ECUEBC1_EngShutDown_2Bits = 0;
  }// 
}//














void ECUCAN_InterfaceOut_TSC1Update(void)//
{
  //
  Btm_ECUTSC1_EngORCtlMd_2Bits=ECUTSC1_stEngOverrideCtrlMdUB;
  
  if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_CtrlOff)//释放控制
  {
    //
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
    Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = 0xfa;
  }//
  else if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_SpdCtrl)//转速控制
  {
    //
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = ((ECUTSC1_rpmSpdDmdLmtUW*8)/256);
    Btm_ECUTSC1_EngRqedSpdlmt_LByte = ((ECUTSC1_rpmSpdDmdLmtUW*8)%256); 
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = 0xfa; 
  }//
  else if((ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_TrqCtrl))//
  {
    //
    //Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
    //Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
    //Btm_ECUTSC1_EngRqedTrqlmt_Byte = ECUTSC1_pctTrqDmdLmtUB + 125;
    
    //因实验车ECU J1939报文不标准故将代码改为以下方式
    Btm_ECUTSC1_EngRqedSpdConditions_2Bits = 0;
    Btm_ECUTSC1_ORCtlMdP_2Bits = 0;
    Btm_ECUTSC1_EngRqedSpdlmt_LByte  = 0xFF;
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xFF;
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = ECUTSC1_pctTrqDmdLmtSB + 125;
    Btm_ECUTSC1_TransmissionRate_3Bits = 0xFF;
    Btm_ECUTSC1_CtlPurp_5Bits = 0xFF;
    Btm_ECUTSC1_EngRqedTrqHiRes_4Bits = 0xFF;
    Btm_ECUTSC1_MsgCout_4Bits = 0xFF;
    Btm_ECUTSC1_MsgChecksum_4Bits = 0xFF;
  }//
  else if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_SpdTrqlmt)//限制模式
  {
    //
    //判断是转速限制还是扭矩限制
    if(EngTsk_numSpdTrqlmtUB == 1)//
    {
      //
      Btm_ECUTSC1_EngRqedSpdlmt_HByte= ((ECUTSC1_rpmSpdDmdLmtUW*8)/256);
      Btm_ECUTSC1_EngRqedSpdlmt_LByte= ((ECUTSC1_rpmSpdDmdLmtUW*8)%256); 
      Btm_ECUTSC1_EngRqedTrqlmt_Byte=0xfa;
    }//
    else if(EngTsk_numSpdTrqlmtUB == 2)//
    {
      //
      Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
      Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
      Btm_ECUTSC1_EngRqedTrqlmt_Byte=(ECUTSC1_pctTrqDmdLmtUB+125);
    }//
    else//
    {
      //
    }//
  }//
  else//
  {
    //
  }//   
}//

//潍柴发动机 added by Leo
void ECUCAN_InterfaceOutWc_TSC1Update(void)//
{
  //
  Btm_ECUTSC1_EngORCtlMd_2Bits=ECUTSC1_stEngOverrideCtrlMdUB;
  
  if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_CtrlOff)//释放控制
  {
    //
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
    Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = 0xfa;
  }//
  else if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_SpdCtrl)//转速控制
  {
    //
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = ((ECUTSC1_rpmSpdDmdLmtUW*8)/256);
    Btm_ECUTSC1_EngRqedSpdlmt_LByte = ((ECUTSC1_rpmSpdDmdLmtUW*8)%256); 
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = 0xfa; 
  }//
  else if((ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_TrqCtrl))//
  {
    //
    //Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
    //Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
    //Btm_ECUTSC1_EngRqedTrqlmt_Byte = ECUTSC1_pctTrqDmdLmtUB + 125;
    
    //因实验车ECU J1939报文不标准故将代码改为以下方式
    Btm_ECUTSC1_EngRqedSpdConditions_2Bits = 0;
    Btm_ECUTSC1_ORCtlMdP_2Bits = 0;
    Btm_ECUTSC1_EngRqedSpdlmt_LByte  = 0x00;
    Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0x00;
    Btm_ECUTSC1_EngRqedTrqlmt_Byte = ECUTSC1_pctTrqDmdLmtSB + 125;
    Btm_ECUTSC1_TransmissionRate_3Bits = 0x00;
    Btm_ECUTSC1_CtlPurp_5Bits = 0x00;
    Btm_ECUTSC1_EngRqedTrqHiRes_4Bits = 0x00;
    Btm_ECUTSC1_MsgCout_4Bits = 0x00;
    Btm_ECUTSC1_MsgChecksum_4Bits = 0x00;
  }//
  else if(ECUTSC1_stEngOverrideCtrlMdUB ==  EngCtrlMd_SpdTrqlmt)//限制模式
  {
    //
    //判断是转速限制还是扭矩限制
    if(EngTsk_numSpdTrqlmtUB == 1)//
    {
      //
      Btm_ECUTSC1_EngRqedSpdlmt_HByte= ((ECUTSC1_rpmSpdDmdLmtUW*8)/256);
      Btm_ECUTSC1_EngRqedSpdlmt_LByte= ((ECUTSC1_rpmSpdDmdLmtUW*8)%256); 
      Btm_ECUTSC1_EngRqedTrqlmt_Byte=0xfa;
    }//
    else if(EngTsk_numSpdTrqlmtUB == 2)//
    {
      //
      Btm_ECUTSC1_EngRqedSpdlmt_HByte = 0xfa;
      Btm_ECUTSC1_EngRqedSpdlmt_LByte = 0xff; 
      Btm_ECUTSC1_EngRqedTrqlmt_Byte=(ECUTSC1_pctTrqDmdLmtUB+125);
    }//
    else//
    {
      //
    }//
  }//
  else//
  {
    //
  }//   
}//

void ECUCAN_InterfaceOut_CCVSUpdate(void) //CCVS变量更新
{
  //
  //if(CAN_OutputUpdt_stECUCCVSUB == 1)//
  {
    //
    Btm_ECUCCVSTX_TwoSpdAxleSW_2Bits= ECUCCVSTX_swTwoSpdAxleSWUB;
    Btm_ECUCCVSTX_ParkingBrakeSW_2Bits= ECUCCVSTX_swParkingBrakeSWUB;
    Btm_ECUCCVSTX_CCSPauseSW_2Bits= ECUCCVSTX_swCCSPauseSWUB;
    //(Btm_ECUCCVS_WheelBasedVehSpd_HByte*256+Btm_ECUCCVS_WheelBasedVehSpd_LByte)/256= ECUCCVS_kmphWheelBasedVehSpdIUW; //分辨率1/256(km/h) 偏移量0
    Btm_ECUCCVSTX_WheelBasedVehSpd_HByte= ECUCCVS_kmphWheelBasedVehSpdIUW>>8;
    Btm_ECUCCVSTX_WheelBasedVehSpd_LByte= ECUCCVS_kmphWheelBasedVehSpdIUW;
    Btm_ECUCCVSTX_CCSActive_2Bits= CrCtl_stActive_BL;//CCS激活状态      原定义ECUCCVS_stCCSActiveUB
    Btm_ECUCCVSTX_CCSEnableSW_2Bits= MFLv_swtBL;   //OFF-ON开关                    ECUCCVS_stCCSEnableSWUB
    Btm_ECUCCVSTX_BrakeSW_2Bits= ECUCCVSTX_swBrakeSWUB;
    Btm_ECUCCVSTX_ClutchSW_2Bits= ECUCCVSTX_swClutchSWUB;
    Btm_ECUCCVSTX_CCSSetSW_2Bits= MFLv_setDownBL; // SET-键                        ECUCCVS_swCCSSetSWUB;
    Btm_ECUCCVSTX_CCSCoastSW_2Bits= MFLv_setUpBL; // SET+键                        ECUCCVS_swCCSSetSWUB;
    Btm_ECUCCVSTX_CCSResumeSW_2Bits= MFLv_resBL;  //RESUME键                       ECUCCVS_swCCSResumeSWUB
    Btm_ECUCCVSTX_CCSAccelSW_2Bits= ECUCCVSTX_swCCSAccelSWUB;
    Btm_ECUCCVSTX_CCSSetSpd_Byte= CrCtl_vSetPointTrgtIn_10mphUW; //CCS设定车速     ECUCCVS_kmphCCSSetSpdUB      
    Btm_ECUCCVSTX_CCSPTOSt_5DBits= ECUCCVSTX_stCCSPTOStUB;         //                接收用:Btm_ECUCCVS_CCSPTOSt_5DBits= Btm_ECUCCVS_CCSPTOSt_5DBits%32
    Btm_ECUCCVSTX_CCSCtlSt_3DBits= CrCtl_stModeIn_UB<<5;         //CCS状态         ECUCCVS_stCCSCtlStUB= Btm_ECUCCVS_CCSCtlSt_3DBits/32
    Btm_ECUCCVSTX_EngIdleIncrementSW_2Bits= ECUCCVSTX_swEngIdleIncrementSWUB;
    Btm_ECUCCVSTX_EngIdleDecrementSW_2Bits= ECUCCVSTX_swEngIdleDecrementSWUB;
    Btm_ECUCCVSTX_EngTestMdSW_2Bits= ECUCCVSTX_swEngTestMdSWUB;
    Btm_ECUCCVSTX_EngShutdownOrSW_2Bits= ECUCCVSTX_swEngShutdownOrSWUB;
    
  }//   
}//robin190624

void ECUCAN_InterfaceOut_PCCUpdate(void) //PCC变量更新
{
   Btm_ECUPCC_ForwardVehicleSpeed_Byte= PCC_NEXT_SEG_SPD;//PCC目标车速 原ECUPCC_kmphForwardVehicleSpdUB;               
   Btm_ECUPCC_ForwardVehicleDistance_Byte= ECUPCC_mDistanceToForwardVehicleUB;             
   Btm_ECUPCC_ACCSetSpd_Byte= ECUPCC_kmphACCSetSpdUB;                         
   Btm_ECUPCC_ACCMode_3Bits= ECUPCC_stPCCStateUB;  // PCC状态 ECUPCC_stACCModeUB                          
   Btm_ECUPCC_ACCSetDistance_3Bits= ECUPCC_mACCSetDistanceUB;                   
   Btm_ECUPCC_RoadCurvature_LByte= ECUPCC_stRoadCurvatureUB;                    
   Btm_ECUPCC_RoadCurvature_HByte= ECUPCC_stRoadCurvatureUB<<8;                    
   Btm_ECUPCC_PCCState_2Bits= ECUPCC_stPCCStateUB;//PCC状态                         
   Btm_ECUPCC_ACCShutoffWarning_2Bits= ECUPCC_stACCShutoffWarningUB;                
   Btm_ECUPCC_ACCDisAlert_2Bits= ECUPCC_stACCDisAlertUB;      
}//robin190708

void ECUCAN_InterfaceOut_TC1Update(void) //TC1变量更新
{
  Btm_ECUTC1_TransGearShiftInhibitRq_2Bits= TransGearShiftInhibitRqUB;         
  Btm_ECUTC1_TorqueConverterLockupDisableRq_2Bits= TorqueConverterLockupDisableRqUB;  
  Btm_ECUTC1_DisengageDrivelineRq_2Bits= DisengageDrivelineRqUB;  
  Btm_ECUTC1_RqedPercentClutchSlip_Byte= RqedPercentClutchSlipUB;        
  Btm_ECUTC1_TransRqedGear_Byte= TransRqedGearUB;                  
  Btm_ECUTC1_DisengageDiffLockRqFrontAxle1_2Bits= DisengageDiffLockRqFrontAxle1UB;  
  Btm_ECUTC1_DisengageDiffLockRqFrontAxle2_2Bits= DisengageDiffLockRqRearAxle1UB; 
  Btm_ECUTC1_DisengageDiffLockRqRearAxle1_2Bits= DisengageDiffLockRqRearAxle2UB; 
  Btm_ECUTC1_DisengageDiffLockRqRearAxle2_2Bits= DisengageDiffLockRqCentralUB;     
  Btm_ECUTC1_DisengageDiffLockRqCentral_2Bits= DisengageDiffLockRqCentralFrontUB; 
  Btm_ECUTC1_DisengageDiffLockRqCentralRear_2Bits= DisengageDiffLockRqCentralRearUB;  
  Btm_ECUTC1_TransMode1_2Bits= TransMode1UB;                     
  Btm_ECUTC1_TransMode2_2Bits= TransMode2UB;                
  Btm_ECUTC1_TransMode2_2Bits= TransMode3UB;                  
  Btm_ECUTC1_TransMode2_2Bits= TransMode4UB;             
  Btm_ECUTC1_TrnsShftSlctorDisplayModeSwitch_2Bits= TrnsShftSlctorDisplayModeSwitchUB;
}//robin添加修改190710



