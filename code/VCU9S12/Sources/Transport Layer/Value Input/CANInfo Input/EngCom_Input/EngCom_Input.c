#include "Allh.h"



unsigned char ECUEEC2_pctAccelPedalPosRAWUB; 


//------------------------EEC1--------------------------------
unsigned char ECUEEC1_stEngTrqMdUB;             //可用
unsigned char ECUEEC1_pctDrvTrqDmdUB;          //可用
unsigned char ECUEEC1_pctActualTrqUB;                //可用
unsigned int  ECUEEC1_rpmEngSpdUW;                 //可用
unsigned char ECUEEC1_stSourceOFEngCtrlUB;        //可用
//------------------------EEC2--------------------------------
unsigned char ECUEEC2_swAccelPedalLowIdleSWUB;     //不可用
unsigned char ECUEEC2_swAccelPedalKickDownSWUB;    //不可用
unsigned char ECUEEC2_pctAccelPedalPosRAWUB;
unsigned char ECUEEC2_pctEngLoadPctUB;
unsigned char ECUEEC2_pctRemoteAccelPedalPosUB;        //不可用
unsigned char ECUEEC2_pctAccelPedal2PosUB;             //为255不可用
//------------------------EEC3--------------------------------
unsigned char ECUEEC3_pctNomFriTrqPctUB;
//------------------------ET1---------------------------------
unsigned char ECUET1_tEngCoolantTempO40UB;
unsigned char ECUET1_tEngFuelTempO40UB;
unsigned int  ECUET1_tEngOilTempUW;
unsigned int  ECUET1_tEngTurboOilTempUW;
unsigned char ECUET1_tEngInterCoolerTempO40UB;
//-------------------------LFE------------------------------
unsigned int  ECULFE_lphEngFuelRateUW;
unsigned int  ECULFE_kmpkgEngInstantFuelEcoUW;
unsigned int  ECULFE_kmpkgEngAverageFuelEcoUW;
unsigned char ECULFE_pctEngThrottlePosUB;
//----------------------------LFC----------------------------------
unsigned char ECULFC_EngTripFuel_41Byte;
unsigned char ECULFC_EngTripFuel_42Byte;
unsigned char ECULFC_EngTripFuel_43Byte;
unsigned char ECULFC_EngTripFuel_44Byte;
unsigned long ECULFC_EngTripFuel_4Bytes;
unsigned char ECULFC_EngTotalFuel_41Byte;
unsigned char ECULFC_EngTotalFuel_42Byte;
unsigned char ECULFC_EngTotalFuel_43Byte;
unsigned char ECULFC_EngTotalFuel_44Byte;
unsigned long ECULFC_EngTotalFuel_4Bytes;
unsigned long ECULFC_lEngTotalFuelUL;
unsigned int  ECULFC_lEngTotalFuelUW;
unsigned long ECULFC_lEngTripFuelUL;
unsigned int  ECULFC_lEngTripFuelUW;
//----------------------------ETC1----------------------------------
unsigned char  ECUETC1_TransDrivelineEngage;            // 变速器传动介入
unsigned char  ECUETC1_TorqueConverterLockupEngaged;    // 禁止液力变矩器锁止介入
unsigned char  ECUETC1_TransShiftInProcess;             // 变速器换挡中
unsigned char  ECUETC1_TransOutputShaftSpeed;           // 变速器输出轴转速 
unsigned char  ECUETC1_PercentClutchSlip;               // 离合滑动百分比  
unsigned char  ECUETC1_EngMomentaryOverspeedEnabl;      // 发动机瞬间超速启用
unsigned char  ECUETC1_ProgressiveShiftDisable;         // 渐进换挡禁用
unsigned char  ECUETC1_TransInputShaftSpeed;            // 变速器输入轴转速
unsigned char  ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl; // 变速器控制设备源地址 
//----------------------------ETC2----------------------------------
unsigned char  ECUETC2_TransSelectedGear;                // 变速器选择档位
unsigned char  ECUETC2_TransActualGearRatio;             // 变速器实际传动比
unsigned char  ECUETC2_TransActualGearRatio;             // 变速器实际传动比
unsigned char  ECUETC2_TransCurrentGear;                 // 变速器当前档位
unsigned char  ECUETC2_TransRqedRange;                   // 变速器请求范围 
unsigned char  ECUETC2_TransRqedRange;                   // 变速器请求范围  
unsigned char  ECUETC2_TransCurrentRange;                // 变速器当前范围
unsigned char  ECUETC2_TransCurrentRange;                // 变速器当前范围

