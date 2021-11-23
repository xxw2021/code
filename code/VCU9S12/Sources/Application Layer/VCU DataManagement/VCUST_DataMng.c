#include "Allh.h"





const ConstParam_ZHVCU ZHVCU_ConstP = {
  /* Computed Parameter: Map_EngAnly_VehSpd2SlideEngSpdL
   * Referenced by: '<S12>/Map_EngAnly_VehSpd2SlideEngSpdLThr'
   */
  { 700U, 700U, 700U, 700U, 700U, 700U, 700U, 750U, 750U, 750U, 750U, 800U, 800U,
    800U, 800U, 800U, 800U, 800U, 800U },

  /* Computed Parameter: Map_TrqCtrl_VehMassRatioEngSpd2
   * Referenced by: '<Root>/Map_TrqCtrl_VehMassRatioEngSpd2TrqCrtRatio'
   */
  { 10U, 17U }
};


uint16_T AnaSen_barAirTankPrsF100UW;
uint16_T AnaSen_vBatteryVF100UW;
//uint8_T CANTimeout_stECUUB;
//uint8_T CANTimeout_stMeterUB;
//uint8_T CANTxAllow_stECUEBC1UB;
//uint8_T CANTxAllow_stECUTSC1UB;
uint8_T DrvMdST_numSSStartTimerUW;
uint16_T DrvMdST_numSSStopAllowTimerUW;
uint8_T DrvMdST_stSSMtrStartErrFlagUB;
uint8_T DrvMdST_stSSStartErrFlagUB;
uint8_T DrvMdST_stSSWorkStUB;
uint8_T ECUAMB_tAmbAirTempUB;
uint8_T ECUAMB_tEngAirInletTempUB;
uint16_T ECUCCVS_kmphVehSpdF100UW;
uint8_T ECUCCVS_kmphVehSpdUB;
uint8_T ECUCCVS_stBrakeSWUB;
uint8_T ECUCCVS_stClutchSWUB;
uint16_T ECUEBC2_kmphFrontAxleLeftSpdUW;
uint16_T ECUEBC2_kmphFrontAxleRightSpdUW;
uint16_T ECUEBC2_kmphFrontAxleSpdUW;
uint16_T ECUEBC2_kmphRearAxleLeftSpdUW;
uint16_T ECUEBC2_kmphRearAxleRightSpdUW;
//uint16_T ECUEC1_nmEngRefTrqUW;
uint8_T ECUEC1_sEngMaxOverrideTimeLmtUB;
//uint8_T ECUEEC1_pctActualTrqUB;
//uint8_T ECUEEC1_pctDrvTrqDmdUB;
uint8_T ECUEEC1_pctEngTrqDmdUB;
//uint16_T ECUEEC1_rpmEngSpdUW;
uint8_T ECUEEC1_stEngStarterMdUB;
//uint8_T ECUEEC1_stEngTrqMdUB;
//uint8_T ECUEEC1_stSourceOFEngCtrlUB;
//uint8_T ECUEEC2_pctAccelPedalPosUB;
uint8_T ECUEEC2_pctEngLoadAtCurSpdUB;
uint8_T ECUEEC2_pctMaxAvaEngTrqUB;
uint16_T ECUEEC3_kgphAfterExhaustGasMasFlowUW;
//uint8_T ECUEEC3_pctNomFriTrqPctUB;
uint16_T ECUEEC3_rpmEngDesriedOperatSpdAAdjUW;
uint16_T ECUEEC3_rpmEngDesriedOperatSpdUW;
uint8_T ECUEFL_kpaEngOilPreUB;
uint8_T ECUERC1_stRetarderTrqMdeUB;
uint8_T ECUET1_tEngCoolantTempUB;
uint32_T ECUHOURS_hEngTotalHoursUL;
uint32_T ECUHOURS_hEngTotalRvlUL;
//uint32_T ECULFC_lEngTotalFuelUL;
//uint32_T ECULFC_lEngTripFuelUL;
uint16_T ECULFE_lphEngAvgFuelRateUW;
//uint16_T ECULFE_lphEngFuelRateUW;
uint16_T ECULFE_lphEngInstFuelRateUW;
uint8_T ECUTI1_stCatalystTankLevelUB;
uint8_T ECUTI1_tCatalystTankTempUB;
//uint8_T ECUTSC1_pctTrqDmdLmtUB;
//uint16_T ECUTSC1_rpmSpdDmdLmtUW;
uint8_T ECUTSC1_stEngOverrideCtrlMdeUB;
uint16_T EngAnly_nmActualTrqUW;
uint16_T EngAnly_nmDrvTrqDmdUW;
uint16_T EngAnly_nmEngLoadTrqAtCurSpdUW;
uint16_T EngAnly_nmEngRTOutCurveTrqUW;
uint16_T EngAnly_nmEngRefTrqUW;
uint16_T EngAnly_nmEngTrqDmdUW;
uint16_T EngAnly_nmMaxAvaEngTrqUW;
uint16_T EngAnly_nmNomFriTrqUW;
uint16_T EngAnly_rpmEngSpdBrakeLThrUW;
uint16_T EngAnly_rpmEngSpdSlideLThrUW;
//uint8_T EngAnly_stEngStartedStUB;
uint8_T EngCtrl_pctBrakeTrqDmdUB;
uint8_T EngCtrl_pctSlideTrqDmdUB;
uint8_T MdAllow_stSSCycleUB;
uint8_T MdAllow_stSSStopUB;
uint8_T MdSTExe_stMdCalUB;
uint8_T MdST_stDrvMdUB;
uint8_T MdST_stMainMdUB;
uint8_T MdST_stStartMdUB;
uint8_T MdST_stStopMdUB;
uint16_T MeterTCO1_kmphVehSpdF100UW;
//uint8_T MeterTCO1_kmphVehSpdUB;
uint8_T PwrDrv_stStartSWChORlyUB;
//uint8_T PwrDrv_stViceStartUB;
//uint8_T PwrDrv_stViceStopUB;
uint8_T SWAnly_stGearChgUB;
uint8_T SWSen_stABSWorkUB;
uint8_T SWSen_stACACUB;
uint8_T SWSen_stBrakeSWUB;
uint8_T SWSen_stClutchSWUB;
uint8_T SWSen_stNeutralSWUB;
//uint8_T SWSen_stONSWUB;
uint8_T SWSen_stParkBrakeSWUB;
uint8_T SWSen_stReverseSWUB;
uint8_T SWSen_stSSMdUB;
uint8_T SWSen_stSafetyBeltUB;
uint8_T SWSen_stStartSWUB;
uint8_T SubSysTskExe_stCANUB;
uint8_T SubSysTskExe_stECUUB;
uint8_T SubSysTskExe_stMeterUB;
uint8_T SubSysTskExe_stStartSWChOUB;
uint8_T SubSysTskExe_stViceSSUB;
uint16_T TrqCtrl_nmEngRawTrqCtrlUW;
uint16_T TrqCtrl_nmEngTrqCtrlMinDiffUW;
uint16_T TrqCtrl_nmEngTrqCtrlUW;
uint16_T TrqCtrl_nmEngTrqIncStepUW;
uint16_T TrqCtrl_nmTrqDmdAftCrtUW;
uint16_T TrqCtrl_nmTrqDmdCrtRawUW;
uint16_T TrqCtrl_nmTrqDmdCrtUW;
uint16_T TrqCtrl_nmTrqDmdIncDiffUW;
uint16_T TrqCtrl_nmTrqDmdRawUW;
uint16_T TrqCtrl_nmVehMassEngTrqCrtRatioUW;
uint16_T TrqCtrl_numEngTrqIncStepmsTimeUW;
uint16_T TrqCtrl_numEngTrqIncStepmsTimerUW;
uint8_T TrqCtrl_pctEngTrqCtrlUB;
uint16_T TrqCtrl_pctTrqDmdCrtRatioUW;
uint16_T TrqCtrl_pctVehMassEngTrqCrtRatioUW;
uint16_T VehAnly_numGearNowUW;
uint8_T VehAnly_pctVehMassRatioUB;
uint16_T VehAnly_rGearBoxRatioUW;
uint16_T VehAnly_rGearRatioUW;
uint8_T VehAnly_stTSConedUB;
uint8_T VehAnly_stVehBrakeStUB;
uint8_T ViceSSCtl_stViceStopCANUB;
uint8_T ViceSS_stStopConditionUB;

