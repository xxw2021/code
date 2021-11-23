
 #ifndef   __CCP_INTERFACE_H
    #define   __CCP_INTERFACE_H 

#include "CCP.h"

void CCP_DAQTask(void);
CCP_BYTEFARPTR  ccpGetPointer(CCP_BYTE addr_ext , CCP_DWORD address) ;
uchar  ccpUnlock(uchar * a);
CCP_DWORD ccpGetSeed( CCP_BYTE resourceMask );

#endif    