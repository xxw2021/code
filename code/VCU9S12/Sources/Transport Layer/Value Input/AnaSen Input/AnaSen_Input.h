#ifndef ANASEN_INPUT_H
#define ANASEN_INPUT_H




#define AD_numTotalCh    16
#define AD_Smoothing     4



extern unsigned int PINRAW_AD[AD_numTotalCh];
extern unsigned char ADBUFtemp_Ch[AD_numTotalCh];
extern unsigned int ADSmoothing_ADD[AD_numTotalCh];
extern unsigned int ADBUF_CH1[AD_numTotalCh][AD_Smoothing];
extern unsigned char _Btm_ADChn_Enable[AD_numTotalCh];
extern unsigned int _Btm_ADAverageUW[AD_numTotalCh];



void ADCh_ValueInit(void);
void ADCh_Update_10ms(void);
void ADSen_ChConfig(void);


#endif