/* Definition for custom storage class: Global */
uint16_T DrvMdST_numSSStartMaxTimeUWC = 0U;
uint16_T ECUAnly_nmEngRefTrqInitUWC = 0U;
uint16_T EngAnly_rpmEngStartedSpdLThrUWC = 0U;
uint16_T EngAnly_rpmSSEngStopSpdHThrUWC = 0U;
uint8_T EngAnly_tMtrStartEngTempLThrUBC = 0U;
uint16_T MapAccPedalPos2EngTrqIncTimer_numTrqIncTimerUWA[21] = { 1U, 3U, 4U, 5U,
  6U, 7U, 8U, 9U, 10U, 15U, 20U, 15U, 10U, 8U, 7U, 6U, 5U, 4U, 4U, 4U, 4U } ;

uint16_T MapAccPedalPos2EngTrqIncTimer_pctAccPedalPosUWA[21] = { 0U, 5U, 10U,
  15U, 20U, 25U, 30U, 35U, 40U, 45U, 50U, 55U, 60U, 65U, 70U, 75U, 80U, 85U, 90U,
  95U, 100U } ;

uint16_T MapAccPos2TrqDmdCrtRatio_pctAccPosUWA[21] = { 0U, 5U, 10U, 15U, 20U,
  25U, 30U, 35U, 40U, 45U, 50U, 55U, 60U, 65U, 70U, 75U, 80U, 85U, 90U, 95U,
  100U } ;

