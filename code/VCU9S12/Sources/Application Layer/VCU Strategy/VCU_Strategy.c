#include "Allh.h"




/* Block signals and states (auto storage) */
D_Work_ZHVCU ZHVCU_DWork;

/* Forward declaration for local functions */
static void ZHVCU_VehAnly_GearDXTimeReset(void);

/* Declare variables for internal data of system '<Root>/Func_BrakeEngTrqDmdUpdt' */
rtDW_Func_BrakeEngTrqDmdUpdt_ZH ZHVC_Func_BrakeEngTrqDmdUpdt_DW;

/* Declare variables for internal data of system '<S4>/DrvMd' */
rtDW_DrvMd_ZHVCU ZHVCU_DrvMd_DW;

/* Declare variables for internal data of system '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
rtDW_Func_EngSpdSlideBrakeLThrU Func_EngSpdSlideBrakeLThrUpd_DW;

/* Declare variables for internal data of system '<Root>/Func_GearCal' */
rtDW_Func_GearCal_ZHVCU ZHVCU_Func_GearCal_DW;

/* Declare variables for internal data of system '<Root>/Func_SlideEngTrqDmdUpdt' */
rtDW_Func_SlideEngTrqDmdUpdt_ZH ZHVC_Func_SlideEngTrqDmdUpdt_DW;

/* Declare variables for internal data of system '<S22>/StartMd' */
rtDW_StartMd_ZHVCU ZHVCU_StartMd_DW;

/* Declare variables for internal data of system '<S24>/StopMd' */
rtDW_StopMd_ZHVCU ZHVCU_StopMd_DW;
uint8_T look1_iu8lu32n32yu8Ds1_Y0hbqrP2(uint8_T u0, const uint8_T bp0[], const
  uint8_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T frac;
  int32_T finalAccum;
  uint32_T bpIdx;

  /* Lookup 1-D
     Canonical function name: look1_iu8lu32n32yu8Ds16Is32n23_plinlagss
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx = prevIndex[0U];
  while ((u0 < bp0[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex) && (u0 >= bp0[bpIdx + 1U])) {
    bpIdx++;
  }

  prevIndex[0U] = bpIdx;
  frac = div_nzp_repeat_u32((uint32_T)(uint8_T)((uint32_T)u0 - bp0[bpIdx]) << 24,
    (uint8_T)((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]), 8U);

  /* Interpolation 1-D
     Canonical function name: intrp1d_u8p23s16s32u32u32n32la_s
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    finalAccum = table[bpIdx] << 23;
  } else {
    finalAccum = mul_ssu32_loSR((int16_T)(table[bpIdx + 1U] - table[bpIdx]),
      frac, 9U) + (table[bpIdx] << 23);
  }

  finalAccum >>= 23;
  if (finalAccum < 0) {
    finalAccum = 0;
  } else {
    if (finalAccum > 255) {
      finalAccum = 255;
    }
  }

  return (uint8_T)finalAccum;
}

uint16_T look1_iu16lu32n32yu16D_HfJiOU2v(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T frac;
  int32_T finalAccum;
  uint32_T bpIdx;

  /* Lookup 1-D
     Canonical function name: look1_iu16lu32n32yu16Ds32Is32n15_plinlagss
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx = prevIndex[0U];
  while ((u0 < bp0[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex) && (u0 >= bp0[bpIdx + 1U])) {
    bpIdx++;
  }

  prevIndex[0U] = bpIdx;
  frac = div_nzp_repeat_u32((uint32_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) <<
    16, (uint16_T)((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]), 16U);

  /* Interpolation 1-D
     Canonical function name: intrp1d_u16p15s32s32u32u32n32la_s
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    finalAccum = table[bpIdx] << 15;
  } else {
    finalAccum = mul_ssu32_loSR(table[bpIdx + 1U] - table[bpIdx], frac, 17U) +
      (table[bpIdx] << 15);
  }

  finalAccum >>= 15;
  if (finalAccum < 0) {
    finalAccum = 0;
  } else {
    if (finalAccum > 65535) {
      finalAccum = 65535;
    }
  }

  return (uint16_T)finalAccum;
}

uint16_T look1_iu16lu32n32yu16t_0NvOblQd(uint16_T u0, const uint16_T bp0[],
  const uint32_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  int32_T finalAccum;
  uint32_T bpIdx;

  /* Lookup 1-D
     Canonical function name: look1_iu16lu32n32yu16tu32Is32p1_plinlagsse
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx = prevIndex[0U];
  while ((u0 < bp0[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex) && (u0 >= bp0[bpIdx + 1U])) {
    bpIdx++;
  }

  prevIndex[0U] = bpIdx;
  frac = div_nzp_repeat_u32((uint32_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) <<
    16, (uint16_T)((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]), 16U);

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    finalAccum = (int32_T)(table[bpIdx] >> 1);
  } else if (table[bpIdx + 1U] >= table[bpIdx]) {
    finalAccum = (int32_T)mul_u32_hiSR(frac, table[bpIdx + 1U] - table[bpIdx],
      1U) + (int32_T)(table[bpIdx] >> 1);
  } else {
    finalAccum = (int32_T)(table[bpIdx] >> 1) - (int32_T)mul_u32_hiSR(frac,
      table[bpIdx] - table[bpIdx + 1U], 1U);
  }

  if (finalAccum <= 0) {
    y = 0U;
  } else if (finalAccum > 32767) {
    y = MAX_uint16_T;
  } else {
    y = (uint16_T)((uint16_T)finalAccum << 1);
  }

  return y;
}

uint16_T look2_iu16lu32n32yu16D_Gb9u1U7n(uint16_T u0, uint16_T u1, const
  uint16_T bp0[], const uint16_T bp1[], const uint16_T table[], uint32_T
  prevIndex[], const uint32_T maxIndex[], uint32_T stride)
{
  uint32_T fractions[2];
  uint32_T bpIdx;
  uint32_T bpIdx_0;
  int32_T yL_1d;
  int32_T yR_1d;
  uint32_T offset_1d;

  /* Lookup 2-D
     Canonical function name: look2_iu16lu32n32yu16Ds32Is32n15_plinlagss
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx = prevIndex[0U];
  while ((u0 < bp0[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex[0U]) && (u0 >= bp0[bpIdx + 1U])) {
    bpIdx++;
  }

  prevIndex[0U] = bpIdx;
  fractions[0U] = div_nzp_repeat_u32((uint32_T)(uint16_T)((uint32_T)u0 -
    bp0[bpIdx]) << 16, (uint16_T)((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]), 16U);

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  /* Linear Search */
  bpIdx_0 = prevIndex[1U];
  while ((u1 < bp1[bpIdx_0]) && (bpIdx_0 > 0U)) {
    bpIdx_0--;
  }

  while ((bpIdx_0 < maxIndex[1U]) && (u1 >= bp1[bpIdx_0 + 1U])) {
    bpIdx_0++;
  }

  prevIndex[1U] = bpIdx_0;

  /* Interpolation 2-D
     Canonical function name: intrp2d_u16p15s32s32u32u32n32la_s
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIdx_0 * stride + bpIdx;
  if (bpIdx == maxIndex[0U]) {
    yL_1d = table[offset_1d] << 15;
  } else {
    yL_1d = mul_ssu32_loSR(table[offset_1d + 1U] - table[offset_1d], fractions
      [0U], 17U) + (table[offset_1d] << 15);
  }

  if (bpIdx_0 == maxIndex[1U]) {
  } else {
    offset_1d += stride;
    if (bpIdx == maxIndex[0U]) {
      yR_1d = table[offset_1d] << 15;
    } else {
      yR_1d = mul_ssu32_loSR(table[offset_1d + 1U] - table[offset_1d],
        fractions[0U], 17U) + (table[offset_1d] << 15);
    }

    yL_1d += mul_ssu32_sr32(yR_1d - yL_1d, div_nzp_repeat_u32((uint32_T)
      (uint16_T)((uint32_T)u1 - bp1[bpIdx_0]) << 16, (uint16_T)((uint32_T)
      bp1[bpIdx_0 + 1U] - bp1[bpIdx_0]), 16U));
  }

  yL_1d >>= 15;
  if (yL_1d < 0) {
    yL_1d = 0;
  } else {
    if (yL_1d > 65535) {
      yL_1d = 65535;
    }
  }

  return (uint16_T)yL_1d;
}

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if (!((in1 == 0U) || (in0 >= 0))) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return u32_chi >> aShift;
}

int32_T mul_ssu32_sr32(int32_T a, uint32_T b)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi;
}

/* Output and update for atomic system: '<Root>/CommFunc_PctCal' */
void ZHVCU_CommFunc_PctCal(void)
{
  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant3_1'
   *  Constant: '<S1>/Constant5'
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  Product: '<S1>/Divide8'
   *  Product: '<S1>/Divide9'
   */
  TrqCtrl_nmTrqDmdRawUW = (uint16_T)((uint32_T)EngAnly_nmDrvTrqDmdUW *
    TrqMng_pctDrvDmd2TrqDmdRatioUBC / 100U);
}

/* System initialize for atomic system: '<Root>/FuncMAl_SSStop' */
void ZHVCU_FuncMAl_SSStop_Init(void)
{
  MdAllow_stSSStopUB = 0U;
}

/* Output and update for atomic system: '<Root>/FuncMAl_SSStop' */
void ZHVCU_FuncMAl_SSStop(void)
{
  int32_T tmp;

  /* Inport: '<Root>/In26' incorporates:
   *  Constant: '<Root>/Constant23'
   *  Inport: '<Root>/In160'
   *  Inport: '<Root>/In181'
   *  Inport: '<Root>/In182'
   *  Inport: '<Root>/In183'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In44'
   *  Inport: '<Root>/In6'
   *  Inport: '<Root>/In9'
   */
  /* Gateway: FuncMAl_SSStop */
  /* During: FuncMAl_SSStop */
  /* Entry Internal: FuncMAl_SSStop */
  /* Transition: '<S2>:1' */
  if ((MeterTCO1_kmphVehSpdUB < 5) && (ECUEEC1_rpmEngSpdUW < 750) &&
      (ECUET1_tEngCoolantTempUB > MdST_tDrvSSEngTempLThrUBC) &&
      (ECUEEC2_pctAccelPedalPosUB < 10) && (SWSen_stClutchSWUB == 0) &&
      (SWSen_stStartSWUB == 0) && (SWSen_stSSMdUB == 1) &&
      (DrvMdST_stSSMtrStartErrFlagUB == 0) && (SWSen_stNeutralSWUB == 1) &&
      (MdAllow_stSSCycleUB == 1) && (SWSen_stParkBrakeSWUB == 1)) {
    /* Transition: '<S2>:2' */
    /* Transition: '<S2>:5' */
    tmp = DrvMdST_numSSStopAllowTimerUW + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    DrvMdST_numSSStopAllowTimerUW = (uint16_T)tmp;
    if (DrvMdST_numSSStopAllowTimerUW > 150) {
      /* Transition: '<S2>:14' */
      /* Transition: '<S2>:16' */
      DrvMdST_numSSStopAllowTimerUW = 0U;
      MdAllow_stSSStopUB = 1U;

      /* Transition: '<S2>:11' */
    } else {
      /* Transition: '<S2>:9' */
    }

    /* Transition: '<S2>:6' */
  } else {
    /* Transition: '<S2>:3' */
    DrvMdST_numSSStopAllowTimerUW = 0U;
    MdAllow_stSSStopUB = 0U;
  }

  /* End of Inport: '<Root>/In26' */
  /* Transition: '<S2>:8' */
}

/* Output and update for atomic system: '<Root>/Func_BrakeEngTrqDmdUpdt' */
void ZHVCU_Func_BrakeEngTrqDmdUpdt(void)
{
  uint8_T rtb_Map_EngTrqAnly_VehSpd2Brake;
  uint16_T rtb_Map_EngTrqAnly_EngSpd2Brake;
  uint32_T rtb_Divide2;

  /* Lookup_n-D: '<S3>/Map_EngTrqAnly_VehSpd2BrakeEngTrqPctCtrl' incorporates:
   *  Inport: '<Root>/In26'
   */
  rtb_Map_EngTrqAnly_VehSpd2Brake = look1_iu8lu32n32yu8Ds1_Y0hbqrP2
    (MeterTCO1_kmphVehSpdUB, (&(MapVehSpd2BrakeEngTrqPctCtrl_kmphVehSpdUBA[0])),
     (&(MapVehSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUBWA[0])),
     &ZHVC_Func_BrakeEngTrqDmdUpdt_DW.m_bpIndex, 22U);

  /* Lookup_n-D: '<S3>/Map_EngTrqAnly_EngSpd2BrakeEngTrqPctCtrl' incorporates:
   *  Inport: '<Root>/In6'
   */
  rtb_Map_EngTrqAnly_EngSpd2Brake = look1_iu16lu32n32yu16D_HfJiOU2v
    (ECUEEC1_rpmEngSpdUW, (&(MapEngSpd2BrakeEngTrqPctCtrl_rpmEngSpdUWA[0])),
     (&(MapEngSpd2BrakeEngTrqPctCtrl_pctEngTrqCtrlUWA[0])),
     &ZHVC_Func_BrakeEngTrqDmdUpdt_DW.m_bpIndex_d, 26U);

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/Constant6'
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   *  Product: '<S3>/Divide1'
   */
  rtb_Divide2 = (uint32_T)rtb_Map_EngTrqAnly_EngSpd2Brake *
    rtb_Map_EngTrqAnly_VehSpd2Brake / 100U;

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S3>/Constant7'
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  Switch: '<S38>/Switch'
   */
  if (rtb_Divide2 > 30U) {
    EngCtrl_pctBrakeTrqDmdUB = 30U;
  } else {
    EngCtrl_pctBrakeTrqDmdUB = (uint8_T)rtb_Divide2;
  }

  /* End of Switch: '<S38>/Switch2' */
}

/* System initialize for atomic system: '<S4>/DrvMd' */
void ZHVCU_DrvMd_Init(void)
{
  ZHVCU_DrvMd_DW.MdST_stMdCalUB = 0U;
  ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = 0U;
  ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = 0U;
  ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = 0U;
  ZHVCU_DrvMd_DW.SubSysTsk_stCANUB = 0U;
  ZHVCU_DrvMd_DW.SubSysTsk_stMeterUB = 0U;
}

/* Output and update for atomic system: '<S4>/DrvMd' */
void ZHVCU_DrvMd(void)
{
  int32_T tmp;

  /* Gateway: Func_DrvMd/DrvMd */
  /* During: Func_DrvMd/DrvMd */
  /* Entry Internal: Func_DrvMd/DrvMd */
  /* Transition: '<S39>:599' */
  /* Transition: '<S39>:481' */
  ZHVCU_DrvMd_DW.SubSysTsk_stCANUB = (uint8_T)SubSysTsk_CAN_POST;
  ZHVCU_DrvMd_DW.SubSysTsk_stMeterUB = (uint8_T)SubSysTsk_Meter_POST;
  if (VehAnly_stTSConedUB == VehAnly_stTSConedUB_Closed) {
    /* Inport: '<Root>/In48' */
    /* Transition: '<S39>:505' */
    if (SWSen_stBrakeSWUB == 0) {
      /* Inport: '<Root>/In9' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<Root>/Constant2'
       */
      /* Transition: '<S39>:542' */
      /* Transition: '<S39>:544' */
      if (ECUEEC2_pctAccelPedalPosUB <= MdST_pctAccPedalPosDrvSlideHThrUB) {
        /* Transition: '<S39>:545' */
        /* Transition: '<S39>:551' */
        /* 滑行过程 模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Slide;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_Slide;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Slide;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;

        /* Transition: '<S39>:554' */
        /* Transition: '<S39>:555' */
      } else if ((ECUEEC2_pctAccelPedalPosUB > MdST_pctAccPedalPosDrvSlideHThrUB)
                 && (ECUEEC2_pctAccelPedalPosUB <=
                     MdST_pctAccPedalPosDrvSlideAccHThrUB)) {
        /* Transition: '<S39>:547' */
        /* Transition: '<S39>:553' */
        /* 小油门滑行过程 模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_SlideAcc;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_SlideAcc;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Slide;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;

        /* Transition: '<S39>:555' */
      } else {
        /* Transition: '<S39>:549' */
        /* 正常扭矩行车过程    模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Drv;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_Drv;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Drv;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;
      }

      /* End of Inport: '<Root>/In9' */
      /* Transition: '<S39>:557' */
    } else {
      /* Transition: '<S39>:540' */
      /* 制动过程   模式执行动作 */
      MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
      MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
      MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Brake;
      ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_Brake;

      /* 子系统执行动作 */
      ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Brake;
      ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
      ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
        SubSysTsk_StartSWChO_OFF;
    }

    /* End of Inport: '<Root>/In48' */
    /* Transition: '<S39>:558' */
    /* Transition: '<S39>:472' */
    /* Transition: '<S39>:479' */
    /* Transition: '<S39>:477' */
    /* Transition: '<S39>:473' */
  } else if (VehAnly_stTSConedUB == VehAnly_stTSConedUB_HalfClosed) {
    /* Transition: '<S39>:483' */
    /* Transition: '<S39>:506' */
    /* 起步过程  模式执行动作 */
    MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
    MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
    MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Launch;
    ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_Launch;

    /* 子系统执行动作 */
    ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
    ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
    ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)SubSysTsk_StartSWChO_OFF;
    DrvMdST_stSSWorkStUB = 0U;

    /* Transition: '<S39>:472' */
    /* Transition: '<S39>:479' */
    /* Transition: '<S39>:477' */
    /* Transition: '<S39>:473' */
  } else {
    /* Transition: '<S39>:499' */
    /* 动力系统处于断开状态 */
    if (MdAllow_stSSStopUB == 1) {
      /* Inport: '<Root>/In42' */
      /* Transition: '<S39>:523' */
      /* 允许起停时，执行起停操作   先执行是否允许起停的判断 */
      if (EngAnly_stEngStartedStUB == 1) {
        /* Transition: '<S39>:480' */
        /* Transition: '<S39>:516' */
        /* 模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_SSStop;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_SSStop;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Stop;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;
        DrvMdST_stSSWorkStUB = 1U;

        /* Transition: '<S39>:479' */
        /* Transition: '<S39>:477' */
        /* Transition: '<S39>:473' */
      } else {
        /* Transition: '<S39>:487' */
        /* 模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_SSStopped;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_SSStopped;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;
        DrvMdST_stSSWorkStUB = 2U;

        /* Transition: '<S39>:477' */
        /* Transition: '<S39>:473' */
      }
    } else {
      /* Inport: '<Root>/In42' */
      /* Transition: '<S39>:498' */
      /* 不满足SS条件 */
      if (EngAnly_stEngStartedStUB == 1) {
        /* Transition: '<S39>:497' */
        /* 发动机起动状态时 待机 */
        /* Transition: '<S39>:520' */
        /* 模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Standby;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_Standby;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;

        /* Transition: '<S39>:473' */
      } else {
        /* Transition: '<S39>:489' */
        /* 此时发动机处于熄火状态  需要启动发动机  模式执行动作 */
        MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
        MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
        MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_SSStart;
        ZHVCU_DrvMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stDrvMdUB_SSStart;

        /* 子系统执行动作 */
        ZHVCU_DrvMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
        ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Start;
        ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)
          SubSysTsk_StartSWChO_OFF;

        /* Constant: '<S4>/DrvMdST_numSSStartMaxTimeUWC' */
        if (DrvMdST_numSSStartTimerUW < DrvMdST_numSSStartMaxTimeUWC) {
          /* Transition: '<S39>:519' */
          /* Transition: '<S39>:476' */
          tmp = DrvMdST_numSSStartTimerUW + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          DrvMdST_numSSStartTimerUW = (uint8_T)tmp;

          /* Transition: '<S39>:518' */
        } else {
          /* Transition: '<S39>:494' */
          DrvMdST_numSSStartTimerUW = 0U;
          DrvMdST_stSSStartErrFlagUB = 1U;
        }

        /* End of Constant: '<S4>/DrvMdST_numSSStartMaxTimeUWC' */
        /* Transition: '<S39>:512' */
        MdAllow_stSSCycleUB = 2U;
      }
    }
  }

  /* Transition: '<S39>:527' */
}

