/*
 * File: CrCtl.h
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

#ifndef RTW_HEADER_CrCtl_h_
#define RTW_HEADER_CrCtl_h_
#include <string.h>
#ifndef CrCtl_COMMON_INCLUDES_
# define CrCtl_COMMON_INCLUDES_
#include <string.h>
#include "TypeDefine.h"
//#include "rtwtypes.h"
//#include "rtw_continuous.h"
//#include "rtw_solver.h"
#endif                                 /* CrCtl_COMMON_INCLUDES_ */

#include "CrCtl_types.h"

/* Shared type includes */
//#include "multiword_types.h"

/* Includes for objects with custom storage classes. */
#include "SPN683.h"
#include "SPN525.h"
#include "SPN256.h"
#include "SPN574.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define BRKCD_ST_1                     0U
#define COENG_STNORMAL                 4U
#define CRCTL_ACC                      8U
#define CRCTL_CUT                      1U
#define CRCTL_DECL                     4U
#define CRCTL_ENA                      1
#define CRCTL_NOSHOFFCONACTV           0U
#define CRCTL_NOTENA                   0
#define CRCTL_NOTLCK                   0U
#define CRCTL_OFF                      2U
#define CRCTL_RMPONE                   2U
#define CRCTL_SUBCALCSET               6U
#define CRCTL_SUBRMPEND                4U
#define CRCTL_SUBSETEND                7U
#define CRCTL_SUBWAITRES               9U
#define CRCTL_TIPDWN                   3U
#define CRCTL_TIPUP                    7U
#define MFLV_ACC                       6U
#define MFLV_DECL                      4U
#define MFLV_MODEERR                   255U
#define MFLV_NEUTR                     0U
#define MFLV_OFF                       0U
#define MFLV_RES                       7U
#define MFLV_SET                       2U
#define MFLV_SWTOFF                    1U
#define MFLV_TIPDWN                    3U
#define MFLV_TIPUP                     5U
#define T15CD_ST_OFF                   0U

/* Definition for custom storage class: Define */
#define CRCTL_ACTV                     1U
#define CRCTL_HOLD                     9U
#define CRCTL_LCK                      2U
#define CRCTL_LCKACTV                  1U
#define CRCTL_NEUTR                    1U
#define CRCTL_NOTACTV                  0U
#define CRCTL_OVERRIDE                 2U
#define CRCTL_PCCACT                   1
#define CRCTL_RESABV                   5U
#define CRCTL_RESBLW                   6U
#define CRCTL_RMPTWO                   3U
#define CRCTL_SUBGVNR                  8U
#define CRCTL_SUBNOSUB                 1U
#define CRCTL_SUBPREPHOLD              5U
#define CRCTL_SUBRMP                   3U
#define CRCTL_SUBSTRTVAL               2U
#define CRCTL_SUSPENDENDRAMP           3U                        /* Suspend mode is not active and ramp is running to the previous saved value */
#define CRCTL_SUSPENDNOTACTIVE         0U                        /* Suspend mode not active */
#define CRCTL_SUSPENDRAMPDONE          2U                        /* Suspend mode is active and ramp has reached the end value */
#define CRCTL_SUSPENDSTARTRAMP         1U                        /* Suspend mode is active and the ramp is running to the end value */
#define DSPCC                          0U
#define ENPCCBETMODE                   1U
#define ENPCCOPTMODE                   2U
#define FALSE                          0
#define MFLV_SETOPT                    8U
#define NEUTRGEAR                      0U                        /* Transmission gear is nuetral */
#define PCCBETMODE                     0
#define PCCOPTMODE                     1
#define TRUE                           1
#define T_ms                           10U

