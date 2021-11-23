#include "Allh.h"





void PIT_Init(void) 
{  
    PITCFLMT_PITE=1;  //PIT使能
    PITCFLMT_PITSWAI=1; //Wait模式下不工作
    PITCFLMT_PITFRZ=0; //Freeze模式下正常工作
    
    
    PITCE_PCE0=1;  //PIT通道0使能
    PITCE_PCE1=1;  //PIT通道1使能
    PITCE_PCE2=1;  //PIT通道2使能
    PITCE_PCE3=1;  //PIT通道3使能
    
    PITMUX_PMUX0  = 0; //通道0 Micro Time base 0
    PITMUX_PMUX1  = 0; //通道0 Micro Time base 0
    PITMUX_PMUX2  = 0; //通道2 Micro Time base 0
    PITMUX_PMUX3  = 0; //通道3 Micro Time base 0
    
    
    
    PITINTE_PINTE0  = 0; //禁止中断
    PITINTE_PINTE1  = 0; //禁止中断 
    PITINTE_PINTE2  = 0; //禁止中断
    PITINTE_PINTE3  = 0; //禁止中断
    
    
    
    
    
    PITMTLD0=199;       //时钟1
    PITCFLMT_PFLMT0=1;  //load micro time base 0

    PITMTLD1=199;       //时钟2
    PITCFLMT_PFLMT1=1;  //load micro time base 1


    //---------------时钟规划-----------------
    //T=(PITMTLD0+1)*(PITLD0+1)/8M


   
    //--------------PIT规划--------------------------------
    //PIT1   10KHz    0.1ms    作为时间基准，优先级最高
    //PIT2   100Hz    10ms     为时间基准的100倍，作为安全策略等的执行    执行StUpdate
    //PIT3   25Hz     40ms     作为任务的执行函数
    //PIT4   10Hz     10ms     备用

    PITLD0=39;       //8M/200/40=1000Hz   1ms
    PITFLT_PFLT0=1;   //通道强制加载位
    PITINTE_PINTE0=1; //通道允许中断

   	PITLD1=399;  //8M/200/400=100Hz    10ms
    PITFLT_PFLT1=1;   //8M/200/400=100Hz
    PITINTE_PINTE1=1; //通道允许中断

    PITLD2=799;    //最新更正为20模式      //8M/200/400=100Hz   40ms        25Hz 
    PITFLT_PFLT2=1;   //8M/200/800=50Hz     8000000/200/1600=25Hz  40ms
    PITINTE_PINTE2=1; //通道允许中断
    
    PITLD3=3999;   //8M/200/2000=20Hz    100ms
    PITFLT_PFLT3=1;     //8M/200/4000=10Hz   100ms
    PITINTE_PINTE3=1; //通道允许中断


}