#ifndef SWSEN_ANLY_H
#define SWSEN_ANLY_H







#define SWAnly_ON   1
#define SWAnly_OFF  0



extern unsigned char SWSen_stECOPwrSWUB;

extern unsigned char SWSen_stONSWUB;

void SWSenAnly_ValueInit(void);


void SWSenAnly_Update_10ms(void);



#endif