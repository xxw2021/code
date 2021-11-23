/*
 * File: CrCtl.c
 *
 * Code generated for Simulink model 'CrCtl'.
 *
 * Model version                  : 1.3390
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Jul 23 15:02:00 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->HC(S)12
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CrCtl.h"
#include "CrCtl_private.h"

/* Named constants for Chart: '<S229>/manualShiftSuspChart' */
#define CrCtl_IN_CRCTL_SUSPENDENDRAMP_3h ((uint8_T)1U)
#define CrCtl_IN_CRCTL_SUSPENDNOTACTIVE_0h ((uint8_T)2U)
#define CrCtl_IN_CRCTL_SUSPENDRAMPDONE_2h ((uint8_T)3U)
#define CrCtl_IN_SUSPENDSTARTRUMP      ((uint8_T)1U)
#define CrCtl_IN_StepOutSuspend        ((uint8_T)1U)
#define CrCtl_IN_SuspendEndRump        ((uint8_T)2U)

/* Block signals (default storage) */
B_CrCtl_T CrCtl_B;

/* Block states (default storage) */
DW_CrCtl_T CrCtl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CrCtl_T CrCtl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CrCtl_T CrCtl_Y;

/* Real-time model */
RT_MODEL_CrCtl_T CrCtl_M_;
RT_MODEL_CrCtl_T *const CrCtl_M = &CrCtl_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
uint8_T AccPedPos1_pctUB;
int8_T ActlRtdrPctTrq_SB;
uint8_T ActualEngPercentTorque_UB;
uint8_T BrkCD_stPressed_UB;
uint8_T ConvCD_stClth_UB;
uint8_T CrCtl_CCAcc_UB;
uint8_T CrCtl_CCCstDecl_UB;
uint8_T CrCtl_CCRes_UB;
uint8_T CrCtl_CCSet_UB;
uint8_T CrCtl_CCVSCCSt_UB;
boolean_T CrCtl_PCCAct_BL;
uint8_T CrCtl_TC1DisengDiffLckRqFrtAxl1_UB;
uint8_T CrCtl_TC1DisengDrvlnReq_UB;
uint8_T CrCtl_TC1TrsReqGear_UB;
uint8_T CrCtl_TSC1EngOvrdCtrlMd_UB;
uint8_T CrCtl_enPCC_UB;
boolean_T CrCtl_stActive_BL;
uint8_T CrCtl_stModeIn_UB;
uint8_T CrCtl_stModeSubIn_UB;
uint8_T CrCtl_stOpFunc_UB;             /* State          Value (h)   Meaning
                                          CRCTL_NOTACTV  0           Cruise control inactive
                                          CRCTL_ACTV     1           Cruise control active
                                          CRCTL_OVERRIDE 2           Cruise control violation AccPed_trqDes > CrCtl_trqDes and AccPed_rChkdVal > 0% */
uint16_T CrCtl_tiPCCRmp_10msUW;
int32_T CrCtl_trqDes_10mNmSL;
int32_T CrCtl_trqPCCReqin_10mNmSL;
uint16_T CrCtl_vSetPointAct_mp_10mphUW;
uint16_T CrCtl_vSetPointTrgtIn_10mphUW;
uint16_T CrCtl_vSetPointTrgt_10mphUW;
uint8_T CrCtl_vSetPointTrgt_kmphUB;
int8_T EEC1_DrvrDmdEngPctTrq_UB;
uint8_T ETC1_trsSftPrcs_UB;
int8_T ETC2_trsCrntGr_SB;
int8_T ETC2_trsSlctGr_SB;
uint16_T EngReferenceTorque_NmUW;
int8_T EngRqedTorque_TorqueLimit_SB;
uint16_T EngSpeed_rpmUW;
boolean_T MFLv_resBL;
boolean_T MFLv_setDownBL;
boolean_T MFLv_setUpBL;
uint8_T MFLv_stCrCtlMode;
boolean_T MFLv_swtBL;
boolean_T PCC_TC1Act_Bl;
uint8_T PCC_offRsn_UB;
int8_T PCC_targetGear_SB;
int8_T PCC_trqReq_pctSB;
uint8_T PCC_vSetPointTrgt_kmphUW;
int32_T PrpBrk_trqDes_10mNmL;
uint16_T RefRtdrTrq_NmUW;
uint8_T TCU_stShiftHandle_UB;
uint16_T TachographVehicleSpeed_10mphUW;
uint16_T VSSCD_v_10mphUW;

/* Definition for custom storage class: Global */
uint8_T CRCTL_PCC = 10U;
int16_T CrCtl_AccIKi1_C = 110;
int16_T CrCtl_AccIKi2_C = 35;
int16_T CrCtl_AccIKi3_C = 55;
int16_T CrCtl_AccIKiNeg1_C = 110;
int16_T CrCtl_AccIKiNeg2_C = 45;
int16_T CrCtl_AccIKiNeg3_C = 60;
int16_T CrCtl_AccIKiPos1_C = 110;
int16_T CrCtl_AccIKiPos2_C = 45;
int16_T CrCtl_AccIKiPos3_C = 60;
int16_T CrCtl_AccIWinNeg1_C = 110;
int16_T CrCtl_AccIWinNeg2_C = 55;
int16_T CrCtl_AccIWinNeg3_C = 60;
int16_T CrCtl_AccIWinPos1_C = 110;
int16_T CrCtl_AccIWinPos2_C = 55;
int16_T CrCtl_AccIWinPos3_C = 60;
int16_T CrCtl_AccPKp1_C = 110;
int16_T CrCtl_AccPKp2_C = 35;
int16_T CrCtl_AccPKp3_C = 55;
int16_T CrCtl_AccPKpNeg1_C = 110;
int16_T CrCtl_AccPKpNeg2_C = 45;
int16_T CrCtl_AccPKpNeg3_C = 60;
int16_T CrCtl_AccPKpPos1_C = 110;
int16_T CrCtl_AccPKpPos2_C = 45;
int16_T CrCtl_AccPKpPos3_C = 60;
int16_T CrCtl_AccPWinNeg1_C = 110;
int16_T CrCtl_AccPWinNeg2_C = 55;
int16_T CrCtl_AccPWinNeg3_C = 60;
int16_T CrCtl_AccPWinPos1_C = 110;
int16_T CrCtl_AccPWinPos2_C = 55;
int16_T CrCtl_AccPWinPos3_C = 60;
int16_T CrCtl_DeclIKi1_C = 75;
int16_T CrCtl_DeclIKi2_C = 35;
int16_T CrCtl_DeclIKi3_C = 30;
int16_T CrCtl_DeclIKiNeg1_C = 80;
int16_T CrCtl_DeclIKiNeg2_C = 45;
int16_T CrCtl_DeclIKiNeg3_C = 30;
int16_T CrCtl_DeclIKiPos1_C = 80;
int16_T CrCtl_DeclIKiPos2_C = 45;
int16_T CrCtl_DeclIKiPos3_C = 30;
int16_T CrCtl_DeclIWinNeg1_C = 85;
int16_T CrCtl_DeclIWinNeg2_C = 55;
int16_T CrCtl_DeclIWinNeg3_C = 30;
int16_T CrCtl_DeclIWinPos1_C = 85;
int16_T CrCtl_DeclIWinPos2_C = 55;
int16_T CrCtl_DeclIWinPos3_C = 30;
int16_T CrCtl_DeclPKp1_C = 75;
int16_T CrCtl_DeclPKp2_C = 35;
int16_T CrCtl_DeclPKp3_C = 30;
int16_T CrCtl_DeclPKpNeg1_C = 80;
int16_T CrCtl_DeclPKpNeg2_C = 45;
int16_T CrCtl_DeclPKpNeg3_C = 30;
int16_T CrCtl_DeclPKpPos1_C = 80;
int16_T CrCtl_DeclPKpPos2_C = 45;
int16_T CrCtl_DeclPKpPos3_C = 30;
int16_T CrCtl_DeclPWinNeg1_C = 85;
int16_T CrCtl_DeclPWinNeg2_C = 55;
int16_T CrCtl_DeclPWinNeg3_C = 30;
int16_T CrCtl_DeclPWinPos1_C = 85;
int16_T CrCtl_DeclPWinPos2_C = 55;
int16_T CrCtl_DeclPWinPos3_C = 30;
uint8_T CrCtl_GearMin_C = 1U;
int16_T CrCtl_HoldIKi1_C = 50;
int16_T CrCtl_HoldIKi2_C = 20;
int16_T CrCtl_HoldIKi3_C = 20;
int16_T CrCtl_HoldIKiNeg1_C = 58;
int16_T CrCtl_HoldIKiNeg2_C = 25;
int16_T CrCtl_HoldIKiNeg3_C = 20;
int16_T CrCtl_HoldIKiPos1_C = 55;
int16_T CrCtl_HoldIKiPos2_C = 25;
int16_T CrCtl_HoldIKiPos3_C = 25;
int16_T CrCtl_HoldIWinNeg1_C = 58;
int16_T CrCtl_HoldIWinNeg2_C = 25;
int16_T CrCtl_HoldIWinNeg3_C = 20;
int16_T CrCtl_HoldIWinPos1_C = 60;
int16_T CrCtl_HoldIWinPos2_C = 20;
int16_T CrCtl_HoldIWinPos3_C = 20;
int16_T CrCtl_HoldPKp1_C = 50;
int16_T CrCtl_HoldPKp2_C = 20;
int16_T CrCtl_HoldPKp3_C = 25;
int16_T CrCtl_HoldPKpNeg1_C = 75;
int16_T CrCtl_HoldPKpNeg2_C = 20;
int16_T CrCtl_HoldPKpNeg3_C = 25;
int16_T CrCtl_HoldPKpPos1_C = 70;
int16_T CrCtl_HoldPKpPos2_C = 25;
int16_T CrCtl_HoldPKpPos3_C = 25;
int16_T CrCtl_HoldPWinNeg1_C = 110;
int16_T CrCtl_HoldPWinNeg2_C = 25;
int16_T CrCtl_HoldPWinNeg3_C = 25;
int16_T CrCtl_HoldPWinPos1_C = 100;
int16_T CrCtl_HoldPWinPos2_C = 20;
int16_T CrCtl_HoldPWinPos3_C = 20;
int16_T CrCtl_ResHoldIKi1_C = 85;
int16_T CrCtl_ResHoldIKi2_C = 35;
int16_T CrCtl_ResHoldIKi3_C = 30;
int16_T CrCtl_ResHoldIKiNeg1_C = 90;
int16_T CrCtl_ResHoldIKiNeg2_C = 45;
int16_T CrCtl_ResHoldIKiNeg3_C = 25;
int16_T CrCtl_ResHoldIKiPos1_C = 90;
int16_T CrCtl_ResHoldIKiPos2_C = 45;
int16_T CrCtl_ResHoldIKiPos3_C = 25;
int16_T CrCtl_ResHoldIWinNeg1_C = 100;
int16_T CrCtl_ResHoldIWinNeg2_C = 55;
int16_T CrCtl_ResHoldIWinNeg3_C = 35;
int16_T CrCtl_ResHoldIWinPos1_C = 100;
int16_T CrCtl_ResHoldIWinPos2_C = 55;
int16_T CrCtl_ResHoldIWinPos3_C = 35;
int16_T CrCtl_ResHoldPKp1_C = 85;
int16_T CrCtl_ResHoldPKp2_C = 35;
int16_T CrCtl_ResHoldPKp3_C = 30;
int16_T CrCtl_ResHoldPKpNeg1_C = 90;
int16_T CrCtl_ResHoldPKpNeg2_C = 45;
int16_T CrCtl_ResHoldPKpNeg3_C = 25;
int16_T CrCtl_ResHoldPKpPos1_C = 90;
int16_T CrCtl_ResHoldPKpPos2_C = 45;
int16_T CrCtl_ResHoldPKpPos3_C = 25;
int16_T CrCtl_ResHoldPWinNeg1_C = 100;
int16_T CrCtl_ResHoldPWinNeg2_C = 55;
int16_T CrCtl_ResHoldPWinNeg3_C = 35;
int16_T CrCtl_ResHoldPWinPos1_C = 100;
int16_T CrCtl_ResHoldPWinPos2_C = 55;
int16_T CrCtl_ResHoldPWinPos3_C = 35;
int16_T CrCtl_ResIKi1_C = 50;
int16_T CrCtl_ResIKi2_C = 50;
int16_T CrCtl_ResIKi3_C = 50;
int16_T CrCtl_ResIKiNeg1_C = 50;
int16_T CrCtl_ResIKiNeg2_C = 50;
int16_T CrCtl_ResIKiNeg3_C = 50;
int16_T CrCtl_ResIKiPos1_C = 50;
int16_T CrCtl_ResIKiPos2_C = 50;
int16_T CrCtl_ResIKiPos3_C = 50;
int16_T CrCtl_ResIWinNeg1_C = 50;
int16_T CrCtl_ResIWinNeg2_C = 50;
int16_T CrCtl_ResIWinNeg3_C = 50;
int16_T CrCtl_ResIWinPos1_C = 50;
int16_T CrCtl_ResIWinPos2_C = 50;
int16_T CrCtl_ResIWinPos3_C = 50;
int16_T CrCtl_ResPKp1_C = 50;
int16_T CrCtl_ResPKp2_C = 50;
int16_T CrCtl_ResPKp3_C = 50;
int16_T CrCtl_ResPKpNeg1_C = 50;
int16_T CrCtl_ResPKpNeg2_C = 50;
int16_T CrCtl_ResPKpNeg3_C = 50;
int16_T CrCtl_ResPKpPos1_C = 50;
int16_T CrCtl_ResPKpPos2_C = 50;
int16_T CrCtl_ResPKpPos3_C = 50;
int16_T CrCtl_ResPWinNeg1_C = 50;
int16_T CrCtl_ResPWinNeg2_C = 50;
int16_T CrCtl_ResPWinNeg3_C = 50;
int16_T CrCtl_ResPWinPos1_C = 50;
int16_T CrCtl_ResPWinPos2_C = 50;
int16_T CrCtl_ResPWinPos3_C = 50;
int16_T CrCtl_aAccShOff_C_10mmps2 = 278;
int8_T CrCtl_aAccThres_C_10mmps2 = 100;
int16_T CrCtl_aDeclShOff_C_10mmps2 = -1200;
int8_T CrCtl_aDeclThres_C_10mmps2 = -83;
int8_T CrCtl_facRmpSlpAcc_C_100mphps = 100;
int8_T CrCtl_facRmpSlpDecl_C_100mph = 100;
int8_T CrCtl_facRmpSlpHiAcc_C_Nmps = 50;
int8_T CrCtl_facRmpSlpHiDecl_C = 50;
uint8_T CrCtl_facRmpSlpRes_C_100mphps = 100U;
int8_T CrCtl_facSlpRmp1Sus_C = 1;
uint8_T CrCtl_facSlpRmp2Sus_C = 1U;
int16_T CrCtl_facSlpRmpTwoDwn_C = -30;
uint8_T CrCtl_facSlpRmpTwoUp_C = 1U;
int8_T CrCtl_facTrqIncrRmpOne_C = 5;
int8_T CrCtl_facTrqIncrRmpTwo_C = 5;
int8_T CrCtl_facTrqRedRmpOne_C = 5;
int8_T CrCtl_facTrqRedRmpTwo_C = 5;
int8_T CrCtl_facTrqStrtAcc_C_100mNmpkmph = 5;
uint8_T CrCtl_gear = 12U;
int32_T CrCtl_nMaxShOff_C_10mrpm = 300000;
int32_T CrCtl_nMinShOff_C_10mrpm = 50000;
uint8_T CrCtl_rVnDvtAbsShOff_C_mmphprpm = 44U;
uint8_T CrCtl_stParSelThres1_C = 2U;
uint8_T CrCtl_stParSelThres2_C = 2U;
boolean_T CrCtl_swtSusRmpInit_C = 0;   /* Switch over of starting torque initialisation for the torque ramp upon ending suspend<value> */
boolean_T CrCtl_swtSusRmpStp_C = 0;    /* Switch over of suspend behaviour: ramp or single step<value> */
int8_T CrCtl_tiAccShOff_C_ms = 60;
int8_T CrCtl_tiDeclShOff_C_ms = 60;
uint8_T CrCtl_tiDvtShOff_C_ms = 60U;
uint8_T CrCtl_tiEnaAftShOff_C = 3U;
uint8_T CrCtl_tiOverrideShOff_C = 1U;
uint8_T CrCtl_tiShDwnRmpOne_C = 50U;
int16_T CrCtl_trqCorAcc_C_Nmp10mmps2 = 2000;
int16_T CrCtl_trqCorDecl_C_mNmp10mmps2 = 2000;
uint8_T CrCtl_trqOfsResAbv_C = 50U;
uint8_T CrCtl_trqOfsResBlw_C = 1U;
int16_T CrCtl_trqStrtAccOfs_C_10mNm = 1000;
int16_T CrCtl_vDvtMaxAccDecl_C_10mph = 200;
int16_T CrCtl_vDvtShOff_C_10mph = 200;
int16_T CrCtl_vEnaAftShoff_C_10mph = 1000;
int8_T CrCtl_vMaxDvtAcc_C_10mph = 100;
int16_T CrCtl_vMaxDvtDecl_C_10mph = 200;
uint8_T CrCtl_vMaxDvtResAbv_C = 1U;
uint8_T CrCtl_vMaxDvtResBlw_C_10mph = 100U;
int16_T CrCtl_vMaxShOff_C_10mph = 20000;
int16_T CrCtl_vMax_C_10mph = 10000;
int16_T CrCtl_vMinShOff_C_10mph = 500;
int16_T CrCtl_vMin_C_10mph = 1000;
int16_T CrCtl_vPIGovDvt_C1_10mphSW = 500;
int16_T CrCtl_vPIGovDvt_C2_10mphSW = 200;
int16_T CrCtl_vPIGovDvt_C3_10mphSW = -200;
int16_T CrCtl_vPIGovDvt_C4_10mphSW = -500;
int16_T CrCtl_vTipDwnLoLim_C_10mph = 2000;
int16_T CrCtl_vTipDwnUpLim_C_10mph = 2000;
int8_T CrCtl_vTipStp_C_10mph = 100;
int16_T CrCtl_vTipUpLoLim_C_10mph = 2000;
int16_T CrCtl_vTipUpUpLim_C_10mph = 2000;
uint8_T stcMovSwt = 1U;

/* Forward declaration for local functions */
static void CrCtl_enter_internal_MFLv_Detection(const boolean_T *setDownBf,
  const boolean_T *setUpBf);
static void CrCtl_enter_internal_Key_Press(void);
uint16_T look1_iu16lu32n16_binlcse(uint16_T u0, const uint16_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0UL;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1UL;
    }

    frac = ((uint32_T)(u0 - bp0[iLeft]) << 16) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = 65536UL;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1UL] >= table[iLeft]) {
    y = (uint16_T)(((table[iLeft + 1UL] - table[iLeft]) * frac) >> 16) +
      table[iLeft];
  } else {
    y = table[iLeft] - (uint16_T)(((table[iLeft] - table[iLeft + 1UL]) * frac) >>
      16);
  }

  return y;
}

uint16_T look1_iu8lu32n16tu16_binlcse(uint8_T u0, const uint8_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0UL;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1UL;
    }

    frac = ((uint32_T)(uint8_T)((uint16_T)u0 - bp0[iLeft]) << 16) / (uint8_T)
      ((uint16_T)bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = 65536UL;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1UL] >= table[iLeft]) {
    y = (uint16_T)(((table[iLeft + 1UL] - table[iLeft]) * frac) >> 16) +
      table[iLeft];
  } else {
    y = table[iLeft] - (uint16_T)(((table[iLeft] - table[iLeft + 1UL]) * frac) >>
      16);
  }

  return y;
}

int16_T look1_iu16lu16n16ts16Ds32_binlcas(uint16_T u0, const uint16_T bp0[],
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;
  uint16_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (uint16_T)(((uint32_T)(u0 - bp0[iLeft]) << 16) / (bp0[iLeft + 1UL] -
      bp0[iLeft]));
  } else {
    iLeft = maxIndex;
    frac = 0U;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (int16_T)((((int32_T)table[iLeft + 1UL] - table[iLeft]) * frac) >> 16) +
      table[iLeft];
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) > 0;
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  int16_T y;
  uint32_T su1;
  uint32_T su2;
  int16_T i;
  su1 = u1[n - 1] & 2147483648UL;
  su2 = u2[n - 1] & 2147483648UL;
  if ((su1 ^ su2) != 0UL) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = su1 > su2 ? 1 : -1;
      }
    }
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void MultiWordUnsignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2,
  uint32_T y[])
{
  int16_T n1m1;
  int16_T i;
  n1m1 = n1 - 1;
  for (i = 0; i < n1m1; i++) {
    y[i] = u1[i];
  }

  y[n1m1] = ((1UL << (32U - n2)) - 1UL) & u1[n1m1];
}

void uMultiWordDivZero(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y1[], int16_T m1, uint32_T y2[], int16_T m2, uint32_T t1[],
  int16_T l1, uint32_T t2[], int16_T l2)
{
  uMultiWord2MultiWord(u1, n1, t1, l1);
  uMultiWord2MultiWord(u2, n2, t2, l2);
  if (uMultiWordDiv(t1, l1, t2, l2, y1, m1, y2, m2) < 0) {
    MultiWordSetUnsignedMax(y1, m1);
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T
  n)
{
  int16_T nm;
  int16_T i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0UL;
    }
  }
}

void MultiWordSetUnsignedMax(uint32_T y[], int16_T n)
{
  int16_T i;
  for (i = 0; i < n; i++) {
    y[i] = MAX_uint32_T;
  }
}

int16_T uMultiWordDiv(uint32_T a[], int16_T na, uint32_T b[], int16_T nb,
                      uint32_T q[], int16_T nq, uint32_T r[], int16_T nr)
{
  int16_T y;
  int16_T nza;
  int16_T nzb;
  int16_T na1;
  int16_T nb1;
  uint16_T kba;
  uint16_T kbb;
  uint16_T nba;
  uint16_T nbb;
  uint16_T kbs;
  uint16_T nbq;
  uint16_T tnb;
  int16_T tpi;
  uint32_T t;
  uint32_T mask;
  uint32_T ak;
  uint32_T bk;
  uint32_T bb;
  int16_T ka;
  int16_T kr;
  nzb = nb;
  tpi = nb - 1;
  while ((nzb > 0) && (b[tpi] == 0UL)) {
    nzb--;
    tpi--;
  }

  if (nzb > 0) {
    nza = na;
    for (tpi = 0; tpi < nq; tpi++) {
      q[tpi] = 0UL;
    }

    tpi = na - 1;
    while ((nza > 0) && (a[tpi] == 0UL)) {
      nza--;
      tpi--;
    }

    if ((nza > 0) && (nza >= nzb)) {
      nb1 = nzb - 1;
      na1 = nza - 1;
      for (kr = 0; kr < nr; kr++) {
        r[kr] = 0UL;
      }

      /* Quick return if dividend and divisor fit into single word. */
      if (nza == 1) {
        ak = a[0];
        bk = b[0];
        t = ak / bk;
        q[0] = t;
        r[0] = ak - t * bk;
        y = 7;
      } else {
        /* Remove leading zeros from both, dividend and divisor. */
        kbb = 1U;
        t = b[nb1] >> 1U;
        while (t != 0UL) {
          kbb++;
          t >>= 1U;
        }

        kba = 1U;
        t = a[na1] >> 1U;
        while (t != 0UL) {
          kba++;
          t >>= 1U;
        }

        /* Quick return if quotient is zero. */
        if ((nza > nzb) || (kba >= kbb)) {
          nba = ((uint16_T)na1 << 5) + kba;
          nbb = ((uint16_T)nb1 << 5) + kbb;

          /* Normalize b. */
          if (kbb != 32U) {
            bk = b[nb1];
            kbs = 32U - kbb;
            for (tpi = nb1; tpi > 0; tpi--) {
              t = bk << kbs;
              bk = b[tpi - 1];
              t |= bk >> kbb;
              b[tpi] = t;
            }

            b[tpi] = bk << kbs;
            mask = ~((1UL << kbs) - 1UL);
          } else {
            mask = MAX_uint32_T;
          }

          /* Initialize quotient to zero. */
          tnb = 0U;
          y = 0;

          /* Until exit conditions have been met, do */
          do {
            /* Normalize a */
            if (kba != 32U) {
              kbs = 32U - kba;
              tnb += kbs;
              ak = a[na1];
              for (ka = na1; ka > 0; ka--) {
                t = ak << kbs;
                ak = a[ka - 1];
                t |= ak >> kba;
                a[ka] = t;
              }

              a[ka] = ak << kbs;
            }

            /* Compare b against the a. */
            ak = a[na1];
            bk = b[nb1];
            if (((nb1 == 0 ? mask : MAX_uint32_T) & ak) == bk) {
              kr = 0;
              ka = na1;
              tpi = nb1;
              while ((kr == 0) && (tpi > 0)) {
                ka--;
                ak = a[ka];
                tpi--;
                bk = b[tpi];
                if (((tpi == 0 ? mask : MAX_uint32_T) & ak) != bk) {
                  kr = ak > bk ? 1 : -1;
                }
              }
            } else {
              kr = ak > bk ? 1 : -1;
            }

            /* If the remainder in a is still greater or equal to b, subtract normalized divisor from a. */
            if ((kr >= 0) || (nba > nbb)) {
              nbq = nba - nbb;

              /* If the remainder and the divisor are equal, set remainder to zero. */
              if (kr == 0) {
                ka = na1;
                for (tpi = nb1; tpi > 0; tpi--) {
                  a[ka] = 0UL;
                  ka--;
                }

                a[ka] -= b[tpi];
              } else {
                /* Otherwise, subtract the divisor from the remainder */
                if (kr < 0) {
                  ak = a[na1];
                  kba = 31U;
                  for (ka = na1; ka > 0; ka--) {
                    t = ak << 1U;
                    ak = a[ka - 1];
                    t |= ak >> 31U;
                    a[ka] = t;
                  }

                  a[ka] = ak << 1U;
                  tnb++;
                  nbq--;
                }

                bb = 0UL;
                ka = na1 - nb1;
                for (tpi = 0; tpi < nzb; tpi++) {
                  bk = b[tpi];
                  t = a[ka];
                  ak = (t - bk) - bb;
                  bb = bb != 0UL ? (uint32_T)(ak >= t) : (uint32_T)(ak > t);
                  a[ka] = ak;
                  ka++;
                }
              }

              /* Update the quotient. */
              tpi = (int16_T)(nbq >> 5);
              q[tpi] |= 1UL << (nbq - ((uint16_T)tpi << 5));

              /* Remove leading zeros from the remainder and check whether the exit conditions have been met. */
              tpi = na1;
              while ((nza > 0) && (a[tpi] == 0UL)) {
                nza--;
                tpi--;
              }

              if (nza >= nzb) {
                na1 = nza - 1;
                kba = 1U;
                t = a[na1] >> 1U;
                while (t != 0UL) {
                  kba++;
                  t >>= 1U;
                }

                nba = (((uint16_T)na1 << 5) + kba) - tnb;
                if (nba < nbb) {
                  y = 2;
                }
              } else if (nza == 0) {
                y = 1;
              } else {
                na1 = nza - 1;
                y = 4;
              }
            } else {
              y = 3;
            }
          } while (y == 0);

          /* Return the remainder. */
          if (y == 1) {
            r[0] = a[0];
          } else {
            tpi = (int16_T)(tnb >> 5);
            nbq = tnb - ((uint16_T)tpi << 5);
            if (nbq == 0U) {
              ka = tpi;
              for (kr = 0; kr <= nb1; kr++) {
                r[kr] = a[ka];
                ka++;
              }
            } else {
              kbs = 32U - nbq;
              ak = a[tpi];
              kr = 0;
              for (ka = tpi + 1; ka <= na1; ka++) {
                t = ak >> nbq;
                ak = a[ka];
                t |= ak << kbs;
                r[kr] = t;
                kr++;
              }

              r[kr] = ak >> nbq;
            }
          }

          /* Restore b. */
          if (kbb != 32U) {
            bk = b[0];
            kbs = 32U - kbb;
            for (tpi = 0; tpi < nb1; tpi++) {
              t = bk >> kbs;
              bk = b[tpi + 1];
              t |= bk << kbb;
              b[tpi] = t;
            }

            b[tpi] = bk >> kbs;
          }
        } else {
          for (kr = 0; kr < nr; kr++) {
            r[kr] = a[kr];
          }

          y = 6;
        }
      }
    } else {
      for (kr = 0; kr < nr; kr++) {
        r[kr] = a[kr];
      }

      y = 5;
    }
  } else {
    y = -1;
  }

  return y;
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n)
{
  int16_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0UL;
  }
}

uint32_T MultiWord2uLong(const uint32_T u[])
{
  return u[0];
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0L) != (denominator < 0L)) && (numerator % denominator
           != 0L) ? -1L : 0L) + numerator / denominator;
}

int16_T div_nde_s16_floor(int16_T numerator, int16_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0L) {
    quotient = numerator >= 0L ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0L ? ~(uint32_T)numerator + 1UL : (uint32_T)
      numerator;
    absDenominator = denominator < 0L ? ~(uint32_T)denominator + 1UL : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0L) != (denominator < 0L));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0UL) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

int8_T div_s8s32_floor(int32_T numerator, int32_T denominator)
{
  int8_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0L) {
    quotient = (int8_T)(numerator >= 0L ? 127 : -128);

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0L ? ~(uint32_T)numerator + 1UL : (uint32_T)
      numerator;
    absDenominator = denominator < 0L ? ~(uint32_T)denominator + 1UL : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0L) != (denominator < 0L));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0UL) {
        tempAbsQuotient++;
      }
    }

    quotient = (int8_T)(quotientNeedsNegation ? (int16_T)(int8_T)-(int32_T)
                        tempAbsQuotient : (int16_T)(int8_T)tempAbsQuotient);
  }

  return quotient;
}

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0L ? ~(uint32_T)in0 + 1UL : (uint32_T)in0;
  absIn1 = in1 < 0L ? ~(uint32_T)in1 + 1UL : (uint32_T)in1;
  in0Hi = absIn0 >> 16UL;
  in0Lo = absIn0 & 65535UL;
  in1Hi = absIn1 >> 16UL;
  absIn0 = absIn1 & 65535UL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0UL;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16UL) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1UL;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16UL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0L) || ((in1 == 0L) || ((in0 > 0L) == (in1 > 0L))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> aShift;
}

int16_T div_s16u32(uint32_T numerator, uint32_T denominator)
{
  int16_T quotient;
  if (denominator == 0UL) {
    quotient = MAX_int16_T;

    /* Divide by zero handler */
  } else {
    quotient = (int16_T)(numerator / denominator);
  }

  return quotient;
}

/*
 * Output and update for action system:
 *    '<S17>/Switch Case Action Subsystem'
 *    '<S49>/Switch Case Action Subsystem'
 *    '<S50>/Switch Case Action Subsystem'
 *    '<S78>/Switch Case Action Subsystem'
 *    '<S84>/Switch Case Action Subsystem'
 */
void CrCtl_SwitchCaseActionSubsystem(boolean_T rtu_signalIn, boolean_T
  *rty_signalOut, uint8_T *rtd_numPeriod_o, boolean_T *rtd_timeLck_n)
{
  /* DataStoreWrite: '<S23>/Data Store Write' incorporates:
   *  Constant: '<S23>/Constant'
   */
  *rtd_timeLck_n = true;

  /* DataStoreWrite: '<S23>/Data Store Write1' incorporates:
   *  Constant: '<S23>/Constant1'
   */
  *rtd_numPeriod_o = 0U;

  /* Inport: '<S23>/signalIn' */
  *rty_signalOut = rtu_signalIn;
}

/* System initialize for atomic system: '<S2>/CrCtl_Mode_CdtnsFwd' */
void CrCtl_CrCtl_Mode_CdtnsFwd_Init(void)
{
  /* InitializeConditions for Memory: '<S11>/Memory' */
  CrCtl_DW.Memory_PreviousInput_n = true;
}

/* Outputs for atomic system: '<S2>/CrCtl_Mode_CdtnsFwd' */
void CrCtl_CrCtl_Mode_CdtnsFwd(void)
{
  boolean_T rtb_RelationalOperator3;
  boolean_T Merge_p;
  uint8_T tmp;

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Constant: '<S11>/CRCTL_NOSHOFFCONACTV_0h'
   *  Constant: '<S11>/MFLV_NEUTR_0h'
   *  Memory: '<S11>/Memory'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  RelationalOperator: '<S11>/Relational Operator1'
   */
  CrCtl_B.LogicalOperator_o = (CrCtl_DW.Memory_PreviousInput_n &&
    (CrCtl_B.CrCtl_stShOffFdbck == ((uint8_T)CRCTL_NOSHOFFCONACTV)) &&
    (CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)MFLV_NEUTR)));

  /* If: '<S17>/If' incorporates:
   *  DataStoreRead: '<S24>/Data Store Read4'
   *  If: '<S24>/If'
   *  Memory: '<S17>/Memory'
   */
  if (CrCtl_B.LogicalOperator_o && (!CrCtl_DW.Memory_PreviousInput_m3)) {
    /* Outputs for IfAction SubSystem: '<S17>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem(CrCtl_B.LogicalOperator_o, &Merge_p,
      &CrCtl_DW.numPeriod_o, &CrCtl_DW.timeLck_n);

    /* End of Outputs for SubSystem: '<S17>/Switch Case Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    if (CrCtl_DW.timeLck_n) {
      /* Gain: '<S11>/Gain' */
      if (((uint8_T)T_ms) > 15) {
        tmp = MAX_uint8_T;
      } else {
        tmp = (uint8_T)(((uint8_T)T_ms) << 4);
      }

      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* If: '<S24>/If' incorporates:
       *  Constant: '<S11>/CrCtl_tiEnaAftShOff_C'
       *  Constant: '<S25>/Constant1'
       *  Constant: '<S25>/Constant2'
       *  Constant: '<S25>/Constant4'
       *  Constant: '<S25>/Constant5'
       *  Constant: '<S25>/T_ms'
       *  DataStoreRead: '<S25>/Data Store Read1'
       *  DataStoreRead: '<S25>/Data Store Read2'
       *  DataStoreWrite: '<S25>/Data Store Write'
       *  DataStoreWrite: '<S25>/Data Store Write1'
       *  Gain: '<S11>/Gain'
       *  MultiPortSwitch: '<S25>/Index Vector2'
       *  Product: '<S25>/Product'
       *  RelationalOperator: '<S25>/Relational Operator'
       *  Sum: '<S25>/Add'
       */
      if (!((int32_T)((uint32_T)((uint16_T)CrCtl_DW.numPeriod_o * ((uint8_T)T_ms))
                      << 4) < (uint16_T)tmp * CrCtl_tiEnaAftShOff_C)) {
        CrCtl_DW.timeLck_n = false;
        CrCtl_DW.numPeriod_o = 0U;
        Merge_p = CrCtl_B.LogicalOperator_o;
      } else {
        CrCtl_DW.numPeriod_o++;
        Merge_p = true;
      }

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* If: '<S24>/If' incorporates:
       *  Inport: '<S26>/signalIn'
       */
      Merge_p = CrCtl_B.LogicalOperator_o;

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
    }

    /* End of Outputs for SubSystem: '<S17>/Switch Case Action Subsystem1' */
  }

  /* End of If: '<S17>/If' */

  /* Logic: '<S11>/Logical Operator1' incorporates:
   *  Constant: '<S11>/CrCtl_vEnaAftShoff_C_10mph'
   *  RelationalOperator: '<S11>/Relational Operator2'
   */
  Merge_p = (Merge_p && ((int32_T)VSSCD_v_10mphUW > CrCtl_vEnaAftShoff_C_10mph));

  /* RelationalOperator: '<S11>/Relational Operator3' incorporates:
   *  Constant: '<S11>/CRCTL_NOSHOFFCONACTV_0h'
   */
  rtb_RelationalOperator3 = (CrCtl_B.CrCtl_stShOffFdbck != ((uint8_T)
    CRCTL_NOSHOFFCONACTV));

  /* Outputs for Enabled SubSystem: '<S19>/RESET Priority' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (CrCtl_ConstB.LogicalOperator2_e) {
    if (!CrCtl_DW.RESETPriority_MODE_g) {
      CrCtl_DW.RESETPriority_MODE_g = true;
    }
  } else {
    if (CrCtl_DW.RESETPriority_MODE_g) {
      CrCtl_DW.RESETPriority_MODE_g = false;
    }
  }

  if (CrCtl_DW.RESETPriority_MODE_g) {
    /* Logic: '<S20>/Logical Operator2' incorporates:
     *  Logic: '<S20>/Logical Operator'
     *  Logic: '<S20>/Logical Operator1'
     *  UnitDelay: '<S20>/IC = ic'
     */
    CrCtl_B.LogicalOperator2_p = ((Merge_p || CrCtl_DW.ICic_DSTATE_b) &&
      (!rtb_RelationalOperator3));

    /* Logic: '<S20>/Logical Operator3' */
    CrCtl_B.LogicalOperator3_i = !CrCtl_B.LogicalOperator2_p;
  }

  /* End of Outputs for SubSystem: '<S19>/RESET Priority' */

  /* Outputs for Enabled SubSystem: '<S19>/SET  Priority' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (CrCtl_ConstB.RelationalOperator1_h) {
    if (!CrCtl_DW.SETPriority_MODE_p) {
      CrCtl_DW.SETPriority_MODE_p = true;
    }
  } else {
    if (CrCtl_DW.SETPriority_MODE_p) {
      CrCtl_DW.SETPriority_MODE_p = false;
    }
  }

  if (CrCtl_DW.SETPriority_MODE_p) {
    /* Logic: '<S21>/Logical Operator' incorporates:
     *  Logic: '<S21>/Logical Operator1'
     *  Logic: '<S21>/Logical Operator2'
     *  UnitDelay: '<S21>/IC = ic'
     */
    CrCtl_B.LogicalOperator_k = (Merge_p || ((!rtb_RelationalOperator3) &&
      CrCtl_DW.ICic_DSTATE));

    /* Logic: '<S21>/Logical Operator3' */
    CrCtl_B.LogicalOperator3_d = !CrCtl_B.LogicalOperator_k;
  }

  /* End of Outputs for SubSystem: '<S19>/SET  Priority' */

  /* MultiPortSwitch: '<S11>/Index Vector' incorporates:
   *  Constant: '<S11>/CRCTL_ENA_1h'
   *  Constant: '<S11>/CRCTL_NOTENA_0h'
   *  Constant: '<S11>/CRCTL_NOTLCK _0h'
   *  Constant: '<S11>/CRCTL_OFF_2h'
   *  Logic: '<S11>/Logical Operator2'
   *  Logic: '<S19>/Logical Operator1'
   *  RelationalOperator: '<S11>/Relational Operator4'
   *  RelationalOperator: '<S11>/Relational Operator5'
   */
  if (!((CrCtl_B.LogicalOperator_k || CrCtl_B.LogicalOperator2_p) &&
        (CrCtl_B.CrCtl_stModeFdbck != ((uint8_T)CRCTL_OFF)) &&
        (CrCtl_B.CrCtl_stLck_fdbck == ((uint8_T)CRCTL_NOTLCK)))) {
    CrCtl_B.signal4_e = CRCTL_NOTENA;
  } else {
    CrCtl_B.signal4_e = CRCTL_ENA;
  }

  /* End of MultiPortSwitch: '<S11>/Index Vector' */

  /* Logic: '<S19>/Logical Operator3' */
  CrCtl_B.LogicalOperator3_e = (CrCtl_B.LogicalOperator3_d ||
    CrCtl_B.LogicalOperator3_i);
}