uint16_T MapAccPos2TrqDmdCrtRatio_pctTrqCrtRatioUWA[21] = { 10U, 20U, 30U, 40U,
  50U, 60U, 70U, 98U, 92U, 66U, 54U, 64U, 54U, 51U, 65U, 24U, 66U, 24U, 66U, 54U,
  55U } ;

uint16_T MapEngRTOutCurve_nmEngTrqUWA[6] = { 600U, 800U, 1500U, 1500U, 1400U, 0U
} ;

uint16_T MapEngRTOutCurve_rpmEngSpdUWA[6] = { 600U, 800U, 1200U, 1400U, 1800U,
  2400U } ;

uint16_T MapEngSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUWA[27] = { 40U, 20U, 10U, 5U,
  3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U } ;

uint16_T MapEngSpd2BrakeEngTrqPctCtrl_rpmEngSpdUWA[27] = { 0U, 500U, 600U, 700U,
  800U, 900U, 1000U, 1100U, 1200U, 1300U, 1400U, 1500U, 1600U, 1700U, 1800U,
  1900U, 2000U, 2100U, 2200U, 2400U, 2600U, 2800U, 3000U, 3500U, 4000U, 4500U,
  5000U } ;

uint16_T MapEngSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUWA[27] = { 40U, 20U, 10U, 5U,
  3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U } ;

uint16_T MapEngSpd2SlideEngTrqPctCtrl_rpmEngSpdUWA[27] = { 0U, 500U, 600U, 700U,
  800U, 900U, 1000U, 1100U, 1200U, 1300U, 1400U, 1500U, 1600U, 1700U, 1800U,
  1900U, 2000U, 2100U, 2200U, 2400U, 2600U, 2800U, 3000U, 3500U, 4000U, 4500U,
  5000U } ;

