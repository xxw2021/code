#ifndef MC33972_INPUT_H
#define MC33972_INPUT_H



#define MC33972_numTotalChn  22

extern unsigned long MC33972_SWSt;

void MC33972_Update_10ms(void);
void MC33972Input_ValueInit(void);
void MC33972_SWStUpdate(void);
void MC33972_SWStInput(void);
void MC33972_SMUpdate(void);
void MC33972_ChnEnable(void);



#endif