/* Update for atomic system: '<S2>/CrCtl_Mode_CdtnsFwd' */
void CrCtl_CrCtl_Mode_CdtnsFwd_Update(void)
{
  /* Update for Memory: '<S11>/Memory' */
  CrCtl_DW.Memory_PreviousInput_n = CrCtl_B.LogicalOperator3_e;

  /* Update for Memory: '<S17>/Memory' */
  CrCtl_DW.Memory_PreviousInput_m3 = CrCtl_B.LogicalOperator_o;

  /* Update for Enabled SubSystem: '<S19>/RESET Priority' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (CrCtl_DW.RESETPriority_MODE_g) {
    /* Update for UnitDelay: '<S20>/IC = ic' */
    CrCtl_DW.ICic_DSTATE_b = CrCtl_B.LogicalOperator2_p;
  }

  /* End of Update for SubSystem: '<S19>/RESET Priority' */

  /* Update for Enabled SubSystem: '<S19>/SET  Priority' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (CrCtl_DW.SETPriority_MODE_p) {
    /* Update for UnitDelay: '<S21>/IC = ic' */
    CrCtl_DW.ICic_DSTATE = CrCtl_B.LogicalOperator_k;
  }

  /* End of Update for SubSystem: '<S19>/SET  Priority' */
}

/* Output and update for atomic system: '<S2>/CrCtl_Mode_MFLvRqstMnplt' */
void CrCtl_CrCtl_Mode_MFLvRqstMnplt(void)
{
  /* MultiPortSwitch: '<S12>/Index Vector2' incorporates:
   *  Constant: '<S12>/MFLV_ACC_6h'
   *  Constant: '<S12>/MFLV_DECL_4h'
   *  Constant: '<S12>/MFLV_TIPDWN_3h'
   *  Constant: '<S12>/MFLV_TIPUP_5h'
   *  Logic: '<S12>/Logical Operator'
   *  MultiPortSwitch: '<S12>/Index Vector3'
   *  RelationalOperator: '<S12>/Relational Operator4'
   *  RelationalOperator: '<S12>/Relational Operator5'
   *  RelationalOperator: '<S12>/Relational Operator6'
   *  RelationalOperator: '<S12>/Relational Operator7'
   */
  if (!CrCtl_ConstB.RelationalOperator3) {
    CrCtl_B.IndexVector5 = CrCtl_B.MFLv_stCrCtlMode_f;
  } else if (!((CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)MFLV_DECL)) ||
               (CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)MFLV_ACC)) ||
               (CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)MFLV_TIPUP)) ||
               (CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)MFLV_TIPDWN)))) {
    /* MultiPortSwitch: '<S12>/Index Vector3' */
    CrCtl_B.IndexVector5 = CrCtl_B.MFLv_stCrCtlMode_f;
  } else {
    /* MultiPortSwitch: '<S12>/Index Vector3' incorporates:
     *  Constant: '<S12>/MFLV_NEUTR_0h'
     */
    CrCtl_B.IndexVector5 = ((uint8_T)MFLV_NEUTR);
  }

  /* End of MultiPortSwitch: '<S12>/Index Vector2' */

  /* MultiPortSwitch: '<S12>/Index Vector5' incorporates:
   *  RelationalOperator: '<S12>/Relational Operator2'
   */
  if (CrCtl_B.LogicalOperator_f) {
    /* MultiPortSwitch: '<S12>/Index Vector4' incorporates:
     *  Constant: '<S12>/MFLV_NEUTR_0h'
     *  Constant: '<S12>/MFLV_OFF'
     *  Constant: '<S12>/MFLV_SWTOFF'
     *  RelationalOperator: '<S12>/Relational Operator8'
     */
    if (!(CrCtl_B.IndexVector5 == ((uint8_T)MFLV_OFF))) {
      CrCtl_B.IndexVector5 = ((uint8_T)MFLV_NEUTR);
    } else {
      CrCtl_B.IndexVector5 = ((uint8_T)MFLV_SWTOFF);
    }

    /* End of MultiPortSwitch: '<S12>/Index Vector4' */
  }

  /* End of MultiPortSwitch: '<S12>/Index Vector5' */
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvNeutr' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvNeutr(void)
{
  /* MultiPortSwitch: '<S29>/Index Vector' incorporates:
   *  Constant: '<S29>/CRCTL_ACC_8h'
   *  Constant: '<S29>/CRCTL_DECL_4h'
   *  Constant: '<S29>/CRCTL_ENA_1h'
   *  Constant: '<S29>/CRCTL_SUBRMPEND_4h'
   *  Constant: '<S29>/CRCTL_SUBRMP_3h'
   *  Constant: '<S29>/MFLV_NEUTR_0h'
   *  Inport: '<S29>/CrCtl_stModeIn'
   *  Logic: '<S29>/Logical Operator'
   *  Logic: '<S29>/Logical Operator1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   *  RelationalOperator: '<S29>/Relational Operator2'
   *  RelationalOperator: '<S29>/Relational Operator3'
   *  RelationalOperator: '<S29>/Relational Operator4'
   */
  if (!(((CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_DECL)) ||
         (CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_ACC))) &&
        (CrCtl_B.CrCtl_stModeSubFdbck == ((uint8_T)CRCTL_SUBRMP)) &&
        (CrCtl_B.IndexVector_k == ((uint8_T)MFLV_NEUTR)) && (CrCtl_B.signal4_e ==
        CRCTL_ENA))) {
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBRMPEND);
  }

  /* End of MultiPortSwitch: '<S29>/Index Vector' */

  /* SignalConversion: '<S29>/OutportBufferForCrCtl_stMode' incorporates:
   *  Inport: '<S29>/CrCtl_stModeIn'
   */
  CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvSet' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvSet(void)
{
  /* MultiPortSwitch: '<S32>/Index Vector' incorporates:
   *  Constant: '<S32>/CRCTL_DECL(=4h)'
   *  Constant: '<S32>/CRCTL_ENA(=1h)'
   *  Constant: '<S32>/MFLV_SET(=2h)'
   *  Constant: '<S32>/MFLV_SET_8h'
   *  Logic: '<S32>/Logical Operator'
   *  Logic: '<S32>/Logical Operator1'
   *  Logic: '<S32>/Logical Operator2'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator1'
   *  RelationalOperator: '<S32>/Relational Operator2'
   */
  if (!((!CrCtl_B.CrCtl_stActiveFdbck) && ((CrCtl_B.IndexVector_k == ((uint8_T)
          MFLV_SET)) || (CrCtl_B.IndexVector_k == ((uint8_T)MFLV_SETOPT))) &&
        (CrCtl_B.signal4_e == CRCTL_ENA))) {
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;

    /* MultiPortSwitch: '<S32>/Index Vector1' */
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge = ((uint8_T)CRCTL_DECL);

    /* MultiPortSwitch: '<S32>/Index Vector1' incorporates:
     *  Constant: '<S32>/CRCTL_DECL(=4h)'
     *  Constant: '<S32>/CRCTL_SUBSETEND(=7h)'
     */
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBSETEND);
  }

  /* End of MultiPortSwitch: '<S32>/Index Vector' */

  /* MultiPortSwitch: '<S32>/Index Vector2' */
  CrCtl_B.Merge2 = CrCtl_B.rVn_mmphprpm;
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvTipDwn' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvTipDwn(void)
{
  /* MultiPortSwitch: '<S33>/Index Vector' incorporates:
   *  Constant: '<S33>/CRCTL_ENA(=1h)'
   *  Constant: '<S33>/CRCTL_TIPDWN(=3h)'
   *  Constant: '<S33>/MFLV_TIPDWN(=3h)'
   *  Logic: '<S33>/Logical Operator1'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  RelationalOperator: '<S33>/Relational Operator1'
   *  RelationalOperator: '<S33>/Relational Operator2'
   */
  if (!(CrCtl_B.CrCtl_stActiveFdbck && (CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph >
        0U) && (CrCtl_B.IndexVector_k == ((uint8_T)MFLV_TIPDWN)) &&
        (CrCtl_B.signal4_e == CRCTL_ENA))) {
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;

    /* MultiPortSwitch: '<S33>/Index Vector1' */
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge = ((uint8_T)CRCTL_TIPDWN);

    /* MultiPortSwitch: '<S33>/Index Vector1' incorporates:
     *  Constant: '<S33>/CRCTL_SUBCALCSET(=6h)'
     *  Constant: '<S33>/CRCTL_TIPDWN(=3h)'
     */
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBCALCSET);
  }

  /* End of MultiPortSwitch: '<S33>/Index Vector' */
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvDecl' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvDecl(void)
{
  boolean_T rtb_LogicalOperator_h;

  /* Logic: '<S28>/Logical Operator' incorporates:
   *  Constant: '<S28>/CRCTL_ENA(=1h)'
   *  Constant: '<S28>/MFLV_DECL(=4h)'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  RelationalOperator: '<S28>/Relational Operator2'
   */
  rtb_LogicalOperator_h = (CrCtl_B.CrCtl_stActiveFdbck &&
    (CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph > 0U) && (CrCtl_B.IndexVector_k ==
    ((uint8_T)MFLV_DECL)) && (CrCtl_B.signal4_e == CRCTL_ENA));

  /* MultiPortSwitch: '<S28>/Index Vector1' incorporates:
   *  Constant: '<S28>/CRCTL_DECL(=4h)'
   *  Constant: '<S28>/CRCTL_SUBSTRTVAL(=2h)'
   *  Logic: '<S28>/Logical Operator1'
   *  RelationalOperator: '<S28>/Relational Operator3'
   */
  if (!(rtb_LogicalOperator_h && (CrCtl_B.CrCtl_stModeFdbck != ((uint8_T)
         CRCTL_DECL)))) {
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S28>/Index Vector1' */

  /* MultiPortSwitch: '<S28>/Index Vector2' */
  CrCtl_B.Merge2 = CrCtl_B.rVn_mmphprpm;

  /* MultiPortSwitch: '<S28>/Index Vector4' incorporates:
   *  Constant: '<S28>/CRCTL_DECL(=4h)'
   */
  if (!rtb_LogicalOperator_h) {
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;
  } else {
    CrCtl_B.Merge = ((uint8_T)CRCTL_DECL);
  }

  /* End of MultiPortSwitch: '<S28>/Index Vector4' */
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvTipUp' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvTipUp(void)
{
  /* MultiPortSwitch: '<S34>/Index Vector1' incorporates:
   *  Constant: '<S34>/CRCTL_ENA(=1h)'
   *  Constant: '<S34>/CRCTL_SUBCALCSET(=6h)'
   *  Constant: '<S34>/MFLV_TIPUP(=5h)'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  RelationalOperator: '<S34>/Relational Operator1'
   *  RelationalOperator: '<S34>/Relational Operator2'
   */
  if (!(CrCtl_B.CrCtl_stActiveFdbck && (CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph >
        0U) && (CrCtl_B.IndexVector_k == ((uint8_T)MFLV_TIPUP)) &&
        (CrCtl_B.signal4_e == CRCTL_ENA))) {
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;

    /* MultiPortSwitch: '<S34>/Index Vector4' */
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;
  } else {
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBCALCSET);

    /* MultiPortSwitch: '<S34>/Index Vector4' incorporates:
     *  Constant: '<S34>/CRCTL_SUBCALCSET(=6h)'
     *  Constant: '<S34>/CRCTL_TIPUP(=7h)'
     */
    CrCtl_B.Merge = ((uint8_T)CRCTL_TIPUP);
  }

  /* End of MultiPortSwitch: '<S34>/Index Vector1' */
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvAcc' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvAcc(void)
{
  boolean_T rtb_LogicalOperator_jd;

  /* Logic: '<S27>/Logical Operator' incorporates:
   *  Constant: '<S27>/CRCTL_ENA(=1h)'
   *  Constant: '<S27>/MFLV_ACC(=6h)'
   *  RelationalOperator: '<S27>/Relational Operator'
   *  RelationalOperator: '<S27>/Relational Operator1'
   *  RelationalOperator: '<S27>/Relational Operator2'
   */
  rtb_LogicalOperator_jd = (CrCtl_B.CrCtl_stActiveFdbck &&
    (CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph > 0U) && (CrCtl_B.IndexVector_k ==
    ((uint8_T)MFLV_ACC)) && (CrCtl_B.signal4_e == CRCTL_ENA));

  /* MultiPortSwitch: '<S27>/Index Vector1' incorporates:
   *  Constant: '<S27>/CRCTL_ACC(=8h)'
   *  Constant: '<S27>/CRCTL_SUBSTRTVAL(=2h)'
   *  Logic: '<S27>/Logical Operator1'
   *  RelationalOperator: '<S27>/Relational Operator3'
   */
  if (!(rtb_LogicalOperator_jd && (CrCtl_B.CrCtl_stModeFdbck != ((uint8_T)
         CRCTL_ACC)))) {
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S27>/Index Vector1' */

  /* MultiPortSwitch: '<S27>/Index Vector2' */
  CrCtl_B.Merge2 = CrCtl_B.rVn_mmphprpm;

  /* MultiPortSwitch: '<S27>/Index Vector4' incorporates:
   *  Constant: '<S27>/CRCTL_ACC(=8h)'
   */
  if (!rtb_LogicalOperator_jd) {
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;
  } else {
    CrCtl_B.Merge = ((uint8_T)CRCTL_ACC);
  }

  /* End of MultiPortSwitch: '<S27>/Index Vector4' */
}

/* Output and update for action system: '<S13>/CrCtl_Mode_SwtMds_MFLvRes' */
void CrCtl_CrCtl_Mode_SwtMds_MFLvRes(void)
{
  /* MultiPortSwitch: '<S31>/Index Vector4' incorporates:
   *  Constant: '<S31>/CRCTL_ACC(=8h)'
   *  Constant: '<S31>/CRCTL_ENA(=1h)'
   *  Constant: '<S31>/MFLV_RES(=7h)'
   *  Logic: '<S31>/Logical Operator'
   *  Logic: '<S31>/Logical Operator1'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S31>/Relational Operator1'
   *  RelationalOperator: '<S31>/Relational Operator2'
   */
  if (!((!CrCtl_B.CrCtl_stActiveFdbck) && (CrCtl_B.IndexVector_k == ((uint8_T)
         MFLV_RES)) && (CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph > 0U) &&
        (CrCtl_B.signal4_e == CRCTL_ENA))) {
    CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;

    /* MultiPortSwitch: '<S31>/Index Vector1' */
    CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_B.Merge = ((uint8_T)CRCTL_ACC);

    /* MultiPortSwitch: '<S31>/Index Vector1' incorporates:
     *  Constant: '<S31>/CRCTL_ACC(=8h)'
     *  Constant: '<S31>/CRCTL_SUBWAITRES(=9h)'
     */
    CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBWAITRES);
  }

  /* End of MultiPortSwitch: '<S31>/Index Vector4' */
}

/* System initialize for atomic system: '<S2>/CrCtl_Mode_SwtMds' */
void CrCtl_CrCtl_Mode_SwtMds_Init(void)
{
  /* SystemInitialize for Merge: '<S13>/Merge' */
  CrCtl_B.Merge = 0U;

  /* SystemInitialize for Merge: '<S13>/Merge1' */
  CrCtl_B.Merge1 = 0U;

  /* SystemInitialize for Merge: '<S13>/Merge2' */
  CrCtl_B.Merge2 = 0;
}

/* Output and update for atomic system: '<S2>/CrCtl_Mode_SwtMds' */
void CrCtl_CrCtl_Mode_SwtMds(void)
{
  int8_T rtAction;
  boolean_T rtb_LogicalOperator_du;

  /* SwitchCase: '<S13>/Switch Case' */
  rtAction = -1;
  switch ((int32_T)CrCtl_B.IndexVector_k) {
   case 0L:
    rtAction = 0;
    break;

   case 2L:
   case 8L:
    rtAction = 1;
    break;

   case 3L:
    rtAction = 2;
    break;

   case 4L:
    rtAction = 3;
    break;

   case 5L:
    rtAction = 4;
    break;

   case 6L:
    rtAction = 5;
    break;

   case 7L:
    rtAction = 6;
    break;

   case 10L:
    rtAction = 7;
    break;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvNeutr' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvNeutr();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvNeutr' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvSet' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvSet();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvSet' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvTipDwn' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvTipDwn();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvTipDwn' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvDecl' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvDecl();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvDecl' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvTipUp' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvTipUp();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvTipUp' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvAcc' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvAcc();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvAcc' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvRes' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    CrCtl_CrCtl_Mode_SwtMds_MFLvRes();

    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvRes' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvPCC' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* MultiPortSwitch: '<S30>/Index Vector1' incorporates:
     *  Constant: '<S30>/Constant'
     *  Logic: '<S30>/Logical Operator2'
     *  RelationalOperator: '<S30>/Relational Operator'
     */
    if (!(((uint8_T)CRCTL_NEUTR) == CrCtl_B.CrCtl_stModeFdbck)) {
      rtb_LogicalOperator_du = CrCtl_B.CrCtl_stActiveFdbck;
    } else {
      rtb_LogicalOperator_du = !CrCtl_B.CrCtl_stActiveFdbck;
    }

    /* End of MultiPortSwitch: '<S30>/Index Vector1' */

    /* Logic: '<S30>/Logical Operator' incorporates:
     *  Constant: '<S30>/CRCTL_ENA_1h'
     *  RelationalOperator: '<S30>/Relational Operator2'
     */
    rtb_LogicalOperator_du = (rtb_LogicalOperator_du && (CrCtl_B.signal4_e ==
      CRCTL_ENA));

    /* MultiPortSwitch: '<S30>/Index Vector3' incorporates:
     *  Constant: '<S30>/CRCTL_PCC_10h'
     *  Constant: '<S30>/CRCTL_SUBSTRTVAL_2h'
     *  Logic: '<S30>/Logical Operator1'
     *  RelationalOperator: '<S30>/Relational Operator3'
     */
    if (!(rtb_LogicalOperator_du && (CrCtl_B.CrCtl_stModeFdbck != CRCTL_PCC))) {
      CrCtl_B.Merge1 = CrCtl_B.CrCtl_stModeSubFdbck;
    } else {
      CrCtl_B.Merge1 = ((uint8_T)CRCTL_SUBSTRTVAL);
    }

    /* End of MultiPortSwitch: '<S30>/Index Vector3' */

    /* MultiPortSwitch: '<S30>/Index Vector5' incorporates:
     *  Constant: '<S30>/CRCTL_PCC_10h'
     */
    if (!rtb_LogicalOperator_du) {
      CrCtl_B.Merge = CrCtl_B.CrCtl_stModeFdbck;
    } else {
      CrCtl_B.Merge = CRCTL_PCC;
    }

    /* End of MultiPortSwitch: '<S30>/Index Vector5' */
    /* End of Outputs for SubSystem: '<S13>/CrCtl_Mode_SwtMds_MFLvPCC' */
    break;
  }

  /* End of SwitchCase: '<S13>/Switch Case' */
}

/* System initialize for atomic system: '<Root>/CrCtl_Mode' */
void CrCtl_CrCtl_Mode_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */
  CrCtl_CrCtl_Mode_CdtnsFwd_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/CrCtl_Mode_SwtMds' */
  CrCtl_CrCtl_Mode_SwtMds_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CrCtl_Mode_SwtMds' */
}

/* Outputs for atomic system: '<Root>/CrCtl_Mode' */
void CrCtl_CrCtl_Mode(void)
{
  /* Logic: '<S14>/Logical Operator' incorporates:
   *  Constant: '<S14>/SHIFTINPROCESS_1h'
   *  Inport: '<Root>/ETC1_trsSftPrcs_UB'
   *  RelationalOperator: '<S14>/Relational Operator2'
   */
  CrCtl_B.LogicalOperator_f = (ETC1_trsSftPrcs_UB == ((uint8_T)SHIFTINPROCESS));

  /* Inport: '<S2>/MFLv_stCrCtlMode' */
  CrCtl_B.MFLv_stCrCtlMode_f = MFLv_stCrCtlMode;

  /* Outputs for Atomic SubSystem: '<S2>/CrCtl_Mode_MFLvRqstMnplt' */
  CrCtl_CrCtl_Mode_MFLvRqstMnplt();

  /* End of Outputs for SubSystem: '<S2>/CrCtl_Mode_MFLvRqstMnplt' */

  /* Outputs for Atomic SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */
  CrCtl_CrCtl_Mode_CdtnsFwd();

  /* End of Outputs for SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */

  /* MultiPortSwitch: '<S15>/Index Vector5' incorporates:
   *  Constant: '<S15>/CRCTL_PCCACT_1h'
   *  Constant: '<S15>/CRCTL_PCCINACT'
   *  Constant: '<S15>/PCC'
   *  Constant: '<S15>/enPCCBetMode'
   *  Constant: '<S15>/enPCCOptMode'
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S15>/Logical Operator2'
   *  Logic: '<S15>/Logical Operator3'
   *  Memory: '<S15>/Memory'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  RelationalOperator: '<S15>/Relational Operator4'
   *  RelationalOperator: '<S15>/Relational Operator5'
   */
  if (!((CrCtl_PCCAct_BL == CRCTL_PCCACT) && (CrCtl_DW.Memory_PreviousInput_go ==
        FALSE) && ((CrCtl_B.IndexVector_d == ((uint8_T)ENPCCBETMODE)) ||
                   (CrCtl_B.IndexVector_d == ((uint8_T)ENPCCOPTMODE))))) {
    CrCtl_B.IndexVector_k = CrCtl_B.MFLv_stCrCtlMode_f;
  } else {
    CrCtl_B.IndexVector_k = 10U;
  }

  /* End of MultiPortSwitch: '<S15>/Index Vector5' */

  /* Outputs for Atomic SubSystem: '<S2>/CrCtl_Mode_SwtMds' */
  CrCtl_CrCtl_Mode_SwtMds();

  /* End of Outputs for SubSystem: '<S2>/CrCtl_Mode_SwtMds' */
}

/* Update for atomic system: '<Root>/CrCtl_Mode' */
void CrCtl_CrCtl_Mode_Update(void)
{
  /* Update for Atomic SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */
  CrCtl_CrCtl_Mode_CdtnsFwd_Update();

  /* End of Update for SubSystem: '<S2>/CrCtl_Mode_CdtnsFwd' */

  /* Update for Memory: '<S15>/Memory' incorporates:
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   */
  CrCtl_DW.Memory_PreviousInput_go = CrCtl_PCCAct_BL;
}

/* Output and update for atomic system: '<S36>/CrCtlShOff_Cdtns_1' */
void CrCtl_CrCtlShOff_Cdtns_1(void)
{
  /* MultiPortSwitch: '<S40>/Index Vector6' incorporates:
   *  Constant: '<S3>/Fid_CrCtlAccPed_Normal'
   *  Constant: '<S3>/Fid_CrCtlBrk_Normal'
   *  Constant: '<S3>/Fid_CrCtlBstPres_Normal'
   *  Constant: '<S3>/Fid_CrCtlClth_Normal'
   *  Constant: '<S3>/Fid_CrCtlEngSpdSens_Normal'
   *  Constant: '<S3>/Fid_CrCtlRailPres_Normal'
   *  Constant: '<S3>/Fid_CrCtlVehSpdSens_Normal'
   *  Constant: '<S3>/T15CD_stDebVal1'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  Constant: '<S40>/Constant4'
   *  Constant: '<S40>/Constant5'
   *  Constant: '<S40>/Constant6'
   *  Constant: '<S40>/Constant7'
   *  Constant: '<S40>/Constant8'
   *  Constant: '<S40>/Constant9'
   *  Constant: '<S40>/MFLV_MODEERR_FFh'
   *  Constant: '<S40>/MFLV_SWTOFF_1h'
   *  Constant: '<S40>/T15CD_ST_OFF(=0)'
   *  Constant: '<S40>/constant'
   *  Constant: '<S40>/constant1'
   *  Constant: '<S40>/constant2'
   *  Constant: '<S40>/constant3'
   *  Constant: '<S40>/constant4'
   *  Constant: '<S40>/constant5'
   *  Constant: '<S40>/constant6'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  RelationalOperator: '<S40>/Relational Operator10'
   *  RelationalOperator: '<S40>/Relational Operator2'
   *  RelationalOperator: '<S40>/Relational Operator3'
   *  RelationalOperator: '<S40>/Relational Operator4'
   *  RelationalOperator: '<S40>/Relational Operator5'
   *  RelationalOperator: '<S40>/Relational Operator6'
   *  RelationalOperator: '<S40>/Relational Operator7'
   *  RelationalOperator: '<S40>/Relational Operator8'
   *  RelationalOperator: '<S40>/Relational Operator9'
   */
  if (!(1U == ((uint8_T)T15CD_ST_OFF))) {
    CrCtl_B.RelationalOperator2_m = false;
    CrCtl_B.RelationalOperator3 = (CrCtl_B.MFLv_stCrCtlMode_f == ((uint8_T)
      MFLV_SWTOFF));
    CrCtl_B.RelationalOperator8 = false;
    CrCtl_B.signal5_k = (MFLv_stCrCtlMode == ((uint8_T)MFLV_MODEERR));
    CrCtl_B.signal4 = false;
    CrCtl_B.signal5 = false;
    CrCtl_B.signal6 = false;
    CrCtl_B.signal7 = false;
    CrCtl_B.signal8 = false;
    CrCtl_B.signal9 = false;
  } else {
    CrCtl_B.RelationalOperator2_m = false;
    CrCtl_B.RelationalOperator3 = false;
    CrCtl_B.RelationalOperator8 = false;
    CrCtl_B.signal5_k = false;
    CrCtl_B.signal4 = false;
    CrCtl_B.signal5 = false;
    CrCtl_B.signal6 = false;
    CrCtl_B.signal7 = false;
    CrCtl_B.signal8 = false;
    CrCtl_B.signal9 = false;
  }

  /* End of MultiPortSwitch: '<S40>/Index Vector6' */
}

/*
 * Output and update for action system:
 *    '<S49>/Switch Case Action Subsystem1'
 *    '<S50>/Switch Case Action Subsystem1'
 */
void CrCtl_SwitchCaseActionSubsystem1(boolean_T rtu_signalIn, int8_T rtu_Time,
  boolean_T *rty_signalOut, uint8_T *rtd_numPeriod_g, boolean_T *rtd_timeLck_f)
{
  /* If: '<S59>/If' incorporates:
   *  Inport: '<S61>/signalIn'
   */
  if (*rtd_timeLck_f) {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    /* MultiPortSwitch: '<S60>/Index Vector2' incorporates:
     *  Constant: '<S60>/Constant4'
     *  Constant: '<S60>/T_ms'
     *  Product: '<S60>/Product'
     *  RelationalOperator: '<S60>/Relational Operator'
     */
    if (!((int32_T)((uint16_T)*rtd_numPeriod_g * ((uint8_T)T_ms)) < rtu_Time)) {
      /* DataStoreWrite: '<S60>/Data Store Write' incorporates:
       *  Constant: '<S60>/Constant2'
       */
      *rtd_timeLck_f = false;

      /* DataStoreWrite: '<S60>/Data Store Write1' incorporates:
       *  Constant: '<S60>/Constant5'
       */
      *rtd_numPeriod_g = 0U;
      *rty_signalOut = rtu_signalIn;
    } else {
      /* DataStoreWrite: '<S60>/Data Store Write1' incorporates:
       *  Constant: '<S60>/Constant1'
       *  Sum: '<S60>/Add'
       */
      (*rtd_numPeriod_g)++;
      *rty_signalOut = true;
    }

    /* End of MultiPortSwitch: '<S60>/Index Vector2' */
    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    *rty_signalOut = rtu_signalIn;

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
  }

  /* End of If: '<S59>/If' */
}

/* Outputs for atomic system: '<S36>/CrCtlShOff_Cdtns_2' */
void CrCtl_CrCtlShOff_Cdtns_2(void)
{
  boolean_T rtb_LogicalOperator10;
  boolean_T RelationalOperator11;

  /* RelationalOperator: '<S41>/Relational Operator11' incorporates:
   *  Constant: '<S41>/0x02'
   */
  RelationalOperator11 = (CrCtl_B.CrCtl_stModeFdbck <= 2);

  /* Logic: '<S41>/Logical Operator10' incorporates:
   *  RelationalOperator: '<S41>/Relational Operator10'
   */
  rtb_LogicalOperator10 = ((CrCtl_B.rVn_mmphprpm == 0) &&
    CrCtl_B.LogicalOperator_f);

  /* Outputs for Enabled SubSystem: '<S54>/RESET Priority' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  if (CrCtl_ConstB.LogicalOperator2) {
    if (!CrCtl_DW.RESETPriority_MODE) {
      CrCtl_DW.RESETPriority_MODE = true;
    }
  } else {
    if (CrCtl_DW.RESETPriority_MODE) {
      CrCtl_DW.RESETPriority_MODE = false;
    }
  }

  if (CrCtl_DW.RESETPriority_MODE) {
    /* Logic: '<S55>/Logical Operator2' incorporates:
     *  DataTypeConversion: '<S54>/Data Type Conversion1'
     *  Logic: '<S55>/Logical Operator'
     *  Logic: '<S55>/Logical Operator1'
     *  Memory: '<S55>/IC=ic'
     */
    CrCtl_B.LogicalOperator2 = ((rtb_LogicalOperator10 ||
      CrCtl_DW.ICic_PreviousInput_k) && (!RelationalOperator11));
  }

  /* End of Outputs for SubSystem: '<S54>/RESET Priority' */

  /* Outputs for Enabled SubSystem: '<S54>/SET  Priority' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (CrCtl_ConstB.RelationalOperator1) {
    if (!CrCtl_DW.SETPriority_MODE) {
      CrCtl_DW.SETPriority_MODE = true;
    }
  } else {
    if (CrCtl_DW.SETPriority_MODE) {
      CrCtl_DW.SETPriority_MODE = false;
    }
  }

  if (CrCtl_DW.SETPriority_MODE) {
    /* Logic: '<S56>/Logical Operator' incorporates:
     *  DataTypeConversion: '<S54>/Data Type Conversion1'
     *  Logic: '<S56>/Logical Operator1'
     *  Logic: '<S56>/Logical Operator2'
     *  Memory: '<S56>/IC=ic'
     */
    CrCtl_B.LogicalOperator_l = (rtb_LogicalOperator10 ||
      ((!RelationalOperator11) && CrCtl_DW.ICic_PreviousInput));
  }

  /* End of Outputs for SubSystem: '<S54>/SET  Priority' */

  /* RelationalOperator: '<S41>/Relational Operator12' incorporates:
   *  Constant: '<S3>/T15CD_stDebVal1'
   *  Constant: '<S41>/T15CD_ST_OFF(=0)'
   */
  RelationalOperator11 = (1U == ((uint8_T)T15CD_ST_OFF));

  /* MultiPortSwitch: '<S41>/Index Vector6' incorporates:
   *  Constant: '<S41>/BRKCD_ST_1(=0h)'
   *  Constant: '<S41>/Constant3'
   *  Constant: '<S41>/Constant4'
   *  Constant: '<S41>/Constant5'
   *  Constant: '<S41>/Constant6'
   *  Constant: '<S41>/CrCtl_rVnDvtAbsShOff_C_mmphprph_44'
   *  Constant: '<S41>/shield'
   *  Constant: '<S41>/shield1'
   *  Constant: '<S41>/shield2'
   *  Constant: '<S7>/CoDT_trqMin0_10mNm'
   *  Inport: '<Root>/BrkCD_stPressed_UB'
   *  Logic: '<S41>/Logical Operator5'
   *  Logic: '<S41>/Logical Operator6'
   *  Logic: '<S41>/Logical Operator8'
   *  Logic: '<S54>/Logical Operator1'
   *  RelationalOperator: '<S41>/Relational Operator4'
   *  RelationalOperator: '<S41>/Relational Operator5'
   *  RelationalOperator: '<S41>/Relational Operator6'
   *  RelationalOperator: '<S41>/Relational Operator7'
   */
  if (!RelationalOperator11) {
    CrCtl_B.signal4_e = (CrCtl_B.LogicalOperator_l || CrCtl_B.LogicalOperator2);
    CrCtl_B.signal3 = ((!CrCtl_B.LogicalOperator_f) && (CrCtl_B.rVn_mmphprpm <
      CrCtl_rVnDvtAbsShOff_C_mmphprpm));
    CrCtl_B.signal2 = false;
    CrCtl_B.signal1 = ((BrkCD_stPressed_UB != ((uint8_T)BRKCD_ST_1)) &&
                       (CrCtl_B.CrCtl_trqDesIn_10mNm >= 0L));
  } else {
    CrCtl_B.signal4_e = false;
    CrCtl_B.signal3 = false;
    CrCtl_B.signal2 = false;
    CrCtl_B.signal1 = false;
  }

  CrCtl_B.RelationalOperator8 = false;
  CrCtl_B.signal5_k = false;

  /* End of MultiPortSwitch: '<S41>/Index Vector6' */

  /* RelationalOperator: '<S41>/Relational Operator3' incorporates:
   *  Constant: '<S41>/CrCtl_aAccShOff_C_10mmps2'
   */
  CrCtl_B.RelationalOperator3 = (CrCtl_B.Diff > CrCtl_aAccShOff_C_10mmps2);

  /* If: '<S50>/If' incorporates:
   *  Constant: '<S41>/CrCtl_tiAccShOff_C_ms'
   *  Memory: '<S50>/Memory'
   */
  if (CrCtl_B.RelationalOperator3 && (!CrCtl_DW.Memory_PreviousInput_bl)) {
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S63>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem(CrCtl_B.RelationalOperator3,
      &RelationalOperator11, &CrCtl_DW.numPeriod_a, &CrCtl_DW.timeLck_a);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem1(CrCtl_B.RelationalOperator3,
      CrCtl_tiAccShOff_C_ms, &RelationalOperator11, &CrCtl_DW.numPeriod_a,
      &CrCtl_DW.timeLck_a);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem1' */
  }

  /* End of If: '<S50>/If' */

  /* RelationalOperator: '<S41>/Relational Operator2' incorporates:
   *  Constant: '<S41>/CrCtl_aDeclShOff_C_10mmps2'
   */
  CrCtl_B.RelationalOperator2_m = (CrCtl_B.Diff < CrCtl_aDeclShOff_C_10mmps2);

  /* If: '<S49>/If' incorporates:
   *  Constant: '<S41>/CrCtl_tiDeclShOff_C_ms'
   *  Memory: '<S49>/Memory'
   */
  if (CrCtl_B.RelationalOperator2_m && (!CrCtl_DW.Memory_PreviousInput_l2)) {
    /* Outputs for IfAction SubSystem: '<S49>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem(CrCtl_B.RelationalOperator2_m,
      &RelationalOperator11, &CrCtl_DW.numPeriod_g, &CrCtl_DW.timeLck_f);

    /* End of Outputs for SubSystem: '<S49>/Switch Case Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S49>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem1(CrCtl_B.RelationalOperator2_m,
      CrCtl_tiDeclShOff_C_ms, &RelationalOperator11, &CrCtl_DW.numPeriod_g,
      &CrCtl_DW.timeLck_f);

    /* End of Outputs for SubSystem: '<S49>/Switch Case Action Subsystem1' */
  }

  /* End of If: '<S49>/If' */
}