/* System initialize for enable system: '<Root>/Func_DrvMd' */
void ZHVCU_Func_DrvMd_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/DrvMd' */
  ZHVCU_DrvMd_Init();
}

/* Output and update for enable system: '<Root>/Func_DrvMd' */
void ZHVCU_Func_DrvMd(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/Func_DrvMd' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (ZHVCU_DWork.RelationalOperator2) {
    /* Chart: '<S4>/DrvMd' */
    ZHVCU_DrvMd();
  }

  /* End of Outputs for SubSystem: '<Root>/Func_DrvMd' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_DrvTrqDmdUpdt' */
void ZHVC_Func_EngAnly_DrvTrqDmdUpdt(void)
{
  uint32_T u0;

  /* Product: '<S5>/Divide1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/In4'
   *  Product: '<S5>/Divide6'
   */
  u0 = (uint32_T)ECUEEC1_pctDrvTrqDmdUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S5>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmDrvTrqDmdUW = (uint16_T)u0;
  } else {
    EngAnly_nmDrvTrqDmdUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S5>/MinMax' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_DrvTrqDmdUpdt1' */
void ZHV_Func_EngAnly_DrvTrqDmdUpdt1(void)
{
  uint32_T u0;

  /* Product: '<S6>/Divide1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/In8'
   *  Product: '<S6>/Divide6'
   */
  u0 = (uint32_T)ECUEEC1_pctEngTrqDmdUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S6>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmEngTrqDmdUW = (uint16_T)u0;
  } else {
    EngAnly_nmEngTrqDmdUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S6>/MinMax' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_EngActualTrqUpdt' */
void Z_Func_EngAnly_EngActualTrqUpdt(void)
{
  uint32_T u0;

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/In5'
   *  Product: '<S7>/Divide6'
   */
  u0 = (uint32_T)ECUEEC1_pctActualTrqUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S7>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmActualTrqUW = (uint16_T)u0;
  } else {
    EngAnly_nmActualTrqUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S7>/MinMax' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_EngLoadTrqAtCurSpdUpdt' */
void Func_EngAnly_EngLoadTrqAtCurSpd(void)
{
  uint32_T u0;

  /* Product: '<S8>/Divide1' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/In14'
   *  Product: '<S8>/Divide6'
   */
  u0 = (uint32_T)ECUEEC2_pctEngLoadAtCurSpdUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S8>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmEngLoadTrqAtCurSpdUW = (uint16_T)u0;
  } else {
    EngAnly_nmEngLoadTrqAtCurSpdUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S8>/MinMax' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_MaxAvaEngTrqUpdt' */
void Z_Func_EngAnly_MaxAvaEngTrqUpdt(void)
{
  uint32_T u0;

  /* Product: '<S9>/Divide1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/In23'
   *  Product: '<S9>/Divide6'
   */
  u0 = (uint32_T)ECUEEC2_pctMaxAvaEngTrqUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S9>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmMaxAvaEngTrqUW = (uint16_T)u0;
  } else {
    EngAnly_nmMaxAvaEngTrqUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S9>/MinMax' */
}

/* Output and update for atomic system: '<Root>/Func_EngAnly_NomFriTrqUpdt' */
void ZHVC_Func_EngAnly_NomFriTrqUpdt(void)
{
  uint32_T u0;

  /* Product: '<S10>/Divide1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Inport: '<Root>/In17'
   *  Product: '<S10>/Divide6'
   */
  u0 = (uint32_T)ECUEEC3_pctNomFriTrqPctUB * EngAnly_nmEngRefTrqUW / 100U;

  /* MinMax: '<S10>/MinMax' */
  if (u0 < EngAnly_nmEngRTOutCurveTrqUW) {
    EngAnly_nmNomFriTrqUW = (uint16_T)u0;
  } else {
    EngAnly_nmNomFriTrqUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<S10>/MinMax' */
}

/* System initialize for atomic system: '<Root>/Func_EngRefTrqUpdt' */
void ZHVCU_Func_EngRefTrqUpdt_Init(void)
{
  EngAnly_nmEngRefTrqUW = 0U;
}

/* Output and update for atomic system: '<Root>/Func_EngRefTrqUpdt' */
void ZHVCU_Func_EngRefTrqUpdt(void)
{
  /* Inport: '<Root>/In11' */
  /* Gateway: Func_EngRefTrqUpdt */
  /* During: Func_EngRefTrqUpdt */
  /* Entry Internal: Func_EngRefTrqUpdt */
  /* Transition: '<S11>:11' */
  /*  ECUEC1_nmEngRefTrqUW to ECUAnly_nmEngRefTrqUW  */
  if (ECUEC1_nmEngRefTrqUW < 1000) {
    /* Constant: '<Root>/Constant4' */
    /* Transition: '<S11>:10' */
    /* Transition: '<S11>:9' */
    EngAnly_nmEngRefTrqUW = ECUAnly_nmEngRefTrqInitUWC;

    /* Transition: '<S11>:8' */
  } else {
    /* Transition: '<S11>:7' */
    EngAnly_nmEngRefTrqUW = ECUEC1_nmEngRefTrqUW;
  }

  /* End of Inport: '<Root>/In11' */
  /* Transition: '<S11>:6' */
}

/* Output and update for atomic system: '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
void Z_Func_EngSpdSlideBrakeLThrUpdt(void)
{
  /* Lookup_n-D: '<S12>/Map_EngAnly_VehSpd2BrakeEngSpdLThr' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion7'
   *  Inport: '<Root>/In26'
   */
  EngAnly_rpmEngSpdBrakeLThrUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (MeterTCO1_kmphVehSpdUB, (&(MapVehSpd2BrakeEngSpdLThr_kmphVehSpdUWA[0])),
     (&(MapVehSpd2BrakeEngSpdLThr_rpmEngSpdUWA[0])),
     &Func_EngSpdSlideBrakeLThrUpd_DW.m_bpIndex, 18U);

  /* Lookup_n-D: '<S12>/Map_EngAnly_VehSpd2SlideEngSpdLThr' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion7'
   *  Inport: '<Root>/In26'
   */
  EngAnly_rpmEngSpdSlideLThrUW = look1_iu16lu32n32yu16t_0NvOblQd
    (MeterTCO1_kmphVehSpdUB, (&(MapVehSpd2SlideEngSpdLThr_kmphVehSpdUWA[0])),
     ZHVCU_ConstP.Map_EngAnly_VehSpd2SlideEngSpdL,
     &Func_EngSpdSlideBrakeLThrUpd_DW.m_bpIndex_i, 18U);
}

/* System initialize for atomic system: '<Root>/Func_EngTask' */
void ZHVCU_Func_EngTask_Init(void)
{
  CANTxAllow_stECUTSC1UB = 0U;
  ECUTSC1_pctTrqDmdLmtUB = 0U;
  ECUTSC1_rpmSpdDmdLmtUW = 0U;
  ECUTSC1_stEngOverrideCtrlMdeUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_EngTask' */
void ZHVCU_Func_EngTask(void)
{
  /* Gateway: Func_EngTask */
  /* During: Func_EngTask */
  /* Entry Internal: Func_EngTask */
  /* Transition: '<S13>:1' */
  if (SubSysTskExe_stECUUB == SubSysTsk_ECU_Exit) {
    /* Transition: '<S13>:7' */
    /* Transition: '<S13>:14' */
    CANTxAllow_stECUTSC1UB = 1U;
    ECUTSC1_stEngOverrideCtrlMdeUB = (uint8_T)EngCtrlMd_CtrlOff;
    ECUTSC1_rpmSpdDmdLmtUW = 0U;
    ECUTSC1_pctTrqDmdLmtUB = 0U;

    /* Transition: '<S13>:86' */
    /* Transition: '<S13>:42' */
    /* Transition: '<S13>:41' */
    /* Transition: '<S13>:96' */
    /* Transition: '<S13>:98' */
    /* Transition: '<S13>:90' */
  } else if (SubSysTskExe_stECUUB == SubSysTsk_ECU_Drv) {
    /* Transition: '<S13>:9' */
    /* Transition: '<S13>:16' */
    CANTxAllow_stECUTSC1UB = 1U;
    ECUTSC1_stEngOverrideCtrlMdeUB = (uint8_T)EngCtrlMd_TrqCtrl;
    ECUTSC1_rpmSpdDmdLmtUW = 0U;
    ECUTSC1_pctTrqDmdLmtUB = TrqCtrl_pctEngTrqCtrlUB;

    /* Transition: '<S13>:42' */
    /* Transition: '<S13>:41' */
    /* Transition: '<S13>:96' */
    /* Transition: '<S13>:98' */
    /* Transition: '<S13>:90' */
  } else if (SubSysTskExe_stECUUB == SubSysTsk_ECU_Slide) {
    /* Inport: '<Root>/In6' */
    /* Transition: '<S13>:34' */
    if (ECUEEC1_rpmEngSpdUW > EngAnly_rpmEngSpdSlideLThrUW) {
      /* Transition: '<S13>:37' */
      /* Transition: '<S13>:39' */
      CANTxAllow_stECUTSC1UB = 1U;
      ECUTSC1_stEngOverrideCtrlMdeUB = (uint8_T)EngCtrlMd_TrqCtrl;
      ECUTSC1_rpmSpdDmdLmtUW = 0U;
      ECUTSC1_pctTrqDmdLmtUB = EngCtrl_pctSlideTrqDmdUB;

      /* Transition: '<S13>:41' */
      /* Transition: '<S13>:96' */
      /* Transition: '<S13>:98' */
      /* Transition: '<S13>:90' */
    } else {
      /* Transition: '<S13>:40' */
      CANTxAllow_stECUTSC1UB = 1U;
      ECUTSC1_stEngOverrideCtrlMdeUB = (uint8_T)EngCtrlMd_CtrlOff;
      ECUTSC1_rpmSpdDmdLmtUW = 0U;
      ECUTSC1_pctTrqDmdLmtUB = 0U;

      /* Transition: '<S13>:96' */
      /* Transition: '<S13>:98' */
      /* Transition: '<S13>:90' */
    }

    /* End of Inport: '<Root>/In6' */
  } else if ((SubSysTskExe_stECUUB == SubSysTsk_ECU_Brake) &&
             (ECUEEC1_rpmEngSpdUW > EngAnly_rpmEngSpdBrakeLThrUW)) {
    /* Transition: '<S13>:10' */
    /* Transition: '<S13>:94' */
    /* Transition: '<S13>:97' */
    CANTxAllow_stECUTSC1UB = 1U;
    ECUTSC1_stEngOverrideCtrlMdeUB = (uint8_T)EngCtrlMd_TrqCtrl;
    ECUTSC1_rpmSpdDmdLmtUW = 0U;
    ECUTSC1_pctTrqDmdLmtUB = EngCtrl_pctBrakeTrqDmdUB;

    /* Transition: '<S13>:98' */
    /* Transition: '<S13>:90' */
  } else {
    /* Transition: '<S13>:92' */
    /* Transition: '<S13>:91' */
    /* Transition: '<S13>:90' */
  }

  /* Transition: '<S13>:21' */
}

/* Output and update for atomic system: '<Root>/Func_EngTrqCrtRatio2NmTrqCrt' */
void ZH_Func_EngTrqCrtRatio2NmTrqCrt(void)
{
  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant3'
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  DataTypeConversion: '<S14>/Data Type Conversion5'
   *  Product: '<S14>/Divide8'
   *  Product: '<S14>/Divide9'
   *  Sum: '<S14>/Add'
   */
  TrqCtrl_nmVehMassEngTrqCrtRatioUW = (uint16_T)((100U -
    TrqCtrl_pctVehMassEngTrqCrtRatioUW) * EngAnly_nmEngRTOutCurveTrqUW / 100U);
}

/* Output and update for atomic system: '<Root>/Func_EngTrqDmdCrtRatioCal' */
void ZHVCU_Func_EngTrqDmdCrtRatioCal(void)
{
  /* DataTypeConversion: '<S15>/Data Type Conversion7' incorporates:
   *  Constant: '<S15>/Constant5'
   *  DataTypeConversion: '<S15>/Data Type Conversion5'
   *  DataTypeConversion: '<S15>/Data Type Conversion6'
   *  Product: '<S15>/Divide8'
   *  Product: '<S15>/Divide9'
   */
  TrqCtrl_nmTrqDmdCrtUW = (uint16_T)((uint32_T)TrqCtrl_nmTrqDmdCrtRawUW *
    TrqCtrl_pctTrqDmdCrtRatioUW / 100U);
}

/* Output and update for atomic system: '<Root>/Func_EngTrqNm2Pct' */
void ZHVCU_Func_EngTrqNm2Pct(void)
{
  uint32_T rtb_Divide9_h0;

  /* Product: '<S16>/Divide9' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DataTypeConversion: '<S16>/Data Type Conversion5'
   *  Inport: '<Root>/In11'
   *  Product: '<S16>/Divide8'
   */
  rtb_Divide9_h0 = TrqCtrl_nmEngTrqCtrlUW * 100U / ECUEC1_nmEngRefTrqUW;

  /* Switch: '<S40>/Switch2' incorporates:
   *  Constant: '<Root>/TrqCtrl_pctEngTrqCtrlLowLmtUBC'
   *  Constant: '<Root>/TrqCtrl_pctEngTrqCtrlUpLmtUBC'
   *  RelationalOperator: '<S40>/LowerRelop1'
   *  RelationalOperator: '<S40>/UpperRelop'
   *  Switch: '<S40>/Switch'
   */
  if (rtb_Divide9_h0 > TrqCtrl_pctEngTrqCtrlUpLmtUBC) {
    TrqCtrl_pctEngTrqCtrlUB = TrqCtrl_pctEngTrqCtrlUpLmtUBC;
  } else if (rtb_Divide9_h0 < TrqCtrl_pctEngTrqCtrlLowLmtUBC) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<Root>/TrqCtrl_pctEngTrqCtrlLowLmtUBC'
     */
    TrqCtrl_pctEngTrqCtrlUB = TrqCtrl_pctEngTrqCtrlLowLmtUBC;
  } else {
    TrqCtrl_pctEngTrqCtrlUB = (uint8_T)rtb_Divide9_h0;
  }

  /* End of Switch: '<S40>/Switch2' */
}

/* Output and update for atomic system: '<Root>/Func_EngTrqNm2Pct1' */
void ZHVCU_Func_EngTrqNm2Pct1(void)
{
  uint32_T rtb_Divide9_m;

  /* Product: '<S17>/Divide9' incorporates:
   *  Constant: '<Root>/VehAnly_tVehActualMassUB'
   *  Constant: '<Root>/VehAnly_tVehBasicMassUBC'
   *  Constant: '<S17>/Constant3'
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   *  DataTypeConversion: '<S17>/Data Type Conversion5'
   *  Product: '<S17>/Divide8'
   */
  rtb_Divide9_m = VehAnly_tVehActualMassUB * 100U / VehAnly_tVehBasicMassUBC;

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<Root>/VehAnly_pctVehMassRatioLowLmtUBC'
   *  Constant: '<Root>/VehAnly_pctVehMassRatioUpLmtUBC'
   *  RelationalOperator: '<S41>/LowerRelop1'
   *  RelationalOperator: '<S41>/UpperRelop'
   *  Switch: '<S41>/Switch'
   */
  if (rtb_Divide9_m > VehAnly_pctVehMassRatioUpLmtUBC) {
    VehAnly_pctVehMassRatioUB = VehAnly_pctVehMassRatioUpLmtUBC;
  } else if (rtb_Divide9_m < VehAnly_pctVehMassRatioLowLmtUBC) {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<Root>/VehAnly_pctVehMassRatioLowLmtUBC'
     */
    VehAnly_pctVehMassRatioUB = VehAnly_pctVehMassRatioLowLmtUBC;
  } else {
    VehAnly_pctVehMassRatioUB = (uint8_T)rtb_Divide9_m;
  }

  /* End of Switch: '<S41>/Switch2' */
}

/* Function for Chart: '<Root>/Func_GearCal' */
static void ZHVCU_VehAnly_GearDXTimeReset(void)
{
  /* Graphical Function 'VehAnly_GearDXTimeReset': '<S18>:190' */
  /* Transition: '<S18>:193' */
  /* Transition: '<S18>:194' */
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD1TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD2TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD3TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD4TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD5TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD6TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD7TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD8TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD9TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD10TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD11TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD12TimerUW = 0U;
}

/* System initialize for atomic system: '<Root>/Func_GearCal' */
void ZHVCU_Func_GearCal_Init(void)
{
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD10TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD11TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD12TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD1TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD2TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD3TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD4TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD5TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD6TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD7TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD8TimerUW = 0U;
  ZHVCU_Func_GearCal_DW.VehAnly_numGearD9TimerUW = 0U;
  VehAnly_numGearNowUW = 0U;
  VehAnly_rGearBoxRatioUW = 0U;
}

/* Output and update for atomic system: '<Root>/Func_GearCal' */
void ZHVCU_Func_GearCal(void)
{
  int32_T tmp;

  /* Inport: '<Root>/In181' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  /* Gateway: Func_GearCal */
  /* During: Func_GearCal */
  /* Entry Internal: Func_GearCal */
  /* Transition: '<S18>:1' */
  if ((SWSen_stNeutralSWUB != 1) && (SWSen_stReverseSWUB == 1) &&
      (SWSen_stClutchSWUB == 0)) {
    /* Transition: '<S18>:91' */
    /* Transition: '<S18>:94' */
    VehAnly_numGearNowUW = (uint16_T)Gear_R;
    ZHVCU_VehAnly_GearDXTimeReset();
    VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_R;
    SWAnly_stGearChgUB = 0U;

    /* Transition: '<S18>:93' */
  } else if ((SWSen_stNeutralSWUB != 1) && (SWSen_stReverseSWUB != 1) &&
             (SWSen_stClutchSWUB == 0)) {
    /* Transition: '<S18>:86' */
    if ((VehAnly_rGearRatioUW >= GearRatio_D1_LThr) && (VehAnly_rGearRatioUW <
         GearRatio_D1_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:9' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD1TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:98' */
        /* Transition: '<S18>:100' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD1TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD1TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:101' */
        /* Transition: '<S18>:230' */
      } else {
        /* Transition: '<S18>:226' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:228' */
          /* Transition: '<S18>:13' */
          SWAnly_stGearChgUB = 0U;
          VehAnly_numGearNowUW = (uint16_T)Gear_D1;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D1;

          /* Transition: '<S18>:230' */
        } else {
          /* Transition: '<S18>:232' */
        }
      }

      /* Transition: '<S18>:231' */
      /* Transition: '<S18>:107' */
      /* Transition: '<S18>:237' */
      /* Transition: '<S18>:238' */
      /* Transition: '<S18>:118' */
      /* Transition: '<S18>:319' */
      /* Transition: '<S18>:320' */
      /* Transition: '<S18>:122' */
      /* Transition: '<S18>:283' */
      /* Transition: '<S18>:284' */
      /* Transition: '<S18>:127' */
      /* Transition: '<S18>:286' */
      /* Transition: '<S18>:287' */
      /* Transition: '<S18>:132' */
      /* Transition: '<S18>:289' */
      /* Transition: '<S18>:290' */
      /* Transition: '<S18>:137' */
      /* Transition: '<S18>:292' */
      /* Transition: '<S18>:293' */
      /* Transition: '<S18>:143' */
      /* Transition: '<S18>:296' */
      /* Transition: '<S18>:295' */
      /* Transition: '<S18>:148' */
      /* Transition: '<S18>:299' */
      /* Transition: '<S18>:298' */
      /* Transition: '<S18>:153' */
      /* Transition: '<S18>:301' */
      /* Transition: '<S18>:302' */
      /* Transition: '<S18>:158' */
      /* Transition: '<S18>:304' */
      /* Transition: '<S18>:305' */
      /* Transition: '<S18>:163' */
      /* Transition: '<S18>:307' */
      /* Transition: '<S18>:308' */
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D2_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D2_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:11' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD2TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:104' */
        /* Transition: '<S18>:106' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD2TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD2TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:107' */
        /* Transition: '<S18>:237' */
        /* Transition: '<S18>:238' */
        /* Transition: '<S18>:118' */
        /* Transition: '<S18>:319' */
        /* Transition: '<S18>:320' */
        /* Transition: '<S18>:122' */
        /* Transition: '<S18>:283' */
        /* Transition: '<S18>:284' */
        /* Transition: '<S18>:127' */
        /* Transition: '<S18>:286' */
        /* Transition: '<S18>:287' */
        /* Transition: '<S18>:132' */
        /* Transition: '<S18>:289' */
        /* Transition: '<S18>:290' */
        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:234' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:240' */
          /* Transition: '<S18>:15' */
          SWAnly_stGearChgUB = 0U;
          VehAnly_numGearNowUW = (uint16_T)Gear_D2;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D2;

          /* Transition: '<S18>:237' */
          /* Transition: '<S18>:238' */
          /* Transition: '<S18>:118' */
          /* Transition: '<S18>:319' */
          /* Transition: '<S18>:320' */
          /* Transition: '<S18>:122' */
          /* Transition: '<S18>:283' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:241' */
          /* Transition: '<S18>:238' */
          /* Transition: '<S18>:118' */
          /* Transition: '<S18>:319' */
          /* Transition: '<S18>:320' */
          /* Transition: '<S18>:122' */
          /* Transition: '<S18>:283' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D3_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D3_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:18' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD3TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:115' */
        /* Transition: '<S18>:117' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD3TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD3TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:118' */
        /* Transition: '<S18>:319' */
        /* Transition: '<S18>:320' */
        /* Transition: '<S18>:122' */
        /* Transition: '<S18>:283' */
        /* Transition: '<S18>:284' */
        /* Transition: '<S18>:127' */
        /* Transition: '<S18>:286' */
        /* Transition: '<S18>:287' */
        /* Transition: '<S18>:132' */
        /* Transition: '<S18>:289' */
        /* Transition: '<S18>:290' */
        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:243' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:244' */
          /* Transition: '<S18>:20' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D3;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D3;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:319' */
          /* Transition: '<S18>:320' */
          /* Transition: '<S18>:122' */
          /* Transition: '<S18>:283' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:321' */
          /* Transition: '<S18>:320' */
          /* Transition: '<S18>:122' */
          /* Transition: '<S18>:283' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D4_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D4_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:22' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD4TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:120' */
        /* Transition: '<S18>:123' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD4TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD4TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:122' */
        /* Transition: '<S18>:283' */
        /* Transition: '<S18>:284' */
        /* Transition: '<S18>:127' */
        /* Transition: '<S18>:286' */
        /* Transition: '<S18>:287' */
        /* Transition: '<S18>:132' */
        /* Transition: '<S18>:289' */
        /* Transition: '<S18>:290' */
        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:247' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:248' */
          /* Transition: '<S18>:24' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D4;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D4;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:283' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:317' */
          /* Transition: '<S18>:284' */
          /* Transition: '<S18>:127' */
          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D5_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D5_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:26' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD5TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:125' */
        /* Transition: '<S18>:128' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD5TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD5TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:127' */
        /* Transition: '<S18>:286' */
        /* Transition: '<S18>:287' */
        /* Transition: '<S18>:132' */
        /* Transition: '<S18>:289' */
        /* Transition: '<S18>:290' */
        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:251' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:252' */
          /* Transition: '<S18>:28' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D5;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D5;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:286' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:316' */
          /* Transition: '<S18>:287' */
          /* Transition: '<S18>:132' */
          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D6_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D6_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:30' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD6TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:130' */
        /* Transition: '<S18>:133' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD6TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD6TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:132' */
        /* Transition: '<S18>:289' */
        /* Transition: '<S18>:290' */
        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:255' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:256' */
          /* Transition: '<S18>:32' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D6;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D6;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:289' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:315' */
          /* Transition: '<S18>:290' */
          /* Transition: '<S18>:137' */
          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D7_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D7_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:34' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD7TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:135' */
        /* Transition: '<S18>:138' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD7TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD7TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:137' */
        /* Transition: '<S18>:292' */
        /* Transition: '<S18>:293' */
        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:259' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:260' */
          /* Transition: '<S18>:36' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D7;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D7;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:292' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:314' */
          /* Transition: '<S18>:293' */
          /* Transition: '<S18>:143' */
          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D8_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D8_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:38' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD8TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:140' */
        /* Transition: '<S18>:142' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD8TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD8TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:143' */
        /* Transition: '<S18>:296' */
        /* Transition: '<S18>:295' */
        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:263' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:264' */
          /* Transition: '<S18>:40' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D8;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D8;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:296' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:313' */
          /* Transition: '<S18>:295' */
          /* Transition: '<S18>:148' */
          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D9_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D9_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:42' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD9TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:145' */
        /* Transition: '<S18>:147' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD9TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD9TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:148' */
        /* Transition: '<S18>:299' */
        /* Transition: '<S18>:298' */
        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:267' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:268' */
          /* Transition: '<S18>:44' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D9;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D9;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:299' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:312' */
          /* Transition: '<S18>:298' */
          /* Transition: '<S18>:153' */
          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D10_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D10_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:46' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD10TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:150' */
        /* Transition: '<S18>:152' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD10TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD10TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:153' */
        /* Transition: '<S18>:301' */
        /* Transition: '<S18>:302' */
        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:271' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:272' */
          /* Transition: '<S18>:48' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D10;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D10;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:301' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:311' */
          /* Transition: '<S18>:302' */
          /* Transition: '<S18>:158' */
          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D11_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D11_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:50' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD11TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:155' */
        /* Transition: '<S18>:157' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD11TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD11TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:158' */
        /* Transition: '<S18>:304' */
        /* Transition: '<S18>:305' */
        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:275' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:276' */
          /* Transition: '<S18>:52' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D11;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D11;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:304' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:310' */
          /* Transition: '<S18>:305' */
          /* Transition: '<S18>:163' */
          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        }
      }
    } else if ((VehAnly_rGearRatioUW >= GearRatio_D12_LThr) &&
               (VehAnly_rGearRatioUW < GearRatio_D12_HThr)) {
      /* Constant: '<Root>/Constant13' */
      /* Transition: '<S18>:54' */
      if (ZHVCU_Func_GearCal_DW.VehAnly_numGearD12TimerUW <
          VehAnly_numGearConfirmTimeUWC) {
        /* Transition: '<S18>:160' */
        /* Transition: '<S18>:162' */
        tmp = ZHVCU_Func_GearCal_DW.VehAnly_numGearD12TimerUW + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        ZHVCU_Func_GearCal_DW.VehAnly_numGearD12TimerUW = (uint16_T)tmp;

        /* Transition: '<S18>:163' */
        /* Transition: '<S18>:307' */
        /* Transition: '<S18>:308' */
      } else {
        /* Transition: '<S18>:279' */
        ZHVCU_VehAnly_GearDXTimeReset();
        if (SWAnly_stGearChgUB == 1) {
          /* Transition: '<S18>:280' */
          /* Transition: '<S18>:56' */
          VehAnly_numGearNowUW = (uint16_T)Gear_D12;
          VehAnly_rGearBoxRatioUW = (uint16_T)GearBoxRatio_D12;
          SWAnly_stGearChgUB = 0U;

          /* Transition: '<S18>:307' */
          /* Transition: '<S18>:308' */
        } else {
          /* Transition: '<S18>:309' */
          /* Transition: '<S18>:308' */
        }
      }
    } else {
      /* Transition: '<S18>:58' */
      ZHVCU_VehAnly_GearDXTimeReset();
    }

    /* Transition: '<S18>:72' */
    /* Transition: '<S18>:93' */
  } else {
    /* Transition: '<S18>:73' */
    VehAnly_numGearNowUW = (uint16_T)Gear_N;
    ZHVCU_VehAnly_GearDXTimeReset();
  }

  /* End of Inport: '<Root>/In181' */
  /* Transition: '<S18>:75' */
}

/* Output and update for atomic system: '<Root>/Func_GearRatioCal' */
void ZHVCU_Func_GearRatioCal(void)
{
  uint32_T rtb_Divide7;

  /* Product: '<S19>/Divide7' incorporates:
   *  Constant: '<S19>/Constant6'
   *  DataTypeConversion: '<S19>/DTC'
   *  DataTypeConversion: '<S19>/DTC1'
   *  Inport: '<Root>/In25'
   *  Inport: '<Root>/In6'
   *  Product: '<S19>/Divide6'
   */
  rtb_Divide7 = MeterTCO1_kmphVehSpdF100UW * 100U / ECUEEC1_rpmEngSpdUW;

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S19>/Constant1'
   *  RelationalOperator: '<S42>/LowerRelop1'
   */
  if (rtb_Divide7 > 1000U) {
    rtb_Divide7 = 1000U;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* DataTypeConversion: '<S19>/DTC2' */
  VehAnly_rGearRatioUW = (uint16_T)rtb_Divide7;
}

/* System initialize for atomic system: '<Root>/Func_STActionAllONChart' */
void ZH_Func_STActionAllONChart_Init(void)
{
  MdST_stMainMdUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_STActionAllONChart' */
void ZHVCU_Func_STActionAllONChart(void)
{
  /* Inport: '<Root>/In193' */
  /* Gateway: Func_STActionAllONChart */
  /* During: Func_STActionAllONChart */
  /* Entry Internal: Func_STActionAllONChart */
  /* Transition: '<S20>:185' */
  if (SWSen_stONSWUB == 0) {
    /* Transition: '<S20>:216' */
    /* Transition: '<S20>:218' */
    DrvMdST_stSSWorkStUB = 0U;

    /* Transition: '<S20>:219' */
  } else {
    /* Transition: '<S20>:214' */
  }

  /* Inport: '<Root>/In42' */
  /* Transition: '<S20>:211' */
  if ((EngAnly_stEngStartedStUB == 0) && (DrvMdST_stSSWorkStUB == 0)) {
    /* Inport: '<Root>/In193' incorporates:
     *  Inport: '<Root>/In183'
     */
    /* Transition: '<S20>:187' */
    if ((SWSen_stONSWUB == 1) && (SWSen_stStartSWUB == 1)) {
      /* Transition: '<S20>:201' */
      /* Transition: '<S20>:205' */
      MdST_stMainMdUB = (uint8_T)MdST_stMainMdUB_Start;

      /* Transition: '<S20>:203' */
    } else {
      /* Transition: '<S20>:198' */
      MdST_stMainMdUB = (uint8_T)MdST_stMainMdUB_Stop;
    }

    /* Transition: '<S20>:194' */
  } else {
    /* Transition: '<S20>:190' */
    MdST_stMainMdUB = (uint8_T)MdST_stMainMdUB_Drv;
  }

  /* End of Inport: '<Root>/In42' */
  /* Transition: '<S20>:197' */
}

/* Output and update for atomic system: '<Root>/Func_SlideEngTrqDmdUpdt' */
void ZHVCU_Func_SlideEngTrqDmdUpdt(void)
{
  uint8_T rtb_Map_EngAnly_VehSpd2SlideEng;
  uint16_T rtb_Map_EngAnly_EngSpd2SlideEng;
  uint32_T rtb_Divide9_k;

  /* Lookup_n-D: '<S21>/Map_EngAnly_VehSpd2SlideEngTrqPctCtrl' incorporates:
   *  Inport: '<Root>/In26'
   */
  rtb_Map_EngAnly_VehSpd2SlideEng = look1_iu8lu32n32yu8Ds1_Y0hbqrP2
    (MeterTCO1_kmphVehSpdUB, (&(MapVehSpd2SlideEngTrqPctCtrl_kmphVehSpdUBA[0])),
     (&(MapVehSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUBWA[0])),
     &ZHVC_Func_SlideEngTrqDmdUpdt_DW.m_bpIndex, 22U);

  /* Lookup_n-D: '<S21>/Map_EngAnly_EngSpd2SlideEngTrqPctCtrl' incorporates:
   *  Inport: '<Root>/In6'
   */
  rtb_Map_EngAnly_EngSpd2SlideEng = look1_iu16lu32n32yu16D_HfJiOU2v
    (ECUEEC1_rpmEngSpdUW, (&(MapEngSpd2SlideEngTrqPctCtrl_rpmEngSpdUWA[0])),
     (&(MapEngSpd2SlideEngTrqPctCtrl_pctEngTrqCtrlUWA[0])),
     &ZHVC_Func_SlideEngTrqDmdUpdt_DW.m_bpIndex_c, 26U);

  /* Product: '<S21>/Divide9' incorporates:
   *  Constant: '<S21>/Constant3'
   *  DataTypeConversion: '<S21>/Data Type Conversion2'
   *  DataTypeConversion: '<S21>/Data Type Conversion5'
   *  Product: '<S21>/Divide8'
   */
  rtb_Divide9_k = (uint32_T)rtb_Map_EngAnly_EngSpd2SlideEng *
    rtb_Map_EngAnly_VehSpd2SlideEng / 100U;

  /* Switch: '<S43>/Switch2' incorporates:
   *  Constant: '<S21>/Constant4'
   *  RelationalOperator: '<S43>/LowerRelop1'
   *  Switch: '<S43>/Switch'
   */
  if (rtb_Divide9_k > 30U) {
    EngCtrl_pctSlideTrqDmdUB = 30U;
  } else {
    EngCtrl_pctSlideTrqDmdUB = (uint8_T)rtb_Divide9_k;
  }

  /* End of Switch: '<S43>/Switch2' */
}

/* System initialize for atomic system: '<S22>/StartMd' */
void ZHVCU_StartMd_Init(void)
{
  ZHVCU_StartMd_DW.MdST_stMdCalUB = 0U;
  ZHVCU_StartMd_DW.SubSysTsk_stECUUB = 0U;
  ZHVCU_StartMd_DW.SubSysTsk_stStartSWChOUB = 0U;
  ZHVCU_StartMd_DW.SubSysTsk_stViceSSUB = 0U;
  ZHVCU_StartMd_DW.SubSysTsk_stCANUB = 0U;
  ZHVCU_StartMd_DW.SubSysTsk_stMeterUB = 0U;
}

/* Output and update for atomic system: '<S22>/StartMd' */
void ZHVCU_StartMd(void)
{
  /* Gateway: Func_StartMd/StartMd */
  /* During: Func_StartMd/StartMd */
  /* Entry Internal: Func_StartMd/StartMd */
  /* Transition: '<S44>:45' */
  /* 模式执行动作 */
  MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_Exit;
  MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_StarterStart;
  MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Exit;
  ZHVCU_StartMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stStartMdUB_StarterStart;

  /* 子系统执行动作 */
  ZHVCU_StartMd_DW.SubSysTsk_stCANUB = (uint8_T)SubSysTsk_CAN_POST;
  ZHVCU_StartMd_DW.SubSysTsk_stMeterUB = (uint8_T)SubSysTsk_Meter_POST;
  ZHVCU_StartMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
  ZHVCU_StartMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
  ZHVCU_StartMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)SubSysTsk_StartSWChO_OFF;
}

/* System initialize for enable system: '<Root>/Func_StartMd' */
void ZHVCU_Func_StartMd_Init(void)
{
  /* SystemInitialize for Chart: '<S22>/StartMd' */
  ZHVCU_StartMd_Init();
}

/* Output and update for enable system: '<Root>/Func_StartMd' */
void ZHVCU_Func_StartMd(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/Func_StartMd' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (ZHVCU_DWork.RelationalOperator1) {
    /* Chart: '<S22>/StartMd' */
    ZHVCU_StartMd();
  }

  /* End of Outputs for SubSystem: '<Root>/Func_StartMd' */
}

/* System initialize for atomic system: '<Root>/Func_StartSWChOTask' */
void ZHVCU_Func_StartSWChOTask_Init(void)
{
  PwrDrv_stStartSWChORlyUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_StartSWChOTask' */
void ZHVCU_Func_StartSWChOTask(void)
{
  /* Gateway: Func_StartSWChOTask */
  /* During: Func_StartSWChOTask */
  /* Entry Internal: Func_StartSWChOTask */
  /* Transition: '<S23>:1' */
  if (SubSysTskExe_stStartSWChOUB == SubSysTsk_StartSWChO_ON) {
    /* Transition: '<S23>:5' */
    /* Transition: '<S23>:7' */
    PwrDrv_stStartSWChORlyUB = 1U;

    /* Transition: '<S23>:10' */
  } else {
    /* Transition: '<S23>:9' */
    PwrDrv_stStartSWChORlyUB = 0U;
  }

  /* Transition: '<S23>:13' */
}

/* System initialize for atomic system: '<S24>/StopMd' */
void ZHVCU_StopMd_Init(void)
{
  ZHVCU_StopMd_DW.MdST_stMdCalUB = 0U;
  ZHVCU_StopMd_DW.SubSysTsk_stECUUB = 0U;
  ZHVCU_StopMd_DW.SubSysTsk_stStartSWChOUB = 0U;
  ZHVCU_StopMd_DW.SubSysTsk_stViceSSUB = 0U;
  ZHVCU_StopMd_DW.SubSysTsk_stCANUB = 0U;
  ZHVCU_StopMd_DW.SubSysTsk_stMeterUB = 0U;
}

/* Output and update for atomic system: '<S24>/StopMd' */
void ZHVCU_StopMd(void)
{
  /* Gateway: Func_StopMd/StopMd */
  /* During: Func_StopMd/StopMd */
  /* Entry Internal: Func_StopMd/StopMd */
  /* Transition: '<S45>:45' */
  /* 模式执行动作 */
  MdST_stStopMdUB = (uint8_T)MdST_stStopMdUB_ON;
  MdST_stStartMdUB = (uint8_T)MdST_stStartMdUB_Exit;
  MdST_stDrvMdUB = (uint8_T)MdST_stDrvMdUB_Exit;
  ZHVCU_StopMd_DW.MdST_stMdCalUB = (uint8_T)MdST_stStopMdUB_ON;

  /* 子系统执行动作 */
  ZHVCU_StopMd_DW.SubSysTsk_stCANUB = (uint8_T)SubSysTsk_CAN_POST;
  ZHVCU_StopMd_DW.SubSysTsk_stMeterUB = (uint8_T)SubSysTsk_Meter_POST;
  ZHVCU_StopMd_DW.SubSysTsk_stECUUB = (uint8_T)SubSysTsk_ECU_Exit;
  ZHVCU_StopMd_DW.SubSysTsk_stViceSSUB = (uint8_T)SubSysTsk_ViceSS_Exit;
  ZHVCU_StopMd_DW.SubSysTsk_stStartSWChOUB = (uint8_T)SubSysTsk_StartSWChO_OFF;
}

/* System initialize for enable system: '<Root>/Func_StopMd' */
void ZHVCU_Func_StopMd_Init(void)
{
  /* SystemInitialize for Chart: '<S24>/StopMd' */
  ZHVCU_StopMd_Init();
}

/* Output and update for enable system: '<Root>/Func_StopMd' */
void ZHVCU_Func_StopMd(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/Func_StopMd' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  if (ZHVCU_DWork.RelationalOperator5) {
    /* Chart: '<S24>/StopMd' */
    ZHVCU_StopMd();
  }

  /* End of Outputs for SubSystem: '<Root>/Func_StopMd' */
}

/* System initialize for atomic system: '<Root>/Func_TSStUpdt' */
void ZHVCU_Func_TSStUpdt_Init(void)
{
  VehAnly_stTSConedUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_TSStUpdt' */
void ZHVCU_Func_TSStUpdt(void)
{
  /* Inport: '<Root>/In181' incorporates:
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In9'
   */
  /* Gateway: Func_TSStUpdt */
  /* During: Func_TSStUpdt */
  /* Entry Internal: Func_TSStUpdt */
  /* Transition: '<S25>:1' */
  if ((SWSen_stNeutralSWUB == 0) && (SWSen_stClutchSWUB == 1) &&
      (ECUEEC2_pctAccelPedalPosUB > 3)) {
    /* Transition: '<S25>:3' */
    /* Transition: '<S25>:8' */
    VehAnly_stTSConedUB = (uint8_T)VehAnly_stTSConedUB_HalfClosed;

    /* Transition: '<S25>:14' */
    /* Transition: '<S25>:15' */
  } else if ((SWSen_stNeutralSWUB == 0) && (SWSen_stClutchSWUB == 0)) {
    /* Transition: '<S25>:6' */
    /* Transition: '<S25>:9' */
    VehAnly_stTSConedUB = (uint8_T)VehAnly_stTSConedUB_Closed;

    /* Transition: '<S25>:15' */
  } else {
    /* Transition: '<S25>:5' */
    VehAnly_stTSConedUB = (uint8_T)VehAnly_stTSConedUB_Open;
  }

  /* End of Inport: '<Root>/In181' */
  /* Transition: '<S25>:16' */
}

/* System initialize for atomic system: '<Root>/Func_TrqCtrlEngTrqCtrlStep' */
void Func_TrqCtrlEngTrqCtrlStep_Init(void)
{
  TrqCtrl_nmEngRawTrqCtrlUW = 0U;
}

/* Output and update for atomic system: '<Root>/Func_TrqCtrlEngTrqCtrlStep' */
void ZHVC_Func_TrqCtrlEngTrqCtrlStep(void)
{
  int32_T tmp;

  /* Gateway: Func_TrqCtrlEngTrqCtrlStep */
  /* During: Func_TrqCtrlEngTrqCtrlStep */
  /* Entry Internal: Func_TrqCtrlEngTrqCtrlStep */
  /* Transition: '<S26>:14' */
  if ((EngAnly_nmActualTrqUW < TrqCtrl_nmTrqDmdAftCrtUW) &&
      (TrqCtrl_nmTrqDmdAftCrtUW - EngAnly_nmActualTrqUW >
       TrqCtrl_nmEngTrqCtrlMinDiffUW)) {
    /* Transition: '<S26>:17' */
    if (TrqCtrl_numEngTrqIncStepmsTimerUW < TrqCtrl_numEngTrqIncStepmsTimeUW) {
      /* Transition: '<S26>:22' */
      /* Transition: '<S26>:24' */
      tmp = TrqCtrl_numEngTrqIncStepmsTimerUW + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      TrqCtrl_numEngTrqIncStepmsTimerUW = (uint16_T)tmp;

      /* Transition: '<S26>:27' */
    } else {
      /* Transition: '<S26>:26' */
      tmp = EngAnly_nmActualTrqUW + TrqCtrl_nmEngTrqIncStepUW;
      if (tmp > 65535) {
        tmp = 65535;
      }

      TrqCtrl_nmEngRawTrqCtrlUW = (uint16_T)tmp;
      TrqCtrl_numEngTrqIncStepmsTimerUW = 0U;
    }

    /* Transition: '<S26>:49' */
    /* Transition: '<S26>:37' */
  } else if (EngAnly_nmActualTrqUW > TrqCtrl_nmTrqDmdAftCrtUW) {
    /* Transition: '<S26>:29' */
    /* Transition: '<S26>:35' */
    TrqCtrl_nmEngRawTrqCtrlUW = TrqCtrl_nmTrqDmdAftCrtUW;
    TrqCtrl_numEngTrqIncStepmsTimerUW = 0U;

    /* Transition: '<S26>:37' */
  } else {
    /* Transition: '<S26>:36' */
    TrqCtrl_nmEngRawTrqCtrlUW = EngAnly_nmActualTrqUW;
    TrqCtrl_numEngTrqIncStepmsTimerUW = 0U;
  }

  /* Transition: '<S26>:41' */
}

/* System initialize for atomic system: '<Root>/Func_TrqMng_EngTrqDmdDiff' */
void Func_TrqMng_EngTrqDmdDiff_Init(void)
{
  TrqCtrl_nmTrqDmdIncDiffUW = 0U;
}

/* Output and update for atomic system: '<Root>/Func_TrqMng_EngTrqDmdDiff' */
void ZHVCU_Func_TrqMng_EngTrqDmdDiff(void)
{
  int32_T tmp;

  /* Gateway: Func_TrqMng_EngTrqDmdDiff */
  /* During: Func_TrqMng_EngTrqDmdDiff */
  /* Entry Internal: Func_TrqMng_EngTrqDmdDiff */
  /* Transition: '<S27>:1' */
  if (TrqCtrl_nmTrqDmdAftCrtUW >= EngAnly_nmActualTrqUW) {
    /* Transition: '<S27>:8' */
    /* Transition: '<S27>:9' */
    tmp = TrqCtrl_nmTrqDmdAftCrtUW - EngAnly_nmActualTrqUW;
    if (tmp < 0) {
      tmp = 0;
    }

    TrqCtrl_nmTrqDmdIncDiffUW = (uint16_T)tmp;

    /* Transition: '<S27>:10' */
  } else {
    /* Transition: '<S27>:11' */
    TrqCtrl_nmTrqDmdIncDiffUW = 0U;
  }

  /* Transition: '<S27>:12' */
}

/* System initialize for atomic system: '<Root>/Func_TrqMng_TrqDmdCrt' */
void ZHVC_Func_TrqMng_TrqDmdCrt_Init(void)
{
  TrqCtrl_nmTrqDmdAftCrtUW = 0U;
}

/* Output and update for atomic system: '<Root>/Func_TrqMng_TrqDmdCrt' */
void ZHVCU_Func_TrqMng_TrqDmdCrt(void)
{
  int32_T tmp;

  /* Gateway: Func_TrqMng_TrqDmdCrt */
  /* During: Func_TrqMng_TrqDmdCrt */
  /* Entry Internal: Func_TrqMng_TrqDmdCrt */
  /* Transition: '<S28>:1' */
  if (TrqCtrl_nmTrqDmdRawUW > TrqCtrl_nmTrqDmdCrtUW) {
    /* Transition: '<S28>:8' */
    /* Transition: '<S28>:9' */
    tmp = TrqCtrl_nmTrqDmdRawUW - TrqCtrl_nmTrqDmdCrtUW;
    if (tmp < 0) {
      tmp = 0;
    }

    TrqCtrl_nmTrqDmdAftCrtUW = (uint16_T)tmp;

    /* Transition: '<S28>:10' */
  } else {
    /* Transition: '<S28>:11' */
    TrqCtrl_nmTrqDmdAftCrtUW = 0U;
  }

  /* Transition: '<S28>:12' */
}

/* System initialize for atomic system: '<Root>/Func_VehBrakeStUpdt' */
void ZHVCU_Func_VehBrakeStUpdt_Init(void)
{
  VehAnly_stVehBrakeStUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_VehBrakeStUpdt' */
void ZHVCU_Func_VehBrakeStUpdt(void)
{
  /* Inport: '<Root>/In48' incorporates:
   *  Inport: '<Root>/In182'
   */
  /* Gateway: Func_VehBrakeStUpdt */
  /* During: Func_VehBrakeStUpdt */
  /* Entry Internal: Func_VehBrakeStUpdt */
  /* Transition: '<S29>:19' */
  if ((SWSen_stBrakeSWUB == 1) || (SWSen_stParkBrakeSWUB == 1)) {
    /* Transition: '<S29>:20' */
    /* Transition: '<S29>:28' */
    VehAnly_stVehBrakeStUB = 1U;

    /* Transition: '<S29>:25' */
  } else {
    /* Transition: '<S29>:22' */
    VehAnly_stVehBrakeStUB = 0U;
  }

  /* End of Inport: '<Root>/In48' */
  /* Transition: '<S29>:24' */
}

/* System initialize for atomic system: '<Root>/Func_ViceSSTsk' */
void ZHVCU_Func_ViceSSTsk_Init(void)
{
  PwrDrv_stViceStartUB = 0U;
  PwrDrv_stViceStopUB = 0U;
  CANTxAllow_stECUEBC1UB = 0U;
  ViceSSCtl_stViceStopCANUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_ViceSSTsk' */
void ZHVCU_Func_ViceSSTsk(void)
{
  /* Inport: '<Root>/In6' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Inport: '<Root>/In181'
   */
  /* Gateway: Func_ViceSSTsk */
  /* During: Func_ViceSSTsk */
  /* Entry Internal: Func_ViceSSTsk */
  /* Transition: '<S30>:1' */
  if ((SubSysTskExe_stViceSSUB == SubSysTsk_ViceSS_Start) &&
      (ECUEEC1_rpmEngSpdUW < EngAnly_rpmEngStartedSpdLThrUWC) &&
      (SWSen_stNeutralSWUB == 1)) {
    /* Transition: '<S30>:4' */
    /* Transition: '<S30>:18' */
    PwrDrv_stViceStartUB = 1U;
    PwrDrv_stViceStopUB = 0U;
    ViceSSCtl_stViceStopCANUB = 0U;
    CANTxAllow_stECUEBC1UB = 0U;

    /* Transition: '<S30>:13' */
    /* Transition: '<S30>:14' */
  } else if ((SubSysTskExe_stViceSSUB == SubSysTsk_ViceSS_Stop) &&
             (ViceSS_stStopConditionUB == 1)) {
    /* Transition: '<S30>:6' */
    /* Transition: '<S30>:11' */
    PwrDrv_stViceStartUB = 0U;
    PwrDrv_stViceStopUB = 0U;
    ViceSSCtl_stViceStopCANUB = 1U;
    CANTxAllow_stECUEBC1UB = 1U;

    /* Transition: '<S30>:14' */
  } else {
    /* Transition: '<S30>:8' */
    PwrDrv_stViceStartUB = 0U;
    PwrDrv_stViceStopUB = 0U;
    ViceSSCtl_stViceStopCANUB = 0U;
    CANTxAllow_stECUEBC1UB = 0U;
  }

  /* End of Inport: '<Root>/In6' */
  /* Transition: '<S30>:16' */
}

/* System initialize for atomic system: '<Root>/Func_ViceStopCdtUpdt' */
void ZHVCU_Func_ViceStopCdtUpdt_Init(void)
{
  ViceSS_stStopConditionUB = 0U;
}

/* Output and update for atomic system: '<Root>/Func_ViceStopCdtUpdt' */
void ZHVCU_Func_ViceStopCdtUpdt(void)
{
  /* Inport: '<Root>/In6' incorporates:
   *  Constant: '<Root>/Constant32'
   *  Constant: '<Root>/Constant33'
   *  Inport: '<Root>/In160'
   *  Inport: '<Root>/In181'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In26'
   *  Inport: '<Root>/In44'
   *  Inport: '<Root>/In9'
   */
  /* Gateway: Func_ViceStopCdtUpdt */
  /* During: Func_ViceStopCdtUpdt */
  /* Entry Internal: Func_ViceStopCdtUpdt */
  /* Transition: '<S31>:1' */
  if ((ECUEEC1_rpmEngSpdUW > EngAnly_rpmSSEngStopSpdHThrUWC) &&
      (MeterTCO1_kmphVehSpdUB < 5) && (SWSen_stNeutralSWUB == 1) &&
      (SWSen_stClutchSWUB == 0) && (VehAnly_stVehBrakeStUB == 1) &&
      (SWSen_stSSMdUB == 1) && (ECUET1_tEngCoolantTempUB >
       EngAnly_tMtrStartEngTempLThrUBC) && (ECUEEC2_pctAccelPedalPosUB < 2)) {
    /* Transition: '<S31>:5' */
    /* Transition: '<S31>:6' */
    ViceSS_stStopConditionUB = 1U;

    /* Transition: '<S31>:9' */
  } else {
    /* Transition: '<S31>:8' */
    ViceSS_stStopConditionUB = 0U;
  }

  /* End of Inport: '<Root>/In6' */
  /* Transition: '<S31>:11' */
}

/* Model step function */
void ZHVCU_step(void)
{
  uint16_T u1;

  /* Chart: '<Root>/Func_STActionAllONChart' */
  ZHVCU_Func_STActionAllONChart();

  /* RelationalOperator: '<Root>/Relational Operator5' incorporates:
   *  Constant: '<Root>/MdST_stMainMdUB_Stop'
   */
  ZHVCU_DWork.RelationalOperator5 = (MdST_stMainMdUB == 0);

  /* Outputs for Enabled SubSystem: '<Root>/Func_StopMd' */
  ZHVCU_Func_StopMd();

  /* End of Outputs for SubSystem: '<Root>/Func_StopMd' */

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/MdST_stMainMdUB_Start'
   */
  ZHVCU_DWork.RelationalOperator1 = (MdST_stMainMdUB == 1);

  /* Outputs for Enabled SubSystem: '<Root>/Func_StartMd' */
  ZHVCU_Func_StartMd();

  /* End of Outputs for SubSystem: '<Root>/Func_StartMd' */

  /* Chart: '<Root>/FuncMAl_SSStop' */
  ZHVCU_FuncMAl_SSStop();

  /* Chart: '<Root>/Func_TSStUpdt' */
  ZHVCU_Func_TSStUpdt();

  /* RelationalOperator: '<Root>/Relational Operator2' incorporates:
   *  Constant: '<Root>/MdST_stMainMdUB_Drv'
   */
  ZHVCU_DWork.RelationalOperator2 = (MdST_stMainMdUB == 2);

  /* Outputs for Enabled SubSystem: '<Root>/Func_DrvMd' */
  ZHVCU_Func_DrvMd();

  /* End of Outputs for SubSystem: '<Root>/Func_DrvMd' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' */
  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S32>/Divide2' */
    MdSTExe_stMdCalUB = ZHVCU_StopMd_DW.MdST_stMdCalUB;
    break;

   case 1:
    /* Product: '<S32>/Divide2' */
    MdSTExe_stMdCalUB = ZHVCU_StartMd_DW.MdST_stMdCalUB;
    break;

   default:
    /* Product: '<S32>/Divide2' */
    MdSTExe_stMdCalUB = ZHVCU_DrvMd_DW.MdST_stMdCalUB;
    break;
  }

  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S36>/Divide2' */
    SubSysTskExe_stCANUB = ZHVCU_StopMd_DW.SubSysTsk_stCANUB;
    break;

   case 1:
    /* Product: '<S36>/Divide2' */
    SubSysTskExe_stCANUB = ZHVCU_StartMd_DW.SubSysTsk_stCANUB;
    break;

   default:
    /* Product: '<S36>/Divide2' */
    SubSysTskExe_stCANUB = ZHVCU_DrvMd_DW.SubSysTsk_stCANUB;
    break;
  }

  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S37>/Divide2' */
    SubSysTskExe_stMeterUB = ZHVCU_StopMd_DW.SubSysTsk_stMeterUB;
    break;

   case 1:
    /* Product: '<S37>/Divide2' */
    SubSysTskExe_stMeterUB = ZHVCU_StartMd_DW.SubSysTsk_stMeterUB;
    break;

   default:
    /* Product: '<S37>/Divide2' */
    SubSysTskExe_stMeterUB = ZHVCU_DrvMd_DW.SubSysTsk_stMeterUB;
    break;
  }

  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S33>/Divide2' */
    SubSysTskExe_stECUUB = ZHVCU_StopMd_DW.SubSysTsk_stECUUB;
    break;

   case 1:
    /* Product: '<S33>/Divide2' */
    SubSysTskExe_stECUUB = ZHVCU_StartMd_DW.SubSysTsk_stECUUB;
    break;

   default:
    /* Product: '<S33>/Divide2' */
    SubSysTskExe_stECUUB = ZHVCU_DrvMd_DW.SubSysTsk_stECUUB;
    break;
  }

  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S34>/Divide2' */
    SubSysTskExe_stStartSWChOUB = ZHVCU_StopMd_DW.SubSysTsk_stStartSWChOUB;
    break;

   case 1:
    /* Product: '<S34>/Divide2' */
    SubSysTskExe_stStartSWChOUB = ZHVCU_StartMd_DW.SubSysTsk_stStartSWChOUB;
    break;

   default:
    /* Product: '<S34>/Divide2' */
    SubSysTskExe_stStartSWChOUB = ZHVCU_DrvMd_DW.SubSysTsk_stStartSWChOUB;
    break;
  }

  switch (MdST_stMainMdUB) {
   case 0:
    /* Product: '<S35>/Divide2' */
    SubSysTskExe_stViceSSUB = ZHVCU_StopMd_DW.SubSysTsk_stViceSSUB;
    break;

   case 1:
    /* Product: '<S35>/Divide2' */
    SubSysTskExe_stViceSSUB = ZHVCU_StartMd_DW.SubSysTsk_stViceSSUB;
    break;

   default:
    /* Product: '<S35>/Divide2' */
    SubSysTskExe_stViceSSUB = ZHVCU_DrvMd_DW.SubSysTsk_stViceSSUB;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Chart: '<Root>/Func_EngRefTrqUpdt' */
  ZHVCU_Func_EngRefTrqUpdt();

  /* Lookup_n-D: '<Root>/Map_EngAnly_EngOutCurveUpdt' incorporates:
   *  Inport: '<Root>/In6'
   */
  EngAnly_nmEngRTOutCurveTrqUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (ECUEEC1_rpmEngSpdUW, (&(MapEngRTOutCurve_rpmEngSpdUWA[0])),
     (&(MapEngRTOutCurve_nmEngTrqUWA[0])), &ZHVCU_DWork.m_bpIndex, 5U);

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_EngActualTrqUpdt' */
  Z_Func_EngAnly_EngActualTrqUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_EngActualTrqUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_DrvTrqDmdUpdt' */
  ZHVC_Func_EngAnly_DrvTrqDmdUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_DrvTrqDmdUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_DrvTrqDmdUpdt1' */
  ZHV_Func_EngAnly_DrvTrqDmdUpdt1();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_DrvTrqDmdUpdt1' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_EngLoadTrqAtCurSpdUpdt' */
  Func_EngAnly_EngLoadTrqAtCurSpd();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_EngLoadTrqAtCurSpdUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_MaxAvaEngTrqUpdt' */
  Z_Func_EngAnly_MaxAvaEngTrqUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_MaxAvaEngTrqUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngAnly_NomFriTrqUpdt' */
  ZHVC_Func_EngAnly_NomFriTrqUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngAnly_NomFriTrqUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/CommFunc_PctCal' */
  ZHVCU_CommFunc_PctCal();

  /* End of Outputs for SubSystem: '<Root>/CommFunc_PctCal' */

  /* Lookup_n-D: '<Root>/Map_EngAnly_EngSpd2TrqDmdCrtUpdt' incorporates:
   *  Inport: '<Root>/In6'
   */
  TrqCtrl_nmTrqDmdCrtRawUW = look1_iu16lu32n32yu16D_HfJiOU2v(ECUEEC1_rpmEngSpdUW,
    (&(MapEngSpd2TrqDmdCrt_rpmEngSpdUWA[0])),
    (&(MapEngSpd2TrqDmdCrt_nmTrqDmdCrtUWA[0])), &ZHVCU_DWork.m_bpIndex_j, 34U);

  /* Lookup_n-D: '<Root>/Map_EngAnly_AccPos2TrqDmdCrtPctUpdt' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Inport: '<Root>/In9'
   */
  TrqCtrl_pctTrqDmdCrtRatioUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (ECUEEC2_pctAccelPedalPosUB, (&(MapAccPos2TrqDmdCrtRatio_pctAccPosUWA[0])),
     (&(MapAccPos2TrqDmdCrtRatio_pctTrqCrtRatioUWA[0])),
     &ZHVCU_DWork.m_bpIndex_n, 20U);

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngTrqDmdCrtRatioCal' */
  ZHVCU_Func_EngTrqDmdCrtRatioCal();

  /* End of Outputs for SubSystem: '<Root>/Func_EngTrqDmdCrtRatioCal' */

  /* Chart: '<Root>/Func_TrqMng_TrqDmdCrt' */
  ZHVCU_Func_TrqMng_TrqDmdCrt();

  /* Chart: '<Root>/Func_TrqMng_EngTrqDmdDiff' */
  ZHVCU_Func_TrqMng_EngTrqDmdDiff();

  /* Lookup_n-D: '<Root>/Map_EngCtrl_EngTrqDmdDiff2TrqIncStep' */
  TrqCtrl_nmEngTrqIncStepUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (TrqCtrl_nmTrqDmdIncDiffUW,
     (&(MapEngTrqDmdIncDiff2TrqIncStep_nmTrqDmdIncDiffUWA[0])),
     (&(MapEngTrqDmdIncDiff2TrqIncStep_nmTrqIncStepUWA[0])),
     &ZHVCU_DWork.m_bpIndex_jg, 31U);

  /* Lookup_n-D: '<Root>/Map_EngCtrl_EngTrqDmdDiff2TrqCtrlMinDiff' */
  TrqCtrl_nmEngTrqCtrlMinDiffUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (TrqCtrl_nmTrqDmdIncDiffUW,
     (&(MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmIncTrqDiffUWA[0])),
     (&(MapEngTrqIncDiff2EngTrqCtrlMinDiff_nmTrqCtrlMidDiffUWA[0])),
     &ZHVCU_DWork.m_bpIndex_na, 25U);

  /* Lookup_n-D: '<Root>/Map_EngCtrl_AccPedalPos2TrqIncTimer' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Inport: '<Root>/In9'
   */
  TrqCtrl_numEngTrqIncStepmsTimeUW = look1_iu16lu32n32yu16D_HfJiOU2v
    (ECUEEC2_pctAccelPedalPosUB,
     (&(MapAccPedalPos2EngTrqIncTimer_pctAccPedalPosUWA[0])),
     (&(MapAccPedalPos2EngTrqIncTimer_numTrqIncTimerUWA[0])),
     &ZHVCU_DWork.m_bpIndex_jk, 20U);

  /* Chart: '<Root>/Func_TrqCtrlEngTrqCtrlStep' */
  ZHVC_Func_TrqCtrlEngTrqCtrlStep();

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngTrqNm2Pct1' */
  ZHVCU_Func_EngTrqNm2Pct1();

  /* End of Outputs for SubSystem: '<Root>/Func_EngTrqNm2Pct1' */

  /* Lookup_n-D: '<Root>/Map_TrqCtrl_VehMassRatioEngSpd2TrqCrtRatio' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Inport: '<Root>/In6'
   */
  TrqCtrl_pctVehMassEngTrqCrtRatioUW = look2_iu16lu32n32yu16D_Gb9u1U7n
    (VehAnly_pctVehMassRatioUB, ECUEEC1_rpmEngSpdUW,
     (&(MapVehMassRatioEngSpd2EngTrqCrtRatio_pctVehMassRatioUWA[0])),
     (&(MapVehMassRatioEngSpd2EngTrqCrtRatio_rpmEngSpdUWA[0])),
     (&(MapVehMassRatioEngSpd2EngTrqCrtRatio_pctTrqCrtRatioUWA[0])),
     ZHVCU_DWork.m_bpIndex_a, ZHVCU_ConstP.Map_TrqCtrl_VehMassRatioEngSpd2, 11U);

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngTrqCrtRatio2NmTrqCrt' */
  ZH_Func_EngTrqCrtRatio2NmTrqCrt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngTrqCrtRatio2NmTrqCrt' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/TrqCtrl_stMassCorrEnUBC'
   */
  if (TrqCtrl_stMassCorrEnUBC != 0) {
    u1 = TrqCtrl_nmVehMassEngTrqCrtRatioUW;
  } else {
    u1 = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MinMax: '<Root>/MinMax1' */
  if (TrqCtrl_nmEngRawTrqCtrlUW < u1) {
    u1 = TrqCtrl_nmEngRawTrqCtrlUW;
  }

  if (u1 < EngAnly_nmEngRTOutCurveTrqUW) {
    TrqCtrl_nmEngTrqCtrlUW = u1;
  } else {
    TrqCtrl_nmEngTrqCtrlUW = EngAnly_nmEngRTOutCurveTrqUW;
  }

  /* End of MinMax: '<Root>/MinMax1' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngTrqNm2Pct' */
  ZHVCU_Func_EngTrqNm2Pct();

  /* End of Outputs for SubSystem: '<Root>/Func_EngTrqNm2Pct' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_BrakeEngTrqDmdUpdt' */
  ZHVCU_Func_BrakeEngTrqDmdUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_BrakeEngTrqDmdUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_SlideEngTrqDmdUpdt' */
  ZHVCU_Func_SlideEngTrqDmdUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_SlideEngTrqDmdUpdt' */

  /* Outputs for Atomic SubSystem: '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
  Z_Func_EngSpdSlideBrakeLThrUpdt();

  /* End of Outputs for SubSystem: '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */

  /* Chart: '<Root>/Func_EngTask' */
  ZHVCU_Func_EngTask();

  /* Chart: '<Root>/Func_StartSWChOTask' */
  ZHVCU_Func_StartSWChOTask();

  /* Chart: '<Root>/Func_VehBrakeStUpdt' */
  ZHVCU_Func_VehBrakeStUpdt();

  /* Chart: '<Root>/Func_ViceStopCdtUpdt' */
  ZHVCU_Func_ViceStopCdtUpdt();

  /* Chart: '<Root>/Func_ViceSSTsk' */
  ZHVCU_Func_ViceSSTsk();

  /* Outputs for Atomic SubSystem: '<Root>/Func_GearRatioCal' */
  ZHVCU_Func_GearRatioCal();

  /* End of Outputs for SubSystem: '<Root>/Func_GearRatioCal' */

  /* Chart: '<Root>/Func_GearCal' */
  ZHVCU_Func_GearCal();
}

/* Initialize for atomic system: '<Root>/CommFunc_PctCal' */
void ZHVC_CommFunc_PctCal_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmTrqDmdRawUW = 0U;
}