//----------------------------CCVS---------------------------------
unsigned char ECUCCVS_swTwoSpdAxleSWUB;
unsigned char ECUCCVS_swParkingBrakeSWUB;
unsigned char ECUCCVS_swCCSPauseSWUB;
unsigned int  ECUCCVS_kmphWheelBasedVehSpdIUW;
unsigned char ECUCCVS_stCCSActiveUB;
unsigned char ECUCCVS_stCCSEnableSWUB;
unsigned char ECUCCVS_swBrakeSWUB;
unsigned char ECUCCVS_swClutchSWUB;
unsigned char ECUCCVS_swCCSSetSWUB;
unsigned char ECUCCVS_swCCSCoastSWUB;
unsigned char ECUCCVS_swCCSResumeSWUB;
unsigned char ECUCCVS_swCCSAccelSWUB;
unsigned char ECUCCVS_kmphCCSSetSpdUB;		
unsigned char ECUCCVS_stCCSPTOStUB; 		
unsigned char ECUCCVS_stCCSCtlStUB;		
unsigned char ECUCCVS_swEngIdleIncrementSWUB;
unsigned char ECUCCVS_swEngIdleDecrementSWUB;
unsigned char ECUCCVS_swEngTestMdSWUB;
unsigned char ECUCCVS_swEngShutdownOrSWUB;
//------------------------------AMB----------------------------------
unsigned char ECUAMB_pBarometricPressUB;
//------------------------------ERC1--------------------------------
unsigned char ECUERC1_pctActualRetarderTrqPctUB;
//EC1
unsigned int  ECUEC1_rpmEngSpdAtIdlePoint1UW;                               
unsigned char ECUEC1_pctEngPctTrqAtIdlePoint1UB;        
unsigned int  ECUEC1_rpmEngSpdAtPoint2UW;                                        
unsigned char ECUEC1_pctEngPctTrqAtPoint2UB;            
unsigned int  ECUEC1_rpmEngSpdAtPoint3UW;                                       
unsigned char ECUEC1_pctEngPctTrqAtPoint3UB;            
unsigned int  ECUEC1_rpmEngSpdAtPoint4UW;                                       
unsigned char ECUEC1_pctEngPctTrqAtPoint4UB;            
unsigned int  ECUEC1_rpmEngSpdAtPoint5UW;                                        
unsigned char ECUEC1_pctEngPctTrqAtPoint5UB;            
unsigned int  ECUEC1_rpmEngSpdAtHighIdlePoint6UW;                       
unsigned int  ECUEC1_numEngGainOfEndSpdGovernorUW;                     
unsigned int  ECUEC1_nmEngRefTrqUW;     //发动机参考扭矩值                                 
unsigned int  ECUEC1_rpmEngMxMmntaryOverrideSpdPoint7UW;        
unsigned char ECUEC1_100msEngMxMomentaryOverrideTimelmtUB;      
unsigned char ECUEC1_rpmEngRqedSpdCtrlRangeLowerlmtUB;      
unsigned char ECUEC1_rpmEngRqedSpdCtrlRangeUpperlmtUB;      
unsigned char ECUEC1_pctEngRqdTrqCtrlRangeLowerlmtUB;      
unsigned char ECUEC1_pctEngRqdTrqCtrlRangeUpperlmtUB;      
unsigned int  ECUEC1_rpmEngExRngRqdSpdCtrlRngUpperlmtUW;          
unsigned int  ECUEC1_EngMomentOfInertiaUW;                                   
unsigned int  ECUEC1_nmEngDefaultTrqlmtUW;                             
unsigned char ECUEC1_SupportVariableRateTSC1MessageUB;       
unsigned char ECUEC1_SupportTSC1CtrlPurpGroup1Of4UB;      
unsigned char ECUEC1_SupportTSC1CtrlPurpGroup2Of4UB;      
unsigned char ECUEC1_SupportTSC1CtrlPurpGroup3Of4UB;      
unsigned char ECUEC1_SupportTSC1CtrlPurpGroup4Of4UB;      
//EC1报文发动机外特性点输入信号整理
unsigned int ECUEC1_rpmMAPSpdPoint1UW;
unsigned int ECUEC1_nmMAPTrqPoint1UW;
unsigned int ECUEC1_rpmMAPSpdPoint2UW;
unsigned int ECUEC1_nmMAPTrqPoint2UW;
unsigned int ECUEC1_rpmMAPSpdPoint3UW;
unsigned int ECUEC1_nmMAPTrqPoint3UW;
unsigned int ECUEC1_rpmMAPSpdPoint4UW;
unsigned int ECUEC1_nmMAPTrqPoint4UW;
unsigned int ECUEC1_rpmMAPSpdPoint5UW;
unsigned int ECUEC1_nmMAPTrqPoint5UW;
unsigned int ECUEC1_rpmMAPSpdPoint6UW;
unsigned int ECUEC1_nmMAPTrqPoint6UW;
//ECUEEC1上报的发动机扭矩百分比信息
unsigned int ECUEEC1_nmDriverTrqDemandUW;
unsigned int ECUEEC1_nmActualTrqUW;
//EEC3上报摩擦扭矩解析
unsigned int ECUEEC3_nmNomFriTrqPctUW;
//LFE相关内容
unsigned long ECULFE_50mlphEngRTFuelRateUL;
unsigned long ECULFE_mlpkmEngRTFuelRateUL;
unsigned int ECULFE_mlphEngRTFuelRateUW;
unsigned int ECULFE_lphEngRTFuelRateUW;
unsigned int ECULFE_gpkwhEngFuelRateUW;
unsigned int VehAnly_lp100kmEngFuelRTRateUW;

unsigned long ECUAnly_lp100kmRTVehFuleRatioUW;
unsigned long EngAnly_lp100kmRTFuelRatioF; 


