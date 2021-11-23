#ifndef ALLH_H
#define ALLH_H
              
  

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xep100.h> 

          
          

#include "TypeDefine.h"

#include "String.h"         


//-----------------------------------------------
//硬件部分初始化
//
//
//-----------------------------------------------
#include "Hardware_Init.h"
#include "Value_Init.h"
#include "AD_Init.h"
#include "CAN_Init.h"
#include "ECT_Init.h"
#include "GPIO_Init.h"
#include "MCU_Init.h"
#include "PIT_Init.h"
#include "PIT_Func.h"
#include "PWM_Init.h"
#include "SPI_Init.h"
#include "TLE7230_Init.h"
#include "MC33972_Init.h"

// chxd add 2019-02-20
#include "S32K144_Init.h"
#include "BTNCom_Output.h"
#include "PCC_Instruction.h"







//CAN配置问题
#include "CANCom_Config.h"
#include "CAN0_Func.h"
#include "CAN1_Func.h"
#include "CAN4_Func.h"




//部件输入的操作
#include "SWSen_Input.h"
#include "SWChn_Input.h"
#include "MC33972_Input.h"
#include "AnaSen_Input.h"
#include "Value_Input.h"
#include "CANInfo_Input.h"
#include "EngCom_Input.h"
#include "ABSCom_Input.h"
#include "MeterCom_Input.h"


 


//部件输出的操作
#include "Value_Output.h"
#include "BTS724_Ctrl.h"
#include "TLE7230_Ctrl.h"
#include "HSD_Output.h"
#include "LSD_Output.h"
#include "CANInfo_Output.h"
#include "ECUCom_Output.h"




//标定变量的操作
#include "ccp.h"
#include "CCPPAR.h"
#include "CCP_Interface.h" 

//进行部件分析操作
#include "SWSen_Anly.h"
#include "AnaSen_Anly.h"
#include "Engine_Anly.h"
#include "Vehicle_Anly.h"
#include "Transmission_Anly.h"
#include "SubSystem_Anly.h"




//策略相关内容

//数据管理
#include "VCUST_DataMng.h"

//整车策略
#include "StepConnect.h"

#include "VCUST_DataMng.h"


#include "VCU_Strategy.h"


//安全策略


/*

//--------------------------------------------------
//传输层    
//
//--------------------------------------------------
#include "CANCom_Config.h"
#include "CAN0_Func.h"
#include "CAN1_Func.h"
#include "CAN4_Func.h"
#include "ccp.h"
#include "CCPPAR.h"
#include "CCP_Interface.h"                 
#include "Value_Input.h"
#include "AnaSen_Input.h"
#include "CANInfo_Input.h"
#include "EngCom_Input.h"
#include "MCUCom_Input.h"
#include "BMSCom_Input.h"           
#include "HVCUCom_Input.h"
#include "MeterCom_Input.h"
                 
#include "SWSen_Input.h"
#include "SPIInfo_Input.h"

#include "Value_Output.h"                                  
#include "BTS724Ctl.h"
#include "VehRlyCtl.h"                                          
              
#include "CANInfo_Output.h"
#include "MCUCom_Output.h"                 
#include "ECUCom_Output.h"
#include "MeterCom_Output.h"
#include "HVCUCom_Output.h"
                                                            
#include "TLE7230Ctl.h"
#include "ViceSSCtrl.h"

//执行层    Subsystem Anly
#include "SubSysAnly.h"
#include "EngAnly.h"
#include "SWSenAnly.h"
#include "AnaSenAnly.h"
#include "MtrAnly.h"
#include "BMSAnly.h"
#include "VehAnly.h"
#include "HVCUAnly.h"
#include "HCUAnly.h"
#include "TransAnly.h"
#include "CplAnly.h"
#include "EDSAnly.h"


//应用层
#include "Timer_Func.h"
#include "Safety_Strategy.h"


#include "HybridST_GenFunc.h"

#include "SubSysConnect.h"

#include "HYBST.h"

*/                              

#include "CrCtl.h"


#endif