/* Initialize for atomic system: '<Root>/FuncMAl_SSStop' */
void ZHVCU_FuncMAl_SSStop_initialize(void)
{
  /* custom signals */
  MdAllow_stSSStopUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_BrakeEngTrqDmdUpdt' */
void Func_BrakeEngTrqDmdU_initialize(void)
{
  /* custom signals */
  EngCtrl_pctBrakeTrqDmdUB = 0U;
  (void) memset((void *)&ZHVC_Func_BrakeEngTrqDmdUpdt_DW, 0,
                sizeof(rtDW_Func_BrakeEngTrqDmdUpdt_ZH));
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_DrvTrqDmdUpdt' */
void Func_EngAnly_DrvTrqD_initialize(void)
{
  /* custom signals */
  EngAnly_nmDrvTrqDmdUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_DrvTrqDmdUpdt1' */
void Func_EngAnly_DrvTr_l_initialize(void)
{
  /* custom signals */
  EngAnly_nmEngTrqDmdUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_EngActualTrqUpdt' */
void Func_EngAnly_EngActu_initialize(void)
{
  /* custom signals */
  EngAnly_nmActualTrqUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_EngLoadTrqAtCurSpdUpdt' */
void Func_EngAnly_EngLoad_initialize(void)
{
  /* custom signals */
  EngAnly_nmEngLoadTrqAtCurSpdUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_MaxAvaEngTrqUpdt' */
void Func_EngAnly_MaxAvaE_initialize(void)
{
  /* custom signals */
  EngAnly_nmMaxAvaEngTrqUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngAnly_NomFriTrqUpdt' */
void Func_EngAnly_NomFriT_initialize(void)
{
  /* custom signals */
  EngAnly_nmNomFriTrqUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngRefTrqUpdt' */
void Z_Func_EngRefTrqUpdt_initialize(void)
{
  /* custom signals */
  EngAnly_nmEngRefTrqUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
void Func_EngSpdSlideBrak_initialize(void)
{
  /* custom signals */
  EngAnly_rpmEngSpdBrakeLThrUW = 0U;
  EngAnly_rpmEngSpdSlideLThrUW = 0U;
  (void) memset((void *)&Func_EngSpdSlideBrakeLThrUpd_DW, 0,
                sizeof(rtDW_Func_EngSpdSlideBrakeLThrU));
}

/* Initialize for atomic system: '<Root>/Func_EngTask' */
void ZHVCU_Func_EngTask_initialize(void)
{
  /* custom signals */
  ECUTSC1_rpmSpdDmdLmtUW = 0U;
  CANTxAllow_stECUTSC1UB = 0U;
  ECUTSC1_pctTrqDmdLmtUB = 0U;
  ECUTSC1_stEngOverrideCtrlMdeUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngTrqCrtRatio2NmTrqCrt' */
void Func_EngTrqCrtRatio2_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmVehMassEngTrqCrtRatioUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngTrqDmdCrtRatioCal' */
void Func_EngTrqDmdCrtRat_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmTrqDmdCrtUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngTrqNm2Pct' */
void ZH_Func_EngTrqNm2Pct_initialize(void)
{
  /* custom signals */
  TrqCtrl_pctEngTrqCtrlUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_EngTrqNm2Pct1' */
void Z_Func_EngTrqNm2Pct1_initialize(void)
{
  /* custom signals */
  VehAnly_pctVehMassRatioUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_GearCal' */
void ZHVCU_Func_GearCal_initialize(void)
{
  /* custom signals */
  VehAnly_numGearNowUW = 0U;
  VehAnly_rGearBoxRatioUW = 0U;
  (void) memset((void *)&ZHVCU_Func_GearCal_DW, 0,
                sizeof(rtDW_Func_GearCal_ZHVCU));
}

/* Initialize for atomic system: '<Root>/Func_GearRatioCal' */
void ZH_Func_GearRatioCal_initialize(void)
{
  /* custom signals */
  VehAnly_rGearRatioUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_STActionAllONChart' */
void Func_STActionAllONCh_initialize(void)
{
  /* custom signals */
  MdST_stMainMdUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_SlideEngTrqDmdUpdt' */
void Func_SlideEngTrqDmdU_initialize(void)
{
  /* custom signals */
  EngCtrl_pctSlideTrqDmdUB = 0U;
  (void) memset((void *)&ZHVC_Func_SlideEngTrqDmdUpdt_DW, 0,
                sizeof(rtDW_Func_SlideEngTrqDmdUpdt_ZH));
}

/* Initialize for atomic system: '<Root>/Func_StartSWChOTask' */
void Func_StartSWChOTask_initialize(void)
{
  /* custom signals */
  PwrDrv_stStartSWChORlyUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_TSStUpdt' */
void ZHVCU_Func_TSStUpdt_initialize(void)
{
  /* custom signals */
  VehAnly_stTSConedUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_TrqCtrlEngTrqCtrlStep' */
void Func_TrqCtrlEngTrqCt_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmEngRawTrqCtrlUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_TrqMng_EngTrqDmdDiff' */
void Func_TrqMng_EngTrqDm_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmTrqDmdIncDiffUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_TrqMng_TrqDmdCrt' */
void Func_TrqMng_TrqDmdCr_initialize(void)
{
  /* custom signals */
  TrqCtrl_nmTrqDmdAftCrtUW = 0U;
}

/* Initialize for atomic system: '<Root>/Func_VehBrakeStUpdt' */
void Func_VehBrakeStUpdt_initialize(void)
{
  /* custom signals */
  VehAnly_stVehBrakeStUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_ViceSSTsk' */
void ZHVCU_Func_ViceSSTsk_initialize(void)
{
  /* custom signals */
  PwrDrv_stViceStartUB = 0U;
  PwrDrv_stViceStopUB = 0U;
  CANTxAllow_stECUEBC1UB = 0U;
  ViceSSCtl_stViceStopCANUB = 0U;
}

/* Initialize for atomic system: '<Root>/Func_ViceStopCdtUpdt' */
void Func_ViceStopCdtUpdt_initialize(void)
{
  /* custom signals */
  ViceSS_stStopConditionUB = 0U;
}

/* Model initialize function */
void ZHVCU_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  EngAnly_nmEngRTOutCurveTrqUW = 0U;
  TrqCtrl_nmTrqDmdCrtRawUW = 0U;
  TrqCtrl_pctTrqDmdCrtRatioUW = 0U;
  TrqCtrl_nmEngTrqIncStepUW = 0U;
  TrqCtrl_nmEngTrqCtrlMinDiffUW = 0U;
  TrqCtrl_numEngTrqIncStepmsTimeUW = 0U;
  TrqCtrl_pctVehMassEngTrqCrtRatioUW = 0U;
  TrqCtrl_nmEngTrqCtrlUW = 0U;
  MdSTExe_stMdCalUB = 0U;
  SubSysTskExe_stCANUB = 0U;
  SubSysTskExe_stMeterUB = 0U;
  SubSysTskExe_stECUUB = 0U;
  SubSysTskExe_stStartSWChOUB = 0U;
  SubSysTskExe_stViceSSUB = 0U;

  /* states (dwork) */
  (void) memset((void *)&ZHVCU_DWork, 0,
                sizeof(D_Work_ZHVCU));

  /* custom states */
  DrvMdST_numSSStopAllowTimerUW = 0U;
  TrqCtrl_numEngTrqIncStepmsTimerUW = 0U;
  DrvMdST_numSSStartTimerUW = 0U;
  DrvMdST_stSSMtrStartErrFlagUB = 0U;
  DrvMdST_stSSStartErrFlagUB = 0U;
  DrvMdST_stSSWorkStUB = 0U;
  MdAllow_stSSCycleUB = 0U;
  MdST_stDrvMdUB = 0U;
  MdST_stStartMdUB = 0U;
  MdST_stStopMdUB = 0U;
  SWAnly_stGearChgUB = 0U;

  /* external inputs */
  CANTimeout_stECUUB = 0U;
  CANTimeout_stMeterUB = 0U;
  ECUET1_tEngCoolantTempUB = 0U;
  ECULFC_lEngTripFuelUL = 0U;
  ECUAMB_tEngAirInletTempUB = 0U;
  ECULFC_lEngTotalFuelUL = 0U;
  SWSen_stNeutralSWUB = 0U;
  SWSen_stParkBrakeSWUB = 0U;
  SWSen_stStartSWUB = 0U;
  SWSen_stABSWorkUB = 0U;
  SWSen_stONSWUB = 0U;
  SWSen_stACACUB = 0U;
  ECULFE_lphEngFuelRateUW = 0U;
  ECULFE_lphEngInstFuelRateUW = 0U;
  SWSen_stReverseSWUB = 0U;
  AnaSen_vBatteryVF100UW = 0U;
  AnaSen_barAirTankPrsF100UW = 0U;
  SWSen_stSafetyBeltUB = 0U;
  SWSen_stBrakeSWUB = 0U;
  ECUAMB_tAmbAirTempUB = 0U;
  ECUEEC1_stEngTrqMdUB = 0U;
  ECUEEC1_pctDrvTrqDmdUB = 0U;
  ECUEEC1_pctActualTrqUB = 0U;
  ECUEEC1_rpmEngSpdUW = 0U;
  ECUEEC1_stSourceOFEngCtrlUB = 0U;
  ECUEEC1_pctEngTrqDmdUB = 0U;
  ECUEEC2_pctAccelPedalPosUB = 0U;
  ECUEEC2_pctEngLoadAtCurSpdUB = 0U;
  ECUEEC3_pctNomFriTrqPctUB = 0U;
  ECUEEC3_rpmEngDesriedOperatSpdUW = 0U;
  ECUEEC3_rpmEngDesriedOperatSpdAAdjUW = 0U;
  ECUEEC3_kgphAfterExhaustGasMasFlowUW = 0U;
  ECUEEC1_stEngStarterMdUB = 0U;
  ECUEEC2_pctMaxAvaEngTrqUB = 0U;
  ECULFE_lphEngAvgFuelRateUW = 0U;
  MeterTCO1_kmphVehSpdF100UW = 0U;
  MeterTCO1_kmphVehSpdUB = 0U;
  ECUERC1_stRetarderTrqMdeUB = 0U;
  ECUCCVS_kmphVehSpdUB = 0U;
  ECUCCVS_kmphVehSpdF100UW = 0U;
  ECUCCVS_stBrakeSWUB = 0U;
  ECUCCVS_stClutchSWUB = 0U;
  ECUEFL_kpaEngOilPreUB = 0U;
  ECUTI1_stCatalystTankLevelUB = 0U;
  ECUTI1_tCatalystTankTempUB = 0U;
  ECUEBC2_kmphFrontAxleSpdUW = 0U;
  ECUEBC2_kmphFrontAxleLeftSpdUW = 0U;
  ECUEBC2_kmphFrontAxleRightSpdUW = 0U;
  ECUEBC2_kmphRearAxleLeftSpdUW = 0U;
  ECUEBC2_kmphRearAxleRightSpdUW = 0U;
  ECUHOURS_hEngTotalHoursUL = 0U;
  ECUHOURS_hEngTotalRvlUL = 0U;
  SWSen_stClutchSWUB = 0U;
  ECUEC1_nmEngRefTrqUW = 0U;
  ECUEC1_sEngMaxOverrideTimeLmtUB = 0U;
  EngAnly_stEngStartedStUB = 0U;
  SWSen_stSSMdUB = 0U;

  /* Initialize subsystem data */
  ZHVC_CommFunc_PctCal_initialize();
  ZHVCU_FuncMAl_SSStop_initialize();
  Func_BrakeEngTrqDmdU_initialize();
  Func_EngAnly_DrvTrqD_initialize();
  Func_EngAnly_DrvTr_l_initialize();
  Func_EngAnly_EngActu_initialize();
  Func_EngAnly_EngLoad_initialize();
  Func_EngAnly_MaxAvaE_initialize();
  Func_EngAnly_NomFriT_initialize();
  Z_Func_EngRefTrqUpdt_initialize();
  Func_EngSpdSlideBrak_initialize();
  ZHVCU_Func_EngTask_initialize();
  Func_EngTrqCrtRatio2_initialize();
  Func_EngTrqDmdCrtRat_initialize();
  ZH_Func_EngTrqNm2Pct_initialize();
  Z_Func_EngTrqNm2Pct1_initialize();
  ZHVCU_Func_GearCal_initialize();
  ZH_Func_GearRatioCal_initialize();
  Func_STActionAllONCh_initialize();
  Func_SlideEngTrqDmdU_initialize();
  Func_StartSWChOTask_initialize();
  ZHVCU_Func_TSStUpdt_initialize();
  Func_TrqCtrlEngTrqCt_initialize();
  Func_TrqMng_EngTrqDm_initialize();
  Func_TrqMng_TrqDmdCr_initialize();
  Func_VehBrakeStUpdt_initialize();
  ZHVCU_Func_ViceSSTsk_initialize();
  Func_ViceStopCdtUpdt_initialize();

  /* SystemInitialize for Chart: '<Root>/Func_STActionAllONChart' */
  ZH_Func_STActionAllONChart_Init();

  /* SystemInitialize for Enabled SubSystem: '<Root>/Func_StopMd' */
  ZHVCU_Func_StopMd_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Func_StopMd' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Func_StartMd' */
  ZHVCU_Func_StartMd_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Func_StartMd' */

  /* SystemInitialize for Chart: '<Root>/FuncMAl_SSStop' */
  ZHVCU_FuncMAl_SSStop_Init();

  /* SystemInitialize for Chart: '<Root>/Func_TSStUpdt' */
  ZHVCU_Func_TSStUpdt_Init();

  /* SystemInitialize for Enabled SubSystem: '<Root>/Func_DrvMd' */
  ZHVCU_Func_DrvMd_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Func_DrvMd' */

  /* SystemInitialize for Chart: '<Root>/Func_EngRefTrqUpdt' */
  ZHVCU_Func_EngRefTrqUpdt_Init();

  /* SystemInitialize for Chart: '<Root>/Func_TrqMng_TrqDmdCrt' */
  ZHVC_Func_TrqMng_TrqDmdCrt_Init();

  /* SystemInitialize for Chart: '<Root>/Func_TrqMng_EngTrqDmdDiff' */
  Func_TrqMng_EngTrqDmdDiff_Init();

  /* SystemInitialize for Chart: '<Root>/Func_TrqCtrlEngTrqCtrlStep' */
  Func_TrqCtrlEngTrqCtrlStep_Init();

  /* SystemInitialize for Chart: '<Root>/Func_EngTask' */
  ZHVCU_Func_EngTask_Init();

  /* SystemInitialize for Chart: '<Root>/Func_StartSWChOTask' */
  ZHVCU_Func_StartSWChOTask_Init();

  /* SystemInitialize for Chart: '<Root>/Func_VehBrakeStUpdt' */
  ZHVCU_Func_VehBrakeStUpdt_Init();

  /* SystemInitialize for Chart: '<Root>/Func_ViceStopCdtUpdt' */
  ZHVCU_Func_ViceStopCdtUpdt_Init();

  /* SystemInitialize for Chart: '<Root>/Func_ViceSSTsk' */
  ZHVCU_Func_ViceSSTsk_Init();

  /* SystemInitialize for Chart: '<Root>/Func_GearCal' */
  ZHVCU_Func_GearCal_Init();
}

/* Model terminate function */
void ZHVCU_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