/* Block signals (default storage) */
typedef struct {
  uint64m_T vchSpd_10mph;              /* '<S327>/Product1' */
  uint64m_T r0;
  uint64m_T r1;
  uint64m_T r2;
  uint64m_T r3;
  uint64m_T r4;
  uint64m_T r5;
  uint64m_T r6;
  uint64m_T r7;
  uint64m_T r8;
  uint64m_T r9;
  uint64m_T r10;
  uint64m_T r11;
  uint64m_T r12;
  int32_T Eng_nAvrg_10mrpm;            /* '<S7>/Data Type Conversion9' */
  int32_T CrCtl_trqDesIn_10mNm;        /* '<S7>/Gain5' */
  int32_T Gain;                        /* '<S327>/Gain' */
  int32_T CrCtl_trqDes;                /* '<S4>/Merge' */
  int32_T Switch_o;                    /* '<S212>/Switch' */
  int32_T CrCtl_trqLead_10mNm;         /* '<S4>/Merge1' */
  int32_T Memory;                      /* '<S125>/Memory' */
  int32_T OutportBufferForCrCtl_trqPCCStrtVal;/* '<S182>/PrpBrk_trqDes_10mNm' */
  int32_T CrCtl_trqDes_In;             /* '<S210>/CrCtl_trqDes_In' */
  int32_T OutportBufferForCrCtl_trqLead;/* '<S210>/CrCtl_trqDes_In' */
  int32_T ActlEngPctTrq_Nm;            /* '<S7>/Divide' */
  uint16_T CrCtl_vSetPointTrgtFdbck_10mph;/* '<Root>/00' */
  uint16_T PCC_vSetPointTrgt_10mphUW;  /* '<Root>/Product1' */
  uint16_T Memory1;                    /* '<S4>/Memory1' */
  uint16_T Memory_c;                   /* '<S4>/Memory' */
  uint16_T Memory1_a;                  /* '<S125>/Memory1' */
  uint16_T Merge9;                     /* '<S125>/Merge9' */
  uint16_T PCC_vSetPointTrgt_kmphUW_In;/* '<S180>/PCC_vSetPointTrgt_kmphUW_In' */
  uint16_T OutportBufferForCrCtl_vSetPointAct_mp;/* '<S163>/CrCtl_vSetPointTrgt_In' */
  uint16_T OutportBufferForCrCtl_vSetPointAct_mp_e;/* '<S138>/Index Vector1' */
  uint16_T CrCtl_vSetPointAct_mp;      /* '<S127>/Merge6' */
  uint16_T Merge9_m;                   /* '<S126>/Merge9' */
  uint16_T OutportBufferForCrCtl_vSetPointAct_mp_en;/* '<S150>/Saturation Dynamic' */
  uint16_T IndexVector;                /* '<S210>/Index Vector' */
  int16_T rVn_mmphprpm;                /* '<S327>/Divide3' */
  int16_T Diff;                        /* '<S328>/Diff' */
  int16_T AccPed_trqDes_NmSW;          /* '<S7>/Divide3' */
  int16_T P;                           /* '<S213>/Merge' */
  int16_T I;                           /* '<S213>/Merge' */
  int16_T CrCtl_rVnBeg;                /* '<S4>/Merge6' */
  int16_T CrCtl_rVnBeg_In;             /* '<S210>/CrCtl_rVnBeg_In' */
  int16_T IndexVector4;                /* '<S37>/Index Vector4' */
  int16_T CrCtl_rVnSusp_mp;            /* '<S37>/Index Vector1' */
  int16_T Merge2;                      /* '<S13>/Merge2' */
  uint8_T CrCtl_stModeFdbck;           /* '<Root>/Memory' */
  uint8_T CrCtl_stModeSubFdbck;        /* '<Root>/Memory1' */
  uint8_T CrCtl_stOpFuncFdbck_UB;      /* '<Root>/ CRCTL_NOTACTV_0h' */
  uint8_T CrCtl_stLck_fdbck;           /* '<Root>/CRCTL_NOTLCK_0h' */
  uint8_T CrCtl_stShOffFdbck;          /* '<Root>/CRCTL_NOSHOFFCONACTV_0h' */
  uint8_T Gearbx_stGear;               /* '<S327>/ig2stGear_weiChaiJH6500HP' */
  uint8_T CrCtl_stOpFunc;              /* '<S4>/Merge3' */
  uint8_T CrCtl_stMode;                /* '<S4>/Merge4' */
  uint8_T CrCtl_stModeSub;             /* '<S4>/Merge5' */
  uint8_T CrCtl_stLck;                 /* '<S4>/Merge8' */
  uint8_T CrCtl_stSuspRamp_mp;         /* '<S229>/manualShiftSuspChart' */
  uint8_T isUsePI;                     /* '<S135>/PISlct' */
  uint8_T IndexVector1;                /* '<S210>/Index Vector1' */
  uint8_T CrCtl_stLck_In;              /* '<S210>/CrCtl_stLck_In' */
  uint8_T IndexVector11;               /* '<S3>/Index Vector11' */
  uint8_T IndexVector_i;               /* '<S117>/Index Vector' */
  uint8_T MFLv_stCrCtlMode_f;          /* '<S2>/MFLv_stCrCtlMode' */
  uint8_T Merge;                       /* '<S13>/Merge' */
  uint8_T Merge1;                      /* '<S13>/Merge1' */
  uint8_T IndexVector5;                /* '<S12>/Index Vector5' */
  uint8_T IndexVector_d;               /* '<S115>/Index Vector' */
  uint8_T OutportBufferForCrCtl_stOpFunc;/* '<S210>/CRCTL_ACTV(=1h)' */
  uint8_T OutportBufferForCrCtl_stModeSub;/* '<S210>/CRCTL_SUBSTRTVAL(=2h)' */
  uint8_T IndexVector_k;               /* '<S36>/Index Vector' */
  boolean_T CrCtl_stActiveFdbck;       /* '<Root>/FALSE' */
  boolean_T PCC_Mode_BL;               /* '<S5>/MFLvDtctAndPrs' */
  boolean_T LogicalOperator;           /* '<S125>/Logical Operator' */
  boolean_T IndexVector7;              /* '<S3>/Index Vector7' */
  boolean_T IndexVector3;              /* '<S37>/Index Vector3' */
  boolean_T RelationalOperator1;       /* '<S37>/Relational Operator1' */
  boolean_T En;                        /* '<S37>/fallingEdge' */
  boolean_T RelationalOperator2;       /* '<S43>/Relational Operator2' */
  boolean_T LogicalOperator_l;         /* '<S56>/Logical Operator' */
  boolean_T LogicalOperator2;          /* '<S55>/Logical Operator2' */
  boolean_T signal4;                   /* '<S40>/Index Vector6' */
  boolean_T signal5;                   /* '<S40>/Index Vector6' */
  boolean_T signal6;                   /* '<S40>/Index Vector6' */
  boolean_T signal7;                   /* '<S40>/Index Vector6' */
  boolean_T signal8;                   /* '<S40>/Index Vector6' */
  boolean_T signal9;                   /* '<S40>/Index Vector6' */
  boolean_T LogicalOperator_f;         /* '<S14>/Logical Operator' */
  boolean_T LogicalOperator_o;         /* '<S11>/Logical Operator' */
  boolean_T LogicalOperator3_e;        /* '<S19>/Logical Operator3' */
  boolean_T LogicalOperator_k;         /* '<S21>/Logical Operator' */
  boolean_T LogicalOperator3_d;        /* '<S21>/Logical Operator3' */
  boolean_T LogicalOperator2_p;        /* '<S20>/Logical Operator2' */
  boolean_T LogicalOperator3_i;        /* '<S20>/Logical Operator3' */
  boolean_T OutportBufferForCrCtl_stActive;/* '<S210>/CRCTL_STACTIVE(=1h)' */
  boolean_T signal1;                   /* '<S42>/Index Vector6' */
  boolean_T signal2;                   /* '<S42>/Index Vector6' */
  boolean_T signal3;                   /* '<S42>/Index Vector6' */
  boolean_T RelationalOperator3;       /* '<S41>/Relational Operator3' */
  boolean_T RelationalOperator2_m;     /* '<S41>/Relational Operator2' */
  boolean_T signal5_k;                 /* '<S42>/Index Vector6' */
  boolean_T signal4_e;                 /* '<S42>/Index Vector6' */
  boolean_T RelationalOperator8;       /* '<S42>/Relational Operator8' */
} B_CrCtl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_PreviousInput;        /* '<S229>/Memory1' */
  real_T PCC_vSetPointTrgt_kmphUW_m;
  int32_T Integrator_DSTATE;           /* '<S212>/Integrator' */
  int32_T Memory_PreviousInput;        /* '<S125>/Memory' */
  int32_T Memory2_PreviousInput;       /* '<S180>/Memory2' */
  int32_T Memory1_PreviousInput_c;     /* '<S181>/Memory1' */
  int16_T UD_DSTATE;                   /* '<S328>/UD' */
  int16_T CrCtl_trqOldVal_mp;          /* '<S229>/Data Store Memory1' */
  int16_T Memory2_PreviousInput_h;     /* '<S37>/Memory2' */
  int16_T Memory3_PreviousInput;       /* '<S37>/Memory3' */
  uint16_T u0_PreviousInput;           /* '<Root>/00' */
  uint16_T Memory1_PreviousInput_c4;   /* '<S4>/Memory1' */
  uint16_T Memory_PreviousInput_d;     /* '<S4>/Memory' */
  uint16_T Memory1_PreviousInput_b;    /* '<S125>/Memory1' */
  uint16_T Memory_PreviousInput_l;     /* '<S181>/Memory' */
  boolean_T ICic_DSTATE;               /* '<S21>/IC = ic' */
  boolean_T ICic_DSTATE_b;             /* '<S20>/IC = ic' */
  int8_T Memory2_PreviousInput_i;      /* '<Root>/Memory2' */
  int8_T Integrator_PrevResetState;    /* '<S212>/Integrator' */
  uint8_T Memory_PreviousInput_m;      /* '<Root>/Memory' */
  uint8_T Memory1_PreviousInput_m;     /* '<Root>/Memory1' */
  uint8_T CRCTL_NOTACTV_0h_PreviousInput;/* '<Root>/ CRCTL_NOTACTV_0h' */
  uint8_T CRCTL_NOTLCK_0h_PreviousInput;/* '<Root>/CRCTL_NOTLCK_0h' */
  uint8_T CRCTL_NOSHOFFCONACTV_0h_PreviousInput;/* '<Root>/CRCTL_NOSHOFFCONACTV_0h' */
  uint8_T Memory3_PreviousInput_o;     /* '<Root>/Memory3' */
  uint8_T is_active_c23_CrCtl;         /* '<S5>/MFLvDtctAndPrs' */
  uint8_T countD;                      /* '<S5>/MFLvDtctAndPrs' */
  uint8_T countU;                      /* '<S5>/MFLvDtctAndPrs' */
  uint8_T Integrator_IC_LOADING;       /* '<S212>/Integrator' */
  uint8_T Memory_PreviousInput_f;      /* '<S229>/Memory' */
  uint8_T is_active_c16_CrCtl;         /* '<S229>/manualShiftSuspChart' */
  uint8_T is_c16_CrCtl;                /* '<S229>/manualShiftSuspChart' */
  uint8_T is_CRCTL_SUSPENDENDRAMP_3h;  /* '<S229>/manualShiftSuspChart' */
  uint8_T is_CRCTL_SUSPENDSTARTRUMP_1h;/* '<S229>/manualShiftSuspChart' */
  uint8_T Memory2_PreviousInput_c;     /* '<S3>/Memory2' */
  uint8_T Memory_PreviousInput_g;      /* '<S115>/Memory' */
  uint8_T Memory_PreviousInput_e;      /* '<S117>/Memory' */
  uint8_T numPeriod;                   /* '<S84>/Data Store Memory1' */
  uint8_T numPeriod_c;                 /* '<S78>/Data Store Memory1' */
  uint8_T numPeriod_g;                 /* '<S49>/Data Store Memory1' */
  uint8_T numPeriod_a;                 /* '<S50>/Data Store Memory1' */
  uint8_T numPeriod_o;                 /* '<S17>/Data Store Memory1' */
  boolean_T setDownBf_PreviousInput;   /* '<S5>/setDownBf' */
  boolean_T setUpBf_PreviousInput;     /* '<S5>/setUpBf' */
  boolean_T FALSE_PreviousInput;       /* '<Root>/FALSE' */
  boolean_T setDownPress;              /* '<S5>/MFLvDtctAndPrs' */
  boolean_T setUpPress;                /* '<S5>/MFLvDtctAndPrs' */
  boolean_T Memory3_PreviousInput_g;   /* '<S125>/Memory3' */
  boolean_T Memory4_PreviousInput;     /* '<S37>/Memory4' */
  boolean_T Memory1_PreviousInput_k;   /* '<S37>/Memory1' */
  boolean_T Memory_PreviousInput_b;    /* '<S84>/Memory' */
  boolean_T timeLck;                   /* '<S84>/Data Store Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S78>/Memory' */
  boolean_T timeLck_b;                 /* '<S78>/Data Store Memory' */
  boolean_T Memory_PreviousInput_bl;   /* '<S50>/Memory' */
  boolean_T Memory_PreviousInput_l2;   /* '<S49>/Memory' */
  boolean_T timeLck_f;                 /* '<S49>/Data Store Memory' */
  boolean_T timeLck_a;                 /* '<S50>/Data Store Memory' */
  boolean_T ICic_PreviousInput;        /* '<S56>/IC=ic' */
  boolean_T ICic_PreviousInput_k;      /* '<S55>/IC=ic' */
  boolean_T Memory_PreviousInput_go;   /* '<S15>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_m3;   /* '<S17>/Memory' */
  boolean_T timeLck_n;                 /* '<S17>/Data Store Memory' */
  boolean_T SETPriority_MODE;          /* '<S54>/SET  Priority' */
  boolean_T RESETPriority_MODE;        /* '<S54>/RESET Priority' */
  boolean_T SETPriority_MODE_p;        /* '<S19>/SET  Priority' */
  boolean_T RESETPriority_MODE_g;      /* '<S19>/RESET Priority' */
} DW_CrCtl_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint64m_T Product4;            /* '<S327>/Product4' */
  const uint32_T Product3;             /* '<S327>/Product3' */
  const int32_T DataTypeConv3;         /* '<S219>/DataTypeConv3' */
  const int32_T Switch;                /* '<S167>/Switch' */
  const int32_T Switch_i;              /* '<S144>/Switch' */
  const int32_T Add8;                  /* '<S36>/Add8' */
  const uint8_T Product2;              /* '<S327>/Product2' */
  const boolean_T UpperRelop;          /* '<S167>/UpperRelop' */
  const boolean_T UpperRelop_o;        /* '<S144>/UpperRelop' */
  const boolean_T RelationalOperator2; /* '<S36>/Relational Operator2' */
  const boolean_T RelationalOperator1; /* '<S54>/Relational Operator1' */
  const boolean_T LogicalOperator2;    /* '<S54>/Logical Operator2' */
  const boolean_T RelationalOperator3; /* '<S12>/Relational Operator3' */
  const boolean_T RelationalOperator1_h;/* '<S19>/Relational Operator1' */
  const boolean_T LogicalOperator2_e;  /* '<S19>/Logical Operator2' */
} ConstB_CrCtl_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S176>/Switch'
   */
  int64m_T Switch_Threshold;

  /* Computed Parameter: weiChaiExCharCv_JH6500HP_tableData
   * Referenced by: '<S327>/weiChaiExCharCv_JH6500HP'
   */
  int16_T weiChaiExCharCv_JH6500HP_tableData[7];

  /* Pooled Parameter (Expression: [0:100:20000])
   * Referenced by:
   *   '<S185>/CrCtl_trqVCorResAbv_CUR'
   *   '<S196>/CrCtl_trqVCorResBlw_CUR'
   */
  uint16_T pooled6[201];

  /* Computed Parameter: gear2ig_weiChaiJH6500HP_tableData
   * Referenced by: '<S327>/gear2ig_weiChaiJH6500HP'
   */
  uint16_T gear2ig_weiChaiJH6500HP_tableData[12];

  /* Computed Parameter: weiChaiExCharCv_JH6500HP_bp01Data
   * Referenced by: '<S327>/weiChaiExCharCv_JH6500HP'
   */
  uint16_T weiChaiExCharCv_JH6500HP_bp01Data[7];

  /* Computed Parameter: gear2ig_weiChaiJH6500HP_bp01Data
   * Referenced by: '<S327>/gear2ig_weiChaiJH6500HP'
   */
  uint8_T gear2ig_weiChaiJH6500HP_bp01Data[12];
} ConstP_CrCtl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T FrmMng_stETC1ShfActv;        /* '<Root>/FrmMng_stETC1ShfActv' */
  uint8_T PrpCtl_stCrCtlShOff;         /* '<Root>/PrpCtl_stCrCtlShOff' */
  uint8_T VESGov_stCrCtlShutOff;       /* '<Root>/VESGov_stCrCtlShutOff' */
  uint8_T BrkCD_stParkBrk;             /* '<Root>/BrkCD_stParkBrk' */
  uint8_T EBSwCD_stPreSelMode;         /* '<Root>/EBSwCD_stPreSelMode' */
  uint16_T VehDa_stTrqDem;             /* '<Root>/VehDa_stTrqDem' */
  uint16_T CoVeh_stTSEATrqspdReq;      /* '<Root>/CoVeh_stTSEATrqspdReq' */
  uint16_T EISGov_trq;                 /* '<Root>/EISGov_trq' */
  int16_T CoEng_stlnrDesBrk;           /* '<Root>/CoEng_stInrDesBrk' */
} ExtU_CrCtl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int8_T EngRqedTorque_TorqueLimit_SB_l;/* '<Root>/EngRqedTorque_TorqueLimit_SB' */
  uint8_T CrCtl_stOpFunc_UB_f;         /* '<Root>/CrCtl_stOpFunc_UB' */
  uint8_T CrCtl_TSC1EngOvrdCtrlMd_UB_i;/* '<Root>/CrCtl_TSC1EngOvrdCtrlMd_UB' */
  uint8_T CrCtl_TC1DisengDrvlnReq_UB_b;/* '<Root>/CrCtl_TC1DisengDrvlnReq_UB' */
  uint8_T CrCtl_TC1DisengDiffLckRqFrtAxl1_UB_g;/* '<Root>/CrCtl_TC1DisengDiffLckRqFrtAxl1_UB' */
  boolean_T MFLv_swt_Bl;               /* '<Root>/MFLv_swt_Bl' */
  uint8_T CrCtl_CCVSCCSt_UB_g;         /* '<Root>/CrCtl_CCVSCCSt_UB' */
} ExtY_CrCtl_T;

/* Real-time Model Data Structure */


  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
 


/* Block signals (default storage) */
extern B_CrCtl_T CrCtl_B;

/* Block states (default storage) */
extern DW_CrCtl_T CrCtl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CrCtl_T CrCtl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CrCtl_T CrCtl_Y;
extern const ConstB_CrCtl_T CrCtl_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_CrCtl_T CrCtl_ConstP;

/* Model entry point functions */
extern void CrCtl_initialize(void);
extern void CrCtl_step(void);
extern void CrCtl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CrCtl_T *const CrCtl_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern uint8_T AccPedPos1_pctUB;
extern int8_T ActlRtdrPctTrq_SB;
extern uint8_T ActualEngPercentTorque_UB;
extern uint8_T BrkCD_stPressed_UB;
extern uint8_T ConvCD_stClth_UB;
extern uint8_T CrCtl_CCAcc_UB;
extern uint8_T CrCtl_CCCstDecl_UB;
extern uint8_T CrCtl_CCRes_UB;
extern uint8_T CrCtl_CCSet_UB;
extern uint8_T CrCtl_CCVSCCSt_UB;
extern boolean_T CrCtl_PCCAct_BL;
extern uint8_T CrCtl_TC1DisengDiffLckRqFrtAxl1_UB;
extern uint8_T CrCtl_TC1DisengDrvlnReq_UB;
extern uint8_T CrCtl_TC1TrsReqGear_UB;
extern uint8_T CrCtl_TSC1EngOvrdCtrlMd_UB;
extern uint8_T CrCtl_enPCC_UB;
extern boolean_T CrCtl_stActive_BL;
extern uint8_T CrCtl_stModeIn_UB;
extern uint8_T CrCtl_stModeSubIn_UB;
extern uint8_T CrCtl_stOpFunc_UB;      /* State          Value (h)   Meaning
                                          CRCTL_NOTACTV  0           Cruise control inactive
                                          CRCTL_ACTV     1           Cruise control active
                                          CRCTL_OVERRIDE 2           Cruise control violation AccPed_trqDes > CrCtl_trqDes and AccPed_rChkdVal > 0% */
