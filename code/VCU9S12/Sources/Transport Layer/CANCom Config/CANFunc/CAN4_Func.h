#ifndef CAN4_FUNC_H
#define CAN4_FUNC_H



void   CAN4TransmitMsg(CAN_Msg_struct* TP_pMsg);
extern unsigned char  CAN4TXMsgPossible(void);
void   CAN4Diagnostic(void);



#endif