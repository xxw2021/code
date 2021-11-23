#ifndef VehRlyCTL_H
#define VehRlyCTL_H



extern unsigned char RlyTsk_stEDSPwrOnUB;
extern unsigned char RlyTsk_stStartSWChangeOverRlyUB;
extern unsigned char RlyTsk_stHCUMainPwrRlyUB;
extern unsigned char RlyTsk_stACFanRlyUB;
extern unsigned char RlyTsk_stDCDCEnableUB;


extern unsigned char RlyTsk_stBMSPwrONUB;
extern unsigned char RlyTsk_stATSPwrONUB;


void VehRlyCtl_ValueInit(void);
void VehRlyCtl_Update_20ms(void);

void VehRlyCtl_ValueInit(void);


void VehRlyCtl_HCUMainPwrRlyCtl(void); 
void VehRlyCtl_ACFanRlyCtl(void); 
void VehRlyCtl_StartSWChangeOverRlyCtl(void);
void VehRlyCtl_EDSPwrONCtl(void);

void VehRlyCtl_DCDCEnableCtrl(void);




//RlyTsk_stBMSPwrONUB     H111Òý½Å    Y/W
void VehRlyCtl_BMSPwrONCtrl(void);
//RlyTsk_stATSPwrONUB      //H112Òý½Å  R/BL
void VehRlyCtl_ATSPwrONCtrl(void);


#endif