uint16_T MapEngSpd2TrqDmdCrt_nmTrqDmdCrtUWA[35] = { 100U, 100U, 100U, 100U, 80U,
  80U, 90U, 85U, 75U, 65U, 60U, 50U, 55U, 56U, 80U, 100U, 75U, 65U, 60U, 50U,
  55U, 56U, 80U, 75U, 65U, 60U, 50U, 55U, 56U, 80U, 75U, 65U, 60U, 50U, 55U } ;

uint16_T MapEngSpd2TrqDmdCrt_rpmEngSpdUWA[35] = { 600U, 700U, 800U, 900U, 1000U,
  1100U, 1200U, 1300U, 1400U, 1500U, 1600U, 1700U, 1800U, 1900U, 2000U, 2100U,
  2200U, 2300U, 2400U, 2500U, 2600U, 2700U, 2800U, 2900U, 3000U, 3100U, 3200U,
  3300U, 3400U, 3500U, 3600U, 3700U, 3800U, 3900U, 4000U } ;

uint16_T MapEngTrqDmdIncDiff2TrqIncStep_nmTrqDmdIncDiffUWA[32] = { 0U, 10U, 20U,
  40U, 60U, 80U, 100U, 130U, 160U, 190U, 220U, 250U, 300U, 400U, 500U, 600U,
  700U, 800U, 900U, 1000U, 1100U, 1200U, 1300U, 1400U, 1500U, 1600U, 1700U,
  1800U, 1900U, 2000U, 2300U, 2500U } ;

uint16_T MapEngTrqDmdIncDiff2TrqIncStep_nmTrqIncStepUWA[32] = { 0U, 1U, 2U, 4U,
  6U, 8U, 10U, 13U, 16U, 19U, 22U, 25U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U,
  110U, 120U, 130U, 140U, 150U, 160U, 170U, 180U, 190U, 200U, 230U, 250U } ;

uint16_T MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmIncTrqDiffUWA[26] = { 0U, 10U, 20U,
  30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 125U, 150U, 175U, 200U, 250U, 300U,
  400U, 600U, 800U, 1000U, 1500U, 2000U, 2500U, 3000U, 4000U } ;

uint16_T MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmTrqCtrlMidDiffUWA[26] = { 0U, 17U,
  17U, 17U, 20U, 40U, 40U, 40U, 50U, 50U, 50U, 50U, 50U, 50U, 50U, 50U, 50U, 50U,
  50U, 50U, 50U, 50U, 50U, 50U, 50U, 50U } ;

uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_pctTrqCrtRatioUWA[198] = { 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 30U, 20U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 100U, 90U, 20U, 10U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 100U, 100U, 90U, 30U, 10U, 0U, 0U, 0U, 0U, 0U, 0U,
  100U, 100U, 100U, 90U, 40U, 20U, 0U, 0U, 0U, 0U, 0U, 100U, 100U, 100U, 100U,
  90U, 60U, 0U, 0U, 0U, 0U, 0U, 100U, 100U, 100U, 100U, 100U, 90U, 20U, 0U, 0U,
  0U, 0U, 100U, 100U, 100U, 100U, 100U, 100U, 90U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U } ;

uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_pctVehMassRatioUWA[11] = { 0U, 10U,
  20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U } ;

uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_rpmEngSpdUWA[18] = { 600U, 800U,
  1000U, 1200U, 1400U, 1600U, 1800U, 2000U, 2200U, 2400U, 2600U, 2800U, 3000U,
  3200U, 3400U, 3800U, 4000U, 5000U } ;

uint16_T MapVehSpd2BrakeEngSpdLThr_kmphVehSpdUWA[19] = { 0U, 5U, 10U, 15U, 20U,
  25U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 120U, 140U, 160U, 180U, 200U } ;

