#ifndef METERCOM_INPUT_H
#define METERCOM_INPUT_H








//-----------------TCO1------------------
extern unsigned char MeterTCO1_kmphVehSpdUB;
extern unsigned int  MeterTCO1_kmphVehSpd100UW;
extern unsigned int  MeterTCO1_kmphVehSpd256UW;




void Meter2HCU_ValueInit(void);
void Meter2HCU_Update_10ms(void);
void Meter2HCU_TCO1Update(void);




#endif