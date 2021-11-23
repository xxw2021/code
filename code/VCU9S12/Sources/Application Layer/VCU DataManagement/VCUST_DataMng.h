/*
 * HybridST_DataMng.h
 *
 *  Created on: 2018年3月28日
 *      Author: Administrator
 */

#ifndef __VCUST_DATAMNG_H_
#define __VCUST_DATAMNG_H_


#include "TypeDefine.h"




//void* memset(void* s, int c, size_t n);
void CalData_ValueInit(void);




#define StepTime        10
#define msStepTime      10
#define sStepTime       100
#define ms100StepTime   10
#define ms10StepTime    1
#define ms20StepTime    2



#define St_Normal   0
#define St_Warning  1
#define St_Red      2
#define St_Err      3


#define VehAnly_stTSConedUB_Open           0
#define VehAnly_stTSConedUB_Closed         1
#define VehAnly_stTSConedUB_HalfClosed     2

//Stop
#define MdST_stMainMdUB_Stop               0
#define MdST_stStopMdUB_Exit               0
#define MdST_stStopMdUB_ON                 11

//Start
#define MdST_stMainMdUB_Start               1
#define MdST_stStartMdUB_Exit               0
#define MdST_stStartMdUB_StarterStart       21

//Drv
#define MdST_stMainMdUB_Drv                 2
#define MdST_stDrvMdUB_Exit                 0
#define MdST_stDrvMdUB_SSStopped            31
#define MdST_stDrvMdUB_SSStop               32
#define MdST_stDrvMdUB_Launch               33
#define MdST_stDrvMdUB_Brake                34
#define MdST_stDrvMdUB_SSStart              35
#define MdST_stDrvMdUB_Drv                  36
#define MdST_stDrvMdUB_SlideAcc             37
#define MdST_stDrvMdUB_Slide                38
#define MdST_stDrvMdUB_Standby              39


//部件动作
//CAN
#define SubSysTsk_CAN_POST              0
//Meter
#define SubSysTsk_Meter_POST            0
//ECU
#define SubSysTsk_ECU_Exit              0
#define SubSysTsk_ECU_Drv               1
#define SubSysTsk_ECU_Slide             2
#define SubSysTsk_ECU_Brake             3


//StartSWChO
#define SubSysTsk_StartSWChO_Exit       0
#define SubSysTsk_StartSWChO_OFF        0
#define SubSysTsk_StartSWChO_ON         1
//ViceSS
#define SubSysTsk_ViceSS_Exit           0
#define SubSysTsk_ViceSS_Start          1
#define SubSysTsk_ViceSS_Stop           2


//发动机部件控制
#define EngCtrlMd_CtrlOff             0
#define EngCtrlMd_SpdCtrl             1
#define EngCtrlMd_TrqCtrl             2
#define EngCtrlMd_SpdTrqlmt           3




#define Gear_R            100
#define Gear_R7           118
#define Gear_R6           119
#define Gear_R5           120
#define Gear_R4           121
#define Gear_R3           122
#define Gear_R2           123
#define Gear_R1           124
#define Gear_N            125
#define Gear_D1           126
#define Gear_D2           127
#define Gear_D3           128
#define Gear_D4           129
#define Gear_D5           130
#define Gear_D6           131
#define Gear_D7           132
#define Gear_D8           133
#define Gear_D9           134
#define Gear_D10          135
#define Gear_D11          136
#define Gear_D12          137
#define Gear_D13          138
#define Gear_D14          139
#define Gear_D15          140
#define Gear_D16          141
#define Gear_D17          142
#define Gear_D18          143
#define Gear_X            250

#define GearRatio_D1        41
#define GearRatio_D2        52
#define GearRatio_D3        67
#define GearRatio_D4        87
#define GearRatio_D5        116
#define GearRatio_D6        143
#define GearRatio_D7        183
#define GearRatio_D8        236
#define GearRatio_D9        303
#define GearRatio_D10       389
#define GearRatio_D11       498
#define GearRatio_D12       638

#define GearBoxRatio_D1     1210
#define GearBoxRatio_D2     941
#define GearBoxRatio_D3     731
#define GearBoxRatio_D4     571
#define GearBoxRatio_D5     446
#define GearBoxRatio_D6     348
#define GearBoxRatio_D7     271
#define GearBoxRatio_D8     211
#define GearBoxRatio_D9     164
#define GearBoxRatio_D10    128
#define GearBoxRatio_D11    100
#define GearBoxRatio_D12    78
#define GearBoxRatio_R    1156

