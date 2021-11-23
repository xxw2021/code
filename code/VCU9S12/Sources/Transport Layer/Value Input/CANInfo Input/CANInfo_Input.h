#ifndef CANINFO_INPUT_H
#define CANINFO_INPUT_H





extern unsigned int CANInput_numCfmTimeUW;
extern unsigned int CANInput_numUnCfmTimeUW;

extern unsigned char CANTimeout_stECUUB;     
extern unsigned char CANTimeout_stMeterUB;   
 
extern unsigned int CANTimeout_numMeterTimerUW;
extern unsigned int CANTimeout_numMeterTimeUWC;

extern unsigned int CANTimeout_numECUTimerUW;
extern unsigned int CANTimeout_numECUTimeUWC;




extern unsigned char CANInputUpdt_stECUAMBUB;
extern unsigned char CANInputUpdt_stECUCCVSUB;

extern unsigned char CANInputUpdt_stECUETC1UB;//robin add 190715
extern unsigned char CANInputUpdt_stECUETC2UB;//robin add 190715


extern unsigned char CANInputUpdt_stECUEEC1UB;
extern unsigned char CANInputUpdt_stECUEEC2UB;
extern unsigned char CANInputUpdt_stECUEEC3UB;
extern unsigned char CANInputUpdt_stECUERC1UB;
extern unsigned char CANInputUpdt_stECUET1UB;
extern unsigned char CANInputUpdt_stECULFCUB;
extern unsigned char CANInputUpdt_stECULFEUB;
extern unsigned char CANInputUpdt_stECUEC1UB;


extern unsigned char CANInputUpdt_stMeterTCO11UB;
extern unsigned char CANInputUpdt_stMeterTCO12UB;



void CANInfoInput_ValueInit(void);




void CANInfo_InputUpdate_10ms(void);

void CANInfo_InputUpdate_20ms(void);

void CANInfo_InputUpdate_50ms(void);

void CANInfo_InputUpdate_100ms(void);

void CANInfo_InputUpdate_1000ms(void);






#endif