extern uint16_T CrCtl_tiPCCRmp_10msUW;
extern int32_T CrCtl_trqDes_10mNmSL;
extern int32_T CrCtl_trqPCCReqin_10mNmSL;
extern uint16_T CrCtl_vSetPointAct_mp_10mphUW;
extern uint16_T CrCtl_vSetPointTrgtIn_10mphUW;
extern uint16_T CrCtl_vSetPointTrgt_10mphUW;
extern uint8_T CrCtl_vSetPointTrgt_kmphUB;
extern int8_T EEC1_DrvrDmdEngPctTrq_UB;
extern uint8_T ETC1_trsSftPrcs_UB;
extern int8_T ETC2_trsCrntGr_SB;
extern int8_T ETC2_trsSlctGr_SB;
extern uint16_T EngReferenceTorque_NmUW;
extern int8_T EngRqedTorque_TorqueLimit_SB;
extern uint16_T EngSpeed_rpmUW;
extern boolean_T MFLv_resBL;
extern boolean_T MFLv_setDownBL;
extern boolean_T MFLv_setUpBL;
extern uint8_T MFLv_stCrCtlMode;
extern boolean_T MFLv_swtBL;
extern boolean_T PCC_TC1Act_Bl;
extern uint8_T PCC_offRsn_UB;
extern int8_T PCC_targetGear_SB;
extern int8_T PCC_trqReq_pctSB;
extern uint8_T PCC_vSetPointTrgt_kmphUW;
extern int32_T PrpBrk_trqDes_10mNmL;
extern uint16_T RefRtdrTrq_NmUW;
extern uint8_T TCU_stShiftHandle_UB;
extern uint16_T TachographVehicleSpeed_10mphUW;
extern uint16_T VSSCD_v_10mphUW;

