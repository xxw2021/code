#ifndef __VCU_STRATRGY_H
#define __VCU_STRATRGY_H




/* Block signals and states (auto storage) for system '<Root>/Func_BrakeEngTrqDmdUpdt' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<S3>/Map_EngTrqAnly_VehSpd2BrakeEngTrqPctCtrl' */
  uint32_T m_bpIndex_d;                /* '<S3>/Map_EngTrqAnly_EngSpd2BrakeEngTrqPctCtrl' */
} rtDW_Func_BrakeEngTrqDmdUpdt_ZH;

/* Block signals and states (auto storage) for system '<S4>/DrvMd' */
typedef struct {
  uint8_T MdST_stMdCalUB;              /* '<S4>/DrvMd' */
  uint8_T SubSysTsk_stECUUB;           /* '<S4>/DrvMd' */
  uint8_T SubSysTsk_stStartSWChOUB;    /* '<S4>/DrvMd' */
  uint8_T SubSysTsk_stViceSSUB;        /* '<S4>/DrvMd' */
  uint8_T SubSysTsk_stCANUB;           /* '<S4>/DrvMd' */
  uint8_T SubSysTsk_stMeterUB;         /* '<S4>/DrvMd' */
} rtDW_DrvMd_ZHVCU;

/* Block signals and states (auto storage) for system '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<S12>/Map_EngAnly_VehSpd2BrakeEngSpdLThr' */
  uint32_T m_bpIndex_i;                /* '<S12>/Map_EngAnly_VehSpd2SlideEngSpdLThr' */
} rtDW_Func_EngSpdSlideBrakeLThrU;

/* Block signals and states (auto storage) for system '<Root>/Func_GearCal' */
typedef struct {
  uint16_T VehAnly_numGearD10TimerUW;  /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD11TimerUW;  /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD12TimerUW;  /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD1TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD2TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD3TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD4TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD5TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD6TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD7TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD8TimerUW;   /* '<Root>/Func_GearCal' */
  uint16_T VehAnly_numGearD9TimerUW;   /* '<Root>/Func_GearCal' */
} rtDW_Func_GearCal_ZHVCU;

/* Block signals and states (auto storage) for system '<Root>/Func_SlideEngTrqDmdUpdt' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<S21>/Map_EngAnly_VehSpd2SlideEngTrqPctCtrl' */
  uint32_T m_bpIndex_c;                /* '<S21>/Map_EngAnly_EngSpd2SlideEngTrqPctCtrl' */
} rtDW_Func_SlideEngTrqDmdUpdt_ZH;

/* Block signals and states (auto storage) for system '<S22>/StartMd' */
typedef struct {
  uint8_T MdST_stMdCalUB;              /* '<S22>/StartMd' */
  uint8_T SubSysTsk_stECUUB;           /* '<S22>/StartMd' */
  uint8_T SubSysTsk_stStartSWChOUB;    /* '<S22>/StartMd' */
  uint8_T SubSysTsk_stViceSSUB;        /* '<S22>/StartMd' */
  uint8_T SubSysTsk_stCANUB;           /* '<S22>/StartMd' */
  uint8_T SubSysTsk_stMeterUB;         /* '<S22>/StartMd' */
} rtDW_StartMd_ZHVCU;

/* Block signals and states (auto storage) for system '<S24>/StopMd' */
typedef struct {
  uint8_T MdST_stMdCalUB;              /* '<S24>/StopMd' */
  uint8_T SubSysTsk_stECUUB;           /* '<S24>/StopMd' */
  uint8_T SubSysTsk_stStartSWChOUB;    /* '<S24>/StopMd' */
  uint8_T SubSysTsk_stViceSSUB;        /* '<S24>/StopMd' */
  uint8_T SubSysTsk_stCANUB;           /* '<S24>/StopMd' */
  uint8_T SubSysTsk_stMeterUB;         /* '<S24>/StopMd' */
} rtDW_StopMd_ZHVCU;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T m_bpIndex_a[2];             /* '<Root>/Map_TrqCtrl_VehMassRatioEngSpd2TrqCrtRatio' */
  uint32_T m_bpIndex;                  /* '<Root>/Map_EngAnly_EngOutCurveUpdt' */
  uint32_T m_bpIndex_j;                /* '<Root>/Map_EngAnly_EngSpd2TrqDmdCrtUpdt' */
  uint32_T m_bpIndex_n;                /* '<Root>/Map_EngAnly_AccPos2TrqDmdCrtPctUpdt' */
  uint32_T m_bpIndex_jg;               /* '<Root>/Map_EngCtrl_EngTrqDmdDiff2TrqIncStep' */
  uint32_T m_bpIndex_na;               /* '<Root>/Map_EngCtrl_EngTrqDmdDiff2TrqCtrlMinDiff' */
  uint32_T m_bpIndex_jk;               /* '<Root>/Map_EngCtrl_AccPedalPos2TrqIncTimer' */
  boolean_T RelationalOperator5;       /* '<Root>/Relational Operator5' */
  boolean_T RelationalOperator1;       /* '<Root>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<Root>/Relational Operator2' */
} D_Work_ZHVCU;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Map_EngAnly_VehSpd2SlideEngSpdL
   * Referenced by: '<S12>/Map_EngAnly_VehSpd2SlideEngSpdLThr'
   */
  uint32_T Map_EngAnly_VehSpd2SlideEngSpdL[19];

  /* Computed Parameter: Map_TrqCtrl_VehMassRatioEngSpd2
   * Referenced by: '<Root>/Map_TrqCtrl_VehMassRatioEngSpd2TrqCrtRatio'
   */
  uint32_T Map_TrqCtrl_VehMassRatioEngSpd2[2];
} ConstParam_ZHVCU;