void ECU2HCU_ValueInit(void)//
{
  //
  ECUEEC2_pctAccelPedalPosRAWUB = 0; 
  //------------------------EEC1--------------------------------
  ECUEEC1_stEngTrqMdUB = 0;             
  ECUEEC1_pctDrvTrqDmdUB = 0;          
  ECUEEC1_pctActualTrqUB = 0;                
  ECUEEC1_rpmEngSpdUW = 0;                 
  ECUEEC1_stSourceOFEngCtrlUB = 0;        
  //------------------------EEC2--------------------------------
  ECUEEC2_swAccelPedalLowIdleSWUB = 0;     
  ECUEEC2_swAccelPedalKickDownSWUB = 0;    
  ECUEEC2_pctAccelPedalPosRAWUB = 0;
  ECUEEC2_pctEngLoadPctUB = 0;
  ECUEEC2_pctRemoteAccelPedalPosUB = 0;        
  ECUEEC2_pctAccelPedal2PosUB = 0;             //为255不可用
  //------------------------EEC3--------------------------------
  ECUEEC3_pctNomFriTrqPctUB = 0;
  //------------------------ET1---------------------------------
  ECUET1_tEngCoolantTempO40UB = 0;
  ECUET1_tEngFuelTempO40UB = 0;
  ECUET1_tEngOilTempUW = 0;
  ECUET1_tEngTurboOilTempUW = 0;
  ECUET1_tEngInterCoolerTempO40UB = 0;
  //-------------------------LFE------------------------------
  ECULFE_lphEngFuelRateUW = 0;
  ECULFE_kmpkgEngInstantFuelEcoUW = 0;
  ECULFE_kmpkgEngAverageFuelEcoUW = 0;
  ECULFE_pctEngThrottlePosUB = 0;
  //----------------------------LFC----------------------------------
  ECULFC_EngTripFuel_41Byte = 0;
  ECULFC_EngTripFuel_42Byte = 0;
  ECULFC_EngTripFuel_43Byte = 0;
  ECULFC_EngTripFuel_44Byte = 0;
  ECULFC_EngTripFuel_4Bytes = 0;
  ECULFC_EngTotalFuel_41Byte = 0;
  ECULFC_EngTotalFuel_42Byte = 0;
  ECULFC_EngTotalFuel_43Byte = 0;
  ECULFC_EngTotalFuel_44Byte = 0;
  ECULFC_EngTotalFuel_4Bytes = 0;
  ECULFC_lEngTotalFuelUL = 0;
  ECULFC_lEngTotalFuelUW = 0;
  ECULFC_lEngTripFuelUL = 0;
  ECULFC_lEngTripFuelUW = 0;
  //----------------------------CCVS---------------------------------
  ECUCCVS_swTwoSpdAxleSWUB = 0;
  ECUCCVS_swParkingBrakeSWUB = 0;
  ECUCCVS_swCCSPauseSWUB = 0;
  ECUCCVS_kmphWheelBasedVehSpdIUW = 0;
  ECUCCVS_stCCSActiveUB = 0;
  ECUCCVS_stCCSEnableSWUB = 0;
  ECUCCVS_swBrakeSWUB = 0;
  ECUCCVS_swClutchSWUB = 0;
  ECUCCVS_swCCSSetSWUB = 0;
  ECUCCVS_swCCSCoastSWUB = 0;
  ECUCCVS_swCCSResumeSWUB = 0;
  ECUCCVS_swCCSAccelSWUB = 0;
  ECUCCVS_kmphCCSSetSpdUB = 0;		
  ECUCCVS_stCCSPTOStUB = 0; 		
  ECUCCVS_stCCSCtlStUB = 0;		
  ECUCCVS_swEngIdleIncrementSWUB = 0;
  ECUCCVS_swEngIdleDecrementSWUB = 0;
  ECUCCVS_swEngTestMdSWUB = 0;
  ECUCCVS_swEngShutdownOrSWUB = 0;
  
//----------------------------ETC1----------------------------------
  ECUETC1_TransDrivelineEngage= 0;            // 变速器传动介入
  ECUETC1_TorqueConverterLockupEngaged= 0;    // 禁止液力变矩器锁止介入
  ECUETC1_TransShiftInProcess= 0;             // 变速器换挡中
  ECUETC1_TransOutputShaftSpeed= 0;           // 变速器输出轴转速 
  ECUETC1_PercentClutchSlip= 0;               // 离合滑动百分比  
  ECUETC1_EngMomentaryOverspeedEnabl= 0;      // 发动机瞬间超速启用
  ECUETC1_ProgressiveShiftDisable= 0;         // 渐进换挡禁用
  ECUETC1_TransInputShaftSpeed= 0;            // 变速器输入轴转速
  ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl= 0; // 变速器控制设备源地址 
//----------------------------ETC2----------------------------------
  ECUETC2_TransSelectedGear= 0;                // 变速器选择档位
  ECUETC2_TransActualGearRatio= 0;             // 变速器实际传动比
  ECUETC2_TransActualGearRatio= 0;             // 变速器实际传动比
  ECUETC2_TransCurrentGear= 0;                 // 变速器当前档位
  ECUETC2_TransRqedRange= 0;                   // 变速器请求范围 
  ECUETC2_TransRqedRange= 0;                   // 变速器请求范围  
  ECUETC2_TransCurrentRange= 0;                // 变速器当前范围
  ECUETC2_TransCurrentRange= 0;                // 变速器当前范围

  
  //------------------------------AMB----------------------------------
  ECUAMB_pBarometricPressUB = 0;
  //------------------------------ERC1--------------------------------
  ECUERC1_pctActualRetarderTrqPctUB = 0;
  //EC1
  ECUEC1_rpmEngSpdAtIdlePoint1UW = 0;                               
  ECUEC1_pctEngPctTrqAtIdlePoint1UB = 0;        
  ECUEC1_rpmEngSpdAtPoint2UW = 0;                                        
  ECUEC1_pctEngPctTrqAtPoint2UB = 0;            
  ECUEC1_rpmEngSpdAtPoint3UW = 0;                                       
  ECUEC1_pctEngPctTrqAtPoint3UB = 0;            
  ECUEC1_rpmEngSpdAtPoint4UW = 0;                                       
  ECUEC1_pctEngPctTrqAtPoint4UB = 0;            
  ECUEC1_rpmEngSpdAtPoint5UW = 0;                                        
  ECUEC1_pctEngPctTrqAtPoint5UB = 0;            
  ECUEC1_rpmEngSpdAtHighIdlePoint6UW = 0;                       
  ECUEC1_numEngGainOfEndSpdGovernorUW = 0;                     
  ECUEC1_nmEngRefTrqUW = 0;     //发动机参考扭矩值                                 
  ECUEC1_rpmEngMxMmntaryOverrideSpdPoint7UW = 0;        
  ECUEC1_100msEngMxMomentaryOverrideTimelmtUB = 0;      
  ECUEC1_rpmEngRqedSpdCtrlRangeLowerlmtUB = 0;      
  ECUEC1_rpmEngRqedSpdCtrlRangeUpperlmtUB = 0;      
  ECUEC1_pctEngRqdTrqCtrlRangeLowerlmtUB = 0;      
  ECUEC1_pctEngRqdTrqCtrlRangeUpperlmtUB = 0;      
  ECUEC1_rpmEngExRngRqdSpdCtrlRngUpperlmtUW = 0;          
  ECUEC1_EngMomentOfInertiaUW = 0;                                   
  ECUEC1_nmEngDefaultTrqlmtUW = 0;                             
  ECUEC1_SupportVariableRateTSC1MessageUB = 0;       
  ECUEC1_SupportTSC1CtrlPurpGroup1Of4UB = 0;      
  ECUEC1_SupportTSC1CtrlPurpGroup2Of4UB = 0;      
  ECUEC1_SupportTSC1CtrlPurpGroup3Of4UB = 0;      
  ECUEC1_SupportTSC1CtrlPurpGroup4Of4UB = 0;      
  //EC1报文发动机外特性点输入信号整理
  ECUEC1_rpmMAPSpdPoint1UW = 0;
  ECUEC1_nmMAPTrqPoint1UW = 0;
  ECUEC1_rpmMAPSpdPoint2UW = 0;
  ECUEC1_nmMAPTrqPoint2UW = 0;
  ECUEC1_rpmMAPSpdPoint3UW = 0;
  ECUEC1_nmMAPTrqPoint3UW = 0;
  ECUEC1_rpmMAPSpdPoint4UW = 0;
  ECUEC1_nmMAPTrqPoint4UW = 0;
  ECUEC1_rpmMAPSpdPoint5UW = 0;
  ECUEC1_nmMAPTrqPoint5UW = 0;
  ECUEC1_rpmMAPSpdPoint6UW = 0;
  ECUEC1_nmMAPTrqPoint6UW = 0;
  //ECUEEC1上报的发动机扭矩百分比信息
  ECUEEC1_nmDriverTrqDemandUW = 0;
  ECUEEC1_nmActualTrqUW = 0;
  //EEC3上报摩擦扭矩解析
  ECUEEC3_nmNomFriTrqPctUW = 0;
  //LFE相关内容
  ECULFE_50mlphEngRTFuelRateUL = 0;
  ECULFE_mlpkmEngRTFuelRateUL = 0;
  ECULFE_mlphEngRTFuelRateUW = 0;
  ECULFE_lphEngRTFuelRateUW = 0;
  ECULFE_gpkwhEngFuelRateUW = 0;
  VehAnly_lp100kmEngFuelRTRateUW = 0;
}//