/* Declaration for custom storage class: Global */
extern uint8_T CRCTL_PCC;
extern int16_T CrCtl_AccIKi1_C;
extern int16_T CrCtl_AccIKi2_C;
extern int16_T CrCtl_AccIKi3_C;
extern int16_T CrCtl_AccIKiNeg1_C;
extern int16_T CrCtl_AccIKiNeg2_C;
extern int16_T CrCtl_AccIKiNeg3_C;
extern int16_T CrCtl_AccIKiPos1_C;
extern int16_T CrCtl_AccIKiPos2_C;
extern int16_T CrCtl_AccIKiPos3_C;
extern int16_T CrCtl_AccIWinNeg1_C;
extern int16_T CrCtl_AccIWinNeg2_C;
extern int16_T CrCtl_AccIWinNeg3_C;
extern int16_T CrCtl_AccIWinPos1_C;
extern int16_T CrCtl_AccIWinPos2_C;
extern int16_T CrCtl_AccIWinPos3_C;
extern int16_T CrCtl_AccPKp1_C;
extern int16_T CrCtl_AccPKp2_C;
extern int16_T CrCtl_AccPKp3_C;
extern int16_T CrCtl_AccPKpNeg1_C;
extern int16_T CrCtl_AccPKpNeg2_C;
extern int16_T CrCtl_AccPKpNeg3_C;
extern int16_T CrCtl_AccPKpPos1_C;
extern int16_T CrCtl_AccPKpPos2_C;
extern int16_T CrCtl_AccPKpPos3_C;
extern int16_T CrCtl_AccPWinNeg1_C;
extern int16_T CrCtl_AccPWinNeg2_C;
extern int16_T CrCtl_AccPWinNeg3_C;
extern int16_T CrCtl_AccPWinPos1_C;
extern int16_T CrCtl_AccPWinPos2_C;
extern int16_T CrCtl_AccPWinPos3_C;
extern int16_T CrCtl_DeclIKi1_C;
extern int16_T CrCtl_DeclIKi2_C;
extern int16_T CrCtl_DeclIKi3_C;
extern int16_T CrCtl_DeclIKiNeg1_C;
extern int16_T CrCtl_DeclIKiNeg2_C;
extern int16_T CrCtl_DeclIKiNeg3_C;
extern int16_T CrCtl_DeclIKiPos1_C;
extern int16_T CrCtl_DeclIKiPos2_C;
extern int16_T CrCtl_DeclIKiPos3_C;
extern int16_T CrCtl_DeclIWinNeg1_C;
extern int16_T CrCtl_DeclIWinNeg2_C;
extern int16_T CrCtl_DeclIWinNeg3_C;
extern int16_T CrCtl_DeclIWinPos1_C;
extern int16_T CrCtl_DeclIWinPos2_C;
extern int16_T CrCtl_DeclIWinPos3_C;
extern int16_T CrCtl_DeclPKp1_C;
extern int16_T CrCtl_DeclPKp2_C;
extern int16_T CrCtl_DeclPKp3_C;
extern int16_T CrCtl_DeclPKpNeg1_C;
extern int16_T CrCtl_DeclPKpNeg2_C;
extern int16_T CrCtl_DeclPKpNeg3_C;
extern int16_T CrCtl_DeclPKpPos1_C;
extern int16_T CrCtl_DeclPKpPos2_C;
extern int16_T CrCtl_DeclPKpPos3_C;
extern int16_T CrCtl_DeclPWinNeg1_C;
extern int16_T CrCtl_DeclPWinNeg2_C;
extern int16_T CrCtl_DeclPWinNeg3_C;
extern int16_T CrCtl_DeclPWinPos1_C;
extern int16_T CrCtl_DeclPWinPos2_C;
extern int16_T CrCtl_DeclPWinPos3_C;
extern uint8_T CrCtl_GearMin_C;
extern int16_T CrCtl_HoldIKi1_C;
extern int16_T CrCtl_HoldIKi2_C;
extern int16_T CrCtl_HoldIKi3_C;
extern int16_T CrCtl_HoldIKiNeg1_C;
extern int16_T CrCtl_HoldIKiNeg2_C;
extern int16_T CrCtl_HoldIKiNeg3_C;
extern int16_T CrCtl_HoldIKiPos1_C;
extern int16_T CrCtl_HoldIKiPos2_C;
extern int16_T CrCtl_HoldIKiPos3_C;
extern int16_T CrCtl_HoldIWinNeg1_C;
extern int16_T CrCtl_HoldIWinNeg2_C;
extern int16_T CrCtl_HoldIWinNeg3_C;
extern int16_T CrCtl_HoldIWinPos1_C;
extern int16_T CrCtl_HoldIWinPos2_C;
extern int16_T CrCtl_HoldIWinPos3_C;
extern int16_T CrCtl_HoldPKp1_C;
extern int16_T CrCtl_HoldPKp2_C;
extern int16_T CrCtl_HoldPKp3_C;
extern int16_T CrCtl_HoldPKpNeg1_C;
extern int16_T CrCtl_HoldPKpNeg2_C;
extern int16_T CrCtl_HoldPKpNeg3_C;
extern int16_T CrCtl_HoldPKpPos1_C;
extern int16_T CrCtl_HoldPKpPos2_C;
extern int16_T CrCtl_HoldPKpPos3_C;
extern int16_T CrCtl_HoldPWinNeg1_C;
extern int16_T CrCtl_HoldPWinNeg2_C;
extern int16_T CrCtl_HoldPWinNeg3_C;
extern int16_T CrCtl_HoldPWinPos1_C;
extern int16_T CrCtl_HoldPWinPos2_C;
extern int16_T CrCtl_HoldPWinPos3_C;
extern int16_T CrCtl_ResHoldIKi1_C;
extern int16_T CrCtl_ResHoldIKi2_C;
extern int16_T CrCtl_ResHoldIKi3_C;
extern int16_T CrCtl_ResHoldIKiNeg1_C;
extern int16_T CrCtl_ResHoldIKiNeg2_C;
extern int16_T CrCtl_ResHoldIKiNeg3_C;
extern int16_T CrCtl_ResHoldIKiPos1_C;
extern int16_T CrCtl_ResHoldIKiPos2_C;
extern int16_T CrCtl_ResHoldIKiPos3_C;
extern int16_T CrCtl_ResHoldIWinNeg1_C;
extern int16_T CrCtl_ResHoldIWinNeg2_C;
extern int16_T CrCtl_ResHoldIWinNeg3_C;
extern int16_T CrCtl_ResHoldIWinPos1_C;
extern int16_T CrCtl_ResHoldIWinPos2_C;
extern int16_T CrCtl_ResHoldIWinPos3_C;
extern int16_T CrCtl_ResHoldPKp1_C;
extern int16_T CrCtl_ResHoldPKp2_C;
extern int16_T CrCtl_ResHoldPKp3_C;
extern int16_T CrCtl_ResHoldPKpNeg1_C;
extern int16_T CrCtl_ResHoldPKpNeg2_C;
extern int16_T CrCtl_ResHoldPKpNeg3_C;
extern int16_T CrCtl_ResHoldPKpPos1_C;
extern int16_T CrCtl_ResHoldPKpPos2_C;
extern int16_T CrCtl_ResHoldPKpPos3_C;
extern int16_T CrCtl_ResHoldPWinNeg1_C;
extern int16_T CrCtl_ResHoldPWinNeg2_C;
extern int16_T CrCtl_ResHoldPWinNeg3_C;
extern int16_T CrCtl_ResHoldPWinPos1_C;
extern int16_T CrCtl_ResHoldPWinPos2_C;
extern int16_T CrCtl_ResHoldPWinPos3_C;
extern int16_T CrCtl_ResIKi1_C;
extern int16_T CrCtl_ResIKi2_C;
extern int16_T CrCtl_ResIKi3_C;
extern int16_T CrCtl_ResIKiNeg1_C;
extern int16_T CrCtl_ResIKiNeg2_C;
extern int16_T CrCtl_ResIKiNeg3_C;
extern int16_T CrCtl_ResIKiPos1_C;
extern int16_T CrCtl_ResIKiPos2_C;
extern int16_T CrCtl_ResIKiPos3_C;
extern int16_T CrCtl_ResIWinNeg1_C;
extern int16_T CrCtl_ResIWinNeg2_C;
extern int16_T CrCtl_ResIWinNeg3_C;
extern int16_T CrCtl_ResIWinPos1_C;
extern int16_T CrCtl_ResIWinPos2_C;
extern int16_T CrCtl_ResIWinPos3_C;
extern int16_T CrCtl_ResPKp1_C;
extern int16_T CrCtl_ResPKp2_C;
extern int16_T CrCtl_ResPKp3_C;
extern int16_T CrCtl_ResPKpNeg1_C;
extern int16_T CrCtl_ResPKpNeg2_C;
extern int16_T CrCtl_ResPKpNeg3_C;
extern int16_T CrCtl_ResPKpPos1_C;
extern int16_T CrCtl_ResPKpPos2_C;
extern int16_T CrCtl_ResPKpPos3_C;
extern int16_T CrCtl_ResPWinNeg1_C;
extern int16_T CrCtl_ResPWinNeg2_C;
extern int16_T CrCtl_ResPWinNeg3_C;
extern int16_T CrCtl_ResPWinPos1_C;
extern int16_T CrCtl_ResPWinPos2_C;
extern int16_T CrCtl_ResPWinPos3_C;
extern int16_T CrCtl_aAccShOff_C_10mmps2;
extern int8_T CrCtl_aAccThres_C_10mmps2;
extern int16_T CrCtl_aDeclShOff_C_10mmps2;
extern int8_T CrCtl_aDeclThres_C_10mmps2;
extern int8_T CrCtl_facRmpSlpAcc_C_100mphps;
extern int8_T CrCtl_facRmpSlpDecl_C_100mph;
extern int8_T CrCtl_facRmpSlpHiAcc_C_Nmps;
extern int8_T CrCtl_facRmpSlpHiDecl_C;
extern uint8_T CrCtl_facRmpSlpRes_C_100mphps;
extern int8_T CrCtl_facSlpRmp1Sus_C;
extern uint8_T CrCtl_facSlpRmp2Sus_C;
extern int16_T CrCtl_facSlpRmpTwoDwn_C;
extern uint8_T CrCtl_facSlpRmpTwoUp_C;
extern int8_T CrCtl_facTrqIncrRmpOne_C;
extern int8_T CrCtl_facTrqIncrRmpTwo_C;
extern int8_T CrCtl_facTrqRedRmpOne_C;
extern int8_T CrCtl_facTrqRedRmpTwo_C;
extern int8_T CrCtl_facTrqStrtAcc_C_100mNmpkmph;
extern uint8_T CrCtl_gear;
extern int32_T CrCtl_nMaxShOff_C_10mrpm;
extern int32_T CrCtl_nMinShOff_C_10mrpm;
extern uint8_T CrCtl_rVnDvtAbsShOff_C_mmphprpm;
extern uint8_T CrCtl_stParSelThres1_C;
extern uint8_T CrCtl_stParSelThres2_C;
extern boolean_T CrCtl_swtSusRmpInit_C;/* Switch over of starting torque initialisation for the torque ramp upon ending suspend<value> */
extern boolean_T CrCtl_swtSusRmpStp_C; /* Switch over of suspend behaviour: ramp or single step<value> */
extern int8_T CrCtl_tiAccShOff_C_ms;
extern int8_T CrCtl_tiDeclShOff_C_ms;
extern uint8_T CrCtl_tiDvtShOff_C_ms;
extern uint8_T CrCtl_tiEnaAftShOff_C;
extern uint8_T CrCtl_tiOverrideShOff_C;
extern uint8_T CrCtl_tiShDwnRmpOne_C;
extern int16_T CrCtl_trqCorAcc_C_Nmp10mmps2;
extern int16_T CrCtl_trqCorDecl_C_mNmp10mmps2;
extern uint8_T CrCtl_trqOfsResAbv_C;
extern uint8_T CrCtl_trqOfsResBlw_C;
extern int16_T CrCtl_trqStrtAccOfs_C_10mNm;
extern int16_T CrCtl_vDvtMaxAccDecl_C_10mph;
extern int16_T CrCtl_vDvtShOff_C_10mph;
extern int16_T CrCtl_vEnaAftShoff_C_10mph;
extern int8_T CrCtl_vMaxDvtAcc_C_10mph;
extern int16_T CrCtl_vMaxDvtDecl_C_10mph;
extern uint8_T CrCtl_vMaxDvtResAbv_C;
extern uint8_T CrCtl_vMaxDvtResBlw_C_10mph;
extern int16_T CrCtl_vMaxShOff_C_10mph;
extern int16_T CrCtl_vMax_C_10mph;
extern int16_T CrCtl_vMinShOff_C_10mph;
extern int16_T CrCtl_vMin_C_10mph;
extern int16_T CrCtl_vPIGovDvt_C1_10mphSW;
extern int16_T CrCtl_vPIGovDvt_C2_10mphSW;
extern int16_T CrCtl_vPIGovDvt_C3_10mphSW;
extern int16_T CrCtl_vPIGovDvt_C4_10mphSW;
extern int16_T CrCtl_vTipDwnLoLim_C_10mph;
extern int16_T CrCtl_vTipDwnUpLim_C_10mph;
extern int8_T CrCtl_vTipStp_C_10mph;
extern int16_T CrCtl_vTipUpLoLim_C_10mph;
extern int16_T CrCtl_vTipUpUpLim_C_10mph;
extern uint8_T stcMovSwt;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/0' : Unused code path elimination
 * Block '<S1>/NotAvailable' : Unused code path elimination
 * Block '<S1>/Set' : Unused code path elimination
 * Block '<S9>/Constant8' : Unused code path elimination
 * Block '<S9>/CrCtl_swtVESGov_C' : Unused code path elimination
 * Block '<S9>/CrCtl_vMinDec_C' : Unused code path elimination
 * Block '<S9>/Index Vector' : Unused code path elimination
 * Block '<S9>/Index Vector1' : Unused code path elimination
 * Block '<S9>/Index Vector2' : Unused code path elimination
 * Block '<S9>/Index Vector3' : Unused code path elimination
 * Block '<S9>/Index Vector4' : Unused code path elimination
 * Block '<S9>/Index Vector5' : Unused code path elimination
 * Block '<S9>/Logical Operator' : Unused code path elimination
 * Block '<S9>/MFLV_DECL' : Unused code path elimination
 * Block '<S9>/MFLV_NEUTR' : Unused code path elimination
 * Block '<S9>/MFLV_SWTOFF' : Unused code path elimination
 * Block '<S9>/Relational Operator' : Unused code path elimination
 * Block '<S9>/Relational Operator1' : Unused code path elimination
 * Block '<S9>/Relational Operator2' : Unused code path elimination
 * Block '<S9>/Relational Operator3' : Unused code path elimination
 * Block '<S9>/Relational Operator4' : Unused code path elimination
 * Block '<S9>/Relational Operator5' : Unused code path elimination
 * Block '<S9>/Relational Operator6' : Unused code path elimination
 * Block '<S10>/Index Vector' : Unused code path elimination
 * Block '<S10>/Index Vector1' : Unused code path elimination
 * Block '<S10>/Index Vector2' : Unused code path elimination
 * Block '<S10>/Index Vector3' : Unused code path elimination
 * Block '<S10>/Index Vector4' : Unused code path elimination
 * Block '<S10>/Logical Operator' : Unused code path elimination
 * Block '<S10>/Logical Operator1' : Unused code path elimination
 * Block '<S10>/MFLV_ACC' : Unused code path elimination
 * Block '<S10>/MFLV_DECL' : Unused code path elimination
 * Block '<S10>/MFLV_NEUTR' : Unused code path elimination
 * Block '<S10>/MFLV_SET' : Unused code path elimination
 * Block '<S10>/MFLV_SWTOFF' : Unused code path elimination
 * Block '<S10>/MFLV_TIPDWN' : Unused code path elimination
 * Block '<S10>/MFLV_TIPUP' : Unused code path elimination
 * Block '<S10>/Relational Operator' : Unused code path elimination
 * Block '<S10>/Relational Operator1' : Unused code path elimination
 * Block '<S10>/Relational Operator2' : Unused code path elimination
 * Block '<S10>/Relational Operator3' : Unused code path elimination
 * Block '<S10>/Relational Operator4' : Unused code path elimination
 * Block '<S10>/Relational Operator5' : Unused code path elimination
 * Block '<S10>/Relational Operator6' : Unused code path elimination
 * Block '<S10>/Relational Operator7' : Unused code path elimination
 * Block '<S10>/Relational Operator8' : Unused code path elimination
 * Block '<S10>/VESGOV_STOFF' : Unused code path elimination
 * Block '<S10>/VESGOV_STOFFRAMP' : Unused code path elimination
 * Block '<Root>/Scope237' : Unused code path elimination
 * Block '<Root>/Scope238' : Unused code path elimination
 * Block '<Root>/Scope239' : Unused code path elimination
 * Block '<Root>/Scope240' : Unused code path elimination
 * Block '<Root>/Scope241' : Unused code path elimination
 * Block '<Root>/Scope242' : Unused code path elimination
 * Block '<Root>/Scope243' : Unused code path elimination
 * Block '<Root>/Scope244' : Unused code path elimination
 * Block '<Root>/Scope245' : Unused code path elimination
 * Block '<Root>/Scope247' : Unused code path elimination
 * Block '<Root>/Scope397' : Unused code path elimination
 * Block '<Root>/Scope398' : Unused code path elimination
 * Block '<Root>/Scope399' : Unused code path elimination
 * Block '<Root>/Scope400' : Unused code path elimination
 * Block '<Root>/Scope401' : Unused code path elimination
 * Block '<Root>/Scope402' : Unused code path elimination
 * Block '<Root>/Scope405' : Unused code path elimination
 * Block '<Root>/Scope406' : Unused code path elimination
 * Block '<Root>/Scope407' : Unused code path elimination
 * Block '<Root>/Scope233' : Unused code path elimination
 * Block '<Root>/Scope234' : Unused code path elimination
 * Block '<Root>/Scope236' : Unused code path elimination
 * Block '<Root>/Scope232' : Unused code path elimination
 * Block '<S2>/CrCtl_vMinAct_C_10mph' : Unused code path elimination
 * Block '<S2>/Index Vector6' : Unused code path elimination
 * Block '<S2>/Memory' : Unused code path elimination
 * Block '<S2>/Memory1' : Unused code path elimination
 * Block '<S2>/Relational Operator9' : Unused code path elimination
 * Block '<S35>/ AMT shift' : Unused code path elimination
 * Block '<S35>/AccPedal override' : Unused code path elimination
 * Block '<S35>/CRCTL_ACTV_1h' : Unused code path elimination
 * Block '<S35>/CRCTL_AMTREQSHIFT_4h' : Unused code path elimination
 * Block '<S35>/CRCTL_NOTACTV_0h' : Unused code path elimination
 * Block '<S35>/CRCTL_OVERRIDE_2h' : Unused code path elimination
 * Block '<S35>/CRCTL_PCCREQAMT_3h' : Unused code path elimination
 * Block '<S35>/CRCTL_PCC_10h' : Unused code path elimination
 * Block '<S35>/Index Vector3' : Unused code path elimination
 * Block '<S35>/Index Vector4' : Unused code path elimination
 * Block '<S35>/Index Vector5' : Unused code path elimination
 * Block '<S35>/Index Vector6' : Unused code path elimination
 * Block '<S35>/Logical Operator' : Unused code path elimination
 * Block '<S35>/Logical Operator1' : Unused code path elimination
 * Block '<S35>/Relational Operator2' : Unused code path elimination
 * Block '<S35>/Relational Operator3' : Unused code path elimination
 * Block '<S35>/Relational Operator4' : Unused code path elimination
 * Block '<S35>/manual shift' : Unused code path elimination
 * Block '<S35>/noAccPed' : Unused code path elimination
 * Block '<S35>/requare AMT to shift' : Unused code path elimination
 * Block '<Root>/Scope345' : Unused code path elimination
 * Block '<S3>/CRCTL_LCKACTV_1h' : Unused code path elimination
 * Block '<S3>/CRCTL_NOTLCK_0h' : Unused code path elimination
 * Block '<S36>/0xFFFFFFFF' : Unused code path elimination
 * Block '<S36>/Add3' : Unused code path elimination
 * Block '<S36>/Constant10' : Unused code path elimination
 * Block '<S36>/Constant11' : Unused code path elimination
 * Block '<S36>/Constant12' : Unused code path elimination
 * Block '<S36>/Constant13' : Unused code path elimination
 * Block '<S36>/Constant3' : Unused code path elimination
 * Block '<S36>/Constant4' : Unused code path elimination
 * Block '<S36>/Constant5' : Unused code path elimination
 * Block '<S36>/Constant6' : Unused code path elimination
 * Block '<S36>/Constant7' : Unused code path elimination
 * Block '<S36>/Constant8' : Unused code path elimination
 * Block '<S36>/Constant9' : Unused code path elimination
 * Block '<Root>/Scope256' : Unused code path elimination
 * Block '<Root>/Scope454' : Unused code path elimination
 * Block '<Root>/Scope455' : Unused code path elimination
 * Block '<Root>/Scope456' : Unused code path elimination
 * Block '<Root>/Scope457' : Unused code path elimination
 * Block '<Root>/Scope458' : Unused code path elimination
 * Block '<Root>/Scope459' : Unused code path elimination
 * Block '<Root>/Scope460' : Unused code path elimination
 * Block '<Root>/Scope461' : Unused code path elimination
 * Block '<Root>/Scope462' : Unused code path elimination
 * Block '<S41>/Abs' : Unused code path elimination
 * Block '<S54>/Logical Operator3' : Unused code path elimination
 * Block '<S55>/Logical Operator3' : Unused code path elimination
 * Block '<S56>/Logical Operator3' : Unused code path elimination
 * Block '<S41>/CrCtl_rVnDvtShOff_C' : Unused code path elimination
 * Block '<S51>/DTProp1' : Unused code path elimination
 * Block '<S51>/DTProp2' : Unused code path elimination
 * Block '<S51>/Extract Desired Bits' : Unused code path elimination
 * Block '<S51>/Modify Scaling Only' : Unused code path elimination
 * Block '<S41>/Logical Operator1' : Unused code path elimination
 * Block '<S41>/Logical Operator2' : Unused code path elimination
 * Block '<S41>/Logical Operator3' : Unused code path elimination
 * Block '<S41>/Logical Operator4' : Unused code path elimination
 * Block '<S41>/Relational Operator8' : Unused code path elimination
 * Block '<S41>/Subtract' : Unused code path elimination
 * Block '<Root>/Scope443' : Unused code path elimination
 * Block '<Root>/Scope444' : Unused code path elimination
 * Block '<Root>/Scope445' : Unused code path elimination
 * Block '<S77>/DTProp1' : Unused code path elimination
 * Block '<S77>/DTProp2' : Unused code path elimination
 * Block '<S42>/Logical Operator4' : Unused code path elimination
 * Block '<S78>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope449' : Unused code path elimination
 * Block '<Root>/Scope450' : Unused code path elimination
 * Block '<Root>/Scope451' : Unused code path elimination
 * Block '<Root>/Scope452' : Unused code path elimination
 * Block '<Root>/Scope453' : Unused code path elimination
 * Block '<S43>/CRCTL_ACTV(=1h)' : Unused code path elimination
 * Block '<S43>/CRCTL_HOLD(=9h)' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/Constant1' : Unused code path elimination
 * Block '<S43>/Constant2' : Unused code path elimination
 * Block '<S43>/Constant3' : Unused code path elimination
 * Block '<S43>/CrCtl_facDvtRelShOff_C' : Unused code path elimination
 * Block '<S43>/CrCtl_vDvtNegShOff_C_10mph' : Unused code path elimination
 * Block '<S43>/CrCtl_vDvtPosShOff_C_10mph' : Unused code path elimination
 * Block '<S43>/Divide' : Unused code path elimination
 * Block '<S43>/Logical Operator' : Unused code path elimination
 * Block '<S43>/Logical Operator1' : Unused code path elimination
 * Block '<S43>/Logical Operator2' : Unused code path elimination
 * Block '<S43>/Logical Operator3' : Unused code path elimination
 * Block '<S43>/Logical Operator4' : Unused code path elimination
 * Block '<S43>/Logical Operator5' : Unused code path elimination
 * Block '<S43>/Product' : Unused code path elimination
 * Block '<S43>/Relational Operator' : Unused code path elimination
 * Block '<S43>/Relational Operator1' : Unused code path elimination
 * Block '<S43>/Relational Operator10' : Unused code path elimination
 * Block '<S43>/Relational Operator3' : Unused code path elimination
 * Block '<S43>/Relational Operator4' : Unused code path elimination
 * Block '<S43>/Relational Operator5' : Unused code path elimination
 * Block '<S43>/Subtract' : Unused code path elimination
 * Block '<S43>/Sum1' : Unused code path elimination
 * Block '<S43>/T15CD_ST_OFF(=0)' : Unused code path elimination
 * Block '<S43>/UnitConv' : Unused code path elimination
 * Block '<S36>/Dirve' : Unused code path elimination
 * Block '<S36>/Gain21' : Unused code path elimination
 * Block '<S36>/Gain22' : Unused code path elimination
 * Block '<S36>/Gain23' : Unused code path elimination
 * Block '<S36>/Gain24' : Unused code path elimination
 * Block '<S36>/Index Vector3' : Unused code path elimination
 * Block '<S36>/Index Vector4' : Unused code path elimination
 * Block '<S36>/Index Vector5' : Unused code path elimination
 * Block '<S36>/Index Vector6' : Unused code path elimination
 * Block '<S36>/Index Vector7' : Unused code path elimination
 * Block '<S36>/Index Vector8' : Unused code path elimination
 * Block '<S36>/Relational Operator5' : Unused code path elimination
 * Block '<Root>/Scope437' : Unused code path elimination
 * Block '<Root>/Scope438' : Unused code path elimination
 * Block '<Root>/Scope439' : Unused code path elimination
 * Block '<Root>/Scope440' : Unused code path elimination
 * Block '<Root>/Scope441' : Unused code path elimination
 * Block '<Root>/Scope442' : Unused code path elimination
 * Block '<Root>/Scope446' : Unused code path elimination
 * Block '<Root>/Scope447' : Unused code path elimination
 * Block '<Root>/Scope448' : Unused code path elimination
 * Block '<S37>/Constant' : Unused code path elimination
 * Block '<S116>/DTProp1' : Unused code path elimination
 * Block '<S116>/DTProp2' : Unused code path elimination
 * Block '<S37>/Index Vector2' : Unused code path elimination
 * Block '<S3>/CrCtl_trqMin_10mNm' : Unused code path elimination
 * Block '<S3>/Index Vector1' : Unused code path elimination
 * Block '<S3>/Index Vector2' : Unused code path elimination
 * Block '<S3>/Relational Operator' : Unused code path elimination
 * Block '<S3>/T15CD_ST_OFF_0h' : Unused code path elimination
 * Block '<Root>/Scope298' : Unused code path elimination
 * Block '<Root>/Scope346' : Unused code path elimination
 * Block '<Root>/Scope348' : Unused code path elimination
 * Block '<Root>/Scope351' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Data Type Propagation' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Propagation' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Propagation' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Scope338' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Scope260' : Unused code path elimination
 * Block '<Root>/Scope261' : Unused code path elimination
 * Block '<Root>/Scope263' : Unused code path elimination
 * Block '<Root>/Scope264' : Unused code path elimination
 * Block '<Root>/Scope265' : Unused code path elimination
 * Block '<Root>/Scope342' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Scope340' : Unused code path elimination
 * Block '<Root>/Scope349' : Unused code path elimination
 * Block '<Root>/Scope352' : Unused code path elimination
 * Block '<Root>/Scope353' : Unused code path elimination
 * Block '<Root>/Scope354' : Unused code path elimination
 * Block '<Root>/Scope355' : Unused code path elimination
 * Block '<Root>/Scope356' : Unused code path elimination
 * Block '<Root>/Scope357' : Unused code path elimination
 * Block '<Root>/Scope250' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Scope331' : Unused code path elimination
 * Block '<Root>/Scope332' : Unused code path elimination
 * Block '<Root>/Scope333' : Unused code path elimination
 * Block '<Root>/Scope385' : Unused code path elimination
 * Block '<Root>/Scope386' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Propagation' : Unused code path elimination
 * Block '<S194>/CRCTL_STACTIVE(=1)' : Unused code path elimination
 * Block '<Root>/Scope389' : Unused code path elimination
 * Block '<S195>/CRCTL_STACTIVE_1h' : Unused code path elimination
 * Block '<Root>/Scope372' : Unused code path elimination
 * Block '<Root>/Scope373' : Unused code path elimination
 * Block '<Root>/Scope374' : Unused code path elimination
 * Block '<Root>/Scope375' : Unused code path elimination
 * Block '<Root>/Scope376' : Unused code path elimination
 * Block '<Root>/Scope377' : Unused code path elimination
 * Block '<Root>/Scope378' : Unused code path elimination
 * Block '<Root>/Scope379' : Unused code path elimination
 * Block '<Root>/Scope380' : Unused code path elimination
 * Block '<Root>/Scope381' : Unused code path elimination
 * Block '<S196>/CRCTL_STACTIVE(=1)' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate' : Unused code path elimination
 * Block '<S218>/Data Type Propagation' : Unused code path elimination
 * Block '<S215>/DISAct' : Unused code path elimination
 * Block '<S215>/Index Vector1' : Unused code path elimination
 * Block '<S215>/Logical Operator2' : Unused code path elimination
 * Block '<S215>/Relational Operator' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate' : Unused code path elimination
 * Block '<S255>/Data Type Propagation' : Unused code path elimination
 * Block '<S250>/Scope' : Unused code path elimination
 * Block '<S250>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope248' : Unused code path elimination
 * Block '<Root>/Scope358' : Unused code path elimination
 * Block '<Root>/Scope382' : Unused code path elimination
 * Block '<Root>/Scope383' : Unused code path elimination
 * Block '<Root>/Scope384' : Unused code path elimination
 * Block '<Root>/Scope426' : Unused code path elimination
 * Block '<Root>/Scope427' : Unused code path elimination
 * Block '<Root>/Scope428' : Unused code path elimination
 * Block '<Root>/Scope429' : Unused code path elimination
 * Block '<Root>/Scope430' : Unused code path elimination
 * Block '<Root>/Scope432' : Unused code path elimination
 * Block '<Root>/Scope424' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S7>/VESGOV_STOFF' : Unused code path elimination
 * Block '<S327>/CnvUnt' : Unused code path elimination
 * Block '<S327>/Constant3' : Unused code path elimination
 * Block '<S328>/Data Type Duplicate' : Unused code path elimination
 * Block '<S327>/Divide1' : Unused code path elimination
 * Block '<S327>/Divide12' : Unused code path elimination
 * Block '<S327>/Divide2' : Unused code path elimination
 * Block '<S327>/Divide4' : Unused code path elimination
 * Block '<S327>/EDSEfficiency' : Unused code path elimination
 * Block '<S327>/FinnalDriveEfficiency_10mUnt' : Unused code path elimination
 * Block '<S327>/GearEfficiency_D2_10mUnt' : Unused code path elimination
 * Block '<S327>/Product6' : Unused code path elimination
 * Block '<S327>/Product7' : Unused code path elimination
 * Block '<S327>/engSpd2BrkPwr_rpm2kw' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope100' : Unused code path elimination
 * Block '<Root>/Scope101' : Unused code path elimination
 * Block '<Root>/Scope102' : Unused code path elimination
 * Block '<Root>/Scope103' : Unused code path elimination
 * Block '<Root>/Scope104' : Unused code path elimination
 * Block '<Root>/Scope105' : Unused code path elimination
 * Block '<Root>/Scope106' : Unused code path elimination
 * Block '<Root>/Scope107' : Unused code path elimination
 * Block '<Root>/Scope108' : Unused code path elimination
 * Block '<Root>/Scope109' : Unused code path elimination
 * Block '<Root>/Scope11' : Unused code path elimination
 * Block '<Root>/Scope110' : Unused code path elimination
 * Block '<Root>/Scope111' : Unused code path elimination
 * Block '<Root>/Scope112' : Unused code path elimination
 * Block '<Root>/Scope113' : Unused code path elimination
 * Block '<Root>/Scope114' : Unused code path elimination
 * Block '<Root>/Scope115' : Unused code path elimination
 * Block '<Root>/Scope116' : Unused code path elimination
 * Block '<Root>/Scope117' : Unused code path elimination
 * Block '<Root>/Scope118' : Unused code path elimination
 * Block '<Root>/Scope119' : Unused code path elimination
 * Block '<Root>/Scope12' : Unused code path elimination
 * Block '<Root>/Scope120' : Unused code path elimination
 * Block '<Root>/Scope121' : Unused code path elimination
 * Block '<Root>/Scope122' : Unused code path elimination
 * Block '<Root>/Scope123' : Unused code path elimination
 * Block '<Root>/Scope124' : Unused code path elimination
 * Block '<Root>/Scope125' : Unused code path elimination
 * Block '<Root>/Scope126' : Unused code path elimination
 * Block '<Root>/Scope127' : Unused code path elimination
 * Block '<Root>/Scope128' : Unused code path elimination
 * Block '<Root>/Scope129' : Unused code path elimination
 * Block '<Root>/Scope13' : Unused code path elimination
 * Block '<Root>/Scope130' : Unused code path elimination
 * Block '<Root>/Scope131' : Unused code path elimination
 * Block '<Root>/Scope132' : Unused code path elimination
 * Block '<Root>/Scope133' : Unused code path elimination
 * Block '<Root>/Scope134' : Unused code path elimination
 * Block '<Root>/Scope135' : Unused code path elimination
 * Block '<Root>/Scope136' : Unused code path elimination
 * Block '<Root>/Scope137' : Unused code path elimination
 * Block '<Root>/Scope138' : Unused code path elimination
 * Block '<Root>/Scope139' : Unused code path elimination
 * Block '<Root>/Scope14' : Unused code path elimination
 * Block '<Root>/Scope140' : Unused code path elimination
 * Block '<Root>/Scope141' : Unused code path elimination
 * Block '<Root>/Scope142' : Unused code path elimination
 * Block '<Root>/Scope143' : Unused code path elimination
 * Block '<Root>/Scope144' : Unused code path elimination
 * Block '<Root>/Scope145' : Unused code path elimination
 * Block '<Root>/Scope146' : Unused code path elimination
 * Block '<Root>/Scope147' : Unused code path elimination
 * Block '<Root>/Scope148' : Unused code path elimination
 * Block '<Root>/Scope149' : Unused code path elimination
 * Block '<Root>/Scope15' : Unused code path elimination
 * Block '<Root>/Scope150' : Unused code path elimination
 * Block '<Root>/Scope151' : Unused code path elimination
 * Block '<Root>/Scope152' : Unused code path elimination
 * Block '<Root>/Scope153' : Unused code path elimination
 * Block '<Root>/Scope154' : Unused code path elimination
 * Block '<Root>/Scope155' : Unused code path elimination
 * Block '<Root>/Scope156' : Unused code path elimination
 * Block '<Root>/Scope157' : Unused code path elimination
 * Block '<Root>/Scope158' : Unused code path elimination
 * Block '<Root>/Scope159' : Unused code path elimination
 * Block '<Root>/Scope16' : Unused code path elimination
 * Block '<Root>/Scope160' : Unused code path elimination
 * Block '<Root>/Scope161' : Unused code path elimination
 * Block '<Root>/Scope162' : Unused code path elimination
 * Block '<Root>/Scope163' : Unused code path elimination
 * Block '<Root>/Scope164' : Unused code path elimination
 * Block '<Root>/Scope165' : Unused code path elimination
 * Block '<Root>/Scope166' : Unused code path elimination
 * Block '<Root>/Scope167' : Unused code path elimination
 * Block '<Root>/Scope168' : Unused code path elimination
 * Block '<Root>/Scope169' : Unused code path elimination
 * Block '<Root>/Scope17' : Unused code path elimination
 * Block '<Root>/Scope170' : Unused code path elimination
 * Block '<Root>/Scope171' : Unused code path elimination
 * Block '<Root>/Scope172' : Unused code path elimination
 * Block '<Root>/Scope173' : Unused code path elimination
 * Block '<Root>/Scope174' : Unused code path elimination
 * Block '<Root>/Scope175' : Unused code path elimination
 * Block '<Root>/Scope176' : Unused code path elimination
 * Block '<Root>/Scope177' : Unused code path elimination
 * Block '<Root>/Scope178' : Unused code path elimination
 * Block '<Root>/Scope179' : Unused code path elimination
 * Block '<Root>/Scope18' : Unused code path elimination
 * Block '<Root>/Scope180' : Unused code path elimination
 * Block '<Root>/Scope181' : Unused code path elimination
 * Block '<Root>/Scope182' : Unused code path elimination
 * Block '<Root>/Scope183' : Unused code path elimination
 * Block '<Root>/Scope184' : Unused code path elimination
 * Block '<Root>/Scope185' : Unused code path elimination
 * Block '<Root>/Scope186' : Unused code path elimination
 * Block '<Root>/Scope187' : Unused code path elimination
 * Block '<Root>/Scope188' : Unused code path elimination
 * Block '<Root>/Scope189' : Unused code path elimination
 * Block '<Root>/Scope19' : Unused code path elimination
 * Block '<Root>/Scope190' : Unused code path elimination
 * Block '<Root>/Scope191' : Unused code path elimination
 * Block '<Root>/Scope192' : Unused code path elimination
 * Block '<Root>/Scope193' : Unused code path elimination
 * Block '<Root>/Scope194' : Unused code path elimination
 * Block '<Root>/Scope195' : Unused code path elimination
 * Block '<Root>/Scope196' : Unused code path elimination
 * Block '<Root>/Scope197' : Unused code path elimination
 * Block '<Root>/Scope198' : Unused code path elimination
 * Block '<Root>/Scope199' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope20' : Unused code path elimination
 * Block '<Root>/Scope200' : Unused code path elimination
 * Block '<Root>/Scope201' : Unused code path elimination
 * Block '<Root>/Scope202' : Unused code path elimination
 * Block '<Root>/Scope203' : Unused code path elimination
 * Block '<Root>/Scope204' : Unused code path elimination
 * Block '<Root>/Scope205' : Unused code path elimination
 * Block '<Root>/Scope206' : Unused code path elimination
 * Block '<Root>/Scope207' : Unused code path elimination
 * Block '<Root>/Scope208' : Unused code path elimination
 * Block '<Root>/Scope209' : Unused code path elimination
 * Block '<Root>/Scope21' : Unused code path elimination
 * Block '<Root>/Scope210' : Unused code path elimination
 * Block '<Root>/Scope211' : Unused code path elimination
 * Block '<Root>/Scope212' : Unused code path elimination
 * Block '<Root>/Scope213' : Unused code path elimination
 * Block '<Root>/Scope214' : Unused code path elimination
 * Block '<Root>/Scope215' : Unused code path elimination
 * Block '<Root>/Scope216' : Unused code path elimination
 * Block '<Root>/Scope217' : Unused code path elimination
 * Block '<Root>/Scope218' : Unused code path elimination
 * Block '<Root>/Scope219' : Unused code path elimination
 * Block '<Root>/Scope22' : Unused code path elimination
 * Block '<Root>/Scope220' : Unused code path elimination
 * Block '<Root>/Scope221' : Unused code path elimination
 * Block '<Root>/Scope222' : Unused code path elimination
 * Block '<Root>/Scope223' : Unused code path elimination
 * Block '<Root>/Scope224' : Unused code path elimination
 * Block '<Root>/Scope225' : Unused code path elimination
 * Block '<Root>/Scope226' : Unused code path elimination
 * Block '<Root>/Scope227' : Unused code path elimination
 * Block '<Root>/Scope228' : Unused code path elimination
 * Block '<Root>/Scope229' : Unused code path elimination
 * Block '<Root>/Scope23' : Unused code path elimination
 * Block '<Root>/Scope230' : Unused code path elimination
 * Block '<Root>/Scope231' : Unused code path elimination
 * Block '<Root>/Scope235' : Unused code path elimination
 * Block '<Root>/Scope24' : Unused code path elimination
 * Block '<Root>/Scope246' : Unused code path elimination
 * Block '<Root>/Scope249' : Unused code path elimination
 * Block '<Root>/Scope25' : Unused code path elimination
 * Block '<Root>/Scope251' : Unused code path elimination
 * Block '<Root>/Scope252' : Unused code path elimination
 * Block '<Root>/Scope253' : Unused code path elimination
 * Block '<Root>/Scope254' : Unused code path elimination
 * Block '<Root>/Scope255' : Unused code path elimination
 * Block '<Root>/Scope257' : Unused code path elimination
 * Block '<Root>/Scope258' : Unused code path elimination
 * Block '<Root>/Scope259' : Unused code path elimination
 * Block '<Root>/Scope26' : Unused code path elimination
 * Block '<Root>/Scope262' : Unused code path elimination
 * Block '<Root>/Scope266' : Unused code path elimination
 * Block '<Root>/Scope267' : Unused code path elimination
 * Block '<Root>/Scope268' : Unused code path elimination
 * Block '<Root>/Scope269' : Unused code path elimination
 * Block '<Root>/Scope27' : Unused code path elimination
 * Block '<Root>/Scope270' : Unused code path elimination
 * Block '<Root>/Scope271' : Unused code path elimination
 * Block '<Root>/Scope272' : Unused code path elimination
 * Block '<Root>/Scope273' : Unused code path elimination
 * Block '<Root>/Scope274' : Unused code path elimination
 * Block '<Root>/Scope275' : Unused code path elimination
 * Block '<Root>/Scope276' : Unused code path elimination
 * Block '<Root>/Scope277' : Unused code path elimination
 * Block '<Root>/Scope278' : Unused code path elimination
 * Block '<Root>/Scope279' : Unused code path elimination
 * Block '<Root>/Scope28' : Unused code path elimination
 * Block '<Root>/Scope280' : Unused code path elimination
 * Block '<Root>/Scope281' : Unused code path elimination
 * Block '<Root>/Scope282' : Unused code path elimination
 * Block '<Root>/Scope283' : Unused code path elimination
 * Block '<Root>/Scope284' : Unused code path elimination
 * Block '<Root>/Scope285' : Unused code path elimination
 * Block '<Root>/Scope286' : Unused code path elimination
 * Block '<Root>/Scope287' : Unused code path elimination
 * Block '<Root>/Scope288' : Unused code path elimination
 * Block '<Root>/Scope289' : Unused code path elimination
 * Block '<Root>/Scope29' : Unused code path elimination
 * Block '<Root>/Scope290' : Unused code path elimination
 * Block '<Root>/Scope291' : Unused code path elimination
 * Block '<Root>/Scope292' : Unused code path elimination
 * Block '<Root>/Scope293' : Unused code path elimination
 * Block '<Root>/Scope294' : Unused code path elimination
 * Block '<Root>/Scope295' : Unused code path elimination
 * Block '<Root>/Scope296' : Unused code path elimination
 * Block '<Root>/Scope297' : Unused code path elimination
 * Block '<Root>/Scope299' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope30' : Unused code path elimination
 * Block '<Root>/Scope300' : Unused code path elimination
 * Block '<Root>/Scope301' : Unused code path elimination
 * Block '<Root>/Scope302' : Unused code path elimination
 * Block '<Root>/Scope303' : Unused code path elimination
 * Block '<Root>/Scope304' : Unused code path elimination
 * Block '<Root>/Scope305' : Unused code path elimination
 * Block '<Root>/Scope306' : Unused code path elimination
 * Block '<Root>/Scope307' : Unused code path elimination
 * Block '<Root>/Scope308' : Unused code path elimination
 * Block '<Root>/Scope309' : Unused code path elimination
 * Block '<Root>/Scope31' : Unused code path elimination
 * Block '<Root>/Scope310' : Unused code path elimination
 * Block '<Root>/Scope311' : Unused code path elimination
 * Block '<Root>/Scope312' : Unused code path elimination
 * Block '<Root>/Scope313' : Unused code path elimination
 * Block '<Root>/Scope314' : Unused code path elimination
 * Block '<Root>/Scope315' : Unused code path elimination
 * Block '<Root>/Scope316' : Unused code path elimination
 * Block '<Root>/Scope317' : Unused code path elimination
 * Block '<Root>/Scope318' : Unused code path elimination
 * Block '<Root>/Scope319' : Unused code path elimination
 * Block '<Root>/Scope32' : Unused code path elimination
 * Block '<Root>/Scope320' : Unused code path elimination
 * Block '<Root>/Scope321' : Unused code path elimination
 * Block '<Root>/Scope322' : Unused code path elimination
 * Block '<Root>/Scope323' : Unused code path elimination
 * Block '<Root>/Scope324' : Unused code path elimination
 * Block '<Root>/Scope325' : Unused code path elimination
 * Block '<Root>/Scope326' : Unused code path elimination
 * Block '<Root>/Scope327' : Unused code path elimination
 * Block '<Root>/Scope328' : Unused code path elimination
 * Block '<Root>/Scope329' : Unused code path elimination
 * Block '<Root>/Scope33' : Unused code path elimination
 * Block '<Root>/Scope330' : Unused code path elimination
 * Block '<Root>/Scope334' : Unused code path elimination
 * Block '<Root>/Scope335' : Unused code path elimination
 * Block '<Root>/Scope336' : Unused code path elimination
 * Block '<Root>/Scope337' : Unused code path elimination
 * Block '<Root>/Scope339' : Unused code path elimination
 * Block '<Root>/Scope34' : Unused code path elimination
 * Block '<Root>/Scope341' : Unused code path elimination
 * Block '<Root>/Scope343' : Unused code path elimination
 * Block '<Root>/Scope344' : Unused code path elimination
 * Block '<Root>/Scope347' : Unused code path elimination
 * Block '<Root>/Scope35' : Unused code path elimination
 * Block '<Root>/Scope350' : Unused code path elimination
 * Block '<Root>/Scope359' : Unused code path elimination
 * Block '<Root>/Scope36' : Unused code path elimination
 * Block '<Root>/Scope360' : Unused code path elimination
 * Block '<Root>/Scope361' : Unused code path elimination
 * Block '<Root>/Scope362' : Unused code path elimination
 * Block '<Root>/Scope363' : Unused code path elimination
 * Block '<Root>/Scope364' : Unused code path elimination
 * Block '<Root>/Scope365' : Unused code path elimination
 * Block '<Root>/Scope366' : Unused code path elimination
 * Block '<Root>/Scope367' : Unused code path elimination
 * Block '<Root>/Scope368' : Unused code path elimination
 * Block '<Root>/Scope369' : Unused code path elimination
 * Block '<Root>/Scope37' : Unused code path elimination
 * Block '<Root>/Scope370' : Unused code path elimination
 * Block '<Root>/Scope371' : Unused code path elimination
 * Block '<Root>/Scope38' : Unused code path elimination
 * Block '<Root>/Scope387' : Unused code path elimination
 * Block '<Root>/Scope388' : Unused code path elimination
 * Block '<Root>/Scope39' : Unused code path elimination
 * Block '<Root>/Scope390' : Unused code path elimination
 * Block '<Root>/Scope391' : Unused code path elimination
 * Block '<Root>/Scope392' : Unused code path elimination
 * Block '<Root>/Scope393' : Unused code path elimination
 * Block '<Root>/Scope394' : Unused code path elimination
 * Block '<Root>/Scope395' : Unused code path elimination
 * Block '<Root>/Scope396' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope40' : Unused code path elimination
 * Block '<Root>/Scope403' : Unused code path elimination
 * Block '<Root>/Scope404' : Unused code path elimination
 * Block '<Root>/Scope408' : Unused code path elimination
 * Block '<Root>/Scope409' : Unused code path elimination
 * Block '<Root>/Scope41' : Unused code path elimination
 * Block '<Root>/Scope410' : Unused code path elimination
 * Block '<Root>/Scope411' : Unused code path elimination
 * Block '<Root>/Scope412' : Unused code path elimination
 * Block '<Root>/Scope413' : Unused code path elimination
 * Block '<Root>/Scope414' : Unused code path elimination
 * Block '<Root>/Scope415' : Unused code path elimination
 * Block '<Root>/Scope416' : Unused code path elimination
 * Block '<Root>/Scope417' : Unused code path elimination
 * Block '<Root>/Scope418' : Unused code path elimination
 * Block '<Root>/Scope419' : Unused code path elimination
 * Block '<Root>/Scope42' : Unused code path elimination
 * Block '<Root>/Scope420' : Unused code path elimination
 * Block '<Root>/Scope421' : Unused code path elimination
 * Block '<Root>/Scope422' : Unused code path elimination
 * Block '<Root>/Scope423' : Unused code path elimination
 * Block '<Root>/Scope425' : Unused code path elimination
 * Block '<Root>/Scope43' : Unused code path elimination
 * Block '<Root>/Scope431' : Unused code path elimination
 * Block '<Root>/Scope433' : Unused code path elimination
 * Block '<Root>/Scope434' : Unused code path elimination
 * Block '<Root>/Scope435' : Unused code path elimination
 * Block '<Root>/Scope436' : Unused code path elimination
 * Block '<Root>/Scope44' : Unused code path elimination
 * Block '<Root>/Scope45' : Unused code path elimination
 * Block '<Root>/Scope46' : Unused code path elimination
 * Block '<Root>/Scope47' : Unused code path elimination
 * Block '<Root>/Scope48' : Unused code path elimination
 * Block '<Root>/Scope49' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope50' : Unused code path elimination
 * Block '<Root>/Scope51' : Unused code path elimination
 * Block '<Root>/Scope52' : Unused code path elimination
 * Block '<Root>/Scope53' : Unused code path elimination
 * Block '<Root>/Scope54' : Unused code path elimination
 * Block '<Root>/Scope55' : Unused code path elimination
 * Block '<Root>/Scope56' : Unused code path elimination
 * Block '<Root>/Scope57' : Unused code path elimination
 * Block '<Root>/Scope58' : Unused code path elimination
 * Block '<Root>/Scope59' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope60' : Unused code path elimination
 * Block '<Root>/Scope61' : Unused code path elimination
 * Block '<Root>/Scope62' : Unused code path elimination
 * Block '<Root>/Scope63' : Unused code path elimination
 * Block '<Root>/Scope64' : Unused code path elimination
 * Block '<Root>/Scope65' : Unused code path elimination
 * Block '<Root>/Scope66' : Unused code path elimination
 * Block '<Root>/Scope67' : Unused code path elimination
 * Block '<Root>/Scope68' : Unused code path elimination
 * Block '<Root>/Scope69' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope70' : Unused code path elimination
 * Block '<Root>/Scope71' : Unused code path elimination
 * Block '<Root>/Scope72' : Unused code path elimination
 * Block '<Root>/Scope73' : Unused code path elimination
 * Block '<Root>/Scope74' : Unused code path elimination
 * Block '<Root>/Scope75' : Unused code path elimination
 * Block '<Root>/Scope76' : Unused code path elimination
 * Block '<Root>/Scope77' : Unused code path elimination
 * Block '<Root>/Scope78' : Unused code path elimination
 * Block '<Root>/Scope79' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope80' : Unused code path elimination
 * Block '<Root>/Scope81' : Unused code path elimination
 * Block '<Root>/Scope82' : Unused code path elimination
 * Block '<Root>/Scope83' : Unused code path elimination
 * Block '<Root>/Scope84' : Unused code path elimination
 * Block '<Root>/Scope85' : Unused code path elimination
 * Block '<Root>/Scope86' : Unused code path elimination
 * Block '<Root>/Scope87' : Unused code path elimination
 * Block '<Root>/Scope88' : Unused code path elimination
 * Block '<Root>/Scope89' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<Root>/Scope90' : Unused code path elimination
 * Block '<Root>/Scope91' : Unused code path elimination
 * Block '<Root>/Scope92' : Unused code path elimination
 * Block '<Root>/Scope93' : Unused code path elimination
 * Block '<Root>/Scope94' : Unused code path elimination
 * Block '<Root>/Scope95' : Unused code path elimination
 * Block '<Root>/Scope96' : Unused code path elimination
 * Block '<Root>/Scope97' : Unused code path elimination
 * Block '<Root>/Scope98' : Unused code path elimination
 * Block '<Root>/Scope99' : Unused code path elimination
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S77>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S116>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion4' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CrCtl'
 * '<S1>'   : 'CrCtl/CCVSCrCtlState'
 * '<S2>'   : 'CrCtl/CrCtl_Mode'
 * '<S3>'   : 'CrCtl/CrCtl_ShOff'
 * '<S4>'   : 'CrCtl/CrCtl_State'
 * '<S5>'   : 'CrCtl/MFLv'
 * '<S6>'   : 'CrCtl/TSC1Adres'
 * '<S7>'   : 'CrCtl/vhcIn'
 * '<S8>'   : 'CrCtl/CCVSCrCtlState/Chart'
 * '<S9>'   : 'CrCtl/CrCtl_Mode/CrCtl_Mode_Case1'
 * '<S10>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_Case2'
 * '<S11>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd'
 * '<S12>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_MFLvRqstMnplt'
 * '<S13>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds'
 * '<S14>'  : 'CrCtl/CrCtl_Mode/trigSusp'
 * '<S15>'  : 'CrCtl/CrCtl_Mode/whthEntPCC'
 * '<S16>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/Bistable'
 * '<S17>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge'
 * '<S18>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/Subsystem'
 * '<S19>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/Bistable/Model'
 * '<S20>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/Bistable/Model/RESET Priority'
 * '<S21>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/Bistable/Model/SET  Priority'
 * '<S22>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge/Chart'
 * '<S23>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge/Switch Case Action Subsystem'
 * '<S24>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge/Switch Case Action Subsystem1'
 * '<S25>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S26>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_CdtnsFwd/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S27>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvAcc'
 * '<S28>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvDecl'
 * '<S29>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvNeutr'
 * '<S30>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvPCC'
 * '<S31>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvRes'
 * '<S32>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvSet'
 * '<S33>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvTipDwn'
 * '<S34>'  : 'CrCtl/CrCtl_Mode/CrCtl_Mode_SwtMds/CrCtl_Mode_SwtMds_MFLvTipUp'
 * '<S35>'  : 'CrCtl/CrCtl_Mode/trigSusp/Subsystem'
 * '<S36>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns'
 * '<S37>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn'
 * '<S38>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_modeSelect'
 * '<S39>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_modeSelect2'
 * '<S40>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_1'
 * '<S41>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2'
 * '<S42>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3'
 * '<S43>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4'
 * '<S44>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_5'
 * '<S45>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6'
 * '<S46>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_1/Chart'
 * '<S47>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_1/Subsystem'
 * '<S48>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Bistable'
 * '<S49>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge'
 * '<S50>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1'
 * '<S51>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Extract Bits'
 * '<S52>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1'
 * '<S53>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2'
 * '<S54>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Bistable/Model'
 * '<S55>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Bistable/Model/RESET Priority'
 * '<S56>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Bistable/Model/SET  Priority'
 * '<S57>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge/Chart'
 * '<S58>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge/Switch Case Action Subsystem'
 * '<S59>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge/Switch Case Action Subsystem1'
 * '<S60>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S61>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S62>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1/Chart'
 * '<S63>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1/Switch Case Action Subsystem'
 * '<S64>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1/Switch Case Action Subsystem1'
 * '<S65>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S66>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/DelayRisingEdge1/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S67>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1/Chart'
 * '<S68>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1/Switch Case Action Subsystem'
 * '<S69>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1/Switch Case Action Subsystem1'
 * '<S70>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S71>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S72>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2/Chart'
 * '<S73>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2/Switch Case Action Subsystem'
 * '<S74>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2/Switch Case Action Subsystem1'
 * '<S75>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S76>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_2/Subsystem2/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S77>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Extract Bits'
 * '<S78>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1'
 * '<S79>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1/Chart'
 * '<S80>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1/Switch Case Action Subsystem'
 * '<S81>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1/Switch Case Action Subsystem1'
 * '<S82>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S83>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_3/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S84>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge'
 * '<S85>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1'
 * '<S86>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge/Chart'
 * '<S87>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge/Switch Case Action Subsystem'
 * '<S88>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge/Switch Case Action Subsystem1'
 * '<S89>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S90>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/DelayRisingEdge/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S91>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1/Chart'
 * '<S92>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1/Switch Case Action Subsystem'
 * '<S93>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1/Switch Case Action Subsystem1'
 * '<S94>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S95>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_4/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S96>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits'
 * '<S97>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits1'
 * '<S98>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits2'
 * '<S99>'  : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits3'
 * '<S100>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits4'
 * '<S101>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits5'
 * '<S102>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Extract Bits6'
 * '<S103>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1'
 * '<S104>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2'
 * '<S105>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1/Chart'
 * '<S106>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1/Switch Case Action Subsystem'
 * '<S107>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1/Switch Case Action Subsystem1'
 * '<S108>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S109>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem1/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S110>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2/Chart'
 * '<S111>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2/Switch Case Action Subsystem'
 * '<S112>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2/Switch Case Action Subsystem1'
 * '<S113>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2/Switch Case Action Subsystem1/If Action Subsystem'
 * '<S114>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Cdtns/CrCtlShOff_Cdtns_6/Subsystem2/Switch Case Action Subsystem1/If Action Subsystem1'
 * '<S115>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn/Clock'
 * '<S116>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn/Extract Bits3'
 * '<S117>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn/Timer'
 * '<S118>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn/fallingEdge'
 * '<S119>' : 'CrCtl/CrCtl_ShOff/CrCtlShOff_Reactvtn/Clock/Chart'
 * '<S120>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc'
 * '<S121>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl'
 * '<S122>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold'
 * '<S123>' : 'CrCtl/CrCtl_State/CrCtl_State_Neutr'
 * '<S124>' : 'CrCtl/CrCtl_State/CrCtl_State_Off'
 * '<S125>' : 'CrCtl/CrCtl_State/CrCtl_State_PCC'
 * '<S126>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv'
 * '<S127>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw'
 * '<S128>' : 'CrCtl/CrCtl_State/CrCtl_State_TipDwn'
 * '<S129>' : 'CrCtl/CrCtl_State/CrCtl_State_TipUp'
 * '<S130>' : 'CrCtl/CrCtl_State/Subsystem'
 * '<S131>' : 'CrCtl/CrCtl_State/Subsystem1'
 * '<S132>' : 'CrCtl/CrCtl_State/Subsystem3'
 * '<S133>' : 'CrCtl/CrCtl_State/Subsystem4'
 * '<S134>' : 'CrCtl/CrCtl_State/enPCC'
 * '<S135>' : 'CrCtl/CrCtl_State/spdGov'
 * '<S136>' : 'CrCtl/CrCtl_State/spdGov1'
 * '<S137>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubPrepHold'
 * '<S138>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp'
 * '<S139>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmpEnd'
 * '<S140>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubStrtVal'
 * '<S141>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubWaitRes'
 * '<S142>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PIGovernor1'
 * '<S143>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PISelector1'
 * '<S144>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/Saturation Dynamic'
 * '<S145>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PIGovernor1/PID Controller'
 * '<S146>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PIGovernor1/PID Controller1'
 * '<S147>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PIGovernor1/Saturation Dynamic'
 * '<S148>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmp/PIGovernor1/Saturation Dynamic1'
 * '<S149>' : 'CrCtl/CrCtl_State/CrCtl_State_Acc/CrCtl_State_Acc_SubRmpEnd/Saturation Dynamic'
 * '<S150>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp'
 * '<S151>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmpEnd'
 * '<S152>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmpHold'
 * '<S153>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubSetEnd'
 * '<S154>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubStrtVal'
 * '<S155>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PIGovernor'
 * '<S156>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PISelector'
 * '<S157>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/Saturation Dynamic'
 * '<S158>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PIGovernor/PID Controller'
 * '<S159>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PIGovernor/PID Controller1'
 * '<S160>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PIGovernor/Saturation Dynamic'
 * '<S161>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmp/PIGovernor/Saturation Dynamic1'
 * '<S162>' : 'CrCtl/CrCtl_State/CrCtl_State_Decl/CrCtl_State_Decl_SubRmpEnd/Saturation Dynamic'
 * '<S163>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr'
 * '<S164>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubStrtVal'
 * '<S165>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PIGovernor'
 * '<S166>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PISelector'
 * '<S167>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/Saturation Dynamic'
 * '<S168>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PIGovernor/PID Controller'
 * '<S169>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PIGovernor/PID Controller1'
 * '<S170>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PIGovernor/Saturation Dynamic'
 * '<S171>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubGvnr/PIGovernor/Saturation Dynamic1'
 * '<S172>' : 'CrCtl/CrCtl_State/CrCtl_State_Hold/CrCtl_State_Hold_SubStrtVal/Saturation Dynamic'
 * '<S173>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_Cut'
 * '<S174>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpOne'
 * '<S175>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpTwo'
 * '<S176>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpOne/CrCtl_State_Off_RmpOne_SubRmp'
 * '<S177>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpOne/CrCtl_State_Off_RmpOne_SubStrtVal'
 * '<S178>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpTwo/CrCtl_State_Off_RmpTwo_SubRmp'
 * '<S179>' : 'CrCtl/CrCtl_State/CrCtl_State_Off/CrCtl_State_Off_RmpTwo/CrCtl_State_Off_RmpTwo_SubStrtVal'
 * '<S180>' : 'CrCtl/CrCtl_State/CrCtl_State_PCC/CrCtl_State_PCC_Hold'
 * '<S181>' : 'CrCtl/CrCtl_State/CrCtl_State_PCC/CrCtl_State_PCC_SubRmp'
 * '<S182>' : 'CrCtl/CrCtl_State/CrCtl_State_PCC/CrCtl_State_PCC_SubStrtVal'
 * '<S183>' : 'CrCtl/CrCtl_State/CrCtl_State_PCC/CrCtl_State_PCC_SubRmp/Saturation Dynamic1'
 * '<S184>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp'
 * '<S185>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubStrtVal'
 * '<S186>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PIGovernor'
 * '<S187>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PISelector'
 * '<S188>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/Saturation Dynamic'
 * '<S189>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PIGovernor/PID Controller'
 * '<S190>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PIGovernor/PID Controller1'
 * '<S191>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PIGovernor/Saturation Dynamic'
 * '<S192>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubRmp/PIGovernor/Saturation Dynamic1'
 * '<S193>' : 'CrCtl/CrCtl_State/CrCtl_State_ResAbv/CrCtl_State_ResAbv_SubStrtVal/Saturation Dynamic'
 * '<S194>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold'
 * '<S195>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp'
 * '<S196>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubStrtVal'
 * '<S197>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PIGovernor'
 * '<S198>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PISelector'
 * '<S199>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PIGovernor/PID Controller'
 * '<S200>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PIGovernor/PID Controller1'
 * '<S201>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PIGovernor/Saturation Dynamic'
 * '<S202>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubPrepHold/PIGovernor/Saturation Dynamic1'
 * '<S203>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PIGovernor'
 * '<S204>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PISelector'
 * '<S205>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PIGovernor/PID Controller'
 * '<S206>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PIGovernor/PID Controller1'
 * '<S207>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PIGovernor/Saturation Dynamic'
 * '<S208>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubRmp/PIGovernor/Saturation Dynamic1'
 * '<S209>' : 'CrCtl/CrCtl_State/CrCtl_State_ResBlw/CrCtl_State_ResBlw_SubStrtVal/Saturation Dynamic'
 * '<S210>' : 'CrCtl/CrCtl_State/CrCtl_State_TipDwn/CrCtl_State_TipDwn_SubCalcSet'
 * '<S211>' : 'CrCtl/CrCtl_State/Subsystem3/Switch_CrCtl_trqMin_mp'
 * '<S212>' : 'CrCtl/CrCtl_State/spdGov/PIGovernor'
 * '<S213>' : 'CrCtl/CrCtl_State/spdGov/PISelector'
 * '<S214>' : 'CrCtl/CrCtl_State/spdGov/PISlct'
 * '<S215>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions'
 * '<S216>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1'
 * '<S217>' : 'CrCtl/CrCtl_State/spdGov/PIGovernor/PCtrlr'
 * '<S218>' : 'CrCtl/CrCtl_State/spdGov/PIGovernor/Saturation Dynamic1'
 * '<S219>' : 'CrCtl/CrCtl_State/spdGov/PIGovernor/clampingCircuit'
 * '<S220>' : 'CrCtl/CrCtl_State/spdGov/PIGovernor/clampingCircuit/Dead Zone Dynamic'
 * '<S221>' : 'CrCtl/CrCtl_State/spdGov/PISelector/ACC'
 * '<S222>' : 'CrCtl/CrCtl_State/spdGov/PISelector/CRCTL_RESABV(=5h)'
 * '<S223>' : 'CrCtl/CrCtl_State/spdGov/PISelector/CRCTL_RESBLW(=6h)'
 * '<S224>' : 'CrCtl/CrCtl_State/spdGov/PISelector/DECL'
 * '<S225>' : 'CrCtl/CrCtl_State/spdGov/PISelector/HOLD'
 * '<S226>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Chart1'
 * '<S227>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend'
 * '<S228>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1'
 * '<S229>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp'
 * '<S230>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S231>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S232>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/Chart'
 * '<S233>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/Interaction with vehicle speed limit'
 * '<S234>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/KeepInSuspend'
 * '<S235>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/StepIntoSuspend'
 * '<S236>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/StepOutSuspend'
 * '<S237>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/Subsystem'
 * '<S238>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend/StepOutSuspend/Saturation Dynamic'
 * '<S239>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S240>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S241>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/Chart'
 * '<S242>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/Interaction with vehicle speed limit'
 * '<S243>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/KeepInSuspend'
 * '<S244>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/StepIntoSuspend'
 * '<S245>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/StepOutSuspend'
 * '<S246>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/Subsystem'
 * '<S247>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/Suspend1/StepOutSuspend/Saturation Dynamic'
 * '<S248>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart'
 * '<S249>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDENDRAMP_3h.StepOutSuspend'
 * '<S250>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDENDRAMP_3h.SuspendEndRump'
 * '<S251>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDNOTACTIVE_0h'
 * '<S252>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDRAMPDONE_2h'
 * '<S253>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDSTARTRUMP_1h.SUSPENDSTARTRUMP'
 * '<S254>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDSTARTRUMP_1h.StepIntoSUSPEND'
 * '<S255>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions/manualShiftSusp/manualShiftSuspChart/CRCTL_SUSPENDENDRAMP_3h.StepOutSuspend/Saturation Dynamic'
 * '<S256>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart'
 * '<S257>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend'
 * '<S258>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1'
 * '<S259>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/adrsAMT'
 * '<S260>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.StepOutSuspend'
 * '<S261>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.SuspendEndRump'
 * '<S262>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDNOTACTIVE_0h'
 * '<S263>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDRAMPDONE_2h'
 * '<S264>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDSTARTRUMP_1h.SUSPENDSTARTRUMP'
 * '<S265>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDSTARTRUMP_1h.StepIntoSUSPEND'
 * '<S266>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.StepOutSuspend/Saturation Dynamic1'
 * '<S267>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S268>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S269>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/Chart'
 * '<S270>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/Interaction with vehicle speed limit'
 * '<S271>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/KeepInSuspend'
 * '<S272>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/StepIntoSuspend'
 * '<S273>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/StepOutSuspend'
 * '<S274>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/Subsystem'
 * '<S275>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend/StepOutSuspend/Saturation Dynamic'
 * '<S276>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S277>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S278>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/Chart'
 * '<S279>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/Interaction with vehicle speed limit'
 * '<S280>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/KeepInSuspend'
 * '<S281>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/StepIntoSuspend'
 * '<S282>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/StepOutSuspend'
 * '<S283>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/Subsystem'
 * '<S284>' : 'CrCtl/CrCtl_State/spdGov/trqInterventions1/Suspend1/StepOutSuspend/Saturation Dynamic'
 * '<S285>' : 'CrCtl/CrCtl_State/spdGov1/PIGovernor'
 * '<S286>' : 'CrCtl/CrCtl_State/spdGov1/PISelector'
 * '<S287>' : 'CrCtl/CrCtl_State/spdGov1/PISlct'
 * '<S288>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions'
 * '<S289>' : 'CrCtl/CrCtl_State/spdGov1/PIGovernor/PCtrlr'
 * '<S290>' : 'CrCtl/CrCtl_State/spdGov1/PIGovernor/Saturation Dynamic1'
 * '<S291>' : 'CrCtl/CrCtl_State/spdGov1/PIGovernor/clampingCircuit'
 * '<S292>' : 'CrCtl/CrCtl_State/spdGov1/PIGovernor/clampingCircuit/Dead Zone Dynamic'
 * '<S293>' : 'CrCtl/CrCtl_State/spdGov1/PISelector/ACC'
 * '<S294>' : 'CrCtl/CrCtl_State/spdGov1/PISelector/CRCTL_RESABV(=5h)'
 * '<S295>' : 'CrCtl/CrCtl_State/spdGov1/PISelector/CRCTL_RESBLW(=6h)'
 * '<S296>' : 'CrCtl/CrCtl_State/spdGov1/PISelector/DECL'
 * '<S297>' : 'CrCtl/CrCtl_State/spdGov1/PISelector/HOLD'
 * '<S298>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart'
 * '<S299>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend'
 * '<S300>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1'
 * '<S301>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.StepOutSuspend'
 * '<S302>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.SuspendEndRump'
 * '<S303>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDNOTACTIVE_0x0_1'
 * '<S304>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDRAMPDONE_0x2_1'
 * '<S305>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDSTARTRUMP_0x1_2.SUSPENDSTARTRUMP'
 * '<S306>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDSTARTRUMP_0x1_2.StepIntoSUSPEND'
 * '<S307>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Chart/CRCTL_SUSPENDENDRAMP_0x3_1.StepOutSuspend/Saturation Dynamic1'
 * '<S308>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S309>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S310>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/Chart'
 * '<S311>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/Interaction with vehicle speed limit'
 * '<S312>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/KeepInSuspend'
 * '<S313>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/StepIntoSuspend'
 * '<S314>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/StepOutSuspend'
 * '<S315>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/Subsystem'
 * '<S316>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend/StepOutSuspend/Saturation Dynamic'
 * '<S317>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/CRCTL_SUSPENDENDRAMP(0x3)'
 * '<S318>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/CRCTL_SUSPENDNOTACTIVE(0x0)'
 * '<S319>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/Chart'
 * '<S320>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/Interaction with vehicle speed limit'
 * '<S321>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/KeepInSuspend'
 * '<S322>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/StepIntoSuspend'
 * '<S323>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/StepOutSuspend'
 * '<S324>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/Subsystem'
 * '<S325>' : 'CrCtl/CrCtl_State/spdGov1/trqInterventions/Suspend1/StepOutSuspend/Saturation Dynamic'
 * '<S326>' : 'CrCtl/MFLv/MFLvDtctAndPrs'
 * '<S327>' : 'CrCtl/vhcIn/vhcAdres_Sub'
 * '<S328>' : 'CrCtl/vhcIn/vhcAdres_Sub/Discrete Derivative'
 * '<S329>' : 'CrCtl/vhcIn/vhcAdres_Sub/Mean'
 * '<S330>' : 'CrCtl/vhcIn/vhcAdres_Sub/ig2stGear_weiChaiJH6500HP'
 * '<S331>' : 'CrCtl/vhcIn/vhcAdres_Sub/ig2stGear_xiChaiJH6500HP'
 * '<S332>' : 'CrCtl/vhcIn/vhcAdres_Sub/Mean/Model'
 * '<S333>' : 'CrCtl/vhcIn/vhcAdres_Sub/Mean/Model/Discrete Variable Time Delay'
 */
#endif                                 /* RTW_HEADER_CrCtl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
