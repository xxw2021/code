#include "Allh.h"





void PIT_Init(void) 
{  
    PITCFLMT_PITE=1;  //PITʹ��
    PITCFLMT_PITSWAI=1; //Waitģʽ�²�����
    PITCFLMT_PITFRZ=0; //Freezeģʽ����������
    
    
    PITCE_PCE0=1;  //PITͨ��0ʹ��
    PITCE_PCE1=1;  //PITͨ��1ʹ��
    PITCE_PCE2=1;  //PITͨ��2ʹ��
    PITCE_PCE3=1;  //PITͨ��3ʹ��
    
    PITMUX_PMUX0  = 0; //ͨ��0 Micro Time base 0
    PITMUX_PMUX1  = 0; //ͨ��0 Micro Time base 0
    PITMUX_PMUX2  = 0; //ͨ��2 Micro Time base 0
    PITMUX_PMUX3  = 0; //ͨ��3 Micro Time base 0
    
    
    
    PITINTE_PINTE0  = 0; //��ֹ�ж�
    PITINTE_PINTE1  = 0; //��ֹ�ж� 
    PITINTE_PINTE2  = 0; //��ֹ�ж�
    PITINTE_PINTE3  = 0; //��ֹ�ж�
    
    
    
    
    
    PITMTLD0=199;       //ʱ��1
    PITCFLMT_PFLMT0=1;  //load micro time base 0

    PITMTLD1=199;       //ʱ��2
    PITCFLMT_PFLMT1=1;  //load micro time base 1


    //---------------ʱ�ӹ滮-----------------
    //T=(PITMTLD0+1)*(PITLD0+1)/8M


   
    //--------------PIT�滮--------------------------------
    //PIT1   10KHz    0.1ms    ��Ϊʱ���׼�����ȼ����
    //PIT2   100Hz    10ms     Ϊʱ���׼��100������Ϊ��ȫ���Եȵ�ִ��    ִ��StUpdate
    //PIT3   25Hz     40ms     ��Ϊ�����ִ�к���
    //PIT4   10Hz     10ms     ����

    PITLD0=39;       //8M/200/40=1000Hz   1ms
    PITFLT_PFLT0=1;   //ͨ��ǿ�Ƽ���λ
    PITINTE_PINTE0=1; //ͨ�������ж�

   	PITLD1=399;  //8M/200/400=100Hz    10ms
    PITFLT_PFLT1=1;   //8M/200/400=100Hz
    PITINTE_PINTE1=1; //ͨ�������ж�

    PITLD2=799;    //���¸���Ϊ20ģʽ      //8M/200/400=100Hz   40ms        25Hz 
    PITFLT_PFLT2=1;   //8M/200/800=50Hz     8000000/200/1600=25Hz  40ms
    PITINTE_PINTE2=1; //ͨ�������ж�
    
    PITLD3=3999;   //8M/200/2000=20Hz    100ms
    PITFLT_PFLT3=1;     //8M/200/4000=10Hz   100ms
    PITINTE_PINTE3=1; //ͨ�������ж�


}