#ifndef  CAN0_FUNC_H_
#define  CAN0_FUNC_H_








//+++++++++++++++++++++++++++++++++           ++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++ECU通讯协议++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++           ++++++++++++++++++++++++++++++++++++
//-----------------------------------EEC1-----------------------------------------
//Electronic Eng Ctrller 1
//报文ID:0xcf004
//寄存器ID:
//发送方式：周期发送
//长度:8Byte
//Byte1:EngTrqMd                       Bit0~3
//      发动机扭矩控制模式
//Byte2:Driver Demand Eng Pct Trq    Bit0~7
//      驾驶员需求的扭矩百分比
//Byte3:Actual Eng Pct Trq           Bit0~7
//      实际发动机扭矩百分比
//Byte4~5:EngSpd                          Bit0~7
//      发动机转速
//Byte6:Sourse Address of Ctrlling Device for Eng Ctrl      Bit0~7
//      发动机控制设备的源地址
//Byte7~8:预留
//---------------------------------------------------------------------------------

 typedef union {
    byte Byte;
    struct {
      byte data0         :4;
      byte data1         :4;
                                       
    } Bits;
}Str_Can_RxData_EEC1;

extern volatile Str_Can_RxData_EEC1             RxCANBuf_EEC1[8];

#define Btm_ECUEEC1_EngTrqMd_4Bits   RxCANBuf_EEC1[0].Bits.data0    // EngTrqMd
#define Btm_ECUEEC1_DriverTrq_Byte     RxCANBuf_EEC1[1].Byte          // Driver Demand Eng Pct Trq
#define Btm_ECUEEC1_ActualTrq_Byte     RxCANBuf_EEC1[2].Byte          // Actual Eng Pct Trq
#define Btm_ECUEEC1_EngSpd_LByte        RxCANBuf_EEC1[3].Byte          // EngSpd
#define Btm_ECUEEC1_EngSpd_HByte        RxCANBuf_EEC1[4].Byte          // EngSpd
#define Btm_ECUEEC1_SAofEngCtl_Byte       RxCANBuf_EEC1[5].Byte          // Sourse Address of Ctrlling Device for Eng Ctrl


//-----------------------------------EEC2-----------------------------------------
//Electronic Eng Ctrller 2
//报文ID:0xcf003
//寄存器ID:
//发送方式：周期发送  50ms
//长度:8Byte
//Byte1:Accel Pedal1 Low Idle SW   Bit0-1
//      怠速开关
//      AccelPedal Kick down SW    Bit2-3
//      加速踏板Kick down开关
//      Road Spd lmt Status        Bit4-5
//      限速状态
//      Accel Pedal2 Low Idle SW   Bit6-7
//      加速踏板2怠速开关
//Byte2:Accel Pedal Pos1               Bit0~7
//      加速踏板位置1
//Byte3:Eng Pct Load At Current Spd   Bit0~7
//      发动机当前转速下的负载百分比       
//Byte4:Remote Accel Pedal Pos              Bit0~7
//      远程加速油门踏板位置
//Byte5:Accel Pedal2 Pos2                   Bit0~7
//      油门踏板2行程信号
//Byte6~8:预留
//---------------------------------------------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_EEC2;

extern volatile Str_Can_RxData_EEC2     RxCANBuf_EEC2[8];

#define  Btm_ECUEEC2_AccelPedalLowIdleSW_2Bits     RxCANBuf_EEC2[0].Bits.data0    // Accel Pedal1 Low Idle SW
#define  Btm_ECUEEC2_AccelPedalKickDownSW_2Bits    RxCANBuf_EEC2[0].Bits.data1    // AccelPedal Kick down SW
#define  Btm_ECUEEC2_AccelPedal1Pos_Byte           RxCANBuf_EEC2[1].Byte          // Accel Pedal Pos1
#define  Btm_ECUEEC2_EngLoadPct_Byte           RxCANBuf_EEC2[2].Byte          // Eng Pct Load At Current Spd
#define  Btm_ECUEEC2_RemoteAccelPedalPos_Byte      RxCANBuf_EEC2[3].Byte          // Remote Accel Pedal Pos
#define  Btm_ECUEEC2_AccelPedal2Pos_Byte           RxCANBuf_EEC2[4].Byte          // Accel Pedal2 Pos2 




//-----------------------------------EEC3-----------------------------------------
//Electronic Eng Ctrller 3
//报文ID:0xfedf
//寄存器ID:
//发送方式：周期发送  250ms
//长度:8Byte
//Byte1: Nominal Friction Pct Trq   Bit0-7
//       名义摩擦扭矩百分比
//Byte2~8:预留
//--------------------------------------------------------------------------------

 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_EEC3;

extern volatile Str_Can_RxData_EEC3     RxCANBuf_EEC3[8];

#define Btm_ECUEEC3_NomFriTrqPct_Byte    RxCANBuf_EEC3[0].Byte   //Nominal Friction Pct Trq



//-----------------------------------ET1-----------------------------------------
//Eng Temperature 1
//报文ID:0xfeee
//寄存器ID:
//发送方式：周期发送  1000ms
//长度:8Byte
//Byte1: Eng Coolant Temp                    Bit0~7
//       发动机冷却剂温度
//Byte2: Eng Fuel Temp                       Bit0~7
//       发动机燃油温度
//Byte3~4: Eng Oil Temp                      Bit0~7
//       发动机机油温度
//Byte5~6: Eng Turbo Oil Temp                Bit0~7
//       发动机涡轮增压器油温
//Byte7: Eng Inter cooler Temp               Bit0~7
//       发动机中冷器温度
//Byte8: Eng Inter cooler Thermostat Opening Bit0~7
//
//--------------------------------------------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :1;
      byte data1         :1;
      byte data2         :1;                                                                              
      byte data3         :1;
      byte data4         :1;                                        
      byte data5         :1;                                       
      byte data6         :1;                                        
      byte data7         :1;                                       
    } Bits;
}Str_Can_RxData_ET1;

extern volatile  Str_Can_RxData_ET1     RxCANBuf_ET1[8];

