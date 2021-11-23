#include "Allh.h"




unsigned char MeterTCO1_kmphVehSpdUB;
unsigned int  MeterTCO1_kmphVehSpd100UW;
unsigned int  MeterTCO1_kmphVehSpd256UW;




//
void Meter2HCU_ValueInit(void)//
{
  //
  MeterTCO1_kmphVehSpdUB = 0;
  MeterTCO1_kmphVehSpd100UW = 0; 
}//




void Meter2HCU_Update_10ms(void)//
{
  //
  Meter2HCU_TCO1Update();
}//



void Meter2HCU_TCO1Update(void)//
{
  //
  unsigned long temp_VehSpd;
  unsigned long temp_VehSpd256;
  unsigned long temp_VehSpd25600;
  unsigned long temp_VehSpd100;
  
  
  CANTimeout_numMeterTimerUW ++;
  if((CANTimeout_numMeterTimerUW > CANTimeout_numMeterTimeUWC))//
  {
    //
    CANTimeout_stMeterUB = 1;
  }//
  else//
  {
    //
    CANTimeout_stMeterUB  = 0;
  }//
  
  if(CANInputUpdt_stMeterTCO11UB == 1)//
  {
    //
    CANTimeout_numMeterTimerUW = 0;

    temp_VehSpd25600 = (unsigned long)Btm_MeterTCO1_TachographVehSpd_LByte*(unsigned long)100 + (unsigned long)Btm_MeterTCO1_TachographVehSpd_HByte * (unsigned long)25600;   
    
    temp_VehSpd256 = temp_VehSpd25600 / 100;
    
    temp_VehSpd100 = temp_VehSpd25600 / 256;
    
    temp_VehSpd = temp_VehSpd256/256;
    
    MeterTCO1_kmphVehSpd256UW = (unsigned int)temp_VehSpd256;
    
    MeterTCO1_kmphVehSpd100UW = (unsigned int)temp_VehSpd100;

    MeterTCO1_kmphVehSpdUB = (unsigned char)temp_VehSpd;
    
    CANInputUpdt_stMeterTCO11UB = 0;
  }//
  
  if(CANInputUpdt_stMeterTCO12UB == 1)//
  {
    //
    CANTimeout_numMeterTimerUW = 0;
    
    temp_VehSpd25600 = (unsigned long)Btm_MeterTCO1_TachographVehSpd_LByte*(unsigned long)100 + (unsigned long)Btm_MeterTCO1_TachographVehSpd_HByte * (unsigned long)25600;
    
    temp_VehSpd256 = temp_VehSpd25600 / 100;
    
    temp_VehSpd100 = temp_VehSpd25600 / 256;
    
    temp_VehSpd = temp_VehSpd256/256;
    
    MeterTCO1_kmphVehSpd256UW = (unsigned int)temp_VehSpd256;
    
    MeterTCO1_kmphVehSpd100UW = (unsigned int)temp_VehSpd100;

    MeterTCO1_kmphVehSpdUB = (unsigned char)temp_VehSpd;
    
    CANInputUpdt_stMeterTCO12UB = 0;
  }//  
}//
