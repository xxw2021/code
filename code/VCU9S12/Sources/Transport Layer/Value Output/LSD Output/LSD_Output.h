#ifndef LSD_OUTPUT_H
#define LSD_OUTPUT_H


         


extern unsigned char PwrDrv_stViceStopUB;
extern unsigned char PwrDrv_stViceStartUB;




void LSDOutput_ValueInit(void);

void LSDOutput_Update_10ms(void);

void PwrDrv_ViceStop_Update(void);
void PwrDrv_ViceStart_Update(void);

void PwrDrv_TLE7230Ctrl_Update(void);


#endif