void ECU2HCU_Update_10ms(void)//
{
  //
  ECU2HCU_EEC1Update();
  ECU2HCU_EEC2Update();
  ECU2HCU_EEC3Update();
  ECU2HCU_ET1Update();
  ECU2HCU_LFCUpdate();
  ECU2HCU_LFEUpdate();
  ECU2HCU_CCVSUpdate();
  ECU2HCU_AMBUpdate();
  ECU2HCU_ERC1Update();
  ECU2HCU_EC1Update();
}//




void ECU2HCU_RTOutCurveUpdate(void)//
{
  //
  /*
  EngMapRTOutCurve_rpmEngSpdIndexA[0] = ECUEC1_rpmMAPSpdPoint1UW;
  EngMapRTOutCurve_rpmEngSpdIndexA[1] = ECUEC1_rpmMAPSpdPoint2UW;
  EngMapRTOutCurve_rpmEngSpdIndexA[2] = ECUEC1_rpmMAPSpdPoint3UW;
  EngMapRTOutCurve_rpmEngSpdIndexA[3] = ECUEC1_rpmMAPSpdPoint4UW;
  EngMapRTOutCurve_rpmEngSpdIndexA[4] = ECUEC1_rpmMAPSpdPoint5UW;
  EngMapRTOutCurve_rpmEngSpdIndexA[5] = ECUEC1_rpmMAPSpdPoint6UW;
  
  EngMapRTOutCurve_nmEngTrqIndexA[0] = ECUEC1_nmMAPTrqPoint1UW;
  EngMapRTOutCurve_nmEngTrqIndexA[1] = ECUEC1_nmMAPTrqPoint2UW;
  EngMapRTOutCurve_nmEngTrqIndexA[2] = ECUEC1_nmMAPTrqPoint3UW;
  EngMapRTOutCurve_nmEngTrqIndexA[3] = ECUEC1_nmMAPTrqPoint4UW;
  EngMapRTOutCurve_nmEngTrqIndexA[4] = ECUEC1_nmMAPTrqPoint5UW;
  EngMapRTOutCurve_nmEngTrqIndexA[5] = ECUEC1_nmMAPTrqPoint6UW;
  */
}//