#define Btm_ECUET1_EngCoolantTemp_Byte      RxCANBuf_ET1[0].Byte    // Eng Coolant Temp
#define Btm_ECUET1_EngFuelTemp_Byte         RxCANBuf_ET1[1].Byte    // Eng Fuel Temp
#define Btm_ECUET1_EngOilTemp_LByte         RxCANBuf_ET1[2].Byte    // Eng Oil Temp
#define Btm_ECUET1_EngOilTemp_HByte         RxCANBuf_ET1[3].Byte    // Eng Oil Temp
#define Btm_ECUET1_EngTurboOilTemp_LByte    RxCANBuf_ET1[4].Byte    // Eng Turbo Oil Temp
#define Btm_ECUET1_EngTorboOilTemp_HByte    RxCANBuf_ET1[5].Byte    // Eng Turbo Oil Temp
#define Btm_ECUET1_EngInterCoolerTemp_Byte  RxCANBuf_ET1[6].Byte    // Eng Inter cooler Temp


//-----------------------------------LFE-----------------------------------------
//Fuel Economy燃油经济性报文
//报文ID:0xfef2
//寄存器ID:
//发送方式：周期发送  100ms
//长度:8Byte
//Byte1-2: Eng Fuel Rate                           Bit0~7
//         发动机燃油喷射率
//Byte3-4: Eng Instantaneous Fuel Economy             Bit0~7
//         当前车速下的燃油经济性
//Byte5-6:Eng Average Fuel Economy                    Bit0~7
//        发动机一段时间内平均燃油经济性
//Byte7:  Eng Throttle Pos                            Bit0~7
//        节气门位置                                  
//Byte8:  Eng Throttle2 Pos                           Bit0~7
//        节气门位置
//--------------------------------------------------------------------------------

typedef union {
    byte Byte;
    struct {
      byte data0         :1;
      byte data1         :1;
      byte data2         :1;                                                                              
      byte data3         :1;
      byte data4         :1;                                        
      byte data5         :1;                                       
      byte data6         :1;                                        
      byte data7         :1;                                       
    } Bits;
}Str_Can_RxData_LFE;

extern volatile  Str_Can_RxData_LFE     RxCANBuf_LFE[8];

#define Btm_ECULFE_EngFuelRate_LByte           RxCANBuf_LFE[0].Byte      //Eng Fuel Rate
#define Btm_ECULFE_EngFuelRate_HByte           RxCANBuf_LFE[1].Byte      //Eng Fuel Rate
#define Btm_ECULFE_EngInstantFuelEco_LByte     RxCANBuf_LFE[2].Byte      //Eng Instantaneous Fuel Economy
#define Btm_ECULFE_EngInstantFuelEco_HByte     RxCANBuf_LFE[3].Byte      //Eng Instantaneous Fuel Economy
#define Btm_ECULFE_EngAverageFuelEco_LByte     RxCANBuf_LFE[4].Byte      //Eng Average Fuel Economy
#define Btm_ECULFE_EngAverageFuelEco_HByte     RxCANBuf_LFE[5].Byte      //Eng Average Fuel Economy
#define Btm_ECULFE_EngThrottlePos_Byte         RxCANBuf_LFE[6].Byte      //Eng Throttle Pos



//-----------------------------------LFC-----------------------------------------
//Fuel Economy燃油经济性报文
//报文ID:0xfee9
//寄存器ID:
//发送方式：
//长度:8Byte                                  Bit0~7
//Byte1-2: Eng Trip Fuel
//         发动机航段燃油量
//Byte3-4: Eng Total Fuel Used             Bit0~7
//         发动机总燃油消耗量
//--------------------------------------------------------------------------------

typedef union {
    byte Byte;
    struct {
      byte data0         :1;
      byte data1         :1;
      byte data2         :1;                                                                              
      byte data3         :1;
      byte data4         :1;                                        
      byte data5         :1;                                       
      byte data6         :1;                                        
      byte data7         :1;                                       
    } Bits;
}Str_Can_RxData_LFC;

extern volatile  Str_Can_RxData_LFC     RxCANBuf_LFC[8];

#define Btm_ECULFC_EngTripFuel_41Byte          RxCANBuf_LFC[0].Byte   // Eng Trip Fuel
#define Btm_ECULFC_EngTripFuel_42Byte          RxCANBuf_LFC[1].Byte   // Eng Trip Fuel
#define Btm_ECULFC_EngTripFuel_43Byte          RxCANBuf_LFC[2].Byte   // Eng Trip Fuel
#define Btm_ECULFC_EngTripFuel_44Byte          RxCANBuf_LFC[3].Byte   // Eng Trip Fuel

#define Btm_ECULFC_EngTotalFuel_41Byte         RxCANBuf_LFC[4].Byte   // Eng Total Fuel Used
#define Btm_ECULFC_EngTotalFuel_42Byte         RxCANBuf_LFC[5].Byte   // Eng Total Fuel Used
#define Btm_ECULFC_EngTotalFuel_43Byte         RxCANBuf_LFC[6].Byte   // Eng Total Fuel Used
#define Btm_ECULFC_EngTotalFuel_44Byte         RxCANBuf_LFC[7].Byte   // Eng Total Fuel Used


//-----------------------------------ETC1接收-----------------------------------------
//robin20190712
//ETC1 
//报文ID:0xCF002FE
//寄存器ID:0x679805FC
//发送方式：接收
//长度:8Byte
//Byte0:  Transmission Driveline Engaged                   Bit0-1
//        变速器传动介入
//        Transmission Torque Converter Lockup Engaged     Bit2-3
//        禁止液力变矩器锁止介入
//        Transimission Shift In Process                   Bit4-5
//        变速器换挡中
//Byte1-2:Transmission Output Shaft Speed                  Bit0-7
//        变速器输出轴转速  
//Byte3:  Percent Clutch Slip                              Bit0-7
//        离合滑动百分比 
//Byte4:  Engine Momentary Overspeed Enable                Bit0-1
//        发动机瞬间超速启用
//        Progressive Shift Disable                        Bit2-3
//        渐进换挡禁用
//Byte5-6:Transmission Input Shaft Speed                   Bit0-7
//        变速器输入轴转速
//Byte7:  Source Address of Controlling Device for Transmission Control     Bit0-7
//        变速器控制设备源地址
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_ETC1;