/* Update for atomic system: '<S36>/CrCtlShOff_Cdtns_2' */
void CrCtl_CrCtlShOff_Cdtns_2_Update(void)
{
  /* Update for Enabled SubSystem: '<S54>/RESET Priority' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  if (CrCtl_DW.RESETPriority_MODE) {
    /* Update for Memory: '<S55>/IC=ic' */
    CrCtl_DW.ICic_PreviousInput_k = CrCtl_B.LogicalOperator2;
  }

  /* End of Update for SubSystem: '<S54>/RESET Priority' */

  /* Update for Enabled SubSystem: '<S54>/SET  Priority' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (CrCtl_DW.SETPriority_MODE) {
    /* Update for Memory: '<S56>/IC=ic' */
    CrCtl_DW.ICic_PreviousInput = CrCtl_B.LogicalOperator_l;
  }

  /* End of Update for SubSystem: '<S54>/SET  Priority' */

  /* Update for Memory: '<S50>/Memory' */
  CrCtl_DW.Memory_PreviousInput_bl = CrCtl_B.RelationalOperator3;

  /* Update for Memory: '<S49>/Memory' */
  CrCtl_DW.Memory_PreviousInput_l2 = CrCtl_B.RelationalOperator2_m;
}

/* Outputs for atomic system: '<S36>/CrCtlShOff_Cdtns_3' */
void CrCtl_CrCtlShOff_Cdtns_3(void)
{
  boolean_T rtb_Merge_o;

  /* MultiPortSwitch: '<S42>/Index Vector6' incorporates:
   *  Constant: '<S3>/AccPed_stBrkDes'
   *  Constant: '<S3>/T15CD_stDebVal1'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  Constant: '<S42>/Constant4'
   *  Constant: '<S42>/CrCtl_GearMin_C'
   *  Constant: '<S42>/CrCtl_nMaxShOff_C_10mrpm'
   *  Constant: '<S42>/CrCtl_nMinShOff_C_10mrpm'
   *  Constant: '<S42>/CrCtl_vMaxShOff_C_10mph'
   *  Constant: '<S42>/CrCtl_vMinShOff_C_10mph'
   *  Constant: '<S42>/FALSE'
   *  Constant: '<S42>/T15CD_ST_OFF (=0)'
   *  Constant: '<S42>/constant1'
   *  Logic: '<S42>/Logical Operator'
   *  Logic: '<S42>/Logical Operator1'
   *  Logic: '<S42>/Logical Operator2'
   *  RelationalOperator: '<S42>/Relational Operator'
   *  RelationalOperator: '<S42>/Relational Operator1'
   *  RelationalOperator: '<S42>/Relational Operator10'
   *  RelationalOperator: '<S42>/Relational Operator2'
   *  RelationalOperator: '<S42>/Relational Operator3'
   *  RelationalOperator: '<S42>/Relational Operator4'
   *  RelationalOperator: '<S42>/Relational Operator5'
   *  RelationalOperator: '<S42>/Relational Operator6'
   */
  if (!(1U == ((uint8_T)T15CD_ST_OFF))) {
    CrCtl_B.signal1 = ((CrCtl_B.Gearbx_stGear < CrCtl_GearMin_C) &&
                       (CrCtl_B.LogicalOperator_f == FALSE));
    CrCtl_B.signal5_k = false;
    CrCtl_B.signal2 = (((int32_T)VSSCD_v_10mphUW > CrCtl_vMaxShOff_C_10mph) ||
                       ((int32_T)VSSCD_v_10mphUW < CrCtl_vMinShOff_C_10mph));
    CrCtl_B.signal3 = ((CrCtl_B.Eng_nAvrg_10mrpm > CrCtl_nMaxShOff_C_10mrpm) ||
                       (CrCtl_B.Eng_nAvrg_10mrpm < CrCtl_nMinShOff_C_10mrpm));
    CrCtl_B.signal4_e = false;
  } else {
    CrCtl_B.signal1 = false;
    CrCtl_B.signal5_k = false;
    CrCtl_B.signal2 = false;
    CrCtl_B.signal3 = false;
    CrCtl_B.signal4_e = false;
  }

  /* End of MultiPortSwitch: '<S42>/Index Vector6' */

  /* RelationalOperator: '<S42>/Relational Operator8' incorporates:
   *  Constant: '<S42>/CRCTL_OVERRIDE(=2h)'
   */
  CrCtl_B.RelationalOperator8 = (CrCtl_B.CrCtl_stOpFuncFdbck_UB == ((uint8_T)
    CRCTL_OVERRIDE));

  /* If: '<S78>/If' incorporates:
   *  DataStoreRead: '<S81>/Data Store Read4'
   *  If: '<S81>/If'
   *  Memory: '<S78>/Memory'
   */
  if (CrCtl_B.RelationalOperator8 && (!CrCtl_DW.Memory_PreviousInput_i)) {
    /* Outputs for IfAction SubSystem: '<S78>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem(CrCtl_B.RelationalOperator8, &rtb_Merge_o,
      &CrCtl_DW.numPeriod_c, &CrCtl_DW.timeLck_b);

    /* End of Outputs for SubSystem: '<S78>/Switch Case Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S78>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    if (CrCtl_DW.timeLck_b) {
      /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* If: '<S81>/If' incorporates:
       *  Constant: '<S42>/CrCtl_tiOverrideShOff_C'
       *  Constant: '<S82>/20ms'
       *  Constant: '<S82>/Constant1'
       *  Constant: '<S82>/Constant2'
       *  Constant: '<S82>/Constant5'
       *  DataStoreRead: '<S82>/Data Store Read1'
       *  DataStoreRead: '<S82>/Data Store Read2'
       *  DataStoreWrite: '<S82>/Data Store Write'
       *  DataStoreWrite: '<S82>/Data Store Write1'
       *  MultiPortSwitch: '<S82>/Index Vector2'
       *  Product: '<S82>/Product'
       *  RelationalOperator: '<S82>/Relational Operator'
       *  Sum: '<S82>/Add'
       */
      if (!((uint16_T)CrCtl_DW.numPeriod_c * ((uint8_T)T_ms) <
            CrCtl_tiOverrideShOff_C)) {
        CrCtl_DW.timeLck_b = false;
        CrCtl_DW.numPeriod_c = 0U;
      } else {
        CrCtl_DW.numPeriod_c++;
      }

      /* End of Outputs for SubSystem: '<S81>/If Action Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S78>/Switch Case Action Subsystem1' */
  }

  /* End of If: '<S78>/If' */
}

/* Update for atomic system: '<S36>/CrCtlShOff_Cdtns_3' */
void CrCtl_CrCtlShOff_Cdtns_3_Update(void)
{
  /* Update for Memory: '<S78>/Memory' */
  CrCtl_DW.Memory_PreviousInput_i = CrCtl_B.RelationalOperator8;
}

/* Outputs for atomic system: '<S36>/CrCtlShOff_Cdtns_4' */
void CrCtl_CrCtlShOff_Cdtns_4(void)
{
  boolean_T rtb_Merge_i1;

  /* RelationalOperator: '<S43>/Relational Operator2' incorporates:
   *  Constant: '<S43>/CrCtl_vDvtShOff_C_10mph'
   *  Sum: '<S43>/Sum'
   */
  CrCtl_B.RelationalOperator2 = (VSSCD_v_10mphUW > ((int32_T)((int16_T)
    (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vDvtShOff_C_10mph >> 1)) << 1));

  /* If: '<S84>/If' incorporates:
   *  DataStoreRead: '<S88>/Data Store Read4'
   *  If: '<S88>/If'
   *  Memory: '<S84>/Memory'
   */
  if (CrCtl_B.RelationalOperator2 && (!CrCtl_DW.Memory_PreviousInput_b)) {
    /* Outputs for IfAction SubSystem: '<S84>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    CrCtl_SwitchCaseActionSubsystem(CrCtl_B.RelationalOperator2, &rtb_Merge_i1,
      &CrCtl_DW.numPeriod, &CrCtl_DW.timeLck);

    /* End of Outputs for SubSystem: '<S84>/Switch Case Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S84>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    if (CrCtl_DW.timeLck) {
      /* Outputs for IfAction SubSystem: '<S88>/If Action Subsystem' incorporates:
       *  ActionPort: '<S89>/Action Port'
       */
      /* If: '<S88>/If' incorporates:
       *  Constant: '<S43>/CrCtl_tiDvtShOff_C_ms'
       *  Constant: '<S89>/T_ms'
       *  DataStoreRead: '<S89>/Data Store Read2'
       *  MultiPortSwitch: '<S89>/Index Vector2'
       *  Product: '<S89>/Product'
       *  RelationalOperator: '<S89>/Relational Operator'
       */
      if (!((uint16_T)CrCtl_DW.numPeriod * ((uint8_T)T_ms) <
            CrCtl_tiDvtShOff_C_ms)) {
        /* DataStoreWrite: '<S89>/Data Store Write' incorporates:
         *  Constant: '<S89>/Constant2'
         */
        CrCtl_DW.timeLck = false;

        /* DataStoreWrite: '<S89>/Data Store Write1' incorporates:
         *  Constant: '<S89>/Constant5'
         */
        CrCtl_DW.numPeriod = 0U;
      } else {
        /* DataStoreWrite: '<S89>/Data Store Write1' incorporates:
         *  Constant: '<S89>/Constant1'
         *  DataStoreRead: '<S89>/Data Store Read1'
         *  Sum: '<S89>/Add'
         */
        CrCtl_DW.numPeriod++;
      }

      /* End of Outputs for SubSystem: '<S88>/If Action Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S84>/Switch Case Action Subsystem1' */
  }

  /* End of If: '<S84>/If' */
}

/* Update for atomic system: '<S36>/CrCtlShOff_Cdtns_4' */
void CrCtl_CrCtlShOff_Cdtns_4_Update(void)
{
  /* Update for Memory: '<S84>/Memory' */
  CrCtl_DW.Memory_PreviousInput_b = CrCtl_B.RelationalOperator2;
}

/* Outputs for atomic system: '<S3>/CrCtlShOff_Cdtns' */
void CrCtl_CrCtlShOff_Cdtns(void)
{
  int16_T rtb_Gain_p;
  int16_T rtb_Gain1;
  int16_T rtb_Gain2;
  int16_T rtb_Gain9;
  int16_T rtb_Gain13;
  int16_T rtb_Gain14;
  int16_T rtb_Gain15;
  uint16_T rtb_Gain10;
  int16_T Gain11;
  int16_T Gain12;

  /* Outputs for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_1' */
  CrCtl_CrCtlShOff_Cdtns_1();

  /* End of Outputs for SubSystem: '<S36>/CrCtlShOff_Cdtns_1' */

  /* Gain: '<S36>/Gain' */
  rtb_Gain_p = CrCtl_B.RelationalOperator3;

  /* Gain: '<S36>/Gain1' */
  rtb_Gain1 = CrCtl_B.RelationalOperator2_m << 1;

  /* Gain: '<S36>/Gain2' */
  rtb_Gain2 = CrCtl_B.signal5_k << 2;

  /* Gain: '<S36>/Gain9' */
  rtb_Gain9 = CrCtl_B.RelationalOperator8 << 9;

  /* Outputs for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_2' */
  CrCtl_CrCtlShOff_Cdtns_2();

  /* End of Outputs for SubSystem: '<S36>/CrCtlShOff_Cdtns_2' */

  /* Gain: '<S36>/Gain11' */
  Gain11 = CrCtl_B.RelationalOperator8 << 10;

  /* Gain: '<S36>/Gain12' */
  Gain12 = CrCtl_B.signal5_k << 11;

  /* Gain: '<S36>/Gain13' */
  rtb_Gain13 = CrCtl_B.signal2 << 12;

  /* Gain: '<S36>/Gain14' */
  rtb_Gain14 = CrCtl_B.signal3 << 13;

  /* Gain: '<S36>/Gain15' */
  rtb_Gain15 = CrCtl_B.signal1 << 14;

  /* Gain: '<S36>/Gain10' */
  rtb_Gain10 = (uint16_T)CrCtl_B.signal4_e << 15;

  /* Outputs for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_3' */
  CrCtl_CrCtlShOff_Cdtns_3();

  /* End of Outputs for SubSystem: '<S36>/CrCtlShOff_Cdtns_3' */

  /* MultiPortSwitch: '<S36>/Index Vector' incorporates:
   *  Constant: '<S36>/CRCTL_CUT_1h'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/PCCSHOFFHILL'
   *  Constant: '<S36>/PCCSHOFFPRDCT'
   *  Gain: '<S36>/Gain3'
   *  Gain: '<S36>/Gain4'
   *  Gain: '<S36>/Gain5'
   *  Gain: '<S36>/Gain6'
   *  Gain: '<S36>/Gain7'
   *  Gain: '<S36>/Gain8'
   *  Inport: '<Root>/PCC_offRsn_UB'
   *  Logic: '<S36>/Logical Operator'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  RelationalOperator: '<S36>/Relational Operator3'
   *  RelationalOperator: '<S36>/Relational Operator4'
   *  Sum: '<S36>/Add'
   *  Sum: '<S36>/Add1'
   *  Sum: '<S36>/Add6'
   */
  if (!((int32_T)((uint32_T)((uint16_T)((((((((((((((((PCC_offRsn_UB == 2) ||
      (PCC_offRsn_UB == 11)) + rtb_Gain_p) + rtb_Gain1) + rtb_Gain2) +
      (CrCtl_B.signal4 << 3)) + (CrCtl_B.signal5 << 4)) + (CrCtl_B.signal6 << 5))
    + (CrCtl_B.signal7 << 6)) + (CrCtl_B.signal8 << 7)) + (CrCtl_B.signal9 << 8))
              + rtb_Gain9) + Gain11) + Gain12) + rtb_Gain13) + rtb_Gain14) +
         rtb_Gain15) + rtb_Gain10) != 0L)) {
    /* MultiPortSwitch: '<S36>/Index Vector1' incorporates:
     *  Constant: '<S36>/CRCTL_RMPONE_2h'
     *  Constant: '<S36>/Constant1'
     *  Gain: '<S36>/Gain16'
     *  Gain: '<S36>/Gain17'
     *  Gain: '<S36>/Gain18'
     *  Gain: '<S36>/Gain19'
     *  Gain: '<S36>/Gain20'
     *  RelationalOperator: '<S36>/Relational Operator1'
     *  Sum: '<S36>/Add2'
     */
    if (!((int32_T)((((((uint32_T)CrCtl_B.signal1 << 16) + ((uint32_T)
              CrCtl_B.signal2 << 17)) + ((uint32_T)CrCtl_B.signal3 << 18)) +
                     ((uint32_T)CrCtl_B.signal4_e << 19)) + ((uint32_T)
           CrCtl_B.signal5_k << 20)) != 0L)) {
      /* MultiPortSwitch: '<S36>/Index Vector2' incorporates:
       *  Constant: '<S36>/CRCTL_NOSHOFFCONACTV_0h'
       *  Constant: '<S36>/CRCTL_RMPTWO_3h'
       */
      if (!CrCtl_ConstB.RelationalOperator2) {
        CrCtl_B.IndexVector_k = ((uint8_T)CRCTL_NOSHOFFCONACTV);
      } else {
        CrCtl_B.IndexVector_k = ((uint8_T)CRCTL_RMPTWO);
      }

      /* End of MultiPortSwitch: '<S36>/Index Vector2' */
    } else {
      CrCtl_B.IndexVector_k = ((uint8_T)CRCTL_RMPONE);
    }

    /* End of MultiPortSwitch: '<S36>/Index Vector1' */
  } else {
    CrCtl_B.IndexVector_k = ((uint8_T)CRCTL_CUT);
  }

  /* End of MultiPortSwitch: '<S36>/Index Vector' */

  /* Outputs for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_4' */
  CrCtl_CrCtlShOff_Cdtns_4();

  /* End of Outputs for SubSystem: '<S36>/CrCtlShOff_Cdtns_4' */
}

/* Update for atomic system: '<S3>/CrCtlShOff_Cdtns' */
void CrCtl_CrCtlShOff_Cdtns_Update(void)
{
  /* Update for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_2' */
  CrCtl_CrCtlShOff_Cdtns_2_Update();

  /* End of Update for SubSystem: '<S36>/CrCtlShOff_Cdtns_2' */

  /* Update for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_3' */
  CrCtl_CrCtlShOff_Cdtns_3_Update();

  /* End of Update for SubSystem: '<S36>/CrCtlShOff_Cdtns_3' */

  /* Update for Atomic SubSystem: '<S36>/CrCtlShOff_Cdtns_4' */
  CrCtl_CrCtlShOff_Cdtns_4_Update();

  /* End of Update for SubSystem: '<S36>/CrCtlShOff_Cdtns_4' */
}

/* System initialize for atomic system: '<S3>/CrCtlShOff_Reactvtn' */
void CrCtl_CrCtlShOff_Reactvtn_Init(void)
{
  /* SystemInitialize for Chart: '<S37>/fallingEdge' */
  CrCtl_B.En = false;
}

/* Outputs for atomic system: '<S3>/CrCtlShOff_Reactvtn' */
void CrCtl_CrCtlShOff_Reactvtn(void)
{
  boolean_T rtb_LogicalOperator5_m;
  uint8_T ExtractDesiredBits_d;
  int16_T u;
  uint16_T tmp;

  /* DataTypeConversion: '<S116>/Extract Desired Bits' incorporates:
   *  Inport: '<Root>/ConvCD_stClth_UB'
   */
  ExtractDesiredBits_d = (uint8_T)(ConvCD_stClth_UB & 1);

  /* Logic: '<S37>/Logical Operator2' incorporates:
   *  Constant: '<S37>/CRCTL_OFF_2h'
   *  Logic: '<S37>/Logical Operator1'
   *  RelationalOperator: '<S37>/Relational Operator2'
   *
   * Block description for '<S37>/Relational Operator2':
   *  during active cruise control
   */
  CrCtl_B.IndexVector3 = (((ExtractDesiredBits_d != 0) ||
    CrCtl_B.LogicalOperator_f) && (CrCtl_B.Merge > ((uint8_T)CRCTL_OFF)));

  /* MultiPortSwitch: '<S115>/Index Vector' incorporates:
   *  Chart: '<S115>/Chart'
   *  Constant: '<S115>/Constant'
   *  Constant: '<S115>/Constant1'
   *  Logic: '<S37>/Logical Operator'
   *  Logic: '<S37>/Logical Operator4'
   *  Memory: '<S115>/Memory'
   *  Sum: '<S115>/Add'
   */
  if (!((ExtractDesiredBits_d == 0) && ((!(ExtractDesiredBits_d != 0)) &&
        CrCtl_B.IndexVector3))) {
    CrCtl_B.IndexVector_d = 0U;
  } else {
    CrCtl_B.IndexVector_d = (uint8_T)(1U + CrCtl_DW.Memory_PreviousInput_g);
  }

  /* End of MultiPortSwitch: '<S115>/Index Vector' */

  /* Logic: '<S37>/Logical Operator5' incorporates:
   *  Logic: '<S37>/Logical Operator3'
   *  Memory: '<S37>/Memory4'
   */
  rtb_LogicalOperator5_m = (CrCtl_B.IndexVector3 && ((ExtractDesiredBits_d != 0)
    || CrCtl_DW.Memory4_PreviousInput));

  /* MultiPortSwitch: '<S117>/Index Vector' incorporates:
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Constant1'
   *  Memory: '<S117>/Memory'
   *  Sum: '<S117>/Add'
   */
  if (!rtb_LogicalOperator5_m) {
    CrCtl_B.IndexVector_i = 1U;
  } else {
    CrCtl_B.IndexVector_i = (uint8_T)(1U + CrCtl_DW.Memory_PreviousInput_e);
  }

  /* End of MultiPortSwitch: '<S117>/Index Vector' */

  /* Gain: '<S37>/Gain1' incorporates:
   *  Constant: '<S37>/CrCtl_tiSuspSync_C'
   *  Gain: '<S37>/Gain'
   */
  tmp = ((uint8_T)T_ms) * 3U;

  /* MultiPortSwitch: '<S37>/Index Vector3' incorporates:
   *  Constant: '<S37>/FALSE1'
   *  Gain: '<S117>/Gain'
   *  Gain: '<S37>/Gain1'
   *  RelationalOperator: '<S117>/Relational Operator'
   */
  if (!((uint16_T)((uint8_T)T_ms) * CrCtl_B.IndexVector_i <= tmp)) {
    /* MultiPortSwitch: '<S37>/Index Vector' incorporates:
     *  Constant: '<S37>/FALSE'
     *  Gain: '<S115>/Gain'
     *  RelationalOperator: '<S37>/Relational Operator'
     */
    if (tmp < (uint16_T)((uint8_T)T_ms) * CrCtl_B.IndexVector_d) {
      CrCtl_B.IndexVector3 = FALSE;
    }

    /* End of MultiPortSwitch: '<S37>/Index Vector' */

    /* MultiPortSwitch: '<S37>/Index Vector4' incorporates:
     *  Memory: '<S37>/Memory2'
     */
    CrCtl_B.IndexVector4 = CrCtl_DW.Memory2_PreviousInput_h;
  } else {
    CrCtl_B.IndexVector3 = FALSE;

    /* MultiPortSwitch: '<S37>/Index Vector4' incorporates:
     *  Constant: '<S37>/FALSE1'
     */
    CrCtl_B.IndexVector4 = CrCtl_B.rVn_mmphprpm;
  }

  /* End of MultiPortSwitch: '<S37>/Index Vector3' */

  /* MultiPortSwitch: '<S37>/Index Vector1' incorporates:
   *  Memory: '<S37>/Memory3'
   */
  if (!rtb_LogicalOperator5_m) {
    CrCtl_B.CrCtl_rVnSusp_mp = CrCtl_B.rVn_mmphprpm;
  } else {
    CrCtl_B.CrCtl_rVnSusp_mp = CrCtl_DW.Memory3_PreviousInput;
  }

  /* End of MultiPortSwitch: '<S37>/Index Vector1' */

  /* Sum: '<S37>/Sum' */
  u = CrCtl_B.CrCtl_rVnSusp_mp - CrCtl_B.rVn_mmphprpm;

  /* Abs: '<S37>/Abs' */
  if (u < 0) {
    u = -u;
  }

  /* End of Abs: '<S37>/Abs' */

  /* RelationalOperator: '<S37>/Relational Operator1' */
  CrCtl_B.RelationalOperator1 = (u < 10);

  /* Chart: '<S37>/fallingEdge' incorporates:
   *  Memory: '<S37>/Memory1'
   */
  CrCtl_B.En = ((!CrCtl_B.RelationalOperator1) &&
                CrCtl_DW.Memory1_PreviousInput_k);
}

/* Update for atomic system: '<S3>/CrCtlShOff_Reactvtn' */
void CrCtl_CrCtlShOff_Reactvtn_Update(void)
{
  /* Update for Memory: '<S115>/Memory' */
  CrCtl_DW.Memory_PreviousInput_g = CrCtl_B.IndexVector_d;

  /* Update for Memory: '<S37>/Memory4' */
  CrCtl_DW.Memory4_PreviousInput = CrCtl_B.En;

  /* Update for Memory: '<S117>/Memory' */
  CrCtl_DW.Memory_PreviousInput_e = CrCtl_B.IndexVector_i;

  /* Update for Memory: '<S37>/Memory2' */
  CrCtl_DW.Memory2_PreviousInput_h = CrCtl_B.IndexVector4;

  /* Update for Memory: '<S37>/Memory3' */
  CrCtl_DW.Memory3_PreviousInput = CrCtl_B.CrCtl_rVnSusp_mp;

  /* Update for Memory: '<S37>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_k = CrCtl_B.RelationalOperator1;
}

/* System initialize for atomic system: '<Root>/CrCtl_ShOff' */
void CrCtl_CrCtl_ShOff_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S3>/CrCtlShOff_Reactvtn' */
  CrCtl_CrCtlShOff_Reactvtn_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/CrCtlShOff_Reactvtn' */

  /* SystemInitialize for Chart: '<S3>/CrCtlShOff_modeSelect' */
  CrCtl_stModeIn_UB = 0;
  CrCtl_stModeSubIn_UB = 0;
}

/* Outputs for atomic system: '<Root>/CrCtl_ShOff' */
void CrCtl_CrCtl_ShOff(void)
{
  /* Inport: '<S3>/CrCtl_vSetPointTrgtFdbck_10mph' */
  CrCtl_vSetPointTrgtIn_10mphUW = CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph;

  /* Outputs for Atomic SubSystem: '<S3>/CrCtlShOff_Cdtns' */
  CrCtl_CrCtlShOff_Cdtns();

  /* End of Outputs for SubSystem: '<S3>/CrCtlShOff_Cdtns' */

  /* MultiPortSwitch: '<S3>/Index Vector11' incorporates:
   *  Constant: '<S3>/CRCTL_OFF_2h'
   *  Memory: '<S3>/Memory2'
   *  RelationalOperator: '<S3>/Relational Operator7'
   */
  if (!(CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_OFF))) {
    CrCtl_B.IndexVector11 = CrCtl_B.IndexVector_k;
  } else {
    CrCtl_B.IndexVector11 = CrCtl_DW.Memory2_PreviousInput_c;
  }

  /* End of MultiPortSwitch: '<S3>/Index Vector11' */

  /* Outputs for Atomic SubSystem: '<S3>/CrCtlShOff_Reactvtn' */
  CrCtl_CrCtlShOff_Reactvtn();

  /* End of Outputs for SubSystem: '<S3>/CrCtlShOff_Reactvtn' */

  /* MultiPortSwitch: '<S3>/Index Vector7' incorporates:
   *  Constant: '<S3>/CRCTL_NOSHOFFCONACTV'
   *  Constant: '<S3>/FALSE'
   *  RelationalOperator: '<S3>/Relational Operator3'
   *
   * Block description for '<S3>/Index Vector7':
   *  any other shutoff condition is used for cruise control and must also
   *  reset the suspend function by CrCtl_stSuspAct=0
   */
  if (CrCtl_B.IndexVector_k == ((uint8_T)CRCTL_NOSHOFFCONACTV)) {
    CrCtl_B.IndexVector7 = CrCtl_B.IndexVector3;
  } else {
    CrCtl_B.IndexVector7 = FALSE;
  }

  /* End of MultiPortSwitch: '<S3>/Index Vector7' */

  /* Chart: '<S3>/CrCtlShOff_modeSelect' */
  if (CrCtl_B.IndexVector_k != ((uint8_T)CRCTL_NOSHOFFCONACTV)) {
    if ((CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_OFF)) ||
        (CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_NEUTR))) {
      CrCtl_stModeIn_UB = CrCtl_B.CrCtl_stModeFdbck;
      CrCtl_stModeSubIn_UB = CrCtl_B.CrCtl_stModeSubFdbck;
    } else {
      CrCtl_stModeIn_UB = ((uint8_T)CRCTL_OFF);
      CrCtl_stModeSubIn_UB = ((uint8_T)CRCTL_SUBSTRTVAL);
    }
  } else if (CrCtl_B.CrCtl_stModeFdbck == ((uint8_T)CRCTL_OFF)) {
    CrCtl_stModeIn_UB = CrCtl_B.CrCtl_stModeFdbck;
    CrCtl_stModeSubIn_UB = CrCtl_B.CrCtl_stModeSubFdbck;
  } else {
    CrCtl_stModeIn_UB = CrCtl_B.Merge;
    CrCtl_stModeSubIn_UB = CrCtl_B.Merge1;
  }

  /* End of Chart: '<S3>/CrCtlShOff_modeSelect' */
}

/* Update for atomic system: '<Root>/CrCtl_ShOff' */
void CrCtl_CrCtl_ShOff_Update(void)
{
  /* Update for Atomic SubSystem: '<S3>/CrCtlShOff_Cdtns' */
  CrCtl_CrCtlShOff_Cdtns_Update();

  /* End of Update for SubSystem: '<S3>/CrCtlShOff_Cdtns' */

  /* Update for Memory: '<S3>/Memory2' */
  CrCtl_DW.Memory2_PreviousInput_c = CrCtl_B.IndexVector11;

  /* Update for Atomic SubSystem: '<S3>/CrCtlShOff_Reactvtn' */
  CrCtl_CrCtlShOff_Reactvtn_Update();

  /* End of Update for SubSystem: '<S3>/CrCtlShOff_Reactvtn' */
}

/* Output and update for action system: '<S4>/CrCtl_State_Neutr' */
void CrCtl_CrCtl_State_Neutr(void)
{
  /* SignalConversion: '<S123>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Constant: '<S7>/CoDT_trqMin0_10mNm'
   *  Inport: '<S123>/CoDT_trqMin'
   */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S123>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Constant: '<S7>/CoDT_trqMin0_10mNm'
   *  Inport: '<S123>/CoDT_trqMin'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* SignalConversion: '<S123>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S123>/CRCTL_STINACTIVE'
   */
  CrCtl_stActive_BL = FALSE;

  /* SignalConversion: '<S123>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S123>/CRCTL_NOTACTV'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_NOTACTV);

  /* Inport: '<S123>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S123>/CrCtl_stModeSub_In' */
  CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;

  /* Inport: '<S123>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S123>/CrCtl_vSetPointTrgt_In' */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* Inport: '<S123>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S124>/CrCtl_State_Off_Cut' */
void CrCtl_CrCtl_State_Off_Cut(void)
{
  /* SignalConversion: '<S173>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Constant: '<S173>/Constant'
   */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S173>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Constant: '<S173>/Constant'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* SignalConversion: '<S173>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S173>/CRCTL_STINACTIVE(=0)'
   */
  CrCtl_stActive_BL = FALSE;

  /* SignalConversion: '<S173>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S173>/CRCTL_NOTACTV(=0)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_NOTACTV);

  /* SignalConversion: '<S173>/OutportBufferForCrCtl_stMode' incorporates:
   *  Constant: '<S173>/CRCTL_NEUTR(=1h)'
   */
  CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_NEUTR);

  /* SignalConversion: '<S173>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S173>/CRCTL_SUBNOSUB(=1h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBNOSUB);

  /* MultiPortSwitch: '<S173>/Index Vector1' incorporates:
   *  Constant: '<S173>/CRCTL_LCK(=2h)'
   *  Constant: '<S173>/CRCTL_LCKACTV(=1h)'
   *  RelationalOperator: '<S173>/Relational Operator'
   */
  if (!(0 == ((uint8_T)CRCTL_LCKACTV))) {
    CrCtl_B.CrCtl_stLck = 0U;
  } else {
    CrCtl_B.CrCtl_stLck = ((uint8_T)CRCTL_LCK);
  }

  /* End of MultiPortSwitch: '<S173>/Index Vector1' */

  /* Inport: '<S173>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S173>/CrCtl_vSetPointTrgt_In' */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
}

/* Output and update for action system: '<S124>/CrCtl_State_Off_RmpOne' */
void CrCtl_CrCtl_State_Off_RmpOne(void)
{
  int64m_T rtb_Product1;
  uint32_T tmp;
  uint32_T tmp_0;

  /* SwitchCase: '<S174>/Switch Case' incorporates:
   *  Inport: '<S176>/CrCtl_rVnBeg_In'
   *  Inport: '<S176>/CrCtl_stLck_In'
   *  Inport: '<S176>/CrCtl_vSetPointTrgt_In'
   *  Inport: '<S177>/CrCtl_rVnBeg_In'
   *  Inport: '<S177>/CrCtl_stLck_In'
   *  Inport: '<S177>/CrCtl_stMode_In'
   *  Inport: '<S177>/CrCtl_vSetPointTrgt_In'
   */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S174>/CrCtl_State_Off_RmpOne_SubStrtVal' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    /* MultiPortSwitch: '<S177>/Index Vector' incorporates:
     *  Constant: '<S177>/CrCtl_facTrqIncrRmpOne_C'
     *  Constant: '<S177>/CrCtl_facTrqRedRmpOne_C'
     *  Constant: '<S7>/CoDT_trqMin0_10mNm'
     *  Product: '<S177>/Divide'
     *  Product: '<S177>/Divide1'
     *  RelationalOperator: '<S177>/Relational Operator'
     *  Sum: '<S177>/Subtract'
     *  Sum: '<S177>/Subtract1'
     *  Sum: '<S177>/Subtract2'
     *  Sum: '<S177>/Subtract3'
     */
    if (!(CrCtl_B.CrCtl_trqDesIn_10mNm > 0L)) {
      CrCtl_B.CrCtl_trqDes = div_nde_s32_floor(-CrCtl_B.CrCtl_trqDesIn_10mNm,
        10L) * CrCtl_facTrqIncrRmpOne_C + CrCtl_B.CrCtl_trqDesIn_10mNm;
    } else {
      CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm - div_nde_s32_floor
        (CrCtl_B.CrCtl_trqDesIn_10mNm, 10L) * CrCtl_facTrqRedRmpOne_C;
    }

    /* End of MultiPortSwitch: '<S177>/Index Vector' */

    /* SignalConversion: '<S177>/OutportBufferForCrCtl_trqLead' */
    CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

    /* SignalConversion: '<S177>/OutportBufferForCrCtl_stActive' incorporates:
     *  Constant: '<S177>/CRCTL_STACTIVE(=1)'
     */
    CrCtl_stActive_BL = TRUE;

    /* SignalConversion: '<S177>/OutportBufferForCrCtl_stOpFunc' incorporates:
     *  Constant: '<S177>/CRCTL_ACTV_1h'
     */
    CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

    /* SignalConversion: '<S177>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S177>/CRCTL_SUBRMP(=3h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;
    CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
    CrCtl_B.CrCtl_stLck = 0U;

    /* End of Outputs for SubSystem: '<S174>/CrCtl_State_Off_RmpOne_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S174>/CrCtl_State_Off_RmpOne_SubRmp' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    /* MultiPortSwitch: '<S176>/Index Vector' incorporates:
     *  Constant: '<S176>/CrCtl_tiShDwnRmpOne_C'
     *  Constant: '<S7>/CoDT_trqMin0_10mNm'
     *  RelationalOperator: '<S176>/Relational Operator'
     *  Sum: '<S176>/Add'
     *  Sum: '<S176>/Subtract3'
     */
    if (!(CrCtl_B.CrCtl_trqDesIn_10mNm > 0L)) {
      CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm +
        CrCtl_tiShDwnRmpOne_C;
    } else {
      CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm -
        CrCtl_tiShDwnRmpOne_C;
    }

    /* End of MultiPortSwitch: '<S176>/Index Vector' */

    /* Product: '<S176>/Product1' incorporates:
     *  Sum: '<S176>/Subtract'
     *  Sum: '<S176>/Subtract2'
     */
    tmp = (uint32_T)CrCtl_B.CrCtl_trqDesIn_10mNm;
    tmp_0 = (uint32_T)CrCtl_B.CrCtl_trqDes;
    sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_Product1.chunks[0U], 2);

    /* Switch: '<S176>/Switch' */
    if (sMultiWordGt(&rtb_Product1.chunks[0U],
                     &CrCtl_ConstP.Switch_Threshold.chunks[0], 2)) {
      /* SignalConversion: '<S176>/OutportBufferForCrCtl_stMode' */
      CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

      /* SignalConversion: '<S176>/OutportBufferForCrCtl_stModeSub' */
      CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
    } else {
      /* SignalConversion: '<S176>/OutportBufferForCrCtl_stMode' incorporates:
       *  Constant: '<S176>/CRCTL_NEUTR(=1h)'
       */
      CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_NEUTR);

      /* SignalConversion: '<S176>/OutportBufferForCrCtl_stModeSub' incorporates:
       *  Constant: '<S176>/CRCTL_SUBNOSUB(=1h)'
       */
      CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBNOSUB);
    }

    /* End of Switch: '<S176>/Switch' */

    /* SignalConversion: '<S176>/OutportBufferForCrCtl_trqLead' */
    CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

    /* SignalConversion: '<S176>/OutportBufferForCrCtl_stActive' incorporates:
     *  Constant: '<S176>/CRCTL_STACTIVE(=1)'
     */
    CrCtl_stActive_BL = TRUE;

    /* SignalConversion: '<S176>/OutportBufferForCrCtl_stOpFunc' incorporates:
     *  Constant: '<S176>/CRCTL_ACTV(=1h)'
     */
    CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);
    CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
    CrCtl_B.CrCtl_stLck = 0U;

    /* End of Outputs for SubSystem: '<S174>/CrCtl_State_Off_RmpOne_SubRmp' */
    break;
  }

  /* End of SwitchCase: '<S174>/Switch Case' */
}