#define GearRatio_D1_LThr        36       //+- 5      36-46
#define GearRatio_D1_HThr        46       //+- 5      36-46

#define GearRatio_D2_LThr        46       //+- 7      46-60
#define GearRatio_D2_HThr        60       //+- 7      46-60

#define GearRatio_D3_LThr        60       //+- 8      60-76
#define GearRatio_D3_HThr        76       //+- 8      60-76

#define GearRatio_D4_LThr        77       //+- 10     77-97
#define GearRatio_D4_HThr        97       //+- 10     77-97

#define GearRatio_D5_LThr        105      //+- 10     106-126
#define GearRatio_D5_HThr        126      //+- 10     106-126

#define GearRatio_D6_LThr        127      //+- 16     127-159
#define GearRatio_D6_HThr        159      //+- 16     127-159

#define GearRatio_D7_LThr        160      //+- 15     168-198
#define GearRatio_D7_HThr        210      //+- 15     168-198

#define GearRatio_D8_LThr        220      //+- 15     221-251
#define GearRatio_D8_HThr        260      //+- 15     221-251

#define GearRatio_D9_LThr        280      //+- 20     283-323
#define GearRatio_D9_HThr        330      //+- 20     283-323

#define GearRatio_D10_LThr       350      //+- 20     369-409
#define GearRatio_D10_HThr       420      //+- 20     369-409

#define GearRatio_D11_LThr       450      //+- 30     468-528
#define GearRatio_D11_HThr       550      //+- 30     468-528

#define GearRatio_D12_LThr       580      //+- 40     398-678
#define GearRatio_D12_HThr       690      //+- 40     398-678





