/*
 * File: CrCtl_data.c
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

/* Invariant block signals (default storage) */
const ConstB_CrCtl_T CrCtl_ConstB = {
  { { 0xC305F240UL, 0x4UL } },         /* '<S327>/Product4' */
  3769920U,                            /* '<S327>/Product3' */
  -1,                                  /* '<S219>/DataTypeConv3' */
  0,                                   /* '<S167>/Switch' */
  0,                                   /* '<S144>/Switch' */
  0,                                   /* '<S36>/Add8' */
  120U,                                /* '<S327>/Product2' */
  0,                                   /* '<S167>/UpperRelop' */
  0,                                   /* '<S144>/UpperRelop' */
  0,                                   /* '<S36>/Relational Operator2' */
  1,                                   /* '<S54>/Relational Operator1' */
  0,                                   /* '<S54>/Logical Operator2' */
  0,                                   /* '<S12>/Relational Operator3' */
  1,                                   /* '<S19>/Relational Operator1' */
  0                                    /* '<S19>/Logical Operator2' */
};

/* Constant parameters (default storage) */
const ConstP_CrCtl_T CrCtl_ConstP = {
  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S176>/Switch'
   */
  { { 0UL, 0UL } },

  /* Computed Parameter: weiChaiExCharCv_JH6500HP_tableData
   * Referenced by: '<S327>/weiChaiExCharCv_JH6500HP'
   */
  { 960, 2121, 2121, 2121, 1642, 0, 0 },

  /* Pooled Parameter (Expression: [0:100:20000])
   * Referenced by:
   *   '<S185>/CrCtl_trqVCorResAbv_CUR'
   *   '<S196>/CrCtl_trqVCorResBlw_CUR'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U, 800U, 900U, 1000U, 1100U,
    1200U, 1300U, 1400U, 1500U, 1600U, 1700U, 1800U, 1900U, 2000U, 2100U, 2200U,
    2300U, 2400U, 2500U, 2600U, 2700U, 2800U, 2900U, 3000U, 3100U, 3200U, 3300U,
    3400U, 3500U, 3600U, 3700U, 3800U, 3900U, 4000U, 4100U, 4200U, 4300U, 4400U,
    4500U, 4600U, 4700U, 4800U, 4900U, 5000U, 5100U, 5200U, 5300U, 5400U, 5500U,
    5600U, 5700U, 5800U, 5900U, 6000U, 6100U, 6200U, 6300U, 6400U, 6500U, 6600U,
    6700U, 6800U, 6900U, 7000U, 7100U, 7200U, 7300U, 7400U, 7500U, 7600U, 7700U,
    7800U, 7900U, 8000U, 8100U, 8200U, 8300U, 8400U, 8500U, 8600U, 8700U, 8800U,
    8900U, 9000U, 9100U, 9200U, 9300U, 9400U, 9500U, 9600U, 9700U, 9800U, 9900U,
    10000U, 10100U, 10200U, 10300U, 10400U, 10500U, 10600U, 10700U, 10800U,
    10900U, 11000U, 11100U, 11200U, 11300U, 11400U, 11500U, 11600U, 11700U,
    11800U, 11900U, 12000U, 12100U, 12200U, 12300U, 12400U, 12500U, 12600U,
    12700U, 12800U, 12900U, 13000U, 13100U, 13200U, 13300U, 13400U, 13500U,
    13600U, 13700U, 13800U, 13900U, 14000U, 14100U, 14200U, 14300U, 14400U,
    14500U, 14600U, 14700U, 14800U, 14900U, 15000U, 15100U, 15200U, 15300U,
    15400U, 15500U, 15600U, 15700U, 15800U, 15900U, 16000U, 16100U, 16200U,
    16300U, 16400U, 16500U, 16600U, 16700U, 16800U, 16900U, 17000U, 17100U,
    17200U, 17300U, 17400U, 17500U, 17600U, 17700U, 17800U, 17900U, 18000U,
    18100U, 18200U, 18300U, 18400U, 18500U, 18600U, 18700U, 18800U, 18900U,
    19000U, 19100U, 19200U, 19300U, 19400U, 19500U, 19600U, 19700U, 19800U,
    19900U, 20000U },

  /* Computed Parameter: gear2ig_weiChaiJH6500HP_tableData
   * Referenced by: '<S327>/gear2ig_weiChaiJH6500HP'
   */
  { 1226U, 956U, 736U, 580U, 452U, 353U, 271U, 212U, 163U, 128U, 100U, 78U },

  /* Computed Parameter: weiChaiExCharCv_JH6500HP_bp01Data
   * Referenced by: '<S327>/weiChaiExCharCv_JH6500HP'
   */
  { 600U, 1000U, 1200U, 1400U, 1900U, 2150U, 2600U },

  /* Computed Parameter: gear2ig_weiChaiJH6500HP_bp01Data
   * Referenced by: '<S327>/gear2ig_weiChaiJH6500HP'
   */
  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