/* Output and update for action system: '<S124>/CrCtl_State_Off_RmpTwo' */
void CrCtl_CrCtl_State_Off_RmpTwo(void)
{
  int64m_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  int16_T tmp_2;
  static int64m_T tmp_3 = { { 0UL, 0UL }/* chunks */
  };

  /* SwitchCase: '<S175>/Switch Case' incorporates:
   *  Inport: '<S178>/CrCtl_rVnBeg_In'
   *  Inport: '<S178>/CrCtl_stLck_In'
   *  Inport: '<S178>/CrCtl_vSetPointTrgt_In'
   *  Inport: '<S179>/CrCtl_rVnBeg_In'
   *  Inport: '<S179>/CrCtl_stLck_In'
   *  Inport: '<S179>/CrCtl_stMode_In'
   *  Inport: '<S179>/CrCtl_vSetPointTrgt_In'
   */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S175>/CrCtl_State_Off_RmpTwo_SubStrtVal' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* MultiPortSwitch: '<S179>/Index Vector' incorporates:
     *  Constant: '<S179>/CrCtl_facTrqIncrRmpTwo_C'
     *  Constant: '<S179>/CrCtl_facTrqRedRmpTwo_C'
     *  Constant: '<S7>/CoDT_trqMin0_10mNm'
     *  Product: '<S179>/Divide'
     *  Product: '<S179>/Divide1'
     *  RelationalOperator: '<S179>/Relational Operator'
     *  Sum: '<S179>/Subtract'
     *  Sum: '<S179>/Subtract1'
     *  Sum: '<S179>/Subtract2'
     *  Sum: '<S179>/Subtract3'
     */
    if (!(CrCtl_B.CrCtl_trqDesIn_10mNm > 0L)) {
      CrCtl_B.CrCtl_trqDes = div_nde_s32_floor(-CrCtl_B.CrCtl_trqDesIn_10mNm,
        10L) * CrCtl_facTrqIncrRmpTwo_C + CrCtl_B.CrCtl_trqDesIn_10mNm;
    } else {
      CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm - div_nde_s32_floor
        (CrCtl_B.CrCtl_trqDesIn_10mNm, 10L) * CrCtl_facTrqRedRmpTwo_C;
    }

    /* End of MultiPortSwitch: '<S179>/Index Vector' */

    /* SignalConversion: '<S179>/OutportBufferForCrCtl_trqLead' */
    CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

    /* SignalConversion: '<S179>/OutportBufferForCrCtl_stActive' incorporates:
     *  Constant: '<S179>/CRCTL_STACTIVE(=1h)'
     */
    CrCtl_stActive_BL = TRUE;

    /* SignalConversion: '<S179>/OutportBufferForCrCtl_stOpFunc' incorporates:
     *  Constant: '<S179>/CRCTL_ACTV(=1h)'
     */
    CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

    /* SignalConversion: '<S179>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S179>/CRCTL_SUBRMP(=3h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;
    CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
    CrCtl_B.CrCtl_stLck = 0U;

    /* End of Outputs for SubSystem: '<S175>/CrCtl_State_Off_RmpTwo_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S175>/CrCtl_State_Off_RmpTwo_SubRmp' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/CrCtl_facSlpRmpTwoDwn_C'
     *  Constant: '<S178>/CrCtl_facSlpRmpTwoUp_C'
     *  Sum: '<S178>/Subtract'
     */
    if (CrCtl_B.CrCtl_trqDesIn_10mNm > 0L) {
      tmp_2 = CrCtl_facSlpRmpTwoDwn_C;
    } else {
      tmp_2 = CrCtl_facSlpRmpTwoUp_C;
    }

    /* End of Switch: '<S178>/Switch1' */

    /* Sum: '<S178>/Add' incorporates:
     *  Constant: '<S178>/T_ms'
     *  Product: '<S178>/Divide'
     *  Product: '<S178>/Product'
     */
    CrCtl_B.CrCtl_trqDes = div_nde_s32_floor((int32_T)tmp_2 * ((uint8_T)T_ms),
      10L) + CrCtl_B.CrCtl_trqDesIn_10mNm;

    /* Product: '<S178>/Product1' incorporates:
     *  Sum: '<S178>/Subtract'
     *  Sum: '<S178>/Subtract2'
     */
    tmp_0 = (uint32_T)CrCtl_B.CrCtl_trqDesIn_10mNm;
    tmp_1 = (uint32_T)CrCtl_B.CrCtl_trqDes;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

    /* MultiPortSwitch: '<S178>/Index Vector' incorporates:
     *  RelationalOperator: '<S178>/Relational Operator'
     */
    if (!sMultiWordGt(&tmp.chunks[0U], &tmp_3.chunks[0U], 2)) {
      /* SignalConversion: '<S178>/OutportBufferForCrCtl_stMode' incorporates:
       *  Constant: '<S178>/CRCTL_NEUTR (=1h)'
       */
      CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_NEUTR);

      /* SignalConversion: '<S178>/OutportBufferForCrCtl_stModeSub' incorporates:
       *  Constant: '<S178>/CRCTL_SUBNOSUB (=1h)'
       */
      CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBNOSUB);
    } else {
      /* SignalConversion: '<S178>/OutportBufferForCrCtl_stMode' */
      CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

      /* SignalConversion: '<S178>/OutportBufferForCrCtl_stModeSub' */
      CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
    }

    /* End of MultiPortSwitch: '<S178>/Index Vector' */

    /* SignalConversion: '<S178>/OutportBufferForCrCtl_trqLead' */
    CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

    /* SignalConversion: '<S178>/OutportBufferForCrCtl_stActive' incorporates:
     *  Constant: '<S178>/CRCTL_STACTIVE(=1h)'
     */
    CrCtl_stActive_BL = TRUE;

    /* SignalConversion: '<S178>/OutportBufferForCrCtl_stOpFunc' incorporates:
     *  Constant: '<S178>/CRCTL_ACTV(=1h)'
     */
    CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);
    CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
    CrCtl_B.CrCtl_stLck = 0U;

    /* End of Outputs for SubSystem: '<S175>/CrCtl_State_Off_RmpTwo_SubRmp' */
    break;
  }

  /* End of SwitchCase: '<S175>/Switch Case' */
}

/* Output and update for action system: '<S4>/CrCtl_State_Off' */
void CrCtl_CrCtl_State_Off(void)
{
  /* SwitchCase: '<S124>/Switch Case1' */
  switch ((int32_T)CrCtl_B.IndexVector11) {
   case 0L:
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S124>/CrCtl_State_Off_Cut' incorporates:
     *  ActionPort: '<S173>/Action Port'
     */
    CrCtl_CrCtl_State_Off_Cut();

    /* End of Outputs for SubSystem: '<S124>/CrCtl_State_Off_Cut' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S124>/CrCtl_State_Off_RmpOne' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    CrCtl_CrCtl_State_Off_RmpOne();

    /* End of Outputs for SubSystem: '<S124>/CrCtl_State_Off_RmpOne' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S124>/CrCtl_State_Off_RmpTwo' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    CrCtl_CrCtl_State_Off_RmpTwo();

    /* End of Outputs for SubSystem: '<S124>/CrCtl_State_Off_RmpTwo' */
    break;
  }

  /* End of SwitchCase: '<S124>/Switch Case1' */
}

/* Start for action system: '<S4>/CrCtl_State_TipDwn' */
void CrCtl_CrCtl_State_TipDwn_Start(void)
{
  /* Start for IfAction SubSystem: '<S128>/CrCtl_State_TipDwn_SubCalcSet' */
  /* Start for Constant: '<S210>/CRCTL_STACTIVE(=1h)' */
  CrCtl_B.OutportBufferForCrCtl_stActive = TRUE;

  /* Start for Constant: '<S210>/CRCTL_ACTV(=1h)' */
  CrCtl_B.OutportBufferForCrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Start for Constant: '<S210>/CRCTL_SUBSTRTVAL(=2h)' */
  CrCtl_B.OutportBufferForCrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);

  /* End of Start for SubSystem: '<S128>/CrCtl_State_TipDwn_SubCalcSet' */
}

/* Output and update for action system: '<S4>/CrCtl_State_TipDwn' */
void CrCtl_CrCtl_State_TipDwn(void)
{
  boolean_T rtb_LogicalOperator1_dc;
  boolean_T rtb_RelationalOperator_nx;

  /* SwitchCase: '<S128>/Switch Case' incorporates:
   *  Constant: '<S210>/CRCTL_ACTV(=1h)'
   *  Constant: '<S210>/CRCTL_STACTIVE(=1h)'
   *  Constant: '<S210>/CRCTL_SUBSTRTVAL(=2h)'
   *  Inport: '<S210>/CrCtl_rVnBeg_In'
   *  Inport: '<S210>/CrCtl_stLck_In'
   *  Inport: '<S210>/CrCtl_trqDes_In'
   */
  if (CrCtl_stModeSubIn_UB == 6) {
    /* Outputs for IfAction SubSystem: '<S128>/CrCtl_State_TipDwn_SubCalcSet' incorporates:
     *  ActionPort: '<S210>/Action Port'
     */
    /* RelationalOperator: '<S210>/Relational Operator' incorporates:
     *  Constant: '<S210>/3000'
     *  Sum: '<S210>/Subtract'
     */
    rtb_RelationalOperator_nx = (VSSCD_v_10mphUW <= ((int32_T)((int16_T)
      (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vTipDwnUpLim_C_10mph >> 1)) <<
      1));
    CrCtl_B.CrCtl_trqDes_In = CrCtl_B.CrCtl_trqDesIn_10mNm;

    /* Logic: '<S210>/Logical Operator1' incorporates:
     *  Constant: '<S210>/03000'
     *  Constant: '<S210>/CrCtl_vMin_C_10mph'
     *  Constant: '<S210>/CrCtl_vTipStp_C_10mph'
     *  Inport: '<S210>/CrCtl_trqDes_In'
     *  Logic: '<S210>/Logical Operator'
     *  RelationalOperator: '<S210>/Relational Operator1'
     *  RelationalOperator: '<S210>/Relational Operator2'
     *  RelationalOperator: '<S210>/Relational Operator3'
     *  Sum: '<S210>/Subtract1'
     *  Sum: '<S210>/Subtract2'
     */
    rtb_LogicalOperator1_dc = (rtb_RelationalOperator_nx && (VSSCD_v_10mphUW >=
      ((int32_T)((int16_T)(CrCtl_vSetPointTrgtIn_10mphUW >> 1) -
                 (CrCtl_vTipDwnLoLim_C_10mph >> 1)) << 1)) && (((int32_T)
      ((int16_T)(CrCtl_vSetPointTrgtIn_10mphUW >> 1) - (CrCtl_vTipStp_C_10mph >>
      1)) << 1) > CrCtl_vMin_C_10mph) && (CrCtl_B.CrCtl_trqDes_In > -1L));

    /* MultiPortSwitch: '<S210>/Index Vector' incorporates:
     *  Constant: '<S210>/CrCtl_vTipStp_C_10mph'
     *  Sum: '<S210>/Subtract3'
     */
    if (!rtb_LogicalOperator1_dc) {
      CrCtl_B.IndexVector = CrCtl_vSetPointTrgtIn_10mphUW;
    } else {
      CrCtl_B.IndexVector = (uint16_T)((int16_T)(CrCtl_vSetPointTrgtIn_10mphUW >>
        1) - (CrCtl_vTipStp_C_10mph >> 1)) << 1;
    }

    /* End of MultiPortSwitch: '<S210>/Index Vector' */

    /* MultiPortSwitch: '<S210>/Index Vector1' incorporates:
     *  Constant: '<S210>/CRCTL_HOLD(=9h)'
     *  Constant: '<S210>/CRCTL_RESABV(=5h)'
     *  Logic: '<S210>/Logical Operator2'
     *  Logic: '<S210>/Logical Operator3'
     */
    if (!((!rtb_RelationalOperator_nx) || rtb_LogicalOperator1_dc)) {
      CrCtl_B.IndexVector1 = ((uint8_T)CRCTL_HOLD);
    } else {
      CrCtl_B.IndexVector1 = ((uint8_T)CRCTL_RESABV);
    }

    /* End of MultiPortSwitch: '<S210>/Index Vector1' */

    /* SignalConversion: '<S210>/OutportBufferForCrCtl_trqLead' */
    CrCtl_B.OutportBufferForCrCtl_trqLead = CrCtl_B.CrCtl_trqDes_In;
    CrCtl_B.OutportBufferForCrCtl_stActive = TRUE;
    CrCtl_B.OutportBufferForCrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);
    CrCtl_B.OutportBufferForCrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
    CrCtl_B.CrCtl_rVnBeg_In = CrCtl_B.IndexVector4;
    CrCtl_B.CrCtl_stLck_In = 0U;

    /* End of Outputs for SubSystem: '<S128>/CrCtl_State_TipDwn_SubCalcSet' */
  }

  /* End of SwitchCase: '<S128>/Switch Case' */

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_rVnBeg' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.CrCtl_rVnBeg_In;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_stActive' */
  CrCtl_stActive_BL = CrCtl_B.OutportBufferForCrCtl_stActive;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_stLck' */
  CrCtl_B.CrCtl_stLck = CrCtl_B.CrCtl_stLck_In;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_stMode1' */
  CrCtl_B.CrCtl_stMode = CrCtl_B.IndexVector1;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_stModeSub1' */
  CrCtl_B.CrCtl_stModeSub = CrCtl_B.OutportBufferForCrCtl_stModeSub;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_stOpFunc' */
  CrCtl_B.CrCtl_stOpFunc = CrCtl_B.OutportBufferForCrCtl_stOpFunc;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_trqDes' */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDes_In;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.OutportBufferForCrCtl_trqLead;

  /* SignalConversion: '<S128>/OutportBufferForCrCtl_vSetPointTrgt' */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_B.IndexVector;
}