void ECU2HCU_EC1Update(void)//
{
  //
  unsigned long temp_pointXTrq;
  
  if(CANInputUpdt_stECUEC1UB == 1)//
  {
    //
    ECUEC1_rpmEngSpdAtIdlePoint1UW = (Btm_ECUEC1_EngSpdAtIdlePoint1_LByte + 256 * Btm_ECUEC1_EngSpdAtIdlePoint1_HByte)/8;                
    ECUEC1_pctEngPctTrqAtIdlePoint1UB = Btm_ECUEC1_EngPctTrqAtIdlePoint1_Byte - 125;        

    ECUEC1_rpmEngSpdAtPoint2UW = (Btm_ECUEC1_EngSpdAtPoint2_LByte + Btm_ECUEC1_EngSpdAtPoint2_HByte * 256) / 8;                              
    ECUEC1_pctEngPctTrqAtPoint2UB = Btm_ECUEC1_EngPctTrqAtPoint2_Byte - 125;
    
    ECUEC1_rpmEngSpdAtPoint3UW = (Btm_ECUEC1_EngSpdAtPoint3_LByte + 256 * Btm_ECUEC1_EngSpdAtPoint3_HByte) / 8;                    
    ECUEC1_pctEngPctTrqAtPoint3UB = Btm_ECUEC1_EngPctTrqAtPoint3_Byte - 125;            


    ECUEC1_rpmEngSpdAtPoint4UW = (Btm_ECUEC1_EngSpdAtPoint4_LByte + 256 * Btm_ECUEC1_EngSpdAtPoint4_HByte) / 8;                    
    ECUEC1_pctEngPctTrqAtPoint4UB = Btm_ECUEC1_EngPctTrqAtPoint4_Byte - 125;            

    ECUEC1_rpmEngSpdAtPoint5UW = (Btm_ECUEC1_EngSpdAtPoint5_LByte + 256 * Btm_ECUEC1_EngSpdAtPoint5_HByte) / 8;                    
    ECUEC1_pctEngPctTrqAtPoint5UB = Btm_ECUEC1_EngPctTrqAtPoint5_Byte - 125;                      

    ECUEC1_rpmEngSpdAtHighIdlePoint6UW = (Btm_ECUEC1_EngSpdAtHighIdlePoint6_LByte + 256 * Btm_ECUEC1_EngSpdAtHighIdlePoint6_HByte) / 8;                      

    ECUEC1_nmEngRefTrqUW = Btm_ECUEC1_EngReferenceTrq_LByte + 256 * Btm_ECUEC1_EngReferenceTrq_HByte;                  

    ECUEC1_rpmEngMxMmntaryOverrideSpdPoint7UW = (Btm_ECUEC1_EngMxMmntaryOverrideSpdPoint7_LByte + 256 * Btm_ECUEC1_EngMxMmntaryOverrideSpdPoint7_HByte) / 8;     

    ECUEC1_100msEngMxMomentaryOverrideTimelmtUB = Btm_ECUEC1_EngMxMomentaryOverrideTimelmt_Byte;      



    if(ECUEC1_nmEngRefTrqUW < 1000)//
    {
      //
      ECUEC1_nmEngRefTrqUW = 1650;
    }//

    //Point1 IdleSpd = Point1
    ECUEC1_rpmMAPSpdPoint1UW = ECUEC1_rpmEngSpdAtIdlePoint1UW;
    temp_pointXTrq = ((unsigned long)ECUEC1_pctEngPctTrqAtIdlePoint1UB * (unsigned long)ECUEC1_nmEngRefTrqUW)/100;
    ECUEC1_nmMAPTrqPoint1UW = (unsigned int)temp_pointXTrq;
    
    //Point2 = Point3
    ECUEC1_rpmMAPSpdPoint2UW = ECUEC1_rpmEngSpdAtPoint3UW;
    temp_pointXTrq = ((unsigned long)ECUEC1_pctEngPctTrqAtPoint3UB * (unsigned long)ECUEC1_nmEngRefTrqUW)/100;
    ECUEC1_nmMAPTrqPoint2UW = (unsigned int)temp_pointXTrq;
    
    //Point3 = Point4
    ECUEC1_rpmMAPSpdPoint3UW = ECUEC1_rpmEngSpdAtPoint4UW;
    temp_pointXTrq = ((unsigned long)ECUEC1_pctEngPctTrqAtPoint4UB * (unsigned long)ECUEC1_nmEngRefTrqUW)/100;
    ECUEC1_nmMAPTrqPoint3UW = (unsigned int)temp_pointXTrq;
    
    //Point4 = Point5
    ECUEC1_rpmMAPSpdPoint4UW = ECUEC1_rpmEngSpdAtPoint5UW;
    temp_pointXTrq = ((unsigned long)ECUEC1_pctEngPctTrqAtPoint5UB * (unsigned long)ECUEC1_nmEngRefTrqUW)/100;
    ECUEC1_nmMAPTrqPoint4UW = (unsigned int)temp_pointXTrq;
    
    //Point5 = Point2
    ECUEC1_rpmMAPSpdPoint5UW = ECUEC1_rpmEngSpdAtPoint2UW;
    temp_pointXTrq = ((unsigned long)ECUEC1_pctEngPctTrqAtPoint2UB * (unsigned long)ECUEC1_nmEngRefTrqUW)/100;
    ECUEC1_nmMAPTrqPoint5UW = (unsigned int)temp_pointXTrq;
    
    //Point6 = Point6
    ECUEC1_rpmMAPSpdPoint6UW = ECUEC1_rpmEngSpdAtHighIdlePoint6UW;
    ECUEC1_nmMAPTrqPoint6UW = 0;
    
    ECU2HCU_RTOutCurveUpdate();    
    
    CANInputUpdt_stECUEC1UB = 0;
  }//  
}//

