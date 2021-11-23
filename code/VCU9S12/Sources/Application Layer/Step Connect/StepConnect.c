#include "Allh.h"



unsigned int StepTimer1ms = 0;
unsigned int StepTimer10ms = 0;
unsigned int StepTimer20ms = 0;
unsigned int StepTimer50ms = 0;//robin add 190711
unsigned int StepTimer100ms = 0;
unsigned char engTypeUB = 2;//引擎类型 1--锡柴，2--潍柴 added by Leo




//1ms任务执行
void StepConnect_1ms(void)//
{
  //
  StepTimer1ms ++;
  if(StepTimer1ms > 9999)//
  {
    StepTimer1ms = 0;
  }//
  
  
}//
  



unsigned char swch1;
unsigned char swch2;
unsigned char swch3;
unsigned char swch4;
unsigned char swch5;
unsigned char swch6;
unsigned char swch7;
unsigned char swch8;
unsigned char swch9;
unsigned char swch10;
unsigned char swch11;
unsigned char swch12;


unsigned char hsfb1;
unsigned char hsfb2;
unsigned char hsfb3;
unsigned char hsfb4;
unsigned char hsfb5;
unsigned char hsfb6;
unsigned char hsfb7;
unsigned char hsfb8;
unsigned char hsfb9;
unsigned char hsfb10;
unsigned char hsfb11;
unsigned char hsfb12;
unsigned char hsfb13;
unsigned char hsfb14;
unsigned char hsfb15;
unsigned char hsfb16;





