
 #ifndef   __CCP_INTERFACE_H
    #define   __CCP_INTERFACE_H 

#include "CCP.h"

 //CCP_DWORD ccpGetCalPage( void );

// void ccpSetCalPage( CCP_DWORD a ) ;

// CCP_BYTE ccpFlashProgramm( CCP_BYTEPTR data, CCP_MTABYTEPTR a, CCP_BYTE size );

//void ccpFlashClear( CCP_MTABYTEPTR a, CCP_DWORD size );

void CCP_DAQTask(void);


//uchar * ccpGetPointer( uchar addr_ext, uint addr ) ;      // get Pointer into

void ccpUserBackground( void );

uchar ccpDisableNormalOperation( uchar * a, uint s );


#endif    