void ECU2HCU_ETC1Update(void)//robin add 190715
{
  if(CANInputUpdt_stECUETC1UB == 1)//
 {
    ECUETC1_TransDrivelineEngage= Btm_ECUETC1_TransDrivelineEngaged_2Bits;                   // 变速器传动介入
    ECUETC1_TorqueConverterLockupEngaged= Btm_ECUETC1_TorqueConverterLockupEngaged_2Bits;    // 禁止液力变矩器锁止介入
    ECUETC1_TransShiftInProcess= Btm_ECUETC1_TransShiftInProcess_2Bits;                      // 变速器换挡中
    ECUETC1_TransOutputShaftSpeed= (Btm_ECUETC1_TransOutputShaftSpeed_LByte + Btm_ECUETC1_TransOutputShaftSpeed_HByte * 256) / 8;                  // 变速器输出轴转速 
    ECUETC1_PercentClutchSlip= Btm_ECUETC1_PercentClutchSlip_Byte;                           // 离合滑动百分比  
    ECUETC1_EngMomentaryOverspeedEnabl= Btm_ECUETC1_EngMomentaryOverspeedEnable_2Bits;       // 发动机瞬间超速启用
    ECUETC1_ProgressiveShiftDisable= Btm_ECUETC1_ProgressiveShiftDisable_2Bits;              // 渐进换挡禁用
    ECUETC1_TransInputShaftSpeed= (Btm_ECUETC1_TransInputShaftSpeed_LByte + Btm_ECUETC1_TransInputShaftSpeed_HByte * 256) / 8 ;                    // 变速器输入轴转速
    ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl= Btm_ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl_Byte; // 变速器控制设备源地址 
 }
 CANInputUpdt_stECUETC1UB = 0;
}

void ECU2HCU_ETC2Update(void)//robin add 190715
{
  if(CANInputUpdt_stECUETC2UB == 1)//
  {
    ECUETC2_TransSelectedGear= Btm_ECUETC2_TransSelectedGear_Byte+125;                // 变速器选择档位
    ECUETC2_TransActualGearRatio=(Btm_ECUETC2_TransActualGearRatio_LByte + Btm_ECUETC2_TransActualGearRatio_HByte * 256) / 1000 ;         // 变速器实际传动比
    ECUETC2_TransCurrentGear= Btm_ECUETC2_TransCurrentGear_Byte+125;                 // 变速器当前档位
    ECUETC2_TransRqedRange= Btm_TransRqedRange_LByte + Btm_TransRqedRange_HByte * 256;  // 变速器请求范围 
    ECUETC2_TransCurrentRange= Btm_TransCurrentRange_LByte + Btm_TransCurrentRange_HByte * 256;  // 变速器当前范围
  }
  CANInputUpdt_stECUETC2UB = 0;
}





void ECU2HCU_EEC1Update(void)//
{
  //
  unsigned long temp_nmTrq;
  
  unsigned long temp_pct;
  unsigned long temp_refertorque;
  
  CANTimeout_numECUTimerUW ++;
  
  if((CANTimeout_numECUTimerUW > CANTimeout_numECUTimeUWC) && (SWSen_stONSWUB == 1))//
  {
    //
    CANTimeout_stECUUB = 1;
  }//
  else//
  {
    //
    CANTimeout_stECUUB = 0;
  }//
  
  if(CANInputUpdt_stECUEEC1UB == 1)//
  {
    //
    CANTimeout_numECUTimerUW = 0;
    
    ECUEEC1_stEngTrqMdUB= Btm_ECUEEC1_EngTrqMd_4Bits;
    ECUEEC1_pctDrvTrqDmdUB= Btm_ECUEEC1_DriverTrq_Byte-125;    //分辨率1 偏移量-125
    ECUEEC1_pctActualTrqUB= Btm_ECUEEC1_ActualTrq_Byte-125;    //分辨率1 偏移量-125
    ECUEEC1_rpmEngSpdUW= (Btm_ECUEEC1_EngSpd_HByte*256+Btm_ECUEEC1_EngSpd_LByte)/8;    //分辨率1/8   偏移量0
    ECUEEC1_stSourceOFEngCtrlUB= Btm_ECUEEC1_SAofEngCtl_Byte;
  
  
  
    //就发动机的扭矩百分比等信息进行更新
    
    //此处存在溢出情况  使用temp复制进行修正
    temp_pct = (unsigned long)(ECUEEC1_pctDrvTrqDmdUB);
    temp_refertorque = (unsigned long)(ECUEC1_nmEngRefTrqUW);
    temp_nmTrq = (temp_pct * temp_refertorque)/100;
    //temp_nmTrq = (ECUEEC1_pctDriverTrqDemandUB * ECUEC1_nmEngRefTrqUW)/100; 
    ECUEEC1_nmDriverTrqDemandUW = (unsigned int)temp_nmTrq;

    
    temp_pct = (unsigned long)(ECUEEC1_pctActualTrqUB);
    temp_refertorque = (unsigned long)(ECUEC1_nmEngRefTrqUW);
    temp_nmTrq = (temp_pct * temp_refertorque)/100;
    //temp_nmTrq = (ECUEEC1_pctActualTrqUB * ECUEC1_nmEngRefTrqUW)/100;
    ECUEEC1_nmActualTrqUW = (unsigned int)temp_nmTrq;
  
    CANInputUpdt_stECUEEC1UB = 0;
  }// 
}//






