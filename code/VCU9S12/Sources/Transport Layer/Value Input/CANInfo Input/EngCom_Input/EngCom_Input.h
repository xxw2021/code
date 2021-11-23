#ifndef EngCOM_INPUT_H
#define EngCOM_INPUT_H




//------------------------EEC2--------------------------------
extern unsigned char ECUEEC2_pctAccelPedalPosRAWUB;      //


//------------------------EEC1--------------------------------
extern unsigned char ECUEEC1_stEngTrqMdUB;             //����
extern unsigned char ECUEEC1_pctDrvTrqDmdUB;          //����
extern unsigned char ECUEEC1_pctActualTrqUB;                //����
extern unsigned int  ECUEEC1_rpmEngSpdUW;                 //����
extern unsigned char ECUEEC1_stSourceOFEngCtrlUB;        //����
//------------------------EEC2--------------------------------
extern unsigned char ECUEEC2_swAccelPedalLowIdleSWUB;     //������
extern unsigned char ECUEEC2_swAccelPedalKickDownSWUB;    //������
extern unsigned char ECUEEC2_pctAccelPedalPosRAWUB;
extern unsigned char ECUEEC2_pctEngLoadPctUB;
extern unsigned char ECUEEC2_pctRemoteAccelPedalPosUB;        //������
extern unsigned char ECUEEC2_pctAccelPedal2PosUB;             //Ϊ255������
//------------------------EEC3--------------------------------
extern unsigned char ECUEEC3_pctNomFriTrqPctUB;
//------------------------ET1---------------------------------
extern unsigned char ECUET1_tEngCoolantTempO40UB;
extern unsigned char ECUET1_tEngFuelTempO40UB;
extern unsigned int  ECUET1_tEngOilTempUW;
extern unsigned int  ECUET1_tEngTurboOilTempUW;
extern unsigned char ECUET1_tEngInterCoolerTempO40UB;
//-------------------------LFE------------------------------
extern unsigned int  ECULFE_lphEngFuelRateUW;
extern unsigned int  ECULFE_kmpkgEngInstantFuelEcoUW;
extern unsigned int  ECULFE_kmpkgEngAverageFuelEcoUW;
extern unsigned char ECULFE_pctEngThrottlePosUB;
//----------------------------LFC----------------------------------
extern unsigned char ECULFC_EngTripFuel_41Byte;
extern unsigned char ECULFC_EngTripFuel_42Byte;
extern unsigned char ECULFC_EngTripFuel_43Byte;
extern unsigned char ECULFC_EngTripFuel_44Byte;
extern unsigned long ECULFC_EngTripFuel_4Bytes;
extern unsigned char ECULFC_EngTotalFuel_41Byte;
extern unsigned char ECULFC_EngTotalFuel_42Byte;
extern unsigned char ECULFC_EngTotalFuel_43Byte;
extern unsigned char ECULFC_EngTotalFuel_44Byte;
extern unsigned long ECULFC_EngTotalFuel_4Bytes;
extern unsigned long ECULFC_lEngTotalFuelUL;
extern unsigned int  ECULFC_lEngTotalFuelUW;
extern unsigned long ECULFC_lEngTripFuelUL;
extern unsigned int  ECULFC_lEngTripFuelUW;

