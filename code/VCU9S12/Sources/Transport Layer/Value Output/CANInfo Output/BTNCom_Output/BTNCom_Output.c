#include "Allh.h"

#define MFL_BTN_NUM 4
#define CANIDBuf_BTN             0x80D84242 //0x10182121 //0x80D80010 == 0x10180008
#define CANPBuf_BTN              3
#define CANLBuf_BTN              8


volatile Key_Pressed_State Key_CurState;

volatile Key_Pressed_State Key_LastState;

unsigned char CANTxErr_stBTNUB = 0;
unsigned char BTN_TxBuf[8] = {0,0,0,0,0,0,0,0};

unsigned char BTN_LastState[8] = {0,0,0,0,0,0,0,0};


void CANTx2BTNTest_10ms(void)//
{
    
    BTNCAN_TxBufUpdate();
    //CANTxErr_stBTNUB = CANMain_TX(CANIDBuf_BTN, CANPBuf_BTN, CANLBuf_BTN, (unsigned char *)BTN_TxBuf);
}//


void BTNCAN_TxBufUpdate(void)//
{
    unsigned char n = 0;

    for ( n = 0; n < MFL_BTN_NUM; n++ )
    {
        BTN_TxBuf[n] = _Btm_SWLH_VB[n+1];
    }

}

void BTNCAN_TxBufUpdate_Test(void)//
{
    unsigned char n = 0;
    unsigned char keypressed = 0;
    for ( n = 1; n <= MFL_BTN_NUM; n++ )
    {
        if (0 == BTN_LastState[n] && 1 == _Btm_SWLH_VB[n])
        {
            BTN_LastState[n] == 1;

            BTN_TxBuf[n] = _Btm_SWLH_VB[n];
            keypressed = 1;
        } else if (1 == BTN_LastState[n] && 0 == _Btm_SWLH_VB[n])
        {
            BTN_LastState[n] == 0;
            BTN_TxBuf[n] = _Btm_SWLH_VB[n];
        }
    }
    
    if (keypressed)
    {
        CANTxErr_stBTNUB = CANMain_TX(CANIDBuf_BTN, CANPBuf_BTN, CANLBuf_BTN, (unsigned char *)BTN_TxBuf);
        
    }

    for ( n = 0; n < MFL_BTN_NUM; n++ )
    {
        BTN_TxBuf[n] = 0;
        keypressed = 1;
    }
}

