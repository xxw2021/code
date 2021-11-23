/*
 * File: CrCtl_private.h
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

#ifndef RTW_HEADER_CrCtl_private_h_
#define RTW_HEADER_CrCtl_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "CrCtl.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern uint16_T look1_iu16lu32n16_binlcse(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
extern uint16_T look1_iu8lu32n16tu16_binlcse(uint8_T u0, const uint8_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
extern int16_T look1_iu16lu16n16ts16Ds32_binlcas(uint16_T u0, const uint16_T
  bp0[], const int16_T table[], uint32_T maxIndex);
extern void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y[], int16_T n);
extern boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
extern int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n);
extern void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y[], int16_T n);
extern void MultiWordUnsignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2,
  uint32_T y[]);
extern void uMultiWordDivZero(const uint32_T u1[], int16_T n1, const uint32_T
  u2[], int16_T n2, uint32_T y1[], int16_T m1, uint32_T y2[], int16_T m2,
  uint32_T t1[], int16_T l1, uint32_T t2[], int16_T l2);
extern void uMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n);
extern void MultiWordSetUnsignedMax(uint32_T y[], int16_T n);
extern int16_T uMultiWordDiv(uint32_T a[], int16_T na, uint32_T b[], int16_T nb,
  uint32_T q[], int16_T nq, uint32_T r[], int16_T nr);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n);
extern uint32_T MultiWord2uLong(const uint32_T u[]);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern int16_T div_nde_s16_floor(int16_T numerator, int16_T denominator);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern int8_T div_s8s32_floor(int32_T numerator, int32_T denominator);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift);
extern int16_T div_s16u32(uint32_T numerator, uint32_T denominator);
extern void CrCtl_SwitchCaseActionSubsystem(boolean_T rtu_signalIn, boolean_T
  *rty_signalOut, uint8_T *rtd_numPeriod_o, boolean_T *rtd_timeLck_n);
extern void CrCtl_SwitchCaseActionSubsystem1(boolean_T rtu_signalIn, int8_T
  rtu_Time, boolean_T *rty_signalOut, uint8_T *rtd_numPeriod_g, boolean_T
  *rtd_timeLck_f);
extern void CrCtl_CrCtl_Mode_CdtnsFwd_Init(void);
extern void CrCtl_CrCtl_Mode_CdtnsFwd_Update(void);
extern void CrCtl_CrCtl_Mode_CdtnsFwd(void);
extern void CrCtl_CrCtl_Mode_MFLvRqstMnplt(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvNeutr(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvSet(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvTipDwn(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvDecl(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvTipUp(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvAcc(void);
extern void CrCtl_CrCtl_Mode_SwtMds_MFLvRes(void);
extern void CrCtl_CrCtl_Mode_SwtMds_Init(void);
extern void CrCtl_CrCtl_Mode_SwtMds(void);
extern void CrCtl_CrCtl_Mode_Init(void);
extern void CrCtl_CrCtl_Mode_Update(void);
extern void CrCtl_CrCtl_Mode(void);
extern void CrCtl_CrCtlShOff_Cdtns_1(void);
extern void CrCtl_CrCtlShOff_Cdtns_2_Update(void);
extern void CrCtl_CrCtlShOff_Cdtns_2(void);
extern void CrCtl_CrCtlShOff_Cdtns_3_Update(void);
extern void CrCtl_CrCtlShOff_Cdtns_3(void);
extern void CrCtl_CrCtlShOff_Cdtns_4_Update(void);
extern void CrCtl_CrCtlShOff_Cdtns_4(void);
extern void CrCtl_CrCtlShOff_Cdtns_Update(void);
extern void CrCtl_CrCtlShOff_Cdtns(void);
extern void CrCtl_CrCtlShOff_Reactvtn_Init(void);
extern void CrCtl_CrCtlShOff_Reactvtn_Update(void);
extern void CrCtl_CrCtlShOff_Reactvtn(void);
extern void CrCtl_CrCtl_ShOff_Init(void);
extern void CrCtl_CrCtl_ShOff_Update(void);
extern void CrCtl_CrCtl_ShOff(void);
extern void CrCtl_CrCtl_State_Neutr(void);
extern void CrCtl_CrCtl_State_Off_Cut(void);
extern void CrCtl_CrCtl_State_Off_RmpOne(void);
extern void CrCtl_CrCtl_State_Off_RmpTwo(void);
extern void CrCtl_CrCtl_State_Off(void);
extern void CrCtl_CrCtl_State_TipDwn_Start(void);
extern void CrCtl_CrCtl_State_TipDwn(void);
extern void CrCtl_CrCtl_State_Decl_SubStrtVal(void);
extern void CrCtl_CrCtl_State_Decl_SubRmp(void);
extern void CrCtl_CrCtl_State_Decl_SubRmpEnd(void);
extern void CrCtl_CrCtl_State_Decl_SubRmpHold(void);
extern void CrCtl_CrCtl_State_Decl_SubSetEnd(void);
extern void CrCtl_CrCtl_State_Decl(void);
extern void CrCtl_CrCtl_State_ResAbv_SubStrtVal(void);
extern void CrCtl_CrCtl_State_ResAbv_SubRmp(void);
extern void CrCtl_CrCtl_State_ResAbv_Init(void);
extern void CrCtl_CrCtl_State_ResAbv(void);
extern void CrCtl_CrCtl_State_ResBlw_SubStrtVal(void);
extern void CrCtl_CrCtl_State_ResBlw_SubRmp(void);
extern void CrCtl_CrCtl_State_ResBlw_SubPrepHold(void);
extern void CrCtl_CrCtl_State_ResBlw_Init(void);
extern void CrCtl_CrCtl_State_ResBlw(void);
extern void CrCtl_CrCtl_State_TipUp(void);
extern void CrCtl_CrCtl_State_Acc_SubStrtVal(void);
extern void CrCtl_CrCtl_State_Acc_SubRmp(void);
extern void CrCtl_CrCtl_State_Acc_SubRmpEnd(void);
extern void CrCtl_CrCtl_State_Acc_SubPrepHold(void);
extern void CrCtl_CrCtl_State_Acc_SubWaitRes(void);
extern void CrCtl_CrCtl_State_Acc(void);
extern void CrCtl_CrCtl_State_Hold_SubStrtVal(void);
extern void CrCtl_CrCtl_State_Hold_SubGvnr(void);
extern void CrCtl_CrCtl_State_Hold(void);
extern void CrCtl_CrCtl_State_PCC_SubStrtVal(void);
extern void CrCtl_CrCtl_State_PCC_SubRmp(void);
extern void CrCtl_CrCtl_State_PCC_Hold(void);
extern void CrCtl_CrCtl_State_PCC_Init(void);
extern void CrCtl_CrCtl_State_PCC(void);
extern void CrCtl_CrCtl_State_Init(void);
extern void CrCtl_CrCtl_State_Start(void);
extern void CrCtl_CrCtl_State_Update(void);
extern void CrCtl_CrCtl_State(void);

#endif                                 /* RTW_HEADER_CrCtl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