/* Output and update for action system: '<S121>/CrCtl_State_Decl_SubStrtVal' */
void CrCtl_CrCtl_State_Decl_SubStrtVal(void)
{
  /* SignalConversion: '<S154>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S154>/PrpBrk_trqDes'
   */
  CrCtl_B.CrCtl_trqDes = PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S154>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S154>/PrpBrk_trqDes'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S154>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S154>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S154>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S154>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S154>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S154>/CRCTL_SUBRMP(=3h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);

  /* Inport: '<S154>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S154>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S154>/VSSCD_v' */
  CrCtl_vSetPointTrgt_10mphUW = VSSCD_v_10mphUW;

  /* Inport: '<S154>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S121>/CrCtl_State_Decl_SubRmp' */
void CrCtl_CrCtl_State_Decl_SubRmp(void)
{
  /* SignalConversion: '<S150>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S150>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S150>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S150>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* MultiPortSwitch: '<S150>/Index Vector' incorporates:
   *  Constant: '<S150>/CrCtl_facRmpSlpDecl_C_100mph'
   *  Constant: '<S150>/CrCtl_vDvtMaxAccDecl_C_10mph'
   *  Constant: '<S150>/T_ms'
   *  Logic: '<S150>/Logical Operator'
   *  Product: '<S150>/Divide'
   *  Product: '<S150>/Product1'
   *  RelationalOperator: '<S150>/Relational Operator'
   *  RelationalOperator: '<S150>/Relational Operator1'
   *  Sum: '<S150>/Add'
   *  Sum: '<S150>/Subtract'
   */
  if (!((CrCtl_B.CrCtl_trqDesIn_10mNm == -1L) || (CrCtl_vSetPointTrgtIn_10mphUW <
        ((int32_T)((int16_T)(VSSCD_v_10mphUW >> 1) -
                   (CrCtl_vDvtMaxAccDecl_C_10mph >> 1)) << 1)))) {
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)((int16_T)
      (CrCtl_vSetPointTrgtIn_10mphUW >> 1) - (div_nde_s16_floor
      (CrCtl_facRmpSlpDecl_C_100mph * ((uint8_T)T_ms), 100) >> 1)) << 1;
  } else {
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
  }

  /* End of MultiPortSwitch: '<S150>/Index Vector' */

  /* Switch: '<S157>/Switch2' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S150>/CrCtl_vMin_C_10mph'
   *  RelationalOperator: '<S157>/LowerRelop1'
   *  RelationalOperator: '<S157>/UpperRelop'
   *  Switch: '<S157>/Switch'
   */
  if (CrCtl_vSetPointTrgt_10mphUW > 30000U) {
    CrCtl_vSetPointTrgt_10mphUW = 30000U;
  } else {
    if ((int16_T)CrCtl_vSetPointTrgt_10mphUW < CrCtl_vMin_C_10mph) {
      /* Switch: '<S157>/Switch' incorporates:
       *  Constant: '<S150>/CrCtl_vMin_C_10mph'
       */
      CrCtl_vSetPointTrgt_10mphUW = (uint16_T)CrCtl_vMin_C_10mph;
    }
  }

  /* End of Switch: '<S157>/Switch2' */

  /* SignalConversion: '<S150>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp_en = CrCtl_vSetPointTrgt_10mphUW;

  /* SignalConversion: '<S150>/OutportBufferForCrCtl_trqDes' */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S150>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* Inport: '<S150>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S150>/CrCtl_stModeSub_In' */
  CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;

  /* Inport: '<S150>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S150>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S121>/CrCtl_State_Decl_SubRmpEnd' */
void CrCtl_CrCtl_State_Decl_SubRmpEnd(void)
{
  int16_T tmp;

  /* MultiPortSwitch: '<S151>/Index Vector1' incorporates:
   *  Constant: '<S151>/CrCtl_aDeclThres_C_10mmps2'
   *  RelationalOperator: '<S151>/Relational Operator'
   */
  if (!(CrCtl_B.Diff >= CrCtl_aDeclThres_C_10mmps2)) {
    /* SignalConversion: '<S151>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S151>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S151>/CRCTL_SUBPREPHOLD(=5h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBPREPHOLD);
  } else {
    /* SignalConversion: '<S151>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S151>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S151>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S151>/CRCTL_SUBSTRTVAL(=8h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S151>/Index Vector1' */

  /* MinMax: '<S151>/MinMax' */
  if (CrCtl_B.Diff < 0) {
    tmp = CrCtl_B.Diff;
  } else {
    tmp = 0;
  }

  /* End of MinMax: '<S151>/MinMax' */

  /* Sum: '<S151>/Subtract' incorporates:
   *  Constant: '<S151>/CrCtl_trqCorDecl_C_mNmp10mmps2'
   *  Gain: '<S151>/Gain'
   *  Product: '<S151>/Product1'
   */
  CrCtl_B.CrCtl_trqDes = (int32_T)-tmp * CrCtl_trqCorDecl_C_mNmp10mmps2 +
    CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S151>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S151>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S151>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S151>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S151>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Switch: '<S162>/Switch2' incorporates:
   *  Constant: '<S151>/CrCtl_vMax_C_10mph'
   *  Constant: '<S151>/CrCtl_vMin_C_10mph'
   *  RelationalOperator: '<S162>/LowerRelop1'
   *  RelationalOperator: '<S162>/UpperRelop'
   *  Switch: '<S162>/Switch'
   */
  if ((int32_T)VSSCD_v_10mphUW > CrCtl_vMax_C_10mph) {
    /* SignalConversion: '<S151>/OutportBufferForCrCtl_vSetPointTrgt' */
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)CrCtl_vMax_C_10mph;
  } else if ((int32_T)VSSCD_v_10mphUW < CrCtl_vMin_C_10mph) {
    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S151>/CrCtl_vMin_C_10mph'
     *  SignalConversion: '<S151>/OutportBufferForCrCtl_vSetPointTrgt'
     */
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)CrCtl_vMin_C_10mph;
  } else {
    /* SignalConversion: '<S151>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
     *  Switch: '<S162>/Switch'
     */
    CrCtl_vSetPointTrgt_10mphUW = VSSCD_v_10mphUW;
  }

  /* End of Switch: '<S162>/Switch2' */

  /* Inport: '<S151>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S151>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S121>/CrCtl_State_Decl_SubRmpHold' */
void CrCtl_CrCtl_State_Decl_SubRmpHold(void)
{
  int16_T rtb_IndexVector_j1;

  /* Sum: '<S152>/Subtract' incorporates:
   *  Constant: '<S152>/CrCtl_vMaxDvtDecl_C_10mph'
   *  Inport: '<S152>/CrCtl_vSetPointTrgt_In'
   */
  rtb_IndexVector_j1 = (int16_T)(CrCtl_vSetPointTrgtIn_10mphUW >> 1) -
    (CrCtl_vMaxDvtDecl_C_10mph >> 1);

  /* MultiPortSwitch: '<S152>/Index Vector1' incorporates:
   *  Constant: '<S152>/CrCtl_aDeclThres_C_10mmps2'
   *  Logic: '<S152>/Logical Operator'
   *  RelationalOperator: '<S152>/Relational Operator1'
   *  RelationalOperator: '<S152>/Relational Operator2'
   */
  if (!((VSSCD_v_10mphUW > ((int32_T)rtb_IndexVector_j1 << 1)) && (CrCtl_B.Diff >=
        CrCtl_aDeclThres_C_10mmps2))) {
    /* SignalConversion: '<S152>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S152>/OutportBufferForCrCtl_stModeSub' */
    CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
  } else {
    /* SignalConversion: '<S152>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S152>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S152>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S152>/CRCTL_SUBSTRTVAL(=2h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S152>/Index Vector1' */

  /* MultiPortSwitch: '<S152>/Index Vector' incorporates:
   *  Constant: '<S152>/CrCtl_facRmpSlpHiDecl_C'
   *  Gain: '<S152>/Gain'
   *  RelationalOperator: '<S152>/Relational Operator'
   */
  if (!(VSSCD_v_10mphUW < ((int32_T)rtb_IndexVector_j1 << 1))) {
    rtb_IndexVector_j1 = CrCtl_facRmpSlpHiDecl_C;
  } else {
    rtb_IndexVector_j1 = CrCtl_facRmpSlpHiDecl_C << 1;
  }

  /* End of MultiPortSwitch: '<S152>/Index Vector' */

  /* Sum: '<S152>/Add' incorporates:
   *  Constant: '<S152>/T_ms'
   *  Product: '<S152>/Divide'
   *  Product: '<S152>/Product'
   */
  CrCtl_B.CrCtl_trqDes = div_nde_s32_floor((int32_T)rtb_IndexVector_j1 *
    ((uint8_T)T_ms), 10L) + CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S152>/OutportBufferForCrCtl_trqLead_10mNm' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S152>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S152>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S152>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S152>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S152>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S152>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Inport: '<S152>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S152>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S121>/CrCtl_State_Decl_SubSetEnd' */
void CrCtl_CrCtl_State_Decl_SubSetEnd(void)
{
  /* SignalConversion: '<S153>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S153>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S153>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S153>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S153>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S153>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S153>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S153>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S153>/OutportBufferForCrCtl_stMode' incorporates:
   *  Constant: '<S153>/CRCTL_HOLD(=9h)'
   */
  CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

  /* SignalConversion: '<S153>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S153>/CRCTL_SUBSTRTVAL(=2h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);

  /* Inport: '<S153>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S153>/VSSCD_v' */
  CrCtl_vSetPointTrgt_10mphUW = VSSCD_v_10mphUW;

  /* Inport: '<S153>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_Decl' */
void CrCtl_CrCtl_State_Decl(void)
{
  /* SwitchCase: '<S121>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S121>/CrCtl_State_Decl_SubStrtVal' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    CrCtl_CrCtl_State_Decl_SubStrtVal();

    /* End of Outputs for SubSystem: '<S121>/CrCtl_State_Decl_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S121>/CrCtl_State_Decl_SubRmp' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    CrCtl_CrCtl_State_Decl_SubRmp();

    /* End of Outputs for SubSystem: '<S121>/CrCtl_State_Decl_SubRmp' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S121>/CrCtl_State_Decl_SubRmpEnd' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    CrCtl_CrCtl_State_Decl_SubRmpEnd();

    /* End of Outputs for SubSystem: '<S121>/CrCtl_State_Decl_SubRmpEnd' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S121>/CrCtl_State_Decl_SubRmpHold' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    CrCtl_CrCtl_State_Decl_SubRmpHold();

    /* End of Outputs for SubSystem: '<S121>/CrCtl_State_Decl_SubRmpHold' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S121>/CrCtl_State_Decl_SubSetEnd' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    CrCtl_CrCtl_State_Decl_SubSetEnd();

    /* End of Outputs for SubSystem: '<S121>/CrCtl_State_Decl_SubSetEnd' */
    break;
  }

  /* End of SwitchCase: '<S121>/Switch Case' */

  /* SignalConversion: '<S121>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_vSetPointAct_mp_10mphUW =
    CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp_en;
}

/* Output and update for action system: '<S126>/CrCtl_State_ResAbv_SubStrtVal' */
void CrCtl_CrCtl_State_ResAbv_SubStrtVal(void)
{
  /* MinMax: '<S185>/MinMax' incorporates:
   *  Inport: '<S185>/CrCtl_vSetPointTrgt_In'
   */
  if (VSSCD_v_10mphUW > CrCtl_vSetPointTrgtIn_10mphUW) {
    CrCtl_B.Merge9_m = VSSCD_v_10mphUW;
  } else {
    CrCtl_B.Merge9_m = CrCtl_vSetPointTrgtIn_10mphUW;
  }

  /* End of MinMax: '<S185>/MinMax' */

  /* Switch: '<S193>/Switch2' incorporates:
   *  Constant: '<S185>/12000'
   *  RelationalOperator: '<S193>/LowerRelop1'
   */
  if ((int32_T)CrCtl_B.Merge9_m > CrCtl_vMax_C_10mph) {
    /* SignalConversion: '<S185>/OutportBufferForCrCtl_vSetPointAct_mp' */
    CrCtl_B.Merge9_m = (uint16_T)CrCtl_vMax_C_10mph;
  }

  /* End of Switch: '<S193>/Switch2' */

  /* SignalConversion: '<S185>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S185>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* Sum: '<S185>/Subtract1' incorporates:
   *  Constant: '<S185>/CrCtl_trqOfsResAbv_C'
   *  Lookup_n-D: '<S185>/CrCtl_trqVCorResAbv_CUR'
   *  Sum: '<S185>/Subtract'
   */
  CrCtl_B.CrCtl_trqDes = (PrpBrk_trqDes_10mNmL - look1_iu16lu32n16_binlcse
    (VSSCD_v_10mphUW, CrCtl_ConstP.pooled6, CrCtl_ConstP.pooled6, 200UL)) -
    CrCtl_trqOfsResAbv_C;

  /* SignalConversion: '<S185>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S185>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S185>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S185>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S185>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S185>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S185>/CRCTL_SUBRMP(=3h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);

  /* Inport: '<S185>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S185>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S185>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S126>/CrCtl_State_ResAbv_SubRmp' */
void CrCtl_CrCtl_State_ResAbv_SubRmp(void)
{
  uint8_T tmp;

  /* MultiPortSwitch: '<S184>/Index Vector' incorporates:
   *  Inport: '<S184>/CrCtl_vSetPointTrgt_In'
   *  RelationalOperator: '<S184>/Relational Operator2'
   */
  if (!(VSSCD_v_10mphUW <= CrCtl_vSetPointTrgtIn_10mphUW)) {
    /* SignalConversion: '<S184>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S184>/OutportBufferForCrCtl_stModeSub' */
    CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
  } else {
    /* SignalConversion: '<S184>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S184>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S184>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S184>/CRCTL_SUBSTRTVAL(=2h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S184>/Index Vector' */

  /* MultiPortSwitch: '<S184>/Index Vector1' incorporates:
   *  Constant: '<S184>/CrCtl_facRmpSlpRes_C_100mphps'
   *  Constant: '<S184>/CrCtl_vMaxDvtResAbv_C'
   *  Inport: '<S184>/CrCtl_vSetPointTrgt_In'
   *  Product: '<S184>/Divide'
   *  RelationalOperator: '<S184>/Relational Operator1'
   *  Sum: '<S184>/Subtract2'
   */
  if (!(VSSCD_v_10mphUW < CrCtl_vSetPointTrgtIn_10mphUW + CrCtl_vMaxDvtResAbv_C))
  {
    tmp = CrCtl_facRmpSlpRes_C_100mphps;
  } else {
    tmp = (uint8_T)((uint16_T)CrCtl_facRmpSlpRes_C_100mphps >> 1);
  }

  /* End of MultiPortSwitch: '<S184>/Index Vector1' */

  /* Sum: '<S184>/Subtract1' incorporates:
   *  Constant: '<S184>/T_ms'
   *  Product: '<S184>/Divide1'
   *  Product: '<S184>/VSSCD_v_delta'
   */
  CrCtl_B.Merge9_m = CrCtl_B.Memory_c - (uint16_T)tmp * ((uint8_T)T_ms) / 100U;

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S184>/Constant'
   *  Inport: '<S184>/CrCtl_vSetPointTrgt_In'
   *  RelationalOperator: '<S188>/LowerRelop1'
   *  RelationalOperator: '<S188>/UpperRelop'
   *  Switch: '<S188>/Switch'
   */
  if (CrCtl_B.Merge9_m > 30000U) {
    /* SignalConversion: '<S184>/OutportBufferForCrCtl_vSetPoinAct_mp' */
    CrCtl_B.Merge9_m = 30000U;
  } else {
    if (CrCtl_B.Merge9_m < CrCtl_vSetPointTrgtIn_10mphUW) {
      /* Switch: '<S188>/Switch' incorporates:
       *  Inport: '<S184>/CrCtl_vSetPointTrgt_In'
       *  SignalConversion: '<S184>/OutportBufferForCrCtl_vSetPoinAct_mp'
       */
      CrCtl_B.Merge9_m = CrCtl_vSetPointTrgtIn_10mphUW;
    }
  }

  /* End of Switch: '<S188>/Switch2' */

  /* SignalConversion: '<S184>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S184>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S184>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S184>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S184>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S184>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S184>/OutportBufferForCrCtl_trqDes' */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S184>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* Inport: '<S184>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S184>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* System initialize for action system: '<S4>/CrCtl_State_ResAbv' */
void CrCtl_CrCtl_State_ResAbv_Init(void)
{
  /* SystemInitialize for Merge: '<S126>/Merge9' */
  CrCtl_B.Merge9_m = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_ResAbv' */
void CrCtl_CrCtl_State_ResAbv(void)
{
  /* SwitchCase: '<S126>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S126>/CrCtl_State_ResAbv_SubStrtVal' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    CrCtl_CrCtl_State_ResAbv_SubStrtVal();

    /* End of Outputs for SubSystem: '<S126>/CrCtl_State_ResAbv_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S126>/CrCtl_State_ResAbv_SubRmp' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    CrCtl_CrCtl_State_ResAbv_SubRmp();

    /* End of Outputs for SubSystem: '<S126>/CrCtl_State_ResAbv_SubRmp' */
    break;
  }

  /* End of SwitchCase: '<S126>/Switch Case' */

  /* SignalConversion: '<S126>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_vSetPointAct_mp_10mphUW = CrCtl_B.Merge9_m;
}

/* Output and update for action system: '<S127>/CrCtl_State_ResBlw_SubStrtVal' */
void CrCtl_CrCtl_State_ResBlw_SubStrtVal(void)
{
  /* MinMax: '<S196>/MinMax' incorporates:
   *  Inport: '<S196>/CrCtl_vSetPointTrgt_In'
   */
  if (VSSCD_v_10mphUW < CrCtl_vSetPointTrgtIn_10mphUW) {
    CrCtl_B.CrCtl_vSetPointAct_mp = VSSCD_v_10mphUW;
  } else {
    CrCtl_B.CrCtl_vSetPointAct_mp = CrCtl_vSetPointTrgtIn_10mphUW;
  }

  /* End of MinMax: '<S196>/MinMax' */

  /* Switch: '<S209>/Switch' incorporates:
   *  Constant: '<S196>/CrCtl_vMin_C_10mph'
   *  RelationalOperator: '<S209>/UpperRelop'
   *  Switch: '<S209>/Switch2'
   */
  if ((int32_T)CrCtl_B.CrCtl_vSetPointAct_mp < CrCtl_vMin_C_10mph) {
    /* SignalConversion: '<S196>/OutportBufferForCrCtl_vSetPointAct_mp' */
    CrCtl_B.CrCtl_vSetPointAct_mp = (uint16_T)CrCtl_vMin_C_10mph;
  }

  /* End of Switch: '<S209>/Switch' */

  /* SignalConversion: '<S196>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S196>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* Sum: '<S196>/Subtract1' incorporates:
   *  Constant: '<S196>/CrCtl_trqOfsResBlw_C'
   *  Lookup_n-D: '<S196>/CrCtl_trqVCorResBlw_CUR'
   *  Sum: '<S196>/Subtract'
   */
  CrCtl_B.CrCtl_trqDes = (PrpBrk_trqDes_10mNmL + look1_iu16lu32n16_binlcse
    (VSSCD_v_10mphUW, CrCtl_ConstP.pooled6, CrCtl_ConstP.pooled6, 200UL)) +
    CrCtl_trqOfsResBlw_C;

  /* SignalConversion: '<S196>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S196>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S196>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S196>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S196>/CRCTL_SUBRMP(=3h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);

  /* Inport: '<S196>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S196>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S196>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S127>/CrCtl_State_ResBlw_SubRmp' */
void CrCtl_CrCtl_State_ResBlw_SubRmp(void)
{
  uint8_T tmp;

  /* SignalConversion: '<S195>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S195>/CRCTL_ACTV_1h'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* MultiPortSwitch: '<S195>/Index Vector5' incorporates:
   *  Constant: '<S195>/T_ms'
   *  Product: '<S195>/Divide'
   *  Product: '<S195>/VSSCD_v_delta1'
   *  RelationalOperator: '<S195>/Relational Operator4'
   *  Sum: '<S195>/Add'
   */
  if (!(CrCtl_B.CrCtl_trqDesIn_10mNm >= CrCtl_B.Gain)) {
    /* MultiPortSwitch: '<S195>/Index Vector4' incorporates:
     *  Constant: '<S195>/CrCtl_facRmpSlpRes_C_100mphps'
     *  Constant: '<S195>/CrCtl_vMaxDvtResBlw_C_10mph'
     *  Inport: '<S195>/CrCtl_vSetPointTrgt_In'
     *  Product: '<S195>/Divide1'
     *  RelationalOperator: '<S195>/Relational Operator'
     *  Sum: '<S195>/Subtract'
     */
    if (!(CrCtl_B.Memory1 > CrCtl_vSetPointTrgtIn_10mphUW -
          CrCtl_vMaxDvtResBlw_C_10mph)) {
      tmp = CrCtl_facRmpSlpRes_C_100mphps;
    } else {
      tmp = (uint8_T)((uint16_T)CrCtl_facRmpSlpRes_C_100mphps >> 1);
    }

    /* End of MultiPortSwitch: '<S195>/Index Vector4' */
    CrCtl_B.CrCtl_vSetPointAct_mp = (uint16_T)tmp * ((uint8_T)T_ms) / 100U +
      CrCtl_B.Memory1;
  } else {
    CrCtl_B.CrCtl_vSetPointAct_mp = CrCtl_B.Memory1;
  }

  /* End of MultiPortSwitch: '<S195>/Index Vector5' */

  /* MultiPortSwitch: '<S195>/Index Vector6' incorporates:
   *  Constant: '<S195>/CRCTL_SUBPREPHOLD(=5h)'
   *  Inport: '<S195>/CrCtl_vSetPointTrgt_In'
   *  Logic: '<S195>/Logical Operator'
   *  RelationalOperator: '<S195>/Relational Operator1'
   *  RelationalOperator: '<S195>/Relational Operator5'
   */
  if (!((CrCtl_B.Memory1 >= CrCtl_vSetPointTrgtIn_10mphUW) || (VSSCD_v_10mphUW >=
        CrCtl_vSetPointTrgtIn_10mphUW))) {
    CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
  } else {
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBPREPHOLD);
  }

  /* End of MultiPortSwitch: '<S195>/Index Vector6' */

  /* SignalConversion: '<S195>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S195>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S195>/OutportBufferForCrCtl_trqDes' */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S195>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* Inport: '<S195>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S195>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S195>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S127>/CrCtl_State_ResBlw_SubPrepHold' */
void CrCtl_CrCtl_State_ResBlw_SubPrepHold(void)
{
  /* MultiPortSwitch: '<S194>/Index Vector' incorporates:
   *  Inport: '<S194>/CrCtl_vSetPointTrgt_In'
   *  RelationalOperator: '<S194>/Relational Operator'
   */
  if (!(VSSCD_v_10mphUW >= CrCtl_vSetPointTrgtIn_10mphUW)) {
    /* SignalConversion: '<S194>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S194>/OutportBufferForCrCtl_stModeSub' */
    CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
  } else {
    /* SignalConversion: '<S194>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S194>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S194>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S194>/CRCTL_SUBSTRTVAL(=2h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S194>/Index Vector' */

  /* SignalConversion: '<S194>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S194>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S194>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S194>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S194>/OutportBufferForCrCtl_trqDes' */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SignalConversion: '<S194>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* Inport: '<S194>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S194>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;

  /* Inport: '<S194>/CrCtl_vSetPointAct_mp_In' */
  CrCtl_B.CrCtl_vSetPointAct_mp = CrCtl_B.Memory1;
}

/* System initialize for action system: '<S4>/CrCtl_State_ResBlw' */
void CrCtl_CrCtl_State_ResBlw_Init(void)
{
  /* SystemInitialize for Merge: '<S127>/Merge6' */
  CrCtl_B.CrCtl_vSetPointAct_mp = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_ResBlw' */
void CrCtl_CrCtl_State_ResBlw(void)
{
  /* SignalConversion: '<S127>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S127>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SwitchCase: '<S127>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S127>/CrCtl_State_ResBlw_SubStrtVal' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    CrCtl_CrCtl_State_ResBlw_SubStrtVal();

    /* End of Outputs for SubSystem: '<S127>/CrCtl_State_ResBlw_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S127>/CrCtl_State_ResBlw_SubRmp' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    CrCtl_CrCtl_State_ResBlw_SubRmp();

    /* End of Outputs for SubSystem: '<S127>/CrCtl_State_ResBlw_SubRmp' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S127>/CrCtl_State_ResBlw_SubPrepHold' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    CrCtl_CrCtl_State_ResBlw_SubPrepHold();

    /* End of Outputs for SubSystem: '<S127>/CrCtl_State_ResBlw_SubPrepHold' */
    break;
  }

  /* End of SwitchCase: '<S127>/Switch Case' */

  /* SignalConversion: '<S127>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_vSetPointAct_mp_10mphUW = CrCtl_B.CrCtl_vSetPointAct_mp;
}

/* Output and update for action system: '<S4>/CrCtl_State_TipUp' */
void CrCtl_CrCtl_State_TipUp(void)
{
  boolean_T rtb_LogicalOperator1_hm;
  boolean_T rtb_RelationalOperator1_f;

  /* RelationalOperator: '<S129>/Relational Operator1' incorporates:
   *  Constant: '<S129>/2000'
   *  Sum: '<S129>/Subtract1'
   */
  rtb_RelationalOperator1_f = (VSSCD_v_10mphUW >= ((int32_T)((int16_T)
    (CrCtl_vSetPointTrgtIn_10mphUW >> 1) - (CrCtl_vTipUpLoLim_C_10mph >> 1)) <<
    1));

  /* Logic: '<S129>/Logical Operator1' incorporates:
   *  Constant: '<S129>/02000'
   *  Constant: '<S129>/100'
   *  Constant: '<S129>/10000'
   *  Inport: '<S129>/CrCtl_trqDes_In'
   *  Logic: '<S129>/Logical Operator'
   *  RelationalOperator: '<S129>/Relational Operator'
   *  RelationalOperator: '<S129>/Relational Operator2'
   *  RelationalOperator: '<S129>/Relational Operator3'
   *  Sum: '<S129>/Subtract'
   *  Sum: '<S129>/Subtract2'
   */
  rtb_LogicalOperator1_hm = ((VSSCD_v_10mphUW <= ((int32_T)((int16_T)
    (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vTipUpUpLim_C_10mph >> 1)) <<
    1)) && rtb_RelationalOperator1_f && (((int32_T)((int16_T)
    (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vTipStp_C_10mph >> 1)) << 1) <
    CrCtl_vMax_C_10mph) && (CrCtl_B.CrCtl_trqDesIn_10mNm < CrCtl_B.Gain));

  /* MultiPortSwitch: '<S129>/Index Vector' incorporates:
   *  Constant: '<S129>/100'
   *  Sum: '<S129>/Subtract3'
   */
  if (!rtb_LogicalOperator1_hm) {
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
  } else {
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)((int16_T)
      (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vTipStp_C_10mph >> 1)) << 1;
  }

  /* End of MultiPortSwitch: '<S129>/Index Vector' */

  /* MultiPortSwitch: '<S129>/Index Vector1' incorporates:
   *  Constant: '<S129>/CRCTL_HOLD_9h'
   *  Constant: '<S129>/CRCTL_RESBLW(=6h)'
   *  Logic: '<S129>/Logical Operator2'
   *  Logic: '<S129>/Logical Operator3'
   */
  if (!((!rtb_RelationalOperator1_f) || rtb_LogicalOperator1_hm)) {
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);
  } else {
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_RESBLW);
  }

  /* End of MultiPortSwitch: '<S129>/Index Vector1' */

  /* SignalConversion: '<S129>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S129>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S129>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S129>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S129>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S129>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S129>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S129>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S129>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S129>/CRCTL_SUBSTRTVAL(=2h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);

  /* Inport: '<S129>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S129>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S120>/CrCtl_State_Acc_SubStrtVal' */
void CrCtl_CrCtl_State_Acc_SubStrtVal(void)
{
  /* Sum: '<S140>/Subtract1' incorporates:
   *  Constant: '<S140>/CrCtl_facTrqStrtAcc_C_100mNmpkmph'
   *  Constant: '<S140>/CrCtl_trqStrtAccOfs_C_10mNm'
   *  Inport: '<S140>/VSSCD_v_10mph'
   *  Product: '<S140>/Divide'
   *  Product: '<S140>/Product'
   *  Sum: '<S140>/Subtract'
   */
  CrCtl_B.CrCtl_trqDes = div_nde_s32_floor((int32_T)VSSCD_v_10mphUW *
    CrCtl_facTrqStrtAcc_C_100mNmpkmph + CrCtl_trqStrtAccOfs_C_10mNm, 10L) +
    PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S140>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S140>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S140>/VSSCD_v_10mph'
   */
  CrCtl_vSetPointTrgt_10mphUW = VSSCD_v_10mphUW;

  /* SignalConversion: '<S140>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S140>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S140>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S140>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S140>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S140>/CRCTL_SUBRMP(=3h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);

  /* Inport: '<S140>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S140>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S140>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S120>/CrCtl_State_Acc_SubRmp' */
void CrCtl_CrCtl_State_Acc_SubRmp(void)
{
  /* MultiPortSwitch: '<S138>/Index Vector1' incorporates:
   *  Constant: '<S138>/200'
   *  RelationalOperator: '<S138>/Relational Operator'
   *  Sum: '<S138>/Add'
   */
  if (!(CrCtl_vSetPointTrgtIn_10mphUW > ((int32_T)((int16_T)(VSSCD_v_10mphUW >>
          1) + (CrCtl_vDvtMaxAccDecl_C_10mph >> 1)) << 1))) {
    /* MultiPortSwitch: '<S138>/Index Vector' incorporates:
     *  Constant: '<S138>/12000'
     *  Constant: '<S138>/30'
     *  Constant: '<S138>/T_ms'
     *  Logic: '<S138>/Logical Operator'
     *  Product: '<S138>/Divide'
     *  Product: '<S138>/Product'
     *  RelationalOperator: '<S138>/Relational Operator1'
     *  RelationalOperator: '<S138>/Relational Operator2'
     *  Sum: '<S138>/Add1'
     */
    if (!((CrCtl_B.CrCtl_trqDesIn_10mNm < CrCtl_B.Gain) && ((int32_T)
          CrCtl_vSetPointTrgtIn_10mphUW < CrCtl_vMax_C_10mph))) {
      CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
    } else {
      CrCtl_vSetPointTrgt_10mphUW = (uint16_T)((div_nde_s16_floor
        (CrCtl_facRmpSlpAcc_C_100mphps * ((uint8_T)T_ms), 100) >> 1) + (int16_T)
        (CrCtl_vSetPointTrgtIn_10mphUW >> 1)) << 1;
    }

    /* End of MultiPortSwitch: '<S138>/Index Vector' */
  } else {
    CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;
  }

  /* End of MultiPortSwitch: '<S138>/Index Vector1' */

  /* SignalConversion: '<S138>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp_e = CrCtl_vSetPointTrgt_10mphUW;

  /* Switch: '<S144>/Switch2' incorporates:
   *  RelationalOperator: '<S144>/LowerRelop1'
   */
  if (0L > CrCtl_B.Gain) {
    CrCtl_B.CrCtl_trqDes = CrCtl_B.Gain;
  } else {
    CrCtl_B.CrCtl_trqDes = CrCtl_ConstB.Switch_i;
  }

  /* End of Switch: '<S144>/Switch2' */

  /* SignalConversion: '<S138>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S138>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S138>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S138>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S138>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Inport: '<S138>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S138>/CrCtl_stModeSub_In' */
  CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;

  /* Inport: '<S138>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S138>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S120>/CrCtl_State_Acc_SubRmpEnd' */
void CrCtl_CrCtl_State_Acc_SubRmpEnd(void)
{
  int16_T tmp;

  /* MultiPortSwitch: '<S139>/Index Vector' incorporates:
   *  Constant: '<S139>/CrCtl_aAccThres_C_10mmps2'
   *  RelationalOperator: '<S139>/Relational Operator'
   */
  if (!(CrCtl_B.Diff <= CrCtl_aAccThres_C_10mmps2)) {
    /* SignalConversion: '<S139>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S139>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S139>/CRCTL_SUBPREPHOLD(=5h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBPREPHOLD);
  } else {
    /* SignalConversion: '<S139>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S139>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S139>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S139>/CRCTL_SUBSTRTVAL(=2h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S139>/Index Vector' */

  /* MinMax: '<S139>/MinMax' */
  if (CrCtl_B.Diff > 0) {
    tmp = CrCtl_B.Diff;
  } else {
    tmp = 0;
  }

  /* End of MinMax: '<S139>/MinMax' */

  /* Sum: '<S139>/Subtract' incorporates:
   *  Constant: '<S139>/CrCtl_trqCorAcc_C_Nmp10mmps2'
   *  Product: '<S139>/Product'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm - (int32_T)tmp *
    CrCtl_trqCorAcc_C_Nmp10mmps2;

  /* SignalConversion: '<S139>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S139>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S139>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S139>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S139>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Switch: '<S149>/Switch2' incorporates:
   *  Constant: '<S139>/CrCtl_vMax_C_10mph'
   *  Constant: '<S139>/CrCtl_vMin_C_10mph'
   *  RelationalOperator: '<S149>/LowerRelop1'
   *  RelationalOperator: '<S149>/UpperRelop'
   *  Switch: '<S149>/Switch'
   */
  if ((int32_T)VSSCD_v_10mphUW > CrCtl_vMax_C_10mph) {
    /* SignalConversion: '<S139>/OutportBufferForCrCtl_vSetPointTrgt' */
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)CrCtl_vMax_C_10mph;
  } else if ((int32_T)VSSCD_v_10mphUW < CrCtl_vMin_C_10mph) {
    /* Switch: '<S149>/Switch' incorporates:
     *  Constant: '<S139>/CrCtl_vMin_C_10mph'
     *  SignalConversion: '<S139>/OutportBufferForCrCtl_vSetPointTrgt'
     */
    CrCtl_vSetPointTrgt_10mphUW = (uint16_T)CrCtl_vMin_C_10mph;
  } else {
    /* SignalConversion: '<S139>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
     *  Switch: '<S149>/Switch'
     */
    CrCtl_vSetPointTrgt_10mphUW = VSSCD_v_10mphUW;
  }

  /* End of Switch: '<S149>/Switch2' */

  /* Inport: '<S139>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S139>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S120>/CrCtl_State_Acc_SubPrepHold' */
void CrCtl_CrCtl_State_Acc_SubPrepHold(void)
{
  boolean_T rtb_RelationalOperator_j0;
  int16_T rtb_RelationalOperator_la;

  /* RelationalOperator: '<S137>/Relational Operator' incorporates:
   *  Constant: '<S137>/CrCtl_vMaxDvtAcc_C_10mph'
   *  Inport: '<S137>/CrCtl_vSetPointTrgt_In'
   *  Sum: '<S137>/Add'
   */
  rtb_RelationalOperator_j0 = (VSSCD_v_10mphUW > ((int32_T)((int16_T)
    (CrCtl_vSetPointTrgtIn_10mphUW >> 1) + (CrCtl_vMaxDvtAcc_C_10mph >> 1)) << 1));

  /* MultiPortSwitch: '<S137>/Index Vector1' incorporates:
   *  Constant: '<S137>/100'
   *  Logic: '<S137>/Logical Operator'
   *  Logic: '<S137>/Logical Operator1'
   *  RelationalOperator: '<S137>/Relational Operator1'
   */
  if (!((!rtb_RelationalOperator_j0) && (CrCtl_B.Diff <=
        CrCtl_aAccThres_C_10mmps2))) {
    /* SignalConversion: '<S137>/OutportBufferForCrCtl_stMode' */
    CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

    /* SignalConversion: '<S137>/OutportBufferForCrCtl_stModeSub' */
    CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
  } else {
    /* SignalConversion: '<S137>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S137>/CRCTL_HOLD(=9h)'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_HOLD);

    /* SignalConversion: '<S137>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S137>/CRCTL_SUBSTRTVAL(=2h)'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
  }

  /* End of MultiPortSwitch: '<S137>/Index Vector1' */

  /* MultiPortSwitch: '<S137>/Index Vector' incorporates:
   *  Constant: '<S137>/CrCtl_facRmpSlpHiAcc_C_Nmps'
   *  Gain: '<S137>/Gain'
   */
  if (!rtb_RelationalOperator_j0) {
    rtb_RelationalOperator_la = CrCtl_facRmpSlpHiAcc_C_Nmps;
  } else {
    rtb_RelationalOperator_la = CrCtl_facRmpSlpHiAcc_C_Nmps << 1;
  }

  /* End of MultiPortSwitch: '<S137>/Index Vector' */

  /* Sum: '<S137>/Subtract' incorporates:
   *  Constant: '<S137>/T_ms'
   *  Product: '<S137>/Divide'
   *  Product: '<S137>/Product'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm - div_nde_s32_floor
    ((int32_T)rtb_RelationalOperator_la * ((uint8_T)T_ms), 1000L);

  /* SignalConversion: '<S137>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S137>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S137>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S137>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S137>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S137>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S137>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Inport: '<S137>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S137>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S120>/CrCtl_State_Acc_SubWaitRes' */
void CrCtl_CrCtl_State_Acc_SubWaitRes(void)
{
  /* SignalConversion: '<S141>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S141>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S141>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S141>/CrCtl_trqDes_In'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDesIn_10mNm;

  /* SignalConversion: '<S141>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S141>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S141>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S141>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* MultiPortSwitch: '<S141>/Index Vector' incorporates:
   *  Constant: '<S141>/CRCTL_RESABV(=5h)'
   *  Constant: '<S141>/CRCTL_RESBLW(=6h)'
   *  Inport: '<S141>/CrCtl_vSetPointTrgt_In'
   *  RelationalOperator: '<S141>/Relational Operator'
   */
  if (!(VSSCD_v_10mphUW > CrCtl_vSetPointTrgtIn_10mphUW)) {
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_RESBLW);
  } else {
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_RESABV);
  }

  /* End of MultiPortSwitch: '<S141>/Index Vector' */

  /* SignalConversion: '<S141>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S141>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S141>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S141>/CRCTL_SUBSTRTVAL (=2h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);

  /* Inport: '<S141>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S141>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_Acc' */
void CrCtl_CrCtl_State_Acc(void)
{
  /* SwitchCase: '<S120>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S120>/CrCtl_State_Acc_SubStrtVal' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    CrCtl_CrCtl_State_Acc_SubStrtVal();

    /* End of Outputs for SubSystem: '<S120>/CrCtl_State_Acc_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S120>/CrCtl_State_Acc_SubRmp' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    CrCtl_CrCtl_State_Acc_SubRmp();

    /* End of Outputs for SubSystem: '<S120>/CrCtl_State_Acc_SubRmp' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S120>/CrCtl_State_Acc_SubRmpEnd' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    CrCtl_CrCtl_State_Acc_SubRmpEnd();

    /* End of Outputs for SubSystem: '<S120>/CrCtl_State_Acc_SubRmpEnd' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S120>/CrCtl_State_Acc_SubPrepHold' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    CrCtl_CrCtl_State_Acc_SubPrepHold();

    /* End of Outputs for SubSystem: '<S120>/CrCtl_State_Acc_SubPrepHold' */
    break;

   case 9L:
    /* Outputs for IfAction SubSystem: '<S120>/CrCtl_State_Acc_SubWaitRes' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    CrCtl_CrCtl_State_Acc_SubWaitRes();

    /* End of Outputs for SubSystem: '<S120>/CrCtl_State_Acc_SubWaitRes' */
    break;
  }

  /* End of SwitchCase: '<S120>/Switch Case' */

  /* SignalConversion: '<S120>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_vSetPointAct_mp_10mphUW =
    CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp_e;
}

/* Output and update for action system: '<S122>/CrCtl_State_Hold_SubStrtVal' */
void CrCtl_CrCtl_State_Hold_SubStrtVal(void)
{
  /* Switch: '<S172>/Switch2' incorporates:
   *  RelationalOperator: '<S172>/LowerRelop1'
   *  RelationalOperator: '<S172>/UpperRelop'
   *  Switch: '<S172>/Switch'
   */
  if (PrpBrk_trqDes_10mNmL > CrCtl_B.Gain) {
    CrCtl_B.CrCtl_trqDes = CrCtl_B.Gain;
  } else if (PrpBrk_trqDes_10mNmL < -1L) {
    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    CrCtl_B.CrCtl_trqDes = -1L;
  } else {
    CrCtl_B.CrCtl_trqDes = PrpBrk_trqDes_10mNmL;
  }

  /* End of Switch: '<S172>/Switch2' */

  /* SignalConversion: '<S164>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S164>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S164>/CRCTL_STACTIVE'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S164>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S164>/CRCTL_ACTV_1h'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S164>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S164>/CRCTL_SUBGVNR_8h'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBGVNR);

  /* Inport: '<S164>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S164>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S164>/CrCtl_vSetPointTrgt_In' */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* Inport: '<S164>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S122>/CrCtl_State_Hold_SubGvnr' */
void CrCtl_CrCtl_State_Hold_SubGvnr(void)
{
  /* Switch: '<S167>/Switch2' incorporates:
   *  RelationalOperator: '<S167>/LowerRelop1'
   */
  if (0L > CrCtl_B.Gain) {
    CrCtl_B.CrCtl_trqDes = CrCtl_B.Gain;
  } else {
    CrCtl_B.CrCtl_trqDes = CrCtl_ConstB.Switch;
  }

  /* End of Switch: '<S167>/Switch2' */

  /* SignalConversion: '<S163>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S163>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S163>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S163>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S163>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S163>/OutportBufferForCrCtl_vSetPointTrgt' incorporates:
   *  Inport: '<S163>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_vSetPointTrgtIn_10mphUW;

  /* SignalConversion: '<S163>/OutportBufferForCrCtl_vSetPointAct_mp' incorporates:
   *  Inport: '<S163>/CrCtl_vSetPointTrgt_In'
   */
  CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp = CrCtl_vSetPointTrgtIn_10mphUW;

  /* Inport: '<S163>/CrCtl_stMode_In' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S163>/CrCtl_stModeSub_In' */
  CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;

  /* Inport: '<S163>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S163>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_Hold' */
void CrCtl_CrCtl_State_Hold(void)
{
  /* SwitchCase: '<S122>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S122>/CrCtl_State_Hold_SubStrtVal' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    CrCtl_CrCtl_State_Hold_SubStrtVal();

    /* End of Outputs for SubSystem: '<S122>/CrCtl_State_Hold_SubStrtVal' */
    break;

   case 8L:
    /* Outputs for IfAction SubSystem: '<S122>/CrCtl_State_Hold_SubGvnr' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    CrCtl_CrCtl_State_Hold_SubGvnr();

    /* End of Outputs for SubSystem: '<S122>/CrCtl_State_Hold_SubGvnr' */
    break;
  }

  /* End of SwitchCase: '<S122>/Switch Case' */

  /* SignalConversion: '<S122>/OutportBufferForCrCtl_vSetPointAct_mp' */
  CrCtl_vSetPointAct_mp_10mphUW = CrCtl_B.OutportBufferForCrCtl_vSetPointAct_mp;
}

/* Output and update for action system: '<S125>/CrCtl_State_PCC_SubStrtVal' */
void CrCtl_CrCtl_State_PCC_SubStrtVal(void)
{
  /* SignalConversion: '<S182>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S182>/PrpBrk_trqDes_10mNm'
   */
  CrCtl_B.CrCtl_trqDes = PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S182>/PrpBrk_trqDes_10mNm'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_trqPCCStrtVal' incorporates:
   *  Inport: '<S182>/PrpBrk_trqDes_10mNm'
   */
  CrCtl_B.OutportBufferForCrCtl_trqPCCStrtVal = PrpBrk_trqDes_10mNmL;

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S182>/CRCTL_STACTIVE'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S182>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_stModeSub' incorporates:
   *  Constant: '<S182>/CRCTL_SUBRMP(=3h)'
   */
  CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBRMP);

  /* SignalConversion: '<S182>/OutportBufferForCrCtl_clkPCCStrtVal' incorporates:
   *  Constant: '<S182>/Constant'
   */
  CrCtl_B.Merge9 = 0U;

  /* Inport: '<S182>/CrCtl_stModeIn' */
  CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

  /* Inport: '<S182>/CrCtl_rVnBegIn' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S182>/CrCtl_stLckIn' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Output and update for action system: '<S125>/CrCtl_State_PCC_SubRmp' */
void CrCtl_CrCtl_State_PCC_SubRmp(void)
{
  /* Sum: '<S181>/Add' incorporates:
   *  Constant: '<S181>/Constant'
   */
  CrCtl_B.Merge9 = CrCtl_B.Memory1_a + 1U;

  /* MultiPortSwitch: '<S181>/Index Vector2' */
  if (!CrCtl_B.LogicalOperator) {
    /* MultiPortSwitch: '<S181>/Index Vector' incorporates:
     *  Inport: '<Root>/CrCtl_tiPCCRmp_10msUW'
     *  RelationalOperator: '<S181>/Relational Operator1'
     */
    if (!(CrCtl_tiPCCRmp_10msUW <= CrCtl_B.Merge9)) {
      /* MultiPortSwitch: '<S181>/Index Vector3' incorporates:
       *  Logic: '<S181>/Logical Operator'
       *  Memory: '<S181>/Memory'
       *  Memory: '<S181>/Memory1'
       *  RelationalOperator: '<S181>/Relational Operator2'
       *  RelationalOperator: '<S181>/Relational Operator3'
       */
      if (!((CrCtl_tiPCCRmp_10msUW == CrCtl_DW.Memory_PreviousInput_l) &&
            (CrCtl_trqPCCReqin_10mNmSL == CrCtl_DW.Memory1_PreviousInput_c))) {
        /* SignalConversion: '<S181>/OutportBufferForCrCtl_stMode' */
        CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

        /* SignalConversion: '<S181>/OutportBufferForCrCtl_stModeSub' incorporates:
         *  Constant: '<S181>/CRCTL_SUBSTRTVAL(=2h)'
         */
        CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
      } else {
        /* SignalConversion: '<S181>/OutportBufferForCrCtl_stMode' */
        CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

        /* SignalConversion: '<S181>/OutportBufferForCrCtl_stModeSub' */
        CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
      }

      /* End of MultiPortSwitch: '<S181>/Index Vector3' */
    } else {
      /* SignalConversion: '<S181>/OutportBufferForCrCtl_stMode' */
      CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

      /* SignalConversion: '<S181>/OutportBufferForCrCtl_stModeSub' incorporates:
       *  Constant: '<S181>/CRCTL_SUBSETEND(=7h)'
       */
      CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSETEND);
    }

    /* End of MultiPortSwitch: '<S181>/Index Vector' */
  } else {
    /* SignalConversion: '<S181>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S181>/CRCTL_ACC_8h'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_ACC);

    /* SignalConversion: '<S181>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S181>/CRCTL_SUBWAITRES_9h'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBWAITRES);
  }

  /* End of MultiPortSwitch: '<S181>/Index Vector2' */

  /* MultiPortSwitch: '<S181>/Index Vector1' incorporates:
   *  Constant: '<S181>/T_ms'
   *  Inport: '<Root>/CrCtl_tiPCCRmp_10msUW'
   *  Product: '<S181>/Divide'
   *  Product: '<S181>/Product1'
   *  Product: '<S181>/Product2'
   *  Product: '<S181>/Product3'
   *  RelationalOperator: '<S181>/Relational Operator'
   *  Sum: '<S181>/Add1'
   *  Sum: '<S181>/Add2'
   */
  if (!(CrCtl_tiPCCRmp_10msUW == 0U)) {
    CrCtl_B.CrCtl_trqDes = div_s32_floor((CrCtl_trqPCCReqin_10mNmSL -
      CrCtl_B.Memory) * (int32_T)((uint32_T)CrCtl_B.Merge9 * ((uint8_T)T_ms)),
      (int32_T)(CrCtl_tiPCCRmp_10msUW * 10UL)) + CrCtl_B.Memory;
  } else {
    CrCtl_B.CrCtl_trqDes = CrCtl_trqPCCReqin_10mNmSL;
  }

  /* End of MultiPortSwitch: '<S181>/Index Vector1' */

  /* SignalConversion: '<S181>/OutportBufferForCrCtl_trqLead' */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_B.CrCtl_trqDes;

  /* SignalConversion: '<S181>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S181>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S181>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S181>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Inport: '<S181>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S181>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;

  /* Update for Memory: '<S181>/Memory' incorporates:
   *  Inport: '<Root>/CrCtl_tiPCCRmp_10msUW'
   */
  CrCtl_DW.Memory_PreviousInput_l = CrCtl_tiPCCRmp_10msUW;

  /* Update for Memory: '<S181>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_c = CrCtl_trqPCCReqin_10mNmSL;
}

/* Output and update for action system: '<S125>/CrCtl_State_PCC_Hold' */
void CrCtl_CrCtl_State_PCC_Hold(void)
{
  /* MultiPortSwitch: '<S180>/Index Vector2' */
  if (!CrCtl_B.LogicalOperator) {
    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Inport: '<S180>/CrCtl_trqPCCReqIn_10mNmSL'
     *  Memory: '<S180>/Memory2'
     *  RelationalOperator: '<S180>/Relational Operator'
     */
    if (!(CrCtl_trqPCCReqin_10mNmSL == CrCtl_DW.Memory2_PreviousInput)) {
      /* SignalConversion: '<S180>/OutportBufferForCrCtl_stMode' */
      CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

      /* SignalConversion: '<S180>/OutportBufferForCrCtl_stModeSub' incorporates:
       *  Constant: '<S180>/CRCTL_SUBSTRTVAL_2h'
       */
      CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBSTRTVAL);
    } else {
      /* SignalConversion: '<S180>/OutportBufferForCrCtl_stMode' */
      CrCtl_B.CrCtl_stMode = CrCtl_stModeIn_UB;

      /* SignalConversion: '<S180>/OutportBufferForCrCtl_stModeSub' */
      CrCtl_B.CrCtl_stModeSub = CrCtl_stModeSubIn_UB;
    }

    /* End of MultiPortSwitch: '<S180>/Index Vector1' */
  } else {
    /* SignalConversion: '<S180>/OutportBufferForCrCtl_stMode' incorporates:
     *  Constant: '<S180>/CRCTL_ACC_8h'
     */
    CrCtl_B.CrCtl_stMode = ((uint8_T)CRCTL_ACC);

    /* SignalConversion: '<S180>/OutportBufferForCrCtl_stModeSub' incorporates:
     *  Constant: '<S180>/CRCTL_SUBWAITRES_9h'
     */
    CrCtl_B.CrCtl_stModeSub = ((uint8_T)CRCTL_SUBWAITRES);
  }

  /* End of MultiPortSwitch: '<S180>/Index Vector2' */

  /* SignalConversion: '<S180>/OutportBufferForCrCtl_trqDes' incorporates:
   *  Inport: '<S180>/CrCtl_trqPCCReqIn_10mNmSL'
   */
  CrCtl_B.CrCtl_trqDes = CrCtl_trqPCCReqin_10mNmSL;

  /* SignalConversion: '<S180>/OutportBufferForCrCtl_trqLead' incorporates:
   *  Inport: '<S180>/CrCtl_trqPCCReqIn_10mNmSL'
   */
  CrCtl_B.CrCtl_trqLead_10mNm = CrCtl_trqPCCReqin_10mNmSL;

  /* SignalConversion: '<S180>/OutportBufferForCrCtl_stActive' incorporates:
   *  Constant: '<S180>/CRCTL_STACTIVE(=1)'
   */
  CrCtl_stActive_BL = TRUE;

  /* SignalConversion: '<S180>/OutportBufferForCrCtl_stOpFunc' incorporates:
   *  Constant: '<S180>/CRCTL_ACTV(=1h)'
   */
  CrCtl_B.CrCtl_stOpFunc = ((uint8_T)CRCTL_ACTV);

  /* Inport: '<S180>/PCC_vSetPointTrgt_kmphUW_In' */
  CrCtl_B.PCC_vSetPointTrgt_kmphUW_In = CrCtl_B.PCC_vSetPointTrgt_10mphUW;

  /* Inport: '<S180>/CrCtl_rVnBeg_In' */
  CrCtl_B.CrCtl_rVnBeg = CrCtl_B.IndexVector4;

  /* Inport: '<S180>/CrCtl_stLck_In' */
  CrCtl_B.CrCtl_stLck = 0U;

  /* Update for Memory: '<S180>/Memory2' incorporates:
   *  Inport: '<S180>/CrCtl_trqPCCReqIn_10mNmSL'
   */
  CrCtl_DW.Memory2_PreviousInput = CrCtl_trqPCCReqin_10mNmSL;
}

/* System initialize for action system: '<S4>/CrCtl_State_PCC' */
void CrCtl_CrCtl_State_PCC_Init(void)
{
  /* SystemInitialize for Merge: '<S125>/Merge9' */
  CrCtl_B.Merge9 = 0U;
}

/* Output and update for action system: '<S4>/CrCtl_State_PCC' */
void CrCtl_CrCtl_State_PCC(void)
{
  /* Logic: '<S125>/Logical Operator' incorporates:
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   *  Memory: '<S125>/Memory3'
   */
  CrCtl_B.LogicalOperator = (CrCtl_DW.Memory3_PreviousInput_g &&
    (!CrCtl_PCCAct_BL));

  /* Memory: '<S125>/Memory' */
  CrCtl_B.Memory = CrCtl_DW.Memory_PreviousInput;

  /* Memory: '<S125>/Memory1' */
  CrCtl_B.Memory1_a = CrCtl_DW.Memory1_PreviousInput_b;

  /* SwitchCase: '<S125>/Switch Case' */
  switch ((int32_T)CrCtl_stModeSubIn_UB) {
   case 2L:
    /* Outputs for IfAction SubSystem: '<S125>/CrCtl_State_PCC_SubStrtVal' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    CrCtl_CrCtl_State_PCC_SubStrtVal();

    /* End of Outputs for SubSystem: '<S125>/CrCtl_State_PCC_SubStrtVal' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S125>/CrCtl_State_PCC_SubRmp' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    CrCtl_CrCtl_State_PCC_SubRmp();

    /* End of Outputs for SubSystem: '<S125>/CrCtl_State_PCC_SubRmp' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S125>/CrCtl_State_PCC_Hold' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    CrCtl_CrCtl_State_PCC_Hold();

    /* End of Outputs for SubSystem: '<S125>/CrCtl_State_PCC_Hold' */
    break;
  }

  /* End of SwitchCase: '<S125>/Switch Case' */

  /* SignalConversion: '<S125>/OutportBufferForCrCtl_vSetPointTrgt' */
  CrCtl_vSetPointTrgt_10mphUW = CrCtl_B.PCC_vSetPointTrgt_kmphUW_In;

  /* Update for Memory: '<S125>/Memory3' incorporates:
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   */
  CrCtl_DW.Memory3_PreviousInput_g = CrCtl_PCCAct_BL;

  /* Update for Memory: '<S125>/Memory' */
  CrCtl_DW.Memory_PreviousInput = CrCtl_B.OutportBufferForCrCtl_trqPCCStrtVal;

  /* Update for Memory: '<S125>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_b = CrCtl_B.Merge9;
}

/* System initialize for atomic system: '<Root>/CrCtl_State' */
void CrCtl_CrCtl_State_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S212>/Integrator' */
  CrCtl_DW.Integrator_IC_LOADING = 1U;
  CrCtl_DW.Integrator_PrevResetState = 2;

  /* SystemInitialize for IfAction SubSystem: '<S4>/CrCtl_State_ResAbv' */
  CrCtl_CrCtl_State_ResAbv_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/CrCtl_State_ResAbv' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/CrCtl_State_ResBlw' */
  CrCtl_CrCtl_State_ResBlw_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/CrCtl_State_ResBlw' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/CrCtl_State_PCC' */
  CrCtl_CrCtl_State_PCC_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/CrCtl_State_PCC' */

  /* SystemInitialize for Chart: '<S135>/PISlct' */
  CrCtl_B.isUsePI = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge10' */
  CrCtl_vSetPointAct_mp_10mphUW = 0U;

  /* SystemInitialize for Merge: '<S213>/Merge' */
  CrCtl_B.P = 0;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  CrCtl_B.CrCtl_trqDes = 0L;

  /* SystemInitialize for Merge: '<S4>/Merge3' */
  CrCtl_B.CrCtl_stOpFunc = 0U;

  /* SystemInitialize for Merge: '<S213>/Merge' */
  CrCtl_B.I = 0;

  /* SystemInitialize for Chart: '<S215>/Chart1' */
  CrCtl_TC1TrsReqGear_UB = 0;

  /* SystemInitialize for Chart: '<S229>/manualShiftSuspChart' */
  CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h = 0;
  CrCtl_DW.is_CRCTL_SUSPENDSTARTRUMP_1h = 0;
  CrCtl_DW.is_active_c16_CrCtl = 0U;
  CrCtl_DW.is_c16_CrCtl = 0;
  CrCtl_B.CrCtl_stSuspRamp_mp = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge1' */
  CrCtl_B.CrCtl_trqLead_10mNm = 0L;

  /* SystemInitialize for Merge: '<S4>/Merge2' */
  CrCtl_stActive_BL = false;

  /* SystemInitialize for Merge: '<S4>/Merge4' */
  CrCtl_B.CrCtl_stMode = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge5' */
  CrCtl_B.CrCtl_stModeSub = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge6' */
  CrCtl_B.CrCtl_rVnBeg = 0;

  /* SystemInitialize for Merge: '<S4>/Merge7' */
  CrCtl_vSetPointTrgt_10mphUW = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge8' */
  CrCtl_B.CrCtl_stLck = 0U;
}

/* Start for atomic system: '<Root>/CrCtl_State' */
void CrCtl_CrCtl_State_Start(void)
{
  /* Start for IfAction SubSystem: '<S4>/CrCtl_State_TipDwn' */
  CrCtl_CrCtl_State_TipDwn_Start();

  /* End of Start for SubSystem: '<S4>/CrCtl_State_TipDwn' */
}

/* Outputs for atomic system: '<Root>/CrCtl_State' */
void CrCtl_CrCtl_State(void)
{
  uint8_T rtb_PIModeSlct;
  int32_T rtb_CrCtl_trqDes_10mNmSL;
  boolean_T rtb_RelationalOperator17_o;
  boolean_T rtb_RelationalOperator16_k;
  boolean_T rtb_RelationalOperator15_b;
  boolean_T rtb_RelationalOperator14_e;
  uint16_T rtb_Switch2_n;
  int16_T rtb_IndexVector3_a;
  int32_T Subtract;
  int32_T Sum;
  int8_T Subtract_m;

  /* Memory: '<S4>/Memory1' */
  CrCtl_B.Memory1 = CrCtl_DW.Memory1_PreviousInput_c4;

  /* Memory: '<S4>/Memory' */
  CrCtl_B.Memory_c = CrCtl_DW.Memory_PreviousInput_d;

  /* SwitchCase: '<S4>/Switch Case' */
  switch ((int32_T)CrCtl_stModeIn_UB) {
   case 1L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_Neutr' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    CrCtl_CrCtl_State_Neutr();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_Neutr' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_Off' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    CrCtl_CrCtl_State_Off();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_Off' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_TipDwn' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    CrCtl_CrCtl_State_TipDwn();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_TipDwn' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_Decl' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    CrCtl_CrCtl_State_Decl();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_Decl' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_ResAbv' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    CrCtl_CrCtl_State_ResAbv();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_ResAbv' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_ResBlw' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    CrCtl_CrCtl_State_ResBlw();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_ResBlw' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_TipUp' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    CrCtl_CrCtl_State_TipUp();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_TipUp' */
    break;

   case 8L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_Acc' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    CrCtl_CrCtl_State_Acc();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_Acc' */
    break;

   case 9L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_Hold' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    CrCtl_CrCtl_State_Hold();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_Hold' */
    break;

   case 10L:
    /* Outputs for IfAction SubSystem: '<S4>/CrCtl_State_PCC' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    CrCtl_CrCtl_State_PCC();

    /* End of Outputs for SubSystem: '<S4>/CrCtl_State_PCC' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Chart: '<S135>/PISlct' */
  if (CrCtl_B.IndexVector7) {
    rtb_PIModeSlct = 0U;
    CrCtl_B.isUsePI = 0U;
  } else if ((CrCtl_stModeIn_UB == 4) && (CrCtl_stModeSubIn_UB == 3)) {
    rtb_PIModeSlct = 3U;
    CrCtl_B.isUsePI = 1U;
  } else if ((CrCtl_stModeIn_UB == 5) && (CrCtl_stModeSubIn_UB == 3)) {
    rtb_PIModeSlct = 5U;
    CrCtl_B.isUsePI = 1U;
  } else if ((CrCtl_stModeIn_UB == 6) && (CrCtl_stModeSubIn_UB == 3)) {
    rtb_PIModeSlct = 4U;
    CrCtl_B.isUsePI = 1U;
  } else if ((CrCtl_stModeIn_UB == 6) && (CrCtl_stModeSubIn_UB == 5)) {
    rtb_PIModeSlct = 4U;
    CrCtl_B.isUsePI = 1U;
  } else if ((CrCtl_stModeIn_UB == 8) && (CrCtl_stModeSubIn_UB == 3)) {
    rtb_PIModeSlct = 2U;
    CrCtl_B.isUsePI = 1U;
  } else if ((CrCtl_stModeIn_UB == 9) && (CrCtl_stModeSubIn_UB == 8)) {
    rtb_PIModeSlct = 1U;
    CrCtl_B.isUsePI = 1U;
  } else {
    rtb_PIModeSlct = 0U;
    CrCtl_B.isUsePI = 0U;
  }

  /* End of Chart: '<S135>/PISlct' */

  /* DiscreteIntegrator: '<S212>/Integrator' */
  if (CrCtl_DW.Integrator_IC_LOADING != 0) {
    CrCtl_DW.Integrator_DSTATE = PrpBrk_trqDes_10mNmL;
  }

  if ((CrCtl_B.isUsePI > 0) && (CrCtl_DW.Integrator_PrevResetState <= 0)) {
    CrCtl_DW.Integrator_DSTATE = PrpBrk_trqDes_10mNmL;
  }

  /* Sum: '<S135>/Subtract' */
  Subtract = (int32_T)CrCtl_vSetPointAct_mp_10mphUW - VSSCD_v_10mphUW;

  /* SwitchCase: '<S213>/Switch Case1' */
  switch ((int32_T)rtb_PIModeSlct) {
   case 1L:
    /* Outputs for IfAction SubSystem: '<S213>/HOLD' incorporates:
     *  ActionPort: '<S225>/Action Port'
     */
    /* RelationalOperator: '<S225>/Relational Operator17' incorporates:
     *  Constant: '<S225>/CrCtl_vPIGovDvt_C3_10mphSW'
     */
    rtb_RelationalOperator17_o = (Subtract > CrCtl_vPIGovDvt_C3_10mphSW);

    /* RelationalOperator: '<S225>/Relational Operator16' incorporates:
     *  Constant: '<S225>/CrCtl_vPIGovDvt_C4_10mphSW'
     */
    rtb_RelationalOperator16_k = (Subtract > CrCtl_vPIGovDvt_C4_10mphSW);

    /* RelationalOperator: '<S225>/Relational Operator15' incorporates:
     *  Constant: '<S225>/CrCtl_vPIGovDvt_C2_10mphSW'
     */
    rtb_RelationalOperator15_b = (Subtract > CrCtl_vPIGovDvt_C2_10mphSW);

    /* RelationalOperator: '<S225>/Relational Operator14' incorporates:
     *  Constant: '<S225>/CrCtl_vPIGovDvt_C1_10mphSW'
     */
    rtb_RelationalOperator14_e = (Subtract > CrCtl_vPIGovDvt_C1_10mphSW);

    /* MultiPortSwitch: '<S225>/Index Vector1' incorporates:
     *  Constant: '<S225>/CrCtl_stParSelThres1_C'
     *  MultiPortSwitch: '<S225>/Index Vector10'
     *  RelationalOperator: '<S225>/Relational Operator'
     */
    if (!(CrCtl_B.Gearbx_stGear < CrCtl_stParSelThres1_C)) {
      /* MultiPortSwitch: '<S225>/Index Vector' incorporates:
       *  Constant: '<S225>/CrCtl_stParSelThres2_C'
       *  MultiPortSwitch: '<S225>/Index Vector6'
       *  RelationalOperator: '<S225>/Relational Operator1'
       */
      if (!(CrCtl_B.Gearbx_stGear > CrCtl_stParSelThres2_C)) {
        /* MultiPortSwitch: '<S225>/Index Vector2' incorporates:
         *  Constant: '<S225>/CrCtl_HoldIWinPos2_C'
         *  Constant: '<S225>/CrCtl_HoldPWinPos2_C'
         */
        if (!rtb_RelationalOperator14_e) {
          /* MultiPortSwitch: '<S225>/Index Vector3' incorporates:
           *  Constant: '<S225>/CrCtl_HoldIKiPos2_C'
           *  Constant: '<S225>/CrCtl_HoldPKpPos2_C'
           */
          if (!rtb_RelationalOperator15_b) {
            /* MultiPortSwitch: '<S225>/Index Vector4' incorporates:
             *  Constant: '<S225>/CrCtl_HoldIKi2_C'
             *  Constant: '<S225>/CrCtl_HoldPKp2_C'
             */
            if (!rtb_RelationalOperator17_o) {
              /* MultiPortSwitch: '<S225>/Index Vector5' incorporates:
               *  Constant: '<S225>/CrCtl_HoldIKiNeg2_C'
               *  Constant: '<S225>/CrCtl_HoldIWinNeg2_C'
               *  Constant: '<S225>/CrCtl_HoldPKpNeg2_C'
               *  Constant: '<S225>/CrCtl_HoldPWinNeg2_C'
               */
              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.I = CrCtl_HoldIWinNeg2_C;
              } else {
                CrCtl_B.I = CrCtl_HoldIKiNeg2_C;
              }

              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.P = CrCtl_HoldPWinNeg2_C;
              } else {
                CrCtl_B.P = CrCtl_HoldPKpNeg2_C;
              }

              /* End of MultiPortSwitch: '<S225>/Index Vector5' */
            } else {
              CrCtl_B.I = CrCtl_HoldIKi2_C;
              CrCtl_B.P = CrCtl_HoldPKp2_C;
            }

            /* End of MultiPortSwitch: '<S225>/Index Vector4' */
          } else {
            CrCtl_B.I = CrCtl_HoldIKiPos2_C;
            CrCtl_B.P = CrCtl_HoldPKpPos2_C;
          }

          /* End of MultiPortSwitch: '<S225>/Index Vector3' */
        } else {
          CrCtl_B.I = CrCtl_HoldIWinPos2_C;
          CrCtl_B.P = CrCtl_HoldPWinPos2_C;
        }

        /* End of MultiPortSwitch: '<S225>/Index Vector2' */
      } else if (!rtb_RelationalOperator14_e) {
        /* MultiPortSwitch: '<S225>/Index Vector7' incorporates:
         *  Constant: '<S225>/CrCtl_HoldIKiPos3_C'
         *  Constant: '<S225>/CrCtl_HoldPKpPos3_C'
         *  MultiPortSwitch: '<S225>/Index Vector6'
         */
        if (!rtb_RelationalOperator15_b) {
          /* MultiPortSwitch: '<S225>/Index Vector8' incorporates:
           *  Constant: '<S225>/CrCtl_HoldIKi3_C'
           *  Constant: '<S225>/CrCtl_HoldPKp3_C'
           */
          if (!rtb_RelationalOperator17_o) {
            /* MultiPortSwitch: '<S225>/Index Vector9' incorporates:
             *  Constant: '<S225>/CrCtl_HoldIKiNeg3_C'
             *  Constant: '<S225>/CrCtl_HoldIWinNeg3_C'
             *  Constant: '<S225>/CrCtl_HoldPKpNeg3_C'
             *  Constant: '<S225>/CrCtl_HoldPWinNeg3_C'
             */
            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.I = CrCtl_HoldIWinNeg3_C;
            } else {
              CrCtl_B.I = CrCtl_HoldIKiNeg3_C;
            }

            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.P = CrCtl_HoldPWinNeg3_C;
            } else {
              CrCtl_B.P = CrCtl_HoldPKpNeg3_C;
            }

            /* End of MultiPortSwitch: '<S225>/Index Vector9' */
          } else {
            CrCtl_B.I = CrCtl_HoldIKi3_C;
            CrCtl_B.P = CrCtl_HoldPKp3_C;
          }

          /* End of MultiPortSwitch: '<S225>/Index Vector8' */
        } else {
          CrCtl_B.I = CrCtl_HoldIKiPos3_C;
          CrCtl_B.P = CrCtl_HoldPKpPos3_C;
        }

        /* End of MultiPortSwitch: '<S225>/Index Vector7' */
      } else {
        /* MultiPortSwitch: '<S225>/Index Vector6' incorporates:
         *  Constant: '<S225>/CrCtl_HoldIWinPos3_C'
         *  Constant: '<S225>/CrCtl_HoldPWinPos3_C'
         */
        CrCtl_B.I = CrCtl_HoldIWinPos3_C;
        CrCtl_B.P = CrCtl_HoldPWinPos3_C;
      }

      /* End of MultiPortSwitch: '<S225>/Index Vector' */
    } else if (!rtb_RelationalOperator14_e) {
      /* MultiPortSwitch: '<S225>/Index Vector11' incorporates:
       *  Constant: '<S225>/CrCtl_HoldIKiPos1_C'
       *  Constant: '<S225>/CrCtl_HoldPKpPos1_C'
       *  MultiPortSwitch: '<S225>/Index Vector10'
       */
      if (!rtb_RelationalOperator15_b) {
        /* MultiPortSwitch: '<S225>/Index Vector12' incorporates:
         *  Constant: '<S225>/CrCtl_HoldIKi1_C'
         *  Constant: '<S225>/CrCtl_HoldPKp1_C'
         */
        if (!rtb_RelationalOperator17_o) {
          /* MultiPortSwitch: '<S225>/Index Vector13' incorporates:
           *  Constant: '<S225>/CrCtl_HoldIKiNeg1_C'
           *  Constant: '<S225>/CrCtl_HoldIWinNeg1_C'
           *  Constant: '<S225>/CrCtl_HoldPKpNeg1_C'
           *  Constant: '<S225>/CrCtl_HoldPWinNeg1_C'
           */
          if (!rtb_RelationalOperator16_k) {
            CrCtl_B.I = CrCtl_HoldIWinNeg1_C;
            CrCtl_B.P = CrCtl_HoldPWinNeg1_C;
          } else {
            CrCtl_B.I = CrCtl_HoldIKiNeg1_C;
            CrCtl_B.P = CrCtl_HoldPKpNeg1_C;
          }

          /* End of MultiPortSwitch: '<S225>/Index Vector13' */
        } else {
          CrCtl_B.I = CrCtl_HoldIKi1_C;
          CrCtl_B.P = CrCtl_HoldPKp1_C;
        }

        /* End of MultiPortSwitch: '<S225>/Index Vector12' */
      } else {
        CrCtl_B.I = CrCtl_HoldIKiPos1_C;
        CrCtl_B.P = CrCtl_HoldPKpPos1_C;
      }

      /* End of MultiPortSwitch: '<S225>/Index Vector11' */
    } else {
      /* MultiPortSwitch: '<S225>/Index Vector10' incorporates:
       *  Constant: '<S225>/CrCtl_HoldIWinPos1_C'
       *  Constant: '<S225>/CrCtl_HoldPWinPos1_C'
       */
      CrCtl_B.I = CrCtl_HoldIWinPos1_C;
      CrCtl_B.P = CrCtl_HoldPWinPos1_C;
    }

    /* End of MultiPortSwitch: '<S225>/Index Vector1' */
    /* End of Outputs for SubSystem: '<S213>/HOLD' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S213>/ACC' incorporates:
     *  ActionPort: '<S221>/Action Port'
     */
    /* RelationalOperator: '<S221>/Relational Operator19' incorporates:
     *  Constant: '<S221>/CrCtl_vPIGovDvt_C3_10mphSW'
     */
    rtb_RelationalOperator17_o = (Subtract > CrCtl_vPIGovDvt_C3_10mphSW);

    /* RelationalOperator: '<S221>/Relational Operator18' incorporates:
     *  Constant: '<S221>/CrCtl_vPIGovDvt_C4_10mphSW'
     */
    rtb_RelationalOperator16_k = (Subtract > CrCtl_vPIGovDvt_C4_10mphSW);

    /* RelationalOperator: '<S221>/Relational Operator17' incorporates:
     *  Constant: '<S221>/CrCtl_vPIGovDvt_C2_10mphSW'
     */
    rtb_RelationalOperator15_b = (Subtract > CrCtl_vPIGovDvt_C2_10mphSW);

    /* RelationalOperator: '<S221>/Relational Operator16' incorporates:
     *  Constant: '<S221>/CrCtl_vPIGovDvt_C1_10mphSW'
     */
    rtb_RelationalOperator14_e = (Subtract > CrCtl_vPIGovDvt_C1_10mphSW);

    /* MultiPortSwitch: '<S221>/Index Vector15' incorporates:
     *  Constant: '<S221>/CrCtl_stParSelThres1_C1'
     *  MultiPortSwitch: '<S221>/Index Vector16'
     *  RelationalOperator: '<S221>/Relational Operator14'
     */
    if (!(CrCtl_B.Gearbx_stGear < CrCtl_stParSelThres1_C)) {
      /* MultiPortSwitch: '<S221>/Index Vector14' incorporates:
       *  Constant: '<S221>/CrCtl_stParSelThres2_C1'
       *  MultiPortSwitch: '<S221>/Index Vector24'
       *  RelationalOperator: '<S221>/Relational Operator15'
       */
      if (!(CrCtl_B.Gearbx_stGear > CrCtl_stParSelThres2_C)) {
        /* MultiPortSwitch: '<S221>/Index Vector20' incorporates:
         *  Constant: '<S221>/CrCtl_AccIWinPos2_C'
         *  Constant: '<S221>/CrCtl_AccPWinPos2_C'
         */
        if (!rtb_RelationalOperator14_e) {
          /* MultiPortSwitch: '<S221>/Index Vector21' incorporates:
           *  Constant: '<S221>/CrCtl_AccIKiPos2_C'
           *  Constant: '<S221>/CrCtl_AccPKpPos2_C'
           */
          if (!rtb_RelationalOperator15_b) {
            /* MultiPortSwitch: '<S221>/Index Vector22' incorporates:
             *  Constant: '<S221>/CrCtl_AccIKi2_C'
             *  Constant: '<S221>/CrCtl_AccPKp2_C'
             */
            if (!rtb_RelationalOperator17_o) {
              /* MultiPortSwitch: '<S221>/Index Vector23' incorporates:
               *  Constant: '<S221>/CrCtl_AccIKiNeg2_C'
               *  Constant: '<S221>/CrCtl_AccIWinNeg2_C'
               *  Constant: '<S221>/CrCtl_AccPKpNeg2_C'
               *  Constant: '<S221>/CrCtl_AccPWinNeg2_C'
               */
              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.I = CrCtl_AccIWinNeg2_C;
              } else {
                CrCtl_B.I = CrCtl_AccIKiNeg2_C;
              }

              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.P = CrCtl_AccPWinNeg2_C;
              } else {
                CrCtl_B.P = CrCtl_AccPKpNeg2_C;
              }

              /* End of MultiPortSwitch: '<S221>/Index Vector23' */
            } else {
              CrCtl_B.I = CrCtl_AccIKi2_C;
              CrCtl_B.P = CrCtl_AccPKp2_C;
            }

            /* End of MultiPortSwitch: '<S221>/Index Vector22' */
          } else {
            CrCtl_B.I = CrCtl_AccIKiPos2_C;
            CrCtl_B.P = CrCtl_AccPKpPos2_C;
          }

          /* End of MultiPortSwitch: '<S221>/Index Vector21' */
        } else {
          CrCtl_B.I = CrCtl_AccIWinPos2_C;
          CrCtl_B.P = CrCtl_AccPWinPos2_C;
        }

        /* End of MultiPortSwitch: '<S221>/Index Vector20' */
      } else if (!rtb_RelationalOperator14_e) {
        /* MultiPortSwitch: '<S221>/Index Vector25' incorporates:
         *  Constant: '<S221>/CrCtl_AccIKiPos3_C'
         *  Constant: '<S221>/CrCtl_AccPKpPos3_C'
         *  MultiPortSwitch: '<S221>/Index Vector24'
         */
        if (!rtb_RelationalOperator15_b) {
          /* MultiPortSwitch: '<S221>/Index Vector26' incorporates:
           *  Constant: '<S221>/CrCtl_AccIKi3_C'
           *  Constant: '<S221>/CrCtl_AccPKp3_C'
           */
          if (!rtb_RelationalOperator17_o) {
            /* MultiPortSwitch: '<S221>/Index Vector27' incorporates:
             *  Constant: '<S221>/CrCtl_AccIKiNeg3_C'
             *  Constant: '<S221>/CrCtl_AccIWinNeg3_C'
             *  Constant: '<S221>/CrCtl_AccPKpNeg3_C'
             *  Constant: '<S221>/CrCtl_AccPWinNeg3_C'
             */
            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.I = CrCtl_AccIWinNeg3_C;
            } else {
              CrCtl_B.I = CrCtl_AccIKiNeg3_C;
            }

            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.P = CrCtl_AccPWinNeg3_C;
            } else {
              CrCtl_B.P = CrCtl_AccPKpNeg3_C;
            }

            /* End of MultiPortSwitch: '<S221>/Index Vector27' */
          } else {
            CrCtl_B.I = CrCtl_AccIKi3_C;
            CrCtl_B.P = CrCtl_AccPKp3_C;
          }

          /* End of MultiPortSwitch: '<S221>/Index Vector26' */
        } else {
          CrCtl_B.I = CrCtl_AccIKiPos3_C;
          CrCtl_B.P = CrCtl_AccPKpPos3_C;
        }

        /* End of MultiPortSwitch: '<S221>/Index Vector25' */
      } else {
        /* MultiPortSwitch: '<S221>/Index Vector24' incorporates:
         *  Constant: '<S221>/CrCtl_AccIWinPos3_C'
         *  Constant: '<S221>/CrCtl_AccPWinPos3_C'
         */
        CrCtl_B.I = CrCtl_AccIWinPos3_C;
        CrCtl_B.P = CrCtl_AccPWinPos3_C;
      }

      /* End of MultiPortSwitch: '<S221>/Index Vector14' */
    } else if (!rtb_RelationalOperator14_e) {
      /* MultiPortSwitch: '<S221>/Index Vector17' incorporates:
       *  Constant: '<S221>/CrCtl_AccIKiPos1_C'
       *  Constant: '<S221>/CrCtl_AccPKpPos1_C'
       *  MultiPortSwitch: '<S221>/Index Vector16'
       */
      if (!rtb_RelationalOperator15_b) {
        /* MultiPortSwitch: '<S221>/Index Vector18' incorporates:
         *  Constant: '<S221>/CrCtl_AccIKi1_C'
         *  Constant: '<S221>/CrCtl_AccPKp1_C'
         */
        if (!rtb_RelationalOperator17_o) {
          /* MultiPortSwitch: '<S221>/Index Vector19' incorporates:
           *  Constant: '<S221>/CrCtl_AccIKiNeg1_C'
           *  Constant: '<S221>/CrCtl_AccIWinNeg1_C'
           *  Constant: '<S221>/CrCtl_AccPKpNeg1_C'
           *  Constant: '<S221>/CrCtl_AccPWinNeg1_C'
           */
          if (!rtb_RelationalOperator16_k) {
            CrCtl_B.I = CrCtl_AccIWinNeg1_C;
            CrCtl_B.P = CrCtl_AccPWinNeg1_C;
          } else {
            CrCtl_B.I = CrCtl_AccIKiNeg1_C;
            CrCtl_B.P = CrCtl_AccPKpNeg1_C;
          }

          /* End of MultiPortSwitch: '<S221>/Index Vector19' */
        } else {
          CrCtl_B.I = CrCtl_AccIKi1_C;
          CrCtl_B.P = CrCtl_AccPKp1_C;
        }

        /* End of MultiPortSwitch: '<S221>/Index Vector18' */
      } else {
        CrCtl_B.I = CrCtl_AccIKiPos1_C;
        CrCtl_B.P = CrCtl_AccPKpPos1_C;
      }

      /* End of MultiPortSwitch: '<S221>/Index Vector17' */
    } else {
      /* MultiPortSwitch: '<S221>/Index Vector16' incorporates:
       *  Constant: '<S221>/CrCtl_AccIWinPos1_C'
       *  Constant: '<S221>/CrCtl_AccPWinPos1_C'
       */
      CrCtl_B.I = CrCtl_AccIWinPos1_C;
      CrCtl_B.P = CrCtl_AccPWinPos1_C;
    }

    /* End of MultiPortSwitch: '<S221>/Index Vector15' */
    /* End of Outputs for SubSystem: '<S213>/ACC' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S213>/DECL' incorporates:
     *  ActionPort: '<S224>/Action Port'
     */
    /* RelationalOperator: '<S224>/Relational Operator19' incorporates:
     *  Constant: '<S224>/CrCtl_vPIGovDvt_C3_10mphSW'
     */
    rtb_RelationalOperator17_o = (Subtract > CrCtl_vPIGovDvt_C3_10mphSW);

    /* RelationalOperator: '<S224>/Relational Operator18' incorporates:
     *  Constant: '<S224>/CrCtl_vPIGovDvt_C4_10mphSW'
     */
    rtb_RelationalOperator16_k = (Subtract > CrCtl_vPIGovDvt_C4_10mphSW);

    /* RelationalOperator: '<S224>/Relational Operator17' incorporates:
     *  Constant: '<S224>/CrCtl_vPIGovDvt_C2_10mphSW'
     */
    rtb_RelationalOperator15_b = (Subtract > CrCtl_vPIGovDvt_C2_10mphSW);

    /* RelationalOperator: '<S224>/Relational Operator16' incorporates:
     *  Constant: '<S224>/CrCtl_vPIGovDvt_C1_10mphSW'
     */
    rtb_RelationalOperator14_e = (Subtract > CrCtl_vPIGovDvt_C1_10mphSW);

    /* MultiPortSwitch: '<S224>/Index Vector15' incorporates:
     *  Constant: '<S224>/CrCtl_stParSelThres1_C1'
     *  MultiPortSwitch: '<S224>/Index Vector16'
     *  RelationalOperator: '<S224>/Relational Operator14'
     */
    if (!(CrCtl_B.Gearbx_stGear < CrCtl_stParSelThres1_C)) {
      /* MultiPortSwitch: '<S224>/Index Vector14' incorporates:
       *  Constant: '<S224>/CrCtl_stParSelThres2_C1'
       *  MultiPortSwitch: '<S224>/Index Vector24'
       *  RelationalOperator: '<S224>/Relational Operator15'
       */
      if (!(CrCtl_B.Gearbx_stGear > CrCtl_stParSelThres2_C)) {
        /* MultiPortSwitch: '<S224>/Index Vector20' incorporates:
         *  Constant: '<S224>/CrCtl_DeclIWinPos2_C'
         *  Constant: '<S224>/CrCtl_DeclPWinPos2_C'
         */
        if (!rtb_RelationalOperator14_e) {
          /* MultiPortSwitch: '<S224>/Index Vector21' incorporates:
           *  Constant: '<S224>/CrCtl_DeclIKiPos2_C1'
           *  Constant: '<S224>/CrCtl_DeclPKpPos2_C1'
           */
          if (!rtb_RelationalOperator15_b) {
            /* MultiPortSwitch: '<S224>/Index Vector22' incorporates:
             *  Constant: '<S224>/CrCtl_DeclIKi2_C'
             *  Constant: '<S224>/CrCtl_DeclPKp2_C'
             */
            if (!rtb_RelationalOperator17_o) {
              /* MultiPortSwitch: '<S224>/Index Vector23' incorporates:
               *  Constant: '<S224>/CrCtl_DeclIKiNeg2_C'
               *  Constant: '<S224>/CrCtl_DeclIWinNeg2_C'
               *  Constant: '<S224>/CrCtl_DeclPKpNeg2_C'
               *  Constant: '<S224>/CrCtl_DeclPWinNeg2_C'
               */
              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.I = CrCtl_DeclIWinNeg2_C;
              } else {
                CrCtl_B.I = CrCtl_DeclIKiNeg2_C;
              }

              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.P = CrCtl_DeclPWinNeg2_C;
              } else {
                CrCtl_B.P = CrCtl_DeclPKpNeg2_C;
              }

              /* End of MultiPortSwitch: '<S224>/Index Vector23' */
            } else {
              CrCtl_B.I = CrCtl_DeclIKi2_C;
              CrCtl_B.P = CrCtl_DeclPKp2_C;
            }

            /* End of MultiPortSwitch: '<S224>/Index Vector22' */
          } else {
            CrCtl_B.I = CrCtl_DeclIKiPos2_C;
            CrCtl_B.P = CrCtl_DeclPKpPos2_C;
          }

          /* End of MultiPortSwitch: '<S224>/Index Vector21' */
        } else {
          CrCtl_B.I = CrCtl_DeclIWinPos2_C;
          CrCtl_B.P = CrCtl_DeclPWinPos2_C;
        }

        /* End of MultiPortSwitch: '<S224>/Index Vector20' */
      } else if (!rtb_RelationalOperator14_e) {
        /* MultiPortSwitch: '<S224>/Index Vector25' incorporates:
         *  Constant: '<S224>/CrCtl_DeclIKiPos3_C'
         *  Constant: '<S224>/CrCtl_DeclPKpPos3_C'
         *  MultiPortSwitch: '<S224>/Index Vector24'
         */
        if (!rtb_RelationalOperator15_b) {
          /* MultiPortSwitch: '<S224>/Index Vector26' incorporates:
           *  Constant: '<S224>/CrCtl_DeclIKi3_C'
           *  Constant: '<S224>/CrCtl_DeclPKp3_C'
           */
          if (!rtb_RelationalOperator17_o) {
            /* MultiPortSwitch: '<S224>/Index Vector27' incorporates:
             *  Constant: '<S224>/CrCtl_DeclIKiNeg3_C'
             *  Constant: '<S224>/CrCtl_DeclIWinNeg3_C'
             *  Constant: '<S224>/CrCtl_DeclPKpNeg3_C'
             *  Constant: '<S224>/CrCtl_DeclPWinNeg3_C'
             */
            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.I = CrCtl_DeclIWinNeg3_C;
            } else {
              CrCtl_B.I = CrCtl_DeclIKiNeg3_C;
            }

            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.P = CrCtl_DeclPWinNeg3_C;
            } else {
              CrCtl_B.P = CrCtl_DeclPKpNeg3_C;
            }

            /* End of MultiPortSwitch: '<S224>/Index Vector27' */
          } else {
            CrCtl_B.I = CrCtl_DeclIKi3_C;
            CrCtl_B.P = CrCtl_DeclPKp3_C;
          }

          /* End of MultiPortSwitch: '<S224>/Index Vector26' */
        } else {
          CrCtl_B.I = CrCtl_DeclIKiPos3_C;
          CrCtl_B.P = CrCtl_DeclPKpPos3_C;
        }

        /* End of MultiPortSwitch: '<S224>/Index Vector25' */
      } else {
        /* MultiPortSwitch: '<S224>/Index Vector24' incorporates:
         *  Constant: '<S224>/CrCtl_DeclIWinPos3_C'
         *  Constant: '<S224>/CrCtl_DeclPWinPos3_C'
         */
        CrCtl_B.I = CrCtl_DeclIWinPos3_C;
        CrCtl_B.P = CrCtl_DeclPWinPos3_C;
      }

      /* End of MultiPortSwitch: '<S224>/Index Vector14' */
    } else if (!rtb_RelationalOperator14_e) {
      /* MultiPortSwitch: '<S224>/Index Vector17' incorporates:
       *  Constant: '<S224>/CrCtl_DeclIKiPos1_C'
       *  Constant: '<S224>/CrCtl_DeclPKpPos1_C'
       *  MultiPortSwitch: '<S224>/Index Vector16'
       */
      if (!rtb_RelationalOperator15_b) {
        /* MultiPortSwitch: '<S224>/Index Vector18' incorporates:
         *  Constant: '<S224>/CrCtl_DeclIKi1_C'
         *  Constant: '<S224>/CrCtl_DeclPKp1_C'
         */
        if (!rtb_RelationalOperator17_o) {
          /* MultiPortSwitch: '<S224>/Index Vector19' incorporates:
           *  Constant: '<S224>/CrCtl_DeclIKiNeg1_C'
           *  Constant: '<S224>/CrCtl_DeclIWinNeg1_C'
           *  Constant: '<S224>/CrCtl_DeclPKpNeg1_C'
           *  Constant: '<S224>/CrCtl_DeclPWinNeg1_C'
           */
          if (!rtb_RelationalOperator16_k) {
            CrCtl_B.I = CrCtl_DeclIWinNeg1_C;
            CrCtl_B.P = CrCtl_DeclPWinNeg1_C;
          } else {
            CrCtl_B.I = CrCtl_DeclIKiNeg1_C;
            CrCtl_B.P = CrCtl_DeclPKpNeg1_C;
          }

          /* End of MultiPortSwitch: '<S224>/Index Vector19' */
        } else {
          CrCtl_B.I = CrCtl_DeclIKi1_C;
          CrCtl_B.P = CrCtl_DeclPKp1_C;
        }

        /* End of MultiPortSwitch: '<S224>/Index Vector18' */
      } else {
        CrCtl_B.I = CrCtl_DeclIKiPos1_C;
        CrCtl_B.P = CrCtl_DeclPKpPos1_C;
      }

      /* End of MultiPortSwitch: '<S224>/Index Vector17' */
    } else {
      /* MultiPortSwitch: '<S224>/Index Vector16' incorporates:
       *  Constant: '<S224>/CrCtl_DeclIWinPos1_C'
       *  Constant: '<S224>/CrCtl_DeclPWinPos1_C'
       */
      CrCtl_B.I = CrCtl_DeclIWinPos1_C;
      CrCtl_B.P = CrCtl_DeclPWinPos1_C;
    }

    /* End of MultiPortSwitch: '<S224>/Index Vector15' */
    /* End of Outputs for SubSystem: '<S213>/DECL' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S213>/CRCTL_RESBLW(=6h)' incorporates:
     *  ActionPort: '<S223>/Action Port'
     */
    /* RelationalOperator: '<S223>/Relational Operator4' incorporates:
     *  Constant: '<S223>/CrCtl_vPIGovDvt_C3_10mphSW'
     */
    rtb_RelationalOperator17_o = (Subtract > CrCtl_vPIGovDvt_C3_10mphSW);

    /* RelationalOperator: '<S223>/Relational Operator3' incorporates:
     *  Constant: '<S223>/CrCtl_vPIGovDvt_C4_10mphSW'
     */
    rtb_RelationalOperator16_k = (Subtract > CrCtl_vPIGovDvt_C4_10mphSW);

    /* RelationalOperator: '<S223>/Relational Operator2' incorporates:
     *  Constant: '<S223>/CrCtl_vPIGovDvt_C2_10mphSW'
     */
    rtb_RelationalOperator15_b = (Subtract > CrCtl_vPIGovDvt_C2_10mphSW);

    /* RelationalOperator: '<S223>/Relational Operator12' incorporates:
     *  Constant: '<S223>/CrCtl_vPIGovDvt_C1_10mphSW'
     */
    rtb_RelationalOperator14_e = (Subtract > CrCtl_vPIGovDvt_C1_10mphSW);

    /* MultiPortSwitch: '<S223>/Index Vector1' incorporates:
     *  Constant: '<S223>/CrCtl_stParSelThres1_C'
     *  MultiPortSwitch: '<S223>/Index Vector10'
     *  RelationalOperator: '<S223>/Relational Operator'
     */
    if (!(CrCtl_B.Gearbx_stGear < CrCtl_stParSelThres1_C)) {
      /* MultiPortSwitch: '<S223>/Index Vector' incorporates:
       *  Constant: '<S223>/CrCtl_stParSelThres2_C'
       *  MultiPortSwitch: '<S223>/Index Vector6'
       *  RelationalOperator: '<S223>/Relational Operator1'
       */
      if (!(CrCtl_B.Gearbx_stGear > CrCtl_stParSelThres2_C)) {
        /* MultiPortSwitch: '<S223>/Index Vector2' incorporates:
         *  Constant: '<S223>/CrCtl_ResHoldIWinPos2_C'
         *  Constant: '<S223>/CrCtl_ResHoldPWinPos2_C'
         */
        if (!rtb_RelationalOperator14_e) {
          /* MultiPortSwitch: '<S223>/Index Vector3' incorporates:
           *  Constant: '<S223>/CrCtl_ResHoldIKiPos2_C'
           *  Constant: '<S223>/CrCtl_ResHoldPKpPos2_C'
           */
          if (!rtb_RelationalOperator15_b) {
            /* MultiPortSwitch: '<S223>/Index Vector4' incorporates:
             *  Constant: '<S223>/CrCtl_ResHoldIKi2_C'
             *  Constant: '<S223>/CrCtl_ResHoldPKp2_C'
             */
            if (!rtb_RelationalOperator17_o) {
              /* MultiPortSwitch: '<S223>/Index Vector5' incorporates:
               *  Constant: '<S223>/CrCtl_ResHoldIKiNeg2_C'
               *  Constant: '<S223>/CrCtl_ResHoldIWinNeg2_C'
               *  Constant: '<S223>/CrCtl_ResHoldPKpNeg2_C'
               *  Constant: '<S223>/CrCtl_ResHoldPWinNeg2_C'
               */
              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.I = CrCtl_ResHoldIWinNeg2_C;
              } else {
                CrCtl_B.I = CrCtl_ResHoldIKiNeg2_C;
              }

              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.P = CrCtl_ResHoldPWinNeg2_C;
              } else {
                CrCtl_B.P = CrCtl_ResHoldPKpNeg2_C;
              }

              /* End of MultiPortSwitch: '<S223>/Index Vector5' */
            } else {
              CrCtl_B.I = CrCtl_ResHoldIKi2_C;
              CrCtl_B.P = CrCtl_ResHoldPKp2_C;
            }

            /* End of MultiPortSwitch: '<S223>/Index Vector4' */
          } else {
            CrCtl_B.I = CrCtl_ResHoldIKiPos2_C;
            CrCtl_B.P = CrCtl_ResHoldPKpPos2_C;
          }

          /* End of MultiPortSwitch: '<S223>/Index Vector3' */
        } else {
          CrCtl_B.I = CrCtl_ResHoldIWinPos2_C;
          CrCtl_B.P = CrCtl_ResHoldPWinPos2_C;
        }

        /* End of MultiPortSwitch: '<S223>/Index Vector2' */
      } else if (!rtb_RelationalOperator14_e) {
        /* MultiPortSwitch: '<S223>/Index Vector7' incorporates:
         *  Constant: '<S223>/CrCtl_ResHoldIKiPos3_C'
         *  Constant: '<S223>/CrCtl_ResHoldPKpPos3_C'
         *  MultiPortSwitch: '<S223>/Index Vector6'
         */
        if (!rtb_RelationalOperator15_b) {
          /* MultiPortSwitch: '<S223>/Index Vector8' incorporates:
           *  Constant: '<S223>/CrCtl_ResHoldIKi3_C'
           *  Constant: '<S223>/CrCtl_ResHoldPKp3_C'
           */
          if (!rtb_RelationalOperator17_o) {
            /* MultiPortSwitch: '<S223>/Index Vector9' incorporates:
             *  Constant: '<S223>/CrCtl_ResHoldIKiNeg3_C'
             *  Constant: '<S223>/CrCtl_ResHoldIWinNeg3_C'
             *  Constant: '<S223>/CrCtl_ResHoldPKpNeg3_C'
             *  Constant: '<S223>/CrCtl_ResHoldPWinNeg3_C'
             */
            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.I = CrCtl_ResHoldIWinNeg3_C;
            } else {
              CrCtl_B.I = CrCtl_ResHoldIKiNeg3_C;
            }

            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.P = CrCtl_ResHoldPWinNeg3_C;
            } else {
              CrCtl_B.P = CrCtl_ResHoldPKpNeg3_C;
            }

            /* End of MultiPortSwitch: '<S223>/Index Vector9' */
          } else {
            CrCtl_B.I = CrCtl_ResHoldIKi3_C;
            CrCtl_B.P = CrCtl_ResHoldPKp3_C;
          }

          /* End of MultiPortSwitch: '<S223>/Index Vector8' */
        } else {
          CrCtl_B.I = CrCtl_ResHoldIKiPos3_C;
          CrCtl_B.P = CrCtl_ResHoldPKpPos3_C;
        }

        /* End of MultiPortSwitch: '<S223>/Index Vector7' */
      } else {
        /* MultiPortSwitch: '<S223>/Index Vector6' incorporates:
         *  Constant: '<S223>/CrCtl_ResHoldIWinPos3_C'
         *  Constant: '<S223>/CrCtl_ResHoldPWinPos3_C'
         */
        CrCtl_B.I = CrCtl_ResHoldIWinPos3_C;
        CrCtl_B.P = CrCtl_ResHoldPWinPos3_C;
      }

      /* End of MultiPortSwitch: '<S223>/Index Vector' */
    } else if (!rtb_RelationalOperator14_e) {
      /* MultiPortSwitch: '<S223>/Index Vector11' incorporates:
       *  Constant: '<S223>/CrCtl_ResHoldIKiPos1_C'
       *  Constant: '<S223>/CrCtl_ResHoldPKpPos1_C'
       *  MultiPortSwitch: '<S223>/Index Vector10'
       */
      if (!rtb_RelationalOperator15_b) {
        /* MultiPortSwitch: '<S223>/Index Vector12' incorporates:
         *  Constant: '<S223>/CrCtl_ResHoldIKi1_C'
         *  Constant: '<S223>/CrCtl_ResHoldPKp1_C'
         */
        if (!rtb_RelationalOperator17_o) {
          /* MultiPortSwitch: '<S223>/Index Vector13' incorporates:
           *  Constant: '<S223>/CrCtl_ResHoldIKiNeg1_C'
           *  Constant: '<S223>/CrCtl_ResHoldIWinNeg1_C'
           *  Constant: '<S223>/CrCtl_ResHoldPKpNeg1_C'
           *  Constant: '<S223>/CrCtl_ResHoldPWinNeg1_C'
           */
          if (!rtb_RelationalOperator16_k) {
            CrCtl_B.I = CrCtl_ResHoldIWinNeg1_C;
            CrCtl_B.P = CrCtl_ResHoldPWinNeg1_C;
          } else {
            CrCtl_B.I = CrCtl_ResHoldIKiNeg1_C;
            CrCtl_B.P = CrCtl_ResHoldPKpNeg1_C;
          }

          /* End of MultiPortSwitch: '<S223>/Index Vector13' */
        } else {
          CrCtl_B.I = CrCtl_ResHoldIKi1_C;
          CrCtl_B.P = CrCtl_ResHoldPKp1_C;
        }

        /* End of MultiPortSwitch: '<S223>/Index Vector12' */
      } else {
        CrCtl_B.I = CrCtl_ResHoldIKiPos1_C;
        CrCtl_B.P = CrCtl_ResHoldPKpPos1_C;
      }

      /* End of MultiPortSwitch: '<S223>/Index Vector11' */
    } else {
      /* MultiPortSwitch: '<S223>/Index Vector10' incorporates:
       *  Constant: '<S223>/CrCtl_ResHoldIWinPos1_C'
       *  Constant: '<S223>/CrCtl_ResHoldPWinPos1_C'
       */
      CrCtl_B.I = CrCtl_ResHoldIWinPos1_C;
      CrCtl_B.P = CrCtl_ResHoldPWinPos1_C;
    }

    /* End of MultiPortSwitch: '<S223>/Index Vector1' */
    /* End of Outputs for SubSystem: '<S213>/CRCTL_RESBLW(=6h)' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S213>/CRCTL_RESABV(=5h)' incorporates:
     *  ActionPort: '<S222>/Action Port'
     */
    /* RelationalOperator: '<S222>/Relational Operator17' incorporates:
     *  Constant: '<S222>/CrCtl_vPIGovDvt_C3_10mphSW'
     */
    rtb_RelationalOperator17_o = (Subtract > CrCtl_vPIGovDvt_C3_10mphSW);

    /* RelationalOperator: '<S222>/Relational Operator16' incorporates:
     *  Constant: '<S222>/CrCtl_vPIGovDvt_C4_10mphSW'
     */
    rtb_RelationalOperator16_k = (Subtract > CrCtl_vPIGovDvt_C4_10mphSW);

    /* RelationalOperator: '<S222>/Relational Operator15' incorporates:
     *  Constant: '<S222>/CrCtl_vPIGovDvt_C2_10mphSW'
     */
    rtb_RelationalOperator15_b = (Subtract > CrCtl_vPIGovDvt_C2_10mphSW);

    /* RelationalOperator: '<S222>/Relational Operator14' incorporates:
     *  Constant: '<S222>/CrCtl_vPIGovDvt_C1_10mphSW'
     */
    rtb_RelationalOperator14_e = (Subtract > CrCtl_vPIGovDvt_C1_10mphSW);

    /* MultiPortSwitch: '<S222>/Index Vector1' incorporates:
     *  Constant: '<S222>/CrCtl_stParSelThres1_C1'
     *  MultiPortSwitch: '<S222>/Index Vector14'
     *  RelationalOperator: '<S222>/Relational Operator'
     */
    if (!(CrCtl_B.Gearbx_stGear < CrCtl_stParSelThres1_C)) {
      /* MultiPortSwitch: '<S222>/Index Vector' incorporates:
       *  Constant: '<S222>/CrCtl_stParSelThres2_C1'
       *  MultiPortSwitch: '<S222>/Index Vector22'
       *  RelationalOperator: '<S222>/Relational Operator1'
       */
      if (!(CrCtl_B.Gearbx_stGear > CrCtl_stParSelThres2_C)) {
        /* MultiPortSwitch: '<S222>/Index Vector18' incorporates:
         *  Constant: '<S222>/CrCtl_ResIWinPos2_C'
         *  Constant: '<S222>/CrCtl_ResPWinPos2_C'
         */
        if (!rtb_RelationalOperator14_e) {
          /* MultiPortSwitch: '<S222>/Index Vector19' incorporates:
           *  Constant: '<S222>/CrCtl_ResIKiPos2_C'
           *  Constant: '<S222>/CrCtl_ResPKpPos2_C'
           */
          if (!rtb_RelationalOperator15_b) {
            /* MultiPortSwitch: '<S222>/Index Vector20' incorporates:
             *  Constant: '<S222>/CrCtl_ResIKi2_C'
             *  Constant: '<S222>/CrCtl_ResPKp2_C'
             */
            if (!rtb_RelationalOperator17_o) {
              /* MultiPortSwitch: '<S222>/Index Vector21' incorporates:
               *  Constant: '<S222>/CrCtl_ResIKiNeg2_C'
               *  Constant: '<S222>/CrCtl_ResIWinNeg2_C'
               *  Constant: '<S222>/CrCtl_ResPKpNeg2_C'
               *  Constant: '<S222>/CrCtl_ResPWinNeg2_C'
               */
              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.I = CrCtl_ResIWinNeg2_C;
              } else {
                CrCtl_B.I = CrCtl_ResIKiNeg2_C;
              }

              if (!rtb_RelationalOperator16_k) {
                CrCtl_B.P = CrCtl_ResPWinNeg2_C;
              } else {
                CrCtl_B.P = CrCtl_ResPKpNeg2_C;
              }

              /* End of MultiPortSwitch: '<S222>/Index Vector21' */
            } else {
              CrCtl_B.I = CrCtl_ResIKi2_C;
              CrCtl_B.P = CrCtl_ResPKp2_C;
            }

            /* End of MultiPortSwitch: '<S222>/Index Vector20' */
          } else {
            CrCtl_B.I = CrCtl_ResIKiPos2_C;
            CrCtl_B.P = CrCtl_ResPKpPos2_C;
          }

          /* End of MultiPortSwitch: '<S222>/Index Vector19' */
        } else {
          CrCtl_B.I = CrCtl_ResIWinPos2_C;
          CrCtl_B.P = CrCtl_ResPWinPos2_C;
        }

        /* End of MultiPortSwitch: '<S222>/Index Vector18' */
      } else if (!rtb_RelationalOperator14_e) {
        /* MultiPortSwitch: '<S222>/Index Vector23' incorporates:
         *  Constant: '<S222>/CrCtl_ResIKiPos3_C'
         *  Constant: '<S222>/CrCtl_ResPKpPos3_C'
         *  MultiPortSwitch: '<S222>/Index Vector22'
         */
        if (!rtb_RelationalOperator15_b) {
          /* MultiPortSwitch: '<S222>/Index Vector24' incorporates:
           *  Constant: '<S222>/CrCtl_ResIKi3_C'
           *  Constant: '<S222>/CrCtl_ResPKp3_C'
           */
          if (!rtb_RelationalOperator17_o) {
            /* MultiPortSwitch: '<S222>/Index Vector25' incorporates:
             *  Constant: '<S222>/CrCtl_ResIKiNeg3_C'
             *  Constant: '<S222>/CrCtl_ResIWinNeg3_C'
             *  Constant: '<S222>/CrCtl_ResPKpNeg3_C'
             *  Constant: '<S222>/CrCtl_ResPWinNeg3_C'
             */
            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.I = CrCtl_ResIWinNeg3_C;
            } else {
              CrCtl_B.I = CrCtl_ResIKiNeg3_C;
            }

            if (!rtb_RelationalOperator16_k) {
              CrCtl_B.P = CrCtl_ResPWinNeg3_C;
            } else {
              CrCtl_B.P = CrCtl_ResPKpNeg3_C;
            }

            /* End of MultiPortSwitch: '<S222>/Index Vector25' */
          } else {
            CrCtl_B.I = CrCtl_ResIKi3_C;
            CrCtl_B.P = CrCtl_ResPKp3_C;
          }

          /* End of MultiPortSwitch: '<S222>/Index Vector24' */
        } else {
          CrCtl_B.I = CrCtl_ResIKiPos3_C;
          CrCtl_B.P = CrCtl_ResPKpPos3_C;
        }

        /* End of MultiPortSwitch: '<S222>/Index Vector23' */
      } else {
        /* MultiPortSwitch: '<S222>/Index Vector22' incorporates:
         *  Constant: '<S222>/CrCtl_ResIWinPos3_C'
         *  Constant: '<S222>/CrCtl_ResPWinPos3_C'
         */
        CrCtl_B.I = CrCtl_ResIWinPos3_C;
        CrCtl_B.P = CrCtl_ResPWinPos3_C;
      }

      /* End of MultiPortSwitch: '<S222>/Index Vector' */
    } else if (!rtb_RelationalOperator14_e) {
      /* MultiPortSwitch: '<S222>/Index Vector15' incorporates:
       *  Constant: '<S222>/CrCtl_ResIKiPos1_C'
       *  Constant: '<S222>/CrCtl_ResPKpPos1_C'
       *  MultiPortSwitch: '<S222>/Index Vector14'
       */
      if (!rtb_RelationalOperator15_b) {
        /* MultiPortSwitch: '<S222>/Index Vector16' incorporates:
         *  Constant: '<S222>/CrCtl_ResIKi1_C'
         *  Constant: '<S222>/CrCtl_ResPKp1_C'
         */
        if (!rtb_RelationalOperator17_o) {
          /* MultiPortSwitch: '<S222>/Index Vector17' incorporates:
           *  Constant: '<S222>/CrCtl_ResIKiNeg1_C'
           *  Constant: '<S222>/CrCtl_ResIWinNeg1_C'
           *  Constant: '<S222>/CrCtl_ResPKpNeg1_C'
           *  Constant: '<S222>/CrCtl_ResPWinNeg1_C'
           */
          if (!rtb_RelationalOperator16_k) {
            CrCtl_B.I = CrCtl_ResIWinNeg1_C;
            CrCtl_B.P = CrCtl_ResPWinNeg1_C;
          } else {
            CrCtl_B.I = CrCtl_ResIKiNeg1_C;
            CrCtl_B.P = CrCtl_ResPKpNeg1_C;
          }

          /* End of MultiPortSwitch: '<S222>/Index Vector17' */
        } else {
          CrCtl_B.I = CrCtl_ResIKi1_C;
          CrCtl_B.P = CrCtl_ResPKp1_C;
        }

        /* End of MultiPortSwitch: '<S222>/Index Vector16' */
      } else {
        CrCtl_B.I = CrCtl_ResIKiPos1_C;
        CrCtl_B.P = CrCtl_ResPKpPos1_C;
      }

      /* End of MultiPortSwitch: '<S222>/Index Vector15' */
    } else {
      /* MultiPortSwitch: '<S222>/Index Vector14' incorporates:
       *  Constant: '<S222>/CrCtl_ResIWinPos1_C'
       *  Constant: '<S222>/CrCtl_ResPWinPos1_C'
       */
      CrCtl_B.I = CrCtl_ResIWinPos1_C;
      CrCtl_B.P = CrCtl_ResPWinPos1_C;
    }

    /* End of MultiPortSwitch: '<S222>/Index Vector1' */
    /* End of Outputs for SubSystem: '<S213>/CRCTL_RESABV(=5h)' */
    break;
  }

  /* End of SwitchCase: '<S213>/Switch Case1' */

  /* Sum: '<S212>/Sum' incorporates:
   *  DiscreteIntegrator: '<S212>/Integrator'
   *  Product: '<S217>/POut'
   */
  Sum = Subtract * CrCtl_B.P + CrCtl_DW.Integrator_DSTATE;

  /* MultiPortSwitch: '<S215>/Index Vector' incorporates:
   *  RelationalOperator: '<S218>/LowerRelop1'
   *  RelationalOperator: '<S218>/UpperRelop'
   *  Switch: '<S218>/Switch'
   *  Switch: '<S218>/Switch2'
   */
  if (CrCtl_B.isUsePI == 0) {
    rtb_CrCtl_trqDes_10mNmSL = CrCtl_B.CrCtl_trqDes;
  } else if (Sum > CrCtl_B.Gain) {
    /* Switch: '<S218>/Switch2' */
    rtb_CrCtl_trqDes_10mNmSL = CrCtl_B.Gain;
  } else if (Sum < -1L) {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_CrCtl_trqDes_10mNmSL = -1L;
  } else {
    rtb_CrCtl_trqDes_10mNmSL = Sum;
  }

  /* End of MultiPortSwitch: '<S215>/Index Vector' */

  /* Switch: '<S215>/Switch2' incorporates:
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Inport: '<Root>/RefRtdrTrq_NmUW'
   */
  if (rtb_CrCtl_trqDes_10mNmSL >= 0L) {
    rtb_Switch2_n = EngReferenceTorque_NmUW;
  } else {
    rtb_Switch2_n = RefRtdrTrq_NmUW;
  }

  /* End of Switch: '<S215>/Switch2' */

  /* Switch: '<S215>/Switch3' incorporates:
   *  Constant: '<S215>/Constant3'
   *  Product: '<S215>/Divide3'
   */
  if (rtb_Switch2_n != 0U) {
    EngRqedTorque_TorqueLimit_SB = div_s8s32_floor(rtb_CrCtl_trqDes_10mNmSL,
      rtb_Switch2_n);
  } else {
    EngRqedTorque_TorqueLimit_SB = 0;
  }

  /* End of Switch: '<S215>/Switch3' */

  /* MultiPortSwitch: '<S215>/Index Vector2' incorporates:
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Inport: '<Root>/RefRtdrTrq_NmUW'
   *  RelationalOperator: '<S215>/Relational Operator1'
   */
  if (!(EngRqedTorque_TorqueLimit_SB < 0)) {
    rtb_Switch2_n = EngReferenceTorque_NmUW;
  } else {
    rtb_Switch2_n = RefRtdrTrq_NmUW;
  }

  /* End of MultiPortSwitch: '<S215>/Index Vector2' */

  /* Product: '<S215>/Product' */
  CrCtl_trqDes_10mNmSL = (int32_T)EngRqedTorque_TorqueLimit_SB * rtb_Switch2_n;

  /* MultiPortSwitch: '<S215>/Index Vector5' incorporates:
   *  Constant: '<S215>/CRCTL_OVERRIDE_2h'
   *  Constant: '<S215>/noAccPed1'
   *  Gain: '<S215>/Gain'
   *  Inport: '<Root>/AccPedPos1_pctUB'
   *  Logic: '<S215>/Logical Operator1'
   *  RelationalOperator: '<S215>/Relational Operator4'
   *  RelationalOperator: '<S215>/Relational Operator5'
   */
  if (!((AccPedPos1_pctUB > 0) && (100L * CrCtl_B.AccPed_trqDes_NmSW >
        rtb_CrCtl_trqDes_10mNmSL))) {
    /* MultiPortSwitch: '<S215>/Index Vector4' incorporates:
     *  Constant: '<S215>/CRCTL_NOTACTV_0h'
     *  Constant: '<S215>/CRCTL_SUSPENDRAMPDONE_2h'
     *  Constant: '<S215>/SHIFTINPROCESS_1h'
     *  Inport: '<Root>/ETC1_trsSftPrcs_UB'
     *  Logic: '<S215>/Logical Operator'
     *  RelationalOperator: '<S215>/Relational Operator2'
     *  RelationalOperator: '<S215>/Relational Operator6'
     */
    if (!((ETC1_trsSftPrcs_UB == ((uint8_T)SHIFTINPROCESS)) || (0 == ((uint8_T)
           CRCTL_SUSPENDRAMPDONE)))) {
      CrCtl_stOpFunc_UB = CrCtl_B.CrCtl_stOpFunc;
    } else {
      CrCtl_stOpFunc_UB = ((uint8_T)CRCTL_NOTACTV);
    }

    /* End of MultiPortSwitch: '<S215>/Index Vector4' */
  } else {
    CrCtl_stOpFunc_UB = ((uint8_T)CRCTL_OVERRIDE);
  }

  /* End of MultiPortSwitch: '<S215>/Index Vector5' */

  /* Switch: '<S220>/Switch' incorporates:
   *  RelationalOperator: '<S220>/u_GTE_up'
   *  RelationalOperator: '<S220>/u_GT_lo'
   *  Switch: '<S220>/Switch1'
   */
  if (Sum >= CrCtl_B.Gain) {
    rtb_CrCtl_trqDes_10mNmSL = CrCtl_B.Gain;
  } else if (Sum > CrCtl_ConstB.DataTypeConv3) {
    /* Switch: '<S220>/Switch1' */
    rtb_CrCtl_trqDes_10mNmSL = Sum;
  } else {
    rtb_CrCtl_trqDes_10mNmSL = CrCtl_ConstB.DataTypeConv3;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Sum: '<S220>/Diff' */
  CrCtl_B.Switch_o = Sum - rtb_CrCtl_trqDes_10mNmSL;

  /* RelationalOperator: '<S219>/NotEqual' incorporates:
   *  Gain: '<S219>/ZeroGain'
   */
  rtb_RelationalOperator17_o = (0L != CrCtl_B.Switch_o);

  /* Signum: '<S219>/SignDeltaU' */
  if (CrCtl_B.Switch_o < 0L) {
    CrCtl_B.Switch_o = -1L;
  } else {
    CrCtl_B.Switch_o = ((uint32_T)CrCtl_B.Switch_o > 0UL);
  }

  /* End of Signum: '<S219>/SignDeltaU' */

  /* DataTypeConversion: '<S219>/DataTypeConv1' */
  rtb_IndexVector3_a = (int16_T)CrCtl_B.Switch_o;

  /* Product: '<S212>/IOut' */
  CrCtl_B.Switch_o = Subtract * CrCtl_B.I;

  /* Signum: '<S219>/SignPreIntegrator' */
  if (CrCtl_B.Switch_o < 0L) {
    Subtract = -1L;
  } else {
    Subtract = ((uint32_T)CrCtl_B.Switch_o > 0UL);
  }

  /* End of Signum: '<S219>/SignPreIntegrator' */

  /* Switch: '<S212>/Switch' incorporates:
   *  Constant: '<S212>/Constant'
   *  DataTypeConversion: '<S219>/DataTypeConv1'
   *  DataTypeConversion: '<S219>/DataTypeConv2'
   *  Logic: '<S219>/AND'
   *  RelationalOperator: '<S219>/Equal'
   */
  if (rtb_RelationalOperator17_o && ((int8_T)rtb_IndexVector3_a == (int16_T)
       Subtract)) {
    CrCtl_B.Switch_o = 0L;
  }

  /* End of Switch: '<S212>/Switch' */

  /* Sum: '<S215>/Subtract' incorporates:
   *  Inport: '<Root>/ETC2_trsCrntGr_SB'
   *  Inport: '<Root>/PCC_targetGear_SB'
   *
   * Block description for '<Root>/ETC2_trsCrntGr_SB':
   *  SPN 523 Transmission Current Gear. -125 to +125, negative values are
   *  reverse gears, positive values are forward gears, zero is neutral. 251
   *  (0xFB) is park.
   *
   * Block description for '<Root>/PCC_targetGear_SB':
   *  PCC target gear that require TCU to act
   */
  Subtract_m = (int8_T)(PCC_targetGear_SB - ETC2_trsCrntGr_SB);

  /* Chart: '<S215>/Chart1' */
  if (Subtract_m >= 2) {
    CrCtl_TC1TrsReqGear_UB = ((uint8_T)UPSHIFT2);
  } else {
    switch (Subtract_m) {
     case 1:
      CrCtl_TC1TrsReqGear_UB = ((uint8_T)UPSHIFT1);
      break;

     case 0:
      CrCtl_TC1TrsReqGear_UB = ((uint8_T)HOLDCURRENTGEAR);
      break;

     case -1:
      CrCtl_TC1TrsReqGear_UB = ((uint8_T)DOWNSHIFT2);
      break;

     default:
      if (Subtract_m <= -2) {
        CrCtl_TC1TrsReqGear_UB = ((uint8_T)DOWNSHIFT2);
      }
      break;
    }
  }

  /* End of Chart: '<S215>/Chart1' */

  /* Chart: '<S229>/manualShiftSuspChart' incorporates:
   *  Constant: '<S250>/CrCtl_swtSusRmpStp_C'
   *  Memory: '<S229>/Memory1'
   *  MultiPortSwitch: '<S250>/Index Vector3'
   */
  if (CrCtl_DW.is_active_c16_CrCtl == 0U) {
    CrCtl_DW.is_active_c16_CrCtl = 1U;
    CrCtl_DW.is_c16_CrCtl = CrCtl_IN_CRCTL_SUSPENDNOTACTIVE_0h;

    /* SignalConversion: '<S251>/OutportBufferForCrCtl_stSuspRamp_mp' incorporates:
     *  Constant: '<S251>/CRCTL_SUSPENDNOTACTIVE_0h'
     */
    CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDNOTACTIVE);
  } else {
    switch (CrCtl_DW.is_c16_CrCtl) {
     case CrCtl_IN_CRCTL_SUSPENDENDRAMP_3h:
      if (CrCtl_B.CrCtl_stSuspRamp_mp == 0) {
        CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h = 0;
        CrCtl_DW.is_c16_CrCtl = CrCtl_IN_CRCTL_SUSPENDNOTACTIVE_0h;

        /* SignalConversion: '<S251>/OutportBufferForCrCtl_stSuspRamp_mp' incorporates:
         *  Constant: '<S251>/CRCTL_SUSPENDNOTACTIVE_0h'
         */
        CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDNOTACTIVE);
      } else if (CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h == CrCtl_IN_StepOutSuspend)
      {
        CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h = CrCtl_IN_SuspendEndRump;

        /* MultiPortSwitch: '<S250>/Index Vector3' incorporates:
         *  Constant: '<S250>/CrCtl_swtSusRmpStp_C'
         *  Constant: '<S250>/T_ms1'
         *  DataStoreRead: '<S250>/Data Store Read1'
         *  Product: '<S250>/Product2'
         */
        if (!CrCtl_swtSusRmpStp_C) {
          /* MultiPortSwitch: '<S250>/Index Vector2' incorporates:
           *  Constant: '<S250>/CrCtl_facSlpRmp2Sus_C'
           *  DataStoreRead: '<S250>/Data Store Read1'
           *  Gain: '<S250>/Gain1'
           *  RelationalOperator: '<S250>/Relational Operator3'
           */
          if (!(0 > CrCtl_DW.CrCtl_trqOldVal_mp)) {
            /* MultiPortSwitch: '<S250>/Index Vector4' incorporates:
             *  Constant: '<S250>/CrCtl_facSlpRmp2Sus_C'
             *  Constant: '<S250>/noRmp'
             *  RelationalOperator: '<S250>/Relational Operator2'
             */
            if (!(CrCtl_DW.CrCtl_trqOldVal_mp >= 0)) {
              Subtract_m = 0;
            } else {
              Subtract_m = (int8_T)CrCtl_facSlpRmp2Sus_C;
            }
          } else {
            Subtract_m = (int8_T)-CrCtl_facSlpRmp2Sus_C;
          }

          rtb_IndexVector3_a = Subtract_m * ((uint8_T)T_ms);
        } else {
          rtb_IndexVector3_a = CrCtl_DW.CrCtl_trqOldVal_mp;
        }

        /* MultiPortSwitch: '<S250>/Index Vector1' incorporates:
         *  Constant: '<S250>/CRCTL_SUSPENDNOTACTIVE_0h'
         *  Constant: '<S250>/Constant'
         *  DataStoreRead: '<S250>/Data Store Read1'
         *  Memory: '<S229>/Memory'
         *  Product: '<S250>/Product'
         *  RelationalOperator: '<S250>/Relational Operator1'
         *  Sum: '<S250>/Subtract'
         *  Sum: '<S250>/Subtract1'
         */
        if (!((int32_T)(rtb_IndexVector3_a - CrCtl_DW.CrCtl_trqOldVal_mp) *
              -CrCtl_DW.CrCtl_trqOldVal_mp <= 0L)) {
          CrCtl_B.CrCtl_stSuspRamp_mp = CrCtl_DW.Memory_PreviousInput_f;
        } else {
          CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDNOTACTIVE);
        }
      } else {
        if (!CrCtl_swtSusRmpStp_C) {
          /* MultiPortSwitch: '<S250>/Index Vector2' incorporates:
           *  Constant: '<S250>/CrCtl_facSlpRmp2Sus_C'
           *  DataStoreRead: '<S250>/Data Store Read1'
           *  Gain: '<S250>/Gain1'
           *  MultiPortSwitch: '<S250>/Index Vector3'
           *  RelationalOperator: '<S250>/Relational Operator3'
           */
          if (!(0 > CrCtl_DW.CrCtl_trqOldVal_mp)) {
            /* MultiPortSwitch: '<S250>/Index Vector4' incorporates:
             *  Constant: '<S250>/CrCtl_facSlpRmp2Sus_C'
             *  Constant: '<S250>/noRmp'
             *  RelationalOperator: '<S250>/Relational Operator2'
             */
            if (!(CrCtl_DW.CrCtl_trqOldVal_mp >= 0)) {
              Subtract_m = 0;
            } else {
              Subtract_m = (int8_T)CrCtl_facSlpRmp2Sus_C;
            }
          } else {
            Subtract_m = (int8_T)-CrCtl_facSlpRmp2Sus_C;
          }

          /* MultiPortSwitch: '<S250>/Index Vector3' incorporates:
           *  Constant: '<S250>/T_ms1'
           *  Product: '<S250>/Product2'
           */
          rtb_IndexVector3_a = Subtract_m * ((uint8_T)T_ms);
        } else {
          /* MultiPortSwitch: '<S250>/Index Vector3' incorporates:
           *  DataStoreRead: '<S250>/Data Store Read1'
           */
          rtb_IndexVector3_a = CrCtl_DW.CrCtl_trqOldVal_mp;
        }

        /* MultiPortSwitch: '<S250>/Index Vector1' incorporates:
         *  Constant: '<S250>/CRCTL_SUSPENDNOTACTIVE_0h'
         *  Constant: '<S250>/Constant'
         *  DataStoreRead: '<S250>/Data Store Read1'
         *  Memory: '<S229>/Memory'
         *  Product: '<S250>/Product'
         *  RelationalOperator: '<S250>/Relational Operator1'
         *  Sum: '<S250>/Subtract'
         *  Sum: '<S250>/Subtract1'
         */
        if (!((int32_T)(rtb_IndexVector3_a - CrCtl_DW.CrCtl_trqOldVal_mp) *
              -CrCtl_DW.CrCtl_trqOldVal_mp <= 0L)) {
          CrCtl_B.CrCtl_stSuspRamp_mp = CrCtl_DW.Memory_PreviousInput_f;
        } else {
          CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDNOTACTIVE);
        }
      }
      break;

     case CrCtl_IN_CRCTL_SUSPENDNOTACTIVE_0h:
      /* SignalConversion: '<S251>/OutportBufferForCrCtl_stSuspRamp_mp' incorporates:
       *  Constant: '<S251>/CRCTL_SUSPENDNOTACTIVE_0h'
       */
      CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDNOTACTIVE);
      break;

     case CrCtl_IN_CRCTL_SUSPENDRAMPDONE_2h:
      if (CrCtl_DW.Memory1_PreviousInput == 1.0) {
        CrCtl_DW.is_c16_CrCtl = CrCtl_IN_CRCTL_SUSPENDENDRAMP_3h;
        CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h = CrCtl_IN_StepOutSuspend;

        /* SignalConversion: '<S249>/OutportBufferForCrCtl_stSuspRamp_mp' incorporates:
         *  Constant: '<S249>/CRCTL_SUSPENDENDRAMP_3h'
         */
        CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDENDRAMP);
      }
      break;

     default:
      if (CrCtl_B.CrCtl_stSuspRamp_mp == 2) {
        CrCtl_DW.is_CRCTL_SUSPENDSTARTRUMP_1h = 0;
        CrCtl_DW.is_c16_CrCtl = CrCtl_IN_CRCTL_SUSPENDRAMPDONE_2h;
      } else if (CrCtl_DW.Memory1_PreviousInput == 1.0) {
        CrCtl_DW.is_CRCTL_SUSPENDSTARTRUMP_1h = 0;
        CrCtl_DW.is_c16_CrCtl = CrCtl_IN_CRCTL_SUSPENDENDRAMP_3h;
        CrCtl_DW.is_CRCTL_SUSPENDENDRAMP_3h = CrCtl_IN_StepOutSuspend;

        /* SignalConversion: '<S249>/OutportBufferForCrCtl_stSuspRamp_mp' incorporates:
         *  Constant: '<S249>/CRCTL_SUSPENDENDRAMP_3h'
         */
        CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDENDRAMP);
      } else if (CrCtl_DW.is_CRCTL_SUSPENDSTARTRUMP_1h ==
                 CrCtl_IN_SUSPENDSTARTRUMP) {
        /* MultiPortSwitch: '<S253>/Index Vector4' incorporates:
         *  Constant: '<S253>/CRCTL_SUSPENDRAMPDONE_2h'
         *  MultiPortSwitch: '<S253>/Index Vector3'
         */
        CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDRAMPDONE);
      } else {
        CrCtl_DW.is_CRCTL_SUSPENDSTARTRUMP_1h = CrCtl_IN_SUSPENDSTARTRUMP;

        /* MultiPortSwitch: '<S253>/Index Vector4' incorporates:
         *  Constant: '<S253>/CRCTL_SUSPENDRAMPDONE_2h'
         *  MultiPortSwitch: '<S253>/Index Vector3'
         */
        CrCtl_B.CrCtl_stSuspRamp_mp = ((uint8_T)CRCTL_SUSPENDRAMPDONE);
      }
      break;
    }
  }

  /* End of Chart: '<S229>/manualShiftSuspChart' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   */
  CrCtl_TC1DisengDiffLckRqFrtAxl1_UB = (uint8_T)CrCtl_PCCAct_BL;

  /* MultiPortSwitch: '<S134>/Index Vector' incorporates:
   *  Constant: '<S134>/CRCTL_HOLD_9h'
   *  Constant: '<S134>/CRCTL_PCC_10h'
   *  Constant: '<S134>/CRCTL_RESABV_5h'
   *  Constant: '<S134>/CRCTL_RESBLW_6h'
   *  Constant: '<S134>/CRCTL_SUBGVNR_8h'
   *  Constant: '<S134>/CRCTL_SUBPREPHOLD_5h'
   *  Constant: '<S134>/CRCTL_SUBRMP_3h'
   *  Constant: '<S134>/dsPCC'
   *  Logic: '<S134>/Logical Operator'
   *  Logic: '<S134>/Logical Operator1'
   *  Logic: '<S134>/Logical Operator2'
   *  Logic: '<S134>/Logical Operator3'
   *  Logic: '<S134>/Logical Operator4'
   *  MultiPortSwitch: '<S134>/Index Vector1'
   *  RelationalOperator: '<S134>/Relational Operator'
   *  RelationalOperator: '<S134>/Relational Operator1'
   *  RelationalOperator: '<S134>/Relational Operator2'
   *  RelationalOperator: '<S134>/Relational Operator3'
   *  RelationalOperator: '<S134>/Relational Operator4'
   *  RelationalOperator: '<S134>/Relational Operator5'
   *  RelationalOperator: '<S134>/Relational Operator6'
   *  RelationalOperator: '<S134>/Relational Operator7'
   */
  if (!(((CrCtl_stModeIn_UB == ((uint8_T)CRCTL_RESBLW)) &&
         ((CrCtl_stModeSubIn_UB == ((uint8_T)CRCTL_SUBPREPHOLD)) ||
          (CrCtl_stModeSubIn_UB == ((uint8_T)CRCTL_SUBRMP)))) ||
        ((CrCtl_stModeIn_UB == ((uint8_T)CRCTL_RESABV)) && (CrCtl_stModeSubIn_UB
         == ((uint8_T)CRCTL_SUBRMP))) || (CrCtl_stModeIn_UB == CRCTL_PCC) ||
        ((CrCtl_stModeIn_UB == ((uint8_T)CRCTL_HOLD)) && (CrCtl_stModeSubIn_UB ==
         ((uint8_T)CRCTL_SUBGVNR))))) {
    CrCtl_enPCC_UB = ((uint8_T)DSPCC);
  } else if (!CrCtl_B.PCC_Mode_BL) {
    /* MultiPortSwitch: '<S134>/Index Vector1' incorporates:
     *  Constant: '<S134>/enPCCBetMode'
     */
    CrCtl_enPCC_UB = ((uint8_T)ENPCCBETMODE);
  } else {
    /* MultiPortSwitch: '<S134>/Index Vector1' incorporates:
     *  Constant: '<S134>/enPCCOptMode'
     */
    CrCtl_enPCC_UB = ((uint8_T)ENPCCOPTMODE);
  }

  /* End of MultiPortSwitch: '<S134>/Index Vector' */

  /* MultiPortSwitch: '<S215>/Index Vector6' incorporates:
   *  Constant: '<S215>/takeNoAction'
   *  Inport: '<Root>/CrCtl_PCCAct_BL'
   */
  if (CrCtl_PCCAct_BL) {
    /* MultiPortSwitch: '<S215>/Index Vector3' incorporates:
     *  Constant: '<S215>/ALLOWDRIVELINEENGG_0h'
     *  Constant: '<S215>/DISDRIVELINE_1h'
     *  Constant: '<S215>/NeutralGear_0h'
     *  Inport: '<Root>/PCC_targetGear_SB'
     *  RelationalOperator: '<S215>/Relational Operator3'
     *
     * Block description for '<Root>/PCC_targetGear_SB':
     *  PCC target gear that require TCU to act
     */
    if (!(PCC_targetGear_SB == ((uint8_T)NEUTRGEAR))) {
      CrCtl_TC1DisengDrvlnReq_UB = ((uint8_T)ALLOWDRIVELINEENGG);
    } else {
      CrCtl_TC1DisengDrvlnReq_UB = ((uint8_T)DISDRIVELINE);
    }

    /* End of MultiPortSwitch: '<S215>/Index Vector3' */
  } else {
    CrCtl_TC1DisengDrvlnReq_UB = 3;
  }

  /* End of MultiPortSwitch: '<S215>/Index Vector6' */
}