uint16_T MapVehSpd2BrakeEngSpdLThr_rpmEngSpdUWA[19] = { 700U, 700U, 700U, 700U,
  700U, 700U, 700U, 750U, 750U, 750U, 750U, 800U, 800U, 800U, 800U, 800U, 800U,
  800U, 800U } ;

uint8_T MapVehSpd2BrakeEngTrqPctCtrl_kmphVehSpdUBA[23] = { 0U, 3U, 5U, 10U, 15U,
  20U, 25U, 30U, 35U, 40U, 45U, 50U, 60U, 70U, 80U, 90U, 100U, 110U, 120U, 130U,
  140U, 150U, 200U } ;

uint8_T MapVehSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUBWA[23] = { 10U, 6U, 6U, 5U,
  5U, 4U, 3U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

uint16_T MapVehSpd2SlideEngSpdLThr_kmphVehSpdUWA[19] = { 0U, 5U, 10U, 15U, 20U,
  25U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U, 120U, 140U, 160U, 180U, 200U } ;

uint8_T MapVehSpd2SlideEngTrqPctCtrl_kmphVehSpdUBA[23] = { 0U, 3U, 5U, 10U, 15U,
  20U, 25U, 30U, 35U, 40U, 45U, 50U, 60U, 70U, 80U, 90U, 100U, 110U, 120U, 130U,
  140U, 150U, 200U } ;

uint8_T MapVehSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUBWA[23] = { 10U, 6U, 6U, 5U,
  5U, 4U, 3U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

uint8_T MdST_pctAccPedalPosDrvSlideAccHThrUB = 0U;
uint8_T MdST_pctAccPedalPosDrvSlideHThrUB = 0U;
uint8_T MdST_tDrvSSEngTempLThrUBC = 0U;
uint8_T TrqCtrl_pctEngTrqCtrlLowLmtUBC = 0U;
uint8_T TrqCtrl_pctEngTrqCtrlUpLmtUBC = 0U;
uint8_T TrqCtrl_stMassCorrEnUBC = 0U;
uint8_T TrqMng_pctDrvDmd2TrqDmdRatioUBC = 0U;
uint16_T VehAnly_numGearConfirmTimeUWC = 0U;
uint8_T VehAnly_pctVehMassRatioLowLmtUBC = 0U;
uint8_T VehAnly_pctVehMassRatioUpLmtUBC = 0U;
uint8_T VehAnly_tVehActualMassUB = 0U;
uint8_T VehAnly_tVehBasicMassUBC = 0U;







void VCUST_ValueInit(void)//
{
  //
  DrvMdST_numSSStartMaxTimeUWC = 0U;
  ECUAnly_nmEngRefTrqInitUWC = 0U;
  EngAnly_rpmEngStartedSpdLThrUWC = 0U;
  EngAnly_rpmSSEngStopSpdHThrUWC = 0U;
  EngAnly_tMtrStartEngTempLThrUBC = 0U;
  MdST_pctAccPedalPosDrvSlideAccHThrUB = 0U;
  MdST_pctAccPedalPosDrvSlideHThrUB = 0U;
  MdST_tDrvSSEngTempLThrUBC = 0U;
  TrqCtrl_pctEngTrqCtrlLowLmtUBC = 0U;
  TrqCtrl_pctEngTrqCtrlUpLmtUBC = 0U;
  TrqCtrl_stMassCorrEnUBC = 0U;
  TrqMng_pctDrvDmd2TrqDmdRatioUBC = 0U;
  VehAnly_numGearConfirmTimeUWC = 0U;
  VehAnly_pctVehMassRatioLowLmtUBC = 0U;
  VehAnly_pctVehMassRatioUpLmtUBC = 0U;
  VehAnly_tVehActualMassUB = 0U;
  VehAnly_tVehBasicMassUBC = 0U;
  
  
  
}//