//10ms任务执行
void StepConnect_10ms(void)//
{
  //
  StepTimer10ms ++;
  if(StepTimer10ms > 9999)//
  {
    StepTimer10ms = 0;
  }//
  
  
  ValueInput_Update_10ms();
  
  ActualEngPercentTorque_UB        = ECUEEC1_pctActualTrqUB;
  DriversDemandEngPercentTorque_UB = ECUEEC1_pctDrvTrqDmdUB;
  BrkCD_stPressed_UB               = ECUCCVS_swBrakeSWUB;
  ConvCD_stClth_UB                 = ECUCCVS_swClutchSWUB;
  AccPedPos1_pctUB                 = ECUEEC2_pctAccelPedalPosRAWUB;
  TachographVehicleSpeed_10mphUW  = MeterTCO1_kmphVehSpd100UW; //MeterTCO1_kmphVehSpdUB;
  EngSpeed_rpmUW                  = ECUEEC1_rpmEngSpdUW;
  EngReferenceTorque_NmUW         = ECUEC1_nmEngRefTrqUW;
  CrCtl_PCCAct_BL                 = PCC_isActive;
  PCC_offRsn_UB                   = PCC_OffReason;
  PCC_vSetPointTrgt_kmphUW        = PCC_kmphExitSpeed;
  //CrCtl_trqPCCReqin_10mNmSL = (int32_T)PCC_nmNextSegTrq * 100;
  PCC_trqReq_pctSB = PCC_nmNextSegTrq;
  CrCtl_tiPCCRmp_10msUW = 3;
  //RefRtdrTrq_NmUW = 3514;//锡柴发动机制动参考扭矩值，待RC报文解析之后可取消
  RefRtdrTrq_NmUW = 64501;//潍柴发动机制动参考扭矩值，待RC报文解析之后可取消
    
 
  CrCtl_step();
  //CANTxAllow_stECUTSC1UB        = 1;
  //CANTxAllow_stRtdrTSC1UB       = 1;
  if (CrCtl_stActive_BL == 1) 
  {
    ECUTSC1_stEngOverrideCtrlMdUB = EngCtrlMd_TrqCtrl;
  } 
  else 
  {
    ECUTSC1_stEngOverrideCtrlMdUB = EngCtrlMd_CtrlOff;
  }
  //ECUTSC1_pctTrqDmdLmtUB        = EngRqedTorque_TorqueLimit_UB;
  ECUTSC1_pctTrqDmdLmtSB          = EngRqedTorque_TorqueLimit_SB;
  
  
  //判断扭矩正负
  if (ECUTSC1_pctTrqDmdLmtSB >= 0) 
  {
     CANTxAllow_stECUTSC1UB        = 1;//激活正扭矩TSC1报文   
  }
  else 
  {
     CANTxAllow_stRtdrTSC1UB       = 1;//激活负扭矩TSC1报文
     ECUTSC1_pctTrqDmdLmtSB        = -100;
  }
  
  //按发动机类型输出控制报文
  switch (engTypeUB) 
  {
    case 1:                            //锡柴发动机
      CANTx2ECU_10ms();
      CANTx2Rtdr_50ms();               //TSC1 RR 控负扭矩 用于锡柴发动机 added by Leo
      break;
    case 2:                            //潍柴发动机
      CANTx2ECUWc_10ms();              //TSC1 TE 控正扭矩 潍柴 added by Leo
      CANTx2RtdrWc_50ms();             //TSC1 VR 控负扭矩 用于潍柴发动机 added by Leo
      break;
  }
  
  CANTxAllow_stECUTSC1UB        = 0;
  CANTxAllow_stRtdrTSC1UB       = 0;
  
  
  swch1 = _Btm_SWLH_VB[0];  
  swch2 = _Btm_SWLH_VB[1];     
  swch3 = _Btm_SWLH_VB[2];      
  swch4 = _Btm_SWLH_VB[3];     
  swch5 = _Btm_SWLH_VB[4];     
  swch6 = _Btm_SWLH_VB[5];      
  swch7 = _Btm_SWLH_VB[6];        
  swch8 = _Btm_SWLH_VB[7];      
  swch9 = _Btm_SWLH_VB[8];     
  swch10 = _Btm_SWLH_VB[9];      
  swch11 = _Btm_SWLH_VB[10];    
  swch12 = _Btm_SWLH_VB[11]; 
  
  
  hsfb1 = HighSideFB_Chn1;
  hsfb2 = HighSideFB_Chn2;
  hsfb3 = HighSideFB_Chn3;
  hsfb4 = HighSideFB_Chn4;
  
  hsfb5 = HighSideFB_Chn5;
  hsfb6 = HighSideFB_Chn6;
  hsfb7 = HighSideFB_Chn7;
  hsfb8 = HighSideFB_Chn8;
  
  hsfb9 = HighSideFB_Chn9;
  hsfb10 = HighSideFB_Chn10;
  hsfb11 = HighSideFB_Chn11;
  hsfb12 = HighSideFB_Chn12;
  
  hsfb13 = HighSideFB_Chn13;
  hsfb14 = HighSideFB_Chn14;
  hsfb15 = HighSideFB_Chn15;
  hsfb16 = HighSideFB_Chn16;

  //ZHVCU_step();
  
  
  //HSDOutput_Update_10ms();
  

  // chxd add 2019-02-20
  CANTx2BTNTest_10ms();  //MFLv多功能杆状态发送，不用Matlab/Smulink调试时可屏蔽此函数调用的CAN发送函数
   /*MFLv I/O*/
  MFLv_swtBL     = 0; //_Btm_SWLH_VB[1];
  MFLv_resBL     = 1;//_Btm_SWLH_VB[2];
  MFLv_setDownBL = 1;//_Btm_SWLH_VB[3];
  MFLv_setUpBL   = 1;//_Btm_SWLH_VB[4];
  
 
  S32K144_SetMFLvState(); 
  //S32K144_Test();
  S32K144_SPI_Process();
  
}//
  

//20ms任务执行
void StepConnect_20ms(void)//
{
  //
  StepTimer20ms ++;
  if(StepTimer20ms > 9999)//
  {
    StepTimer20ms = 0;
  }//
  
  
  
  ccpDaq(0);
  
}//
//50ms任务执行   
void StepConnect_50ms(void)//
{
  //
  StepTimer50ms ++;
  if(StepTimer50ms > 9999)//
  {
    StepTimer50ms = 0;
  }//
  
  ValueOutput_Update_50ms();
  
  
}  

//100ms任务执行    
void StepConnect_100ms(void)//
{
  //
  StepTimer100ms ++;
  if(StepTimer100ms > 9999)//
  {
    StepTimer100ms = 0;
  }//
 
  
 PCCStateDetect();
 ValueOutput_Update_100ms();
 
 
  
  
}//
  