/* Update for atomic system: '<Root>/CrCtl_State' */
void CrCtl_CrCtl_State_Update(void)
{
  /* Update for Memory: '<S4>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_c4 = CrCtl_B.CrCtl_vSetPointAct_mp;

  /* Update for Memory: '<S4>/Memory' */
  CrCtl_DW.Memory_PreviousInput_d = CrCtl_B.Merge9_m;

  /* Update for DiscreteIntegrator: '<S212>/Integrator' */
  CrCtl_DW.Integrator_IC_LOADING = 0U;
  CrCtl_DW.Integrator_DSTATE += mul_s32_hiSR(1374389535L, CrCtl_B.Switch_o, 5UL);
  CrCtl_DW.Integrator_PrevResetState = (int8_T)(CrCtl_B.isUsePI > 0);

  /* Update for Memory: '<S229>/Memory' */
  CrCtl_DW.Memory_PreviousInput_f = CrCtl_B.CrCtl_stSuspRamp_mp;

  /* Update for Memory: '<S229>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput = 0.0;
}

/* Function for Chart: '<S5>/MFLvDtctAndPrs' */
static void CrCtl_enter_internal_MFLv_Detection(const boolean_T *setDownBf,
  const boolean_T *setUpBf)
{
  /* Inport: '<Root>/MFLv_swtBL' incorporates:
   *  Inport: '<Root>/MFLv_setDownBL'
   *  Inport: '<Root>/MFLv_setUpBL'
   */
  if (MFLv_swtBL) {
    if (CrCtl_B.CrCtl_stModeFdbck == 1) {
      /* Inport: '<Root>/MFLv_resBL' incorporates:
       *  Inport: '<Root>/MFLv_setDownBL'
       *  Inport: '<Root>/MFLv_setUpBL'
       */
      if (MFLv_resBL) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_RES);
      } else if ((int16_T)*setUpBf > (int16_T)MFLv_setUpBL) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_SET);
        CrCtl_B.PCC_Mode_BL = PCCBETMODE;
      } else if ((int16_T)*setDownBf > (int16_T)MFLv_setDownBL) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_SETOPT);
        CrCtl_B.PCC_Mode_BL = PCCOPTMODE;
      } else {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_NEUTR);
      }

      /* End of Inport: '<Root>/MFLv_resBL' */
    } else if ((CrCtl_B.CrCtl_stModeFdbck == 9) || (CrCtl_B.CrCtl_stModeFdbck ==
                CRCTL_PCC)) {
      if (CrCtl_DW.setUpPress) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_ACC);
      } else if (CrCtl_DW.setDownPress) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_DECL);
      } else if ((int16_T)*setDownBf > (int16_T)MFLv_setDownBL) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_TIPDWN);
      } else if ((int16_T)*setUpBf > (int16_T)MFLv_setUpBL) {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_TIPUP);
      } else {
        MFLv_stCrCtlMode = ((uint8_T)MFLV_NEUTR);
      }
    } else if ((CrCtl_B.CrCtl_stModeFdbck == 8) && CrCtl_DW.setUpPress) {
      MFLv_stCrCtlMode = ((uint8_T)MFLV_ACC);
    } else if ((CrCtl_B.CrCtl_stModeFdbck == 4) && CrCtl_DW.setDownPress) {
      MFLv_stCrCtlMode = ((uint8_T)MFLV_DECL);
    } else {
      MFLv_stCrCtlMode = ((uint8_T)MFLV_NEUTR);
    }
  } else if (!MFLv_swtBL) {
    MFLv_stCrCtlMode = ((uint8_T)MFLV_SWTOFF);
  } else {
    MFLv_stCrCtlMode = 0;
  }

  /* End of Inport: '<Root>/MFLv_swtBL' */
}

