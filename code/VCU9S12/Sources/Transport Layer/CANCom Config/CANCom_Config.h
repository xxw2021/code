#ifndef CANCOM_CONFIG_H
#define CANCOM_CONFIG_H

extern unsigned long CANIDBuf_FromCANID(unsigned long RAW_CANID);
extern unsigned long CANID2CANIDBuff(unsigned long Raw_CANID);


extern unsigned char CANTxAllow_stECUTSC1UB;
extern unsigned char CANTxAllow_stECUEBC1UB;
extern unsigned char CANTxErr_stECUTSC1UB;
extern unsigned char CANTxErr_stECUEBC1UB;
extern unsigned char CANTxAllow_stTBoxUB;
extern unsigned char CANTxErr_stTboxUB; 


//robin add 190711
extern unsigned char CANTxErr_stECUCCVSUB;
extern unsigned char CANTxErr_stECUPCCUB;
extern unsigned char CANTxErr_stECUTC1UB;



void CANCom_Config(void);



#endif