extern uint16_T AnaSen_barAirTankPrsF100UW;
extern uint16_T AnaSen_vBatteryVF100UW;
//extern uint8_T CANTimeout_stECUUB;
//extern uint8_T CANTimeout_stMeterUB;
//extern uint8_T CANTxAllow_stECUEBC1UB;
//extern uint8_T CANTxAllow_stECUTSC1UB;
extern uint8_T DrvMdST_numSSStartTimerUW;
extern uint16_T DrvMdST_numSSStopAllowTimerUW;
extern uint8_T DrvMdST_stSSMtrStartErrFlagUB;
extern uint8_T DrvMdST_stSSStartErrFlagUB;
extern uint8_T DrvMdST_stSSWorkStUB;
extern uint8_T ECUAMB_tAmbAirTempUB;
extern uint8_T ECUAMB_tEngAirInletTempUB;
extern uint16_T ECUCCVS_kmphVehSpdF100UW;
extern uint8_T ECUCCVS_kmphVehSpdUB;
extern uint8_T ECUCCVS_stBrakeSWUB;
extern uint8_T ECUCCVS_stClutchSWUB;
extern uint16_T ECUEBC2_kmphFrontAxleLeftSpdUW;
extern uint16_T ECUEBC2_kmphFrontAxleRightSpdUW;
extern uint16_T ECUEBC2_kmphFrontAxleSpdUW;
extern uint16_T ECUEBC2_kmphRearAxleLeftSpdUW;
extern uint16_T ECUEBC2_kmphRearAxleRightSpdUW;
//extern uint16_T ECUEC1_nmEngRefTrqUW;
extern uint8_T ECUEC1_sEngMaxOverrideTimeLmtUB;
//extern uint8_T ECUEEC1_pctActualTrqUB;
//extern uint8_T ECUEEC1_pctDrvTrqDmdUB;
extern uint8_T ECUEEC1_pctEngTrqDmdUB;
//extern uint16_T ECUEEC1_rpmEngSpdUW;
extern uint8_T ECUEEC1_stEngStarterMdUB;
//extern uint8_T ECUEEC1_stEngTrqMdUB;
//extern uint8_T ECUEEC1_stSourceOFEngCtrlUB;
//extern uint8_T ECUEEC2_pctAccelPedalPosUB;
extern uint8_T ECUEEC2_pctEngLoadAtCurSpdUB;
extern uint8_T ECUEEC2_pctMaxAvaEngTrqUB;
extern uint16_T ECUEEC3_kgphAfterExhaustGasMasFlowUW;
//extern uint8_T ECUEEC3_pctNomFriTrqPctUB;
extern uint16_T ECUEEC3_rpmEngDesriedOperatSpdAAdjUW;
extern uint16_T ECUEEC3_rpmEngDesriedOperatSpdUW;
extern uint8_T ECUEFL_kpaEngOilPreUB;
extern uint8_T ECUERC1_stRetarderTrqMdeUB;
extern uint8_T ECUET1_tEngCoolantTempUB;
extern uint32_T ECUHOURS_hEngTotalHoursUL;
extern uint32_T ECUHOURS_hEngTotalRvlUL;
//extern uint32_T ECULFC_lEngTotalFuelUL;
//extern uint32_T ECULFC_lEngTripFuelUL;
extern uint16_T ECULFE_lphEngAvgFuelRateUW;
//extern uint16_T ECULFE_lphEngFuelRateUW;
extern uint16_T ECULFE_lphEngInstFuelRateUW;
extern uint8_T ECUTI1_stCatalystTankLevelUB;
extern uint8_T ECUTI1_tCatalystTankTempUB;
//extern uint8_T ECUTSC1_pctTrqDmdLmtUB;
//extern uint16_T ECUTSC1_rpmSpdDmdLmtUW;
extern uint8_T ECUTSC1_stEngOverrideCtrlMdeUB;
extern uint16_T EngAnly_nmActualTrqUW;
extern uint16_T EngAnly_nmDrvTrqDmdUW;
extern uint16_T EngAnly_nmEngLoadTrqAtCurSpdUW;
extern uint16_T EngAnly_nmEngRTOutCurveTrqUW;
extern uint16_T EngAnly_nmEngRefTrqUW;
extern uint16_T EngAnly_nmEngTrqDmdUW;
extern uint16_T EngAnly_nmMaxAvaEngTrqUW;
extern uint16_T EngAnly_nmNomFriTrqUW;
extern uint16_T EngAnly_rpmEngSpdBrakeLThrUW;
extern uint16_T EngAnly_rpmEngSpdSlideLThrUW;
//extern uint8_T EngAnly_stEngStartedStUB;
extern uint8_T EngCtrl_pctBrakeTrqDmdUB;
extern uint8_T EngCtrl_pctSlideTrqDmdUB;
extern uint8_T MdAllow_stSSCycleUB;
extern uint8_T MdAllow_stSSStopUB;
extern uint8_T MdSTExe_stMdCalUB;
extern uint8_T MdST_stDrvMdUB;
extern uint8_T MdST_stMainMdUB;
extern uint8_T MdST_stStartMdUB;
extern uint8_T MdST_stStopMdUB;
extern uint16_T MeterTCO1_kmphVehSpdF100UW;
//extern uint8_T MeterTCO1_kmphVehSpdUB;
extern uint8_T PwrDrv_stStartSWChORlyUB;
//extern uint8_T PwrDrv_stViceStartUB;
//extern uint8_T PwrDrv_stViceStopUB;
extern uint8_T SWAnly_stGearChgUB;
extern uint8_T SWSen_stABSWorkUB;
extern uint8_T SWSen_stACACUB;
extern uint8_T SWSen_stBrakeSWUB;
extern uint8_T SWSen_stClutchSWUB;
extern uint8_T SWSen_stNeutralSWUB;
//extern uint8_T SWSen_stONSWUB;
extern uint8_T SWSen_stParkBrakeSWUB;
extern uint8_T SWSen_stReverseSWUB;
extern uint8_T SWSen_stSSMdUB;
extern uint8_T SWSen_stSafetyBeltUB;
extern uint8_T SWSen_stStartSWUB;
extern uint8_T SubSysTskExe_stCANUB;
extern uint8_T SubSysTskExe_stECUUB;
extern uint8_T SubSysTskExe_stMeterUB;
extern uint8_T SubSysTskExe_stStartSWChOUB;
extern uint8_T SubSysTskExe_stViceSSUB;
extern uint16_T TrqCtrl_nmEngRawTrqCtrlUW;
extern uint16_T TrqCtrl_nmEngTrqCtrlMinDiffUW;
extern uint16_T TrqCtrl_nmEngTrqCtrlUW;
extern uint16_T TrqCtrl_nmEngTrqIncStepUW;
extern uint16_T TrqCtrl_nmTrqDmdAftCrtUW;
extern uint16_T TrqCtrl_nmTrqDmdCrtRawUW;
extern uint16_T TrqCtrl_nmTrqDmdCrtUW;
extern uint16_T TrqCtrl_nmTrqDmdIncDiffUW;
extern uint16_T TrqCtrl_nmTrqDmdRawUW;
extern uint16_T TrqCtrl_nmVehMassEngTrqCrtRatioUW;
extern uint16_T TrqCtrl_numEngTrqIncStepmsTimeUW;
extern uint16_T TrqCtrl_numEngTrqIncStepmsTimerUW;
extern uint8_T TrqCtrl_pctEngTrqCtrlUB;
extern uint16_T TrqCtrl_pctTrqDmdCrtRatioUW;
extern uint16_T TrqCtrl_pctVehMassEngTrqCrtRatioUW;
extern uint16_T VehAnly_numGearNowUW;
extern uint8_T VehAnly_pctVehMassRatioUB;
extern uint16_T VehAnly_rGearBoxRatioUW;
extern uint16_T VehAnly_rGearRatioUW;
extern uint8_T VehAnly_stTSConedUB;
extern uint8_T VehAnly_stVehBrakeStUB;
extern uint8_T ViceSSCtl_stViceStopCANUB;
extern uint8_T ViceSS_stStopConditionUB;