/* Function for Chart: '<S5>/MFLvDtctAndPrs' */
static void CrCtl_enter_internal_Key_Press(void)
{
  int16_T tmp;

  /* Update for Inport: '<Root>/MFLv_setUpBL' */
  if (MFLv_setUpBL) {
    tmp = CrCtl_DW.countU + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    CrCtl_DW.countU = (uint8_T)tmp;
    CrCtl_DW.setUpPress = (CrCtl_DW.countU > 100);
  } else {
    CrCtl_DW.countU = 0U;
    CrCtl_DW.setUpPress = false;

    /* Update for Inport: '<Root>/MFLv_setDownBL' */
    if (MFLv_setDownBL) {
      tmp = CrCtl_DW.countD + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      CrCtl_DW.countD = (uint8_T)tmp;
      CrCtl_DW.setDownPress = (CrCtl_DW.countD > 100);
    } else {
      CrCtl_DW.countD = 0U;
      CrCtl_DW.setDownPress = false;
    }

    /* End of Update for Inport: '<Root>/MFLv_setDownBL' */
  }

  /* End of Update for Inport: '<Root>/MFLv_setUpBL' */
}

/* Model step function */
void CrCtl_step(void)
{
  /* local block i/o variables */
  int16_T rtb_TSamp;
  uint16_T rtb_ig_10mUnt;
  int32_T rtb_Product3_g;
  uint32_T tmp;

  /* Memory: '<Root>/Memory' */
  CrCtl_B.CrCtl_stModeFdbck = CrCtl_DW.Memory_PreviousInput_m;

  /* Chart: '<S5>/MFLvDtctAndPrs' */
  if (CrCtl_DW.is_active_c23_CrCtl == 0U) {
    CrCtl_DW.is_active_c23_CrCtl = 1U;
    CrCtl_enter_internal_MFLv_Detection(&CrCtl_DW.setDownBf_PreviousInput,
      &CrCtl_DW.setUpBf_PreviousInput);
    CrCtl_enter_internal_Key_Press();
  } else {
    CrCtl_enter_internal_MFLv_Detection(&CrCtl_DW.setDownBf_PreviousInput,
      &CrCtl_DW.setUpBf_PreviousInput);
    CrCtl_enter_internal_Key_Press();
  }

  /* End of Chart: '<S5>/MFLvDtctAndPrs' */

  /* Lookup_n-D: '<S327>/gear2ig_weiChaiJH6500HP' incorporates:
   *  Constant: '<S327>/CrCtl_gear_12'
   */
  rtb_ig_10mUnt = look1_iu8lu32n16tu16_binlcse(CrCtl_gear,
    CrCtl_ConstP.gear2ig_weiChaiJH6500HP_bp01Data,
    CrCtl_ConstP.gear2ig_weiChaiJH6500HP_tableData, 11UL);

  /* Chart: '<S327>/ig2stGear_weiChaiJH6500HP' */
  if ((rtb_ig_10mUnt >= 78U) && (rtb_ig_10mUnt < 461U)) {
    CrCtl_B.Gearbx_stGear = 1U;
  } else if ((rtb_ig_10mUnt >= 461U) && (rtb_ig_10mUnt < 843U)) {
    CrCtl_B.Gearbx_stGear = 2U;
  } else {
    if ((rtb_ig_10mUnt >= 843U) && (rtb_ig_10mUnt <= 1226U)) {
      CrCtl_B.Gearbx_stGear = 3U;
    }
  }

  /* End of Chart: '<S327>/ig2stGear_weiChaiJH6500HP' */

  /* Product: '<S327>/Product1' incorporates:
   *  Inport: '<Root>/EngSpd_rpmUW'
   */
  tmp = EngSpeed_rpmUW;

  /* Product: '<S327>/Divide5' */
  CrCtl_B.r8 = CrCtl_ConstB.Product4;
  uLong2MultiWord(rtb_ig_10mUnt, &CrCtl_B.r9.chunks[0U], 2);
  uMultiWordDivZero(&CrCtl_B.r8.chunks[0U], 2, &CrCtl_B.r9.chunks[0U], 2,
                    &CrCtl_B.r7.chunks[0U], 2, &CrCtl_B.r10.chunks[0U], 2,
                    &CrCtl_B.r11.chunks[0U], 2, &CrCtl_B.r12.chunks[0U], 2);
  MultiWordUnsignedWrap(&CrCtl_B.r7.chunks[0U], 2, 16U, &CrCtl_B.r6.chunks[0U]);

  /* Product: '<S327>/Divide6' */
  uLong2MultiWord(37UL, &CrCtl_B.r7.chunks[0U], 2);
  uMultiWordDivZero(&CrCtl_B.r6.chunks[0U], 2, &CrCtl_B.r7.chunks[0U], 2,
                    &CrCtl_B.r5.chunks[0U], 2, &CrCtl_B.r8.chunks[0U], 2,
                    &CrCtl_B.r9.chunks[0U], 2, &CrCtl_B.r10.chunks[0U], 2);
  MultiWordUnsignedWrap(&CrCtl_B.r5.chunks[0U], 2, 16U, &CrCtl_B.r4.chunks[0U]);

  /* Product: '<S327>/Divide8' */
  uLong2MultiWord(1000UL, &CrCtl_B.r5.chunks[0U], 2);
  uMultiWordDivZero(&CrCtl_B.r4.chunks[0U], 2, &CrCtl_B.r5.chunks[0U], 2,
                    &CrCtl_B.r3.chunks[0U], 2, &CrCtl_B.r6.chunks[0U], 2,
                    &CrCtl_B.r7.chunks[0U], 2, &CrCtl_B.r8.chunks[0U], 2);
  MultiWordUnsignedWrap(&CrCtl_B.r3.chunks[0U], 2, 16U, &CrCtl_B.r2.chunks[0U]);

  /* Product: '<S327>/Divide9' */
  uLong2MultiWord(1000UL, &CrCtl_B.r3.chunks[0U], 2);
  uMultiWordDivZero(&CrCtl_B.r2.chunks[0U], 2, &CrCtl_B.r3.chunks[0U], 2,
                    &CrCtl_B.r1.chunks[0U], 2, &CrCtl_B.r4.chunks[0U], 2,
                    &CrCtl_B.r5.chunks[0U], 2, &CrCtl_B.r6.chunks[0U], 2);
  MultiWordUnsignedWrap(&CrCtl_B.r1.chunks[0U], 2, 16U, &CrCtl_B.r0.chunks[0U]);

  /* Product: '<S327>/Product1' */
  uMultiWordMul(&tmp, 1, &CrCtl_B.r0.chunks[0U], 2,
                &CrCtl_B.vchSpd_10mph.chunks[0U], 2);

  /* DataTypeConversion: '<S327>/Data Type Conversion1' */
  rtb_ig_10mUnt = (uint16_T)MultiWord2uLong(&CrCtl_B.vchSpd_10mph.chunks[0U]);

  /* MultiPortSwitch: '<S7>/Index Vector' incorporates:
   *  Constant: '<S7>/stc0'
   *  Inport: '<Root>/TachographVehicleSpeed_10mphUW'
   */
  if (stcMovSwt == 0) {
    VSSCD_v_10mphUW = rtb_ig_10mUnt;
  } else {
    VSSCD_v_10mphUW = TachographVehicleSpeed_10mphUW;
  }

  /* End of MultiPortSwitch: '<S7>/Index Vector' */

  /* Product: '<S327>/Divide3' incorporates:
   *  Gain: '<S327>/Gain1'
   *  Inport: '<Root>/EngSpd_rpmUW'
   */
  CrCtl_B.rVn_mmphprpm = div_s16u32(100UL * rtb_ig_10mUnt, EngSpeed_rpmUW);

  /* Memory: '<Root>/Memory1' */
  CrCtl_B.CrCtl_stModeSubFdbck = CrCtl_DW.Memory1_PreviousInput_m;

  /* Memory: '<Root>/00' */
  CrCtl_B.CrCtl_vSetPointTrgtFdbck_10mph = CrCtl_DW.u0_PreviousInput;

  /* SampleTimeMath: '<S328>/TSamp' incorporates:
   *  DataTypeConversion: '<S327>/Data Type Conversion2'
   *  Product: '<S327>/Divide10'
   *  Product: '<S327>/Product5'
   *
   * About '<S328>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = (int16_T)div_nde_s32_floor((int16_T)MultiWord2sLong
    (&CrCtl_B.vchSpd_10mph.chunks[0U]) * 5L, 18L) * 100;

  /* Sum: '<S328>/Diff' incorporates:
   *  UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  CrCtl_B.Diff = rtb_TSamp - CrCtl_DW.UD_DSTATE;

  /* DataTypeConversion: '<S7>/Data Type Conversion9' incorporates:
   *  Gain: '<S7>/Gain7'
   *  Inport: '<Root>/EngSpd_rpmUW'
   */
  CrCtl_B.Eng_nAvrg_10mrpm = (int32_T)((51200UL * EngSpeed_rpmUW) >> 9);

  /* Switch: '<S7>/Switch' incorporates:
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Inport: '<Root>/RefRtdrTrq_NmUW'
   */
  if (CrCtl_DW.Memory2_PreviousInput_i > 0) {
    rtb_ig_10mUnt = EngReferenceTorque_NmUW;
  } else {
    rtb_ig_10mUnt = RefRtdrTrq_NmUW;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Gain: '<S7>/Gain5' incorporates:
   *  Product: '<S7>/Divide1'
   *  Product: '<S7>/Product1'
   */
  CrCtl_B.CrCtl_trqDesIn_10mNm = div_nde_s32_floor((int32_T)
    CrCtl_DW.Memory2_PreviousInput_i * rtb_ig_10mUnt, 100L) * 100L;

  /* Memory: '<Root>/ CRCTL_NOTACTV_0h' */
  CrCtl_B.CrCtl_stOpFuncFdbck_UB = CrCtl_DW.CRCTL_NOTACTV_0h_PreviousInput;

  /* Memory: '<Root>/FALSE' */
  CrCtl_B.CrCtl_stActiveFdbck = CrCtl_DW.FALSE_PreviousInput;

  /* Memory: '<Root>/CRCTL_NOTLCK_0h' */
  CrCtl_B.CrCtl_stLck_fdbck = CrCtl_DW.CRCTL_NOTLCK_0h_PreviousInput;

  /* Memory: '<Root>/CRCTL_NOSHOFFCONACTV_0h' */
  CrCtl_B.CrCtl_stShOffFdbck = CrCtl_DW.CRCTL_NOSHOFFCONACTV_0h_PreviousInput;

  /* Memory: '<Root>/Memory3' */
  CrCtl_B.IndexVector_d = CrCtl_DW.Memory3_PreviousInput_o;

  /* Outputs for Atomic SubSystem: '<Root>/CrCtl_Mode' */
  CrCtl_CrCtl_Mode();

  /* End of Outputs for SubSystem: '<Root>/CrCtl_Mode' */

  /* Outputs for Atomic SubSystem: '<Root>/CrCtl_ShOff' */
  CrCtl_CrCtl_ShOff();

  /* End of Outputs for SubSystem: '<Root>/CrCtl_ShOff' */

  /* MultiPortSwitch: '<S1>/Index Vector' incorporates:
   *  Constant: '<S1>/Accelerate'
   *  Constant: '<S1>/Decelerate//Coast'
   *  Constant: '<S1>/Hold'
   *  Constant: '<S1>/Off//Disable'
   *  Constant: '<S1>/Resume'
   */
  switch (CrCtl_stModeIn_UB) {
   case 1:
    CrCtl_CCVSCCSt_UB = 0;
    break;

   case 2:
    CrCtl_CCVSCCSt_UB = 0;
    break;

   case 3:
    CrCtl_CCVSCCSt_UB = 3;
    break;

   case 4:
    CrCtl_CCVSCCSt_UB = 3;
    break;

   case 5:
    CrCtl_CCVSCCSt_UB = 4;
    break;

   case 6:
    CrCtl_CCVSCCSt_UB = 4;
    break;

   case 7:
    CrCtl_CCVSCCSt_UB = 2;
    break;

   case 8:
    CrCtl_CCVSCCSt_UB = 2;
    break;

   case 9:
    CrCtl_CCVSCCSt_UB = 1;
    break;

   default:
    CrCtl_CCVSCCSt_UB = 1;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Index Vector' */

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/ActualEngPercentTorque_UB'
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Product: '<S7>/Product'
   */
  CrCtl_B.ActlEngPctTrq_Nm = (int32_T)((uint32_T)ActualEngPercentTorque_UB *
    EngReferenceTorque_NmUW / 100UL);

  /* Product: '<S7>/Divide2' incorporates:
   *  Inport: '<Root>/ActlRtdrPctTrq_SB'
   *  Inport: '<Root>/RefRtdrTrq_NmUW'
   *  Product: '<S7>/Product2'
   */
  rtb_Product3_g = div_nde_s32_floor((int32_T)ActlRtdrPctTrq_SB *
    RefRtdrTrq_NmUW, 100L);

  /* MultiPortSwitch: '<S7>/Index Vector1' incorporates:
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   */
  if (!((CrCtl_B.ActlEngPctTrq_Nm <= 0L) && (rtb_Product3_g < 0L))) {
    rtb_Product3_g = CrCtl_B.ActlEngPctTrq_Nm;
  }

  /* End of MultiPortSwitch: '<S7>/Index Vector1' */

  /* Gain: '<S7>/Gain3' */
  PrpBrk_trqDes_10mNmL = 100L * rtb_Product3_g;

  /* Gain: '<S327>/Gain' incorporates:
   *  Inport: '<Root>/EngSpd_rpmUW'
   *  Lookup_n-D: '<S327>/weiChaiExCharCv_JH6500HP'
   */
  CrCtl_B.Gain = 100L * look1_iu16lu16n16ts16Ds32_binlcas(EngSpeed_rpmUW,
    CrCtl_ConstP.weiChaiExCharCv_JH6500HP_bp01Data,
    CrCtl_ConstP.weiChaiExCharCv_JH6500HP_tableData, 6UL);

  /* Product: '<S7>/Divide3' incorporates:
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Inport: '<Root>/EEC1_DrvrDmdEngPctTrq_UB'
   *  Product: '<S7>/Product3'
   */
  CrCtl_B.AccPed_trqDes_NmSW = (int16_T)div_nde_s32_floor((int32_T)
    EEC1_DrvrDmdEngPctTrq_UB * EngReferenceTorque_NmUW, 100L);

  /* Product: '<Root>/Product' incorporates:
   *  Inport: '<Root>/EC1_EngRefTrq_NmUW'
   *  Inport: '<Root>/PCC_trqReq_pctSB'
   */
  CrCtl_trqPCCReqin_10mNmSL = (int32_T)EngReferenceTorque_NmUW *
    PCC_trqReq_pctSB;

  /* Product: '<Root>/Product1' incorporates:
   *  Inport: '<Root>/PCC_vSetPointTrgt_kmphUW'
   */
  CrCtl_B.PCC_vSetPointTrgt_10mphUW = PCC_vSetPointTrgt_kmphUW * 100U;

  /* Outputs for Atomic SubSystem: '<Root>/CrCtl_State' */
  CrCtl_CrCtl_State();

  /* End of Outputs for SubSystem: '<Root>/CrCtl_State' */

  /* MultiPortSwitch: '<S1>/Index Vector1' incorporates:
   *  Constant: '<S1>/AcceleratorOverride'
   *  Constant: '<S1>/CRCTL_OVERRIDE_2h'
   *  RelationalOperator: '<S1>/Relational Operator'
   */
  if (CrCtl_stOpFunc_UB == ((uint8_T)CRCTL_OVERRIDE)) {
    CrCtl_CCVSCCSt_UB = 6;
  }

  /* End of MultiPortSwitch: '<S1>/Index Vector1' */

  /* Outport: '<Root>/CrCtl_CCVSCCSt_UB' */
  CrCtl_Y.CrCtl_CCVSCCSt_UB_g = CrCtl_CCVSCCSt_UB;

  /* Product: '<Root>/Divide4' */
  CrCtl_vSetPointTrgt_kmphUB = (uint8_T)(CrCtl_vSetPointTrgt_10mphUW / 100U);

  /* MultiPortSwitch: '<S6>/Index Vector' incorporates:
   *  Constant: '<S6>/CRCTL_ACTV_1h'
   *  Constant: '<S6>/OverrideDisabled'
   *  Constant: '<S6>/TorqueControl'
   *  Logic: '<S6>/Logical Operator1'
   *  RelationalOperator: '<S6>/Relational Operator1'
   */
  if (!(CrCtl_stActive_BL && (CrCtl_stOpFunc_UB == ((uint8_T)CRCTL_ACTV)))) {
    CrCtl_TSC1EngOvrdCtrlMd_UB = 0;
  } else {
    CrCtl_TSC1EngOvrdCtrlMd_UB = 2;
  }

  /* End of MultiPortSwitch: '<S6>/Index Vector' */

  /* Outport: '<Root>/CrCtl_TSC1EngOvrdCtrlMd_UB' */
  CrCtl_Y.CrCtl_TSC1EngOvrdCtrlMd_UB_i = CrCtl_TSC1EngOvrdCtrlMd_UB;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/MFLV_SETOPT_8h'
   *  Constant: '<S1>/MFLV_SET_2h'
   *  Logic: '<S1>/Logical Operator2'
   *  RelationalOperator: '<S1>/Relational Operator5'
   *  RelationalOperator: '<S1>/Relational Operator6'
   */
  CrCtl_CCSet_UB = (uint8_T)((MFLv_stCrCtlMode == ((uint8_T)MFLV_SET)) ||
    (MFLv_stCrCtlMode == ((uint8_T)MFLV_SETOPT)));

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Constant: '<S1>/MFLV_DECL_4h'
   *  Constant: '<S1>/MFLV_TIPDWN_3h'
   *  Logic: '<S1>/Logical Operator1'
   *  RelationalOperator: '<S1>/Relational Operator3'
   *  RelationalOperator: '<S1>/Relational Operator4'
   */
  CrCtl_CCCstDecl_UB = (uint8_T)((MFLv_stCrCtlMode == ((uint8_T)MFLV_TIPDWN)) ||
    (MFLv_stCrCtlMode == ((uint8_T)MFLV_DECL)));

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<S1>/MFLV_ACC_6h'
   *  Constant: '<S1>/MFLV_TIPUP_5h'
   *  Logic: '<S1>/Logical Operator'
   *  RelationalOperator: '<S1>/Relational Operator1'
   *  RelationalOperator: '<S1>/Relational Operator2'
   */
  CrCtl_CCAcc_UB = (uint8_T)((MFLv_stCrCtlMode == ((uint8_T)MFLV_TIPUP)) ||
    (MFLv_stCrCtlMode == ((uint8_T)MFLV_ACC)));

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Constant: '<S1>/MFLV_RES_7h'
   *  RelationalOperator: '<S1>/Relational Operator7'
   */
  CrCtl_CCRes_UB = (uint8_T)(MFLv_stCrCtlMode == ((uint8_T)MFLV_RES));

  /* Outport: '<Root>/EngRqedTorque_TorqueLimit_SB' */
  CrCtl_Y.EngRqedTorque_TorqueLimit_SB_l = EngRqedTorque_TorqueLimit_SB;

  /* Outport: '<Root>/CrCtl_stOpFunc_UB' */
  CrCtl_Y.CrCtl_stOpFunc_UB_f = CrCtl_stOpFunc_UB;

  /* Outport: '<Root>/CrCtl_TC1DisengDrvlnReq_UB' */
  CrCtl_Y.CrCtl_TC1DisengDrvlnReq_UB_b = CrCtl_TC1DisengDrvlnReq_UB;

  /* Outport: '<Root>/CrCtl_TC1DisengDiffLckRqFrtAxl1_UB' */
  CrCtl_Y.CrCtl_TC1DisengDiffLckRqFrtAxl1_UB_g =
    CrCtl_TC1DisengDiffLckRqFrtAxl1_UB;

  /* Outport: '<Root>/MFLv_swt_Bl' incorporates:
   *  Inport: '<Root>/MFLv_swtBL'
   */
  CrCtl_Y.MFLv_swt_Bl = MFLv_swtBL;

  /* Update for Memory: '<S5>/setDownBf' incorporates:
   *  Inport: '<Root>/MFLv_setDownBL'
   */
  CrCtl_DW.setDownBf_PreviousInput = MFLv_setDownBL;

  /* Update for Memory: '<S5>/setUpBf' incorporates:
   *  Inport: '<Root>/MFLv_setUpBL'
   */
  CrCtl_DW.setUpBf_PreviousInput = MFLv_setUpBL;

  /* Update for Memory: '<Root>/Memory' */
  CrCtl_DW.Memory_PreviousInput_m = CrCtl_B.CrCtl_stMode;

  /* Update for Memory: '<Root>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_m = CrCtl_B.CrCtl_stModeSub;

  /* Update for Memory: '<Root>/00' */
  CrCtl_DW.u0_PreviousInput = CrCtl_vSetPointTrgt_10mphUW;

  /* Update for UnitDelay: '<S328>/UD'
   *
   * Block description for '<S328>/UD':
   *
   *  Store in Global RAM
   */
  CrCtl_DW.UD_DSTATE = rtb_TSamp;

  /* Update for Memory: '<Root>/Memory2' */
  CrCtl_DW.Memory2_PreviousInput_i = EngRqedTorque_TorqueLimit_SB;

  /* Update for Memory: '<Root>/ CRCTL_NOTACTV_0h' */
  CrCtl_DW.CRCTL_NOTACTV_0h_PreviousInput = CrCtl_stOpFunc_UB;

  /* Update for Memory: '<Root>/FALSE' */
  CrCtl_DW.FALSE_PreviousInput = CrCtl_stActive_BL;

  /* Update for Memory: '<Root>/CRCTL_NOTLCK_0h' */
  CrCtl_DW.CRCTL_NOTLCK_0h_PreviousInput = CrCtl_B.CrCtl_stLck;

  /* Update for Memory: '<Root>/CRCTL_NOSHOFFCONACTV_0h' */
  CrCtl_DW.CRCTL_NOSHOFFCONACTV_0h_PreviousInput = CrCtl_B.IndexVector11;

  /* Update for Memory: '<Root>/Memory3' */
  CrCtl_DW.Memory3_PreviousInput_o = CrCtl_enPCC_UB;

  /* Update for Atomic SubSystem: '<Root>/CrCtl_Mode' */
  CrCtl_CrCtl_Mode_Update();

  /* End of Update for SubSystem: '<Root>/CrCtl_Mode' */

  /* Update for Atomic SubSystem: '<Root>/CrCtl_ShOff' */
  CrCtl_CrCtl_ShOff_Update();

  /* End of Update for SubSystem: '<Root>/CrCtl_ShOff' */

  /* Update for Atomic SubSystem: '<Root>/CrCtl_State' */
  CrCtl_CrCtl_State_Update();

  /* End of Update for SubSystem: '<Root>/CrCtl_State' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  CrCtl_M->Timing.t[0] =
    (++CrCtl_M->Timing.clockTick0) * CrCtl_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    CrCtl_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void CrCtl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)CrCtl_M, 0,
                sizeof(RT_MODEL_CrCtl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CrCtl_M->solverInfo, &CrCtl_M->Timing.simTimeStep);
    rtsiSetTPtr(&CrCtl_M->solverInfo, &rtmGetTPtr(CrCtl_M));
    rtsiSetStepSizePtr(&CrCtl_M->solverInfo, &CrCtl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&CrCtl_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(CrCtl_M))));
    rtsiSetRTModelPtr(&CrCtl_M->solverInfo, CrCtl_M);
  }

  rtsiSetSimTimeStep(&CrCtl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&CrCtl_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(CrCtl_M, &CrCtl_M->Timing.tArray[0]);
  CrCtl_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &CrCtl_B), 0,
                sizeof(B_CrCtl_T));

  /* custom signals */
  PrpBrk_trqDes_10mNmL = 0;
  CrCtl_trqPCCReqin_10mNmSL = 0;
  CrCtl_trqDes_10mNmSL = 0;
  VSSCD_v_10mphUW = 0U;
  CrCtl_vSetPointAct_mp_10mphUW = 0U;
  CrCtl_vSetPointTrgt_10mphUW = 0U;
  CrCtl_vSetPointTrgtIn_10mphUW = 0U;
  CrCtl_CCVSCCSt_UB = 0U;
  CrCtl_vSetPointTrgt_kmphUB = 0U;
  CrCtl_TSC1EngOvrdCtrlMd_UB = 0U;
  CrCtl_CCSet_UB = 0U;
  CrCtl_CCCstDecl_UB = 0U;
  CrCtl_CCAcc_UB = 0U;
  CrCtl_CCRes_UB = 0U;
  MFLv_stCrCtlMode = 0U;
  CrCtl_stOpFunc_UB = 0U;
  CrCtl_TC1DisengDiffLckRqFrtAxl1_UB = 0U;
  CrCtl_enPCC_UB = 0U;
  CrCtl_TC1DisengDrvlnReq_UB = 0U;
  CrCtl_TC1TrsReqGear_UB = 0U;
  CrCtl_stModeIn_UB = 0U;
  CrCtl_stModeSubIn_UB = 0U;
  EngRqedTorque_TorqueLimit_SB = 0;
  CrCtl_stActive_BL = false;

  /* states (dwork) */
  (void) memset((void *)&CrCtl_DW, 0,
                sizeof(DW_CrCtl_T));

  /* external inputs */
  (void)memset((void *)&CrCtl_U, 0, sizeof(ExtU_CrCtl_T));
  ActualEngPercentTorque_UB = 0U;
  EEC1_DrvrDmdEngPctTrq_UB = 0;
  EngSpeed_rpmUW = 0U;
  BrkCD_stPressed_UB = 0U;
  ConvCD_stClth_UB = 0U;
  AccPedPos1_pctUB = 0U;
  EngReferenceTorque_NmUW = 0U;
  TachographVehicleSpeed_10mphUW = 0U;
  RefRtdrTrq_NmUW = 0U;
  ActlRtdrPctTrq_SB = 0;
  ETC1_trsSftPrcs_UB = 0U;
  ETC2_trsCrntGr_SB = 0;
  ETC2_trsSlctGr_SB = 0;
  TCU_stShiftHandle_UB = 0U;
  MFLv_swtBL = false;
  MFLv_resBL = false;
  MFLv_setDownBL = false;
  MFLv_setUpBL = false;
  CrCtl_PCCAct_BL = false;
  CrCtl_tiPCCRmp_10msUW = 0U;
  PCC_trqReq_pctSB = 0;
  PCC_offRsn_UB = 0U;
  PCC_vSetPointTrgt_kmphUW = 0U;
  PCC_targetGear_SB = 0;
  PCC_TC1Act_Bl = false;

  /* external outputs */
  (void) memset((void *)&CrCtl_Y, 0,
                sizeof(ExtY_CrCtl_T));

  /* Machine initializer */
  CrCtl_DW.PCC_vSetPointTrgt_kmphUW_m = 0.0;

  /* Start for Atomic SubSystem: '<Root>/CrCtl_State' */
  CrCtl_CrCtl_State_Start();

  /* End of Start for SubSystem: '<Root>/CrCtl_State' */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  CrCtl_DW.Memory_PreviousInput_m = 1U;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  CrCtl_DW.Memory1_PreviousInput_m = 1U;

  /* InitializeConditions for Memory: '<Root>/ CRCTL_NOTACTV_0h' */
  CrCtl_DW.CRCTL_NOTACTV_0h_PreviousInput = ((uint8_T)CRCTL_NOTACTV);

  /* InitializeConditions for Memory: '<Root>/FALSE' */
  CrCtl_DW.FALSE_PreviousInput = FALSE;

  /* InitializeConditions for Memory: '<Root>/CRCTL_NOTLCK_0h' */
  CrCtl_DW.CRCTL_NOTLCK_0h_PreviousInput = ((uint8_T)CRCTL_NOTLCK);

  /* InitializeConditions for Memory: '<Root>/CRCTL_NOSHOFFCONACTV_0h' */
  CrCtl_DW.CRCTL_NOSHOFFCONACTV_0h_PreviousInput = ((uint8_T)
    CRCTL_NOSHOFFCONACTV);

  /* SystemInitialize for Chart: '<S5>/MFLvDtctAndPrs' */
  CrCtl_DW.is_active_c23_CrCtl = 0U;
  CrCtl_DW.countD = 0U;
  CrCtl_DW.countU = 0U;
  CrCtl_DW.setDownPress = false;
  CrCtl_DW.setUpPress = false;
  MFLv_stCrCtlMode = 0;
  CrCtl_B.PCC_Mode_BL = false;

  /* SystemInitialize for Chart: '<S327>/ig2stGear_weiChaiJH6500HP' */
  CrCtl_B.Gearbx_stGear = 0U;

  /* SystemInitialize for Atomic SubSystem: '<Root>/CrCtl_Mode' */
  CrCtl_CrCtl_Mode_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/CrCtl_Mode' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/CrCtl_ShOff' */
  CrCtl_CrCtl_ShOff_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/CrCtl_ShOff' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/CrCtl_State' */
  CrCtl_CrCtl_State_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/CrCtl_State' */
}

/* Model terminate function */
void CrCtl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