void ECU2HCU_EEC2Update(void)//
{
  //
  unsigned int temp_accel;
  
  
  if(CANInputUpdt_stECUEEC2UB == 1)//
  {
    //
    ECUEEC2_swAccelPedalLowIdleSWUB= Btm_ECUEEC2_AccelPedalLowIdleSW_2Bits;
    ECUEEC2_swAccelPedalKickDownSWUB= Btm_ECUEEC2_AccelPedalKickDownSW_2Bits;
    
    temp_accel = (unsigned int)Btm_ECUEEC2_AccelPedal1Pos_Byte * (unsigned int)2 / (unsigned int)5;
    
    ECUEEC2_pctAccelPedalPosRAWUB = (unsigned char)temp_accel;   //分辨率0.4  偏移量0
    
    
    ECUEEC2_pctEngLoadPctUB= Btm_ECUEEC2_EngLoadPct_Byte;     //分辨率1   偏移量0
    ECUEEC2_pctRemoteAccelPedalPosUB= Btm_ECUEEC2_RemoteAccelPedalPos_Byte;   
    ECUEEC2_pctAccelPedal2PosUB= Btm_ECUEEC2_AccelPedal2Pos_Byte;
    
    CANInputUpdt_stECUEEC2UB = 0;
  }//  
}//




void ECU2HCU_EEC3Update(void)//
{
  //
  unsigned long temp_nmTrq;
  
  if(CANInputUpdt_stECUEEC3UB == 1)//
  {
    //
    ECUEEC3_pctNomFriTrqPctUB = Btm_ECUEEC3_NomFriTrqPct_Byte-125;    //分辨率1 偏移量-125
    
    temp_nmTrq = (ECUEEC3_pctNomFriTrqPctUB * ECUEC1_nmEngRefTrqUW)/100;
    ECUEEC3_nmNomFriTrqPctUW = (unsigned int)temp_nmTrq;
    
    CANInputUpdt_stECUEEC3UB = 0;
  }//  
}//

void ECU2HCU_ET1Update(void)//
{
  //
  if(CANInputUpdt_stECUET1UB == 1)//
  {
    //
    ECUET1_tEngCoolantTempO40UB= Btm_ECUET1_EngCoolantTemp_Byte;      //分辨率1 偏移量-40
    ECUET1_tEngFuelTempO40UB= Btm_ECUET1_EngFuelTemp_Byte;             //分辨率1 偏移量-40
    ECUET1_tEngOilTempUW= (Btm_ECUET1_EngOilTemp_HByte*256+Btm_ECUET1_EngOilTemp_LByte)/32;    //分辨率1/32  偏移量-273
    ECUET1_tEngTurboOilTempUW= (Btm_ECUET1_EngTorboOilTemp_HByte*256+Btm_ECUET1_EngTurboOilTemp_LByte)/32;   //分辨率1/32  偏移量-273
    ECUET1_tEngInterCoolerTempO40UB= Btm_ECUET1_EngInterCoolerTemp_Byte; //分辨率1 偏移量-40
    
    CANInputUpdt_stECUET1UB = 0;
  }//  
}//

void ECU2HCU_LFCUpdate(void)//
{
  //
  if(CANInputUpdt_stECULFCUB == 1)//
  {
    //
    ECULFC_lEngTotalFuelUL = (Btm_ECULFC_EngTotalFuel_41Byte + Btm_ECULFC_EngTotalFuel_42Byte * 256 + Btm_ECULFC_EngTotalFuel_43Byte * 65536 + Btm_ECULFC_EngTotalFuel_44Byte * 16777216) / 2;
                              
    
    ECULFC_lEngTotalFuelUW = (unsigned int)ECULFC_lEngTotalFuelUL;
    
    
    ECULFC_lEngTripFuelUL = (Btm_ECULFC_EngTripFuel_41Byte + Btm_ECULFC_EngTripFuel_42Byte * 256 + Btm_ECULFC_EngTripFuel_43Byte * 65536 + Btm_ECULFC_EngTripFuel_44Byte * 16777216)/2;
    
    ECULFC_lEngTripFuelUW = (unsigned int)ECULFC_lEngTripFuelUL; 
    
    
    CANInputUpdt_stECULFCUB = 0;
  }//
}//