extern   volatile   Str_Can_RxData_ETC1    RxCANBuf_ETC1[8];
#define  Btm_ECUETC1_TransDrivelineEngaged_2Bits              RxCANBuf_ETC1[0].Bits.data0    // 变速器传动介入
#define  Btm_ECUETC1_TorqueConverterLockupEngaged_2Bits       RxCANBuf_ETC1[0].Bits.data1    // 禁止液力变矩器锁止介入
#define  Btm_ECUETC1_TransShiftInProcess_2Bits                RxCANBuf_ETC1[0].Bits.data2    // 变速器换挡中
#define  Btm_ECUETC1_TransOutputShaftSpeed_LByte              RxCANBuf_ETC1[1].Byte          // 变速器输出轴转速 
#define  Btm_ECUETC1_TransOutputShaftSpeed_HByte              RxCANBuf_ETC1[2].Byte          // 变速器输出轴转速 
#define  Btm_ECUETC1_PercentClutchSlip_Byte                   RxCANBuf_ETC1[3].Byte          // 离合滑动百分比  
#define  Btm_ECUETC1_EngMomentaryOverspeedEnable_2Bits        RxCANBuf_ETC1[4].Bits.data0    // 发动机瞬间超速启用
#define  Btm_ECUETC1_ProgressiveShiftDisable_2Bits            RxCANBuf_ETC1[4].Bits.data1    // 渐进换挡禁用
#define  Btm_ECUETC1_TransInputShaftSpeed_LByte               RxCANBuf_ETC1[5].Byte          // 变速器输入轴转速
#define  Btm_ECUETC1_TransInputShaftSpeed_HByte               RxCANBuf_ETC1[6].Byte          // 变速器输入轴转速
#define  Btm_ECUETC1_SrcAddrssOfCtrllngDvcFrTrnsCtrl_Byte     RxCANBuf_ETC1[7].Byte          // 变速器控制设备源地址 

//-----------------------------------ETC2接收-----------------------------------------
//robin20190712
//ETC2 
//报文ID:0xCF002FE
//寄存器ID:0x679805FC
//发送方式：接收
//长度:8Byte
//Byte0:  Transmission Selected Gear                  Bit0-7
//        变速器选择档位
//Byte1-2:Transmission Actual Gear Ratio              Bit0-7
//        变速器实际传动比  
//Byte3:  Transmission Current Gear                   Bit0-7
//        变速器当前档位 
//Byte4-5:Transmission Requested Range                Bit0-7
//        变速器请求范围
//Byte6-7:Transmission Current Range                  Bit0-7
//        变速器当前范围
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_ETC2;

extern   volatile   Str_Can_RxData_ETC2    RxCANBuf_ETC2[8];
#define  Btm_ECUETC2_TransSelectedGear_Byte                   RxCANBuf_ETC2[0].Byte    // 变速器选择档位
#define  Btm_ECUETC2_TransActualGearRatio_LByte               RxCANBuf_ETC2[1].Byte    // 变速器实际传动比
#define  Btm_ECUETC2_TransActualGearRatio_HByte               RxCANBuf_ETC2[2].Byte    // 变速器实际传动比
#define  Btm_ECUETC2_TransCurrentGear_Byte                    RxCANBuf_ETC2[3].Byte    // 变速器当前档位
#define  Btm_TransRqedRange_LByte                             RxCANBuf_ETC2[4].Byte    // 变速器请求范围 
#define  Btm_TransRqedRange_HByte                             RxCANBuf_ETC2[5].Byte    // 变速器请求范围  
#define  Btm_TransCurrentRange_LByte                          RxCANBuf_ETC2[6].Byte    // 变速器当前范围
#define  Btm_TransCurrentRange_HByte                          RxCANBuf_ETC2[7].Byte    // 变速器当前范围

//-----------------------------------TC1发送-----------------------------------------
//robin20190710
//TC1 
//报文ID:0xC01FEFE
//寄存器ID:601BFDFC
//发送方式：周期性发送
//长度:8Byte
//Byte0:  Transmission Gear Shift Inhibit Request                  Bit0-1
//        禁止变速器换挡请求
//        Transmission Torque Converter Lockup Disable Request     Bit2-3
//        禁止液力变矩器锁止请求
//        Disengage Driveline Request                              Bit4-5
//        切断传动请求
//Byte1:  Requested Percent Clutch Slip                            Bit0-7
//        请求离合器滑动百分比  
//Byte2:  Transmission Requested Gear                              Bit0-7
//        变速器请求档位 
//Byte3:  Disengage Differential Lock Request - Front Axle 1       Bit0-1
//        前轴1差速锁脱开请求
//        Disengage Differential Lock Request - Front Axle 2       Bit2-3
//        前轴2差速锁脱开请求
//        Disengage Differential Lock Request - Rear Axle 1        Bit4-5
//        前轴3差速锁脱开请求
//        Disengage Differential Lock Request - Rear Axle 2        Bit6-7
//        前轴4差速锁脱开请求
//Byte4:  Disengage Differential Lock Request - Central            Bit0-1
//        差速锁脱开请求 - 中央
//        Disengage Differential Lock Request - Central Front      Bit2-3
//        差速锁脱开请求 - 中央 前部
//        Disengage Differential Lock Request - Central Rear       Bit4-5
//        差速锁脱开请求 - 中央 后部
//Byte5:  Transmission Mode1                                       Bit0-1
//        变速器模式1
//        Transmission Mode2                                       Bit2-3
//        变速器模式2       
//        Transmission Mode3                                       Bit4-5
//        变速器模式3        
//        Transmission Mode4                                       Bit6-7
//        变速器模式4
//Byte6:  Transmission Shift Selector Display Mode Switch          Bit6-7
//        变速箱换档选择器显示模式开关
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_TxData_TC1;

