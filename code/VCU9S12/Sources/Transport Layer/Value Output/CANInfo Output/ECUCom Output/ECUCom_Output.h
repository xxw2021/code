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

extern unsigned char CANTxAllow_stECUCCVSUB;//robin�޸����190710
extern unsigned char CANTxAllow_stECUPCCUB;//robin�޸����190710
extern unsigned char CANTxAllow_stECUTC1UB;//robin�޸����190710




               



extern unsigned char  ECUEBC1_stEngShutDownSWUB;


void CANTxECU_ValueInit(void);

void CANTx2ECU_10ms(void);
void CANTx2Rtdr_50ms(void);//TSC1 RR �ظ�Ť�� �������񷢶��� added by Leo
void CANTx2ECU_100ms(void);
void CANTx2ECUWc_10ms(void);//TSC1 TE ����Ť�� Ϋ�� added by Leo
void CANTx2RtdrWc_50ms(void);//TSC1 VR �ظ�Ť�� ����Ϋ�񷢶��� added by Leo
void CANTx2ECU_50ms(void);


void ECUCAN_InterfaceOut_EBC1Update(void);
void ECUCAN_InterfaceOut_TSC1Update(void);
void ECUCAN_InterfaceOutWc_TSC1Update(void);//Ϋ�񷢶��� added by Leo
void ECUCAN_InterfaceOut_CCVSUpdate(void);//robin�޸����190710
void ECUCAN_InterfaceOut_PCCUpdate(void);//robin�޸����190710
void ECUCAN_InterfaceOut_TC1Update(void);//robin�޸����190710




#endif