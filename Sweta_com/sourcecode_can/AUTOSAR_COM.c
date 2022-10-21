

#include "CAN_IF.h"
#include "AUTOSAR_COM_Config.h"

void CAN_Send_signal(int CAN_SIG,int Value)
{        
    AUTOSAR_MSG1 AUTOSAR_MSG1_S;
//    if(CAN_SIG == )
    {
        AUTOSAR_MSG1_S.sig_1_s = Value;
    }
//    AUTOSAR_MSG1_S.sig_1_s = Value;       
//     CAN_FRAME(0,data);

}