extern   volatile   Str_Can_TxData_TC1    TxCANBuf_TC1[8];
#define  Btm_ECUTC1_TransGearShiftInhibitRq_2Bits              TxCANBuf_TC1[0].Bits.data0    // Transmission Gear Shift Inhibit Request 
#define  Btm_ECUTC1_TorqueConverterLockupDisableRq_2Bits       TxCANBuf_TC1[0].Bits.data1    // Transmission Torque Converter Lockup Disable Request  
#define  Btm_ECUTC1_DisengageDrivelineRq_2Bits                 TxCANBuf_TC1[0].Bits.data2    // Disengage Driveline Request 
#define  Btm_ECUTC1_RqedPercentClutchSlip_Byte                 TxCANBuf_TC1[1].Byte          // Requested Percent Clutch Slip  
#define  Btm_ECUTC1_TransRqedGear_Byte                         TxCANBuf_TC1[2].Byte          // Transmission Requested Gear 
#define  Btm_ECUTC1_DisengageDiffLockRqFrontAxle1_2Bits        TxCANBuf_TC1[3].Bits.data0    // Disengage Differential Lock Request - Front Axle 1   
#define  Btm_ECUTC1_DisengageDiffLockRqFrontAxle2_2Bits        TxCANBuf_TC1[3].Bits.data1    // Disengage Differential Lock Request - Front Axle 2
#define  Btm_ECUTC1_DisengageDiffLockRqRearAxle1_2Bits         TxCANBuf_TC1[3].Bits.data2    // Disengage Differential Lock Request - Rear Axle 1
#define  Btm_ECUTC1_DisengageDiffLockRqRearAxle2_2Bits         TxCANBuf_TC1[3].Bits.data3    // Disengage Differential Lock Request - Rear Axle 2
#define  Btm_ECUTC1_DisengageDiffLockRqCentral_2Bits           TxCANBuf_TC1[4].Bits.data0    // Disengage Differential Lock Request - Central
#define  Btm_ECUTC1_DisengageDiffLockRqCentralFront_2Bits      TxCANBuf_TC1[4].Bits.data1    // Disengage Differential Lock Request - Central Front 
#define  Btm_ECUTC1_DisengageDiffLockRqCentralRear_2Bits       TxCANBuf_TC1[4].Bits.data2    // Disengage Differential Lock Request - Central Rear  
#define  Btm_ECUTC1_TransMode1_2Bits                           TxCANBuf_TC1[5].Bits.data0    // Transmission Mode1
#define  Btm_ECUTC1_TransMode2_2Bits                           TxCANBuf_TC1[5].Bits.data1    // Transmission Mode2
#define  Btm_ECUTC1_TransMode3_2Bits                           TxCANBuf_TC1[5].Bits.data2    // Transmission Mode3
#define  Btm_ECUTC1_TransMode4_2Bits                           TxCANBuf_TC1[5].Bits.data3    // Transmission Mode4
#define  Btm_ECUTC1_TrnsShftSlctorDisplayModeSwitch_2Bits      TxCANBuf_TC1[6].Bits.data3    // Transmission Shift Selector Display Mode Switch 



//-----------------------------------PCC状态发送-----------------------------------------
//robin20190708
//PCC State 
//报文ID:0x10FE6FFE
//寄存器ID:
//发送方式：周期性发送
//长度:8Byte
//Byte0:  Speed of forward vehicle                            Bit0-7
//        前车车速
//Byte1:  Distance to forward vehicle                         Bit0-7
//        距离前车距离  
//Byte2:  Adaptive Cruise Control Set Speed                   Bit0-7
//        自适应巡航设定车速
//Byte3:  Adaptive Cruise Control Mode                        Bit0-2
//        自适应巡航控制模式
//Byte3:  Adaptive cruise control set distance mode           Bit3-5
//        ACC设定距离模式
//Byte4-5:Road curvature                                      Bit0-7
//        道路曲率
//Byte6:  ACC Target Detected                                 Bit0-1
//        ACC目标检测/改为PCCState
//Byte6:  ACC System Shutoff Warning                          Bit2-3
//        ACC关闭报警
//Byte6:  ACC Distance Alert Signal                           Bit4-5
//        ACC距离报警信号
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_TxData_PCC;

extern volatile Str_Can_TxData_PCC  TxCANBuf_PCC[8];
#define  Btm_ECUPCC_ForwardVehicleSpeed_Byte               TxCANBuf_PCC[0].Byte           // Speed of forward vehicle
#define  Btm_ECUPCC_ForwardVehicleDistance_Byte            TxCANBuf_PCC[1].Byte           // Distance to forward vehicle 
#define  Btm_ECUPCC_ACCSetSpd_Byte                         TxCANBuf_PCC[2].Byte           // Adaptive Cruise Control Set Speed
#define  Btm_ECUPCC_ACCMode_3Bits                          TxCANBuf_PCC[3].Byte           // Adaptive Cruise Control Mode  
#define  Btm_ECUPCC_ACCSetDistance_3Bits                   TxCANBuf_PCC[3].Byte           // Adaptive cruise control set distance mode 
#define  Btm_ECUPCC_RoadCurvature_LByte                    TxCANBuf_PCC[4].Byte           //Adaptive Cruise Control Set Speed
#define  Btm_ECUPCC_RoadCurvature_HByte                    TxCANBuf_PCC[5].Byte           //Adaptive Cruise Control Set Speed
#define  Btm_ECUPCC_PCCState_2Bits                         TxCANBuf_PCC[6].Bits.data0     //此处修改为PCCState 原为ACC Target Detected
#define  Btm_ECUPCC_ACCShutoffWarning_2Bits                TxCANBuf_PCC[6].Bits.data1     //ACC System Shutoff Warning
#define  Btm_ECUPCC_ACCDisAlert_2Bits                      TxCANBuf_PCC[6].Bits.data2     //ACC Distance Alert Signal



//-----------------------------------CCVS改为发送-----------------------------------------
//robin20190624
//Cruise Ctrl/Veh Spd 
//报文ID:0xfef1
//寄存器ID:
//发送方式：100ms周期性发送
//长度:8Byte
//Byte1: Two Spd Axle SW                   Bit0-1//       两轴车速开关
//Byte1: Parking Brake SW                  Bit2-3//       驻车制动开关
//Byte1: Curise Ctl Pause SW               Bit4-5//       巡航控制暂停开关
//Byte1: Park Brake Release In Hibit Rq    Bit6-7//
//Byte2-3: Wheel Based Veh Spd             Bit0-7//       基于车轮的车速
//Byte4: Cruise Ctl Active                 Bit0-1//       巡航系统工作中
//Byte4: Cruise Ctl Enable SW              Bit2-3//       巡航控制使能开关
//Byte4: Brake SW                          Bit4-5//       制动开关
//Byte4: Clutch SW                         Bit6-7//       离合器开关
//Byte5: Cruise Ctl Set SW                 Bit0-1//       巡航控制Set开关
//Byte5: Cruise Ctl Coast SW               Bit2-3//       巡航控制花型滑行开关
//Byte5: Cruise Ctl Resume SW              Bit4-5//       巡航控制Resume开关
//Byte5: Cruise Ctl Accelerate SW          Bit6-7//       巡航控制加速开关
//Byte6: Cruise Ctl Set Spd                Bit0-7//       巡航设定车速
//Byte7: PTO St                            Bit0-4//       PTO状态
//Byte7: Cruise Ctl St                     Bit5-7//       巡航控制状态
//Byte8: Eng Idle Increment SW             Bit0-1//       发动机怠速增量开关
//Byte8: Eng Idle Decrement SW             Bit2-3//       发动机怠速减量开关
//Byte8: Eng Test Md SW                    Bit4-5//       发动机测试模式开关
//Byte8: Eng Shut Down Override Swtich     Bit6-7//       发动机关闭超越开关
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_TxData_CCVS;