void ECU2HCU_LFEUpdate(void)//
{
  //
  if(CANInputUpdt_stECUCCVSUB == 1)//
  {
    //
    //unsigned long temp_gpkm;
    unsigned long temp_mlpkm;
    unsigned long temp_mlph;
    unsigned long temp_lph;
    unsigned long temp_gpkwh;
    unsigned long temp_tn;
    unsigned long temp_power;
    unsigned long temp_gph;
    unsigned long temp_lp100km;

    unsigned long temp_spdf;
    unsigned long temp_mlphf;

    temp_mlph = (Btm_ECULFE_EngFuelRate_HByte*256+Btm_ECULFE_EngFuelRate_LByte) * 50;     //ml per hour
    temp_lph = temp_mlph/1000;


    ECULFE_mlphEngRTFuelRateUW = (unsigned int)temp_mlph;    //数值准确
    ECULFE_lphEngRTFuelRateUW = (unsigned int)temp_lph;      //数值准确 buyong /2


    temp_tn = (unsigned long)ECUEEC1_pctActualTrqUB * (unsigned long)ECUEC1_nmEngRefTrqUW / (unsigned long)100;
    temp_power = temp_tn * (unsigned long)ECUEEC1_rpmEngSpdUW * (20) / 191;
    temp_gph = (unsigned long)ECULFE_mlphEngRTFuelRateUW * 20 / 17;
    temp_gpkwh = temp_gph * 1000/ temp_power;
    ECULFE_gpkwhEngFuelRateUW = (unsigned int)temp_gpkwh;

    temp_mlpkm = 602352/(Btm_ECULFE_EngInstantFuelEco_HByte*256+Btm_ECULFE_EngInstantFuelEco_LByte);
    //temp_gpkm = (unsigned long)512000/((unsigned long)Msg_ECULFE.datMsgUBA[5]*(unsigned long)256+(unsigned long)Msg_ECULFE.datMsgUBA[4]);
    temp_lp100km = temp_mlpkm / 10;

    ECULFE_lphEngFuelRateUW= ECULFE_mlphEngRTFuelRateUW/20;   //燃油消耗速度  分辨率/20  偏移量0    数值准确

    VehAnly_lp100kmEngFuelRTRateUW = (unsigned int)temp_lp100km;
    ECULFE_kmpkgEngInstantFuelEcoUW= (Btm_ECULFE_EngInstantFuelEco_HByte*256+Btm_ECULFE_EngInstantFuelEco_LByte)/512;  //瞬时燃油消耗量  分辨率1/512(km/kg) 偏移量0
    ECULFE_kmpkgEngAverageFuelEcoUW= (Btm_ECULFE_EngAverageFuelEco_HByte*256+Btm_ECULFE_EngAverageFuelEco_LByte)/512;  //平均燃油消耗量  分辨率1/512(km/kg) 偏移量0
    ECULFE_pctEngThrottlePosUB= Btm_ECULFE_EngThrottlePos_Byte;


    ECUAnly_lp100kmRTVehFuleRatioUW = ECULFE_lphEngFuelRateUW/MeterTCO1_kmphVehSpdUB;

    temp_spdf = (float)MeterTCO1_kmphVehSpdUB;
    temp_mlphf = (float)ECULFE_mlphEngRTFuelRateUW;

    EngAnly_lp100kmRTFuelRatioF = temp_mlphf / temp_spdf / 10;
    
    CANInputUpdt_stECULFEUB = 0;
  }//    
}//



void ECU2HCU_CCVSUpdate(void)//
{
  //
  if(CANInputUpdt_stECUCCVSUB == 1)//
  {
    //
    ECUCCVS_swTwoSpdAxleSWUB= Btm_ECUCCVS_TwoSpdAxleSW_2Bits;
    ECUCCVS_swParkingBrakeSWUB= Btm_ECUCCVS_ParkingBrakeSW_2Bits;
    ECUCCVS_swCCSPauseSWUB= Btm_ECUCCVS_CCSPauseSW_2Bits;
    ECUCCVS_kmphWheelBasedVehSpdIUW= (Btm_ECUCCVS_WheelBasedVehSpd_HByte*256+Btm_ECUCCVS_WheelBasedVehSpd_LByte)/256; //分辨率1/256(km/h) 偏移量0
    ECUCCVS_stCCSActiveUB= Btm_ECUCCVS_CCSActive_2Bits;
    ECUCCVS_stCCSEnableSWUB= Btm_ECUCCVS_CCSEnableSW_2Bits;
    ECUCCVS_swBrakeSWUB= Btm_ECUCCVS_BrakeSW_2Bits;
    ECUCCVS_swClutchSWUB= Btm_ECUCCVS_ClutchSW_2Bits;
    ECUCCVS_swCCSSetSWUB= Btm_ECUCCVS_CCSSetSW_2Bits;
    ECUCCVS_swCCSSetSWUB= Btm_ECUCCVS_CCSCoastSW_2Bits;
    ECUCCVS_swCCSResumeSWUB= Btm_ECUCCVS_CCSResumeSW_2Bits;
    ECUCCVS_swCCSAccelSWUB= Btm_ECUCCVS_CCSAccelSW_2Bits;
    ECUCCVS_kmphCCSSetSpdUB= Btm_ECUCCVS_CCSSetSpd_Byte;
    ECUCCVS_stCCSPTOStUB= Btm_ECUCCVS_CCSPTOSt_5DBits%32;
    ECUCCVS_stCCSCtlStUB= Btm_ECUCCVS_CCSCtlSt_3DBits/32;
    ECUCCVS_swEngIdleIncrementSWUB= Btm_ECUCCVS_EngIdleIncrementSW_2Bits;
    ECUCCVS_swEngIdleDecrementSWUB= Btm_ECUCCVS_EngIdleDecrementSW_2Bits;
    ECUCCVS_swEngTestMdSWUB= Btm_ECUCCVS_EngTestMdSW_2Bits;
    ECUCCVS_swEngShutdownOrSWUB= Btm_ECUCCVS_EngShutdownOrSW_2Bits;
    
    CANInputUpdt_stECUCCVSUB = 0;
  }//   
}//


void ECU2HCU_AMBUpdate(void)//
{
  //
  if(CANInputUpdt_stECUAMBUB == 1)//
  {
    //
    ECUAMB_pBarometricPressUB= Btm_ECUAMB_BarometricPress_Byte/2;  //大气压力 分辨率1/2 偏移量0
    
    CANInputUpdt_stECUAMBUB = 0;
  }//  
}//



void ECU2HCU_ERC1Update(void)//
{
  //
  if(CANInputUpdt_stECUERC1UB == 1)//
  {
    //
    ECUERC1_pctActualRetarderTrqPctUB= Btm_ECUERC1_ActualRetarderTrqPct_Byte;  //分辨率1 偏移量0
    
    CANInputUpdt_stECUERC1UB = 0;
  }//  
}//




