/* Extern declarations of internal data for system '<Root>/Func_BrakeEngTrqDmdUpdt' */
extern rtDW_Func_BrakeEngTrqDmdUpdt_ZH ZHVC_Func_BrakeEngTrqDmdUpdt_DW;

/* Extern declarations of internal data for system '<S4>/DrvMd' */
extern rtDW_DrvMd_ZHVCU ZHVCU_DrvMd_DW;

/* Extern declarations of internal data for system '<Root>/Func_EngSpdSlideBrakeLThrUpdt' */
extern rtDW_Func_EngSpdSlideBrakeLThrU Func_EngSpdSlideBrakeLThrUpd_DW;

/* Extern declarations of internal data for system '<Root>/Func_GearCal' */
extern rtDW_Func_GearCal_ZHVCU ZHVCU_Func_GearCal_DW;

/* Extern declarations of internal data for system '<Root>/Func_SlideEngTrqDmdUpdt' */
extern rtDW_Func_SlideEngTrqDmdUpdt_ZH ZHVC_Func_SlideEngTrqDmdUpdt_DW;

/* Extern declarations of internal data for system '<S22>/StartMd' */
extern rtDW_StartMd_ZHVCU ZHVCU_StartMd_DW;

/* Extern declarations of internal data for system '<S24>/StopMd' */
extern rtDW_StopMd_ZHVCU ZHVCU_StopMd_DW;

/* Block signals and states (auto storage) */
extern D_Work_ZHVCU ZHVCU_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_ZHVCU ZHVCU_ConstP;

/* Model entry point functions */
extern void ZHVCU_initialize(void);
extern void ZHVCU_step(void);
extern void ZHVCU_terminate(void);





extern uint8_T look1_iu8lu32n32yu8Ds1_Y0hbqrP2(uint8_T u0, const uint8_T bp0[],
  const uint8_T table[], uint32_T prevIndex[], uint32_T maxIndex);
extern uint16_T look1_iu16lu32n32yu16D_HfJiOU2v(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T prevIndex[], uint32_T maxIndex);
extern uint16_T look1_iu16lu32n32yu16t_0NvOblQd(uint16_T u0, const uint16_T bp0[],
  const uint32_T table[], uint32_T prevIndex[], uint32_T maxIndex);
extern uint16_T look2_iu16lu32n32yu16D_Gb9u1U7n(uint16_T u0, uint16_T u1, const
  uint16_T bp0[], const uint16_T bp1[], const uint16_T table[], uint32_T
  prevIndex[], const uint32_T maxIndex[], uint32_T stride);