extern volatile Str_Can_TxData_CCVS  TxCANBuf_CCVS[8];

#define  Btm_ECUCCVSTX_TwoSpdAxleSW_2Bits                    TxCANBuf_CCVS[0].Bits.data0    // Two Spd Axle SW 
#define  Btm_ECUCCVSTX_ParkingBrakeSW_2Bits                  TxCANBuf_CCVS[0].Bits.data1    // Parking Brake SW 
#define  Btm_ECUCCVSTX_CCSPauseSW_2Bits                      TxCANBuf_CCVS[0].Bits.data2    // Curise Ctl Pause SW

#define  Btm_ECUCCVSTX_WheelBasedVehSpd_LByte                TxCANBuf_CCVS[1].Byte          // Wheel Based Veh Spd 
#define  Btm_ECUCCVSTX_WheelBasedVehSpd_HByte                TxCANBuf_CCVS[2].Byte          // Wheel Based Veh Spd 

#define  Btm_ECUCCVSTX_CCSActive_2Bits                       TxCANBuf_CCVS[3].Bits.data0    // Cruise Ctl Active
#define  Btm_ECUCCVSTX_CCSEnableSW_2Bits                     TxCANBuf_CCVS[3].Bits.data1    // Cruise Ctl Enable SW 
#define  Btm_ECUCCVSTX_BrakeSW_2Bits                         TxCANBuf_CCVS[3].Bits.data2    // Brake SW
#define  Btm_ECUCCVSTX_ClutchSW_2Bits                        TxCANBuf_CCVS[3].Bits.data3    // Clutch SW

#define  Btm_ECUCCVSTX_CCSSetSW_2Bits                        TxCANBuf_CCVS[4].Bits.data0    // Cruise Ctl Set SW
#define  Btm_ECUCCVSTX_CCSCoastSW_2Bits                      TxCANBuf_CCVS[4].Bits.data1    // Cruise Ctl Coast SW 
#define  Btm_ECUCCVSTX_CCSResumeSW_2Bits                     TxCANBuf_CCVS[4].Bits.data2    // Cruise Ctl Resume SW 
#define  Btm_ECUCCVSTX_CCSAccelSW_2Bits                      TxCANBuf_CCVS[4].Bits.data3    // Cruise Ctl Accelerate SW 

#define  Btm_ECUCCVSTX_CCSSetSpd_Byte                        TxCANBuf_CCVS[5].Byte          // Cruise Ctl Set Spd 

#define  Btm_ECUCCVSTX_CCSPTOSt_5DBits                       TxCANBuf_CCVS[6].Byte          // PTO St   

#define  Btm_ECUCCVSTX_CCSCtlSt_3DBits                       TxCANBuf_CCVS[6].Byte          // Cruise Ctl St  

#define  Btm_ECUCCVSTX_EngIdleIncrementSW_2Bits              TxCANBuf_CCVS[7].Bits.data0    // Eng Idle Increment SW 
#define  Btm_ECUCCVSTX_EngIdleDecrementSW_2Bits              TxCANBuf_CCVS[7].Bits.data1    // Eng Idle Decrement SW 
#define  Btm_ECUCCVSTX_EngTestMdSW_2Bits                     TxCANBuf_CCVS[7].Bits.data2    // Eng Test Md SW    
#define  Btm_ECUCCVSTX_EngShutdownOrSW_2Bits                 TxCANBuf_CCVS[7].Bits.data3    // Eng Shut Down Override Swtich  



//-----------------------------------CCVS-----------------------------------------
//Cruise Ctrl/Veh Spd 
//报文ID:0xfef1
//寄存器ID:
//发送方式：
//长度:8Byte
//Byte1: Two Spd Axle SW               Bit0-1
//       两轴车速开关
//Byte1: Parking Brake SW                Bit2-3
//       驻车制动开关
//Byte1: Curise Ctl Pause SW             Bit4-5
//       巡航控制暂停开关
//Byte1: Park Brake Release In Hibit Rq      Bit6-7
//
//Byte2-3: Wheel Based Veh Spd         Bit0-7
//       基于车轮的车速
//Byte4: Cruise Ctl Active                   Bit0-1
//       巡航系统工作中
//Byte4: Cruise Ctl Enable SW            Bit2-3
//       巡航控制使能开关
//Byte4: Brake SW                        Bit4-5
//       制动开关
//Byte4: Clutch SW                       Bit6-7
//       离合器开关
//Byte5: Cruise Ctl Set SW               Bit0-1
//       巡航控制Set开关
//Byte5: Cruise Ctl Coast SW             Bit2-3
//       巡航控制花型滑行开关
//Byte5: Cruise Ctl Resume SW            Bit4-5
//       巡航控制Resume开关
//Byte5: Cruise Ctl Accelerate SW        Bit6-7
//       巡航控制加速开关
//Byte6: Cruise Ctl Set Spd                  Bit0-7
//       巡航设定车速
//Byte7: PTO St                           Bit0-4
//       PTO状态
//Byte7: Cruise Ctl St                    Bit5-7
//       巡航控制状态
//Byte8: Eng Idle Increment SW           Bit0-1
//       发动机怠速增量开关
//Byte8: Eng Idle Decrement SW           Bit2-3
//       发动机怠速减量开关
//Byte8: Eng Test Md SW                Bit4-5
//       发动机测试模式开关
//Byte8: Eng Shut Down Override Swtich       Bit6-7
//       发动机关闭超越开关
//--------------------------------------------------------------------------------
 typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_CCVS;

extern volatile Str_Can_RxData_CCVS  RxCANBuf_CCVS[8];

#define  Btm_ECUCCVS_TwoSpdAxleSW_2Bits                   RxCANBuf_CCVS[0].Bits.data0    // Two Spd Axle SW 
#define  Btm_ECUCCVS_ParkingBrakeSW_2Bits                 RxCANBuf_CCVS[0].Bits.data1    // Parking Brake SW 
#define  Btm_ECUCCVS_CCSPauseSW_2Bits                     RxCANBuf_CCVS[0].Bits.data2    // Curise Ctl Pause SW