//----------------------------ETC1----------------------------------
extern unsigned char  ECUETC1_TransDrivelineEngage;            // ��������������
extern unsigned char  ECUETC1_TorqueConverterLockupEngaged;    // ��ֹҺ���������ֹ����
extern unsigned char  ECUETC1_TransShiftInProcess;             // ������������
extern unsigned char  ECUETC1_TransOutputShaftSpeed;           // �����������ת�� 
extern unsigned char  ECUETC1_PercentClutchSlip;               // ��ϻ����ٷֱ�  
extern unsigned char  ECUETC1_EngMomentaryOverspeedEnabl;      // ������˲�䳬������
extern unsigned char  ECUETC1_ProgressiveShiftDisable;         // ������������
extern unsigned char  ECUETC1_TransInputShaftSpeed;            // ������������ת��
extern unsigned char  ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl; // �����������豸Դ��ַ 
//----------------------------ETC2----------------------------------
extern unsigned char  ECUETC2_TransSelectedGear;                // ������ѡ��λ
extern unsigned char  ECUETC2_TransActualGearRatio;             // ������ʵ�ʴ�����
extern unsigned char  ECUETC2_TransActualGearRatio;             // ������ʵ�ʴ�����
extern unsigned char  ECUETC2_TransCurrentGear;                 // ��������ǰ��λ
extern unsigned char  ECUETC2_TransRqedRange;                   // ����������Χ 
extern unsigned char  ECUETC2_TransRqedRange;                   // ����������Χ  
extern unsigned char  ECUETC2_TransCurrentRange;                // ��������ǰ��Χ
extern unsigned char  ECUETC2_TransCurrentRange;                // ��������ǰ��Χ