extern void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift);
extern int32_T mul_ssu32_sr32(int32_T a, uint32_T b);
extern void ZHVCU_CommFunc_PctCal(void);
extern void ZHVCU_FuncMAl_SSStop_Init(void);
extern void ZHVCU_FuncMAl_SSStop(void);
extern void ZHVCU_Func_BrakeEngTrqDmdUpdt(void);
extern void ZHVCU_DrvMd_Init(void);
extern void ZHVCU_DrvMd(void);
extern void ZHVCU_Func_DrvMd_Init(void);
extern void ZHVCU_Func_DrvMd(void);
extern void ZHVC_Func_EngAnly_DrvTrqDmdUpdt(void);
extern void ZHV_Func_EngAnly_DrvTrqDmdUpdt1(void);
extern void Z_Func_EngAnly_EngActualTrqUpdt(void);
extern void Func_EngAnly_EngLoadTrqAtCurSpd(void);
extern void Z_Func_EngAnly_MaxAvaEngTrqUpdt(void);
extern void ZHVC_Func_EngAnly_NomFriTrqUpdt(void);
extern void ZHVCU_Func_EngRefTrqUpdt_Init(void);
extern void ZHVCU_Func_EngRefTrqUpdt(void);
extern void Z_Func_EngSpdSlideBrakeLThrUpdt(void);
extern void ZHVCU_Func_EngTask_Init(void);
extern void ZHVCU_Func_EngTask(void);
extern void ZH_Func_EngTrqCrtRatio2NmTrqCrt(void);
extern void ZHVCU_Func_EngTrqDmdCrtRatioCal(void);
extern void ZHVCU_Func_EngTrqNm2Pct(void);
extern void ZHVCU_Func_EngTrqNm2Pct1(void);
extern void ZHVCU_Func_GearCal_Init(void);
extern void ZHVCU_Func_GearCal(void);
extern void ZHVCU_Func_GearRatioCal(void);
extern void ZH_Func_STActionAllONChart_Init(void);
extern void ZHVCU_Func_STActionAllONChart(void);
extern void ZHVCU_Func_SlideEngTrqDmdUpdt(void);
extern void ZHVCU_StartMd_Init(void);
extern void ZHVCU_StartMd(void);
extern void ZHVCU_Func_StartMd_Init(void);
extern void ZHVCU_Func_StartMd(void);
extern void ZHVCU_Func_StartSWChOTask_Init(void);
extern void ZHVCU_Func_StartSWChOTask(void);
extern void ZHVCU_StopMd_Init(void);
extern void ZHVCU_StopMd(void);
extern void ZHVCU_Func_StopMd_Init(void);
extern void ZHVCU_Func_StopMd(void);
extern void ZHVCU_Func_TSStUpdt_Init(void);
extern void ZHVCU_Func_TSStUpdt(void);
extern void Func_TrqCtrlEngTrqCtrlStep_Init(void);
extern void ZHVC_Func_TrqCtrlEngTrqCtrlStep(void);
extern void Func_TrqMng_EngTrqDmdDiff_Init(void);
extern void ZHVCU_Func_TrqMng_EngTrqDmdDiff(void);
extern void ZHVC_Func_TrqMng_TrqDmdCrt_Init(void);
extern void ZHVCU_Func_TrqMng_TrqDmdCrt(void);
extern void ZHVCU_Func_VehBrakeStUpdt_Init(void);
extern void ZHVCU_Func_VehBrakeStUpdt(void);
extern void ZHVCU_Func_ViceSSTsk_Init(void);
extern void ZHVCU_Func_ViceSSTsk(void);
extern void ZHVCU_Func_ViceStopCdtUpdt_Init(void);
extern void ZHVCU_Func_ViceStopCdtUpdt(void);
extern void ZHVC_CommFunc_PctCal_initialize(void);
extern void ZHVCU_FuncMAl_SSStop_initialize(void);
extern void Func_BrakeEngTrqDmdU_initialize(void);
extern void Func_EngAnly_DrvTrqD_initialize(void);
extern void Func_EngAnly_DrvTr_l_initialize(void);
extern void Func_EngAnly_EngActu_initialize(void);
extern void Func_EngAnly_EngLoad_initialize(void);
extern void Func_EngAnly_MaxAvaE_initialize(void);
extern void Func_EngAnly_NomFriT_initialize(void);
extern void Z_Func_EngRefTrqUpdt_initialize(void);
extern void Func_EngSpdSlideBrak_initialize(void);
extern void ZHVCU_Func_EngTask_initialize(void);
extern void Func_EngTrqCrtRatio2_initialize(void);
extern void Func_EngTrqDmdCrtRat_initialize(void);
extern void ZH_Func_EngTrqNm2Pct_initialize(void);
extern void Z_Func_EngTrqNm2Pct1_initialize(void);
extern void ZHVCU_Func_GearCal_initialize(void);
extern void ZH_Func_GearRatioCal_initialize(void);
extern void Func_STActionAllONCh_initialize(void);
extern void Func_SlideEngTrqDmdU_initialize(void);
extern void Func_StartSWChOTask_initialize(void);
extern void ZHVCU_Func_TSStUpdt_initialize(void);
extern void Func_TrqCtrlEngTrqCt_initialize(void);
extern void Func_TrqMng_EngTrqDm_initialize(void);
extern void Func_TrqMng_TrqDmdCr_initialize(void);
extern void Func_VehBrakeStUpdt_initialize(void);
extern void ZHVCU_Func_ViceSSTsk_initialize(void);
extern void Func_ViceStopCdtUpdt_initialize(void);




#endif