#define  Btm_ECUCCVS_WheelBasedVehSpd_LByte            RxCANBuf_CCVS[1].Byte          // Wheel Based Veh Spd 
#define  Btm_ECUCCVS_WheelBasedVehSpd_HByte            RxCANBuf_CCVS[2].Byte          // Wheel Based Veh Spd 

#define  Btm_ECUCCVS_CCSActive_2Bits                       RxCANBuf_CCVS[3].Bits.data0    // Cruise Ctl Active
#define  Btm_ECUCCVS_CCSEnableSW_2Bits                     RxCANBuf_CCVS[3].Bits.data1    // Cruise Ctl Enable SW 
#define  Btm_ECUCCVS_BrakeSW_2Bits                         RxCANBuf_CCVS[3].Bits.data2    // Brake SW
#define  Btm_ECUCCVS_ClutchSW_2Bits                        RxCANBuf_CCVS[3].Bits.data3    // Clutch SW

#define  Btm_ECUCCVS_CCSSetSW_2Bits                        RxCANBuf_CCVS[4].Bits.data0    // Cruise Ctl Set SW
#define  Btm_ECUCCVS_CCSCoastSW_2Bits                      RxCANBuf_CCVS[4].Bits.data1    // Cruise Ctl Coast SW 
#define  Btm_ECUCCVS_CCSResumeSW_2Bits                     RxCANBuf_CCVS[4].Bits.data2    // Cruise Ctl Resume SW 
#define  Btm_ECUCCVS_CCSAccelSW_2Bits                      RxCANBuf_CCVS[4].Bits.data3    // Cruise Ctl Accelerate SW 

#define  Btm_ECUCCVS_CCSSetSpd_Byte                        RxCANBuf_CCVS[5].Byte          // Cruise Ctl Set Spd 

#define  Btm_ECUCCVS_CCSPTOSt_5DBits                    RxCANBuf_CCVS[6].Byte          // PTO St   

#define  Btm_ECUCCVS_CCSCtlSt_3DBits                    RxCANBuf_CCVS[6].Byte          // Cruise Ctl St  

#define  Btm_ECUCCVS_EngIdleIncrementSW_2Bits              RxCANBuf_CCVS[7].Bits.data0    // Eng Idle Increment SW 
#define  Btm_ECUCCVS_EngIdleDecrementSW_2Bits              RxCANBuf_CCVS[7].Bits.data1    // Eng Idle Decrement SW 
#define  Btm_ECUCCVS_EngTestMdSW_2Bits                   RxCANBuf_CCVS[7].Bits.data2    // Eng Test Md SW    
#define  Btm_ECUCCVS_EngShutdownOrSW_2Bits                 RxCANBuf_CCVS[7].Bits.data3    // Eng Shut Down Override Swtich  


//-----------------------------------TSC1-----------------------------------------
//Trq/Spd Ctrl 1 
//报文ID:
//寄存器ID:
//发送方式：
//长度:8Byte
//Byte1: Eng Overide Ctrl Md             Bit0-1
//
//Byte1: Eng Rqed Spd Ctl Conditions        Bit2-3
//
//Byte1: Override Ctl Md Priority           Bit4-5
//
//Byte2-3: Eng Rqed Spd Spd lmt         Bit0-7
//
//Byte4: Eng Rqed Trq Trq lmt         Bit0-7
//
//Byte5: Transmission Rate                    Bit0-2
//
//Byte5: Ctrl Purp                      Bit3-7
//
//Byte6: Eng Requested Trq Hi Res       Bit0-3
//
//Byte8: Message Counter                      Bit0-3
//
//Byte8: Message Check Sum                    Bit0-3
//
//-------------------------------------------------------------------------------------

typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_TSC1;

extern volatile Str_Can_RxData_TSC1  TxCANBuf_TSC1[8];
                                              
#define Btm_ECUTSC1_EngORCtlMd_2Bits             TxCANBuf_TSC1[0].Bits.data0
#define Btm_ECUTSC1_EngRqedSpdConditions_2Bits   TxCANBuf_TSC1[0].Bits.data1
#define Btm_ECUTSC1_ORCtlMdP_2Bits               TxCANBuf_TSC1[0].Bits.data2
#define Btm_ECUTSC1_EngRqedSpdlmt_LByte          TxCANBuf_TSC1[1].Byte
#define Btm_ECUTSC1_EngRqedSpdlmt_HByte          TxCANBuf_TSC1[2].Byte
#define Btm_ECUTSC1_EngRqedTrqlmt_Byte           TxCANBuf_TSC1[3].Byte
#define Btm_ECUTSC1_TransmissionRate_3Bits       TxCANBuf_TSC1[4].Byte
#define Btm_ECUTSC1_CtlPurp_5Bits                TxCANBuf_TSC1[4].Byte
#define Btm_ECUTSC1_EngRqedTrqHiRes_4Bits        TxCANBuf_TSC1[5].Byte
#define Btm_ECUTSC1_MsgCout_4Bits                TxCANBuf_TSC1[6].Byte
#define Btm_ECUTSC1_MsgChecksum_4Bits            TxCANBuf_TSC1[7].Byte



//-----------------------------------EBC1-----------------------------------------
//Trq/Spd Ctrl 1 
//报文ID:
//寄存器ID:
//发送方式：
//长度:8Byte
//Byte8-4: EngShutDownCANSW              Bit4-5
//
//
//-------------------------------------------------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_EBC1;

extern volatile Str_Can_RxData_EBC1  TxCANBuf_EBC1[8];
                                              

#define Btm_ECUEBC1_EngShutDown_Byte0             TxCANBuf_EBC1[0].Byte
#define Btm_ECUEBC1_EngShutDown_Byte1             TxCANBuf_EBC1[1].Byte
#define Btm_ECUEBC1_EngShutDown_Byte2             TxCANBuf_EBC1[2].Byte

#define Btm_ECUEBC1_EngShutDown_41Bits            TxCANBuf_EBC1[3].Bits.data0
#define Btm_ECUEBC1_EngShutDown_42Bits            TxCANBuf_EBC1[3].Bits.data1
#define Btm_ECUEBC1_EngShutDown_2Bits             TxCANBuf_EBC1[3].Bits.data2
#define Btm_ECUEBC1_EngShutDown_44Bits            TxCANBuf_EBC1[3].Bits.data3