//----------------------------CCVS---------------------------------
extern unsigned char ECUCCVS_swTwoSpdAxleSWUB;
extern unsigned char ECUCCVS_swParkingBrakeSWUB;
extern unsigned char ECUCCVS_swCCSPauseSWUB;
extern unsigned int  ECUCCVS_kmphWheelBasedVehSpdIUW;
extern unsigned char ECUCCVS_stCCSActiveUB;
extern unsigned char ECUCCVS_stCCSEnableSWUB;
extern unsigned char ECUCCVS_swBrakeSWUB;
extern unsigned char ECUCCVS_swClutchSWUB;
extern unsigned char ECUCCVS_swCCSSetSWUB;
extern unsigned char ECUCCVS_swCCSCoastSWUB;
extern unsigned char ECUCCVS_swCCSResumeSWUB;
extern unsigned char ECUCCVS_swCCSAccelSWUB;
extern unsigned char ECUCCVS_kmphCCSSetSpdUB;		
extern unsigned char ECUCCVS_stCCSPTOStUB; 		
extern unsigned char ECUCCVS_stCCSCtlStUB;		
extern unsigned char ECUCCVS_swEngIdleIncrementSWUB;
extern unsigned char ECUCCVS_swEngIdleDecrementSWUB;
extern unsigned char ECUCCVS_swEngTestMdSWUB;
extern unsigned char ECUCCVS_swEngShutdownOrSWUB;
//------------------------------AMB----------------------------------
extern unsigned char ECUAMB_pBarometricPressUB;
//------------------------------ERC1--------------------------------
extern unsigned char ECUERC1_pctActualRetarderTrqPctUB;
//EC1
extern unsigned int  ECUEC1_rpmEngSpdAtIdlePoint1UW;                               
extern unsigned char ECUEC1_pctEngPctTrqAtIdlePoint1UB;        
extern unsigned int  ECUEC1_rpmEngSpdAtPoint2UW;                                        
extern unsigned char ECUEC1_pctEngPctTrqAtPoint2UB;            
extern unsigned int  ECUEC1_rpmEngSpdAtPoint3UW;                                       
extern unsigned char ECUEC1_pctEngPctTrqAtPoint3UB;            
extern unsigned int  ECUEC1_rpmEngSpdAtPoint4UW;                                       
extern unsigned char ECUEC1_pctEngPctTrqAtPoint4UB;            
extern unsigned int  ECUEC1_rpmEngSpdAtPoint5UW;                                        
extern unsigned char ECUEC1_pctEngPctTrqAtPoint5UB;            
extern unsigned int  ECUEC1_rpmEngSpdAtHighIdlePoint6UW;                       
extern unsigned int  ECUEC1_numEngGainOfEndSpdGovernorUW;                     
extern unsigned int  ECUEC1_nmEngRefTrqUW;     //�������ο�Ť��ֵ                                 
extern unsigned int  ECUEC1_rpmEngMxMmntaryOverrideSpdPoint7UW;        
extern unsigned char ECUEC1_100msEngMxMomentaryOverrideTimelmtUB;      
extern unsigned char ECUEC1_rpmEngRqedSpdCtrlRangeLowerlmtUB;      
extern unsigned char ECUEC1_rpmEngRqedSpdCtrlRangeUpperlmtUB;      
extern unsigned char ECUEC1_pctEngRqdTrqCtrlRangeLowerlmtUB;      
extern unsigned char ECUEC1_pctEngRqdTrqCtrlRangeUpperlmtUB;      
extern unsigned int  ECUEC1_rpmEngExRngRqdSpdCtrlRngUpperlmtUW;          
extern unsigned int  ECUEC1_EngMomentOfInertiaUW;                                   
extern unsigned int  ECUEC1_nmEngDefaultTrqlmtUW;                             
extern unsigned char ECUEC1_SupportVariableRateTSC1MessageUB;       
extern unsigned char ECUEC1_SupportTSC1CtrlPurpGroup1Of4UB;      
extern unsigned char ECUEC1_SupportTSC1CtrlPurpGroup2Of4UB;      
extern unsigned char ECUEC1_SupportTSC1CtrlPurpGroup3Of4UB;      
extern unsigned char ECUEC1_SupportTSC1CtrlPurpGroup4Of4UB;      
//EC1���ķ����������Ե������ź�����
extern unsigned int ECUEC1_rpmMAPSpdPoint1UW;
extern unsigned int ECUEC1_nmMAPTrqPoint1UW;
extern unsigned int ECUEC1_rpmMAPSpdPoint2UW;
extern unsigned int ECUEC1_nmMAPTrqPoint2UW;
extern unsigned int ECUEC1_rpmMAPSpdPoint3UW;
extern unsigned int ECUEC1_nmMAPTrqPoint3UW;
extern unsigned int ECUEC1_rpmMAPSpdPoint4UW;
extern unsigned int ECUEC1_nmMAPTrqPoint4UW;
extern unsigned int ECUEC1_rpmMAPSpdPoint5UW;
extern unsigned int ECUEC1_nmMAPTrqPoint5UW;
extern unsigned int ECUEC1_rpmMAPSpdPoint6UW;
extern unsigned int ECUEC1_nmMAPTrqPoint6UW;
//ECUEEC1�ϱ��ķ�����Ť�ذٷֱ���Ϣ
extern unsigned int ECUEEC1_nmDriverTrqDemandUW;
extern unsigned int ECUEEC1_nmActualTrqUW;
//EEC3�ϱ�Ħ��Ť�ؽ���
extern unsigned int ECUEEC3_nmNomFriTrqPctUW;
//LFE�������
extern unsigned long ECULFE_50mlphEngRTFuelRateUL;
extern unsigned long ECULFE_mlpkmEngRTFuelRateUL;
extern unsigned int ECULFE_mlphEngRTFuelRateUW;
extern unsigned int ECULFE_lphEngRTFuelRateUW;
extern unsigned int ECULFE_gpkwhEngFuelRateUW;
extern unsigned int VehAnly_lp100kmEngFuelRTRateUW;

extern unsigned long ECUAnly_lp100kmRTVehFuleRatioUW;
extern unsigned long EngAnly_lp100kmRTFuelRatioF; 



void ECU2HCU_ValueInit(void);
void ECU2HCU_RTOutCurveUpdate(void);

void ECU2HCU_Update_10ms(void);
void ECU2HCU_EC1Update(void);
void ECU2HCU_EEC1Update(void);
void ECU2HCU_EEC2Update(void);
void ECU2HCU_EEC3Update(void);
void ECU2HCU_ET1Update(void);
void ECU2HCU_LFCUpdate(void);
void ECU2HCU_LFEUpdate(void);
void ECU2HCU_CCVSUpdate(void);
void ECU2HCU_AMBUpdate(void);
void ECU2HCU_ERC1Update(void);


void ECU2HCU_ETC2Update(void);//robin add 190715

void ECU2HCU_ETC1Update(void);//robin add 190712


#endif