/* Definition for custom storage class: Global */
extern uint16_T DrvMdST_numSSStartMaxTimeUWC;
extern uint16_T ECUAnly_nmEngRefTrqInitUWC;
extern uint16_T EngAnly_rpmEngStartedSpdLThrUWC;
extern uint16_T EngAnly_rpmSSEngStopSpdHThrUWC;
extern uint8_T EngAnly_tMtrStartEngTempLThrUBC;






extern uint16_T MapAccPedalPos2EngTrqIncTimer_numTrqIncTimerUWA[21];
extern uint16_T MapAccPedalPos2EngTrqIncTimer_pctAccPedalPosUWA[21];
extern uint16_T MapAccPos2TrqDmdCrtRatio_pctAccPosUWA[21];
extern uint16_T MapAccPos2TrqDmdCrtRatio_pctTrqCrtRatioUWA[21];
extern uint16_T MapEngRTOutCurve_nmEngTrqUWA[6];
extern uint16_T MapEngRTOutCurve_rpmEngSpdUWA[6];
extern uint16_T MapEngSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUWA[27];
extern uint16_T MapEngSpd2BrakeEngTrqPctCtrl_rpmEngSpdUWA[27];
extern uint16_T MapEngSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUWA[27];
extern uint16_T MapEngSpd2SlideEngTrqPctCtrl_rpmEngSpdUWA[27];
extern uint16_T MapEngSpd2TrqDmdCrt_nmTrqDmdCrtUWA[35];
extern uint16_T MapEngSpd2TrqDmdCrt_rpmEngSpdUWA[35];
extern uint16_T MapEngTrqDmdIncDiff2TrqIncStep_nmTrqDmdIncDiffUWA[32];
extern uint16_T MapEngTrqDmdIncDiff2TrqIncStep_nmTrqIncStepUWA[32];
extern uint16_T MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmIncTrqDiffUWA[26];
extern uint16_T MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmTrqCtrlMidDiffUWA[26];
extern uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_pctTrqCrtRatioUWA[198];
extern uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_pctVehMassRatioUWA[11];
extern uint16_T MapVehMassRatioEngSpd2EngTrqCrtRatio_rpmEngSpdUWA[18];
extern uint16_T MapVehSpd2BrakeEngSpdLThr_kmphVehSpdUWA[19];
extern uint16_T MapVehSpd2BrakeEngSpdLThr_rpmEngSpdUWA[19];
extern uint8_T MapVehSpd2BrakeEngTrqPctCtrl_kmphVehSpdUBA[23];
extern uint8_T MapVehSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUBWA[23];
extern uint16_T MapVehSpd2SlideEngSpdLThr_kmphVehSpdUWA[19];
extern uint8_T MapVehSpd2SlideEngTrqPctCtrl_kmphVehSpdUBA[23];
extern uint8_T MapVehSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUBWA[23];



extern uint8_T MdST_pctAccPedalPosDrvSlideAccHThrUB;
extern uint8_T MdST_pctAccPedalPosDrvSlideHThrUB;
extern uint8_T MdST_tDrvSSEngTempLThrUBC;
extern uint8_T TrqCtrl_pctEngTrqCtrlLowLmtUBC;
extern uint8_T TrqCtrl_pctEngTrqCtrlUpLmtUBC;
extern uint8_T TrqCtrl_stMassCorrEnUBC;
extern uint8_T TrqMng_pctDrvDmd2TrqDmdRatioUBC;
extern uint16_T VehAnly_numGearConfirmTimeUWC;
extern uint8_T VehAnly_pctVehMassRatioLowLmtUBC;
extern uint8_T VehAnly_pctVehMassRatioUpLmtUBC;
extern uint8_T VehAnly_tVehActualMassUB;
extern uint8_T VehAnly_tVehBasicMassUBC;


void VCUST_ValueInit(void);



#endif /* SYSTEM_APPLICATION_LAYER_HYBRIDST_DATAMNG_HYBRIDST_DATAMNG_H_ */