#define Btm_ECUEBC1_EngShutDown_Byte4             TxCANBuf_EBC1[4].Byte
#define Btm_ECUEBC1_EngShutDown_Byte5             TxCANBuf_EBC1[5].Byte
#define Btm_ECUEBC1_EngShutDown_Byte6             TxCANBuf_EBC1[6].Byte
#define Btm_ECUEBC1_EngShutDown_Byte7             TxCANBuf_EBC1[7].Byte












//-----------------------------------AMB-----------------------------------------
//Ambient Conditions 
//报文ID: 0xfef5
//寄存器ID:
//发送方式：
//长度:8Byte
//Byte1: Barometric Press
//       大气压力
//Byte2-3: Cabinterior Temp
//       车厢内部温度
//---------------------------------------------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_AMB;

extern volatile Str_Can_RxData_AMB  RxCANBuf_AMB[8];

#define Btm_ECUAMB_BarometricPress_Byte   RxCANBuf_AMB[0].Byte



//-----------------------------------ERC1-----------------------------------------
//Ambient Conditions 
//报文ID: 0xf000
//寄存器ID:
//发送方式：
//长度:8Byte
//Byte2: Actual Retarder Pct Trq
//       实际缓速器扭矩百分比
//---------------------------------------------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_ERC1;

extern volatile Str_Can_RxData_ERC1  RxCANBuf_ERC1[8];

#define Btm_ECUERC1_ActualRetarderTrqPct_Byte    RxCANBuf_ERC1[1].Byte



//+++++++++++++++++++++++++++++++++            ++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++仪表通讯协议++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++            ++++++++++++++++++++++++++++++++++++
//-----------------------------------TCO1------------------------------------------
typedef union {
    byte Byte;
    struct {
      byte data0         :2;                                        
      byte data1         :2;                                       
      byte data2         :2;                                       
      byte data3         :2;                                       
    } Bits;
}Str_Can_RxData_TCO1;

extern volatile Str_Can_RxData_TCO1  RxCANBuf_TCO1[8];



#define Btm_MeterTCO1_TachographOutputShaftSpd_LByte    RxCANBuf_TCO1[4].Byte
#define Btm_MeterTCO1_TachographOutputShaftSpd_HByte    RxCANBuf_TCO1[5].Byte
#define Btm_MeterTCO1_TachographVehSpd_LByte        RxCANBuf_TCO1[6].Byte
#define Btm_MeterTCO1_TachographVehSpd_HByte        RxCANBuf_TCO1[7].Byte


//+++++++++++++++++++++++++++++++++            ++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++仪表通讯协议++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++            ++++++++++++++++++++++++++++++++++++
//-----------------------------------TCO1------------------------------------------

typedef union{
  //
  byte Byte;
  struct{
    //
    byte data0         :4;                                        
    byte data1         :4;                                       
  }Bits; 
}Str_Can_RxData_EC1;
extern volatile Str_Can_RxData_EC1 RxCANBuf_EC1[39];

#define Btm_ECUEC1_EngSpdAtIdlePoint1_LByte                RxCANBuf_EC1[0].Byte
#define Btm_ECUEC1_EngSpdAtIdlePoint1_HByte                RxCANBuf_EC1[1].Byte
#define Btm_ECUEC1_EngPctTrqAtIdlePoint1_Byte        RxCANBuf_EC1[2].Byte

#define Btm_ECUEC1_EngSpdAtPoint2_LByte                    RxCANBuf_EC1[3].Byte
#define Btm_ECUEC1_EngSpdAtPoint2_HByte                    RxCANBuf_EC1[4].Byte
#define Btm_ECUEC1_EngPctTrqAtPoint2_Byte            RxCANBuf_EC1[5].Byte

#define Btm_ECUEC1_EngSpdAtPoint3_LByte                    RxCANBuf_EC1[6].Byte
#define Btm_ECUEC1_EngSpdAtPoint3_HByte                    RxCANBuf_EC1[7].Byte
#define Btm_ECUEC1_EngPctTrqAtPoint3_Byte            RxCANBuf_EC1[8].Byte

#define Btm_ECUEC1_EngSpdAtPoint4_LByte                    RxCANBuf_EC1[9].Byte
#define Btm_ECUEC1_EngSpdAtPoint4_HByte                    RxCANBuf_EC1[10].Byte
#define Btm_ECUEC1_EngPctTrqAtPoint4_Byte            RxCANBuf_EC1[11].Byte

#define Btm_ECUEC1_EngSpdAtPoint5_LByte                    RxCANBuf_EC1[12].Byte
#define Btm_ECUEC1_EngSpdAtPoint5_HByte                    RxCANBuf_EC1[13].Byte
#define Btm_ECUEC1_EngPctTrqAtPoint5_Byte            RxCANBuf_EC1[14].Byte

#define Btm_ECUEC1_EngSpdAtHighIdlePoint6_LByte            RxCANBuf_EC1[15].Byte
#define Btm_ECUEC1_EngSpdAtHighIdlePoint6_HByte            RxCANBuf_EC1[16].Byte

#define Btm_ECUEC1_EngGainOfEndSpdGovernor_LByte           RxCANBuf_EC1[17].Byte
#define Btm_ECUEC1_EngGainOfEndSpdGovernor_HByte           RxCANBuf_EC1[18].Byte

#define Btm_ECUEC1_EngReferenceTrq_LByte                  RxCANBuf_EC1[19].Byte
#define Btm_ECUEC1_EngReferenceTrq_HByte                  RxCANBuf_EC1[20].Byte

#define Btm_ECUEC1_EngMxMmntaryOverrideSpdPoint7_LByte     RxCANBuf_EC1[21].Byte
#define Btm_ECUEC1_EngMxMmntaryOverrideSpdPoint7_HByte     RxCANBuf_EC1[22].Byte

#define Btm_ECUEC1_EngMxMomentaryOverrideTimelmt_Byte      RxCANBuf_EC1[23].Byte

#define Btm_ECUEC1_EngRqedSpdCtrlRangeLowerlmt_Byte      RxCANBuf_EC1[24].Byte
#define Btm_ECUEC1_EngRqedSpdCtrlRangeUpperlmt_Byte      RxCANBuf_EC1[25].Byte

#define Btm_ECUEC1_EngRqdTrqCtrlRangeLowerlmt_Byte      RxCANBuf_EC1[26].Byte
#define Btm_ECUEC1_EngRqdTrqCtrlRangeUpperlmt_Byte      RxCANBuf_EC1[27].Byte

