#ifndef ECUCOM_OUTPUT_H
#define ECUCOM_OUTPUT_H






extern unsigned char  ECUTSC1_stEngOverrideCtrlMdUB;
extern unsigned int   ECUTSC1_rpmSpdDmdLmtUW;
extern unsigned char  ECUTSC1_pctTrqDmdLmtUB;
extern signed char    ECUTSC1_pctTrqDmdLmtSB; //added by Leo

extern unsigned char EngTsk_numSpdTrqlmtUB;

extern unsigned char  ECUEBC1_stEngShutDownSWUB;


extern unsigned char CANTxAllow_stECUTSC1UB;
extern unsigned char CANTxAllow_stRtdrTSC1UB; //added by Leo
extern unsigned char CANTxAllow_stECUEBC1UB;

extern unsigned char CANTxAllow_stECUCCVSUB;//robin修改添加190710
extern unsigned char CANTxAllow_stECUPCCUB;//robin修改添加190710
extern unsigned char CANTxAllow_stECUTC1UB;//robin修改添加190710




               



extern unsigned char  ECUEBC1_stEngShutDownSWUB;


void CANTxECU_ValueInit(void);

void CANTx2ECU_10ms(void);
void CANTx2Rtdr_50ms(void);//TSC1 RR 控负扭矩 用于锡柴发动机 added by Leo
void CANTx2ECU_100ms(void);
void CANTx2ECUWc_10ms(void);//TSC1 TE 控正扭矩 潍柴 added by Leo
void CANTx2RtdrWc_50ms(void);//TSC1 VR 控负扭矩 用于潍柴发动机 added by Leo
void CANTx2ECU_50ms(void);


void ECUCAN_InterfaceOut_EBC1Update(void);
void ECUCAN_InterfaceOut_TSC1Update(void);
void ECUCAN_InterfaceOutWc_TSC1Update(void);//潍柴发动机 added by Leo
void ECUCAN_InterfaceOut_CCVSUpdate(void);//robin修改添加190710
void ECUCAN_InterfaceOut_PCCUpdate(void);//robin修改添加190710
void ECUCAN_InterfaceOut_TC1Update(void);//robin修改添加190710




#endif