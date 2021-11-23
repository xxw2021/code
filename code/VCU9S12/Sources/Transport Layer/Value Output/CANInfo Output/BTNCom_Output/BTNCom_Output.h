#ifndef BTNCOM_OUTPUT_H
#define BTNCOM_OUTPUT_H


void CANTx2BTNTest_10ms(void);
void CANTx2BTNTest_100ms(void);




void BTNCAN_TxBufUpdate(void);

typedef enum {
    KEY_OFF = 0,
    KEY_ON, 
    KEY_RESUME,
    KEY_SETPLUS,
    KEY_SETMINUS,
} key_enum_t;

typedef union {
    byte Byte;
    struct {
      byte key0         :2;
      byte key1         :2;
      byte key2         :2;
      byte key3         :2;
    } Bits;
} Key_Pressed_State;
extern volatile Key_Pressed_State Key_CurState;


#define  Key_SWT_State    Key_CurState.Bits.key0
#define  Key_RES_State    Key_CurState.Bits.key1
#define  Key_SETDWN_State Key_CurState.Bits.key2
#define  Key_SETUP_State  Key_CurState.Bits.key3



#endif