#define Btm_ECUEC1_EngExRngRqdSpdCtrlRngUpperlmt_LByte     RxCANBuf_EC1[28].Byte
#define Btm_ECUEC1_EngExRngRqdSpdCtrlRngUpperlmt_HByte     RxCANBuf_EC1[29].Byte

#define Btm_ECUEC1_EngMomentOfInertia_LByte                  RxCANBuf_EC1[30].Byte
#define Btm_ECUEC1_EngMomentOfInertia_HByte                  RxCANBuf_EC1[31].Byte

#define Btm_ECUEC1_EngDefaultTrqlmt_LByte               RxCANBuf_EC1[32].Byte
#define Btm_ECUEC1_EngDefaultTrqlmt_HByte               RxCANBuf_EC1[33].Byte

#define Btm_ECUEC1_SupportVariableRateTSC1Message_Byte       RxCANBuf_EC1[34].Byte
#define Btm_ECUEC1_SupportTSC1CtrlPurpGroup1Of4_Byte      RxCANBuf_EC1[35].Byte
#define Btm_ECUEC1_SupportTSC1CtrlPurpGroup2Of4_Byte      RxCANBuf_EC1[36].Byte
#define Btm_ECUEC1_SupportTSC1CtrlPurpGroup3Of4_Byte      RxCANBuf_EC1[37].Byte
#define Btm_ECUEC1_SupportTSC1CtrlPurpGroup4Of4_Byte      RxCANBuf_EC1[38].Byte










extern unsigned char CANMain_TX(unsigned long id,unsigned char priority,unsigned char length,unsigned char *txdata); 



#define NO_ERR 0x00
#define ERR_Buf_FULL 0x80


//报文ID及优先级等
//extern const unsigned long CANIDBuf_HCU2BMS_1st;
//extern const unsigned char CANPBuf_HCU2BMS_1st;
//extern const unsigned char CANLBuf_HCU2BMS_1st;  

/***************************************************************************/
//---------------------------------ECU 报文 ID------------------------------
#define CANSA_ECU        0x00
#define CANSA_TCU        0x03
#define CANSA_Meter1     0x17
#define CANSA_Meter2     0xfe

#define CANPGN_EEC1      0xf004
#define CANPGN_EEC2      0xf003
#define CANPGN_EEC3      0xfedf
#define CANPGN_ET1       0xfeee
#define CANPGN_LFE       0xfef2
#define CANPGN_LFC       0xfee9
#define CANPGN_CCVS      0xfef1

#define CANPGN_ETC1      0xf002
#define CANPGN_ETC2      0xf005

#define CANPGN_AMB       0xfef5
#define CANPGN_ERC1      0xf000
#define CANPGN_Data_EC1  0xebff

#define CANPGN_TSC1      0x0000
                         
#define CANPGN_TCO1      0xfe6c
   





#define CANIDBuf_EEC1             0x67980800   //
#define CANPBuf_EEC1              3
#define CANLBuf_EEC1              8

#define CANIDBuf_EEC2             0x67980600   //
#define CANPBuf_EEC2              3
#define CANLBuf_EEC2              8

#define CANIDBuf_EEC3             0xc7fcbe00   //
#define CANPBuf_EEC3              6
#define CANLBuf_EEC3              8

#define CANIDBuf_ET1              0xc7fddc00   //
#define CANPBuf_ET1               6
#define CANLBuf_ET1               8

#define CANIDBuf_LFE              0xc7fde400   //
#define CANPBuf_LFE               6
#define CANLBuf_LFE               8

#define CANIDBuf_LFC              0xc7fdd200   //
#define CANPBuf_LFC               6
#define CANLBuf_LFC               8

#define CANIDBuf_CCVS             0xc7fde200   //
#define CANPBuf_CCVS              6
#define CANLBuf_CCVS              8


#define CANIDBuf_PCC              0x87FCDFFC  //0x10FE6FFE  robin修改添加190708
#define CANPBuf_PCC               4 //
#define CANLBuf_PCC               8  //robin修改添加190708

#define CANIDBuf_TC1              0x601BFDFC  //0xC01FEFE  robin修改添加190708
#define CANPBuf_TC1               3 //
#define CANLBuf_TC1               8  //robin修改添加190708


#define CANIDBuf_AMB              0xc7fdea00   //
#define CANPBuf_AMB               6
#define CANLBuf_AMB               8
                                     
#define CANIDBuf_ERC1             0xc7980000   //
#define CANPBuf_ERC1              6
#define CANLBuf_ERC1              8

#define CANIDBuf_EC1              0xc7fdc600    //
#define CANPBuf_EC1               6
#define CANLBuf_EC1               39

#define CANIDBuf_GEC1             0xc779fe00   //0x18ecff00
#define CANIDBuf_DEC1             0xc75ffe00   //0x18ebff00


#define CANIDBuf_GRC              0xc779fe1e   //0x18ecff0f
#define CANIDBuf_DRC              0xc75ffe1e   //0x18ebff0f





#define CANIDBuf_TSC1             0x60180042 //0x0C000021 VE
#define CANIDBuf_TSC1_RR          0x60181E20 //0x0C000F10 TSC1锡柴负扭矩报文
#define CANIDBuf_TSC1_TE          0x60180006 //0x0C000003 TSC1潍柴正扭矩报文
#define CANIDBuf_TSC1_VR          0x60181E42 //0x0C000F21 TSC1潍柴负扭矩报文
#define CANIDBuf_TSC1_PtofE       0x60180048 //0x0C000024 TSC1潍柴陕汽正扭矩报文
#define CANIDBuf_TSC1_MR          0x60181E4E //0x0C000F27 TSC1潍柴陕汽负扭矩报文
#define CANPBuf_TSC1              3
#define CANLBuf_TSC1              8


#define CANIDBuf_EBC1             0xc7980216 //   //0x18f0010b 
#define CANPBuf_EBC1              3
#define CANLBuf_EBC1              8



//---------------------------------Meter 报文 ID------------------------------
#define CANIDBuf_TCO1_1             0x67fcd82e      //0x0c fe6c 17   
#define CANIDBuf_TCO1_2             0x67fcd9de      //0x0c fe6c fe
#define CANPBuf_TCO1                3
#define CANLBuf_TCO1                8






void CAN0Func_ValueInit(void);





#endif